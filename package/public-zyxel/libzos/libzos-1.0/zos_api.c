/*!
 *  @file zos_api.c
 *      OS porting layer
 *
 *  @author     CP Wang
 *  @date       2017-12-15 19:26:21
 *  @copyright  Copyright 2017 Zyxel Communications Corp. All Rights Reserved.
 */
//==============================================================================
#include <stdio.h>
#include <stdlib.h>     // system()
#include <stdarg.h>     // va_list()
#include <sys/types.h>
#include <sys/wait.h>   // waitpid()
#include <unistd.h>     // fork(), execvp(), _exit()
#include <string.h>     // strchr()
#include <errno.h>

#include "zlog_api.h"

//==============================================================================
#define ZOS_CMD_MAX_LEN     1024

//==============================================================================
/*
    copy from
        build_dir\target-arm_v7-a_uClibc-0.9.32_eabi\zcfg_be-2.0\libzcfg_be\libzcfg_be_common\zcfg_be_common.c
*/
/*
 * zcfg_system():
 * Used to prevent command injection
 * usage likes system(), but does not support sepcial characters except & "
 * & must be seperate and can not be appended to the parameters
 * e.g.
 * Correct case : zcfg_system("ping 8.8.8.8 &") -> excute "ping 8.8.8.8" in background
 * Wrong case : zcfg_system("ping 8.8.8.8&")  -> 8.8.8.8& will be treate as a argement
 *
 * zcfg_system("ping \"8.8.8.8 4.4.4.4\"")  -> 8.8.8.8 4.4.4.4 will be treate as a argement since they are enclosed in double quotation marks
 * zcfg_system("ping 8.8.8.8 > /tmp/result)  -> not support redirect (>)
 *
 * plan to support redirect (>) in future.
*/
static int _zcfg_system(const char *cmd)
{
	pid_t pid, pid2;
	char *argv[128] = {NULL};
	char buf[ZOS_CMD_MAX_LEN + 1] = {0};
	int i = 0, j = 0;
	char *p = NULL;
	int status = 0;
	int background = 0;

	if (*cmd == '\0')
	{
		return -1;
	}

	strncpy(buf, cmd, ZOS_CMD_MAX_LEN);

	while (i<ZOS_CMD_MAX_LEN && cmd[i]!='\0')
	{
		if(buf[i] != ' '){
			if(buf[i] == '\"'){
				argv[j++] = &buf[++i];
				p = strchr(&buf[i], '\"');
				if(p != NULL){
					i = p - buf;
					buf[i] = '\0';
				}
				else
					return -1;

			}
			else{
				argv[j++] = &buf[i];
				p = strchr(&buf[i], ' ');
				if(p != NULL){
					i = p - buf;
					buf[i] = '\0';
				}
				else
					break;
			}
		}
		i++;
	}

	if(*argv[j-1] == '&'){
		background = 1;
		argv[j-1] = NULL;
	}

	if((pid = fork()) < 0){
		status = -1;
	}
	else if(pid == 0){
		if(!background){
			execvp(argv[0], argv);
			_exit(127);
		}
		else{
			if((pid2 = fork()) < 0){
				_exit(-1);
			}
			else if(pid2 == 0){
				execvp(argv[0], argv);
				_exit(127);
			}
			else{
				_exit(0);
			}
		}
	}
	else if(pid >0){
		if(waitpid(pid, &status, 0)<0){
			if (errno != EINTR) {
				status = -1;
			}
		}
	}

	return status;

} // _zcfg_system

//==============================================================================
/*!
 *  system command
 *
 *  @param [in] b_linux     if true then use linux system() else use _zcfg_system()
 *  @param [in] format      string format of command
 *  @param [in] ...         arguments required by the format
 *
 *  @return true  - command executed successful
 *          false - fail to execute command
 */
bool zos_system(
    bool        b_linux,
    const char  *format,
    ...
)
{
    char        cmd[ZOS_CMD_MAX_LEN + 1] = {0};
    va_list     ap;
    int         r;

    memset(cmd, 0, sizeof(cmd));

    if (format == NULL)
    {
        ZLOG_ERROR("format == NULL\n");
        return false;
    }

    va_start(ap, format);

    r = vsnprintf(cmd, ZOS_CMD_MAX_LEN, format, ap);

    va_end(ap);

    if (r < 0 || r > ZOS_CMD_MAX_LEN)
    {
        ZLOG_ERROR("fail to vsnprintf()");
        return false;
    }

    if (b_linux)
    {
        if (system(cmd) == -1)
        {
            ZLOG_ERROR("fail to system(%s)", cmd);
            return false;
        }
    }
    else
    {
        if (_zcfg_system(cmd) == -1)
        {
            ZLOG_ERROR("fail to _zcfg_system(%s)", cmd);
            return false;
        }
    }

    return true;

} // zos_system
