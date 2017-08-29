#ifndef AP_INFH
#define AP_INFH

#define IN
#define OUT
#define INOUT

#define HI_VOID		void
typedef char		HI_CHAR;
typedef char *		HI_PCHAR;
typedef int		HI_S32;

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

/*
 * ap start
 * ssid      - wifi ap ssid
 * security  - security mode
 *             "NONE"
 *             "WEP"
 *             "WPAPSK"
 * password  - "security key"
 * channel   - "from 1 to 11"
 *
 * if invoke this function fail,ruturn -1
 * if invoke this function succeed,ruturn 0
 *
 */
HI_S32 HI_Ap_Start(HI_PCHAR ssid, HI_PCHAR security, HI_PCHAR password, HI_S32 channel);

#endif /*AP_INFH*/
