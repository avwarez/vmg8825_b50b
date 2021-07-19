/*************************************************************************** 
*  Copyright (C) 2008-2020 ZyXEL Communications, Corp.
*  All Rights Reserved.
*
* ZyXEL Confidential; Need to Know only.
* Protected as an unpublished work.
*
* The computer program listings, specifications and documentation
* herein are the property of ZyXEL Communications, Corp. and shall
* not be reproduced, copied, disclosed, or used in whole or in part
* for any reason without the prior express written permission of
* ZyXEL Communications, Corp.
*
**************************************************************************/
#ifndef _BE_MODULE_DEBUG_H
#define _BE_MODULE_DEBUG_H

#define BE_MODULE_DEBUG_LEVEL_FILE "/tmp/zcmd_debug_level"

typedef struct zcfg_dbg_module_list_s { 
	char *module; 
	int *level; 
	int eid[4];
 } zcfg_dbg_module_list_t;
 
extern struct zcfg_dbg_module_list_s zcfg_dbg_module_list[];
extern int zcfg_module_dbg_level;
extern int zcfg_module_err_level;
extern int zcfg_module_dbg_init;
extern void ZCFG_PRINT(const char *fmt, ...);

extern int debug_all;
extern int debug_begui_customization;
extern int debug_behome_cyber_security;
extern int debug_bedevice;
extern int debug_bezylog;
extern int debug_besysinfo;
extern int debug_beaccount;
extern int debug_bedevinfo;
extern int debug_beethlink;
extern int debug_beethintf;
extern int debug_bewifi_radio;
extern int debug_bewifi_ssid;
extern int debug_bewifi_ap;
extern int debug_bewifi_apsteer;
extern int debug_bewifi_easymesh;
extern int debug_bewifi_onessid;
extern int debug_bewifi_soniq;
extern int debug_bewlan_scheduler;
extern int debug_bebridging;
extern int debug_bebridgingbr;
extern int debug_bebridgePort;
extern int debug_bebridgeFilter;
extern int debug_bewifi;
extern int debug_beipiface;
extern int debug_beipk;
extern int debug_beipp;
extern int debug_belog;
extern int debug_beloopguard;
extern int debug_benatIntf;
extern int debug_bev4addr;
extern int debug_bev6addr;
extern int debug_bev6prefix;
extern int debug_beusbhost;
extern int debug_beusbintf;
extern int debug_beusbport;
extern int debug_bedsl;
extern int debug_bextmlink;
extern int debug_bezlog;
extern int debug_bezx;
extern int debug_bezyee;
extern int debug_bezylicense;
extern int debug_beatmlink;
extern int debug_beptmlink;
extern int debug_bePwrMgmt;
extern int debug_berouter;
extern int debug_berainfo;
extern int debug_bedhcp4_server;
extern int debug_bedhcp4_serverpool;
extern int debug_bedhcp4_serverpool_option;
extern int debug_bedhcp4_serverpool_staticaddr;
extern int debug_bedhcp4_serversubnet;
extern int debug_bedhcp4_relay;
extern int debug_bedhcp6_server;
extern int debug_bedhcp6_serverpool;
extern int debug_bevlanTerm;
extern int debug_bevoiceCallPolicyBook;
extern int debug_bevoiceCallPolicyBookList;
extern int debug_bevoiceCallStatus;
extern int debug_bevoiceCap;
extern int debug_bevoiceCapCodec;
extern int debug_bevoiceCapSip;
extern int debug_bevoiceCommon;
extern int debug_bevoiceLine;
extern int debug_bevoiceLineCallingFeatures;
extern int debug_bevoiceLineCodecList;
extern int debug_bevoiceLineProc;
extern int debug_bevoiceLineRinger;
extern int debug_bevoiceLineRingerDescription;
extern int debug_bevoiceLineSip;
extern int debug_bevoiceLineStats;
extern int debug_bevoicePhonebook;
extern int debug_bevoicePhyIntf;
extern int debug_bevoiceProf;
extern int debug_bevoiceProfFaxT38;
extern int debug_bevoiceProfNumberingPlan;
extern int debug_bevoiceProfNumberingPlanPrefixInfo;
extern int debug_bevoiceProfRTP;
extern int debug_bevoiceProfRTPSRTP;
extern int debug_bevoiceProfSip;
extern int debug_bevoiceSpeedDialBookList;
extern int debug_bevoiceSrv;
extern int debug_bepppiface;
extern int debug_bepppifaceipcp;
extern int debug_bepptp;
extern int debug_beproximitysensor;
extern int debug_bedhcp4_client;
extern int debug_bedhcp6_client;
extern int debug_beradvd;
extern int debug_beradvdOpt;
extern int debug_bedns;
extern int debug_bedns_route;
extern int debug_bedns_server;
extern int debug_benat_port_map;
extern int debug_benat_port_trigger;
extern int debug_benat_addr_mapping;
extern int debug_beneigh;
extern int debug_beoiwizard;
extern int debug_besessCtl;
extern int debug_besfpMgmt;
extern int debug_befirewall;
extern int debug_beGpon;
extern int debug_begponinfo;
extern int debug_begreTunnel;
extern int debug_begreTunnelIface;
extern int debug_bebridgingfirewall;
extern int debug_betr69;
extern int debug_beddns;
extern int debug_betime;
extern int debug_bediagnostic;
extern int debug_beschedule;
extern int debug_beparenCtl;
extern int debug_beqos;
extern int debug_beqosQueue;
extern int debug_beqosClass;
extern int debug_beqosPolicer;
extern int debug_beqosShaper;
extern int debug_be6rd;
extern int debug_beigmp;
extern int debug_besnmp;
extern int debug_bemld;
extern int debug_bemosUserConfig;
extern int debug_bevcAutoHunt;
extern int debug_bevlanAutoHunt;
extern int debug_beupnp;
extern int debug_beurl_filter;
extern int debug_bemacfilter;
extern int debug_bemacfilter_whitelist;
extern int debug_beuserinterface;
extern int debug_beremoMgmt;
extern int debug_behosts;
extern int debug_behostshost;
extern int debug_becert;
extern int debug_bechangehosticon;
extern int debug_bedatausage;
extern int debug_beportmirror;
extern int debug_bedslite;
extern int debug_beduStateChangeComplPol;
extern int debug_beSTBVendorID;
extern int debug_berip;
extern int debug_bebgp;
extern int debug_beospfv2;
extern int debug_betr64;
extern int debug_bewwanbackup;
extern int debug_beXpon;
extern int debug_besamba;
extern int debug_bednsentry;
extern int debug_bednsRelay;
extern int debug_bednsforwarder;
extern int debug_bedlna;
extern int debug_bevlangroup;
extern int debug_beTFTPServerName;
extern int debug_bespeedtest;
extern int debug_beoneconnect;
extern int debug_beoneconnectPCRule;
extern int debug_beonlineFWUpgrade;
extern int debug_beadp;
extern int debug_beadpSystemProtect;
extern int debug_beipsecTunnel;
extern int debug_beipsecFilter;
extern int debug_beipsecProfile;
extern int debug_beipsecXmlReload;
extern int debug_beipsec;
extern int debug_befreeradius;
extern int debug_befreeradiusRadius;
extern int debug_befreeradiusLdap;
extern int debug_bepptpvpn;
extern int debug_bel2tpvpn;
extern int debug_bel2client;
extern int debug_begrevpn;
extern int debug_begre;
extern int debug_bevrfLite;
extern int debug_bemultiwan;
extern int debug_beconnectivity;
extern int debug_libzcfg_be_common;
extern int debug_libzcfg_be_cyber_security;
extern int debug_libzcfg_be_xtmlink;
extern int debug_libzcfg_be_qos;
extern int debug_libzcfg_be_wan;
extern int debug_libzcfg_be_lan;
extern int debug_libzcfg_be_iptables;
extern int debug_libzcfg_be_route;
extern int debug_libzcfg_be_tms;
extern int debug_libzcfg_be_dns;
extern int debug_libzcfg_be_wlan;
extern int debug_libzcfg_be_macfilter;
extern int debug_libzcfg_be_usb;
extern int debug_libzcfg_be_voice;
extern int debug_libzcfg_be_pki;
extern int debug_libzcfg_be_object;
extern int debug_libzcfg_be_quicksec;
extern int debug_libzcfg_be_freeradius;
extern int debug_becfilter; //jessy 20180329
extern int debug_bediaginfo;
extern int debug_begdpr; //XYZ,20180507

extern int debug_esmd;

extern int debug_zcmd;
extern int debug_zcmd_tr98;

extern zcfg_dbg_module_list_t * zcfg_get_module_debug_level( char *module, char *buf, int count );
extern zcfg_dbg_module_list_t * zcfg_set_module_debug_level( char *module, int level );
extern zcfg_dbg_module_list_t * zcfg_update_module_debug_level( char *module, char *buf );
#endif
