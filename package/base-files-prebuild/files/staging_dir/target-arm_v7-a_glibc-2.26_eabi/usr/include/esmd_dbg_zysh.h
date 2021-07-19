#ifndef _ESMD_MODULE_LOG_H_
#define _ESMD_MODULE_LOG_H_

#ifdef CONFIG_ZCFG_MODULE_DEBUG
#include "be_module_debug.h"
#undef zcfgLog
#undef zcfgLogPrefix

#define zcfgLogPrefix(logLev, Prefix ,format, args...) \
{\
    _zcfgLogPrefix(logLev,Prefix,format,##args);\
    if ( debug_esmd > logLev ) \
        ZCFG_PRINT(format, ##args); \
}

#define zcfgLog(logLev, format, args...) \
{\
    _zcfgLog(logLev,format,##args);\
    if ( debug_esmd > logLev ) \
        ZCFG_PRINT(format, ##args); \
}

#undef printf
#define printf(format, args...) \
{\
    if ( debug_esmd > zcfg_module_dbg_level ) \
        ZCFG_PRINT(format, ##args); \
}
#endif

#else
#error "Duplicate include"
#endif
