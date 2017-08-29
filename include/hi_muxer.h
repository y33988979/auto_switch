#ifndef __HI_MUXER_H__
#define __HI_MUXER_H__

#include "hi_type.h"
#include "hi_transcoder.h"
//#include "hi_tran_mbuf.h"

#ifdef __cplusplus
extern "C"{
#endif


#define TRANSCODER_MUXER_MEM_MAX (16)

/*********************************************
	转码模块转码文件封装类型
**********************************************/
    
/*********************************************
       transcoder muxer file type
**********************************************/
typedef enum eTran_Muxerype
{
    TRANSCODER_MUTEX_FLV = 1,
    TRANSCODER_MUTEX_TS = 2,
    TRANSCODER_MUTEX_RTP = 4,
    TRANSCODER_MUTEX_ES = 8,
    TRANSCODER_MUTEX_HIES = 16,
    TRANSCODER_MUTEX_BUTT,
}Transcoder_MuxerType;

/*********************************************
	转码模块转码文件封装输入参数
**********************************************/
/*********************************************
       transcoder muxer create attr
**********************************************/
typedef struct tagTran_MuxerAttr
{
    Transcoder_MediaCodec audioCodec;		/*音频CodecID*/
    Transcoder_MediaCodec videoCodec;		/*视频CodecID*/
    HI_S32 s32Width;				/*视频分辨率--高*/
    HI_S32 s32Height; 				/*视频分辨率--宽*/
    HI_S32 s32VideoBitRate;				/*视频比特率*/
    HI_S32 s32VideoFrameRate;			/*视频帧率*/
    HI_S32 s32AudioSampleRate;			/*音频采样率*/
    HI_S32 s32AudioBandWidth;			/*音频采样宽度*/
    HI_S32 s32AudioChannels;            /*音频采样的声道数量*/
}Transcoder_MuxerAttr;

/** 
brief muxer模块初始化
attention 
param[in] NULL
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief muxer module initialization function
attention 
param[in] NULL
retval ::HI_SUCCESS    success
     HI_FAILURE    failure
*/
HI_S32 HI_Muxer_Init();
/** 
brief muxer模块去初始化
attention 
param[in] NULL
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief muxer module uninitialization function
attention 
param[in] NULL
retval ::HI_SUCCESS    success
     HI_FAILURE    failure
*/
HI_S32 HI_Muxer_DeInit();
/** 
brief muxer模块创建句柄
attention 此接口由protocol调用，用来生成一个muxer的接口
param[in] HI_U32 muxerType muxer的类型
param[OUT] HI_HANDLE* hMuxerHandle    生成的muxer的句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief muxer  create handle function 
attention this function called by user and protocol，create a new muxer handle
param[in] HI_U32 muxerType muxer type
param[OUT] HI_HANDLE* hMuxerHandle    create muxer handle
retval ::HI_SUCCESS      success
           HI_FAILURE       failure
*/
HI_S32 HI_Muxer_Create(HI_HANDLE* hMuxerHandle,HI_U32 muxerType,Transcoder_MuxerAttr* muxerAttr);
/** 
brief muxer模块销毁句柄
attention 此接口由protocol调用，用来销毁一个muxer的接口
param[in] HI_HANDLE hMuxerHandle muxer的句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief muxer  destroy handle function 
attention this function called by user and protocol，destroy a new muxer handle
param[in] HI_HANDLE hMuxerHandle muxer handle
retval ::HI_SUCCESS      success
           HI_FAILURE       failure
*/
HI_S32 HI_Muxer_Destroy(HI_HANDLE hMuxerHandle);
/** 
brief muxer模块获取头数据
attention 此接口由protocol调用，用来获取第一个头数据，或特征帧
param[in] HI_HANDLE hMuxerHandle   muxer的句柄
param[OUT] HI_CHAR* pTAGFrame   TAG的数据缓冲位置
[IN/OUT]          HI_S32* ps32Len   普通 TAG数据的缓冲区长度(IN)
                                                  Muxer之后的数据包长度(OUT)
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/

/** 
brief muxer  get file header
attention this function called by user and protocol,get the file header or special frame
param[in] HI_HANDLE hMuxerHandle  muxer  handle
param[OUT] HI_CHAR* pTAGFrame   TAG buffer address
[IN/OUT]          HI_S32* ps32Len   TAG buffer initial len(IN)
                                                  after muxer buffer len(OUT)
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
HI_S32 HI_Muxer_GetHeader(HI_HANDLE hMuxerHandle,HI_CHAR* pTAGFrame,HI_S32* ps32Len);
/** 
brief muxer模块获取普通数据
attention 此接口由protocol调用，用来获取一个封装的普通 TAG数据
param[in] HI_U32 muxerType muxer的类型
                TRANSCODER_STRAM* pstTranFrame 从Transcoder中读取的数据帧
param[OUT] HI_CHAR* pTAGFrame  生成的普通的TAG数据
         [IN/OUT]          HI_S32* ps32Len   普通 TAG数据的缓冲区长度(IN)
                                                           Muxer之后的数据包长度
                   
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief muxer get normal frame
attention this function called by user and protocol,muxer a ES frame to a Muxer TAG
param[in] HI_U32 muxerType muxer  type
    TRANSCODER_STRAM* pstTranFrame  ES stream get from Transcoder
param[OUT] HI_CHAR* pTAGFrame  create TAG Frame
     [OUT/IN]   HI_S32* ps32Len     TAG buffer init len[in] / TAG buffer used len[OUT]
       
retval ::HI_SUCCESS  success
HI_FAILURE failure
*/
HI_S32 HI_Muxer_DoMuxer(HI_HANDLE hMuxerHandle,HI_CHAR* pTAGFrame,HI_S32* ps32Len,TRANSCODER_STRAM* pstTranFrame);
/** 
brief muxer模块设置私有属性
attention 此接口由protocol调用，用来设置一个muxer的私有属性
param[in] HI_HANDLE hMuxerHandle muxer模块的句柄
                HI_VOID* stAttr 设置的私有参数
                HI_S32 s32Len 私有参数的长度
                   
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief muxer set private attr
attention this function called by user and protocol,to set muxer private attr
param[in] HI_HANDLE hMuxerHandle muxer  handle
            HI_VOID* stAttr  private attr defined by protocol specific module
            HI_S32 s32Len   the private attr data len
               
retval ::HI_SUCCESS  success
 HI_FAILURE failure
*/
HI_S32 HI_Muxer_SetPrivateData(HI_HANDLE hMuxerHandle,HI_VOID* stAttr,HI_S32 s32Len);

/** 
brief Muxer 注册外部协议函数
attention :此函数需在HI_Muxer_Init后才能调用
param[in] HI_CHAR* pLibMuxerName 要注册的库名称
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief Muxer register external muxer lib 
attention :called after HI_Muxer_Init
param[in] HI_CHAR* pLibMuxerName the name of external muxer lib
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Muxer_RegistMuxer(const HI_CHAR* pLibMuxerName);
/** 
brief Muxer 去注册外部协议函数
attention :此函数需在HI_Muxer_Init后才能调用
param[in] HI_CHAR* pLibMuxerName 要去注册的库名称
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief Muxer  unregister external muxer lib 
attention :called after HI_Muxer_Init
param[in] HI_CHAR* pLibMuxerName the name of external muxer lib would unregiste
retval ::HI_SUCCESS success
     HI_FAILURE failure
*/
HI_S32 HI_Muxer_DeRegistMuxer(const HI_CHAR* pLibMuxerName);
#ifdef __cplusplus
}
#endif


#endif
