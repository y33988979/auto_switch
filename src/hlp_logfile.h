/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_LOGFILE_H__
#define __HLP_LOGFILE_H__

#include <common.h>
#include <config.h>
#include <hlp_core.h>

typedef struct _logfile
{
    S32  fd;
    U32  id;
    S8   filename[64];
    U8   rbuffer[4096];
    U8   rlen;
    U32  file_size;
    
}logfile_t;

S32 hlp_logfile_init();
logfile_t* hlp_logfile_create(S8 *filename);
S32 hlp_logfile_fsync(logfile_t* logfile);
void hlp_logfile_destory(logfile_t* logfile);
U32 hlp_logfile_size(logfile_t *logfile);
S32 hlp_logfile_write(logfile_t* logfile, S8 *data, U32 len);


#endif /* __HLP_LOGFILE_H__ */

