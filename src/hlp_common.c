/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */



#include <hlp_common.h>
#include <hlp_debug.h>

static U32 ori_timesec = 0;
void hlp_time_init()
{
    struct timeval   tv;

    if (gettimeofday(&tv, NULL) == 0)
    {
        ori_timesec =  tv.tv_sec*1000 + tv.tv_usec/1000;
    }
    else
    {
        HLP_ERROR(HLP_MOD_COMMON, "gettimeofday falied! errno=%d:%s", errno, strerror(errno));
    }

	return;
}

U32 hlp_time_ms()
{
    struct timeval  tv;
    U32    Clk = 1;	    /* Default value */

    if (gettimeofday(&tv, NULL) == 0)
    {
        Clk =  tv.tv_sec*1000 + tv.tv_usec/1000;
    }
    else
    {
        HLP_ERROR(HLP_MOD_COMMON, "gettimeofday falied! errno=%d:%s", errno, strerror(errno));
    }

    return Clk - ori_timesec;
}

void hlp_get_current_data_string(hlp_s8_t *dateString)
{
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	time_t timep;
	struct tm *p;

	time(&timep);
	p=gmtime(&timep);
	printf("%04d-%02d-%02d %02d:%02d:%02d [%s] \n",\
     (1900+p->tm_year), (1+p->tm_mon),p->tm_mday,\
     p->tm_hour, p->tm_min, p->tm_sec, wday[p->tm_wday]);
	sprintf((char*)dateString, "%04d%02d%02d", 1900+p->tm_year, p->tm_mon, p->tm_mday);
}

void hlp_get_current_time_string(hlp_s8_t *timeString)
{
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	time_t timep;
	struct tm *p;

	time(&timep);
	p=gmtime(&timep);
	printf("%04d%02d%02d",(1900+p->tm_year), (1+p->tm_mon),p->tm_mday);
	printf("%s%02d%02d%02d\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
	sprintf((char*)timeString, "%d04%02d%02d", p->tm_hour, p->tm_min, p->tm_sec);
}

void hlp_get_current_datetime_string(hlp_s8_t *datetimeString)
{
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	time_t timep;
	struct tm *p;

	time(&timep);
	p=gmtime(&timep);
	printf("%04d%02d%02d",(1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
	printf("%s%02d%02d%02d\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
	sprintf((char*)datetimeString, "%04d%02d%02d_%02d%02d%02d", \
		1900+p->tm_year, p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
}

void hlp_msleep(hlp_u32_t Delay)
{
    struct timespec x;

    /* if < 2ms */
    if (Delay <= 2)
    {
        x.tv_sec  = 0;
        x.tv_nsec = 2000001;
    }
    else
    {
        x.tv_sec  = Delay / 1000;
        x.tv_nsec = (Delay % 1000) * 1000000;
    }
    nanosleep (&x, 0);
}

hlp_s32_t hlp_get_dir_file_num(hlp_s8_t *path)
{
	struct dirent **namelist;
	int n;

	n = scandir(path, &namelist, 0, alphasort);
	if(n < 0)
	{
        HLP_ERROR(HLP_MOD_COMMON, "scandir error! path[%s], errno=%d:%s", path, errno, strerror(errno));
		return -1;
	}
	else
		return n;
}

hlp_s32_t hlp_get_filename_maxid_by_path(hlp_s8_t *path)
{
    struct dirent **namelist;
	int i, n;
    hlp_s8_t name_prefix[64];
    hlp_s8_t maxid_filename[64];
    hlp_s32_t logfile_id = 0;

    if(!path)
        return -1;

    printf("path====%s\n", path);
	n = scandir(path, &namelist, 0, alphasort);
	if(n < 0)
	{
        HLP_ERROR(HLP_MOD_COMMON, "scandir error! path[%s], errno=%d:%s", path, errno, strerror(errno));
	}
    else
	{
	    i = n;
		while(i--)
		{
		    printf("name=%s\n", namelist[i]->d_name);
		    if(hlp_strcmp(namelist[i]->d_name, ".") == 0
              || hlp_strcmp(namelist[i]->d_name, "..") == 0) {
                free(namelist[i]);
                continue;
            }

            if(logfile_id == 0) {
                if(hlp_strncmp(namelist[i]->d_name, HLP_LOG_NAME_PREFIX, \
                strlen(HLP_LOG_NAME_PREFIX)) == 0){
                    hlp_strcpy(maxid_filename, namelist[i]->d_name);
                    HLP_INFO(HLP_MOD_COMMON, "maxid_filename: %s", maxid_filename);
                    logfile_id = atoi(maxid_filename+strlen(HLP_LOG_NAME_PREFIX)+1);
                }
            }

			free(namelist[i]);
		}
		free(namelist);
	}
     
    return logfile_id;
}

hlp_s32_t hlp_get_new_filename(hlp_s8_t *path, hlp_s8_t *filename)
{
    struct dirent **namelist;
	int i, n;
    hlp_s8_t name_prefix[64];
    hlp_s8_t maxid_filename[64];
    hlp_s32_t logfile_id = 0;

    logfile_id = hlp_get_filename_maxid_by_path(path);
    if(logfile_id >= 0){
        if(logfile_id == 0)
            HLP_INFO(HLP_MOD_COMMON, "it seems not have log files in \"%s\" ", path);
        sprintf(filename, "%s/%s_%03d.txt", path, HLP_LOG_NAME_PREFIX, logfile_id+1);
        return 0;
    }
    else if(logfile_id == 0) {
        
        return 0;
    }
    else {
        HLP_ERROR(HLP_MOD_COMMON, "can't parse logifle_id, filename=%s", maxid_filename);
        return -1;
    }
        
    return 0;
}

hlp_bool_t hlp_file_isexist(hlp_s8_t *path, hlp_s8_t *filename)
{
	struct dirent **namelist;
	int n;

	n = scandir(path, &namelist, 0, alphasort);
	if(n < 0)
	{
        HLP_ERROR(HLP_MOD_COMMON, "scandir error! path[%s], errno=%d:%s", path, errno, strerror(errno));
	}
	else
	{
		while (n--)
		{
            //HLP_INFO(HLP_MOD_COMMON, "pathname:[%s]", namelist[n]->d_name);
			if(hlp_strcmp(namelist[n]->d_name, filename) == 0)
			{
				return HLP_TRUE;
			}
			free(namelist[n]);
		}
		free(namelist);
	}
	return HLP_FALSE;
}


S32 hlp_mkdir2(S8 *path)
{
    if(access(path, F_OK) == 0)
        return 0;

    if(mkdir(path, 0777) < 0) {
        HLP_ERROR(HLP_MOD_COMMON, "mkdir %s error! errno=%d:%s", path, errno, strerror(errno));
        return -1;
    }

    HLP_INFO(HLP_MOD_COMMON, "mkdir %s !", path);

    return 0;
}

S32 hlp_rmdir2(S8 *path)
{
    if(access(path, F_OK) != 0)
        return 0;

    if(rmdir(path) < 0) {
        HLP_ERROR(HLP_MOD_COMMON, "rmdir %s error! errno=%d:%s", path, errno, strerror(errno));
        return -1;
    }

    HLP_INFO(HLP_MOD_COMMON, "rmdir %s !", path);

    return 0;
}

S32 hlp_mkdir(S8 *path)
{
    S8 command[128] = {0};

    if(access(path, F_OK) == 0)
        return 0;

    sprintf(command, "mkdir -p %s", path);
    if(system(command) == -1) {
        HLP_ERROR(HLP_MOD_COMMON, "mkdir %s error! errno=%d:%s", path, errno, strerror(errno));
        return -1;
    }

    HLP_INFO(HLP_MOD_COMMON, "mkdir -p %s !", path);

    return 0;
}

S32 hlp_rmdir(S8 *path)
{
    S8 command[128] = {0};

    if(access(path, F_OK) != 0)
        return 0;

    sprintf(command, "rm -rf %s/*", path);
    if(system(command) == -1) {
        HLP_ERROR(HLP_MOD_COMMON, "rmdir %s error! errno=%d:%s", path, errno, strerror(errno));
        return -1;
    }

    HLP_INFO(HLP_MOD_COMMON, "rm -rf %s/* !", path);

    return 0;
}

S32 rootfs_add_files()
{
    S32 ret;
    if(access("/etc/mdev.conf", F_OK) == 0)
        return 0;

    ret = system("cp /root/HI3716/patch/mdev.conf /etc/mdev.conf");
    if(ret == -1){
        HLP_ERROR(HLP_MOD_COMMON, "cp mdev.conf error! errno=%d:%s", errno, strerror(errno));
        return -1;
    }

    HLP_INFO(HLP_MOD_COMMON, "add file --> /etc/mdev.conf");

    if(access("/sbin/automount.sh", F_OK) == 0)
        return 0;

    ret = system("cp /root/HI3716/patch/automount.sh /sbin/automount.sh");
    if(ret == -1){
        HLP_ERROR(HLP_MOD_COMMON, "cp mdev.conf error! errno=%d:%s", errno, strerror(errno));
        return -1;
    }

    HLP_INFO(HLP_MOD_COMMON, "add file --> /sbin/automount.sh");
    return 0;
}

S32 rootfs_replace_rcS()
{
    S32 fd;
    S32 n;
    S8  buffer[1024];
    S8  path[] = "/etc/init.d/rcS";

    fd = open(path , O_RDWR);
    if(fd < 0) {
        HLP_ERROR(HLP_MOD_COMMON, "open %s error! errno=%d:%s", path, errno, strerror(errno));
        return -1;
    }

    memset(buffer, 0, sizeof(buffer));
    n = read(fd, buffer, sizeof(buffer));
    if(n < 0) {
        close(fd);
        HLP_ERROR(HLP_MOD_COMMON, "read %s error! errno=%d:%s", path, errno, strerror(errno));
        return -1;
    }

    if(hlp_strstr(buffer, "mdev") == NULL) {
        hlp_memset(buffer, 0, sizeof(buffer));
        hlp_strcpy(buffer, "\n/bin/echo > /dev/mdev.seq");
        hlp_strcat(buffer, "\necho /sbin/mdev > /proc/sys/kernel/hotplug");
        hlp_strcat(buffer, "\n/sbin/mdev -s\n\n");

        n = lseek(fd, 0, SEEK_END);
        if(n < 0) {
            close(fd);
            HLP_ERROR(HLP_MOD_COMMON, "lseek %s error! errno=%d:%s", path, errno, strerror(errno));
            return -1;
        }
        n = write(fd, buffer, hlp_strlen(buffer));
        if(n < 0) {
            close(fd);
            HLP_ERROR(HLP_MOD_COMMON, "write %s error! errno=%d:%s", path, errno, strerror(errno));
            return -1;
        }
        close(fd);
        HLP_INFO(HLP_MOD_COMMON, "replace file --> /etc/init.d/rcS");
        sync();
        reboot(0x01234567);
        return -1;
    }

    close(fd);
    return 0;
}

S32 rootfs_replace_profile()
{
    S32 fd;
    S32 n;
    S8  buffer[1024];
    S8  path[] = "/etc/profile";

    fd = open(path , O_RDWR);
    if(fd < 0) {
        HLP_ERROR(HLP_MOD_COMMON, "open %s error! errno=%d:%s", path, errno, strerror(errno));
        return -1;
    }

    memset(buffer, 0, sizeof(buffer));
    n = read(fd, buffer, sizeof(buffer));
    if(n < 0) {
        close(fd);
        HLP_ERROR(HLP_MOD_COMMON, "read %s error! errno=%d:%s", path, errno, strerror(errno));
        return -1;
    }
    close(fd);
    return 0;
}

S32 hlp_rootfs_init()
{
    if(rootfs_add_files() < 0)
        return -1;
    if(rootfs_replace_rcS() < 0)
        return -1;

    return 0;
}

S32 hlp_common_init()
{
    hlp_time_init();

    return 0;
}


