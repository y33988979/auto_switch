/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */

#include <common.h>
#include <hlp_debug.h>
#include <hlp_gpio.h>
#include <hi_common.h>
#include "hi_unf_ecs.h"


#define hlp_gpio_num_calc(group, index)   (group*8+index)
#define LED_INTERVAL_TIME  100000

hlp_u8_t hlp_led_status = LED_LIGHT_BLANK;

hlp_s32_t hlp_gpio_config(hlp_u32_t gpio_addr)
{
	hlp_u32_t ret = 0;
	hlp_u32_t gpio_regvalue = 0;

	/* gpio config */
	ret = HI_SYS_ReadRegister(MULIT_CONFIG_BASE + gpio_addr, &gpio_regvalue);
	switch(gpio_addr)
	{
		case GPIO_BUZZER_ADDR:
			gpio_regvalue &= 0xFFFFFFF8;
			gpio_regvalue |= 0x03;
			break;
		case GPIO_RED_LED_ADDR:
		case GPIO_GREEN_LED_ADDR:
		//case GPIO_POWER_SWITCH_ADDR:
			gpio_regvalue &= 0xFFFFFFFC;
			gpio_regvalue |= 0x02;
			break;
		default:
			break;
	}
	ret |= HI_SYS_WriteRegister(MULIT_CONFIG_BASE + gpio_addr, gpio_regvalue);
	//printf("hlp_gpio_config ret=%d\n", ret);
	return ret;
}


hlp_s32_t hlp_gpio_read(hlp_u32_t gpioNO, hlp_u32_t *gpio_value)
{
	hlp_s32_t  ret = 0;

	//printf("hlp_gpio_read GpioNo=%d, value=%d\n", gpioNO, *gpio_value);
	//ret = HI_UNF_GPIO_Open();
	ret |= HI_UNF_GPIO_SetDirBit(gpioNO, GPIO_IN);
	ret |= HI_UNF_GPIO_ReadBit(gpioNO, gpio_value);
	//ret |= HI_UNF_GPIO_Close();
	//printf("hlp_gpio_read ret=%d\n", ret);
	return ret;
}

hlp_s32_t hlp_gpio_write(hlp_u32_t gpioNO, hlp_u32_t gpio_value)
{
	hlp_s32_t  ret = 0;

	//printf("hlp_gpio_write GpioNo=%d, value=%d\n", gpioNO, gpio_value);
	//ret = HI_UNF_GPIO_Open();
	ret |= HI_UNF_GPIO_SetDirBit(gpioNO, GPIO_OUT);
	ret |= HI_UNF_GPIO_WriteBit(gpioNO, gpio_value);
	//ret |= HI_UNF_GPIO_Close();
	//printf("hlp_gpio_write ret=%d\n", ret);
	return ret;
}

hlp_s32_t hlp_buzzer_ringon()
{
	hlp_s32_t  ret = 0;

	//ret |= hlp_gpio_config(GPIO_BUZZER_ADDR);
	ret |= hlp_gpio_write(GPIO_BUZZER_NO, 0);
	return ret;
}

hlp_s32_t hlp_buzzer_ringoff()
{
	hlp_s32_t  ret = 0;

	//ret |= hlp_gpio_config(GPIO_BUZZER_ADDR);
	ret |= hlp_gpio_write(GPIO_BUZZER_NO, 1);

	return ret;
}

hlp_s32_t hlp_redled_on()
{
	hlp_s32_t  ret = 0;

	//ret |= hlp_gpio_config(GPIO_RED_LED_ADDR);
	ret |= hlp_gpio_write(GPIO_RED_LED_NO, 1);
	hlp_led_status = LED_LIGHT_RED;
	return ret;
}

hlp_s32_t hlp_redled_off()
{
	hlp_s32_t  ret = 0;

	//ret |= hlp_gpio_config(GPIO_RED_LED_ADDR);
	ret |= hlp_gpio_write(GPIO_RED_LED_NO, 0);
	hlp_led_status = LED_LIGHT_BLANK;
	return ret;
}

hlp_s32_t hlp_greenled_on()
{
	hlp_s32_t  ret = 0;

	//ret |= hlp_gpio_config(GPIO_GREEN_LED_ADDR);
	ret |= hlp_gpio_write(GPIO_GREEN_LED_NO, 1);
	hlp_led_status = LED_LIGHT_GREEN;
	return ret;
}

hlp_s32_t hlp_greenled_off()
{
	hlp_s32_t  ret = 0;

	//ret |= hlp_gpio_config(GPIO_GREEN_LED_ADDR);
	ret |= hlp_gpio_write(GPIO_GREEN_LED_NO, 0);
	hlp_led_status = LED_LIGHT_BLANK;
	return ret;
}

hlp_s32_t hlp_power_switch_on()
{
	hlp_s32_t  ret = 0;

	//ret |= hlp_gpio_config(GPIO_POWER_SWITCH_ADDR);
	ret |= hlp_gpio_write(GPIO_POWER_SWITCH_NO, 1);
	return ret;
}

hlp_s32_t hlp_power_switch_off()
{
	hlp_s32_t  ret = 0;

	//ret |= hlp_gpio_config(GPIO_POWER_SWITCH_ADDR);
	ret |= hlp_gpio_write(GPIO_POWER_SWITCH_NO, 0);
	return ret;
}

hlp_s32_t hlp_buzzer_ring_ms(hlp_u32_t time)
{
	hlp_s32_t   ret = 0;
	ret |= hlp_buzzer_ringon();
	usleep(time*1000);
	ret |= hlp_buzzer_ringoff();
	return ret;
}

void hlp_set_led_status(hlp_u8_t staus)
{
	hlp_led_status = staus;
}

hlp_u8_t hlp_get_led_status()
{
	return hlp_led_status;
}

hlp_s32_t hlp_operation_success()
{
	hlp_s32_t i, ret = 0;

	for(i=0; i<1; i++)
	{
		ret |= hlp_greenled_off();
		usleep(LED_INTERVAL_TIME);
		ret |= hlp_greenled_on();
		usleep(LED_INTERVAL_TIME);
	}
	hlp_buzzer_ring_ms(100);

	return ret;
}

hlp_s32_t hlp_operation_failed()
{
	hlp_s32_t  i, ret = 0;

	ret |= hlp_buzzer_ringon();
	//usleep(LED_INTERVAL_TIME*3);
	for(i=0; i<3; i++)
	{
		ret |= hlp_redled_off();
		usleep(LED_INTERVAL_TIME);
		ret |= hlp_redled_on();
		usleep(LED_INTERVAL_TIME);
	}
	ret |= hlp_buzzer_ringoff();
	return ret;
}

hlp_s32_t hlp_gpio_init()
{
    hlp_s32_t  ret = 0;

    ret = HI_UNF_GPIO_Open();

	ret |= hlp_gpio_config(GPIO_POWER_SWITCH_ADDR);
    ret |= hlp_gpio_config(GPIO_BUZZER_ADDR);
    ret |= hlp_gpio_config(GPIO_GREEN_LED_ADDR);
    ret |= hlp_gpio_config(GPIO_RED_LED_ADDR);
    
	hlp_redled_off();
	hlp_greenled_on();
	hlp_buzzer_ringoff();
	hlp_power_switch_off();

    if(ret == 0)
        HLP_INFO(HLP_MOD_GPIO, "GPIO7_4 GPIO7_5 GPIO9_6 GPIO3_7 config success!");
    
	return ret?-1:0;
}

hlp_s32_t hlp_gpio_test()
{
	int cnt = 10000;
	int total = cnt;

	while(cnt--)
	{
		//hlp_greenled_on();
		hlp_redled_on();
		//hlp_buzzer_ringon();
		//hlp_power_switch_on();
		//printf("gpio_on\n");
		usleep(100*1000);

		//hlp_greenled_off();
		hlp_redled_off();
		//hlp_buzzer_ringoff();
		//hlp_power_switch_off();
		//printf("gpio_off\n");
		usleep(100*1000);
		printf("gpio_test[%d]!!!!\n", total-cnt);
	}

	return 0;
}

