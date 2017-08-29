/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#ifndef __HLP_STRING_H__
#define __HLP_STRING_H__


#include <hlp_config.h>
#include <hlp_core.h>

#define hlp_strncmp(s1, s2, n)  strncmp((const char *) s1, (const char *) s2, n)

/* msvc and icc7 compile strcmp() to inline loop */
#define hlp_strcmp(s1, s2)  strcmp((const char *) s1, (const char *) s2)
#define hlp_strcpy(s1, s2)  strcpy((char *) s1, (const char *) s2)
#define hlp_strcat(s1, s2)  strcat((char *) s1, (const char *) s2)
#define hlp_strstr(s1, s2)  strstr((const char *) s1, (const char *) s2)
#define hlp_strlen(s)       strlen((const char *) s)
#define hlp_strchr(s1, c)   strchr((const char *) s1, (int) c)

#define hlp_tolower(c)      (u_char) ((c >= 'A' && c <= 'Z') ? (c | 0x20) : c)
#define hlp_toupper(c)      (u_char) ((c >= 'a' && c <= 'z') ? (c & ~0x20) : c)

/* * msvc and icc7 compile memset() to the inline "rep stos" 
 * while ZeroMemory() and bzero() are the calls. 
 * icc7 may also inline several mov's of a zeroed register for small blocks. */
#define hlp_memzero(buf, n)       (void) memset((void *)buf, (int)0, n)
#define hlp_memset(buf, c, n)     (void) memset((void *)buf, (int)c, n)

#define hlp_memcpy(dst, src, n)   (void) memcpy((void *)dst, (const void *)src, n)
#define hlp_memmove(dst, src, n)   (void) memmove(dst, src, n)
#define hlp_memcmp(s1, s2, n)  memcmp((const char *) s1, (const char *) s2, n)

#define hlp_qsort             qsort

#define hlp_sscanf            sscanf
#define hlp_sprintf           sprintf

#endif /* __HLP_STRING_H__ */

