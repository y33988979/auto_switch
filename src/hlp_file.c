/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#include <hlp_file.h>


ssize_t hlp_file_read(hlp_file_t *file, u_char *buffer, size_t len)
{
	ssize_t rSize;
	if((rSize = read(file->fd, buffer, len)) < 0)
	{
		perror("hlp_file_read error:");
	}
	return rSize;
}

ssize_t hlp_file_write(hlp_file_t *file, u_char *buffer, size_t len)
{
	ssize_t wSize;
	if((wSize = write(file->fd, buffer, len)) < 0)
	{
		perror("hlp_file_write error:");
	}
	return wSize;
}



int hlp_file_test()
{
	return 0;
}

