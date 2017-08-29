
/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name             :   mpi_vdec.h
  Version               :   Initial Draft
  Author                :   Hisilicon multimedia software group
  Created               :   2006/06/12
  Last Modified         :
  Description           :
  Function List         :
  History               :
  1.Date                :   2006/06/12
    Author              :
Modification            :   Created file
******************************************************************************/

#ifndef  __MPI_VDEC_H__
#define  __MPI_VDEC_H__

#include "hi_unf_avplay.h"
#include "mpi_priv_vdec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */


typedef struct hiVDEC_ES_BUF_S
{
    HI_U8  *addr;      /*Virtual address of the buffer user.*/
    HI_U32  bufsize;   /*Buffer size, in the unit of byte.*/
    HI_U64  pts;       /*PTS of the data filled in a buffer.*/
}VDEC_ES_BUF_S, *PTR_VDEC_ES_BUF_S;

typedef struct hiVDEC_STATUSINFO_S
{
    HI_U32  BufferSize;        /*Total buffer size, in the unit of byte.*/
    HI_U32  BufferAvailable;   /*Available buffer, in the unit of byte.*/
    HI_U32  BufferUsed;        /*Used buffer, in the unit of byte.*/
    HI_U32  VfmwFrmSize;       /**/
    HI_U32  VfmwStrmSize;
    HI_U32  StrmInBps;
    HI_U32  TotalDecFrameNum;
    HI_U32  TotalErrorFrameNum;
    HI_U32  TotalErrorStreamNum;
    HI_U32  u32FrameBufNum;    /* frame num in buffer to display */
    HI_BOOL bEndOfStream;      /* There's no enough stream in buffer to decode a frame */
}VDEC_STATUSINFO_S;

typedef struct hiVDEC_DEBUGINFO_S
{
	HI_BOOL   enable;              /*Enable status.*/
	HI_UNF_VCODEC_TYPE_E  type;     /*Decoding protocol.*/
    HI_U32    VdecThreadState;	   /*Status of a decoding thread.*/

    /*video frame buffer status*/
	HI_U32    FrameQueueSize;      /*Size of a decoding frame queue.*/
    HI_U32    CurrentQueueFrameNum;/*Current unread decoding frame.*/

    /*video stream buffer status*/
    HI_U32    BufferSize;          /*Stream buffer size.*/
	HI_U32    BufferUsed;          /*Used stream buffer size.*/

    HI_U32 err_num;                /*Total number of decoding errors.*/

	HI_U32 total_bits;             /*Total bits of decoded streams, in the unit of KBit.*/
	HI_U32 total_frame;            /*Total number of decoded frames.*/
	HI_U32 total_time;             /*Total decoding time, in the unit of millisecond.*/
	HI_U32 average_bps;            /*Average bit rate, in the unit of kbit/s.*/
	HI_U32 average_fps_integer;    /*Integer part of the average frame rate, in the unit of frame/s.*/
	HI_U32 average_fps_decimal;    /*Decimal part of the average frame rate, in the unit of frame/s.*/
}VDEC_DEBUGINFO_S, *PTR_VDEC_DEBUGINFO_S;

typedef enum hiVDEC_SUB_STANDARD_E
{
	VDEC_NOT_SUB_STANDARD,
	VDEC_MPEG2_SUB_MPEG1,
	VDEC_MPEG4_SUB_SHV,
	VDEC_MPEG4_XVID,
	VDEC_MPEG4_DIVX,
	VDEC_SUB_STANDARD_BUTT
}VDEC_SUB_STANDARD_E;

typedef struct hiVDEC_FRAME_BUF_S
{
	HI_U32 u32PhyAddr;
	HI_U32 u32Size;
}VDEC_FRAME_BUF_S;

typedef enum hiVDEC_COLOR_FMT_E
{
	VDEC_COLOR_FMT_400,       /*YUV400*/
	VDEC_COLOR_FMT_420,       /*YUV420*/
	VDEC_COLOR_FMT_422_2x1,   /*YUV 422 2x1*/  
	VDEC_COLOR_FMT_422_1x2,   /*YUV 422 1x2*/  
	VDEC_COLOR_FMT_444,       /*YUV 444*/  
	VDEC_COLOR_FMT_BUTT       /*unsupported format*/	
}VDEC_COLOR_FMT_E;

typedef struct hiVDEC_USR_FRAME_S
{
	HI_BOOL             bFrameValid;      
    VDEC_COLOR_FMT_E    enFmt;            /* Color format */
    HI_U32              Pts;
    HI_BOOL             bSemiPlanar;
    HI_S32              s32YWidth;
    HI_S32              s32YHeight;
    HI_S32              s32LumaPhyAddr;  
    HI_S32              s32LumaStride;
    HI_S32              s32CbPhyAddr;    /* ChromePhyAddr if bSemiPlanar is true;CbPhyAddr if bSemiPlanar is false */
    HI_S32              s32CrPhyAddr;    /* invalid if bSemiPlanar is true; CrPhyAddr if bSemiPlanar is false */
    HI_S32              S32ChromStride;  
} VDEC_USR_FRAME_S;

HI_S32 HI_MPI_VDEC_Init(HI_VOID);
HI_S32 HI_MPI_VDEC_deInit(HI_VOID);
HI_S32 HI_MPI_VDEC_Reset(HI_VOID);
HI_S32 HI_MPI_VDEC_AllocChan(HI_HANDLE *piHandle, HI_UNF_AVPLAY_OPEN_OPT_S *pstMaxCapbility);
HI_S32 HI_MPI_VDEC_freeChan(HI_HANDLE hVdec);
HI_S32 HI_MPI_VDEC_SetChanAttr(HI_HANDLE hVdec, const HI_UNF_VCODEC_ATTR_S *pAttr);
HI_S32 HI_MPI_VDEC_GetChanAttr(HI_HANDLE hVdec, HI_UNF_VCODEC_ATTR_S *pAttr);
HI_S32 HI_MPI_VDEC_SetChanAdvAttr(HI_HANDLE hVdec, HI_UNF_VCODEC_ADV_ATTR_S *pAttr);
HI_S32 HI_MPI_VDEC_GetChanAdvAttr(HI_HANDLE hVdec, HI_UNF_VCODEC_ADV_ATTR_S *pAttr);
HI_S32 HI_MPI_VDEC_ChanBufferInit(HI_HANDLE hVdec, HI_U32 u32BufSize, HI_HANDLE hDmxVidChn);
HI_S32 HI_MPI_VDEC_ChanBufferDeInit(HI_HANDLE hVdec);
HI_S32 HI_MPI_VDEC_ResetChan(HI_HANDLE hVdec);
HI_S32 HI_MPI_VDEC_ChanStart(HI_HANDLE hVdec);
HI_S32 HI_MPI_VDEC_ChanStop(HI_HANDLE hVdec);
HI_S32 HI_MPI_VDEC_ChanGetBuffer(HI_HANDLE hVdec, HI_U32 RequestSize, VDEC_ES_BUF_S *pBuf);
HI_S32 HI_MPI_VDEC_ChanPutBuffer(HI_HANDLE hVdec, VDEC_ES_BUF_S *pBuf);
HI_S32 HI_MPI_VDEC_ChanRecvFrm(HI_HANDLE hVdec, HI_UNF_VO_FRAMEINFO_S* pFrameinfo);
HI_S32 HI_MPI_VDEC_ChanRlsFrm(HI_HANDLE hVdec, HI_UNF_VO_FRAMEINFO_S* pFrameinfo);
HI_S32 HI_MPI_VDEC_ChanRcvBuffer(HI_HANDLE hVdec, VDEC_ES_BUF_S *pBuf);
HI_S32 HI_MPI_VDEC_ChanRlsBuffer(HI_HANDLE hVdec, VDEC_ES_BUF_S *pBuf);
HI_S32 HI_MPI_VDEC_ChanGetFrame(HI_HANDLE hVdec, VDEC_FRAME_BUF_S *pFrameBuf);
HI_S32 HI_MPI_VDEC_ChanPutFrame(HI_HANDLE hVdec, VDEC_USR_FRAME_S *pFrameInfo);
HI_S32 HI_MPI_VDEC_ChanIFrameDecode(HI_HANDLE hVdec,const HI_UNF_AVPLAY_I_FRAME_S *pIFrame,HI_UNF_VO_FRAMEINFO_S *pVoFrameInfo);
HI_S32 HI_MPI_VDEC_GetChanStatusInfo(HI_HANDLE hVdec,  VDEC_STATUSINFO_S *pStatusinfo);
HI_S32 HI_MPI_VDEC_GetChanDebugInfo(HI_HANDLE hVdec,  VDEC_DEBUGINFO_S *pDebuginfo);
HI_S32 HI_MPI_VDEC_GetChanStreamInfo(HI_HANDLE hVdec,  HI_UNF_VCODEC_STREAMINFO_S *pStreaminfo);
HI_S32 HI_MPI_VDEC_PeekBuffSize(HI_HANDLE hVdec, HI_U32 bufSize);

HI_S32 HI_MPI_VDEC_CheckNewEvent(HI_HANDLE hVdec, VDEC_CMD_EVENT_S *pNewEvent);
HI_S32 HI_MPI_VDEC_ReadNewFrame(HI_HANDLE hVdec, HI_UNF_VO_FRAMEINFO_S *pNewFrame);
HI_S32 HI_MPI_VDEC_ReadNewSeq(HI_HANDLE hVdec, HI_UNF_VIDEO_SEQUENCE_INFO_S *pSeqInfo);
HI_S32 HI_MPI_VDEC_ChanRecvUsrData(HI_HANDLE hVdec, HI_UNF_VIDEO_USERDATA_S *pUsrData);

HI_S32 HI_MPI_VDEC_SetChanFrmRate(HI_HANDLE hVdec, HI_UNF_VCODEC_FRMRATE_S *pFrmRate);
HI_S32 HI_MPI_VDEC_GetChanFrmRate(HI_HANDLE hVdec, HI_UNF_VCODEC_FRMRATE_S *pFrmRate);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif//__MPI_AO_H__




