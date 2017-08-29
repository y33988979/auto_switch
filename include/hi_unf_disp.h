/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_disp.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/15
  Description   :
  History       :
  1.Date        : 2009/12/15
    Author      : w58735
    Modification: Created file

*******************************************************************************/
/** 
 * \file
 *\brief : define DISPLAY module information
 * \brief supply infor about display.CNcomment:提供DISPLAY的相关信息
 */
 
#ifndef  __HI_UNF_DISP_H__
#define  __HI_UNF_DISP_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      H_2_2_8 */
/** @{ */  /** <!-- [DISPLAY] */

/**max DAC count*/
/**CNcomment:最大的DAC数目*/
#define MAX_DAC_NUM (6)

/**enum define about DISPLAY channel*/
/**CNcomment:定义DISPLAY通道枚举*/
typedef enum hiUNF_DISP_E
{
    HI_UNF_DISP_SD0 = 0x0,  /**< SD DISPLAY0 */ /**<CNcomment:标清DISPLAY0 */
    HI_UNF_DISP_HD0,         /**< HD DISPLAY0 *//**<CNcomment: 高清DISPLAY0 */
    HI_UNF_DISP_BUTT
}HI_UNF_DISP_E;

/**define the sigal type of DAC output*/
/**CNcomment:定义支持的DAC信号格式*/
typedef enum hiUNF_DISP_DAC_MODE_E
{
    HI_UNF_DISP_DAC_MODE_SILENCE = 0,    /**<No signal */ /**<CNcomment:无输出*/
    HI_UNF_DISP_DAC_MODE_CVBS,           /**<CVBS output */ /**<CNcomment:CVBS输出*/
    HI_UNF_DISP_DAC_MODE_Y,              /**<Y component signal output*//**<CNcomment:Y亮度分量输出*/
    HI_UNF_DISP_DAC_MODE_PB,             /**<PB component signal output*//**<CNcomment:蓝色色差分量输出*/
    HI_UNF_DISP_DAC_MODE_PR,             /**<PR componet signal output *//**<CNcomment:红色色差分量输出*/
    HI_UNF_DISP_DAC_MODE_R,              /**< Red component signal output*//**<CNcomment:CNcomment:红色分量输出*/
    HI_UNF_DISP_DAC_MODE_G,              /**<green component signal output*//**<CNcomment:绿色分量输出*/
    HI_UNF_DISP_DAC_MODE_B,              /**<blue component signal output*//**<CNcomment:蓝色分量输出*/
    HI_UNF_DISP_DAC_MODE_SVIDEO_Y,       /**<SVIDEO Y signal output*//**<CNcomment:SVIDEO_Y分量输出*/
    HI_UNF_DISP_DAC_MODE_SVIDEO_C,       /**<SVIDEO C signal output *//**<CNcomment:SVIDEO_C分量输出*/
    HI_UNF_DISP_DAC_MODE_HD_Y,           /**<HD Y component signal output*//**<CNcomment:高清Y亮度分量输出*/
    HI_UNF_DISP_DAC_MODE_HD_PB,          /**<HD PB component signal output*//**<CNcomment:高清蓝色色差分量输出*/
    HI_UNF_DISP_DAC_MODE_HD_PR,          /**< HD PR component signal output *//**<CNcomment:高清红色色差分量输出*/
    HI_UNF_DISP_DAC_MODE_HD_R,           /**< HD red component signal output*/ /**<CNcomment:高清红色分量输出*/
    HI_UNF_DISP_DAC_MODE_HD_G,           /**< HD green component signal output*//**<CNcomment:高清绿色分量输出*/
    HI_UNF_DISP_DAC_MODE_HD_B,           /**< HD blue component signal output*//**<CNcomment:高清蓝色分量输出*/
    HI_UNF_DISP_DAC_MODE_BUTT
}HI_UNF_DISP_DAC_MODE_E;


/**define the interface type of display output*/
/**CNcomment:定义支持的显示输出接口 */
typedef struct  hiUNF_DISP_INTERFACE_S
{
    HI_BOOL                      bScartEnable;                /**<flag of enable scart output*//**<CNcomment:是否输出Scart信号*/
    HI_BOOL                      bBt1120Enable;               /**<flag of enable Bt1120 output*//**<CNcomment:是否输出Bt1120数字信号*/
    HI_BOOL                      bBt656Enable;                /**<flag of enable Bt656 output*//**<CNcomment:是否输出Bt656数字信号*/
    HI_UNF_DISP_DAC_MODE_E       enDacMode[MAX_DAC_NUM];      /**<the DAC output signal type of the defined interface type *//**<CNcomment:各个DAC的输出信号*/
}HI_UNF_DISP_INTERFACE_S ;


/**define LCD output data width*/
/**CNcomment:定义LCD输出的数据位宽*/
typedef enum hiUNF_DISP_LCD_DATA_WIDTH_E
{
    HI_UNF_DISP_LCD_DATA_WIDTH8 = 0,       /**<8 bits*//**<CNcomment:8位*/
    HI_UNF_DISP_LCD_DATA_WIDTH16,          /**<16 bits*//**<CNcomment:16位*/
    HI_UNF_DISP_LCD_DATA_WIDTH24,          /**<24 bits*//**<CNcomment:24位*/
    HI_UNF_DISP_LCD_DATA_WIDTH_BUTT
}HI_UNF_DISP_LCD_DATA_WIDTH_E;

/**define the LCD data format*/
/**CNcomment:定义LCD的数据格式*/
typedef enum hiHI_UNF_DISP_LCD_DATA_FMT
{
    HI_UNF_DISP_LCD_DATA_FMT_YUV422 = 0,         /**<YUV422，data width is 16*//**<CNcomment:YUV422，位宽为16*/
    HI_UNF_DISP_LCD_DATA_FMT_RGB565 = 0x8,       /**<RGB565，data width is 16*//**<CNcomment:RGB565，位宽为16*/
    HI_UNF_DISP_LCD_DATA_FMT_RGB444 = 0xa,       /**<RGB444，data width is 16*//**<CNcomment:RGB444，位宽为16*/
    HI_UNF_DISP_LCD_DATA_FMT_RGB666 = 0xb,       /**<RGB666，data width is 24*//**<CNcomment:RGB666，位宽为24*/
    HI_UNF_DISP_LCD_DATA_FMT_RGB888 = 0xc,       /**<RGB888，data widht is 24*//**<CNcomment:RGB888，位宽为24*/
    HI_UNF_DISP_LCD_DATA_FMT_BUTT
}HI_UNF_DISP_LCD_DATA_FMT_E;

/**define LCD timing */
/**CNcomment:定义LCD的时序参数*/
typedef struct hiUNF_DISP_LCD_PARA_S
{
    HI_U32                    VFB;                 /**<vertical front blank*//**<CNcomment:垂直前消隐*/
    HI_U32                    VBB;                 /**<vertical back blank*//**<CNcomment:垂直后消隐*/
    HI_U32                    VACT;                /**<vertical active area*//**<CNcomment:垂直有效区*/
    HI_U32                    HFB;                 /**<horizonal front blank*//**<CNcomment:水平前消隐*/
    HI_U32                    HBB;                 /**<horizonal back blank*//**<CNcomment:水平后消隐*/
    HI_U32                    HACT;                /**<horizonal active area*/ /**<CNcomment:水平有效区*/
    HI_U32                    VPW;                 /**<vertical sync pluse width*//**<CNcomment:垂直脉冲宽度*/
    HI_U32                    HPW;                 /**<horizonal sync pluse width*/ /**<CNcomment:水平脉冲宽度*/
    HI_BOOL                   IDV;                 /**< flag of data valid signal is needed flip*//**<CNcomment:有效数据信号是否翻转*/
    HI_BOOL                   IHS;                 /**<flag of horizonal sync pluse is needed flip*//**<CNcomment:水平同步脉冲信号是否翻转*/
    HI_BOOL                   IVS;                 /**<flag of vertical sync pluse is needed flip*//**<CNcomment:垂直同步脉冲信号是否翻转*/
    HI_BOOL                   ClockReversal;       /**<flag of clock is needed flip*//**<CNcomment:时钟是否翻转*/
    HI_UNF_DISP_LCD_DATA_WIDTH_E   DataWidth;      /**<data width*/ /**<CNcomment:数据位宽*/
    HI_UNF_DISP_LCD_DATA_FMT_E       ItfFormat;      /**<data format.*//**<CNcomment:数据格式.*/
    HI_BOOL                   DitherEnable;        /**< flag of is enable Dither*//**<CNcomment:数据格式.*/
    HI_U32                    ClkPara0;            /**<PLL  register SC_VPLL1FREQCTRL0  value *//**<CNcomment:PLL  SC_VPLL1FREQCTRL0  寄存器*/
    HI_U32                    ClkPara1;            /**<PLL  register SC_VPLL1FREQCTRL1 value*//**<CNcomment:PLL   SC_VPLL1FREQCTRL1寄存器*/
    HI_U32                    InRectWidth;         /**< display rect width  */ /**< CNcomment:显示区域宽 */
    HI_U32                    InRectHeight;        /**< display rect height  */ /**< CNcomment:显示区域高  */
} HI_UNF_DISP_LCD_PARA_S;

/**define the layer which can attach to different display channel*/
/**CNcomment:定义可自由绑定的叠加层*/
typedef enum hiUNF_DISP_FREE_LAYER_E
{
    HI_UNF_DISP_FREE_LAYER_OSD_0,         /**<0sd layer0 which can be attach*/    /**<CNcomment:可自由绑定图形层0*/

    HI_UNF_DISP_FREE_LAYER_BUTT
}HI_UNF_DISP_FREE_LAYER_E;


/**define the layer which can be overlay on the display channel*/
/**CNcomment:定义DISPLAY通道上的叠加层*/
typedef enum hiUNF_DISP_LAYER_E
{
    HI_UNF_DISP_LAYER_VIDEO_0 = 0,   /**<video layer 0*//**<CNcomment:视频层0*/
    HI_UNF_DISP_LAYER_OSD_0,         /**<osd layer 0*//**<CNcomment:图形层0*/
    HI_UNF_DISP_LAYER_ATTACH_OSD_0,  /**< attached osd layer 0*//**<CNcomment:绑定图形层0*/

    HI_UNF_DISP_LAYER_BUTT
}HI_UNF_DISP_LAYER_E;


/**define the struct about color */
/**CNcomment:定义显示颜色的结构体 */
typedef struct  hiUNF_DISP_BG_COLOR_S
{
    HI_U8 u8Red ;            /**<red */ /**<CNcomment:红色分量*/
    HI_U8 u8Green ;          /**<green*//**<CNcomment:绿色分量*/
    HI_U8 u8Blue ;           /**<blue*//**<CNcomment:蓝色分量*/
} HI_UNF_DISP_BG_COLOR_S;

/********************************ENCODER STRUCT********************************/
/** define the enum of Macrovision output type*/
/** CNcomment:显示输出Macrovision模式枚举定义*/
typedef enum hiUNF_DISP_MACROVISION_MODE_E
{
    HI_UNF_DISP_MACROVISION_MODE_TYPE0,  /**<type 0 *//**<CNcomment:典型配置0 */
    HI_UNF_DISP_MACROVISION_MODE_TYPE1,  /**<type 1 *//**<CNcomment:典型配置1 */
    HI_UNF_DISP_MACROVISION_MODE_TYPE2,  /**<type 2  *//**<CNcomment:典型配置2 */
    HI_UNF_DISP_MACROVISION_MODE_TYPE3,  /**<type 3  *//**<CNcomment:典型配置3 */
    HI_UNF_DISP_MACROVISION_MODE_CUSTOM, /**<type of configure by user  *//**<CNcomment:用户自定义配置 */
    HI_UNF_DISP_MACROVISION_MODE_BUTT
} HI_UNF_DISP_MACROVISION_MODE_E;

/** define teletex data info structure*/
/** CNcomment:定义图文信息数据结构*/
typedef struct hiUNF_DISP_TTX_DATA_S
{
    HI_U8   *pu8DataAddr;               /**<Ttx data buffer virtual address*/ /**<CNcomment:Ttx数据用户虚拟地址*/
    HI_U32   u32DataLen;                /**<Ttx data lenght*//**<CNcomment:Ttx数据长度*/
} HI_UNF_DISP_TTX_DATA_S;


/* CGMS type select */
/*CNcomment:CGMS 类型选择*/
typedef enum hiUNF_DISP_CGMS_TYPE_E
{
    HI_UNF_DISP_CGMS_TYPE_A = 0x00,
    HI_UNF_DISP_CGMS_TYPE_B,

    HI_UNF_DISP_CGMS_TYPE_BUTT
}HI_UNF_DISP_CGMS_TYPE_E;


/* definition of CGMS mode */
/*CNcomment:定义CGMS 模式*/
typedef enum hiUNF_DISP_CGMS_MODE_E
{
   HI_UNF_DISP_CGMS_MODE_COPY_FREELY    = 0,    /* copying is permitted without restriction */
   HI_UNF_DISP_CGMS_MODE_COPY_NO_MORE   = 0x01, /* No more copies are allowed (one generation copy has been made) */
   HI_UNF_DISP_CGMS_MODE_COPY_ONCE      = 0x02, /* One generation of copies may be made */
   HI_UNF_DISP_CGMS_MODE_COPY_NEVER     = 0x03, /* No copying is permitted */
      
   HI_UNF_DISP_CGMS_MODE_BUTT
}HI_UNF_DISP_CGMS_MODE_E;


/** definition of CGMS configuration */
typedef struct hiUNF_DISP_CGMS_CFG_S
{
    HI_BOOL                  bEnable;    /** HI_TRUE:CGMS is enabled; HI_FALSE:CGMS is disabled */
    HI_UNF_DISP_CGMS_TYPE_E  enType;     /** type-A or type-B or None(BUTT) */
    HI_UNF_DISP_CGMS_MODE_E  enMode;     /** CGMS mode. */
     
}HI_UNF_DISP_CGMS_CFG_S;


/** define VBI information structure*/
/**CNcomment: 定义VBI信息数据结构*/
typedef struct hiUNF_DISP_VBI_DATA_S
{
    HI_U8  *pu8DataAddr;                 /**<Vbi data buffer virtual address*/ /**<CNcomment:Vbi数据用户虚拟地址*/
    HI_U32  u32DataLen;                  /**<Vbi data lenght*/  /**<CNcomment:Vbi数据长度*/
} HI_UNF_DISP_VBI_DATA_S;


/**define WSS information structure*/
/**CNcomment:定义图文信息数据结构 */
typedef struct hiUNF_DISP_WSS_DATA_S
{
    HI_BOOL bEnable;                /**<WSS configure enable  HI_TRUE: enable, HI_FALSE: disnable*/  /**<CNcomment:WSS配置使能。HI_TRUE：使能；HI_FALSE：禁止*/
    HI_U16  u16Data;                /**<Wss data */ /**<CNcomment:Wss数据*/
} HI_UNF_DISP_WSS_DATA_S;

/**define display channel interface type */
/**CNcomment:定义DISPLAY通道的接口类型*/
typedef enum hiUNF_DISP_INTF_TYPE_E
{
    HI_UNF_DISP_INTF_TYPE_TV = 0,    /**<TV type*/ /**<CNcomment:输出接口为TV*/
    HI_UNF_DISP_INTF_TYPE_LCD,       /**<LCD type*/ /**<CNcomment:输出接口为LCD*/
    HI_UNF_DISP_INTF_TYPE_BUTT
}HI_UNF_DISP_INTF_TYPE_E;

/**define display output range struct */
/**CNcomment:定义DISPLAY输出范围类型*/
typedef struct hiUNF_RECT_S
{
    HI_S32 x, y;

    HI_S32 w, h;
} HI_UNF_RECT_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */


/******************************* API declaration *****************************/
/** \addtogroup      H_1_2_6 */
/** @{ */  /** <!-- [DISPLAY] */

/**
\brief Initiallization DISP module. CNcomment:初始化DISP模块
\attention \n
Please call this API function, before call anyother API of DISP module. 
CNcomment:调用DISP模块其它接口前要求首先调用本接口
\param  none. CNcomment:无
\retval ::HI_SUCCESS  operation success. CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NOT_EXIST DISP device not exist.CNcomment:设备不存在
\retval ::HI_ERR_DISP_NOT_DEV_FILE  DISP  not device file .CNcomment:非设备
\retval ::HI_ERR_DISP_DEV_OPEN_ERR  DISP  open fail.CNcomment:打开失败
\see \n
none. CNcomment:无
*/
HI_S32 HI_UNF_DISP_Init(HI_VOID);

/**
\brief deinital. CNcomment:去初始化DISP模块
\attention \n
please call API HI_UNF_DISP_Close and open all the DISP device, before call this API.
CNcomment:在调用::HI_UNF_DISP_Close接口关闭所有打开的DISP后调用本接口
\param none. CNcomment:无
\retval ::HI_SUCCESS success.CNcomment:成功
\retval ::HI_ERR_DISP_DEV_CLOSE_ERR  DISP close fail.CNcomment:关闭失败
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_DeInit(HI_VOID);

/**
\brief Attach one DISP channel to anoter.CNcomment:将两个DISP通道绑定
\attention \n
Please finish the attach operation before the DISP channel has been open, and currently we only support HD channel attach to SD channel.
CNcomment:目前支持将高清DISP绑定到标清DISP通道上，绑定在打开DISP通道前必须完成绑定操作。
\param[in] enDstDisp   Destination DISP channel  CNcomment:目标DISP通道号
\param[in] enSrcDisp   source DISP channel.CNcomment:  源DISP通道号
\retval ::HI_SUCCESS  operation success.CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT  display not be initialization. CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter. CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT   invalid opeation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_Attach(HI_UNF_DISP_E enDstDisp, HI_UNF_DISP_E enSrcDisp);

/**
\brief dettach DISP.CNcomment:将两个DISP通道解绑定
\attention \n
should  close the DISP channels, before do detach operation.
CNcomment:只有在关闭两个DISP通道后才能进行解绑定操作。
\param[in] enDstDisp   Destination DISP channel.  CNcomment:目标DISP通道号
\param[in] enSrcDisp    source DISP channel.CNcomment: 源DISP通道号
\retval ::HI_SUCCESS  success. CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT   DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT   invalid operation.CNcomment:操作非法
\see \n
none. CNcomment:无
*/
HI_S32 HI_UNF_DISP_Detach(HI_UNF_DISP_E enDstDisp, HI_UNF_DISP_E enSrcDisp);

/**
\brief open DISP channel. CNcomment:打开指定DISP通道
\attention \n
Please config the valid parameters before open DISP. 
CNcomment:在打开DISP之前，先完成对其的参数设置，避免画面闪烁
\param[in] enDisp   DISP channel ID, please reference the define of HI_UNF_DISP_E.CNcomment:DISP通道号，请参见::HI_UNF_DISP_E
\retval ::HI_SUCCESS success.CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT   DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_CREATE_ERR    DISP create fail.CNcomment:DISP创建失败
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_Open(HI_UNF_DISP_E enDisp);

/**
\brief  coase DISP channel. CNcomment:关闭指定DISP
\attention \n
none. CNcomment:无
\param[in] enDisp DISP channel ID. CNcomment:DISP通道号
\retval ::HI_SUCCESS success. CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT DISP uninitialization.  CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_INVALID_PARA invalid input parameter. CNcomment:输入参数非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_Close(HI_UNF_DISP_E enDisp);

/**
\brief  attach OSD layer to DISP. CNcomment:将OSD绑定到DISP上
\attention \n
please finish attach operation before DISP channel be open.
CNcomment:必须在DISP打开之前完成绑定。
\param[in] enDisp      DISP channel ID. CNcomment:DISP通道号
\param[in] enLayer    the osd layer needed to be attach. CNcomment:可绑定的图形层
\retval ::HI_SUCCESS  success. CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT   DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR      CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA invalid input parameter.CNcomment: 输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT   invalid operation. CNcomment:操作非法
\see \n
none. CNcomment:无
*/
HI_S32 HI_UNF_DISP_AttachOsd(HI_UNF_DISP_E enDisp, HI_UNF_DISP_FREE_LAYER_E enLayer);

/**
\brief CNcomment:detach OSD layer from DISP. CNcomment:将OSD从DISP解绑定
\attention \n
none. CNcomment:无
\param[in] enDisp      DISP channel ID. CNcomment:DISP通道号
\param[in] enLayer     OSD layer needed detach. CNcomment:可绑定的图形层
\retval ::HI_SUCCESS  success. CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization. CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR      Input pointer is NULL. CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT  invalid operation.  CNcomment:操作非法
\see \n
none. CNcomment:无
*/
HI_S32 HI_UNF_DISP_DetachOsd(HI_UNF_DISP_E enDisp, HI_UNF_DISP_FREE_LAYER_E enLayer);

/**
\brief  set DISP interface type. CNcomment:设置DISP的接口类型
\attention \n
Interface type  setting is the first paramter, needed by DISP configuration. 
CNcomment:接口类型是DISP应该设置的第一个参数。
\param[in] enDisp      DISP channel ID. CNcomment:DISP通道号
\param[in] enIntfType  DISP interface type.  CNcomment:DISP的接口类型
\retval ::HI_SUCCESS   success. CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT   DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR      Input pointer is NULL. CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter. CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT   invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetIntfType(HI_UNF_DISP_E enDisp, HI_UNF_DISP_INTF_TYPE_E enIntfType);

/**
\brief get DISP interface type. CNcomment:获取DISP的接口类型
\attention \n
none. CNcomment:无
\param[in] enDisp        DISP channel ID.CNcomment:DISP通道号
\param[in] penIntfType  the pointer of DISP type. CNcomment:DISP的接口类型指针
\retval ::HI_SUCCESS   success. CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT   DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR        Input pointer is NULL. CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter. CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT   invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetIntfType(HI_UNF_DISP_E enDisp, HI_UNF_DISP_INTF_TYPE_E *penIntfType);

/**
\brief set DISP output format.CNcomment:设置DISP的制式
\attention \n
This API is only useful for TV interface type source , for LCD type this API has no effect. \n
for HD DISP channel please set HD display format, and for SD DISP channel please set SD display format.\n
for scenario of HD,SD use same source, only support format which frame rate is 50Hz or 60Hz.\n
CNcomment:只有当设置DISP为TV后，调用本接口才有意义。\n
对高清的DISP，只能设置高清的制式；对标清的DISP，只能设置标清的制式。\n
在同源显示场景下，暂不支持刷新率非50Hz/60Hz的制式，如：暂不支持1080P24/1080P25/1080P30
\param[in] enDisp               DISP channel ID.CNcomment:DISP通道号
\param[in] enEncodingFormat    DISP format. CNcomment:DISP的制式
\retval ::HI_SUCCESS  success. CNcomment:成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none. CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetFormat(HI_UNF_DISP_E enDisp, HI_UNF_ENC_FMT_E enEncodingFormat);

/**
\brief get DISP format. CNcomment:获取DISP的制式
\attention \n
none. CNcomment:无
\param[in] enDisp               DISP channel ID.CNcomment:DISP通道号
\param[in] penEncodingFormat    poiner of DISP format.DCNcomment:ISP的制式指针
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetFormat(HI_UNF_DISP_E enDisp, HI_UNF_ENC_FMT_E *penEncodingFormat);

/**
\brief  set DAC mode.CNcomment:设置DAC模式
\attention \n
Please config DISP paramter first, then call this API set DAC mode. \n
There are 6 DAC provided by SOC. suggest, please use the typcal DAC configuration.  DAC 0/1/2 used by HD channel, DAC3/4/5 used by SD channel.
CNcomment:DAC属于所有DISP共有资源，在完成DISP的参数配置并打开后，再调用本接口完成DAC的配置。\n
共有6个DAC，推荐0，1，2用作高清输出，3，4，5用作标清输出。
\param[in] pstDacMode   pointer of Dac mode. CNcomment:指针类型，DAC模式，请参见::HI_UNF_OUTPUT_INTERFACE_S
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetDacMode(const HI_UNF_DISP_INTERFACE_S *pstDacMode);

/**
\brief  Get DAC mode. CNcomment:获取DAC模式
\attention \n
none. CNcomment:无
\param[out] pstDacMode    pointer of Dac mode.CNcomment:指针类型，DAC模式
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetDacMode(HI_UNF_DISP_INTERFACE_S *pstDacMode);

/**
\brief Set LCD parameter. CNcomment:设置DISP的LCD参数
\attention \n
This API function is only useful for DISP interface is LCD, but is no effect for TV type.
CNcomment:只有当设置DISP为LCD后，调用本接口才有意义。
\param[in] enDisp         DISP channel ID. CNcomment:DISP通道号
\param[in] pstLcdPara     pointer of LCD paramter. CNcomment:指针类型，LCD参数，请参见::HI_UNF_DISP_LCD_PARA_S
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetLcdPara(HI_UNF_DISP_E enDisp, const HI_UNF_DISP_LCD_PARA_S *pstLcdPara);

/**
\brief  get LCD parameter which had been config. CNcomment:获取DISP的LCD参数
\attention \n
none.CNcomment:无
\param[in] enDisp          DISP channel ID.CNcomment:DISP通道号
\param[in] pstLcdPara      pointer of LCD paramter. CNcomment:指针类型，LCD参数
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无?*/
HI_S32 HI_UNF_DISP_GetLcdPara(HI_UNF_DISP_E enDisp, HI_UNF_DISP_LCD_PARA_S *pstLcdPara);

/**
\brief   set DISP layers Z order.CNcomment:设置DISP上叠加层的Z序
\attention \n
CNcomment:无
\param[in] enDisp          DISP channel ID.CNcomment: DISP通道号
\param[in] enLayer        layer ID which needed overlay to the DISP channel.CNcomment: DISP上的叠加层
\param[in] enZFlag        the way of overlay. CNcomment:Z序调节方式
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetLayerZorder(HI_UNF_DISP_E enDisp, HI_UNF_DISP_LAYER_E enLayer, HI_LAYER_ZORDER_E enZFlag);

/**
\brief  get DISP overlay z order.CNcomment:获取DISP上叠加层的Z序
\attention \n
In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.
CNcomment:在高标清绑定情况下，高清DISP的设置会自动同步到标清DISP；标清DISP的设置会自动同步到高清DISP。
\param[in] enDisp            DISP channel ID.CNcomment:DISP通道号
\param[in] enLayer           CNcomment:DISP上的叠加层
\param[in] pu32Zorder        CNcomment:叠加层Z序数值，数值越大优先级越高
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetLayerZorder(HI_UNF_DISP_E enDisp, HI_UNF_DISP_LAYER_E enLayer, HI_U32 *pu32Zorder);

/**
\brief set DISP back ground color.CNcomment:设置DISP背景色
\attention \n
none.
CNcomment:无
\param[in] enDisp       CNcomment:DISP通道号
\param[in] pstBgColor   CNcomment:指针类型，待配置的显示输出背景色。请参见::HI_UNF_BG_COLOR_S
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetBgColor(HI_UNF_DISP_E enDisp, const HI_UNF_DISP_BG_COLOR_S *pstBgColor);

/**
\brief  set DISP back ground color.CNcomment:获取DISP背景色
\attention \n
In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.
CNcomment:在高标清绑定情况下，高清DISP的设置会自动同步到标清DISP；标清DISP的设置会自动同步到高清DISP。
\param[in] enDisp          DISP channel ID.CNcomment:DISP通道号
\param[out] pstBgColor   pointer of back ground color.CNcomment: 指针类型，显示输出背景色
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetBgColor(HI_UNF_DISP_E enDisp, HI_UNF_DISP_BG_COLOR_S *pstBgColor);

/**
\brief  set DISP brightness.CNcomment:设置DISP亮度
\attention \n
if the value seted more than 100, we clip it to 100.CNcomment:大于100的值按100处理
\param[in] enDisp            DISP channel ID.CNcomment:DISP通道号
\param[in] u32Brightness   brightness value. the range is 0~100, 0 means the min brightness value.
CNcomment:待设置的显示输出亮度值。取值范围为0～100。0：最小亮度；100：最大亮度
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetBrightness(HI_UNF_DISP_E enDisp, HI_U32 u32Brightness);

/**
\brief   get the DISP brightness.CNcomment:获取DISP亮度
\attention \n
In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.
CNcomment:查询的默认亮度值为50。\n
在高标清绑定情况下，高清DISP的设置会自动同步到标清DISP；标清DISP的设置会自动同步到高清DISP。
\param[in] enDisp              DISP channel ID.CNcomment:DISP通道号
\param[out] pu32Brightness    pointer of brightness. CNcomment:指针类型，显示输出亮度值
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetBrightness(HI_UNF_DISP_E enDisp, HI_U32 *pu32Brightness);

/**
\brief  set DISP contrast value.CNcomment:设置DISP对比度
\attention \n
If the value is more than 100, we clip it to 100.
CNcomment:大于100的值按100处理
\param[in] enDisp          DISP channel ID.CNcomment:DISP通道号
\param[in] u32Contrast    contrast value. the range is 0~100, 0 means the min contrast value. \n
CNcomment:待设置的显示输出对比度值。取值范围为0～100。0：最小对比度；100：最大对比度
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetContrast(HI_UNF_DISP_E enDisp, HI_U32 u32Contrast);

/**
\brief  get DISP contrast value.CNcomment:获取DISP对比度
\attention \n
In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.\n
CNcomment:查询的默认对比度值为50。\n
在高标清绑定情况下，高清DISP的设置会自动同步到标清DISP；标清DISP的设置会自动同步到高清DISP。
\param[in] enDisp           DISP channel ID.CNcomment:DISP通道号
\param[out] pu32Contrast   pointer of contrast. CNcomment:指针类型，显示输出对比度值
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无?*/
HI_S32 HI_UNF_DISP_GetContrast(HI_UNF_DISP_E enDisp, HI_U32 *pu32Contrast);

/**
\brief   set DISP saturation. CNcomment:设置DISP饱和度
\attention \n
If the value is more than 100, we clip it to 100.
CNcomment:大于100的值按100处理
\param[in] enDisp             DISP channel ID.CNcomment:DISP通道号
\param[in] u32Saturation      saturation value. the range is 0~100, 0 means the min saturation value. \n
CNcomment:待设置的显示输出饱和度值。取值范围为0～100。0：最小饱和度；100：最大饱和度
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无?*/
HI_S32 HI_UNF_DISP_SetSaturation(HI_UNF_DISP_E enDisp, HI_U32 u32Saturation);

/**
\brief   get DISP saturation.CNcomment:获取DISP饱和度
\attention \n
In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.\n
CNcomment:查询的默认饱和度值为50。\n
在高标清绑定情况下，高清DISP的设置会自动同步到标清DISP；标清DISP的设置会自动同步到高清DISP。
\param[in] enDisp                 DISP channel ID.CNcomment:DISP通道号
\param[out] pu32Saturation    pointer of saturation. CNcomment:指针类型，显示输出饱和度值
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetSaturation(HI_UNF_DISP_E enDisp, HI_U32 *pu32Saturation);

/**
\brief  set DISP hueplus. CNcomment:设置DISP色调
\attention \n
none.CNcomment:无
\param[in] enDisp              DISP channel ID.CNcomment:DISP通道号
\param[in] u32HuePlus       hueplus value. the range is 0~100, 0 means the min hueplus value. \n
CNcomment:显示输出色调增益值。范围为0～100。0：表示最小色调增益；100：表示最大色调增益
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetHuePlus(HI_UNF_DISP_E enDisp, HI_U32 u32HuePlus);

/**
\brief get DISP hueplus. CNcomment:获取DISP色调
\attention \n
In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.\n
CNcomment:查询的默认色调值为50。\n
在高标清绑定情况下，高清DISP的设置会自动同步到标清DISP；标清DISP的设置会自动同步到高清DISP。
\param[in] enDisp          DISP channel ID.CNcomment: DISP通道号
\param[out] pu32HuePlus     pointer of hueplus. CNcomment:指针类型，显示输出色调增益值
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetHuePlus(HI_UNF_DISP_E enDisp, HI_U32 *pu32HuePlus);

/**
\brief set auto contrast adjustment.CNcomment:自适应对比度调节
\attention \n
none.CNcomment:无
\param[in] enDisp           DISP channel ID.CNcomment:DISP通道号
\param[out] bEnable         flag of enable or disnable.CNcomment:使能/禁止标志
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetAccEnable(HI_UNF_DISP_E enDisp, HI_BOOL bEnable);

/**
\brief Send teletex data pes.CNcomment:发送图文数据PES包
\attention \n
none.CNcomment:无
\param[in] enDisp            DISP channel ID.CNcomment:DISP通道号
\param[in] pstTtxData       pointer of ttxdata pes. CNcomment:指针类型，指向图文数据包的指针
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SendTtxData(HI_UNF_DISP_E enDisp, const HI_UNF_DISP_TTX_DATA_S *pstTtxData);

/**
\brief  send VBI data pes. CNcomment:发送VBI（Vertical Blanking Interval）数据PES包
\attention \n
none.CNcomment:无
\param[in] enDisp             DISP channel ID.CNcomment:DISP通道号
\param[in] pstVbiData        pointer of VBI data pes description structure.CNcomment:指针类型，指向VBI数据包的指针
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SendVbiData(HI_UNF_DISP_E enDisp, const HI_UNF_DISP_VBI_DATA_S *pstVbiData);

/**
\brief  set Wss. CNcomment:直接设置WSS（Wide Screen Singnalling）数据
\attention \n
none. CNcomment:无
\param[in] enDisp           DISP channel ID.CNcomment:DISP通道号
\param[in] pstWssData        pointer of Wss data description structure.CNcomment:指针类型，指向WSS数据的指针
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetWss(HI_UNF_DISP_E enDisp, const HI_UNF_DISP_WSS_DATA_S *pstWssData);

/**
\brief  set Macrovision mode CNcomment:设置Macrovision模式
\attention \n
none.CNcomment:无
\param[in] enDisp          DISP channel ID.CNcomment:DISP通道号
\param[in] enMode        Macrovision mode.  CNcomment:Macrovision模式，请参见::HI_UNF_MACROVISION_MODE_E
\param[in] pData          pointer of Macrovision control data CNcomment: 指针类型，自定义的Macrovision控制数据
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetMacrovision(HI_UNF_DISP_E enDisp, HI_UNF_DISP_MACROVISION_MODE_E enMode, const HI_VOID *pData);

/**
\brief get Macrovision mode. CNcomment: 获取Macrovision模式
\attention \n
none. CNcomment:无
\param[in] enDisp      DISP channel ID.CNcomment:DISP通道号
\param[out] penMode    pointer of Macrovision mode. CNcomment:指针类型，MACROVISION模式
\param[out] pData      a data pointer only valid whenpenMode=HI_MACROVISION_MODE_CUSTOM.\n
CNcomment:指针类型，仅当penMode=HI_MACROVISION_MODE_CUSTOM时有效
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_GetMacrovision(HI_UNF_DISP_E enDisp, HI_UNF_DISP_MACROVISION_MODE_E *penMode, const HI_VOID *pData);


/**
\brief   set CGMS data. CNcomment:设置CGMS（Copy Generation Management System）数据
\attention \n
none. CNcomment:无
\param[in] enDisp                   DISP channel ID.CNcomment:DISP通道号
\param[in] pstCgmsCfg             pointer of CGMS configuration  CNcomment:指针类型，指向CGMS配置数据的指针
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
none.CNcomment:无
*/
HI_S32 HI_UNF_DISP_SetCgms(HI_UNF_DISP_E enDisp, const HI_UNF_DISP_CGMS_CFG_S *pstCgmsCfg);

/**
\brief set Disp output range. CNcomment:设置Display输出区域
\attention \n
无
\param[in] enDisp                   DISP channel ID.CNcomment:DISP通道号
\param[in] pstOutRect             pointer of display output range.CNcomment:指针类型，指向Display输出区域配置数据的指针
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NO_INIT    DISP uninitialization.CNcomment:DISP未初始化
\retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:输入指针为空
\retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法
\retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:操作非法
\see \n
无
*/
HI_S32 HI_UNF_DISP_SetOutputWin(HI_UNF_DISP_E enDisp, HI_UNF_RECT_S *pstOutRect);
/** @} */  /** <!-- ==== API declaration end ==== */


/**
\brief set Disp output range. CNcomment:用于TC 设置颜色空间；
\attention \n
无
\param[in] enDisp                DISP channel ID.CNcomment:DISP通道号
\param[in] bEnable              是否使能TC colorspace mode.
\retval ::HI_SUCCESS CNcomment: success.成功
\retval ::HI_ERR_DISP_DEV_NOT_EXIST     DISP DEVICE NOT EXIST.
\retval ::HI_ERR_DISP_NOT_DEV_FILE          not char device.
\retval ::HI_ERR_DISP_DEV_OPEN_ERR     open device error.
\see \n
无*/
HI_S32 HI_UNF_DISP_SetCsc(HI_UNF_DISP_E enDisp, HI_BOOL bEnable);

#ifdef __cplusplus
 #if __cplusplus
}

 #endif
#endif
#endif
