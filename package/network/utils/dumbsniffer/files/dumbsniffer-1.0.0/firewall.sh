#!/bin/sh

set -ex

# Configuration
OFFSET=12
MASK=$(( 0xFF << $OFFSET ))
REFUSE=$(( 1 << $OFFSET ))
BYPASS=$(( 2 << $OFFSET ))
OK=$(( 3 << $OFFSET ))
QUEUE=1

if [ "$1" = debug ] ; then
	# If running on a full-blown computer, it is better to use this
	DEBUG=true
else
	DEBUG=false
fi

# To delete all the marks from previous tests
conntrack --update -m 0/$MASK || true

iptables -t mangle -N skysniffer-restore-mark || iptables -t mangle -F skysniffer-restore-mark
#iptables -t mangle -A skysniffer-restore-mark -j CONNMARK --restore-mark --mask $MASK
iptables -t mangle -A skysniffer-restore-mark -j CONNZEXTMARK --restore-mark --mask $MASK
iptables -t mangle -D PREROUTING -j skysniffer-restore-mark || true
iptables -t mangle -I PREROUTING -j skysniffer-restore-mark
iptables -t mangle -D OUTPUT -j skysniffer-restore-mark || true
iptables -t mangle -I OUTPUT -j skysniffer-restore-mark

iptables -N skysniffer || iptables -F skysniffer
iptables -A skysniffer -m zextmark --mark $OK/$MASK -j RETURN
iptables -A skysniffer -p tcp --sport 22 -j RETURN
iptables -A skysniffer -p tcp --dport 22 -j RETURN
iptables -A skysniffer -s 127.0.0.1 -j RETURN
# iptables -A skysniffer -m mark '!' --mark 0/$MASK -j CONNMARK --save-mark --mask $MASK
iptables -A skysniffer -m zextmark '!' --mark 0/$MASK -j CONNZEXTMARK --save-mark --mask $MASK
iptables -A skysniffer -m mark '!' --mark 0/$MASK -j CONNZEXTMARK --save-mark --mask $MASK
iptables -A skysniffer -m zextmark --mark $REFUSE/$MASK -j REJECT
iptables -A skysniffer -m mark --mark $REFUSE/$MASK -j REJECT
iptables -A skysniffer -m zextmark --mark $BYPASS/$MASK -j RETURN
iptables -A skysniffer -m mark --mark $BYPASS/$MASK -j RETURN
if $DEBUG ; then
	iptables -A skysniffer -j ZEXTMARK --set-mark 42
	iptables -A skysniffer -j MARK --set-mark 420
	iptables -A skysniffer -j NFQUEUE --queue-num $QUEUE --queue-bypass
else
	iptables -A skysniffer -j ZEXTMARK --set-mark 42
	iptables -A skysniffer -j MARK --set-mark 420
	iptables -A skysniffer -j NFQUEUE --queue-num $QUEUE # --queue-bypass
fi

iptables -D FORWARD -j skysniffer || true
iptables -I FORWARD -j skysniffer
if $DEBUG ; then
	iptables -D INPUT -j skysniffer || true
	iptables -I INPUT -j skysniffer
	iptables -D OUTPUT -j skysniffer || true
	iptables -I OUTPUT -j skysniffer
fi
