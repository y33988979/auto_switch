/******************************************************************************

                              Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_tuner.h
Version       : Initial Draft
Author        : Hisilicon multimedia Hardware group l50549
Created       : 2006/8/3
Last Modified :
Description   : Hi3110-SW-D002
Function List :
History       :
******************************************************************************/
#ifndef __HI_TUNER_H__
#define __HI_TUNER_H__

#include "hi_unf_ecs.h"

#define HI_FATAL_TUNER(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_FATAL, HI_DEBUG_ID_TUNER, fmt)

#define HI_ERR_TUNER(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_ERROR, HI_DEBUG_ID_TUNER, fmt)

#define HI_WARN_TUNER(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_WARNING, HI_DEBUG_ID_TUNER, fmt)

#define HI_INFO_TUNER(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_INFO, HI_DEBUG_ID_TUNER, fmt)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*---- TUNER COMMAND----*/
#define HI_TUNER_IOC_MAGIC 't'
#define TUNER_CONNECT_CMD _IOW(HI_TUNER_IOC_MAGIC, 1, TUNER_SIGNAL_S)
#define TUNER_GET_STATUS_CMD _IOWR(HI_TUNER_IOC_MAGIC, 2, TUNER_DATA_S)
#define TUNER_GET_SIGNALSTRENGTH_CMD _IOWR(HI_TUNER_IOC_MAGIC, 3, TUNER_DATABUF_S)
#define TUNER_GET_BER_CMD _IOWR(HI_TUNER_IOC_MAGIC, 4, TUNER_DATABUF_S)
#define TUNER_GET_SNR_CMD _IOWR(HI_TUNER_IOC_MAGIC, 5, TUNER_DATA_S)
#define TUNER_SET_TSTYPE_CMD _IOW(HI_TUNER_IOC_MAGIC, 6, TUNER_DATA_S)
#define TUNER_SELECT_TYPE_CMD _IOW(HI_TUNER_IOC_MAGIC, 7, TUNER_DATABUF_S)
#define TUNER_SELECT_I2C_CMD _IOW(HI_TUNER_IOC_MAGIC, 8, TUNER_DATA_S)
#define TUNER_SELECT_RW_CMD _IOWR(HI_TUNER_IOC_MAGIC, 9, TUNER_RegRW_S)
#define TUNER_SET_TUNER_CMD _IOWR(HI_TUNER_IOC_MAGIC, 10, TUNER_SET_TUNER_S)
#define TUNER_LOW_CONS_CMD _IO(HI_TUNER_IOC_MAGIC, 11)
#define TUNER_NORMAL_MODE_CMD _IO(HI_TUNER_IOC_MAGIC, 12)
#define TUNER_SET_QAMINSIDE_CMD _IOR(HI_TUNER_IOC_MAGIC, 13, TUNER_QAMINSIDE_E)
#define TUNER_CONNECTUNBLOCK_CMD _IOW(HI_TUNER_IOC_MAGIC, 14, TUNER_SIGNAL_S)
#define TUNER_SELECT_SYMBOLRATE_CMD _IOR(HI_TUNER_IOC_MAGIC, 15, TUNER_DATA_S)
#define TUNER_CHECK_VALID_I2CADDR _IOW(HI_TUNER_IOC_MAGIC, 16, TUNER_DATA_S) 
#define TUNER_TEST_SINGLE_AGC _IOWR(HI_TUNER_IOC_MAGIC, 17, AGC_TEST_S) 
#define TUNER_GET_FREQ_SYMB_OFFSET _IOWR(HI_TUNER_IOC_MAGIC, 18, TUNER_DATABUF_S)
#define TUNER_CONNECT_TIMEOUT_CMD _IOWR(HI_TUNER_IOC_MAGIC, 19, TUNER_DATABUF_S)
/*
#define TUNER_BASE_CONNECT_CMD _IOW(HI_TUNER_IOC_MAGIC, 20, TUNER_SIGNAL_S)
#define TUNER_BASE_SELECT_TYPE_CMD _IOW(HI_TUNER_IOC_MAGIC, 21, TUNER_DATABUF_S)
#define TUNER_BASE_SELECT_I2C_CMD _IOW(HI_TUNER_IOC_MAGIC, 22, TUNER_DATA_S)
#define TUNER_BASE_SET_TSTYPE_CMD _IOW(HI_TUNER_IOC_MAGIC, 23, TUNER_DATA_S)
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*__TUNER_H__*/
