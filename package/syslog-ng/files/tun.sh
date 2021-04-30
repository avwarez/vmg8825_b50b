#!/bin/sh

if grep -q '3.4.11' /proc/version && echo $?; then
insmod /lib/modules/3.4.11/tun.ko
fi

