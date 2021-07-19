#
# Copyright (C) 2006-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=net-snmp
PKG_VERSION:=5.8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@ZyXEL_SITE/opensource/network/services
DL_DIR:=$(TOPDIR)/dl

PKG_LICENSE:=BSD
PKG_LICENSE_FILES:=COPYING

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PATCH_DIR:=patches-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

PKG_INSTALL:=1

LIB_ZCFG = +libjson +ZYXEL_SUPPORT_ZCFG:libzyutil  +ZYXEL_SUPPORT_ZCFG:libzcfg_msg +ZYXEL_SUPPORT_ZCFG:libzcfg_fe_rdm_access +ZYXEL_SUPPORT_ZCFG:libzcfg_fe_rdm_string +ZYXEL_SUPPORT_ZCFG:libzcfg_fe_schema +ZYXEL_SUPPORT_ZCFG:libzcfg_fe_rdm_struct +libcrypto +librt +libzcmd_tool +libopenssl
SNMP_LIBS = -ljson -lzcfg_msg -lzyutil -lzcfg_fe_schema -lzcfg_fe_rdm_access -lzcfg_fe_rdm_string -lzcfg_fe_rdm_struct  -lzcfg_fe_rdm_access -lcrypto -lzcmd_tool -lzlog -lzos -lnsl -lrt


ifneq ($(strip $(BRCM_BOARD)),)
SNMP_CFLAGS += -DBROADCOM
endif

ifneq ($(strip $(ZCFG_PLATFORM)),)
SNMP_CFLAGS += -D$(ZCFG_PLATFORM)_PLATFORM
endif

ifeq ($(CONFIG_HAWAIIAN_TELCOM),y)
SNMP_CFLAGS += -DHAWAIIAN_TELCOM
endif

define Package/net-snmp
  SECTION:=net
  CATEGORY:=Base system
  TITLE:=Tools and libraries relating to the SNMP
  DEPENDS:= $(LIB_ZCFG) +NETSNMP_MODSW:glib2 +NETSNMP_MODSW:zyee
endef

define Package/net-snmp/config
	source "$(SOURCE)/Config.in"
endef

#Disable Dependencies Check
define CheckDependencies
endef

define Build/Configure
	$(call Build/Configure/Default, \
			--with-install-prefix=$(PKG_BUILD_DIR)/_install \
			--disable-embedded-perl \
			--disable-manuals \
			--disable-scripts \
			--disable-mibs \
			--disable-des \
			--enable-mini-agent \
			--disable-applications \
			--with-cflags="$(SNMP_CFLAGS)" \
			--with-libs="$(SNMP_LIBS)" \
			--with-transports="UDP" \
			--disable-mib-loading \
			--with-sys-contact="@ZyXEL.com" \
			--with-sys-location="Taiwan" \
			--with-logfile="/var/log/snmpd.log" \
			--with-default-snmp-version="2" \
			--with-persistent-directory="/var/net-snmp/" \
			--with-mib-modules="utilities mibII if-mib ZYXEL-PRESTIGE-MIB disman/event notification target" \
			--with-out-mib-modules="host ucd_snmp mibII/vacm_context mibII/setSerialNo mibII/mta_sendmail mibII/system_mib snmpv3mibs agentx agent_mibs disman/schedule disman/old-event-mib" \
			--sysconfdir="/etc/snmp" \
			--disable-deprecated \
			--disable-privacy \
			--disable-md5 \
			--disable-local-smux \
			--with-openssl=no \
			--without-perl-modules \
			--disable-perl-cc-checks \
			--disable-internal-md5 \
			--without-kmem-usage \
			--with-openssl=no \
			--enable-ipv6 \
			--enable-fast-install \
			--enable-shared=yes \
			--without-nl \
			--enable-static=no)
endef

define Build/Prepare
	$(Build/Prepare/Default)
ifneq ($(CONFIG_NETSNMP_MODSW),)
	$$(call link_files,zcfg-service,$(PKG_BUILD_DIR))
endif
endef

define Build/Compile
#$(Build/Compile/Default)
ifneq ($(CONFIG_NETSNMP_MODSW),)
	$(MAKE) -C $(PKG_BUILD_DIR)/zcfg-service \
			CC="$(TARGET_CC)" \
   	        PKG_NAME="$(PKG_NAME)" CFLAGS="$(CFLAGS)"
endif
endef

define Package/net-snmp/install
	$(INSTALL_DIR) $(1)/sbin
	install -m 755 $(PKG_INSTALL_DIR)/usr/sbin/snmpd  $(1)/sbin/snmpd
	$(TARGET_CROSS)strip $(1)/sbin/snmpd
ifneq ($(CONFIG_NETSNMP_MODSW),)
	install -m 755 $(PKG_BUILD_DIR)/zcfg-service/$(PKG_NAME)-zcfgd $(1)/sbin/$(PKG_NAME)-zcfgd
	$(TARGET_CROSS)strip $(1)/sbin/$(PKG_NAME)-zcfgd	
	$(INSTALL_DIR) $(1)/etc/init.d
	$(CP) $(PKG_BUILD_DIR)/zcfg-service/script/$(PKG_NAME).sh $(1)/etc/init.d/
endif
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/*.so* $(1)/usr/lib/
	#$(INSTALL_DIR) $(1)/etc/snmp/
	#$(INSTALL_DATA) $(PKG_BUILD_DIR)/snmpd.conf.tmp $(1)/etc/snmp/
endef

define Build/InstallDev
	# if build as module, NOT build into the image.
ifneq ($(CONFIG_NETSNMP_MODSW),)
	cp $(PACKAGE_DIR)/$(PKG_NAME)*.ipk $(PKG_BUILD_DIR)/
	rm -f $(PACKAGE_DIR)/$(PKG_NAME)*.ipk
endif
endef

$(eval $(call BuildPackage,net-snmp))
