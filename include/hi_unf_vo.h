/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_vo.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/16
  Description   :
  History       :
  1.Date        : 2009/12/16
    Author      : w58735
    Modification: Created file

*******************************************************************************/
/** 
 * \file
 * \brief  supply info of vo module. CNcomment:提供VO的相关信息
 */
 
#ifndef  __HI_UNF_VO_H__
#define  __HI_UNF_VO_H__

#include "hi_unf_common.h"
#include "hi_unf_vi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      VO */
/** @{ */  /** <!-- [VO] */

/**defines the vo enumeration of video layer.*/
/**CNcomment:定义VO枚举*/
typedef enum hiUNF_VO_E
{
    HI_UNF_VO_SD0   = 0x0,  /**< standard definition video layer*//**<CNcomment:标清视频层0 */
    HI_UNF_VO_HD0,          /**< high definition video layer*//**<CNcomment:高清视频层0 */
    HI_UNF_VO_BUTT
}HI_UNF_VO_E;

/**define the attribution of window.*/
/**CNcomment:定义WINDOW属性*/
typedef struct hiUNF_WINDOW_ATTR_S
{
    HI_UNF_VO_E               enVo;          /**<the layer where window locate in.*//**<CNcomment: 窗口所在的视频层 */
    HI_BOOL                   bVirtual;      /**< whether is virtual window or not.*//**<CNcomment: 是否为虚拟窗口 */
    HI_UNF_VIDEO_FORMAT_E     enVideoFormat; /**<the data format of virtual window*//**<CNcomment: 虚拟窗口数据格式 */
    HI_UNF_ASPECT_RATIO_E     enAspectRatio; /**<the aspect ratio of window.*//**<CNcomment: 窗口的宽高转换比例 */
    HI_UNF_ASPECT_CVRS_E      enAspectCvrs;  /**<the method to the aspect ratio transfer.*//**<CNcomment: 窗口的宽高转换方式 */
    HI_RECT_S                 stInputRect;   /**<the crop area .*//**<CNcomment: 窗口的裁减区域 */
    HI_RECT_S                 stOutputRect;  /**<the window display area on the layer.*//**<CNcomment: 窗口在视频层上的显示区域 */
    HI_RECT_S                 stReviseOutputRect; /*Revise win size*/
} HI_UNF_WINDOW_ATTR_S;

typedef struct hiUNF_BUFFER_ATTR_S
{
    HI_S32              s32Stride;
    HI_U32              u32PhyAddr[16];
    HI_U32              u32BuffIndex[16];
    HI_S32              s32BuffNum;
}HI_UNF_BUFFER_ATTR_S;

/** the running mode of vo*/
/**CNcomment:VO设备的运行模式 */
typedef enum hiUNF_VO_DEV_MODE_E
{
    HI_UNF_VO_DEV_MODE_NORMAL,  /**<normal mode: no more than 2 windows to be created.*//**<CNcomment: 正常模式，只能创建2个WINDOW */
    HI_UNF_VO_DEV_MODE_MOSAIC,  /**<mosaic mode: can create more than 2 windows.*//**<CNcomment: 马赛克模式，可以创建多个WINDOW */
    HI_UNF_VO_DEV_MODE_STANDALONE,  /*seperate mode,only 1 window can be created,and  the aspect ratio set seperately.*/
    HI_UNF_VO_DEV_MODE_BUTT
} HI_UNF_VO_DEV_MODE_E;

/**define the freeze mode enumeration.*/
/**CNcomment:定义Freeze模式枚举*/
typedef enum hiUNF_WINDOW_FREEZE_MODE_E
{
    HI_UNF_WINDOW_FREEZE_MODE_LAST = 0,   /**<display the last frame when freeze.*//**<CNcomment: freeze时显示最后一帧*/
    HI_UNF_WINDOW_FREEZE_MODE_BLACK = 1,  /**<display a black frame when freeze.*//**<CNcomment: freeze时显示后黑屏*/
    HI_UNF_WINDOW_FREEZE_MODE_BUTT
} HI_UNF_WINDOW_FREEZE_MODE_E;

/**define the algs enumeration.*/
/**CNcomment:定义算法类型枚举*/
typedef  enum hiUNF_ALG_TYPE_E
{
    HI_ALG_TYPE_DEI = 0,		/**<deinteralce alg.*//**<CNcomment: 视频去隔行算法*/
    HI_ALG_TYPE_ACC,			/**<clolor enhanced alg. *//**<CNcomment: 视频颜色增强算法*/
    HI_ALG_TYPE_ACM,			/**<color management alg.*//**<CNcomment: 视频颜色管理算法*/
    HI_ALG_TYPE_SHARPNESS,		/**<the color sharpen alg.*//**<CNcomment: 视频颜色锐化算法*/
    HI_ALG_TYPE_BUTT
} HI_UNF_ALG_TYPE_E;

/**define the struct of alg contoller func.*/
/**CNcomment:定义算法控制结构体  */
typedef struct hiUNFALG_CONTROL_S
{
    HI_UNF_ALG_TYPE_E	enAlgType;		/**<the alg enum.*//**<CNcomment: 算法控制类型*/
    HI_BOOL		bEnable;		/**<whether to open the alg or not.*//**<CNcomment: 算法使能/关闭控制*/
    HI_VOID    *alg_info;		/** define the alg information.*/
	                                        /** since the alg_info structure is not the same for different alg types, so it's a ptr of void **/
} HI_UNF_ALG_CONTROL_S;

/*define the sharpen alg info struct.*/
typedef struct hiUNF_VO_SHARPEN_INFO_S
{ 
    HI_S16 s16LTICTIStrengthRatio;		/**define the sharpen strength.*/
}HI_UNF_VO_SHARPEN_INFO_S;


/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      VO */
/** @{ */  /** <!-- [VO] */

/**
\brief  init vo module. CNcomment:初始化VO模块
\attention \n
call this func before any other vo funcs .
CNcomment:调用VO模块要求首先调用本接口
\param[in]   enDevMode  the vo running mode.  CNcomment:VO模块的运行模式
\retval ::HI_SUCCESS successs.CNcomment:成功
\retval ::HI_ERR_VO_DEV_NOT_EXIST  vo device not exist. CNcomment:VO设备不存在
\retval ::HI_ERR_VO_NOT_DEV_FILE   not vo device. CNcomment:VO非设备
\retval ::HI_ERR_VO_DEV_OPEN_ERR   open vo failed. CNcomment:VO打开失败
\retval ::HI_ERR_VO_INVALID_PARA   illegal param. CNcomment:输入参数非法
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_Init(HI_UNF_VO_DEV_MODE_E enDevMode);

/**
\brief  deinit vo module.CNcomment:去初始化VO模块
\attention \n
before calling this func ,you should call HI_UNF_VO_Close to close all the windows first.
CNcomment:在调用::HI_UNF_VO_Close接口关闭所有打开的VO后调用本接口
\param CNcomment:无
\retval ::HI_SUCCESS  success.CNcomment:成功
\retval ::HI_ERR_VO_DEV_CLOSE_ERR  vo deinited failed. CNcomment:VO关闭失败
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_DeInit(HI_VOID);

/**
\brief open the given vo layer.CNcomment:打开指定VO
\attention \n
CNcomment:无
\param[in] enVo    vo layer.CNcomment:VO层号
\retval ::HI_SUCCESS openned success.CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT  display not inited. CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_CREATE_ERR    opend failed.CNcomment:创建失败
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_Open(HI_UNF_VO_E enVo);

/**
\brief close the given vo layer.CNcomment:关闭指定VO
\attention \n
CNcomment:无
\param[in] enVo  vo layer.CNcomment:VO层号
\retval ::HI_SUCCESS  close success.CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params. CNcomment:输入参数非法
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_Close(HI_UNF_VO_E enVo);




/**
\brief set the alpha value of given vo layer.CNcomment:设置指定VO的ALPHA
\attention \n
CNcomment:无
\param[in] enVo       vo layer num.  CNcomment:VO层号
\param[in] u32Alpha   the alpha value determines transparence of image,range:0~255.0:transparent;255: not transparent. 
 CNcomment:视频图像显示透明度值，取值范围为0～255。取值为0时：全透明；取值为255时：不透明
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA illegal params. CNcomment:输入参数非法
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetAlpha(HI_UNF_VO_E enVo, HI_U32 u32Alpha);

/**
\brief  get the alpha value of given vo layer. CNcomment:获取指定vo的ALPHA
\attention \n
CNcomment:无
\param[in]  enVo    vo layer number. CNcomment:VO层号
\param[out] pu32Alpha   ptr value,determines the alpha value.CNcomment:指针类型，视频图像显示透明度值
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT   display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA illegal params. CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR      null pointerCNcomment:输入指针为空
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_GetAlpha(HI_UNF_VO_E enVo, HI_U32 *pu32Alpha);

/**
\brief set the rect of given vo.CNcomment:设置指定VO的rect
\attention \n
this func can be called only at the conditions of mosaic mode of vo.
CNcomment:只有在VO工作在MOSAIC模式才能调用本接口
\param[in] enVo       vo layer number. CNcomment:VO层号
\param[in] pstRect   a pointer typeof HI_RECT_S.CNcomment:rect的结构指针
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT   display not inited. CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment:操作非法
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetRect(HI_UNF_VO_E enVo, const HI_RECT_S *pstRect);


/**
\brief  get the rect of given vo.CNcomment:获取指定VO的rect
\attention \n
only under mosaic mode can this func be called.
CNcomment:只有在VO工作在MOSAIC模式才能调用本接口
\param[in] enVo       vo layer number. CNcomment:VO层号
\param[in] pstRect   a pointer typeof HI_RECT_S.CNcomment:rect的结构指针
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT   display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation. CNcomment:操作非法
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_GetRect(HI_UNF_VO_E enVo, HI_RECT_S *pstRect);

/**
\brief create the window.CNcomment:创建WINDOW
\attention \n
only ater vo openning can windows be created.
CNcomment:只有打开VO后，才能在其之上创建WINDOW
\param[in] pWinAttr   a pointer typeof HI_UNF_WINDOW_ATTR_S.CNcomment:WINDO属性结构指针
\param[in] phWindow   the window handler to be created.CNcomment:创建的WINDOW句柄
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_CREATE_ERR     CNcomment:创建失败
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_CreateWindow(const HI_UNF_WINDOW_ATTR_S *pWinAttr, HI_HANDLE *phWindow);

/**
\brief  destroy the given window.CNcomment:销毁WINDOW
\attention \n
CNcomment:无
\param[in] hWindow    the input window handler. CNcomment:WINDOW句柄
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT   display not inited. CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_DestroyWindow(HI_HANDLE hWindow);


/**
\brief to enable or disable the given window.CNcomment:使能/禁止WINDOW
\attention \n
Window can only be disabled after the corresponding avplay is stopped, else data will overflow.
CNcomment:只有先将AVPLAY的VID通道stop后，才能禁止window，否则将引起数据的溢出
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄
\param[in] bEnable     the flag  of enable or disable window. CNcomment:使能/禁止标志
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetWindowEnable(HI_HANDLE hWindow, HI_BOOL bEnable);

/**
\brief get the status of the given window: enable or not.CNcomment:获取WINDOW的使能状态
\attention \n
CNcomment:无
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄
\param[in] pbEnable    the status of window:enable or disable.CNcomment:使能/禁止标志.
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_GetWindowEnable(HI_HANDLE hWindow, HI_BOOL *pbEnable);

/**
\brief set the attribution of the given window. CNcomment:设置WINDOW属性
\attention \n
the two members of pWinAttr:envo and bVirtual are fixed when window created, and they can't be modified here.
CNcomment:enVo和bVirtual参数一旦创建后就不能再进行修改。
\param[in] hWindow    the input window handler.CNcomment:WINDOW句柄
\param[in] pWinAttr   the pointer of windows attr.CNcomment:WINDO属性结构指针
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT   display not inited. CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetWindowAttr(HI_HANDLE hWindow, const HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\brief get the attribution of the given window.CNcomment:获取WINDOW属性
\attention \n
CNcomment:无
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄
\param[in] pWinAttr    the pointer of windows attr. CNcomment:WINDO属性结构指针
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited. CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_GetWindowAttr(HI_HANDLE hWindow, HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\brief get the frame from given window ,used for 3d graphics testing.CNcomment:获取WINDOW的Frame信息，专门用于3D图形测试
\attention \n
CNcomment:无
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄
\param[out] pstFrameinfo  frame information. CNcomment:Frame信息
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT   display not inited.CNcomment: DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_AcquireFrame(HI_HANDLE hWindow, HI_UNF_VO_FRAMEINFO_S *pstFrameinfo);

/**
\brief return the frame back to the given window, used for 3d graphics testing.CNcomment:释放用户获取WINDOW的Frame，专门用于3D图形测试
\attention \n
CNcomment:无
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_ReleaseFrame(HI_HANDLE hWindow);

/**
\brief set the zorder of the given window.CNcomment:设置WINDOW的Z序
\attention \n
CNcomment:无
\param[in] hWindow    the input window handler.CNcomment:WINDOW句柄
\param[in] enZFlag    how to adjust zorder. CNcomment:Z序调节方式
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT   display not inited. CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetWindowZorder(HI_HANDLE hWindow, HI_LAYER_ZORDER_E enZFlag);

/**
\brief get the zorder of the given window.CNcomment:获取WINDOW的Z序
\attention \n
CNcomment:无
\param[in] hWindow       the input window handler.CNcomment:WINDOW句柄
\param[in] pu32Zorder    value of zoder, bigger value means higher prioty. CNcomment:Z序数值，数值越大优先级越高
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_GetWindowZorder(HI_HANDLE hWindow, HI_U32 *pu32Zorder);

/**
\brief attach the window with video source such as vi/avplay. CNcomment:把WINDOW与指定的AVPLAY/VI绑定
\attention \n
it can attach the handler of avplay or vi to the window.
CNcomment:可以将AVPLAY或VI的句柄绑定到WINDOW上。
\param[in] hWindow     the input window handler. CNcomment:WINDOW句柄
\param[in] hSrc        the handler of video source. CNcomment:数据源句柄
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params. CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_AttachWindow(HI_HANDLE hWindow, HI_HANDLE hSrc);


/**
\brief detach the window from the video source such as avplay or vi. CNcomment:把WINDOW与指定的AVPLAY/VI解绑定
\attention \n
CNcomment:无
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄
\param[in] hSrc        the handler of video source.CNcomment:数据源句柄
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: 输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_DetachWindow(HI_HANDLE hWindow, HI_HANDLE hSrc);

/**
\brief set the playing ratio of the given window.CNcomment:设置Winsow的播放速率
\attention \n
this function can change the playing ratio when playing.
CNcomment:此功能用于在播放过程中改变播放速率
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄
\param[in] u32WinRatio      play rate of window, range:[1,256*256], 256 means normal rate, 512 means 2X, 128 means 1/2X.CNcomment:取值范围为 [1, 256*256]，256代表正常速度播放
\retval ::HI_SUCCESS CNcomment: 成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: 输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST windows not exist.CNcomment: 窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetWindowRatio(HI_HANDLE hWindow, HI_U32 u32WinRatio);


/**
\brief  to freeze the video content of given window.CNcomment:冻结WINDOW的显示内容
\attention \n
the display will be freezed after calling this func, but backgrounddly,the data flow is normal from video decoder.
so when freezing is cacelled, the newest video content can be display at once.
CNcomment:此功能用于在播放过程中冻结屏幕显示内容，此时WINDOW中的数据流继续运行，\n
因此取消冻结后，会立刻显示最新的内容。
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄
\param[in] bEnable           shows whether to freeze window.CNcomment:使能/禁止标志
\param[in] enWinFreezeMode   the mode of freeze.CNcomment:冻结的方式
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: 输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_FreezeWindow(HI_HANDLE hWindow, HI_BOOL bEnable, HI_UNF_WINDOW_FREEZE_MODE_E enWinFreezeMode);


/**
\brief reset the window.CNcomment:复位WINDOW
\attention \n
this function can reset buffers of the given window, and black frame or the last frame will be displayed according configuration.
CNcomment:此功能清空window中的缓冲，根据参数显示黑帧或最后一帧。
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄
\param[in] enWinFreezeMode   method of freeze the window.CNcomment:复位的方式
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_ResetWindow(HI_HANDLE hWindow, HI_UNF_WINDOW_FREEZE_MODE_E enWinFreezeMode);

/**
\brief pass the external allocated buffer to this function to test 3d graphics.CNcomment:向WINDOW传递用户外部分配的buffer，专门用于3D图形测试
\attention \n
CNcomment:无
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄
\param[in] pstBufAttr  external buffer.CNcomment:外部的buffer
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_AttachExternBuffer(HI_HANDLE hWindow,HI_UNF_BUFFER_ATTR_S* pstBufAttr);

/**
\brief to set the work mode of window: quick output or not. Deinterlace alg will be disabled when quick output is enabled.
CNcomment:设置WINDOW是否工作在快速输出模式，快速输出模式强制关闭去隔行算法
\attention \n
CNcomment:无
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄
\param[in] bQuickOutputEnable  whether determine the output mode of window. CNcomment:快速输出模式使能/禁止标志
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: 输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetQuickOutputEnable(HI_HANDLE hWindow, HI_BOOL bQuickOutputEnable);

/**
\brief set the output rect attr when window is under browser mode.CNcomment:设置浏览器模式下，输出窗口属性
\attention \n
Only the member:stOutputRect of struct HI_UNF_WINDOW_ATTR_S is effective when calling this func.And then, the setting of HI_UNF_VO_SetWindowAttr
will be useless once calling this function. Negative value is allowed in rect setting.
CNcomment:只有stOutputRect成员设置有效，调用此接口后，HI_UNF_VO_SetWindowAttr\n
设置的窗口属性将无效，该接口允许坐标出现负数。
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄
\param[in] pWinAttr          the window attr only effective to outrect.CNcomment:WINDOW窗口，只有stOutputRect有效。
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT   display not inited.CNcomment: DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetWindowOutRect(HI_HANDLE hWindow, const HI_UNF_WINDOW_ATTR_S *pWinAttr);


/**
\brief  to set the filed mode of given window. CNcomment:设置窗口的场播放模式
\attention \n
when fast-backward playing, there will be no abnormity through calling this func. But calling of this
func is forbidden when normal playing. It should be called after HI_UNF_VO_AttachWindow.
CNcomment:通过设置此接口使能，保证快退不会出现场图像回退的现象，在正常播放时，\n
请设置为禁止，默认为禁止。HI_UNF_VO_AttachWindow调用之后使用有效。
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄
\param[in] bEnable           wether to enable field play.CNcomment:使能/禁止标志
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_SetWindowFieldMode(HI_HANDLE hWindow, HI_BOOL bEnable);

/**
\brief  to switch the given alg on or off.CNcomment:视频层算法开关
\attention \n
to switch the ACC/ACM alg on or off using this func, it also works when playing and should be called after vo init.
CNcomment:通过此接口控制视频层ACC\ACM等算法的开启关闭，正常播放时也可以切换，\n
必须要VO INIT之后才能调用.
\param[in] pAlgControl         the control struct of alg. CNcomment:算法控制结构体
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_AlgControl(const HI_UNF_ALG_CONTROL_S *pAlgControl);

/**
\brief capture the current frame of given window.CNcomment:捕获WINDOW的当前帧
\attention \n
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄
\param[in] pstCapPicture
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: 输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment: 操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_CapturePicture(HI_HANDLE hWindow, HI_UNF_CAPTURE_PICTURE_S *pstCapPicture);


/**
\brief if you capture picture is finished, release the memory .CNcomment:捕获完毕，释放捕获的内存区域
\attention \n
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄
\param[in] pstCapPicture
\retval ::HI_SUCCESS CNcomment:成功
\retval ::HI_ERR_VO_NO_INIT    display not inited.CNcomment:DISP未初始化
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: 输入参数非法
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment: 操作非法
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在
\see \n
CNcomment:无
*/
HI_S32 HI_UNF_VO_CapturePictureRelease(HI_HANDLE hWindow, HI_UNF_CAPTURE_PICTURE_S *pstCapPicture);



/** @} */  /** <!-- ==== API declaration end ==== */


#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif
#endif
