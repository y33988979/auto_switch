/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : mpi_priv_vdec.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2006/05/17
  Description   : 
  History       :
  1.Date        : 2006/05/17
    Author      : g45345
    Modification: Created file

******************************************************************************/
#ifndef __MPI_PRIV_VDEC_H__
#define __MPI_PRIV_VDEC_H__

#include "hi_unf_common.h"
#include "hi_unf_avplay.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

#define VDEC_CHAN_MAX_NUM      17

#define I_FRAME_STREAM_SIZE 0x32000
#define I_FRAME_STREAM_TAIL 12

#define VDEC_IOCTL(fd...)   ioctl(fd)

typedef struct hiVDEC_CMD_EVENT_S
{
    HI_U32   handle; /* inner use, Don't care */
    
    HI_BOOL  bNewFrame;
    HI_BOOL  bNewSeq;
    HI_BOOL  bNewUserData;
    
    HI_BOOL  bNormChange;
    HI_UNF_NORMCHANGE_PARAM_S stNormChangeParam;

    HI_BOOL  bFramePackingChange;
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E enFramePackingType;
} VDEC_CMD_EVENT_S;

typedef struct hiVIDEO_FRAME_RATE_S
{
	HI_U32  FrameRateInteger;         /*integer part of frame rate*/
	HI_U32  FrameRateDecimal;         /*demical part of frame rate*/
}VIDEO_FRAME_RATE_S;

typedef struct hiVIDEO_RESOLUTION_S
{
	HI_U32  DisplayWidth;             /*Display width.*/
	HI_U32  DisplayHeight;            /*Display height.*/
	HI_U32  DisplayCenterX;           /*Horizontal coordinate of the display image center (the left upper point of the original image is the coordinate origin).*/
	HI_U32  DisplayCenterY;           /*Vertical coordinate of the display image center (the upper left point of the original image is the coordinate origin).*/
}VIDEO_RESOLUTION_S;

typedef struct hiVDEC_IFRAME_DEC_S
{
    HI_HANDLE                 hVdec;
    HI_UNF_AVPLAY_I_FRAME_S   stIFrame;
    HI_UNF_VO_FRAMEINFO_S     stVoFrameInfo;
}VDEC_IFRAME_DEC_S;

#if 1
#define VDEC_LOCK_DECLARE(p_mutex);                 \
	    static pthread_mutex_t p_mutex = PTHREAD_MUTEX_INITIALIZER;

#define VDEC_LOCK_DESTROY(p_mutex)                  \
        (void)pthread_mutex_destroy(p_mutex)

#define VDEC_LOCK(p_mutex)                          \
        (void)pthread_mutex_lock(p_mutex)

#define VDEC_UNLOCK(p_mutex)                        \
        (void)pthread_mutex_unlock(p_mutex)
#else
#define VDEC_LOCK_DECLARE(p_mutex);

#define VDEC_LOCK_DESTROY(p_mutex)

#define VDEC_LOCK(p_mutex)

#define VDEC_UNLOCK(p_mutex)

#endif



#define UMAPC_VDEC_RESET                _IO  (HI_ID_VDEC,101)
#define UMAPC_VDEC_SETATTR              _IOW (HI_ID_VDEC,102, HI_UNF_VCODEC_ATTR_S)
#define UMAPC_VDEC_GETATTR              _IOR (HI_ID_VDEC,103, HI_UNF_VCODEC_ATTR_S)
#define UMAPC_VDEC_BUFATTACH            _IOW (HI_ID_VDEC,104, HI_MMZ_BUF_S)
#define UMAPC_VDEC_BUFDETACH            _IO  (HI_ID_VDEC,105)
#define UMAPC_VDEC_BUFRESET             _IO  (HI_ID_VDEC,106)
#define UMAPC_VDEC_GETBUF               _IOWR(HI_ID_VDEC,107, VDEC_ES_BUF_S)
#define UMAPC_VDEC_PUTBUF               _IOW (HI_ID_VDEC,108, VDEC_ES_BUF_S)
#define UMAPC_VDEC_RECEIVE              _IOWR(HI_ID_VDEC,109, HI_UNF_VO_FRAMEINFO_S)
#define UMAPC_VDEC_RELEASE              _IOW (HI_ID_VDEC,110, HI_UNF_VO_FRAMEINFO_S)
#define UMAPC_VDEC_USRDATA              _IOWR(HI_ID_VDEC,111, HI_UNF_VIDEO_USERDATA_S)
#define UMAPC_VDEC_IFRAMEDECODE         _IOWR(HI_ID_VDEC,116, VDEC_IFRAME_DEC_S)



/*the following are several common function-check macro*/
/*CNcomment: 以下是几个常用的功能检测宏*/
#define CHECK_VDEC_OPEN_STATE(p_mutex)       \
    do                                       \
    {                                        \
        if (vdec_fd == -1)                   \
        {                                    \
            HI_ERR_VDEC("%s:Video device not open!\n", __FUNCTION__);\
            VDEC_UNLOCK(p_mutex);            \
            return  HI_FAILURE;          \
        }                                    \
    }while(0)



#define HI_FATAL_VDEC(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_FATAL, HI_DEBUG_ID_VDEC, fmt)

#define HI_ERR_VDEC(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_ERROR, HI_DEBUG_ID_VDEC, fmt)

#define HI_WARN_VDEC(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_WARNING, HI_DEBUG_ID_VDEC, fmt)

#define HI_INFO_VDEC(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_INFO, HI_DEBUG_ID_VDEC, fmt)


HI_S32 VDEC_Chan_FrmBufGetReadBuf(HI_S32 handle,  HI_UNF_VO_FRAMEINFO_S  *ptVidFrm);
HI_S32 VDEC_Chan_FrmBufPutReadBuf(HI_S32 handle,  HI_UNF_VO_FRAMEINFO_S  *ptVidFrm);
HI_S32 VDEC_Chan_FrmBufRlsReadBuf(HI_S32 handle, HI_UNF_VO_FRAMEINFO_S *ptVidFrm);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __MPI_PRIV_VDEC_H__ */


