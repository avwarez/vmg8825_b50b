#
# Copyright (C) 2006-2016 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=openssl
#PKG_BASE:=1.1.1
#PKG_BUGFIX:=b
#PKG_VERSION:=$(PKG_BASE)$(PKG_BUGFIX)
PKG_VERSION:=$(call qstrip,$(CONFIG_OPENSSL_VERSION))
PKG_RELEASE:=5
PKG_USE_MIPS16:=0
ENGINES_DIR=engines-1.1

PKG_BUILD_PARALLEL:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@ZyXEL_SITE/opensource/libs
#PKG_SOURCE_URL:= \
	http://ftp.fi.muni.cz/pub/openssl/source/ \
	http://ftp.linux.hr/pub/openssl/source/ \
	ftp://ftp.pca.dfn.de/pub/tools/net/openssl/source/ \
	http://www.openssl.org/source/ \
	http://www.openssl.org/source/old/$(PKG_BASE)/
PKG_HASH:=5c557b023230413dfb0756f3137a13e6d726838ccd1430888ad15bfb2b43ea4b

PATCH_DIR:=patches-$(PKG_VERSION)

ifeq ($(strip $(CONFIG_OPENSSL_VERSION)),"1.0.2n")
PKG_LICENSE:=OpenSSL
PKG_LICENSE_FILES:=LICENSE
PKG_CPE_ID:=cpe:/a:openssl:openssl
PKG_CONFIG_DEPENDS:= \
	CONFIG_OPENSSL_ENGINE_CRYPTO \
	CONFIG_OPENSSL_ENGINE_DIGEST \
	CONFIG_OPENSSL_WITH_EC \
	CONFIG_OPENSSL_WITH_EC2M \
	CONFIG_OPENSSL_WITH_SSL3 \
	CONFIG_OPENSSL_HARDWARE_SUPPORT \
	CONFIG_OPENSSL_WITH_DEPRECATED \
	CONFIG_OPENSSL_WITH_DTLS \
	CONFIG_OPENSSL_WITH_COMPRESSION \
	CONFIG_OPENSSL_WITH_NPN \
	CONFIG_OPENSSL_WITH_PSK \
	CONFIG_OPENSSL_WITH_SRP \
	CONFIG_OPENSSL_OPTIMIZE_SPEED
endif

ifeq ($(strip $(CONFIG_OPENSSL_VERSION)),"1.1.1b")
PKG_LICENSE:=OpenSSL
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Eneas U de Queiroz <cotequeiroz@gmail.com>
PKG_CPE_ID:=cpe:/a:openssl:openssl
PKG_CONFIG_DEPENDS:= \
	CONFIG_OPENSSL_ENGINE \
	CONFIG_OPENSSL_ENGINE_BUILTIN \
	CONFIG_OPENSSL_ENGINE_BUILTIN_AFALG \
	CONFIG_OPENSSL_ENGINE_BUILTIN_DEVCRYPTO \
	CONFIG_OPENSSL_ENGINE_BUILTIN_PADLOCK \
	CONFIG_OPENSSL_NO_DEPRECATED \
	CONFIG_OPENSSL_OPTIMIZE_SPEED \
	CONFIG_OPENSSL_PREFER_CHACHA_OVER_GCM \
	CONFIG_OPENSSL_WITH_ARIA \
	CONFIG_OPENSSL_WITH_ASM \
	CONFIG_OPENSSL_WITH_ASYNC \
	CONFIG_OPENSSL_WITH_BLAKE2 \
	CONFIG_OPENSSL_WITH_CAMELLIA \
	CONFIG_OPENSSL_WITH_CHACHA_POLY1305 \
	CONFIG_OPENSSL_WITH_CMS \
	CONFIG_OPENSSL_WITH_COMPRESSION \
	CONFIG_OPENSSL_WITH_DTLS \
	CONFIG_OPENSSL_WITH_EC \
	CONFIG_OPENSSL_WITH_EC2M \
	CONFIG_OPENSSL_WITH_ERROR_MESSAGES \
	CONFIG_OPENSSL_WITH_GOST \
	CONFIG_OPENSSL_WITH_IDEA \
	CONFIG_OPENSSL_WITH_MDC2 \
	CONFIG_OPENSSL_WITH_NPN \
	CONFIG_OPENSSL_WITH_PSK \
	CONFIG_OPENSSL_WITH_RFC3779 \
	CONFIG_OPENSSL_WITH_SEED \
	CONFIG_OPENSSL_WITH_SM234 \
	CONFIG_OPENSSL_WITH_SRP \
	CONFIG_OPENSSL_WITH_SSE2 \
	CONFIG_OPENSSL_WITH_TLS13 \
	CONFIG_OPENSSL_WITH_WHIRLPOOL
endif

include $(INCLUDE_DIR)/package.mk

ifneq ($(CONFIG_CCACHE),)
HOSTCC=$(HOSTCC_NOCACHE)
HOSTCXX=$(HOSTCXX_NOCACHE)
endif

define Package/openssl/Default
  TITLE:=Open source SSL toolkit
  URL:=http://www.openssl.org/
  SECTION:=libs
  CATEGORY:=Libraries
endef

define Package/libopenssl/config
source "$(SOURCE)/Config.in"
endef

#include $(SOURCE)/Makefile-$(PKG_VERSION)
ifeq ($(strip $(CONFIG_OPENSSL_VERSION)),"1.0.2n")
include $(TOPDIR)/package/libs/openssl/Makefile-1.0.2n
endif

#ifeq ($(CONFIG_OPENSSL_VERSION_1_1_1b),y)
ifeq ($(strip $(CONFIG_OPENSSL_VERSION)),"1.1.1b")
#include $(TOPDIR)/package/libs/openssl/Makefile-$(PKG_VERSION)
include $(TOPDIR)/package/libs/openssl/Makefile-1.1.1b
endif

define Package/openssl/Default/description
The OpenSSL Project is a collaborative effort to develop a robust,
commercial-grade, full-featured, and Open Source toolkit implementing the
Transport Layer Security (TLS) protocol as well as a full-strength
general-purpose cryptography library.
endef

define Package/libopenssl
$(call Package/openssl/Default)
  SUBMENU:=SSL
  DEPENDS:=+OPENSSL_WITH_COMPRESSION:zlib \
	   +OPENSSL_ENGINE_BUILTIN_AFALG:kmod-crypto-user \
	   +OPENSSL_ENGINE_BUILTIN_DEVCRYPTO:kmod-cryptodev \
	   +OPENSSL_ENGINE_BUILTIN_PADLOCK:kmod-crypto-hw-padlock \
	   +libpthread
  TITLE+= (libraries)
  ABI_VERSION:=1.1
  #ABI_VERSION:=$(PKG_VERSION)
  MENU:=1
endef

define Package/libopenssl/description
$(call Package/openssl/Default/description)
This package contains the OpenSSL shared libraries, needed by other programs.
endef

define Package/openssl-util
  $(call Package/openssl/Default)
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libopenssl +OPENSSL_VERSION_1_1_1b:libopenssl-conf
  TITLE+= (utility)
endef

define Package/openssl-util/description
$(call Package/openssl/Default/description)
This package contains the OpenSSL command-line utility.
endef

define Package/libopenssl-conf
  $(call Package/openssl/Default)
  SUBMENU:=SSL
  TITLE:=/etc/ssl/openssl.cnf config file
  DEPENDS:=libopenssl @OPENSSL_VERSION_1_1_1b
endef

define Package/libopenssl-conf/conffiles
/etc/ssl/openssl.cnf
endef

define Package/libopenssl-conf/description
$(call Package/openssl/Default/description)
This package installs the OpenSSL configuration file /etc/ssl/openssl.cnf.
endef

define Package/libopenssl-afalg
  $(call Package/openssl/Default)
  SUBMENU:=SSL
  TITLE:=AFALG hardware acceleration engine
  DEPENDS:=libopenssl @OPENSSL_ENGINE @KERNEL_AIO @!LINUX_3_18 \
	   +PACKAGE_libopenssl-afalg:kmod-crypto-user +libopenssl-conf @!OPENSSL_ENGINE_BUILTIN @OPENSSL_VERSION_1_1_1b
endef

define Package/libopenssl-afalg/description
This package adds an engine that enables hardware acceleration
through the AF_ALG kernel interface.
To use it, you need to configure the engine in /etc/ssl/openssl.cnf
See https://www.openssl.org/docs/man1.1.1/man5/config.html#Engine-Configuration-Module
and https://openwrt.org/docs/techref/hardware/cryptographic.hardware.accelerators
The engine_id is "afalg"
endef

define Package/libopenssl-devcrypto
  $(call Package/openssl/Default)
  SUBMENU:=SSL
  TITLE:=/dev/crypto hardware acceleration engine
  DEPENDS:=libopenssl @OPENSSL_ENGINE +PACKAGE_libopenssl-devcrypto:kmod-cryptodev +libopenssl-conf \
	   @!OPENSSL_ENGINE_BUILTIN @OPENSSL_VERSION_1_1_1b
endef

define Package/libopenssl-devcrypto/description
This package adds an engine that enables hardware acceleration
through the /dev/crypto kernel interface.
To use it, you need to configure the engine in /etc/ssl/openssl.cnf
See https://www.openssl.org/docs/man1.1.1/man5/config.html#Engine-Configuration-Module
and https://openwrt.org/docs/techref/hardware/cryptographic.hardware.accelerators
The engine_id is "devcrypto"
endef

define Package/libopenssl-padlock
  $(call Package/openssl/Default)
  SUBMENU:=SSL
  TITLE:=VIA Padlock hardware acceleration engine
  DEPENDS:=libopenssl @OPENSSL_ENGINE @TARGET_x86 +PACKAGE_libopenssl-padlock:kmod-crypto-hw-padlock \
	   +libopenssl-conf @!OPENSSL_ENGINE_BUILTIN @OPENSSL_VERSION_1_1_1b
endef

define Package/libopenssl-padlock/description
This package adds an engine that enables VIA Padlock hardware acceleration.
To use it, you need to configure it in /etc/ssl/openssl.cnf.
See https://www.openssl.org/docs/man1.1.1/man5/config.html#Engine-Configuration-Module
and https://openwrt.org/docs/techref/hardware/cryptographic.hardware.accelerators
The engine_id is "padlock"
endef

$(eval $(call BuildPackage,libopenssl))
ifeq ($(strip $(CONFIG_OPENSSL_VERSION)),"1.1.1b")
$(eval $(call BuildPackage,libopenssl-conf))
$(eval $(call BuildPackage,libopenssl-afalg))
$(eval $(call BuildPackage,libopenssl-devcrypto))
$(eval $(call BuildPackage,libopenssl-padlock))
endif
$(eval $(call BuildPackage,openssl-util))