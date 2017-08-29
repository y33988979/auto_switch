/**
 \file
 \brief common head file or PVR
 \copyright Shenzhen Hisilicon Co., Ltd.
 \date 2008-2018
 \version draft
 \author z40717
 \date 2010-6-12
 */

#ifndef __COMMON_AUDIO_H__
#define __COMMON_AUDIO_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include "hi_type.h"
#include "hi_unf_ecs.h"

#ifdef __cplusplus
extern "C"
{
#endif


        /***************************** Macro Definition ******************************/
#undef CHIP_TYPE_NOTHING

#if  defined (CHIP_TYPE_hi3720v100)
#define SYS_PINSHARED_ADDR 0x10203000
#define SIO_DEV_NUMBER 3

#define sio0_gpio_vga0vs 0x14
#define SIO0_MCLK_PINSHARED_OFFSET sio0_gpio_vga0vs
#define SIO0_MCLK_MASK 0x3
#define SIO0_MCLK_BITS 0x1

#define sio0_gpio 0x18
#define SIO0_BCLK_PINSHARED_OFFSET sio0_gpio
#define SIO0_BCLK_MASK 0x1
#define SIO0_BCLK_BITS 0x1

#define SIO0_FSYNC_PINSHARED_OFFSET sio0_gpio
#define SIO0_FSYNC_MASK 0x1
#define SIO0_FSYNC_BITS 0x1

#define SIO0_DOUT_PINSHARED_OFFSET sio0_gpio
#define SIO0_DOUT_MASK 0x1
#define SIO0_DOUT_BITS 0x1

#define SIO0_DIN_PINSHARED_OFFSET sio0_gpio
#define SIO0_DIN_MASK 0x1
#define SIO0_DIN_BITS 0x1

#define sio1_gpio 0x28
#define SIO1_MCLK_PINSHARED_OFFSET sio1_gpio
#define SIO1_MCLK_MASK 0x1
#define SIO1_MCLK_BITS 0x1

#define SIO1_BCLK_PINSHARED_OFFSET sio1_gpio
#define SIO1_BCLK_MASK 0x1
#define SIO1_BCLK_BITS 0x1

#define SIO1_FSYNC_PINSHARED_OFFSET sio1_gpio
#define SIO1_FSYNC_MASK 0x1
#define SIO1_FSYNC_BITS 0x1

#define SIO1_DOUT_PINSHARED_OFFSET sio1_gpio
#define SIO1_DOUT_MASK 0x1
#define SIO1_DOUT_BITS 0x1

#define SIO1_DIN_PINSHARED_OFFSET sio1_gpio
#define SIO1_DIN_MASK 0x1
#define SIO1_DIN_BITS 0x1

#define sio2_gpio_vga1vs 0x2c
#define SIO2_MCLK_PINSHARED_OFFSET sio2_gpio_vga1vs
#define SIO2_MCLK_MASK 0x3
#define SIO2_MCLK_BITS 0x1

#define sio2_gpio_hdmihot 0x30
#define SIO2_BCLK_PINSHARED_OFFSET sio2_gpio_hdmihot
#define SIO2_BCLK_MASK 0x3
#define SIO2_BCLK_BITS 0x1

#define sio2_gpio 0x34
#define SIO2_FSYNC_PINSHARED_OFFSET sio2_gpio
#define SIO2_FSYNC_MASK 0x3
#define SIO2_FSYNC_BITS 0x1

#define sio2_gpio_vga1hs_usb1 0x38
#define SIO2_DOUT_PINSHARED_OFFSET sio2_gpio_vga1hs_usb1
#define SIO2_DOUT_MASK 0x3
#define SIO2_DOUT_BITS 0x1

#define sio2_gpio_hdmicec 0x3c
#define SIO2_DIN_PINSHARED_OFFSET sio2_gpio_hdmicec
#define SIO2_DIN_MASK 0x3
#define SIO2_DIN_BITS 0x1

#if defined (BOARD_TYPE_hi3720tst1)
#define gpio_usb1_viu601 0x10
#define MUTECTL_PINSHARED_OFFSET gpio_usb1_viu601
#define MUTECTL_MASK 0x3
#define MUTECTL_BITS 0x0
#define MUTECTL_GPIO_NUM (8 * 0 + 2)      /* GPIO0_2 */

#else
#error YOU MUST DEFINE  BOARD_TYPE!
#endif
#elif  defined (CHIP_TYPE_hi3716hv100)
#define SYS_PINSHARED_ADDR 0x10203000

#define SIO_DEV_NUMBER 1
#define sio0_gpio_vga0vs 0x14
#define SIO0_MCLK_PINSHARED_OFFSET sio0_gpio_vga0vs
#define SIO0_MCLK_MASK 0x1
#define SIO0_MCLK_BITS 0x1

#define sio0_gpio 0x18
#define SIO0_BCLK_PINSHARED_OFFSET sio0_gpio
#define SIO0_BCLK_MASK 0x1
#define SIO0_BCLK_BITS 0x1

#define SIO0_FSYNC_PINSHARED_OFFSET sio0_gpio
#define SIO0_FSYNC_MASK 0x1
#define SIO0_FSYNC_BITS 0x1

#define SIO0_DOUT_PINSHARED_OFFSET sio0_gpio
#define SIO0_DOUT_MASK 0x1
#define SIO0_DOUT_BITS 0x1

#define SIO0_DIN_PINSHARED_OFFSET sio0_gpio
#define SIO0_DIN_MASK 0x1
#define SIO0_DIN_BITS 0x1
#if defined (BOARD_TYPE_hi3716hdmo) || defined (BOARD_TYPE_hi3716hdmoverb)

#define ebi_adr_vougpio 0x150
#define MUTECTL_PINSHARED_OFFSET ebi_adr_vougpio
#define MUTECTL_MASK 0x1
#define MUTECTL_BITS 0x1
#define MUTECTL_GPIO_NUM (8 * 7 + 1)      /* GPIO7_1 */

#else
#error YOU MUST DEFINE  BOARD_TYPE!
#endif
#elif  defined (CHIP_TYPE_hi3716hv101)
#define SYS_PINSHARED_ADDR 0x10203000

#define SIO_DEV_NUMBER 1
#define sio0_gpio_vga0vs_ao_aio 0x00
#define SIO0_MCLK_PINSHARED_OFFSET sio0_gpio_vga0vs_ao_aio
#define SIO0_MCLK_MASK 0x7
#define SIO0_MCLK_BITS 0x1

#define sio0_gpio_ao_aio 0x04
#define SIO0_BCLK_PINSHARED_OFFSET sio0_gpio_ao_aio
#define SIO0_BCLK_MASK 0x7
#define SIO0_BCLK_BITS 0x1

#define SIO0_FSYNC_PINSHARED_OFFSET sio0_gpio_ao_aio
#define SIO0_FSYNC_MASK 0x7
#define SIO0_FSYNC_BITS 0x1

#define SIO0_DOUT_PINSHARED_OFFSET sio0_gpio_ao_aio
#define SIO0_DOUT_MASK 0x7
#define SIO0_DOUT_BITS 0x1

#define SIO0_DIN_PINSHARED_OFFSET sio0_gpio_ao_aio
#define SIO0_DIN_MASK 0x7
#define SIO0_DIN_BITS 0x1
#if defined (BOARD_TYPE_hi3716hdmo) || defined (BOARD_TYPE_hi3716hdmoverb)
#define ebiadr_gpio 0x124
#define MUTECTL_PINSHARED_OFFSET ebiadr_gpio
#define MUTECTL_MASK 0x1
#define MUTECTL_BITS 0x1
#define MUTECTL_GPIO_NUM (8 * 7 + 1)      /* GPIO7_1 */

#else
#error YOU MUST DEFINE  BOARD_TYPE!
#endif
#elif  defined (CHIP_TYPE_hi3716cv100)
#define SYS_PINSHARED_ADDR 0x10203000

#define SIO_DEV_NUMBER 1

#define sio0_gpio_vga0vs 0x14
#define SIO0_MCLK_PINSHARED_OFFSET sio0_gpio_vga0vs
#define SIO0_MCLK_MASK 0x1
#define SIO0_MCLK_BITS 0x1

#define sio0_gpio 0x18
#define SIO0_BCLK_PINSHARED_OFFSET sio0_gpio
#define SIO0_BCLK_MASK 0x1
#define SIO0_BCLK_BITS 0x1

#define SIO0_FSYNC_PINSHARED_OFFSET sio0_gpio
#define SIO0_FSYNC_MASK 0x1
#define SIO0_FSYNC_BITS 0x1

#define SIO0_DOUT_PINSHARED_OFFSET sio0_gpio
#define SIO0_DOUT_MASK 0x1
#define SIO0_DOUT_BITS 0x1

#define SIO0_DIN_PINSHARED_OFFSET sio0_gpio
#define SIO0_DIN_MASK 0x1
#define SIO0_DIN_BITS 0x1

#if defined (BOARD_TYPE_hi3716ctst)
#define tsi0_vi0_tsi1_gpio 0x19c
#define MUTECTL_PINSHARED_OFFSET tsi0_vi0_tsi1_gpio
#define MUTECTL_MASK 0x3
#define MUTECTL_BITS 0x3
#define MUTECTL_GPIO_NUM (8 * 12 + 0)     /* GPIO12_0 */

#elif  defined (BOARD_TYPE_hi3716cdmo)
#define SYS_PINSHARED_ADDR 0x10203000
#define ebi_adr_vougpio 0x150
#define MUTECTL_PINSHARED_OFFSET ebi_adr_vougpio
#define MUTECTL_MASK 0x1
#define MUTECTL_BITS 0x1
#define MUTECTL_GPIO_NUM (8 * 7 + 1)      /* GPIO7_1 */

#elif  defined (BOARD_TYPE_hi3716cdmoverb)

#define ebi_adr_vougpio 0x150
#define MUTECTL_PINSHARED_OFFSET ebi_adr_vougpio
#define MUTECTL_MASK 0x1
#define MUTECTL_BITS 0x1
#define MUTECTL_GPIO_NUM (8 * 7 + 1)      /* GPIO7_1 */


#else
#error YOU MUST DEFINE  BOARD_TYPE!
#endif
#elif  defined (CHIP_TYPE_hi3716cv101) || defined (CHIP_TYPE_hi3716c) 
#define SYS_PINSHARED_ADDR 0x10203000

#define SIO_DEV_NUMBER 1
#define sio0_gpio_vga0vs_ao_aio 0x00
#define SIO0_MCLK_PINSHARED_OFFSET sio0_gpio_vga0vs_ao_aio
#define SIO0_MCLK_MASK 0x7
#define SIO0_MCLK_BITS 0x1

#define sio0_gpio_ao_aio 0x04
#define SIO0_BCLK_PINSHARED_OFFSET sio0_gpio_ao_aio
#define SIO0_BCLK_MASK 0x7
#define SIO0_BCLK_BITS 0x1

#define SIO0_FSYNC_PINSHARED_OFFSET sio0_gpio_ao_aio
#define SIO0_FSYNC_MASK 0x7
#define SIO0_FSYNC_BITS 0x1

#define SIO0_DOUT_PINSHARED_OFFSET sio0_gpio_ao_aio
#define SIO0_DOUT_MASK 0x7
#define SIO0_DOUT_BITS 0x1

#define SIO0_DIN_PINSHARED_OFFSET sio0_gpio_ao_aio
#define SIO0_DIN_MASK 0x7
#define SIO0_DIN_BITS 0x1

#if defined (BOARD_TYPE_hi3716ctst)
#define ebiadr_gpio 0x7c
#define MUTECTL_PINSHARED_OFFSET ebiadr_gpio
#define MUTECTL_MASK 0x3
#define MUTECTL_BITS 0x0
#define MUTECTL_GPIO_NUM (8 * 5 + 3)      /* GPIO5_3 */

#elif  defined (BOARD_TYPE_hi3716cdmo) || defined (BOARD_TYPE_hi3716cdmoverb)
#define ebiadr_gpio 0x124
#define MUTECTL_PINSHARED_OFFSET ebiadr_gpio
#define MUTECTL_MASK 0x1
#define MUTECTL_BITS 0x1
#define MUTECTL_GPIO_NUM (8 * 7 + 1)      /* GPIO7_1 */

#else
#error YOU MUST DEFINE  BOARD_TYPE!
#endif
#elif  defined (CHIP_TYPE_hi3716mv100)
#define SYS_PINSHARED_ADDR 0x10203000
#define SIO_DEV_NUMBER 0
#if defined (BOARD_TYPE_hi3716mdmo) || defined (BOARD_TYPE_hi3716mstb) || defined (BOARD_TYPE_hi3716mdmo3avera)
#define det_vi0_tsi0_gpio 0x1a4
#define MUTECTL_PINSHARED_OFFSET det_vi0_tsi0_gpio
#define MUTECTL_MASK 0x3
#define MUTECTL_BITS 0x3
#define MUTECTL_GPIO_NUM (8 * 12 + 5)     /* GPIO12_5 */

#else
#error YOU MUST DEFINE  BOARD_TYPE!
#endif
#elif  defined (CHIP_TYPE_hi3716mv101) || defined (CHIP_TYPE_hi3716m)
#define SYS_PINSHARED_ADDR 0x10203000
#define SIO_DEV_NUMBER 0
#if defined (BOARD_TYPE_hi3716mdmo) || defined (BOARD_TYPE_hi3716mstb)  || defined (BOARD_TYPE_hi3716mdmo3avera)
#define tsi0_vi0_gpio 0x158
#define MUTECTL_PINSHARED_OFFSET tsi0_vi0_gpio
#define MUTECTL_MASK 0x3
#define MUTECTL_BITS 0x3
#define MUTECTL_GPIO_NUM (8 * 12 + 5)     /* GPIO12_5 */

#else
#error YOU MUST DEFINE  BOARD_TYPE!
#endif
#else
#define   CHIP_TYPE_NOTHING

//#error YOU MUST DEFINE CHIP_TYPE !
#endif

#if  defined (CHIP_TYPE_hi3716mv101) || defined (CHIP_TYPE_hi3716hv101)|| defined (CHIP_TYPE_hi3716cv101) || defined (CHIP_TYPE_hi3716m)
        /* ALL pilot chip is same for SPDIF OUT */
#define spdif_gpio 0x1c
#elif  defined (CHIP_TYPE_hi3716mv100) || defined (CHIP_TYPE_hi3716hv100)|| defined (CHIP_TYPE_hi3716cv100) || defined (CHIP_TYPE_hi3720v100) || defined (CHIP_TYPE_hi3716c)
        /* ALL mpw chip is same for SPDIF OUT */
#define spdif_gpio 0x40
#else
#error YOU MUST DEFINE  CHIP_TYPE FOR SPDIF!
#endif
#define SPDIF_PINSHARED_OFFSET spdif_gpio
#define SPDIF_MASK 0x3
#define SPDIF_BITS 0x1

        /*************************** Structure Definition ****************************/

        /********************** Global Variable declaration **************************/

        /******************************* API declaration *****************************/
        HI_S32 SetReg32Val(HI_U32 u32Base, HI_U32 u32Offset, HI_U32 u32ANDVal, HI_U32 u32ORVal);


        /**
         \brief 撤销ADAC LineOut 静音电路控制，正常工作模式必须撤销静音电路。
         \attention \n
         \see \n
        无
         */
        HI_VOID  AudioLineOutMuteCntrDisable(HI_VOID);

        /**
         \brief 使能SIO 管脚输出。
         \attention \n
         \param[in] u32SioDevNum  SIO 通道号
         \see \n
        无
         */
        HI_VOID  AudioSIOPinSharedEnable(HI_U32 u32SioDevNum);

        /**
         \brief 使能 SPDIF 管脚输出。
         \attention \n
         \see \n
        无
         */
        HI_VOID  AudioSPDIFOutSharedEnable(HI_VOID);

#ifdef __cplusplus
}
#endif
#endif /* __SAMPLE_AUDIO_PUB_H__ */
