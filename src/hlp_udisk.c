/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */

#include <hlp_debug.h>
#include <hlp_gpio.h>
#include <hlp_panel.h>
#include <hlp_config.h>
#include <hlp_udisk.h>
#include <linux/netlink.h>

S8* hlp_get_udisk_path()
{
    if(access("/mnt/sda1", F_OK) == 0){
        return "/mnt/sda1";
    }else if(access("/mnt/sdb1", F_OK) == 0){
        return "/mnt/sdb1";
    }else if(access("/mnt/sdc1", F_OK) == 0){
        return "/mnt/sdc1";
    }else if(access("/mnt/sdd1", F_OK) == 0){
        return "/mnt/sdd1";
    }
    HLP_ERROR(HLP_MOD_UDISK, "can't get udisk path, it maybe unmounted.");
    
    return NULL;
}

#define UDEV_MONITOR_KERNEL 	1
static S32 init_hotplug_sock(void)
{

    struct sockaddr_nl snl;
    const S32 buffersize = 4 * 1024;
    S32 retval;

    memset(&snl, 0x00, sizeof(struct sockaddr_nl));
    snl.nl_family = AF_NETLINK;
    snl.nl_pid = getpid();
    snl.nl_groups = UDEV_MONITOR_KERNEL;

    int hotplug_sock = socket(PF_NETLINK, SOCK_DGRAM, 15);
    if (hotplug_sock == -1)
    {
        HLP_ERROR(HLP_MOD_UDISK, "error getting socket: %s", strerror(errno));
        return -1;
    }

    /* set receive buffersize */
    setsockopt(hotplug_sock, SOL_SOCKET, 32, &buffersize, sizeof(buffersize));
    retval = bind(hotplug_sock, (struct sockaddr *) &snl, sizeof(struct sockaddr_nl));
    if (retval < 0) 
    {
        HLP_ERROR(HLP_MOD_UDISK, "bind failed: %s", strerror(errno));
        close(hotplug_sock);
        hotplug_sock = -1;
        return -1;
    }

    return hotplug_sock;
}


S32 hlp_udisk_mount_ok()
{
	FILE  *fp;
	S32   i = 0;
	S8    line[256];
	S8   *mount_dir_ptr = NULL;
	S32   usb_mount_ok = HLP_FALSE;

    if((fp = fopen("/proc/mounts", "r")) != NULL) {
        while(fgets((char*)line, sizeof(line), fp)) {
            //printf("line: %s\n", line);
            if((mount_dir_ptr = strstr(line, "/mnt/sd")) != NULL)
            {
                while(*(mount_dir_ptr+i) != ' ' && i<256)
                    i++;
                *(mount_dir_ptr+i) = '\0';

                usb_mount_ok = HLP_TRUE;
                break;
            }
        }
        fclose(fp);
    }
    
    return usb_mount_ok;
}

S32 udisk_mount_handle()
{
    U32 mount_ok = 0;
    U32 cnt = 5;
    S32 ret;
    S8  mount_path[128] = {0};
    S8  dir_path[128] = {0};
    S8  file_path[128] = {0};
    
    /* print mount point  */
    hlp_strcpy(mount_path, hlp_get_udisk_path());
    hlp_config_set_mount_path(mount_path);
    HLP_INFO(HLP_MOD_UDISK, "udisk path: %s", mount_path);

    /* create log directory for serail data save */
    sprintf(dir_path, "%s/%s", mount_path, HLP_LOG_DIR);
    ret = hlp_mkdir(dir_path);
    if(ret < 0)
        return -1;

    /* short ring.. hint success */
    hlp_operation_success();

    /* load config */
    sprintf(file_path, "%s/%s", mount_path, HLP_CONFIG_NAME);
    ret = hlp_config_load(file_path);
    if(ret < 0)
        return -1;

    /* check config */
    if(hlp_config_is_ok()) {
        panel_led_show_string("Succ");
        return 0;
    }else {
        panel_led_show_string("Erro");
        return -1;
    }
    
    return -1;
}

void udisk_plugout_handle()
{
    HLP_INFO(HLP_MOD_UDISK, "usb is plugout!");
}

void udisk_plugin_handle()
{
    U32 mount_ok = 0;
    U32 cnt = 5;

    HLP_INFO(HLP_MOD_UDISK, "usb is plugin! mount check...");
    /* wait udisk mount.. */
    while(cnt--) {
        usleep(1000*1000);
        if(hlp_udisk_mount_ok()) {
            mount_ok = 1;
            break;
        }
    }

    if(mount_ok) {
        HLP_INFO(HLP_MOD_UDISK, "\nudisk is mounted!");
        udisk_mount_handle();
    }
    else {
        /* unmounted */
        HLP_ERROR(HLP_MOD_UDISK, "\nudisk is unmounted!");
        panel_led_show_string("Erro");
        hlp_operation_failed();
    }
    
}

void udisk_thread(void* args)
{
    S32 hotplug_sock = -1;
    S32 is_plugin = 0;
    S8 *usb_desc = NULL;
    S32 len;
    S8  uevent_buffer[1024];   
    
    hotplug_sock = init_hotplug_sock();

    while(1) {
        memset(uevent_buffer, 0, sizeof(uevent_buffer));
        len = recv(hotplug_sock, &uevent_buffer, sizeof(uevent_buffer), 0);
        if(len < 0) {
            HLP_ERROR(HLP_MOD_UDISK, "hotplug_sock recv error! errno=%d:%s", errno, strerror(errno));
            usleep(200*1000);
		    continue;
        }
        
        if(strncmp(uevent_buffer, "add", 3) == 0)
            is_plugin = 1;
        else 
            is_plugin = 0;

        //printf("buf: %s\n", uevent_buffer);
        usb_desc = strstr(uevent_buffer, "usb");
        if(!usb_desc || strlen(usb_desc) > 22)
            continue ;

        HLP_INFO(HLP_MOD_UDISK, "envent: %s\n", uevent_buffer);

        if(is_plugin)
            udisk_plugin_handle();
        else
            udisk_plugout_handle();
    }
    
}

S32 hlp_udisk_init()
{
    pthread_t udisk_tid;

    if(hlp_udisk_mount_ok())
        udisk_mount_handle();

    if(pthread_create(&udisk_tid, NULL, (void*)udisk_thread, NULL) < 0){
        HLP_ERROR(HLP_MOD_UDISK, "udisk_thread create error! errno=%d:%s", errno, strerror(errno));
		return -1;
    }
    
    HLP_INFO(HLP_MOD_UDISK, "udisk_thread start success!");
    return 0;
}


