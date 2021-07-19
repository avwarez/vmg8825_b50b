/****************************************************************************
 *
 * Copyright (C) 2013 by ZyXEL
 *
 ****************************************************************************/

/**
 * @file   zyMAP1905_global.h
 * @date   Oct 2018
 * @brief  Defines global definitions
 */

#ifndef __MAP1905_GLOBAL_H__
#define __MAP1905_GLOBAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libzyMAPLog.h"

/* Copy form file "zy1905_release_version.h" */
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define zy1905_Release_Version STR(PKGVERSION)

#define DEF_CONF_FOLDER		"/etc/zy1905"

/**< Default value of the configuration option (DATA_MODEL_FOLDER) */
#define	DEF_DATA_MODEL_FOLDER	"/tmp"

/** Defines the size of interface name */
#define INTF_NAME_SIZE					16

/** Define the maximun number of configuration options */
#define MAX_OPTION_NUM					256

/** Multicast WIFI client data */
#define L2MESSAGE_MAX_LEN 				1300
#define ONEWIFIDATA_LEN 				150

#define IEEE1905_MAX_BSS_PER_DEV		10
#define IEEE1905_VNDR_TLV_OUI_LENGTH	3

/** Zyxel debug level */
#if 0
#define CRITICAL	0 	/**< for critical errors */
#define ERROR 		1 	/**< for regular errors */
#define WARNING 	2 	/**< for warning messages */
#define INFO 		3 	/**< for informational messages */
#define DEBUG 		4 	/**< for debugging messages */
#endif

#define g_zyMainLoopTimer 1000000 /* MICROSEC for ZYXEL Main Loop function for Multi-AP */

#define ZY1905_MAC_DELIM_FMT  "%02hhX:%02hhX:%02hhX:%02hhX:%02hhX:%02hhX"
#define ZY1905_MAC_FMT(x) ((unsigned char *)(x))[0], ((unsigned char *)(x))[1], ((unsigned char *)(x))[2], ((unsigned char *)(x))[3], ((unsigned char *)(x))[4], ((unsigned char *)(x))[5]

/**
 * @defgroup DATA_TYPE_DEF Data type definitions
 * @brief    Data type definitions
 */

#ifndef FALSE
#define FALSE	0
#endif

#ifndef TRUE
#define TRUE	1
#endif

typedef unsigned char	UINT8;
typedef	signed short  	INT16;
typedef	unsigned short	UINT16;
typedef signed int		INT32;
typedef	unsigned int	UINT32;

#define ZY1905_MAC_SCANF(x) &((x)[0]), &((x)[1]), &((x)[2]), &((x)[3]), &((x)[4]), &((x)[5])

#if 0
#define DPRINTF(level, x...) do { if ((level) <= ZY_DEBUGLEVEL) { printf("zy1905[%s] > %s[line %d]: ",\
(level == 0) ? "CRI" : (level == 1) ? "ERR" : (level == 2) ? "WAR" : (level == 3) ? "INF" : "DBG",\
__FUNCTION__, __LINE__); printf(x); } } while (0)
#endif

/** Enumerates the system state */
typedef enum {
	STATE_UNINIT = 0,	/**< Uninitialized */
	STATE_INIT = 1, 	/**< Initialized */
	STATE_START = 2,	/**< Starting */
} SysState;

/** Enumerates the return code */
typedef enum {
	SUCCESS	= 0x00, 						/**< Success */
	UNMATCHED_MAC_ADDRESS = 0x01, 			/**< The MAC address is not matched by any 1905.1 interface MAC address */
	UNSUPPORTED_PWR_STATE = 0x02, 			/**< The requested power state transition is unsupported by the 1905.1 interface */
	UNAVAILABLE_PWR_STATE = 0x03, 			/**< The requested power state transition is currently unavailable by the 1905.1 interface */
	NBR_OF_FWD_RULE_EXCEEDED = 0x04, 		/**< No new rule could be added to the current set of forwarding rules */
	INVALID_RULE_ID = 0x05, 				/**< Invalid rule ID value */
	DUPLICATE_CLASSIFICATION_SET = 0x06, 	/**< An identical classificationSet already exists in the current set of forwarding rules */
	UNMATCHED_NEIGHBOR_MAC_ADDRESS = 0x07, 	/**< The MAC address does not match any neighbor's 1905.1 AL MAC address */
	FAILURE = 0x10,							/**< The 1905.1 interface has either rejected the request or is nonresponsive */
	INTERNAL_ERROR = 0x11,					/**< Internal ERROR */
	INVALID_OPERATION = 0x12,				/**< Invaild operation */
	INVALID_ZYSOCKET = 0x13,				/**< Invaild socket, prevent same definition as SDK */
	UNSUPPORTED_CONF_OPTION = 0x20,			/**< Unsupported configuration option */
	UNSUPPORTED_CONF_VALUE = 0x21,			/**< Unsupported configuration value */
	UNAVAILABLE_CONF_VALUE = 0x22,			/**< The configuration value is currently unavailable */
	UNSUPPORTED_SERVICE_ID = 0x30,			/**< The service ID is unsupported */
	SERVICE_REQ_NOT_READY = 0x31,			/**< Service request isn't ready */
	SERVICE_RESP_NOT_READY = 0x32,			/**< Isn't ready for writing service response */
	UNSUPPORTED_MESSAGE_TYPE = 0x40,		/**< The message type is unsupported */
	MESSAGE_HAS_GEN_RECV = 0x41,			/**< The message has generated or received */
	DATA_MODEL_INVALID_INDEX = 0x50,		/**< Invalid index */
	DATA_MODEL_EMPTY_ENTRY = 0x51,			/**< Empty entry */
	DATA_MODEL_INVALID_ID = 0x52,			/**< Invalid ID */
	DATA_MODEL_NBR_EXIST = 0x53,			/**< Neighbor device existed */
	DATA_MODEL_NEW_NBR = 0x54,				/**< Neighbor device doesn't exist */
	DATA_MODEL_UNCHANGED = 0x55,			/**< Data model unchanged */
	DATA_MODEL_UPDATED = 0x56,				/**< Data model updated  */
	DATA_MODEL_NOT_FOUND = 0x57,			/**< The entry isn't found */
	NET_TOPOL_DISABLE = 0x61,				/**< The capability of network topology is disable */
	NET_TOPOL_INCOMPLETED = 0x62			/**< Network topology is incompleted */
} RetCode;

/** Enumerates the configuration options */
typedef enum {
	OPTION_ENABLE_REBOOT_FROM_NBR = 0,				/**< Configuration option (ENABLE_REBOOT_FROM_NBR) */
	OPTION_ENABLE_INTF_PWR_CTRL_FROM_NBR = 1,		/**< Configuration option (ENABLE_INTF_PWR_CTRL_FROM_NBR) */
	OPTION_ENABLE_FIRMWAREVERSION = 2,				/**< Configuration option (ENABLE_FIRMWAREVERSION) */
	OPTION_ENABLE_WPS_CONFIG = 3,					/**< Configuration option (ENABLE_WPS_CONFIG) */
	OPTION_FW_UPGRADESTATUS = 4,					/**< Configuration option (FW_CTRL) */
	OPTION_FW_NEWFWVERSION = 5,						/**< Configuration option (FW_NewFW) */
	OPTION_FW_NEWFWDATE = 6,						/**< Configuration option (FW_NewFWdate) */
	OPTION_HOSTNAME = 7,							/**< Configuration option (HOSTNAME) */
	OPTION_DEVICEIP = 8,							/**< Configuration option (DEVICEIP) */
	OPTION_FW_NEWFW = 9,							/**< Configuration option (NewFW) */
	OPTION_DEVICEMODE = 10,							/**< Configuration option (DEVICEMODE) */
	OPTION_ZY1905_RELEASE_VERSION = 11,				/**< Configuration option (ZY1905_RELEASE_VERSION) */
	OPTION_LEDSTATUS = 12,							/**< Configuration option (LEDSTATUS) */
	OPTION_WIFICHANNELINFO_24G = 13,				/**< Configuration option (WIFICHANNELINFO_24G) */
	OPTION_WIFICHANNELINFO_5G = 14,					/**< Configuration option (WIFICHANNELINFO_5G) */
	OPTION_WIFICHANNELINFO_60G = 15,				/**< Configuration option (WIFICHANNELINFO_60G) */
	OPTION_ZY1905_RELEASE_VERSION_GIT = 16,			/**< Configuration option (ZY1905_RELEASE_VERSION_GIT) */
	OPTION_RESET_AFTER_DIST = 19,					/**< Configuration option (RESET_AFTER_DIST) */
	OPTION_VER_APPVERSION = 101,					/**< Configuration option (APPVERSION) */
	OPTION_VER_L2DEVICECTRL = 102,					/**< Configuration option (L2DEVICECTRL) */
	OPTION_VER_WIFIAUTOCFG = 103,					/**< Configuration option (WIFIAUTOCFG) */
	OPTION_VER_WIFIONOFF = 104,						/**< Configuration option (WIFIONOFF) */
	OPTION_VER_FWUPGRADE = 105,						/**< Configuration option (FWUPGRADE) */
	OPTION_VER_LEDONOFF = 106,						/**< Configuration option (LEDONOFF) */
} ConfOption;

/** Enumerates the power state of a 1905.1 interface */
typedef enum {
	PWR_ON = 0,					/**< Power ON */
	PWR_SAVE = 1,				/**< Power saving mode */
	PWR_OFF = 2, 				/**< Power OFF */
	PWR_UNSUPPORTED = 3,		/**< Unsupported */
	PWR_UNKNOWN = 255			/**< Power state unknown */
} IntfPwrState;

/** Enumerates the operational status  */
typedef enum {
	OPER_UNKNOWN = 0, 			/**< The operational state is Unknow */
	OPER_NOT_PRESENT = 1,		/**< The operational state is NotPresent */
	OPER_DOWN = 2, 				/**< The operational state is Down */
	OPER_LOWER_LAYER_DOWN = 3,	/**< The operational state is LowerLayerDown */
	OPER_TESTING = 4,			/**< The operational state is Testing */
	OPER_DORMANT = 5, 			/**< The operational state is Dormant */
	OPER_UP = 6, 				/**< The operational state is Up */
} OperStatus;

/** Enumerates the transient phase of the discovery of network topology */
typedef enum {
	TOPOL_INCOMPLETE = 0,		/**< Indicates that the device is populating the topology object during the transient phase */
	TOPOL_AVAILABLE = 1,		/**< Indicates that the transient phase is over and the device is maintaining and updating the topology object as changes occur */
	TOPOL_ERR_MISCONFIG = 2		/**< Indicates that a necessary configuration value is undefined or invalid */
} TopolStatus;

/** Enumerates the capability of network topology */
typedef enum {
	TOPOL_DISABLE = 0,		/**< Disable network topology */
	TOPOL_ENABLE = 1,		/**< Enable network topology */
	TOPOL_UNKNOWN = 255		/**< Unknown */
} TopolCap;

/** Enumerates the event type of the change log of the network topology */
typedef enum {
	TOPOL_LOG_EVENT_NEW_NBR = 0,	/**< The discovery of a neighbor */
	TOPOL_LOG_EVENT_LOST_NBR = 1	/**< The loss of a neighbor */
} TopolLogEventType;

/** Enumerates the type of neighbor */
typedef enum {
	NBR_TYPE_IEEE1905 = 0,		/**< IEEE 1905.1 neighbor device */
	NBR_TYPE_NON_IEEE1905 = 1	/**< Non-IEEE 1905.1 neighbor device */
} NbrType;

/** Enumerates the interface type (media type) */
typedef enum {
	MEDIA_TYPE_IEEE802_3u = 0x0000,		/**< IEEE 802.3u fast Ethernet */
	MEDIA_TYPE_IEEE802_3ab = 0x0001,	/**< IEEE 802.3ab gigabit Ethernet */
	MEDIA_TYPE_IEEE802_11b = 0x0100,	/**< IEEE 802.11b (2.4 GHz) */
	MEDIA_TYPE_IEEE802_11g = 0x0101,	/**< IEEE 802.11g (2.4 GHz) */
	MEDIA_TYPE_IEEE802_11a = 0x0102,	/**< IEEE 802.11a (5 GHz) */
	MEDIA_TYPE_IEEE802_11n = 0x0103,	/**< IEEE 802.11n (2.4 GHz) */
	MEDIA_TYPE_IEEE802_11n_5G = 0x0104,	/**< IEEE 802.11n (5 GHz) */
	MEDIA_TYPE_IEEE802_11ac = 0x0105,	/**< IEEE 802.11ac (5 GHz) */
	MEDIA_TYPE_IEEE802_11ad = 0x0106,	/**< IEEE 802.11ad (60 GHz) */
	MEDIA_TYPE_IEEE802_11af = 0x0107,	/**< IEEE 802.11af (whitespace) */
	MEDIA_TYPE_IEEE1901_WAVELET = 0x0200,	/**< IEEE 1901 wavelet */
	MEDIA_TYPE_IEEE1901_FFT = 0x0201,	/**< IEEE 1901 FFT */
	MEDIA_TYPE_MoCA_V1_1 = 0x0300,		/**< MoCA v1.1 */
	MEDIA_TYPE_MoCA_V2_0 = 0x0301		/**< MoCA v2.0 */
} MediaType;

/** Enumerates the transmission type of CDMU message */
typedef enum {
	UNICAST = 0,		/**< Unicast */
	NBR_MULTICAST = 1,	/**< Neighbor multicast */
	RELAY_MULTICAST = 2	/**< Relayed multicast */
} TransType;

/** Enumerates the IEEE802.11 role */
typedef enum {
	IEEE80211_ROLE_AP = 0, 			/**< AP */
	IEEE80211_ROLE_NON_AP_PCP_STA = 4, 	/**< Non-AP/non-PCP STA */
	IEEE80211_ROLE_WIFI_PCP_CL = 8, 	/**< Wi-Fi P2P cilent */
	IEEE80211_ROLE_WIFI_PCP_GP_OWNER = 9, 	/**< Wi-Fi P2P group owner */
	IEEE80211_ROLE_80211ad_PCP = 10 	/**< 802.11ad PCP */
} IEEE80211Role;

/** Enumerates the security setup method */
typedef enum {
	UCPK = 0,	/**< User configured passphrase or key*/
	PBC = 1,	/**< Push button configuration */
	NFCNK = 2,	/**< Near-filed communication network key */
	UNKNOWN	= 255	/**< UNKNOWN */
} SecSetupMethod;

/** A structure to represent the TLV */
typedef struct {
	UINT8 	type;		/**< Type */
	UINT16	len;		/**< Length */
	UINT8 	*value;		/**< Value */
} Tlv;

/** A structure to represent the interface list */
typedef struct {
	UINT8 	intfMac[6];	/**< Interface MAC */
	UINT16	mediaType;	/**< Media type (interface type) */
} IntfList;

/** A structure to represent the return code of each interface */
typedef struct {
	UINT8 	intfMac[6];	/**< Interface MAC */
	UINT16	mediaType;	/**< Media type (interface type) */
	UINT8	retCode;	/**< Return code */
} IntfRet;

/** Enumerates the configuration options */
typedef enum {
	OPTION_WIFI_CLINET_NBRMAC       = 0,     /**< Configuration option (OPTION_WIFI_CLINET_NBRMAC) */
	OPTION_WIFI_CLINET_MEDIATYPE    = 1,     /**< Configuration option (OPTION_WIFI_CLINET_MEDIATYPE) */
	OPTION_WIFI_CLINET_RATE         = 2,     /**< Configuration option (OPTION_WIFI_CLINET_RATE) */
	OPTION_WIFI_CLINET_RSSI         = 3,     /**< Configuration option (OPTION_WIFI_CLINET_RSSI) */
	OPTION_WIFI_CLINET_SIGNALLEVEL  = 4,     /**< Configuration option (OPTION_WIFI_CLINET_SIGNALLEVEL) */
	OPTION_WIFI_CLINET_TX           = 5,     /**< Configuration option (OPTION_WIFI_CLINET_TX) */
	OPTION_WIFI_CLINET_RX           = 6,     /**< Configuration option (OPTION_WIFI_CLINET_RX) */
#if 1 //__ZYXEL__,Andrew, support DataDownlinkRate/DataUplinkRate
	OPTION_WIFI_CLINET_TX_RATE 		= 7,	 /**< Configuration option (OPTION_WIFI_CLINET_TX_RATE) */
	OPTION_WIFI_CLINET_RX_RATE 		= 8,	 /**< Configuration option (OPTION_WIFI_CLINET_RX_RATE) */
#endif
} WIFIClientOption;

#endif
