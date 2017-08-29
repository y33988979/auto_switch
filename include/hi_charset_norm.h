/**
 \file
 \brief common module
 \author Shenzhen Hisilicon Co., Ltd.
 \date 2008-2018
 \version 1.0
 \author 
 \date 2011-10-9
 */

#ifndef __HI_CHARSET_NORM_H__
#define __HI_CHARSET_NORM_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/**
字符集编码类型,
添加字符集，遵循以下约定:
1、添加字符集后，需要在字符集编码类型后添加上编码类型
2、添加的编码类型编号是连续
3、添加的编码类型基于前面的编码类型编号+1
*/
typedef enum hiCHARSET_CODETYPE_ENUM {
    HI_CHARSET_CODETYPE_NONE = 0,        /**默认值，不设置*/
    HI_CHARSET_CODETYPE_BIG5 = 1,        /**繁体中文*/
    HI_CHARSET_CODETYPE_UTF8 = 2,        /**UTF8*/
    HI_CHARSET_CODETYPE_ISO8859_1 = 3,   /** 西欧语系 ，拉丁文1*/
    HI_CHARSET_CODETYPE_ISO8859_2 = 4,   /**中欧和东欧语系，拉丁文2*/
    HI_CHARSET_CODETYPE_ISO8859_3 = 5,   /** 欧洲东南部语系，拉丁文3*/
    HI_CHARSET_CODETYPE_ISO8859_4 = 6,   /**斯堪的那维亚和波罗的海语系，拉丁文4*/
    HI_CHARSET_CODETYPE_ISO8859_5 = 7,   /**拉丁文和斯拉夫文*/
    HI_CHARSET_CODETYPE_ISO8859_6 = 8,   /**拉丁文和阿拉伯文*/
    HI_CHARSET_CODETYPE_ISO8859_7 = 9,   /**拉丁文和希腊文*/
    HI_CHARSET_CODETYPE_ISO8859_8 =10,   /**拉丁文和希伯来文*/
    HI_CHARSET_CODETYPE_ISO8859_9 =11,   /**为土耳其文修正的拉丁文，拉丁文5*/
    HI_CHARSET_CODETYPE_ISO8859_10=12,   /**拉普人、北欧和爱斯基摩人的文字，拉丁文6*/
    HI_CHARSET_CODETYPE_ISO8859_11=13,   /**拉丁文与泰文*/
    HI_CHARSET_CODETYPE_ISO8859_13=14,   /**波罗的海周边语系，拉丁文7*/
    HI_CHARSET_CODETYPE_ISO8859_14=15,   /**凯尔特文，拉丁文8*/
    HI_CHARSET_CODETYPE_ISO8859_15=16,   /**改进的拉丁文1，拉丁文9*/
    HI_CHARSET_CODETYPE_ISO8859_16=17,   /**罗马尼亚文，拉丁文10*/
    HI_CHARSET_CODETYPE_UNICODE_16LE=18, /**16位小端的UNICODE*/
    HI_CHARSET_CODETYPE_UNICODE_16BE=19, /**16位大端的UNICODE*/
    HI_CHARSET_CODETYPE_GBK=20,          /**简体中文GBK*/
    HI_CHARSET_CODETYPE_CP1250 = 21,     /**中欧*/
    HI_CHARSET_CODETYPE_CP1251 = 22,     /**西里尔文*/
    HI_CHARSET_CODETYPE_CP1252 = 23,     /**拉丁文I*/
    HI_CHARSET_CODETYPE_CP1253 = 24,     /**希腊文*/
    HI_CHARSET_CODETYPE_CP1254 = 25,     /**土耳其文*/
    HI_CHARSET_CODETYPE_CP1255 = 26,     /**希伯来文*/
    HI_CHARSET_CODETYPE_CP1256 = 27,     /**阿拉伯文*/
    HI_CHARSET_CODETYPE_CP1257 = 28,     /**波罗的海文*/
    HI_CHARSET_CODETYPE_CP1258 = 29,     /**越南*/
    HI_CHARSET_CODETYPE_CP874  = 30,     /**泰文*/
    HI_CHARSET_CODETYPE_UNICODE_32LE=31, /**32位小端的UNICODE*/
    HI_CHARSET_CODETYPE_UNICODE_32BE=32, /**32位大端的UNICODE*/
    HI_CHARSET_CODETYPE_BULT,
} HI_CHARSET_CODETYPE_E;

/** 版本号定义 */
typedef struct hiCHARSET_LIB_VERSION_S
{
    HI_U8 u8VersionMajor;    /**< Major version accessor element */
    HI_U8 u8VersionMinor;    /**< Minor version accessor element */
    HI_U8 u8Revision;        /**< Revision version accessor element */
    HI_U8 u8Step;            /**< Step version accessor element */
} HI_CHARSET_LIB_VERSION_S;

/** 码流探测器API */
typedef struct hiCHARSET_DETECTOR_FUN_S
{
    /** 
    \brief 根据私有数据，创建探测器
    \attention \n
    无
    \param [out] pDetectHandle  创建的探测器句柄
    \param [in] u32UserData  用户私有数据

    \retval ::HI_SUCCESS 创建探测器成功
    \retval ::HI_FAILURE 创建失败

    \see \n
    无
    */
    HI_S32 (*detect_create)(HI_HANDLE *pDetectHandle, HI_U32 u32UserData);

    /** 
    \brief 根据数据流，探测编码类型
    \attention \n
    无
    \param [in]  pDetectHandle 探测器句柄
    \param [in]  u8Input 输入数据流
    \param [in]  u32Inlen 输入数据流长度，必须为准确的数据流长度
    \param [in]  s32UserData 用户私有数据
    \param [out] s32CodeType 数据编码类型

    \retval ::HI_SUCCESS  数据流识别成功，正确返回编码类型
    \retval ::HI_FAILURE 数据识别失败，返回编码类型有误
    
    \see \n
    无
    */
    HI_S32 (*identstream)(HI_HANDLE handle, const HI_U8 *u8Input, const HI_S32 s32Inlen, HI_S32 s32UserData, HI_S32 *s32CodeType);

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
    HI_S32 (*detect_setDataAsync)(HI_HANDLE handle,HI_U32 u32Cmd, HI_VOID *pArg);


    /** 
    \brief 关闭探测器
    \attention \n
    无
    \param [in] pDetectHandle  探测器句柄

    \retval ::HI_SUCCESS 操作成功
    \retval ::HI_FAILURE 参数非法

    \see \n
    无
    */
    HI_S32 (*detect_close)(HI_HANDLE pDetectHandle);
} HI_CHARSET_DETECTOR_FUN_S;

/**转码器API */
typedef struct hiCHARSET_CONVERTER_FUN_S
{
    /** 
    \brief 根据转码源编码类型和目的编码类型，查找识别器
    \attention \n
    无
    \param [in] s32SrcType  源编码类型
    \param [in] s32DstType  目的编码类型

    \retval ::HI_SUCCESS 创建成功
    \retval ::HI_FAILURE 创建失败

    \see \n
    无
    */
    HI_S32 (*conv_find)(HI_S32 s32SrcType, HI_S32 s32DstType);

    /** 
    \brief 创建转码器
    \attention \n
    无
    \param [out] pConvHandle  创建的转码器句柄
    \param [in] u32UserData  用户私有数据

    \retval ::HI_SUCCESS 创建成功
    \retval ::HI_FAILURE 创建失败

    \see \n
    无
    */
    HI_S32 (*conv_create)(HI_HANDLE *pConvHandle, HI_U32 u32UserData);
    


    /** 
    \brief 根据数据流进行转码
    \attention \n
    无
    \param [in]  pConvHandle 转码器句柄
    \param [in]  u8Input 输入数据流
    \param [in]  u32Inlen 输入数据流长度
    \param [out] u8Output 转码后数据
    \param [out] u32Outlen 转码后数据长度
    \param [out] u32Usedlen 已经转码的数据长度

    \retval ::HI_SUCCESS  转码成功
    \retval ::HI_FAILURE    转码失败
    
    \see \n
    无
    */
    HI_S32 (*convstream)(HI_HANDLE pConvHandle, const HI_U8 *u8Input, const HI_S32 s32Inlen, HI_U8 *u8Output, HI_S32 *s32Outlen, HI_S32 s32SrcType, HI_S32 s32DstType, HI_S32 *s32Usedlen);

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
    HI_S32 (*conv_setDataAsync)(HI_HANDLE handle,HI_U32 u32Cmd, HI_VOID *pArg);


    /** 
    \brief 关闭转码器
    \attention \n
    无
    \param [in] pConvHandle  转码器句柄

    \retval ::HI_SUCCESS 操作成功
    \retval ::HI_FAILURE 参数非法

    \see \n
    无
    */
    HI_S32 (*conv_close)(HI_HANDLE pConvHandle);
} HI_CHARSET_CONVERTER_FUN_S;

/*******************************************************
HI_CHARSET_S g_stCharset_entry=
{
    .pszDllName  = (const HI_PCHAR )"libhicharset.so",
    .stLibVersion = {1, 0, 0, 0},
    .pszCharSetDesc = (const HI_PCHAR )"hicharset detector and converter",
    .u32Priority   = 0,
    
    .stDetectorFun.detect_create = ,
    .stDetectorFun.identstream   = ,
    .stDetectorFun.detect_setDataAsync = ,
    .stDetectorFun.detect_close  = ,
    
    .stConverterFun.conv_find   = ,
    .stConverterFun.conv_create = ,
    .stConverterFun.convstream  = ,
    .stConverterFun.conv_setDataAsync = ,
    .stConverterFun.conv_close = ,

    .next           = NULL,
    .pDllModule     = NULL,
    .u32PrivateData = 0,
};
********************************************************/


typedef struct hiCHARSET_S
{
    /**< 字符集名称 */
    const HI_CHAR *pszDllName;

    /**< 字符集版本号 */
    const HI_CHARSET_LIB_VERSION_S stLibVersion;

    /**< 字符集描述 */
    const HI_CHAR *pszCharSetDesc;

    /**< 优先级，从0x0 - 0xFFFFFFFF，0xFFFFFFFF优先级最高，该属性无效 */
    HI_U32 u32Priority;

    /**< 字符集探测器访问接口，探测器实现必须遵循如下规则:
         1、对于探测器，探测精度也高，优先级越高，如果不确认编码类型，则失败返回
         2、如果字符集没有实现探测器功能，必须将该参数设置为NULL;
         */

    HI_CHARSET_DETECTOR_FUN_S stDetectorFun;

    /**<转码器接口，该接口遵循以下规则:
         1、如果字符集没有实现该接口，必须将该参数设置为NULL;
         2、该参数可以在外部指定，即: 字符集可以不实现该接口，
         */

    HI_CHARSET_CONVERTER_FUN_S stConverterFun;

    struct hiCHARSET_S *next;

    /**< 动态库句柄 */
    HI_VOID  *pDllModule;

    /**< 私有数据 */
    HI_U32 u32PrivateData;
} HI_CHARSET_S;

/**
**获取字符编码最小值
**/
extern HI_S32 HI_CHARSET_GetMinCodetype();

/**
**获取字符编码最大值
**/
extern HI_S32 HI_CHARSET_GetMaxCodetype();

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif



