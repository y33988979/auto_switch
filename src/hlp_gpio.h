/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_GPIO_H__
#define __HLP_GPIO_H__


#include <common.h>
#include <config.h>
#include <hlp_core.h>

#define MULIT_CONFIG_BASE       (0x10203000)

#define GPIO_IN                  1
#define GPIO_OUT                 0

/* the max number of each group */
#define GPIO_NUM_OF_GROUP		 8

/* gpio address and number */
#define GPIO7_4_NO               (7*GPIO_NUM_OF_GROUP+4)
#define GPIO7_4_ADDR             0x009C     //bits[1:0]   10:GPIO7_4
#define GPIO9_6_NO               (9*GPIO_NUM_OF_GROUP+6)
#define GPIO9_6_ADDR             0x0164     //bits[2:0]   011:GPIO9_6
#define GPIO7_5_NO               (7*GPIO_NUM_OF_GROUP+5)
#define GPIO7_5_ADDR             0x009C     //bits[1:0]   10:GPIO7_5
#define GPIO3_7_NO               (3*GPIO_NUM_OF_GROUP+7)
#define GPIO3_7_ADDR             0x0098     //bits[1:0]   10:GPIO3_7

/* Peripheral gpio number */
#define GPIO_POWER_SWITCH_NO     GPIO7_4_NO
#define GPIO_BUZZER_NO           GPIO9_6_NO
#define GPIO_GREEN_LED_NO        GPIO7_5_NO
#define GPIO_RED_LED_NO          GPIO3_7_NO

/* Peripheral gpio address */
#define GPIO_POWER_SWITCH_ADDR   GPIO7_4_ADDR
#define GPIO_BUZZER_ADDR         GPIO9_6_ADDR
#define GPIO_GREEN_LED_ADDR      GPIO7_5_ADDR
#define GPIO_RED_LED_ADDR        GPIO3_7_ADDR

#define LED_LIGHT_BLANK          0
#define LED_LIGHT_RED            1
#define LED_LIGHT_GREEN          2

extern hlp_u8_t hlp_led_status;

hlp_s32_t hlp_buzzer_ringon();
hlp_s32_t hlp_buzzer_ringoff();
hlp_s32_t hlp_redled_on();
hlp_s32_t hlp_redled_off();
hlp_s32_t hlp_greenled_on();
hlp_s32_t hlp_greenled_off();
hlp_s32_t hlp_power_switch_on();
hlp_s32_t hlp_power_switch_off();
hlp_s32_t hlp_buzzer_ring_ms(hlp_u32_t time);
hlp_s32_t hlp_operation_success();
hlp_s32_t hlp_operation_failed();
void hlp_set_led_status(hlp_u8_t staus);
hlp_u8_t hlp_get_led_status();

hlp_s32_t hlp_gpio_init();
hlp_s32_t hlp_gpio_test();

#endif /* __HLP_GPIO_H__ */

