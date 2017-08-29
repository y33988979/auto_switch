/**
 \file
 \brief Subtitle output Module
 \author Shenzhen Hisilicon Co., Ltd.
 \date 2008-2018
 \version 1.0
 \author 
 \date 2010-03-10
 */

#ifndef __HI_UNF_SO_H__
#define __HI_UNF_SO_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */
/*************************** Structure Definition ****************************/
/** \addtogroup     SO */
/** @{ */  /** <!—[SO]*/  


#define HI_UNF_SO_PALETTE_ENTRY (256)    /**< Number of palette */ /**< CNComment: 调色板颜色个数 */
#define HI_UNF_SO_NO_PTS        (-1)
#define HI_UNF_SO_MAX_NODE_NUM  (20)
#define HI_UNF_SO_MAX_BUFFER_SIZE (0x200000)  /* 2M */


/** 字幕类型 */
typedef enum hiUNF_SO_SUBTITLE_TYPE_E
{
    HI_UNF_SUBTITLE_BITMAP = 0x0,  /**< Bmp subtitle *//**< CNComment:图像字幕 */
    HI_UNF_SUBTITLE_TEXT,          /**< Text subtitle *//**< CNComment:string字幕 */
    HI_UNF_SUBTITLE_ASS,           /**< Ass/ssa sbutitle *//**< CNComment:ass字幕 */
    HI_UNF_SUBTITLE_BUTT
} HI_UNF_SO_SUBTITLE_TYPE_E;

/** Message type of subtitle */
/** CNComment:显示消息，对于teltext，含显示和擦除两个消息 */
typedef enum hiUNF_SO_DISP_MSG_TYPE_E
{
    HI_UNF_SO_DISP_MSG_NORM  = 0x0,     /**< Draw the subtitle *//**< CNComment:正常显示数据 */
    HI_UNF_SO_DISP_MSG_ERASE,           /**< Clear the subtitle *//**< CNComment:擦除 */
    HI_UNF_SO_DISP_MSG_END              /**< Message of drawing a page *//**< CNComment:整页显示结束 */
} HI_UNF_SO_DISP_MSG_TYPE_E;

/** The parameter of clear region */
/** CNComment:擦除参数 */
typedef struct hiUNF_SO_CLEAR_PARAM_S
{
    HI_U32 x, y, w, h;     /**< Postion of clearing *//**< CNComment:擦除位置和高宽信息 */
} HI_UNF_SO_CLEAR_PARAM_S;

/** Color components  */
/** CNComment:颜色结构 */
typedef struct hiUNF_SO_COLOR_S
{
    HI_U8 u8Red;      /**< Red component *//**< CNComment:R分量颜色值 */
    HI_U8 u8Green;    /**< Green component *//**< CNComment:G分量颜色值 */
    HI_U8 u8Blue;     /**< Blue component *//**< CNComment:B分量颜色值 */
    HI_U8 u8Alpha;    /**< Alpha component *//**< CNComment:透明度，值为0为透明，0xFF为不透明 */
} HI_UNF_SO_COLOR_S;

/** Information of bitmap subtitle */
/** CNComment:图像字幕信息 */
typedef struct hiUNF_SO_GFX_S
{
    HI_S64 s64Pts;         /**< Start a display time, unit is Millisecond *//**< CNComment:显示时间戳，单位ms */
    HI_U32 u32Duration;    /**< Duration of displaying, unit is Millisecond *//**< CNComment:显示时长，单位ms */
    HI_U32 u32Len;         /**< Bytes of subtitle data *//**< CNComment:数据长度，单位字节 */
    HI_U8  *pu8PixData;    /**< Data of subtitle *//**< CNComment: 图像数据 */

    HI_UNF_SO_DISP_MSG_TYPE_E enMsgType;                   /**< Type of display message *//**< CNComment:显示消息类型 */  
    HI_UNF_SO_COLOR_S stPalette[HI_UNF_SO_PALETTE_ENTRY];  /**< Palette *//**< CNComment:调色板，ARGB8888 */
    HI_S32 s32BitWidth;    /**< Bits of Pix *//**< CNComment:象素位宽 , 可以为 2,4,8位*/
    HI_U32 x, y, w, h;     /**< Position of display subtitle *//**< CNComment:显示位置和高宽信息 */
} HI_UNF_SO_GFX_S;

/** Infomation of text subtitle */
/** CNComment:文本字幕信息 */
typedef struct hiUNF_SO_TEXT_S
{
    HI_S64 s64Pts;              /**< Start a display time, unit is Millisecond *//**< CNComment:显示时间戳，单位ms */
    HI_U32 u32Duration;         /**< Duration of displaying, unit is Millisecond *//**< CNComment:显示时长，单位ms */
    HI_U32 u32Len;              /**< Bytes of subtitle data *//**< CNComment:字幕数据长度，单位字节 */
    HI_U8 *pu8Data;             /**< Data of subtitle *//**< CNComment:字幕数据 */

    HI_U32 x, y, w, h;          /**< Position of display subtitle *//**< CNComment:显示位置和高宽信息 */
} HI_UNF_SO_TEXT_S;

/** Infomation of ass/ssa subtitle */
/** CNComment:ass字幕信息 */
typedef struct hiUNF_SO_ASS_S
{
    HI_S64 s64Pts;                /**< Start a display time, unit is Millisecond *//**< CNComment:显示时间戳，单位ms */
    HI_U32 u32Duration;           /**< Duration of displaying, unit is Millisecond *//**< CNComment:显示时长，单位ms */
    HI_U32 u32FrameLen;           /**< Bytes of subtitle data *//**< CNComment:帧长度，单位字节 */
    HI_U8  *pu8EventData;         /**< Data of subtitle *//**< CNComment:帧数据 */
    HI_U32 u32ExtradataSize;      /**< Length of extra data *//**< CNComment:扩展数据长度，单位字节 */
    HI_U8  *pu8Extradata;         /**< Extra data *//**< CNComment:扩展数据 */
} HI_UNF_SO_ASS_S;

/** Infomation of subtitle */
/** CNComment:字幕信息 */
typedef struct hiUNF_SO_SUBTITLE_INFO_S
{
    HI_UNF_SO_SUBTITLE_TYPE_E eType; /**< type *//**< CNComment:字幕类型 */

    union
    {
        HI_UNF_SO_GFX_S  stGfx;      /**< Gfx subtitle *//**< CNComment:图形字幕 */
        HI_UNF_SO_TEXT_S stText;     /**< Text subtitle *//**< CNComment:文本字幕 */
        HI_UNF_SO_ASS_S  stAss;      /**< Ass subtitle *//**< CNComment:ASS字幕 */
    } unSubtitleParam;
} HI_UNF_SO_SUBTITLE_INFO_S;

/** 
\brief Call back funtion of getting current play time. 
CNComment:获取当前播放帧的时间戳，如果当前时间无效，ps64CurrentPts赋值为HI_UNF_SO_NO_PTS
\attention \n
None
\param[in] u32UserData Userdata.CNComment:注册传入的用户数据
\param[out] ps64CurrentPts Current play time. CNComment:当前播放帧时间戳，单位ms 

\retval ::HI_SUCCESS

\see \n
None
*/
typedef HI_S32 (*HI_UNF_SO_GETPTS_FN)(HI_U32 u32UserData, HI_S64 *ps64CurrentPts);

/** 
\brief Callback funtion of drawing the subtitle. CNComment:字幕画图回调函数
\attention \n
None
\param[in] u32UserData Userdata. CNComment:注册传入的用户数据
\param[in] pstInfo Information of subtitle. CNComment:字幕信息
\param[in] pArg User data. CNComment:扩展数据

\retval ::HI_SUCCESS

\see \n
None
*/
typedef HI_S32 (*HI_UNF_SO_ONDRAW_FN)(HI_U32 u32UserData, const HI_UNF_SO_SUBTITLE_INFO_S *pstInfo, HI_VOID *pArg);

/** 
\brief Call back funtion of clearing the subtitle. CNComment:字幕显示到时清除函数
\attention \n
None
\param[in] u32UserData User data. CNComment:注册传入的用户数据
\param[out] pArg Parameter of clearing the subtitle, Type is HI_UNF_SO_CLEAR_PARAM_S. CNComment:擦除参数，指向HI_UNF_SO_CLEAR_PARAM_S结构

\retval ::HI_SUCCESS

\see \n
None
*/
typedef HI_S32 (*HI_UNF_SO_ONCLEAR_FN)(HI_U32 u32UserData, HI_VOID *pArg);

/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      SO */
/** @{ */  /** <!—[SO] */

/**
\brief  Init SO module. CNComment:subtitle output 模块初始化
\attention \n
None
\param None

\retval ::HI_SUCCESS Init success.
\retval ::HI_FAILURE Operation fail.

\see \n
None
*/
HI_S32 HI_UNF_SO_Init(HI_VOID);

/**
\brief  Deinit SO module. CNComment:subtitle output 模块去初始化
\attention \n
None
\param None

\retval ::HI_SUCCESS  Deinit success.
\retval ::HI_FAILURE Operation fail.

\see \n
None
*/
HI_S32 HI_UNF_SO_DeInit(HI_VOID);

/**
\brief  Creates an SO instance. CNComment:创建一个so实例
\attention \n
None
\param[out] phdl Handle of SO instance. CNComment:播放器实例

\retval ::HI_SUCCESS  Create success. CNComment:创建成功，句柄有效
\retval ::HI_FAILURE  Operation fail. CNComment:创建失败

\see \n
None
*/
HI_S32 HI_UNF_SO_Create(HI_HANDLE *phdl);

/**
\brief  Destroy an SO instance. CNComment:销毁一个so实例
\attention \n
None
\param[in] handle Handle of SO instance. CNComment:so实例句柄

\retval ::HI_SUCCESS  Destroy success. CNComment:销毁成功
\retval ::HI_FAILURE  Operation fail. CNComment:销毁失败，参数非法

\see \n
None
*/
HI_S32 HI_UNF_SO_Destroy(HI_HANDLE handle);

/**
\brief  Setting offset time of the subtitle. CNComment:设置字幕时间偏移
\attention \n
None
\param[in] handle Handle of SO instance. CNComment:so实例句柄
\param[in] s64OffsetMs Offset of subtitle, unit is Millisecondes.CNComment:字幕显示时间偏移值，单位ms

\retval ::HI_SUCCESS  Operation success.
\retval ::HI_FAILURE  Operation fail.

\see \n
None
*/
HI_S32 HI_UNF_SO_SetOffset(HI_HANDLE handle, HI_S64 s64OffsetMs);

/**
\brief  Register the callback function of getting current play time. CNComment:注册时间戳获取回调函数，so通过获取当前播放时间戳同步字幕
\attention \n
None
\param[in] handle Handle of SO instance.CNComment:so实例句柄
\param[in] pstCallback Callback function. CNComment:回调函数参数
\param[in] u32UserData User data. CNComment:用户数据

\retval ::HI_SUCCESS  Register success. CNComment:注册成功
\retval ::HI_FAILURE  Parameter invalid. CNComment:注册失败

\see \n
None
*/
HI_S32 HI_UNF_SO_RegGetPtsCb(HI_HANDLE handle, HI_UNF_SO_GETPTS_FN pstCallback, HI_U32 u32UserData);

/**
\brief  Register the callback function of drawing subtitle.
CNComment:注册字幕绘制清除回调函数，如果设置了该函数，则so使用该函数实现字幕输出，字幕显示时长到达后，so调用清除函数通知清除
\attention \n
None
\param[in] handle Handle of SO instance. CNComment:so实例句柄
\param[in] pfnOnDraw Callback function of drawing subtitle. CNComment:绘制函数
\param[in] pfnOnClear Callback function of clearing subtitle. CNComment:清除函数
\param[in] u32UserData User data. CNComment:用户数据

\retval ::HI_SUCCESS  Register success. CNComment:注册成功
\retval ::HI_FAILURE Parameter invalid. CNComment:注册失败

\see \n
None
*/
HI_S32 HI_UNF_SO_RegOnDrawCb(HI_HANDLE handle, HI_UNF_SO_ONDRAW_FN pfnOnDraw,
                                          HI_UNF_SO_ONCLEAR_FN pfnOnClear, HI_U32 u32UserData);

/**
\brief  Set the surface of drawing subtitle, if you do not set the ondraw callback function, SO painting subtitles with the surface.
CNComment:设置字幕绘制画布句柄，如果没有设置ondraw回调函数，则so使用设置的画布句柄输出字幕
\attention \n
This feature is not implemented. CNComment:该功能未实现
\param[in] handle Handle of SO instance.CNComment:so实例句柄
\param[in] hSurfaceHandle Handle of surface. CNComment:画布句柄

\retval ::HI_SUCCESS Success of setting surface. CNComment:设置成功
\retval ::HI_FAILURE  Operation invalid. CNComment:设置失败

\see \n
None
*/
HI_S32 HI_UNF_SO_SetDrawSurface(HI_HANDLE handle, HI_HANDLE hSurfaceHandle);

/**
\brief  Set the font of drawing subtitle.
CNComment:设置字幕显示字体，该设置仅对设置画布输出字幕的方式起作用
\attention \n
This feature is not implemented. CNComment:该功能未实现
\param[in] handle Handle of SO instance.CNComment:so实例句柄
\param[in] hFont Handle of font instance.CNComment:创建的字体句柄

\retval ::HI_SUCCESS  Success.CNComment:设置成功
\retval ::HI_FAILURE  Operation invalid. CNComment:设置失败

\see \n
None
*/
HI_S32 HI_UNF_SO_SetFont(HI_HANDLE handle, HI_HANDLE hFont);

/**
\brief Set the color of drawing text subtitle.
CNComment:设置字幕显示颜色，该设置仅对设置画布输出字幕的方式起作用
\attention \n
This feature is not implemented. CNCommnet:该功能未实现
\param[in] handle Handle of SO instance. CNComment:so实例句柄
\param[in] u32Color Value of the color. CNComment:颜色值

\retval ::HI_SUCCESS  Success. CNComment:设置成功
\retval ::HI_FAILURE  Operation invalid. CNComment:设置失败

\see \n
None
*/
HI_S32 HI_UNF_SO_SetColor(HI_HANDLE handle, HI_U32 u32Color);

/**
\brief Set the position of display subtitle.
CNComment:设置字幕显示坐标，该设置仅对设置画布输出字幕的方式起作用
\attention \n
This feature is not implemented. 该功能未实现
\param[in] handle Handle of SO instance. CNComment:so实例句柄
\param[in] u32x Value of x coordinate.CNComment:x坐标
\param[in] u32y Value of y coordinate. CNComment:y坐标

\retval ::HI_SUCCESS  Success. CNComment:设置成功
\retval ::HI_FAILURE  Parameter invalid. CNComment:设置失败

\see \n
None
*/
HI_S32 HI_UNF_SO_SetPos(HI_HANDLE handle, HI_U32 u32x, HI_U32 u32y);

/**
\brief  Getting the number in the butitle queue.
CNComment:获取缓冲buffer中未显示的字幕数据个数
\attention \n
None
\param[in] handle Handle of SO instance. CNComment:so实例句柄
\param[out] pu32SubNum Number of subtitles in queue. CNComment:缓冲字幕个数

\retval ::HI_SUCCESS Success. CNComment:成功
\retval ::HI_FAILURE Operation fail. CNComment:失败

\see \n
None
*/
HI_S32 HI_UNF_SO_GetSubNumInBuff(HI_HANDLE handle, HI_U32 *pu32SubNum);

/**
\brief Clear the subtitles in queue.
CNComment:清除字幕缓冲中的数据，字幕切换时，需调用该接口清除so字幕缓存
\attention \n
None
\param[in] handle Handle of SO instance. CNComment:so实例句柄

\retval ::HI_SUCCESS Success. CNComment:成功
\retval ::HI_FAILURE Operation invalid. CNComment:失败

\see \n
None
*/
HI_S32 HI_UNF_SO_ResetSubBuf(HI_HANDLE handle);

/**
\brief  Send subtitles to SO queue. If the data size and the number is larger than the value set by the user, then the transmission fails.
CNComment:发送字幕数据给so，如果缓冲size和个数都超过用户设置的值，则发送失败
\attention \n
None
\param[in] handle Handle of SO instance. CNComment:so实例句柄
\param[in] pstSubInfo Data of subtitle. CNComment:字幕信息
\param[in] u32TimeOut Timeout of sending subtitle. CNComment:发送超时时间，单位ms

\retval ::HI_SUCCESS  Success. CNComment:发送成功
\retval ::HI_FAILURE  Operation fail.CNComment:发送失败

\see \n
None
*/
HI_S32 HI_UNF_SO_SendData(HI_HANDLE handle, const HI_UNF_SO_SUBTITLE_INFO_S *pstSubInfo, HI_U32 u32TimeOutMs);

/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_SO_H__ */

