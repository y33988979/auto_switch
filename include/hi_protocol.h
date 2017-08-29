#ifndef __HI_PROTOCOL_H__
#define __HI_PROTOCOL_H__

#include "hi_type.h"

#ifdef __cplusplus
extern "C"{
#endif

/***********enum**************/
#define TRANSCODER_PROTOCOL_MEM_MAX     (16)
/*****************************************
	transcoder module status machine enum
******************************************/
/*****************************************
	转码模块协议状态机
******************************************/
typedef enum eTran_ProtocolStatus
{
	TRANSCODER_PROTOCOL_INIT = 0,
	TRANSCODER_PROTOCOL_STOP,
	TRANSCODER_PROTOCOL_START,
	TRANSCODER_PROTOCOL_STATUS_BUTT,
}Transcoder_ProtocolStatus;

typedef enum eWFD_External_Method
{
    WFD_SOURCE_METHOD_INIT = 0,
    WFD_SOURCE_METHOD_RESET = 1,
    WFD_SOURCE_METHOD_SEEK = 2,
    WFD_SOURCE_METHOD_CHANGE = 3,
    WFD_SOURCE_METHOD_BUTT,
}WFD_External_Method_E;

/****************************************************
	转码模块转码协议服务器类型
*****************************************************/
/****************************************************
        transcoder module protocol server type
*****************************************************/
typedef enum eTran_ProtocolType
{
    TRANSCODER_PROTOCOL_HTTP = 1,
    TRANSCODER_PROTOCOL_RTSP = 2,
    TRANSCODER_PROTOCOL_VTRL_DRV = 4,
    TRANSCODER_PROTOCOL_FAST_STREAM = 8,
    TRANSCODER_PROTOCOL_SAMPLE = 16,
    TRANSCODER_PROTOCOL_BUTT,
}Transcoder_ProtocolType;

#define TRANSCODER_COMMAND_BASE 0xA0000000
/****************************************************
	转码模块Protocol 向主模块提交的命令集合
*****************************************************/
/****************************************************
     Protocol send Command to Transcoder type 
*****************************************************/
typedef enum eProto_CallBackCommand
{
    PROTOCOL_COMMAND_PAUSE = TRANSCODER_COMMAND_BASE + 1,
    PROTOCOL_COMMAND_SEEK = TRANSCODER_COMMAND_BASE + 2,
    PROTOCOL_COMMAND_SETATTR = TRANSCODER_COMMAND_BASE + 3,
    PROTOCOL_COMMAND_SETSOURCE = TRANSCODER_COMMAND_BASE + 4,
    PROTOCOL_COMMAND_SETMUTE = TRANSCODER_COMMAND_BASE + 5,
}Protocol_CallBackCommand;
/****************************************************
	转码模块转码协议服务器打开参数
*****************************************************/
/****************************************************
      Protocol create handle Protocol Attr
*****************************************************/
typedef struct tagProtocolAttr
{
    HI_S32 s32Port;             /*协议的端口*/
    HI_U32 u32ProtocolType;     /*协议的类型*/
    HI_HANDLE SourceHandle;     /*协议数据来源*/
    HI_S32 s32UserNum;          /*协议支持的用户数量*/
}ProtocolAttr;


/** 
brief Protocol模块初始化
attention 
param[in] NULL
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
    
/** 
brief Protocol  initialization function
attention 
param[in] NULL
retval ::HI_SUCCESS     success
HI_FAILURE   failure
*/
HI_S32 HI_Protocol_Init();
/** 
brief Protocol模块去初始化
attention 
param[in] NULL
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/

/** 
brief Protocol uninitialization function
attention 
param[in] NULL
retval ::HI_SUCCESS    success
	 HI_FAILURE         failure
*/
HI_S32 HI_Protocol_DeInit();
/** 
brief Protocol模块生成Protocol句柄
attention 此接口由用户调用，和Transcoder没有必然的先后顺序
param[in] ProtocolAttr* pstTranAttr 设置的Protocol的属性
param[out] HI_HANDLE* hProtocolHandle 生成的Protocol句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief Protocol  module create Protocol handle
attention this function called by user, not have relationship with transcoder
param[in] ProtocolAttr* pstTranAttr  protocol create attr
param[out] HI_HANDLE* hProtocolHandle creative protocol handle
retval ::HI_SUCCESS  success
HI_FAILURE failure
*/
HI_S32 HI_Protocol_Create(HI_HANDLE* hProtocolHandle,const ProtocolAttr* pstTranAttr);
/** 
brief Protocol  module destroy protocol handle
attention  this function called by user, not have relationship with transcoder
param[in] HI_HANDLE hProtocolHandle need destory protocol  handle
retval ::HI_SUCCESS success
	 HI_FAILURE failure
*/
HI_S32 HI_Protocol_destory(HI_HANDLE hProtocolHandle);
/** 
brief Protocol注册函数
attention :此函数需在Transcoder_create后才能调用,当用户的输入源发生较大变化，需要先调用HI_Protocol_UnRegistHandle，
	  然后调用本函数，例如：播放本地文件时，本地文件播放完成，又从头播放的情况，或者dvb出现换台的情况。
param[in] HI_HANDLE hTranHandle 要绑定的Transcoder的句柄
                HI_HANDLE pProtocolHandle 要帮定的Protocol句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/

/** 
brief Protocol regist handle function
attention :this function called by user, must after called after transcoder create function
	   when the source of HiTranscoder happens large change,need called HI_Protocol_UnRegistHandle then this
	   function,for example:when play local file,happens rewind,need play from begin,or dvb change channel.
param[in] HI_HANDLE hTranHandle  need regist Transcoder handle
                HI_HANDLE pProtocolHandle need regist Protocol handle
retval ::HI_SUCCESS   success
	 HI_FAILURE       failure
*/
HI_S32 HI_Protocol_RegistHandle(HI_HANDLE pProtocolHandle,HI_HANDLE hTranHandle);
/** 
brief Protocol去注册函数
attention :此函数需在Transcoder_create后才能调用,当用户的输入源发生较大变化，需要先调用本函数
	   例如：播放本地文件时，本地文件播放完成，又从头播放的情况，或者dvb出现换台的情况。
param[in] HI_HANDLE hTranHandle 要去绑定的Transcoder的句柄
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief Protocol unregist handle function
attention :this function called by user, must after called after transcoder create function,
	   when the source of HiTranscoder happens large change,need called this function
	   for example:when play local file,happens rewind,need play from begin,or dvb change channel.
param[in] HI_HANDLE hTranHandle  need unregist Transcoder handle
              HI_HANDLE pProtocolHandle need unregist Protocol handle
retval ::HI_SUCCESS   success
            HI_FAILURE       failure
*/
HI_S32 HI_Protocol_UnRegistHandle(HI_HANDLE pProtocolHandle,HI_HANDLE hTranHandle);

/** 
brief Protocol 注册外部协议函数
attention :此函数需在HI_Protocol_Init后才能调用
param[in] HI_CHAR* pLibProtocolName 要注册的库名称
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief Protocol regist external protocol server
attention :this function called by user, must after called after protocol init function
param[in] HI_CHAR* pLibProtocolName  need regist external .so name
retval ::HI_SUCCESS   success
            HI_FAILURE       failure
*/
HI_S32 HI_Protocol_RegistProtocol(const HI_CHAR* pLibProtocolName);

/** 
brief Protocol 去注册外部协议函数
attention :此函数需在HI_Protocol_Init后才能调用
param[in] HI_CHAR* pLibProtocolName 要去注册的库名称
retval ::HI_SUCCESS 成功
	 HI_FAILURE 失败
*/
/** 
brief Protocol unregist external protocol server
attention :this function called by user, must after called after protocol init function
param[in] HI_CHAR* pLibProtocolName  need unregist external .so name
retval ::HI_SUCCESS   success
            HI_FAILURE       failure
*/
HI_S32 HI_Protocol_DeRegistProtocol(const HI_CHAR* pLibProtocolName);

HI_S32 HI_Protocol_WFD_SetClientCommand(HI_HANDLE hProtocolHandle,HI_U32 u32Command,HI_BOOL bBufferFlag);

#ifdef __cplusplus
}
#endif


#endif
