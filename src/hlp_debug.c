/* hlp log Program
 * 
 *  Copyright (c) 2017 yuchen
 *  Copyright 2017-2017 jiuzhoutech Inc.
 *  yuchen  <yuchen@jiuzhoutech.com, 382347665@qq.com>
 * 
 *  this is a log interface API, for app.
 * Note : 
 */
 

#include <stdarg.h>
#include <hlp_log.h>
#include <hlp_debug.h>

//static U8 g_hlp_dbg_module[HLP_MOD_CNT] = {0};
static U8 g_hlp_dbg_lever[HLP_MOD_CNT] = {0};
static U8 g_dbg_buf[2048] = {0};
static U32 debug_inited = 0;

typedef struct debug_module
{
    U32  id;
    U8   name_desc[32];
}debug_module_t;

static S8 *debug_level_info[] = 
{
    "don't print any info",
    "print error info",
    "print warn info",
    "print info info",
    "print debug info",
    "print verbose info"
};

static debug_module_t g_dbg_modules[HLP_MOD_CNT] =
{
    {0,               "none"},
    {HLP_MOD_ALL,     "All Module"},
    {HLP_MOD_COMMON,  "Common Module"},
    {HLP_MOD_CONFIG,  "Config Module"},
    {HLP_MOD_GPIO,    "Gpio   Module"},
    {HLP_MOD_SERIAL,   "Serial    Module"},
    {HLP_MOD_LOGFILE,  "Logfile    Module"},
    {HLP_MOD_SWITCH,   "Switch    Module"},
    {HLP_MOD_PANEL,    "Panel    Module"},
    {HLP_MOD_UDISK,    "Udisk    Module"},
    
};

S32 hlp_debug(U32 module_id, U32 lever, const char *fmt, ...)
{
    S32 n;
    U32 size = 2048;
    U32 current_module_lever;
    va_list ap;

    if(module_id <= 0 || module_id >= HLP_MOD_CNT \
        || lever < HLP_DBG_NONE || lever > HLP_DBG_ALL)
    {
        printf("[ERROR]hlp_debug: invalid param! module_id=%d, lever=%d", module_id, lever);
        return -1;
    }

    current_module_lever = g_hlp_dbg_lever[module_id];
    if(lever > current_module_lever && lever != HLP_DBG_ALL)
        return -1;

    /* print log message to console */
    {
        va_start(ap, fmt);
        //n = vsprintf(g_dbg_buf, fmt, ap);
        n = vfprintf(stdout, fmt, ap);
        n = vsnprintf(g_dbg_buf, size, fmt, ap);
        hlp_log_write(g_dbg_buf, n);
        va_end(ap);
        //fflush(stdout);
    }
    //n = printf(g_dbg_buf, n); 
    return n;
}

/*
* debug lever:
* 0:NONE 1:ERROR, 2:WARN, 3:INFO, 4:DEBUG 5:ALL
*/
S32 hlp_debug_setlever(U32 module_id, U32 lever)
{
    
    U32 i;
    if(module_id <= 0 || module_id >= HLP_MOD_CNT)
    {
        printf("[ERROR]%s module id is invalid! id = %d\n", __FUNCTION__, module_id);
        return -1;
    }
    if(lever < HLP_DBG_NONE || lever > HLP_DBG_VERBOSE)
    {
        printf("[ERROR]%s level id is invalid! level = %d\n", __FUNCTION__, lever);
        return -1;
    }

    /* set all modules */
    if(module_id == HLP_MOD_ALL)
    {
        for(i=0; i<HLP_MOD_CNT; i++)
        {
            g_hlp_dbg_lever[i] = lever;
        }
    }
    else
    {
        g_hlp_dbg_lever[module_id] = lever;
    }
    
    return lever;
}

U32 hlp_debug_test(int lever)
{
    hlp_debug_setlever(1, lever);
    HLP_INFO(HLP_MOD_SERIAL, "INFO: test!");
    HLP_WARN(HLP_MOD_SERIAL, "WARN: test!");
    HLP_DEBUG(HLP_MOD_SERIAL, "DEBUG: test!");
    HLP_ERROR(HLP_MOD_SERIAL, "ERROR: test!");
    HLP_PRINT(HLP_MOD_SERIAL, "PRINT: test!");
}
void debug_help()
{
    U32 i;
    printf("=====================================================\n");
    printf("usage:   debugset [module_id] [lever]\n");
    printf("lever: 0:none 1:error 2:warn 3:info 4:debug 5:all\n");
    printf("example: debugset 1 2\n\n");
    printf("Module No	Descriptions\n");
    for(i=0; i<HLP_MOD_CNT; i++)
        printf("%d: %s\n", g_dbg_modules[i].id, g_dbg_modules[i].name_desc);
    printf("=====================================================\n");
    printf("Print level     Descriptions\n");
    for(i=0; i<HLP_DBG_ALL; i++)
    {
        printf("%4d		%s\n", i, debug_level_info[i]);
    }
    printf("=====================================================\n");
}

void hlp_debug_control()
{
    U32  module_id;
    U32  dbg_lever;
    S32  len;
    char *ptr = NULL;
    char cmdline[512];

    sleep(1);
    printf("HLP_V2 > ");
    fflush(stdout);
    while(1)
    {
        memset(cmdline, 0, sizeof(cmdline));
        ptr = fgets(cmdline, sizeof(cmdline), stdin);
        if(ptr == NULL)
        {
            hlp_msleep(200);
            continue;
        }

        if(strncmp(cmdline, "quit", 4) == 0)
            exit(1);

        //printf("input=%s", cmdline);
        if(strncmp(cmdline, "help", 4) == 0)
        {
            debug_help();
            continue;
        }
             
        if(strncmp(cmdline, "debugset ", strlen("debugset ")) != 0)
        {
            printf("HLP_V2 > ");
            fflush(stdout);
            continue;
        }

        len = strlen(cmdline);
        while(len--)
        {
            if(cmdline[len] == ' ' || cmdline[len] == '\n')
                cmdline[len] = '\0';
        }

        ptr = cmdline + strlen("debugset ");
        len = 5;
        while(len-- && *ptr == '\0')
            ptr++;

        printf("len=%d\n", len);
        if(len < 0) {debug_help();continue;}
        module_id = atoi(ptr);

        ptr += strlen(ptr);
        len = 5;
        while(len-- && *ptr == '\0')
            ptr++;
        
        if(len < 0) {debug_help();continue;}
        dbg_lever = atoi(ptr);

        /* set debug lever */
        hlp_debug_setlever(module_id, dbg_lever);
        HLP_PRINT(HLP_MOD_ALL, "debugset: [%s] lever[%d]!\n",\
            g_dbg_modules[module_id].name_desc, dbg_lever);
    }
}

S32 hlp_debug_init()
{
    pthread_t tid;
    if(debug_inited)
        return 0;
    
#if 0
    if(pthread_create(&tid, NULL, (void*)hlp_debug_control, NULL) < 0)
    {
        HLP_ERROR(HLP_MOD_ALL, "debug_ctrl task create error: %s", strerror(errno));
        return -1;
    }
    HLP_PRINT(HLP_MOD_ALL, "debug_ctrl task create success!\n");
#endif
    debug_inited = 1;
    
    return 0;
}

#if 0
hlp_log_t* hlp_log_init()
{
    hlp_log_t *log;

    log = (hlp_log_t)malloc(sizeof(hlp_log_t));
}
S32 hlp_log_deinit()
{
    free(log);
}

S32 hlp_log_open(U8 *filename)
{
    FILE *fp = NULL;
    fp = fopen(filename, "w+");
    if(pf == NULL)
    {
        HLP_PRINT(HLP_MOD_ALL, "fopen error: %s", strerror(errno));
    }
    return fp;
}

S32 hlp_log_close(FILE *fp)
{
    fclose(fp);
}

S32 hlp_log_write(char *buffer)
{
    int len ;
    len = fwrite(buffer, 1, strlen(buffer), fp);
    if(len < 0)
        HLP_PRINT(HLP_MOD_ALL, "fwrite error: %s", strerror(errno));
    return len;
}
#endif


