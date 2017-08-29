#ifndef __HI_UNF_SUBT_H__
#define __HI_UNF_SUBT_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus*/

/***************************** Macro Definition ******************************/
/** Invalid handle in subtitle */
/**CNcomment: 无效的字幕句柄 */
#define SUBT_INVALID_HANDLE   (0x0)
/** the max item(language) in Subtitling descriptor */
/**CNcomment: 最大的字幕项(语言)个数 */
#define SUBT_ITEM_MAX_NUM     (32)
/** the max subtitle instance */
/**CNcomment: 最大的字幕模块实例 */
#define SUBT_INSTANCE_MAX_NUM (8)

/** @} */  /** <!-- ==== Macro Definition end ==== */

/*************************** Structure Definition ****************************/
/** Defines the type used to code the subtitle */
/**CNcomment: 定义字幕编码类型枚举 */
typedef enum hiUNF_SUBT_TYPE_E
{
    HI_UNF_SUBT_TYPE_BITMAP = 0, /**< coding of bitmap */ /**<CNcomment: 位图编码 */
    HI_UNF_SUBT_TYPE_TEXT,       /**< coded as a string of characters */ /**<CNcomment: 文本编码 */
    HI_UNF_SUBT_TYPE_BUTT
}HI_UNF_SUBT_TYPE_E;

/** Defines the status of the subtitling page */
/**CNcomment: 定义字幕页状态枚举 */
typedef enum hiUNF_SUBT_PAGE_STATE_E
{
	HI_UNF_SUBT_PAGE_NORMAL_CASE		= 0,	/**< page update, use previous page instance to display */ /**<CNcomment: 局部更新 */
	HI_UNF_SUBT_PAGE_ACQUISITION_POINT,		    /**< page refresh, use next page instance to display */ /**<CNcomment: 全屏刷新 */
	HI_UNF_SUBT_PAGE_MODE_CHANGE,				/**< new page, needed to display the new page */ /**<CNcomment: 刷新整个字幕页 */
	HI_UNF_SUBT_PAGE_BUTT
}HI_UNF_SUBT_PAGE_STATE_E;

/** Defines the data of the subtitle output */
/**CNcomment: 定义字幕输出数据结构体 */
typedef struct hiUNF_SUBT_DATA_S
{
    HI_UNF_SUBT_TYPE_E enDataType;        /**< the type used to code the subtitle */ /**<CNcomment: 字幕编码类型 */
    HI_UNF_SUBT_PAGE_STATE_E enPageState; /**< the status of the subtitling page */ /**<CNcomment: 字幕页状态 */
    HI_U32             u32x;              /**< the horizontal address of subtitling page */ /**<CNcomment: x坐标 */
    HI_U32             u32y;              /**< the vertical address of subtitling page */ /**<CNcomment: y坐标 */
    HI_U32             u32w;              /**< the horizontal length of subtitling page */ /**<CNcomment: 宽度 */
    HI_U32             u32h;              /**< the vertical length of subtitling page */ /**<CNcomment: 高度 */
    HI_U32             u32BitWidth;       /**< bits in pixel-code */ /**<CNcomment: 位宽 */
    HI_U32             u32PTS;            /**< presentation time stamp */ /**<CNcomment: 时间戳 */
    HI_U32             u32Duration;       /**< the period, expressed in ms, after which a page instance is no longer valid */ /**<CNcomment: 持续时间，单位是ms */
    HI_U32             u32PaletteItem;    /**< pixels of palette */ /**<CNcomment: 调色板长度 */
    HI_VOID*           pvPalette;         /**< palette data */ /**<CNcomment: 调色板数据 */
    HI_U32             u32DataLen;        /**< subtitling page data length */ /**<CNcomment: 字幕数据长度 */
    HI_U8*             pu8SubtData;       /**< subtitling page data */ /**<CNcomment: 字幕数据 */
}HI_UNF_SUBT_DATA_S;

/** Defines the item of the subtitling content */
/**CNcomment: 定义字幕服务项结构体 */
typedef struct hiUNF_SUBT_ITEM_S
{
    HI_U32 u32SubtPID;      /**< the pid for playing subtitle */ /**<CNcomment: 字幕pid */
    HI_U16 u16PageID;       /**< the Subtitle page id */ /**<CNcomment: 字幕页id */
    HI_U16 u16AncillaryID;  /**< the Subtitle ancillary id */ /**<CNcomment: 字幕辅助页id */
}HI_UNF_SUBT_ITEM_S;

typedef HI_S32 (*HI_UNF_SUBT_CALLBACK_FN)(HI_U32 u32UserData, HI_UNF_SUBT_DATA_S *pstData);

/** Defines the parameter of subtitle instance */
/**CNcomment: 定义字幕模块参数结构体 */
typedef struct hiUNF_SUBT_PARAM_S
{
    HI_UNF_SUBT_ITEM_S astItems[SUBT_ITEM_MAX_NUM]; /**< the item of the subtitling content */ /**<CNcomment: 字幕内容 */
    HI_U8  u8SubtItemNum;                           /**< amount of subtitling item */ /**<CNcomment: 字幕内容个数 */
    HI_UNF_SUBT_CALLBACK_FN pfnCallback;            /**< callback function in which output subtitling page data */ /**<CNcomment: 回调函数，用来输出解码后的字幕数据 */
    HI_U32 u32UserData;                             /**< user data used in callback function */ /**<CNcomment: 用户数据，只用在回调函数里面 */
}HI_UNF_SUBT_PARAM_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API Declaration *****************************/
/**
\brief Initialize subtitle module. CNcomment: 初始化字幕模块
\attention \n
none. CNcomment: 无
\retval ::HI_SUCCESS initialize success. CNcomment: 初始化成功
\retval ::HI_FAILURE initialize failure. CNcomment: 初始化失败
\see \n
none. CNcomment: 无
*/
HI_S32 HI_UNF_SUBT_Init(HI_VOID);

/**
\brief DeInitialize subtitle module. CNcomment: 去初始化字幕模块
\attention \n
none. CNcomment: 无
\retval ::HI_SUCCESS deinitialize success. CNcomment: 去初始化成功
\retval ::HI_FAILURE deinitialize failure. CNcomment: 去初始化失败
\see \n
none. CNcomment: 无
*/
 HI_S32 HI_UNF_SUBT_DeInit(HI_VOID);

/**
\brief Create subtitle module. CNcomment: 创建字幕模块
\attention \n
none. CNcomment: 无
\param[in]  pstSubtParam  parameters used in created subtitle. CNcomment: 参数值
\param[out] phSubt        subtitle handle. CNcomment: 字幕句柄
\retval ::HI_SUCCESS create success. CNcomment: 创建成功
\retval ::HI_FAILURE create failure. CNcomment: 创建失败
\see \n
none. CNcomment: 无
*/
HI_S32 HI_UNF_SUBT_Create(HI_UNF_SUBT_PARAM_S *pstSubtParam, HI_HANDLE *phSubt);

/**
\brief Destroy subtitle module. CNcomment: 销毁字幕模块
\attention \n
none. CNcomment: 无
\param[in]  hSubt         subtitle handle. CNcomment: 字幕句柄
\retval ::HI_SUCCESS destroy success. CNcomment: 销毁成功
\retval ::HI_FAILURE destroy failure. CNcomment: 销毁失败
\see \n
none. CNcomment: 无
*/
HI_S32 HI_UNF_SUBT_Destroy(HI_HANDLE hSubt);

/**
\brief Select one subtitle content to output. CNcomment: 切换字幕内容
\attention \n
none. CNcomment: 无
\param[in]  hSubt         subtitle handle. CNcomment: 字幕句柄
\param[in]  pstSubtItem   subtitle item. CNcomment: 字幕内容项
\retval ::HI_SUCCESS switching success. CNcomment: 切换成功
\retval ::HI_FAILURE switching failure. CNcomment: 切换失败
\see \n
none. CNcomment: 无
*/
HI_S32 HI_UNF_SUBT_SwitchContent(HI_HANDLE hSubt, HI_UNF_SUBT_ITEM_S *pstSubtItem);

/**
\brief Reset subtitle module. CNcomment: 复位字幕模块
\attention \n
none. CNcomment: 无
\param[in]  hSubt         subtitle handle. CNcomment: 字幕句柄
\retval ::HI_SUCCESS reset success. CNcomment: 复位成功
\retval ::HI_FAILURE reset failure. CNcomment: 复位失败
\see \n
none. CNcomment: 无
*/
HI_S32 HI_UNF_SUBT_Reset(HI_HANDLE hSubt);

/**
\brief Update subtitle module. CNcomment: 更新字幕模块
\attention \n
none. CNcomment: 无
\param[in]  hSubt         subtitle handle. CNcomment: 字幕句柄
\param[in]  pstSubtParam  the new subtitle content. CNcomment: 新的字幕内容信息
\retval ::HI_SUCCESS update success. CNcomment: 更新成功
\retval ::HI_FAILURE update failure. CNcomment: 更新失败
\see \n
none. CNcomment: 无
*/
HI_S32 HI_UNF_SUBT_Update(HI_HANDLE hSubt, HI_UNF_SUBT_PARAM_S *pstSubtParam);

/**
\brief Inject DVB subtitle stream to decoder. CNcomment: 注入字幕数据到解码器
\attention \n
Used the PES packet syntax for carriage of DVB subtitles. CNcomment:DVB字幕传输使用PES格式 
\param[in]  hSubt         subtitle handle. CNcomment: 字幕句柄
\param[in]  u32SubtPID    the pid of subtitle stream. CNcomment: 字幕流pid
\param[in]  pu8Data       subtitle stream data. CNcomment: 字幕数据
\param[in]  u32DataSize   the size of subtitle stream data. CNcomment: 字幕数据长度
\retval ::HI_SUCCESS inject success. CNcomment: 注入成功
\retval ::HI_FAILURE inject failure. CNcomment: 注入失败
\see \n
none. CNcomment: 无
*/
HI_S32 HI_UNF_SUBT_InjectData(HI_HANDLE hSubt, HI_U32 u32SubtPID, HI_U8* pu8Data, HI_U32 u32DataSize);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus*/

#endif
