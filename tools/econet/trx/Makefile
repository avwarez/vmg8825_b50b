
include $(TOPDIR)/rules.mk

PKG_NAME := econet-trx

#7.3.180.1 using for MT7520 new SDK
#PKG_VERSION:=7.3.180.1
#7.3.119.8 using for MT7520
#PKG_VERSION:=7.3.119.8
#7.3.119.1 using for MT7505
#PKG_VERSION:=7.3.119.1
#7.3.207.4 using for EN7521
#PKG_VERSION:=7.3.207.4
PKG_VERSION:=$(call qstrip,$(CONFIG_TC_SDK_VERSION))
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@ZyXEL_SITE/private/Trendchip/tools
DL_DIR:=$(TOPDIR)/dl
PATCH_DIR:=patches-$(PKG_VERSION)

HOST_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/host-build.mk

##reference Project/config/menuconfig/Config.in
#ifeq ($(CONFIG_$(CONFIG_CUSTOM_SDK_PREFIX)_TCSUPPORT_CPU_EN7580),y)
ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_LITTLE_ENDIAN),y)
CUSTOM_MKFLAGS=TCSUPPORT_LITTLE_ENDIAN=1
else
CUSTOM_MKFLAGS=
endif

ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_BOOTROM_LARGE_SIZE),y)
CUSTOM_MKFLAGS+=TCSUPPORT_BOOTROM_LARGE_SIZE=1
endif

ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_SECURE_BOOT),y)
CUSTOM_MKFLAGS+=TCSUPPORT_SECURE_BOOT=1
endif
ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_SECURE_BOOT_V1),y)
CUSTOM_MKFLAGS+=TCSUPPORT_SECURE_BOOT_V1=1
endif
ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_SECURE_BOOT_V2),y)
CUSTOM_MKFLAGS+=TCSUPPORT_SECURE_BOOT_V2=1
endif

#=======================
# Below reference EN7528_7.3.257.150\Project\rule.mak, TCSUPPORT_BB_256KB was export by rule.mak
ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7516),y)
ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_SECURE_BOOT),y)
CUSTOM_MKFLAGS+=TCSUPPORT_BB_256KB=1
endif
endif

ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7528),y)
ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_LITTLE_ENDIAN),y)
CUSTOM_MKFLAGS+=TCSUPPORT_BB_256KB=1
endif
endif

ifeq ($(CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX)_TCSUPPORT_CPU_EN7516)),y)
CUSTOM_MKFLAGS+=TCSUPPORT_BB_256KB=1
endif
#=======================

define Host/Compile
	$(MAKE) -C $(HOST_BUILD_DIR)/tools/trx \
                CC="$(HOSTCC)" \
                CXX="$(CXX) $(HOST_STATIC_LINKING)" \
		clean
	CFLAGS="-O2 -Wall" $(CUSTOM_MKFLAGS) $(MAKE) -C $(HOST_BUILD_DIR)/tools/trx \
                CC="$(HOSTCC)" \
                CXX="$(CXX) $(HOST_STATIC_LINKING)"
endef

define Host/Install
	$(CP) $(HOST_BUILD_DIR)/tools/trx/trx $(STAGING_DIR_HOST)/bin/$(PKG_NAME)
	$(CP) $(HOST_BUILD_DIR)/tools/trx/trx_config $(STAGING_DIR_HOST)/bin/$(PKG_NAME)_config
	$(INSTALL_DIR) $(STAGING_DIR)/usr/include/trx
	$(CP) $(HOST_BUILD_DIR)/tools/trx/trx.h $(STAGING_DIR)/usr/include/trx/trx.h
endef

define Host/Clean
	rm -f $(STAGING_DIR_HOST)/bin/$(PKG_NAME)
	rm -f $(STAGING_DIR)/usr/include/trx/trx.h
endef

$(eval $(call HostBuild))
