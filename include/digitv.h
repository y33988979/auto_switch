/*******************************************************************************
    Copyright (C), 2004-2007, YOUNGSUN. Co., Ltd.

    File name : digitv.h

    Description : 数字电视的应用
 
    Others:      
    
    History: 	1. 2004-3-15 yzb Create
    			2. 2011-11-2 xyan Modify

*******************************************************************************/
#ifndef _DTV_H
#define _DTV_H

/*----------------------------------------------------------------------------
 *	Include
 *----------------------------------------------------------------------------*/
#include "stbtype.h"        
#include "driver.h"     	
#include "midware.h"        
//#include "midcas.h"

/*----------------------------------------------------------------------------
 *	Define
 *----------------------------------------------------------------------------*/
/*DTV显示时间定义*/
#define DTV_BANNER_SHOW_TIME    				5000   /*Banner显示时间*/
#define DTV_SHOW_CHNL_NUM_TIME  				5000   /*频道号显示时间*/
#define DTV_SHOW_VOLUME_TIME    				3000   /*音量条显示时间*/
#define DTV_RECOVER_VOLUME_TIME    				1000   /*DTV切台恢复音量时间*/
#define TIME_UPDATE_TIME						5000   /*应用更新间隔时间*/

/*DTV音量定义*/
#define MIN_VOLUME_SET							63	//对应驱动最小声音
#ifdef _VOLUME_32_
#define DTV_MAX_VOLUME							32
#else
#define DTV_MAX_VOLUME							63
#endif

#define DTV_INVALID_TS         					0xFFFF
#define DTV_INVALID_CHANNEL    					0xFFFF 
#define DTV_SystemTimeAdjuested					TDTReceived

/*----------------------------------------------------------------------------
 *	Struct
 *----------------------------------------------------------------------------*/
typedef enum 
{
	DTV_MSG_PROCESSED,      /*消息已被处理*/
    DTV_MSG_NOT_PROCESSED	/*消息未被处理*/
}DTV_Msg_Process_Status;

typedef enum
{
	DTV_PLAY_DTV = 1,		/*电视播放状态*/
	DTV_PLAY_RADIO = 2,		/*广播播放状态*/
	DTV_PLAY_COUNT
}DTV_Play_state;

typedef enum
{
	DTV_BANNER_SHOW,		/*Banner显示*/
	DTV_VOLUME_SHOW,		/*音量条显示*/
	DTV_BANNER_HIDE,		/*Banner隐藏*/
	DTV_BANNER_STATUS_COUNT
}DTV_BannerStatus_e;

typedef enum
{
	NO_AD,					/*无广告*/
    BMP_AD,					/*BMP广告*/
    GIF_AD,					/*GIF广告*/
    JPG_AD					/*JPEG广告*/
}DTV_BannerAdType_e;

typedef enum 
{
	DTV_CA_MSG_INVALID = CA_MSGCODE_BASE,
	DTV_CA_SHOW_BUY,		/*显示CA提示*/
	DTV_CA_HIDE_BUY,		/*清除CA提示*/
	DTV_CA_SHOW_FINGER,		/*显示CA指纹*/
	DTV_CA_HIDE_FINGER,		/*清除CA指纹*/
	DTV_CA_SHOW_TOPOSD,		/*显示CA上滚动*/
	DTV_CA_HIDE_TOPOSD,		/*清除CA上滚动*/
	DTV_CA_SHOW_BOTOSD,		/*显示CA下滚动*/
	DTV_CA_HIDE_BOTOSD,		/*清除CA下滚动*/
	DTV_CA_SHOW_MAIL,		/*显示CA邮件*/
	DTV_CA_EXHAUST_MAIL,	/*闪烁CA邮件*/
	DTV_CA_HIDE_MAIL,		/*清除CA邮件*/
	DTV_CA_SHOW_DETITLE,	/*显示CA反授权*/
	DTV_CA_EXHAUST_DETITLE,	/*闪烁CA反授权*/
	DTV_CA_HIDE_DETITLE,	/*清除CA反授权*/
	DTV_CA_SHOW_FEEDING,	/*显示CA喂养*/
	DTV_CA_HIDE_FEEDING,	/*清除CA喂养*/
	DTV_CA_SHOW_IPPV,		/*显示CA IPPV购买*/
	DTV_CA_HIDE_IPPV,		/*清除CA IPPV购买*/
	DTV_CA_SHOW_UPGRADE,	/*显示CA升级信息*/
	DTV_CA_HIDE_UPGRADE,	/*清除CA升级信息*/
	DTV_CA_MSG_COUNT  
}DTV_CAMsg_Type;

typedef enum 
{
	DTV_USER_MSG_INVALID = DTV_USER_BASE,
	DTV_USER_CHANGE_CHNL,	/*普通切台消息*/
	DTV_USER_CHANGE_TO_TV,	/*切换到TV模式消息*/
	DTV_USER_CHANGE_TO_RADIO,/*切换到Radio模式消息*/
	DTV_USER_RESET_CAINFO,	/*重新设置当前播放节目CA参数消息*/
	DTV_USER_REPLAY_AV,		/*重新启动当前节目播放消息*/
	DTV_USER_REPLAY,		/*重新播放当前节目消息*/
	DTV_USER_REFRESH_PLAY,	/*刷新当前频道并重新播放消息*/
	DTV_USER_CLEAR_BANNER,	/*清除Banner显示消息*/
	DTV_USER_CLEAR_CHNL_NUM,/*清除频道号显示消息*/
	DTV_USER_RECOVER_VOLUME,/*设置音量消息*/
	DTV_USER_COUNT
}DTV_UserMsg_e;

typedef enum 
{  
	DTV_START_FROM_POWER_OFF = 0,	/*DTV从待机中重启*/
	DTV_START_FROM_APP = 0x01,		/*DTV从应用退出后重启*/
	DTV_START_FROM_COUNT
}DTV_Start_From_e;

 /*DTV模块的错误码*/
typedef enum 
{
	DTV_SUCCESS,		/*DTV操作成功*/
	DTV_FAILED,			/*DTV操作失败*/
	DTV_INVALID_CHNL = DTV_ERROR_BASE,	/*频道号无效*/
	DTV_CHANGE_TS_FAILED,/*切频点失败*/
	DTV_PLAYAV_FAILED,	/*播放失败*/
	DTV_START_FAILED,	/*启动DTV失败*/
	DTV_SUSPEND_FAILED,	/*挂起DTV失败*/
	DTV_ERROR_COUNT
}DTV_ErrorCode_e;

typedef struct 
{
	unsigned short usCurrentTS;			/*DTV当前节目的TsNo*/
	unsigned short usCurrentChannel;	/*DTV当前电视频道号*/	
	unsigned short usCurrentRadioChannel;/*DTV当前广播频道号*/	
	unsigned short usLastChannel;		/*DTV上一个电视频道号*/	
	unsigned short usLastRadioChannel;	/*DTV上一个广播频道号*/	
	unsigned char ucCurrentVolume;		/*DTV当前节目音量值*/
	unsigned char ucCurrentTrack;		/*DTV当前节目声道值*/

    unsigned char ucDigKeyInputMode;	/*DTV频道号输入模式*/
    unsigned char ucDigKeyInputedNum;	/*已有输入个数*/
    unsigned char aucDigKeyInput[3];	/*保存已有输入键值*/

	BOOL bMute;				/*DTV静音标示*/
	BOOL bRegionShow;		/*DTVRegion显示标示*/
	BOOL bIdle;				/*DTV是否挂起标示(TRUE为挂起,FALSE为非挂起)*/
	BOOL bDTVPlay;			/*DTV是否播放标示*/
	BOOL bChnlNumShow;		/*DTV频道号显示标示*/
	BOOL bTvOrRadioRestart;	/*强制切台标示*/
	
	DTV_BannerStatus_e BannerStatus;	/*DTV Banner条显示状态*/
} DTV_State_t;

/*----------------------------------------------------------------------------
 *	External variable
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 *	Global functions
 *----------------------------------------------------------------------------*/
/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_IsDTVStart
  Description     : 获取DTV是否开始运行标示
  Input           : 
  Outut           : TRUE为DTV已经运行,FALSE为DTV尚未运行
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
BOOL DTV_IsDTVStart(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetCurrentChannel
  Description     : 获取DTV当前频道号
  Input           : 
  Outut           : DTV当前播放的频道号
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned short DTV_GetCurrentChannel(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetLastChannel
  Description     : 获取DTV前一个播放的频道号
  Input           : 
  Outut           : DTV前一个播放的频道号
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned short DTV_GetLastChannel(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetCurrentVolume
  Description     : 获取DTV当前播放频道音量值
  Input           : 
  Outut           : DTV当前播放频道的音量值
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned char DTV_GetCurrentVolume(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SetCurrentVolume
  Description     : 设置DTV当前播放频道的音量值
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_SetCurrentVolume(unsigned char ucVol);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetCurrentTrack
  Description     : 获取DTV当前播放频道的声道值
  Input           : 
  Outut           : DTV当前频道播放的声道值
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned char DTV_GetCurrentTrack(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SetCurrentTrack
  Description     : 设置DTV当前播放频道的声道值
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_SetCurrentTrack(unsigned char ucTrack);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetCurrentTsNo
  Description     : 获取DTV当前播放频道的TsNo
  Input           : 
  Outut           : DTV当前频道的TsNo
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned short DTV_GetCurrentTsNo(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SetCurrentTsNo
  Description     : 设置DTV当前播放频道的TsNo
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_SetCurrentTsNo(unsigned short usTsNo);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetDTVMute
  Description     : 获取DTV当前静音标识
  Input           : 
  Outut           : DTV当前静音标识
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
BOOL DTV_GetDTVMute(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SetDTVMute
  Description     : 设置DTV当前静音标识
  Input           : 静音标识
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_SetDTVMute(BOOL bMute);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetDTVSuspendFlag
  Description     : 获取DTV当前是否挂起标示
  Input           : 
  Outut           : DTV当前挂起标示
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
BOOL DTV_GetDTVSuspendFlag(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SetDTVSuspendFlag
  Description     : 设置DTV当前是否挂起标示
  Input           : 
  Outut           : DTV当前挂起标示
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_SetDTVSuspendFlag(BOOL bFlag);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetModeToChange
  Description     : 获取DTV即将切换的模式
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned int DTV_GetModeToChange(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SetModeToChange
  Description     : 设置DTV即将切换的模式
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_SetModeToChange(unsigned int uiMode);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_GetChnlNumToChange
  Description     : 获取DTV即将切换的频道号
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned short DTV_GetChnlNumToChange(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SetChnlNumToChange
  Description     : 设置DTV即将切换的频道号
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_SetChnlNumToChange(unsigned short usChnlNum);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SendDTVMsg
  Description     : 给DTV发送消息
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned int DTV_SendDTVMsg (MSG_MsgInfo_t *pstMsgInfo);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_DelTimeMsg
  Description     : 删除DTV定时消息
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : DTV定时消息使用MSG_CLASS_TIME类型
*****************************************************************************/ 
void DTV_DelTimeMsg(unsigned int uiMsgCode);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_AddTimeMsg
  Description     : 给DTV发送定时消息
  Input           : uiMsgCode为消息体,uiTime为毫秒发送时间
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : DTV定时消息使用MSG_CLASS_TIME类型
*****************************************************************************/ 
void DTV_AddTimeMsg(unsigned int uiMsgCode,unsigned int uiTime);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SendStartDTVMsg
  Description     : 给DTV发送启动DTV的消息
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
BOOL DTV_SendStartDTVMsg(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_SendSuspendDTVMsg
  Description     : 给DTV发送挂起DTV的消息
  Input           : 要灌背景I帧的数据指针和数据大小
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
BOOL DTV_SendSuspendDTVMsg(unsigned char *pFrameData,unsigned int FrameSize);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_ChangeChannelMsg
  Description     : 给DTV发送切台消息
  Input           : PlayStatus为要切换的DTV状态,ChnlNo为要切的频道号
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned int DTV_ChangeChannelMsg(int PlayStatus,unsigned short ChnlNo);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_ChangeChannelTmMsg
  Description     : 给DTV发送定时切台消息
  Input           : PlayStatus为要切换的DTV状态,ChnlNo为要切的频道号
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_ChangeChannelTmMsg(int PlayStatus,unsigned short ChnlNo);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_ChangeToTvMsg
  Description     : 给DTV发送切换到TV的消息
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned int DTV_ChangeToTvMsg(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_ChangeToRadioMsg
  Description     : 给DTV发送切换到Radio的消息
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
unsigned int DTV_ChangeToRadioMsg(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_ForceStartDTV
  Description     : 强制启动DTV
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_ForceStartDTV(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_ForceSuspendDTV
  Description     : 强制挂起DTV
  Input           : 
  Outut           : 
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/ 
void DTV_ForceSuspendDTV(void);

/*****************************************************************************
  Date&Time       : 2009-04-24
  Author          :   xyan
  Function Name   : DTV_ManagerTaskInit
  Description     : DTV管理任务初始化
  Input           : 
  Outut           : TRUE为初始化成功;FALSE为初始化失败
  Calls           : 
  Called by       :
  Global Variables: 
  Others          : 
*****************************************************************************/
BOOL DTV_ManagerTaskInit(void);

#endif 

