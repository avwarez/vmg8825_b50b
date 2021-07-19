/****************************************************************************
 *
 * Copyright (C) 2013 by ZyXEL
 *
 ****************************************************************************/

/**
 * @file   zyMAP1905_message.h
 * @date   Dec 2018
 * @brief  Vendor specific message handler
 */

#ifndef __ZY_VEND_MESSAGE_HANDLER_H__
#define __ZY_VEND_MESSAGE_HANDLER_H__

#include <stdbool.h>
#include "zyMAP1905_global.h"
#include "zyMAP1905_dataManager.h"
#include "zyMAP1905_service.h"

/** Defines the maximum number of vendor specific query message lookup table */
#define MAX_QUERIED_VEND_MSG_NUM	64

/** Defines the lifetime of vendor specific query message */
#define QUERIED_VEND_MSG_TIMEOUT	5

typedef struct {
  UINT8 	type;
  UINT16 	length;
} __attribute__((__packed__)) zy1905_tlv;

#define zyTlvMdidType			    0xC0

/** A structure to represent vendor specific query message lookup table */
typedef struct {
	UINT8		alMac[6];	/**< AL MAC */
	UINT16 		msgId; 		/**< (-1) indicates unset or (>=0) indicates the message ID */
	UINT16 		vendMsgType; 	/**< Vendor message type*/
	UINT8 		retry; 		/**< Retry counter */
	time_t 		timeStamp;	/**< The time at which the query/search message was sent */
} QueriedVendMsg;

/** Defines the length of the header of vendor specific message */
#define VEND_MSG_HEADER_LEN	15

typedef struct zyBSS_MdidInfo_s {
	unsigned char 		BSSID[6];
	char 				ifname[16];
	unsigned short 		mdid;
} zyBSS_MdidInfo_t;

typedef struct zyTopology_MdidInfo_s {
	unsigned int 		InterfaceNumberOfEntries;
	zyBSS_MdidInfo_t 	BSS[IEEE1905_MAX_BSS_PER_DEV];
} zyTopology_MdidInfo_t;

/** Defines the length of the header of WIFI client message */
//#define WIFI_MAX_CLIENT_NUM 256
//#define WIFI_MAX_OPTION_NUM 32
/** Enumerates the vendor specific message type */
typedef enum {
	VEND_MSG_TYPE_CONF_QUERY 		   = 0x0000,	/**< A message to query a device・s configuration value */
	VEND_MSG_TYPE_CONF_RESP 		   = 0x0001,	/**< A message to carry configuration value in response to a configuration value query */
	VEND_MSG_TYPE_INTF_PWR_STATE_QUERY = 0x0002,	/**< A message to query the power state of interface(s) */
	VEND_MSG_TYPE_INTF_PWR_STATE_RESP  = 0x0003,	/**< A message to carry the power state of interface(s) in response to a interface power state query */
	VEND_MSG_TYPE_REBOOT_REQ  		   = 0x0004,	/**< A message to reboot a specific 1905.1 neighbor device */
	VEND_MSG_TYPE_REBOOT_RESP 		   = 0x0005,	/**< A message to response to reboot request */
	VEND_MSG_TYPE_INTF_PWR_CTRL_REQ    = 0x0006,	/**< A message to control the power state of a specific neighbor interface */
	VEND_MSG_TYPE_INTF_PWR_CTRL_RESP   = 0x0007,	/**< A message to response to interface power control request */
	VEND_MSG_TYPE_WIFI_STATE_REQ 	   = 0x0008,	/**< A message to query wifi state of a specific neighbor interface */
	VEND_MSG_TYPE_WIFI_STATE_RESP 	   = 0x0009,	/**< A message to carry to interface wifi state request */
	VEND_MSG_TYPE_AP_AUTOCONFIG_QUER   = 0x000A,	/**< A message to query AP auto-config */
	VEND_MSG_TYPE_AP_AUTOCONFIG_DIST   = 0x000B,	/**< A message to distribute AP auto-config */
	VEND_MSG_TYPE_AP_AUTOCONFIG_ACK    = 0x000C,	/**< A message to acknowledge of distribution of AP auto-config */
	VEND_MSG_TYPE_WPS_CTRL_REQ         = 0x0010,	/**< A message to control the WPS of a specific neighbor interface */
	VEND_MSG_TYPE_WPS_CTRL_RESP        = 0x0011,	/**< A message to response to interface WPS request */
	VEND_MSG_TYPE_APSteering_REQ       = 0x0012,	/**< A message to control the APSteering of a specific neighbor interface */
	VEND_MSG_TYPE_APSteering_RESP      = 0x0013,	/**< A message to response to interface APSteering request */
	VEND_MSG_TYPE_FW_CTRL_REQ          = 0x0014,	/**< A message to control the FW control of a specific neighbor interface */
	VEND_MSG_TYPE_FW_CTRL_RESP         = 0x0015,	/**< A message to response to interface FW control request */
	VEND_MSG_TYPE_RESETTODEFAULT_REQ   = 0x0016,	/**< A message to resetToDefault a specific 1905.1 neighbor device */
	VEND_MSG_TYPE_RESETTODEFAULT_RESP  = 0x0017,	/**< A message to response to resetToDefault request */
	VEND_MSG_TYPE_WIFI_CLIENT_MCAST    = 0x0018,	/**< Not used */
	VEND_MSG_TYPE_SENDCOMMAND_REQ      = 0x0019,	/**< A message to send command URL a specific 1905.1 neighbor device */
	VEND_MSG_TYPE_SENDCOMMAND_RESP     = 0x0020,	/**< A message to response to send command URL request */
	VEND_MSG_TYPE_LED_CTRL_REQ         = 0x0021,	/**< A message to set LED ctrl a specific 1905.1 neighbor device */
	VEND_MSG_TYPE_LED_CTRL_MCAST_REQ   = 0x0022,	/**< A message to set LED ctrl a specific 1905.1 neighbor device by multicast*/
	VEND_MSG_TYPE_LED_CTRL_RESP        = 0x0023,	/**< A message to response to set LED ctrl request */
	VEND_MSG_TYPE_WIFI_CLIENT_MCAST2   = 0x0024,	/**< A message to send wifi client mcast 2 */
	VEND_MSG_TYPE_LINK_QUALITY_QUER    = 0x002A,	/**< A message to query link quality */
	VEND_MSG_TYPE_LINK_QUALITY_RESP    = 0x002B,	/**< A message to response link quality */
	VEND_MSG_TYPE_LINK_QUALITY_SEND    = 0x002C,	/**< A message to query link quality */
	VEND_MSG_TYPE_REQ_PARENTALCTRLIP   = 0x0031,
	VEND_MSG_TYPE_RESP_PARENTALCTRLIP  = 0x0032,
	VEND_MSG_TYPE_UNKNOWN 			   = 255		/**< UNKNOWN */
} VendMsgType;

typedef enum {
	CTRL_ID_SET_REBOOT           = 2 ,
	CTRL_ID_SET_POWER_CTRL       = 3 ,
	CTRL_ID_SET_APAUTOCONFIG_CFG = 7 ,
	CTRL_ID_SET_APSTEERING       = 8 ,
	CTRL_ID_SET_FW_CONTROL       = 9 ,
	CTRL_ID_SET_RESET_TO_DEFAULT = 10,
} CtrlMsgType;

/** A structure to represent the specific data of vendor specific message */
typedef struct {
	UINT8 		oui[3];		/**< OUI */
	UINT8 		alMac[6];	/**< AL MAC */
	UINT8		seqNum;		/**< Sequence number */
	UINT8		lastSegInd;	/**< Last segment indicator */
	UINT16 		msgType;	/**< Vendor specific message type */
	UINT16 		dataLen;	/**< The length of vendor specific message data */
	UINT8 		*data;		/**< Vendor specific message data */
	bool		respInd;	/**< Response indicator */
	bool		relayInd;	/**< Relay indicator */
} VendMsg;

/** A structure to represent the configuration of IEEE 1905.1 device */
typedef struct {
	UINT8 	option;		/**< Configuration option */
	UINT16 	valueNum;	/**< Number of configuration value */
	UINT8	value[128];	/**< Configuration value */
} DevConf;

/** A structure to represent the vendor specific message data of configuration value query message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the receiving device */
} ConfQueryMsgData;

/** A structure to represent the vendor specific message data of configuration value response message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the transmitting device */
	UINT8		optionNum;	/**< Number of configutation options */
	DevConf		devConf[MAX_OPTION_NUM]; /**< Configurations */
} ConfRespMsgData;

/** A structure to represent the vendor specific message data of interface power state query message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the receiving device */
} IntfPwrStateQueryMsgData;

/** A structure to represent the power state of each interface */
typedef struct {
	UINT8 	intfMac[6];	/**< Interface MAC */
	UINT16	mediaType;	/**< Media type (interface type) */
	UINT8	pwrState;	/**< Power state */
} IntfPwr;

/** A structure to represent the vendor specific message data of interface power state response message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the transmitting device */
	UINT8		intfNum;	/**< Interface number */
	IntfPwr		intfPwr[MAX_INTF_NUM]; /**< The power state of interface(s) */
} IntfPwrStateRespMsgData;

/** A structure to represent the vendor specific message data of reboot request message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the receiving device */
} RebootReqMsgData;

/** A structure to represent the vendor specific message data of reboot response message */
typedef struct {
	RetCode		retCode;	/**< Result code for the reboot request message */
} RebootRespMsgData;

/** A structure to represent the vendor specific message data of interface power control request message */
typedef struct {
	UINT8		alMac[6];	/**< 1905.1 AL MAC address of the receiving device */
	UINT8		intfNum;	/**< Interface number */
	IntfList	intfList[MAX_INTF_NUM];	/**< Interface list */
	IntfPwrState 	pwrState;	/**< New power state of above interface(s) */
} IntfPwrCrtlReqMsgData;

/** A structure to represent the vendor specific message data of interface power control response message */
typedef struct {
	UINT8		intfNum;	/**< Interface number */
	IntfRet		intfRet[MAX_INTF_NUM]; /**< Return code of each interface */
} IntfPwrCrtlRespMsgData;

//WIFI
/** A structure to represent the vendor specific message data of interface power state query message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the receiving device */
} WIFIStateQueryMsgData;

/** A structure to represent the vendor specific message data of interface power state response message */
typedef struct {
	UINT8         alMac[6];
	UINT8         nbrMac[6];
	MediaType     mediaType;
	UINT16        rate;
	UINT16        rssi;
	UINT16        signalLevel;
} WIFIStateRespMsgData;

//FW control
/** A structure to represent the vendor specific message data of FW control query message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the receiving device */
	UINT16		FWOption;       /**< FW option*/
	UINT16		FWTopoOption;   /**< FW topology option*/
	UINT16		FWURLcount;	/**< FW URL count*/
	UINT8		FWURL[1024];	/**< FW URL*/
	UINT8		DataValue[1024];	/**< FW Data*/
} FWCtrlReqMsgData;

/** A structure to represent the vendor specific message data of FW control response message */
typedef struct {
	RetCode		retCode;	/**< Result code for the WPS config request message */
} FWCtrlRespMsgData;

/** A structure to represent the vendor specific message data of resetToDefault request message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the receiving device */
} ResetToDefaultReqMsgData;

/** A structure to represent the vendor specific message data of resetToDefault response message */
typedef struct {
	RetCode		retCode;	/**< Result code for the reboot request message */
} ResetToDefaultRespMsgData;

/** A structure to represent the WIFI client data */
typedef struct {
	UINT8       alMac[6];            /**< 1905.1 AL MAC address of the transmitting device */
	UINT16      wificlientSendNum;   /**< Number of wifi client */
	UINT8       value[1500];         /**< wifi data value */
} WIFIClientSenddata;

/** A structure to represent the WIFI client data */
typedef struct wificlientdata {
	struct 		wificlientdata *next;
	UINT16      valueNum;              /**< Number of wifi data value */
	UINT8       value[256];            /**< wifi data value */
} WIFIClientdata;

/** A structure to represent the vendor specific message data of WIFI client value message */
typedef struct {
	UINT8                alMac[6];               /**< 1905.1 AL MAC address of the transmitting device */
	UINT16               wificlientNum;          /**< Number of wifi client */
	WIFIClientdata       *wificlientdata;          /**< wifi client data */
} WIFIclientMsgData;

//Send command
/** A structure to represent the vendor specific message data of FW control query message */
typedef struct {
	UINT8 	alMac[6];			/**< 1905.1 AL MAC address of the receiving device */
	UINT16	CommandDatacount;	/**< FW option*/
	UINT16	CommandURLcount;	/**< FW topology option*/
	UINT8	CommandURL[2048];	/**< FW Data*/
} SendCommandReqMsgData;

typedef struct CommandDataList {
	struct		CommandDataList *next;
	UINT8		data[1024];
} CommandDataList;

/** A structure to represent the vendor specific message data of FW control response message */
typedef struct {
	RetCode		retCode;	/**< Result code for the WPS config request message */
} SendCommandRespMsgData;

//LED
/** A structure to represent the vendor specific message data of LED control query message */
typedef struct {
	UINT8 		alMac[6];	/**< 1905.1 AL MAC address of the receiving device */
	UINT16		LEDOption;	/**< FW topology option*/
} LEDCtrlReqMsgData;

/** A structure to represent the vendor specific message data of LED control response message */
typedef struct {
	RetCode		retCode;	/**< Result code for the WPS config request message */
} LEDCtrlRespMsgData;

/**
 * @brief  Check if the the vendor specific response message has received, if hasn't resend the query message
 * @param  void
 * @return Return code
 */
RetCode checkZyVendRespMsgReceived();

/**
 * @brief  Request to send configuration value query message
 * @param  alMac AL MAC address of the receiving device
 * @param  retry Retry counter
 * @return Return code
 */
RetCode zyMAP1905_ConfQuery_send(UINT8 *alMac, UINT8 retry);

/**
 * @brief  Request to interface power state query message
 * @param  alMac AL MAC address of the receiving device
 * @param  retry Retry counter
 * @return Return code
 */
RetCode zyMAP1905_IntfPwrStateQuery_send(UINT8 *alMac, UINT8 retry);

/**
 * @brief  Request to send WIFI configuration value query message
 * @param  alMac AL MAC address of the receiving device
 * @param  retry Retry counter
 * @return Return code
 */
RetCode zyMAP1905_WifiStateQuery_send(UINT8 *alMac, UINT8 retry);

/**
 * @brief  Handle the vendor specific message
 * @param  macSa Source MAC
 * @param  msgId Message ID
 * @param  vendMsg Vendor specific message
 * @return Return code
 */
RetCode handleZyVendSpecMsg(UINT8 *macSa, UINT16 msgId, VendMsg *vendMsg, VendMsgType CommandType);

int parseZyVendMsg(unsigned char *tlv_data, VendMsg *vendMsg);

int genZyVendMsg(unsigned char *tlv_data, unsigned int *tlv_data_len, unsigned char *specData);

//insert mdid tlv data to topology response
int zyMAP1905_TlvMDID_insert(unsigned char *pbuf, unsigned int *tlv_data_len, zyTopology_MdidInfo_t* pTopoMdid);

#endif
