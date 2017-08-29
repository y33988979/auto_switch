/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : hi_unf_ttx.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2011/10/20
  Description   : Teletext UNF header file
  History       :
  1.Date        : 2011/10/20
    Author      : l00185424
    Modification: Created file

******************************************************************************/
#ifndef __HI_UNF_TTX_H__
#define __HI_UNF_TTX_H__

#include "hi_type.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif  /* End of #ifdef __cplusplus */

/***************************** Macro Definition ******************************/
/**<Teletext max line in page */ /** CNcomment: teletext页的最大行数 */
#define HI_UNF_TTX_MAX_LINES (32)
/**<Teletext line size */ /** CNcomment: teletext行的长度 */
#define HI_UNF_TTX_LINE_SIZE (46)

/** @} */  /** <!-- ==== Macro Definition end ==== */

/********************************Structure Definition********************************/
/** \addtogroup      Teletext */
/** @{ */  /** <!-- 【Teletext】 */

/**<Teletext key support list */ /** CNcomment: 默认支持的交互方式 */

typedef enum hiUNF_TTX_KEY_E
{
    HI_UNF_TTX_KEY_0,
    HI_UNF_TTX_KEY_1,
    HI_UNF_TTX_KEY_2,
    HI_UNF_TTX_KEY_3,
    HI_UNF_TTX_KEY_4,
    HI_UNF_TTX_KEY_5,
    HI_UNF_TTX_KEY_6,
    HI_UNF_TTX_KEY_7,
    HI_UNF_TTX_KEY_8,
    HI_UNF_TTX_KEY_9, /** Three number key to open a specified page *//** CNcomment: <三个数字键打开指定页 */
    HI_UNF_TTX_KEY_PREVIOUS_PAGE, /** Previous page */  /** CNcomment: <上一页 */
    HI_UNF_TTX_KEY_NEXT_PAGE, /** Next page */ /** CNcomment: <下一页 */
    HI_UNF_TTX_KEY_PREVIOUS_SUBPAGE, /** Previous subpage *//** CNcomment: <上一 子页 */
    HI_UNF_TTX_KEY_NEXT_SUBPAGE, /** Next subpage */ /** CNcomment: <下一 子页*/
    HI_UNF_TTX_KEY_PREVIOUS_MAGAZINE, /** Previous magazine *//** CNcomment: <上一杂志 */
    HI_UNF_TTX_KEY_NEXT_MAGAZINE, /** Next magazine *//** CNcomment: <下一杂志 */
    HI_UNF_TTX_KEY_RED, /** First link in packet X/27, if inexistence, Show first valid page*//** CNcomment: <X/27 包中的第一个链接，无X/27则显示最近有效页 */
    HI_UNF_TTX_KEY_GREEN, /** Second  link in packet X/27, if inexistence, Show second valid page*/  /** CNcomment: <X/27 包中的第二个链接，无X/27则显示第二有效页 */
    HI_UNF_TTX_KEY_YELLOW, /** Third  link in packet X/27, if inexistence, Show third valid page*/ /** CNcomment: <X/27 包中的第三个链接，无X/27则显示第三有效页 */
    HI_UNF_TTX_KEY_CYAN, /** Fourth  link in packet X/27, if inexistence, Show fourth valid page*/ /** CNcomment: <X/27 包中的第四个链接，无X/27则显示第四有效页 */
    HI_UNF_TTX_KEY_INDEX, /** Sixth  link in packet X/27, if inexistence, Show index  page*/ /** CNcomment: <X/27 包中的第六个链接，无X/27则指向起始页 */
    HI_UNF_TTX_KEY_REVEAL, /**Reveal or hide concealed  information *//** CNcomment: <显示/隐藏conceal 信息 */
    HI_UNF_TTX_KEY_HOLD, /** Switch between start and stop auto play  *//** CNcomment: <自动播放/停止自动播放切换 */
    HI_UNF_TTX_KEY_MIX, /** Switch  between  transparent and nontransparent  background *//** CNcomment: <Teletext背景透明/不透明切换 */
    HI_UNF_TTX_KEY_UPDATE, /** Update current page*//** CNcomment: <更新当前页 */
    HI_UNF_TTX_KEY_BUTT /**<Invalid key*//**CNcomment:< 无效的按键 */
} HI_UNF_TTX_KEY_E;

/**<Teletext output type */
typedef enum hiUNF_TTX_OUTPUT_E
{
    HI_UNF_TTX_VBI_OUTPUT, /**<Only VBI output ,nonsupport  for the moment *//** CNcomment:<VBI 输出，暂不支持*/
    HI_UNF_TTX_OSD_OUTPUT, /**<Only OSD output */ /** CNcomment:<OSD 输出 */
    HI_UNF_TTX_DUAL_OUTPUT, /**<VBI OSD dual output ,VBI nonsupport  for the moment*//**  CNcomment:<VBI和OSD同时输出，暂不支持VBI */
    HI_UNF_TTX_BUTT /** Invalid output type */ /**  CNcomment:<无效输出类型*/
} HI_UNF_TTX_OUTPUT_E;

/**<Teletext type */
typedef enum hiUNF_TTX_TYPE_E
{
    HI_UNF_TTX_INITTTX = 1, /**<Initial Teletext page */  /** CNcomment:<Teletext 图文*/
    HI_UNF_TTX_TTXSUBT = 2, /**<Teletext subtitle page */ /** CNcomment:<Teletext 字幕*/
    HI_UNF_TTX_ADDINFO = 3, /** Nonsupport for the moment <Additional information page */ /**  暂不支持CNcomment:<附加信息页 */
    HI_UNF_TTX_PROGSCD = 4, /** Nonsupport for the moment <Programme schedule page */  /** 暂不支持CNcomment:<节目指南页 */
    HI_UNF_TTX_TTXSUBT_HIP = 5, /** Nonsupport for the moment <Teletext subtitle page for hearing impaired people */ /** 暂不支持CNcomment:<为听力有障碍的人设置的Teletext字幕 页*/
    HI_UNF_TTX_TTXSUBT_BUTT /** Invalid teletext type */ /** CNcomment:<无效的teletext 类型 */
} HI_UNF_TTX_TYPE_E;

/**<Teletext page type */
typedef enum hiUNF_TTX_PAGE_TYPE_E
{
    HI_UNF_TTX_PAGE_CUR, /**<Current reveal page *//** 当前显示页*/
    HI_UNF_TTX_PAGE_INDEX,      /**<Initial Teletext page , if  packet X/30 exist, return index page in X/30, otherwise return default index page 100*/
    /** CNcomment:<初始页，如果有X/30包，返回X/30包指定初始页，否则返回默认首页100 */
    HI_UNF_TTX_PAGE_LINK1, /** First link  in packet  X/27, if  inexistence, return first valid page*//** CNcomment:<X/27包中第1个链接，如果没有，返回当前页最近有效页 */
    HI_UNF_TTX_PAGE_LINK2, /** Second link  in packet  X/27, if inexistence, return second valid page*//**CNcomment:<X/27包中第2个链接，如果没有，返回当前页第二有效页 */
    HI_UNF_TTX_PAGE_LINK3, /** Third link  in packet  X/27, if  inexistence, return third valid page*//**CNcomment:<X/27包中第3个链接，如果没有，返回当前页第三有效页 */
    HI_UNF_TTX_PAGE_LINK4, /** Fourth  link  in packet  X/27, if  inexistence, return fourth valid page*//**CNcomment:<X/27包中第4个链接，如果没有，返回当前页第四有效页 */
    HI_UNF_TTX_PAGE_LINK5, /** Fifth link  in packet  X/27, if inexistence, return fifth valid page*//** CNcomment:<X/27包中第5个链接，如果没有，返回0ff:3f7f */
    HI_UNF_TTX_PAGE_LINK6, /** Sixth link  in packet  X/27, if inexistence, return Sixth valid page*//**CNcomment:<X/27包中第6个链接，如果没有，返回0ff:3f7f */
    HI_UNF_TTX_PAGE_BUTT /** Invalid  page type */ /**无效页类型 */
} HI_UNF_TTX_PAGE_TYPE_E;

/**<Teletext user command type */
typedef enum hiUNF_TTX_CMD_E
{
    HI_UNF_TTX_CMD_KEY, /** <(HI_UNF_TTX_KEY_E *)Default alternation type, key */ /** CNcomment:<按键，默认的交互方式 */
    HI_UNF_TTX_CMD_OPENPAGE, /** (HI_UNF_TTX_PAGE_ADDR_S *) Open specified page*/ /** CNcomment:<(HI_UNF_TTX_PAGE_ADDR_S *)打开指定页 */
    HI_UNF_TTX_CMD_GETPAGEADDR, /** (HI_UNF_TTX_GETPAGEADDR_S *)Get current page , index page and  link page  address*//**  CNcomment:<(HI_UNF_TTX_GETPAGEADDR_S *) 获取当前、首页、链接页地址 */
    HI_UNF_TTX_CMD_CHECKPAGE, /** (HI_UNF_TTX_CHECK_PARAM_S *) Check the specified page be received or not*//**  CNcomment:<(HI_UNF_TTX_CHECK_PARAM_S *) 检查是否收到参数中指定的页*/
    HI_UNF_TTX_CMD_SETREQUEST, /** (HI_UNF_TTX_REQUEST_RAWDATA_S *) Sets up a request for teletext raw data*//**  CNcomment:<(HI_UNF_TTX_REQUEST_RAWDATA_S *) 请求获取teletext中的原始数据 */
    HI_UNF_TTX_CMD_CLEARREQUEST, /** (HI_UNF_TTX_REQUEST_RAWDATA_S *) Clears a request set up by the HI_UNF_TTX_CMD_SETREQUEST*//**  CNcomment:<(HI_UNF_TTX_REQUEST_RAWDATA_S *) 释放由HI_UNF_TTX_CMD_SETREQUEST创建的数据请求 */
    HI_UNF_TTX_CMD_BUTT /** Invalid command type *//** CNcomment:<无效命令类型*/
} HI_UNF_TTX_CMD_E;

/**<G0  char set */
typedef  enum   hiUNF_TTX_G0SET_E
{
    HI_UNF_TTX_G0SET_LATIN, /** LATIN G0 Primary Set  *//** CNcomment:<LATIN G0主字符集*/
    HI_UNF_TTX_G0SET_CYRILLIC_1, /** CYRILLIC_1 G0 Primary Set *//** CNcomment:<CYRILLIC_1  G0主字符集*/
    HI_UNF_TTX_G0SET_CYRILLIC_2, /** CYRILLIC_2 G0 Primary Set*//**  CNcomment:<CYRILLIC_2 G0主字符集*/
    HI_UNF_TTX_G0SET_CYRILLIC_3, /** CYRILLIC_3 G0 Primary Set*//** CNcomment:<CYRILLIC_3 G0主字符集 */
    HI_UNF_TTX_G0SET_GREEK, /** GREEK  G0 Primary Set*//** CNcomment:<GREEK G0主字符集*/
    HI_UNF_TTX_G0SET_HEBREW, /** HEBREW  G0 Primary Set*//** CNcomment:<HEBREW  G0主字符集 */
    HI_UNF_TTX_G0SET_ARABIC, /**ARABIC  G0 Primary Set*//** CNcomment:<ARABIC G0主字符集*/
    HI_UNF_TTX_G0SET_BUTT /** Invalid G0 Primary Set *//** CNcomment:<无效G0主字符集 */
} HI_UNF_TTX_G0SET_E;

typedef  enum   hiUNF_TTX_CHARSET_E
{
    HI_UNF_TTX_CHARSET_G0, /** G0  character set */  /** CNcomment:<G0  字符集*/
    HI_UNF_TTX_CHARSET_G1, /** G1  character set*/  /** CNcomment:<G1字符集*/
    HI_UNF_TTX_CHARSET_G2, /** G2  character set */  /** CNcomment:<G2 字符集*/
    HI_UNF_TTX_CHARSET_G3, /** G3  character set */  /** CNcomment:<G3 字符集*/
    HI_UNF_TTX_CHARSET_BUTT /** Invalid  character set */  /** CNcomment:<无效字符集 */
} HI_UNF_TTX_CHARSET_E;

typedef HI_U32 HI_UNF_TTX_COLOR;

typedef struct hiUNF_TTX_PAGEAREA_S
{
    HI_U32 u32Row         : 8; /** The origination  row  number of the area  */       /**  CNcomment:<区域起始行号*/
    HI_U32 u32Column      : 8; /** The origination  column  number of the area */   /**  CNcomment:<区域起始列号*/
    HI_U32 u32RowCount    : 8; /** The count of row the area covers */       /** CNcomment:<区域覆盖的列数*/
    HI_U32 u32ColumnCount : 8; /** The count of column  the area covers *//**  CNcomment:<区域覆盖的行数 */
} HI_UNF_TTX_PAGEAREA_S;

typedef  struct  hiUNF_TTX_CHARATTR_S
{
    HI_U32               u32Index    : 8; /** Index of a char in a character set  *//**  CNcomment:<字符在字符集中的索引*/
    HI_BOOL              bContiguous : 1; /**  Contiguous mosaic char or not *//** CNcomment:<是否为连续马赛克标志 */
    HI_UNF_TTX_G0SET_E   enG0Set     : 3; /** G0 Primary Set  , latin , arabic .... *//** CNcomment:<G0主字符集 */
    HI_UNF_TTX_CHARSET_E enCharSet   : 3; /**  Character set  , G0 ,  G1  ....*/   /**  CNcomment:<字符集 */
    HI_U32               u8NationSet : 6; /** National  subset,  English ,French,  German .... */       /** CNcomment:<国家字符子集 */
    HI_U32               u8Reserved  : 11;
} HI_UNF_TTX_CHARATTR_S;

typedef struct hiUNF_TTX_DRAWCAHR_S
{
    HI_UNF_TTX_CHARATTR_S  * pstCharAttr;   /** Character attribution, it can decide the position of a char in  a  font */
    /** CNcomment:<字符属性，决定了一个字符在特定字库中的位置*/
    HI_UNF_TTX_PAGEAREA_S * pstPageArea; /** Area of character in page *//** CNcomment:<字符在页面上的位置 */
    HI_UNF_TTX_COLOR        u32Foreground; /**Foreground color *//** CNcomment:<前景色 */
    HI_UNF_TTX_COLOR        u32Background; /**Background color *//** CNcomment:<背景色 */
} HI_UNF_TTX_DRAWCAHR_S;

typedef struct hiUNF_TTX_FILLRECT_S
{
    HI_UNF_TTX_PAGEAREA_S * pstPageArea; /** Destination rectangle  *//** CNcomment:<目的矩形*/
    HI_UNF_TTX_COLOR        u32Color; /** Color *//** CNcomment:<颜色值 */
} HI_UNF_TTX_FILLRECT_S;

typedef struct hiUNF_TTX_REFRESHLAYER_S
{
    HI_UNF_TTX_PAGEAREA_S * pstPageArea; /** Destination rectangle  *//** CNcomment:<(HI_UNF_TTX_BUFFER_PARAM_S *) 创建缓存 */
} HI_UNF_TTX_REFRESHLAYER_S;

typedef struct hiUNF_TTX_BUFFER_PARAM_S
{
    HI_U32 u32Row     : 8; /** The row number of buffer page*//** CNcomment:<缓存页面的行数 */
    HI_U32 u32Column  : 8; /** The column  number of buffer page*//** CNcomment:<缓存页面的列数 */
    HI_U32 u8Reserved : 16;
} HI_UNF_TTX_BUFFER_PARAM_S;

typedef enum hiUNF_TTX_CB_E
{
    HI_UNF_TTX_CB_TTX_TO_APP_MSG, /** Send message to GUI pthread *//**CNcomment<发送绘制消息到GUI线程   */
    HI_UNF_TTX_CB_APP_FILLRECT, /** (HI_UNF_TTX_FILLRECT_S *) Fill rectangle *//**  CNcomment:<(HI_UNF_TTX_FILLRECT_S *)矩形填充 */
    HI_UNF_TTX_CB_APP_DRAWCHAR,   /**(HI_UNF_TTX_DRAWCAHR_S*)Select a char from a specified font and draw it  in specified rectangle of OSD by specified foreground and background*/
    /** CNcomment:(HI_UNF_TTX_DRAWCAHR_S*) <绘制函数，将指定字符以指定的前、背景色显示在OSD的指定区域 */
    HI_UNF_TTX_CB_APP_REFRESH, /** (HI_UNF_TTX_REFRESHLAYER_S*) Refresh layer */ /** CNcomment:<(HI_UNF_TTX_REFRESHLAYER_S*) 图层刷新函数 */
    HI_UNF_TTX_CB_CREATE_BUFF, /** (HI_UNF_TTX_BUFFER_PARAM_S *) Create buffer */ /** CNcomment:<(HI_UNF_TTX_BUFFER_PARAM_S *) 创建缓存 */
    HI_UNF_TTX_CB_DESTROY_BUFF, /** Destroy buffer *//** CNcomment:<销毁缓存 */
    HI_UNF_TTX_CB_GETPTS, /** (HI_S64 *) Get the PTS of the stream */ /** CNcomment:<(HI_S64 *) 获取当前播放码流的PTS*/
    HI_UNF_TTX_CB_BUTT /** Invalid callback type*//** CNcomment:<无效回调类型*/
} HI_UNF_TTX_CB_E;

/** Callback function */ /** CNcomment:<回调函数 */
typedef HI_S32 (*HI_UNF_TTX_CB_FN)(HI_HANDLE hTTX, HI_UNF_TTX_CB_E enCB, HI_VOID *pvCBParam);

/**<Teletext Init param */
typedef struct hiUNF_TTX_INIT_PARA_S
{
    HI_U8 *pu8MemAddr;   /** The address of memory ,  If  0, malloc the memory in the module, Otherwise malloced outside the module */
    /** CNcomment:<数据分配的起始地址，如果为0则内部分配 ，否则由外部分配内存*/
    HI_U32 u32MemSize;       /** The size of memory,  If  0, the size decided in the module, Otherwise decided outside the module */
    /** CNcomment:<数据分配的大小，如果为0 ，由内部决定，否则大小由外部决定*/
    HI_UNF_TTX_CB_FN pfnCB; /** Callback function *//** CNcomment:<回调函数*/
    HI_BOOL          bFlash; /** Permit flash or not */           /**CNcomment:<是否开启闪烁功能 */
    HI_BOOL          bNavigation; /**  Permit navigation bar *//** CNcomment:<是否提供导航条 */
} HI_UNF_TTX_INIT_PARA_S;

/**<Teletext page address */
typedef struct hiUNF_TTX_PAGE_ADDR_S
{
    HI_U8  u8MagazineNum; /**<Magazine number */   /** CNcomment:<杂志号 */
    HI_U8  u8PageNum; /**<Page number */       /** CNcomment:<页号 */
    HI_U16 u16PageSubCode; /**<Page sub-code */ /** CNcomment:<子页号 */
} HI_UNF_TTX_PAGE_ADDR_S;

/**<Teletext content param */
typedef struct hiUNF_TTX_CONTENT_PARA_S
{
    HI_UNF_TTX_TYPE_E      enType; /**<Teletext content type */      /** CNcomment:<Teletext内容类型 */
    HI_UNF_TTX_PAGE_ADDR_S stInitPgAddr;/**<Init page address, if Magazine number or Page number be equal to 0xFF,set to 100th page.sub-page numbet default  0*/
    /** CNcomment:<初始页地址，如果杂志号或页号为0xff，则设置为第100页。子页号默认为0 */
} HI_UNF_TTX_CONTENT_PARA_S;

typedef struct hiUNF_TTX_CHECK_PARAM_S
{
    HI_UNF_TTX_PAGE_ADDR_S stPageAddr; /**[in]<page address*/ /** CNcomment:<传入:页地址  */
    HI_BOOL                bSucceed; /**[out]<success or failure*/    /** CNcomment:<传出:是否成功 */
} HI_UNF_TTX_CHECK_PARAM_S;

/**<Get page address*/
typedef struct hiUNF_TTX_GETPAGEADDR_S
{
    HI_UNF_TTX_PAGE_TYPE_E enPageType; /**[in]< page type */ /** CNcomment:<传入: 页类型 */
    HI_UNF_TTX_PAGE_ADDR_S stPageAddr; /**[out]< page address */ /**  CNcomment:<传出 : 页地址*/
} HI_UNF_TTX_GETPAGEADDR_S;

/**<Teletext raw data*/ /** CNcomment:<ttx原始数据 */
typedef struct hiUNF_TTX_RAWDATA_S
{
    HI_U32 u32ValidLines; /**< bit-field lines  0..31 */ /** CNcomment:<有效位标识 */
    HI_U8  au8Lines[HI_UNF_TTX_MAX_LINES][HI_UNF_TTX_LINE_SIZE]; /**<line data */ /** CNcomment:<ttx行数据 */
} HI_UNF_TTX_RAWDATA_S;

/** Callback function in which notified raw data to consumer */ /** CNcomment:<用于回传ttx原始数据的回调函数 */
typedef HI_S32 (*HI_UNF_TTX_REQUEST_CALLBACK_FN)(HI_UNF_TTX_RAWDATA_S *pstRawData);

/**<Request teletext raw data*/ /** CNcomment:<请求ttx原始数据 */
typedef struct hiUNF_TTX_REQUEST_RAWDATA_S
{
    HI_UNF_TTX_RAWDATA_S *pstRawData;  /**[out]<raw data address*/ /** CNcomment:<传入:原始数据地址  */
    HI_UNF_TTX_REQUEST_CALLBACK_FN pfnRequestCallback; /**[in]<Callback function */ /** CNcomment:<回调函数 */
} HI_UNF_TTX_REQUEST_RAWDATA_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/********************************API declaration********************************/
/** \addtogroup      Teletext  */
/** @{ */  /** <!-- 【Teletext】 */

/**
 \brief     Initializes  TTX  module. CNcomment: 初始化TTX模块
 \attention \n
none. CNcomment: 无
 \param        none. CNcomment: 无
 \retval ::HI_SUCCESS     success.  CNcomment:  成功
 \retval ::HI_FAILURE        failure. CNcomment: 失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_Init(HI_VOID);

/**
 \brief  Deinitializes TTX module. CNcomment:去初始化TTX模块
 \attention \n
none. CNcomment: 无
 \param      none. CNcomment: 无
 \retval ::HI_SUCCESS     success.  CNcomment:  成功
 \retval ::HI_FAILURE       failure. CNcomment: 失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_DeInit(HI_VOID);

/**
 \brief  Create a TTX instance, just support for a single  instance for the moment.  CNcomment: 创建TTX实例，目前只支持单实例
 \attention \n
After creating a instance  successfully, the instance  default  to be enable , decode and be
prepared to display teletext. Call  correspond interface to display teletext.
CNcomment: 创建成功后这个实例默认enable，解析并准备显示
teletext内容。调用相应的输出控制接口后输出。
 \param[in] pstInitParam    Initialized  parameter.  CNcomment: 初始化参数
 \param[out] phTTX    Teletext  instance.   CNcomment: Teletext句柄
 \retval ::HI_SUCCESS     success.    CNcomment: 成功
 \retval ::HI_FAILURE        failure.  CNcomment: 失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_Create(HI_UNF_TTX_INIT_PARA_S* pstInitParam, HI_HANDLE* phTTX);

/**
 \brief    Destory  a  teletext instance.  CNcomment: 销毁TTX实例
 \attention \n
none.CNcomment:无
 \param[in] hTTX      Teletext instance.   CNcomment: Teletext句柄
 \retval ::HI_SUCCESS   success.     CNcomment: 成功
 \retval ::HI_FAILURE     failure.  CNcomment:  失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_Destroy(HI_HANDLE hTTX);

/**
 \brief   Inject the teletext PES data  .  CNcomment:注入Teletext PES 数据
 \attention \n
none.CNcomment:无
 \param[in] hTTX     Teletext instance.   CNcomment: Teletext句柄
 \param[in] pu8Data      Address of data.   CNcomment: 数据地址
 \param[in] u32DataSize     the length of data. CNcomment: 数据长度
 \retval ::HI_SUCCESS    success.   CNcomment: 成功
 \retval ::HI_FAILURE      failure.  CNcomment:  失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_InjectData(HI_HANDLE hTTX, HI_U8 *pu8Data, HI_U32 u32DataSize);

/**
 \brief   Reset data  .  CNcomment:清除收到的数据 数据
 \attention \n
none.CNcomment:无
 \param[in] hTTX     Teletext instance.   CNcomment: Teletext句柄
 \retval ::HI_SUCCESS    success.   CNcomment: 成功
 \retval ::HI_FAILURE      failure.  CNcomment:  失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_ResetData(HI_HANDLE hTTX);

/**
 \brief  Set the initial page address of teletext.
CNcomment: 设置Teletext的初始页
 \attention \n
none.CNcomment:无
 \param[in] hTTX      Teletext instance.   CNcomment: Teletext句柄
 \param[in] pstContentParam  context  parameter.  CNcomment:内容参数
 \retval ::HI_SUCCESS    success.    CNcomment:成功
 \retval ::HI_FAILURE      failure.   CNcomment:失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_SwitchContent (HI_HANDLE hTTX, HI_UNF_TTX_CONTENT_PARA_S* pstContentParam);

/**
 \brief  All operation related to OSD.
CNcomment: 和OSD相关的所有操作
 \attention \n
none.CNcomment:无
 \param[in] hTTX      Teletext instance.   CNcomment: Teletext句柄
 \param[in] enMsgAction  Action of the message.  CNcomment:消息指定的动作
 \retval ::HI_SUCCESS    success.    CNcomment:成功
 \retval ::HI_FAILURE      failure.   CNcomment:失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_Display(HI_HANDLE hTTX, HI_HANDLE hDispalyHandle);

/**
 \brief   Enable  or disable teletext output, and set the type of output.
CNcomment: 使能或关闭teletext输出、设置输出类型
 \attention \n
 The parameter can be reset  time after time.   CNcomment:  可重复进行输出设置
 \param[in] hTTX        Teletext instance.     CNcomment: Teletext句柄
 \param[in]enOutput     Output  type: OSD,VBI or OSD  VBI dual output.   CNcomment:  输出类型:OSD / VBI /OSD-VBI同时输出
 \param[in] bEnable       HI_TRUE: enable,  HI_FALSE: disable.   CNcomment:  HI_TRUE: 使能，HI_FALSE: 关闭
 \retval ::HI_SUCCESS      success.  CNcomment:  成功
 \retval ::HI_FAILURE        failure.  CNcomment:  失败
 \see \n
none.CNcomment:无
 */
HI_S32 HI_UNF_TTX_Output (HI_HANDLE hTTX, HI_UNF_TTX_OUTPUT_E enOutput, HI_BOOL bEnable);

/**
 \brief     The function  of TTX instance to handle user's operation.  CNcomment:TTX实例用户操作处理函数
 \attention \n
none.CNcomment:无
 \param[in] hTTX     Teletext instance.   CNcomment: Teletext句柄
 \param[in] enCMD      Type of command.   CNcomment: 命令类型
 \param[in] pvCMDParam     Parameter of  command(The parameter must be  conveted to appropriate  type at every
specifical application), when the command is UPDATE or EXIT, the command can be NULL.
CNcomment: 命令参数(具体应用需要强制转换)，UPDATE/EXIT时可为NULL
 \param[out] pvCMDParam    Parameter of command , when the command is  GETPAGEADDR, it points to the address of specifical  pages.
CNcomment:  命令参数，GETPAGEADDR时输出页地址
 \retval ::HI_SUCCESS    success.   CNcomment: 成功
 \retval ::HI_FAILURE      failure.  CNcomment:  失败
 \see \n
Please  consult  the definition of  HI_UNF_TTX_CMD_E.  CNcomment: 请参考HI_UNF_TTX_CMD_E定义
 */
HI_S32 HI_UNF_TTX_ExecCmd(HI_HANDLE hTTX,
                          HI_UNF_TTX_CMD_E enCMD, HI_VOID *pvCMDParam);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif
#endif
