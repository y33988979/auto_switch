/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */

#include <hlp_debug.h>
#include <hlp_config.h>
#include <hlp_serial.h>
#include <hlp_logfile.h>
#include <hlp_switch.h>
#include <hlp_udisk.h>

#include <hlp_uart.h>

static U32 capture_start = 0;
static U32 capture_suspend = 0;
static U32 g_keyword_is_detected = 0;
static S32 uart_fd = -1;

static serial_buffer_t  serial_buffer; //256k


S32 serial_buffer_init()
{
    memset(&serial_buffer, 0, sizeof(serial_buffer_t));
    return 0;
}

S32 serial_buffer_reset()
{
    memset(&serial_buffer, 0, sizeof(serial_buffer_t));
    return 0;
}

S32 serial_buffer_put(S8 *data, U32 len)
{
    serial_buffer_t *buf = &serial_buffer;

    if(len < 0) {
        HLP_ERROR(HLP_MOD_SERIAL, "invaild param, len=%d!", len);
        return -1;
    }
        
    if(len > buf->size - buf->data_len - 1) {
        HLP_ERROR(HLP_MOD_SERIAL, "the serial_buffer is full!");
        return -1;
    }
    
    memcpy(buf->data+buf->data_len, data, len);
    buf->data_len += len;
    
    return buf->data_len;
}

void hlp_serial_capture_start()
{
    S8    logdir[128] = {0};

    /* cleanup logs */
    sprintf(logdir, "%s/%s", hlp_get_udisk_path(), HLP_LOG_DIR);
    hlp_rmdir(logdir);

    serial_buffer_reset();
    /* flush uart */
    DRV_EraseIO(uart_fd);
    capture_start = 1;
    capture_suspend = 0;
}

void hlp_serial_capture_stop()
{
    capture_start = 0;
    capture_suspend = 1;
    
}

void hlp_serial_capture_suspend()
{ 
    capture_suspend = 1;
}

void hlp_serial_capture_resume()
{
    serial_buffer_reset();
    /* flush uart */
    DRV_EraseIO(uart_fd);
    capture_suspend = 0;
}

S32 hlp_console_readline(S8 *buffer, U32 len)
{
    S32  n;
    S8  *ptr = NULL;
    
    ptr = fgets(buffer, len-1, stdin);
    if(ptr == NULL) {
        HLP_ERROR(HLP_MOD_SERIAL, "fgets error! errno=%d:%s", errno, strerror(errno));
        return -1;
    }

    buffer[len-1] = '\0';
    n = hlp_strlen(buffer);
    
    if(n >= len-10)
        HLP_ERROR(HLP_MOD_SERIAL, "the dataline is too long! len=%d", n);
    
    return n;
}

S32 hlp_serial_read(S8 *buffer, U32 len)
{
    S32  n;
    S32  ret;
    
    ret = DRV_SerialRead(uart_fd, buffer, len);
    if(ret < 0) {
        HLP_ERROR(HLP_MOD_SERIAL, "read uart error! errno=%d:%s", errno, strerror(errno));
        return -1;
    }
        
    return ret;
}

S32 hlp_serial_find_keywork(S8 *src, S8 *keyword)
{
    src = serial_buffer.data;
    return hlp_strstr(src, keyword)?1:0;
}

void keyword_set_detected(U32 is_detected)
{
    g_keyword_is_detected = is_detected;
}

U32 keyword_is_detected()
{
    return g_keyword_is_detected;
}

void* serial_thread(void *args)
{
    S32   found = 0;
    S32   len = 0;
    S32   total_len = 0;
    U32   logfile_id = 0;
    S8    buffer[2048];
    S8    filename[128];
    S8    mount_path[128];
    S8    logs_path[128];
    logfile_t *logfile = NULL;
    hlp_conf_t config;

    while(1) {
        
        if(capture_start == 0) {
            logfile_id = 1;
            total_len = 0;
            if(logfile) {
                hlp_logfile_fsync(logfile);
                hlp_logfile_destory(logfile);
                logfile = NULL;
            }

            usleep(200*1000);
            continue;
        }

        /* if once test done, suspend uart! wait next poweron.. */
        if(capture_suspend) {
            usleep(200*1000);
            continue;
        }

        /* create log file on udisk */
        if(logfile == NULL) {
            found = 0;
            hlp_config_get(&config);
            sprintf(filename, "%s/%s/%s_%03d.txt", config.mount_path, HLP_LOG_DIR, HLP_LOG_NAME_PREFIX, logfile_id++);
            sprintf(logs_path, "%s/%s", config.mount_path, HLP_LOG_DIR);
            hlp_get_new_filename(logs_path, filename);
            logfile = hlp_logfile_create(filename);
            if(logfile == NULL) {
                usleep(100*1000);
                continue;
            }
        }

        memset(buffer, 0, sizeof(buffer));
        len = hlp_serial_read(buffer, sizeof(buffer));
        if(len < 0){
            usleep(200*1000);
            continue;
        }
        total_len += len;
        serial_buffer_put(buffer, len);
        help_led_flashing();
        
        //printf("serial buffer=%s\n", buffer);
        #if 0
        /* find keyword in serial log */
        found = hlp_serial_find_keywork(buffer, config.keyword);
        if(found) {
            //keyword_set_detected(1);
            HLP_INFO(HLP_MOD_SERIAL, "found keyword! [%s]", config.keyword);
        }
        #endif

        /* save serial log to udisk */
        len = hlp_logfile_write(logfile, buffer, len);
        if(logfile->file_size >= HLP_LOG_FILE_SIZE_MAX) {
            hlp_logfile_fsync(logfile);
            hlp_logfile_destory(logfile);
            logfile = NULL;
        }
        
        usleep(50*1000);
    }

}

S32 hlp_serial_init()
{
    S32 ret;
    S32 fd = -1;
    pthread_t serial_tid;

    serial_buffer_init();

#ifdef USE_UART_DEVICE
    fd = DRV_OpenSerial("/dev/ttyAMA0");
	if(fd < 0)
	{
		HLP_INFO(HLP_MOD_SERIAL, "open ttyAMA0 error! errno=%d:%s", errno, strerror(errno));
        return -1;
	}
	DRV_SetSpeed(fd);
	DRV_SetSerialRowmode(fd);
	DRV_SetTimeout(fd, 2, 0);//时间单位为百毫秒，2为200ms
	uart_fd = fd;

#endif
    ret = pthread_create(&serial_tid, NULL, (void * (*)(void*)) serial_thread, NULL);
	if(ret < 0)
	{
        HLP_ERROR(HLP_MOD_SERIAL, "serial_thread create error! errno=%d:%s", errno, strerror(errno));
		return -1;
	}

    HLP_INFO(HLP_MOD_SERIAL, "serial_thread start success!");

    return 0;
}


