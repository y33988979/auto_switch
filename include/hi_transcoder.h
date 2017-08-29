#ifndef __HI_TRANSCODER_H__
#define __HI_TRANSCODER_H__

#include "hi_type.h"
#include "hi_unf_venc.h"
#include "hi_unf_aenc.h"

#ifdef __cplusplus
extern "C"{
#endif


/***************获取软件平台*****************/
/***************software platform define *****************/
#ifdef ANDROID_TOOLCHAIN
#define SOFT_BOARD_VERSION_ANDROID 
#else
#define SOFT_BOARD_VERSION_LINUX
#endif

/***********enum**************/

/*****************************************
	读取帧数据类型
******************************************/
/*****************************************
     transcoder media data type
******************************************/
typedef enum eTran_PAYLOAD
{
    PAYLOAD_VIDEO_NORMAL_FRAME = 1,
    PAYLOAD_VIDEO_KEY_FRAME = 5, //视频关键帧
    PAYLOAD_VIDEO_SPS_FRAME = 7,
    PAYLOAD_VIDEO_PPS_FRAME = 8,
    PAYLOAD_AUDIO_FRAME = 10, //音频帧
    PAYLOAD_MD_FRAME, //MD数据
    PAYLOAD_BUTT
}TRANSCODER_PAYLOAD_E;

/*****************************************
	转码模块转码音视频类型
******************************************/
/*****************************************
      transcoder video/audio type
******************************************/
typedef enum eTran_MediaCodec
{
    TRANSCODER_CODEC_ID_H264 = 0, 
    TRANSCODER_CODEC_ID_H263, 
    TRANSCODER_CODEC_ID_MPEG4,
    TRANSCODER_CODEC_ID_AACLC,
    TRANSCODER_CODEC_ID_AMRNB,
    TRANSCODER_CODEC_ID_G711A,
    TRANSCODER_CODEC_ID_NONE,
    TRANSCODER_CODEC_ID_BUTT
}Transcoder_MediaCodec;


typedef enum eTran_Attr_ID_E
{
    TRANSCODER_ALL_ATTR,
    TRANSCODER_VIDEO_ATTR,
    TRANSCODER_AUDIO_ATTR,
    TRANSCODER_BACKGND_ATTR,
    TRANSCODER_ATTR_BUTT
}Transcoder_Attr_ID_E;
/*****************************************
	媒体数据payLoad数据类型
******************************************/
/*****************************************
       media data payload data structure
******************************************/
typedef union hiTranscoder_DATA_TYPE_U
{
    HI_UNF_VENC_STREAM_S stVencStream;
    HI_UNF_ES_BUF_S      stAencStream;
}HI_TRAN_DATA_TYPE_U;

/*****************************************
	媒体数据帧结构
******************************************/
    
/*****************************************
     transcoder data frame structure
******************************************/
typedef struct tagTran_STREAM_S
{
	TRANSCODER_PAYLOAD_E ePayloadType;			/*PayLoad数据类型*/
    HI_TRAN_DATA_TYPE_U  enDataStream;
}TRANSCODER_STRAM;


/*提供给用户的指令回调接口，根据不同的指令，设置属性后传入源端模块，
由源端模块确定其相应方式

如为后台转码，此函数会由 Transcoder实现*/
/*
    supply for user callback function, modified by user, set by source module
*/
typedef HI_S32 (*HI_TRANSCODER_NODIFY_CALLBACK)(HI_HANDLE Handle,HI_U32 u32Command,HI_VOID* stAttr,HI_S32 s32Len );
/*******************************************
	转码模块转码输入参数
********************************************/
/*******************************************
     transcoder module create attr
********************************************/
typedef struct tagTran_HandleAttr
{
    Transcoder_MediaCodec audioCodec;		/*音频CodecID*/
    Transcoder_MediaCodec videoCodec;		/*视频CodecID*/
 //   HI_U32 u32ProtocolMask;                 /*打开时的打开协议的mask 值，可打开多个协议*/
    HI_U32 SourceType;              /*转码模块源处理音频源类型，为后续编码扩展预留*/
//    HI_S32 s32X;                    /*转码的起始位置 X 坐标*/
//    HI_S32 s32Y;                    /*转码的起始位置 Y 坐标*/
    HI_S32 s32Width;				/*视频分辨率--高*/
    HI_S32 s32Height; 				/*视频分辨率--宽*/
    HI_S32 s32VideoBitRate;				/*视频比特率*/
    HI_S32 s32VideoFrameRate;			/*视频帧率*/
    HI_S32 s32AudioSampleRate;			/*音频采样率*/
    HI_S32 s32AudioBandWidth;			/*音频采样宽度*/
    HI_S32 s32AudioChannels;            /*音频采样的声道数量*/
    HI_BOOL bCycle;                     /*对于文件输入是否要循环*/
    HI_HANDLE hSrc;				/*转码输入源，如果为NULL，则全屏转码*/
    HI_TRANSCODER_NODIFY_CALLBACK pNodifySrcFunc;   /*转码模块提供给其他模块的回调函数,后端端口回调给源端*/
}Transcoder_HandleAttr;

/********************************API declaration********************************/

/** 
brief 初始化转码器
attention 
调用转码要求首先调用该接口
param[in] 无
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief  transcoder initialization function
attention 
HiTranscoder module must init function
param[in] NULL
retval ::HI_SUCCESS  SUCCESS
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_Init(void);
/** 
brief 去初始化转码器
attention 
转码退出要求最后调用该接口
param[in] 无
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief transcoder uninitialization function
attention 
HiTranscoder module all clear function must called behind
param[in] 无
retval ::HI_SUCCESS  success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_DeInit(void);
/** 
brief 打开转码通道
attention 
当业务需要使用转码能力时调用，需要设置Transcoder_HandleAttr给转码通道
当转码属性中的hsrc为空时，现在版本返回错误
并且静音
param[in] Transcoder_HandleAttr pstAttr  设置转码通道的属性
param[out] HI_HANDLE* pHandle  		 建立的转码通道句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief  create transcoder function
attention 
transcoder create handle.must set Transcoder_HandleAttr attr,could call Transcoder_getDefaultAttr
when attr's property hsrc is NULL ,now version return failure
param[in] Transcoder_HandleAttr pstAttr  transcoder handle attr
param[out] HI_HANDLE* pHandle        create the handle of transcoder
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_Create(HI_HANDLE* pHandle,const Transcoder_HandleAttr *pstAttr);

/** 
brief 销毁转码通道
attention 
当业务需要关闭转码能力时调用，
需要注意此时的状态需要销毁所有的协议，虚拟驱动。
param[in] HI_HANDLE* pHandle  		 要销毁的转码通道句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief destroy transcoder handle
attention 
called this function,need destroy all protocol,
param[in] HI_HANDLE* pHandle         need destroy transcoder handle
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_Destroy(HI_HANDLE pHandle);
/** 
brief 获取转码能力属性
attention 
当业务需要获取转码能力属性
需要注意此接口需要在create函数调用后使用
param[in] HI_HANDLE* pHandle  		 欲设置的转码通道句柄
param[out] Transcoder_HandleAttr *pstAttr 获取的转码通道的属性
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief get the attr of transcoder handle
attention this function called after transcoder create handle function,
param[in] HI_HANDLE* pHandle         will get transcoder handle
param[out] Transcoder_HandleAttr *pstAttr transcoder handle attr
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_GetAttr(HI_HANDLE pHandle,Transcoder_Attr_ID_E eTranAttr,Transcoder_HandleAttr *pstAttr);
/** 
brief 设置转码能力属性
attention 
当业务需要设置转码能力属性
需要注意此接口需要在create函数调用后使用
param[in] HI_HANDLE* pHandle  		 欲设置的转码通道句柄
param[in] Transcoder_HandleAttr *pstAttr 设置转码通道的属性
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief set transcoder handle attr
attention 
need called after transcoder create function
param[in] HI_HANDLE* pHandle         the handle who need set attr
param[in] Transcoder_HandleAttr *pstAttr the attr will set to handle
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_SetAttr(HI_HANDLE pHandle,Transcoder_Attr_ID_E eTranAttr,const Transcoder_HandleAttr *pstAttr);
/** 
brief 获取转码使用资源情况
attention 
当业务需要获取转码资源情况
需要注意此接口需要在init函数调用后使用
param[in] HI_HANDLE* pHandle  		 欲设置的转码通道句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief get the resource info of transcoder module
attention 
this function called after transcoder initial function
param[in] HI_HANDLE pHandle         the handle
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_GetResourceInfo(HI_HANDLE pHandle);
/** 
brief 获取转码Debug 信息
attention 
当业务需要获取转码Debug 信息
需要注意此接口需要在init函数调用后使用
param[in] HI_HANDLE* pHandle  		 欲设置的转码通道句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief get the debug info of transcoder
attention 
this function called after transcoder handle init
param[in] HI_HANDLE pHandle         the handle of transcoder
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_GetDebugInfo(HI_HANDLE pHandle);
/********************************API declaration********************************/

/** 
brief 设置转码器状态机－－start
attention 
在转码器进入Stop-start状态接收该接口的状态机转换请求
param[in] HI_HANDLE hTranHandle  转码句柄
         [in] HI_BOOL bBlock  是否组赛
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief set transcoder handle status --- start
attention 
 when transcoder enter stop-start status machine ,after transcoder create handle
 
param[in] HI_HANDLE hTranHandle  transcoder handle
        [in] HI_BOOL bBlock  blocked called or not 
retval ::HI_SUCCESS success
     HI_FAILURE success
*/

HI_S32 HI_Transcoder_Start(HI_HANDLE hTranHandle,HI_BOOL bBlock);
/** 
brief 异步设置转码器状态机－－stop
attention 
在转码器进入Stop-start状态接收该接口的状态机转换请求
param[in] HI_HANDLE hTranHandle  转码句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief set transcoder handle status --- stop
attention 
 when transcoder enter stop-start status machine ,after transcoder create handle
 
param[in] HI_HANDLE hTranHandle  transcoder handle
        [in] HI_BOOL bBlock  blocked called or not 
retval ::HI_SUCCESS success
     HI_FAILURE success
*/
HI_S32 HI_Transcoder_Stop(HI_HANDLE hTranHandle,HI_BOOL bBlock);
/** 
brief 同步启动Transcoder模块的回调函数，其回调流程根据 Command不同而由
        用户指定不同的实现分支
attention 
在转码器进入Stop-start状态接收该接口的状态机转换请求
param[in] HI_HANDLE hTranHandle  转码句柄
               HI_U32 u32Command     转码回调的指令
               HI_VOID* pstAttr           指令的参数
               I_S32 s32AttrLen           指令参数的长度
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief sync called Transcoder module callback function,different because of command,
attention 
when transcoder enter stop-start status machine ,after transcoder create handle
param[in] HI_HANDLE hTranHandle  transcoder handle
               HI_U32 u32Command      transcoder callback command
               HI_VOID* pstAttr           callback attr 
               I_S32 s32AttrLen           callback attr len
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_SetCommand(HI_HANDLE hTranHandle,HI_U32 u32Command,HI_VOID* pstAttr,HI_S32 s32AttrLen);

/** 
brief 注册媒体数据读取句柄
attention 
注册媒体数据读出接口，该接口由protocol模块进行调用
param[in] HI_HANDLE hTranHandle Transcoder句柄
param[out]HI_HANDLE* phMbufReadHandle 媒体数据的读取句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief register media data read handle
attention 
register media data read handle,this function called by protocol and user
param[in] HI_HANDLE hTranHandle  transcoder handle
param[out]HI_HANDLE* phMbufReadHandle media data read handle
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_RegisterHandle(HI_HANDLE hTranHandle,HI_HANDLE* phMbufReadHandle);
/** 
brief 去注册媒体数据句柄
attention 
去注册MBUF写入接口，该接口由protocol模块进行调用
param[in]HI_HANDLE hMbufReadHandle 媒体数据的读取句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief unregister media data read handle
attention 
unregister media data read handle,this function called by protocol and user
param[in]HI_HANDLE hMbufReadHandle media data read handle
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Transcoder_DeRegisterHandle(HI_HANDLE hMbufReadHandle);
/** 
brief 读取媒体数据
attention 
读取的数据可能无法读出，此时返回HI_FAILURE

param[in] HI_HANDLE hReadHandle MBUF的读取句柄
param[out]TRANSCODER_FRAME* pstTranFrame 从MBUF中读取的数据帧结构
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief 读取媒体数据
attention 
读取的数据可能由于MBUF数据为空，无法读出，此时返回HI_FAILURE

param[in] HI_HANDLE hReadHandle MBUF的读取句柄
param[out]TRANSCODER_FRAME* pstTranFrame 从MBUF中读取的数据帧结构
retval ::HI_SUCCESS 成功
     HI_FAILURE 失败
*/
HI_S32 HI_Transcoder_ReadStream(HI_HANDLE hReadHandle,TRANSCODER_STRAM* pstTranFrame);
/** 
brief 读取媒体数据
attention 
读取的数据可能由于MBUF数据为空，无法读出，此时返回HI_FAILURE

param[in] HI_HANDLE hReadHandle MBUF的读取句柄
param[out]TRANSCODER_FRAME* pstTranFrame 从MBUF中读取的数据帧结构
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
HI_VOID Transcoder_getDefaultAttr(Transcoder_HandleAttr* stTranHandleAttr);

#ifdef __cplusplus
}
#endif


#endif
