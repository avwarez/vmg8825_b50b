#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include "zcfg_common.h"
#include "zcfg_msg.h"
#include "zcfg_ret.h"
#include "zcfg_rdm_obj.h"
#include "zcfg_fe_rdm_struct.h"
#include "zcfg_fe_rdm_access.h"
#include "snmp_zcfg.h"

/* should remap rdm oid */
extern int RDM_OID_ZY_SNMP;
extern int RDM_OID_TRAP_ADDR;

static char* find_match(const char *buf, const char * buf_end, const char *match, size_t len)
{
    int i;
    const char *start = buf;
    while (start + len < buf_end) {
        for (i = 0; i < len; i++)
            if (start[i] != match[i]) break;

        if (i == len) return (char *)start;
        start++;
    }
    return 0;
}

static int ReplaceFile(const char *m, const char *r, const char *fname)
{
    long buf_len;
    int ret = -1;
    char *buf = NULL, *start = NULL, *end = NULL;
    size_t len = strlen(m), nlen = strlen(r);
    FILE *fd = NULL;
    
    if ((fd = fopen(fname, "r")) == NULL) rpFail("Can't open file(%s)", fname);

    fseek(fd, 0, SEEK_END);
    buf_len = ftell(fd);
    if ( !(buf = (char*)malloc(buf_len)) ) rpFail("Can't alloc memory(%ld)", buf_len);

    fseek(fd, 0, SEEK_SET);
    if (fread(buf, 1, buf_len, fd) != buf_len) rpFail("fail to read file");
    fclose(fd);
    fd = NULL;

    ret = 0;
    start = buf;
    end = find_match(start, buf + buf_len, m, len);
    if (!end) rpFail("Not match");

    fd = fopen(fname, "w");
    if (fd != NULL) {
        do {
            ret++;
            fwrite(start, 1, end - start, fd);
            fwrite(r, 1, nlen, fd);
            start = end + len;
            end = find_match(start, buf + buf_len, m, len);
        } while (end);

        if (start < (buf + buf_len))
            fwrite(start, 1,  (buf + buf_len) - start, fd);
    }
rpDone:
    if (fd != NULL) {fclose(fd); fd = NULL;}
    if (buf) free(buf);
    return ret;
}

zcfgRet_t snmpConfCreate(rdm_ZySnmp_t *snmpObj)
{
    rdm_TrapAddr_t *trapAddrObj = NULL;
    objIndex_t trapAddrIid;
    FILE *snmpConf;
    char cmd[256];

    /* snmp config */
    if (snmpObj == NULL)
        return ZCFG_INTERNAL_ERROR;

    snmpConf = fopen(SNMPD_CONFIG, "w");
    if (snmpConf == NULL) {
        printf("%s: Failed to open %s\n", __func__, SNMPD_CONFIG);
        return ZCFG_INTERNAL_ERROR;
    }

    fprintf(snmpConf, "agentaddress udp:%d,tcp:%d", snmpObj->Port, snmpObj->Port);
#ifdef SUPPORT_IPV6
    fprintf(snmpConf, ",udp6:%d,tcp6:%d", snmpObj->Port, snmpObj->Port);
#endif
    fprintf(snmpConf, "\n\n");
    fprintf(snmpConf, "rocommunity %s\n", strcmp(snmpObj->ROCommunity, snmpObj->RWCommunity) ? snmpObj->ROCommunity : "");
    fprintf(snmpConf, "rwcommunity %s\n", snmpObj->RWCommunity);
    fprintf(snmpConf, "trapcommunity %s\n", snmpObj->TrapCommunity);
    fprintf(snmpConf, "\n");
#ifdef SUPPORT_IPV6 //__ZYXEL__, Chi-Hsiang
    fprintf(snmpConf, "rocommunity6 %s\n", strcmp(snmpObj->ROCommunity, snmpObj->RWCommunity) ? snmpObj->ROCommunity : "");
    fprintf(snmpConf, "rwcommunity6 %s\n", snmpObj->RWCommunity);
    fprintf(snmpConf, "\n");
#endif
    fprintf(snmpConf, "com2sec RoUser default %s\n", strcmp(snmpObj->ROCommunity, snmpObj->RWCommunity) ? snmpObj->ROCommunity : "");
    fprintf(snmpConf, "com2sec RwUser default %s\n", snmpObj->RWCommunity);
    fprintf(snmpConf, "com2sec TrapUser default %s\n", snmpObj->TrapCommunity);
    fprintf(snmpConf, "group RoUserGroup v1 RoUser\n" \
                      "group RoUserGroup v2c RoUser\n" \
                      "group RwUserGroup v1 RwUser\n" \
                      "group RwUserGroup v2c RwUser\n" \
                      "group TrapUserGroup v1 TrapUser\n" \
                      "group TrapUserGroup v2c TrapUser\n" \
                      "access RoUserGroup \"\" any noauth exact all none none\n" \
                      "access RwUserGroup \"\" any noauth exact all all none\n" \
                      "access TrapUserGroup \"\" any noauth exact all none all\n" \
            );
    fprintf(snmpConf, "\n");
    fprintf(snmpConf, "rouser admin\n");
    fprintf(snmpConf, "iquerySecName admin\n");
    fprintf(snmpConf, "\n");
    fprintf(snmpConf, "notificationEvent linkUpTrap .1.3.6.1.6.3.1.1.5.4 .1.3.6.1.2.1.2.2.1.1 .1.3.6.1.2.1.2.2.1.2 .1.3.6.1.2.1.2.2.1.7 .1.3.6.1.2.1.2.2.1.8\n");
    fprintf(snmpConf, "notificationEvent linkDownTrap .1.3.6.1.6.3.1.1.5.3 .1.3.6.1.2.1.2.2.1.1 .1.3.6.1.2.1.2.2.1.2 .1.3.6.1.2.1.2.2.1.7 .1.3.6.1.2.1.2.2.1.8\n");
    fprintf(snmpConf, "monitor  -r 30 -e linkUpTrap   \"Interface linkUp\"   .1.3.6.1.2.1.2.2.1.8 != 2\n");
    fprintf(snmpConf, "monitor  -r 30 -e linkDownTrap \"Interface linkDown\" .1.3.6.1.2.1.2.2.1.8 == 2\n");
    fprintf(snmpConf, "\n");

    /* snmp-trap */
    IID_INIT(trapAddrIid);
    while (zcfgFeObjStructGetNext(RDM_OID_TRAP_ADDR, &trapAddrIid, (void **)&trapAddrObj) == ZCFG_SUCCESS) {
        if (strcmp(trapAddrObj->Host, "")) {
            if (trapAddrObj->TarpVer == 2)
                sprintf(cmd, "trap2sink");
            else
                sprintf(cmd, "trapsink");

            fprintf(snmpConf,"%s %s %s %d\n", cmd, trapAddrObj->Host, snmpObj->TrapCommunity, trapAddrObj->Port);
        }
        zcfgFeObjStructFree(trapAddrObj);
    }
    
    fprintf(snmpConf, "\n");
    fclose(snmpConf);
    return ZCFG_SUCCESS;
}

zcfgRet_t snmpStop()
{
    int pid;
    FILE *fd;

    fd = fopen(SNMPD_PID, "r");
    if (fd == NULL) {
        unlink(SNMPD_PID);
        return ZCFG_NOT_FOUND;
    }

    fscanf(fd, "%d", &pid);
    fclose(fd);

    /* remove pid file and kill it */
    unlink(SNMPD_PID);
    return (kill(pid, SIGKILL) == 0) ? ZCFG_SUCCESS : ZCFG_INTERNAL_ERROR;
}

zcfgRet_t snmpStart(unsigned char configModified, unsigned char isboot)
{
    struct stat st;
    char cmd[256];

    /* bit mesk:
     * MSB         [1][0]  LSB
     * [1]:delay runing
     * [0]:WarmStart
     * Ex:
     * -w 1 ---- WarmStart
     * -w 0 ---- ColdStart
     * -w 3 ---- WarmStart with delay
     * -w 2 ---- ColdStart with delay
     */
    if (stat(SNMPD_CONFIG, &st) == 0) {
        sprintf(cmd, "/sbin/snmpd -LS6d -c %s -p %s -w %u &", SNMPD_CONFIG, SNMPD_PID, ((isboot << 1) | !configModified));
        system(cmd);
        return ZCFG_SUCCESS;
    } else
        return ZCFG_INTERNAL_ERROR;
}

int snmp_zcfg_reload(void *newObj, void *curObj, unsigned int oid, objIndex_t *objIid)
{
    rdm_ZySnmp_t *snmpObj = (rdm_ZySnmp_t *)newObj;

    printf("%s : Enter\n", __FUNCTION__);
    
    if (newObj != NULL && curObj != NULL) {
        /* stop snmp first if running */
        if (snmpStop() == ZCFG_SUCCESS)
            printf("%s: Stop snmpd\n", __FUNCTION__);

        if (snmpObj->Enable) {
            if (snmpConfCreate(snmpObj) == ZCFG_SUCCESS) {
                if (snmpStart(1, 0) == ZCFG_SUCCESS)
                    printf("%s: Start snmpd\n", __FUNCTION__);
                else
                    printf("%s: Failed to start snmpd\n", __FUNCTION__);
            } else {
                printf("%s: Failed to create snmpd.conf\n", __FUNCTION__);
            }
        }
    }

    return 0;
}

int snmptrap_zcfg_reload(void *newObj, void *curObj, unsigned int oid, objIndex_t *objIid)
{
    rdm_ZySnmp_t *snmpObj = NULL;
    rdm_TrapAddr_t *trapObj;
    objIndex_t snmpIid;
    FILE *fp = NULL;
    short restart = 0;
    char trap[10] = {0}, match[300] = {0}, replace[300] = {0};

    printf("%s : Enter\n", __FUNCTION__);

    IID_INIT(snmpIid);
    if (zcfgFeObjStructGet(RDM_OID_ZY_SNMP, &snmpIid, (void **)&snmpObj) != ZCFG_SUCCESS) {
        printf("%s: Failed to get RDM_OID_ZY_SNMP\n", __FUNCTION__);
        return -1;
    }

    if (snmpObj->Enable) {
        if (newObj != NULL && curObj != NULL) {
            /* modify */
            if (memcmp(newObj, curObj, sizeof(rdm_TrapAddr_t)) == 0)
                goto skip;

            trapObj = newObj;
            sprintf(trap, "%s", (trapObj->TarpVer == 2) ? "trap2sink" : "trapsink");
            sprintf(replace, "%s %s %s %d", trap, trapObj->Host, snmpObj->TrapCommunity, trapObj->Port);

            trapObj = curObj;
            if (strcmp(trapObj->Host, "")) {
                sprintf(trap, "%s", (trapObj->TarpVer == 2) ? "trap2sink" : "trapsink");
                sprintf(match, "%s %s %s %d", trap, trapObj->Host, snmpObj->TrapCommunity, trapObj->Port);
                if (ReplaceFile(match, replace, SNMPD_CONFIG))
                    restart = 1;
            } else {
                if ((fp = fopen(SNMPD_CONFIG, "a+"))) {
                    fprintf(fp, "%s\n", replace);
                    fclose(fp);
                    restart = 1;
                }
            }
        } else if (newObj == NULL && curObj != NULL) {
            /* delete */
            trapObj = curObj;
            sprintf(trap, "%s", (trapObj->TarpVer == 2) ? "trap2sink" : "trapsink");
            sprintf(match, "%s %s %s %d", trap, trapObj->Host, snmpObj->TrapCommunity, trapObj->Port);
            replace[0] = '\0';
            if (ReplaceFile(match, replace, SNMPD_CONFIG))
                restart = 1;

        } else if (newObj != NULL && curObj == NULL) {
            /* add */
            trapObj = newObj;
            if (strcmp(trapObj->Host, "")) {
                sprintf(trap, "%s", (trapObj->TarpVer == 2) ? "trap2sink" : "trapsink");
                sprintf(replace, "%s %s %s %d", trap, trapObj->Host, snmpObj->TrapCommunity, trapObj->Port);
                
                if ((fp = fopen(SNMPD_CONFIG, "a+"))) {
                    fprintf(fp, "%s\n", replace);                                                                                                                fclose(fp);
                    restart = 1;
                }
            }
        }
    }

    if (restart) {
        printf("%s: Restart snmpd\n", __FUNCTION__);
        snmpStop();
        snmpStart(1, 0);
    }

skip:
    free(snmpObj);
    return 0;
}

