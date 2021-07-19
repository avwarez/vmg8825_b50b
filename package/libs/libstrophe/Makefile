# 
# Copyright (C) 2006 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libstrophe
PKG_VERSION:=0.10.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=https://github.com/strophe/libstrophe
PKG_SOURCE_URL:=@ZyXEL_SITE/opensource/libs

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

PKG_LICENSE:=GPLv3
PKG_LICENSE_FILES:=COPYING

include $(INCLUDE_DIR)/package.mk

define Package/libstrophe
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:= +libopenssl +expat
  TITLE:=A generic dynamic object loading library
  URL:=http://strophe.im/libstrophe
endef

define Package/libstrophe/description
  Helper A minimal XMPP library
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig

	$(CP) $(PKG_INSTALL_DIR)/usr/include/*.h $(1)/usr/include/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libstrophe.{a,so*} $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libstrophe.pc $(1)/usr/lib/pkgconfig/
endef

define Package/libstrophe/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/.libs/libstrophe.so.* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libstrophe))
