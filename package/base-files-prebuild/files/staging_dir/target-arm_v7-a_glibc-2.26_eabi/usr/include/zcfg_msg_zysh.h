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
#ifndef _ZCFG_MSG_ZYSH_H
#define _ZCFG_MSG_ZYSH_H

/* Support CMD */
#define ZCFG_ZYSH_CMD_FLASH_ERASE 	1
#define ZCFG_ZYSH_CMD_SET_ATBT 		2
#define ZCFG_ZYSH_CMD_GET_ATBT 		3
#define ZCFG_ZYSH_CMD_GET_CHKSUM	4
#define ZCFG_ZYSH_CMD_MOUNT_ALL		5
#define ZCFG_ZYSH_CMD_ATCR			6
#define ZCFG_ZYSH_CMD_HWCLOCK		7
#define ZCFG_ZYSH_CMD_FETCH_SERVER	8
#define ZCFG_ZYSH_CMD_SET_DATE		9
#define ZCFG_ZYSH_CMD_HOST			10
#define ZCFG_ZYSH_CMD_GEN_CA		11
#define ZCFG_ZYSH_CMD_SHOW_CA		12
#define ZCFG_ZYSH_CMD_REBOOT		13
#define ZCFG_ZYSH_CMD_SHUTDOWN		14
#define ZCFG_ZYSH_CMD_REG_SVR		15
#define ZCFG_ZYSH_CMD_WATCHDOG		16
#define ZCFG_ZYSH_CMD_TCPDUMP		17
#define ZCFG_ZYSH_CMD_CONNTRACT		18
#define ZCFG_ZYSH_CMD_DMESG 		19
#define ZCFG_ZYSH_CMD_IPTABLES		20
#define ZCFG_ZYSH_CMD_IPROUTE 		21
#define ZCFG_ZYSH_CMD_IPRULE 		22
#define ZCFG_ZYSH_CMD_KILL_PROCESS	23
#define ZCFG_ZYSH_CMD_GDB       	24
#define ZCFG_ZYSH_CMD_SWAP_IMAGE   	25
#define ZCFG_ZYSH_CMD_GET_MODULE_DEBUG_LEVEL	26
#define ZCFG_ZYSH_CMD_SET_MODULE_DEBUG_LEVEL	27
#define ZCFG_ZYSH_CMD_SET_OUTPUT_REDIRECT		28
#define ZCFG_ZYSH_CMD_GET_OUTPUT_REDIRECT	29
#define ZCFG_ZYSH_CMD_REMOVE_OUTPUT_REDIRECT	30

#define PSM_ATBT_TOKEN_FILE     "/var/zyxel/psm_atbt_token"
#define MAX_ZCFG_ZYSH_BUF_SIZE 256
typedef struct zcfgZysh_s {
	uint32_t cmd;
	uint32_t chkSum;
	int value;
	char buf[MAX_ZCFG_ZYSH_BUF_SIZE];
}zcfgZysh_t;

#endif
