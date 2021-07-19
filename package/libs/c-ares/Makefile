#
# Copyright (C) 2009-2010 OpenWrt.org
# Copyright (C) 2009 Jakob Pfeiffer
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=c-ares
PKG_VERSION:=1.14.0
PKG_RELEASE:=1
PKG_LICENSE:=MIT

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=https://c-ares.haxx.se/download
PKG_SOURCE_URL:=@ZyXEL_SITE/opensource/libs
DL_DIR:=$(TOPDIR)/dl
PKG_HASH:=45d3c1fd29263ceec2afc8ff9cd06d5f8f889636eb4e80ce3cc7f0eaf7aadc6e

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

TARGET_CPPFLAGS += $(filter -D%,$(TARGET_CFLAGS))
TARGET_CFLAGS := $(filter-out -D%,$(TARGET_CFLAGS))

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PATCH_DIR:=patches-$(PKG_VERSION)

define Package/libcares
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Library for asyncronous DNS Requests (including name resolves)
  URL:=http://c-ares.haxx.se/
  MAINTAINER:=Karl Palsson <karlp@etactica.com>
endef

define Package/libcares/description
  c-ares is a C library for asynchronous DNS requests (including name resolves)

C89 compatibility, MIT licensed, builds for and runs on POSIX, Windows,
Netware, Android and many more operating systems.

endef

define Package/libcares/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/*.so.* $(1)/usr/lib/

	$(INSTALL_DIR) $(STAGING_DIR)/usr/lib/voice
	$(CP)  $(PKG_INSTALL_DIR)/usr/lib/libcares.a  $(STAGING_DIR)/usr/lib/voice/

#NOTE: The following actions are to make this 'c-ares' library Backward-Compatible for the VoIP application(s) originally utilizing the 'ares' library (e.g. ZyIMS VoIP).
	$(RM)  $(STAGING_DIR)/usr/lib/voice/libares.a
	$(LN)  $(STAGING_DIR)/usr/lib/voice/libcares.a  $(STAGING_DIR)/usr/lib/voice/libares.a
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)
	$(CP) $(PKG_INSTALL_DIR)/* $(1)/

	$(INSTALL_DIR) $(STAGING_DIR)/usr/include/voice/c-ares
	$(CP) $(PKG_BUILD_DIR)/ares.h  $(STAGING_DIR)/usr/include/voice/c-ares/
	$(CP) $(PKG_BUILD_DIR)/ares_dns.h  $(STAGING_DIR)/usr/include/voice/c-ares/
	$(CP) $(PKG_BUILD_DIR)/ares_version.h  $(STAGING_DIR)/usr/include/voice/c-ares/
	$(CP) $(PKG_BUILD_DIR)/ares_private.h  $(STAGING_DIR)/usr/include/voice/c-ares/
	$(CP) $(PKG_BUILD_DIR)/ares_build.h  $(STAGING_DIR)/usr/include/voice/c-ares/
	$(CP) $(PKG_BUILD_DIR)/ares_llist.h  $(STAGING_DIR)/usr/include/voice/c-ares/
	$(CP) $(PKG_BUILD_DIR)/ares_rules.h  $(STAGING_DIR)/usr/include/voice/c-ares/

#NOTE: The following actions are to make this 'c-ares' library Backward-Compatible for the VoIP application(s) originally utilizing the 'ares' library (e.g. ZyIMS VoIP).
	$(RM) -r $(STAGING_DIR)/usr/include/voice/ares
	$(LN) $(STAGING_DIR)/usr/include/voice/c-ares  $(STAGING_DIR)/usr/include/voice/ares
endef

$(eval $(call BuildPackage,libcares))
