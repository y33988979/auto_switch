/******************************************************************************

  Copyright (C), 2001-2011, HiSilicon Technologies Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_avplay.h
  Version       : Initial draft
  Author        : HiSilicon multimedia software group
  Created Date  : 2009-12-21
  Description   :
  Change History:
  Date          : 2009-12-21
  Author        : Wan Li (employee ID: 58735)
  Description   : This file is created.

*******************************************************************************/
/** 
 * \file
 * \brief Describes the information about the audio/video player (AVPLAY) module. CNcomment: 提供AVPLAY的相关信息
 */
#ifndef __HI_UNF_AVPLAY_H__
#define __HI_UNF_AVPLAY_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/*********************************error  macro******************************************/
/*************************** Structure Definition ****************************/
/** \addtogroup      AVPLAY */
/** @{ */  /** <!-- 【AVPLAY】 */

/**Highest priority of the video decoder*/
/**CNcomment:视频解码器的最大优先级*/
#define HI_UNF_VCODEC_MAX_PRIORITY  16


/**Defines the buffer ID required in an AVPLAY.*/
/**CNcomment:定义AV播放器中需要的BufferID枚举类型 */
typedef enum hiUNF_AVPLAY_BUFID_E
{
    HI_UNF_AVPLAY_BUF_ID_ES_VID  = 0,    /**<ID of the buffer for storing the video elementary streams (ESs) played by an AVPLAY*//**<CNcomment: AV播放器ES视频Buffer ID*/
    HI_UNF_AVPLAY_BUF_ID_ES_AUD  = 1,    /**<ID of the buffer for storing the audio ESs played by an AVPLAY*//**<CNcomment: AV播放器ES音频Buffer ID*/
    HI_UNF_AVPLAY_BUF_ID_BUTT
} HI_UNF_AVPLAY_BUFID_E;

/********************************************************************************/
/**Defines the type of a media channel.*/
/**CNcomment:定义媒体通道类型 */
typedef enum hiUNF_AVPLAY_MEDIA_CHAN
{
    HI_UNF_AVPLAY_MEDIA_CHAN_AUD  = 0x01,  /**<Audio channel*//**<CNcomment: 音频通道 */
    HI_UNF_AVPLAY_MEDIA_CHAN_VID  = 0x02,  /**<Video channel*//**<CNcomment: 视频通道 */

    HI_UNF_AVPLAY_MEDIA_CHAN_BUTT = 0x8
} HI_UNF_AVPLAY_MEDIA_CHAN_E;


/**Defines the type of an input stream interface.*/
/**CNcomment:定义数据输入流接口类型 */
typedef enum hiUNF_AVPLAY_STREAM_TYPE_E
{
    HI_UNF_AVPLAY_STREAM_TYPE_TS = 0,   /**<Transport stream (TS)*/
    HI_UNF_AVPLAY_STREAM_TYPE_ES,       /**<ES stream*/
    HI_UNF_AVPLAY_STREAM_TYPE_VP,       /**<VP stream*/

    HI_UNF_AVPLAY_STREAM_TYPE_BUTT
} HI_UNF_AVPLAY_STREAM_TYPE_E;

/********************************************************************************/

/**Defines the stream attributes.*/
/**CNcomment:定义码流属性的结构体 */
typedef struct hiUNF_AVPLAY_STREAM_ATTR_S
{
    HI_UNF_AVPLAY_STREAM_TYPE_E enStreamType;   /**<Stream type*//**<CNcomment:码流类型 */

    HI_U32                      u32VidBufSize;  /**<Video buffer size*//**<CNcomment: 视频缓冲大小 */
    HI_U32                      u32AudBufSize;  /**<Audio buffer size*//**<CNcomment: 音频缓冲大小 */

	HI_UNF_VP_NET_PARA_S        stNetCfgPara;	/**<Network parameter. It is valid when the stream type is VP.*//**<CNcomment: 网络参数，码流类型为VP时有效 */

} HI_UNF_AVPLAY_STREAM_ATTR_S;

/**Supported synchronization control mode*/
/**CNcomment:支持的同步控制模式 */
typedef enum hiUNF_SYNC_REF_E
{
    HI_UNF_SYNC_REF_NONE = 0, /**<Free playing without synchronization*//**<CNcomment: 自由播放*/
    HI_UNF_SYNC_REF_AUDIO,    /**<Audio-based synchronization*//**<CNcomment: 以音频为准  */
    HI_UNF_SYNC_REF_VIDEO,    /**<Video-based synchronization*//**<CNcomment: 以视频为准  */
    HI_UNF_SYNC_REF_PCR,      /**<Program clock reference (PCR)-based synchronization*//**<CNcomment: 以PCR（Program Clock Reference）为准 */
    HI_UNF_SYNC_REF_SCR,      /**<Program clock reference (SCR)-based synchronization*//**<CNcomment: 以SCR(System Clock Reference) 为准 */

    HI_UNF_AVPLAY_SYNC_REF_BUTT
} HI_UNF_SYNC_REF_E;

/**Defines the status of a buffer.*/
/**CNcomment:定义使用的缓冲区状态枚举类型 */
typedef enum hiUNF_AVPLAY_BUF_STATE_E
{
    HI_UNF_AVPLAY_BUF_STATE_EMPTY = 0,   /**<The buffer is idle.*//**<CNcomment: 缓冲区空闲*/
    HI_UNF_AVPLAY_BUF_STATE_LOW,         /**<The buffer usage is too low.*//**<CNcomment: 缓冲区占用率过低*/
    HI_UNF_AVPLAY_BUF_STATE_NORMAL,      /**<The buffer works normally.*//**<CNcomment: 缓冲区使用正常*/
    HI_UNF_AVPLAY_BUF_STATE_HIGH,        /**<The buffer usage is too high.*//**<CNcomment: 缓冲区占用率过高*/
    HI_UNF_AVPLAY_BUF_STATE_FULL         /**<The buffer is full.*//**<CNcomment: 缓冲区已满*/
}HI_UNF_AVPLAY_BUF_STATE_E;

/**Type of the event callback function*/
/**CNcomment: 事件回调函数类型 */
typedef enum hiUNF_AVPLAY_EVENT_E
{
    HI_UNF_AVPLAY_EVENT_EOS,                   /**<The end of stream (EOS) operation is performed, NULL*//**<CNcomment: EOS执行结束, NULL */
    HI_UNF_AVPLAY_EVENT_STOP,                  /**<The stop operation is performed, NULL*//**<CNcomment: STOP执行结束, NULL   */
    HI_UNF_AVPLAY_EVENT_RNG_BUF_STATE,         /**<Status change of the media buffer queue, HI_UNF_AVPLAY_EVENT_RNG_BUF_STATE*//**<CNcomment: 媒体缓存队列状态变化, HI_UNF_AVPLAY_EVENT_RNG_BUF_STATE */
    HI_UNF_AVPLAY_EVENT_NORM_SWITCH,           /**<Standard switch, HI_UNF_ENC_FMT_E*//**<CNcomment: 制式切换, HI_UNF_ENC_FMT_E        */
    HI_UNF_AVPLAY_EVENT_FRAMEPACKING_CHANGE,   /**<3D Frame packing change,HI_UNF_VIDEO_FRAME_PACKING_TYPE_E*//**<CNcomment: 3D帧类型变化, HI_UNF_VIDEO_FRAME_PACKING_TYPE_E        */
    //HI_UNF_AVPLAY_EVENT_NEW_SEQ,             /**<Information about the new sequence, HI_UNF_VIDEO_SEQUENCE_INFO_S*//**<CNcomment: 新序列信息, HI_UNF_VIDEO_SEQUENCE_INFO_S */
    HI_UNF_AVPLAY_EVENT_NEW_VID_FRAME,         /**<New video frame, HI_UNF_VO_FRAMEINFO_S*//**<CNcomment: 新视频帧, HI_UNF_VO_FRAMEINFO_S */
    HI_UNF_AVPLAY_EVENT_NEW_AUD_FRAME,         /**<New audio frame, HI_UNF_AO_FRAMEINFO_S*//**<CNcomment: 新音频帧, HI_UNF_AO_FRAMEINFO_S */
    HI_UNF_AVPLAY_EVENT_NEW_USER_DATA,         /**<New video user data, HI_UNF_VIDEO_USERDATA_S*//**<CNcomment: 新视频用户数据, HI_UNF_VIDEO_USERDATA_S */
    HI_UNF_AVPLAY_EVENT_GET_AUD_ES,            /**<New audio ES data, HI_UNF_ES_BUF_S*//**<CNcomment: 新音频ES数据, HI_UNF_ES_BUF_S */
    HI_UNF_AVPLAY_EVENT_IFRAME_ERR,      /**<I frame decode error*//**<CNcomment: 解码I帧错误 */
    HI_UNF_AVPLAY_EVENT_JUMP_STREAM,           /**<discard stream data while fast forward*//**<CNcomment: 快进的时候需要丢弃码流数据 */
    HI_UNF_AVPLAY_EVENT_SOUND_POOL,      /**< Reserve *//**<CNcomment: 保留*/

    HI_UNF_AVPLAY_EVENT_BUTT
} HI_UNF_AVPLAY_EVENT_E;

/**Mode of processing the buffer overflow*/
/**CNcomment: 缓冲溢出处理类型 */
typedef enum hiUNF_AVPLAY_OVERFLOW_E
{
    HI_UNF_AVPLAY_OVERFLOW_RESET,              /**<Reset during overflow*//**<CNcomment: 溢出时进行复位  */
    HI_UNF_AVPLAY_OVERFLOW_DISCARD,            /**<Discard during overflow*//**<CNcomment: 溢出时进行丢弃  */
    HI_UNF_AVPLAY_OVERFLOW_BUTT
} HI_UNF_AVPLAY_OVERFLOW_E;

/**Defines the type of the event callback function.*/
/**CNcomment: 定义事件回调函数枚举类型*/
typedef HI_S32 (*HI_UNF_AVPLAY_EVENT_CB_FN)(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E enEvent, HI_U32 u32Para);

/**Defines the attribute ID of an AVPLAY.*/
/**CNcomment: 定义AV播放器属性ID枚举类型 */
typedef enum hiUNF_AVPLAY_ATTR_ID_E
{
    HI_UNF_AVPLAY_ATTR_ID_STREAM_MODE = 0,  /**<Playing mode, HI_UNF_AVPLAY_ATTR_S*//**<CNcomment: 播放模式 , HI_UNF_AVPLAY_ATTR_S */

    HI_UNF_AVPLAY_ATTR_ID_ADEC,             /**<Audio attribute, HI_UNF_ACODEC_ATTR_S*//**<CNcomment: 音频属性 , HI_UNF_ACODEC_ATTR_S */
    HI_UNF_AVPLAY_ATTR_ID_VDEC,             /**<Video attribute, HI_UNF_VCODEC_ATTR_S*//**<CNcomment: 视频属性 , HI_UNF_VCODEC_ATTR_S  */

    HI_UNF_AVPLAY_ATTR_ID_VDEC_ADV,          /**<Advanced video attribute, HI_UNF_VCODEC_ADV_ATTR_S*//**<CNcomment: 高级视频属性 , HI_UNF_VCODEC_ADV_ATTR_S  */

    HI_UNF_AVPLAY_ATTR_ID_AUD_PID,          /**<Audio packet identifier (PID), HI_U32*//**<CNcomment: 音频PID , HI_U32*/
    HI_UNF_AVPLAY_ATTR_ID_VID_PID,          /**<Video PID , HI_U32*//**<CNcomment: 视频PID , HI_U32*/
    HI_UNF_AVPLAY_ATTR_ID_PCR_PID,          /**<PCR PID, HI_U32*//**<CNcomment: PCR PID , HI_U32*/

    HI_UNF_AVPLAY_ATTR_ID_SYNC,             /**<Synchronization attribute, HI_UNF_SYNC_ATTR_S*//**<CNcomment: 同步属性 , HI_UNF_SYNC_ATTR_S */
    HI_UNF_AVPLAY_ATTR_ID_AFD,              /**<Whether to enable the active format descriptor (AFD), HI_BOOL*//**<CNcomment: AFD 是否开启， HI_BOOL */
    HI_UNF_AVPLAY_ATTR_ID_OVERFLOW,         /**<Overflow processing type, HI_UNF_AVPLAY_OVERFLOW_E*//**<CNcomment: 溢出处理类型 , HI_UNF_AVPLAY_OVERFLOW_E */

    HI_UNF_AVPLAY_ATTR_ID_FRMRATE,          /**< FrameRate HI_UNF_VCODEC_FRMRATE_S */ /**<CNcomment: 帧率 , HI_UNF_VCODEC_FRMRATE_S */
    HI_UNF_AVPLAY_ATTR_ID_ADEC_VOL,         /**<Audio decode volume*//**<CNcomment: ADEC音量 , HI_U32 */
    HI_UNF_AVPLAY_ATTR_ID_BUTT
} HI_UNF_AVPLAY_ATTR_ID_E;

/*******************************************************************************/

/**Defines the  synchronization region.*/
/**CNcomment: 定义音视频同步区间 */
typedef struct hiUNF_SYNC_REGION_S
{
    HI_S32                s32VidPlusTime;        /**<Plus time range during video synchronization*//**<CNcomment: 视频同步超前的时间范围 */
    HI_S32                s32VidNegativeTime;    /**<Negative time range during video synchronization*//**<CNcomment: 视频同步落后的时间范围 */
    HI_BOOL               bSmoothPlay;           /**<Slow playing enable*//**<CNcomment: 慢放使能 */
} HI_UNF_SYNC_REGION_S;

/**Defines the audio/video synchronization attributes.*/
/**CNcomment: 定义音视频同步属性 */
typedef struct hiUNF_SYNC_ATTR_S
{
    HI_UNF_SYNC_REF_E     enSyncRef;             /**<Audio-based synchronization, PCR-based synchronization, and free playing without synchronization*//**<CNcomment: 音频为准，PCR为准，自由播放等 */
    HI_UNF_SYNC_REGION_S  stSyncStartRegion;     /**<Synchronization start region*//**<CNcomment: 同步起调区间 */
    HI_UNF_SYNC_REGION_S  stSyncNovelRegion;     /**<Synchronization exception region*//**<CNcomment: 同步异常区间 */
    HI_S32                s32VidPtsAdjust;       /**<Video presentation time stamp (PTS) adjustment*//**<CNcomment: 视频PTS调整*/
    HI_S32                s32AudPtsAdjust;       /**<Audio PTS adjustment*//**<CNcomment: 音频PTS调整*/

    HI_U32                u32PreSyncTimeoutMs;   /**<Pre-synchronization timeout, in ms*//**<CNcomment: 预同步的超时时间，单位为毫秒 */
    HI_BOOL               bQuickOutput;          /**<Fast output enable*//**<CNcomment: 快速输出使能 */
} HI_UNF_SYNC_ATTR_S;

/**Defines the playing attributes of an AVPLAY.*/
/**CNcomment: 定义AV播放属性 */
typedef struct hiUNF_AVPLAY_ATTR_S
{
    HI_U32                       u32DemuxId;   /**<ID of the DEMUX used by an AVPLAY, only for ts mode*//**<CNcomment: AVPLAY所使用的DEMUX ID 仅当码流类型为TS时有效*/
    HI_UNF_AVPLAY_STREAM_ATTR_S  stStreamAttr; /**<Stream attributes*//**<CNcomment: 码流属性 */
} HI_UNF_AVPLAY_ATTR_S;

/********************************************************************************/
/**Defines the synchronization status when an AVPLAY is running.*/
/**CNcomment: 定义播放器运行状态信息中同步状态信息类型 */
typedef struct hiUNF_SYNC_STATUS_S
{
    HI_U32 u32FirstAudPts;    /**<PTS of the first audio frame*//**<CNcomment: 第一个音频帧 PTS */
    HI_U32 u32FirstVidPts;    /**<PTS of the first video frame*//**<CNcomment: 第一个视频帧 PTS */
    HI_U32 u32LastAudPts;     /**<PTS of the last audio frame*//**<CNcomment: 最近播放的一个音频帧 PTS */
    HI_U32 u32LastVidPts;     /**<PTS of the last video frame*//**<CNcomment: 最近播放的一个视频帧 PTS */
    HI_S32 s32DiffAvPlayTime; /**<Playing time difference between audio and video frames*//**<CNcomment: 音视频 播放时差 */
    HI_U32 u32PlayTime;       /**<Playing time*//**<CNcomment: 当前已播放时间 */
    HI_U32 u32LocalTime;      /**<Local synchronization reference time*//**<CNcomment: 本地同步参考时间 */
} HI_UNF_SYNC_STATUS_S;

/**Defines the status of a media buffer.*/
/**CNcomment:定义媒体缓冲区的状态信息 */
typedef struct hiUNF_AVPLAY_BUF_STATUS_S
{
    HI_U32 u32BufId;         /**<Media buffer ID*//**<CNcomment: 媒体缓冲 标识 */
    HI_U32 u32BufSize;       /**<Media buffer size*//**<CNcomment: 媒体缓冲大小 */
    HI_U32 u32BufRptr;       /**<Read pointer of the media buffer. This pointer is valid when TSs are being played.*//**<CNcomment: 媒体缓冲读指针,Ts播放时有效*/
    HI_U32 u32BufWptr;       /**<Write pointer of the media buffer. This pointer is valid when TSs are being played.*//**<CNcomment: 媒体缓冲写指针,Ts播放时有效*/
    HI_U32 u32UsedSize;      /**<Used size of the media buffer*//**<CNcomment: 媒体缓冲已使用大小 */
    HI_U32 u32FrameBufTime;  /**<Frame buffer time*//**<CNcomment: 帧缓冲时间 */
    HI_U32 u32FrameBufNum;   /**<The number of frames in frame buffer*//**<CNcomment: 帧缓冲数目 仅VIDEO有效*/
    HI_BOOL bEndOfStream;    /**<Flag to indicate end of stream*//**<CNcomment: 缓冲中码流解码完毕标识 仅VIDEO有效*/
} HI_UNF_AVPLAY_BUF_STATUS_S;

/**Defines the playing status of an AVPLAY.*/
/**CNcomment:定义AV的播放状态 */
typedef enum hiUNF_AVPLAY_STATUS_E
{
    HI_UNF_AVPLAY_STATUS_STOP = 0, /**<Stop*//**<CNcomment: 停止 */
    HI_UNF_AVPLAY_STATUS_PLAY,     /**<Play*//**<CNcomment: 播放 */
    HI_UNF_AVPLAY_STATUS_TPLAY,    /**<Trick play, such as fast forward and rewind*//**<CNcomment: TPlay, 快进快退 */
    HI_UNF_AVPLAY_STATUS_PAUSE,    /**<Pause*//**<CNcomment: 暂停 */
    HI_UNF_AVPLAY_STATUS_EOS,      /**<EOS*//**<CNcomment: 码流播放结束 */
    HI_UNF_AVPLAY_STATUS_SEEK ,    /**<Seek play*//**<CNcomment: 定位播放 */

    HI_UNF_AVPLAY_STATUS_BUTT
}HI_UNF_AVPLAY_STATUS_E;

/**Defines the output value after the playing status of an AVPLAY is queried.*/
/**CNcomment:定义AV播放状态查询输出值类型 */
typedef struct hiUNF_AVPLAY_STATUS_INFO_S
{
    HI_UNF_SYNC_STATUS_S       stSyncStatus;      /**<Synchronization status*//**<CNcomment: 同步状态 */
    HI_UNF_AVPLAY_STATUS_E     enRunStatus;       /**<Running status*//**< CNcomment:运行状态 */
    HI_U32                     u32VidFrameCount;  /**<Count of played video frames*//**<CNcomment: 视频已播放帧数 */
    HI_U32                     u32AuddFrameCount; /**<Count of played audio frames*//**<CNcomment: 音频已播放帧数 */
    HI_UNF_AVPLAY_BUF_STATUS_S stBufStatus[HI_UNF_AVPLAY_BUF_ID_BUTT]; /**<Status of the media buffer*//**<CNcomment:媒体缓冲状态 */
    HI_U32                     u32VidErrorFrameCount; /**<Number of error frames during video decoding*/ /**<CNcomment: 视频解码错误帧数 */    
} HI_UNF_AVPLAY_STATUS_INFO_S;

/********************************************************************************/
/**Defines the information about the playing program streams to be queried.*/
/**CNcomment: 定义播放节目流查询信息类型*/
typedef struct hiUNF_AVPLAY_STREAM_INFO_S
{
    HI_UNF_VCODEC_STREAMINFO_S stVidStreamInfo; /**<Video stream information*//**<CNcomment:视频流信息 */
    HI_UNF_ACODEC_STREAMINFO_S stAudStreamInfo; /**<Audio stream information*//**<CNcomment:音频流信息 */
} HI_UNF_AVPLAY_STREAM_INFO_S;

/********************************************************************************/
/**Defines the information about an I frame.*//**CNcomment:定义I帧数据信息类型 */
typedef struct hiUNF_AVPLAY_I_FRAME_S
{
    HI_U8  *             pu8Addr;    /**<User-state virtual address of a frame*//**<CNcomment:帧数据用户态虚拟地址*/
    HI_U32               u32BufSize; /**<Frame size, in byte*//**<CNcomment:帧数据大小，单位字节*/
    HI_UNF_VCODEC_TYPE_E enType;     /**<Protocol type of a data segment*//**<CNcomment:该片数据的协议类型*/
} HI_UNF_AVPLAY_I_FRAME_S;

/********************************************************************************/
/**Defines the decoder type. The occupied memory varies according to decoders.*/
/**CNcomment:定义解码器类型 不同类型的解码器占用内存不同*/
typedef enum hiHI_UNF_VCODEC_DEC_TYPE_E
{
    HI_UNF_VCODEC_DEC_TYPE_NORMAL,            /**<Normal type.*//**<CNcomment:普通类型*/

    /**<I frame decoding type. If an AVPLAY is used to decode I frames only (HI_UNF_AVPLAY_DecodeIFrame), you can select this type to reduce the memory usage.*/
    /**<CNcomment:I帧解码类型 如果avplay仅用于I帧解码(HI_UNF_AVPLAY_DecodeIFrame) 设置为此类型可以节省内存*/    
    HI_UNF_VCODEC_DEC_TYPE_ISINGLE,  
    
    HI_UNF_VCODEC_DEC_TYPE_BUTT               
}HI_UNF_VCODEC_DEC_TYPE_E;

/**Defines the level of the protocol supported by the decoder. This value affects the number of frame buffers allocated by the normal decoder. 
The greater the value, the more the required frame buffers.*/
/**CNcomment:定义解码器支持的协议级别 影响NORMAL类型解码器分配的帧存个数 值越大需要的帧存数目越多*/
typedef enum hiHI_UNF_VCODEC_PRTCL_LEVEL_E
{
    HI_UNF_VCODEC_PRTCL_LEVEL_MPEG = 0,   /**<Protocols excluding the H.264 protocol*//**<CNcomment:除h264外的其他协议 */
    HI_UNF_VCODEC_PRTCL_LEVEL_H264 = 1,  /**<H.264 protocol and other protocols*//**<CNcomment:h264协议 */    
    HI_UNF_VCODEC_PRTCL_LEVEL_BUTT
}HI_UNF_VCODEC_PRTCL_LEVEL_E;

/**Defines the attributes when an AVPLAY enables the video decoder. The settings affect the memory occupied by the video decoder and decoding performance.*/
/**CNcomment:定义AV播放器打开视频解码器时属性设置结构体 影响视频解码器占用内存大小及解码能力*/
typedef struct hiHI_UNF_AVPLAY_OPEN_OPT_S
{
    HI_UNF_VCODEC_DEC_TYPE_E    enDecType;       /**<Maximum resolution supported by the decoder. This value affects the size of each frame buffer.*//**<CNcomment:Decoder type*//**<解码器类型*/   
    HI_UNF_VCODEC_CAP_LEVEL_E   enCapLevel;      /**<Maximum resolution supported by the decoder. This value affects the size of each frame buffer.*//**<CNcomment:解码器支持的最大分辨率 影响每个帧存的大小*/
    HI_UNF_VCODEC_PRTCL_LEVEL_E enProtocolLevel; /**<Supported protocol level. This value affects the number of frame buffers.*//**<CNcomment:支持的协议级别 影响帧存数目*/
}HI_UNF_AVPLAY_OPEN_OPT_S;

/**Defines the video display mode after an AVPLAY is stopped.*/
/**CNcomment:定义AV播放器停止时视频显示模式 */
typedef enum hiUNF_AVPLAY_STOP_MODE_E
{
    HI_UNF_AVPLAY_STOP_MODE_STILL = 0,  /**<The last frame is still after an AVPLAY is stopped.*//**<CNcomment:stop后保留最后一帧*/
    HI_UNF_AVPLAY_STOP_MODE_BLACK = 1,  /**<The blank screen is displayed after an AVPLAY is stopped.*//**<CNcomment:stop后黑屏*/
    HI_UNF_AVPLAY_STOP_MODE_BUTT
} HI_UNF_AVPLAY_STOP_MODE_E;

/**Defines the attributes when an AVPLAY is started.*/
/**CNcomment:定义AV播放器启动时属性设置结构体*/
typedef struct hiAVPLAY_START_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_START_OPT_S;

/**Defines the attributes when an AVPLAY is stopped.*/
/**CNcomment:定义AV播放器停止时属性设置结构体*/
typedef struct hiAVPLAY_STOP_OPT_S
{
    /**
         s32Timeout: end of stream timeout
         s32Timeout = 0   Wait until streams are played in non-block mode, that is, the interface is returned immediately. CNcomment:非阻塞等待码流播放结束，立即返回
         s32Timeout > 0   Block timeout, in ms, CNcomment:阻塞超时时间，单位为毫秒
         s32Timeout = -1  Infinite wait,CNcomment:无限等待
     */
    HI_U32                    u32TimeoutMs;    /**<Timeout, in ms*//**<CNcomment:超时值，单位为毫秒*/
    HI_UNF_AVPLAY_STOP_MODE_E enMode;          /**<Video display mode*//**<CNcomment:视频显示模式*/
} HI_UNF_AVPLAY_STOP_OPT_S;

/**Defines the attributes when an AVPLAY is paused.*/
/**CNcomment:定义AV播放器暂停时属性设置结构体*/
typedef struct hiAVPLAY_PAUSE_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_PAUSE_OPT_S;

/**Defines the attributes when the playing mode of an AVPLAY is fast forward.*/
/**CNcomment:定义AV播放器快进时属性设置结构体*/
typedef struct hiAVPLAY_TPLAY_OPT_S
{
    HI_U32       u32TplaySpeed;        /**<The speed when the playing mode of an AVPLAY is fast forward.*//**<CNcomment:快进速度*/
} HI_UNF_AVPLAY_TPLAY_OPT_S;

/**Defines the attributes when an AVPLAY is resumed.*/
/**CNcomment:定义AV播放器恢复时属性设置结构体*/
typedef struct hiAVPLAY_RESUME_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_RESUME_OPT_S;

/**Defines the attributes when an AVPLAY is reset.*/
/**CNcomment:定义AV播放器复位时属性设置结构体*/
typedef struct hiAVPLAY_RESET_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_RESET_OPT_S;

/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      AVPLAY */
/** @{ */  /** <!-- 【AVPLAY】 */

/**
\brief Initializes the AVPLAY module.CNcomment:初始化AVPLAY模块
\attention \n
Before calling ::HI_UNF_AVPLAY_Create to create an AVPLAY, you must call this application programming interface (API).
CNcomment 在调用::HI_UNF_AVPLAY_Create接口创建播放器之前，调用本接口
\param  N/A
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NOT_EXIST There is no AVPLAY. CNcomment:AVPLAY设备不存在
\retval ::HI_ERR_AVPLAY_NOT_DEV_FILE  The file is not an AVPLAY file. CNcomment:AVPLAY非设备
\retval ::HI_ERR_AVPLAY_DEV_OPEN_ERR  An AVPLAY fails to be started. CNcomment:AVPLAY打开失败
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Init(HI_VOID);

/**
\brief Deinitializes the AVPLAY module. CNcomment:去初始化AVPLAY模块
\attention \n
Before calling ::HI_UNF_AVPLAY_Destroy to destroy all players, you must call this API.
CNcomment: 在调用::HI_UNF_AVPLAY_Destroy接口销毁所有的播放器后，调用本接口
\param N/A
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_INVALID_OPT  The operation is invalid.  CNcomment:操作非法
\retval ::HI_ERR_AVPLAY_DEV_CLOSE_ERR  An AVPLAY fails to be stopped. CNcomment:AVPLAY关闭失败
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_DeInit(HI_VOID);

/**
\brief Obtains the default configuration of an AVPLAY. CNcomment:获取缺省的AV播放配置
\attention \n
When calling this API to set the enCfg parameter, you must enter correct mode of the player to be created.\n
It is recommended that you call this API to obtain the default AVPLAY attributes before creating an AVPLAY. This avoids creation failures due to incomplete or incorrect parameters.
CNcomment:调用本接口输入enCfg参数时，请正确输入想要创建播放器模式\n
创建AV播放器前建议调用本接口，获取到AV播放器默认属性，避免创建AV播放器时由于参数不全或参数错误导致播放器创建不成功现象
\param[out] pstAvAttr  Pointer to AVPLAY attributes. For details, see the description of ::HI_UNF_AVPLAY_ATTR_S. CNcomment: 指针类型，AV播放属性，请参见::HI_UNF_AVPLAY_ATTR_S
\param[in] enCfg       AVPLAY type. For details, see the description of ::HI_UNF_AVPLAY_STREAM_TYPE_E. CNcomment: AV播放的类型，请参见::HI_UNF_AVPLAY_STREAM_TYPE_E
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetDefaultConfig(HI_UNF_AVPLAY_ATTR_S *pstAvAttr, HI_UNF_AVPLAY_STREAM_TYPE_E enCfg);

/**
\brief Registers a dynamic audio decoding library. CNcomment:注册音频动态解码库
\attention \n
\param[in] pFileName Name of the file in the audio decoding library CNcomment:音频解码库文件名
\retval ::HI_SUCCESS  Success CNcomment:成功
\retval ::HI_FAILURE Failure CNcomment:失败
\retval ::HI_ERR_AVPLAY_NULL_PTR  The input pointer is null. CNcomment:输入指针为空

\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_RegisterAcodecLib(const HI_CHAR *pFileName);

/**
\brief Searches for registered dynamic audio decoding libraries. CNcomment:查找注册音频动态解码库
\attention \n
\param[in] enDstCodecID Codec ID of an audio decoding library  CNcomment:音频解码库CodecID
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_FAILURE Failure CNcomment:失败
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_FoundRegisterDeoder(const HI_U32 enDstCodecID);

/**
\brief Searches for registered dynamic audio decoding libraries based on the audio format. 
CNcomment:根据音频格式, 查找注册音频动态解码库
\attention \n
\param[in] enFormat Audio format CNcomment:音频格式
\param[out] penDstCodecID If an audio decoding library is found, its codec ID is returned. 
CNcomment:成功则返回音频解码库CodecID
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_FAILURE Failure CNcomment:失败
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_FoundSupportDeoder(const HA_FORMAT_E enFormat,HI_U32 * penDstCodecID);


/**
\brief Sets private commands for a dynamic audio decoding library. These commands are used to call ha_codec. 
CNcomment:设置私有命令给音频动态解码库, 调用ha_codec 方法 
HI_HA_ERRORTYPE_E (*DecSetConfig)(HI_VOID * hDecoder, HI_VOID * pstConfigStructure);
\attention \n
\param[in] hAvplay         AVPLAY handle  CNcomment:AV播放句柄
\param[in] pPara  Attribute structure CNcomment:属性结构
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_FAILURE Failure CNcomment:失败
\retval ::HI_ERR_AVPLAY_NULL_PTR  The input pointer is null. CNcomment:输入指针为空
\see \n
N/A
*/

HI_S32 HI_UNF_AVPLAY_ConfigAcodec(const HI_U32 enDstCodecID, HI_VOID *pPara);

//HI_S32 HI_UNF_AVPLAY_ControlAcodec( HI_HANDLE hAvplay, HI_VOID *pPara);

/**
\brief Creates an AVPLAY. CNcomment:创建AV播放器
\attention \n
Note the following point when setting the input parameter pstAttr: The stream source can be HI_UNF_AVPLAY_STREAM_TYPE_ES (ESs input from the memory) or HI_UNF_AVPLAY_STREAM_TYPE_TS (ESs input from the memory and TSs input from the Tuner).
CNcomment:输入属性参数pstAttr中有几点需要注意：码流源支持HI_UNF_AVPLAY_STREAM_TYPE_ES（内存输入ES流）、HI_UNF_AVPLAY_STREAM_TYPE_TS（内存输入TS流或TUNER输入TS 流）
\param[in]  pstAvAttr   Pointer to AVPLAY attributes. For details, see the description of ::HI_UNF_AVPLAY_ATTR_S. 指针类型，AV播放属性，请参见::HI_UNF_AVPLAY_ATTR_S
\param[out] phAvplay    Pointer to the handle of a created AVPLAY.CNcomment:指针类型，创建的AV播放句柄
\retval ::HI_SUCCESS  Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_CREATE_ERR       The AVPLAY fails to be created. CNcomment:AVPLAY创建失败
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Create(const HI_UNF_AVPLAY_ATTR_S *pstAvAttr, HI_HANDLE *phAvplay);

/**
\brief Destroys an AVPLAY. CNcomment:销毁AV播放器
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Destroy(HI_HANDLE hAvplay);

/**
\brief Sets the attributes of an AVPLAY. CNcomment:设置AV播放属性
\attention \n
You can set the audio/video PID, audio/video decoding type, and synchronization mode by calling this API.\n
Different attribute IDs correspond to different data types. For details, see the Note part of HI_UNF_AVPLAY_ATTR_ID_E. The attribute types of the pPara and enAttrID parameters must be the same.\n
Before setting HI_UNF_AVPLAY_ATTR_ID_ADEC (audio decoding attribute) and HI_UNF_AVPLAY_ATTR_ID_VDEC (video decoding attribute),\n
you must disable the audio channel or video channel. The new attributes take effect when you enable the audio channel or video channel again.
CNcomment:调用本接口可实现设置音视频PID、设置音视频解码类型、设置同步方式等功能\n
不同的属性ID对应的结构体请参见结构体HI_UNF_AVPLAY_ATTR_ID_E的"注意"。pPara参数要与enAttrID对应的属性结构体类型保持一致\n
当需要设置HI_UNF_AVPLAY_ATTR_ID_ADEC（音频解码属性），HI_UNF_AVPLAY_ATTR_ID_VDEC（视频解码属性）时\n
需要先关闭音频或视频通道，再设置新属性，然后再重新打开音频或视频通道新属性才可以生效。
\param[in] hAvplay         AVPLAY handle CNcomment:AV播放句柄
\param[in] enAttrID        Attribute ID CNcomment:属性ID
\param[in] pPara  Data type corresponding to an attribute ID CNcomment:属性ID对应结构
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SetAttr(HI_HANDLE hAvplay, HI_UNF_AVPLAY_ATTR_ID_E enAttrID, HI_VOID *pPara);

/**
\brief Obtains the attributes of an AVPLAY. CNcomment:获取AV播放属性
\attention \n
N/A
\param[in] hAvplay          AVPLAY handle AV播放句柄
\param[in] enAttrID         Attribute ID CNcomment:属性ID
\param[in] pPara   Data type corresponding to an attribute ID, CNcomment:属性ID对应结构
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetAttr(HI_HANDLE hAvplay, HI_UNF_AVPLAY_ATTR_ID_E enAttrID, HI_VOID *pPara);

/**
\brief Decodes I frames. CNcomment:解码I帧码流
\attention \n
If pstCapPicture is null, the decoded I frames are displayed in the window; if pstCapPicture is not null, the information about I frames is reported.\n
You must stop the video decoder before calling this API. If I frames are being processed, do not enable the video decoder.
CNcomment:当pstCapPicture为空指针时，解完的I帧将在window上显示，如果非空，则不会显示而是将I帧信息上报。\n
调用该接口前，需停止视频解码器；I帧处理没有完成时，也不能启动视频解码器
\param[in] hAvplay         AVPLAY handle CNcomment:AV播放句柄
\param[in] pstFrame        Pointer to frame attributes CNcomment:指针类型，帧数据属性
\param[in] pstCapPicture   Pointer to the frame information CNcomment:指针类型，帧信息
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_DecodeIFrame(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_I_FRAME_S *pstFrame, HI_UNF_CAPTURE_PICTURE_S *pstCapPicture);

/**
\brief Sets the mode of a video decoder. CNcomment:设置视频解码器的模式
\attention \n
This API is used in trick play mode. Before switching the mode to the trick play mode, you must enable a decoder to decode only I frames by calling this API.\n
Before switching the mode to the normal mode, you also need to set the mode of a decoder to normal by calling this API.
CNcomment:本接口主要应用在倍速播放的场景，当切换到倍速播放前，先调用本接口将解码器设置为只解I帧，\n
当切换回正常播放前，先调用本接口将解码器设置为NORMAL。
\param[in] hAvplay            AVPLAY handle CNcomment:AV播放句柄
\param[in] enDecodeMode       Decoding mode CNcomment:解码模式
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SetDecodeMode(HI_HANDLE hAvplay, HI_UNF_VCODEC_MODE_E enDecodeMode);

/**
\brief Registers an event. CNcomment:注册事件
\attention \n
N/A
\param[in] hAvplay     AVPLAY handle CNcomment:AV播放句柄
\param[in] enEvent     Event type enumeration CNcomment:枚举类型，表示事件类型
\param[in] pfnEventCB  Pointer to the callback function corresponding to the registered event. CNcomment:回调函数指针，指向与注册事件对应的回调函数
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT     The AVPLAY is not initialized.  CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_RegisterEvent(HI_HANDLE      hAvplay,
                                   HI_UNF_AVPLAY_EVENT_E     enEvent,
                                   HI_UNF_AVPLAY_EVENT_CB_FN pfnEventCB);


/**
\brief Deregisters an event. CNcomment:取消注册事件
\attention \n
N/A
\param[in] hAvplay   AVPLAY handle CNcomment:AV播放句柄
\param[in] enEvent   Event type enumeration CNcomment:枚举类型，表示事件类型
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_UnRegisterEvent(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E enEvent);

/**
\brief Enables an AVPLAY channel. CNcomment:打开AV播放器通道
\attention \n
You can enable an audio channel and a video channel for each AVPLAY. If you only need to play videos or audios, you can enable the corresponding channel to save resources.
CNcomment:每个AV播放器仅支持打开音视频通道各1个。如果只播放音频或视频，只需要打开相应通道，以节省资源。
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\param[in] enChn    Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:单独的音视频通道，请参见::HI_UNF_AVPLAY_MEDIA_CHAN_E
\param[in] pPara    Pointer type. For details, see the description of ::HI_UNF_AVPLAY_OPEN_OPT_S. CNcomment:指针类型，请参见::HI_UNF_AVPLAY_OPEN_OPT_S
    If enChn is set to HI_UNF_AVPLAY_MEDIA_CHAN_VID, this API is used to specify the maximum decoding performance of the video decoder.
    If enChn is set to NULL, the maximum performance H264+HI_UNF_VCODEC_CAP_LEVEL_FULLHD is used by default.
    The higher the configured decoding performance, the larger the required MMZ. It is recommended that you configure the performance as required.
	CNcomment:enChn为HI_UNF_AVPLAY_MEDIA_CHAN_VID时用来指定视频解码器的最大解码能力。
    如果设为NULL，将默认为最大能力: H264+HI_UNF_VCODEC_CAP_LEVEL_FULLHD。
    配置支持的能力越大，需要的MMZ物理内存也就越大，建议按需配置即可。
\retval ::HI_SUCCESS Success             CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_ChnOpen(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn, const HI_VOID *pPara);

/**
\brief Disables an AVPLAY channel. CNcomment:关闭AV播放器通道
\attention \n
N/A
\param[in] hAvplay   AVPLAY handle CNcomment:AV播放句柄
\param[in] enChn     Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:单独的音视频通道，请参见::HI_UNF_AVPLAY_MEDIA_CHAN_E
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_ChnClose(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn);

/**
\brief Starts an AVPLAY. The AVPLAY is in play mode. CNcomment:启动播放器，进入PLAY状态
\attention \n
After enabling channels and setting their attributes, you can call this API to start an AVPLAY to enable it to work in play mode. The audios and videos can be played separately or simultaneously.
CNcomment:当完成通道打开和属性设置后，调用本接口启动播放，进入PLAY状态。支持分别和同时启动音视频播放。
\param[in] hAvplay         AVPLAY handle  CNcomment:AV播放句柄
\param[in] enChn           Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:单独的音视频通道，请参见::HI_UNF_AVPLAY_MEDIA_CHAN_E
\param[in] pstStartOpt     Pointer used for expansion. You can set it to NULL. CNcomment:指针类型，待扩展使用，设为NULL即可
\retval ::HI_SUCCESS  Success CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Start(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn, const HI_UNF_AVPLAY_START_OPT_S *pstStartOpt);

/**
\brief Stops an AVPLAY. Then the AVPLAY is in stop mode. CNcomment:停止AV播放，进入STOP状态
\attention \n
If you call this API, all selected channels stop playing. The playing audios and videos can be stopped separately or simultaneously.\n
The parameter pstStopOpt->enMode takes effect only when a video channel is selected.\n
If pstStopOpt->enMode is set to NULL or HI_UNF_AVPLAY_STOP_MODE_STILL, the last frame is kept still.\n
If pstStopOpt->enMode is set to HI_UNF_AVPLAY_STOP_MODE_BLACK, the last frame is cleared, and the blank screen appears.\n
When pstStopOpt->u32TimeoutMs is 0, the AVPLAY stops and this API is returned.\n
When pstStopOpt->u32TimeoutMs is greater than 0, this API is blocked until the data in the buffer is used up.\n
When pstStopOpt->u32TimeoutMs is greater than –1, this API is blocked until the data in the buffer is used up.\n
To stop the audio or video separately when both the audio and video are enabled, you must set pstStopOpt->u32TimeoutMs to 0.
CNcomment:调用本接口将停止所选通道的播放，支持分别和同时停止音视频播放。\n
当所选通道中包含视频通道时，参数pstStopOpt->enMode才有意义。\n
当pstStopOpt->enMode为空或者为HI_UNF_AVPLAY_STOP_MODE_STILL时，保留最后一帧视频图像。\n
当pstStopOpt->enMode为HI_UNF_AVPLAY_STOP_MODE_BLACK时，清除视频最后一帧，视频输出为黑屏。\n
当pstStopOpt->u32TimeoutMs为0时将离开停止播放并返回。\n
当pstStopOpt->u32TimeoutMs>0时将阻塞相应时间，直到缓冲中的数据播完。\n
当pstStopOpt->u32TimeoutMs=-1时将一直阻塞到缓冲中的数据播完。\n
当音视频都处于开启状态时,要单独停止音频和视频，必须设置pstStopOpt->u32TimeoutMs为0
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\param[in] enChn    Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:单独的音视频通道，请参见::HI_UNF_AVPLAY_MEDIA_CHAN_E
\param[in] pstStopOpt   Pointer to the clear screen mode. For details, see the description of ::HI_UNF_AVPLAY_STOP_OPT_S. CNcomment:指针类型，清屏模式，请参见::HI_UNF_AVPLAY_STOP_OPT_S
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Stop(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn, const HI_UNF_AVPLAY_STOP_OPT_S *pstStopOpt);

/**
\brief Pauses an AVPLAY. Then the AVPLAY is in pause mode. CNcomment:暂停AV播放，进入PAUSE状态
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment: AV播放句柄
\param[in] pstPauseOpt  Pointer used for expansion. You can set it to NULL. CNcomment:指针类型，待扩展使用，设为为NULL即可
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Pause(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_PAUSE_OPT_S *pstPauseOpt);

/**
\brief Plays videos or audios in trick play mode. Then the AVPLAY is in TPLAY mode. CNcomment:倍速播放，进入TPLAY状态
\attention \n
Before switching the mode to the trick play mode, you must enable a decoder to decode only I frames by calling HI_UNF_AVPLAY_SetDecodeMode API\n
CNcomment:进入TPLAY状态前，必须调用HI_UNF_AVPLAY_SetDecodeMode接口把解码器设置为只解I帧模式\n
\param[in] hAvplay  AVPLAY handle CNcomment: AV播放句柄
\param[in] pstTplayOpt   Pointer used for expansion. You can set it to NULL. CNcomment:指针类型，待扩展使用，设为为NULL即可
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Tplay(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_TPLAY_OPT_S *pstTplayOpt);

/**
\brief Plays videos or audios in trick play mode. Then the AVPLAY is in fast forward mode. CNcomment:设置AVPLAY为快进模式
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment: AV播放句柄
\param[in] bEnable  FFMode Enable Flag CNcomment: 快进使能标志
\param[in] u32Speed AVPLAY play speed CNcomment: AV播放句柄
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SetPlayerFFMode(HI_HANDLE hAvplay, HI_BOOL bEnable, HI_U32 u32Speed);

/**
\brief Resumes an AVPLAY. Then the AVPLAY is in play mode. CNcomment:恢复AV播放，进入PLAY状态
\attention \n
By calling this API, you can resume an AVPLAY from the trick play mode or pause mode rather than the stop mode.
CNcomment:本接口用来将倍速或暂停状态恢复为播放状态，但无法将停止状态恢复为播放状态。
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\param[in] pstResumeOpt  Pointer used for expansion. You can set it to NULL. CNcomment:指针类型，待扩展使用，暂置为空即可
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Resume(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_RESUME_OPT_S *pstResumeOpt);

/**
\brief Resets an AVPLAY. In this case, the play mode is not changed. CNcomment:复位AV播放，不改变状态
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\param[in] pstResetOpt   Pointer used for expansion. You can set it to NULL. CNcomment:指针类型，待扩展使用，设为为NULL即可
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Reset(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_RESET_OPT_S *pstResetOpt);

/**
\brief Applies for a buffer for storing the streams played by an AVPLAY. CNcomment:申请AV播放的码流缓冲
\attention \n
This API is used only when you want to play the ESs obtained from Internet or local ESs.\n
The pstData parameter is used to return the start address and size of the buffer applied for.\n
If u32TimeOutMs is set to 0, it indicates that the waiting time is 0; if u32TimeOutMs is set to 0XFFFFFFFF, it indicates that the API waits for an infinite time; if u32TimeOutMs is set to other values, it indicates that the waiting time is u32TimeOutMs ms.\n
If no buffer can be applied for during the block period, an error code indicating full buffer is returned.\n
If u32TimeOutMs is set to 0, and no buffer can be applied for, it indicates that the audio and video buffers are full. In this case, you need to call the usleep(N*1000) function to release the CPU.
Therefore, other threads can be scheduled.
CNcomment:当播放网络或本地ES流时才需要使用本接口。\n
参数pstData用来返回成功申请到的Buffer的首地址以及大小。\n
u32TimeOutMs设置为0表示不等待，设置为0xffffffff表示一直等待，设置为其他值表示等待u32TimeOutMs毫秒。\n
若超过阻塞时间，还无法申请到Buffer，则返回buffer满错误码\n
u32TimeOutMs配置为0时，如果申请不到Buffer，说明此时音视频的Buffer已满，需要通过usleep(N*1000)释放cpu
以使其它线程能够得到调度。
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\param[in] enBufId     Buffer queue ID CNcomment:缓冲队列ID
\param[in] u32ReqLen   Size of the buffer applied for CNcomment:申请缓存的大小
\param[out] pstData    Pointer to the returned buffer CNcomment:返回缓存指针
\param[in] u32TimeOutMs      Wait timeout, in ms CNcomment:等待超时时间，单位ms
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetBuf(HI_HANDLE  hAvplay,
                            HI_UNF_AVPLAY_BUFID_E enBufId,
                            HI_U32                u32ReqLen,
                            HI_UNF_STREAM_BUF_S  *pstData,
                            HI_U32                u32TimeOutMs);

/**
\brief Updates the write pointer after data is successfully copied. CNcomment:拷贝数据成功后，更新写指针
\attention \n
After transmitting streams to the buffer applied for, you can call this API to update the write pointer of the audio and video buffers.\n
If the transmitted streams do not contain PTS, u32ptsMs must be set to –1.
CNcomment:在向申请到的缓冲区内送码流完毕后，调用本接口更新音视频缓冲区的写指针。\n
如果本次送入的码流没有对应的PTS，u32ptsMs必须为-1。
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\param[in] enBufId     Buffer queue ID CNcomment:缓冲队列ID
\param[in] u32ValidDataLen     Number of bytes that are written to the buffer CNcomment:实际写入缓冲区的字节数
\param[in] u32PtsMs            PTS, in ms  CNcomment:时间戳,以毫秒为单位
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_PutBuf(HI_HANDLE hAvplay, HI_UNF_AVPLAY_BUFID_E enBufId,
                         HI_U32 u32ValidDataLen, HI_U32 u32PtsMs);


/**
\brief Sets the speed in slow playing mode. CNcomment:设置慢放的速度
\attention \n
You can set the speed in slow playing mode. The value 1 indicates the normal speed, and the value 2 indicates the half of the normal speed. If you want to switch the slow playing mode to normal mode, you can set u32Repeat to 1 by calling this API.
CNcomment:设置慢放的速度。1代表正常，2代表2分之1速度。如果要从慢放恢复到正常播放,仍调用该接口，u32Repeat设置为1
\param[in] hAvplay             AVPLAY handle CNcomment:AV播放句柄
\param[in] u32Repeat           Slow playing speed CNcomment:慢放速度
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SetWindowRepeat(HI_HANDLE hAvplay, HI_U32 u32Repeat);


/**
\brief Obtains the handle of the DMX audio channel used by an AVPLAY in TS mode. CNcomment:TS模式时获取AV播放器使用的DMX音频通道的Handle
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\param[in] phDmxAudChn    Pointer to the handle of a DMX audio channel CNcomment:DMX音频通道Handle指针
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetDmxAudChnHandle(HI_HANDLE hAvplay, HI_HANDLE *phDmxAudChn);

/**
\brief Obtains the handle of the DMX video channel used by an AVPLAY in TS mode. CNcomment:TS模式时获取AV播放器使用的DMX视频通道的Handle
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV播放句柄
\param[in] phDmxVidChn    Pointer to the handle of a DMX video channel CNcomment:DMX视频通道Handle指针
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetDmxVidChnHandle(HI_HANDLE hAvplay, HI_HANDLE *phDmxVidChn);


/**
\brief Obtains the status information about an AVPLAY. CNcomment:获取AV播放状态信息
\attention \n
The parameter stSyncStatus in the data type pstStatusInfo indicates the current synchronization status. This parameter can be used to implement synchronization such as subtitle synchronization.\n
enRunStatus indicates the status of an AVPLAY.\n
u32VidFrameCount indicates the number of played video frames, and u32AuddFrameCount indicates the number of played audio frames.\n
In ES mode, you can query the statuses of the audio and video buffers by checking the stBufStatus parameter.
CNcomment:结构体pstStatusInfo中参数stSyncStatus表示获取的当前同步状态，可以用来支持外挂字幕等的同步。\n
enRunStatus表示获取的AV播放器整体状态。\n
u32VidFrameCount和u32AuddFrameCount用来表示当前音视频已播放的帧数。\n
如果是ES模式，可以通过stBufStatus查询音视频Buffer的状态。
\param[in] hAvplay  AVPLAY handle  CNcomment:AV播放句柄
\param[out] pstStatusInfo  Pointer to the status of an AVPLAY. For details, see the description of HI_UNF_AVPLAY_STATUS_INFO_S. CNcomment:指针类型，AV播放状态信息，请参见HI_UNF_AVPLAY_STATUS_INFO_S
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetStatusInfo(HI_HANDLE          hAvplay,
                                 HI_UNF_AVPLAY_STATUS_INFO_S *pstStatusInfo);


/**
\brief Obtains the information about audio and video streams. CNcomment:获取音视频码流信息
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle  CNcomment:AV播放句柄
\param[in] pstStreamInfo     Pointer to the information about audio and video streams. For details, see the description of HI_UNF_AVPLAY_STREAM_INFO_S. CNcomment:指针类型，音视频码流信息，请参见HI_UNF_AVPLAY_STREAM_INFO_S
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetStreamInfo(HI_HANDLE          hAvplay,
                                   HI_UNF_AVPLAY_STREAM_INFO_S *pstStreamInfo);

/**
\brief Obtains the information audio spectrums. CNcomment:获取音频能量信息
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle  CNcomment:AV播放句柄
\param[in] pSpectrum      Pointer to the array of audio spectrums. CNcomment:指针类型，音频能量信息数组指针
\param[in] u32BandNum     Length of an audio spectrum array CNcomment:音频能量信息数组长度
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:操作非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetAudioSpectrum(HI_HANDLE hAvplay, HI_U16 *pSpectrum, HI_U32 u32BandNum);

/**
\brief Queries whether the AVPLAY buffer is empty. CNcomment:查询AVPLAY buffer是否已经为空
\attention \n
N/A
\param[in] hAvplay        AVPLAY handle CNcomment:AV播放句柄
\param[out] pbIsEmpty      Pointer type. This pointer indicates whether the AVPLAY buffer is empty (the playing ends). CNcomment:指针类型，指示buffer是否已经为空(播放完成)
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_IsBuffEmpty(HI_HANDLE hAvplay, HI_BOOL * pbIsEmpty);

/**
\brief Switch the demux audio channel CNcomment:切换音频DEMUX句柄
\attention \n
N/A
\param[in] hAvplay       AVPLAY handle CNcomment: AV播放句柄
\param[in] hNewDmxAud     New demux audio handle CNcomment:新DMX句柄
\param[out] phOldDmxAud     Old  demux audio handle CNcomment:旧DMX句柄指针
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAY未初始化
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:输入指针为空
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:输入参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SwitchDmxAudChn(HI_HANDLE hAvplay, HI_HANDLE hNewDmxAud, HI_HANDLE *phOldDmxAud);




/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif

#endif
