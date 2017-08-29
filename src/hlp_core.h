/**
 \file
 \brief helper common head file
 \author ychen
 \date 2015.11.16
 */
#ifndef __HLP_CORE_H__
#define __HLP_CORE_H__


typedef unsigned int     hlp_u32_t;
typedef unsigned short   hlp_u16_t;
typedef unsigned char    hlp_u8_t;

typedef  int       hlp_s32_t;
typedef  short     hlp_s16_t;
typedef  char      hlp_s8_t;

#if 1
typedef unsigned int     U32;
typedef unsigned short   U16;
typedef unsigned char    U8;

typedef  int       S32;
typedef  short     S16;
typedef  char      S8;
#endif

typedef unsigned int     hlp_bool_t;

#define  HLP_FALSE       0
#define  HLP_TRUE        1

#define  HLP_OK          0
#define  HLP_ERR        -1
#define  HLP_AGAIN      -2
#define  HLP_BUSY       -3
#define  HLP_DONE       -4
#define  HLP_DECLINED   -5
#define  HLP_ABORT      -6

#define LF     (u_char) '\n'
#define CR     (u_char) '\r'
#define CRLF   "\r\n"

#define hlp_abs(value)       (((value) >= 0) ? (value) : - (value))
#define hlp_max(val1, val2)  ((val1 < val2) ? (val2) : (val1))
#define hlp_min(val1, val2)  ((val1 > val2) ? (val2) : (val1))

#define is_power_of_2(x) ((x) != 0 && (((x) & ((x) - 1)) == 0))

//#define hlp_swap16(x) ((short)((((short)(x)&(short)0x00ffU)<< 8) |(((short)(x)&(short)0xff00U)>> 8)))
#define hlp_swap16(x) ((short)(((short)((x&0xff)<< 8)) | ((short)((x&0xff00)>> 8))))
#define hlp_swap32(x) (((x&0xff)<<24)|((x&0xff00)<<8)|((x&0xff0000)>>8)|((x&0xff000000)>>24))

#include <hlp_string.h>

#endif /* __HLP_CORE_H__ */

