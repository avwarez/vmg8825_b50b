#include "zcfg_common.h"
#include "zcfg_msg.h"
#include "zcfg_ret.h"
#include "zcfg_rdm_obj.h"
#include "zcfg_fe_rdm_struct.h"
#include "zcfg_fe_rdm_access.h"
#include "zyee_zcfg_service.h"
#include "snmp_zcfg.h"

/* should remap rdm oid */
int RDM_OID_ZY_SNMP;
int RDM_OID_TRAP_ADDR;

static int snmpBoot(void)
{
    rdm_ZySnmp_t *snmpObj = NULL;
    objIndex_t snmpIid;
    int config_changed = 0;
    
    printf("Boot SNMP\n");
    zcfgEidInit(ZCFG_EID_ZYEE, PKG_NAME);
    
    IID_INIT(snmpIid);
    if (zcfgFeObjStructGet(RDM_OID_ZY_SNMP, &snmpIid, (void **)&snmpObj) != ZCFG_SUCCESS) {
        printf("%s: Failed to get RDM_OID_ZY_SNMP\n", __FUNCTION__);
        return -1;
    }
    
    /* stop snmp first if running */
    if (snmpStop() == ZCFG_SUCCESS)
        printf("%s: Stop snmpd\n", __FUNCTION__);
    
    if (snmpObj->Enable) {
        if (snmpConfCreate(snmpObj) == ZCFG_SUCCESS) {
            if (snmpStart(config_changed, 1) == ZCFG_SUCCESS)
                printf("%s: Start snmpd\n", __FUNCTION__);
            else
                printf("%s: Failed to start snmpd\n", __FUNCTION__);
        } else {
            printf("%s: Failed to create snmpd.conf\n", __FUNCTION__);
        }
    }
    
    zcfgFeObjStructFree(snmpObj);
    return 0;
}

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
    zyee_zcfg_service_init(PKG_NAME);

    /* should remap rdm oid */
    RDM_OID_ZY_SNMP = zyee_zcfg_rdm_oid_remap("RDM_OID_ZY_SNMP");
    RDM_OID_TRAP_ADDR = zyee_zcfg_rdm_oid_remap("RDM_OID_TRAP_ADDR");
  
    /* watch oid that we are interested */
    zyee_zcfg_service_oid_add_watch(RDM_OID_ZY_SNMP, snmp_zcfg_reload);
    zyee_zcfg_service_oid_add_watch(RDM_OID_TRAP_ADDR, snmptrap_zcfg_reload);

    snmpBoot();

    /* start the service daemon to listen zcfg-reload */
    zyee_zcfg_service_run();

    /* when goes here, it means the zcfg-service daemon is terminated */
    zyee_zcfg_service_cleanup();

    snmpStop();
    return 0;
}
