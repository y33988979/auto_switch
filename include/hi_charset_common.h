/**
 \file
 \brief common module
 \author Shenzhen Hisilicon Co., Ltd.
 \date 2008-2018
 \version 1.0
 \author 
 \date 2011-10-9
 */

#ifndef __HI_CHARSET_COMMON_H__
#define __HI_CHARSET_COMMON_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/**
** 数据流类型
**/
typedef enum hiCHARSET_STREAMTYPE_ENUM{
    HI_CHARSET_STREAMTYPE_UNKNOW = 0,    /*未知数据流*/
    HI_CHARSET_STREAMTYPE_BITS8  = 1,    /*单字节数据流*/
    HI_CHARSET_STREAMTYPE_BITS16LE=2,    /*双字节小端数据流*/
    HI_CHARSET_STREAMTYPE_BITS16BE=3,    /*双字节大端数据流*/
    HI_CHARSET_STREAMTYPE_BITS32LE=4,    /*四字节小端数据流*/
    HI_CHARSET_STREAMTYPE_BITS32BE=5,    /*四字节大端数据流*/
    HI_CHARSET_STREAMTYPE_BULT,
}HI_CHARSET_STREAMTYPE_E;
/**
**  用户调用异步设置命令类型
**/
typedef enum hiCHARSET_CMD_ENUM{
    HI_CHARSET_CMD_NONE = 0,  /*未知命令*/
    HI_CHARSET_CMD_EXIT,      /*设置异步退出命令*/
    HI_CHARSET_CMD_USERDATA,  /*异步设置用户数据*/
    HI_CHARSET_CMD_BULT,
}HI_CHARSET_CMD_E;

typedef struct hiCHARSET_FUN_S{
    /** 
    \brief 创建字符集模块句柄
    \attention \n
    无
    \param [out] handle 字符集句柄
    \param [in] u32Userdata 字符集私有数据
    
    
    \retval ::HI_SUCCESS 操作成功
    \retval ::HI_FAILURE 参数非法
    
    \see \n
    无
    */
    HI_S32 (*Create)(HI_HANDLE *handle, HI_U32 u32Userdata);
    /** 
    \brief 识别数据流类型，创建识别器并且识别数据，完成后销毁识别器
    \attention \n
    无
    \param [in] handle 字符集句柄
    \param [in] input 数据流
    \param [in] inLen 数据流长度
    \param [out] codeType 返回的编码类型
    \param [in] s32UserData 私有数据
    
    \retval ::HI_SUCCESS 操作成功
    \retval ::HI_FAILURE 参数非法
    
    \see \n
    无
    */
    HI_S32 (*IdentStream)(HI_HANDLE handle, const HI_U8 *input, const HI_S32 inLen, HI_S32 s32UserData, HI_S32 *codeType);
    /** 
    \brief  数据流转码，创建转码器，对数据进行转码，
    如果发现数据类型不对，销毁转码器，重新创建
    \attention \n
    无
    \param [in] handle  字符集句柄
    \param [out] out  转码后数据流
    \param [out] outlen  转码后数据流长度
    \param [in] DstType  目标转码类型
    \param [in] input  输入数据流
    \param [in] inLen  输入数据流长度
    \param [in] SrcType  源编码类型
    \param [out] Usedlen  已经转码的数据流长度
    
    \retval ::HI_SUCCESS 操作成功
    \retval ::HI_FAILURE 参数非法
    
    \see \n
    无
    */
    HI_S32 (*ConvStream)(HI_HANDLE handle, HI_U8 *out, HI_S32 *outlen,
        const HI_U8 *input, const HI_S32 inLen, HI_S32 SrcType, HI_S32 DstType, HI_S32* Usedlen);
    /** 
    \brief 异步设置用户命令和数据
    \attention \n
    无
    \param [in] handle 字符集句柄
    \param [in] u32Data  私有数据
    
    \retval ::HI_SUCCESS 操作成功
    \retval ::HI_FAILURE 参数非法
    
    \see \n
    无
    */
    HI_S32 (*setDataAsync)(HI_HANDLE handle,HI_U32 u32Cmd, HI_VOID *pArg);

    /** 
    \brief 销毁字符集模块句柄
    \attention \n
    无
    \param [in] handle 字符集句柄
    
    \retval ::HI_SUCCESS 操作成功
    \retval ::HI_FAILURE 参数非法
    
    \see \n
    无
    */
    HI_S32 (*Destroy)(HI_HANDLE handle);


    /** 
    \brief  根据字符编码类型判断字节流类型
    \attention \n
    无
    \param [in] codetype 字符编码
    \param [out] eStreamType 数据流类型
    
    \retval ::HI_SUCCESS 操作成功
    \retval ::HI_FAILURE 参数非法
    
    \see \n
    无
    */
    
    HI_S32 (*GetStreamType)(HI_S32 codetype, HI_CHARSET_STREAMTYPE_E* eStreamType);
}HI_CHARSET_FUN_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_CHARSET_COMMON_H__ */


