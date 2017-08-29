#ifndef __TUNER_COMMON_H__
#define __TUNER_COMMON_H__

#include "hi_type.h"

#include "hi_unf_ecs.h"
#include "priv_tuner.h"

#define QAM_PORT0_ADDR 0xA0
#define QAM_PORT1_ADDR 0xA2
#define QAM_PORT2_ADDR 0xA0
#define TUNER_PORT0_ADDR 0xC0
#define TUNER_PORT1_ADDR 0xC0
#define TUNER_PORT2_ADDR 0xC0
#define XTAL_CLK 28800

#define TUNER_DEBUG_ENABLE

#ifdef TUNER_DEBUG_ENABLE
#ifndef API_DEBUG
    #define API_DEBUG(fmt...) HI_TRACE(HI_LOG_LEVEL_ERROR, HI_DEBUG_ID_TUNER, fmt)
#endif
#else
#ifndef API_DEBUG
    #define API_DEBUG(fmt,args...) printf (fmt,## args)
#endif
#endif

#define TUNER_NUM 3

typedef enum hiTUNER_QAM_TYPE_E
{
    QAM_TYPE_16 = 0,
    QAM_TYPE_32,
    QAM_TYPE_64,
    QAM_TYPE_128,
    QAM_TYPE_256
}TUNER_QAM_TYPE_E;

typedef struct hiTUNER_ACC_QAM_PARAMS_S
{
    HI_U32 u32Frequency;            /* frequency kHz*/
    HI_U32 u32SymbolRate;           /* symbolrate Hz*/
    TUNER_QAM_TYPE_E enQamType;
    HI_BOOL bSI;              /*reverse*/
}TUNER_ACC_QAM_PARAMS_S;

typedef struct  hiTUNER_DATA_S
{
    HI_U32        u32Port;
    HI_U32        u32Data;
}TUNER_DATA_S, *PTR_TUNER_DATA_S;

typedef struct  hiTUNER_DATABUF_S
{
    HI_U32         u32Port;
    HI_U32         u32DataBuf[3];
}TUNER_DATABUF_S, *PTR_TUNER_DATABUF_S;

typedef struct hiTUNER_SET_TUNER_S
{
    HI_U32 u32Freq;
    HI_S32 s32Times;    
}TUNER_SET_TUNER_S, *PTR_TUNER_SET_TUNER_S;


typedef struct  hiTUNER_SIGNAL_S
{
    HI_U32 u32Port;
    TUNER_ACC_QAM_PARAMS_S  stSignal;
}TUNER_SIGNAL_S, *PTR_TUNER_SIGNAL_S;


typedef enum hiTUNER_QAMINSIDE_E
{
    TUNER_QAMINSIDE_IN = 0,
    TUNER_QAMINSIDE_OUT,
    TUNER_QAMINSIDE_INVALID,
}TUNER_QAMINSIDE_E;

typedef struct hiTUNER_I2C_DATA_S
{       
    HI_U8* pu8SendBuf;
    HI_U32 u32SendLength;
    HI_U8* pu8ReceiveBuf;
    HI_U32 u32ReceiveLength;
} TUNER_I2C_DATA_S, *PTR_TUNER_I2C_DATA_S; 

typedef struct  hiAGC_TEST_S 
{
    HI_U32      u32Port;
    HI_U32		u32Agc1;
    HI_U32		u32Agc2;
    HI_BOOL     bLockFlag; 
    HI_BOOL		bAgcLockFlag;
    HI_U8 		u8BagcCtrl12;
	HI_U32		u32Count;
}AGC_TEST_S;

/* standard tuner operation */
typedef struct _TUNER_OPS_S
{
    HI_UNF_TUNER_I2cChannel_E enI2cChannel;
    HI_UNF_TUNER_DEV_TYPE_E   enTunerDevType;
    HI_UNF_DEMOD_DEV_TYPE_E	  enDemodDevType;
	TUNER_ACC_QAM_PARAMS_S    stCurrPara;
	HI_UNF_TUNER_OUPUT_MODE_E      enTsType;
	
	HI_U32	u32DemodAddress;
	HI_U32	u32XtalClk;
	HI_U32  u32TunerAddress;
	HI_U32  u32CurrQamMode;
	HI_U8   u8AdcType;
	HI_U8   u8AgcOutputSel;
	HI_U8   u8AdcDataFmt;
	
    HI_S32 (*tuner_connect)(HI_U32 u32TunerPort, TUNER_ACC_QAM_PARAMS_S * pstChannel);
    HI_S32 (*tuner_get_status)(HI_U32 u32TunerPort, HI_UNF_TUNER_LOCK_STATUS_E * penTunerStatus);
    HI_S32 (*tuner_get_ber)(HI_U32 u32TunerPort, HI_U32 * pu32BERa);
    HI_S32 (*tuner_get_snr)(HI_U32 u32TunerPort, HI_U32 * pu32SignalStrength);
    HI_S32 (*tuner_get_signal_strength)(HI_U32 u32TunerPort, HI_U32 * pu32strength);
    HI_S32 (*tuner_set_ts_type)(HI_U32 u32TunerPort, HI_UNF_TUNER_OUPUT_MODE_E enTsType);
    HI_S32 (*set_tuner)(HI_U32 u32TunerPort, HI_UNF_TUNER_I2cChannel_E enI2cChannel, HI_U32 u32RF);
	HI_S32 (*tuner_get_freq_symb_offset)(HI_U32 u32TunerPort, HI_U32 * pu32Freq, HI_U32 * pu32Symb );
	HI_S32  (*tuner_get_rs)(HI_U32 u32TunerPort, HI_U32 *pu32Rs);
    HI_VOID (*manage_after_chipreset)(HI_U32 u32TunerPort);
    HI_VOID (*recalculate_signal_strength)(HI_U32 u32TunerPort, HI_U32 * pu32Strength);
    HI_VOID (*tuner_test_single_agc)( HI_U32 u32TunerPort, AGC_TEST_S * pstAgcTest );	/* just for test */
	HI_VOID (*tuner_resume)( HI_U32 u32TunerPort );
	HI_VOID (*tuner_get_registers)(HI_U32 u32TunerPort, void *p);
	HI_VOID (*tuner_connect_timeout)(HI_U32 u32ConnectTimeout);
} TUNER_OPS_S;

extern TUNER_OPS_S g_stTunerOps[TUNER_NUM];

extern HI_S32 tuner_i2c_send_data(HI_U32 u32I2cChannel, HI_U8 u8DevAddress, PTR_TUNER_I2C_DATA_S pstDataStruct);
extern HI_S32 tuner_i2c_receive_data(HI_U32 u32I2cChannel, HI_U8 u8DevAddress, PTR_TUNER_I2C_DATA_S pstDataStruct);
extern HI_VOID reset_special_process_flag(HI_BOOL flag);

#endif

