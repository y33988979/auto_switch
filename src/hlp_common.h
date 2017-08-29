/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_COMMON_H__
#define __HLP_COMMON_H__


#include <hlp_config.h>
#include <hlp_core.h>

hlp_s32_t hlp_get_dir_file_num(hlp_s8_t *path);
hlp_bool_t hlp_file_isexist(hlp_s8_t *path, hlp_s8_t *filename);
void hlp_get_current_time_string(hlp_s8_t *timeString);
void hlp_get_current_date_string(hlp_s8_t *dateString);
void hlp_get_current_datetime_string(hlp_s8_t *dateString);
void hlp_msleep(hlp_u32_t Delay);
void hlp_time_init();
U32 hlp_time_ms();
S32 hlp_mkdir(S8 *path);
S32 hlp_rmdir(S8 *path);
S32 hlp_rootfs_init();
S32 hlp_common_init();


#endif /* __HLP_COMMON_H__ */

