#ifndef SNMP_ZCFG_H
#define SNMP_ZCFG_H

#ifndef PKG_NAME
#error "Must provide -DPKG_NAME=string at compiling time!"
#endif

#ifdef _ZCFG_RDM_OID_H
#error "should NOT include zcfg_rdm_oid.h"
#endif

#define rpWarn(fmt, arg...) printf("%s: "fmt"\n",__func__,  ##arg);
#define rpFail(fmt, arg...) { rpWarn(fmt, ##arg); goto rpDone; }

#define SNMPD_CONFIG_TMP "/etc/snmp/snmpd.conf.tmp"
#define SNMPD_CONFIG "/var/snmpd.conf"
#define SNMPD_PID "/var/run/snmpd"

zcfgRet_t snmpConfCreate(rdm_ZySnmp_t *snmpObj);
zcfgRet_t snmpStop();
zcfgRet_t snmpStart(unsigned char configModified, unsigned char isboot);

int snmp_zcfg_reload(void *newObj, void *curObj, unsigned int oid, objIndex_t *objIid);
int snmptrap_zcfg_reload(void *newObj, void *curObj, unsigned int oid, objIndex_t *objIid);

#endif

