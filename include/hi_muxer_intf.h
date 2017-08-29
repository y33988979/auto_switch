#ifndef __HI_MUXER_INTF_H__
#define __HI_MUXER_INTF_H__

#include "hi_type.h"
#include "hi_muxer.h"

#define FLV_DEFAULT_MUXER "flv_default"
#define RTP_DEFAULT_MUXER "rtp_default"
#define TS_DEFAULT_MUXER  "ts_default"
#define HIES_DEFAULT_MUXER  "hies_default"
#define MAX_DLLNAME_LEN 100

typedef struct tagHI_MuxerInfo_S
{
    const HI_PCHAR szName;
    const HI_U32 enMuxerType;
    const HI_PCHAR pszDescription;
    HI_CHAR szDllName[MAX_DLLNAME_LEN];
    HI_VOID  * pDllModule;
    HI_S32 (*MuxerCreate)(HI_HANDLE* hMuxerHandle,HI_U32 muxerType,Transcoder_MuxerAttr* muxerAttr);
    HI_S32 (*MuxerDestroy)(HI_HANDLE phHandle);
    HI_S32 (*MuxerGetHeader)(HI_HANDLE hMuxerHandle,HI_CHAR* pTAGFrame,HI_S32* ps32Len);
    HI_S32 (*DoMuxer)(HI_HANDLE hMuxerHandle,HI_CHAR* pTAGFrame,HI_S32* ps32Len,TRANSCODER_STRAM* pstTranFrame);
    HI_S32 (*setPrivate)(HI_HANDLE hMuxerHandle,HI_VOID* stAttr,HI_S32 s32Len);
    struct tagHI_MuxerInfo_S* next;                              /*转码通道的链表*/
}HI_MuxerInfo_S;


#endif

