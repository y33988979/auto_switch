/**************************************
Author        : Hisilicon multime
Created       : 2006/3/6
Last Modified :
Description   : error code number of ECS
Function List :
History       :
 *********************************/
#ifndef __HI_ERROR_ECS_H__
#define __HI_ERROR_ECS_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/***************************** Macro Definition ******************************/
/** \addtogroup      H_3_5 */
/** @{ */  /** <!-- ¡¾ECS error code number¡¿ */

#define HI_ERR_IR_OPEN_ERR                          (HI_S32)(0x80410001)
#define HI_ERR_IR_CLOSE_ERR                         (HI_S32)(0x80410002)
#define HI_ERR_IR_NOT_INIT                          (HI_S32)(0x80410003)
#define HI_ERR_IR_INVALID_PARA                      (HI_S32)(0x80410004)
#define HI_ERR_IR_NULL_PTR                          (HI_S32)(0x80410005)
#define HI_ERR_IR_READ_FAILED                       (HI_S32)(0x80410006)
#define HI_ERR_IR_IOCTL_FAILED                      (HI_S32)(0x80410007)
#define HI_ERR_IR_UNSUPPORT                         (HI_S32)(0x80410008)

#define HI_ERR_RTC_NOT_INIT                         (HI_S32)(0x80420001)
#define HI_ERR_RTC_REPEAT_INIT                      (HI_S32)(0x80420002)
#define HI_ERR_RTC_INVALID_POINT                    (HI_S32)(0x80420003)
#define HI_ERR_RTC_INVALID_PARA                     (HI_S32)(0x80420004)
#define HI_ERR_RTC_FAILED_INIT                      (HI_S32)(0x80420005)
#define HI_ERR_RTC_FAILED_SETTIME                   (HI_S32)(0x80420006)
#define HI_ERR_RTC_FAILED_GETTIME                   (HI_S32)(0x80420007)
#define HI_ERR_RTC_FAILED_ALARMENABLE               (HI_S32)(0x80420008)
#define HI_ERR_RTC_FAILED_ALARMDISABLE              (HI_S32)(0x80420009)
#define HI_ERR_RTC_FAILED_SETALARM                  (HI_S32)(0x8042000A)
#define HI_ERR_RTC_FAILED_GETALARM                  (HI_S32)(0x8042000B)

#define HI_ERR_WDG_NOT_INIT                         (HI_S32)(0x80430001)
#define HI_ERR_WDG_REPEAT_INIT                      (HI_S32)(0x80430002)
#define HI_ERR_WDG_INVALID_POINT                    (HI_S32)(0x80430003)
#define HI_ERR_WDG_INVALID_PARA                     (HI_S32)(0x80430004)
#define HI_ERR_WDG_FAILED_INIT                      (HI_S32)(0x80430005)
#define HI_ERR_WDG_FAILED_SETTIMEOUT                (HI_S32)(0x80430006)
#define HI_ERR_WDG_FAILED_ENABLE                    (HI_S32)(0x80430007)
#define HI_ERR_WDG_FAILED_DISABLE                   (HI_S32)(0x80430008)
#define HI_ERR_WDG_FAILED_CLEARWDG                  (HI_S32)(0x80430009)
#define HI_ERR_WDG_FAILED_RESET                     (HI_S32)(0x8043000A)
#define HI_ERR_WDG_FAILED_RESMODE                   (HI_S32)(0x8043000B)
#define HI_ERR_WDG_NOT_SUPPORT                      (HI_S32)(0x8043000C)

#define HI_ERR_I2C_OPEN_ERR                         (HI_S32)(0x80440001)
#define HI_ERR_I2C_CLOSE_ERR                        (HI_S32)(0x80440002)
#define HI_ERR_I2C_NOT_INIT                         (HI_S32)(0x80440003)
#define HI_ERR_I2C_INVALID_PARA                     (HI_S32)(0x80440004)
#define HI_ERR_I2C_NULL_PTR                         (HI_S32)(0x80440005)
#define HI_ERR_I2C_COPY_DATA_ERR                    (HI_S32)(0x80440006)
#define HI_ERR_I2C_MALLOC_ERR                       (HI_S32)(0x80440007)
#define HI_ERR_I2C_WRITE_TIMEOUT                    (HI_S32)(0x80440008)
#define HI_ERR_I2C_READ_TIMEOUT                     (HI_S32)(0x80440009)

#define HI_ERR_SCI_OPEN_ERR                         (HI_S32)(0x80450001)
#define HI_ERR_SCI_CLOSE_ERR                        (HI_S32)(0x80450002)
#define HI_ERR_SCI_NOT_INIT                         (HI_S32)(0x80450003)
#define HI_ERR_SCI_INVALID_PARA                     (HI_S32)(0x80450004)
#define HI_ERR_SCI_NULL_PTR                         (HI_S32)(0x80450005)
#define HI_ERR_SCI_INVALID_OPT                      (HI_S32)(0x80450006)
#define HI_ERR_SCI_SEND_ERR                         (HI_S32)(0x80450007)
#define HI_ERR_SCI_RECEIVE_ERR                      (HI_S32)(0x80450008)
#define HI_ERR_SCI_NO_ATR                           (HI_S32)(0x80450009)
#define HI_ERR_SCI_PPS_PTYPE_ERR              (HI_S32)(0x8045000A)
#define HI_ERR_SCI_PPS_FACTOR_ERR            (HI_S32)(0x8045000B)
#define HI_ERR_SCI_PPS_NOTSUPPORT_ERR    (HI_S32)(0x8045000C)


#define HI_ERR_ETH_NOT_INIT                         (HI_S32)(0x80460001)
#define HI_ERR_ETH_REPEAT_INIT                      (HI_S32)(0x80460002)
#define HI_ERR_ETH_INVALID_POINT                    (HI_S32)(0x80460003)
#define HI_ERR_ETH_INVALID_PARA                     (HI_S32)(0x80460004)
#define HI_ERR_ETH_FAILED_INIT                      (HI_S32)(0x80460005)

#define HI_ERR_GPIO_OPEN_ERR                        (HI_S32)(0x80470001)
#define HI_ERR_GPIO_CLOSE_ERR                       (HI_S32)(0x80470002)
#define HI_ERR_GPIO_NOT_INIT                        (HI_S32)(0x80470003)
#define HI_ERR_GPIO_INVALID_PARA                    (HI_S32)(0x80470004)
#define HI_ERR_GPIO_NULL_PTR                        (HI_S32)(0x80470005)
#define HI_ERR_GPIO_INVALID_OPT                     (HI_S32)(0x80470006)
#define HI_ERR_GPIO_FAILED_SETINT                   (HI_S32)(0x80470007)
#define HI_ERR_GPIO_FAILED_SETENABLE                (HI_S32)(0x80470008)
#define HI_ERR_GPIO_FAILED_GETINT                   (HI_S32)(0x80470009)
#define HI_ERR_GPIO_GETINT_TIMEOUT                  (HI_S32)(0x8047000A)

#define HI_ERR_DMAC_NOT_INIT                        (HI_S32)(0x80480001)
#define HI_ERR_DMAC_REPEAT_INIT                     (HI_S32)(0x80480002)
#define HI_ERR_DMAC_INVALID_POINT                   (HI_S32)(0x80480003)
#define HI_ERR_DMAC_INVALID_PARA                    (HI_S32)(0x80480004)
#define HI_ERR_DMAC_FAILED_INIT                     (HI_S32)(0x80480005)
#define HI_ERR_DMAC_FAILED_GETCHANNEL               (HI_S32)(0x80480006)
#define HI_ERR_DMAC_FAILED_MEMTRANS                 (HI_S32)(0x80480007)
#define HI_ERR_DMAC_FAILED_PERTRANS                 (HI_S32)(0x80480008)
#define HI_ERR_DMAC_FAILED_GETSTAT                  (HI_S32)(0x80480009)
#define HI_ERR_DMAC_FAILED_LISTRESET                (HI_S32)(0x8048000A)
#define HI_ERR_DMAC_FAILED_ADDLIST                  (HI_S32)(0x8048000B)
#define HI_ERR_DMAC_FAILED_LISTTRANS                (HI_S32)(0x8048000C)

#define  HI_ERR_PMOC_NOT_INIT                       (HI_S32)(0x80490001)
#define  HI_ERR_PMOC_REPEAT_INIT                    (HI_S32)(0x80490002)
#define  HI_ERR_PMOC_INVALID_POINT                  (HI_S32)(0x80490003)
#define  HI_ERR_PMOC_INVALID_PARA                   (HI_S32)(0x80490004)
#define  HI_ERR_PMOC_FAILED_INIT                    (HI_S32)(0x80490005)
#define  HI_ERR_PMOC_FAILED_MODE                    (HI_S32)(0x80490006)
#define  HI_ERR_PMOC_FAILED_READMODE                (HI_S32)(0x80490007)
#define  HI_ERR_PMOC_FAILED_IRPOWERVAL              (HI_S32)(0x80490008)
#define  HI_ERR_PMOC_FAILED_KEYLEDPOWERVAL          (HI_S32)(0x80490009)
#define  HI_ERR_PMOC_INVALID_MODE                   (HI_S32)(0x8049000A)
#define  HI_ERR_PMOC_FAILED_STANDBY                 (HI_S32)(0x8049000B)
#define  HI_ERR_PMOC_FAILED_SETDEV                  (HI_S32)(0x8049000C)

#define HI_ERR_TUNER_NOT_INIT                       (HI_S32)(0x804A0001)
#define HI_ERR_TUNER_NOT_OPEN                       (HI_S32)(0x804A0002)
#define HI_ERR_TUNER_INVALID_POINT                  (HI_S32)(0x804A0003)
#define HI_ERR_TUNER_INVALID_PARA                   (HI_S32)(0x804A0004)
#define HI_ERR_TUNER_FAILED_INIT                    (HI_S32)(0x804A0005)
#define HI_ERR_TUNER_FAILED_CONNECT                 (HI_S32)(0x804A0006)
#define HI_ERR_TUNER_FAILED_GETSTATUS               (HI_S32)(0x804A0007)
#define HI_ERR_TUNER_FAILED_GETSIGNALSTRENGTH       (HI_S32)(0x804A0008)
#define HI_ERR_TUNER_FAILED_GETBER                  (HI_S32)(0x804A0009)
#define HI_ERR_TUNER_FAILED_GETSNR                  (HI_S32)(0x804A000A)
#define HI_ERR_TUNER_FAILED_SETTSTYPE               (HI_S32)(0x804A000B)
#define HI_ERR_TUNER_FAILED_SELECTTUNER             (HI_S32)(0x804A000C)
#define HI_ERR_TUNER_FAILED_SELECTI2CCHANNEL        (HI_S32)(0x804A000D)
#define HI_ERR_TUNER_FAILED_LOWCONS                 (HI_S32)(0x804A000E)
#define HI_ERR_TUNER_FAILED_NORMALMODE              (HI_S32)(0x804A000F)
#define HI_ERR_TUNER_FAILED_REGRW                   (HI_S32)(0x804A0010)
#define HI_ERR_TUNER_FAILED_SETTUNER                (HI_S32)(0x804A0011)
#define HI_ERR_TUNER_NOT_CONNECT                    (HI_S32)(0x804A0012)
#define HI_ERR_TUNER_INVALID_PORT                   (HI_S32)(0x804A0013)
#define HI_ERR_TUNER_FAILED_SETQAMINSIDE            (HI_S32)(0x804A0014)
#define HI_ERR_TUNER_FAILED_SELECTSYMBOLRATE        (HI_S32)(0x804A0015)
#define HI_ERR_TUNER_FAILED_GETSIGNALQUALITY        (HI_S32)(0x804A0016)
#define HI_ERR_TUNER_FAILED_GETSIGNALINFO           (HI_S32)(0x804A0017)
#define HI_ERR_TUNER_FAILED_BLINDSCAN               (HI_S32)(0x804A0018)
#define HI_ERR_TUNER_FAILED_LNBCTRL                 (HI_S32)(0x804A0019)
#define HI_ERR_TUNER_FAILED_SWITCH                  (HI_S32)(0x804A001A)
#define HI_ERR_TUNER_FAILED_DISEQC                  (HI_S32)(0x804A001B)
#define HI_ERR_TUNER_FAILED_STANDBY                 (HI_S32)(0x804A001C)
#define HI_ERR_TUNER_FAILED_WAKEUP                  (HI_S32)(0x804A001D)
#define HI_ERR_TUNER_FAILED_DISABLE                 (HI_S32)(0x804A001E)
#define HI_ERR_TUNER_FAILED_ENABLE                  (HI_S32)(0x804A001F)
#define HI_ERR_TUNER_FAILED_SETPLPID                  (HI_S32)(0x804A0020)
#define HI_ERR_TUNER_FAILED_GETPLPNUM                  (HI_S32)(0x804A0021)
#define HI_ERR_TUNER_FAILED_GETPLPTYPE                  (HI_S32)(0x804A0022)

#define HI_ERR_KEYLED_NOT_INIT                      (HI_S32)(0x804B0001)
#define HI_ERR_KEYLED_INVALID_PARA                  (HI_S32)(0x804B0002)
#define HI_ERR_KEYLED_NULL_PTR                      (HI_S32)(0x804B0003)
#define HI_ERR_KEYLED_NO_NEW_KEY                    (HI_S32)(0x804B0004)
#define HI_ERR_KEYLED_TIMEOUT                       (HI_S32)(0x804B0005)
#define HI_ERR_KEYLED_FAILED_SETMODE                (HI_S32)(0x804B0006)
#define HI_ERR_KEYLED_FAILED_DISPLAY                (HI_S32)(0x804B0007)


#define HI_ERR_E2PROM_OPEN_ERR                      (HI_S32)(0x804C0001)
#define HI_ERR_E2PROM_CLOSE_ERR                     (HI_S32)(0x804C0002)
#define HI_ERR_E2PROM_NOT_INIT                      (HI_S32)(0x804C0003)
#define HI_ERR_E2PROM_INVALID_PARA                  (HI_S32)(0x804C0004)
#define HI_ERR_E2PROM_NULL_PTR                      (HI_S32)(0x804C0005)
#define HI_ERR_E2PROM_COPY_DATA_ERR                 (HI_S32)(0x804C0006)
#define HI_ERR_E2PROM_MALLOC_ERR                    (HI_S32)(0x804C0007)


#define  HI_ERR_CIPHER_NOT_INIT                     (HI_S32)(0x804D0001)
#define  HI_ERR_CIPHER_INVALID_HANDLE               (HI_S32)(0x804D0002)
#define  HI_ERR_CIPHER_INVALID_POINT                (HI_S32)(0x804D0003)
#define  HI_ERR_CIPHER_INVALID_PARA                 (HI_S32)(0x804D0004)
#define  HI_ERR_CIPHER_FAILED_INIT                  (HI_S32)(0x804D0005)
#define  HI_ERR_CIPHER_FAILED_GETHANDLE             (HI_S32)(0x804D0006)
#define  HI_ERR_CIPHER_FAILED_RELEASEHANDLE         (HI_S32)(0x804D0007)
#define  HI_ERR_CIPHER_FAILED_CONFIGAES             (HI_S32)(0x804D0008)
#define  HI_ERR_CIPHER_FAILED_CONFIGDES             (HI_S32)(0x804D0009)
#define  HI_ERR_CIPHER_FAILED_ENCRYPT               (HI_S32)(0x804D000A)
#define  HI_ERR_CIPHER_FAILED_DECRYPT               (HI_S32)(0x804D000B)
#define  HI_ERR_CIPHER_BUSY                         (HI_S32)(0x804D000C)


#define  HI_ERR_CA_OPEN_ERR                         (HI_S32)(0x804E0001)
#define  HI_ERR_CA_CLOSE_ERR                        (HI_S32)(0x804E0002)
#define  HI_ERR_CA_NOT_INIT                         (HI_S32)(0x804E0003)
#define  HI_ERR_CA_COPY_DATA_ERR                    (HI_S32)(0x804E0004)
#define  HI_ERR_CA_INVALID_PARA                     (HI_S32)(0x804E0005)
#define  HI_ERR_CA_WAIT_TIMEOUT                     (HI_S32)(0x804E0006)
#define  HI_ERR_CA_CW_DECRYPT                       (HI_S32)(0x804E0007)
#define  HI_ERR_CA_R2R_DECRYPT                      (HI_S32)(0x804E0008)
#define  HI_ERR_CA_R2R_ENCRYPT                      (HI_S32)(0x804E0009)
#define  HI_ERR_CA_SETPARAM_AGAIN	                (HI_S32)(0x804E000A)
#define  HI_ERR_CA_DBG_INERR 		                (HI_S32)(0x804E000B)
#define  HI_ERR_CA_NOT_CONFIG                       (HI_S32)(0x804E000C)
#define  HI_ERR_CA_LPK_DECRYPT                      (HI_S32)(0x804E000D)
#define  HI_ERR_CA_NOT_SUPPORT                      (HI_S32)(0x804E000E)
#define  HI_ERR_CA_SWPK_ENCRYPT                     (HI_S32)(0x804E000F)

#define  HI_ERR_C51_COPY_DATA_ERR                    (HI_S32)(0x804F0001)
#define  HI_ERR_C51_INVALID_PARAM                   (HI_S32)(0x804F0002)

#define  HI_ERR_CI_NOT_INIT                         (HI_S32)(0x80500001)
#define  HI_ERR_CI_OPEN_ERR                         (HI_S32)(0x80500002)
#define  HI_ERR_CI_CLOSE_ERR                        (HI_S32)(0x80500003)
#define  HI_ERR_CI_INVALID_PARA                     (HI_S32)(0x80500004)
#define  HI_ERR_CI_NO_MEMORY                        (HI_S32)(0x80500005)
#define  HI_ERR_CI_TIMEOUT                          (HI_S32)(0x80500006)
#define  HI_ERR_CI_REG_READ_ERR                     (HI_S32)(0x80500007)
#define  HI_ERR_CI_REG_WRITE_ERR                    (HI_S32)(0x80500008)
#define  HI_ERR_CI_IO_READ_ERR                      (HI_S32)(0x80500009)
#define  HI_ERR_CI_IO_WRITE_ERR                     (HI_S32)(0x8050000A)
#define  HI_ERR_CI_ATTR_READ_ERR                    (HI_S32)(0x8050000B)
#define  HI_ERR_CI_ATTR_WRITE_ERR                   (HI_S32)(0x8050000C)
#define  HI_ERR_CI_CANNOT_POWEROFF                  (HI_S32)(0x8050000D)
#define  HI_ERR_CI_PCCD_DEVICE_BUSY                 (HI_S32)(0x8050000E)
#define  HI_ERR_CI_PCCD_CIS_READ                    (HI_S32)(0x8050000F)
#define  HI_ERR_CI_UNSUPPORT                        (HI_S32)(0x80500010)
#define  HI_ERR_CI_UNKONWN                          (HI_S32)(0x80500011)

/** @} */  /*! <!-- Macro Definition end */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ECS_ERRCODE_H__ */
