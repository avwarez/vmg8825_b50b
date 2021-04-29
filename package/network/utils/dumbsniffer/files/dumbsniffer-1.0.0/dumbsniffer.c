#define _POSIX_C_SOURCE 200112L

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netlink/msg.h>
#include <netlink/netfilter/queue.h>
#include <netlink/netfilter/queue_msg.h>
#include <netlink/netfilter/ct.h>
#include <netlink/netlink.h>
#include <linux/netlink.h>
#include <linux/netfilter/nfnetlink.h>
#include <linux/netfilter/nfnetlink_conntrack.h>
#include <netlink/socket.h>
#include <libnfnetlink/libnfnetlink.h>

// Config comes here:
#define FAMILY AF_INET
#define QUEUE 1
#define MAX_PKT_SIZE 65536
#define BUFSIZE (32 * 1024 * 1024)

#define VERDICT_REFUSE 1
#define VERDICT_BYPASS 2
#define VERDICT_OK 3
#define VERDICT_MASK 0xFF
#define VERDICT_OFFSET 12
// End of config

#define DIE(MSG) do { fprintf(stderr, "%s:%d: %s: %s\n", __FILE__, __LINE__, MSG, strerror(errno)); abort(); } while (0)
#define CHECK(EXPR) do { if (!(EXPR)) { DIE(#EXPR); } } while (0)
#define CHECK_N(EXPR) do { if ((EXPR) < 0) { DIE(#EXPR); } } while (0)
#define EVER ;;

#define NF_DROP 0
#define NF_ACCEPT 1
#define NF_STOLEN 2
#define NF_QUEUE 3
#define NF_REPEAT 4

#define CONNTRACK_GROUPS ( \
	NF_NETLINK_CONNTRACK_NEW | \
	NF_NETLINK_CONNTRACK_UPDATE | \
	NF_NETLINK_CONNTRACK_DESTROY \
)

#define MAX_ADDR_LEN 20

static struct nfnl_queue_msg *response;
static struct nl_sock *q_sock;

static const uint8_t no_mac[6] = {};

// Dummy decision maker. The real one is much more complex… but that's not the point of this example
static uint32_t decide(const uint8_t *mac, const uint8_t *data, size_t len, uint32_t mark, uint32_t zextmark) {
	if (!mac)
		mac = no_mac;
	struct iphdr header = {};
	if (len < sizeof header) {
		printf("Odd: Packet too short to be an IP packet (only %zu bytes)\n", len);
		return VERDICT_OK;
	}
	memcpy(&header, data, sizeof header);
	if (header.ihl * 4 > len) {
		printf("Odd: IP header length bigger than packet size\n");
	}
	if (header.version != 4) {
		printf("Odd: Expected IPv4 packet, got something else\n");
	}
	char src[MAX_ADDR_LEN];
	char dst[MAX_ADDR_LEN];
	inet_ntop(AF_INET, &header.saddr, src, MAX_ADDR_LEN);
	inet_ntop(AF_INET, &header.daddr, dst, MAX_ADDR_LEN);
	printf("Packet of %zu bytes from %02hhX:%02hhX:%02hhX:%02hhX:%02hhX:%02hhX and input mark %08x zextmark %08x from %s to %s\n", len, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mark, zextmark, src, dst);
	long int r = rand() % 1000;
	if (r < 10) { // 1 % chance to refuse the packet and flow
		printf("Refusing packet\n");
		return VERDICT_REFUSE;
	} else if (r < 110) { // 10 % chance to bypass the flow
		printf("Bypassing packet\n");
		return VERDICT_BYPASS;
	} else {
		printf("OK packet\n");
		return VERDICT_OK;
	}
}

static void q_parse(struct nl_object *obj, void *unused) {
	(void) unused;
	struct nfnl_queue_msg *msg = (void *) obj;
	uint32_t id = nfnl_queue_msg_get_packetid(msg);
	uint8_t family = nfnl_queue_msg_get_family(msg);
	assert(family == FAMILY);
	uint32_t mark = nfnl_queue_msg_test_mark(msg) ? nfnl_queue_msg_get_mark(msg) : 0;
	uint32_t zextmark = nfnl_queue_msg_test_zextmark(msg) ? nfnl_queue_msg_get_zextmark(msg) : 0;
	int hw_addr_len;
	const uint8_t *hw_addr = nfnl_queue_msg_get_hwaddr(msg, &hw_addr_len);
	int pkt_len;
	const uint8_t *pkt = nfnl_queue_msg_get_payload(msg, &pkt_len);

	uint32_t verdict = NF_REPEAT;
	const uint32_t non_verdict_mask = ~(VERDICT_MASK << VERDICT_OFFSET);


	// Make the decision
	mark = (verdict & non_verdict_mask) | (decide(hw_addr, pkt, pkt_len, mark, zextmark) << VERDICT_OFFSET);

	nfnl_queue_msg_set_family(response, family);
	nfnl_queue_msg_set_group(response, QUEUE);
	nfnl_queue_msg_set_packetid(response, id);
	nfnl_queue_msg_set_verdict(response, verdict);
	//nfnl_queue_msg_set_mark(response, mark);
	nfnl_queue_msg_set_zextmark(response, zextmark);

	/*
	 * Most of the time the real skysniffer does just
	 * nfnl_queue_msg_send_verdict (without the payload), but sometimes
	 * also overwriting the packet content.
	 */
	CHECK_N(nfnl_queue_msg_send_verdict_payload(q_sock, response, pkt, pkt_len));
}

static int q_cback(struct nl_msg *msg, void *unused) {
	(void) unused;
	CHECK_N(nl_msg_parse(msg, q_parse, NULL));
	return NL_STOP;
}

static void format_addr(char *dst, struct nl_addr *addr) {
	if (!addr) {
		strcpy(dst, ":-(");
		return;
	}
	size_t len = nl_addr_get_len(addr);
	int af;
	switch (len) {
		case 4:
			af = AF_INET;
			break;
		case 16:
			af = AF_INET6;
			break;
		default:
			strcpy(dst, "AF?");
			return;
	}
	inet_ntop(af, nl_addr_get_binary_addr(addr), dst, MAX_ADDR_LEN);
}

static void ct_parse(struct nl_object *obj, void *unused) {
	struct nfnl_ct *event = (void *) obj;
	const char *proto;
	switch (nfnl_ct_get_proto(event)) {
		case IPPROTO_TCP:
			proto = "TCP";
			break;
		case IPPROTO_UDP:
			proto = "UDP";
			break;
		default:
			proto = "???";
			break;
	}
	const char *family;
	switch (nfnl_ct_get_family(event)) {
		case AF_INET:
			family = "IPv4";
			break;
		case AF_INET6:
			family = "IPv6";
			break;
		default:
			family = "????";
			break;
	}
	unsigned mark = nfnl_ct_test_mark(event) ? nfnl_ct_get_mark(event) : 0;
	unsigned zextmark = nfnl_ct_test_zextmark(event) ? nfnl_ct_get_zextmark(event) : 0;
	long long pkts_orig = nfnl_ct_test_packets(event, 0) ? (long long) nfnl_ct_get_packets(event, 0) : -1LL;
	long long pkts_reply = nfnl_ct_test_packets(event, 1) ? (long long) nfnl_ct_get_packets(event, 1) : -1LL;
	char src[MAX_ADDR_LEN];
	char dst[MAX_ADDR_LEN];
	format_addr(src, nfnl_ct_get_src(event, 0));
	format_addr(dst, nfnl_ct_get_dst(event, 0));
	// Could extract more info like IP addresses, but they are that's just
	// repetitive work and they are in the basic package of conntrack, so
	// not interesting.
	printf("%s/%s with mark %08x, zextmark %08x and %lld/%lld packets from %s to %s\n", family, proto, mark, zextmark, pkts_orig, pkts_reply, src, dst);
}

static int ct_cback(struct nl_msg *msg, void *unused) {
	(void) unused;
	struct nlmsghdr *hdr = nlmsg_hdr(msg);
	int flags = hdr->nlmsg_flags;
	enum cntl_msg_types type = (enum cntl_msg_types) NFNL_MSG_TYPE(hdr->nlmsg_type);
	if (type == IPCTNL_MSG_CT_DELETE) {
		printf("Delete conntrack event\n");
	} else if (type == IPCTNL_MSG_CT_NEW) {
		if (flags & (NLM_F_CREATE|NLM_F_EXCL)) {
			printf("New conntrack event\n");
		} else {
			printf("Update conntrack event\n");
		}
	} else {
		printf("Unknown conntrack event\n");
		return NL_STOP;
	}
	CHECK_N(nl_msg_parse(msg, &ct_parse, NULL));
	return NL_STOP;
}

int main() {
	// Prepare the conntrack connection
	struct nl_sock *ct_sock = nl_socket_alloc();
	CHECK(ct_sock);
	nl_join_groups(ct_sock, CONNTRACK_GROUPS);
	nl_socket_disable_seq_check(ct_sock);
	CHECK_N(nl_connect(ct_sock, NETLINK_NETFILTER));
	CHECK_N(nl_socket_set_nonblocking(ct_sock));
	CHECK_N(nl_socket_modify_cb(ct_sock, NL_CB_VALID, NL_CB_CUSTOM, &ct_cback, NULL));
	size_t bufsize = BUFSIZE;
	int ct_fd = nl_socket_get_fd(ct_sock);
	CHECK_N(setsockopt(ct_fd, SOL_SOCKET, SO_RCVBUFFORCE, &bufsize, sizeof bufsize));

	// Prepare the NFQUEUE connection
	CHECK(response = nfnl_queue_msg_alloc());

	CHECK(q_sock = nfnl_queue_socket_alloc());
	nl_socket_disable_seq_check(q_sock);
	CHECK_N(nl_connect(q_sock, NETLINK_NETFILTER));
	CHECK_N(nl_socket_set_nonblocking(q_sock));
	CHECK_N(nfnl_queue_pf_unbind(q_sock, FAMILY));
	CHECK_N(nfnl_queue_pf_bind(q_sock, FAMILY));

	struct nfnl_queue *queue = nfnl_queue_alloc();
	CHECK(queue);

	nfnl_queue_set_group(queue, QUEUE);
	nfnl_queue_set_copy_mode(queue, NFNL_QUEUE_COPY_PACKET);
	nfnl_queue_set_copy_range(queue, MAX_PKT_SIZE);
	CHECK_N(nfnl_queue_create(q_sock, queue));

	int q_fd = nl_socket_get_fd(q_sock);

	CHECK_N(nl_socket_modify_cb(q_sock, NL_CB_VALID, NL_CB_CUSTOM, &q_cback, NULL));
	int i = 1;
	CHECK_N(setsockopt(q_fd, SOL_NETLINK, NETLINK_NO_ENOBUFS, &i, sizeof i));
	CHECK_N(setsockopt(q_fd, SOL_SOCKET, SO_RCVBUFFORCE, &bufsize, sizeof bufsize));

	// Stuff both into an epoll, so we can multiplex
	int epoll = epoll_create(42);
	CHECK_N(epoll);
	struct epoll_event ev = {
		.events = EPOLLIN,
		.data = {
			.ptr = ct_sock
		}
	};
	CHECK_N(epoll_ctl(epoll, EPOLL_CTL_ADD, ct_fd, &ev));

	ev.data.ptr = q_sock;
	CHECK_N(epoll_ctl(epoll, EPOLL_CTL_ADD, q_fd, &ev));

	for (EVER) {
		int ready = epoll_wait(epoll, &ev, 1, -1);
		CHECK_N(ready);
		if (ready == 0) {
			continue;
		}

		int err = nl_recvmsgs_default(ev.data.ptr);
		if (err < 0) {
			fprintf(stderr, "Err reading: %s/%d\n", nl_geterror(err), err);
		}
	}
}
