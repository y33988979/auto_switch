#ifndef __HI_PROTO_INTF_H__
#define __HI_PROTO_INTF_H__

#include "hi_type.h"
#include "hi_protocol.h"
#include "hi_muxer.h"

#define RTSP_DEFAULT_PROTOCOL "rtsp_default"
#define HTTP_DEFAULT_PROTOCOL "http_default"
typedef struct tagHI_ProtocolInfo_S
{
    const HI_PCHAR szName;
    const HI_U32 enProtocolType;
    const HI_PCHAR pszDescription;
    HI_VOID  * pDllModule;
    HI_S32 (*ProtocolCreate)(HI_HANDLE* hProtocolHandle,const ProtocolAttr* pstTranAttr);
    HI_S32 (*ProtocolDestroy)(HI_HANDLE hProtocolHandle);
    HI_S32 (*ProtocolRegist)(HI_HANDLE pProtocolHandle,HI_HANDLE hTranHandle);
    HI_S32 (*ProtocolDeRegist)(HI_HANDLE pProtocolHandle,HI_HANDLE hTranHandle);
    struct tagHI_ProtocolInfo_S* next;                              /*转码通道的链表*/
}HI_ProtocolInfo_S;

#define MAX_IP_LEN 64

HI_S32 HI_Protocol_GetInstance(HI_HANDLE hProtocolHandle,HI_HANDLE* pInstanceHandle);


typedef HI_S32 HI_SOCKET;
typedef HI_CHAR HI_IP_ADDR[MAX_IP_LEN];
typedef HI_U16  HI_PORT;

#endif

