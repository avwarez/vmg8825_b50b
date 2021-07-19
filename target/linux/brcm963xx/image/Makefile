# 
# Copyright (C) 2006-2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/image.mk
include $(INCLUDE_DIR)/zyxel-zy_feature_bits.mk

CONFIG_BRCM_CFE_BOOT_FROM_NAND=y
ifeq ($(CONFIG_BRCM_CFE_BOOT_FROM_NAND),y)
-include $(BCM_BUILD_DIR)/make.common
endif
SQUASHFS_BLOCKSIZE = 64k
SQUASHFSOPT = -b 64k

####export "ARCH_ENDIAN" for BCM SDK 416L01RC1 hosttool "bcmImageMaker" compatible with old version tool##############
ifeq ($(CONFIG_BIG_ENDIAN),y)
export ARCH_ENDIAN=big
SUMTOOLOPT=-b
TOOL_ENDIAN=
else
export ARCH_ENDIAN=little
SUMTOOLOPT=-l
TOOL_ENDIAN=-e little
endif

ifeq ($(CONFIG_FILL_IN_PARTITION_INFO_INTO_NVRAM),y)
export FLASH_TOTAL_SIZE=$(CONFIG_TARGET_NAND_FLASH_TOTAL_SIZE)
else
export FLASH_TOTAL_SIZE=0
endif

FLASHBLK_SIZE=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_FLASHBLK_SIZE))
JFFS2_BLOCKSIZE:=$(FLASHBLK_SIZE)k
SUMTOOL_BLOCKSIZE:=$(FLASHBLK_SIZE)KiB

UBIFS_BLOCKSIZE:=$(FLASHBLK_SIZE)k
UBIFS_MAX_LEB_COUNT:=688

#depend on blocksize to set page size
ifeq ("$(FLASHBLK_SIZE)","128")
UBIFS_PAGESIZE=2048
endif
ifeq ("$(FLASHBLK_SIZE)","256")
UBIFS_PAGESIZE=4096
endif
ifeq ("$(FLASHBLK_SIZE)","512")
UBIFS_PAGESIZE=4096
endif
ifeq ("$(FLASHBLK_SIZE)","1024")
UBIFS_PAGESIZE=8192
endif
#caclulate LEB eraseblock size, transfer block to bytes - 2 page header(EC & VID)
UBIFS_LEB_BLOCKSIZE_BYTES=`expr $(FLASHBLK_SIZE) \* 1024 - 2 \* $(UBIFS_PAGESIZE)`

# Get bootloader image size in kB.
ifneq ($(call qstrip,$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BTRM_BOOT_ONLY))),)
# Broadcom new mechanism, bootloader(bootrom+cferom) will occupy more than one block
BOOTLOADER_IMAGE_SIZE=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BTRM_NAND_BOOT_PARTITION_SIZE))
UNSECUREHDR="--unsecurehdr"
else
# default bootloader will occupy only one block.
BOOTLOADER_IMAGE_SIZE=$(FLASHBLK_SIZE)
UNSECUREHDR=""
endif

DDRTYPE=""
#CONFIG_BRCMSDK502L06_BRCM_CHIP="63158"
ifneq ($(findstring _$(call qstrip,$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_CHIP)))_,_63158_47622_),)
# --ddrtype DDR3 --unsecurehdr ;  
#CONFIG_BRCMSDK502L06_BUILD_CFE_DDR4 
ifneq ($(call qstrip,$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BUILD_CFE_DDR4))),)
DDRTYPE="--ddrtype DDR4 "
else
DDRTYPE="--ddrtype DDR3 "
endif
endif

# __zy_bsp__ >>>
ZYBSP_BCM_SDK_VER_CHK := $(findstring $(CONFIG_BRCM_SDK_VERSION),"502L04" "502L05" "502L06" "502L07")
ifneq ($(ZYBSP_BCM_SDK_VER_CHK),)
ZYBSP_BCM_SDK_VER=502L0X
CONFIG_BRCM963xx_SDK_VER_502L0X=y
endif
# __zy_bsp__ <<<

ifneq ($(call qstrip,$(CONFIG_BRCM963xx_SDK_VER_416L04) $(CONFIG_BRCM963xx_SDK_VER_416L05) $(CONFIG_BRCM963xx_SDK_VER_502L0X)),)
ifneq ($(call qstrip,$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BUILD_NOR_KERNEL_LZ4))),)
KERNEL_COMPRESSION=lz4
KERNEL_FILE_TYPE=lz4
else
KERNEL_COMPRESSION=lzma
KERNEL_FILE_TYPE=lz
endif
else
KERNEL_COMPRESSION=lzma
KERNEL_FILE_TYPE=lz
endif

#HOSTTOOLS_DIR=$(BCM_BUILD_DIR)/hostTools
HOSTTOOLS_DIR=$(STAGING_DIR_HOST)/bin/$(shell echo $(CONFIG_BRCM_SDK_VERSION))

# Get MRD information, used for hosttool; do $(shell echo xxxx) twice because need to remove quotes
export BRCM_VOICE_BOARD_ID=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_VOICE_BOARD_ID))
export VENDORNAME=$(call qstrip,$(CONFIG_MRD_VENDOR_NAME))
export PRODUCTNAME=$(call qstrip,$(CONFIG_MRD_PRODUCT_NAME))
export SERIALNUMBER=$(call qstrip,$(CONFIG_MRD_SERIAL_NO))
export FIRMWARE_VERSION=$(call qstrip,$(CONFIG_ZYXEL_FIRMWARE_VERSION))
export ZYXEL_MODEL_ID=$(call qstrip,$(CONFIG_MRD_MODEL_ID))
export MAINFEATUREBIT=$(call qstrip,$(CONFIG_MRD_MAIN_FEATURE_BIT))
export DEBUGBIT=$(call qstrip,$(CONFIG_MRD_DEBUG_BIT))
export COUNTRYCODE=$(call qstrip,$(CONFIG_MRD_COUNTRY_CODE))
export NVRAM_MEMORY_CONFIG=$(call qstrip,$(CONFIG_BCM63138_NVRAM_MEMORY_CONFIG))
export NVRAM_MC_MEMORY_ALLOCATION=$(call qstrip,$(CONFIG_BCM63138_NVRAM_MC_MEMORY_ALLOCATION))
export NVRAM_TM_MEMORY_ALLOCATION=$(call qstrip,$(CONFIG_BCM63138_NVRAM_TM_MEMORY_ALLOCATION))
export NVRAM_DHD0_MEMORY_ALLOCATION=$(call qstrip,$(CONFIG_BCM63138_NVRAM_DHD0_MEMORY_ALLOCATION))
export NVRAM_DHD1_MEMORY_ALLOCATION=$(call qstrip,$(CONFIG_BCM63138_NVRAM_DHD1_MEMORY_ALLOCATION))
export NVRAM_DHD2_MEMORY_ALLOCATION=$(call qstrip,$(CONFIG_BCM63138_NVRAM_DHD2_MEMORY_ALLOCATION))
export BRCM_MISC1_PARTITION_SIZE=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_MISC1_PARTITION_SIZE))
export BRCM_MISC2_PARTITION_SIZE=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_MISC2_PARTITION_SIZE))
export BRCM_MISC3_PARTITION_SIZE=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_MISC3_PARTITION_SIZE))
export BRCM_MISC4_PARTITION_SIZE=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_MISC4_PARTITION_SIZE))
export BRCM_GPON_SERIAL_NUMBER=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_GPON_SERIAL_NUMBER))
export BRCM_GPON_PASSWORD=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_GPON_PASSWORD))
# bcmImageMaker need this parameter
export BIN_DIR
# __zy_bsp__ >>>
# Due to BRCM_AUXFS_PERCENT will be filter out by non-NOR flash (BRCM_FLASH_BUILD_NOR) at 502L05,
# we export it here for NAND flash.
ifeq ("$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_AUXFS_PERCENT))","")
BRCM_AUXFS_PERCENT=0
endif
# __zy_bsp__ <<<

# Get common options
ZYXEL_RAS_FORMAT=$($(shell echo CONFIG_BRCMSDK${CONFIG_BRCM_SDK_VERSION}_ZYXEL_RSA_FORMAT))

# For zytool generate multi zld.bin
ZYXEL_ZYTOOL_SCRIPT_DIR=$(TOPDIR)/target/linux/brcm963xx/$(SUBTARGET)

# For ubifs bootfs
TARGET_UBI_BOOTFS=$(BUILD_DIR)/bootfs

define Image/Build/multi_zld
	##doing zytool shell script
	if [ -e $(ZYXEL_ZYTOOL_SCRIPT_DIR)/zytool_multi_zld.sh ]; then \
	if [ -e $(HOSTTOOLS_DIR)/zytool ]; then \
	$(ZYXEL_ZYTOOL_SCRIPT_DIR)/zytool_multi_zld.sh $(HOSTTOOLS_DIR) $(1) $(BRCM_CHIP) $(ARCH_ENDIAN); \
	elif [ ! -e $(HOSTTOOLS_DIR)/zytool ]; then \
	echo "Please clean and rebuild host tools !!"; \
	exit -1; \
	fi \
	elif [ ! -e $(ZYXEL_ZYTOOL_SCRIPT_DIR)/zytool_multi_zld.sh ]; then \
	echo; \
	fi
endef


define Image/Build/merge_firmware
	echo;echo "!!! Package firmware for release !!!";echo
	mkdir -p $(BIN_DIR)/zyxel/
ifneq ($(call qstrip, $(CONFIG_BRCM963xx_SDK_VER_502L0X)), )
	###create fcs image dir for pureUbi and JFFS2withUBI
	mkdir -p $(BIN_DIR)/zyxel_pureUbi/
	mkdir -p $(BIN_DIR)/zyxel_ubi/
endif
	# [BuildMergeFirmware]Generate the tagged image with BCM proprietary tool "bcmImageMaker/bcmImageBuilder"
ifeq ($(ZYXEL_RAS_FORMAT), y)
	##doing ZyXEL image formate
	$(call Image/mkfs/jffs2/sub/original,$(JFFS2_BLOCKSIZE))
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --flashtotalsize $(FLASH_TOTAL_SIZE) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --kernelimg $(KERNEL_BUILD_DIR)/vmlinux.lz --rootfs $(KERNEL_BUILD_DIR)/root.jffs2-$(JFFS2_BLOCKSIZE) --fake_rootfs $(KERNEL_BUILD_DIR)/fake_root.jffs2-$(JFFS2_BLOCKSIZE) --image $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-jffs2-$(JFFS2_BLOCKSIZE)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-jffs2-$(JFFS2_BLOCKSIZE).bin $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR))

ifneq ($(call qstrip, $(CONFIG_BRCM963xx_SDK_VER_502L0X)), )
###START pureUBI, JFFS2withUBI
	$(call Image/mkfs/ubifs/sub/original,$(UBIFS_BLOCKSIZE))
	#pureUBI
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --flashtotalsize $(FLASH_TOTAL_SIZE) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --kernelimg $(KERNEL_BUILD_DIR)/vmlinux.lz --rootfs $(KERNEL_BUILD_DIR)/root.pureubi-$(UBIFS_BLOCKSIZE) --fake_rootfs $(KERNEL_BUILD_DIR)/fake_root.ubifs-$(UBIFS_BLOCKSIZE) --image $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-pureubi-$(UBIFS_BLOCKSIZE)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-pureubi-$(UBIFS_BLOCKSIZE).bin --ubionlyimage $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR))
	
	#JFFS2 bootfs + UBI rootfs
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker  --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin  --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --flashtotalsize $(FLASH_TOTAL_SIZE) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --kernelimg $(KERNEL_BUILD_DIR)/vmlinux.lz --ubifs --bootfs $(KERNEL_BUILD_DIR)/bootfs$(FLASHBLK_SIZE)kb.img --rootfs $(KERNEL_BUILD_DIR)/root.ubifs-$(UBIFS_BLOCKSIZE) --fake_rootfs $(KERNEL_BUILD_DIR)/fake_root.ubifs-$(UBIFS_BLOCKSIZE) --image $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-ubifs-$(UBIFS_BLOCKSIZE)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-ubifs-$(UBIFS_BLOCKSIZE).bin $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR))
###END pureUBI, JFFS2withUBI 
endif

else
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --rootfs $(KERNEL_BUILD_DIR)/root.jffs2-$(JFFS2_BLOCKSIZE) --image $(BIN_DIR)/zyxel/openwrt-nand-$(BOARDNAME)-jffs2-$(JFFS2_BLOCKSIZE)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-jffs2-$(JFFS2_BLOCKSIZE).bin $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR))
endif
	cp $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-jffs2-$(JFFS2_BLOCKSIZE).bin.w $(BIN_DIR)/zyxel/ras.bin
	dd if=$(BIN_DIR)/openwrt-nand-$(BOARDNAME)-jffs2-$(JFFS2_BLOCKSIZE)-cfe.bin.w of=$(BIN_DIR)/zyxel/zld.bin bs=1k count=$(BOOTLOADER_IMAGE_SIZE)
ifneq ($(call qstrip, $(CONFIG_BRCM963xx_SDK_VER_502L0X)), )
	### START pureUbi, JFFS2withUBI
	cp $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-pureubi-$(UBIFS_BLOCKSIZE).bin.w $(BIN_DIR)/zyxel_pureUbi/ras.bin
	dd if=$(BIN_DIR)/openwrt-nand-$(BOARDNAME)-pureubi-$(UBIFS_BLOCKSIZE)-cfe.bin.w of=$(BIN_DIR)/zyxel_pureUbi/zld.bin bs=1k count=$(BOOTLOADER_IMAGE_SIZE)
	cp $(BIN_DIR)/openwrt-nand-$(BOARDNAME)-ubifs-$(UBIFS_BLOCKSIZE).bin.w $(BIN_DIR)/zyxel_ubi/ras.bin
	dd if=$(BIN_DIR)/openwrt-nand-$(BOARDNAME)-ubifs-$(UBIFS_BLOCKSIZE)-cfe.bin.w of=$(BIN_DIR)/zyxel_ubi/zld.bin bs=1k count=$(BOOTLOADER_IMAGE_SIZE)
	###END pureUbi, JFFS2withUBI
endif
ifneq ($(call qstrip,$(CONFIG_BRCM963xx_SDK_VER_416L05) $(CONFIG_BRCM963xx_SDK_VER_502L0X)), )
	$(call Image/Build/multi_zld, $(BIN_DIR)/zyxel)
endif
ifneq ($(call qstrip, $(CONFIG_BRCM963xx_SDK_VER_502L0X)), )
	$(call Image/Build/multi_zld, $(BIN_DIR)/zyxel_pureUbi)
	$(call Image/Build/multi_zld, $(BIN_DIR)/zyxel_ubi)
endif
endef

define Image/Build/CFE
	$(if $(findstring jffs2, $(1)), \
	mkdir -p $(BIN_DIR)/zyxel/;)
	$(if $(findstring pureubi, $(1)), \
	mkdir -p $(BIN_DIR)/zyxel_pureUbi/;)
	$(if $(findstring ubifs, $(1)), \
	mkdir -p $(BIN_DIR)/zyxel_ubi/;)
	$(if $(findstring squbi, $(1)), \
	mkdir -p $(BIN_DIR)/zyxel_squbi/;)
	# [BuildCFE]Generate the tagged image with BCM proprietary tool "bcmImageMaker/bcmImageBuilder"
ifeq ($(CONFIG_BRCM_CFE_BOOT_FROM_NAND),y)
ifeq ($(ZYXEL_RAS_FORMAT), y)
	##doing ZyXEL image formate(including CFE)

	#pureUBI
	$(if $(findstring pureubi, $(1)), \
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --flashtotalsize $(FLASH_TOTAL_SIZE) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --kernelimg $(KERNEL_BUILD_DIR)/vmlinux.lz --rootfs $(KERNEL_BUILD_DIR)/root.$(1) --fake_rootfs $(KERNEL_BUILD_DIR)/fake_root.ubifs-$(UBIFS_BLOCKSIZE) --image $(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin --ubionlyimage $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR));)

	#squbi
	$(if $(findstring squbi, $(1)), \
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --flashtotalsize $(FLASH_TOTAL_SIZE) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --kernelimg $(KERNEL_BUILD_DIR)/vmlinux.lz --rootfs $(KERNEL_BUILD_DIR)/root.$(1) --fake_rootfs $(KERNEL_BUILD_DIR)/fake_root.squbi-$(UBIFS_BLOCKSIZE) --image $(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin --ubionlyimage $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR));)

	
	#JFFS2 bootfs + UBI rootfs
	$(if $(findstring ubifs, $(1)), \
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker  --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin  --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --flashtotalsize $(FLASH_TOTAL_SIZE) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --kernelimg $(KERNEL_BUILD_DIR)/vmlinux.lz --ubifs --bootfs $(KERNEL_BUILD_DIR)/bootfs$(FLASHBLK_SIZE)kb.img --rootfs $(KERNEL_BUILD_DIR)/root.$(1) --fake_rootfs $(KERNEL_BUILD_DIR)/fake_root.ubifs-$(UBIFS_BLOCKSIZE) --image $(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR));)

	#JFFS2
	$(if $(findstring jffs2, $(1)), \
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --flashtotalsize $(FLASH_TOTAL_SIZE) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --kernelimg $(KERNEL_BUILD_DIR)/vmlinux.lz --rootfs $(KERNEL_BUILD_DIR)/root.$(1) --fake_rootfs $(KERNEL_BUILD_DIR)/fake_root.jffs2-$(JFFS2_BLOCKSIZE) --image $(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR));)

else
#####else($(ZYXEL_RAS_FORMAT), y)
	$(HOSTTOOLS_DIR)/scripts/bcmImageMaker --cferom $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)rom.bin --blocksize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --bootofs $(FLASH_BOOT_OFS) --bootsize $(shell expr 1024 \* $(FLASHBLK_SIZE)) --rootfs $(KERNEL_BUILD_DIR)/root.$(1) --image $(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin --fsonly $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin $(call qstrip,$(DDRTYPE)) $(call qstrip,$(UNSECUREHDR))
#END ($(ZYXEL_RAS_FORMAT), y)
endif
	$(if $(findstring jffs2, $(1)), \
	cp $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin.w $(BIN_DIR)/zyxel/ras.bin
	dd if=$(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin.w of=$(BIN_DIR)/zyxel/zld.bin bs=1k count=$(BOOTLOADER_IMAGE_SIZE)
	$(call Image/Build/multi_zld, $(BIN_DIR)/zyxel);)
	$(if $(findstring pureubi, $(1)), \
	cp $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin.w $(BIN_DIR)/zyxel_pureUbi/ras.bin
	dd if=$(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin.w of=$(BIN_DIR)/zyxel_pureUbi/zld.bin bs=1k count=$(BOOTLOADER_IMAGE_SIZE)
	$(call Image/Build/multi_zld, $(BIN_DIR)/zyxel_pureUbi);)
	$(if $(findstring squbi, $(1)), \
	cp $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin.w $(BIN_DIR)/zyxel_squbi/ras.bin
	dd if=$(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin.w of=$(BIN_DIR)/zyxel_squbi/zld.bin bs=1k count=$(BOOTLOADER_IMAGE_SIZE)
	$(call Image/Build/multi_zld, $(BIN_DIR)/zyxel_pureUbi);)
	$(if $(findstring ubifs, $(1)), \
	cp $(BIN_DIR)/openwrt-nand-$(4)-$(1).bin.w $(BIN_DIR)/zyxel_ubi/ras.bin
	dd if=$(BIN_DIR)/openwrt-nand-$(4)-$(1)-cfe.bin.w of=$(BIN_DIR)/zyxel_ubi/zld.bin bs=1k count=$(BOOTLOADER_IMAGE_SIZE)

	$(call Image/Build/multi_zld, $(BIN_DIR)/zyxel_ubi);)

else
	$(HOSTTOOLS_DIR)/bcmImageBuilder --output $(BIN_DIR)/openwrt-$(4)-$(1).bin --chip $(3) --board $(2) --blocksize $(SQUASHFS_BLOCKSIZE) --image-version 4143GW2801456 --cfefile $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP).bin --rootfsfile $(BIN_DIR)/$(IMG_PREFIX)-root.$(1) --kernelfile $(KDIR)/vmlinux.lz
	cp $(BIN_DIR)/openwrt-$(4)-$(1).bin $(BIN_DIR)/zyxel/ras.bin
	cp $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP).bin $(BIN_DIR)/zyxel/zld.bin
	$(HOSTTOOLS_DIR)/bcmImageBuilder --output $(BIN_DIR)/openwrt-$(4)-$(1)-cfe.bin --chip $(3) --board $(2) --blocksize $(SQUASHFS_BLOCKSIZE) --image-version 4143GW2801456 --cfefile $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP).bin --rootfsfile $(KERNEL_BUILD_DIR)/root.$(1) --kernelfile $(KDIR)/vmlinux.lz --include-cfe
endif
endef

define Build/Clean
endef

define Image/mkfs/jffs2/sub/fake
	# Prepare a fake rootfs without default config and cferam.000(JFFS2 fake)
	rm -rf $(TARGET_DIR)_fake
	cp -afp $(TARGET_DIR) $(TARGET_DIR)_fake
	rm -f $(TARGET_DIR)_fake/etc/sysconfig.tar.gz $(TARGET_DIR)_fake/cferam.000
	rm -f $(TARGET_DIR)_fake/etc/zcfg_schema.tar.gz
	rm -f $(TARGET_DIR)_fake/etc/zcfg_defaultStr.bin
	rm -f $(TARGET_DIR)_fake/etc/zcfg_objName.bin
	rm -f $(TARGET_DIR)_fake/etc/zcfg_paramName.bin
	rm -rf $(TARGET_DIR)_fake/usr/lib/opkg

ifneq ($(call qstrip,$(CONFIG_KERNEL_JFFS2_SUMMARY)),y)
	$(STAGING_DIR_HOST)/bin/mkfs.jffs2 $(JFFS2OPTS) -e $(patsubst %k,%KiB,$(1)) -o $(KDIR)/fake_root.jffs2-$(1) -d $(TARGET_DIR)_fake -N $(BUILD_DIR)/nocomprlist -v 2>&1 1>/dev/null | awk '/^.+$$$$/'
else
	$(STAGING_DIR_HOST)/bin/mkfs.jffs2 $(JFFS2OPTS) -e $(patsubst %k,%KiB,$(1)) -o $(KDIR)/tmp_root.jffs2-$(1) -d $(TARGET_DIR)_fake -N $(BUILD_DIR)/nocomprlist -v 2>&1 1>/dev/null | awk '/^.+$$$$/' 
	$(STAGING_DIR_HOST)/bin/sumtool $(SUMTOOLOPT) -p -i $(KDIR)/tmp_root.jffs2-$(1) -o $(KDIR)/fake_root.jffs2-$(1) -e $(SUMTOOL_BLOCKSIZE) -n
	rm $(KDIR)/tmp_root.jffs2-$(1)
endif

endef

define Image/mkfs/jffs2/fcs_RD0_checksum
	$(call Image/mkfs/jffs2/sub/fake,$(JFFS2_BLOCKSIZE))
endef

define Image/mkfs/jffs2/sub/original

ifeq ("$(call qstrip,$(ZYXEL_RAS_FORMAT))","y")
	$(HOSTTOOLS_DIR)/zyfwinfo -f $(TARGET_DIR)/cferam.000 -s -k $(KERNEL_BUILD_DIR)/vmlinux.lz -r $(KDIR)/fake_root.jffs2-$(1) $(TOOL_ENDIAN)
endif
	touch -a -m -t 197001010000.00 $(TARGET_DIR)/cferam.000
	# FIXME: removing this line will cause strange behaviour in the foreach loop below
ifneq ($(call qstrip,$(CONFIG_KERNEL_JFFS2_SUMMARY)),y)
	$(STAGING_DIR_HOST)/bin/mkfs.jffs2 $(JFFS2OPTS) -e $(patsubst %k,%KiB,$(1)) -o $(KDIR)/root.jffs2-$(1) -d $(TARGET_DIR) -N $(BUILD_DIR)/nocomprlist -v 2>&1 1>/dev/null | awk '/^.+$$$$/'
else
	$(STAGING_DIR_HOST)/bin/mkfs.jffs2 $(JFFS2OPTS) -e $(patsubst %k,%KiB,$(1)) -o $(KDIR)/tmp_root.jffs2-$(1) -d $(TARGET_DIR) -N $(BUILD_DIR)/nocomprlist -v 2>&1 1>/dev/null | awk '/^.+$$$$/'
	$(STAGING_DIR_HOST)/bin/sumtool $(SUMTOOLOPT) -p -i $(KDIR)/tmp_root.jffs2-$(1) -o $(KDIR)/root.jffs2-$(1) -e $(SUMTOOL_BLOCKSIZE) -n
	rm $(KDIR)/tmp_root.jffs2-$(1)
endif

endef

define Image/mkfs/jffs2/sub
	# Add nocomprlist for compress whole rootfs but those two image cferam.000 and vmlinux.lz
	echo -e "/cferam.000" > $(BUILD_DIR)/nocomprlist
	if [ -e $(TARGET_DIR)/.ethWanAsLan ]; then \
		echo -e "/.ethWanAsLan" >> $(BUILD_DIR)/nocomprlist; \
	fi
	echo -e "/vmlinux.lz" >> $(BUILD_DIR)/nocomprlist
	if [ -e $(TARGET_DIR)/$(BRCM_DTB) ]; then \
		echo -e "/$(BRCM_DTB)" >> $(BUILD_DIR)/nocomprlist; \
	fi

	$(call Image/mkfs/jffs2/sub/original,$(1))

	$(call Image/Build,jffs2-$(1))
	# no need to remove it
	#rm -rf $(BUILD_DIR)/nocomprlist
endef

ifneq ($(CONFIG_TARGET_ROOTFS_SQUASHFS),)
define Image/mkfs/squashfs
	@mkdir -p $(TARGET_DIR)/overlay
	$(STAGING_DIR_HOST)/bin/mksquashfs4 $(TARGET_DIR) $(KDIR)/root.squashfs -nopad -noappend -root-owned -comp $(SQUASHFSCOMP) $(SQUASHFSOPT) -processors $(if $(CONFIG_PKG_BUILD_JOBS),$(CONFIG_PKG_BUILD_JOBS),1)
	dd if=$(KDIR)/root.squashfs of=$(BIN_DIR)/$(IMG_PREFIX)-root.squashfs bs=$(SQUASHFS_BLOCKSIZE) conv=sync
	$(call Image/Build,squashfs)
endef
endif

ifneq ($(CONFIG_TARGET_ROOTFS_UBIFS),)
define Image/mkfs/ubifs/sub/fake
	# Prepare a fake rootfs without default config and cferam.000(UBI fake)
	rm -rf $(TARGET_DIR)_fake
	cp -afp $(TARGET_DIR) $(TARGET_DIR)_fake
	rm -f $(TARGET_DIR)_fake/etc/sysconfig.tar.gz $(TARGET_DIR)_fake/cferam.000
	rm -f $(TARGET_DIR)_fake/etc/zcfg_schema.tar.gz
	rm -f $(TARGET_DIR)_fake/etc/zcfg_defaultStr.bin
	rm -f $(TARGET_DIR)_fake/etc/zcfg_objName.bin
	rm -f $(TARGET_DIR)_fake/etc/zcfg_paramName.bin
	rm -rf $(TARGET_DIR)_fake/usr/lib/opkg

	#reduce ubi ras.bin size
	rm -f $(TARGET_DIR)_fake/vmlinux.$(KERNEL_FILE_TYPE)

	$(STAGING_DIR_HOST)/bin/mkfs.ubifs $(UBIFS_OPTS) -c $(UBIFS_MAX_LEB_COUNT) -m $(UBIFS_PAGESIZE) -e $(UBIFS_LEB_BLOCKSIZE_BYTES) -o $(KDIR)/fake_root.ubifs-$(1) -r $(TARGET_DIR)_fake
	## add squbi
	echo -e "[ubifs]"                 > $(KDIR)/squbi.ini
	echo -e "mode=ubi"               >> $$(KDIR)/squbi.ini
	echo -e "image=$(KDIR)/squashfs_fake.img" >> $(KDIR)/squbi.ini
	echo -e "vol_id=0"               >> $(KDIR)/squbi.ini
	echo -e "vol_type=static"        >> $(KDIR)/squbi.ini
	echo -e "vol_name=rootfs_squashfs"  >> $(KDIR)/squbi.ini
	
	fakeroot $(STAGING_DIR_HOST)/bin/mksquashfs4 $(TARGET_DIR)_fake $(KDIR)/squashfs_fake.img -noappend -all-root -comp xz
    
	#restore vmlinux.lz for JFFS2 use
	cp $(KDIR)/vmlinux.$(KERNEL_FILE_TYPE) $(TARGET_DIR)_fake
# END Image/mkfs/ubifs/sub/fake
endef

define Image/mkfs/ubifs/fcs_RD0_checksum
	$(call Image/mkfs/ubifs/sub/fake,$(UBIFS_BLOCKSIZE))
endef

define Image/mkfs/ubifs/sub/original
# for make fcs use
ifeq ("$(call qstrip,$(ZYXEL_RAS_FORMAT))","y")
	$(HOSTTOOLS_DIR)/zyfwinfo -f $(TARGET_DIR)/cferam.000 -s -k $(KERNEL_BUILD_DIR)/vmlinux.lz -r $(KDIR)/fake_root.ubifs-$(UBIFS_BLOCKSIZE) $(TOOL_ENDIAN)
endif
	touch -a -m -t 197001010000.00 $(TARGET_DIR)/cferam.000

	#zyfwinfo will update FirmwareVersion string in cferam.000, so update it to bootfs for filestruct_full.bin use
	cp $(TARGET_DIR)/cferam.000 $(TARGET_UBI_BOOTFS)

	fakeroot ./buildUBI -u $(KDIR)/ubinize.cfg -m $(KDIR)/metadata.bin -f $(KDIR)/filestruct_full.bin -t $(TARGET_UBI_BOOTFS) -y $(KDIR)/rootfs.ubifs

	#for pureUbi rootfs
	fakeroot $(STAGING_DIR_HOST)/bin/ubinize -v -o $(KDIR)/root.pureubi-$(UBIFS_BLOCKSIZE) -m $(UBIFS_PAGESIZE) -p $(patsubst %k,%KiB,$(UBIFS_BLOCKSIZE)) $(KDIR)/ubinize.cfg
	
	#for JFFS2withUBI rootfs
	# JFFS2withUBI save cferam in bootfs
	fakeroot $(STAGING_DIR_HOST)/bin/mkfs.jffs2 $(JFFS2OPTS) -p -n -e $(patsubst %k,%KiB,$(UBIFS_BLOCKSIZE)) -r $(TARGET_UBI_BOOTFS) -o $(KDIR)/ibootfs$(FLASHBLK_SIZE)kb.img -N $(BUILD_DIR)/nocomprlist
	fakeroot $(STAGING_DIR_HOST)/bin/sumtool $(SUMTOOLOPT) -p -i $(KDIR)/ibootfs$(FLASHBLK_SIZE)kb.img -o $(KDIR)/bootfs$(FLASHBLK_SIZE)kb.img -e $(SUMTOOL_BLOCKSIZE) -n
	rm -f $(KDIR)/ibootfs$(FLASHBLK_SIZE)kb.img
	
#END define Image/mkfs/ubifs/sub/original
endef

define Image/mkfs/ubifs

ifeq ("$(call qstrip,$(ZYXEL_RAS_FORMAT))","y")
	$(HOSTTOOLS_DIR)/zyfwinfo -f $(TARGET_DIR)/cferam.000 -s -k $(KERNEL_BUILD_DIR)/vmlinux.lz -r $(KDIR)/fake_root.ubifs-$(UBIFS_BLOCKSIZE) $(TOOL_ENDIAN)
endif
	touch -a -m -t 197001010000.00 $(TARGET_DIR)/cferam.000

	# START====Create boot file system dir
	rm -rf $(TARGET_UBI_BOOTFS)
	mkdir $(TARGET_UBI_BOOTFS)
	chmod 777 $(TARGET_UBI_BOOTFS)
	cp $(TARGET_DIR)/cferam.000 $(TARGET_UBI_BOOTFS)
	cp $(TARGET_DIR)/$(BRCM_DTB) $(TARGET_UBI_BOOTFS)
	cp $(KERNEL_BUILD_DIR)/vmlinux.lz $(TARGET_UBI_BOOTFS)

	mkdir -p $(TARGET_UBI_BOOTFS)/etc
	cp $(TARGET_DIR)/etc/image_version $(TARGET_UBI_BOOTFS)/etc

	echo -n "@(#) $$$$"imageversion:" " > $(TARGET_UBI_BOOTFS)/etc/image_ident
	cat $(TARGET_DIR)/etc/image_version | tr -d "\n" >> $(TARGET_UBI_BOOTFS)/etc/image_ident
	echo " $$$$" >> $(TARGET_UBI_BOOTFS)/etc/image_ident

	echo -n "@(#) $$$$"imageversion:" " >> $(TARGET_UBI_BOOTFS)/etc/image_ident
	cat $(TARGET_DIR)/etc/image_version | tr -d "\n" >> $(TARGET_UBI_BOOTFS)/etc/image_ident
	echo " $$$$" >> $(TARGET_UBI_BOOTFS)/etc/image_ident
	# END====Create boot file system dir

    #reduce ubi ras.bin size
	rm -f $(TARGET_DIR)/vmlinux.$(KERNEL_FILE_TYPE)
	rm -f $(TARGET_DIR)/cferam.000

	fakeroot $(STAGING_DIR_HOST)/bin/mkfs.ubifs $(UBIFS_OPTS) -c $(UBIFS_MAX_LEB_COUNT) -m $(UBIFS_PAGESIZE) -e $(UBIFS_LEB_BLOCKSIZE_BYTES) -o $(KDIR)/rootfs.ubifs -r $(TARGET_DIR)



	fakeroot ./buildUBI -u $(KDIR)/ubinize.cfg -m $(KDIR)/metadata.bin -f $(KDIR)/filestruct_full.bin -t $(TARGET_UBI_BOOTFS) -y $(KDIR)/rootfs.ubifs

	fakeroot $(STAGING_DIR_HOST)/bin/ubinize -v -o $(KDIR)/root.pureubi-$(UBIFS_BLOCKSIZE) -m $(UBIFS_PAGESIZE) -p $(patsubst %k,%KiB,$(UBIFS_BLOCKSIZE)) $(KDIR)/ubinize.cfg
	
	$(call Image/Build,pureubi-$(UBIFS_BLOCKSIZE))
	echo;echo "squbi part";echo
	fakeroot ./buildUBI -u $(KDIR)/fake_squbinize.cfg -m $(KDIR)/metadata.bin -f $(KDIR)/filestruct_full.bin -t $(TARGET_UBI_BOOTFS) -y $(KDIR)/squashfs_fake.img -s 1
	fakeroot $(STAGING_DIR_HOST)/bin/ubinize -v -o $(KDIR)/fake_root.squbi-$(UBIFS_BLOCKSIZE) -m $(UBIFS_PAGESIZE) -p $(patsubst %k,%KiB,$(UBIFS_BLOCKSIZE)) $(KDIR)/fake_squbinize.cfg
	
	echo -e "[ubifs]"                 > $(KDIR)/squbi.ini
	echo -e "mode=ubi"               >> $$(KDIR)/squbi.ini
	echo -e "image=$(KDIR)/squashfs.img" >> $(KDIR)/squbi.ini
	echo -e "vol_id=0"               >> $(KDIR)/squbi.ini
	echo -e "vol_type=static"        >> $(KDIR)/squbi.ini
	echo -e "vol_name=rootfs_squashfs"  >> $(KDIR)/squbi.ini
	
	fakeroot $(STAGING_DIR_HOST)/bin/mksquashfs4 $(TARGET_DIR) $(KDIR)/squashfs.img -noappend -all-root -comp xz
	fakeroot ./buildUBI -u $(KDIR)/squbinize.cfg -m $(KDIR)/metadata.bin -f $(KDIR)/filestruct_full.bin -t $(TARGET_UBI_BOOTFS) -y $(KDIR)/squashfs.img -s 1
	fakeroot $(STAGING_DIR_HOST)/bin/ubinize -v -o $(KDIR)/root.squbi-$(UBIFS_BLOCKSIZE) -m $(UBIFS_PAGESIZE) -p $(patsubst %k,%KiB,$(UBIFS_BLOCKSIZE)) $(KDIR)/squbinize.cfg
	$(call Image/Build,squbi-$(UBIFS_BLOCKSIZE))
	
	#restore vmlinux.lz, cferam.000 for JFFS2 use
	cp $(TARGET_UBI_BOOTFS)/vmlinux.$(KERNEL_FILE_TYPE) $(TARGET_DIR)
	cp $(TARGET_UBI_BOOTFS)/cferam.000 $(TARGET_DIR)
#### JFFS2 BootFS/UBI RootFS Start
#prepare config file for JFFS+UBI image
	echo -e "[ubifs]"                 > $(KDIR)/bootfsJFFS2_rootfsUbi.ini	
	echo -e "mode=ubi"               >> $(KDIR)/bootfsJFFS2_rootfsUbi.ini
	echo -e "image= $(KDIR)/rootfs.ubifs" >> $(KDIR)/bootfsJFFS2_rootfsUbi.ini
	echo -e "vol_id=0"               >> $(KDIR)/bootfsJFFS2_rootfsUbi.ini
	echo -e "vol_type=static"       >> $(KDIR)/bootfsJFFS2_rootfsUbi.ini
	echo -e "vol_name=rootfs_ubifs"  >> $(KDIR)/bootfsJFFS2_rootfsUbi.ini
#	echo -e "vol_flags=autoresize"   >> $(KDIR)/bootfsJFFS2_rootfsUbi.ini
	fakeroot $(STAGING_DIR_HOST)/bin/mkfs.jffs2 $(JFFS2OPTS) -p -n -e $(patsubst %k,%KiB,$(UBIFS_BLOCKSIZE)) -r $(TARGET_UBI_BOOTFS) -o $(KDIR)/ibootfs$(FLASHBLK_SIZE)kb.img -N $(BUILD_DIR)/nocomprlist
	fakeroot $(STAGING_DIR_HOST)/bin/sumtool $(SUMTOOLOPT) -p -i $(KDIR)/ibootfs$(FLASHBLK_SIZE)kb.img -o $(KDIR)/bootfs$(FLASHBLK_SIZE)kb.img -e $(SUMTOOL_BLOCKSIZE) -n
	rm -f $(KDIR)/ibootfs$(FLASHBLK_SIZE)kb.img

	fakeroot $(STAGING_DIR_HOST)/bin/ubinize -v -o $(KDIR)/root.ubifs-$(UBIFS_BLOCKSIZE) -m $(UBIFS_PAGESIZE) -p $(patsubst %k,%KiB,$(UBIFS_BLOCKSIZE)) $(KDIR)/bootfsJFFS2_rootfsUbi.ini
#### JFFS2 BootFS/UBI RootFS End

	$(call Image/Build,ubifs-$(UBIFS_BLOCKSIZE))
# END define Image/mkfs/ubifs
endef


# END ifneq ($(CONFIG_TARGET_ROOTFS_UBIFS),)
endif

define Image/mkfs/prepare
	#workaround: copy all *.ko to rootfs/lib/modules/xxx/; the correct way is modify package/kernel/modules/netfilter.mk, but it should care dependence.
	cp `find $(LINUX_DIR)/ -name "*.ko"` $(TARGET_DIR)/lib/modules/$(LINUX_VERSION)/
	#cp `find $(BROADCOM_SDK_DIR)/bcmdrivers/ -name "*.ko"` $(TARGET_DIR)/lib/modules/$(LINUX_VERSION)/
	#prevent duplicate binary, "wl/impl61/main/src/*/linux/prebuilt/*.ko", let cp command fail.
	cp `find $(BROADCOM_SDK_DIR)/bcmdrivers/ -path "*/prebuilt" -prune -o -name "*.ko" -print` $(TARGET_DIR)/lib/modules/$(LINUX_VERSION)/
	#In SDK 502L04, some kernel module locate at "bcm963xx\rdp\" directory.
	#In SDK 502L07, "bcm963xx/rdp/" will not contain kernel module.
	if [ -d $(BROADCOM_SDK_DIR)/rdp ]; then \
		for f in `find $(BROADCOM_SDK_DIR)/rdp -name *.ko`; \
		do \
			cp $$$$f $(TARGET_DIR)/lib/modules/$(LINUX_VERSION)/; \
		done \
	fi
	#./depmod.pl -F $(KDIR)/linux-$(LINUX_VERSION)/System.map -b $(TARGET_DIR)/lib/modules/
	#due to depmod can't generate file at read-only file system, so modify the path that generate file
#ifneq ($($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_ZYXEL)),)
ifneq ($(CONFIG_PACKAGE_zcfg),)
	mkdir -p $(TARGET_DIR)/var/
	touch $(TARGET_DIR)/var/modules.dep
	touch $(TARGET_DIR)/var/modules.symbols
	touch $(TARGET_DIR)/var/modules.alias
	ln -fs /var/modules.dep $(TARGET_DIR)/lib/modules/$(LINUX_VERSION)/
	ln -fs /var/modules.symbols $(TARGET_DIR)/lib/modules/$(LINUX_VERSION)/
	ln -fs /var/modules.alias $(TARGET_DIR)/lib/modules/$(LINUX_VERSION)/
endif
	$(RSTRIP) $(TARGET_DIR)/lib/modules/$(LINUX_VERSION)/
	#do not rsyne modules due to conflict directory name on kernel---ChihYuan Yang
	rsync -av --exclude 'modules' $(BCM_BUILD_DIR)/targets/$(BCM_PROFILE)/fs.install/  $(TARGET_DIR)/

ifeq ($(CONFIG_PACKAGE_base-files), )
ifneq ($(CONFIG_PACKAGE_zcfg),)
ifeq ($(CONFIG_BRCM_SDK_VERSION), "416L02A")
	$(CP) $(TOPDIR)/target/linux/brcm963xx/base-files/* $(TARGET_DIR)/
else
	$(CP) $(TOPDIR)/target/linux/brcm963xx/base-files-$(CONFIG_BRCM_SDK_VERSION)/* $(TARGET_DIR)/
	if [ -d $(TOPDIR)/target/linux/brcm963xx/$(SUBTARGET)/base-files-$(CONFIG_BRCM_SDK_VERSION) ]; then \
		$(CP) $(TOPDIR)/target/linux/brcm963xx//$(SUBTARGET)/base-files-$(CONFIG_BRCM_SDK_VERSION)/* $(TARGET_DIR)/; \
	fi
endif	
else
	# not select zcfg means want to have Broadcom like firmware.
ifeq ("$(call qstrip,$(CONFIG_BRCM963xx_SDK_VER_502L0X))","y")
	$(CP) $(TOPDIR)/target/linux/brcm963xx/base-files-bsp-502Lx/* $(TARGET_DIR)/
ifeq ($(CONFIG_BRCM_SDK_VERSION), "502L07")
	$(CP) $(TARGET_DIR)/etc/make_static_devnodes_502L07.sh $(TARGET_DIR)/etc/make_static_devnodes.sh
	rm $(TARGET_DIR)/etc/make_static_devnodes_502L07.sh
endif
else
	$(CP) $(TOPDIR)/target/linux/brcm963xx/base-files-bsp/* $(TARGET_DIR)/
endif
endif
	rm `find $(TARGET_DIR)/ -name ".gitkeep"`
ifeq ($(call qstrip,$(CONFIG_BRCM963xx_SDK_VER_416L04) $(CONFIG_BRCM963xx_SDK_VER_416L05) $(CONFIG_BRCM963xx_SDK_VER_502L0X)),)
	ln -sf /lib/public/libcms_boardctl.so $(TARGET_DIR)/lib/libcms_boardctl.so
	ln -sf /lib/public/libcms_msg.so $(TARGET_DIR)/lib/libcms_msg.so
	ln -sf /lib/public/libcms_util.so $(TARGET_DIR)/lib/libcms_util.so
endif
endif
	#Need to strip the rootfs to reduce the image size.
	#Don`t strip $(BCM_BUILD_DIR)/targets/$(BCM_PROFILE)/fs.install when you using "sstrip"
	#It may cause compile error when you compile the second time.
	$(RSTRIP) $(TARGET_DIR)/
	
ifneq ($(CONFIG_DSL_SUPPORT),)
	mkdir -p $(TARGET_DIR)/etc/adsl;cp -av $(BROADCOM_SDK_DIR)/bcmdrivers/broadcom/char/adsl/bcm9$(BRCM_CHIP)/*.bin  $(TARGET_DIR)/etc/adsl
endif
ifeq ($(CONFIG_BRCM_CFE_BOOT_FROM_NAND),y)
	cp $(KDIR)/vmlinux.$(KERNEL_FILE_TYPE) $(TARGET_DIR)
	cp $(BIN_DIR)/brcm-cfe/cfe$(BRCM_CHIP)ram.bin $(TARGET_DIR)/cferam.000
	touch -a -m -t 197001010000.00 $(TARGET_DIR)/cferam.000
endif

ifneq ($(call qstrip,$(CONFIG_BRCM963xx_SDK_VER_502L0X)),)
	# Copy the *.dtb file from SDK into rootfs and make sure the timestamp will not changed.
	rsync -av $(DTB_FILE) $(TARGET_DIR)/
	touch -a -m -t 197001010000.00 $(TARGET_DIR)/$(BRCM_DTB)
endif

	$(call Image/mkfs/prepare/default)
ifneq ($(call qstrip,$(CONFIG_BRCM963xx_SDK_VER_416L04) $(CONFIG_BRCM963xx_SDK_VER_416L05) $(CONFIG_BRCM963xx_SDK_VER_502L0X)),)
	#in 416L04,416L05, check if we need to do below action?
	#find $INSTALL_DIR -type f -perm /u=x,g=x,o=x -print |xargs -L1 $EXECSTACK -c 2> /dev/null
endif

endef

define Image/Prepare
	# Using BCM proprietary tool "cmplzma" to compress vmlinux
ifneq ($(call qstrip,$(CONFIG_BRCM963xx_SDK_VER_416L04) $(CONFIG_BRCM963xx_SDK_VER_416L05) $(CONFIG_BRCM963xx_SDK_VER_502L0X)),)
	$(HOSTTOOLS_DIR)/cmplzma -k -2 -$(KERNEL_COMPRESSION) $(KDIR)/vmlinux.elf $(KDIR)/vmlinux $(KDIR)/vmlinux.$(KERNEL_FILE_TYPE)
else
	$(HOSTTOOLS_DIR)/cmplzma -k -2 $(KDIR)/vmlinux.elf $(KDIR)/vmlinux $(KDIR)/vmlinux.$(KERNEL_FILE_TYPE)
endif

endef

define Image/Build
	$(call Image/Build/CFE,$(1),$(BCM_BOARD_NAME),$(BRCM_CHIP),$(BOARDNAME))
endef

$(eval $(call BuildImage))
