#ifndef STA_INFH
#define STA_INFH

#define IN
#define OUT
#define INOUT

#define HI_VOID		void
typedef char 		HI_CHAR; 
typedef char *		HI_PCHAR;
typedef int		HI_S32;


#define CONNECT		0
#define	CHKSTATUS	1
#define DISCONNECT	2
#define RECONNECT	3
#define RESTART		4

#define NOSUCHINF	2
#define NOAPFOUND	3
#define NOSUCHAP	4
#define CONFAIL		5
#define CHKSTATUSFAIL	6
#define ERRPASSWORD	7
#define DISCONFAIL	8
#define RECONFAIL	9
#define RESTARTFAIL	10

#define MAX_PART	5

/*****************************************************************************/

#if !defined(PRINTF_CA) && !defined(FPRINTF_CA)
#ifdef  CONFIG_SUPPORT_CA_RELEASE
#define PRINTF_CA(fmt, args...)
#define FPRINTF_CA(file, fmt, args...)
#else
#define PRINTF_CA(fmt, args...) do{\
        printf("%s(%d): " fmt, __FILE__, __LINE__, ##args); \
} while (0)
#define FPRINTF_CA(file, fmt, args...) do{\
	fprintf((FILE *)file, fmt, ##args); \
} while (0)
#endif
#endif

/*****************************************************************************/
 /*
  * struct sta_link_info
  * @interface: such as "wlan0" "ra0"
  * @ssid: name of ap
  * @security  - security mode
  *             "NONE"
  *             "WEP"
  *             "WPAPSK"
  * @psaaword: the key match to security
  */
struct sta_link_info {
	char interface[8];
	char ssid[32];
	char security[10];
	char password[40];
};

/*****************************************************************************/
/*
 * struct wifi_info
 * @ssid      - ap's ssid
 * @channel   - from 1 to 11
 * @signal    - the quality of signal that ap transmit
 * @encrypt   - whether is on or off
 * @security  - security mode
 *             "NONE"
 *             "WEP"
 *             "WPAPSK"
 */
struct wifi_info {
	char ssid[40];
	char channel[3];
	char signal[8];
	char encrypt[4];
	char security[8];
};

/*****************************************************************************/
/*
 * HI_Sta_Ioctl - to control wifi
 * @link_info: key info to associate ap
 * @cmd: action for sta
 * Returns: 0 if cmd succeed, -1 if cmd fail
 */
HI_S32 HI_Sta_Ioctl(struct sta_link_info *link_info, HI_S32 cmd);

/*****************************************************************************/
/*
 * HI_Get_Security - set ap security type
 * @link_info: key info to associate ap
 * Returns: 0 if get type security succeed, -1 if fail
 */
HI_S32 HI_Get_Security(struct sta_link_info *link_info);

/*****************************************************************************/
/*
 * HI_Connect_Ap
 * @link_info: key info to associate ap
 * Returns: 0 if connect ap succeed, -1 if fail
 */
HI_S32 HI_Connect_Ap(struct sta_link_info *link_info);

/*****************************************************************************/
/*
 * HI_Get_Ap_Raw_Info - to collect the key info of ap for connecting
 * @interface - wifi interface name, such as "ra0", "wlan0"
 * @ap_cnt  - total ap that were scanned
 *             NULL - just store the ap info
 * @ap_list   - the specific infomation of each ap
 *             NULL - just get the count of ap
 * Returns: 0 if collect raw info succeed, -1 if fail
 */
HI_S32 HI_Get_Ap_Raw_Info(struct wifi_info **ap_list, HI_S32 *ap_cnt, HI_PCHAR interface);

/*****************************************************************************/
 /*
  * HI_Get_Ap_Count 
  * @ap_acount: total ap we scan
  * @interface: such as "wlan0" "ra0"
  * Returns: 0 if get ap count succeed, -1 if fail
  */
HI_S32 HI_Get_Ap_Count(HI_S32 *ap_cnt, HI_PCHAR interface);

/*****************************************************************************/
 /*
  * HI_Get_Ap_Info - to extract all key info of ap
  * @wifi_list: all key info of the ap we scan
  * @interface: such as "wlan0" "ra0"
  * Returns: 0 if succeed, -1 if fail
  */
HI_S32 HI_Get_Ap_Info(struct wifi_info **wifi_list, HI_PCHAR interface);

/*****************************************************************************/
/*
 * HI_Extract_Info - divide info 
 * @src:  the raw source info the were scan
 * @sym: such as '\n' ' '
 * @ss: each partition divide 
 */
HI_VOID HI_Extract_Info(HI_CHAR *src, HI_CHAR sym, HI_CHAR *ss[]);

/*****************************************************************************/
/*
 * HI_Store_Info
 * @dev_info: the specific info of eace ap
 * @src: the raw source info that were scan
 */
HI_VOID HI_Store_Info(struct wifi_info *dev_info, HI_CHAR *src[]);

/*****************************************************************************/
/*
 * HI_Show_List
 * @total: how many ap we scan
 * @list: the specific info of each ap
 */
HI_VOID HI_Show_List(HI_S32 total, struct wifi_info *list);

/*****************************************************************************/
int sta_ioctl(struct sta_link_info *link_info, int cmd);
int get_security(INOUT struct sta_link_info *link_info);
int connect_ap(IN struct sta_link_info *link_info);
int get_ap_raw_info(IN struct wifi_info **ap_list, 
		OUT int *ap_cnt, IN char *interface);
void extract_info(char *src, char sym, char *ss[]);
void store_info(OUT struct wifi_info *dev_info, IN char *src[]);
void show_list(IN int total, IN struct wifi_info *list);
int get_ap_count(OUT int *ap_count, IN char *interface);
int get_key_info(IN struct wifi_info **wifi_list, IN char *interface);


#endif /* STA_INFH */
