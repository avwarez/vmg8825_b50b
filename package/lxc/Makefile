#
# Copyright (C) 2014 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=lxc
PKG_VERSION:=2.0.4
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=https://linuxcontainers.org/downloads/lxc/
PKG_SOURCE_URL:=@ZyXEL_SITE/opensource/utils/
#PKG_HASH:=68663a67450a8d6734e137eac54cc7077209fb15c456eec401a2c26e6386eff6

PKG_LICENSE:=LGPL-2.1+ BSD-2-Clause GPL-2.0
PKG_MAINTAINER:=Marko Ratkaj <marko.ratkaj@sartura.hr>

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

PATCH_DIR=patches-${PKG_VERSION}

include $(INCLUDE_DIR)/package.mk

START_LXC = S64lxc

CONFIGURE_ARGS += \
	ac_cv_header_sys_types_h_makedev=no \
	--prefix= \
	--exec_prefix= \
	--enable-doc=no \
	--enable-api-docs=no \
	--enable-examples=no \
	--enable-bash=no \
	--enable-python=no

define Package/lxc/description
	LXC is the userspace control package for Linux Containers, a lightweight
	virtual system mechanism sometimes described as "chroot on steroids".
endef

define Package/lxc
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libpthread
	TITLE:=LXC userspace tools
	URL:=http://lxc.sourceforge.net/
endef

define Package/lxc/config
	source "$(SOURCE)/Config.in"
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)
endef

define Package/lxc/install
	$(MAKE) install DESTDIR=$(1) -C $(PKG_BUILD_DIR)
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_DIR) $(1)/etc/rc3.d
	$(INSTALL_BIN) ./files/lxc.sh $(1)/etc/init.d
	ln -s ../init.d/lxc.sh $(1)/etc/rc3.d/$(START_LXC)						
endef

$(eval $(call BuildPackage,lxc))
