/**
 \file
 \brief common module
 \author Shenzhen Hisilicon Co., Ltd.
 \date 2008-2018
 \version 1.0
 \author 
 \date 2011-10-9
 */

#ifndef __HI_CHARSET_H__
#define __HI_CHARSET_H__

#include "hi_type.h"
#include "hi_charset_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

extern HI_CHARSET_FUN_S g_stCharsetMgr_s;


/**
\brief  init CHARSET module
\attention \n
non
\param non

\retval ::HI_SUCCESS success
\retval ::HI_FAILURE fail

\see \n
non
*/
HI_S32 HI_CHARSET_Init(HI_VOID);

/** 
\brief deinit CHARSET
\attention \n
non
\param non

\retval ::HI_SUCCESS success
\retval ::HI_FAILURE fail

\see \n
non
*/
HI_S32 HI_CHARSET_Deinit(HI_VOID);

/** 
\brief regist charset lib
\attention \n
non
\param[in] dllName charset lib name

\retval ::HI_SUCCESS success
\retval ::HI_FAILURE fail, this lib regist already

\see \n
non
*/
HI_S32 HI_CHARSET_RegisterDynamic(const HI_CHAR *dllName);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __SVR_FORMAT_H__ */






