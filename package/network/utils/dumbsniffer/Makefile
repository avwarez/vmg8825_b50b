include $(TOPDIR)/rules.mk

PKG_NAME:=dumbsniffer
PKG_VERSION:=1.0.0
PKG_RELEASE:=1

#PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=@ZyXEL_SITE/private/ZyXEL
PKG_SROUCE:=
PKG_SOURCE_URL:=
DL_DIR:=$(TOPDIR)/dl
PACKAGE_DIR:=$(BIN_DIR)/packages

PKG_CAT:=zcat

CURR_DIR=$(shell pwd)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SRC_DIR:=$(CURR_DIR)/files/$(PKG_NAME)-$(PKG_VERSION)
# PACKAGE_DIR:=$(BIN_DIR)/packages/private

include $(INCLUDE_DIR)/package.mk

# Disable Dependencies Check
#define CheckDependencies
#endef

define Package/dumbsniffer
	@echo "==> Package/dumbsniffer"
  CATEGORY:= Avast Packages
  TITLE:= avast test package
  DESCRIPTION:=
  DEPENDS:= +libnl 
endef

define Build/Prepare
	$(MAKE) -C $(PKG_SRC_DIR) \
		CC="$(TARGET_CROSS)gcc" \
		INSTALL_DIR="$(PKG_INSTALL_DIR)" \
		BUILD_DIR="$(BUILD_DIR)" \
		PKG_BUILD_DIR="$(PKG_BUILD_DIR)" \
		clone
endef

define Build/Compile
	@echo "==> Build/Compile"
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CC="$(TARGET_CROSS)gcc" \
		STAGING_DIR=$(STAGING_DIR) \
		USRLIBDIR=$(STAGING_DIR)/usr/lib \
		BUILD_DIR=$(BUILD_DIR) \
		PKG_BUILD_DIR="$(PKG_BUILD_DIR)" \
		INSTALL_DIR="$(PKG_INSTALL_DIR)"
endef


define Package/dumbsniffer/install
	@echo "==> Package/dumbsniffer/install"
	$(INSTALL_DIR) $(1)/usr/sbin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dumbsniffer $(1)/usr/sbin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/firewall.sh $(1)/usr/sbin/
endef


$(eval $(call BuildPackage,dumbsniffer))

