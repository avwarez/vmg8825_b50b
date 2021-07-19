/****************************************************************************
 *
 * Copyright (C) 2013 by ZyXEL
 *
 ****************************************************************************/

/**
 * @file   zyMAP1905_dataManager.h
 * @date   Dec 2018
 * @brief  Datamodel manager
 */

#ifndef __ZY_DATA_MANAGER_H__
#define __ZY_DATA_MANAGER_H__

#include <stdbool.h>
#include "zyMAP1905_global.h"
#include "zyMAP1905_netCtrl.h"

const static UINT8 ZyVendSpecOui[3] = {0xFC, 0xF5, 0x28};

#define _PATH_FWUPGRADEALMAC "/tmp/zy1905_FWupgrade"
#define zy1905Config         ".zy1905_conf"
#define Version_FILENAME     "zy1905_Version"

#define VER_APPVERSION      "AppVersion"      /**< Version option (AppVersion) */
#define VER_L2DEVICECTRL    "L2DeviveCtrl"    /**< Version option (L2DEVICECTRL) */
#define VER_WIFIAUTOCFG     "WiFiAutoCfg"     /**< Version option (WIFIAUTOCFG) */
#define VER_WIFIONOFF       "WiFiOnOff"       /**< Version option (WIFIONOFF) */
#define VER_FWUPGRADE       "FwUpgrade"       /**< Version option (FWUPGRADE) */
#define VER_LEDONOFF        "LEDOnOff"        /**< Version option (LEDOnOff) */

#define DEF_APPVERSION    "1.0" /**< Default value of the configuration option (APPVERSION) */
#define DEF_L2DEVICECTRL  "0"   /**< Default value of the configuration option (L2DEVICECTRL) */
#define DEF_WIFIAUTOCFG   "0"   /**< Default value of the configuration option (WIFIAUTOCFG) */
#define DEF_WIFIONOFF     "0"   /**< Default value of the configuration option (WIFIONOFF) */
#define DEF_FWUPGRADE     "0"   /**< Default value of the configuration option (FWUPGRADE) */
#define DEF_LEDONOFF      "0"   /**< Default value of the configuration option (LEDONOFF) */

#define NUM_RADIO_PER_DEV   2

/* Enumerates the options that depend on platform datamodel */
typedef enum {
  RADIO_IDX_24G   = 0,
  RADIO_IDX_5G    = 1,
} RadioIdxList;

typedef struct FWalmacList {
  struct FWalmacList *pre;
  struct FWalmacList *next;
  UINT8  alMac[6];
} FWalmacList;

typedef struct FWalmacData {
  UINT16       nbrNumber;
  FWalmacList *fwalmacList;
} FWalmacData;

/** A structure to represent the configurations of IEEE 1905.1 device  */
typedef struct {
  UINT8   optionNum;                      /* Number of configuration option */
  UINT8   enableReboot;                   /* Enable(TRUE)/disable(FALSE) rebooted by IEEE 1905.1 neighbor device */
  UINT8   enableIntfPwrCtrl;              /* Enable(TRUE)/disable(FALSE) the interface(s) power controlled by IEEE 1905.1 neighbor device */
  UINT8   firmwareversion[128];           /* Device firmware version */
  UINT8   Newfirmwareversion[128];        /* Device new firmware version */
  UINT8   Newfirmwaredate[128];           /* Device new firmware date */
  UINT8   Newfirmware;                    /* Device Newfirmware*/
  UINT8   NewfirmwareUpgradeStatus;       /* Device firmware update Status*/
  UINT8   hostname[128];                  /* Device hostname */
  UINT8   deviceIP[128];                  /* Device IP */
  UINT8   deviceMode[32];                 /* devicemode */
  UINT8   Version_zy1905_Release[32];     /* zy1905 Release Version*/
  UINT8   Version_zy1905_Release_git[32]; /* zy1905 Release Version for git*/
  UINT8   LEDstatus[32];                  /* LED status*/
  UINT8   Version_app[32];                /* AppVersion*/
  UINT8   Version_L2DeviveCtrl[32];       /* reboot*/
  UINT8   Version_WiFiAutoCfg[32];        /* WIFIctrl*/
  UINT8   Version_WiFiOnOff[32];          /* AP_autoconfig*/
  UINT8   Version_FwUpgrade[32];          /* OnlineFWupgrade*/
  UINT8   Version_LEDOnOff[32];           /* LEDOnOff*/
  UINT8   Wifichannel_24G[16];            /* WIFIchannel_24G*/
  UINT8   Wifichannel_5G[16];             /* WIFIchannel_5G*/
  UINT8   Wifichannel_60G[16];            /* WIFIchannel_60G*/
} zyDevConfTable;

/* Enumerates the options that depend on platform datamodel */
typedef enum {
  OPT_CHECK_DEV_BY_ALMAC    = 0,
  OPT_CHECK_DEV_BY_INTF_MAC = 1,
  OPT_GET_CONFIG_DATA       = 2,
  OPT_GET_INTF_STATUS       = 3,
  OPT_GET_DEV_WIFI_NBR      = 4,
} GetDmDataOption;

typedef struct zyDevIntfList {
  struct zyDevIntfList *next;
  UINT8  intfMac[6];        /* MAC Address of this interface */
  IntfPwrState  pwrState;   /* Power state of this Interface */
  MediaType mediaType;      /* Media type (interface type) of this Interface */
} zyDevIntfList;

typedef struct zyDevIntfInfo {
  int intfNums;
  zyDevIntfList *DevIntfList;
} zyDevIntfInfo;

typedef struct zyWIFINeighbor {
  struct  zyWIFINeighbor *next;
  UINT8   nbrMac[6];
  UINT16  mediaType;
  UINT16  rate;
  INT16   rssi;
  UINT16  signalLevel;
  UINT8   Tx[32];
  UINT8   Rx[32];
#if 1 //__ZYXEL__,Andrew, support DataDownlinkRate/DataUplinkRate
  UINT16  tx_rate;
  UINT16  rx_rate;
#endif
  time_t  timeout;
} zyWIFINeighbor;

typedef struct zyWIFINeighborTable {
  UINT16  nbrNumber;
  zyWIFINeighbor  *wifiNeighbor;
} zyWIFINeighborTable;

typedef enum {
  REBOOT_CTRL = 0,
  INTF_PWR_CTRL = 1,
} CTRL_NBR_OPTION;

UINT8* getMAPAlOui();

UINT8* getMAPAlMac();

int getIntfPwrSt(unsigned short media_type);

RetCode getDeviceChannel(zyDevConfTable* zy_DevConfData);

void initDevConfig(zyDevConfTable* zy_DevConfData, bool controller);

RetCode initSecurityConfig(SecConf* zy_SecConf);

bool getEnableRebootFromNbrCap();

bool getEnableIntfPwrCtrlFromNbrCap();

RetCode getalMacOfDevTableByIfMac(UINT8 *alMac, UINT8 *intfMac);

RetCode zyGetWIFIConfdata(zyWIFINeighborTable *wifiNeighbortable);

//add FWupgrade almac
RetCode addZyFWupgradealmac(UINT8 *alMac, int NewfirmwareUpgradeStatus);

//remove FWupgrade almac
RetCode rmZyFWupgradealmac(UINT8 *alMac);

//find FWupgrade almac
FWalmacList *findFWupgradealmac(UINT8 *alMac);

//write file
RetCode updateZyFWNewfirmware(int result);

RetCode updateZyFWUpgradeStatus(int result);

void zyMAP1905_MainLoop();

#endif
