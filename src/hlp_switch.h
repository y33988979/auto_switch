/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_SWITCH_H__
#define __HLP_SWITCH_H__

#include <common.h>
#include <config.h>
#include <hlp_core.h>

typedef struct _switch_task
{
    U32 current_time;
    U32 start_time;
    U32 end_time;
    U32 current_count;
    U32 keyword_is_detected;
    hlp_conf_t *hlp_config;
    
}switch_task_t;

typedef enum _work_status
{
    STATUS_FREE,   
    STATUS_CHECK,  
    STATUS_TESTING,
    STATUS_WARNING,
    STATUS_STOP,
    STATUS_UNKONW
    
}work_status_e;

typedef enum _test_status
{
    TEST_READY,
    TEST_POWER_ON,   
    TEST_POWER_OFF  
    
}test_status_e;

S32 hlp_switch_init();
S32 hlp_switch_task_start();
S32 hlp_switch_task_stop();
void keyword_set_detected(U32 is_detected);
U32 keyword_is_detected();
S32 hlp_switch_once_start(hlp_conf_t *config);
S32 hlp_switch_once_stop(hlp_conf_t *config);

#endif /* __HLP_SWITCH_H__ */

