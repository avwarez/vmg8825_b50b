include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=strongswan
PKG_VERSION:=5.5.2
#PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2

PATCH_DIR:=patches

PKG_CAT:=zcat

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	tar -xjf $(PKG_SOURCE) -C  $(BUILD_DIR)
	cp $(PATCH_DIR)/*.patch $(PKG_BUILD_DIR)
	patch -d $(PKG_BUILD_DIR) -p1 < $(PKG_BUILD_DIR)/*.patch
endef

define Package/strongswan/Default
  SECTION:=security
  CATEGORY:=VPN
  TITLE:=IPSec VPN strongswan
  URL:=http://v6web.litech.org/radvd/
  DESCRIPTION:=
  DEPENDS:=+libopenssl
endef

CONFIGURE_ARGS += \
	--exec_prefix= --prefix= \
	--enable-aes --enable-sha1 --enable-sha2 --enable-ccm --enable-ctr --enable-gcm --enable-openssl --enable-socket-default --enable-nonce --enable-stroke --enable-updown \
	--with-systemdsystemunitdir=no  --with-random-device=/dev/random --with-urandom-device=/dev/urandom --with-routing-table="220" --with-routing-table-prio="220" \
	--disable-gmp --enable-kernel-pfkey \
	--with-ipseclibdir=/lib

#########################################3
define Package/strongswan
  $(call Package/strongswan/Default)
  TITLE+= Daemon
endef


define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)
endef


define Package/strongswan/install
	mkdir -p $(PKG_BUILD_DIR)/gpl
	$(MAKE) DESTDIR=$(PKG_BUILD_DIR)/gpl -C $(PKG_BUILD_DIR) install
	$(INSTALL_DIR) $(1)/usr
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/lib/ipsec
	$(CP) $(PKG_BUILD_DIR)/gpl/usr/lib/ipsec/starter $(1)/usr/lib/ipsec
	$(CP) $(PKG_BUILD_DIR)/gpl/usr/lib/ipsec/charon $(1)/usr/lib/ipsec
	$(CP) $(PKG_BUILD_DIR)/gpl/usr/lib/ipsec/stroke $(1)/usr/lib/ipsec
	$(CP) $(PKG_BUILD_DIR)/gpl/usr/lib/ipsec/_updown $(1)/usr/lib/ipsec
	$(INSTALL_DIR) $(1)/usr/sbin
	$(CP) $(PKG_BUILD_DIR)/gpl/usr/sbin/swanctl $(1)/usr/sbin
	$(CP) $(PKG_BUILD_DIR)/gpl/usr/sbin/ipsec $(1)/usr/sbin
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_BUILD_DIR)/gpl/usr/bin/pki $(1)/usr/bin
	$(INSTALL_DIR) $(1)/lib
	$(INSTALL_DIR) $(1)/lib/plugins
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libcharon.so.0 $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libcharon.so.0.0.0 $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libcharon.so $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libstrongswan.so $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libstrongswan.so.0 $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libstrongswan.so.0.0.0 $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libvici.so $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libvici.so.0 $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/libvici.so.0.0.0 $(1)/lib
	$(CP) -d $(PKG_BUILD_DIR)/gpl/lib/plugins/*.so $(1)/lib/plugins
	$(INSTALL_DIR) $(1)/etc
	$(INSTALL_DIR) $(1)/etc/ipsec.d
	$(INSTALL_DIR) $(1)/etc/strongswan.d
	cp -d -r $(PKG_BUILD_DIR)/gpl/etc/strongswan.d/* $(1)/etc/strongswan.d
	cp -d -r $(PKG_BUILD_DIR)/gpl/etc/ipsec.d/* $(1)/etc/ipsec.d
	cp $(PKG_BUILD_DIR)/gpl/etc/strongswan.conf $(1)/etc/strongswan.conf
	cp $(PKG_BUILD_DIR)/gpl/etc/ipsec.conf $(1)/etc/ipsec.conf
	cp $(PKG_BUILD_DIR)/gpl/etc/ipsec.secrets $(1)/etc/ipsec.secrets
	rm -rf $(1)/etc/ipsec.d/cacerts
	ln -s /var/cert/ca $(1)/etc/ipsec.d/cacerts
endef


$(eval $(call BuildPackage,strongswan))
########################################

