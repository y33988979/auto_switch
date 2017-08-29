/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_SERIAL_H__
#define __HLP_SERIAL_H__

#include <common.h>
#include <config.h>
#include <hlp_core.h>

typedef struct _serial_buffer
{
    S8   data[256*1024];
    U32  data_len;
    U32  write_pos;
    U32  size;
}serial_buffer_t;

S32 serial_buffer_init();
S32 serial_buffer_reset();
S32 serial_buffer_put(S8 *data, U32 len);
S32 hlp_serial_find_keywork(S8 *src, S8 *keyword);
void keyword_set_detected(U32 is_detected);
U32 keyword_is_detected();

S32 hlp_serial_init();
void hlp_serial_capture_start();
void hlp_serial_capture_stop();
void hlp_serial_capture_suspend();
void hlp_serial_capture_resume();

#endif /* __HLP_SERIAL_H__ */

