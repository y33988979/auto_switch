/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */

#include <hlp_debug.h>
#include <hlp_serial.h>
#include <hlp_common.h>
#include <hlp_gpio.h>
#include <hlp_logfile.h>
#include <hlp_config.h>
#include <hlp_udisk.h>
#include <hlp_panel.h>
#include <hlp_switch.h>

extern hlp_u32_t  panel_last_key_time;

static hlp_conf_t g_config = {0};
static switch_task_t  g_switch_task;
static work_status_e  work_status = STATUS_FREE;
static U32 auto_test_start = 0;

S32 hlp_switch_task_start()
{   
    S32 mount_ok;
    S32 config_ok;
    
    if(auto_test_start == HLP_TRUE) {
        HLP_INFO(HLP_MOD_SWITCH, "test have already start!");
        return 0;
    }

    panel_led_show_default_enable(HLP_TRUE, 8);
    
    mount_ok = hlp_udisk_mount_ok();
    config_ok = hlp_config_is_ok();
    if(mount_ok && !config_ok)
        udisk_plugin_handle();
    
    config_ok = hlp_config_is_ok();
    if(mount_ok && config_ok) {
        auto_test_start = HLP_TRUE;
    	g_switch_task.start_time = hlp_time_ms();
    	g_switch_task.current_time = 0;
    	g_switch_task.end_time = 0;
        g_switch_task.keyword_is_detected = 0;
        g_switch_task.current_count = 0;
        hlp_config_get(&g_config);
        keyword_set_detected(0);
        hlp_serial_capture_start();
    	hlp_power_switch_on();
        panel_led_show_number(0);
    	HLP_INFO(HLP_MOD_SWITCH, "test start! poweron.");
        return 0;
    }
    else {
        if(!mount_ok) {
            panel_led_show_string("disk");
            HLP_ERROR(HLP_MOD_SWITCH, "test start failed!\n please plugin udisk!");
        }      
        else if(!config_ok){
            hlp_config_print();
            panel_led_show_string("conf");
            HLP_ERROR(HLP_MOD_SWITCH, "test start failed!\n please check config: %s!",\
            HLP_CONFIG_NAME);
        }
            
        return -1;
    }
}

S32 hlp_switch_task_stop()
{
    if(auto_test_start == HLP_FALSE) {
        HLP_INFO(HLP_MOD_SWITCH, "test have already stop!");
        return 0;
    }

    panel_led_show_default_enable(HLP_FALSE, 0);
	auto_test_start = HLP_FALSE;
    hlp_serial_capture_stop();
	g_switch_task.end_time = hlp_time_ms();
    HLP_INFO(HLP_MOD_SWITCH, "test stop! poweroff. take %d seconds", \
        (g_switch_task.end_time-g_switch_task.start_time)/1000);
    return 0;
}

S32 hlp_switch_once_start(hlp_conf_t *config)
{
    hlp_power_switch_on();
    hlp_serial_capture_resume();
    keyword_set_detected(0);
}

S32 hlp_switch_once_stop(hlp_conf_t *config)
{
    S32 found;
    hlp_power_switch_off();
    hlp_serial_capture_suspend();

    /* find keyword in serial log */
    found = hlp_serial_find_keywork(NULL, config->keyword);
    if(found) {
        keyword_set_detected(1);
        HLP_INFO(HLP_MOD_SWITCH, "found keyword! [%s]", config->keyword);
    }else {
        keyword_set_detected(0);
        HLP_INFO(HLP_MOD_SWITCH, "found not keyword! [%s]", config->keyword);
    } 
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

#if (SERIAL_ANALYZE_SUPPORT)
void* hlp_switch_thread(void *args)
{
	hlp_u32_t      current_time = 0;
	hlp_u16_t      hour = 0;
	hlp_u16_t      min = 0;
	hlp_u16_t      heartbeat_drop_count = 0;
    hlp_conf_t    *config = &g_config;
	switch_task_t   *switch_task = &g_switch_task;
    	
	while(1)
	{
		if(auto_test_start == HLP_FALSE)
		{
			sleep(1);
			continue;
		}
		
        current_time = hlp_time_ms(); 
        switch_task->current_time = current_time-switch_task->start_time;
        if(switch_task->current_time/1000 % config->poweron_duration == 0 \
            && switch_task->current_time/1000 != 0)
        {
            panel_led_show_number(++switch_task->current_count);
            hlp_switch_once_stop(config);
            if(!keyword_is_detected()) {
                hlp_buzzer_ring_ms(1000);
                hlp_switch_task_stop();
                HLP_ERROR(HLP_MOD_SWITCH, "test stop, becase no keyword[%s]!", config->keyword);
                continue;
            }

            /* all done */
            if(switch_task->current_count == config->total_count)
            {
                hlp_power_switch_off();
                hlp_buzzer_ring_ms(300);
                hlp_switch_task_stop();
                heartbeat_drop_count = 0;
                HLP_INFO(HLP_MOD_SWITCH, "hlp_switch_task_stop! total_count=%d", config->total_count);
            }
            else
            {
                heartbeat_drop_count = 0;
                sleep(config->interval_time);
                hlp_switch_once_start(config);
                HLP_INFO(HLP_MOD_SWITCH, "hlp_switch_task_start! current_count=%d", switch_task->current_count);
            }
            continue;
        }

		/*
		printf("t1=%d, t2=%d, t3=%d, ms=%d\n", \
			burnin_task->current_time, burnin_conf->total_time*(60*1000),\
			burnin_task->current_count, current_time);
		printf("[DisplayTime]: hour=%d, min=%d\n", hour, min);
		*/
		
		/* xx秒内未发生按键，显示拷机剩余次数 */
		if(current_time - panel_last_key_time >= 5*1000)
		{	
		    #if 0
			min = hlp_get_burnin_remainder_time_min();
			hour = min / 60;
			min = min % 60;
            panel_led_show_time(hour, min);
            #endif
            panel_led_show_number(switch_task->current_count);
		}


		{
			heartbeat_drop_count++;
			if(heartbeat_drop_count == 500000)  //心跳断了
			{
                HLP_ERROR(HLP_MOD_SWITCH, "heartbeat drop!");
                hlp_power_switch_off();
				hlp_switch_task_stop();
				hlp_greenled_off();
				hlp_redled_on();
				hlp_buzzer_ring_ms(5000);
			}
		}

		/* led flashing */
		//help_led_flashing();

		sleep(1);
	}
}

#else
static S32 test_flag = 0;
static void hlp_switch_onoff()
{
    if(test_flag == 0)
        test_flag = 1;
}

#define SHELL "[Command #] "
void* hlp_switch_thread(void *args)
{
    S32  i,len = 0;
    S8   buffer[2048];
    S8  *ptr = NULL;
    U32  last_time_ms;
    U32  time_ms;
    
    memset(buffer, 0, sizeof(buffer));
    printf(SHELL);
    fflush(stdout);

    last_time_ms = hlp_time_ms();
    while(fgets(buffer, sizeof(buffer), stdin)) {
        
        /* do nothing, print bash */
        if(buffer[0] == '\n') {
            printf(SHELL);
            fflush(stdout);
            continue;
        }

        len = strlen(buffer);
        buffer[len-1] = '\0';
        len--;
        printf("recv command: %s\n", buffer);

        time_ms = hlp_time_ms();
        if(time_ms - last_time_ms < HLP_COMMAND_INTERVAL_MIN) {
            last_time_ms = time_ms;
            printf("command speed so quick! min_interval=50ms\n");
            continue;
        }
        last_time_ms = time_ms;
        
        if(strncmp(buffer, "poweron", 7) == 0) {
            hlp_power_switch_on();
        }else if(strncmp(buffer, "poweroff", 8) == 0) {
            hlp_power_switch_off();
        }else if(strncmp(buffer, "buzzeron", 8) == 0) {
            hlp_buzzer_ringon();
        }else if(strncmp(buffer, "buzzeroff", 9) == 0) {
            hlp_buzzer_ringoff();
        }else {
            /* other command */
            printf("error command!\n");
            printf("[Command #] ");
            fflush(stdout);
        }

    }

    /* error */
    perror("fgets error:");
}

#endif //SERIAL_ANALYZE_SUPPORT

S32 hlp_switch_init()
{
    pthread_t switch_tid;

    if(pthread_create(&switch_tid, NULL, (void*)hlp_switch_thread, NULL) < 0) {
        HLP_ERROR(HLP_MOD_SWITCH, "switch_thread create error! errno=%d:%s", errno, strerror(errno));
		return -1;
    }
    
    HLP_INFO(HLP_MOD_SWITCH, "switch_thread start success!");

    return 0;
}


