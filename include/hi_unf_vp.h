/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_vp.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2011/03/25
  Description   :
  History       :
  1.Date        : 2011/03/25
    Author      :
    Modification: Created file

 *******************************************************************************/

/**
 * \file
 * \brief Describes the information about the video phone (VP) engine. CNcomment: 提供VP视频引擎的相关信息
 */
#ifndef __HI_UNF_VP_H__
#define __HI_UNF_VP_H__
#include "hi_common.h"
#include "hi_unf_common.h"
#include "hi_unf_vi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif


/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_2_13 */
/** @{ */  /** <!-- ====[VP data structure] */

/** */
typedef struct hi_VP_VENC_CHN_ATTR_S
{
    HI_UNF_VCODEC_TYPE_E     enEncType;	       /**<Encoder type*/ /**<CNcomment: 编码器类型 */
    HI_UNF_VI_E              enViPort;		   /**<Input port*/ /**<CNcomment: 输入端口 */
    HI_UNF_VI_INPUT_MODE_E   enInputMode;      /**<Video input mode. Only the universal serial bus (USB) camera is supported.*/ /**<CNcomment: 视频输入模式，目前只支持USB摄像头*/
    HI_U32                   u32Width;
    HI_U32                   u32Height;
    HI_U32                   u32TargetBitRate; /**<Rate controller (RC) parameter. It can be set dynamically.*/ /**<CNcomment: RC参数,可动态设置 */
    HI_U32                   u32TargetFrmRate; /**<Target frame rate. It can be set dynamically.*/ /**<CNcomment: 目标帧率,可动态设置 */ 
    HI_U32                   u32InputFrmRate;  /**<Input frame rate. It can be set dynamically. The value of u32TargetFrmRate is less than or equal to the value of u32InputFrmRate.*/
                                               /**<CNcomment: 输入帧率,可动态设置,u32TargetFrmRate <= u32InputFrmRate */ 
    HI_U32                   u32Gop;		   /**<Group of picture (GOP) size. It can be set dynamically.*/ /**<CNcomment: GOP大小,可动态设置 */ 
	HI_UNF_VP_NET_PARA_S     stEncNetPara;	   /**<Local network parameter*/ /**<CNcomment: 本地网络参数*/	
}HI_VP_VENC_CHN_ATTR_S; 

typedef struct hi_VP_VDEC_CHN_ATTR_S
{
    HI_UNF_VCODEC_TYPE_E     enDecType;	       /**<Decoder type*/ /**<CNcomment: 解码器类型 */
	HI_UNF_VP_NET_PARA_S     stDecNetPara;	   /**<Local network parameter*/ /**<CNcomment: 本地网络参数*/
	
}HI_VP_VDEC_CHN_ATTR_S;          

/**Video engine channel attribute*/
/*CNcomment: 视频引擎通道属性 */
typedef struct hiUNF_VP_CHN_ATTR_S
{
    HI_HANDLE hLocalWin;                       /**<Handle of a local video output (VO) window*/ /**<CNcomment: 本地VO窗口句柄*/  
    HI_HANDLE hRemoteWin;                      /**<Handle of a remote VO window*/ /**<CNcomment: 远端VO窗口句柄*/
    HI_VP_VENC_CHN_ATTR_S stEncAttr;           /**<Encoder parameter*/ /**<CNcomment: 编码器参数*/
	HI_VP_VDEC_CHN_ATTR_S stDecAttr;           /**<Decoder parameter*/ /**<CNcomment: 解码器参数*/
}HI_UNF_VP_CHN_ATTR_S;

/**RTCP configure of video engine channel*/
/*CNcomment: 视频引擎通道RTCP配置信息 */
typedef struct hiUNF_VP_RTCP_CFG_S
{
    HI_U32 		u32EnableFlag;                 /**<Enable RTCP function: 0--disable, 1--enable*/ /**<CNcomment: RTCP统计使能: 0--不使能, 1--使能*/
    HI_U32 		u32SendInterval;               /**<Send interval of RTCP report, [500, 65535]ms, must be integer of 500ms*/ /**<CNcomment: RTCP报告发送间隔, [500, 65535] ms , 必须为500ms的整数倍*/
}HI_UNF_VP_RTCP_CFG_S;

/**RTCP statistics information*/
/**CNcomment: RTCP 统计信息*/
typedef struct hiUNF_VP_RTCP_STATIC_INFO_S
{
    HI_U32 u32TotalLostPacket;                 /**<Total lost packet*/ /**<CNcomment: 数据丢包统计*/
    HI_U32 u32LossFraction;                    /**<Lost rate(%)*/ /**<CNcomment: 丢包率(%) */
    HI_U32 u32Jitter;                          /**<Jitter(ms)*/ /**<CNcomment: 平均抖动(ms) */
    HI_U32 u32Delay;                           /**<Delay(ms)*/ /**<CNcomment: 平均时延(ms) */
}HI_UNF_VP_RTCP_STATIC_S; 

/**Statistic information of network*/
/*CNcomment: 视频引擎通道网络统计信息 */
typedef struct hiUNF_VP_NET_STA_S
{
    HI_U32 u32SendPacketNum;                   /**<Total send packet number*/ /**<CNcomment: 发送包总数*/
    HI_U32 u32SendBytes;                       /**<Total send bytes*/ /**<CNcomment: 发送字节数*/
    HI_UNF_VP_RTCP_STATIC_S stSendInfo;        /**<Send information*/ /**<CNcomment: 发送统计*/
    HI_UNF_VP_RTCP_STATIC_S stRecvInfo;        /**<Reveive information*/ /**<CNcomment: 接收统计*/
}HI_UNF_VP_NET_STA_S;
/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      H_1_2_3 */
/** @{ */  /** <!-- 【VP】 */

/**
 \brief Initializes the VP module. CNcomment: 初始化VP模块
 \attention \n
Call this application programming interface (API) before creating a VP channel by calling ::HI_UNF_VP_Create. 
CNcomment: 在调用::HI_UNF_VP_Create接口创建引擎之前，调用本接口
 \param N/A CNcomment: 无
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_DEV_NOT_EXIST The VP device does not exist. CNcomment: 设备不存在
 \retval ::HI_ERR_VP_DEV_OPEN_ERR The VP device fails to be started. CNcomment: 设备打开错误
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_Init(HI_VOID);

/**
 \brief Deinitializes the VP module. CNcomment: 去初始化VP模块
 \attention \n
Call this API after destroying all VP channels by calling ::HI_UNF_VP_DestroyChannel.
CNcomment: 在调用::HI_UNF_VP_DestroyChannel接口销毁所有的VP通道后，调用本接口
 \param N/A CNcomment: 无
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_NOT_INIT The VP is not initialized. CNcomment: VP未初始化
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_DeInit(HI_VOID);

/**
 \brief Obtains the default parameter values of a VP channel. CNcomment: 获取VP通道缺省参数
 \attention \n
Call this API before creating a VP channel by calling ::HI_UNF_VP_CreateChannel. This enables you to set parameters conveniently.
CNcomment: 在调用::HI_UNF_VP_CreateChannel接口创建VP通道之前，调用本接口，方便填写参数
 \param[in] N/A CNcomment: 无
 \param[out] pstDefChAttr Pointer to the default VP channel attributes. For details, see :HI_UNF_VP_CHN_ATTR_S. CNcomment: 指针类型，VP通道默认属性，参见:HI_UNF_VP_CHN_ATTR_S
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_GetChDefaultAttr(HI_UNF_VP_CHN_ATTR_S *pstDefChAttr);

/**
 \brief Creates a VP channel. CNcomment: 创建VP通道
 \attention \n
N/A CNcomment: 无
 \param[in]  pstChAttr Channel parameter CNcomment: 通道参数
 \param[out] phVp Pointer to the VP channel handle. CNcomment: 指针类型，VP通道句柄
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval ::HI_ERR_VP_NOT_SUPPORT The input parameter is invalid. CNcomment: 输入参数非法
 \retval ::HI_ERR_VP_NOT_SUPPORT The mode is not supported. CNcomment: 不支持模式
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_CreateChannel(HI_UNF_VP_CHN_ATTR_S *pstChAttr, HI_HANDLE *phVp);

/**
 \brief Destroys a VP channel. CNcomment: 销毁VP 通道
 \attention \n
N/A CNcomment: 无
 \param[in] hVp VP channel handle CNcomment: VP通道句柄
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_NOT_INIT The VP module is not initialized. CNcomment: VP未初始化
 \retval ::HI_ERR_VP_INVALID_HANDLE The VP handle is invalid. CNcomment: 非法的VP句柄
 \retval Other values: A channel fails to be destroyed. CNcomment: 其它 销毁通道失败
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_DestroyChannel(HI_HANDLE hVp);

/**
 \brief Obtains the configuration of a VP channel. CNcomment: 获取VP 通道配置
 \attention \n
 \param[in] hVp VP channel handle CNcomment: VP 通道句柄
 \param[out] pstChAttr Pointer to VP channel attributes. For details, see :HI_UNF_VP_CHN_ATTR_S. CNcomment: 指针类型，VP 通道属性，参见:HI_UNF_VP_CHN_ATTR_S
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: 无效的输入参数
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval Other values: Channel attributes fail to be obtained. CNcomment: 其它 获取通道属性失败
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_GetChAttr(HI_HANDLE hVp, HI_UNF_VP_CHN_ATTR_S *pstChAttr);

/**
 \brief Modifies the configuration of a VP channel. CNcomment: 修改VP通道配置
 \attention \n
You are advised to obtain the current channel configuration by calling HI_UNF_VP_GetChAttr(), and modify parameter values as required. Set the corresponding change flags to 1, and set irrelevant change flags to 0.
CNcomment: 建议先调用HI_UNF_VP_GetChAttr()获取当前通道配置，再对参数做必要修改，对应的更改标记置1，无关更改标志置0。
 \param[in] hVp VP channel handle CNcomment: VP 通道句柄
 \param[in] pstChAttr Pointer to VP channel attributes. For details, see :HI_UNF_VP_CHN_ATTR_S. CNcomment: 指针类型，VP 通道属性，参见:HI_UNF_VP_CHN_ATTR_S
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: 无效的输入参数
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval Other values: Channel attributes fail to be modified. CNcomment: 其它 修改通道属性失败
 \see \n
N/A CNcomment:无
 */
HI_S32 HI_UNF_VP_SetChAttr(HI_HANDLE hVp, HI_UNF_VP_CHN_ATTR_S *pstChAttr);

/**
 \brief Starts a VP channel. CNcomment: VP通道开始运行
 \attention \n
After setting parameters including the codec, video input (VI), and video output (VO) parameters, you can start the video engine by calling this API to transmit or receive data over the Internet and display the local or remote video output.
CNcomment: 在参数准备好后，包括编解码器、VI/VO设置正确后，调用此接口可以启动视频引擎的运行，实现网络收发、显示本地、远端视频输出
 \param[in] hVp VP channel handle CNcomment: VP 通道句柄
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: 无效的输入参数
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval Other values: A VP channel fails to be started. CNcomment: 其它 VP通道开始运行失败
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_Start(HI_HANDLE hVp);

/**
 \brief Stops a VP channel. CNcomment: VP通道停止运行
 \attention \n
After a VP channel is started successfully, you can stop it by calling this API to freeze the screen or stop transmitting or receiving data over Internet. You can resume the VP channel by calling HI_UNF_VP_Start.
CNcomment: 在VP通道正常启动运行后，可以通过此接口暂停运行，使画面冻结、网络收发暂停。可以调用HI_UNF_VP_Start恢复运行
 \param[in] hVp VP channel handle CNcomment: VP 通道句柄
 
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: 无效的输入参数
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval Other values: A VP channel fails to be started. CNcomment: 其它 VP通道开始运行失败
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_Stop(HI_HANDLE hVp);

/**
 \brief Previews the local video over a VP channel. CNcomment: VP通道开始预览本地视频
 \attention \n
After the VI and hLocalWin parameters are set, you can preview the local video by calling this API.
CNcomment: 在VI和hLocalWin准备好之后，开始预览本地视频
 \param[in] hVp VP channel handle CNcomment: VP 通道句柄
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: 无效的输入参数
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval Other values: A VP channel fails to be started. CNcomment: 其它 VP通道开始运行失败
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_StartPreView(HI_HANDLE hVp);

/**
 \brief Stops previewing the local video over a VP channel. CNcomment: VP通道预览本地视频
 \attention \n
When a local video is previewed over a VP channel, you can stop previewing the video by calling this API.
CNcomment: 在VP通道预览本地视频后，调用停止预览
 \param[in] hVp VP channel handle CNcomment: VP 通道句柄
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: 无效的输入参数
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval Other values: A VP channel fails to be started. CNcomment: 其它  VP通道开始运行失败
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_StopPreView(HI_HANDLE hVp);

/**
 \brief Configs RTCP channel over a VP channel. CNcomment: VP通道配置RTCP通道
 \attention \n
When a VP channel has been created, you can config RTCP channel to enable and config RTCP sending frequency by calling this API.
CNcomment: 在创建VP通道后，调用该接口配置RTCP通道，可以使能以及调节RTCP发包频率
 \param[in] hVp VP channel handle CNcomment: VP通道句柄
 \param[out] pstRtcpCfg Pointer to config RTCP information, refer to HI_UNF_VP_RTCP_CFG_S. CNcomment: 指针类型，VP 通道RTCP配置信息，参见:HI_UNF_VP_RTCP_CFG_S
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: 无效的输入参数
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval Other value CNcomment: 其它
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_ConfigRtcp(HI_HANDLE hVp,HI_UNF_VP_RTCP_CFG_S *pstRtcpCfg);

/**
 \brief Gets network statistics information over a VP channel. CNcomment: VP通道获取网络统计信息
 \attention \n
When a VP channel has been started, you can get network statistics information to config parameter of video encoder by calling this API.
CNcomment: 在运行VP通道后，调用该接口获取网络统计信息以调整编码器参数
 \param[in] hVp VP channel handle CNcomment: VP通道句柄
 \param[out] pstNetStatics Pointer to network statistics information of VP channel, refer to HI_UNF_VP_NET_STA_S. CNcomment: 指针类型，VP通道网络统计信息，参见:HI_UNF_VP_NET_STA_S
 \retval ::HI_SUCCESS Success CNcomment: 成功
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: 无效的输入参数
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: 空指针
 \retval Other value CNcomment: 其它 
 \see \n
N/A CNcomment: 无
 */
HI_S32 HI_UNF_VP_GetNetStatics(HI_HANDLE hVp,HI_UNF_VP_NET_STA_S *pstNetStatics);
#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif

#endif
