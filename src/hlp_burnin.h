/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_BURNIN_H__
#define __HLP_BURNIN_H__


#include <hlp_config.h>
#include <hlp_core.h>


typedef struct hlp_burnin_conf_item
{
	hlp_s8_t option[32];
	hlp_s8_t value[32];
}hlp_burnin_conf_item_t;

typedef struct hlp_burnin_conf
{
	hlp_u16_t               total_time; /* second */
	hlp_u16_t               interval_time;
	hlp_u16_t               total_count;
	hlp_u16_t               capture_log;
	hlp_u16_t               conf_items_num;
	hlp_burnin_conf_item_t  conf_items[16];
}hlp_burnin_conf_t;

typedef struct hlp_burnin_task
{
	hlp_u32_t               current_time;
	hlp_u32_t               start_time;
	hlp_u32_t               end_time;
	hlp_u16_t               current_count;
	hlp_u16_t               step;
	hlp_burnin_conf_t      *burnin_conf;
}hlp_burnin_task_t;

hlp_s32_t hlp_burnin_init();
void hlp_burnin_task_stop();
void hlp_burnin_task_start();
hlp_u16_t hlp_get_burnin_total_time();
hlp_u16_t hlp_get_burnin_current_time();
hlp_u16_t hlp_get_burnin_interval_time();
hlp_u16_t hlp_get_burnin_current_count();
hlp_u16_t hlp_get_burnin_total_count();
hlp_u16_t hlp_get_burnin_isCapture_log();
hlp_u32_t hlp_get_burnin_remainder_time_min();
void hlp_burnin_print_config();
hlp_s32_t hlp_burnin_load_config();


#endif /* __HLP_BURNIN_H__ */

