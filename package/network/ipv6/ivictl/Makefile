#
# Copyright (C) 2010-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
#include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=ivictl
PKG_RELEASE:=1.0
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_RELEASE)
#PACKAGE_DIR:=$(BIN_DIR)/packages/network/ipv6/ivictl

# PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz

# PKG_SOURCE_URL:=@ZyXEL_SITE/private/ZyXEL
# DL_DIR:=$(TOPDIR)/dl/private

# PKG_CAT:=zcat

include $(INCLUDE_DIR)/package.mk

define Package/map/Default
  SECTION:=ipv6
  CATEGORY:=IPv6
  TITLE:=MAP
  SUBMENU:=MAP-T/MAP-E with IVI
  URL:=https://github.com/cernet/MAP
endef

define Package/ivictl
  $(call Package/map/Default)
  TITLE:=Transporting IPv4 packets across an IPv6 network support
  DEPENDS:=@(IPV6&&LINUX_3_18&&TARGET_en75xx) +kmod-ivi +libc
  URL:=https://github.com/cernet/MAP
  # PKGARCH:=all
endef

define Package/ivictl/description
  MAP is an open source CPE implementation of draft-ietf-softwire-map and draft-ietf-softwire-map-t.
  It runs on Linux and Openwrt.
  
  MAP is a mechanism for transporting IPv4 packets across an IPv6 network using IP translation (MAP-T) or encapsulation (MAP-E),
  and a generic mechanism for mapping between IPv6 addresses and IPv4 addresses and transport layer ports.
endef

define Build/Prepare
	$(CP) ./src/* $(PKG_BUILD_DIR)
	$(Build/Patch)
endef

# TARGET_CFLAGS += -I$(LINUX_DIR)/user_headers/include
# MAKE_FLAGS+=\
		# ARCH="$(LINUX_KARCH)" \
		# KERNELDIR="$(LINUX_DIR)" \
		# CROSS_COMPILE="$(TARGET_CROSS)"

#define Build/Compile
#	$(MAKE) -C $(PKG_BUILD_DIR) \
#		INSTALL_DIR="$(BCM_INSTALL_DIR)"
#endef

define Package/ivictl/install
	$(INSTALL_DIR) $(1)/bin
	$(CP) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/bin
endef

$(eval $(call BuildPackage,ivictl))
