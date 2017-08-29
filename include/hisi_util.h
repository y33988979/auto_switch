#include "hi_type.h"
#include "ipanel_debug.h"

#ifndef     _HISI_UTIL_H
#define     _HISI_UTIL_H
extern INT32_T debug_print(MODULE_ID_E id, DEBUG_LEVEL_E  level, const char *function, int line, CONST CHAR_T *fmt, ...);

#define HISI_INFO(ID, FORMAT, ARGS...)   debug_print( (ID), DEBUG_LEVEL_INFO,__FUNCTION__, __LINE__, FORMAT, ##ARGS )
#define HISI_ERR(ID, FORMAT, ARGS...)   debug_print( (ID), DEBUG_LEVEL_ERROR,__FUNCTION__, __LINE__, FORMAT, ##ARGS )

#define HISI_WIN_1080_SCREEN_W    (1920)
#define HISI_WIN_1080_SCREEN_H    (1080)
#define HISI_WIN_720_SCREEN_W     (1280)
#define HISI_WIN_720_SCREEN_H     (720)
#define HISI_WIN_576_SCREEN_W     (720)
#define HISI_WIN_576_SCREEN_H     (576)
#define HISI_WIN_480_SCREEN_W     (720)
#define HISI_WIN_480_SCREEN_H     (480)

#define HISI_AVPLAY_INVALID_PID   (0x1fff)
#define HISI_INVALID_PTS          (-1)

/*-----------------------------------------------------------------
错误判断
-----------------------------------------------------------------*/
/* 如果func执行失败，只打印出错信息，不返回 */
#define DOFUNC(func, module)\
do{\
    HI_S32 ret = func;\
    if(ret != HI_SUCCESS)\
        HISI_ERR(module, "%s failed !!in %s at %d line ret = 0x%x\n""\033[0m", #func, __FUNCTION__, __LINE__, ret);\
}while(0)

/* 如果func执行失败，则直接返回 */
#define DOFUNC_RETURN(func, module)\
do{\
    HI_S32 ret = func;\
    if(ret != HI_SUCCESS)\
    { \
        HISI_ERR(module, "%s failed !!in %s at %d line ret = 0x%x\n", #func, __FUNCTION__, __LINE__, ret);\
        return ret; \
    } \
}while(0)

/* 如果func执行失败，则直接返回 */
#define DOFUNC_RETURN_ERR(func, err, module)\
do{\
    HI_S32 ret = func;\
    if(ret != HI_SUCCESS)\
    { \
        HISI_ERR(module, "%s failed !!in %s at %d line ret = 0x%x\n", #func, __FUNCTION__, __LINE__, ret);\
        return err; \
    } \
}while(0)

/* 如果func执行失败，则直接空返回 */
#define DOFUNC_RETURN_VOID(func, module)\
do{\
    HI_S32 ret = func;\
    if(ret != HI_SUCCESS)\
    { \
        HISI_ERR(module, "%s failed !!in %s at %d line ret = 0x%x\n", #func, __FUNCTION__, __LINE__, ret);\
        return ; \
    } \
}while(0)

/* 如果func执行失败，则goto到errhanle处 */
#define DOFUNC_GOTO(func, errhandle, module) \
    do{\
        s32Ret = func;\
        if (s32Ret != HI_SUCCESS )\
        {\
            HISI_ERR(module, "%s fail:0x%x, line:%d\n", #func, s32Ret, __LINE__);\
            goto errhandle;\
        } \
    }while(0)


/* 如果val不为真，则返回ret */
#define CHK_RETURN(val , ret, module )\
        do{\
            if( !(val)  )\
            { \
                HISI_ERR(module, "failed !!in %s at %d line ret = 0x%x\n",  __FUNCTION__, __LINE__, ret);\
                return ret; \
            } \
        }while(0)

/* 如果val不为真，则返回 */
#define CHK_RETURN_VOID(val, module)\
        do{\
            if( !(val)  )\
            { \
                HISI_ERR(module, "failed !!in %s at %d line\n",  __FUNCTION__, __LINE__);\
                return; \
            } \
        }while(0)

/* 如果val不为真，则goto到errhanle处 */
#define CHK_GOTO(val,errhandle, module)\
        do{\
            if( !(val)  )\
            { \
                HISI_ERR(module, "failed !!in %s at %d line\n",  __FUNCTION__, __LINE__);\
                goto errhandle; \
            } \
        }while(0)


#define EISPUTTUNERMESSAGE(a, b) send_message_to_tail( EIS_EVENT_TYPE_DVB, a, b)

#define     WAIT_USER_KEY(module)     { \
                HISI_INFO(module, "Press any key to continue ...");  \
                getchar();  \
            }

#define     PID_DUMP()      \
    {                       \
        pid_t ident;        \
        ident=getpid();     \
        HISI_INFO(MODULE_PRINT_OS, "[Thread Debug][%s] PID:%d, TID:%d\n",__FUNCTION__,ident, gettid());  \
    }                       \
 

#define     HISI_LOCK       pthread_mutex_lock
#define     HISI_UNLOCK       pthread_mutex_unlock


HI_S32  hisi_get_avplay_handle( HI_HANDLE *phHandle );
HI_BOOL  hisi_get_standby_status(HI_VOID);
HI_S32  hisi_set_standby_status(HI_BOOL bStatus);

#endif

