/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_PANEL_H__
#define __HLP_PANEL_H__


#include <hlp_config.h>
#include <hlp_core.h>

#define HLP_KEY_NULL               0xff 
#define HLP_PANEL_KEY_UP           6
#define HLP_PANEL_KEY_DOWN         3
#define HLP_PANEL_KEY_LEFT         4
#define HLP_PANEL_KEY_RIGHT        2
#define HLP_PANEL_KEY_SELECT       7
#define HLP_PANEL_KEY_EXIT         5

#define HLP_MENU_CATEGORY_NUM      3
#define HLP_MENU_ITEM_NAME_LEN_MAX 10

#define NUM_NULL 0xFF
#define NUM_0 0x03
#define NUM_1 0x9F
#define NUM_2 0x25
#define NUM_3 0x0d
#define NUM_4 0x99
#define NUM_5 0x49
#define NUM_6 0x41
#define NUM_7 0x1f
#define NUM_8 0x01
#define NUM_9 0x09

#define CHAR_BIG_A 0x11
#define CHAR_BIG_B 0xFF
#define CHAR_BIG_C 0x63
#define CHAR_BIG_D 0xFF
#define CHAR_BIG_E 0x61
#define CHAR_BIG_F 0x71
#define CHAR_BIG_G 0x43
#define CHAR_BIG_H 0x91
#define CHAR_BIG_I 0xF3
#define CHAR_BIG_J 0x8F
#define CHAR_BIG_K 0xFF
#define CHAR_BIG_L 0xE3
#define CHAR_BIG_M 0xFF
#define CHAR_BIG_N 0x13
#define CHAR_BIG_O 0x03
#define CHAR_BIG_P 0x31
#define CHAR_BIG_Q 0xFF
#define CHAR_BIG_R 0xFF
#define CHAR_BIG_S 0x49
#define CHAR_BIG_T 0xFF
#define CHAR_BIG_U 0x83
#define CHAR_BIG_V 0xFF
#define CHAR_BIG_W 0xFF
#define CHAR_BIG_X 0xFF
#define CHAR_BIG_Y 0xFF
#define CHAR_BIG_Z 0xFF

#define CHAR_LIT_a 0x05
#define CHAR_LIT_b 0xC1
#define CHAR_LIT_c 0xE5
#define CHAR_LIT_d 0x85
#define CHAR_LIT_e 0x21
#define CHAR_LIT_f 0xFF
#define CHAR_LIT_g 0x09
#define CHAR_LIT_h 0xD1
#define CHAR_LIT_i 0xDF
#define CHAR_LIT_j 0xFF
#define CHAR_LIT_k 0xFF
#define CHAR_LIT_l 0x9F
#define CHAR_LIT_m 0xFF
#define CHAR_LIT_n 0xD5
#define CHAR_LIT_o 0xC5
#define CHAR_LIT_p 0x31
#define CHAR_LIT_q 0x19
#define CHAR_LIT_r 0xF5
#define CHAR_LIT_s 0x49
#define CHAR_LIT_t 0xE1
#define CHAR_LIT_u 0xC7
#define CHAR_LIT_v 0xC7
#define CHAR_LIT_w 0xFF
#define CHAR_LIT_x 0xFF
#define CHAR_LIT_y 0x89
#define CHAR_LIT_z 0xFF

#define STANDBY_STATUS_LINE 0xfd//0x9F
#define STANDBY_DOUBLE_LINE 0xfd//0x9F  

#define MENU_SHOW_STRING           0
#define MENU_SHOW_NU           0

typedef struct hlp_panel_menu_item      hlp_panel_menu_item_t;
typedef struct hlp_panel_menu_category  hlp_panel_menu_category_t;
typedef struct hlp_panel_menu           hlp_panel_menu_t;

typedef void (*hlp_panel_menu_key_callback)(hlp_panel_menu_t *menu, hlp_u8_t key);
typedef void (*hlp_panel_menu_enter_callback)(hlp_panel_menu_t *menu, hlp_u8_t key);

typedef void (*PanelCallback)(U32 key);

typedef enum
{
	HLP_PANEL_MENU_ITEM,
	HLP_PANEL_MENU_MAIN = 0x11,
	HLP_PANEL_MENU_CATEGORY,
}hlp_panel_menu_type;

typedef enum
{
	ITEM_SHOW_STRING = 0,
	ITEM_SHOW_NUMBER,
	ITEM_SHOW_TIME,
}hlp_panel_item_show_type;

struct hlp_panel_menu_item
{
	hlp_u8_t        name[HLP_MENU_ITEM_NAME_LEN_MAX];
	hlp_u8_t        lever;
	hlp_u8_t        index;
	hlp_u8_t        children_num;
	hlp_panel_menu_type            type;
	hlp_panel_item_show_type       show_type;
	hlp_panel_menu_item_t         *parent;
	hlp_panel_menu_item_t         *prev;
	hlp_panel_menu_item_t         *next;
	hlp_panel_menu_item_t         *chead;
	hlp_panel_menu_item_t         *ctail;
	hlp_panel_menu_key_callback    key_callback;
	hlp_panel_menu_enter_callback  enter_callback;
};

struct hlp_panel_menu_category
{
	hlp_u8_t        name[HLP_MENU_ITEM_NAME_LEN_MAX];
	hlp_u8_t        item_cnt;
	hlp_u8_t        index;
	hlp_panel_menu_t           *parent;
	hlp_panel_menu_category_t  *prev;
	hlp_panel_menu_category_t  *next;
	hlp_panel_menu_item_t      *items;
};

struct hlp_panel_menu
{
	hlp_u8_t        name[HLP_MENU_ITEM_NAME_LEN_MAX];
	hlp_u8_t        item_cnt;
	hlp_u8_t        current_lever;
	hlp_u8_t        current_index;
	hlp_panel_menu_item_t *main_item;
	hlp_panel_menu_item_t *current_item;
};


void panel_led_show_string(U8 *string);
void panel_led_show_number(U32 number);
void hlp_panel_callback_enable(PanelCallback callback);
S32 hlp_panel_init();

#if 0
void DRV_LED_DisplayTime(U32 hour, U32 min);
void DRV_LED_UnDisplayTime();
void DRV_LED_DisplayChar(U8 d1,U8 d2,U8 d3,U8 d4);
#endif

#endif /* __HLP_PANEL_H__ */

