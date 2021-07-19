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
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "be_module_debug.h"
int zcfg_module_err_level = 3; //ZCFG_LOG_ERROR
int zcfg_module_dbg_level = 7;//ZCFG_LOG_DEBUG
int zcfg_module_dbg_init = 0;

void 
ZCFG_PRINT(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	vprintf(fmt,ap);
	va_end(ap);
}

int debug_all = 0;
int debug_begui_customization = 0;
int debug_behome_cyber_security = 0;
int debug_bedevice = 0;
int debug_bezylog = 0;
int debug_besysinfo = 0;
int debug_beaccount = 0;
int debug_bedevinfo = 0;
int debug_beethlink = 0;
int debug_beethintf = 0;
int debug_bewifi_radio = 0;
int debug_bewifi_ssid = 0;
int debug_bewifi_ap = 0;
int debug_bewifi_apsteer = 0;
int debug_bewifi_easymesh = 0;
int debug_bewifi_onessid = 0;
int debug_bewifi_soniq = 0;
int debug_bewlan_scheduler = 0;
int debug_bebridging = 0;
int debug_bebridgingbr = 0;
int debug_bebridgePort = 0;
int debug_bebridgeFilter = 0;
int debug_bewifi = 0;
int debug_beipiface = 0;
int debug_beipk = 0;
int debug_beipp = 0;
int debug_belog = 0;
int debug_beloopguard = 0;
int debug_benatIntf = 0;
int debug_bev4addr = 0;
int debug_bev6addr = 0;
int debug_bev6prefix = 0;
int debug_beusbhost = 0;
int debug_beusbintf = 0;
int debug_beusbport = 0;
int debug_bedsl = 0;
int debug_bextmlink = 0;
int debug_bezlog = 0;
int debug_bezx = 0;
int debug_bezyee = 0;
int debug_bezylicense = 0;
int debug_beatmlink = 0;
int debug_beptmlink = 0;
int debug_bePwrMgmt = 0;
int debug_berouter = 0;
int debug_berainfo = 0;
int debug_bedhcp4_server = 0;
int debug_bedhcp4_serverpool = 0;
int debug_bedhcp4_serverpool_option = 0;
int debug_bedhcp4_serverpool_staticaddr = 0;
int debug_bedhcp4_serversubnet = 0;
int debug_bedhcp4_relay = 0;
int debug_bedhcp6_server = 0;
int debug_bedhcp6_serverpool = 0;
int debug_bevlanTerm = 0;
int debug_bevoiceCallPolicyBook = 0;
int debug_bevoiceCallPolicyBookList = 0;
int debug_bevoiceCallStatus = 0;
int debug_bevoiceCap = 0;
int debug_bevoiceCapCodec = 0;
int debug_bevoiceCapSip = 0;
int debug_bevoiceCommon = 0;
int debug_bevoiceLine = 0;
int debug_bevoiceLineCallingFeatures = 0;
int debug_bevoiceLineCodecList = 0;
int debug_bevoiceLineProc = 0;
int debug_bevoiceLineRinger = 0;
int debug_bevoiceLineRingerDescription = 0;
int debug_bevoiceLineSip = 0;
int debug_bevoiceLineStats = 0;
int debug_bevoicePhonebook = 0;
int debug_bevoicePhyIntf = 0;
int debug_bevoiceProf = 0;
int debug_bevoiceProfFaxT38 = 0;
int debug_bevoiceProfNumberingPlan = 0;
int debug_bevoiceProfNumberingPlanPrefixInfo = 0;
int debug_bevoiceProfRTP = 0;
int debug_bevoiceProfRTPSRTP = 0;
int debug_bevoiceProfSip = 0;
int debug_bevoiceSpeedDialBookList = 0;
int debug_bevoiceSrv = 0;
int debug_bepppiface = 0;
int debug_bepppifaceipcp = 0;
int debug_bepptp = 0;
int debug_beproximitysensor = 0;
int debug_bedhcp4_client = 0;
int debug_bedhcp6_client = 0;
int debug_beradvd = 0;
int debug_beradvdOpt = 0;
int debug_bedns = 0;
int debug_bedns_route = 0;
int debug_bedns_server = 0;
int debug_benat_port_map = 0;
int debug_benat_port_trigger = 0;
int debug_benat_addr_mapping = 0;
int debug_beneigh = 0;
int debug_beoiwizard = 0;
int debug_besessCtl = 0;
int debug_besfpMgmt = 0;
int debug_befirewall = 0;
int debug_beGpon = 0;
int debug_begponinfo = 0;
int debug_begreTunnel = 0;
int debug_begreTunnelIface = 0;
int debug_bebridgingfirewall = 0;
int debug_betr69 = 0;
int debug_beddns = 0;
int debug_betime = 0;
int debug_bediagnostic = 0;
int debug_beschedule = 0;
int debug_beparenCtl = 0;
int debug_beqos = 0;
int debug_beqosQueue = 0;
int debug_beqosClass = 0;
int debug_beqosPolicer = 0;
int debug_beqosShaper = 0;
int debug_be6rd = 0;
int debug_beigmp = 0;
int debug_besnmp = 0;
int debug_bemld = 0;
int debug_bemosUserConfig = 0;
int debug_bevcAutoHunt = 0;
int debug_bevlanAutoHunt = 0;
int debug_beupnp = 0;
int debug_beurl_filter = 0;
int debug_bemacfilter = 0;
int debug_bemacfilter_whitelist = 0;
int debug_beuserinterface = 0;
int debug_beremoMgmt = 0;
int debug_behosts = 0;
int debug_behostshost = 0;
int debug_becert = 0;
int debug_bechangehosticon = 0;
int debug_bedatausage = 0;
int debug_beportmirror = 0;
int debug_bedslite = 0;
int debug_beduStateChangeComplPol = 0;
int debug_beSTBVendorID = 0;
int debug_berip = 0;
int debug_bebgp = 0;
int debug_beospfv2 = 0;
int debug_betr64 = 0;
int debug_bewwanbackup = 0;
int debug_beXpon = 0;
int debug_besamba = 0;
int debug_bednsentry = 0;
int debug_bednsRelay = 0;
int debug_bednsforwarder = 0;
int debug_bedlna = 0;
int debug_bevlangroup = 0;
int debug_beTFTPServerName = 0;
int debug_bespeedtest = 0;
int debug_beoneconnect = 0;
int debug_beoneconnectPCRule = 0;
int debug_beonlineFWUpgrade = 0;
int debug_beadp = 0;
int debug_beadpSystemProtect = 0;
int debug_beipsecTunnel = 0;
int debug_beipsecFilter = 0;
int debug_beipsecProfile = 0;
int debug_beipsecXmlReload = 0;
int debug_beipsec = 0;
int debug_befreeradius = 0;
int debug_befreeradiusRadius = 0;
int debug_befreeradiusLdap = 0;
int debug_bepptpvpn = 0;
int debug_bel2tpvpn = 0;
int debug_bel2client = 0;
int debug_begrevpn = 0;
int debug_begre = 0;
int debug_bevrfLite = 0;
int debug_bemultiwan = 0;
int debug_beconnectivity = 0;
int debug_libzcfg_be_common = 0;
int debug_libzcfg_be_cyber_security = 0;
int debug_libzcfg_be_xtmlink = 0;
int debug_libzcfg_be_qos = 0;
int debug_libzcfg_be_wan = 0;
int debug_libzcfg_be_lan = 0;
int debug_libzcfg_be_iptables = 0;
int debug_libzcfg_be_route = 0;
int debug_libzcfg_be_tms = 0;
int debug_libzcfg_be_dns = 0;
int debug_libzcfg_be_wlan = 0;
int debug_libzcfg_be_macfilter = 0;
int debug_libzcfg_be_usb = 0;
int debug_libzcfg_be_voice = 0;
int debug_libzcfg_be_pki = 0;
int debug_libzcfg_be_object = 0;
int debug_libzcfg_be_quicksec = 0;
int debug_libzcfg_be_freeradius = 0;
int debug_becfilter = 0; //jessy 20180329
int debug_bediaginfo = 0;
int debug_begdpr = 0; //XYZ, 20180504

/* esmd part */
int debug_esmd = 0;

/* zcmd part */
int debug_zcmd = 0;
int debug_zcmd_tr98 = 0;

zcfg_dbg_module_list_t zcfg_dbg_module_list[]={ 
/* special module */
{"all", &debug_all},
{"printf", &zcfg_module_dbg_level}, // all module error large than this level printf function will print to console
{"zcfgLog", &zcfg_module_err_level}, // all module error large than this level zcfgLog function will print to console
/* zcfg_be */
{"begui_customization", &debug_begui_customization},
{"behome_cyber_security", &debug_behome_cyber_security},
{"bedevice", &debug_bedevice},
{"bezylog", &debug_bezylog},
{"besysinfo", &debug_besysinfo},
{"beaccount", &debug_beaccount},
{"bedevinfo", &debug_bedevinfo},
{"beethlink", &debug_beethlink},
{"beethintf", &debug_beethintf},
{"bewifi_radio", &debug_bewifi_radio},
{"bewifi_ssid", &debug_bewifi_ssid},
{"bewifi_ap", &debug_bewifi_ap},
{"bewifi_apsteer", &debug_bewifi_apsteer},
{"bewifi_easymesh", &debug_bewifi_easymesh},
{"bewifi_onessid", &debug_bewifi_onessid},
{"bewifi_soniq", &debug_bewifi_soniq},
{"bewlan_scheduler", &debug_bewlan_scheduler},
{"bebridging", &debug_bebridging},
{"bebridgingbr", &debug_bebridgingbr},
{"bebridgePort", &debug_bebridgePort},
{"bebridgeFilter", &debug_bebridgeFilter},
{"bewifi", &debug_bewifi},
{"beipiface", &debug_beipiface},
{"beipk", &debug_beipk},
{"beipp", &debug_beipp},
{"belog", &debug_belog},
{"beloopguard", &debug_beloopguard},
{"benatIntf", &debug_benatIntf},
{"bev4addr", &debug_bev4addr},
{"bev6addr", &debug_bev6addr},
{"bev6prefix", &debug_bev6prefix},
{"beusbhost", &debug_beusbhost},
{"beusbintf", &debug_beusbintf},
{"beusbport", &debug_beusbport},
{"bedsl", &debug_bedsl},
{"bextmlink", &debug_bextmlink},
{"bezlog", &debug_bezlog},
{"bezx", &debug_bezx},
{"bezyee", &debug_bezyee},
{"bezylicense", &debug_bezylicense},
{"beatmlink", &debug_beatmlink},
{"beptmlink", &debug_beptmlink},
{"bePwrMgmt", &debug_bePwrMgmt},
{"berouter", &debug_berouter},
{"berainfo", &debug_berainfo},
{"bedhcp4_server", &debug_bedhcp4_server},
{"bedhcp4_serverpool", &debug_bedhcp4_serverpool},
{"bedhcp4_serverpool_option", &debug_bedhcp4_serverpool_option},
{"bedhcp4_serverpool_staticaddr", &debug_bedhcp4_serverpool_staticaddr},
{"bedhcp4_serversubnet", &debug_bedhcp4_serversubnet},
{"bedhcp4_relay", &debug_bedhcp4_relay},
{"bedhcp6_server", &debug_bedhcp6_server},
{"bedhcp6_serverpool", &debug_bedhcp6_serverpool},
{"bevlanTerm", &debug_bevlanTerm},
{"bevoiceCallPolicyBook", &debug_bevoiceCallPolicyBook},
{"bevoiceCallPolicyBookList", &debug_bevoiceCallPolicyBookList},
{"bevoiceCallStatus", &debug_bevoiceCallStatus},
{"bevoiceCap", &debug_bevoiceCap},
{"bevoiceCapCodec", &debug_bevoiceCapCodec},
{"bevoiceCapSip", &debug_bevoiceCapSip},
{"bevoiceCommon", &debug_bevoiceCommon},
{"bevoiceLine", &debug_bevoiceLine},
{"bevoiceLineCallingFeatures", &debug_bevoiceLineCallingFeatures},
{"bevoiceLineCodecList", &debug_bevoiceLineCodecList},
{"bevoiceLineProc", &debug_bevoiceLineProc},
{"bevoiceLineRinger", &debug_bevoiceLineRinger},
{"bevoiceLineRingerDescription", &debug_bevoiceLineRingerDescription},
{"bevoiceLineSip", &debug_bevoiceLineSip},
{"bevoiceLineStats", &debug_bevoiceLineStats},
{"bevoicePhonebook", &debug_bevoicePhonebook},
{"bevoicePhyIntf", &debug_bevoicePhyIntf},
{"bevoiceProf", &debug_bevoiceProf},
{"bevoiceProfFaxT38", &debug_bevoiceProfFaxT38},
{"bevoiceProfNumberingPlan", &debug_bevoiceProfNumberingPlan},
{"bevoiceProfNumberingPlanPrefixInfo", &debug_bevoiceProfNumberingPlanPrefixInfo},
{"bevoiceProfRTP", &debug_bevoiceProfRTP},
{"bevoiceProfRTPSRTP", &debug_bevoiceProfRTPSRTP},
{"bevoiceProfSip", &debug_bevoiceProfSip},
{"bevoiceSpeedDialBookList", &debug_bevoiceSpeedDialBookList},
{"bevoiceSrv", &debug_bevoiceSrv},
{"bepppiface", &debug_bepppiface},
{"bepppifaceipcp", &debug_bepppifaceipcp},
{"bepptp", &debug_bepptp},
{"beproximitysensor", &debug_beproximitysensor},
{"bedhcp4_client", &debug_bedhcp4_client},
{"bedhcp6_client", &debug_bedhcp6_client},
{"beradvd", &debug_beradvd},
{"beradvdOpt", &debug_beradvdOpt},
{"bedns", &debug_bedns},
{"bedns_route", &debug_bedns_route},
{"bedns_server", &debug_bedns_server},
{"benat_port_map", &debug_benat_port_map},
{"benat_port_trigger", &debug_benat_port_trigger},
{"benat_addr_mapping", &debug_benat_addr_mapping},
{"beneigh", &debug_beneigh},
{"beoiwizard", &debug_beoiwizard},
{"besessCtl", &debug_besessCtl},
{"besfpMgmt", &debug_besfpMgmt},
{"befirewall", &debug_befirewall},
{"beGpon", &debug_beGpon},
{"begponinfo", &debug_begponinfo},
{"begreTunnel", &debug_begreTunnel},
{"begreTunnelIface", &debug_begreTunnelIface},
{"bebridgingfirewall", &debug_bebridgingfirewall},
{"betr69", &debug_betr69},
{"beddns", &debug_beddns},
{"betime", &debug_betime},
{"bediagnostic", &debug_bediagnostic},
{"beschedule", &debug_beschedule},
{"beparenCtl", &debug_beparenCtl},
{"beqos", &debug_beqos},
{"beqosQueue", &debug_beqosQueue},
{"beqosClass", &debug_beqosClass},
{"beqosPolicer", &debug_beqosPolicer},
{"beqosShaper", &debug_beqosShaper},
{"be6rd", &debug_be6rd},
{"beigmp", &debug_beigmp},
{"besnmp", &debug_besnmp},
{"bemld", &debug_bemld},
{"bemosUserConfig", &debug_bemosUserConfig},
{"bevcAutoHunt", &debug_bevcAutoHunt},
{"bevlanAutoHunt", &debug_bevlanAutoHunt},
{"beupnp", &debug_beupnp},
{"beurl_filter", &debug_beurl_filter},
{"bemacfilter", &debug_bemacfilter},
{"bemacfilter_whitelist", &debug_bemacfilter_whitelist},
{"beuserinterface", &debug_beuserinterface},
{"beremoMgmt", &debug_beremoMgmt},
{"behosts", &debug_behosts},
{"behostshost", &debug_behostshost},
{"becert", &debug_becert},
{"bechangehosticon", &debug_bechangehosticon},
{"bedatausage", &debug_bedatausage},
{"beportmirror", &debug_beportmirror},
{"bedslite", &debug_bedslite},
{"beduStateChangeComplPol", &debug_beduStateChangeComplPol},
{"beSTBVendorID", &debug_beSTBVendorID},
{"berip", &debug_berip},
{"bebgp", &debug_bebgp},
{"beospfv2", &debug_beospfv2},
{"betr64", &debug_betr64},
{"bewwanbackup", &debug_bewwanbackup},
{"beXpon", &debug_beXpon},
{"besamba", &debug_besamba},
{"bednsentry", &debug_bednsentry},
{"bednsRelay", &debug_bednsRelay},
{"bednsforwarder", &debug_bednsforwarder},
{"bedlna", &debug_bedlna},
{"bevlangroup", &debug_bevlangroup},
{"beTFTPServerName", &debug_beTFTPServerName},
{"bespeedtest", &debug_bespeedtest},
{"beoneconnect", &debug_beoneconnect},
{"beoneconnectPCRule", &debug_beoneconnectPCRule},
{"beonlineFWUpgrade", &debug_beonlineFWUpgrade},
{"beadp", &debug_beadp},
{"beadpSystemProtect", &debug_beadpSystemProtect},
{"beipsecTunnel", &debug_beipsecTunnel},
{"beipsecFilter", &debug_beipsecFilter},
{"beipsecProfile", &debug_beipsecProfile},
{"beipsecXmlReload", &debug_beipsecXmlReload},
{"beipsec", &debug_beipsec},
{"befreeradius", &debug_befreeradius},
{"befreeradiusRadius", &debug_befreeradiusRadius},
{"befreeradiusLdap", &debug_befreeradiusLdap},
{"bepptpvpn", &debug_bepptpvpn},
{"bel2tpvpn", &debug_bel2tpvpn},
{"bel2client", &debug_bel2client},
{"begrevpn", &debug_begrevpn},
{"begre", &debug_begre},
{"bemultiwan", &debug_bemultiwan},
{"beconnectivity", &debug_beconnectivity},
{"becfilter", &debug_becfilter}, //jessy 20180329
{"bediaginfo", &debug_bediaginfo},
{"begdpr", &debug_begdpr}, //XYZ, 20180504
{"libzcfg_be_common", &debug_libzcfg_be_common},
{"libzcfg_be_cyber_security", &debug_libzcfg_be_cyber_security},
{"libzcfg_be_xtmlink", &debug_libzcfg_be_xtmlink},
{"libzcfg_be_qos", &debug_libzcfg_be_qos},
{"libzcfg_be_wan", &debug_libzcfg_be_wan},
{"libzcfg_be_lan", &debug_libzcfg_be_lan},
{"libzcfg_be_iptables", &debug_libzcfg_be_iptables},
{"libzcfg_be_route", &debug_libzcfg_be_route},
{"libzcfg_be_tms", &debug_libzcfg_be_tms},
{"libzcfg_be_dns", &debug_libzcfg_be_dns},
{"libzcfg_be_wlan", &debug_libzcfg_be_wlan},
{"libzcfg_be_macfilter", &debug_libzcfg_be_macfilter},
{"libzcfg_be_usb", &debug_libzcfg_be_usb},
{"libzcfg_be_voice", &debug_libzcfg_be_voice},
{"libzcfg_be_pki", &debug_libzcfg_be_pki},
{"libzcfg_be_object", &debug_libzcfg_be_object},
{"libzcfg_be_quicksec", &debug_libzcfg_be_quicksec},
{"libzcfg_be_freeradius", &debug_libzcfg_be_freeradius},
/* ESMD part */
{"esmd", &debug_esmd},
/* ZCMD part */
{"zcmd", &debug_zcmd},
{"zcmd_tr98", &debug_zcmd_tr98},
{NULL,0}
};


zcfg_dbg_module_list_t * 
zcfg_set_module_debug_level( char *module, int level )
{
	zcfg_dbg_module_list_t *dbg_p = &zcfg_dbg_module_list[0];
	
	if ( strcmp(module,"all") == 0 ) {
		while ( dbg_p-> module != NULL ) {
			*(dbg_p->level) = level;
			dbg_p++;
		}
		return &zcfg_dbg_module_list[0];
	}

	while ( dbg_p-> module != NULL ) {
		if ( strcmp(dbg_p->module,module) == 0 ) {
			if ( level <= 0 ) { 
				level = 0;
			} else if ( level >= 8 ) {
				level = 8;
			}
			*(dbg_p->level) = level;
			return dbg_p;
		}
		dbg_p++;
	}
	return NULL;
}


zcfg_dbg_module_list_t *
zcfg_get_module_debug_level( char *module, char *buf, int count)
{
	zcfg_dbg_module_list_t *dbg_p = &zcfg_dbg_module_list[0];
	int i = 0;
	
	if ( strcmp(module,"all") == 0 ) {
		while ( dbg_p-> module != NULL ) {
			buf[i] = (char )*(dbg_p->level);
			dbg_p++;
			i++;
			if ( i >= count ) {
				printf("debug module over buffer size\n");
				return NULL;
			}
		}
		return &zcfg_dbg_module_list[0];
	}
	
	while ( dbg_p-> module != NULL ) {
		if ( strcmp(dbg_p->module,module) == 0 ) {
			buf[0] = (char )*(dbg_p->level); 
			return dbg_p;
		}
		dbg_p++;
	}
	return NULL;
}

zcfg_dbg_module_list_t * 
zcfg_update_module_debug_level( char *module, char *buf )
{
	zcfg_dbg_module_list_t *dbg_p = &zcfg_dbg_module_list[0];
	char *level = buf;

	/* process all case */
	if ( strcmp(module,"all") == 0 ) {
		while ( dbg_p-> module != NULL ) {
			if ( ( strcmp(dbg_p->module,"printf") == 0 ) || 
				( strcmp(dbg_p->module,"zcfg_log") == 0 )) {
				/* Skip this special item 
					The item all should be skip too. But skip this one to speed up process 
				*/
			}
			else {
				*(dbg_p->level) = (int)(*level);
			}
			level++;
			dbg_p++;
		}
		return &zcfg_dbg_module_list[0];
	}

	while ( dbg_p-> module != NULL ) {
		if ( strcmp(dbg_p->module,module) == 0 ) {
			*(dbg_p->level) = (int)(*level);
			return dbg_p;
		}
		dbg_p++;
	}
	return NULL;
}
