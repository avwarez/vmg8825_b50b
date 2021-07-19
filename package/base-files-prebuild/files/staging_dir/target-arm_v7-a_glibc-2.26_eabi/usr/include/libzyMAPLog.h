#ifndef _LIBZYMAPLOG_H
#define _LIBZYMAPLOG_H

#include <syslog.h>

#define LOG_SETTING_FILE	"/tmp/zyMAPLogSetting.txt"

#define LOG_OUTPUT_NONE		0
#define LOG_OUTPUT_STDOUT	(1 << 0)	//output to console
#define LOG_OUTPUT_LOCAL	(1 << 1)	//output to syslog local
#define LOG_OUTPUT_REMOTE	(1 << 2)	//output to syslog server

#define CAT_1905			(1 << 0)
#define	CAT_AP_CONFIG		(1 << 1)
#define CAT_STEER_LOGIC		(1 << 2)
#define CAT_ALL				(CAT_1905 | CAT_AP_CONFIG | CAT_STEER_LOGIC)

typedef unsigned char	UINT8;
typedef unsigned int	UINT32;

void zyMAP_log_setting();

void zyMAP_syslog(UINT8 category, UINT8 level, char *fmt, ...);

#define ZYLOG_1905(level, fmt, ...) zyMAP_syslog(CAT_1905, level, fmt "\n", ##__VA_ARGS__)
#define ZYLOG_APCFG(level, fmt, ...) zyMAP_syslog(CAT_AP_CONFIG, level, fmt "\n", ##__VA_ARGS__)
#define ZYLOG_SL(level, fmt, ...) zyMAP_syslog(CAT_STEER_LOGIC, level, fmt "\n", ##__VA_ARGS__)

#endif
