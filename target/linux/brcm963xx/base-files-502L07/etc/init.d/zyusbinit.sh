#!/bin/sh
if [ -e /proc/zyxel/usb_support ]
then
	USB_CHECK=`cat /proc/zyxel/usb_support`
	if [ "$USB_CHECK" == "1" ]
	then
		echo "The device support usb!"
	else
		echo "The device does not support usb!"
		exit 0
	fi
else
	echo "The device support usb!"
fi

echo -e "\033[1;34mInitial USB driver...\033[0m"
KERNELVER=`uname -r`

#load usb modules
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/usb-common.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/usb-common.ko
 test -e /lib/modules/$KERNELVER/exfat.ko && insmod /lib/modules/$KERNELVER/exfat.ko
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/core/usbcore.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/core/usbcore.ko
 if [ "$1" != "usb30disable" ]; then
 	test -e /lib/modules/$KERNELVER/kernel/drivers/usb/host/xhci-hcd.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/host/xhci-hcd.ko
	test -e /lib/modules/$KERNELVER/kernel/drivers/usb/host/xhci-plat-hcd.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/host/xhci-plat-hcd.ko
 fi
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/host/ehci-hcd.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/host/ehci-hcd.ko
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/host/ehci-platform.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/host/ehci-platform.ko
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/host/ohci-hcd.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/host/ohci-hcd.ko
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/host/ohci-platform.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/host/ohci-platform.ko
 test -e /lib/modules/$KERNELVER/kernel/arch/arm/plat-bcm63xx/bcm_usb.ko && insmod /lib/modules/$KERNELVER/kernel/arch/arm/plat-bcm63xx/bcm_usb.ko
 mount --bind /dev/bus /proc/bus
 ln -s /sys/kernel/debug/usb/devices /proc/bus/usb/devices
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/class/usblp.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/class/usblp.ko
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/storage/usb-storage.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/storage/usb-storage.ko
 test -e /lib/modules/$KERNELVER/kernel/drivers/usb/storage/uas.ko && insmod /lib/modules/$KERNELVER/kernel/drivers/usb/storage/uas.ko
 test -e /lib/modules/$KERNELVER/btusbdrv.ko && insmod /lib/modules/$KERNELVER/btusbdrv.ko
 test -e /lib/modules/$KERNELVER/mii.ko && insmod /lib/modules/$KERNELVER/mii.ko

#EJECT need
 test -e /lib/modules/$KERNELVER/cdrom.ko && insmod /lib/modules/$KERNELVER/cdrom.ko
 test -e /lib/modules/$KERNELVER/isofs.ko && insmod /lib/modules/$KERNELVER/isofs.ko
 
