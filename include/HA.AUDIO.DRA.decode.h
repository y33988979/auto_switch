/******************************************************************************
 Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
 ******************************************************************************
 File Name     : HA.AUDIO.DRA.decode.h
 Version       : Initial Draft
 Author        : Hisilicon multimedia software group
 Created       : 
 Last Modified :
 Description   : 
 Function List :
 History       :
******************************************************************************/
#ifndef __HISI_AUDIO_DECODER_DRA_H__
#define __HISI_AUDIO_DECODER_DRA_H__

#include "hi_type.h"
#include "hi_audio_codec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define    HA_DRA_ID 0x007        
#define    HA_AUDIO_ID_DRA   HA_BUILD_CODEC_ID(VENDOR_HISI,FORMAT_DRA,HA_DRA_ID)  /**< support FORMAT_DRA */

#define HA_DRA_DecGetDefalutOpenParam(pOpenParam) \
do{ HI_S32 i; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->enDecMode = HD_DEC_MODE_SIMUL; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = HI_NULL; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = 0; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredOutChannels = 2; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.bInterleaved  = HI_TRUE; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32BitPerSample = 24; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredSampleRate = 48000; \
    for (i = 0; i < HA_AUDIO_MAXCHANNELS; i++) \
    { \
        ((HI_HADECODE_OPENPARAM_S *)pOpenParam)->sPcmformat.enChannelMapping[i] = HA_AUDIO_ChannelNone; \
    } \
}while(0)

/* dmx 2/0 channel and Multi-channel*/
#define HA_DRA_DecGetOpenParam_MultichPcm(pOpenParam) \
    do{ HI_S32 i; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->enDecMode = HD_DEC_MODE_SIMUL; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = HI_NULL; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = 0; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredOutChannels = 8; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.bInterleaved  = HI_TRUE; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32BitPerSample = 24; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredSampleRate = 48000; \
        for (i = 0; i < HA_AUDIO_MAXCHANNELS; i++) \
        { \
            ((HI_HADECODE_OPENPARAM_S *)pOpenParam)->sPcmformat.enChannelMapping[i] = HA_AUDIO_ChannelNone; \
        } \
    }while(0)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HISI_AUDIO_DECODER_DRA_H__ */

