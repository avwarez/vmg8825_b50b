#!/bin/sh

if [[ "$1" == "" ]] ; then
	echo "Please specify the project name!"
	exit 0
fi

P=$1

echo "P=$P"

if [ ! -e $TOPDIR/configs/$P/platform.defconfig ] || [ ! -e $TOPDIR/configs/$P/project.defconfig ] ; then
	echo "copy $TOPDIR/configs/$P/$P.defconfig to .config!"
	cp $TOPDIR/configs/$P/$P.defconfig $TOPDIR/.config
else
	echo "merge $TOPDIR/configs/$P/platform.defconfig and $TOPDIR/configs/$P/project.defconfig to .config!"
	cat $TOPDIR/configs/$P/platform.defconfig $TOPDIR/configs/$P/project.defconfig > $TOPDIR/.config
fi
if [ -e $TOPDIR/configs/$P/external_toolchain.defconfig ] ; then
	echo "merge $TOPDIR/configs/$P/external_toolchain.defconfig to .config!"
	cat $TOPDIR/configs/$P/external_toolchain.defconfig >> $TOPDIR/.config
	if [ $(grep CONFIG_TARGET_brcm963xx=y $TOPDIR/.config) ] ; then
		$TOPDIR/scripts/private/zyxel/install_toolchain.sh $TOPDIR/dl/private brcm
	fi
	if [ $(grep CONFIG_TARGET_en75xx=y $TOPDIR/.config) ] ; then
		$TOPDIR/scripts/private/zyxel/install_toolchain.sh $TOPDIR/dl/private ecnt
	fi
fi


if [[ "$P" == "ipq807x" ]] ; then
	echo "QCA PLATFORM, use right version."
	rm -rf $TOPDIR/include $TOPDIR/scripts
	cp -rf $TOPDIR/include_qca $TOPDIR/include
	cp -rf $TOPDIR/scripts_qca $TOPDIR/scripts
fi
