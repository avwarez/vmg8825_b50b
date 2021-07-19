/****************************************************************************
 *
 * Copyright (C) 2013 by ZyXEL
 *
 ****************************************************************************/

/**
 * @file   zyMAP1905_service.h
 * @date   Dec 2018
 * @brief  zy1905 command handler
 */

#ifndef __ZY_VEND_SERVICE_HANDLER_H__
#define __ZY_VEND_SERVICE_HANDLER_H__

#include "zyMAP1905_global.h"

#define PATH_RETURNVALUE 		"/tmp/1905ReturnValue"
#define PATH_RETURNVALUE_COUNT	"/tmp/zy1905/zy1905App_Command_count"
#define MAX_INTF_NUM	30

#define ZY1905APP_CMD_BASE				100
#define ZY1905_SET_DEBUG_LEVEL			ZY1905APP_CMD_BASE + 1
#define ZY1905_NBR_REBOOT_QUERY			ZY1905APP_CMD_BASE + 2
#define ZY1905_CTRL_NBR_INTF_PWR_QUERY	ZY1905APP_CMD_BASE + 3
#define ZY1905_FW_CTRL_QUERY			ZY1905APP_CMD_BASE + 9
#define ZY1905_NBR_RESET_DEFAULT_QUERY	ZY1905APP_CMD_BASE + 10
#define ZY1905_SET_FW_RESULT			ZY1905APP_CMD_BASE + 11
#define ZY1905_SEND_COMMAND_QUERY		ZY1905APP_CMD_BASE + 100
#define ZY1905_SET_SYSLOG_DEBUG			ZY1905APP_CMD_BASE + 101

/* FW result */
typedef struct {
	int 	result;		/**< result value */
	UINT8	retCode;	/**< Return code */
} FWresultReqData;

#if 0
typedef struct {
	int	level;
} DebugLEVELReq;
#endif

typedef struct {
	int syslog_output;	/* bit 0:console; bit 1:local; bit 2:remote */
	int syslog_cat;	/* bit 0:1905; bit 1:AP-config; bit 2:Steering Logic */
	int syslog_level; /* syslog level */
} DebugSyslogReqData;

unsigned char* string2MacAddr(const char *string, unsigned char *macAddr);

void zyMAP1905_VendSpecCmd_handle(void *cmdMsg, int cmdType);

void output_ReturnValue(UINT8 ReturnValue);

#endif