#!/bin/sh

case "$1" in
    start)
        echo "net-snmp-zcfgd (service daemon) start ..."
        net-snmp-zcfgd &
        exit 0
        ;;

    stop)
        echo "net-snmp-zcfgd (service daemon) stop ..."
        kill `pidof net-snmp-zcfgd`
        exit 0
        ;;

    restart)
        echo "net-snmp-zcfgd (service daemon) restart ..."
        kill `pidof net-snmp-zcfgd`
        sleep 2
        net-snmp-zcfgd &
        exit 0
        ;;

    *)
        echo "usage: $0 {start|stop|restart}" >&2
        exit 1
        ;;
esac
exit 0
