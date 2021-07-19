/****************************************************************************
 *
 * Copyright (C) 2013 by ZyXEL
 *
 ****************************************************************************/

/**
 * @file   zyMAP1905_wrapper.h
 * @date   Jan 2019
 * @brief  Wrapper and register function for Broadcom IEEE1905
 */

#ifndef __ZY1905_WRAPPER_H__
#define __ZY1905_WRAPPER_H__

#include <time.h>
#include <stdbool.h>
#include "zyMAP1905_global.h"
#include "zyMAP1905_dataManager.h"
#include "zyMAP1905_message.h"
#include "zyMAP1905_apCfg.h"

#define _PATH_NVRAM_TMP "/tmp/.zy1905_nvram_tmp"

#define I5_MAX_VNDR_DATA_BUF 1514
#define IEEE1905_MAC_ADDR_LEN   6

typedef struct {
  unsigned char neighbor_al_mac[6]; /* While Sending/Encoding a Vendor MSG/TLV this is Destination AL_MAC
                                      * While Receiving/Decoding a Vendor MSG/TLV this is Source AL_MAC */
  unsigned char *vendorSpec_msg; /* Vendor data */
  unsigned int vendorSpec_len; /* Vendor data length */
} zy1905VendorData;

/* Vendor Specific Information of each device on the topology */
typedef struct {
  zyDevConfTable    zyDevConf;      /*configurations of IEEE 1905.1 device */
  unsigned short    zyWiFiNbrNum;
  zyWIFINeighbor    *zyWifiNeighbor; /* WIFI Neighbor list */
  SecConf           zySecConf;  /* security configuration */
} zy1905DmDeviceExt;

typedef struct {
  IntfPwrState    zyPwrState;   /**< Power state of this Interface */
} zy1905DmIntfExt;

typedef void *zy1905bcm_getDmData(int opt_type, void *arg, void *output);
typedef RetCode zy1905bcm_writeJsonFile();
typedef int zy1905bcm_sendVenderSpecMsg(zy1905VendorData *msg_data, unsigned short *msgId);
typedef int zy1905bcm_sendVendSpecMcast(zy1905VendorData *msg_data, unsigned short *msgId);
typedef int zy1905bcm_cmdMsgSend(int cmd, void *data, size_t datalen);
typedef RetCode zy1905bcm_ApCfg_set(zyMAP1905_bssInfo *bssInfo_recv);

typedef struct zy1905_call_bks {
    zy1905bcm_getDmData *getDmData;
    zy1905bcm_writeJsonFile *writeJsonFile;
    zy1905bcm_sendVenderSpecMsg *sendVendSpecMsg;
    zy1905bcm_sendVendSpecMcast *sendVendSpecMcast;
    zy1905bcm_cmdMsgSend *cmdMsgSend;
    zy1905bcm_ApCfg_set *zyMAP1905_ApCfg_set;
} zy1905_call_bks_t;

void zyMAP1905_Func_reg(zy1905_call_bks_t *i5_cbs, bool isCmd);

void *zyMAP1905_DmData_get(int opt_type, void *arg, void *output);

RetCode zyMAP1905_JsonDataModel_write();

bool zyMAP1905_findController();

void zyMAP1905_DeviceDm_init(zy1905DmDeviceExt *zy_DeviceDm);

void zyMAP1905_DevIntfDm_init(zy1905DmIntfExt* zy_IntfeDm, unsigned short media_type);

void zyMAP1905_WifiChan_get(char* ifname, unsigned char* chan_result);

bool zyMAP1905_CtrlFromNbrCap_get(int option);

void zyMAP1905_VendSpecMsg_handle(void *msg_data, unsigned short msgId);

// int zyMAP1905_DebugLevel_set(void *pCmd, int argc, char *argv[]); //1

int zyMAP1905_RebootQuery_send(void *pCmd, int argc, char *argv[]); //2

int zyMAP1905_CtrlInftPwrQuery_send(void *pCmd, int argc, char *argv[]); //3

int zyMAP1905_FWCtrlQuery_send(void *pCmd, int argc, char *argv[]); //9

int zyMAP1905_ResetDefaultQuery_send(void *pCmd, int argc, char *argv[]); //10

int zyMAP1905_FwResult_set(void *pCmd, int argc, char *argv[]); //11

int zyMAP1905_CmdQuery_send(void *pCmd, int argc, char *argv[]); //100

int zyMAP1905_SyslogDbg_set(void *pCmd, int argc, char *argv[]); //d

RetCode zyMAP1905_VenderSpecMsg_send(unsigned char *macDa, unsigned short *msgId, unsigned char *specData);

RetCode zyMAP1905_VenderSpecMcastMsg_send(unsigned char *specData, unsigned short *msgId);

RetCode zyMAP1905_mdid_update(zyTopology_MdidInfo_t *pTopoMdid);

void zyMAP1905_ApCfg_reg();

RetCode zyMAP1905_ApCfg_set(zyMAP1905_bssInfo *bssInfo_recv);
#endif
