/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#include <hlp_burnin.h>
#include <hlp_string.h>
#include <hlp_uart.h>
#include <hlp_panel.h>
#include <hlp_uart_command.h>
#include <hlp_gpio.h>
#include <hlp_log.h>
//#include "drv_basic.h"
//#include "yspanel.h"


#define HLP_BURNIN_CONF_PATH        "/root/HI3716/conf/burnin.conf"
#define HLP_BURNIN_CONF_USB_PATH    "/media/volume01/burnin.conf"

hlp_bool_t  burnin_start = HLP_FALSE;
extern hlp_u32_t panel_last_key_time;
extern hlp_u32_t uart_last_send_time;
extern hlp_bool_t  g_uart_need_parse;
extern hlp_bool_t  g_uart_heartbeat_recv;
extern hlp_panel_menu_t *g_main_menu;
extern void DRV_LED_DisplayTime(hlp_u32_t hour, hlp_u32_t min);


hlp_burnin_task_t  g_burnin_task;
hlp_burnin_conf_t  g_burnin_conf = 
{
	1,       /* total_time */
	1,       /* interval_time */
	8,       /* total_count */
	1,       /* capture_log */
	0,       /* conf_items_num */
	{
		{"total_time", "10"},
		{"interval_time", "1"},
		{"total_count", "5"},
		{"capture_log", "1"}
	}
};

hlp_u32_t hlp_time_ms()
{
	hlp_u32_t      tmptm = 0;
	struct timeval tm = {0, 0};
	static struct timeval tmstart = {0, 0};

	if (!tmstart.tv_sec && !tmstart.tv_usec)
	{
		gettimeofday(&tmstart,NULL);
		return 0;
	}

	gettimeofday(&tm, NULL);
	tmptm = (tm.tv_sec-tmstart.tv_sec) * 1000 + (tm.tv_usec-tmstart.tv_usec) / 1000;

	return tmptm;
}

hlp_u32_t hlp_get_burnin_remainder_time_min()
{
	hlp_u32_t      current_time = 0;
	hlp_u16_t      min = 0;
	
	current_time = hlp_time_ms(); 
	current_time = current_time-g_burnin_task.start_time;
	min = g_burnin_conf.total_time - current_time/(1000*60);
	return min;
}

hlp_u16_t hlp_get_burnin_total_time()
{
	return g_burnin_conf.total_time;
}

hlp_u16_t hlp_get_burnin_current_time()
{
	return g_burnin_task.current_time;
}

hlp_u16_t hlp_get_burnin_interval_time()
{
	return g_burnin_conf.interval_time;
}

hlp_u16_t hlp_get_burnin_current_count()
{
	return g_burnin_task.current_count;
}


hlp_u16_t hlp_get_burnin_total_count()
{
	return g_burnin_conf.total_count;
}

hlp_u16_t hlp_get_burnin_isCapture_log()
{
	return g_burnin_conf.capture_log;
}

void help_led_flashing()
{
	static hlp_u16_t n = 0;
	if(n++ % 2 == 0)
	{
		hlp_redled_off();
		hlp_greenled_on();
	}
	else
	{
		hlp_redled_off();
		hlp_greenled_off();
	}
}

void hlp_burnin_print_config()
{
	hlp_burnin_conf_t       *conf = &g_burnin_conf;
	printf("[burnin-config]:total_time=%d.\n", conf->total_time);
	printf("[burnin-config]:interval_time=%d.\n", conf->interval_time);
	printf("[burnin-config]:total_count=%d.\n", conf->total_count);
	printf("[burnin-config]:capture_log=%d.\n", conf->capture_log);
	LOG_WRITE_ERR("[burnin-config]:total_time=%d.\n", conf->total_time);
	LOG_WRITE_ERR("[burnin-config]:interval_time=%d.\n", conf->interval_time);
	LOG_WRITE_ERR("[burnin-config]:total_count=%d.\n", conf->total_count);
	LOG_WRITE_ERR("[burnin-config]:capture_log=%d.\n", conf->capture_log);
}

hlp_s32_t hlp_burnin_load_config()
{
	FILE       *fp = NULL;
	hlp_s8_t    i = 0;
	hlp_s8_t    buffer[128];
	hlp_s8_t    option[32] = {0};
	hlp_s8_t    value[32] = {0};
	hlp_u16_t  *pValue = NULL;
	hlp_burnin_conf_t       *conf = &g_burnin_conf;
	hlp_burnin_conf_item_t  *conf_item = conf->conf_items;

	if((fp = fopen(HLP_BURNIN_CONF_PATH, "r")) == NULL)
	{
		printf("[testhelper]: fopen \"%s\" error, errstr=%s\n", HLP_BURNIN_CONF_PATH, strerror(errno));
		LOG_WRITE_ERR("[testhelper]: fopen \"%s\" error, errstr=%s\n", HLP_BURNIN_CONF_PATH, strerror(errno));
		return HLP_ERROR;
	}
	
	i = 0;
	conf->conf_items_num = 0;
	pValue = &conf->total_time;
	while(fgets((char*)buffer, sizeof(buffer), fp) != NULL)
	{
		/* Warning! */
		if(hlp_strstr(buffer, "#") != NULL)
			continue;
		hlp_memset(option, 0, sizeof(option));
		hlp_memset(value, 0, sizeof(value));
		sscanf((char*)buffer, "%s %s\n", (char*)option, (char*)value);
		printf("option=%s, value=%s.\n", option, value);
		LOG_WRITE_ERR("option=%s, value=%s.\n", option, value);
		
		for(i=0; i<4; i++)
		{
			if(hlp_strcmp(conf_item[i].option, option) == 0)
			{
				hlp_strcpy(conf_item[i].value, value);
				
				*pValue++ = atoi((char*)value);
				conf->conf_items_num++;
			}
		}
	}
	pValue = (hlp_u16_t*)conf;
	hlp_burnin_print_config();
	
	printf("[testhelper]: load config done ! total_item=%d!\n", conf->conf_items_num);
	LOG_WRITE_ERR("[testhelper]: load config done ! total_item=%d!\n", conf->conf_items_num);
	fclose(fp);

	return HLP_OK;
}

void* hlp_burnin_task(void *args)
{
	hlp_u32_t      current_time = 0;
	hlp_u16_t      hour = 0;
	hlp_u16_t      min = 0;
	hlp_u16_t      heartbeat_drop_count = 0;
	
	hlp_burnin_conf_t       *burnin_conf = &g_burnin_conf;
	hlp_burnin_task_t       *burnin_task = &g_burnin_task;
	//hlp_burnin_conf_item_t  *conf_item = burnin_conf->conf_items;
	
	while(1)
	{
		if(burnin_start == HLP_FALSE)
		{
			sleep(1);
			continue;
		}
		
		current_time = hlp_time_ms(); 
		burnin_task->current_time = current_time-burnin_task->start_time;
		if(burnin_task->current_time*1000 >= burnin_conf->total_time*60)
		{
			if(burnin_task->current_count == burnin_conf->total_count)
			{
				hlp_burnin_task_stop();
				heartbeat_drop_count = 0;
				panel_show_main_menu();
				panel_led_show_string("oooo");
				printf("[testhelper]: hlp_burnin_task done! total_count=%d\n", burnin_conf->total_count);
				LOG_WRITE_ERR("[testhelper]: hlp_burnin_task done! total_count=%d\n", burnin_conf->total_count);
			}
			else
			{
				hlp_burnin_task_stop();
				panel_led_show_string("----");
				heartbeat_drop_count = 0;
				sleep(burnin_conf->interval_time);
				burnin_task->current_count++;
				hlp_burnin_task_start();
				printf("[testhelper]: hlp_burnin_task start! current_count=%d\n", burnin_task->current_count);
				LOG_WRITE_ERR("[testhelper]: hlp_burnin_task start! current_count=%d\n", burnin_task->current_count);
			}
			continue;
		}
		/*
		printf("t1=%d, t2=%d, t3=%d, ms=%d\n", \
			burnin_task->current_time, burnin_conf->total_time*(60*1000),\
			burnin_task->current_count, current_time);
		printf("[DisplayTime]: hour=%d, min=%d\n", hour, min);
		*/
		/* xx秒内未发生按键，显示拷机剩余时间 */
		if(current_time - panel_last_key_time >= 10*1000)
		{	
			min = hlp_get_burnin_remainder_time_min();
			hour = min / 60;
			min = min % 60;
			//printf("[DisplayTime]: hour=%d, min=%d\n", hour, min);
			DRV_LED_DisplayTime(hour, min);
		}


		if(g_uart_heartbeat_recv == HLP_TRUE)
		{
			g_uart_need_parse = HLP_FALSE;
			heartbeat_drop_count = 0;
		}
		else
		{
			heartbeat_drop_count++;
			if(heartbeat_drop_count == 5000)  //心跳断了
			{
				printf("HeartBeat drop [50times] Burn stop!!!\n");
				LOG_WRITE_ERR("HeartBeat drop [50times] Burn stop!!!\n");
				hlp_burnin_task_stop();
				hlp_greenled_off();
				hlp_redled_on();
				hlp_buzzer_ring_ms(5000);
			}
		}

		/* led shanshou */
		help_led_flashing();

		sleep(1);
	}
}

void hlp_burnin_task_start()
{
	burnin_start = HLP_TRUE;
	hlp_uart_recv_status_set(UART_RECV_START);
	g_burnin_task.start_time = hlp_time_ms();
	uart_last_send_time = g_burnin_task.start_time;
	g_burnin_task.current_time = 0;
	g_burnin_task.end_time = 0;
	hlp_power_switch_on();
	printf("-----poweron-----!!!\n");
	LOG_WRITE_ERR("-----poweron-----!!!\n");
}

void hlp_burnin_task_stop()
{
	burnin_start = HLP_FALSE;
	hlp_power_switch_off();
	hlp_uart_recv_status_set(UART_RECV_STOP);
	g_burnin_task.end_time = hlp_time_ms();
	panel_led_show_string("----");
}

hlp_s32_t hlp_burnin_init()
{
	int        ret;
	pthread_t  tid;

	burnin_start = HLP_FALSE;
	if(hlp_burnin_load_config() != HLP_OK)
	{
		printf("hlp_burnin_start error! load config failed!\n");
		LOG_WRITE_ERR("hlp_burnin_start error! load config failed!\n");
		return HLP_ERROR;
	}

	g_burnin_task.burnin_conf = &g_burnin_conf;
	g_burnin_task.current_count = 1;
	ret = pthread_create(&tid, NULL, (void * (*)(void*)) hlp_burnin_task, (void*)NULL);
	if(ret < 0)
	{
		perror("pthread_create hlp_burnin_start error:");
		LOG_WRITE_ERR("pthread_create hlp_burnin_start error: %s", strerror(errno));
		return HLP_ERROR;
	}
	
	sleep(1);
	printf("Start hlp_burnin_start success! [0x%x]\n", (int)&tid);
	LOG_WRITE_ERR("Start hlp_burnin_start success! [0x%x]\n", (int)&tid);
	return HLP_OK;
}



int hlp_burnin_test()
{
	return 0;
}

