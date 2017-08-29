/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */

#include <hlp_debug.h>
#include <hlp_logfile.h>

logfile_t* hlp_logfile_create(S8 *filename)
{
    logfile_t *logfile = NULL;
    
    logfile = (logfile_t*)malloc(sizeof(logfile_t));
    if(logfile == NULL) {
        HLP_ERROR(HLP_MOD_LOGFILE, "malloc error! errno=%d:%s", errno, strerror(errno));
        return NULL;
    }

    memset(logfile, 0, sizeof(logfile_t));
    
    logfile->id++;
    hlp_strcpy(logfile->filename, filename);
    logfile->fd = open(filename, O_CREAT|O_WRONLY);
    if(logfile->fd < 0) {
        free(logfile);
        HLP_ERROR(HLP_MOD_LOGFILE, "open %s error! errno=%d:%s", filename, errno, strerror(errno));
        return NULL;
    }
    
    HLP_INFO(HLP_MOD_LOGFILE, "open file: %s", filename);

    return logfile;
}

S32 hlp_logfile_fsync(logfile_t* logfile)
{
    S32 ret;
    ret = fsync(logfile->fd);
    if(ret < 0)
        HLP_ERROR(HLP_MOD_LOGFILE, "fsync error! errno=%d:%s ", errno, strerror(errno));
    return ret;
}

void hlp_logfile_destory(logfile_t* logfile)
{
    if(logfile) {
        close(logfile->fd);
        free(logfile);
    }
}

U32 hlp_logfile_size(logfile_t *logfile)
{
    struct stat st;

    if(fstat(logfile->fd, &st) < 0) {
        HLP_ERROR(HLP_MOD_LOGFILE, "fstat error! errno=%d:%s", errno, strerror(errno));
        return 0;
    }
    
    return st.st_size;
}

S32 hlp_logfile_write(logfile_t* logfile, S8 *data, U32 len)
{
    S32 nwrite = 0;    
    nwrite = write(logfile->fd, data, len);
    if(nwrite < 0) {
        HLP_ERROR(HLP_MOD_LOGFILE, "write error! errno=%d:%s", errno, strerror(errno));
        return -1;
    }
    logfile->file_size = hlp_logfile_size(logfile);
    
    return nwrite;
}

S32 hlp_logfile_init()
{

    return 0;
}


