/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_sio.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       :
  Description   :
  History       :
  1.Date        :
    Author      :
    Modification: Created file

 *******************************************************************************/
#ifndef  __HI_UNF_SIO_H__
#define  __HI_UNF_SIO_H__

#include "hi_type.h"
#include "hi_unf_common.h"
#include "hi_debug.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

typedef HI_S32 AI_CHN;
typedef HI_S32 AO_CHN;
typedef HI_S32 AENC_CHN;
typedef HI_S32 ADEC_CHN;
typedef HI_S32 AUDIO_DEV;
typedef HI_S32 AVENC_CHN;

#define HI_IO_BLOCK 0
#define HI_IO_NOBLOCK 1

#if  defined (CHIP_TYPE_hi3720)
#define SIO_MAX_NUM 3
#elif  defined (CHIP_TYPE_hi3716c) || defined (CHIP_TYPE_hi3716h) || defined (CHIP_TYPE_hi3716m)
#define SIO_MAX_NUM 1
#elif  defined (CHIP_TYPE_hi3716mv300_fpga)
#define SIO_MAX_NUM 1 
#else
#error you must define CHIP_TYPE
#endif

#define AIO_MAX_CHN_NUM 16

#define HI_MPI_AI_CHN AI_CHN
#define HI_MPI_AO_CHN AO_CHN

#define HI_MPI_AUDIO_DEV AUDIO_DEV
#define HI_MPI_AEC_FRAME_S AEC_FRAME_S
#define HI_MPI_AUDIO_FRAME_S HI_UNF_AO_FRAMEINFO_S
#define HI_MPI_AIO_ATTR_S AIO_ATTR_S

#define MAX_AUDIO_FRAME_NUM 50       /*max count of audio frame in Buffer */
#define MAX_AUDIO_POINT_BYTES 4        /*max bytes of one sample point(now 32bit max)*/

#define MAX_VOICE_POINT_NUM 480      /*max sample per frame for voice encode */

#define MAX_AUDIO_POINT_NUM 2048     /*max sample per frame for all encoder(aacplus:2048)*/
#define MIN_AUDIO_POINT_NUM 80       /*min sample per frame*/

/*max length of audio frame by bytes, one frame contain many sample point */
#define MAX_AUDIO_FRAME_LEN (MAX_AUDIO_POINT_BYTES * MAX_AUDIO_POINT_NUM)

/*max length of audio stream by bytes */
#define MAX_AUDIO_STREAM_LEN MAX_AUDIO_FRAME_LEN

#define AI_EXPAND 0x01

typedef enum hiAIO_PCM8BIT_MODE_E
{
    AIO_MODE_PCM_LINEAR = 0,   /* linear-8bit pcm */
    AIO_MODE_PCM_ALAW,          /* ITU 8bit a-law pcm (G.711 A)*/
    AIO_MODE_PCM_ULAW,          /* ITU 8bit u-law pcm (G.711 u)*/
    AIO_MODE_PCM_BUTT
} AIO_PCM8BIT_MODE_E;

typedef enum hiAIO_MODE_E
{
    AIO_MODE_I2S_MASTER = 0,   /* SIO I2S master mode */
    AIO_MODE_I2S_SLAVE,         /* SIO I2S slave mode */
    AIO_MODE_PCM_SLAVE_STD,     /* SIO PCM slave standard mode */
    AIO_MODE_PCM_SLAVE_NSTD,    /* SIO PCM slave non-standard mode */
    AIO_MODE_PCM_MASTER_STD,    /* SIO PCM master standard mode */
    AIO_MODE_PCM_MASTER_NSTD,   /* SIO PCM master non-standard mode */
    AIO_MODE_BUTT
} AIO_MODE_E;

typedef enum hiAIO_SOUND_MODE_E
{
    AUDIO_SOUND_MODE_MOMO   = 0,/*mono*/
    AUDIO_SOUND_MODE_STEREO = 1,/*stereo*/
    AUDIO_SOUND_MODE_BUTT
} AUDIO_SOUND_MODE_E;

/* only valid for AIAO work at master mode */
typedef enum hiAIO_MCLK_SEL_E
{
    AIO_MCLK_128_FS = 0,    /* mclk 128*fs  */
    AIO_MCLK_256_FS,          /* mclk 256*fs */
    AIO_MCLK_384_FS,          /* mclk 384*fs */
    AIO_MCLK_512_FS,          /* mclk 512*fs */
    AIO_MCLK_768_FS,          /* mclk 768*fs */
    AIO_MCLK_1024_FS,        /* mclk 1024*fs */
    AIO_MCLK_BUTT
} AIO_MCLK_SEL_E;

/* only valid for AIAO work at master mode */
typedef enum hiAIO_BCLK_SEL_E
{
    AIO_BCLK_1_DIV = 1,            /*  bclk=mclk/1  */
    AIO_BCLK_2_DIV = 2,            /*  bclk=mclk/2  */
    AIO_BCLK_3_DIV = 3,            /*  bclk=mclk/3  */
    AIO_BCLK_4_DIV = 4,            /*  bclk=mclk/4  */
    AIO_BCLK_6_DIV = 6,            /*  bclk=mclk/6  */
    AIO_BCLK_8_DIV = 8 ,           /*  bclk=mclk/8  */
    AIO_BCLK_12_DIV= 12,          /* bclk=mclk/12 */
    AIO_BCLK_24_DIV= 24,          /* bclk=mclk/24 */
    AIO_BCLK_32_DIV= 32,          /* bclk=mclk/32 */
    AIO_BCLK_48_DIV= 48,          /* bclk=mclk/48 */
    AIO_BCLK_64_DIV= 64,          /* bclk=mclk/64 */
    AIO_BCLK_BUTT
} AIO_BCLK_SEL_E;

typedef struct hiAIO_PRIVATECLK_ATTR_S
{
    AIO_MCLK_SEL_E enMclkSel;        /* Mclk setting */
    AIO_BCLK_SEL_E enBclkSel;         /* Bclk setting */
    HI_BOOL        bSampleRiseEdge;          /* only work for PCM mode. HI_TRUE:sample data at positive edge of bclk, HI_FALSE: sample data at  negative edge of bclk */
} AIO_PRIVATECLK_ATTR_S;

typedef struct hiAIO_ATTR_S
{
    HI_UNF_SAMPLE_RATE_E enSamplerate;   /* valid value 8000/16000/32000/44100/48000 */
    HI_UNF_BIT_DEPTH_E   enBitwidth;           /* valid value:8/16/8/32 */
    AIO_MODE_E           enWorkmode;           /* master or slave mode*/
    AUDIO_SOUND_MODE_E   enSoundmode; /* momo or stereo */
    HI_U32               u32EXFlag;                    /* expand 8bit to 16bit,use AI_EXPAND(only valid for AI 8bit) */
    HI_U32               u32FrmNum;                 /* frame num in buf(0,MAX_AUDIO_FRAME_NUM]*/
    HI_U32               u32PtNumPerFrm;        /* point num per frame (80/160/240/320/480/1024/2048)
                                                                       (ADPCM IMA should add 1 point, AMR only support 160) */
    HI_U32               u32ChnCnt;                    /* channle number on FS, valid value:2/4/8/16 */
    HI_U32               u32ClkSel;                     /* reserved, must be it to 0 */

    AIO_PRIVATECLK_ATTR_S* pstPrivClkAttr;  /* HI_NULL: use default clock setitng: mclk=256*fs, bclk=128*fs, bSampleEdge=HI_FALSE
                                                                            others: use private clock setting
                                             */
} AIO_ATTR_S;

HI_S32 HI_MPI_AI_SetPubAttr(HI_MPI_AUDIO_DEV AudioDevId, const HI_MPI_AIO_ATTR_S *pstAttr);
HI_S32 HI_MPI_AI_GetPubAttr(HI_MPI_AUDIO_DEV AudioDevId, HI_MPI_AIO_ATTR_S *pstAttr);
HI_S32 HI_MPI_AI_Enable(HI_MPI_AUDIO_DEV AiDevId);
HI_S32 HI_MPI_AI_Disable(HI_MPI_AUDIO_DEV AiDevId);
HI_S32 HI_MPI_AI_EnableChn(HI_MPI_AUDIO_DEV AiDevId, HI_MPI_AI_CHN AiChn);
HI_S32 HI_MPI_AI_DisableChn(HI_MPI_AUDIO_DEV AiDevId, HI_MPI_AI_CHN AiChn);
HI_S32 HI_MPI_AI_GetFrame(HI_MPI_AUDIO_DEV AiDevId, HI_MPI_AI_CHN AiChn, HI_MPI_AUDIO_FRAME_S *pstData,
                          HI_MPI_AUDIO_FRAME_S *pstAecData, HI_U32 u32Block);
HI_S32 HI_MPI_AI_EnableAec(HI_MPI_AUDIO_DEV AiDevId, HI_MPI_AI_CHN AiChn, HI_MPI_AUDIO_DEV AoDevId, HI_MPI_AO_CHN AoChn);
HI_S32 HI_MPI_AI_DisableAec(HI_MPI_AUDIO_DEV AiDevId, HI_MPI_AI_CHN AiChn);

HI_S32 HI_MPI_AO_SetPubAttr(HI_MPI_AUDIO_DEV AudioDevId, const HI_MPI_AIO_ATTR_S *pstAttr);
HI_S32 HI_MPI_AO_GetPubAttr(HI_MPI_AUDIO_DEV AudioDevId, HI_MPI_AIO_ATTR_S *pstAttr);
HI_S32 HI_MPI_AO_Enable(HI_MPI_AUDIO_DEV AoDevId);
HI_S32 HI_MPI_AO_Disable(HI_MPI_AUDIO_DEV AoDevId);
HI_S32 HI_MPI_AO_EnableChn(HI_MPI_AUDIO_DEV AoDevId, HI_MPI_AO_CHN AoChn);
HI_S32 HI_MPI_AO_DisableChn(HI_MPI_AUDIO_DEV AoDevId, HI_MPI_AO_CHN AoChn);
HI_S32 HI_MPI_AO_SendFrame(HI_MPI_AUDIO_DEV AoDevId, HI_MPI_AO_CHN AoChn, const HI_MPI_AUDIO_FRAME_S *pstData,
                           HI_U32 u32Block);
HI_S32 HI_MPI_AO_BindAi(HI_MPI_AUDIO_DEV AoDevId, HI_MPI_AO_CHN AoChn, HI_MPI_AUDIO_DEV AiDevId, HI_MPI_AI_CHN AiChn);
HI_S32 HI_MPI_AO_UnBindAi(HI_MPI_AUDIO_DEV AoDevId, HI_MPI_AO_CHN AoChn, HI_MPI_AUDIO_DEV AiDevId, HI_MPI_AI_CHN AiChn);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif
#endif
