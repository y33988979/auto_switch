/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_LOG_H__
#define __HLP_LOG_H__


#include <common.h>
#include <config.h>
#include <hlp_file.h>
#include <hlp_core.h>

#define HLP_ERROR_LOG_PATH        "./runlog/"

#define HLP_LOG_STDERR            0
#define HLP_LOG_EMERG             1
#define HLP_LOG_ALERT             2
#define HLP_LOG_CRIT              3
#define HLP_LOG_ERR               4
#define HLP_LOG_WARN              5
#define HLP_LOG_NOTICE            6
#define HLP_LOG_INFO              7
#define HLP_LOG_DEBUG             8

typedef struct hlp_log_s   hlp_log_t;

struct hlp_log_s
{
	hlp_u8_t     log_level;
	hlp_file_t  *file;
	
};

hlp_s32_t hlp_log_init();
hlp_s32_t hlp_log_close();
hlp_s32_t hlp_log_write(hlp_s8_t *logstr, hlp_u32_t len);
hlp_s32_t hlp_log_error_core(hlp_u8_t level, const char *fmt, ...);

#define LOG_WRITE_ERR(format, args...)   hlp_log_error_core(HLP_LOG_ERR, format, ##args )


#endif /* __HLP_LOG_H__ */

