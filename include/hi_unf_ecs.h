/******************************************************************************

  Copyright (C), 2001-2011, HiSilicon Technologies Co., Ltd.
 ******************************************************************************
 File Name     : hi_unf_ecs_type.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date   : 2008-06-05
Last Modified by:
Description   : Application programming interfaces (APIs) of the external chip software (ECS)
Function List :
Change History:
 ******************************************************************************/
#ifndef __HI_UNF_ECS_TYPE_H__
#define __HI_UNF_ECS_TYPE_H__

#include "hi_common.h"
#include "hi_error_ecs.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define HI_I2C_MAX_NUM_USER (15)    /**<Maximum I2C channel ID*/ /**<CNcomment:最大I2C通道号*/

#define HI_UNF_DISEQC_MSG_MAX_LENGTH (6)    /**<DiSEqC message length*/  /**<CNcomment:DiSEqC消息长度*/
#define HI_UNF_DISEQC_MAX_REPEAT_TIMES (4)  /**<DiSEqC message max repeat times*/
#define MAX_TS_LINE 11                      /** The NO of ts lines that can be configured*/ /** CNcomment:可配置的ts信号线数量*/

#ifdef DISEQC_SUPPORT
#define DISEQC_MAX_MOTOR_PISITION (255) /**<DiSEqC motor max stored position*/ 
#endif /* DISEQC_SUPPORT */
/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_1 */
/** @{ */  /** <!-- [QAM] */

/**Quadrature amplitude modulation (QAM) mode*/
/**CNcomment: QAM调制方式*/
typedef enum hiUNF_QAM_TYPE_E
{
    HI_UNF_MOD_TYPE_DEFAULT,          /**<Default QAM mode. The default QAM mode is HI_UNF_MOD_TYPE_QAM_64 at present.*/   /**<CNcomment:默认的QAM类型, 当前系统默认为HI_UNF_MOD_TYPE_QAM_64 */
    HI_UNF_MOD_TYPE_QAM_16 = 0x100,   /**<Enumeration corresponding to the 16QAM mode*/                                    /**<CNcomment:16QAM对应的枚举值*/
    HI_UNF_MOD_TYPE_QAM_32,           /**<Enumeration corresponding to the 32QAM mode*/                                    /**<CNcomment:32QAM对应的枚举值*/
    HI_UNF_MOD_TYPE_QAM_64,           /**<Enumeration corresponding to the 64QAM mode*/                                    /**<CNcomment:64QAM对应的枚举值*/
    HI_UNF_MOD_TYPE_QAM_128,          /**<Enumeration corresponding to the 128QAM mode*/                                   /**<CNcomment:128QAM对应的枚举值*/
    HI_UNF_MOD_TYPE_QAM_256,          /**<Enumeration corresponding to the 256QAM mode*/                                   /**<CNcomment:256QAM对应的枚举值*/
    HI_UNF_MOD_TYPE_QAM_512,          /**<Enumeration corresponding to the 512QAM mode*/                                   /**<CNcomment:512QAM对应的枚举值*/

    HI_UNF_MOD_TYPE_BPSK = 0x200,     /**<Enumeration corresponding to the binary phase shift keying (BPSK) QAM mode. This mode is not supported at present.*/         /**<CNcomment:BPSK QAM对应的枚举值，暂不支持*/
    HI_UNF_MOD_TYPE_QPSK = 0x300,     /**<Enumeration corresponding to the quaternary phase shift keying (QPSK) QAM mode. This mode is not supported at present.*/     /**<CNcomment:QPSK QAM对应的枚举值，暂不支持*/
    HI_UNF_MOD_TYPE_DQPSK,
    HI_UNF_MOD_TYPE_8PSK,             /**<Enumeration corresponding to the 8 phase shift keying (8PSK) mode*/              /**<CNcomment:8PSK对应的枚举值*/
    HI_UNF_MOD_TYPE_16APSK,           /**<Enumeration corresponding to the 16-Ary Amplitude and Phase Shift Keying (QPSK) mode*/      /**<CNcomment:16APSK对应的枚举值*/
    HI_UNF_MOD_TYPE_32APSK,           /**<Enumeration corresponding to the 32-Ary Amplitude and Phase Shift Keying (QPSK) mode*/      /**<CNcomment:32APSK对应的枚举值*/
    HI_UNF_MOD_TYPE_8VSB,           /**<Enumeration corresponding to (8VSB) mode*/      /**<CNcomment:8VSB对应的枚举值*/
    HI_UNF_MOD_TYPE_16VSB,           /**<Enumeration corresponding to (16VSB) mode*/      /**<CNcomment:16VSB对应的枚举值*/

    /**<Enumeration corresponding to the auto mode. For DVB-S/S2, if detect modulation type fail, it will return auto*/
    /**<CNcomment:卫星信号调制方式自动检测，如果检测失败返回AUTO*/
    HI_UNF_MOD_TYPE_AUTO,

    HI_UNF_MOD_TYPE_BUTT              /**<Invalid QAM mode*/       /**<CNcomment:非法的QAM类型枚举值*/
}HI_UNF_MODULATION_TYPE_E;

/**Frequency locking status of the tuner*/
/**CNcomment:TUNER锁频状态*/
typedef enum  hiUNF_TUNER_LOCK_STATUS_E
{
    HI_UNF_TUNER_SIGNAL_DROPPED = 0,      /**<The signal is not locked.*/  /**<CNcomment:信号未锁定*/
    HI_UNF_TUNER_SIGNAL_LOCKED,            /**<The signal is locked.*/  /**<CNcomment:信号已锁定*/
    HI_UNF_TUNER_SIGNAL_BUTT             /**<Invalid value*/   /**<CNcomment:非法边界值*/
}HI_UNF_TUNER_LOCK_STATUS_E;

/**Output mode of the tuner*/
/**CNcomment:TUNER输出模式 */
typedef enum hiUNF_TUNER_OUTPUT_MODE_E
{
    HI_UNF_TUNER_OUTPUT_MODE_DEFAULT ,            /**<Parallel mode valid*/        /**<CNcomment:并行模式valid*/
    HI_UNF_TUNER_OUTPUT_MODE_PARALLEL_MODE_A,     /**<Parallel mode valid*/     /**<CNcomment:并行模式valid*/
    HI_UNF_TUNER_OUTPUT_MODE_PARALLEL_MODE_B,     /**<Parallel mode burst*/     /**<CNcomment:并行模式burst*/
    HI_UNF_TUNER_OUTPUT_MODE_SERIAL,              /**<Serial mode 74.25M*/  /**<CNcomment:串行模74.25M*/ 
    HI_UNF_TUNER_OUTPUT_MODE_SERIAL_50,           /**<Serial mode 50M*/     /**<CNcomment:串行模50M*/
    HI_UNF_TUNER_OUTPUT_MODE_BUTT                 /**<Invalid value*/       /**<CNcomment:非法值*/
}HI_UNF_TUNER_OUPUT_MODE_E;

/**Signal type of the tuner*/
/**CNcomment:TUNER信号类型*/
typedef enum    hiTUNER_SIG_TYPE_E
{
    HI_UNF_TUNER_SIG_TYPE_CAB = 0  ,   /**<Cable signal*/      /**<CNcomment:CABLE信号*/
    HI_UNF_TUNER_SIG_TYPE_SAT ,        /**<Satellite signal*/  /**<CNcomment:卫星信号*/
    HI_UNF_TUNER_SIG_TYPE_DVB_T  ,       /**<Terrestrial signal*//**<CNcomment:地面信号*/
    HI_UNF_TUNER_SIG_TYPE_DVB_T2  ,       /**<Terrestrial signal*//**<CNcomment:地面信号*/
    HI_UNF_TUNER_SIG_TYPE_ISDB_T  ,       /**<Terrestrial signal*//**<CNcomment:地面信号*/
    HI_UNF_TUNER_SIG_TYPE_ATSC_T  ,       /**<Terrestrial signal*//**<CNcomment:地面信号*/
    HI_UNF_TUNER_SIG_TYPE_DTMB  ,       /**<Terrestrial signal*//**<CNcomment:地面信号*/
    HI_UNF_TUNER_SIG_TYPE_BUTT         /**<Invalid value*/     /**<CNcomment:非法值*/
}HI_UNF_TUNER_SIG_TYPE_E;

/**Inter-integrated (I2C) channel used by the tuner*/
/**CNcomment:TUNER使用的I2C通道*/
typedef enum hiUNF_TUNER_I2cChannel
{
    HI_UNF_I2C_CHANNEL_0 = 0,      /**<I2C channel 0*/                               /**<CNcomment:I2C通道0*/
    HI_UNF_I2C_CHANNEL_1,          /**<I2C channel 1*/                               /**<CNcomment:I2C通道1*/
    HI_UNF_I2C_CHANNEL_2,          /**<I2C channel 2*/                               /**<CNcomment:I2C通道2*/
    HI_UNF_I2C_CHANNEL_3,          /**<I2C channel 3*/                               /**<CNcomment:I2C通道3*/
    HI_UNF_I2C_CHANNEL_QAM = 4,    /**<Dedicated I2C channel of the built-in QAM*/   /**<CNcomment:内置QAM专用I2C通道 */
    HI_UNF_I2C_CHANNEL_5,          /**GPIO simulates I2C*/                           /**CNcomment:GPIO模拟I2C*/
    HI_UNF_I2C_CHANNEL_6,               
    HI_UNF_I2C_CHANNEL_7,
    HI_UNF_I2C_CHANNEL_8,               
    HI_UNF_I2C_CHANNEL_9,               
    HI_UNF_I2C_CHANNEL_10,
    HI_UNF_I2C_CHANNEL_11,               
    HI_UNF_I2C_CHANNEL_12,               
    HI_UNF_I2C_CHANNEL_13,
    HI_UNF_I2C_CHANNEL_14,               
    HI_UNF_I2C_CHANNEL_15,               
    HI_UNF_I2C_CHANNEL_MAX        /**<Invalid value*/                               /**<CNcomment:非法边界值*/
}HI_UNF_TUNER_I2cChannel_E;

/**type of GPIO interrupt*/
/** CNcomment:GPIO 中断类型*/
typedef enum hiUNF_GPIO_INTTYPE_E
{
    HI_UNF_GPIO_INTTYPE_UP,          /**spring by the up edge*/                 /**<CNcomment:上升沿触发*/
	HI_UNF_GPIO_INTTYPE_DOWN,          /**spring by the down edge*/               /**<CNcomment:下降沿触发*/
	HI_UNF_GPIO_INTTYPE_UPDOWN,        /**spring by both the up and down edge*/   /**<CNcomment:双沿触发*/
	HI_UNF_GPIO_INTTYPE_HIGH,          /**spring by the high level*/              /**<CNcomment:高电平触发*/
	HI_UNF_GPIO_INTTYPE_LOW,           /**spring by the low level*/               /**<CNcomment:低电平触发*/
	HI_UNF_GPIO_INTTYPE_BUTT,          /**<Invalid value*/                        /**<CNcomment:非法边界值*/
}HI_UNF_GPIO_INTTYPE_E ;

/**type of TUNER device*/
/**CNcomment:TUNER设备类型*/
typedef enum    hiUNF_TUNER_DEV_TYPE_E
{
    HI_UNF_TUNER_DEV_TYPE_XG_3BL,               /**<XG_3BL*/
    HI_UNF_TUNER_DEV_TYPE_CD1616,               /**<CD1616*/
    HI_UNF_TUNER_DEV_TYPE_ALPS_TDAE,            /**<ALPS_TDAE*/
    HI_UNF_TUNER_DEV_TYPE_TDCC,                 /**<TDCC*/
    HI_UNF_TUNER_DEV_TYPE_TDA18250,             /**<TDA18250*/
    HI_UNF_TUNER_DEV_TYPE_CD1616_DOUBLE,
    HI_UNF_TUNER_DEV_TYPE_MT2081,				        /**<MT2081*/
    HI_UNF_TUNER_DEV_TYPE_TMX7070X,             /**<THOMSON7070X*/
    HI_UNF_TUNER_DEV_TYPE_R820C,             /**<R820C*/
	HI_UNF_TUNER_DEV_TYPE_MXL203,               /**< MXL203 */
    HI_UNF_TUNER_DEV_TYPE_AV2011,               /**<AV2011*/
    HI_UNF_TUNER_DEV_TYPE_SHARP7903,            /**<SHARP7903*/
    HI_UNF_TUNER_DEV_TYPE_MXL101,
    HI_UNF_TUNER_DEV_TYPE_MXL603,
    HI_UNF_TUNER_DEV_TYPE_IT9170,
    HI_UNF_TUNER_DEV_TYPE_IT9133,
    HI_UNF_TUNER_DEV_TYPE_TDA6651,
    HI_UNF_TUNER_DEV_TYPE_TDA18250B,             /**<TDA18250B*/

    HI_UNF_TUNER_DEV_TYPE_BUTT,                 /**<Invalid value*/   /**<CNcomment:非法边界值*/
}HI_UNF_TUNER_DEV_TYPE_E ;

/**Type of the QAM device*/
/**CNcomment:QAM设备类型*/
typedef enum    hiUNF_DEMOD_DEV_TYPE_E
{
    HI_UNF_DEMOD_DEV_TYPE_NONE,                /**<Not supported*/    /**<CNcomment:不支持*/  
    HI_UNF_DEMOD_DEV_TYPE_3130I= 0x100,        /**<Internal QAM*/     /**<CNcomment:内部QAM*/
    HI_UNF_DEMOD_DEV_TYPE_3130E,               /**<External Hi3130*/  /**<CNcomment:外部QAM hi3130芯片*/
    HI_UNF_DEMOD_DEV_TYPE_J83B,                /**<suppoort j83b*/    /**<CNcomment:支持j83b*/
    HI_UNF_DEMOD_DEV_TYPE_AVL6211,             /**<Availink 6211*/    /**<CNcomment:支持Availink 6211*/
    HI_UNF_DEMOD_DEV_TYPE_MXL101,
    HI_UNF_DEMOD_DEV_TYPE_MN88472,
    HI_UNF_DEMOD_DEV_TYPE_IT9170,
    HI_UNF_DEMOD_DEV_TYPE_IT9133,

    HI_UNF_DEMOD_DEV_TYPE_BUTT,                /**<Invalid value*/    /**<CNcomment:非法边界值*/
}HI_UNF_DEMOD_DEV_TYPE_E ;

/**Defines the cable transmission signal.*/
/**CNcomment:定义CABLE传输信号*/
typedef struct  hiUNF_CAB_CONNECT_PARA_S
{
    HI_U32                      u32Freq;            /**<Frequency, in kHz*/      /**<CNcomment:频率，单位：kHz*/
    HI_U32                      u32SymbolRate ;     /**<Symbol rate, in bit/s*/  /**<CNcomment:符号率，单位bps */
    HI_UNF_MODULATION_TYPE_E    enModType ;         /**<QAM mode*/               /**<CNcomment:QAM调制方式*/
    HI_BOOL                     bReverse ;          /**<Spectrum reverse mode*/  /**<CNcomment:频谱倒置处理方式*/
}HI_UNF_CAB_CONNECT_PARA_S ;

/*Not used currently*/
/*CNcomment:暂未使用*/
typedef enum hiUNF_TUNER_FE_GUARD_INTV_E
{
    HI_UNF_TUNER_FE_GUARD_INTV_DEFALUT = 0 ,    /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_1_128       ,       /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_1_32       ,       /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_1_16       ,       /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_1_8        ,       /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_1_4        ,       /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_19_128       ,       /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_19_256       ,       /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_BUTT     ,       /**< */
}HI_UNF_TUNER_FE_GUARD_INTV_E;

/*Not used currently*/
/*CNcomment:暂未使用*/
typedef enum hiUNF_TUNER_FE_DEPUNC_RATE_E
{
    HI_UNF_TUNER_FE_DEPUNC_RATE_DEFAULT = 0 ,    /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_12      ,        /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_23      ,        /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_34      ,        /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_45      ,        /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_56      ,        /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_67      ,        /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_78      ,        /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_89      ,        /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_BUTT    ,        /**< */
}HI_UNF_TUNER_FE_DEPUNC_RATE_E ;

/*Not used currently*/
/*CNcomment:暂未使用*/
typedef enum hiUNF_TUNER_FE_FFT_E
{
    HI_UNF_TUNER_FE_FFT_DEFAULT = 0,   /**< */
    HI_UNF_TUNER_FE_FFT_1K ,           /**< */
    HI_UNF_TUNER_FE_FFT_2K ,           /**< */
    HI_UNF_TUNER_FE_FFT_4K ,           /**< */
    HI_UNF_TUNER_FE_FFT_8K ,           /**< */
    HI_UNF_TUNER_FE_FFT_16K ,           /**< */
    HI_UNF_TUNER_FE_FFT_32K ,           /**< */
    HI_UNF_TUNER_FE_FFT_BUTT ,         /**< */
}HI_UNF_TUNER_FE_FFT_E;

/*Not used currently*/
/*CNcomment:暂未使用*/
typedef enum hiUNF_TUNER_FE_HIERARCHY_E
{
    HI_UNF_TUNER_FE_HIERARCHY_DEFAULT = 0 ,   /**< */
    HI_UNF_TUNER_FE_HIERARCHY_NO,             /**< */
    HI_UNF_TUNER_FE_HIERARCHY_ALHPA1,         /**< */
    HI_UNF_TUNER_FE_HIERARCHY_ALHPA2,         /**< */
    HI_UNF_TUNER_FE_HIERARCHY_ALHPA4,         /**< */
    HI_UNF_TUNER_FE_HIERARCHY_BUTT,           /**< */
}HI_UNF_TUNER_FE_HIERARCHY_E ;

/*CNcomment*/
typedef enum hiUNF_TUNER_TS_PRIORITY_E
{
    HI_UNF_TUNER_TS_PRIORITY_NONE = 0 ,   /**< */
    HI_UNF_TUNER_TS_PRIORITY_HP,             /**< */
    HI_UNF_TUNER_TS_PRIORITY_LP,         /**< */
    HI_UNF_TUNER_TS_PRIORITY_BUTT,           /**< */
}HI_UNF_TUNER_TS_PRIORITY_E ;

typedef struct  hiUNF_TER_CONNECT_PARA_S
{
    HI_U32          u32Freq     ;                    /**<freq in KHz */
    HI_U32          u32BandWidth    ;                /**<bandwidth in KHz */
    HI_UNF_MODULATION_TYPE_E enModType  ;            /**< */
    HI_BOOL                     bReverse ;          /**<Spectrum reverse mode*/  /**<CNcomment:频谱翻转处理方式*/
}HI_UNF_TER_CONNECT_PARA_S ;

#if 0
/*CNcomment:暂未使用*/
typedef struct  hiUNF_TUNER_TER_ATTR_S
{
    HI_UNF_TUNER_FE_DEPUNC_RATE_E   enHpCode ;      /**< */
    HI_UNF_TUNER_FE_DEPUNC_RATE_E   enLpCode ;      /**< */
    HI_UNF_TUNER_FE_GUARD_INTV_E    enGuardIntv ;   /**< */
    HI_UNF_TUNER_FE_FFT_E       enFftType ;         /**< */
    HI_UNF_TUNER_FE_HIERARCHY_E enHierType ;        /**< */

}HI_UNF_TUNER_TER_ATTR_S;
#endif

/**TS clock polarization*/
/*CNcomment:TS时钟极性*/
typedef enum hiUNF_TUNER_TSCLK_POLAR_E
{
    HI_UNF_TUNER_TSCLK_POLAR_FALLING,       /**<Falling edge*/      /**<CNcomment:下降沿*/
    HI_UNF_TUNER_TSCLK_POLAR_RISING,        /**<Rising edge*/       /**<CNcomment:上升沿*/
    HI_UNF_TUNER_TSCLK_POLAR_BUTT           /**<Invalid value*/     /**<CNcomment:非法边界值*/
} HI_UNF_TUNER_TSCLK_POLAR_E;

/**TS format*/
typedef enum hiUNF_TUNER_TS_FORMAT_E
{
    HI_UNF_TUNER_TS_FORMAT_TS,              /**<188*/
    HI_UNF_TUNER_TS_FORMAT_TSP,             /**<204*/
    HI_UNF_TUNER_TS_FORMAT_BUTT             /**<Invalid value*/     /**<CNcomment:非法边界值*/
} HI_UNF_TUNER_TS_FORMAT_E;

/**TS serial PIN*/
typedef enum hiUNF_TUNER_TS_SERIAL_PIN_E
{
    HI_UNF_TUNER_TS_SERIAL_PIN_0,           /**<Serial pin 0, default*/
    HI_UNF_TUNER_TS_SERIAL_PIN_7,           /**<Serial pin 7*/
    HI_UNF_TUNER_TS_SERIAL_PIN_BUTT         /**<Invalid value*/     /**<CNcomment:非法边界值*/
} HI_UNF_TUNER_TS_SERIAL_PIN_E;

/** Tuner RF AGC mode */
typedef enum hiUNF_TUNER_RFAGC_MODE_E
{
    /**< Inverted polarization, default.This setting is used for a tuner whose gain decreases with increased AGC voltage */
    HI_UNF_TUNER_RFAGC_INVERT, 

    /**< Normal polarization. This setting is used for a tuner whose gain increases with increased AGC voltage */
    HI_UNF_TUNER_RFAGC_NORMAL,
    HI_UNF_TUNER_RFAGC_BUTT
} HI_UNF_TUNER_RFAGC_MODE_E;

/** Tuner IQ spectrum mode */
typedef enum hiUNF_TUNER_IQSPECTRUM_MODE_E
{
    HI_UNF_TUNER_IQSPECTRUM_NORMAL,         /**<The received signal spectrum is not inverted */
    HI_UNF_TUNER_IQSPECTRUM_INVERT,         /**<The received signal spectrum is inverted */
    HI_UNF_TUNER_IQSPECTRUM_BUTT
} HI_UNF_TUNER_IQSPECTRUM_MODE_E;

/** DiSEqC Wave Mode */
typedef enum hiUNF_TUNER_DISEQCWAVE_MODE_E
{
    HI_UNF_TUNER_DISEQCWAVE_NORMAL,         /**<Waveform produced by demod */
    HI_UNF_TUNER_DISEQCWAVE_ENVELOPE,       /**<Waveform produced by LNB control device */
    HI_UNF_TUNER_DISEQCWAVE_BUTT
} HI_UNF_TUNER_DISEQCWAVE_MODE_E;

/** LNB power supply and control device */
typedef enum hiUNF_LNBCTRL_DEV_TYPE_E
{
    HI_UNF_LNBCTRL_DEV_TYPE_NONE,           /**<No LNB control device */
    HI_UNF_LNBCTRL_DEV_TYPE_MPS8125,        /**<MPS8125 */
    HI_UNF_LNBCTRL_DEV_TYPE_ISL9492,        /**<ISL9492 */
    HI_UNF_LNBCTRL_DEV_TYPE_BUTT
} HI_UNF_LNBCTRL_DEV_TYPE_E;

typedef struct  hiUNF_TUNER_SAT_ATTR_S
{
    HI_U32                         u32ResetGpioNo;  /**<Demod reset GPIO NO. */
    HI_U32                         u32DemodClk;     /**<Demod reference clock frequency, KHz */
#if 0
    HI_U16                         u16DemodAddress; /**<Demod slave address */
    HI_U16                         u16TunerAddress; /**<Tuner slave address */
#endif
    HI_U16                         u16TunerMaxLPF;  /**<Tuner max LFP, MHz */
    HI_U16                         u16TunerI2CClk;  /**<Tuner I2C clock, kHz */
    HI_UNF_TUNER_RFAGC_MODE_E      enRFAGC;         /**<Tuner RF AGC mode */
    HI_UNF_TUNER_IQSPECTRUM_MODE_E enIQSpectrum;    /**<Tuner IQ spectrum mode */
    HI_UNF_TUNER_TSCLK_POLAR_E     enTSClkPolar;    /**<TS clock polarization */
    HI_UNF_TUNER_TS_FORMAT_E       enTSFormat;      /**<TS format */
    HI_UNF_TUNER_TS_SERIAL_PIN_E   enTSSerialPIN;   /**<TS serial PIN */
    HI_UNF_TUNER_DISEQCWAVE_MODE_E enDiSEqCWave;    /**<DiSEqC Wave Mode */
    HI_UNF_LNBCTRL_DEV_TYPE_E      enLNBCtrlDev;    /**<LNB power supply and control device */
    HI_U16                         u16LNBDevAddress;/**<LNB control device address */
} HI_UNF_TUNER_SAT_ATTR_S;

typedef struct  hiUNF_TUNER_TER_ATTR_S
{
    HI_U32                         u32ResetGpioNo;  /**<Demod reset GPIO NO. */
} HI_UNF_TUNER_TER_ATTR_S;
/** Polarization type */
typedef enum hiUNF_TUNER_FE_POLARIZATION_E
{
    HI_UNF_TUNER_FE_POLARIZATION_H,         /**< Horizontal Polarization */
    HI_UNF_TUNER_FE_POLARIZATION_V,         /**< Vertical Polarization */
    HI_UNF_TUNER_FE_POLARIZATION_L,         /**< Left-hand circular Polarization */
    HI_UNF_TUNER_FE_POLARIZATION_R,         /**< Right-hand circular Polarization */
    HI_UNF_TUNER_FE_POLARIZATION_BUTT,      /**< Invalid */
} HI_UNF_TUNER_FE_POLARIZATION_E;

/** FEC Type */
typedef enum hiUNF_TUNER_FE_FECTYPE_E
{
    HI_UNF_TUNER_FE_FEC_DVBS,
    HI_UNF_TUNER_FE_FEC_DVBS2,
    HI_UNF_TUNER_FE_FEC_BUTT
} HI_UNF_TUNER_FE_FECTYPE_E;

/** FEC Rate */
typedef enum hiUNF_TUNER_FE_FECRATE_E
{
    HI_UNF_TUNER_FE_FEC_AUTO = 0,
    HI_UNF_TUNER_FE_FEC_1_2,
    HI_UNF_TUNER_FE_FEC_2_3,
    HI_UNF_TUNER_FE_FEC_3_4,
    HI_UNF_TUNER_FE_FEC_4_5,
    HI_UNF_TUNER_FE_FEC_5_6,
    HI_UNF_TUNER_FE_FEC_6_7,
    HI_UNF_TUNER_FE_FEC_7_8,
    HI_UNF_TUNER_FE_FEC_8_9,
    HI_UNF_TUNER_FE_FEC_9_10,
    HI_UNF_TUNER_FE_FEC_1_4,
    HI_UNF_TUNER_FE_FEC_1_3,
    HI_UNF_TUNER_FE_FEC_2_5,
    HI_UNF_TUNER_FE_FEC_3_5,
    HI_UNF_TUNER_FE_FECRATE_BUTT
} HI_UNF_TUNER_FE_FECRATE_E;

/** LNB type */
typedef enum hiUNF_TUNER_FE_FE_LNBTYPE_E
{
    HI_UNF_TUNER_FE_LNB_SINGLE_FREQUENCY,   /**<Single LO frequency */
    HI_UNF_TUNER_FE_LNB_DUAL_FREQUENCY,     /**<Dual LO frequency */
    HI_UNF_TUNER_FE_LNB_TYPE_BUTT
} HI_UNF_TUNER_FE_LNB_TYPE_E;

/** LNB band type */
typedef enum hiUNF_TUNER_FE_LNB_BAND_E
{
    HI_UNF_TUNER_FE_LNB_BAND_C,             /**<C */
    HI_UNF_TUNER_FE_LNB_BAND_KU,            /**<Ku */
    HI_UNF_TUNER_FE_LNB_BAND_BUTT
} HI_UNF_TUNER_FE_LNB_BAND_E;

/** LNB power control */
typedef enum hiUNF_TUNER_FE_LNB_POWER_E
{
    HI_UNF_TUNER_FE_LNB_POWER_OFF,          /**<LNB power off */
    HI_UNF_TUNER_FE_LNB_POWER_ON,           /**<LNB power auto, 13V/18V, default */
    HI_UNF_TUNER_FE_LNB_POWER_ENHANCED,     /**<LNB power auto, 14V/19V, some LNB control device can support.*/
    HI_UNF_TUNER_FE_LNB_POWER_BUTT
} HI_UNF_TUNER_FE_LNB_POWER_E;

/** LNB 22K tone status, for Ku band LNB */
typedef enum hiUNF_TUNER_FE_LNB_22K_E
{
    HI_UNF_TUNER_FE_LNB_22K_OFF,            /**<default */
    HI_UNF_TUNER_FE_LNB_22K_ON,
    HI_UNF_TUNER_FE_LNB_22K_BUTT
} HI_UNF_TUNER_FE_LNB_22K_E;

/** 0/12V switch */
typedef enum hiUNF_TUNER_SWITCH_0_12V_E
{
    HI_UNF_TUNER_SWITCH_0_12V_NONE,         /**< None, default */
    HI_UNF_TUNER_SWITCH_0_12V_0,            /**< 0V */
    HI_UNF_TUNER_SWITCH_0_12V_12,           /**< 12V */
    HI_UNF_TUNER_SWITCH_0_12V_BUTT
} HI_UNF_TUNER_SWITCH_0_12V_E;

/** 22KHz switch */
typedef enum hiUNF_TUNER_SWITCH_22K_E
{
    HI_UNF_TUNER_SWITCH_22K_NONE,           /**< None, default */
    HI_UNF_TUNER_SWITCH_22K_0,              /**< 0 */
    HI_UNF_TUNER_SWITCH_22K_22,             /**< 22KHz */
    HI_UNF_TUNER_SWITCH_22K_BUTT
} HI_UNF_TUNER_SWITCH_22K_E;

/** Tone burst switch */
typedef enum hiUNF_TUNER_SWITCH_TONEBURST_E
{
    HI_UNF_TUNER_SWITCH_TONEBURST_NONE,     /**< Don't send tone burst, default */
    HI_UNF_TUNER_SWITCH_TONEBURST_0,        /**< Tone burst 0 */
    HI_UNF_TUNER_SWITCH_TONEBURST_1,        /**< Tone burst 1 */
    HI_UNF_TUNER_SWITCH_TONEBURST_BUTT
} HI_UNF_TUNER_SWITCH_TONEBURST_E;

/**Structure of the satellite transmission signal.*/
/**CNcomment:定义Satellite传输信号*/
typedef struct  hiUNF_SAT_CONNECT_PARA_S
{
    HI_U32                         u32Freq;         /**<Downlink frequency, in kHz*/ /**<CNcomment:下行频率，单位：kHz*/
    HI_U32                         u32SymbolRate;   /**<Symbol rate, in bit/s*/      /**<CNcomment:符号率，单位bps */
    HI_UNF_TUNER_FE_POLARIZATION_E enPolar;         /**<Polarization type*/          /**<CNcomment:极化方式*/
} HI_UNF_SAT_CONNECT_PARA_S;

/**Structure of the satellite transmission signal's detailed information.*/
/**CNcomment:卫星信号详细信息*/
typedef struct  hiUNF_TUNER_SAT_SIGNALINFO_S
{
    HI_U32                         u32Freq;         /**<Downlink frequency, in kHz*/ /**<CNcomment:下行频率，单位：kHz*/
    HI_U32                         u32SymbolRate;   /**<Symbol rate, in bit/s*/      /**<CNcomment:符号率，单位bps */
    HI_UNF_MODULATION_TYPE_E       enModType;       /**<Modulation type*/            /**<CNcomment:调制方式*/
    HI_UNF_TUNER_FE_POLARIZATION_E enPolar;         /**<Polarization type*/          /**<CNcomment:极化方式*/
    HI_UNF_TUNER_FE_FECTYPE_E      enFECType;       /**<FEC type*/
    HI_UNF_TUNER_FE_FECRATE_E      enFECRate;       /**<FEC rate*/
} HI_UNF_TUNER_SAT_SIGNALINFO_S;

typedef enum hiUNF_TUNER_T2_PLP_TYPE_E
{   
    HI_UNF_TUNER_T2_PLP_TYPE_COM=0, 
    HI_UNF_TUNER_T2_PLP_TYPE_DAT1,  
    HI_UNF_TUNER_T2_PLP_TYPE_DAT2,
    HI_UNF_TUNER_T2_PLP_TYPE_BUTT   
} HI_UNF_TUNER_T2_PLP_TYPE_E;

/**Structure of the terrestrial transmission signal's detailed information.*/
/**CNcomment:地面信号详细信息*/
typedef struct  hiUNF_TUNER_TER_SIGNALINFO_S
{
    HI_U32                         u32Freq;         /**<Frequency, in kHz*/ /**<CNcomment:频率，单位：kHz*/
    HI_U32                         u32BandWidth;   /**<Band width, in KHz*/      /**<CNcomment:带宽，单位KHz */
    HI_UNF_MODULATION_TYPE_E       enModType;       /**<Modulation type*/            /**<CNcomment:调制方式*/
    HI_UNF_TUNER_FE_FECRATE_E      enFECRate;       /**<FEC rate*/
    HI_UNF_TUNER_FE_GUARD_INTV_E enGuardIntv;
    HI_UNF_TUNER_FE_FFT_E enFFTMode;
    HI_UNF_TUNER_FE_HIERARCHY_E enHierMod; /**<Hierarchical Modulation and alpha, only used in DVB-T*/
    HI_UNF_TUNER_TS_PRIORITY_E enTsPriority; /**<The TS priority, only used in DVB-T*/
} HI_UNF_TUNER_TER_SIGNALINFO_S;
/**CNcomment:TUNER属性*/
typedef struct hiUNF_TUNER_SIGNALINFO_S
{
    HI_UNF_TUNER_SIG_TYPE_E enSigType;              /**<Signal transmission type*/  /**<CNcomment:信号类型*/

    union
    {
        HI_UNF_TUNER_SAT_SIGNALINFO_S stSat;        /**<Signal info of satellite*/  /**<CNcomment:卫星信号信息*/
        HI_UNF_TUNER_TER_SIGNALINFO_S stTer;        /**<Signal info of terrestrial*/  /**<CNcomment:地面信号信息*/
    } unSignalInfo;
} HI_UNF_TUNER_SIGNALINFO_S;

/** LNB configurating parameters */
typedef struct hiUNF_TUNER_FE_LNB_CONFIG_S
{
    HI_UNF_TUNER_FE_LNB_TYPE_E  enLNBType;      /**<LNB type*/                              /**<CNcomment:LNB类型*/
    HI_U32                      u32LowLO;       /**< Low Local Oscillator Frequency, MHz */ /**<CNcomment:LNB低本振频率，单位MHz*/
    HI_U32                      u32HighLO;      /**< High Local Oscillator Frequency, MHz*/ /**<CNcomment:LNB高本振频率，单位MHz*/
    HI_UNF_TUNER_FE_LNB_BAND_E  enLNBBand;      /**< LNB band, C or Ku */                   /**<CNcomment:LNB波段：C或Ku*/
} HI_UNF_TUNER_FE_LNB_CONFIG_S;

typedef struct tag_TunerAttr_S
{
    HI_UNF_TUNER_DEV_TYPE_E enTunerDevType;     /**<Tuner type*/                              /**<CNcomment:TUNER类型*/
    HI_U32 u32TunerAddr;
} HI_TunerAttr_S;

typedef struct tag_DemodAttr_S
{
    HI_UNF_DEMOD_DEV_TYPE_E enDemodDevType;     /**<QAM type*/                                /**<CNcomment:QAM类型*/
    HI_U32 u32DemodAddr;
} HI_DemodAttr_S;

/**CNcomment:TUNER属性*/
typedef struct  hiTUNER_ATTR_S
{
    HI_UNF_TUNER_SIG_TYPE_E     enSigType ;         /**<Signal type*/                             /**<CNcomment:信号类型*/
    HI_UNF_TUNER_DEV_TYPE_E enTunerDevType;     /**<Tuner type*/                              /**<CNcomment:TUNER类型*/
    HI_U32 u32TunerAddr;                                      /*The i2c address of tuner, if demod type is 3130I,3130E or J83B, you cannot set it*/
    HI_UNF_DEMOD_DEV_TYPE_E enDemodDevType;     /**<QAM type*/                                /**<CNcomment:QAM类型*/
    HI_U32 u32DemodAddr;                                   /*The i2c address of demod, if demod type is 3130I,3130E or J83B, you cannot set it*/
    HI_UNF_TUNER_OUPUT_MODE_E   enOutputMode ;      /**<Output mode of transport streams (TSs)*/  /**<CNcomment:TS流输出模式*/
    HI_UNF_TUNER_I2cChannel_E   enI2cChannel;       /**<I2C channel used by the tuner*/           /**<CNcomment:TUNER使用的I2C通道*/

    union
    {
        HI_UNF_TUNER_TER_ATTR_S stTer ;         /**<Attributes of the terrestrial signal. */  /**<CNcomment:地面信号属性*/
        HI_UNF_TUNER_SAT_ATTR_S stSat;          /**<Attributes of the satellite signal.*/     /**<CNcomment:卫星信号属性*/
    }unTunerAttr ;
}HI_UNF_TUNER_ATTR_S ;

/**Frequency locking parameters of the tuner*/
/**CNcomment:TUNER锁频参数*/
typedef struct  hiUNF_TUNER_CONNECT_PARA_S
{
    HI_UNF_TUNER_SIG_TYPE_E enSigType ;        /**<Signal type*/                 /**<CNcomment:信号类型*/

    union
    {
        HI_UNF_CAB_CONNECT_PARA_S   stCab ;   /**<Cable transmission signal*/    /**<CNcomment:CABLE传输信号*/
        HI_UNF_TER_CONNECT_PARA_S stTer ;       /**<Terrestrial transmission signal*/ /**<CNcomment:地面传输信号*/
        HI_UNF_SAT_CONNECT_PARA_S stSat;        /**<Satellite transmission signal*/   /**<CNcomment:卫星传输信号*/
    }unConnectPara;
}HI_UNF_TUNER_CONNECT_PARA_S ;

/**Frequency locking status and parameters of the tuner*/
/**CNcomment:TUNER锁频状态和锁频参数*/
typedef struct  hiUNF_TUNER_STATUS_S
{
    HI_UNF_TUNER_LOCK_STATUS_E  enLockStatus ;  /**<Frequency locking status*/               /**<CNcomment:锁频状态*/
    HI_UNF_TUNER_CONNECT_PARA_S stConnectPara;  /**<Actual frequency locking parameters*/    /**<CNcomment:实际锁频参数*/
}HI_UNF_TUNER_STATUS_S ;
/**Tuner blind scan type*/
/**CNcomment:TUNER盲扫方式*/
typedef enum hiUNF_TUNER_BLINDSCAN_MODE_E
{
    HI_UNF_TUNER_BLINDSCAN_MODE_AUTO = 0,       /**<Blind scan automatically*/  /**<CNcomment:自动扫描*/
    HI_UNF_TUNER_BLINDSCAN_MODE_MANUAL,         /**<Blind scan manually*/       /**<CNcomment:手动扫描*/
    HI_UNF_TUNER_BLINDSCAN_MODE_BUTT
} HI_UNF_TUNER_BLINDSCAN_MODE_E;

/**Definition of blind scan event type*/
/**CNcomment:TUNER盲扫事件*/
typedef enum hiUNF_TUNER_BLINDSCAN_EVT_E
{
    HI_UNF_TUNER_BLINDSCAN_EVT_STATUS,          /**<New status*/        /**<CNcomment:状态变化*/
    HI_UNF_TUNER_BLINDSCAN_EVT_PROGRESS,        /**<New Porgress */     /**<CNcomment:进度变化*/
    HI_UNF_TUNER_BLINDSCAN_EVT_NEWRESULT,       /**<Find new channel*/  /**<CNcomment:新频点*/
    HI_UNF_TUNER_BLINDSCAN_EVT_BUTT
} HI_UNF_TUNER_BLINDSCAN_EVT_E;

/**Definition of tuner blind scan status*/
/**CNcomment:TUNER盲扫状态*/
typedef enum hiUNF_TUNER_BLINDSCAN_STATUS_E
{
    HI_UNF_TUNER_BLINDSCAN_STATUS_IDLE,         /**<Idel*/              /**<空闲*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_SCANNING,     /**<Scanning*/          /**<扫描中*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_FINISH,       /**<Finish*/            /**<成功完成*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_QUIT,         /**<User quit*/         /**<用户退出*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_FAIL,         /**<Scan fail*/         /**<扫描失败*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_BUTT
} HI_UNF_TUNER_BLINDSCAN_STATUS_E;

/**Structure of satellite TP*/
/**CNcomment:TUNER扫出TP信息*/
typedef struct  hiUNF_TUNER_SAT_TPINFO_S
{
    HI_U32                         u32Freq;         /**<Downlink frequency, in kHz*/ /**<CNcomment:下行频率，单位：kHz*/
    HI_U32                         u32SymbolRate;   /**<Symbol rate, in bit/s*/      /**<CNcomment:符号率，单位bps */
    HI_UNF_TUNER_FE_POLARIZATION_E enPolar;         /**<Polarization type*/          /**<CNcomment:极化方式*/
} HI_UNF_TUNER_SAT_TPINFO_S;

#if 0
/**Result of tuner blind scan */
/**CNcomment:TUNER盲扫结果信息*/
typedef union hiUNF_TUNER_BLINDSCAN_RESULT_U
{
    HI_UNF_TUNER_SAT_TPINFO_S stSat;                /**<Information of new channel*/ /**<CNcomment:新频点信息*/
} HI_UNF_TUNER_BLINDSCAN_RESULT_U;
#endif

/**Notify structure of tuner blind scan */
/**CNcomment:TUNER盲扫通知信息*/
typedef union hiUNF_TUNER_BLINDSCAN_NOTIFY_U
{
    HI_UNF_TUNER_BLINDSCAN_STATUS_E* penStatus;             /**<Scanning status*/
    HI_U16*                          pu16ProgressPercent;   /**<Scanning progress*/
    HI_UNF_TUNER_SAT_TPINFO_S* pstResult;             /**<Scanning result*/
} HI_UNF_TUNER_BLINDSCAN_NOTIFY_U;

/**Parameter of the satellite tuner blind scan */
/**CNcomment:卫星TUNER盲扫参数*/
typedef struct hiUNF_TUNER_SAT_BLINDSCAN_PARA_S
{
    /**<LNB Polarization type, only take effect in manual blind scan mode*/
    /**<CNcomment:LNB极化方式，自动扫描模式设置无效*/
    HI_UNF_TUNER_FE_POLARIZATION_E enPolar;
    
    /**<LNB 22K signal status, for Ku band LNB which has dual LO, 22K ON will select high LO and 22K off select low LO,
        only take effect in manual blind scan mode*/
    /**<CNcomment:LNB 22K状态，对于Ku波段双本振LNB，ON选择高本振，OFF选择低本振，自动扫描模式设置无效*/
    HI_UNF_TUNER_FE_LNB_22K_E      enLNB22K;

    /**<Blind scan start IF, in kHz, only take effect in manual blind scan mode */
    /**<CNcomment:盲扫起始频率(中频)，单位：kHz，自动扫描模式设置无效*/
    HI_U32                         u32StartFreq;   

    /**<Blind scan stop IF, in kHz, only take effect in manual blind scan mode */
    /**<CNcomment:盲扫结束频率(中频)，单位：kHz，自动扫描模式设置无效*/
    HI_U32                         u32StopFreq; 

    /**<The execution of the blind scan may change the 13/18V or 22K status. 
        If you use any DiSEqC device which need send command when 13/18V or 22K status change,
        you should registe a callback here. Otherwise, you can set NULL here.*/
    /**<CNcomment:盲扫过程可能会切换极化方式和22K，如果你用了某些DiSEqC设备需要设置13/18V和22K的，
        请注册这个回调，如果没有用，请可传NULL */
    HI_VOID (*pfnDISEQCSet)(HI_U32 u32TunerId, HI_UNF_TUNER_FE_POLARIZATION_E enPolar,
                            HI_UNF_TUNER_FE_LNB_22K_E enLNB22K);

    /**<Callback when scan status change, scan progress change or find new channel.*/
    /**<CNcomment:扫描状态或进度百分比发生变化时、发现新的频点时回调*/
    HI_VOID (*pfnEVTNotify)(HI_UNF_TUNER_BLINDSCAN_EVT_E enEVT, HI_UNF_TUNER_BLINDSCAN_NOTIFY_U * punNotify);
} HI_UNF_TUNER_SAT_BLINDSCAN_PARA_S;

/**Parameter of the tuner blind scan */
/**CNcomment:TUNER盲扫参数*/
typedef struct hiUNF_TUNER_BLINDSCAN_PARA_S
{
    HI_UNF_TUNER_BLINDSCAN_MODE_E enMode;
    union
    {
        HI_UNF_TUNER_SAT_BLINDSCAN_PARA_S stSat;
    } unScanPara;
} HI_UNF_TUNER_BLINDSCAN_PARA_S;


/**DiSEqC Level*/
typedef enum hiUNF_TUNER_DISEQC_LEVEL_E
{
    HI_UNF_TUNER_DISEQC_LEVEL_1_X,      /**<1.x, one way*/                  /**<1.x，单向 */
    HI_UNF_TUNER_DISEQC_LEVEL_2_X,      /**<2.x, two way, support reply*/   /**<2.x，双向，支持Reply*/
    HI_UNF_TUNER_DISEQC_LEVEL_BUTT
} HI_UNF_TUNER_DISEQC_LEVEL_E;

/**Receive status of DiSEqC reply massage */
/**CNcomment:DiSEqC消息接收状态*/
typedef enum hiUNF_TUNER_DISEQC_RECV_STATUS_E
{
    HI_UNF_TUNER_DISEQC_RECV_OK,        /**<Receive successfully*/          /**<接收成功*/
    HI_UNF_TUNER_DISEQC_RECV_UNSUPPORT, /**<Device don't support reply*/    /**<设备不支持回传*/    
    HI_UNF_TUNER_DISEQC_RECV_TIMEOUT,   /**<Receive timeout*/               /**<接收超时*/
    HI_UNF_TUNER_DISEQC_RECV_ERROR,     /**<Receive fail*/                  /**<接收出错*/
    HI_UNF_TUNER_DISEQC_RECV_BUTT
} HI_UNF_TUNER_DISEQC_RECV_STATUS_E;

/**Structure of the DiSEqC send massage */
/**CNcomment:DiSEqC发送消息结构*/
typedef struct hiUNF_TUNER_DISEQC_SENDMSG_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E     enLevel;        /**<Device device level*/
    HI_UNF_TUNER_SWITCH_TONEBURST_E enToneBurst;    /**<Tone Burst */
    HI_U8                           au8Msg[HI_UNF_DISEQC_MSG_MAX_LENGTH]; /**<Message data*/
    HI_U8                           u8Length;       /**<Message length*/
    HI_U8                           u8RepeatTimes;  /**<Message repeat times*/
} HI_UNF_TUNER_DISEQC_SENDMSG_S;

/**Structure of the DiSEqC reply massage */
/**CNcomment:DiSEqC接收消息结构*/
typedef struct hiUNF_TUNER_DISEQC_RECVMSG_S
{
    HI_UNF_TUNER_DISEQC_RECV_STATUS_E enStatus;     /**<Recieve status*/
    HI_U8                             au8Msg[HI_UNF_DISEQC_MSG_MAX_LENGTH]; /**<Recieve message data*/
    HI_U8                             u8Length;     /**<Recieve message length*/
} HI_UNF_TUNER_DISEQC_RECVMSG_S;

#ifdef DISEQC_SUPPORT
/**DiSEqC Switch port */
typedef enum hiUNF_TUNER_DISEQC_SWITCH_PORT_E
{
    HI_UNF_TUNER_DISEQC_SWITCH_NONE = 0,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_1,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_2,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_3,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_4,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_5,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_6,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_7,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_8,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_9,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_10,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_11,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_12,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_13,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_14,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_15,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_16,
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_BUTT
} HI_UNF_TUNER_DISEQC_SWITCH_PORT_E;

/**Parameter for DiSEqC 1.0/2.0 switch
   Some DiSEqC device need set polarization(13/18V) and 22K, you can set them here. */
/**CNcomment:DiSEqC 1.0/2.0 开关参数
   有些DiSEqC设备需要设置极化方式和22K的，如果用了这种设备，需要在这里设置 */
typedef struct hiUNF_TUNER_DISEQC_SWITCH4PORT_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E       enLevel;  /**<DiSEqC device level*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_E enPort;   /**<DiSEqC switch port*/
    HI_UNF_TUNER_FE_POLARIZATION_E    enPolar;  /**<Polarization type */
    HI_UNF_TUNER_FE_LNB_22K_E         enLNB22K; /**<22K status*/
} HI_UNF_TUNER_DISEQC_SWITCH4PORT_S;

/**Parameter for DiSEqC 1.1/2.1 switch */
/**CNcomment:DiSEqC 1.1/2.1 开关参数 */
typedef struct hiUNF_TUNER_DISEQC_SWITCH16PORT_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E       enLevel;  /**<DiSEqC device level*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_E enPort;   /**<DiSEqC switch port*/
} HI_UNF_TUNER_DISEQC_SWITCH16PORT_S;

/**DiSEqC motor limit setting*/
/**CNcomment:DiSEqC马达极限设置 */
typedef enum hiUNF_TUNER_DISEQC_LIMIT_E
{
    HI_UNF_TUNER_DISEQC_LIMIT_OFF,              /**<Disable Limits*/
    HI_UNF_TUNER_DISEQC_LIMIT_EAST,             /**<Set East Limit*/
    HI_UNF_TUNER_DISEQC_LIMIT_WEST,             /**<Set West Limit*/
    HI_UNF_TUNER_DISEQC_LIMIT_BUTT
} HI_UNF_TUNER_DISEQC_LIMIT_E;

/**Difinition of DiSEqC motor move direction*/
/**CNcomment:DiSEqC马达移动方向 */
typedef enum hiUNF_TUNER_DISEQC_MOVE_DIR_E
{
    HI_UNF_TUNER_DISEQC_MOVE_DIR_EAST,          /**<Move east*/
    HI_UNF_TUNER_DISEQC_MOVE_DIR_WEST,          /**<Move west*/
    HI_UNF_TUNER_DISEQC_MOVE_DIR_BUTT
} HI_UNF_TUNER_DISEQC_MOVE_DIR_E;

/**Difinition of DiSEqC motor move type*/
/**CNcomment:DiSEqC马达移动方式*/
typedef enum hiUNF_TUNER_DISEQC_MOVE_TYPE_E
{
    HI_UNF_TUNER_DISEQC_MOVE_STEP_SLOW,         /**<1 step one time, default*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_FAST,         /**<5 step one time*/
    HI_UNF_TUNER_DISEQC_MOVE_CONTINUE,          /**<Continuous moving*/
    HI_UNF_TUNER_DISEQC_MOVE_TYPE_BUTT
} HI_UNF_TUNER_DISEQC_MOVE_TYPE_E;

/**Parameter for DiSEqC motor store position*/
/**CNcomment:天线存储位置参数*/
typedef struct hiUNF_TUNER_DISEQC_POSITION_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E enLevel;        /**<DiSEqC device level*/
    HI_U32                      u32Pos;         /**<Index of position, 0-255*/
} HI_UNF_TUNER_DISEQC_POSITION_S;

/**Parameter for DiSEqC motor limit setting*/
/**CNcomment:天线Limit设置参数*/
typedef struct hiUNF_TUNER_DISEQC_LIMIT_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E enLevel;        /**<DiSEqC device level*/
    HI_UNF_TUNER_DISEQC_LIMIT_E enLimit;        /**<Limit setting*/
} HI_UNF_TUNER_DISEQC_LIMIT_S;

/**Parameter for DiSEqC motor moving*/
/**CNcomment:DiSEqC马达移动参数*/
typedef struct hiUNF_TUNER_DISEQC_MOVE_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E     enLevel;    /**<DiSEqC device level*/
    HI_UNF_TUNER_DISEQC_MOVE_DIR_E  enDir;      /**<Moving direction */
    HI_UNF_TUNER_DISEQC_MOVE_TYPE_E enType;     /**<Moving type */
} HI_UNF_TUNER_DISEQC_MOVE_S;

/**Parameter for DiSEqC motor recalculate*/
/**CNcomment:DiSEqC天线重计算参数*/
typedef struct hiUNF_TUNER_DISEQC_RECALCULATE_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E enLevel;        /**<DiSEqC device level*/
    HI_U8                       u8Para1;        /**<Parameter 1 */
    HI_U8                       u8Para2;        /**<Parameter 2 */
    HI_U8                       u8Para3;        /**<Parameter 3 */
    HI_U8                       u8Reserve;      /**<Reserve */
} HI_UNF_TUNER_DISEQC_RECALCULATE_S;

/**Parameter for USALS*/
/**CNcomment:USALS 参数*/
typedef struct hiUNF_TUNER_DISEQC_USALS_PARA_S
{
    HI_U16 u16LocalLongitude;   /**<local longitude, is 10*longitude, in param, E:0-1800, W:1800-3600(3600-longtitude) */
    HI_U16 u16LocalLatitude;    /**<local latitude, is 10*latitude, in param N:0-900, S:900-1800(1800-latitude)*/
    HI_U16 u16SatLongitude;     /**<sat longitude, is 10*longitude, in param, E:0-1800, W:1800-3600(3600-longtitude)  */
    HI_U16 u16Angular;          /**<calculate result, out param */
} HI_UNF_TUNER_DISEQC_USALS_PARA_S;

/**Parameter for USALS goto angular*/
/**CNcomment:USALS角度参数*/
typedef struct hiUNF_TUNER_DISEQC_USALS_ANGULAR_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E enLevel;        /**<DiSEqC device level*/
    HI_U16                      u16Angular;     /**<Angular, calculated by HI_UNF_TUNER_DISEQC_CalcAngular()*/
} HI_UNF_TUNER_DISEQC_USALS_ANGULAR_S;
#endif /* DISEQC_SUPPORT */

/** @} */  /** <!-- ==== Structure Definition end ==== */


/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_2 */
/** @{ */  /** <!-- [SCI] */

/**Output configuration of the smart card interface clock (SCICLK) pin*/
/**CNcomment:SCICLK引脚输出配置*/
typedef enum  hiUNF_SCI_CLK_MODE_E
{
    HI_UNF_SCI_CLK_MODE_CMOS = 0,   /**<Complementary metal-oxide semiconductor (CMOS) output*/   /**<CNcomment:CMOS输出*/
    HI_UNF_SCI_CLK_MODE_OD,         /**<Open drain (OD) output*/                                  /**<CNcomment:OD输出*/
    HI_UNF_SCI_CLK_MODE_BUTT
}HI_UNF_SCI_CLK_MODE_E;

/**SCI port*/
/**CNcomment:SCI 端口 */
typedef enum hiUNF_SCI_PORT_E
{
    HI_UNF_SCI_PORT0,      /**< SCI port 0*/  /**<CNcomment:SCI端口0*/
    HI_UNF_SCI_PORT1,      /**< SCI port 1*/  /**<CNcomment:SCI端口1*/
    HI_UNF_SCI_PORT_BUTT     
}HI_UNF_SCI_PORT_E;

/**Status of the SCI card*/
/**CNcomment:智能卡状态 */
typedef enum hiUNF_SCI_STATUS_E
{
    HI_UNF_SCI_STATUS_UNINIT     = 0,   /**<The SCI card is not initialized.*/               /**<CNcomment: SCI未初始化 */
    HI_UNF_SCI_STATUS_FIRSTINIT,        /**<The SCI card is being initialized.*/             /**<CNcomment:SCI初始化过程中*/
    HI_UNF_SCI_STATUS_NOCARD,           /**<There is no SCI card.*/                          /**<CNcomment:无卡 */
    HI_UNF_SCI_STATUS_INACTIVECARD,     /**<The SCI card is not activated (unavailable).*/   /**<CNcomment:卡未完成激活（卡无效） */
 //   HI_UNF_SCI_STATUS_CARDFAULT,		  /**<The SCI card is faulty.*/                        /**<CNcomment:卡故障*/
    HI_UNF_SCI_STATUS_WAITATR,          /**<The SCI card is waiting for the ATR data.*/      /**<CNcomment:等待ATR*/
    HI_UNF_SCI_STATUS_READATR,          /**<The SCI card is receiving the ATR data.*/        /**<CNcomment:正在接收ATR*/
    HI_UNF_SCI_STATUS_READY,            /**<The SCI card is available (activated).*/         /**<CNcomment:卡可以使用（卡激活） */
    HI_UNF_SCI_STATUS_RX,               /**<The SCI card is busy receiving data.*/           /**<CNcomment:卡忙（接收数据中） */
    HI_UNF_SCI_STATUS_TX                /**<The SCI card is busy transmitting data.*/        /**<CNcomment:卡忙（发送数据中） */
} HI_UNF_SCI_STATUS_E;

/**SCI protocol*/
/**CNcomment:SCI 协议 */
typedef enum hiUNF_SCI_PROTOCOL_E
{
    HI_UNF_SCI_PROTOCOL_T0,    /**<7816 T0 protocol*/   /**<CNcomment:7816 T0 协议 */
    HI_UNF_SCI_PROTOCOL_T1,    /**<7816 T1 protocol*/   /**<CNcomment:7816 T1 协议 */
    HI_UNF_SCI_PROTOCOL_T14 ,  /**<7816 T14 protocol*/  /**<CNcomment:7816 T14 协议 */
    HI_UNF_SCI_PROTOCOL_BUTT
}HI_UNF_SCI_PROTOCOL_E;

/**SCI active level*/
/**CNcomment:SCI有效电平*/
typedef enum hiUNF_SCI_LEVEL_E
{
    HI_UNF_SCI_LEVEL_LOW,    /**<Active low*/   /**<CNcomment:低电平有效 */
    HI_UNF_SCI_LEVEL_HIGH,   /**<Active high*/  /**<CNcomment:高电平有效 */
    HI_UNF_SCI_LEVEL_BUTT      
}HI_UNF_SCI_LEVEL_E ;

/**SCI system parameters*/
/**CNcomment:SCI 系统参数 */
typedef struct hiUNF_SCI_PARAMS_S
{
	HI_UNF_SCI_PORT_E enSciPort;		      /**<SCI port ID*/                                          	/**<CNcomment:SCI 端口号 */
	HI_UNF_SCI_PROTOCOL_E enProtocolType; /**<Used protocol type*/                                    /**<CNcomment:使用的协议类型 */
	HI_U32 ActalClkRate;	                /**<Actual clock rate conversion factor F*/	                /**<CNcomment:实际的F 值时钟转换因子 */
	HI_U32 ActalBitRate;                	/**<Actual bit rate conversion factor D*/	                  /**<CNcomment:实际的D 值比特率转换因子 */
	HI_U32 Fi;			                      /**<Clock factor returned by the answer to reset (ATR)*/  	/**<CNcomment:ATR 返回的时钟因子 */
	HI_U32 Di;			                      /**<Bit rate factor returned by the ATR*/                 	/**<CNcomment:ATR 返回的比特率因子 */
	HI_U32 GuardDelay;	                  /**<Extra guard time N*/	                                  /**<CNcomment:N 值额外增加的保护时间*/
	HI_U32 CharTimeouts;	                /**<Character timeout of T0 or T1*/                       	/**<CNcomment:T0 或T1的字符超时时间*/
	HI_U32 BlockTimeouts;	                /**<Block timeout of T1 */                                  /**<CNcomment:T1的块超时时间*/
	HI_U32 TxRetries;			                /**<Number of transmission retries*/                      	/**<CNcomment:发送重试次数*/
}HI_UNF_SCI_PARAMS_S,*HI_UNF_SCI_PARAMS_S_PTR;


/** @} */  /** <!-- ==== Structure Definition End ==== */


/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_3 */
/** @{ */  /** <!-- [E2PROM] */

/**Defines the model of the electrically erasable programmable read-only memory (E2PROM).*/
/**CNcomment:E2PROM型号定义*/
typedef enum hiUNF_E2PROM_CHIP_E
{
    HI_UNF_E2PROM_CHIP_AT24C01,   /**<E2PROM model: AT24C01*/   /**<CNcomment:E2PROM型号：AT24C01 */
    HI_UNF_E2PROM_CHIP_AT24C02,   /**<E2PROM model: AT24C02*/   /**<CNcomment:E2PROM型号：AT24C02 */
    HI_UNF_E2PROM_CHIP_AT24C04,   /**<E2PROM model: T24C04*/    /**<CNcomment:E2PROM型号：AT24C04 */
    HI_UNF_E2PROM_CHIP_AT24C08,   /**<E2PROM model: AT24C08*/   /**<CNcomment:E2PROM型号：AT24C08 */
    HI_UNF_E2PROM_CHIP_AT24C16,   /**<E2PROM model: AT24C16*/   /**<CNcomment:E2PROM型号：AT24C16 */
    HI_UNF_E2PROM_CHIP_AT24C32,   /**<E2PROM model: AT24C32*/   /**<CNcomment:E2PROM型号：AT24C32 */
    HI_UNF_E2PROM_CHIP_AT24C64,   /**<E2PROM model: AT24C64*/   /**<CNcomment:E2PROM型号：AT24C64 */
    HI_UNF_E2PROM_CHIP_AT24C128,  /**<E2PROM model: AT24C128*/  /**<CNcomment:E2PROM型号：AT24C128 */
    HI_UNF_E2PROM_CHIP_AT24C256,  /**<E2PROM model: AT24C256*/  /**<CNcomment:E2PROM型号：AT24C256 */
    HI_UNF_E2PROM_CHIP_M24LC01,   /**<E2PROM model: M24LC01*/   /**<CNcomment:E2PROM型号：M24LC01 */
    HI_UNF_E2PROM_CHIP_M24LC02,   /**<E2PROM model: M24LC02*/   /**<CNcomment:E2PROM型号：M24LC02 */
    HI_UNF_E2PROM_CHIP_M24LC04,   /**<E2PROM model: M24LC04*/   /**<CNcomment:E2PROM型号：M24LC04 */
    HI_UNF_E2PROM_CHIP_M24LC08,   /**<E2PROM model: M24LC08*/   /**<CNcomment:E2PROM型号：M24LC08 */
    HI_UNF_E2PROM_CHIP_M24LC16,   /**<E2PROM model: M24LC16*/   /**<CNcomment:E2PROM型号：M24LC16 */
    HI_UNF_E2PROM_CHIP_M24LC32,   /**<E2PROM model: M24LC32*/   /**<CNcomment:E2PROM型号：M24LC32 */
    HI_UNF_E2PROM_CHIP_M24LC64,   /**<E2PROM model: M24LC64*/   /**<CNcomment:E2PROM型号：M24LC64 */
    HI_UNF_E2PROM_CHIP_M24LC128,  /**<E2PROM model: M24LC128*/  /**<CNcomment:E2PROM型号：M24LC128 */
    HI_UNF_E2PROM_CHIP_M24LC256,  /**<E2PROM model: M24LC256*/  /**<CNcomment:E2PROM型号：M24LC256 */

    HI_UNF_E2PROM_CHIP_BUTT
}HI_UNF_E2PROM_CHIP_E;

/** @} */  /** <!-- ==== Structure Definition End ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_4 */
/** @{ */  /** <!-- [IR] */

/**Code type supported by the infrared (IR) module*/
/**CNcomment:IR支持的码型*/
typedef enum hiUNF_IR_CODE_E
{
    HI_UNF_IR_CODE_NEC_SIMPLE = 0,  /**<NEC with simple repeat code*/   /**<CNcomment:NEC with simple repeat code码型*/
    HI_UNF_IR_CODE_TC9012,          /**<TC9012 code*/                   /**<CNcomment:TC9012码型*/
    HI_UNF_IR_CODE_NEC_FULL,        /**<NEC with full repeat code*/     /**<CNcomment:NEC with full repeat code码型*/
    HI_UNF_IR_CODE_SONY_12BIT,      /**<SONY 12-bit code */             /**<CNcomment:SONY 12BIT码型*/
    HI_UNF_IR_CODE_RAW,      	      /**<Raw code*/	                    /**<CNcomment:raw 码型*/
    HI_UNF_IR_CODE_BUTT
}HI_UNF_IR_CODE_E;

/**List of IR code type. For details about HI_UNF_IR_STD, see HI_UNF_IR_CODE_E.*/
/**CNcomment:IR码型列表,HI_UNF_IR_STD部分请参照HI_UNF_IR_CODE_E */
typedef enum hiUNF_IR_PROTOCOL_E
{
    HI_UNF_IR_NEC,
	  HI_UNF_IR_RC6A=10,
	  HI_UNF_IR_RC5,	
    HI_UNF_IR_LOW_LATENCY_PROTOCOL,
    HI_UNF_IR_RC6_MODE0,         /**<For RC6 mode 0*/
    HI_UNF_IR_RCMM,              /**<For RCMM 24/32 protocol*/
    HI_UNF_IR_RUWIDO,            /**<For Ruwido protocol*/
    HI_UNF_IR_RCRF8,             /**<For RCRF8 protocol*/
    HI_UNF_IR_MULTIPLE,          /**<For multiple protocol support*/
    HI_UNF_IR_RMAP,              /**<For RMAP protocol with Mancester coding*/
   	HI_UNF_IR_RSTEP,             /**<For RSTEP protocol*/
    HI_UNF_IR_RMAP_DOUBLEBIT,    /**<For RMAP protocol with Double bit coding*/
    HI_UNF_IR_LOW_LATENCY_PRO_PROTOCOL,
    HI_UNF_IR_XMP,
    HI_UNF_IR_USER_DEFINED,
    HI_UNF_IR_PROTOCOL_BUTT
} HI_UNF_IR_PROTOCOL_E;

/** @} */  /** <!-- ==== Structure Definition End ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_5 */
/** @{ */  /** <!-- [KEYLED] */
/**keyled type*/
/**CNcomment:KEYLED类型 */
typedef enum  hiUNF_KEYLED_TYPE_E
{
    HI_UNF_KEYLED_TYPE_STD = 0x0, /**<KEYLED type inherent in HiSilicon chips*/   /**<CNcomment:海思芯片自带的KEYLED类型 */
    HI_UNF_KEYLED_TYPE_PT6961,    /**<KEYLED type: PT6961*/                       /**<CNcomment:KEYLED型号：PT6961 */
    HI_UNF_KEYLED_TYPE_CT1642,    /**<KEYLED type: CT1642*/                       /**<CNcomment:KEYLED型号：CT1642 */
    HI_UNF_KEYLED_TYPE_PT6964,	  /**<KEYLED type: PT6964*/ 
    HI_UNF_KEYLED_TYPE_BUTT       
}HI_UNF_KEYLED_TYPE_E;

/**state of key*/
/**CNcomment:按键状态*/
typedef enum  hiUNF_KEY_STATUS_E
{
    HI_UNF_KEY_STATUS_DOWN = 0 ,   /**<Pressed*/   /**<CNcomment:按下按键 */
    HI_UNF_KEY_STATUS_HOLD ,       /**<Hold*/      /**<CNcomment:按住不动 */
    HI_UNF_KEY_STATUS_UP ,         /**<Released*/  /**<CNcomment:抬起按键 */

    HI_UNF_KEY_STATUS_BUTT
}HI_UNF_KEY_STATUS_E ;

/**Blink frequency level of the LED*/
/**CNcomment:LED闪烁频率级别*/
typedef enum hiUNF_KEYLED_LEVEL_E
{
    HI_UNF_KEYLED_LEVEL_1 = 0x01,   /**<Level 1, slowest*/  /**<CNcomment:级别1,闪烁频率最慢*/
    HI_UNF_KEYLED_LEVEL_2,          /**<Level 2*/           /**<CNcomment:级别2 */
    HI_UNF_KEYLED_LEVEL_3,          /**<Level 3*/           /**<CNcomment:级别3 */
    HI_UNF_KEYLED_LEVEL_4,          /**<Level 4*/           /**<CNcomment:级别4 */
    HI_UNF_KEYLED_LEVEL_5,          /**<Level 5, fastest*/  /**<CNcomment:级别5 , 闪烁频率最快*/

    HI_UNF_KEYLED_LEVEL_BUTT
}HI_UNF_KEYLED_LEVEL_E;

/**Blink sequence of LEDs*/
/**CNcomment:闪烁的LED序号*/
typedef enum hiUNF_KEYLED_LIGHT_E
{
    HI_UNF_KEYLED_LIGHT_1 = 0x01,   /**<The first LED blinks.*/   /**<CNcomment:第1个LED闪烁*/
    HI_UNF_KEYLED_LIGHT_2,          /**<The second LED blinks.*/  /**<CNcomment:第2个LED闪烁*/
    HI_UNF_KEYLED_LIGHT_3,          /**<The third LED blinks.*/   /**<CNcomment:第3个LED闪烁*/
    HI_UNF_KEYLED_LIGHT_4,          /**<The fourth LED blinks.*/  /**<CNcomment:第4个LED闪烁*/
    HI_UNF_KEYLED_LIGHT_ALL,        /**<*All LEDs blink.*/        /**<CNcomment:所有LED均闪烁*/
    HI_UNF_KEYLED_LIGHT_NONE,       /**<All LEDs do not blink.*/  /**<CNcomment:所有LED均不闪烁*/

    HI_UNF_KEYLED_LIGHT_BUTT
}HI_UNF_KEYLED_LIGHT_E;

/**Display time of each LED*/
/**CNcomment:LED显示时间*/
typedef struct hiUNF_KEYLED_Time_S
{
    HI_U32 u32Hour;           /**<Hour*/   /**<CNcomment:时*/
    HI_U32 u32Minute;         /**<Minute*/ /**<CNcomment:分*/
}HI_UNF_KEYLED_TIME_S, *HI_UNF_KEYLED_TIME_S_PTR;

/** @} */  /** <!-- ==== Structure Definition End ==== */


/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_6 */
/** @{ */  /** <!-- [ARM MODE] */
/**ARM mode*/
/**CNcomment:ARM所处的模式*/
typedef enum hiUNF_PMOC_MODE_E
{
    HI_UNF_PMOC_MODE_NORMAL = 0,    /**<Normal*/
    HI_UNF_PMOC_MODE_SLOW,          /**<Slow*/
    HI_UNF_PMOC_MODE_DOZE,          /**<Doze*/
    HI_UNF_PMOC_MODE_SLEEP,         /**<Sleep*/

    HI_UNF_PMOC_MODE_BUTT
}HI_UNF_PMOC_MODE_E;
/** @} */  /** <!-- ==== Structure Definition End ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_7 */
/** @{ */  /** <!-- [PM] */

/**standby woken type*/
/**CNcomment:待机被唤醒的类型 */
typedef enum hiUNF_PMOC_ACTUAL_WKUP_E
{
     HI_UNF_PMOC_WKUP_IR  =0,     /**<Woken by the IR module*/                /**<CNcomment:被IR唤醒 */
     HI_UNF_PMOC_WKUP_KEYLED,     /**<Woken by the keys on the front panel*/  /**<CNcomment:被前面板KEY唤醒 */
     HI_UNF_PMOC_WKUP_TIMEOUT,    /**<Woken by the timing interrupt*/         /**<CNcomment:被定时中断唤醒 */
     HI_UNF_PMOC_WKUP_BUTT        
}HI_UNF_PMOC_ACTUAL_WKUP_E;

typedef enum hiUNF_PMOC_SCENE_E
{
     HI_UNF_PMOC_SCENE_STANDARD  =0, /**<Standard scenario*/                    /**<CNcomment:标准场景 */
     HI_UNF_PMOC_SCENE_ETH,          /**<Forward scenario over the ETH port */  /**<CNcomment:网口转发场景 */
     HI_UNF_PMOC_SCENE_PHONE,        /**<Calling scenario*/                     /**<CNcomment:通话场景 */
     HI_UNF_PMOC_SCENE_BUTT        
}HI_UNF_PMOC_SCENE_E;

#define PMOC_WKUP_IRKEY_MAXNUM    6
/**Defines the standby wake-up conditions.*/
/**CNcomment:待机唤醒的条件定义*/
typedef struct hiUNF_PMOC_WKUP_S
{
	/**<Number of supported values of the power key. For the raw IR remote control, the number cannot be greater than the maximum key value 5 that is defined by the macro definition PMOC_WKUP_IRKEY_MAXNUM. Only one key value is supported for other remote controls.*/	
  /**<CNcomment:能够支持power键值个数，raw 型红外遥控: 不能超越PMOC_WKUP_IRKEY_MAXNUM(<=5)宏定义所述个数键值，其余类型只能支持一个键值*/  
    HI_U32 u32IrPmocNum;	
    			
    HI_U32 u32IrPowerKey0[PMOC_WKUP_IRKEY_MAXNUM];	/**<Lower-bit value of the power key on an IR remote control*/	/**<CNcomment:红外遥控 power 低位键值 */
    HI_U32 u32IrPowerKey1[PMOC_WKUP_IRKEY_MAXNUM];	/**<Upper-bit value of the power key on an IR remote control*/	/**<CNcomment:红外遥控 power 高位键值 */
    HI_U32 u32KeypadPowerKey;   		              	/**<Value of the power key*/                                  	/**<CNcomment:按键 power键值 */
    HI_U32 u32WakeUpTime ; 			                  	/**<Preconfigured Wake-up time, in second*/                    	/**<CNcomment:唤醒定时时间 ,单位为 秒  */
}HI_UNF_PMOC_WKUP_S, *HI_UNF_PMOC_WKUP_S_PTR;

/**Configures the time displayed on the front panel in standby mode.*/
/**CNcomment:待机时的前面板显示的时间配置 */
typedef struct hiUNF_PMOC_TIME_S
{
    HI_U32  	u32Hour;       /**<Hour*/     /**<CNcomment:时 */
    HI_U32  	u32Minute;     /**<Minute*/   /**<CNcomment:分 */
    HI_U32  	u32Second;     /**<Second*/   /**<CNcomment:秒 */
}HI_UNF_PMOC_TIME_S,*HI_UNF_PMOC_TIME_S_PTR;

/**Configures the display mode of the front panel in standby mode.*/
/**CNcomment:待机时的前面板显示配置 */
typedef struct hiUNF_PMOC_STANDBY_MODE_S
{
    HI_U32		u32Mode;	         /**<0: no display; 1: display the digits represented by u32DispCod; 2: display the time represented by stTimeInfo*/     /**<CNcomment:0 : 无显示 1 : 显示u32DispCode代表的数字; 2 : 显示stTimeInfo代表的时间. */
    HI_U32		u32DispCode;	     /**<Digits displayed on the front panel when u32Mode is 1*/                                                             /**<CNcomment:u32Mode为1时，前面板显示的数字*/
	HI_UNF_PMOC_TIME_S stTimeInfo; /**<Time displayed on the front panel when u32Mode is 2*/	                                                             /**<CNcomment:u32Mode为2时，前面板显示的时间*/
}HI_UNF_PMOC_STANDBY_MODE_S, *HI_UNF_PMOC_STANDBY_MODE_S_PTR;


/**Type of the device that is woken in standby mode*/
/**CNcomment:待机唤醒的设备类型 */
typedef struct hiUNF_PMOC_DEV_TYPE_S
{
	HI_UNF_IR_CODE_E  irtype;	    /**<Type of the IR remote control*/	 /**<CNcomment:红外遥控类型 */
	HI_UNF_KEYLED_TYPE_E  kltype; /**<Type of the front panel*/        /**<CNcomment:前面板类型 */
}HI_UNF_PMOC_DEV_TYPE_S, *HI_UNF_PMOC_DEV_TYPE_S_PTR;

/** @} */  /** <!-- ==== Structure Definition End ==== */


/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_8 */
/** @{ */  /** <!-- [WDG] */
/**Response mode of the watchdog (WDG)*/
/**CNcomment:WDG响应模式*/
typedef enum hiUNF_WDG_RESPOND_MODE_E
{
    HI_UNF_WDG_RESPOND_MODE_FIRSTRESET = 0, /**<The WDG resets the system for the first time when the WDG is not fed.*/                         /**<CNcomment:WDG第一次复位*/
    HI_UNF_WDG_RESPOND_MODE_SECONDRESET,    /**<The WDG interrupts the system for the first time, and resets the system for the second time.*/  /**<CNcomment:WDG第一次中断，第二次复位*/

    HI_UNF_WDG_RESPOND_MODE_BUTT
}HI_UNF_WDG_RESPOND_MODE_E;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_9 */
/** @{ */  /** <!-- [I2C] */

/**Rate type of the I2C module*/
/**CNcomment:I2C的速率类型 */
typedef enum hiUNF_I2C_RATE_E
{
		HI_UNF_I2C_RATE_10K = 0,   /**<Standard rate: 10 kbit/s*/   /**<CNcomment:标准速率：10kbit/s*/
    HI_UNF_I2C_RATE_50K , 	   /**<Standard rate: 50 kbit/s*/   /**<CNcomment:标准速率：50kbit/s*/
    HI_UNF_I2C_RATE_100K ,     /**<Standard rate: 100 kbit/s*/  /**<CNcomment:标准速率：100kbit/s*/
    HI_UNF_I2C_RATE_200K ,     /**<Standard rate: 200 kbit/s*/  /**<CNcomment:标准速率：200kbit/s*/
    HI_UNF_I2C_RATE_300K ,     /**<Standard rate: 300 kbit/s*/  /**<CNcomment:标准速率：300kbit/s*/
    HI_UNF_I2C_RATE_400K,      /**<Fast rate: 400 kbit/s*/      /**<CNcomment:快速速率：400kbit/s*/

    HI_UNF_I2C_RATE_BUTT
}HI_UNF_I2C_RATE_E;

/** @} */  /** <!-- ==== Structure Definition End ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_10 */
/** @{ */  /** <!-- [CIPHER] */


#define HI_UNF_CIPHER_MIN_CRYPT_LEN      8       /**min length of encrypt, unit: byte*/  /**<CNcomment: 最小加解密长度，单位byte */
#define HI_UNF_CIPHER_MAX_CRYPT_LEN      0xfffff /**max length of encrypt, unit: byte*/  /**<CNcomment: 最大加解密长度，单位byte */

/**CIPHER work mode*/
/**CNcomment:CIPHER工作模式*/
typedef enum hiHI_UNF_CIPHER_WORK_MODE_E
{
    HI_UNF_CIPHER_WORK_MODE_ECB = 0x0,   /**<Electronic codebook (ECB) mode*/    /**<CNcomment:ECB模式。*/
    HI_UNF_CIPHER_WORK_MODE_CBC = 0x1,   /**<Cipher block chaining (CBC) mode*/  /**<CNcomment:CBC模式。*/
    HI_UNF_CIPHER_WORK_MODE_CFB = 0x2,   /**<Cipher feedback (CFB) mode*/        /**<CNcomment:CFB模式。*/
    HI_UNF_CIPHER_WORK_MODE_OFB = 0x3,   /**<Output feedback (OFB) mode*/        /**<CNcomment:OFB模式。*/
    HI_UNF_CIPHER_WORK_MODE_CTR = 0x4,   /**<Counter (CTR) mode*/                /**<CNcomment:CTR模式。*/
    HI_UNF_CIPHER_WORK_MODE_BUTT = 0x5    

}HI_UNF_CIPHER_WORK_MODE_E;

/**Cipher algorithm*/
/**CNcomment:CIPHER加密算法*/
typedef enum hiHI_UNF_CIPHER_ALG_E
{
    HI_UNF_CIPHER_ALG_DES  = 0x0,  /**<Data encryption standard (DES) algorithm*/     /**<CNcomment: DES算法*/
    HI_UNF_CIPHER_ALG_3DES = 0x1,  /**<3DES algorithm*/                               /**< CNcomment:3DES算法*/
    HI_UNF_CIPHER_ALG_AES  = 0x2,  /**<Advanced encryption standard (AES) algorithm*/ /**<CNcomment: AES算法*/
    HI_UNF_CIPHER_ALG_BUTT = 0x3   
}HI_UNF_CIPHER_ALG_E;

/**Key length*/
/**CNcomment: 密钥长度*/
typedef enum hiHI_UNF_CIPHER_KEY_LENGTH_E
{
    HI_UNF_CIPHER_KEY_AES_128BIT = 0x0,  /**<128-bit key for the AES algorithm*/ /**<CNcomment:AES运算方式下采用128bit密钥长度*/
    HI_UNF_CIPHER_KEY_AES_192BIT = 0x1,  /**<192-bit key for the AES algorithm*/ /**<CNcomment:AES运算方式下采用192bit密钥长度*/
    HI_UNF_CIPHER_KEY_AES_256BIT = 0x2,  /**<256-bit key for the AES algorithm*/ /**<CNcomment:AES运算方式下采用256bit密钥长度*/
    HI_UNF_CIPHER_KEY_DES_3KEY = 0x2,    /**<Three keys for the DES algorithm*/  /**<CNcomment:DES运算方式下采用3个key */
    HI_UNF_CIPHER_KEY_DES_2KEY = 0x3,    /**<Two keys for the DES algorithm*/    /**<CNcomment: DES运算方式下采用2个key  */
}HI_UNF_CIPHER_KEY_LENGTH_E;

/**Cipher bit width*/
/**CNcomment: 加密位宽*/
typedef enum hiHI_UNF_CIPHER_BIT_WIDTH_E
{
    HI_UNF_CIPHER_BIT_WIDTH_64BIT  = 0x0,  /**<64-bit width*/   /**<CNcomment:64bit位宽*/
    HI_UNF_CIPHER_BIT_WIDTH_8BIT   = 0x1,  /**<8-bit width*/    /**<CNcomment:8bit位宽*/
    HI_UNF_CIPHER_BIT_WIDTH_1BIT   = 0x2,  /**<1-bit width*/    /**<CNcomment:1bit位宽*/
    HI_UNF_CIPHER_BIT_WIDTH_128BIT = 0x3,  /**<128-bit width*/  /**<CNcomment:128bit位宽*/
}HI_UNF_CIPHER_BIT_WIDTH_E;

//////////////////////////////////////////////
/**symbol of cipher control parameter exchange*/
/**CNcomment:加密控制参数变更标志 */
typedef struct hiUNF_CIPHER_CTRL_CHANGE_FLAG_S
{
    HI_U32   bit1IV:1;              /**<CNcomment:向量变更 */    
    HI_U32   bitsResv:31;           /**<CNcomment:保留  */
}HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S;

/**symbol of using which key ladder for cipher*/
/**CNcomment:使用哪个key ladder标志 */
typedef enum hiUNF_CIPHER_CA_TYPE_E
{
    HI_UNF_CIPHER_CA_TYPE_R2R = 0,    /**<Using R2R key ladder*/                                                    /**<CNcomment:使用R2R key ladder */
    HI_UNF_CIPHER_CA_TYPE_SP  = 1,    /**<Using SP key ladder*/                                                    /**<CNcomment:使用SP key ladder */
}HI_UNF_CIPHER_CA_TYPE_E;

/**Structure of the cipher control information*/
/**CNcomment:加密控制信息结构 */
typedef struct hiHI_UNF_CIPHER_CTRL_S
{
    HI_U32                              u32Key[8];    /**<Key*/                                                                                                       /**<CNcomment:密钥*/
    HI_U32                              u32IV[4];     /**<Initialization vector (IV)*/                                                                                /**<CNcomment:初始向量*/
    HI_BOOL                             bKeyByCA;     /**<Encryption using advanced conditional access (CA) or decryption using keys*/                                /**<CNcomment:是否使用高安全CA加密或解密KEY*/
    HI_UNF_CIPHER_CA_TYPE_E             enCaType;     /**<Using the R2R key or SP key when using advanced CA*/                                                  /**< CNcomment:使用高安全CA时使用SP Key或R2R Key*/
    HI_UNF_CIPHER_ALG_E                 enAlg;        /**<Cipher algorithm*/                                                                                          /**<CNcomment:加密算法*/
    HI_UNF_CIPHER_BIT_WIDTH_E           enBitWidth;   /**<Bit width for encryption or decryption*/                                                                    /**<CNcomment:加密或解密的位宽*/
    HI_UNF_CIPHER_WORK_MODE_E           enWorkMode;   /**<Operating mode*/                                                                                            /**<CNcomment:工作模式*/
    HI_UNF_CIPHER_KEY_LENGTH_E          enKeyLen;     /**<Key length*/                                                                                                /**<CNcomment:密钥长度 */
    HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S    stChangeFlags;/**control information exchange choices, we default all woulde be change except they have been in the choices*/ /**<CNcomment:控制信息变更选项，选项中没有标识的项默认全部变更  */  
} HI_UNF_CIPHER_CTRL_S;

/**cipher data*/
/**CNcomment:加解密数据 */
typedef struct hiHI_UNF_CIPHER_DATA_S
{
    HI_U32 u32SrcPhyAddr;     /**phy address of the original data*/   /**<CNcomment:源数据物理地址*/
    HI_U32 u32DestPhyAddr;    /**phy address of the purpose data*/    /**<CNcomment:目的数据物理地址*/
    HI_U32 u32ByteLength;     /**cigher data length*/                 /**<CNcomment:加解密数据长度*/
} HI_UNF_CIPHER_DATA_S;

typedef enum hiHI_UNF_CIPHER_HASH_TYPE_E
{
    HI_UNF_CIPHER_HASH_TYPE_SHA1 = 0x0,
    HI_UNF_CIPHER_HASH_TYPE_SHA256 = 0x1,
    HI_UNF_CIPHER_HASH_TYPE_BUTT,
}HI_UNF_CIPHER_HASH_TYPE_E;


/** @} */  /** <!-- ==== Structure Definition End ==== */


/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_12 */
/** @{ */  /** <!-- [OTP] */
#define OTP_HDCP_KEY_LEN   320

typedef enum hiHI_UNF_OTP_AREATYPE_E
{
    HI_UNF_OTP_AREATYPE_HDCPKEY,
    HI_UNF_OTP_AREATYPE_BUTT
}HI_UNF_OTP_AREATYPE_E;



typedef struct hiUNF_DECRYPT_HDCP_S
{
	HI_U8 u8KSV[5];                         /**<HDCP KSV:40bits, Orignal data */
	HI_U8 u8PrivateKey[280];                /**<HDCP Device Private key:40*56bits, Orignal data */
}HI_UNF_DECRYPT_HDCP_S;

typedef struct hiUNF_ENCRYPT_HDCP_S
{
	HI_U8 u8EncryptKey[384];                /**<HDCP Encryption key */
}HI_UNF_ENCRYPT_HDCP_S;

typedef struct
{
    HI_BOOL EncryptionFlag;                 /**<HI_TRUE:Encryption, HI_FALSE: Uncryption */
    
    union
    {
        HI_UNF_DECRYPT_HDCP_S DecryptData;  /**<Orignal data, if EncryptionFlag == HI_FALSE */
        HI_UNF_ENCRYPT_HDCP_S EncryptData;  /**<Encrpytion data, if EncryptionFlag == HI_TRUE */
    }key;

    HI_U32 Reserved;                        /**<Reserved for future use */
}HI_UNF_OTP_HDCPKEY_S;

typedef struct
{
    HI_BOOL EncryptionFlag;                 /**<HI_TRUE:Encryption, HI_FALSE: Uncryption */
    
    union
    {
        HI_UNF_DECRYPT_HDCP_S DecryptData;  /**<Orignal data, if EncryptionFlag == HI_FALSE */
        HI_UNF_ENCRYPT_HDCP_S EncryptData;  /**<Encrpytion data, if EncryptionFlag == HI_TRUE */
    }key;

    HI_U32 Reserved;                        /**<Reserved for future use */
}HI_UNF_ADVCA_HDCPKEY_S;

/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_4_12 */
/** @{ */  /** <!-- [CI] */

/**support CI Port*/
/**CNcomment:支持的CI Port */
typedef enum hiUNF_CI_PORT_E
{
    HI_UNF_CI_PORT_0,
    HI_UNF_CI_PORT_1,
    HI_UNF_CI_PORT_BUTT
} HI_UNF_CI_PORT_E;

/**support CI PCMCIA Cards(Module)*/
/**CNcomment:支持的CI PCMCIA Cards(Module) */
typedef enum hiUNF_CI_PCCD_E
{
    HI_UNF_CI_PCCD_A,
    HI_UNF_CI_PCCD_B,
    HI_UNF_CI_PCCD_BUTT
} HI_UNF_CI_PCCD_E;

/**Module on-off power control*/
/**CNcomment:Module开关电源控制 */
typedef enum hiUNF_CI_PCCD_CTRLPOWER_E
{
    HI_UNF_CI_PCCD_CTRLPOWER_ON,
    HI_UNF_CI_PCCD_CTRLPOWER_OFF,
    HI_UNF_CI_PCCD_CTRLPOWER_BUFF
} HI_UNF_CI_PCCD_CTRLPOWER_E;

/**Module ready state:ready/busy*/
/**CNcomment:Module就绪状态:ready/busy */
typedef enum hiUNF_CI_PCCD_READY_E
{
    HI_UNF_CI_PCCD_BUSY,
    HI_UNF_CI_PCCD_READY
} HI_UNF_CI_PCCD_READY_E, *HI_UNF_CI_PCCD_READY_E_PTR;

/**Module online state:present/absent*/
/**CNcomment:Module在线状态:present/absent */
typedef enum hiUNF_CI_PCCD_STATUS_E
{
    HI_UNF_CI_PCCD_STATUS_ABSENT,
    HI_UNF_CI_PCCD_STATUS_PRESENT,
    HI_UNF_CI_PCCD_STATUS_BUTT
} HI_UNF_CI_PCCD_STATUS_E, *HI_UNF_CI_PCCD_STATUS_E_PTR;

/**card call mode*/
/**CNcomment:卡访问模式 */
typedef enum hiUNF_CI_PCCD_ACCESSMODE_E
{
    HI_UNF_CI_PCCD_ACCESS_ATTR,
    HI_UNF_CI_PCCD_ACCESS_IO,
    HI_UNF_CI_PCCD_ACCESS_COMMON,
    HI_UNF_CI_PCCD_ACCESS_BUTT
} HI_UNF_CI_PCCD_ACCESSMODE_E;

/**get state register mask code*/
/**CNcomment:获取状态寄存器掩码 */
typedef enum hiUNF_CI_PCCD_STATUS_REG_E
{
    HI_UNF_CI_PCCD_STATUS_BIT_ALL,  /**get all bits*/               /**<CNcomment:获取所有位 */
    HI_UNF_CI_PCCD_STATUS_BIT_DA,   /**get Data Available bit*/     /**<CNcomment:获取Data Available位 */
    HI_UNF_CI_PCCD_STATUS_BIT_FR,   /**get Free bit*/               /**<CNcomment:获取Free位 */
    HI_UNF_CI_PCCD_STATUS_BIT_RE,   /**get Read Error bit*/         /**<CNcomment:获取Read Error位 */
    HI_UNF_CI_PCCD_STATUS_BIT_WE,   /**get Write Error bit*/        /**<CNcomment:获取Write Error位 */
    HI_UNF_CI_PCCD_STATUS_BIT_BUTT
} HI_UNF_CI_PCCD_STATUS_BIT_E;

/* Added begin 2012-04-24 l00185424: support various CI device */
/**The mode of CI Transport Stream Interface connection */
/**CNcomment:CI TSI连接方式 */
typedef enum hiUNF_CI_TSI_MODE_E
{
    HI_UNF_CI_TSI_DAISY_CHAINED,      /* Daisy-chained */
    HI_UNF_CI_TSI_INDEPENDENT,        /* Independent, non-daisy-chained */
    HI_UNF_CI_TSI_BUTT
}HI_UNF_CI_TSI_MODE_E;

/**The mode of TS pass to the CI device*/
/**CNcomment:过CI设备的TS流模式 */
typedef enum hiUNF_CI_TS_MODE_E
{
    HI_UNF_CI_TS_SERIAL,         /* serial */
    HI_UNF_CI_TS_PARALLEL,       /* Parallel TS, default */
    HI_UNF_CI_TS_USB2SERIAL,     /* USB input, serial output */
    HI_UNF_CI_TS_USB2PARALLEL,   /* USB input, parallel output */
    HI_UNF_CI_TS_BUTT
}HI_UNF_CI_TS_MODE_E;

/**CI device*/
/**CNcomment:支持的CI设备 */
typedef enum hiUNF_CI_DEV_E
{
    HI_UNF_CI_DEV_CIMAX,        /* CIMaX, default */
    HI_UNF_CI_DEV_CIMAXPLUS,    /* CIMaX+ */
    HI_UNF_CI_DEV_HICI,         /* HICI */
    HI_UNF_CI_DEV_STARCI2WIN,   /* StarCI2Win */
    HI_UNF_CI_DEV_BUTT
}HI_UNF_CI_DEV_E;

/**CIMaX device configuration*/
/**CNcomment:CIMaX设备配置 */
typedef struct hiUNF_CI_CIMAX_ATTR_S
{
    HI_U32  u32SMIBitWidth;
    HI_U32  u32SMIBaseAddr;         /* SMI Base Address */
    HI_U32  u32I2cNum;              /* I2C Group */
    HI_U8   u8DevAddress;           /* I2C device address */
}HI_UNF_CI_CIMAX_ATTR_S, *HI_UNF_CI_CIMAX_ATTR_S_PTR;

/**CIMaX+ device configuration*/
/**CNcomment:CIMaX+设备配置 */
typedef struct hiUNF_CI_CIMAXPLUS_ATTR_S
{
    HI_U32  u32ResetGpioNo; /* The GPIO to reset the device */
}HI_UNF_CI_CIMAXPLUS_ATTR_S, *HI_UNF_CI_CIMAXPLUS_ATTR_S_PTR;

/**CI device configuration*/
/**CNcomment:CI设备配置 */
typedef struct hiUNF_CI_ATTR_S
{
    HI_UNF_CI_DEV_E enDevType;      /* CI device type */    
    HI_UNF_CI_TSI_MODE_E enTSIMode; /* The mode of CI Transport Stream Interface connection */
    /* The mode of TS pass to the CI device */
    HI_UNF_CI_TS_MODE_E enTSMode[HI_UNF_CI_PCCD_BUTT]; 
    union
    {
        HI_UNF_CI_CIMAX_ATTR_S stCIMaX;
        HI_UNF_CI_CIMAXPLUS_ATTR_S stCIMaXPlus;
    }unDevAttr;
}HI_UNF_CI_ATTR_S, *HI_UNF_CI_ATTR_S_PTR;
/* Added end 2012-04-24 l00185424: support various CI device */
/**TS control command*/
/**CNcomment:TS控制命令 */
typedef enum hiUNF_CI_PCCD_TSCTRL_E
{
    HI_UNF_CI_PCCD_TSCTRL_BYPASS,
    HI_UNF_CI_PCCD_TSCTRL_SETMODE,
    HI_UNF_CI_PCCD_TSCTRL_WRITETS,
    HI_UNF_CI_PCCD_TSCTRL_BUTT
}HI_UNF_CI_PCCD_TSCTRL_E;
/**USB TS Write parameter*/
/**CNcomment:USB送流参数 */
typedef struct hiUNF_CI_PCCD_TSWRITE_S
{
    HI_U8* pu8Data;     /**<Write data [in]*/
    HI_U32 u32Size;     /**<Write data size [in]*/
}HI_UNF_CI_PCCD_TSWRITE_S;

/**TS control parameter*/
/**CNcomment:TS控制参数 */
typedef union 
{
    struct
    {
        HI_BOOL bByPass;    /**<TURE means bypass, FALSE means pass-through*/  /**<CNcomment:TRUE表示bypass, FALSE表示pass-through */
    }stByPass;

    struct
    {
        HI_UNF_CI_TS_MODE_E enTSMode;        /**<TS mode: parallel/serial/USB */
    }stMode;

    HI_UNF_CI_PCCD_TSWRITE_S stWrite;
    
    /* For extend */
}HI_UNF_CI_PCCD_TSCTRL_PARAM_U;


/** @} */  /** <!-- ==== Structure Definition end ==== */


//////////////////////////////////////////////
//////////////////////////////////////////////

/******************************* API declaration *****************************/
/** \addtogroup      H_1_4_1 */
/** @{ */  /** <!-- [SCI] */
/** 
\brief Initializes the SCI.   CNcomment:\brief SCI初始化
\attention \n
\param  N/A                   CNcomment:\param 无
\retval 0 Success             CNcomment:\retval 0 成功

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_Init(HI_VOID);

/** 
\brief Deinitializes the SCI. CNcomment:\brief SCI去初始化
\attention \n
\param  N/A                   CNcomment:\param 无
\retval 0 Success             CNcomment:\retval 0 成功

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_DeInit(HI_VOID);

/** 
\brief Starts an SCI device to initialize it based on the input port and protocol. If there is an SCI card, the card is also initialized.
CNcomment:\brief 打开SCI（Smart Card Interface）设备，针对输入的端口和协议，进行SCI接口设备的初始化；如果卡存在，则同时对卡进行初始化

\attention \n
This application programming interface (API) cannot be called repeatedly.\n
After an SCI device is started, it is initialized based on the default configuration.\n
If you modify the configuration, you need to call HI_UNF_SCI_ResetCard for the modifications to take effect.\n
If you remove and then insert the SCI card, you need to call HI_UNF_SCI_ResetCard to reset the card.
You need to set frequency parameters when enabling an SCI device. The actual SCI clock provided by the chip is obtained by using the clock divider.\n
The clock divider is calculated based on the externally transferred clock frequency parameters. The fractional part of the clock divider is discarded during calculation. \n
Therefore, an enhanced error occurs when the SCI clock is obtained by dividing the system clock by the clock divider. You need to set the actual output frequency of the \n
SCI card based on the close output frequency. The SCI clock is calculated as follows: Fsci_clk = Frefclk/[(Clkicc + 1) x 2]. Where, Frefclk is the 96 MHz system clock, \n
Fsci_clk is the SCI clock required by peripherals, and clkicc is the required clock divider of registers. clkicc is calculated as follows: Clkicc = Frefclk/(2 x Fsci_clk) - 1. \n
The clkicc may be a floating point value, but only the integral part is used. Therefore, the configured frequency is different from the actual frequency.\n

CNcomment: 重复打开会失败\n
CNcomment: 打开后SCI设备采用默认配置对设备进行初始化\n
CNcomment: 之后如果更改了配置，需要调用HI_UNF_SCI_ResetCard来使配置生效\n
CNcomment: 之后如果对卡进行拔插，需要调用HI_UNF_SCI_ResetCard来进行复位。
CNcomment: 打开设备的时候需要设置频率参数，而芯片实际给SCI 的时钟是由外部传入的
CNcomment: 时钟频率参数计算的分频因子分频得来，因为计算公式会舍弃计算的分频因子的小数部分，
CNcomment: 所以通过系统时钟分频之后给卡的时钟会存在增量误差，实际配置考虑与需求最接近的值来
CNcomment: 设置和权衡，具体算法:Fsci_clk = Frefclk/((clkicc+1)*2);其中Frefclk是系统96M时钟Fsci_clk 是外部需要设置的
CNcomment: sci时钟,实际要配入寄存器分频因子clkicc = Frefclk/(2*Fsci_clk) -1;clkicc 有时候计算出来是浮点数，但只取整，
CNcomment: 所以设置的频率与实际频率有偏差。

\param[in] enSciPort     ID of an SCI port. The port ID can be 0 or 1.  CNcomment:SCI端口号，取值范围为0和1
\param[in] enSciProtocol Protocol type                                  CNcomment:协议类型
\param[in] u32Frequency    Frequency of the SCI card to be set, in kHz. For the T0 and T1 cards, the frequency ranges from 1 MHz to 5 MHz; for the T14 card, the frequency must be set to 6 MHz.  CNcomment:要设置的SCI卡频率。对于T0，T1卡，支持频率1MHz～5MHz；对于T14卡，只支持6MHz。单位为khz
\retval 0 Success                                                       CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT  SCI  No SCI device is started.           CNcomment:设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT   The SCI device has been started.     CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT  The pointer is invalid.             CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.            CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT The SCI device fails to be started.    CNcomment:打开SCI设备失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_Open(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_PROTOCOL_E enSciProtocol, HI_U32 u32Frequency);

/** 
\brief Stops an SCI device.
CNcomment:\brief 关闭SCI设备。

\attention \n
This API cannot be called repeatedly.
CNcomment:重复关闭会失败。

\param[in] enSciPort     ID of an SCI port. The port ID can be 0 or 1.  CNcomment:SCI端口号，取值范围为0和1
\retval 0 Success                                                       CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.               CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_INVALID_POINT The pointer is invalid.              CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.            CNcomment:非法参数
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_Close(HI_UNF_SCI_PORT_E enSciPort);


/** 
\brief Performs a warm reset on an SCI card.
CNcomment:\brief 热复位SCI卡。

\attention \n
If no SCI card is inserted, the reset fails.\n
If you modify the configuration of an SCI device, you need to call HI_S32 HI_UNF_SCI_ResetCard for the modifications to take effect.\n
In addition, if you remove and insert an SCI card after calling HI_UNF_SCI_Open, you also need to call HI_S32 HI_UNF_SCI_ResetCard to reset the card.
CNcomment:没有插入卡，复位会失败\n
CNcomment: 当更改了SCI设备的配置后，需要调用该接口使配置生效\n
CNcomment: 在调用打开SCI设备接口后，对卡进行拔插，也需要调用该接口进行复位。

\param[in] enSciPort   ID of an SCI port. The port ID can be 0 or 1                                             CNcomment:SCI端口号，取值范围为0和1。
\param[in] bWarmResetValid   Reset mode. The value can be 0 or 1. 0: warm reset; 1: cold reset (recommended)    CNcomment:复位方式，取值范围为0和1。0:warm reset,1:cold reset（推荐用这种方式）。
\retval 0 Success                                                                                               CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT The SCI device has been started.                                               CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT  The pointer is invalid.                                                     CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.                                           CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET A warm reset fails to be performed.                                           CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE The SCI card fails to be deactivated.                                      CNcomment:去激活失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_ResetCard(HI_UNF_SCI_PORT_E enSciPort, HI_BOOL bWarmResetValid);


/** 
\brief Deactivates an SCI card.
CNcomment:\brief 去激活SCI卡。

\attention \n
After an SCI card is deactivated, the card cannot be read or written until it is reset.
CNcomment:去激活卡后，无法读写数据。只有重新复位卡后，才能继续读写。

\param[in] enSciPort ID of an SCI port. The port ID can be 0 or 1.         CNcomment:SCI端口号，取值范围为0和1。
\retval 0   Success                                                        CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT No SCI device is started.                    CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT   The SCI device has been started.        CNcomment: SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT The pointer is invalid.                 CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.               CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.      CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET A warm reset fails to be performed.      CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE The SCI card fails to be deactivated. CNcomment:去激活失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_DeactiveCard(HI_UNF_SCI_PORT_E enSciPort);


/** 
\brief Obtains the ATR data of an SCI card.
CNcomment:\brief 获取SCI卡ATR数据。

\attention \n
N/A 
\param[in]  enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                            CNcomment:SCI端口号，取值范围为0和1。
\param[in]  pu8AtrBuf   Length of the ATR data read from the buffer                                             CNcomment:ATR 数据读取 buffer 长度。
\param[in] u32AtrBufSize  Actual number of ATR data segments                                                    CNcomment:实际获取的ATR数据个数。
\param[in]  pu8AtrRcvCount Address for storing the obtained ATR data                                            CNcomment:获取的ATR数据的存储地址。
\retval 0   Success                                                                                             CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                                                       CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT  The SCI device has been started.                                              CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT The pointer is invalid.                                                      CNcomment: 非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.                                           CNcomment: 打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET A warm reset fails to be performed.                                           CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE  The SCI card fails to be deactivated.                                     CNcomment:去激活失败
\retval ::HI_ERR_SCI_FAILED_GETATR  The ATR data fails to be obtained.                                          CNcomment:获取ATR数据失败
\retval ::HI_ERR_SCI_FAILED_CARDSTATUS  The card status fails to be obtained.                                   CNcomment: 获取卡状态失败
\retval ::HI_ERR_SCI_FAILED_SEND  The transmission operation fails.                                             CNcomment: 发送操作失败
\retval ::HI_ERR_SCI_FAILED_RECEIVE The reception operation fails.                                              CNcomment: 接收操作失败
\retval ::HI_ERR_SCI_FAILED_TIMEOUT_VAL The block timeout fails to be set.                                      CNcomment:配置阻塞超时失败
\retval ::HI_ERR_SCI_FAILED_GET_DATA_LEN The length of the data that is not transmitted fails to be obtained.   CNcomment:获取未发送长度失败
\retval ::HI_ERR_SCI_FAILED_CONFIGVCCEN The VCCEN signal fails to be set.                                       CNcomment: 配置VCCEN信号失败
\retval ::HI_ERR_SCI_FAILED_CONFIGDETECT The DETECT signal fails to be set.                                     CNcomment:配置DETECT信号失败
\retval ::HI_ERR_SCI_FAILED_BLK_CARDSTATUS The card status fails to be obtained in block mode.                  CNcomment:阻塞方式获取卡状态失败
\retval ::HI_ERR_SCI_INVALID_PORT The port ID is incorrect.                                                     CNcomment:错误的端口号
\retval ::HI_ERR_SCI_INVALID_PROTOCOL The protocol type is incorrect.                                           CNcomment:错误的协议类型
\retval ::HI_ERR_SCI_INVALID_FREQUENCY The clock frequency is invalid.                                          CNcomment:非法的时钟频率
\retval ::HI_ERR_SCI_INVALID_LENTH The length is invalid.                                                       CNcomment:非法长度
\retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                              CNcomment:无ATR数据
\retval ::HI_ERR_SCI_CARD_STATUS  The card status is incorrect.                                                 CNcomment:卡状态错误
\retval ::HI_ERR_SCI_RECEIVE_TIMEOUT The data reception times out.                                              CNcomment:接收操作超时
\retval ::HI_ERR_SCI_INVALID_TIMEOUT_VAL The timeout is invalid.                                                CNcomment:非法超时时间值
\retval ::HI_ERR_SCI_INVALID_LEVEL_VAL The level is invalid.                                                    CNcomment:非法的电平
\retval ::HI_ERR_SCI_FAILED_BLK_TIMEOUT Obtaining the card status times out.                                    CNcomment:获取卡状态超时
\retval ::HI_ERR_SCI_FAILED_CONFIGSCIMODE  The operating mode of the CLK signal fails to be set.                CNcomment:配置CLK信号线工作模式失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_GetATR(HI_UNF_SCI_PORT_E enSciPort, HI_U8 *pu8AtrBuf, HI_U32 u32AtrBufSize, HI_U8 *pu8AtrRcvCount);


/** 
\brief Obtains the status of an SCI card.
CNcomment:\brief 获取SCI卡状态。

\attention \n
This API is a non-block API. You can transfer data to an SCI card by calling HI_UNF_SCI_Send or HI_UNF_SCI_Receive only when the card status is HI_UNF_SCI_STATUS_READY.
CNcomment:此接口是无阻塞函数，在卡的状态为HI_UNF_SCI_STATUS_READY时，才可调用HI_UNF_SCI_Send或HI_UNF_SCI_Receive接口与卡进行数据交互\n

\param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI端口号，取值范围为0和1。
\param[out] penSCIStatus  Status of an SCI card                                                                 CNcomment: SCI卡状态。
\retval 0 Success                                                                                               CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT  The SCI device has been started.                                              CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT The pointer is invalid.                                                      CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.                                           CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET  A warm reset fails to be performed.                                          CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE The SCI card fails to be deactivated.                                      CNcomment:去激活失败
\retval ::HI_ERR_SCI_FAILED_GETATR  The ATR data fails to be obtained.                                          CNcomment: 获取ATR数据失败
\retval ::HI_ERR_SCI_FAILED_CARDSTATUS The card status fails to be obtained.                                    CNcomment:获取卡状态失败
\retval ::HI_ERR_SCI_FAILED_SEND  The transmission operation fails.                                             CNcomment:发送操作失败
\retval ::HI_ERR_SCI_FAILED_RECEIVE  The reception operation fails.                                             CNcomment: 接收操作失败
\retval ::HI_ERR_SCI_FAILED_TIMEOUT_VAL The block timeout fails to be set.                                      CNcomment:配置阻塞超时失败
\retval ::HI_ERR_SCI_FAILED_GET_DATA_LEN  The length of the data that is not transmitted fails to be obtained.  CNcomment:获取未发送长度失败
\retval ::HI_ERR_SCI_FAILED_CONFIGVCCEN  The VCCEN signal fails to be set.                                      CNcomment:配置VCCEN信号失败
\retval ::HI_ERR_SCI_FAILED_CONFIGDETECT The DETECT signal fails to be set.                                     CNcomment:配置DETECT信号失败
\retval ::HI_ERR_SCI_FAILED_BLK_CARDSTATUS The card status fails to be obtained in block mode.                  CNcomment:阻塞方式获取卡状态失败
\retval ::HI_ERR_SCI_INVALID_PORT The port ID is incorrect.                                                     CNcomment:错误的端口号
\retval ::HI_ERR_SCI_INVALID_PROTOCOL  The protocol type is incorrect.                                          CNcomment: 错误的协议类型
\retval ::HI_ERR_SCI_INVALID_FREQUENCY  The clock frequency is invalid.                                         CNcomment:非法的时钟频率
\retval ::HI_ERR_SCI_INVALID_LENTH  The length is invalid.                                                      CNcomment:非法长度
\retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                              CNcomment:无ATR数据
\retval ::HI_ERR_SCI_CARD_STATUS  The card status is incorrect.                                                 CNcomment:卡状态错误
\retval ::HI_ERR_SCI_RECEIVE_TIMEOUT The data reception times out.                                              CNcomment:接收操作超时
\retval ::HI_ERR_SCI_INVALID_TIMEOUT_VAL  The timeout is invalid.                                               CNcomment:非法超时时间值
\retval ::HI_ERR_SCI_INVALID_LEVEL_VAL The level is invalid.                                                    CNcomment:非法的电平
\retval ::HI_ERR_SCI_FAILED_BLK_TIMEOUT  Obtaining the card status times out.                                   CNcomment:获取卡状态超时
\retval ::HI_ERR_SCI_FAILED_CONFIGSCIMODE The operating mode of the CLK signal fails to be set.                 CNcomment:配置CLK信号线工作模式失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_GetCardStatus(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_STATUS_E *penSciStatus);


/** 
\brief Transmits data to an SCI card.
CNcomment:\brief 向SCI卡发送数据。

\attention \n
Data must be transmitted based on application protocols.\n
Data cannot be transmitted consecutively.\n
In addition, data is transmitted and received in block mode. Therefore, when a large number of data is being transmitted, the transmission may fail if the timeout is too small.
CNcomment:发送数据需要按照应用协议来发送\n
CNcomment: 不能连续两次发送而中间不接收数据\n
CNcomment: 发送读取都是阻塞的，因此发送大量的数据时，受到超时时间的限制，如果超时值比较短，有可能发送失败。
            
\param[in] enSciPort   ID of an SCI port. The port ID can be 0 or 1.                                            CNcomment:SCI端口号，取值范围为0和1。
\param[in]  pSciSendBuf Address for storing the data to be transmitted                                          CNcomment:发送数据的存储地址。
\param[in] u32SendLen  Number of data segments (in byte) to be transmitted                                      CNcomment:发送数据的个数,单位为 BYTE。
\param[in]  pu32ActLen Number of transmitted data segments (in byte)                                            CNcomment:实际发送数据个数,单位为 BYTE。
\param[in] u32TimeoutMs Wait timeout (in ms). 0: not blocked; 0xFFFFFFFF: infinite block                        CNcomment:等待超时值, 单位是毫秒, 0 - 不阻塞, 0xFFFFFFFF-永久阻塞。
\retval 0 Success                                                                                               CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT  SCI  No SCI device is started.                                                   CNcomment:设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT The SCI device has been started.                                               CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT  The pointer is invalid.                                                     CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA The parameter is invalid.                                                     CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.                                           CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET A warm reset fails to be performed.                                           CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE  The SCI card fails to be deactivated.                                     CNcomment:去激活失败
\retval ::HI_ERR_SCI_FAILED_GETATR  The ATR data fails to be obtained.                                          CNcomment:获取ATR数据失败
\retval ::HI_ERR_SCI_FAILED_CARDSTATUS  The card status fails to be obtained.                                   CNcomment:获取卡状态失败
\retval ::HI_ERR_SCI_FAILED_SEND  The transmission operation fails.                                             CNcomment: 发送操作失败
\retval ::HI_ERR_SCI_FAILED_RECEIVE The reception operation fails.                                              CNcomment:接收操作失败
\retval ::HI_ERR_SCI_FAILED_TIMEOUT_VAL  The block timeout fails to be set.                                     CNcomment:配置阻塞超时失败
\retval ::HI_ERR_SCI_FAILED_GET_DATA_LEN The length of the data that is not transmitted fails to be obtained.   CNcomment:获取未发送长度失败
\retval ::HI_ERR_SCI_FAILED_CONFIGVCCEN The VCCEN signal fails to be set.                                       CNcomment:配置VCCEN信号失败
\retval ::HI_ERR_SCI_FAILED_CONFIGDETECT The DETECT signal fails to be set.                                     CNcomment:配置DETECT信号失败
\retval ::HI_ERR_SCI_FAILED_BLK_CARDSTATUS The card status fails to be obtained in block mode.                  CNcomment:阻塞方式获取卡状态失败
\retval ::HI_ERR_SCI_INVALID_PORT The port ID is incorrect.                                                     CNcomment:错误的端口号
\retval ::HI_ERR_SCI_INVALID_PROTOCOL The protocol type is incorrect.                                           CNcomment:错误的协议类型
\retval ::HI_ERR_SCI_INVALID_FREQUENCY  The clock frequency is invalid.                                         CNcomment:非法的时钟频率
\retval ::HI_ERR_SCI_INVALID_LENTH  The length is invalid.                                                      CNcomment:非法长度
\retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                              CNcomment:无ATR数据
\retval ::HI_ERR_SCI_CARD_STATUS  The card status is incorrect.                                                 CNcomment:卡状态错误
\retval ::HI_ERR_SCI_RECEIVE_TIMEOUT  The data reception times out.                                             CNcomment:接收操作超时
\retval ::HI_ERR_SCI_INVALID_TIMEOUT_VAL  The timeout is invalid.                                               CNcomment:非法超时时间值
\retval ::HI_ERR_SCI_INVALID_LEVEL_VAL The level is invalid.                                                    CNcomment: 非法的电平
\retval ::HI_ERR_SCI_FAILED_BLK_TIMEOUT  Obtaining the card status times out.                                   CNcomment:获取卡状态超时
\retval ::HI_ERR_SCI_FAILED_CONFIGSCIMODE  The operating mode of the CLK signal fails to be set.                CNcomment:配置CLK信号线工作模式失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_Send(HI_UNF_SCI_PORT_E enSciPort, HI_U8 *pSciSendBuf, HI_U32 u32SendLen, HI_U32 *pu32ActLen, HI_U32 u32TimeoutMs);


/** 
\brief Receives data from an SCI card.
CNcomment:\brief 从SCI卡接收数据。

\attention \n
You must set the data length obtained by each upper-layer application based on the protocol. If the length of the obtained data is greater than that of the returned data, this API is returned after timeout occurs.
CNcomment:上层应用程序必须根据协议来配置所获取的长度，如果希望获取的长度超出实际能够返回的长度，则只能等到超时到期才能返回。

\param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI端口号，取值范围为0和1。
\param[in]  pSciReceiveBuf   Address for storing the received data                                              CNcomment:接收数据的存储地址。
\param[in] u32ReceiveLen  Number of data segments (in byte) to be received                                      CNcomment:期望接收数据的个数,,单位为 BYTE。
\param[in]  pu32ActLen   Number of received data segments (in byte)                                             CNcomment:实际接收数据个数,单位为 BYTE。
\param[in] u32TimeOutMs  Wait timeout (in ms). 0: not blocked; 0xFFFFFFFF: infinite block                       CNcomment:等待超时值, 单位是毫秒, 0 - 不阻塞, 0xFFFFFFFF-永久阻塞。
\retval 0 Success                                                                                               CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                                                       CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT  The SCI device has been started.                                              CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT  The pointer is invalid.                                                     CNcomment: 非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT The SCI device fails to be started.                                            CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET  A warm reset fails to be performed.                                          CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE  The SCI card fails to be deactivated.                                     CNcomment:去激活失败
\retval ::HI_ERR_SCI_FAILED_GETATR  The ATR data fails to be obtained.                                          CNcomment:获取ATR数据失败
\retval ::HI_ERR_SCI_FAILED_CARDSTATUS The card status fails to be obtained.                                    CNcomment:获取卡状态失败
\retval ::HI_ERR_SCI_FAILED_SEND  The transmission operation fails.                                             CNcomment:发送操作失败
\retval ::HI_ERR_SCI_FAILED_RECEIVE  The reception operation fails.                                             CNcomment:接收操作失败
\retval ::HI_ERR_SCI_FAILED_TIMEOUT_VAL The block timeout fails to be set.                                      CNcomment:配置阻塞超时失败
\retval ::HI_ERR_SCI_FAILED_GET_DATA_LEN The length of the data that is not transmitted fails to be obtained.   CNcomment:获取未发送长度失败
\retval ::HI_ERR_SCI_FAILED_CONFIGVCCEN  The VCCEN signal fails to be set.                                      CNcomment: 配置VCCEN信号失败
\retval ::HI_ERR_SCI_FAILED_CONFIGDETECT  The DETECT signal fails to be set.                                    CNcomment:配置DETECT信号失败
\retval ::HI_ERR_SCI_FAILED_BLK_CARDSTATUS   The card status fails to be obtained in block mode.                CNcomment:阻塞方式获取卡状态失败
\retval ::HI_ERR_SCI_INVALID_PORT The port ID is incorrect.                                                     CNcomment:错误的端口号
\retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                              CNcomment:无ATR数据
\retval ::HI_ERR_SCI_CARD_STATUS  The card status is incorrect.                                                 CNcomment:卡状态错误
\retval ::HI_ERR_SCI_RECEIVE_TIMEOUT  The data reception times out.                                             CNcomment:接收操作超时
\retval ::HI_ERR_SCI_FAILED_BLK_TIMEOUT Obtaining the card status times out.                                    CNcomment:获取卡状态超时
\retval ::HI_ERR_SCI_FAILED_CONFIGSCIMODE The operating mode of the CLK signal fails to be set.                 CNcomment:配置CLK信号线工作模式失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_Receive(HI_UNF_SCI_PORT_E enSciPort, HI_U8 *pSciReceiveBuf, HI_U32 u32ReceiveLen, HI_U32 *pu32ActLen, HI_U32 u32TimeOutMs);


/** 
\brief Sets the active level of the VCCEN signal.
CNcomment:\brief 配置VCCEN信号线的有效电平。
\attention \n
The active level needs to be set based on the circuits of hardware, and the low level is active by default.\n
After changing the active level, you need to call HI_UNF_SCI_ResetCard for the modification take effect.
CNcomment:需要根据硬件电路进行配置，默认为低电平有效\n
CNcomment: 更改此项配置后需要调用HI_UNF_SCI_ResetCard才能使新的配置有效。
         
\param[in] enSciPort ID of an SCI port. The port ID can be 0 or 1.                                              CNcomment:SCI端口号，取值范围为0和1。
\param[in] enSciVcc  Active level of a signal. HI_FALSE: active low; HI_TRUE: active high  Active level of a signal. HI_FALSE: active low; HI_TRUE: active high  CNcomment:信号线的有效电平。HI_FALSE：低电平有效，HI_TRUE：高电平有效。
\retval 0   Success                                                                                             CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                                                       CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT   The SCI device has been started.                                             CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT  The pointer is invalid.                                                     CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.                                           CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET  A warm reset fails to be performed.                                          CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE  The SCI card fails to be deactivated.                                     CNcomment:去激活失败
\retval ::HI_ERR_SCI_FAILED_GETATR  The ATR data fails to be obtained.                                          CNcomment:获取ATR数据失败
\retval ::HI_ERR_SCI_FAILED_CARDSTATUS The card status fails to be obtained.                                    CNcomment:获取卡状态失败
\retval ::HI_ERR_SCI_FAILED_SEND The transmission operation fails.                                              CNcomment:发送操作失败
\retval ::HI_ERR_SCI_FAILED_RECEIVE  The reception operation fails.                                             CNcomment:接收操作失败
\retval ::HI_ERR_SCI_FAILED_TIMEOUT_VAL The block timeout fails to be set.                                      CNcomment:配置阻塞超时失败
\retval ::HI_ERR_SCI_FAILED_GET_DATA_LEN he length of the data that is not transmitted fails to be obtained.    CNcomment:获取未发送长度失败
\retval ::HI_ERR_SCI_FAILED_CONFIGVCCEN The VCCEN signal fails to be set.                                       CNcomment:配置VCCEN信号失败
\retval ::HI_ERR_SCI_FAILED_CONFIGDETECT The DETECT signal fails to be set.                                     CNcomment:配置DETECT信号失败
\retval ::HI_ERR_SCI_FAILED_BLK_CARDSTATUS  The card status fails to be obtained in block mode.                 CNcomment:阻塞方式获取卡状态失败
\retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                              CNcomment:无ATR数据
\retval ::HI_ERR_SCI_CARD_STATUS  The card status is incorrect.                                                 CNcomment:卡状态错误
\retval ::HI_ERR_SCI_RECEIVE_TIMEOUT  The data reception times out.                                             CNcomment:接收操作超时
\retval ::HI_ERR_SCI_INVALID_TIMEOUT_VAL  The timeout is invalid.                                               CNcomment:非法超时时间值
\retval ::HI_ERR_SCI_INVALID_LEVEL_VAL The level is invalid.                                                    CNcomment: 非法的电平
\retval ::HI_ERR_SCI_FAILED_BLK_TIMEOUT Obtaining the card status times out.                                    CNcomment:获取卡状态超时
\retval ::HI_ERR_SCI_FAILED_CONFIGSCIMODE  The operating mode of the CLK signal fails to be set.                CNcomment:配置CLK信号线工作模式失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_ConfigVccEn(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_LEVEL_E enSciVcc);


/** 
\brief Sets the active level of the DETECT signal.
CNcomment:\brief 配置DETECT信号线的有效电平。

\attention \n
The active level needs to be set based on the circuits of hardware, and the high level is active by default.\n
After changing the active level, you need to call HI_UNF_SCI_ResetCard for the modification take effect.
CNcomment:需要根据硬件电路进行设置，默认为高电平有效\n
CNcomment: 更改此项配置后需要调用HI_UNF_SCI_ResetCard才能使新的配置有效。
        
\param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI端口号，取值范围为0和1。
\param[in] enSciDetect Active level of a signal. HI_FALSE: active low; HI_TRUE: active high                     CNcomment:信号线的有效电平。HI_FALSE：低电平有效，HI_TRUE：高电平有效。
\retval 0  Success                                                                                              CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT  The SCI device has been started.                                              CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT The pointer is invalid.                                                      CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.                                           CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET   A warm reset fails to be performed.                                         CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE  The SCI card fails to be deactivated.                                     CNcomment:去激活失败
\retval ::HI_ERR_SCI_FAILED_GETATR  The ATR data fails to be obtained.                                          CNcomment:获取ATR数据失败
\retval ::HI_ERR_SCI_FAILED_CARDSTATUS The card status fails to be obtained.                                    CNcomment:获取卡状态失败
\retval ::HI_ERR_SCI_FAILED_SEND  The transmission operation fails.                                             CNcomment:发送操作失败
\retval ::HI_ERR_SCI_FAILED_RECEIVE  The reception operation fails.                                             CNcomment:接收操作失败
\retval ::HI_ERR_SCI_FAILED_TIMEOUT_VAL  The block timeout fails to be set.                                     CNcomment: 配置阻塞超时失败
\retval ::HI_ERR_SCI_FAILED_GET_DATA_LEN  The length of the data that is not transmitted fails to be obtained.  CNcomment:获取未发送长度失败
\retval ::HI_ERR_SCI_FAILED_CONFIGVCCEN  The VCCEN signal fails to be set.                                      CNcomment:配置VCCEN信号失败
\retval ::HI_ERR_SCI_FAILED_CONFIGDETECT  The DETECT signal fails to be set.                                    CNcomment: 配置DETECT信号失败
\retval ::HI_ERR_SCI_FAILED_BLK_CARDSTATUS The card status fails to be obtained in block mode.                  CNcomment:阻塞方式获取卡状态失败
\retval ::HI_ERR_SCI_INVALID_PORT  The port ID is incorrect.                                                    CNcomment:错误的端口号
\retval ::HI_ERR_SCI_INVALID_PROTOCOL  The protocol type is incorrect.                                          CNcomment:错误的协议类型
\retval ::HI_ERR_SCI_INVALID_FREQUENCY  The clock frequency is invalid.                                         CNcomment:非法的时钟频率
\retval ::HI_ERR_SCI_INVALID_LENTH  The length is invalid.                                                      CNcomment:非法长度
\retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                              CNcomment:无ATR数据
\retval ::HI_ERR_SCI_CARD_STATUS  The card status is incorrect.                                                 CNcomment:卡状态错误
\retval ::HI_ERR_SCI_RECEIVE_TIMEOUT   The data reception times out.                                            CNcomment:接收操作超时
\retval ::HI_ERR_SCI_INVALID_TIMEOUT_VAL  The timeout is invalid.                                               CNcomment:非法超时时间值
\retval ::HI_ERR_SCI_INVALID_LEVEL_VAL  The level is invalid.                                                   CNcomment:非法的电平
\retval ::HI_ERR_SCI_FAILED_BLK_TIMEOUT  Obtaining the card status times out.                                   CNcomment:获取卡状态超时
\retval ::HI_ERR_SCI_FAILED_CONFIGSCIMODE  The operating mode of the CLK signal fails to be set.                CNcomment:配置CLK信号线工作模式失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_ConfigDetect(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_LEVEL_E enSciDetect);


/** 
\brief Sets the mode of a clock signal.
CNcomment:\brief 设置时钟线的模式。
\attention \n
The mode needs to be set based on the circuits of hardware, and the OD mode is selected by default.\n
After changing the mode, you need to call HI_UNF_SCI_ResetCard for the modification take effect.
CNcomment:需要根据硬件电路进行设置，默认为OD模式\n
CNcomment: 更改此项配置后需要调用HI_UNF_SCI_ResetCard才能使新的配置有效。

\param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI端口号，取值范围为0和1。
\param[in] enClkMode  Mode of a clock signal                                                                    CNcomment:时钟线的模式。
\retval 0 Success                                                                                               CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT  The SCI device has been started.                                              CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT  The pointer is invalid.                                                     CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.                                           CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET  A warm reset fails to be performed.                                          CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE  The SCI card fails to be deactivated.                                     CNcomment:去激活失败
\retval ::HI_ERR_SCI_FAILED_GETATR  The ATR data fails to be obtained.                                          CNcomment:获取ATR数据失败
\retval ::HI_ERR_SCI_FAILED_CARDSTATUS  The card status fails to be obtained.                                   CNcomment:获取卡状态失败
\retval ::HI_ERR_SCI_FAILED_SEND  The transmission operation fails.                                             CNcomment:发送操作失败
\retval ::HI_ERR_SCI_FAILED_RECEIVE   The reception operation fails.                                            CNcomment:接收操作失败
\retval ::HI_ERR_SCI_FAILED_TIMEOUT_VAL The block timeout fails to be set.                                      CNcomment:配置阻塞超时失败
\retval ::HI_ERR_SCI_FAILED_GET_DATA_LEN  The length of the data that is not transmitted fails to be obtained.  CNcomment:获取未发送长度失败
\retval ::HI_ERR_SCI_FAILED_CONFIGVCCEN  The VCCEN signal fails to be set.                                      CNcomment: 配置VCCEN信号失败
\retval ::HI_ERR_SCI_FAILED_CONFIGDETECT The DETECT signal fails to be set.                                     CNcomment:配置DETECT信号失败
\retval ::HI_ERR_SCI_FAILED_BLK_CARDSTATUS  The card status fails to be obtained in block mode.                 CNcomment:阻塞方式获取卡状态失败
\retval ::HI_ERR_SCI_INVALID_PORT  The port ID is incorrect.                                                    CNcomment:错误的端口号
\retval ::HI_ERR_SCI_INVALID_PROTOCOL The protocol type is incorrect.                                           CNcomment:错误的协议类型
\retval ::HI_ERR_SCI_INVALID_FREQUENCY   The clock frequency is invalid.                                        CNcomment:非法的时钟频率
\retval ::HI_ERR_SCI_INVALID_LENTH  The length is invalid.                                                      CNcomment:非法长度
\retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                              CNcomment:无ATR数据
\retval ::HI_ERR_SCI_CARD_STATUS  The card status is incorrect.                                                 CNcomment:卡状态错误
\retval ::HI_ERR_SCI_RECEIVE_TIMEOUT  The data reception times out.                                             CNcomment:接收操作超时
\retval ::HI_ERR_SCI_INVALID_TIMEOUT_VAL  The timeout is invalid.                                               CNcomment:非法超时时间值
\retval ::HI_ERR_SCI_INVALID_LEVEL_VAL  The level is invalid.                                                   CNcomment:非法的电平
\retval ::HI_ERR_SCI_FAILED_BLK_TIMEOUT   Obtaining the card status times out.                                  CNcomment:获取卡状态超时
\retval ::HI_ERR_SCI_FAILED_CONFIGSCIMODE The operating mode of the CLK signal fails to be set.                 CNcomment:配置CLK信号线工作模式失败
\see \n
N/A
*/
HI_S32 HI_UNF_SCI_ConfigClkMode(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_CLK_MODE_E enClkMode);


/** 
\brief Changes the card slot.
CNcomment:\brief 切换卡槽。

\attention \n
When you call HI_UNF_SCI_Open, the primary card is used by default, that is, port 0 is used.\n
After you switch to a new SCI device, all the preceding SCI APIs are called to operate the new SCI device.\n
In addition, after a new SCI device is switched, the device is initialized based on the default configuration.\n
If any modifications are made, you need to call HI_UNF_SCI_ResetCard for the modifications to take effect.\n
If the SCI port to be switched to is the same as the current active port, an error code is returned.
CNcomment:调用HI_UNF_SCI_Open时，默认打开的为主卡，即端口0\n
CNcomment: 切换到新的SCI设备后，上述所有SCI接口即对新的SCI设备进行操作\n
CNcomment: 切换到新的SCI设备采用默认配置对设备进行初始化\n
CNcomment: 之后如果更改了配置，需要调用HI_UNF_SCI_ResetCard来使配置生效\n
CNcomment: 希望切换到的SCI端口与当前有效端口相同时，会返回失败。

\param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI端口号，取值范围为0和1。
\param[in] enSciProtocol  Protocol type                                                                         CNcomment:协议类型。
\param[in] u32Frequency Frequency of the SCI card to be set, in kHz. For the T0 and T1 cards, the frequency ranges from 1 MHz to 5 MHz; for the T14 card, the frequency must be set to 6 MHz. CNcomment:要设置的SCI卡频率。对于T0，T1卡，支持频率1MHz~5MHz；对于T14卡，只支持6MHz。单位为kHz。
\retval 0  Success                                                                                              CNcomment:成功
\retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI设备未打开
\retval ::HI_ERR_SCI_REPEAT_INIT  The SCI device has been started.                                              CNcomment:SCI设备重复打开
\retval ::HI_ERR_SCI_INVALID_POINT The pointer is invalid.                                                      CNcomment:非法指针
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:非法参数
\retval ::HI_ERR_SCI_FAILED_INIT  The SCI device fails to be started.                                           CNcomment:打开SCI设备失败
\retval ::HI_ERR_SCI_FAILED_RESET A warm reset fails to be performed.                                           CNcomment:热复位失败
\retval ::HI_ERR_SCI_FAILED_DEACTIVE  The SCI card fails to be deactivated.                                     CNcomment:去激活失败
\retval ::HI_ERR_SCI_FAILED_GETATR  The ATR data fails to be obtained.                                          CNcomment:获取ATR数据失败
\retval ::HI_ERR_SCI_FAILED_CARDSTATUS  The card status fails to be obtained.                                   CNcomment:获取卡状态失败
\retval ::HI_ERR_SCI_FAILED_SEND  The transmission operation fails.                                             CNcomment:发送操作失败
\retval ::HI_ERR_SCI_FAILED_RECEIVE  The reception operation fails.                                             CNcomment:接收操作失败
\retval ::HI_ERR_SCI_FAILED_TIMEOUT_VAL  The block timeout fails to be set.                                     CNcomment:配置阻塞超时失败
\retval ::HI_ERR_SCI_FAILED_GET_DATA_LEN  The length of the data that is not transmitted fails to be obtained.  CNcomment:获取未发送长度失败
\retval ::HI_ERR_SCI_FAILED_CONFIGVCCEN  The VCCEN signal fails to be set.                                      CNcomment:配置VCCEN信号失败
\retval ::HI_ERR_SCI_FAILED_CONFIGDETECT The DETECT signal fails to be set.                                     CNcomment:配置DETECT信号失败
\retval ::HI_ERR_SCI_FAILED_BLK_CARDSTATUS The card status fails to be obtained in block mode.                  CNcomment:阻塞方式获取卡状态失败
\retval ::HI_ERR_SCI_INVALID_PORT The port ID is incorrect.                                                     CNcomment:错误的端口号
\retval ::HI_ERR_SCI_INVALID_PROTOCOL  The protocol type is incorrect.                                          CNcomment:错误的协议类型
\retval ::HI_ERR_SCI_INVALID_FREQUENCY   The clock frequency is invalid.                                        CNcomment:非法的时钟频率
\retval ::HI_ERR_SCI_INVALID_LENTH  The length is invalid.                                                      CNcomment:非法长度
\retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                              CNcomment:无ATR数据
\retval ::HI_ERR_SCI_CARD_STATUS  The card status is incorrect.                                                 CNcomment:卡状态错误
\retval ::HI_ERR_SCI_RECEIVE_TIMEOUT  The data reception times out.                                             CNcomment:接收操作超时
\retval ::HI_ERR_SCI_INVALID_TIMEOUT_VAL  The timeout is invalid.                                               CNcomment:非法超时时间值
\retval ::HI_ERR_SCI_INVALID_LEVEL_VAL The level is invalid.                                                    CNcomment:非法的电平
\retval ::HI_ERR_SCI_FAILED_BLK_TIMEOUT  Obtaining the card status times out.                                   CNcomment:获取卡状态超时
\retval ::HI_ERR_SCI_FAILED_CONFIGSCIMODE  The operating mode of the CLK signal fails to be set.                CNcomment:配置CLK信号线工作模式失败

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_SwitchCard(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_PROTOCOL_E enSciProtocol, HI_U32 u32Frequency);

/** 
\brief Sets the clock rate factor (in ETU) and baud rate regulator factor for special cards.
CNcomment:\brief 对特殊卡需要设置指定etu 时钟率因子，波特率调节因子

\attention \n
This API needs to be called only for special cards.
The configured values must match the clock rate conversion factor F and bit rate regulator factor D defined in the protocol.
You can also set the factors to the values defined in the card specifications. Note that the values must be set correctly.
CNcomment:只有特需要求的卡需要设置，普通卡不需要调用此接口设置，
CNcomment: 设置的值要与协议中规定的F时钟转率转换因子、D比特率调节因子兼容，
CNcomment: 或者设置为卡规范中规定的值，不可随意设置

\param [in] 	enSciPort	ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI端口号，取值范围为0和1 
\param [in] 	u32ClkFactor  Clock rate conversion factor, ranging from 372 to 2048. For details, see the factor F and card features in the protocol.	CNcomment:时钟转率因子372～2048 ，具体设置参考协议的F因子和卡特性
\param [in] 	u32BaudFactor	Baud rate regulator factor 1, 2 x n (n = 1-16). For details, see the factor D and card features in the protocol. CNcomment:波特率校正因子1、2*n (n=1～16) ，具体设置参考协议D因子和卡特性    
\retval  0 	Success                                                                                               CNcomment:成功 
\retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                          CNcomment:SCI设备未打开 
\retval ::HI_ERR_SCI_INVALID_PARA The parameter is invalid.                                                       CNcomment:非法参数 

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_SetEtuFactor(HI_UNF_SCI_PORT_E enSciPort,HI_U32 u32ClkFactor,HI_U32 u32BaudFactor);

/** 
\brief \brief Sets the extra guard time for transmitting two consecutive bytes from the terminal to an IC card. The guard time is the interval between the start edges of two consecutive bytes.
CNcomment:\brief 设置终端向IC卡发送连续的两个字节起始沿额外增加的间隔时间
\attention \n
This setting is performed based on related features only for the cards that require extra character guard time.
In general, the default value is used or the interval guard time is automatically set based on the ART analysis result.
CNcomment:只有特需要求的卡，需要额外设置字符保护时间的才能根据卡的相关特性设置，
CNcomment: 不可随意设置。一般使用系统默认值，或者系统根据ATR解析自动设置。
\param [in] 	enSciPort	ID of an SCI port. The port ID can be 0 or 1.      CNcomment:SCI端口号，取值范围为0和1 
\param [in] 	u32GuardTime  Extra guard time, ranging from 0 to 254 ETU	   CNcomment:额外间隔保护的范围0～254  etu
\retval 0  Success	                                                       CNcomment:成功 
\retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                  CNcomment:SCI设备未打开 
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.               CNcomment:非法参数 

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_SetGuardTime(HI_UNF_SCI_PORT_E enSciPort,HI_U32 u32GuardTime);


/** 
\brief Sets the baud rate supported by the SCI card through protocol and parameters selection (PPS) negotiation or performs negotiation by using the F and D factors returned by the ATR to switch the protocol of a card.
CNcomment:\brief 通过PPS 协商可以设置卡所支持的波特率或者用ATR 传回的F、D因子进行协商，支持多协议卡的协议切换

\attention \n
PPS negotiation is available only when the SCI card supports this function.
The negotiated baud rate must be supported by the SCI card.
The command words for negotiation must comply with the specifications defined in section 9.2 "PPS request and response" in the 7816-3 protocol.
CNcomment:要进行PPS 协商首先卡必须支持该功能，
CNcomment: 要协商的波特率内容必须是卡所规定的支持的波特率范围，
CNcomment: 请求协商的命令字需符合7816-3 中9.2 PPS request and response 。

\param [in] 	enSciPort	ID of an SCI port. The port ID is 0 or 1.                                 CNcomment:SCI端口号，取值范围为0和1 
\param [in] 	pSciSendBuf  PPS negotiation command combined based on card specifications. If the default negotiation mode is used, the command word can be left empty.   CNcomment:根据卡规范组合的PPS协商命令，若使用系统默认的协商方式，命令字的内容可为空
\param [in]	Sendlen	   Length of the command word to be transmitted, ranging from 0 bytes to 5 bytes. The value 0 indicates that the default negotiation mode is used.   CNcomment: 发送命令字的长度(0～5),设置为0表示使用系统默认的协商命令方式。
\param [in]	RecTimeouts  PPS response timeout after commands are transmitted. The value ranges from 1 ms to 10000 ms.  CNcomment: 发送完命令之后，接收PPS 响应的超时时间(1-10000),单位是毫秒
\retval 0 	Success                                                                               CNcomment:成功 
\retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                                         CNcomment:SCI设备未打开 
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                      CNcomment:非法参数
\retval ::HI_ERR_SCI_NULL_PTR		The pointer is null.                                              CNcomment:空指针
\retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                                          CNcomment:不可用的选项
\retval ::HI_ERR_SCI_RECEIVE_ERR  A reception error occurs.                                       CNcomment:接收错误
\retval ::HI_ERR_SCI_PPS_PTYPE_ERR 	The protocol type for PPS negotiation is incorrect.           CNcomment:PPS协商的协议类型错误
\retval ::HI_ERR_SCI_PPS_FACTOR_ERR 	The F factor and D factor for PPS negotiation are incorrect. CNcomment:PPS协商的F、D因子错误
\retval ::HI_ERR_SCI_PPS_NOTSUPPORT_ERR  The PPS negotiation type is not supported.               CNcomment:不支持的PPS协商类型

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_NegotiatePPS(HI_UNF_SCI_PORT_E enSciPort, HI_U8 *pSciSendBuf,HI_U32 Sendlen, HI_U32 RecTimeouts);


/** 
\brief  Obtains the PPS data for the card response after PPS negotiation is successful.
CNcomment:\brief  PPS 协商成功之后,通过该接口可获得卡响应的PPS 数据
\attention \n
This API takes effect only after PPS negotiation is successful.
CNcomment:要等PPS 协商成功之后,使用该接口才有实际意义

\param [in] 	enSciPort	ID of an SCI port. The port ID is 0 or 1.                   CNcomment:SCI端口号，取值范围为0和1 
\param [out] 	pRecBuf   Address of the buffer for storing the data to be received   CNcomment:待接收的数据buffer 地址
\param [out]	pDataLen	  Required length of the received data                      CNcomment:期望接收数据的长度 
\retval 0  Success	                                                                CNcomment:成功 
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                        CNcomment:非法参数
\retval ::HI_ERR_SCI_NULL_PTR	The pointer is null.                                	CNcomment:空指针
\retval ::HI_ERR_SCI_PPS_NOTSUPPORT_ERR  The PPS negotiation type is not supported. CNcomment:不支持的PPS协商类型

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_GetPPSResponData(HI_UNF_SCI_PORT_E enSciPort, HI_U8* pRecBuf, HI_U32* pDataLen);


/** 
brief  Obtains the SCI parameter values including the protocol, ATR clock factor, ATR bit rate factor, actual clock factor, actual bit rate factor, number of retries, guard delay, character wait timeout, and block wait timeout.
CNcomment:\brief  获取sci 参数包括协议、ATR 时钟和比特率因子、实际设置的时钟因子和比特率因子，
CNcomment: 发送重试次数、GuardDelay 、字符等待超时、块等待超时。
\attention \n
This API is available only after HI_UNF_SCI_Init and HI_UNF_SCI_ResetCard are called..
CNcomment:要等 到初始化复位之后,才能使用该接口

\param [in] 	enSciPort	 ID of an SCI port. The port ID is 0 or 1.                      CNcomment:SCI端口号，取值范围为0和1 
\param [out] 	pParams   Pointer to the data type of the data structure to be received   CNcomment:待接收的结构体数据类型指针
\retval 0 	Success                                                                     CNcomment:成功 
\retval ::HI_ERR_SCI_INVALID_PARA The parameter is invalid.                             CNcomment:非法参数
\retval ::HI_ERR_SCI_NULL_PTR		The pointer is null.                                    CNcomment:空指针
\retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                                CNcomment:不可用的选项
\retval ::HI_ERR_SCI_NOT_INIT  	The SCI device is not initialized.                      CNcomment:没完成初始化

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_GetParams(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_PARAMS_S_PTR pParams);


/** 
\brief  Sets the character timeout of T0 and T1 separately based on the current protocol type.
CNcomment:\brief  根据当前协议类型分别可设置T0、T1的字符超时时间

\attention \n
The timeout can be set only after the SCI card is reset successfully. The protocol type must be consistent with the current card type. In general, the timeout is obtained by parsing the ATR. That is, the timeout needs to be set only when card communication fails.
CNcomment:要等卡复位成功之后,才能进行设置，协议类型参数必须与当前卡类型一致，一般情况都是根据ATR解析，只有特殊卡情况才需要设置。

\param [in] 	enSciPort	ID of an SCI port. The port ID is 0 or 1.    CNcomment:SCI端口号，取值范围为0和1 
\param [in] 	enSciProtocol  Protocol type                           CNcomment:协议类型
\param [in]	MaxCharTime  Maximum character timeout. The value of MaxCharTime for T0 ranges from 960 to 244800, and the value of MaxCharTime for T1 ranges from 12 to 32779.	  CNcomment:设置最大的字符超时时间，设置范围T0(960～244800),T1(12～32779)
\retval 0 	Success                                                  CNcomment:成功 
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.         CNcomment:非法参数
\retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.             CNcomment:不可用的选项
\retval ::HI_ERR_SCI_NO_ATR  	The SCI card fails to be reset.        CNcomment:没复位成功

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_SetCharTimeout(HI_UNF_SCI_PORT_E enSciPort,  HI_UNF_SCI_PROTOCOL_E  enSciProtocol, HI_U32 MaxCharTime);


/** 
\brief  Sets the block timeout of T1.
CNcomment:\brief  设置T1的块超时时间

\attention \n
The timeout can be set only after the SCI card is reset successfully. In general, the timeout is obtained by parsing the ATR. That is, the timeout needs to be set only in special cases
CNcomment:要等卡复位成功之后,才能进行设置，一般情况都是根据ATR解析，只有特殊卡情况才需要设置。

\param [in] 	enSciPort	 ID of an SCI port. The port ID is 0 or 1.                         CNcomment:SCI端口号，取值范围为0和1 
\param [in] 	MaxBlockTime   Maximum block timeout. The value ranges from 971 to 491531.   CNcomment:设置块超时的最大值，范围(971～491531)
\retval 0 	Success                                                                        CNcomment:成功 
\retval ::HI_ERR_SCI_INVALID_PARA The parameter is invalid.                                CNcomment:非法参数
\retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                                   CNcomment:不可用的选项
\retval ::HI_ERR_SCI_NO_ATR  		The SCI card fails to be reset.                            CNcomment:没复位成功

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_SetBlockTimeout(HI_UNF_SCI_PORT_E enSciPort,HI_U32 MaxBlockTime);


/** 
\brief  Sets the maximum number of transmission retries after a check error occurs.
CNcomment:\brief  设置校验错误后重发送最大次数

\attention \n
The number can be set only after the SCI card is reset successfully.
CNcomment:要等卡复位成功之后,才能进行设置

\param [in] 	enSciPort	ID of an SCI port. The port ID is 0 or 1.                    CNcomment:SCI端口号，取值范围为0和1 
\param [in] 	TxRetryTimes   Number of transmission retries, ranging from 0 to 7.    CNcomment:次数范围(0～7)
\retval 0 	Success                                                                  CNcomment:成功 
\retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                         CNcomment:非法参数
\retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             CNcomment:不可用的选项
\retval ::HI_ERR_SCI_NO_ATR  	The SCI card fails to be reset.	                       CNcomment:没复位成功

\see \n
N/A
*/
HI_S32 HI_UNF_SCI_SetTxRetries(HI_UNF_SCI_PORT_E enSciPort,HI_U32 TxRetryTimes);

/** @} */  /** <!-- ==== API Declaration End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_2 */
/** @{ */  /** <!-- [E2PROM] */
/*---- e2prom ----*/
/** 
\brief Starts the E2PROM device.
CNcomment:\brief 打开E2PROM（Electrically-Erasable Programmable Read-Only Memory）设备。

\attention \n
This API cannot be called repeatedly.
CNcomment:重复打开会失败。

\param  N/A                                                                   CNcomment:无
\retval 0 Success                                                             CNcomment:成功
\retval ::HI_ERR_E2PROM_NOT_INIT  The E2PROM device is not initialized.       CNcomment:E2PROM设备未初始化
\retval ::HI_ERR_E2PROM_REPEAT_INIT The E2PROM device has been initialized.   CNcomment:E2PROM设备重复初始化
\retval ::HI_ERR_E2PROM_INVALID_POINT The E2PROM pointer is invalid.          CNcomment:E2PROM无效指针
\retval ::HI_ERR_E2PROM_INVALID_PARA   The E2PROM parameter is invalid.       CNcomment:E2PROM无效参数
\retval ::HI_ERR_E2PROM_FAILED_INIT  The E2PROM device fails to be initialized.CNcomment: E2PROM设备初始化失败
\retval ::HI_ERR_E2PROM_FAILED_READ  The E2PROM data fails to be read.        CNcomment:E2PROM数据读取失败
\see \n
N/A
*/
HI_S32 HI_UNF_E2PROM_Open(HI_VOID);


/** 
\brief Stops the E2PROM device.
CNcomment:\brief 关闭E2PROM设备。

\attention \n
This API cannot be called repeatedly.
CNcomment:重复关闭会失败。

\param N/A                                                                       CNcomment:无
\retval 0 Success                                                                CNcomment:成功
\retval ::HI_ERR_E2PROM_NOT_INIT  The E2PROM device is not initialized.          CNcomment:E2PROM设备未初始化
\retval ::HI_ERR_E2PROM_REPEAT_INIT The E2PROM device has been initialized .     CNcomment:E2PROM设备重复初始化
\retval ::HI_ERR_E2PROM_INVALID_POINT  The E2PROM pointer is invalid.            CNcomment:E2PROM无效指针
\retval ::HI_ERR_E2PROM_INVALID_PARA  The E2PROM parameter is invalid.           CNcomment:E2PROM无效参数
\retval ::HI_ERR_E2PROM_FAILED_INIT  The E2PROM device fails to be initialized.  CNcomment:E2PROM设备初始化失败
\retval ::HI_ERR_E2PROM_FAILED_READ The E2PROM data fails to be read.            CNcomment:E2PROM数据读取失败
\see \n
N/A
*/
HI_S32 HI_UNF_E2PROM_Close(HI_VOID);


/** 
\brief Reads data from the E2PROM device.
CNcomment:\brief 从E2PROM设备读数据。
\attention \n
Ensure that the I2C module is available before calling this API.
If the length of the input address u32Addr is greater than the total address length of the chip, no read operation is performed on the E2PROM device.\n
If the input pointer pu8Buf is null, no read operation is performed on the E2PROM device.\n
If the input address u32Addr is valid, but the sum of u32Addr and u32Length is greater than the total address length of the chip, no write operation is performed on the E2PROM device.
CNcomment:调用此接口前应确保I2C模块可用\n
CNcomment: 若传入的地址u32Addr大于芯片地址总长度，则不会对E2PROM进行读操作\n
CNcomment: 若传入的指针pu8Buf为空，则不会对E2PROM进行读操作\n
CNcomment: 若传入地址u32Addr合法，但u32Addr与u32Length的和大于芯片地址总长度，则不会对E2PROM进行读操作。

\param[in] u32Addr  On-chip offset address                                      CNcomment:片内偏移地址。
\param[out]  pu8Buf  Buffer for storing the data to be read                     CNcomment:存放待读取的数据。
\param[in] u32Length  Length of the data to be read                             CNcomment:读取数据的长度。
\retval 0  Success                                                              CNcomment:成功
\retval ::HI_ERR_E2PROM_NOT_INIT  The E2PROM device is not initialized.         CNcomment: E2PROM设备未初始化
\retval ::HI_ERR_E2PROM_REPEAT_INIT  The E2PROM device has been initialized.    CNcomment:E2PROM设备重复初始化
\retval ::HI_ERR_E2PROM_INVALID_POINT The E2PROM pointer is invalid.            CNcomment:E2PROM无效指针
\retval ::HI_ERR_E2PROM_INVALID_PARA  The E2PROM parameter is invalid.          CNcomment:E2PROM无效参数
\retval ::HI_ERR_E2PROM_FAILED_INIT  The E2PROM device fails to be initialized. CNcomment:E2PROM设备初始化失败
\see \n
N/A
*/
HI_S32 HI_UNF_E2PROM_Read (HI_U32 u32Addr, HI_U8 * pu8Buf, HI_U32 u32Length);


/** 
\brief Writes data to the E2PROM device.
CNcomment:\brief 向E2PROM设备写数据。

\attention \n
Ensure that the I2C module is available before calling this API.
If the length of the input address u32Addr is greater than the total address length of the chip, no write operation is performed on the E2PROM device.\n
If the input pointer pu8Buf is null, no write operation is performed on the E2PROM device.\n
If the input address u32Addr is valid, but the sum of u32Addr and u32Length is greater than the total address length of the chip, no write operation is performed on the E2PROM device.
CNcomment:调用此接口前应确保I2C模块可用\n
CNcomment: 若传入的地址u32Addr大于芯片地址总长度，则不会对E2PROM进行写操作\n
CNcomment: 若传入的指针pu8Buf为空，则不会对E2PROM进行写操作\n
CNcomment: 若传入地址u32Addr合法，但u32Addr与u32Length的和大于芯片地址总长度，则不会对E2PROM进行写操作。

\param[in] u32Addr  On-chip offset address                                      CNcomment:片内偏移地址。
\param[in]  pu8Buf  Buffer for storing the data to be written                   CNcomment:存放待写入的数据。
\param[in] u32Length  Length of the data to be written                          CNcomment:要写入的数据长度。
\retval 0  Success                                                              CNcomment:成功
\retval ::HI_ERR_E2PROM_NOT_INIT  The E2PROM device is not initialized.         CNcomment:E2PROM设备未初始化
\retval ::HI_ERR_E2PROM_REPEAT_INIT  The E2PROM device has been initialized.    CNcomment:E2PROM设备重复初始化
\retval ::HI_ERR_E2PROM_INVALID_POINT  The E2PROM pointer is invalid.           CNcomment:E2PROM无效指针
\retval ::HI_ERR_E2PROM_INVALID_PARA   The E2PROM parameter is invalid.         CNcomment:E2PROM无效参数
\retval ::HI_ERR_E2PROM_FAILED_INIT  The E2PROM device fails to be initialized. CNcomment:E2PROM设备初始化失败
\retval ::HI_ERR_E2PROM_FAILED_READ  The E2PROM data fails to be read.          CNcomment:E2PROM数据读取失败
\see \n
N/A
*/
HI_S32 HI_UNF_E2PROM_Write (HI_U32 u32Addr, HI_U8 * pu8Buf, HI_U32 u32Length);


/** 
\brief Sets the type of the E2PROM chip.
CNcomment:\brief 设置E2PROM芯片类型。

\attention \n
Ensure that the I2C module is available before calling this API.
Before calling HI_UNF_E2PROM_Read and HI_UNF_E2PROM_Write, you must call this API.
At present, only the M24LC16 chip is tested.
CNcomment:调用此接口前应确保I2C模块可用\n
CNcomment: 此接口必须在调用HI_UNF_E2PROM_Read和HI_UNF_E2PROM_Write之前调用\n
CNcomment: 目前仅实测了M24LC16芯片，其它类型的芯片未进行测试。
\param[in] enChip  Type of the E2PROM chip                                  CNcomment: E2PROM芯片类型。
                   HI_UNF_E2PROM_CHIP_AT24C01： The chip type is AT24C01.   CNcomment:芯片类型为AT24C01；
                   HI_UNF_E2PROM_CHIP_AT24C02： The chip type is AT24C02.   CNcomment:芯片类型为AT24C02；
                   HI_UNF_E2PROM_CHIP_AT24C04：The chip type is AT24C04.    CNcomment:芯片类型为AT24C04；
                   HI_UNF_E2PROM_CHIP_AT24C08：The chip type is AT24C08.    CNcomment:芯片类型为AT24C08；
                   HI_UNF_E2PROM_CHIP_AT24C16： The chip type is AT24C16.   CNcomment:芯片类型为AT24C16；
                   HI_UNF_E2PROM_CHIP_AT24C32：The chip type is AT24C32.    CNcomment:芯片类型为AT24C32；
                   HI_UNF_E2PROM_CHIP_AT24C64：The chip type is AT24C64.    CNcomment:芯片类型为AT24C64；
                   HI_UNF_E2PROM_CHIP_AT24C128：The chip type is AT24C128.  CNcomment:芯片类型为AT24C128；
                   HI_UNF_E2PROM_CHIP_AT24C256：The chip type is AT24C256.  CNcomment:芯片类型为AT24C256；
                   HI_UNF_E2PROM_CHIP_M24LC01：The chip type is M24LC01.    CNcomment:芯片类型为M24LC01；
                   HI_UNF_E2PROM_CHIP_M24LC02：The chip type is M24LC02.    CNcomment:芯片类型为M24LC02；
                   HI_UNF_E2PROM_CHIP_M24LC04：The chip type is M24LC04.    CNcomment:芯片类型为M24LC04；
                   HI_UNF_E2PROM_CHIP_M24LC08：The chip type is M24LC08.    CNcomment:芯片类型为M24LC08；
                   HI_UNF_E2PROM_CHIP_M24LC16：The chip type is M24LC16.    CNcomment:芯片类型为M24LC16；
                   HI_UNF_E2PROM_CHIP_M24LC32：The chip type is M24LC32.    CNcomment:芯片类型为M24LC32；
                   HI_UNF_E2PROM_CHIP_M24LC64：The chip type is M24LC64.    CNcomment:芯片类型为M24LC64；
                   HI_UNF_E2PROM_CHIP_M24LC128：The chip type is M24LC128.  CNcomment:芯片类型为M24LC128；
                   HI_UNF_E2PROM_CHIP_M24LC256：The chip type is M24LC256.  CNcomment:芯片类型为M24LC256。
\retval 0 Success                                                           CNcomment:成功
\retval ::HI_ERR_E2PROM_NOT_INIT  The E2PROM device is not initialized.     CNcomment:E2PROM设备未初始化
\retval ::HI_ERR_E2PROM_REPEAT_INIT The E2PROM device has been initialized. CNcomment:E2PROM设备重复初始化
\retval ::HI_ERR_E2PROM_INVALID_POINT The E2PROM pointer is invalid.        CNcomment:E2PROM无效指针
\retval ::HI_ERR_E2PROM_INVALID_PARA  The E2PROM parameter is invalid.      CNcomment:E2PROM无效参数
\retval ::HI_ERR_E2PROM_FAILED_INIT  The E2PROM device fails to be initialized.  CNcomment:E2PROM设备初始化失败
\retval ::HI_ERR_E2PROM_FAILED_READ  The E2PROM data fails to be read.      CNcomment:E2PROM数据读取失败
\retval ::HI_ERR_E2PROM_FAILED_WRITE  The E2PROM data fails to be written.  CNcomment:E2PROM数据写入失败
\retval ::HI_ERR_E2PROM_FAILED_SETCHIPTYPE  The E2PROM chip fails to be selected. CNcomment:E2PROM选择芯片失败
\see \n
N/A
*/
HI_S32 HI_UNF_E2PROM_SetChipType(HI_UNF_E2PROM_CHIP_E enChip);


/** 
\brief Sets the I2C bus address of the E2PROM device.
CNcomment:\brief 设置E2PROM的I2C总线地址。

\attention \n
The address is related to the hardware layout. For details, see the corresponding hardware design manuals.
CNcomment:地址跟硬件布局有关，请参考硬件设计。

\param[in] u32E2promAddr  I2C bus address of the E2PROM device                            CNcomment:E2PROM的I2C总线地址。
\retval 0 Success                                                                         CNcomment:成功
\retval ::HI_ERR_E2PROM_NOT_INIT   The E2PROM device is not initialized.                  CNcomment:E2PROM设备未初始化
\retval ::HI_ERR_E2PROM_REPEAT_INIT  The E2PROM device has been initialized.              CNcomment:E2PROM设备重复初始化
\retval ::HI_ERR_E2PROM_INVALID_POINT  The E2PROM pointer is invalid.                     CNcomment:E2PROM无效指针
\retval ::HI_ERR_E2PROM_INVALID_PARA  The E2PROM parameter is invalid.                    CNcomment:E2PROM无效参数
\retval ::HI_ERR_E2PROM_FAILED_INIT  The E2PROM device fails to be initialized.           CNcomment:E2PROM设备初始化失败
\retval ::HI_ERR_E2PROM_FAILED_READ  The E2PROM data fails to be read.                    CNcomment:E2PROM数据读取失败
\retval ::HI_ERR_E2PROM_FAILED_WRITE  The E2PROM data fails to be written.                CNcomment:E2PROM数据写入失败
\retval ::HI_ERR_E2PROM_FAILED_SETADDR  The address of the E2PROM device fails to be set. CNcomment:E2PROM设置地址失败
\see \n
N/A
*/
HI_S32 HI_UNF_E2PROM_SetAddr(HI_U32 u32E2promAddr);


/** 
\brief Sets the ID of the I2C channel used by the E2PROM device.
CNcomment:\brief 设置E2PROM所使用的I2C通道号。

\attention \n
N/A
\param[in] u32I2cNum  ID of the I2C channel used by the E2PROM device, ranging from 0 to HI_I2C_MAX_NUM_USER   CNcomment:E2PROM所用的I2C通道号，范围0～HI_I2C_MAX_NUM_USER
\retval 0  Success                                                                                             CNcomment:成功
\retval ::HI_ERR_E2PROM_NOT_INIT  The E2PROM device is not initialized.                                        CNcomment:E2PROM设备未初始化
\retval ::HI_ERR_E2PROM_REPEAT_INIT  The E2PROM device has been initialized.                                   CNcomment:E2PROM设备重复初始化
\retval ::HI_ERR_E2PROM_INVALID_POINT The E2PROM pointer is invalid.                                           CNcomment:E2PROM无效指针
\retval ::HI_ERR_E2PROM_INVALID_PARA  The E2PROM parameter is invalid.                                         CNcomment:E2PROM无效参数
\retval ::HI_ERR_E2PROM_FAILED_INIT  The E2PROM device fails to be initialized.                                CNcomment:E2PROM设备初始化失败
\retval ::HI_ERR_E2PROM_FAILED_SETI2CNUM  The I2C channel of the E2PROM device fails to be set.                CNcomment:E2PROM设置I2C通道失败
\retval ::HI_ERR_E2PROM_NOT_INIT The E2PROM device is not initialized.                                         CNcomment:E2PROM设备未初始化
\see \n
N/A
*/
HI_S32 HI_UNF_E2PROM_SetI2cNum(HI_U32 u32I2cNum);

/** @} */  /** <!-- ==== API Declaration End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_3 */
/** @{ */  /** <!-- [I2C] */
/*---- i2c ----*/
/** 
\brief Starts the I2C device.
CNcomment:\brief 打开I2C（the Inter-Integrated Circuit）设备。

\attention \n
This API cannot be called repeatedly.
CNcomment:重复调用此接口会失败。

\param N/A                                                               CNcomment:无
\retval 0 Success                                                        CNcomment:成功
\retval ::HI_ERR_I2C_NOT_INIT  I2CThe I2C device is not initialized.     CNcomment:设备未初始化
\retval ::HI_ERR_I2C_REPEAT_INIT  The I2C device has been initialized.   CNcomment:I2C设备重复初始化
\retval ::HI_ERR_I2C_INVALID_POINT  The I2C pointer is invalid.          CNcomment:I2C无效指针
\retval ::HI_ERR_I2C_INVALID_PARA  The I2C parameter is invalid.         CNcomment:I2C无效参数
\see \n
N/A
*/
HI_S32 HI_UNF_I2C_Open (HI_VOID);


/** 
\brief  Closes the I2C device.
CNcomment:\brief 关闭I2C设备。

\attention \n
This API is called after I2C operations are completed.\n
This API cannot be called repeatedly.
CNcomment:在I2C操作结束后调用此接口\n
CNcomment: 重复调用此接口会失败。

\param N/A                                                        CNcomment:无
\retval 0 Success                                                 CNcomment: 成功
\retval ::HI_ERR_I2C_NOT_INIT  The I2C device is not initialized. CNcomment:I2C设备未初始化
\see \n
N/A
*/
HI_S32 HI_UNF_I2C_Close(HI_VOID);

/** 
The I2C device is not initialized.
CNcomment:\brief 创建一路GpioI2c

\attention \n
If the specified GPIO pins are used, this API fails to be called.\n
CNcomment:如果Gpio已被占用会失败\n

\param[in] u32I2cNum  ID of the obtained I2C bus                            CNcomment:得到I2C总线号。
\param[in] whichGpioClock  Group ID of the clock pin, ranging from 0 to 12  CNcomment:Clock管脚组号，取值范围为0～12
\param[in] whichGpioData   Group ID of the data pin, ranging from 0 to 12   CNcomment:Data管脚组号， 取值范围为0～12
\param[in] clockBit  Clock pin ID, ranging from 0 to 7                      CNcomment:Clock管脚位号，取值范围为0～7
\param[in] dataBit   Data pin ID, ranging from 0 to 7                       CNcomment:Data管脚位号， 取值范围为0～7
\retval 0 Success                                                           CNcomment:成功
\retval ::HI_ERR_GPIO_INVALID_PARA  The parameter is invalid.               CNcomment:参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_I2C_CreateGpioI2c(HI_U32 *u32I2cNum, HI_U32 whichGpioClock, HI_U32 whichGpioData, HI_U32 clockBit, HI_U32 dataBit);

/** 
\brief Destroys a inter-integrated circuit (I2C) channel that simulates the general-purpose input/output (GPIO) function.
CNcomment:\brief 销毁一路GpioI2c

\attention \n
If the I2C channel is not used, a code indicating success is returned.\n
CNcomment:如果该GpioI2c未使用，直接返回成功\n

\param[in] u32I2cNum ID of the I2C bus to be destroyed        CNcomment:要销毁的I2C总线号。
\retval 0  Success                                            CNcomment:成功
\retval ::HI_ERR_GPIO_INVALID_PARA  The parameter is invalid. CNcomment:参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_I2C_DestroyGpioI2c(HI_U32 u32I2cNum);
/** 
\brief Reads data by using the I2C bus.
CNcomment:\brief 通过I2C读数据。

\attention \n
N/A
\param[in] u32I2cNum  I2C bus of the device to be read           CNcomment:所读取设备使用的I2C总线。
\param[in] u8DevAddress  Address of a device on the I2C bus      CNcomment:设备在I2C总线上的地址。
\param[in] u32RegAddr  On-chip offset address of a device        CNcomment:设备的片内偏移地址。
\param[in] u32RegAddrCount  Length of an on-chip offset address. CNcomment:片内偏移地址的长度单位。
                      1: 8-bit sub address                       CNcomment:1：表示8bit子地址；
                      2: 16-bit sub address                      CNcomment:2：表示16bit子地址；
                      3: 24-bit sub address                      CNcomment:3：表示24bit子地址；
                      4: 32-bit sub address                      CNcomment:4：表示32bit子地址。

\param[out] pu8Buf   Buffer for storing the data to be read                            CNcomment:读Buffer，存放读取数据。
\param[in] u32Length  Length of the data to be read                                    CNcomment:要读取的数据长度。
\retval 0 Success                                                                      CNcomment:成功
\retval ::HI_ERR_I2C_NOT_INIT  The I2C device is not initialized.                      CNcomment:I2C设备未初始化
\retval ::HI_ERR_I2C_INVALID_POINT  The I2C pointer is invalid.                        CNcomment:I2C无效指针
\retval ::HI_ERR_I2C_INVALID_PARA  The I2C parameter is invalid.                       CNcomment:I2C无效参数
\retval ::HI_ERR_I2C_FAILED_INIT  The I2C device fails to be initialized.              CNcomment:I2C设备初始化失败
\retval ::HI_ERR_I2C_FAILED_READ  Data fails to be read by using the I2C bus.          CNcomment:I2C读数据失败
\retval ::HI_ERR_I2C_FAILED_SETRATE The transfer rate of the I2C bus fails to be set.  CNcomment:I2C设置速率失败
\see \n
N/A
*/
HI_S32 HI_UNF_I2C_Read(HI_U32 u32I2cNum, HI_U8 u8DevAddress, HI_U32 u32RegAddr,
                       HI_U32 u32RegAddrCount, HI_U8 *pu8Buf, HI_U32 u32Length);
                       

/** 
\brief Writes data by using the I2C bus. That is, you can call this API to write data to the device mounted on the I2C bus through the I2C channel.
CNcomment:\brief 通过I2C写数据。通过I2C通道，向I2C总线上挂接的设备进行写操作。

\attention \n
N/A
\param[in] u32I2cNum  I2C bus of the device to be written         CNcomment:待写设备使用的I2C总线。
\param[in] u8DevAddress  Address of a device on the I2C bus       CNcomment:设备在I2C总线上的地址。
\param[in] u32RegAddr  On-chip offset address of a device         CNcomment:设备的片内偏移地址。
\param[in] u32RegAddrCount Length of an on-chip offset address.   CNcomment:片内偏移地址的长度单位。
                    1: 8-bit sub address                          CNcomment:1：表示8bit子地址；
                    2: 16-bit sub address                         CNcomment:2：表示16bit子地址；
                    3: 24-bit sub address                         CNcomment:3：表示24bit子地址；
                    4: 32-bit sub address                         CNcomment:4：表示32bit子地址。
                    
\param[in]  pu8Buf   Buffer for storing the data to be written                         CNcomment:写Buffer，存放待写入数据。
\param[in] u32Length  Length of the data to be written                                 CNcomment:要写入的数据的长度。
\retval 0  Success                                                                     CNcomment:成功
\retval ::HI_ERR_I2C_NOT_INIT  The I2C device is not initialized.                      CNcomment:I2C设备未初始化
\retval ::HI_ERR_I2C_REPEAT_INIT  The I2C device has been initialized.                 CNcomment:I2C设备重复初始化
\retval ::HI_ERR_I2C_INVALID_POINT  The I2C pointer is invalid.                        CNcomment:I2C无效指针
\retval ::HI_ERR_I2C_INVALID_PARA  The I2C parameter is invalid.                       CNcomment:I2C无效参数
\retval ::HI_ERR_I2C_FAILED_INIT  The I2C device fails to be initialized.              CNcomment:I2C设备初始化失败
\retval ::HI_ERR_I2C_FAILED_WRITE  Data fails to be written by using the I2C bus.      CNcomment:I2C写数据失败
\retval ::HI_ERR_I2C_FAILED_SETRATE  The transfer rate of the I2C bus fails to be set. CNcomment:I2C设置速率失败
\see \n
N/A
*/                      
HI_S32 HI_UNF_I2C_Write(HI_U32 u32I2cNum, HI_U8 u8DevAddress, HI_U32 u32RegAddr,
                       HI_U32  u32RegAddrCount, HI_U8 * pu8Buf, HI_U32 u32Length);


/** 
\brief Sets the transfer rate of the I2C bus.
CNcomment:\brief 设置I2C的传输速率。

\attention \n
If you do not call this API to set the transfer rate, the rate 100 kbit/s is used by default.
CNcomment:如果不调用此接口，系统采用100Kbit/s作为缺省速率。

\param[in] u32I2cNum  D of channel corresponding to the device to be written on the I2C bus                         CNcomment:所写设备在I2C总线上的通道号。
\param[in] enI2cRate  I2C clock rate. For details about the definition, see the description of ::HI_UNF_I2C_RATE_E. CNcomment:I2C时钟速率。含义请参考::HI_UNF_I2C_RATE_E
\retval 0  Success                                                                                                  CNcomment:成功
\retval ::HI_ERR_I2C_NOT_INIT  The I2C device is not initialized.                                                   CNcomment:I2C设备未初始化
\retval ::HI_ERR_I2C_REPEAT_INIT  The I2C device has been initialized.                                              CNcomment:I2C设备重复初始化
\retval ::HI_ERR_I2C_INVALID_POINT  The I2C pointer is invalid.                                                     CNcomment:I2C无效指针
\retval ::HI_ERR_I2C_INVALID_PARA  The I2C parameter is invalid.                                                    CNcomment:I2C无效参数
\retval ::HI_ERR_I2C_FAILED_INIT  The I2C device fails to be initialized.                                           CNcomment:I2C设备初始化失败
\retval ::HI_ERR_I2C_FAILED_READ  Data fails to be read by using the I2C bus.                                       CNcomment:I2C读数据失败
\retval ::HI_ERR_I2C_FAILED_WRITE  Data fails to be written by using the I2C bus.                                   CNcomment:I2C写数据失败
\retval ::HI_ERR_I2C_FAILED_SETRATE  The transfer rate of the I2C bus fails to be set.                              CNcomment:I2C设置速率失败
\see \n
N/A
*/
HI_S32 HI_UNF_I2C_SetRate(HI_U32 u32I2cNum, HI_UNF_I2C_RATE_E enI2cRate);

/** @} */  /** <!-- ==== API Declaration End ==== */


/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_4 */
/** @{ */  /** <!-- [KEYLED] */
/**---- keyled ----*/
/**
\brief Initializes the KEYLED module.
CNcomment:\brief 初始化KEYLED模块。

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:重复调用本接口，会返回成功。

\param N/A                                        CNcomment:无
\retval ::HI_SUCCESS Success                      CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.     CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_KEYLED_Init(HI_VOID);


/**
\brief Deinitializes the KEYLED module.
CNcomment:\brief 去初始化KEYLED模块。

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:重复调用本接口，会返回成功。

\param N/A                                    CNcomment:无
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_KEYLED_DeInit(HI_VOID);

/**
\brief Selects the type of the KEYLED.
CNcomment:\brief 选择KEYLED器件类型。

\attention \n
It is recommended to call this API once after the KEYLED module is initialized. By default, the standard KEYLED type is selected.
CNcomment:建议初始化后只选择一次，不要重复调用，默认为标准KEYLED模式。

\param[in] enKeyLedType   KEYLED type         CNcomment:keyled类型。 
\retval ::HI_SUCCESS   Success                CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_KEYLED_SelectType(HI_UNF_KEYLED_TYPE_E enKeyLedType);

/**
\brief Enables the key function.
CNcomment:\brief 打开按键功能。
\attention \n
The KEYLED module starts to receive key values after the key function is enabled.\n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:打开后开始接收按键\n
CNcomment: 重复调用本接口，会返回成功。
\param N/A                                     CNcomment:无
\retval ::HI_SUCCESS Success                   CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.  CNcomment: API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_Open(HI_VOID);

/**
\brief Disables the key function.
CNcomment:\brief 关闭按键功能。

\attention \n
The KEYLED module stops receiving key IDs after the key function is disabled.\n
This API is valid when it is called for the first time. If this API is called repeatedly, the error code HI_SUCCESS is returned.
CNcomment:关闭后停止接收按键\n
CNcomment: 本接口第一次调用起作用,重复调用返回成功。

\param N/A                                    CNcomment:无
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_Close(HI_VOID);

/**
\brief Clears the key values that are not received.
CNcomment:\brief 清空当前没有接收的按键。

\attention \n
This API is used to clear the buffer for storing the key values. In this way, the initial state is returned.
CNcomment:清空按键buffer，回到初时状态。
\param N/A Success                            CNcomment:无
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_Reset(HI_VOID);


/**
\brief Obtains a key value.
CNcomment:\brief 获取一个按键值。

\attention \n
This API is used to obtain the key value that is received first in the buffer. After this API is called, the key value and key status are returned.\n
The key status contains pressed and released.\n
This API needs to work with ::HI_UNF_KEY_SetBlockTime.\n
If there are no key values, the API waits until timeout occurs. In this case, the error code ::HI_ERR_KEYLED_TIMEOUT is returned.\n
If the timeout is set to 0 in non-block mode, the error code ::HI_ERR_KEYLED_NO_NEW_KEY is returned when there are no key values.
If the timeout is set to 0xFFFFFFFF, it indicates infinite wait.
CNcomment:获取buffer中最早到达的按键值，返回按键值的数值和状态\n
CNcomment: 状态包含按下和弹起\n
CNcomment: 接口配合::HI_UNF_KEY_SetBlockTime接口一起使用\n
CNcomment: 没有按键时，进行等待，超时后退出并返回超时错误码\n
CNcomment: 超时值为0时为非阻塞接口，没有按键直接返回没有按键错误码\n
CNcomment: 超时值设置为0xffffffff，一直等待。
\param[out] pu32PressStatus   Key status, pressed or released           CNcomment:按键状态是按下还是弹起。
\param[out] pu32KeyId  Key value                                        CNcomment:按键值。
\retval ::HI_SUCCESS  Success                                           CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized. CNcomment:模块没有初始化
\retval ::HI_ERR_KEYLED_NULL_PTR  The pointer is null.                  CNcomment:指针参数为空
\retval ::HI_ERR_KEYLED_NO_NEW_KEY  There are no key values.            CNcomment:没有按键
\retval ::HI_ERR_KEYLED_TIMEOUT  Waiting for key values times out.      CNcomment:等待按键超时
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_GetValue(HI_U32 * pu32PressStatus, HI_U32 * pu32KeyId);

/**
\brief Sets the timeout of reading key IDs.
CNcomment:\brief 设置按键读取的超时时间。

\attention \n
If the timeout is set to 0, the API is not blocked. If there is no key ID, the error code HI_ERR_KEYLED_NO_NEW_KEY is returned.\n
If the timeout is set to 0xFFFFFFFF, it indicates infinite wait.
CNcomment:超时值为0时不阻塞，没有按键直接返回没有按键错误码\n
CNcomment: 超时值设置为0xffffffff，一直等待。
\param[in] u32BlockTimeMs   Timeout, in ms                               CNcomment:超时时间，单位ms。
\retval ::HI_SUCCESS Success                                             CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                            CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:模块没有初始化
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_SetBlockTime(HI_U32 u32BlockTimeMs);


/**
\brief Set the time of pressing a key repeatedly.
CNcomment:\brief 设置重复按键的时间。

\attention \n
If a key is pressed for a period of time, it considers that the key is pressed repeatedly.\n
The time ranges from 108 ms to 65536 ms. If the time is not within the range, the time is automatically restricted to this range.
The default time is 200 ms.
CNcomment:当某个键处于按下状态，超过设置的时间值判断为重复按键\n
CNcomment: 重复按键的设置范围在108ms到65536ms之间，超过这个范围会自动约束到上限或下限上\n
CNcomment: 默认的重复按键判断时间为200ms。

\param[in] u32RepTimeMs  Time of pressing a key repeatedly, in ms       CNcomment:判断为重复按键的时间，单位ms。
\retval ::HI_SUCCESS Success                                            CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized. CNcomment:模块没有初始化
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_RepKeyTimeoutVal(HI_U32 u32RepTimeMs);

/**
\brief Enables or disables the function of reporting the same key ID.
CNcomment:\brief 设置是否使能重复按键。

\attention \n
The ID of a pressed key is reported consecutively only after the report function is enabled.
CNcomment:只有使能后，一直按住某个键，才能连续上报键值。

\param[in] u32IsRepKey Repeat key report enable. 1: enabled; 0: disabled   CNcomment:是否使能重复按键，1 使能，0 不使能。
\retval ::HI_SUCCESS Success                                               CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                              CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.    CNcomment:模块没有初始化
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_IsRepKey(HI_U32 u32IsRepKey);

/**
\brief Enables or disables the function of reporting the released status of a key.
CNcomment:\brief 设置是否上报按键弹起。

\attention \n
The released statuses of keys are reported only after the report function is enabled. Otherwise, only the pressed statuses are reported.
CNcomment:使能后才会上报按键弹起事件，不然只上报按下事件。

\param[in] u32IsKeyUp Repeat key report enable. 1: enabled; 0: disabled  CNcomment:是否使能重复按键，1 使能，0 不使能。
\retval ::HI_SUCCESS Success                                             CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                            CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:模块没有初始化
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_IsKeyUp(HI_U32 u32IsKeyUp);

/**
\brief Enables the display function of LEDs.
CNcomment:\brief 打开数码管显示功能。

\attention \n
The LEDs work only after the display function is enabled.\n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:打开后才会有数码管的显示\n
CNcomment: 重复调用本接口，会返回成功。

\param N/A                                     CNcomment:无
\retval ::HI_SUCCESS Success                   CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.  CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_LED_Open(HI_VOID);

/**
\brief Disables the display function of LEDs.
CNcomment:\brief 关闭数码管显示功能。

\attention \n
The LEDs do not work after the display function is disabled.\n
This API is valid when it is called for the first time. If this API is called repeatedly, the error code HI_SUCCESS is returned.
CNcomment:关闭后停止数码管显示\n
CNcomment: 本接口第一次调用起作用,重复调用返回成功。

\param N/A                                    CNcomment:无
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_LED_Close(HI_VOID);


/**
\brief Displays characters based on the type of the input code.
CNcomment:\brief 根据传入的码型值进行显示。

\attention \n
Each LED displays a character that corresponds to the value of one byte.\n
During displaying, the values of the four characters to be displayed need to be combined to form a 32-bit unsigned int data segment. The data serves as the parameter value of this API.\n
The four LEDs from left to right display bit[7:0], bit[15:8], bit[23:16], and bit[31:24] of the data respectively.\n
For example, if you want to display "1234" on LEDs, you need to combine the display values corresponding to these characters to form the following unsigned int variable:\n
  Unsigned int parameter = 0x03 + (0x9F <<8) + (0x25<<16) + (0x0D <<24);\n
Where, 0x03, 0x9F, 0x25, and 0x0D are the display values of 1, 2, 3, and 4 respectively.\n
The following shows the mapping between the segments of a 7-segment LED and data bits:\n
       --7--       \n
      |     |      \n
     2|     |6     \n
      |--1--       \n
      |     |      \n
     3|     |5     \n
       --4-- .0    \n
The common display characters and values of the LEDs on HiSilicon demo board are as follows in the case of co-anode (the display characters and values need to be reversed in the case of co-cathode):
  Digitals 0-9: 0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09\n
  Upper-case letters A-Z (the characters that cannot be displayed are expressed as 0xFF):\n
     0xFF, 0xFF, 0x63, 0xFF, 0x61, 0x71, 0xFF, 0x91, 0xFF, 0xFF, 0xFF, 0xE3, 0xFF,\n
     0xFF, 0x03, 0x31, 0xFF, 0xFF, 0x49, 0xFF, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF\n
  Lower-case letters a-z (the characters that cannot be displayed are expressed as 0xFF):\n
    0xFF, 0xC1, 0xE5, 0x85, 0x21, 0xFF, 0x09, 0xD1, 0xDF, 0xFF, 0xFF, 0x9F, 0xFF,\n
    0xD5, 0xC5, 0x31, 0x19, 0xFF, 0x49, 0xFF, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
CNcomment:	每个数码管要显示的字符对应一个字节的显示值。\n
CNcomment: 显示时需要将4 个待显示字符对应的显示值组合成一个unsiged int（32bit）数据作为此接口的参数值。\n
CNcomment: 从左到右的4 个LED 依次显示数据的bit[7:0]、bit[15:8]、bit[23:16]、bit[31:24]。\n
CNcomment: 例如：在LED 上显示“1234”，则需要将这些字符对应的显示值组合成一个Unsigned int 的变量：\n
CNcomment:   Unsigned int parameter = 0x03 + (0x9F <<8) + (0x25<<16) + (0x0D <<24)；\n
CNcomment: 其中：0x03、0x9F、0x25、0x0D 分别是‘1’、‘2’、‘3’、‘4’的显示值。\n
CNcomment:七段数码管段数与数据的bit对应关系如下:\n
CNcomment:       --7--       \n
CNcomment:      |     |      \n
CNcomment:     2|     |6     \n
CNcomment:      |--1--       \n
CNcomment:      |     |      \n
CNcomment:     3|     |5     \n
CNcomment:       --4-- .0    \n
CNcomment:海思DEMO板数码管常用显示字符及其对应的显示值如下(针对共阳极，共阴极要取反)：\n
CNcomment:  . 字符0-9：0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09\n
CNcomment:  . 大写字母A-Z（不能显示的用0xFF 表示）：\n
CNcomment:     0xFF, 0xFF, 0x63, 0xFF, 0x61, 0x71, 0xFF, 0x91, 0xFF, 0xFF, 0xFF, 0xE3, 0xFF,\n
CNcomment:     0xFF, 0x03, 0x31, 0xFF, 0xFF, 0x49, 0xFF, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF\n
CNcomment:  . 小写字母a-z（不能显示的用0xFF 表示）：\n
CNcomment:    0xFF, 0xC1, 0xE5, 0x85, 0x21, 0xFF, 0x09, 0xD1, 0xDF, 0xFF, 0xFF, 0x9F, 0xFF,\n
CNcomment:   0xD5, 0xC5, 0x31, 0x19, 0xFF, 0x49, 0xFF, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
\param[in] u32CodeValue 4-digit value to be displayed                   CNcomment:需要显示的4位数值。
\retval ::HI_SUCCESS Success                                            CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized. CNcomment:模块没有初始化
\see \n
N/A
*/
HI_S32 HI_UNF_LED_Display(HI_U32 u32CodeValue);


/**
\brief Displays the time on LEDs.
CNcomment:\brief 在数码管上显示时间。

\attention \n
The values of hour and minute need to be converted into corresponding decimal values. For example, if you want to display 22:45, you need to set hour to 22 and set minute to 45.\n
Before calling this API, you need to call HI_UNF_LED_SetFlashPin to set the statuses of display pins to HI_UNF_KEYLED_LIGHT_ALL.\n
After the start time is set, the time is displayed on LEDs. At the same time, the colon (:) in the time blinks at the frequency of 1 Hz.\n
Because the time is displayed in 24-hour format, the maximum value of hour is 23, and the maximum value of minute is 59.
CNcomment:小时、分钟只需配置成相应的十进制值就行了。比如显示22：45，则hour=22，minute=45。\n
CNcomment: 需要先调用HI_UNF_LED_SetFlashPin 配置显示管脚为HI_UNF_KEYLED_LIGHT_ALL\n
CNcomment: 传入时间数据结构，然后在数码管上显示，显示时间的同时冒号会以1HZ的频率闪烁\n
CNcomment: 时间的范围注意按24小时制，最大支持小时为23，分为59。

\param[in] stLedTime Time                                                CNcomment:时间。
\retval ::HI_SUCCESS  Success                                            CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                            CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:模块没有初始化
\retval ::HI_ERR_KEYLED_INVALID_PARA  The input parameter is invalid.    CNcomment:输入参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_LED_DisplayTime(HI_UNF_KEYLED_TIME_S stLedTime);

/**
\brief Sets the ID of the blinked LED.
CNcomment:\brief 设置要闪烁的LED 序号。

\attention \n
The IDs of the LEDs on the board are 1, 2, 3, and 4 from left to right.
CNcomment:单板上的数码管的序号从左到右依次为：1、2、3、4。

\param[in] enPin  Pin ID                                                 CNcomment:要显示的序号。
\retval ::HI_SUCCESS Success                                             CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                            CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:模块没有初始化
\retval ::HI_ERR_KEYLED_INVALID_PARA  The input parameter is invalid.    CNcomment:输入参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_LED_SetFlashPin(HI_UNF_KEYLED_LIGHT_E enPin);

/**
\brief Sets the blink level of an LED.
CNcomment:\brief 设置LED 闪烁级别。

\attention \n
The higher the level, the faster an LED blinks.
CNcomment:级别越高闪烁速度越快。

\param[in] enLevel  Blink level                                          CNcomment:闪烁级别。
\retval ::HI_SUCCESS Success                                             CNcomment:成功
\retval ::HI_FAILURE Calling this API fails.                             CNcomment:API系统调用失败
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:模块没有初始化
\retval ::HI_ERR_KEYLED_INVALID_PARA The input parameter is invalid.     CNcomment:输入参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_LED_SetFlashFreq(HI_UNF_KEYLED_LEVEL_E enLevel);

/* 显示锁频灯1:点亮0:关闭  jzby wrwei 20130123 */
/*modi start*/
HI_S32 HI_UNF_LED_DispLockLed(int lock);
/*modi end*/
/** @} */  /** <!-- ==== API Declaration End ==== */


/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_5 */
/** @{ */  /** <!-- [PM] */
/*---- pm ----*/
/** 
\brief Starts the power management on chip (PMoC) device.
CNcomment:\brief 打开低功耗模块设备。

\attention \n
The ARM can be switched to another operating mode and then to low-power mode only after the PMoC device is started.
CNcomment:在打开低功耗模块设备后，才能切换ARM的工作模式，继而进入低功耗状态。

\param N/A                                                               CNcomment:无
\retval 0 Success                                                        CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT  The PMoC device is not started.          CNcomment:PMoC设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.             CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA  The parameter is invalid.            CNcomment:非法参数
\retval ::HI_ERR_PMoC_INVALID_MODE  The system running mode is invalid.  CNcomment:非法的系统运行模式
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_Init(HI_VOID);

/** 
\brief Stops the PMoC device.
CNcomment:\brief 关闭低功耗设备。

\attention \n
N/A
\param  N/A                                                             CNcomment:无
\retval 0 Success                                                       CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT  PMoC  The PMoC device is not started.   CNcomment:设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.            CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA  The parameter is invalid.           CNcomment:非法参数
\retval ::HI_ERR_PMoC_INVALID_MODE  The system running mode is invalid. CNcomment:非法的系统运行模式
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_DeInit(HI_VOID);

/** 
\brief Sets the mode to which the ARM is switched and obtains the wake-up mode.
CNcomment:\brief 设置ARM要切换到的模式，同时获取ARM唤醒的方式。

\attention \n
If the ARM enters the HI_UNF_PMOC_MODE_SLEEP mode, programs stop running at once. The subsequent code can be executed only after the ARM is woken up.\n
Before enabling the standby mode, you must start the IR device, key device on the front panel, and real-time clock (RTC) device; otherwise, the interrupts of these devices are masked. As a result, the corresponding wake-up modes cannot be achieved.\n
Do not access DDRs after the ARM enters the sleep mode. Therefore, the functions of display output, video output, DEMUX input, and audio/video decoding must be disabled.
CNcomment:ARM进入HI_UNF_PMOC_MODE_SLEEP真待机模式后程序立即停止运行，必须在唤醒后才能继续执行后面的代码\n
CNcomment: 进入待机模式前，必须打开IR（遥控器）设备、前面板KEY设备和RTC设备，否则对应模块的中断被屏蔽，不能实现该种模式的唤醒\n
CNcomment: 进入真待机时，必须确保不对DDR进行访问。所以必须关闭显示输出、视频输出、DEMUX输入、音视频解码等。

\param[in] enSystemMode   Mode of the ARM in low-power mode    
			     CNcomment: 置低功耗下ARM所处模式。
                         Because the operating frequency of the ARM is reduced, but the power consumption is not reduced significantly in HI_UNF_PMOC_MODE_SLOW and
                         HI_UNF_PMOC_MODE_DOZE modes, the HI_UNF_PMOC_MODE_SLEEP mode is recommended.
                         If the ARM stops in HI_UNF_PMOC_MODE_SLEEP mode, it can be returned to the normal mode.					
			     CNcomment:由于HI_UNF_PMOC_MODE_SLOW和
                         CNcomment:HI_UNF_PMOC_MODE_DOZE只降低ARM工作频率，功耗降低并不明显，推荐使用HI_UNF_PMOC_MODE_SLEEP真待机模式，
                         CNcomment:此模式下程序停止运行，返回后处于Normal模式。
                         
\param[in]  penWakeUpStatus Wake-up mode returned from the HI_UNF_PMOC_MODE_SLEEP mode. For details about the definition, see the description of ::HI_UNF_PMOC_ACTUAL_WKUP_E. CNcomment: 从HI_UNF_PMOC_MODE_SLEEP状态返回时的唤醒方式。具体含义请参考::HI_UNF_PMOC_ACTUAL_WKUP_E
\retval 0 Success                                                          CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT   The PMoC device is not started.           CNcomment:PMoC设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.               CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA  The parameter is invalid.              CNcomment:非法参数
\retval ::HI_ERR_PMoC_INVALID_MODE  The system running mode is invalid.    CNcomment:非法的系统运行模式
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SwitchSystemMode(HI_UNF_PMOC_MODE_E enSystemMode, HI_UNF_PMOC_ACTUAL_WKUP_E * penWakeUpStatus);


/** 
\brief Sets the wake-up mode of the ARM.
CNcomment:\brief 设置ARM唤醒方式。

\attention \n
You can query the original IR code values by referring to IR remote manuals.\n
In addition, you can query the relationships between the keys and key IDs by checking the connection between hardware and chips.
CNcomment:IR原始码值可以通过遥控器的使用手册得到\n
CNcomment:按键与键值的对应关系可以通过硬件和芯片的连接关系得到。

\param[in] pstAttr  Wake-up mode of the ARM                             CNcomment:ARM唤醒方式。
\retval 0 Success                                                       CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT  The PMoC device is not started.         CNcomment:PMoC设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.            CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA  The parameter is invalid.           CNcomment:非法参数
\retval ::HI_ERR_PMoC_INVALID_MODE  The system running mode is invalid. CNcomment:非法的系统运行模式
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetWakeUpAttr(HI_UNF_PMOC_WKUP_S_PTR pstAttr);

/**
\brief set display content when wake up 
CNcomment:\brief 设置唤醒显示内容。

\attention \n
content that the panel display when standby
CNcomment:待机时面板显示指定内容\n

\param[in] pstStandbyMode  display content:time or channle or no display   CNcomment:显示内容:时间 or 频道 or 无显示。
\retval 0  success                                                         CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT pmoc device do not open PMoC                CNcomment:设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.               CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA  The parameter is invalid.              CNcomment:非法参数
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetStandbyDispMode(HI_UNF_PMOC_STANDBY_MODE_S_PTR pstStandbyMode);

/**
\brief Obtains the current system mode.
CNcomment:\brief 获取系统当前模式。

\attention \n
This API is forward compatible and is valid only in normal state.\n
CNcomment:仅在正常状态下有效，接口前项兼容\n

\param[in] penSystemMode  Mode to be obtained                   CNcomment:需要获取的模式。
\retval 0 Success                                               CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT  The PMoC device is not started. CNcomment:PMoC设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.    CNcomment:非法指针
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_ReadSystemMode(HI_UNF_PMOC_MODE_E * penSystemMode);

/** 
\brief Sets the operating scenario.
CNcomment:\brief 设置工作场景。

\attention \n
Only the standby scenario is supported currently.\n
CNcomment:目前仅支持标准待机场景\n

\param[in] eScene  Standby scenario                               CNcomment:待机场景。
\retval 0 Success                                                 CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT    The PMoC device is not started. CNcomment:PMoC设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.      CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA  The parameter is invalid.     CNcomment:非法参数
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetScene(HI_UNF_PMOC_SCENE_E eScene);


/** 
\brief Sets the types of the devices related to standby such as front panel and IR remote control.
CNcomment:\brief 设置目前前面板同红外遥控等待机相关设备的类型。

\attention \n
The remote control supports only HI_UNF_IR_CODE_NEC_SIMPLE.\n
The front panel supports HI_UNF_KEYLED_TYPE_STD and HI_UNF_KEYLED_TYPE_PT6961.\n
CNcomment:遥控仅支持  HI_UNF_IR_CODE_NEC_SIMPLE 类型\n
CNcomment:前面板支持	HI_UNF_KEYLED_TYPE_STD 同 HI_UNF_KEYLED_TYPE_PT6961 两种类型\n	

\param[in] pdevType  Standby device that needs to be supported by the MCU       CNcomment:需要MCU支持的待机设备。
\retval 0 Success                                                               CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT The PMoC device is not started.                  CNcomment:PMoC设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.                    CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA   The parameter is invalid.                  CNcomment:非法参数
\retval ::HI_ERR_PMOC_FAILED_SETDEV   The setting fails.                        CNcomment:设置失败
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetDevType(HI_UNF_PMOC_DEV_TYPE_S_PTR pdevType);


/** 
\brief Loads the microprogrammed control unit (MCU) codes.
CNcomment:\brief 用于加载MCU代码。

\attention \n
This API is only for debugging. After MCU codes are compiled, you can load them by calling this API. This avoids the compilation of hi_c51.ko.\
CNcomment:仅供调试使用，MCU代码编译完成后，可以使用这个接口载入，避免每次都编译hi_c51.ko\n	

\param[in] pMcuCode Contents o f binary MCU codes               CNcomment:MCU二进制代码内容
\param[in] CodeSize  Size of binary MCU codes                   CNcomment:MCU二进制代码长度
\retval 0 Success                                               CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT  The PMoC device is not started. CNcomment:PMoC设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.    CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA   The parameter is invalid.  CNcomment:非法参数
\retval ::HI_ERR_PMOC_FAILED_SETDEV   setting fail              CNcomment:设置失败
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_LoadMcuCode(HI_U8 *pMcuCode, HI_U32 CodeSize);


/** 
\brief when standby, GPIO pin control 12v and 5v power,relate to hardware
CNcomment:\brief 用于待机时,GPIO管脚控制12V0和5V0电源，与硬件相关。

\attention \n
when standby, the outside power controled by STANDBY_PWROFF pin, the function can be ignored
when some part of outside power controled by GPIO pin, use this function will decrease standby power
CNcomment:待机时外围电源全部由管脚STANDBY_PWROFF控制时，不用理会该接口；
CNcomment:当部分外围电源由GPIO管脚去控制时,合理调用该接口用于降低待机功耗。

\param[in] u32GpioNo  GPIO pin index, choose the fifth[40,47] CNcomment:GPIO管脚索引号,取第5组为[40, 47]
\param[in] bHighOrLow GPIO output control                     CNcomment:GPIO管脚输出控制
\retval 0  success                                            CNcomment:成功
\retval ::HI_ERR_PMoC_NOT_INIT  PMoC  device do not open      CNcomment:设备未打开
\retval ::HI_ERR_PMoC_INVALID_POINT  The pointer is invalid.  CNcomment:非法指针
\retval ::HI_ERR_PMoC_INVALID_PARA   The parameter is invalid.CNcomment:非法参数
\retval ::HI_ERR_PMOC_FAILED_SETDEV  setting fail             CNcomment:设置失败
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetPwrOffGpio(HI_U32 u32GpioNo,HI_BOOL bHighOrLow);


/** @} */  /** <!-- ==== API declaration end ==== */


/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_6 */
/** @{ */  /** <!-- [IR] */
/*---IR---*/
/** 
\brief Starts the IR device.
CNcomment:\brief 打开IR设备。

\attention \n
This API cannot be called repeatedly. Key IDs can be received only after you can start the IR device, and then call HI_UNF_IR_Enable.
CNcomment:重复调用会失败，打开设备后必须再调用HI_UNF_IR_Enable才能正常接收键值。

\param N/A                                                                   CNcomment:无
\retval 0 Success                                                            CNcomment:成功
\retval ::HI_ERR_IR_NOT_INIT   The IR device is not initialized.             CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT The pointer is invalid.                    CNcomment:指针为空
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.                  CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_ISKEYUP_ARG  The parameter of iskeyup is invalid CNcomment:按键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_ISREPKEY_ARG  The parameter of isrepkey is invalid CNcomment:重复键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE    The code type is invalid.            CNcomment:码型参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_IR_Open(HI_VOID);

/**
\brief Stops the IR device.
CNcomment:\brief 关闭IR设备。

\attention \n
This API cannot be called repeatedly.
CNcomment:重复调用关闭会失败。

\param  N/A                                                                  CNcomment:无
\retval 0 Success                                                            CNcomment:成功
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.              CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT   The pointer is invalid.                  CNcomment:指针为空
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.                  CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_ISKEYUP_ARG  The parameter of iskeyup is invalid  CNcomment:按键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_ISREPKEY_ARG  The parameter of isrepkey is invalid CNcomment:重复键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE  The code type is invalid.              CNcomment:码型参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_IR_Close(HI_VOID);


/** 
\brief Enables the IR device.
CNcomment:\brief 使能IR设备。
\attention \n
N/A
\param[in] bEnable  IR enable. HI_TRUE: enabled; HI_FALSE: disabled           CNcomment:IR 使能开关, HI_TRUE 使能, HI_FALSE 禁用。
\retval 0 Success                                                             CNcomment:成功
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.               CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT   The pointer is invalid.                   CNcomment: 指针为空
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.                   CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_ISKEYUP_ARG  The parameter of iskeyup is invalid  CNcomment: 按键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_ISREPKEY_ARG  The parameter of isrepkey is invalid CNcomment:重复键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE   The code type is invalid.              CNcomment:码型参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_IR_Enable ( HI_BOOL bEnable);

/** 
\brief Obtains the protocol type of a remote control.
CNcomment:\brief 获取遥控器的协议类型 。

\attention \n
To obtain the protocol type of an IR remote control, you need to call HI_UNF_IR_GetValue and HI_UNF_IR_GetProtocol in sequence.
CNcomment:当IR_TYPE!=IR_LIRC时有效 请在调用HI_UNF_IR_GetValue之后调用

\param[out]  penProtocol  protocol type pointer,reference HI_UNF_IR_PROTOCOL_E for detail   CNcomment:协议类型指针  具体含义请参考::HI_UNF_IR_PROTOCOL_E
\retval 0 Success                                    CNcomment:成功
\retval ::HI_ERR_IR_NULL_PTR   The pointer is null.  CNcomment:指针为空
\see \n
N/A
*/

HI_S32 HI_UNF_IR_GetProtocol(HI_UNF_IR_PROTOCOL_E *penProtocol);

/**
\brief obtain name of remote control protocol
CNcomment:\brief 获取遥控器的协议名称 。

\attention \n
when IR_TYPE=IR_LIRC is effective, transfer if after HI_UNF_IR_GetValue
CNcomment:当IR_TYPE=IR_LIRC时有效 在调用HI_UNF_IR_GetValue之后再调用

\param[out]  pProtocolName  used to save first address of the protocol name buffer    CNcomment:用于存储协议名称的缓冲区首地址
\param[in]   s32BufLen      used to save length of the protocol name buffer           CNcomment:用于存储协议名称的缓冲区长度
\retval ::HI_SUCCESS        success                                                   CNcomment:成功
\retval ::HI_ERR_IR_INVALID_PARA  invalid patameter                                   CNcomment:参数无效
\see \n
N/A
*/
HI_S32 HI_UNF_IR_GetProtocolName(HI_CHAR *pProtocolName,HI_S32 s32BufLen);


/** 
\brief Obtains the key values and key statuses of the remote control.
CNcomment:\brief 获取遥控器的按键值和按键状态 。

\attention \n
When you call HI_UNF_IR_GetValue in block mode, an error code is returned if timeout occurs. You can call HI_UNF_IR_SetBlockTime to set the timeout u32BlockTime.
If the u32UserCode parameter of HI_UNF_IR_SelectUserCode is 0, pu32KeyId contains the complete code value (including the user code and data code) of a key. If u32UserCode is not 0, pu32KeyId contains only the data code of a key.
CNcomment:阻塞方式下，调用HI_UNF_IR_GetValue函数时，当超时（调用HI_UNF_IR_SetBlockTime函数设置超时时间u32BlockTime）时返回错误信息\n
CNcomment:如果HI_UNF_IR_SelectUserCode接口参数u32UserCode为0，则pu32KeyId包含按键的完整码值（用户码和数据码）；如果用户码不为0，则pu32KeyId只包含按键的数据码

\param[out]  penPressStatus  Key status. For details about the definition, see the description of ::HI_UNF_KEY_STATUS_E.  CNcomment:按键状态。具体含义请参考::HI_UNF_KEY_STATUS_E
\param[out]  pu64KeyId  Key value                                                     CNcomment:按键值
\param[in] u32TimeoutMs  Timeout (in ms). 0: not blocked; 0xFFFFFFFF: infinite block  CNcomment:超时值, 单位是毫秒, 0 - 不阻塞, 0xFFFFFFFF-永久阻塞
\retval 0 Success                                                                     CNcomment:成功
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                       CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT  The pointer is invalid.                            CNcomment: 指针为空
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.                           CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_ISKEYUP_ARG  The parameter of iskeyup is invalid          CNcomment:按键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_ISREPKEY_ARG  The parameter of isrepkey is invalid        CNcomment:重复键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE  The code type is invalid.                       CNcomment:码型参数非法
\see \n
N/A
*/
#define HI_UNF_IR_GetValue(penPressStatus, pu64KeyId, u32TimeoutMs) HI_UNF_IR_GetValueWithProtocol(penPressStatus, pu64KeyId, NULL, 0, u32TimeoutMs)

HI_S32 HI_UNF_IR_GetValueWithProtocol(HI_UNF_KEY_STATUS_E *penPressStatus, HI_U64 *pu64KeyId, 
        HI_CHAR *pszProtocolName, HI_S32 s32NameSize, HI_U32 u32TimeoutMs);
/** 
\brief Set key fetch or symbol fetch from ir driver.
CNcomment:\brief 设定从红外驱动获取的是键值还是裸电平 。

\attention \n

\param[in] mode 0 means key mode. 1 means symbol mode                                 CNcomment:0获取键值，1获取裸电平
\retval 0 Success                                                                     CNcomment:成功
\retval :: others on fail                                                             CNcomment:其他值为失败。  
\see \n
N/A
*/
HI_S32 HI_UNF_IR_SetFetchMode(HI_S32 s32mode);

/** 
\brief Obtains the raw symbols from ir driver.
CNcomment:\brief 获取遥控器的裸电平 。

\attention \n

\param[out]  pu64lower  lower pluse value                                             CNcomment:裸电平对的低位，对应与先低后高格式的低电平
\param[out]  pu64upper  upper space value                                             CNcomment:裸电平对的高位，对应与先低后高格式的高电平
\param[in] s32TimeoutMs read timeout .                                               CNcomment:读超时时间。

\retval 0 Success                                                                     CNcomment:成功
        others on fail.                                                               CNcomment:其他值为失败。  
\see \n
N/A
*/
HI_S32 HI_UNF_IR_GetSymbol(HI_U64 *pu64First, HI_U64* pu64Second, HI_U32 u32TimeoutMs);

/** 
\brief Enables or disables the function of reporting the released status of a key.
CNcomment:\brief 设置是否上报按键弹起状态。

\attention \n
The function is enabled by default.
CNcomment:如不设置，默认为打开。

\param[in] bEnable      Key released enable.  CNcomment:按键弹起有效。
                        0: disabled           CNcomment:0：关闭；
                        1: enabled            CNcomment: 1：使能。
\retval 0  Success                                                      CNcomment:成功
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.         CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT  The pointer is invalid.              CNcomment:指针为空
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.             CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_ISKEYUP_ARG  The parameter of iskeyup is invalid   CNcomment:按键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_ISREPKEY_ARG  The parameter of isrepkey is invalid CNcomment:重复键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE  The code type is invalid.                CNcomment:码型参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_IR_EnableKeyUp(HI_BOOL bEnable);


/** 
\brief Enables or disables the function of reporting the same key value. If keys are pressed and held down, data is continuously transmitted to the receive buffer. Therefore, you can enable or disable this function for applications as required.
CNcomment:\brief 设置是否上报重复按键。一直按键时，数据会源源不断的送入到接收缓冲区，因此应用程序可以根据需要来设置是否上报重复按键。

\attention \n
The function is enabled by default.\n
This API must work with HI_UNF_IR_RepKeyTimeoutVal. The API HI_UNF_IR_RepKeyTimeoutVal is used to set the interval of reporting the same key value.\n
If the function of reporting the same key value is enabled, the keys are pressed and held down, and the interval is set to 300 ms, data is reported once every 300 ms.
If the function is disabled, data is reported only once regardless of how long the keys are hold down.
CNcomment:如不设置，默认为打开\n
CNcomment:此接口需要和HI_UNF_IR_RepKeyTimeoutVal函数结合使用，由HI_UNF_IR_RepKeyTimeoutVal设置上报重复按键的间隔\n
CNcomment:如果使能了重复按键上报，当按键一直处于按下状态，间隔设为300毫秒，则每300毫秒会上报一次数据\n
CNcomment:如果禁止了重复按键上报，则不论按下多长时间，只上报一次数据。
\param[in] bEnable     Repeat key report enable.    CNcomment:按键产生重复按键功能。
                       0: disabled                  CNcomment:0：关闭；
                       1: enabled                   CNcomment:1：使能。
\retval 0 Success 
\retval ::HI_ERR_IR_NOT_INIT   The IR device is not initialized.               CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT  The pointer is invalid.                     CNcomment:指针为空
\retval ::HI_ERR_IR_INVALID_PARA   The parameter is invalid.                   CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_ISKEYUP_ARG  The parameter of iskeyup is invalid   CNcomment:按键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_ISREPKEY_ARG  The parameter of isrepkey is invalid CNcomment:重复键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE  The code type is invalid.                CNcomment:码型参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_IR_EnableRepKey(HI_BOOL bEnable);


/** 
\brief Sets the interval (in ms) of reporting the same key value.
CNcomment:\brief 设置上报重复按键的时间间隔，单位为ms 。

\attention \n
This API is unavailable if the function of reporting the same key value is disabled by calling HI_UNF_IR_IsRepKey.
CNcomment:当HI_UNF_IR_IsRepKey配置为不上报重复按键时，此接口设置无效。

\param[in] u32TimeoutMs   Interval of reporting the same key value. The recommended interval ranges from 108 ms to 65,536 ms. CNcomment:上报重复按键的时间间隔，建议值：108ms～65536ms 。
\retval 0 Success CNcomment:                                                   CNcomment:成功
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT The pointer is invalid.                      CNcomment:指针为空
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.                    CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_ISKEYUP_ARG  The parameter of iskeyup is invalid   CNcomment:按键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_ISREPKEY_ARG  The parameter of isrepkey is invalid  CNcomment:重复键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE  The code type is invalid.                CNcomment:码型参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_IR_SetRepKeyTimeoutAttr(HI_U32 u32TimeoutMs);

/** 
\brief Sets the code type of the remote control.
CNcomment:\brief 设置遥控器码型。

\attention \n
The default code type is HI_UNF_IR_CODE_NEC_SIMPLE.
CNcomment:如不设置，默认为HI_UNF_IR_CODE_NEC_SIMPLE码型。

\param[in] enIRCode Four standard code types of the remote control are supported by default.  CNcomment:默认支持4种标准遥控器码型：
                     HI_UNF_IR_CODE_NEC_SIMPLE：  Nec With Simple code                        CNcomment: Nec With Simple码型；
                     HI_UNF_IR_CODE_TC9012：  TC9012 code                                     CNcomment:TC9012码型；
                     HI_UNF_IR_CODE_NEC_FULL：  Nec With Full code                            CNcomment:Nec With Full码型；
                     HI_UNF_IR_CODE_SONY_12BIT： Sony 12-Bit code                             CNcomment:Sony12Bit码型。
\retval 0 Success                                                CNcomment:成功
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.  CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT  The pointer is invalid.       CNcomment:指针为空
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.      CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE The code type is invalid.   CNcomment:码型参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_IR_SetCodeType(HI_UNF_IR_CODE_E enIRCode);


/** 
\brief  Resets the IR device.
CNcomment:\brief  复位IR设备。

\attention \n
This API is used to delete the key values in the buffer. After the values are deleted, you do not need to set the user code again.
CNcomment:只是把buffer中的键值清掉，清掉之后不需要重新设置用户码。

\param N/A         CNcomment:无
\retval 0 Success  CNcomment:成功
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                 CNcomment:IR设备未初始化
\retval ::HI_ERR_IR_INVALID_POINT  The pointer is invalid.                      CNcomment:指针为空
\retval ::HI_ERR_IR_INVALID_PARA   The parameter is invalid.                    CNcomment:参数非法
\retval ::HI_ERR_IR_INVALID_ISKEYUP_ARG  The parameter of iskeyup is invalid    CNcomment:按键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_ISREPKEY_ARG  The parameter of isrepkey is invalid  CNcomment:重复键是否上报参数非法
\retval ::HI_ERR_IR_INVALID_CODETYPE  The code type is invalid.                 CNcomment:码型参数非法
\see \n
N/A
*/
HI_S32 HI_UNF_IR_Reset(HI_VOID);

/** 
\brief enable a infrared code.
CNcomment:\brief  激活某类红外遥控器协议。

\attention \n
?
\param N/A         CNcomment:无
\retval 0 Success  CNcomment:成功
\retval ::Others on fail. CNcomment:其他值失败。
\see \n
N/A
*/
HI_S32 HI_UNF_IR_EnableProtocol(HI_CHAR* pszProtocolName);

/** 
\brief disable a infrared code.
CNcomment:\brief  禁用某类红外遥控器协议。

\attention \n

\param N/A         CNcomment:无
\retval 0 Success  CNcomment:成功
\retval ::Others on fail. CNcomment:其他值失败。
\see \n
N/A
*/
HI_S32 HI_UNF_IR_DisableProtocol(HI_CHAR* pszProtocolName);

/** 
\brief get the enable or disable stat of  a infrared code.
CNcomment:\brief  获取某类红外遥控器协议激活状态。

\attention \n

\param N/A         CNcomment:无
\retval 0 Success  CNcomment:成功
\retval ::Others on fail. CNcomment:其他值失败。
\see \n
N/A
*/
HI_S32 HI_UNF_IR_GetProtocolEnabled(HI_CHAR* pszProtocolName, HI_BOOL *pbEnabled);


/** @} */  /** <!-- ==== API Declaration End ==== */


/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_7 */
/** @{ */  /** <!-- [WDG] */
/*---- wdg ----*/
/** 
\brief Starts the WDG device.
CNcomment:\brief 打开WDG（Watch Dog）设备。

\attention \n
By default, the WDG device is disabled after it is started. In this case, you need to call HI_UNF_WDG_Enable to enable it.\n
This API cannot be called repeatedly.
CNcomment:打开之后，WDG默认是禁止的，需要显式调用HI_UNF_WDG_Enable使能WDG设备\N
CNcomment:重复打开会失败。

\param N/A          CNcomment:无
\retval 0 Success   CNcomment:成功
\retval ::HI_ERR_WDG_NOT_INIT   The WDG device is not initialized.     CNcomment:WDG设备未初始化
\retval ::HI_ERR_WDG_INVALID_POINT  The WDG input pointer is invalid.  CNcomment:WDG输入指针无效
\retval ::HI_ERR_WDG_INVALID_PARA  The WDG input parameter is invalid. CNcomment:WDG输入参数无效
\see \n
N/A
*/
HI_S32 HI_UNF_WDG_Open(HI_VOID);


/** 
\brief Stops the WDG device.
CNcomment:\brief 关闭WDG设备。

\attention \n
This API cannot be called repeatedly.
CNcomment:重复关闭会失败。

\param N/A          CNcomment:无
\retval 0 Success   CNcomment:成功
\retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.      CNcomment:WDG设备未初始化
\retval ::HI_ERR_WDG_INVALID_POINT  The WDG input pointer is invalid.  CNcomment:WDG输入指针无效
\retval ::HI_ERR_WDG_INVALID_PARA  The WDG input parameter is invalid. CNcomment:WDG输入参数无效
\see \n
N/A
*/
HI_S32 HI_UNF_WDG_Close(HI_VOID);


/** 
\brief Enables the WDG device.
CNcomment:\brief 使能WDG设备。

\attention \n
You must call HI_UNF_WDG_Enable after the WDG device is started.
CNcomment:打开WDG设备后，必须显式调用使能接口。

\param N/A         CNcomment:无
\retval 0 Success  CNcomment:成功
\retval ::HI_ERR_WDG_NOT_INIT The WDG device is not initialized.       CNcomment:WDG设备未初始化
\retval ::HI_ERR_WDG_INVALID_POINT   The WDG input pointer is invalid. CNcomment:WDG输入指针无效
\retval ::HI_ERR_WDG_INVALID_PARA  The WDG input parameter is invalid. CNcomment:WDG输入参数无效
\see \n
N/A
*/
HI_S32 HI_UNF_WDG_Enable(HI_VOID);

/** 
\brief Disables the WDG device.
CNcomment:\brief 禁止WDG设备。

\attention \n
After calling this API, you cannot feed and reset the WDG.
CNcomment:调用此函数后，喂狗和复位操作不起作用。

\param N/A         CNcomment:无
\retval 0 Success  CNcomment:成功
\retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.      CNcomment:WDG设备未初始化
\retval ::HI_ERR_WDG_INVALID_POINT The WDG input pointer is invalid.   CNcomment:WDG输入指针无效
\retval ::HI_ERR_WDG_INVALID_PARA The WDG input parameter is invalid.  CNcomment:WDG输入参数无效
\see \n
N/A
*/
HI_S32 HI_UNF_WDG_Disable(HI_VOID);


/** 
\brief Obtains the interval of feeding the WDG.
CNcomment:\brief 获取喂狗时间间隔。

\attention \n
The interval precision is as high as 1000 ms.
CNcomment:时间间隔精确到1000ms。

\param[in] pu32Value  Interval of feeding the WDG, in ms              CNcomment:喂狗时间间隔，单位为ms
\retval 0 Success                                                     CNcomment:成功
\retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.     CNcomment:WDG 设备未初始化
\retval ::HI_ERR_WDG_INVALID_POINT  The WDG input pointer is invalid. CNcomment:WDG输入指针无效
\see \n
N/A
*/
HI_S32 HI_UNF_WDG_GetTimeout(HI_U32 *pu32Value);

/** 
\brief Sets the interval of feeding the WDG.
CNcomment:\brief 设置喂狗时间间隔。

\attention \n
N/A
\param[in] u32Value  Interval of feeding the WDG, in ms                CNcomment:喂狗时间间隔，单位为ms
\retval 0 Success                                                      CNcomment:成功
\retval ::HI_ERR_WDG_NOT_INIT The WDG device is not initialized.       CNcomment:WDG设备未初始化
\retval ::HI_ERR_WDG_INVALID_POINT The WDG input pointer is invalid.   CNcomment:WDG输入指针无效
\retval ::HI_ERR_WDG_INVALID_PARA  The WDG input parameter is invalid. CNcomment:WDG输入参数无效
\see \n
N/A
*/
HI_S32 HI_UNF_WDG_SetTimeout(HI_U32 u32Value);


/** 
\brief Feeds the WDG.
CNcomment:\brief 执行喂狗操作。

\attention \n
N/A
\param N/A                                                             CNcomment:无
\retval 0 Success                                                      CNcomment:成功
\retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.      CNcomment:WDG设备未初始化
\retval ::HI_ERR_WDG_INVALID_POINT  The WDG input pointer is invalid.  CNcomment:WDG输入指针无效
\retval ::HI_ERR_WDG_INVALID_PARA  The WDG input parameter is invalid. CNcomment:WDG输入参数无效
\see \n
N/A
*/
HI_S32 HI_UNF_WDG_ClearWatchDog (HI_VOID);

/** 
\brief Resets the entire system.
CNcomment:\brief 用于复位整个系统。

\attention \n
N/A
\param N/A        CNcomment:无
\retval 0 Success CNcomment:成功
\retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.      CNcomment:WDG设备未初始化
\retval ::HI_ERR_WDG_INVALID_POINT The WDG input pointer is invalid.   CNcomment:WDG输入指针无效
\retval ::HI_ERR_WDG_INVALID_PARA  The WDG input parameter is invalid. CNcomment:WDG输入参数无效
\see \n
N/A
*/
HI_S32 HI_UNF_WDG_Reset(HI_VOID);

/** @} */  /** <!-- ==== API Declaration End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_8 */
/** @{ */  /** <!-- [GPIO] */
/**---- GPIO----*/
/** 
\brief Starts the general-purpose input/output (GPIO) device.
CNcomment:\brief 打开GPIO（General Purpose Input/Output）设备。

\attention \n
This API can be called repeatedly.
CNcomment:重复打开会成功。

\param  N/A       CNcomment:无
\retval 0 Success CNcomment:成功
\retval ::HI_ERR_GPIO_NOT_INIT  The GPIO device is not initialized.  CNcomment:GPIO设备未初始化
\retval ::HI_ERR_GPIO_INVALID_POINT  The pointer is invalid.         CNcomment:指针为空
\retval ::HI_ERR_GPIO_INVALID_PARA  The parameter is invalid.        CNcomment:参数非法
\retval ::HI_ERR_GPIO_FAILED_SWITCH2LED  The peripheral function fails to be switched to the GPIO function.                 CNcomment:外设功能切换到GPIO功能操作失败
\retval ::HI_ERR_GPIO_FAILED_LED_DIRSET_BIT  The direction of the GPIO pin corresponding to the tuner LED fails to be set.  CNcomment:TUNER指示灯对应GPIO管脚方向设置失败
\retval ::HI_ERR_GPIO_FAILED_LED_WRITE_BIT  The GPIO pin corresponding to the tuner LED fails to be written.                CNcomment:写TUNER指示灯对应GPIO管脚操作失败
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_Open(HI_VOID);


/** 
\brief Stops the GPIO device.
CNcomment:\brief 关闭GPIO设备。

\attention \n
This API can be called repeatedly.
CNcomment:重复关闭会成功。
\param  N/A  CNcomment:无
\retval For details, see the definitions of error codes. CNcomment:请参考错误码定义章节
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_Close(HI_VOID);

/** 
\brief Reads data from a GPIO pin.
CNcomment:\brief 从GPIO单个引脚读取数据。

\attention The pin number is defined as follows: Pin number = GPIO group ID x 8 + GPIO pin ID in the group\n
For example, GPIO1_2 indicates pin 2 in group 1, and the pin number is 10 (1 x 8 + 2).\n
Both pin group ID and pin number are numbered from 0. Each HD chip provides GPIO pins number reference to HD chip hardware manual.\n
N/A
CNcomment:\attention 管脚号计算规则: 管脚号 = GPIO组号*8 + GPIO管脚在组内的遍号。\n
CNcomment:比如GPIO1_2,代表第1组第2脚，那么管脚号=1*8+2=10。\n
CNcomment:GPIO的组号和管脚号的编号都从0开始。高清芯片提供的gpio管脚数请参考相关的芯片硬件手册\n

\param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:管脚号，取值范围为0～103，不同的芯片类型范围不一样。
\param[out] pbHighVolt   Pointer to the input level of a pin  CNcomment:指针类型，返回管脚输入电平。
\retval   For details, see the definitions of error codes.    CNcomment:请参考错误码定义章节
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_ReadBit(HI_U32  u32GpioNo , HI_BOOL  *pbHighVolt );


/** 
\brief Writes data to a GPIO pin.
CNcomment:\brief 向GPIO单个引脚输出数据。
\attention \n
N/A
\param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:管脚号，取值范围为0～103，不同的芯片类型范围不一样。
\param[in] bHighVolt  Output level of a pin              CNcomment:管脚输出电平。
                      0: low level                       CNcomment:0: 低电平；
                      1: high level                      CNcomment:1：高电平；
                     Others: high level                  CNcomment:其他：高电平。
\retval  For details, see the definitions of error codes. CNcomment:请参考错误码定义章节
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_WriteBit(HI_U32  u32GpioNo , HI_BOOL     bHighVolt );


/** 
\brief Sets the direction (input or output) of a GPIO pin.
CNcomment:\brief 设置GPIO单个引脚输入输出方向。

\attention \n
When setting the operating mode of a GPIO pin, ensure that it works in GPIO mode only.\n
This is because the GPIO pin may be multiplexed.
CNcomment:设置对应管脚的工作方式时，必须保证该管脚仅工作在GPIO模式下\n
CNcomment:GPIO管脚有可能被复用。

\param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:管脚号，取值范围为0～103，不同的芯片类型范围不一样。
\param[in] bInput  Boolean variable that indicates the direction of a pin  CNcomment:布尔变量，标识管脚方向。
                   HI_TRUE: input pin  HI_TRUE：                           CNcomment:该管脚用于输入；
                   HI_FALSE: output pin HI_FALSE：                         CNcomment:该管脚用于输出。
\retval For details, see the definitions of error codes.                   CNcomment:请参考错误码定义章节
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_SetDirBit(HI_U32  u32GpioNo , HI_BOOL    bInput);


/** 
\brief Obtains the direction (input or output) of a GPIO pin.
CNcomment:\brief 获取GPIO单个引脚输入输出方向。

\attention \n
N/A
\param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:管脚号，取值范围为0～103，不同的芯片类型范围不一样。
\param[out] pbInput   Pointer to the boolean variable that indicates the direction of a pin  CNcomment:指针类型，指向布尔型变量，用来返回管脚方向。
\retval For details, see the definitions of error codes.                                     CNcomment:请参考错误码定义章节
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_GetDirBit(HI_U32  u32GpioNo , HI_BOOL    *pbInput);


/** 
\brief Starts the cipher device.
CNcomment:\brief 设置GPIO单个引脚的中断类型。

\attention \n
N/A
\param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:管脚号，取值范围为0～103，不同的芯片类型范围不一样。
\param[in] enIntType    interrupt type                                CNcomment:中断类型。
\retval    For details, see the definitions of error codes.           CNcomment:请参考错误码定义章节
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_SetIntType(HI_U32 u32GpioNo, HI_UNF_GPIO_INTTYPE_E enIntType);


/** 
\brief set GPIO single pin interrupt enable
CNcomment:\brief 设置GPIO单个引脚的中断使能。
\attention \n
N/A
\param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:管脚号，取值范围为0～103，不同的芯片类型范围不一样。
\param[in] bEnable  HI_TRUE: interrupt enable, HI_FALSE: interrupt disable CNcomment:HI_TRUE: 中断使能 ,HI_FALSE: 中断禁止。
\retval For details, see the definitions of error codes.                   CNcomment:请参考错误码定义章节
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_SetIntEnable(HI_U32 u32GpioNo, HI_BOOL bEnable); 


/** 
\brief query GPIO interrupt, report it if there is interrupter happen
CNcomment:\brief 查询GPIO中断，只要有GPIO中断就会上报上来 
\attention \n
N/A
\param[out] p32GpioNo    get interrupt pin number        CNcomment:获取中断的管脚号。
\param[in] u32TimeoutMs  get interrupt timeout           CNcomment:获取中断超时时间。
\retval For details, see the definitions of error codes. CNcomment:请参考错误码定义章节
\see \n
N/A
*/
HI_S32 HI_UNF_GPIO_QueryInt(HI_U32 *p32GpioNo, HI_U32 u32TimeoutMs);


/** @} */  /** <!-- ==== API declaration end ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_9 */
/** @{ */  /** <!-- [CIPHER] */
/* ---CIPHER---*/
/** 
\brief  Starts the cipher device.  CNcomment:打开CIPHER设备。
\attention \n
This API is used to start the cipher device. The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:调用此接口打开CIPHER设备。重复打开返回成功。
\param N/A                   CNcomment:无
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                                    CNcomment:API系统调用失败
\retval ::HI_ERR_CIPHER_FAILED_INIT  The cipher device fails to be initialized.  CNcomment:CIPHER设备初始化失败
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Open(HI_VOID);

/** 
\brief  Stops the cipher device.
CNcomment:\brief  关闭CIPHER设备。
\attention \n
This API is used to stop the cipher device. If this API is called repeatedly, HI_SUCCESS is returned, but only the first operation takes effect.
CNcomment:调用此接口关闭CIPHER设备。重复关闭返回成功，第一次起作用。

\param N/A                   CNcomment:无
\retval ::HI_SUCCESS Success  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                            CNcomment:API系统调用失败
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.  CNcomment:CIPHER设备未初始化
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Close(HI_VOID);

/** 
\brief Creates a cipher channel to obtain the cipher handle.
CNcomment:\brief 创建一路CIPHER，获取CIPHER句柄。

\attention \n
This API is used to obtain a cipher handle for encryption and decryption.
CNcomment:调用此接口获取1个CIPHER句柄，用于加解密。

\param[out] phCipher Cipher handle                                       CNcomment:CIPHER句柄。
\retval ::HI_SUCCESS Success                                             CNcomment: 成功
\retval ::HI_FAILURE  Calling this API fails.                            CNcomment: API系统调用失败
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.  CNcomment:CIPHER设备未初始化
\retval ::HI_ERR_CIPHER_INVALID_POINT  The pointer is null.              CNcomment:指针参数为空
\retval ::HI_ERR_CIPHER_FAILED_GETHANDLE  The cipher handle fails to be obtained, because there are no available cipher handles. CNcomment: 获取CIPHER句柄失败，没有空闲的CIPHER句柄

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_CreateHandle(HI_HANDLE* phCipher);

/** 
\brief Destroys existing cipher handles. CNcomment:销毁创建的CIPHER句柄。
\attention \n
This API is used to destroy existing cipher handles.
CNcomment:调用此接口销毁已经创建的CIPHER句柄。

\param[in] hCipher Cipher handle                 CNcomment:CIPHER句柄。
\retval ::HI_SUCCESS Success                     CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.    CNcomment:API系统调用失败
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized. CNcomment:CIPHER设备未初始化
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DestroyHandle(HI_HANDLE hCipher);

/** 
\brief Configures the cipher control information.
CNcomment:\brief 配置CIPHER控制信息

\attention \n
Before encryption or decryption, you must call this API to configure the cipher control information.
The first 64-bit data and the last 64-bit data should not be the same when using TDES algorithm.
CNcomment:进行加密解密前必须先使用此接口配置CIPHER的控制信息。使用TDES算法时，输入密钥的前后64 bit数据不能相同。

\param[in] hCipher Cipher handle                                        CNcomment:CIPHER句柄。
\param[in] pstCtrl Cipher control information                           CNcomment:CIPHER控制信息。
\retval ::HI_SUCCESS Success                                            CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment:API系统调用失败
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized. CNcomment:CIPHER设备未初始化
\retval ::HI_ERR_CIPHER_INVALID_POINT  The pointer is null.             CNcomment:指针参数为空
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.         CNcomment:参数错误
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.          CNcomment:句柄非法
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_ConfigHandle(HI_HANDLE hCipher, HI_UNF_CIPHER_CTRL_S* pstCtrl);

/** 
\brief Performs encryption. 
CNcomment:\brief 进行加密 

\attention \n
This API is used to perform encryption by using the cipher module.
The length of the encrypted data should be a multiple of 8 in TDES mode and 16 in AES mode. Besides, the length can not be bigger than 0xFFFFF.
CNcomment:使用CIPHER进行加密操作。TDES模式下加密的数据长度应当是8的倍数，AES下应当是16的倍数。此外，加密数据长度不能长于0xFFFFF。
    After this operation, the result will affect next operation
    if you want to remove vector, you need to config IV(config pstCtrl->stChangeFlags.bit1IV with 1) by transfering HI_UNF_CIPHER_ConfigHandle
    CNcomment: 本次操作完成后，此次操作的向量运算结果会作用于下一次操作，
    CNcomment:如果要清除向量，需要在下次加密操作之前调用HI_UNF_CIPHER_ConfigHandle重新配置IV(需要设置pstCtrl->stChangeFlags.bit1IV为1),
\param[in] hCipher Cipher handle  CNcomment:CIPHER句柄。
\param[in] u32SrcPhyAddr Physical address of the source data            CNcomment:源数据物理地址。
\param[in] u32DestPhyAddr Physical address of the target data           CNcomment:目的数据物理地址。
\param[in] u32ByteLength   Length of the encrypted data                 CNcomment:加密数据长度。
\retval ::HI_SUCCESS  Success                                           CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment:API系统调用失败
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized. CNcomment:CIPHER设备未初始化
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.         CNcomment:参数错误
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.          CNcomment:句柄非法
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Encrypt(HI_HANDLE hCipher, HI_U32 u32SrcPhyAddr, HI_U32 u32DestPhyAddr, HI_U32 u32ByteLength);

/** 
\brief Performs encryption.
CNcomment:\brief 进行加密

\attention \n
This API is used to perform decryption by using the cipher module.
The length of the decrypted data should be a multiple of 8 in TDES mode and 16 in AES mode. Besides, the length can not be bigger than 0xFFFFF.
CNcomment:使用CIPHER进行解密操作。TDES模式下解密的数据长度应当是8的倍数，AES下应当是16的倍数。此外，解密数据长度不能长于0xFFFFF。
    After this operation, the result will affect next operation
    if you want to remove vector, you need to config IV(config pstCtrl->stChangeFlags.bit1IV with 1) by transfering HI_UNF_CIPHER_ConfigHandle
CNcomment:本次操作完成后，此次操作的向量运算结果会作用于下一次操作，
 CNcomment:如果要清除向量，需要在下次解密操作之前调用HI_UNF_CIPHER_ConfigHandle重新配置IV(需要设置pstCtrl->stChangeFlags.bit1IV为1),
\param[in] hCipher Cipher handle                                        CNcomment:CIPHER句柄。
\param[in] u32SrcPhyAddr Physical address of the source data            CNcomment:源数据物理地址。
\param[in] u32DestPhyAddr Physical address of the target data           CNcomment:目的数据物理地址。
\param[in] u32ByteLength Length of the decrypted data                   CNcomment:解密数据长度。
\retval ::HI_SUCCESS Success                                            CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment:API系统调用失败
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized. CNcomment:CIPHER设备未初始化
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.         CNcomment:参数错误
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.          CNcomment:句柄非法
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Decrypt(HI_HANDLE hCipher, HI_U32 u32SrcPhyAddr, HI_U32 u32DestPhyAddr, HI_U32 u32ByteLength);


/** 
\brief encrypt to multi data package
CNcomment:\brief 进行多个包数据的加密
\attention \n
you can not cipher to more than 128 data package once time
when HI_ERR_CIPHER_BUSY return, the data package you send will not be deal, the custmer should decrease the number of data package or cipher again
note:The operation to more than one data package, every one will calculate usint vector configed by HI_UNF_CIPHER_ConfigHandle
     The font result will not affect the later result 
CNcomment:每次加密的数据包个数最多不能超过128个。
CNcomment:返回HI_ERR_CIPHER_BUSY的时候，送入数据包一个也不会被处理，用户需要减少送入的数据包的数量或者再次尝试加密。
CNcomment:   注意: 对于多个包的操作，每个包都使用HI_UNF_CIPHER_ConfigHandle配置的向量进行运算，
CNcomment:    前一个包的向量运算结果不会作用于下一个包的运算，每个包都是独立运算的。
CNcomment:    前一次函数调用的结果也不会影响后一次函数调用的运算结果。
\param[in] hCipher CIPHER handle                                                                  CNcomment:CIPHER句柄。
\param[in] pstDataPkg data package ready for cipher                                               CNcomment:待加密的数据包。
\param[in] u32DataPkgNum  number of package ready for cipher                                      CNcomment:待加密的数据包个数。
\retval ::HI_SUCCESS   success                                                                    CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                                                    CNcomment:API系统调用失败
\retval ::HI_ERR_CIPHER_NOT_INIT  CIPHER device have not been initialized                         CNcomment:CIPHER设备未初始化
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                             CNcomment:参数错误
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                            CNcomment:句柄非法
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time   CNcomment:硬件正忙，无法一次性处理全部的数据包
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_EncryptMulti(HI_HANDLE hCipher, HI_UNF_CIPHER_DATA_S *pstDataPkg, HI_U32 u32DataPkgNum);


/** 
\brief decrypt to multi data package
CNcomment:\brief 进行多个包数据的解密
\attention \n
you can not decrypt to more than 128 data package once time
when HI_ERR_CIPHER_BUSY return, the data package you send will not be deal, the custmer should decrease the number of data package or decrypt again
note:The operation to more than one data package, every one will calculate usint vector configed by HI_UNF_CIPHER_ConfigHandle
     The font result will not affect the later result 
CNcomment:每次解密的数据包个数最多不能超过128个。
CNcomment:返回HI_ERR_CIPHER_BUSY的时候，送入数据包一个也不会被处理，用户需要减少送入的数据包的数量或者再次尝试解密。
CNcomment:    注意: 对于多个包的操作，每个包都使用HI_UNF_CIPHER_ConfigHandle配置的向量进行运算，
CNcomment:    前一个包的向量运算结果不会作用于下一个包的运算，每个包都是独立运算的。
CNcomment:    前一次函数调用的结果也不会影响后一次函数调用的运算结果。
\param[in] hCipher CIPHER handle                                                                 CNcomment:CIPHER句柄。
\param[in] pstDataPkg data package ready for cipher                                              CNcomment:待解密的数据包。
\param[in] u32DataPkgNum  number of package ready for cipher                                     CNcomment:待解密的数据包个数。
\retval ::HI_SUCCESS success                                                                     CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                                                    CNcomment:API系统调用失败
\retval ::HI_ERR_CIPHER_NOT_INIT  CIPHER device have not been initialized                        CNcomment:CIPHER设备未初始化
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                            CNcomment:参数错误
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                           CNcomment:句柄非法
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time  CNcomment:硬件正忙，无法一次性处理全部的数据包
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DecryptMulti(HI_HANDLE hCipher, HI_UNF_CIPHER_DATA_S *pstDataPkg, HI_U32 u32DataPkgNum);

/** 
\brief Get the random number.
CNcomment:\brief 获取随机数

\attention \n
This API is used to obtain the random number from the hardware.
CNcomment:调用此接口用于获取逻辑层的随机数

\param[out] pu32RandomNumber The random number                           CNcomment:随机数数值。
\retval ::HI_SUCCESS Success                                             CNcomment: 成功
\retval ::HI_FAILURE  Calling this API fails.                            CNcomment: API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_GetRandomNumber(HI_U32 *pu32RandomNumber);

/** 
\brief Get the AES CBC-MAC.
CNcomment:\brief 获取AES CBC-MAC

\attention \n
This API is used to obtain the AES CBC-MAC.
CNcomment:调用此接口用于获取AES CBC-MAC

\param[in] hCipherHandle The cipher handle                        CNcomment:Cipher句柄
                 pInputData: input data                                     CNcomment:输入数据
                 u32InputDataLen: input data length,                  CNcomment:输入数据的长度，如果不是最后一个block，则必须为16个byte的倍数 
                 the length should be multiple of 16 bytes if it is not the last block
                 bIsLastBlock: is last block                                CNcomment:是否最后一个block
\param[out] pOutputMAC: output CBC-MAC                          CNcomment:输出的CBC-MAC                 
\retval ::HI_SUCCESS Success                                             CNcomment: 成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment: API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_CalcMAC(HI_HANDLE hCipherHandle, HI_U8 *pInputData, HI_U32 u32InputDataLen,
                                        HI_U8 *pOutputMAC, HI_BOOL bIsLastBlock);

/** 
\brief Init the hash module, if other program is using the hash module, the API will return failure.
CNcomment:\brief 初始化HASH模块，如果有其他程序正在使用HASH模块，返回失败状态

\attention \n
无.
CNcomment:NONE

\param[in] eShaType Hash type                                           CNcomment:hash类型
                 u32TotalDataLen: the total length of data to calculate the hash  CNcomment:用于计算hash的数据的总长度
 \param[out] pHashHandle: the output hash handle               CNcomment:输出的hash句柄
\retval ::HI_SUCCESS Success                                             CNcomment: 成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment: API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashInit(HI_UNF_CIPHER_HASH_TYPE_E eShaType, HI_U32 u32TotalDataLen, HI_HANDLE *pHashHandle);


/** 
\brief Calculate the hash, if the size of the data to be calculated is very big and the DDR ram is not enough, this API can 
calculate the data one block by one block
CNcomment:\brief 计算hash值，如果需要计算的数据量比较大，该接口可以
实现一个block一个block的计算，避免数据量比较大的情况下，内存不足的问题

\attention \n
无
CNcomment:NONE

\param[in] hHashHandle Hash 句柄                                  CNcomment:hash handle
               pu8InputData: 输入数据缓冲                   CNcomment:the input data buffer
               u32InputDataLen:输入数据的长度         CNcomment:the input data length
\retval ::HI_SUCCESS Success                                             CNcomment: 成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment: API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashUpdate(HI_HANDLE hHashHandle, HI_U8 *pu8InputData, HI_U32 u32InputDataLen);



/** 
\brief Get the final hash value, after calculate all of the data, call this API to get the final hash value and close the handle.
If there is some reason need to interupt the calculation, this API should also be call to close the handle
CNcomment:\brief 获取hash值，在计算完所有的数据后，调用这个接口获取最终的
hash值，该接口同时会关闭hash句柄。如果在计算过程中，需要中断计算，也
必须调用该接口关闭hash句柄

\attention \n
无
CNcomment:NONE

\param[in] hHashHandle Hash 句柄                                  CNcomment:hash handle
\param[out] pu8OutputHash 输出的hash值                   CNcomment:the final output hash value

\retval ::HI_SUCCESS Success                                             CNcomment: 成功
\retval ::HI_FAILURE  Calling this API fails.                           CNcomment: API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashFinal(HI_HANDLE hHashHandle, HI_U8 *pu8OutputHash);



/** @} */  /** <!-- ==== API declaration end ==== */


/******************************* API Declaration *****************************/
/** \addtogroup      H_1_4_10 */
/** @{ */  /** <!-- [TUNER] */
/*---TUNER---*/
/** 
\brief Initializes the tuner.
CNcomment:\brief 初始化TUNER设备。

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:支持重复初始化TUNER设备，此时直接返回成功。
\param N/A                                    CNcomment:无
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Init(HI_VOID);


/** 
\brief Deinitializes the tuner.
CNcomment:\brief 去初始化TUNER设备。

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:支持重复去初始化TUNER设备，此时直接返回成功。
\param  N/A                    CNcomment:无
\retval ::HI_SUCCESS Success   CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DeInit(HI_VOID);


/**
\brief  Obtains the default attributes of the tuner. 
CNcomment:\brief  获取TUNER的默认属性。
\attention \n
This API is available only after the tuner is initialized.
CNcomment:此接口在TUNER设备初始化后才能使用。
\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.             CNcomment:TUNER端口号，取值为0-2。
\param[out] pstTunerAttr The default attributes of the tuner are returned. CNcomment:返回当前TUNER的默认属性。
\retval ::HI_SUCCESS Success                                               CNcomment: 成功
\retval ::HI_FAILURE Calling this API fails.                               CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetDeftAttr(HI_U32  u32tunerId , HI_UNF_TUNER_ATTR_S *pstTunerAttr );


/** 
\brief Sets the current attributes of the tuner.
CNcomment:\brief 设置TUNER当前属性。
\attention \n
N/A
\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.      CNcomment:TUNER端口号，取值为0-2
\param[in] pstTunerAttr tuner attributes                            CNcomment:TUNER的属性。
\retval ::HI_SUCCESS Success                                        CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                       CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetAttr(HI_U32  u32tunerId , const HI_UNF_TUNER_ATTR_S *pstTunerAttr );


/** 
\brief Obtains the attributes of the tuner.
CNcomment:\brief 获取TUNER的属性。

\attention \n
This API is available only after the tuner is initialized.
CNcomment:此接口在TUNER设备初始化后才能使用。

\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.                CNcomment:TUNER端口号，取值为0-2
\param[out] pstTunerAttr   The current attributes of the tuner are returned. CNcomment:返回当前TUNER的属性。
\retval ::HI_SUCCESS Success                                                 CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                                CNcomment: API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetAttr(HI_U32  u32tunerId , HI_UNF_TUNER_ATTR_S *pstTunerAttr );


/** 
\brief Starts the tuner.
CNcomment:\brief 打开TUNER设备。

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:支持重复打开TUNER设备。此时，直接返回成功。

\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.      CNcomment:TUNER端口号，取值为0-2
\retval ::HI_SUCCESS Success                                        CNcomment:成功
\retval ::HI_FAILURE Calling this API fails.                        CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Open (HI_U32    u32tunerId);


/** 
\brief Stops the tuner.
CNcomment:\brief 关闭TUNER设备。

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:支持重复关闭TUNER设备。此时，直接返回成功。

\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.     CNcomment:TUNER端口号，取值为0-2 
\retval ::HI_SUCCESS Success                                      CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                     CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Close(HI_U32    u32tunerId);


/** 
\brief Locks the frequency of the tuner.
CNcomment:\brief TUNER锁频。
\attention \n
N/A
\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.             CNcomment:TUNER端口号，取值为0-2
\param[in] pstConnectPara   Information about the frequency of the tuner  CNcomment:TUNER的频点信息。
\param[in] u32TimeOut  Wait timeout (in ms) when the frequency of the tuner is locked. The value 0 indicates no wait, and any other value indicates the maximum wait period.  CNcomment:TUNER的锁定等待超时时间，0为不等待，其他为最长等待时间，单位ms。
\retval ::HI_SUCCESS Success                                              CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                             CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Connect(HI_U32  u32tunerId , const HI_UNF_TUNER_CONNECT_PARA_S  *pstConnectPara,HI_U32 u32TimeOut);


/** 
\brief Obtains the frequency locking status and parameters of the tuner.
CNcomment:\brief 获取TUNER锁频状态和锁频参数。
\attention \n
N/A
\param[in] u32tunerId tuner port ID. The port ID can be 0-2.             CNcomment:TUNER端口号，取值为0-2
\param[in] u32TimeOut frequency locking timeout, unit: ms, frequency locking time is related to strength of signal CNcomment:锁频的超时时间，单位是毫秒，锁频时间和信号强度有关系。
               if you want to get the state of locking, the u32TimeOut should be set 100ms at least;
               if the u32TimeOut is 0, just config register without locking state, return HI_SUCCESS
               CNcomment: 如果想得到锁定状态，锁频超时最小设置为100ms；
               CNcomment: 如果超时时间为0，只配置寄存器，不判定锁定状态，返回HI_SUCCESS。
\param[out] pstTunerStatus: The current frequency locking status and parameters of the tuner are returned. Note: This parameter is valid only when HI_SUCCESS is returned.  CNcomment: 返回当前TUNER的锁频状态和锁频参数。 注意：此参数只在函数返回成功的情况下才有意义。
\retval ::HI_SUCCESS Success                    CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.  CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetStatus(HI_U32    u32tunerId , HI_UNF_TUNER_STATUS_S  *pstTunerStatus);


/** 
\brief Obtains the current bit error rate (BER) of the tuner. The BER is expressed by using the scientific notation.
CNcomment:\brief 获取当前TUNER 的误码率，用科学计数法表示。
\attention \n
N/A
\param[in] u32tunerId tuner port ID. The port ID can be 0-2.             CNcomment:TUNER端口号，取值为0-2
\param[out] pu32BER  Pointer to the current BER of the tuner The error bit rate consists of three elements. Their definitions are as follows:
                      Their definitions are as follows:
                    pu32BER[0]: integral part of the base number of the BER
                    pu32BER[1]: decimal part of the base number of the BER x 1000
                    pu32BER[2]: absolute value of the exponential of the BER
                    For example, if the BER is 2.156E-7, the values of the three elements are
                    2, 156, and 7 respectively.
                    The three elements are valid only when HI_SUCCESS is returned.
                    Otherwise, the application layer sets a large value as required, for example, 0.5 (the values of the three elements are 5, 0, and 1 respectively).
                         0.5 (the values of the three elements are 5, 0, and 1 respectively).
CNcomment:\param[out] pu32BER  指向当前TUNER 误码率的指针。该指针指向一个包含三个元素的数组，三个元素含义如下:
CNcomment:                    pu32BER[0]:误码率底数的整数部分
CNcomment:                    pu32BER[1]:误码率底数的小数部分乘以1000
CNcomment:                    pu32BER[2]:误码率指数部分取绝对值
CNcomment:                    例如:误码率为2.156E-7，那么三个元素的取值分别为
CNcomment:                    2、156和7
CNcomment:                    这三个元素只在函数返回成功的情况下才有意义，
CNcomment:                    否则应用层可根据实际情况自行设置一个较大值(比如0.5，即三个元素分别为5、0、1)。
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE Calling this API fails.  CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetBER(HI_U32   u32tunerId , HI_U32 *pu32BER);


/** 
\brief Obtains the current signal-to-noise ratio (SNR) of the tuner.
CNcomment:\brief 获取当前TUNER 的信噪比。
\attention \n
N/A
\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[out] pu32SNR  Pointer to the current SNR of the tuner
                    The value of *pu32SNR ranges from 22 to 51.
                    This parameter is valid only when HI_SUCCESS is returned.
                   Otherwise, the application layer sets the parameter to a small value.
CNcomment:\param[out] pu32SNR  指向当前TUNER信噪比的指针。
CNcomment:                    *pu32SNR取值范围为22 ~ 51
CNcomment:                    此参数只在函数返回成功的情况下才有意义，
CNcomment:                    否则，应用层可将此值设置为最小值。
\retval ::HI_SUCCESS Success                   CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.  CNcomment:API系统调用失败

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSNR(HI_U32   u32tunerId , HI_U32 *pu32SNR );             /* range : 0-255  */


/** 
\brief Obtains the current signal strength of the tuner.
CNcomment:\brief 获取当前TUNER的信号强度。
\attention \n
N/A
\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[out] pu32SignalStrength  Pointer to the current signal strength of the tuner
                            For cable signal, the value of *pu32SignalStrength ranges from 20~120.
                            For satellite signal, the value is 15~130，unit in dBuv.
                  This parameter is valid only when HI_SUCCESS is returned.
                  Otherwise, the application layer sets the parameter to a small value.
CNcomment:\param[out] pu32SignalStrength  指向当前TUNER信号强度的指针。
CNcomment:                  对于Cable信号，*pu32SignalStrength的取值范围为20~120
CNcomment:                  对于Satellite信号，*pu32SignalStrength的取值范围为15~130，单位为dBuv
CNcomment:                  此参数只在函数返回成功的情况下才有意义，
CNcomment:                  否则，应用层可将此值设置为最小值。
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSignalStrength(HI_U32   u32tunerId , HI_U32 *pu32SignalStrength );

/**
\brief Obtains the current signal quality of the tuner, returns a percentage value. 
CNcomment:\brief 获取当前TUNER的信号质量，返回百分比。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[out] pu32SignalQuality   Output pointer.                       CNcomment:指向信号质量的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSignalQuality(HI_U32 u32TunerId, HI_U32 *pu32SignalQuality);

/**
\brief Obtains the actual frequency and symbol rate of the current tuner for cable and satellite
signal, for terrestrial signal, symbol rate means nothing, ignore it. 
CNcomment:\brief 获取当前TUNER的实际频率和符号率。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[out] pu32Freq   Pointer to the current frequency of the tuner. CNcomment:指向当前TUNER频点的指针。
\param[out] pu32Symb   Points to the current symbol rate.             CNcomment:指向当前符号率               
\retval ::HI_SUCCESS Success                                          CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                         CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetRealFreqSymb( HI_U32 u32TunerId, HI_U32 *pu32Freq, HI_U32 *pu32Symb );

/**
\brief Obtains current signal information of the TUNER, used in satellite and terrestrial, not necessary for cable. 
CNcomment:\brief 获取当前TUNER的信号信息。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[out] pstSignalInfo Pointer to a signal info structure.         CNcomment:指向信号信息结构体的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSignalInfo(HI_U32 u32TunerId, HI_UNF_TUNER_SIGNALINFO_S *pstSignalInfo);

/**
\brief Sets the LNB parameter. 
CNcomment:\brief 设置LNB参数。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstLNB      Pointer to a LNB parameter structure.          CNcomment:指向LNB参数结构体的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetLNBConfig(HI_U32 u32TunerId, const HI_UNF_TUNER_FE_LNB_CONFIG_S *pstLNB);

/**
\brief Sets the LNB power. 
CNcomment:\brief 设置LNB供电。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] enLNBPower  The enumeration of the LNB power type.         CNcomment:LNB供电方式枚举值。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetLNBPower(HI_U32 u32TunerId, HI_UNF_TUNER_FE_LNB_POWER_E enLNBPower, HI_UNF_TUNER_FE_POLARIZATION_E enPolar);

/**
\brief Sets PLP ID, only used in DVB-T2. 
CNcomment:\brief 设置物理层管道ID。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] u8PLPID  The PLP ID.         CNcomment:物理层管道ID。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/

HI_S32 HI_UNF_TUNER_SetPLPID(HI_U32 u32TunerId, HI_U8 u8PLPID);

/**
\brief Gets PLP number, only used in DVB-T2. 
CNcomment:\brief 获取物理层管道数量。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[out] pu8PLPNum  The PLP number.         CNcomment:物理层管道数量。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/

HI_S32 HI_UNF_TUNER_GetPLPNum(HI_U32 u32TunerId, HI_U8 *pu8PLPNum);


/**
\brief Gets current PLP type, only used in DVB-T2. 
CNcomment:\brief 获取当前物理层管道类型。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[out] penPLPType  The PLP type.         CNcomment:物理层管道类型。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/

HI_S32 HI_UNF_TUNER_GetCurrentPLPType(HI_U32 u32TunerId, HI_UNF_TUNER_T2_PLP_TYPE_E *penPLPType);


/**
\brief Starts blind scan. 
CNcomment:\brief 开始盲扫。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to the blind scan parameter.       CNcomment:指向盲扫参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see Please refer to definition of HI_UNF_TUNER_BLINDSCAN_PARA_S.
N/A
*/
HI_S32 HI_UNF_TUNER_BlindScanStart(HI_U32 u32TunerId, const HI_UNF_TUNER_BLINDSCAN_PARA_S *pstPara);

/**
\brief Stops blind scan. 
CNcomment:\brief 停止盲扫。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_BlindScanStop(HI_U32 u32TunerId);

/**
\brief TUNER standby. 
CNcomment:\brief TUNER待机
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Standby(HI_U32 u32TunerId);

/**
\brief Wakes up TUNER. 
CNcomment:\brief TUNER唤醒
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_WakeUp( HI_U32 u32TunerId);

/**
\brief Disables TUNER, the tuner will be the high impedance state. You need call it when 2 or more demods share
the same TS interface, let indicated tuner release the TS interface so other ones can use it.
CNcomment:\brief TUNER不使能，tuner将进入高阻抗状态，用于多路Demod走同一个TS口时，高阻态以避免TS冲突
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Disable(HI_U32 u32TunerId);

/**
\brief Enables TUNER, cancels disable state.
CNcomment:\brief TUNER使能
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Enable(HI_U32 u32TunerId);

/**
\brief Sends and receives DiSEqC message, only the devices supporting DiSEqC 2.x support receive message. 
CNcomment:\brief 发送接收DiSEqC消息，仅支持DiSEqC 2.x的设备支持接收消息。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstSendMsg  The pointer to a sending message structure.    CNcomment:指向发送消息结构体的指针。
\param[out] pstRecvMsg The pointer to a receiving message structure.If your device is DiSEqC 1.x, you can pass NULL here.
CNcomment:\param[out] pstRecvMsg 指向接收消息结构体的指针。如果是DiSEqC 1.x设备，这里可以传NULL。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
/*HI_S32 HI_UNF_TUNER_DISEQC_SendRecvMessage(HI_U32 u32TunerId,
                                           HI_UNF_TUNER_DISEQC_SENDMSG_S* pstSendMsg,
                                           HI_UNF_TUNER_DISEQC_RECVMSG_S* pstRecvMsg);*/

/**
\brief Sets 0/12V switch. Don't support now. 
CNcomment:\brief 设置0/12V开关状态，暂不支持。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] enPort      The enumeration of the switch port.            CNcomment:开关枚举值。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Switch012V(HI_U32 u32TunerId, HI_UNF_TUNER_SWITCH_0_12V_E enPort);

/**
\brief Sets 22KHz switch. 
CNcomment:\brief 设置22KHz开关状态。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] enPort      The enumeration of the switch port.            CNcomment:开关枚举值。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Switch22K(HI_U32 u32TunerId, HI_UNF_TUNER_SWITCH_22K_E enPort);

/**
\brief Sets tone burst switch. 
CNcomment:\brief 设置Tone burst开关状态。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] enStatus    The enumeration of the switch port.            CNcomment:开关枚举值。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SwitchToneBurst(HI_U32 u32TunerId, HI_UNF_TUNER_SWITCH_TONEBURST_E enStatus);

HI_S32 HI_UNF_TUNER_SetAntennaPower(HI_U32 u32TunerId, HI_BOOL bPower);
#ifdef DISEQC_SUPPORT
/**
\brief Sets DiSEqC 1.0/2.0 switch, at most 4 port.
CNcomment:\brief 设置DiSEqC 1.0/2.0开关，至多4口。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to a switch parameter structure.   CNcomment:指向开关参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see Please refer to definition of HI_UNF_TUNER_DISEQC_SWITCH4PORT_S.
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Switch4Port(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_SWITCH4PORT_S* pstPara);

/**
\brief Sets DiSEqC 1.1/2.1 switch, supports 8in1, 16in1 switches. 
CNcomment:\brief 设置DiSEqC 1.1/2.1开关，支持8口，16口开关。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to a switch parameter structure.   CNcomment:指向开关参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Switch16Port(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_SWITCH16PORT_S* pstPara);

/**
\brief Lets the DiSEqC motor store current position. 
CNcomment:\brief DiSEqC马达存储当前位置。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to a position parameter structure. CNcomment:指向位置参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_StorePos(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_POSITION_S *pstPara);

/**
\brief Lets the DiSEqC motor move to stored position. 
CNcomment:\brief DiSEqC马达转动至存储位置。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to a position parameter structure. CNcomment:指向位置参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_GotoPos(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_POSITION_S *pstPara);

/**
\brief Enables or disables the DiSEqC motor's limit setting. 
CNcomment:\brief 打开、关闭DiSEqC马达权限设置。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to a limit parameter structure.    CNcomment:指向limit参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_SetLimit(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_LIMIT_S* pstPara);

/**
\brief Drives DiSEqC motor. 
CNcomment:\brief 驱动DiSEqC马达移动。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to a movement parameter structure. CNcomment:指向移动参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Move(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_MOVE_S* pstPara);

/**
\brief Halts DiSEqC motor. 
CNcomment:\brief 停止DiSEqC马达移动。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] enLevel     The command level of the DiSEqC motor.         CNcomment:马达支持的命令等级。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Stop(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_LEVEL_E enLevel);

/**
\brief Lets the DiSEqC motor recalculate its stored positions. 
CNcomment:\brief 重新计算马达存储位置。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to a recaulculate parameter structure. CNcomment:指向重计算参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Recalculate(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_RECALCULATE_S* pstPara);

/**
\brief Calculates the angular, basing on site-longitude, site-latitude and satellite-longitude. 
CNcomment:\brief USALS根据当地经纬度、卫星经度计算卫星角度。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in/out] pstPara The pointer to a USALS parameter structure.    CNcomment:指向USALS计算参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_CalcAngular(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_USALS_PARA_S* pstPara);

/**
\brief Gotos the indicated angular. 
CNcomment:\brief USALS设备转至某角度。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] pstPara     The pointer to a USALS angular structure.      CNcomment:指向USALS角度参数的指针。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_GotoAngular(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_USALS_ANGULAR_S* pstPara);

/**
\brief Resets DiSEqC device. 
CNcomment:\brief 复位DiSEqC设备。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] enLevel     The command level of the DiSEqC device.        CNcomment:设备支持的命令等级。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Reset(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_LEVEL_E enLevel);

/**
\brief DiSEqC device standby. 
CNcomment:\brief DiSEqC设备待机。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] enLevel     The command level of the DiSEqC device.        CNcomment:设备支持的命令等级。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Standby(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_LEVEL_E enLevel);

/**
\brief Wakes up DiSEqC device. 
CNcomment:\brief 唤醒DiSEqC设备。
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER端口号，取值为0-2
\param[in] enLevel     The command level of the DiSEqC device.        CNcomment:设备支持的命令等级。
\retval ::HI_SUCCESS   Success                                        CNcomment:成功
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_WakeUp(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_LEVEL_E enLevel);
#endif /* DISEQC_SUPPORT */

/**
\brief write HDCP KEY
CNcomment:\brief 写入HDCP KEY 
\attention \n
config just one time and can not be rework
HI_UNF_HDCP_SetHDCPKey is a new function
HI_UNF_ADVCA_SetHDCPKey is the old function used in font version
CNcomment: 仅能设置一次 不可更改
CNcomment: HI_UNF_HDCP_SetHDCPKey 为新的接口，
CNcomment: HI_UNF_ADVCA_SetHDCPKey为以前版本兼容接口

\param[in] stHdcpKey    HDCP key parameter                   CNcomment:HDCP key参数\n
\retval ::HI_SUCCESS    success                              CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails.                CNcomment:API系统调用失败
\retval ::HI_ERR_CA_NOT_INIT  CA has not been initialized    CNcomment:CA未初始化
\retval ::HI_ERR_CA_SETPARAM_AGAIN  repeat setting parameter CNcomment:重复设置参数
\see \n
::HI_UNF_OTP_HDCPKEY_S
*/
HI_S32 HI_UNF_HDCP_SetHDCPKey(HI_UNF_OTP_HDCPKEY_S stHdcpKey);
HI_S32 HI_UNF_ADVCA_SetHDCPKey(HI_UNF_ADVCA_HDCPKEY_S stHdcpKey);
HI_S32 HI_UNF_HDCP_GetKeyBurnFlag(HI_BOOL *pbKeyBurnFlag);
/** 
\brief Starts an OTP device.
CNcomment:\brief 打开OTP设备
\attention \n
N/A
\param N/A                                    CNcomment:无
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_Open(HI_VOID);

/** 
\brief Stops an OTP device.
CNcomment:\brief 关闭OTP设备
\attention \n
N/A
\param N/A                                    CNcomment:无
\retval ::HI_SUCCESS Success                  CNcomment:成功
\retval ::HI_FAILURE  Calling this API fails. CNcomment:API系统调用失败
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_Close(HI_VOID);

/** 
\brief      Set customer key, the customer key is used by the customer to encrypt some private data
\attention \n
N/A
\param[in] pKey              customer key to be written to OTP    
\param[in] u32KeyLen         the length of customer key, must be 16bytes          
\retval ::HI_SUCCESS           success                            
\retval ::HI_FAILURE            fail                              
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_SetCustomerKey(HI_U8 *pKey, HI_U32 u32KeyLen);

/** 
\brief      Get customer key, the customer key is used by the customer to encrypt some private data
\attention \n
N/A
\param[in] pKey              buffer to store the customer key read from OTP
\param[in] u32KeyLen         the length of buffer, must be 16bytes 
\retval ::HI_SUCCESS           success
\retval ::HI_FAILURE            fail
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetCustomerKey(HI_U8 *pKey, HI_U32 u32KeyLen);

/** 
\brief      Set stb private data, the stb private data is used by the customer to set some private data
\attention \n
N/A
\param[in] u32Offset      the offset to set the private data, should be between 0 and 15    
\param[in] u8Data          the private data          
\retval ::HI_SUCCESS    success                            
\retval ::HI_FAILURE      fail                              
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_SetStbPrivData(HI_U32 u32Offset, HI_U8 u8Data);

/** 
\brief      Get stb private data, the stb private data is used by the customer to set some private data
\attention \n
N/A
\param[in] u32Offset            the offset to set the private data, should be between 0 and 15
\param[out] pu8Data            the data read from OTP  
\retval ::HI_SUCCESS         success
\retval ::HI_FAILURE            fail
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetStbPrivData(HI_U32 u32Offset, HI_U8 *pu8Data);


/** @} */  /** <!-- ==== API declaration end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      H_1_4_12 */
/** @{ */  /** <!-- [CI]*/

/** 
\brief CI init
CNcomment:\brief CI初始化 
\attention \n
N/A
\param    N/A                                         CNcomment:无
\retval ::HI_SUCCESS              success             CNcomment: 成功
\retval ::HI_FAILURE              fail                CNcomment:失败
\retval ::HI_ERR_CI_OPEN_ERR      opening file fail   CNcomment:打开文件失败
\see \n
N/A
*/
HI_S32 HI_UNF_CI_Init(HI_VOID);

/** 
\brief CI deinit
CNcomment:\brief CI去初始化 
\attention \n
N/A
\param  N/A                                              CNcomment:无
\retval ::HI_SUCCESS             success                 CNcomment:成功
\retval ::HI_FAILURE             fail                    CNcomment:失败
\retval ::HI_ERR_CI_CLOSE_ERR    closing file fail       CNcomment:关闭文件失败
\see \n
N/A
*/
HI_S32 HI_UNF_CI_DeInit(HI_VOID);

/** 
\brief Sets CI device configration.
CNcomment:\brief CI设备属性设置 
\attention \n
N/A
\param[in] enCIPort  CI Port number.                     CNcomment:操作的CI port
\param[in] pstCIAttr The pointer to a structure of CI device. 
                                                         CNcomment:指向CI设备属性的指针。
\retval ::HI_SUCCESS            success                  CNcomment:成功
\retval ::HI_FAILURE            fail                     CNcomment:失败
\see \n
N/A
*/
HI_S32 HI_UNF_CI_SetAttr(HI_UNF_CI_PORT_E enCIPort, const HI_UNF_CI_ATTR_S *pstCIAttr);

/** 
\brief Gets CI device configration.
CNcomment:\brief CI设备属性获取 
\attention \n
N/A
\param[in] enCIPort  CI Port number.                     CNcomment:操作的CI port
\param[in] pstCIAttr The pointer to a structure of CI device. 
                                                         CNcomment:指向CI设备属性的指针。
\retval ::HI_SUCCESS            success                  CNcomment:成功
\retval ::HI_FAILURE            fail                     CNcomment:失败
\see \n
N/A
*/
HI_S32 HI_UNF_CI_GetAttr(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_ATTR_S *pstCIAttr);

/** 
\brief open CI Port
CNcomment:\brief 打开CI Port
\attention \n
N/A
\param[in] enCIPort     CI Port number                    CNcomment:操作的CI port
\retval ::HI_SUCCESS    success                           CNcomment:成功
\retval ::HI_FAILURE     fail                             CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter     CNcomment:无效参数
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port   CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR    read register error   CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error  CNcomment:写寄存器错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_Open(HI_UNF_CI_PORT_E enCIPort);

/** 
\brief close CI Port
CNcomment:\brief 关闭CI Port
\attention \n
N/A
\param[in] enCIPort    CI Port number   CNcomment:操作的CI port
\retval ::HI_SUCCESS       success      CNcomment:成功
\retval ::HI_FAILURE       fail         CNcomment:失败
\see \n
N/A
*/
HI_S32 HI_UNF_CI_Close(HI_UNF_CI_PORT_E enCIPort);

/** 
\brief open CAM
CNcomment:\brief 打开CAM卡
\attention \n
N/A
\param[in] enCIPort    CI Port number                                       CNcomment:操作的CI port
\param[in] enCardId     Card ID                                             CNcomment:操作卡
\retval ::HI_SUCCESS    success                                             CNcomment:成功
\retval ::HI_FAILURE     fail                                               CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA   invalid parameter                        CNcomment: 无效参数
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open   CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                     CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                     CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                    CNcomment:写寄存器错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_Open(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/**
 \brief close CAM
 CNcomment:\brief 关闭CAM卡

 \attention \n
N/A
 \param[in] enCIPort   CI Port number   CNcomment:操作的CI port
 \param[in] enCardId   Card Id          CNcomment:操作卡
 \retval ::HI_SUCCESS   success         CNcomment:成功
 \retval ::HI_FAILURE    fail           CNcomment:失败
 \see \n
N/A
 */
HI_S32 HI_UNF_CI_PCCD_Close(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/**
 \brief CAM power switch
 CNcomment:\brief CAM卡电源开关
 \attention \n
	Some solutions don't support power down for a single card, the calling of this interface
	automatically detects a power outage card plug, if it is on ,it will keep power on
    CNcomment:有的方案不支持针对单卡断电，调用本接口断电时会自动检测是否有卡插上，
    CNcomment:如果有，将不会断电
 \param[in] enCIPort    CI Port number                                       CNcomment:操作的CI port
 \param[in] enCardId    Card Id                                              CNcomment:操作卡
 \param[in] enCtrlPower power on\power off                                   CNcomment:开电、关电
 \retval ::HI_SUCCESS      success                                           CNcomment:成功
 \retval ::HI_FAILURE      fail                                              CNcomment:失败
 \retval ::HI_ERR_CI_INVALID_PARA     invalid parameter                      CNcomment:无效参数
 \retval ::HI_ERR_CI_NOT_INIT         have not been initialized or not open  CNcomment:未初始化或未打开
 \retval ::HI_ERR_CI_UNSUPPORT        unsupported CI Port                    CNcomment:不支持的CI Port
 \retval ::HI_ERR_CI_REG_READ_ERR     read register error                    CNcomment:读寄存器错误
 \retval ::HI_ERR_CI_REG_WRITE_ERR    write register error                   CNcomment:写寄存器错误
 \retval ::HI_ERR_CI_CANNOT_POWEROFF  can not power off                      CNcomment:不能断电
 \see \n
N/A
 */
HI_S32 HI_UNF_CI_PCCD_CtrlPower(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                            HI_UNF_CI_PCCD_CTRLPOWER_E enCtrlPower);

/** 
\brief CI reset
CNcomment:\brief CAM卡复位
\attention \n
N/A
\param[in] enCIPort    CI Port number                                         CNcomment:操作的CI port
\param[in] enCardId    Card Id                                                CNcomment:操作卡
\retval ::HI_SUCCESS   success                                                CNcomment:成功
\retval ::HI_FAILURE   fail                                                   CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                      CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open  CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                    CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                    CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                   CNcomment:写寄存器错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_Reset(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/** 
\brief CAM ready state checking
CNcomment:\brief CAM卡就绪状态检测
\attention \n
N/A
\param[in] enCIPort       CI Port number                                     CNcomment:操作的CI port
\param[in] enCardId       Card Id                                            CNcomment:操作卡
\param[out] penCardReady  state value                                        CNcomment:状态值
\retval ::HI_SUCCESS      success                                            CNcomment:成功
\retval ::HI_FAILURE      fail                                               CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA   invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT       have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT      unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR   read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR  write register error                      CNcomment:写寄存器错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_IsReady(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                            HI_UNF_CI_PCCD_READY_E_PTR penCardReady);

/** 
\brief check CAM if it is on  
CNcomment:\brief CAM卡是否插上检测
\attention \n
N/A
\param[in] enCIPort    CI Port number                                         CNcomment:操作的CI port
\param[in] enCardId    Card Id                                                CNcomment:操作卡
\param[out] penCardStatus  card up or card down                               CNcomment:卡插上或未插状态
\retval ::HI_SUCCESS        success                                           CNcomment:成功
\retval ::HI_FAILURE        fail                                              CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                      CNcomment:写寄存器错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_Detect(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                            HI_UNF_CI_PCCD_STATUS_E_PTR penCardStatus);

/** 
\brief CAM set access module
CNcomment:\brief CAM卡设置访问模块
\attention \n
N/A
\param[in] enCIPort    CI Port number                                         CNcomment:操作的CI port
\param[in] enCardId    Card Id                                                CNcomment:操作卡
\param[in] enAccessMode mode you want to set                                  CNcomment:要设置的模式
\retval ::HI_SUCCESS        success                                           CNcomment:成功
\retval ::HI_FAILURE        fail                                              CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                      CNcomment:写寄存器错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_SetAccessMode(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                                    HI_UNF_CI_PCCD_ACCESSMODE_E enAccessMode);

/** 
\brief CAM write or read state checking
CNcomment:\brief CAM卡读写状态检测
\attention \n
N/A
\param[in] enCIPort    CI Port number                                         CNcomment:操作的CI port
\param[in] enCardId    Card Id                                                CNcomment:操作卡
\param[in] enStatus    status of the bit will check                           CNcomment:要检测的状态位
\param[out] pu8Value   status code returned                                   CNcomment:返回的状态码
\retval ::HI_SUCCESS        success                                           CNcomment:成功
\retval ::HI_FAILURE        fail                                              CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_IO_READ_ERR       read IO error                           CNcomment:IO读错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_GetStatus (HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                                HI_UNF_CI_PCCD_STATUS_BIT_E enStatus, HI_U8 *pu8Value);

/** 
\brief CAM IO read data
CNcomment:\brief CAM卡IO读数据
\attention \n
N/A
\param[in] enCIPort       CI Port number                                      CNcomment:操作的CI port
\param[in] enCardId       Card Id                                             CNcomment:操作卡
\param[out] pu8Buffer     data buffer                                         CNcomment: 数据缓冲区
\param[out] pu32ReadLen   data length that read successful                    CNcomment:成功读取的长度
\retval ::HI_SUCCESS      success                                             CNcomment:成功
\retval ::HI_FAILURE        fail                                              CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                      CNcomment:写寄存器错误
\retval ::HI_ERR_CI_IO_READ_ERR     read IO error                             CNcomment:IO读错误
\see \n
    HI_UNF_CI_PCCD_IOWrite()
*/
HI_S32 HI_UNF_CI_PCCD_IORead(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                            HI_U8 *pu8Buffer, HI_U32 *pu32ReadLen);

/** 
\brief CAM IO write data
CNcomment:\brief CAM卡IO写数据
\attention \n
N/A
\param[in] enCIPort       CI Port number                                      CNcomment:操作的CI port
\param[in] enCardId       Card Id                                             CNcomment:操作卡
\param[in] pu8Buffer      data buffer                                         CNcomment:数据缓冲区
\param[in] u32WriteLen     byte number that have been  writen                 CNcomment:写入字节数
\param[out] pu32WriteOKLen  data length that write successful                 CNcomment:成功写入字节数
\param[in] enCIPort       operate CI port                                     CNcomment:操作的CI port
\param[in] enCardId       Card Id                                             CNcomment:操作卡
\param[out] pu8Buffer     data buffer                                         CNcomment: 数据缓冲区
\param[out] pu32ReadLen   data length that read successful                    CNcomment:成功读取的长度
\retval ::HI_SUCCESS      success                                             CNcomment:成功
\retval ::HI_FAILURE        fail                                              CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                      CNcomment:写寄存器错误
\retval ::HI_ERR_CI_IO_WRITE_ERR    write IO error                            CNcomment:IO写错误
\see \n
    HI_UNF_CI_PCCD_IORead()
*/
HI_S32 HI_UNF_CI_PCCD_IOWrite(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                            HI_U8 *pu8Buffer, HI_U32 u32WriteLen, HI_U32 *pu32WriteOKLen);

/** 
\brief check CAM CIS information
CNcomment:\brief 检验CAM卡CIS信息
\attention \n
    reference EN50221.
    CNcomment:请参考规范 EN50221.
\param[in] enCIPort       CI Port number                                         CNcomment:操作的CI port
\param[in] enCardId       Card Id                                                CNcomment:操作卡
\retval ::HI_SUCCESS      success                                                CNcomment:成功
\retval ::HI_FAILURE        fail                                                 CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_PCCD_DEVICE_BUSY   device busy                               CNcomment:设备忙
\retval ::HI_ERR_CI_PCCD_CIS_READ      read CIS information fail                 CNcomment:读CIS信息失败
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                          CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                         CNcomment:写寄存器错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_CheckCIS(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/** 
\brief config CAM COR information
CNcomment:\brief 配置CAM卡COR信息
\attention \n
    N/A
\param[in] enCIPort       CI Port number                                         CNcomment:操作的CI port
\param[in] enCardId       Card Id                                                CNcomment:操作卡
\retval ::HI_SUCCESS      success                                                CNcomment:成功
\retval ::HI_FAILURE        fail                                                 CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_PCCD_DEVICE_BUSY   device busy                               CNcomment:设备忙
\retval ::HI_ERR_CI_ATTR_WRITE_ERR     config COR fail                           CNcomment:配置COR失败
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:写寄存器错误
\see \n
    N/A
*/
HI_S32 HI_UNF_CI_PCCD_WriteCOR(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/** 
\brief CAM IO reset
CNcomment:\brief CAM卡IO口复位
\attention \n
    N/A
\param[in] enCIPort       CI Port number                                         CNcomment:操作的CI port
\param[in] enCardId       Card Id                                                CNcomment:操作卡
\retval ::HI_SUCCESS      success                                                CNcomment:成功
\retval ::HI_FAILURE        fail                                                 CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT          not supported CI Port                     CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_PCCD_TIMEOUT       timeout                                   CNcomment:超时
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:写寄存器错误
\see \n
    HI_UNF_CI_PCCD_CheckCIS()
*/
HI_S32 HI_UNF_CI_PCCD_IOReset(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/** 
\brief CAM negotiate buffer size
CNcomment:\brief CAM卡协商buffer size
\attention \n
    N/A
\param[in] enCIPort      CI Port number                                          CNcomment:操作的CI port
\param[in] enCardId       Card Id                                                CNcomment:操作卡
\param[in] pu16BufferSize   input  buffer size that master support               CNcomment:输入主机端支持buffer size
\param[out] pu16BufferSize  output buffer size after consultation                CNcomment:输出协商后的buffer size
\retval ::HI_SUCCESS      success                                                CNcomment:成功
\retval ::HI_FAILURE        fail                                                 CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_PCCD_TIMEOUT       timeout                                   CNcomment:超时
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:写寄存器错误
\retval ::HI_ERR_CI_IO_READ_ERR        read IO error                             CNcomment:IO读错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_NegBufferSize(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                                    HI_U16 *pu16BufferSize);

/** 
\brief CAM TS control
CNcomment: \brief CAM卡TS控制
\attention \n
    N/A
\param[in] enCIPort       CI Port number                                         CNcomment:操作的CI port
\param[in] enCardId       Card Id                                                CNcomment:操作卡
\param[in] enCMD          control command                                        CNcomment:控制命令
\param[in] pParam         parameter that matching command                        CNcomment:与命令匹配的参数
\retval ::HI_SUCCESS      success                                                CNcomment:成功
\retval ::HI_FAILURE        fail                                                 CNcomment:失败
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:无效参数
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:未初始化或未打开
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:不支持的CI Port
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:读寄存器错误
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:写寄存器错误
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_TSCtrl(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId, 
                                        HI_UNF_CI_PCCD_TSCTRL_E enCMD, HI_UNF_CI_PCCD_TSCTRL_PARAM_U *pParam);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_ECS_TYPE_H__ */

