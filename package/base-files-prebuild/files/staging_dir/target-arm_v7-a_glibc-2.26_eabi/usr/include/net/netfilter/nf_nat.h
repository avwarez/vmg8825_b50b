#ifndef _NETFILTER_NF_NAT_H
#define _NETFILTER_NF_NAT_H

#include <linux/netfilter.h>
#include <linux/netfilter/nf_conntrack_tuple_common.h>

#define NF_NAT_RANGE_MAP_IPS		1
#define NF_NAT_RANGE_PROTO_SPECIFIED	2
#define NF_NAT_RANGE_PROTO_RANDOM	4
#define NF_NAT_RANGE_PERSISTENT		8

struct nf_nat_ipv4_range {
	unsigned int			flags;
	__be32				min_ip;
	__be32				max_ip;
	union nf_conntrack_man_proto	min;
	union nf_conntrack_man_proto	max;

#if 1 /* Support one-to-one port mapping. __TELEFONICA__, ZyXEL Stan Su, 20120307. */
	/* mappingFlag is 1, if it needs to do one-to-one port mapping. */
	unsigned int mappingFlag;

	/* Record external port information. */
	union nf_conntrack_man_proto mappingMin, mappingMax;
#endif
};

struct nf_nat_ipv4_multi_range_compat {
	unsigned int			rangesize;
	struct nf_nat_ipv4_range	range[1];
};

struct nf_nat_range {
	unsigned int			flags;
	union nf_inet_addr		min_addr;
	union nf_inet_addr		max_addr;
	union nf_conntrack_man_proto	min_proto;
	union nf_conntrack_man_proto	max_proto;
#if 1 /* Support one-to-one port mapping. __TELEFONICA__, ZyXEL Stan Su, 20120307. */
    /* mappingFlag is 1, if it needs to do one-to-one port mapping. */
    unsigned int mappingFlag;

    /* Record external port information. */
    union nf_conntrack_man_proto mappingMin, mappingMax;
#endif
};

#endif /* _NETFILTER_NF_NAT_H */
