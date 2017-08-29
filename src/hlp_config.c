/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */


#include <hlp_debug.h>
#include <hlp_config.h>

hlp_conf_t g_hlp_conf;

S32 hlp_config_print()
{
    HLP_INFO(HLP_MOD_CONFIG, "=======config=======");
    HLP_INFO(HLP_MOD_CONFIG, "poweron_duration: %d", g_hlp_conf.poweron_duration);
    HLP_INFO(HLP_MOD_CONFIG, "interval_time: %d", g_hlp_conf.interval_time);
    HLP_INFO(HLP_MOD_CONFIG, "switch_count: %d", g_hlp_conf.total_count);
    HLP_INFO(HLP_MOD_CONFIG, "keyword: %s", g_hlp_conf.keyword);
    return 0;
}

S32 hlp_config_is_ok()
{
    S32 ret = 1;
    if(g_hlp_conf.poweron_duration <= 5
        || g_hlp_conf.poweron_duration > 120) {
        ret = 0;
        HLP_ERROR(HLP_MOD_CONFIG, "poweron_duration[%d] must be [10~120]!", \
            g_hlp_conf.poweron_duration);
    }
        
    if(g_hlp_conf.interval_time <= 3
        || g_hlp_conf.interval_time > 30) {
        ret = 0;
        HLP_ERROR(HLP_MOD_CONFIG, "interval_time[%d] must be [3~30]!", \
            g_hlp_conf.poweron_duration);
    }

    if(g_hlp_conf.keyword)
        
    return ret;
}

S32 hlp_config_set_mount_path(S8 *mount_path)
{
    if(mount_path)
        hlp_strcpy(g_hlp_conf.mount_path, mount_path);
    return 0;
}

S32 hlp_config_get_mount_path(S8 *mount_path)
{
    if(mount_path)
        hlp_strcpy(mount_path, g_hlp_conf.mount_path);
    return 0;
}

S32 hlp_config_load(S8 *conf_file)
{
    S32 n = 20;
    S32 value = 0;
    S8 option[1024];
    S8 buffer[1024];
    FILE *fp = NULL;

    //hlp_config_init();
    
    fp = fopen(conf_file, "r");
    if(fp == NULL) {
        HLP_ERROR(HLP_MOD_CONFIG, "fopen error! errno=%d:%s", errno, strerror(errno));
		return -1;
    }
    
    while(n--) {
        
        memset(buffer, 0, sizeof(buffer));
        if(fgets(buffer, sizeof(buffer), fp)) {
            sscanf(buffer, "%s %d", option, &value);
            HLP_INFO(HLP_MOD_CONFIG, "name=%s, val=%d", option, value);

            if(hlp_strcmp(option, "poweron_duration") == 0) {
                g_hlp_conf.poweron_duration = value;
            }else if(hlp_strcmp(option, "interval_time") == 0) {
                g_hlp_conf.interval_time = value;
            }else if(hlp_strcmp(option, "total_count") == 0) {
                g_hlp_conf.total_count = value;
            }else if(hlp_strcmp(option, "keyword") == 0) {
                sscanf(buffer, "%s %s", option, g_hlp_conf.keyword);
            }
        }
        else
            break;
    }
    fclose(fp);

    hlp_config_print();

    return 0;
}

void hlp_config_get(hlp_conf_t *config)
{
    hlp_memcpy(config, &g_hlp_conf, sizeof(hlp_conf_t));
}

S32 hlp_config_init()
{
    hlp_memset(&g_hlp_conf, 0, sizeof(hlp_conf_t));
    return 0;
}

