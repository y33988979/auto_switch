/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 


#include <hlp_debug.h>
#include <hlp_common.h>
#include <hlp_gpio.h>
#include <hlp_panel.h>
#include <hlp_switch.h>
#include <hi_unf_ecs.h>


static char *hlp_panel_main_menu_str[4] = { "func", "stat", " set", "NULL"};
static char *hlp_panel_menu_item_str[3][4] = 
	{ 
		{"COPY", " CLS", "NULL", "NULL"},
		{"STAT", " TM1", " TM2", " TM3"},
		{"NULL", "NULL", "NULL", "NULL"}
	};
//static hlp_u8_t  hlp_panel_item_num[] = {2, 4, 0};
static char *key_string[7] = {"RIGHT", "DOWN", "LEFT", "EXIT", "UP", "OK", "UNKOWN"};
static hlp_u8_t  hlp_panel_key = HLP_KEY_NULL;
static hlp_u8_t  panel_last_key[4] = {HLP_KEY_NULL};
static hlp_u8_t  panel_last_index=0;
hlp_u32_t  panel_last_key_time = 0;

static HI_UNF_KEYLED_TIME_S stLedTime = {0};
static U8 mLedData[4] = {0};
static U32 gLedUpdate = HLP_FALSE;
static U32 gLedDisplayDefault = HLP_TRUE;
static U32 gLedDisplayDefaultTime = 8;
static U32 gLedDisplayTime = HLP_FALSE;

static void hlp_panel_callback(U32 Key);
PanelCallback fPanelCallback = hlp_panel_callback;

static U8 panel_led_num_covert(U8 uiNumber)
{
    U8 ledNumber;
    
    ledNumber = NUM_NULL;
    switch(uiNumber)
    {
        case 0:
        	ledNumber = NUM_0;
        	break;
        case 1:
        	ledNumber = NUM_1;
        	break;
        case 2:
        	ledNumber = NUM_2;
        	break;
        case 3:
        	ledNumber = NUM_3;
        	break;
        case 4:
        	ledNumber = NUM_4;
        	break;
        case 5:
        	ledNumber = NUM_5;
        	break;
        case 6:
        	ledNumber = NUM_6;
        	break;
        case 7:
        	ledNumber = NUM_7;
        	break;
        case 8:
        	ledNumber = NUM_8;
        	break;
        case 9:
        	ledNumber = NUM_9;
        	break;
        default:
        	break;
        
    }
    return ledNumber;
}


static U8 panel_led_char_covert(U8 charAscc)
{
    U8 LedChar;
    
    LedChar = NUM_NULL;
    switch(charAscc)
    {
        case '0':
        	LedChar = NUM_0;
        	break;
        case '1':
        	LedChar = NUM_1;
        	break;
        case '2':
        	LedChar = NUM_2;
        	break;
        case '3':
        	LedChar = NUM_3;
        	break;
        case '4':
        	LedChar = NUM_4;
        	break;
        case '5':
        	LedChar = NUM_5;
        	break;
        case '6':
        	LedChar = NUM_6;
        	break;
        case '7':
        	LedChar = NUM_7;
        	break;
        case '8':
        	LedChar = NUM_8;
        	break;
        case '9':
        	LedChar = NUM_9;
        	break;
        case 'A':
        	LedChar = CHAR_BIG_A;
        	break;            
        case 'B':
        	LedChar = CHAR_BIG_B;
        	break;
        case 'C':
        	LedChar = CHAR_BIG_C;
        	break;
        case 'D':
        	LedChar = CHAR_BIG_D;
        	break;
        case 'E':
        	LedChar = CHAR_BIG_E;
        	break;
        case 'F':
        	LedChar = CHAR_BIG_F;
        	break;
        case 'G':
        	LedChar = CHAR_BIG_G;
        	break;
        case 'H':
        	LedChar = CHAR_BIG_H;
        	break;
        case 'I':
        	LedChar = CHAR_BIG_I;
        	break;
        case 'J':
        	LedChar = CHAR_BIG_J;
        	break;
        case 'K':
        	LedChar = CHAR_BIG_K;
        	break;
        case 'L':
        	LedChar = CHAR_BIG_L;
        	break;
        case 'M':
        	LedChar = CHAR_BIG_M;
        	break;
        case 'N':
        	LedChar = CHAR_BIG_N;
        	break;
        case 'O':
        	LedChar = CHAR_BIG_O;
        	break;
        case 'P':
        	LedChar = CHAR_BIG_P;
        	break;
        case 'Q':
        	LedChar = CHAR_BIG_Q;
        	break;
        case 'R':
        	LedChar = CHAR_BIG_R;
        	break;
        case 'S':
        	LedChar = CHAR_BIG_S;
        	break;
        case 'T':
        	LedChar = CHAR_BIG_T;
        	break;
        case 'U':
        	LedChar = CHAR_BIG_U;
        	break;
        case 'V':
        	LedChar = CHAR_BIG_V;
        	break;
        case 'W':
        	LedChar = CHAR_BIG_W;
        	break;
        case 'X':
        	LedChar = CHAR_BIG_X;
        	break;
        case 'Y':
        	LedChar = CHAR_BIG_Y;
        	break;
        case 'Z':
        	LedChar = CHAR_BIG_Z;
        	break;
        case 'a':
        	LedChar = CHAR_LIT_a;
        	break;
        case 'b':
        	LedChar = CHAR_LIT_b;
        	break;
        case 'c':
        	LedChar = CHAR_LIT_c ;
        	break;
        case 'd':
        	LedChar = CHAR_LIT_d;
        	break;
        case 'e':
        	LedChar = CHAR_LIT_e;
        	break;
        case 'g':
        	LedChar = CHAR_LIT_g;
        	break;
        case 'h':
        	LedChar = CHAR_LIT_h;
        	break;
        case 'l':
        	LedChar = CHAR_BIG_L;
        	break;            
        case 'm':
        	LedChar = CHAR_LIT_m;
        	break;
        case 'n':
        	LedChar = CHAR_LIT_n;
        	break;
        case 'o':
        	LedChar = CHAR_LIT_o;
        	break;
        case 'p':
        	LedChar = CHAR_LIT_p;
        	break;
        case 'q':
        	LedChar = CHAR_LIT_q;
        	break;
        case 'r':
        	LedChar = CHAR_LIT_r;
        	break;
        case 't':
        	LedChar = CHAR_LIT_t ;
        	break;
        case 'u':
        	LedChar = CHAR_LIT_u;
        	break;
        case 'y':
        	LedChar = CHAR_LIT_y;
        	break;
        case '-':
        	LedChar = STANDBY_STATUS_LINE;
        	break;            
        default:
        	break;        
    }
    return LedChar;
}


void panel_led_display_char(U8 d1,U8 d2,U8 d3,U8 d4)
{
    mLedData[0] = panel_led_char_covert(d1);
    mLedData[1] = panel_led_char_covert(d2);
    mLedData[2] = panel_led_char_covert(d3)|(mLedData[2]&0x01);
    mLedData[3] = panel_led_char_covert(d4);

    mLedData[0] = ~mLedData[0];
    mLedData[1] = ~mLedData[1];
    mLedData[2] = ~mLedData[2];
    mLedData[3] = ~mLedData[3];
    
    gLedUpdate = HLP_TRUE;
}

void panel_led_show_string(U8 *string) 
{
	panel_led_display_char(string[0], string[1], string[2], string[3]);
}

void panel_led_show_number(U32 number) 
{
	U8  string[16] = {0};

	if(number > 9999)
		number = 9999;
	sprintf(string ,"%04d", number);
	panel_led_display_char(string[0], string[1], string[2], string[3]);
}

void panel_led_show_time(U32 hour, U32 min) 
{
    gLedDisplayTime = HI_TRUE;
    
    stLedTime.u32Hour = hour;
    stLedTime.u32Minute = min;
}

void panel_led_show_default_enable(U32 isEnable, U32 sec)
{
    gLedDisplayDefault = isEnable;
    if(isEnable)
        gLedDisplayDefaultTime = sec>10?10:sec;
}
static void hlp_exit_test()
{
	hlp_u8_t index = panel_last_index;
	
	if(panel_last_key[index++%4] == HLP_PANEL_KEY_LEFT
		&&panel_last_key[index++%4] == HLP_PANEL_KEY_DOWN
		&&panel_last_key[index++%4] == HLP_PANEL_KEY_RIGHT
		&&panel_last_key[index++%4] == HLP_PANEL_KEY_UP) {
		HLP_INFO(HLP_MOD_PANEL, "program exit.. for key");
        sync();
		exit(-1);
	}
}

static void hlp_panel_callback(U32 key)
{
	    
    switch(key)
    {
        case HLP_PANEL_KEY_UP:
        break;
        case HLP_PANEL_KEY_DOWN:
        break;
        case HLP_PANEL_KEY_LEFT:
        break;
        case HLP_PANEL_KEY_RIGHT:
        break;
        case HLP_PANEL_KEY_SELECT:
            hlp_switch_task_start();
        break;
        case HLP_PANEL_KEY_EXIT:
            hlp_power_switch_off();
            hlp_switch_task_stop();
        break;
        default:
        break;
    }
}

void hlp_panel_callback_enable(PanelCallback callback)
{
    fPanelCallback = callback;
}

S32 hlp_panel_key_process(U32 key)
{
    if(key <= 7 && key >= 2) {
		HLP_INFO(HLP_MOD_PANEL, "Key %s is pressed!\n", key_string[key-2]);
	}
    else {
        HLP_ERROR(HLP_MOD_PANEL, "Unknown Key [0x%x]!\n", key);
        //return -1;
    }
    
    hlp_buzzer_ringoff();
    hlp_panel_key = key;
    panel_last_key_time = hlp_time_ms();
	panel_last_key[panel_last_index++ % 4] = key;
	hlp_exit_test();

    if(fPanelCallback)
        fPanelCallback(key);

	//hlp_panel_key = HLP_KEY_NULL;
	return HLP_OK;
}

void* led_display_task(void *args)
{
    S32 retcode = 0;
    S32 display_timeout = 0;

    while(1) {
        if(gLedDisplayTime)
        {
            HI_UNF_LED_DisplayTime(stLedTime);
            usleep(100*1000);
            continue;
        }
                
        if(gLedUpdate)
        {
            retcode = HI_UNF_LED_Display(mLedData[3] << 24 | mLedData[2] << 16
                                    | mLedData[1] << 8 | mLedData[0]);
            if (HI_SUCCESS != retcode)
            {
                HLP_ERROR(HLP_MOD_PANEL, "Led display error! retcode=0x%08x", retcode);
                break;
            }
            gLedUpdate = HLP_FALSE;
            display_timeout = gLedDisplayDefaultTime*10;
            
        }else {
            
            if(display_timeout == 0)
                continue;
            
            if(gLedDisplayDefault){
                if(display_timeout-- == 1) {
                    HI_UNF_LED_Display(0x02020202); //show string is "----"
                } 
            }
        }
        usleep(100*1000);
    }

    return NULL;
}

void* panel_task(void *args)
{
    S32  retcode = -1;
    U32  u32PressStatus, u32KeyId;

	while(1) {
        retcode = HI_UNF_KEY_GetValue(&u32PressStatus, &u32KeyId);
        if(retcode == HI_SUCCESS) {
            HLP_INFO(HLP_MOD_PANEL, "KEY  KeyId : 0x%x    PressStatus :%d[%s]", \
                u32KeyId, u32PressStatus
                , (0 == u32PressStatus) ? "DOWN" 
                : (1 == u32PressStatus) ? "HOLD" : "UP"); 
            
            hlp_panel_key_process(u32KeyId);
        }
        usleep(100*1000);
	}
}

S32 hisi_keyled_init()
{
    S32  s32Ret = 0;
    
    HI_SYS_Init();
    HI_UNF_KEYLED_Init();

    s32Ret = HI_UNF_KEYLED_SelectType(HI_UNF_KEYLED_TYPE_CT1642);
    /*open LED device*/
    s32Ret = HI_UNF_LED_Open();
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%08x\n", __FILE__, __LINE__, s32Ret);
        return s32Ret;
    }

    /*enable flash*/
    s32Ret = HI_UNF_LED_SetFlashFreq(HI_UNF_KEYLED_LEVEL_5);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%08x\n", __FILE__, __LINE__, s32Ret);
        return s32Ret;
    }

    /*config LED flash or not*/
    s32Ret = HI_UNF_LED_SetFlashPin(HI_UNF_KEYLED_LIGHT_NONE);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%08x\n", __FILE__, __LINE__, s32Ret);
        return s32Ret;
    }
    /*open KEY device*/
    s32Ret = HI_UNF_KEY_Open();
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%08x\n", __FILE__, __LINE__, s32Ret);
        return s32Ret;
    }

    /*config keyup is valid*/
    s32Ret = HI_UNF_KEY_IsKeyUp(HLP_FALSE);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%08x\n", __FILE__, __LINE__, s32Ret);
        return s32Ret;
    }

    /*config keyhold is valid*/
    s32Ret = HI_UNF_KEY_IsRepKey(HLP_TRUE);
    if (HI_SUCCESS != s32Ret)
    {
        printf("%s: %d ErrorCode=0x%08x\n", __FILE__, __LINE__, s32Ret);
        return s32Ret;
    }
    return 0;
}

S32 hlp_panel_init()
{
	S32        ret;
	pthread_t  tid;

    ret = hisi_keyled_init();
    if(ret < 0) {
        HLP_ERROR(HLP_MOD_PANEL, "hisi_keyled_init error!");
        return -1;
    }

    HLP_INFO(HLP_MOD_PANEL, "hisi_keyled_init success!");
    
	ret = pthread_create(&tid, NULL, (void * (*)(void*)) panel_task, NULL);
	if(ret < 0)
	{
        HLP_ERROR(HLP_MOD_PANEL, "panel_task create error! errno=%d:%s", errno, strerror(errno));
		return -1;
	}
    HLP_INFO(HLP_MOD_PANEL, "panel_task start success!");
    
    ret = pthread_create(&tid, NULL, (void * (*)(void*)) led_display_task, NULL);
	if(ret < 0)
	{
        HLP_ERROR(HLP_MOD_PANEL, "led_display_task create error! errno=%d:%s", errno, strerror(errno));
		return -1;
	}

    panel_led_show_string("----");
    HLP_INFO(HLP_MOD_PANEL, "led_display_task start success!");

	return ret;
}

