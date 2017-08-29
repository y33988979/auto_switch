/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_FILE_H__
#define __HLP_FILE_H__


#include <common.h>
#include <hlp_core.h>

/* 文件定义 */
typedef struct hlp_file_s   hlp_file_t;

struct hlp_file_s
{
	hlp_u32_t   fd;             /* file descriptor */
	hlp_u8_t    name[64];       /* file name */
	hlp_u8_t    path[128];      /* file path */
	hlp_u32_t   offset;         /* offset for read or write */
	
};

#define hlp_file_open(name, mode, access) \
	open((const char *) name, mode, access)

#define hlp_file_close close

ssize_t hlp_file_read(hlp_file_t *file, u_char *buffer, size_t len);

ssize_t hlp_file_write(hlp_file_t *file, u_char *buffer, size_t len);

#define hlp_file_rename(o, n)    rename((const char *) o, (const char *) n)

#define hlp_file_delete(name)    unlink((const char *) name)

void usb_callback_register();

int hlp_file_test();

static inline ssize_t hlp_write_fd(hlp_u32_t fd, void *buf, size_t n)
{    
	return write(fd, buf, n);
}


#endif /* __HLP_FILE_H__ */

