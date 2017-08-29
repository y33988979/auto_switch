/*****************************************************************************/

/*                Copyright 2005 - 2005, Huawei Tech. Co., Ltd.              */
/*                           ALL RIGHTS RESERVED                             */
/*                                                                           */
/* FileName: hi_peffect.h                                                    */
/* Version: 01a                                                              */
/*                                                                           */
/* History:                                                                  */
/* 1. 01a,2008-12-27,z37062 Create this file.                                */
/*****************************************************************************/
#ifndef __HI_EFFECT_H__
#define __HI_EFFECT_H__

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#include <hi_type.h>
#include <hi_go.h>


/** HiEffect 项目错误ID */
#define HIEFFECT_ERR_APPID (0x80000000L + 0x40000000L)
/** HiEffect 模块ID */
#define HIEFFECT_ERR_MODUID 0x00000000
typedef enum hiEFFECTLOG_ERRLEVEL_E
{
    HIEFFECT_LOG_LEVEL_DEBUG = 0,  /* debug-level                                  */
    HIEFFECT_LOG_LEVEL_INFO,       /* informational                                */
    HIEFFECT_LOG_LEVEL_NOTICE,     /* normal but significant condition             */
    HIEFFECT_LOG_LEVEL_WARNING,    /* warning conditions                           */
    HIEFFECT_LOG_LEVEL_ERROR,      /* error conditions                             */
    HIEFFECT_LOG_LEVEL_CRIT,       /* critical conditions                          */
    HIEFFECT_LOG_LEVEL_ALERT,      /* action must be taken immediately             */
    HIEFFECT_LOG_LEVEL_FATAL,      /* just for compatibility with previous version */
    HIEFFECT_LOG_LEVEL_BUTT
} HIEFFECT_LOG_ERRLEVEL_E;

/** HiEffect 错误码定义宏 */
#define HIEFFECT_DEF_ERR(module, errid) \
    ((HI_S32)((HIEFFECT_ERR_APPID) | ((module) << 16) | ((HIEFFECT_LOG_LEVEL_ERROR) << 13) | (errid)))


enum HIEFFECT_ErrorCode_E
{
    ERR_HIEFFECT_CODE_UNDEF,               /*脦麓露篓脪氓脙眉脕卯脗毛*/
    ERR_HIEFFECT_PTR_NULL,                 /*脰赂脮毛虏脦脢媒脦陋驴脮*/
    ERR_HIEFFECT_NO_OPEN,                  /*脡猫卤赂脙禄脫脨麓貌驴陋*/
    ERR_HIEFFECT_OPENED,                   /*脡猫卤赂脪脩戮颅麓貌驴陋*/
    ERR_HIEFFECT_CLOSED,                   /*脡猫卤赂脪脩戮颅鹿脴卤脮*/

    /* New */
    ERR_HIEFFECT_INVALID_DEVICE,           /* invalid device */
    ERR_HIEFFECT_INVALID_HANDLE,
    ERR_HIEFFECT_INVALID_PARAMETER,        /* invalid parameter */
    ERR_HIEFFECT_INVALID_OPERATION,
    ERR_HIEFFECT_ADDR_FAULT,               /* address fault */
    ERR_HIEFFECT_NO_MEM                    /* mem alloc fail */
};

#define HI_ERR_HIEFFECT_CODE_UNDEF\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_CODE_UNDEF)

#define HI_ERR_HIEFFECT_PTR_NULL\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_PTR_NULL)

#define HI_ERR_HIEFFECT_OPENED\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_OPENED)

#define HI_ERR_HIEFFECT_CLOSED\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_CLOSED)

#define HI_ERR_HIEFFECT_NO_OPEN\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_NO_OPEN)


#define HI_ERR_HIEFFECT_INVALID_DEVICE\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_INVALID_DEVICE)

#define HI_ERR_HIEFFECT_INVALID_HANDLE\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_INVALID_HANDLE)

#define HI_ERR_HIEFFECT_INVALID_PARAMETER\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_INVALID_PARAMETER)

#define HI_ERR_HIEFFECT_INVALID_OPERATION\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_INVALID_OPERATION)

#define HI_ERR_HIEFFECT_ADDR_FAULT\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_ADDR_FAULT)

#define HI_ERR_HIEFFECT_NO_MEM\
    HIEFFECT_DEF_ERR(HIEFFECT_ERR_MODUID, ERR_HIEFFECT_NO_MEM)


/*屏幕刷新回调函数*/
typedef HI_S32 (*pRefresh_Callback)(HI_VOID);
typedef enum hiEFFECT_MODE_E
{
    HI_EFFECT_NONE = 0, 				/*拷贝显示*/
    HI_EFFECT_TURNPAGE, 				/*翻页*/
    HI_EFFECT_ROLLPAGE, 				/*卷轴*/
    HI_EFFECT_VERTICALSHUTTER,		/* 垂直百叶窗*/
    HI_EFFECT_HORIZONTALSHUTTER,		/* 水平百叶窗*/
    HI_EFFECT_LEFTIN,					/* 从左抽出*/
    HI_EFFECT_TOPIN, 					/* 从上抽出*/
    HI_EFFECT_TRANSIN, 				/* 渐进渐出*/
    HI_EFFECT_ROTATE,  				/*螺旋*/
    HI_EFFECT_CENTEROUT,  				/*中央渐出*/
    HI_EFFECT_CENTERIN, 				/*中央渐入*/
} EFFECT_MODE_E;

typedef enum hiEFFECT_SPEED
{
    HI_EFFECT_SPEED_FAST   = 1,
    HI_EFFECT_SPEED_NORMAL = 2,
    HI_EFFECT_SPEED_SLOW = 4,
} EFFECT_SPEED;

/*特效初始化函数,
注册屏幕刷新回调函数并设置显示模式
bLetfbox 为HI_TRUE, 表示图像比例与屏幕比例不一致时添加黑边
bLetfbox 为HI_FALSE, 表示图像缩放成全屏,如果图形比例与屏幕比例不一致
会导致变形
注:无论那种方式,图像都全屏显示
 */
extern HI_S32  HI_Effect_Init(pRefresh_Callback pfCallBack, HI_BOOL bLetfbox);
extern HI_S32  HI_Effect_Deinit(HI_VOID);

/*特效播放函数, 该函数为阻塞函数,特效完成才退出
所有surface的像素格式必须保持一致
目前支持的格式:
    HIGO_PF_4444,
    HIGO_PF_0444,
    HIGO_PF_1555,
    HIGO_PF_0555,
    HIGO_PF_565,
 */
extern HI_S32  HI_Effect_Play(HI_HANDLE hNewSurface, HI_HANDLE hScreenSurface, EFFECT_MODE_E mode);

/**
   设置特效句柄。
*/
extern HI_S32 HI_Effect_SetLayer(HI_HANDLE Layer);

/*特效播放中止,可以提高按键响应速度*/
extern HI_S32  HI_Effect_Stop(HI_VOID);

/*特效播放速度*/
extern HI_S32  HI_Effect_SetSpeed(EFFECT_SPEED eSpeed);
#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HI_PEFFECT_H__ */
