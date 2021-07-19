#
# Copyright (C) 2010-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=ivi
PKG_RELEASE:=1.0
PKG_BUILD_DIR:=$(KERNEL_BUILD_DIR)/$(PKG_NAME)-$(PKG_RELEASE)
#PATCH_DIR:=patches

include $(INCLUDE_DIR)/package.mk

BUILT_BINARY_NAME:=ivi.ko

define Package/map/Default
  SECTION:=ipv6
  CATEGORY:=IPv6
  TITLE:=MAP
  SUBMENU:=MAP-T/MAP-E with IVI
  #DEPENDS:=+libzcfg_msg  +libjson +libzcmd_tool +libzcfg_fe_rdm_access +libzcfg_fe_rdm_struct
  URL:=https://github.com/cernet/MAP
endef

define KernelPackage/ivi
  $(call Package/map/Default)
  TITLE:=IVI Kernel Module
  #VERSION:=$(LINUX_VERSION)-$(BOARD)-$(PKG_RELEASE)
  DEPENDS:= @(IPV6&&LINUX_3_18&&TARGET_en75xx) +libc
  FILES:= $(PKG_BUILD_DIR)/$(BUILT_BINARY_NAME)
  #AUTOLOAD:=$(call AutoLoad,46,demo)
endef

define KernelPackage/ivi/description
  IVI Module is built for ivictl(IPv6 MAP).
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)
	$(Build/Patch)
endef

TARGET_CFLAGS += -I$(LINUX_DIR)/user_headers/include

MAKE_FLAGS +=\
		ARCH="$(LINUX_KARCH)" \
		KERNELDIR="$(LINUX_DIR)" \
		CROSS_COMPILE="$(TARGET_CROSS)"

#define Build/Compile
#	$(MAKE) -C $(PKG_BUILD_DIR);
#endef

define KernelPackage/ivi/install
	$(CP) $(PKG_BUILD_DIR)/$(BUILT_BINARY_NAME) $(1)/lib/modules/$(LINUX_VERSION)/$(BUILT_BINARY_NAME)
endef

$(eval $(call KernelPackage,ivi))
