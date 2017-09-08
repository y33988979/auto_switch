/**
 \file
 \brief helper config head file
 \author ychen
 \date 2015.11.16
 */
#ifndef __HLP_CONFIG_H__
#define __HLP_CONFIG_H__

#include <common.h>
#include <config.h>
#include <hlp_core.h>


typedef struct _hlp_conf
{
    U32  poweron_duration;
    U32  interval_time;
    U32  total_count;  //test
    S8   keyword[64];
    S8   mount_path[128];
    U32  isInit;
    
}hlp_conf_t;

S32 hlp_config_init();
S32 hlp_config_set_mount_path(S8 *mount_path);
S32 hlp_config_get_mount_path(S8 *mount_path);
S32 hlp_config_load(S8 *conf_file);
S32 hlp_config_is_ok();
void hlp_config_get(hlp_conf_t *config);

#endif /* __HLP_CONFIG_H__ */

