#ifndef _HLP_DEBUG_H_
#define _HLP_DEBUG_H_

#include <common.h>
#include <config.h>
#include <hlp_core.h>
#include <errno.h>


typedef enum hlp_debug_module
{
    HLP_MOD_ALL = 0x01,
    HLP_MOD_COMMON,
    HLP_MOD_CONFIG,
    HLP_MOD_GPIO,
    HLP_MOD_SERIAL,
    HLP_MOD_LOGFILE,
    HLP_MOD_SWITCH,
    HLP_MOD_PANEL,
    HLP_MOD_UDISK,
    HLP_MOD_CNT
}hlp_module_e;


typedef enum hlp_debug_lever
{
    HLP_DBG_NONE    = 0x0,
    HLP_DBG_ERROR   = 0x1,
    HLP_DBG_WARN    = 0x2,
    HLP_DBG_INFO    = 0x3,
    HLP_DBG_DEBUG   = 0x4,
    HLP_DBG_VERBOSE = 0x5,
    HLP_DBG_ALL

}hlp_dbg_lever_e;

#define tt printf("[ychen]:%s: line:%d  __test__!\n", __func__,__LINE__)

#define hlp_error_en(en, msg) \
    do { errno = en; perror(msg); return (en); } while (0)

#define hlp_error(ret, msg) \
    do { perror(msg); return (ret); } while (0)

S32 hlp_debug(U32 module_id, U32 lever, const char *fmt, ...);
#define HLP_PRINT(mod, msg...)   hlp_debug(mod, HLP_DBG_ALL, msg)
#define HLP_PRINT2(mod, msg...)   hlp_debug(mod, HLP_DBG_DEBUG, msg)
#define HLP_PRINT3(mod, msg,...)   hlp_debug(mod, HLP_DBG_ALL, msg"\n", ## __VA_ARGS__)

#define HLP_ERROR(mod, msg,...)    hlp_debug(mod, HLP_DBG_ERROR, "[ERROR]%s:%d: " msg "\n",__func__,__LINE__, ## __VA_ARGS__)
#define HLP_WARN(mod, msg,...)   hlp_debug(mod, HLP_DBG_WARN, "[WARN]%s:%d: " msg "\n",__func__,__LINE__, ## __VA_ARGS__)
#define HLP_INFO(mod, msg,...)    hlp_debug(mod, HLP_DBG_INFO, "[INFO]%s:%d: " msg "\n",__func__,__LINE__, ## __VA_ARGS__)
#define HLP_DEBUG(mod, msg,...)   hlp_debug(mod, HLP_DBG_DEBUG, "[DEBUG]%s:%d: " msg "\n",__func__,__LINE__, ## __VA_ARGS__)

//#define Dbc_Print_Err(format,...)  Dbc_Print(DBC_PRINT,"[DBC ERROR:][%d][%s][%d][%s]:" format "\n",(int)DRV_OS_TimeNow_MS(),__FILE__,__LINE__,__func__,## __VA_ARGS__)
//#define Dbc_Print_level(level,format,...)  Dbc_Print(level,"[DBC INFO:][%d][%s][%d][%s]:" format "\n",(int)DRV_OS_TimeNow_MS(),__FILE__,__LINE__,__func__,## __VA_ARGS__)

S32 hlp_debug_init();
S32 hlp_debug_setlever(U32 module_id, U32 lever);

#endif /* _HLP_DEBUG_H_ */

