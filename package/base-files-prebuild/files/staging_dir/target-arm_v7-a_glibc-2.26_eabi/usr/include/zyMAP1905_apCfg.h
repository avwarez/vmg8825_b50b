/****************************************************************************
 *
 * Copyright (C) 2013 by ZyXEL
 *
 ****************************************************************************/

/**
 * @file   zyMAP_apCfg.h
 * @date   Feb 2019
 * @brief
 */

#ifndef __ZY_AP_CFG_H__
#define __ZY_AP_CFG_H__

#define SIZE_1_BYTE                1
#define SIZE_2_BYTES               2
#define SIZE_3_BYTES               3
#define IEEE1905_MAX_SSID_LEN      32
#define IEEE1905_MAX_KEY_LEN       64
#define MAP_BAND_24G               0x80
#define MAP_BAND_5G                0x40
#define MESH_IS_ENABLED_SSID       0x02
#define MAP_IDX_MASK               0x0F

#define ZYXEL_VENDOR_EXT_ID        "\x00\x03\x7A"
#define WPS_ZYXEL_EXT_BAND_INDEX   0x01
#define WPS_ZYXEL_EXT_ATTRIBUTE    0x02
#define WPS_ZYXEL_EXT_MDID         0x03
#define WPS_ZYXEL_EXT_TCI          0x04

#define WPS_ID_VENDOR_EXT          0x1049
#define ZYXEL_VENDORID1            0x00
#define ZYXEL_VENDORID2            0x03
#define ZYXEL_VENDORID3            0x7A

typedef struct {
	unsigned char          BandIndex;
	unsigned char          Attribute;
	unsigned short         MDID;
	unsigned short         TCI;
} zyMAP1905_bssInfo;

int zyMAP1905_ApCfg_fill(unsigned char *buf, int bufIdx, zyMAP1905_bssInfo *bssInfo_send);
int zyMAP1905_ApCfg_parse(unsigned char *q, zyMAP1905_bssInfo *bssInfo_recv);
void dumpBssInfo(zyMAP1905_bssInfo *dump_bssinfo);
#endif
