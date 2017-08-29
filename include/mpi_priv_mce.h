#ifndef __MPI_PRIV_MCE_H__
#define __MPI_PRIV_MCE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

#include "hi_unf_common.h"
#include "hi_unf_vo.h"
#include "hi_unf_mce.h"

#define DEF_CHECK_FLAG 0x5a5a5a5a

#define __FASTPLAY_VERISON__ "ver0001\0"

typedef struct hiMCE_Param_S
{
	HI_U32 u32Size;
	HI_U32 u32StartPhyAddr;
}MCE_PARAM_S;


typedef struct mce_Base_Info_S
{
	unsigned int checkflag;
	unsigned int hdIntf;
	unsigned int sdIntf;
	unsigned int hdFmt;
	unsigned int sdFmt;
	unsigned int scart;
	unsigned int Bt1120;
	unsigned int Bt656;
	unsigned int dac[6];
	unsigned int layerformat;
	unsigned int inrectwidth;
	unsigned int inrectheight;
	unsigned int outrectwidth;
	unsigned int outrectheight;
	unsigned int usewbc;
	unsigned int resv1;
	unsigned int resv2;
	unsigned int logoMtdSize; 
	unsigned int playMtdSize; 
	char chVersion[8];
	unsigned int u32Top;
	unsigned int u32Left;
	unsigned int u32HuePlus;
	unsigned int u32Saturation;
	unsigned int u32Contrast;
	unsigned int u32Brightness;
	HI_UNF_DISP_BG_COLOR_S enBgcolor;
	HI_UNF_ASPECT_RATIO_E enAspectRatio;
	HI_UNF_ASPECT_CVRS_E enAspectCvrs;
	HI_UNF_DISP_MACROVISION_MODE_E enDispMacrsn;
  // this struct record lvds interface paramters.
  HI_UNF_DISP_LCD_PARA_S sLcdPara;  
}MCE_BASE_INFO_S;
typedef struct  mce_fastboot_info
{
    unsigned int checkflag;
    
    unsigned int baseparamoffset;         //Base Param Offset:     0x0000
    unsigned int baseparamsize;         //Base Param size:     0x2000

    unsigned int logoparamoffet;         //Logo Param Offset:     0x2000
    unsigned int logoparamsize;         //Logo Param size:     0x2000
    
    unsigned int logodataoffset;          //Logo Data Offset:      0x4000
    unsigned int logodatasize;           //Logo Data Size:user decision or cal by real size

    unsigned int fastplayparamoffset;     //Fastplay Param Offset: 0x4000+logosize
    unsigned int fastplayparamsize;     //Fastplay Param size: 0x2000
    
    unsigned int fastplaydataoffset;      //Fastplay Data Offset:  0x6000+logosize
    unsigned int fastplaydatasize;      //Fastplay Data Size:    user decision or cal by real size
}MCE_FASTBOOT_INFO;

typedef struct mce_Logo_Info_S
{
	unsigned int checkflag;
	unsigned int contentLen;
	unsigned int logoflag;
	char chVersion[8];
   	unsigned int u32XPos;
	unsigned int u32YPos;
	unsigned int u32OutWidth;
	unsigned int u32OutHeight;
	unsigned int u32BgColor;
}MCE_LOGO_INFO_S;

typedef struct mce_Dvb_Info_S
{
	//program
	unsigned int PcrPid;
	unsigned int u32PlayTime;								/**<play time */
	unsigned int VElementPid;
	unsigned int AElementPid;
	HI_UNF_VCODEC_TYPE_E VideoType;
	unsigned int AudioType;
	//tuner
	unsigned int tunerId;
	unsigned int tunerFreq;
	unsigned int tunerSrate;
	unsigned int tunerQam;
	//audio
	unsigned int volume;
	HI_UNF_TRACK_MODE_E  trackMode;
	// vid
	HI_UNF_VO_DEV_MODE_E       devMode;
	unsigned int    tunerDevType;
	unsigned int    demoDev;
	unsigned int  I2cChannel; 
	char chVersion[8];
}MCE_DVB_INFO_S;

typedef struct mce_TsFile_Info_S
{
	// file
	unsigned int contentLen;
	unsigned int IsCycle;	
	unsigned int u32PlayTime;								/**<play time */
	//program
	unsigned int PcrPid;
	unsigned int VElementPid;
	unsigned int AElementPid;
	HI_UNF_VCODEC_TYPE_E VideoType;
	unsigned int AudioType;
	//audio
	unsigned int volume;
	HI_UNF_TRACK_MODE_E trackMode;
	// vid
	HI_UNF_VO_DEV_MODE_E devMode;
	char chVersion[8];	
}MCE_TSFILE_INFO_S;


typedef struct mce_GphFile_Info_S
{
	HI_UNF_PIC_COMMINFO comInfo;
	HI_UNF_PIC_PICTURE	   *ppicInfo;
}MCE_GPHFILE_INFO_S;


typedef enum  mce_Play_Type_E
{
	MCE_PLAY_TYPE_DVB	  = 0x11111111,  
	MCE_PLAY_TYPE_TSFILE  = 0x22222222,  
	MCE_PLAY_TYPE_GPHFILE = 0x44444444  
}MCE_PLAY_TYPE_E;


typedef struct mce_Play_Info_S
{
	unsigned int checkflag;
	MCE_PLAY_TYPE_E playType;
	unsigned int fastplayflag;
	union 
	{
		MCE_DVB_INFO_S     dvbInfo;
		MCE_TSFILE_INFO_S  tsFileInfo;
		MCE_GPHFILE_INFO_S gphFileInfo; 
	}Info;
}MCE_PLAY_INFO_S;


#define HI_MCE_LOGO_EXIT_CMD          _IO(HI_ID_MCE, 0x01   )
#define HI_MCE_VID_EXIT_CMD             _IO(HI_ID_MCE, 0x02   )
#define HI_MCE_GET_PALY_TIME           _IO(HI_ID_MCE, 0x03   )
#define HI_MCE_CLEAR_LOGO_CMD          _IO(HI_ID_MCE, 0x04 )
#define HI_MCE_STOP_FASTPLAY_CMD       _IOW(HI_ID_MCE, 0x05, HI_UNF_MCE_STOPPARM_S)
#define HI_MCE_GET_PLAY_CUR_STATUS_CMD       _IOR(HI_ID_MCE, 0x06, HI_UNF_MCE_PLAYCURSTATUS_S)


#define HI_MCE_TEST_AV_BEGIN           _IO(HI_ID_MCE, 0x10   )
#define HI_MCE_TEST_AV_END              _IO(HI_ID_MCE, 0x11   )
#define HI_MCE_TEST_AV_PRE      	        _IO(HI_ID_MCE, 0x12   )                
#define HI_MCE_TEST_AV_POST            _IO(HI_ID_MCE, 0x13   )
#define HI_MCE_TEST_AV_PARAM      	 _IOR(HI_ID_MCE, 0x14, MCE_PARAM_S)           






#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

