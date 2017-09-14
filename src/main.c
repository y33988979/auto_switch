/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */


#include <hlp_debug.h>
#include <hlp_gpio.h>
#include <hlp_common.h>
#include <hlp_config.h>
#include <hlp_serial.h>
#include <hlp_panel.h>
#include <hlp_udisk.h>
#include <hlp_switch.h>


#define MAIN_CHECK(func) \
    do\
    {\
        if(func < 0)\
        {\
            HLP_ERROR(HLP_MOD_ALL, "main check error!");\
            return -1;\
        }\
    }while(0);

void print_version()
{
    printf("|--------VERSION %s at %s --------|\n",__DATE__,__TIME__);
    usleep(10*1000);
}

int main(int argc, char **argv)
{
    int ret = 0;

    print_version();
    hlp_debug_setlever(1, 4);
    MAIN_CHECK ( hlp_common_init() );
    MAIN_CHECK ( hlp_log_init() );
    MAIN_CHECK ( hlp_rootfs_init() );
    MAIN_CHECK ( hlp_gpio_init() );

#if (SERIAL_ANALYZE_SUPPORT)
    MAIN_CHECK ( hlp_serial_init() );
    MAIN_CHECK ( hlp_debug_init() );
    MAIN_CHECK ( hlp_config_init() );
    MAIN_CHECK ( hlp_panel_init() );
    MAIN_CHECK ( hlp_udisk_init() );
#endif

    MAIN_CHECK ( hlp_switch_init() );

    HLP_INFO(HLP_MOD_ALL, "Enter switch control%s system v1.2!\n",\
        SERIAL_ANALYZE_SUPPORT?"/analyze":"");
    panel_led_show_string("----");

    while(1)
        sleep(3);

    return ret;
}




