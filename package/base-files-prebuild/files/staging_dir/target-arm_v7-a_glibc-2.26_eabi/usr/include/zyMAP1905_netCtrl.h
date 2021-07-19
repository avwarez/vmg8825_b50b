/****************************************************************************
 *
 * Copyright (C) 2013 by ZyXEL
 *
 ****************************************************************************/

/**
 * @file   zyMAP1905_netCtrl.h
 * @date   Dec 2018
 * @brief  Network control like reboot, reset and FW upgrade
 */

#ifndef __ZY_NET_CTRL_H__
#define __ZY_NET_CTRL_H__

#include <time.h>
#include <unistd.h>
#include "zyMAP1905_global.h"

#define DEVICEMODE_ROUTER		"Router"
#define DEVICEMODE_AP			"AP"
#define DEVICEMODE_REPEATER		"Repeater"

//WIFI
#define _PATH_WIFI_24G			"/tmp/assoc_list.24g"
#define _PATH_WIFI_5G			"/tmp/assoc_list.5g"

#define _PATH_DEVICEIP			"/tmp/zy1905_IP"
#define _PATH_DEVICEMODE		"/tmp/zy1905_DeviceMode"

//FW ctrl
//State_new_fw
#define FW_NO_NEW_FW                 0
#define FW_HAVE_NEW_FW               1

//State_fw_is_download
//State_fw_upgrade
#define FW_STATE_FAILED              0
#define FW_STATE_CHECKFW_SUCCESS     1
#define FW_STATE_DOWNLOAD_FW         2
#define FW_STATE_FINISH_DOWNLOAD_FW  3
#define FW_STATE_FW_UPGRADE          4
#define FW_STATE_FINISH_FW_UPGRADE   5
#define FW_STATE_FILE_NOT_EXIST      6
#define FW_STATE_NO_NEW_FW           7
#define FW_STATE_HAVE_NEW_FW         8

#define LED_ON					"LED ON"
#define LED_OFF					"LED OFF"

//WIFI
#define WIFI_BAR2_24G	-85
#define WIFI_BAR3_24G	-80
#define WIFI_BAR4_24G	-70
#define WIFI_BAR5_24G	-50

#define WIFI_BAR2_5G	-85
#define WIFI_BAR3_5G	-80
#define WIFI_BAR4_5G	-70
#define WIFI_BAR5_5G	-50

typedef enum {
	REGISTER = 0,
	ENROLLEE = 1,
} DeviceTypeValue;

/** WIFI config */
typedef struct WIFINeighborList {
	struct WIFINeighborList *next;
	UINT8	nbrMac[6];
	UINT16	mediaType;
	UINT16	rate;
	INT16	rssi;
	UINT16	signalLevel;
	UINT8	Tx[32];
	UINT8	Rx[32];
#if 1//__ZYXEL__,Andrew, support DataDownlinkRate/DataUplinkRate
	UINT16	tx_rate;
	UINT16	rx_rate;
#endif
} WIFINeighborList;

typedef struct WIFINeighborData {
	UINT16		nbrNumber;
	WIFINeighborList	*wifiNeighborList;
} WIFINeighborData;

/** wifi channel Info */
typedef struct {
	UINT8 Wifichannel_24G[16];
	UINT8 Wifichannel_5G[16];
	UINT8 Wifichannel_60G[16];
} WIFIChannelInfo;

/** A structure to represent the vendor specific message data of AP auto-config distribution message */
typedef struct {
	UINT8 		alMac[6];			/**< 1905.1 AL MAC address of the receiving device */
	UINT16		apConfigCount;		/**< AP auto-config count*/
	UINT8		apConfigData[1500];	/**< AP auto-config data*/
} ApCfgDistMsgData;

/** A structure to represent the vendor specific message data of parental control IP query message */
typedef struct {
	UINT8 	alMac[6];	/* 1905.1 AL MAC address of the receiving device */
	UINT16	dataCount;	/* data length count*/
	UINT8	data[1500];	/* list data*/
} QueryParentalCtrlIPMsgData;

/** A structure to represent the security configuration */
typedef struct {
	SecSetupMethod 	setupMethod;	/**< Security setup method for the network */
	UINT16	pwdLen;			/**< The length of the password */
	UINT8	*pwd;			/**< The common password for generating security keys */
} SecConf;

RetCode getDeviceIP(char *DeviceIP);

RetCode runNetCtrl();

RetCode zyReboot();

RetCode zyResetToDefault();

RetCode setZyIntfPwrStateByMedia(const MediaType mediaType, const IntfPwrState pwrState);

RetCode setZyIntfPwrStateById(const UINT8 intfMac[6], const MediaType mediaType, const IntfPwrState pwrState);

RetCode zyGetWIFIConfig(WIFINeighborData *wifiNeighbordata);

//FW Control
RetCode setZyFWresult(int result);

RetCode zyFWCtrl(int ActionOption, int URLOption, char URL[1024]);

RetCode zyGetNewFWversion(char NewFWversion[128]);

RetCode zyGetNewFWdate(char NewFWdate[128]);

//WIFI data
RetCode getSecurityConfig(SecConf *secConf);

#endif