/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_vi.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2010/03/26
  Description   :
  History       :
  1.Date        : 2010/03/26
    Author      : j00131665
    Modification: Created file

*******************************************************************************/
/** 
 * \file
 * \brief Describes the information about video input (VI). CNcomment: 提供VI的相关信息
 */

#ifndef  __HI_UNF_VI_H__
#define  __HI_UNF_VI_H__

#include "hi_type.h"
#include "hi_unf_common.h"


#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif


/********************************Error Code Definition********************************/
/** \addtogroup      H_3_6 */
/** @{ */  /** <!-- 【VI】 */

/**<Incorrect input parameter */
/**<CNcomment: 输入错误参数 */
#define HI_UNF_VI_INVALID_PARA_U32   (HI_U32)(-1)	

/** @} */  /** <!-- ====End of Error Code Definition==== */




/********************************Struct Definition********************************/
/** \addtogroup      H_2_2_10 */
/** @{ */  /** <!-- 【VI】 */

/**Channel type in BT.1120 YC separation mode */
/**CNcomment: BT.1120 YC分离模式通道类型 */
typedef enum hiUNF_VI_CHN_YC_SEL_E
{
    HI_UNF_VI_CHN_YC_SEL_Y = 0,		/**Y separation channel in BT.1120 YC separation mode*/ /**<CNcomment: BT.1120 YC分离模式下Y分离通道 */
    HI_UNF_VI_CHN_YC_SEL_C,			/**C separation channel in BT.1120 YC separation mode*/ /**<CNcomment: BT.1120 YC分离模式下C分离通道 */
    HI_UNF_VI_CHN_YC_SEL_BUTT
}HI_UNF_VI_CHN_YC_SEL_E;

/**Storage type */
/**CNcomment: 存储类型 */
typedef enum hiUNF_VI_STOREMETHOD_E
{
    HI_UNF_VI_STORE_METHOD_PNYUV = 0,  /**<plannar YCbCr */
    HI_UNF_VI_STORE_METHOD_SPNYC,      /**<Semi planar YC, chroma first, then lum */ /**<CNcomment: semi_plannar YC 422，色度V在前，U在后 */
    HI_UNF_VI_STORE_METHOD_PKYUV,      /**<package yuv */
    HI_UNF_VI_STORE_METHOD_BUTT     
} HI_UNF_VI_STOREMETHOD_E;
/**Odd/even field select */
/**CNcomment: 奇偶场选择模式 */
typedef enum hiUNF_VI_CAPSEL_E
{
    HI_UNF_VI_CAPSEL_ODD=0,     /**<Collect the data of the odd field only */ /**<CNcomment: 仅对奇数场采集 */
    HI_UNF_VI_CAPSEL_EVEN,      /**<Collect the data of the even field only */ /**<CNcomment: 仅对偶数场采集 */
    HI_UNF_VI_CAPSEL_BOTH,      /**<Collect the data of both odd and even fields */ /**<CNcomment: 对奇数场和偶数场都采集 */
    HI_UNF_VI_CAPSEL_BUTT
} HI_UNF_VI_CAPSEL_E;

/**Frame/field storage mode */
/**CNcomment: 帧场存储模式 */
typedef enum hiUNF_VI_STORE_MODE_E
{
    HI_UNF_VI_STORE_FIELD = 0,   /**<Field storage mode */ /**<CNcomment: 场存储模式 */
    HI_UNF_VI_STORE_FRAME,       /**<Frame storage mode */ /**<CNcomment: 帧存储模式 */
    HI_UNF_VI_STORE_BUTT
}HI_UNF_VI_STORE_MODE_E;

/**Input port */
/**CNcomment: 输入端口 */
typedef enum hiUNF_VI_E
{
    HI_UNF_VI_PORT0   = 0x0,  /**<Port 0, only this port can be configured in BT1120 mode */ /**<CNcomment: 端口0，BT1120模式下只能配置此端口 */
    HI_UNF_VI_PORT1,          /**<CNcomment: 端口1 */
    HI_UNF_VI_BUTT
}HI_UNF_VI_E;

/**Input interface mode */
/**CNcomment: 输入接口模式 */
typedef enum hiUNF_VI_INPUT_MODE_E
{
    HI_UNF_VI_MODE_BT656 = 0,          /**<ITU-R BT.656 YUV4:2:2 standard, 576I */ /**<CNcomment: ITU-R BT.656 YUV4:2:2 标准，576I */
    HI_UNF_VI_MODE_BT656_480I,		   /**<ITU-R BT.656 YUV4:2:2 standard, 480I */ /**<CNcomment: ITU-R BT.656 YUV4:2:2 标准，480I */
    HI_UNF_VI_MODE_BT601,              /**<ITU-R BT.601 YUV4:2:2 standard */ /**<CNcomment: ITU-R BT.601 YUV4:2:2 标准 */
    HI_UNF_VI_MODE_DIGITAL_CAMERA,     /**<Digital camera. The data format can be RGB or YCbCr */ /**<CNcomment: 数字摄像头，数据可能是RGB或者YCbCr */
    HI_UNF_VI_MODE_RAW_DATA,           /**<Data input over the composite video broadcast signal (CVBS) interface. The data does not need to be processed. */ /**<CNcomment: 通过CVBS输入的数据，不需要处理 */
    HI_UNF_VI_MODE_USB_CAM,            /**<Virtual VI. The data is not input from the hardware, but by calling the related get and put interfaces. */ /**<CNcomment: USB 摄像头，靠用户Get/Put输入数据 */ 
    HI_UNF_VI_MODE_VIRTUAL,            /**<CNcomment: 虚拟VI,不从硬件输入数据，靠用户Get/Put输入数据 */    
    HI_UNF_VI_MODE_BT1120_480P,	       /**<ITU-R BT.1120 YUV4:2:2 standard, 480P */ /**<CNcomment: ITU-R BT.1120 YUV4:2:2 标准，480P */
    HI_UNF_VI_MODE_BT1120_576P,        /**<ITU-R BT.1120 YUV4:2:2 standard, 576P */ /**<CNcomment: ITU-R BT.1120 YUV4:2:2 标准，576P */
    HI_UNF_VI_MODE_BT1120_720P,        /**<ITU-R BT.1120 YUV4:2:2 standard, 720P_50 */ /**<CNcomment: ITU-R BT.1120 YUV4:2:2 标准，720P_50 */
    HI_UNF_VI_MODE_BT1120_720P_60,	   /**<ITU-R BT.1120 YUV4:2:2 standard, 720P_60 */ /**<CNcomment: ITU-R BT.1120 YUV4:2:2 标准，720P_60 */
    HI_UNF_VI_MODE_BT1120_1080I,       /**<ITU-R BT.1120 YUV4:2:2 standard, 1080I_50 */ /**<CNcomment: ITU-R BT.1120 YUV4:2:2 标准，1080I_50 */
    HI_UNF_VI_MODE_BT1120_1080I_60,    /**<ITU-R BT.1120 YUV4:2:2 standard, 1080I_60 */ /**<CNcomment: ITU-R BT.1120 YUV4:2:2 标准，1080I_60 */
    HI_UNF_VI_MODE_BT1120_1080P,       /**<ITU-R BT.1120 YUV4:2:2 standard, 1080P */ /**<CNcomment: ITU-R BT.1120 YUV4:2:2 标准，1080P */
    HI_UNF_VI_MODE_BUTT
} HI_UNF_VI_INPUT_MODE_E;

/**VI frame buffer management mode */
/**CNcomment: VI帧缓存管理方式 */
typedef enum hiUNF_VI_BUF_MGMT_E
{
    HI_UNF_VI_BUF_ALLOC   = 0x0,  /**<VI alloc buffer */ /**<CNcomment: VI申请帧BUF */
    HI_UNF_VI_BUF_MMAP,           /**<User alloc frame buffer, then maps it to VI */ /**<CNcomment: 用户申请帧BUF，并映射给VI */    
    HI_UNF_VI_BUF_BUTT
}HI_UNF_VI_BUF_MGMT_E;

/**VI attributes */
/**CNcomment: VI属性 */
typedef struct hiUNF_VI_ATTR_S
{
    HI_UNF_VI_E              enViPort;		/**<Input port */ /**<CNcomment: 输入端口 */
    HI_UNF_VI_INPUT_MODE_E   enInputMode;   /**<Video input mode */ /**<CNcomment: 视频输入模式 */
    HI_RECT_S                stInputRect;   /**<Crop region of a window */ /**<CNcomment: 窗口的裁减区域 */
    HI_UNF_VI_CAPSEL_E       enCapSel;		/**<Odd/even field select */ /**<CNcomment: 奇偶场采集选择 */

    HI_UNF_VI_CHN_YC_SEL_E   enChnYC;       /**<Valid only in BT1120 mode */ /**<CNcomment: 只有在bt1120模式下有效 */
    HI_UNF_VI_STOREMETHOD_E  enStoreMethod; /**<Video format */ /**<CNcomment: 视频格式 */
    HI_UNF_VI_STORE_MODE_E	 enStoreMode;   /**<Frame/field mode */ /**<CNcomment: 帧场模式 */
	HI_UNF_VI_BUF_MGMT_E     enBufMgmtMode; /**<VI frame buffer management mode */ /**<CNcomment: VI帧缓存管理方式 */

    HI_U32 u32YStride;		/**<Stride of the Y component in planar mode. It is the only stride in other modes. */ /**<CNcomment: planar模式下Y的stride，其他模式的唯一stride */
    HI_U32 u32CStride;		/**<Stride of the C component in planar mode. It is invalid in other modes. */ /**<CNcomment: planar模式下C的stride，其他模式无效 */
    HI_U32 u32ViBufAddr;	/**<Buffer address of frame buffer, user does not need to config in alloc mode;
                                Virtual address of user mode that user inputs frame buffer in MMAP mode */
                            /**<CNcomment: 帧buf地址, ALLOC模式下用户不需要配置，VI分配的物理地址
    									   MMAP模式下用户输入帧buf的用户态虚拟地址 */
    HI_U32 u32FrameSize;    /**<Size of the memory used by a frame, output parameter. You do not need to configure it. */
                            /**<CNcomment: 一帧占用的内存空间,输出参数，用户不需要配置 */
    HI_U32 u32BufSize;		/**<Size of the frame buffer, output parameter. You do not need to configure it. */
                            /**<CNcomment: 帧buf的大小,输出参数，用户不需要配置 */
    HI_U32 u32BufNum;       /**<Number of available buffers */ /**<CNcomment: 可用的帧buf的个数 */
} HI_UNF_VI_ATTR_S;

/**Attributes of the VI buffer */
/**CNcomment: VI Buffer 属性 */
typedef struct  hiUNF_VI_BUF_S
{ 
    HI_U32                      u32FrameIndex;	/**<Frame index */ /**<CNcomment: 帧索引 */
    HI_UNF_VIDEO_FORMAT_E       enPixelFormat;  /**<Sampling format of the input video */ /**<CNcomment: 输入视频采样格式 */
    HI_U32                      u32Width;       /**<Input width */ /**<CNcomment: 输入宽度 */
    HI_U32                      u32Height;      /**<Input height */ /**<CNcomment: 输入高度 */
                                                        
    HI_UNF_VIDEO_FIELD_MODE_E   enField;        /**<Sampling field type, top field, bottom field, or all */ /**<CNcomment: 采场类型，top/bottom/all */
    HI_U32                      u32DownScaled;  /**<Whether to perform down sampling */ /**<CNcomment: 是否要下采样 */
	HI_UNF_VI_BUF_MGMT_E        enBufMode;      /**<VI frame buffer management mode */ /**<CNcomment: VI帧缓存管理方式 */

    /* Only u32PhyAddr[0] is valid in RGB or package storage mode.
       Only u32PhyAddr[0-1] is valid in semi-planar storage mode.
       The validity of pVirAddr and u32Stride is the same as the validity of u32PhyAddr. */
    /* CNcomment: 如果是RGB或者package存储模式，只有u32PhyAddr[0]有效.
       如果是semi-planar存储模式，只有u32PhyAddr[0-1]有效,
       相应的pVirAddr，u32Stride也与u32PhyAddr有效性一致. */
    HI_U32                      u32PhyAddr[3];        /**<Physical address of the A, B, or C component *//**<CNcomment: A/B/C 分量物理地址 */	
    HI_VOID                     *pVirAddr[3];         /**<Virtual address of the A, B, or C component */ /**<CNcomment: A/B/C 分量虚拟地址 */
    HI_U32                      u32Stride[3];         /**<Stride of the A, B, or C component */ /**<CNcomment: A/B/C 分量stride */

    HI_U32                      u32PtsMs;             /**<Presentation time stamp */ /**<CNcomment: 时间戳 */                     
}HI_UNF_VI_BUF_S;

/** @} */  /** <!-- ==== Struct Definition End ==== */

/********************************API Declaration********************************/
/** \addtogroup      H_1_2_8 */
/** @{ */  /** <!-- 【VI】 */

/** 
\brief Initializes the video input unit (VIU). CNcomment: 初始化VI
\attention \n
Before calling the VIU, you must call this application programming interface (API). CNcomment: 调用VI模块要求首先调用该接口
\param[in] N/A CNcomment: 无
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_DEV_NOT_EXIST No VI device exists. CNcomment: 设备不存在
\retval ::HI_ERR_VI_NOT_DEV_FILE The file is not a VI file. CNcomment: 文件非设备
\retval ::HI_ERR_VI_DEV_OPENED The VI device fails to be started. CNcomment: 打开设备失败
\see \n
N/A 无
*/
HI_S32 HI_UNF_VI_Init(HI_VOID);


/** 
\brief Deinitializes the VIU. CNcomment: 去初始化VI
\attention \n
\param[in] N/A CNcomment: 无
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_DEV_NOT_EXIST No VI device exists. CNcomment: 设备不存在
\retval ::HI_ERR_VI_DEV_CLOSE_ERR The VI device fails to be stopped. CNcomment: 关闭VI 设备失败
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_DeInit(HI_VOID);


/** 
\brief Obtains the attributes of a VI port. CNcomment: 获取VI端口默认属性
\attention \n
By default, port 0 is used, half D1 and BT656 formats are used, the data of the odd field is collected, and the semi-planar YUV4:2:0 data is output.
CNcomment: 默认Port=0, HALF-D1, BT656，采集偶场，输出SemiPlanner YUV4:2:0格式数据
\param[in] pstAttr Pointer to VI attributes CNcomment: VI属性指针
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: 空指针
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_GetDefaultAttr(HI_UNF_VI_ATTR_S *pstAttr);


/** 
\brief Set the attributes of a VI port. CNcomment: 设置VI Port属性
\attention \n
This reserved API is combined with HI_UNF_VI_Create, and cannot be called dynamically.
CNcomment: 预留接口，与Create合一，不可动态调用
\param[in] hVi VI handle CNcomment: VI句柄
\param[in] pstAttr  Pointer to VI attributes CNcomment: VI属性指针
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: 空指针
\retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: 句柄错误
\retval ::HI_ERR_VI_CHN_INIT_BUF_ERR An error occurs when the buffer is initialized. CNcomment: 初始化buffer错误
\retval ::HI_ERR_VI_INVALID_PARA The attribute parameters are incorrect. CNcomment: 属性参数错误
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_SetAttr(HI_HANDLE hVi, HI_UNF_VI_ATTR_S *pstAttr);


/** 
\brief Obtains the attributes of a VI port. CNcomment: 获取VI Port属性
\attention \n
\param[in] hVi VI handle CNcomment: VI句柄
\param[out] pstAttr Pointer to VI attributes CNcomment: VI属性指针
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: 空指针
\retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: 句柄错误
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_GetAttr(HI_HANDLE hVi, HI_UNF_VI_ATTR_S *pstAttr);


/** 
\brief Enables a VI port to create a VI handle. CNcomment: 打开VI Port，创建Vi句柄
\attention \n
Before calling the VIU, you must call this API.\n
Unless the virtual VI is used, the port ID must correspond to the hardware. That is, the hardware and software must use the same port\n
CNcomment: 调用VI 模块需要首先调用该接口\n
CNcomment: 除非使用虚拟VI, 否则PortID需要与硬件对应,硬件上使用了哪个Port,那么软件也必须使用哪个Port.\n
\param[in] pstAttr CNcomment: Pointer to VI attributes VI属性指针
\param[in] phandle CNcomment: hVi Pointer to the VI handle VI句柄指针
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: 空指针
\retval ::HI_ERR_VI_CHN_INIT_BUF_ERR An error occurs when the buffer is initialized. CNcomment: 初始化buffer错误
\retval ::HI_ERR_VI_INVALID_PARA The attribute parameters are incorrect. CNcomment: 属性参数错误
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_Create(HI_UNF_VI_ATTR_S *pstAttr, HI_HANDLE *phandle);


/** 
\brief Disable a VI port to destroy the handle. CNcomment: 关闭VI Port，销毁句柄
\attention \n
\param[in] hVi VI handle CNcomment: VI句柄
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: 句柄错误
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_Destroy(HI_HANDLE hVi);


/** 
\brief Obtains the address of a frame buffer over a VI port. CNcomment: 获取虚拟VI Port 一帧图像Buffer
\attention \n
If a virtual VI port is created, you can obtain the VI buffer for stuffing the YUV data by calling this API.\n
This API is used to store the picture captured by the USB camera in the VI frame buffer.\n
CNcomment: 如果用户创建的是虚拟VI Port，一般用于USB摄像头\n
CNcomment: 用户调用此接口从VI获取一帧BUF来填入YUV数据\n
\param[in] hVi VI handle CNcomment: VI句柄
\param[out] pViBuf Pointer to the VI buffer CNcomment: VI buffer指针
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: 句柄错误
\retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: 空指针
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_GetFrame(HI_HANDLE hVi, HI_UNF_VI_BUF_S * pViBuf);


/** 
\brief Releases the VI frame buffer for the driver.  CNcomment: 发送虚拟VI Port 一帧图像Buffer，驱动虚拟Port工作
\attention
In HI_UNF_VI_BUF_ALLOC mode, HI_UNF_VI_GetFrame gets the address of one YUV frame data, after copying YUV data, \n
user can use this function to inform VI data is ready. \n
In HI_UNF_VI_BUF_MMAP mode(only used in USB camera), when camera captures one frame, \n
user can use this function to inform VI data is ready. \n
CNcomment: 当设置为HI_UNF_VI_BUF_ALLOC模式时，HI_UNF_VI_GetFrame获取到一帧YUV数据的地址，\n
					并且拷贝好YUV数据后，就可以调用此接口通知VI数据已经准备好\n
当设置为HI_UNF_VI_BUF_MMAP模式时(仅用于USB摄像头)，摄像头捕获到一帧图像，\n
									就可以调用此接口通知VI数据已经准备好\n					
\param[in] hVi VI handle CNcomment: VI句柄
\param[in] pViBuf Pointer to the VI buffer CNcomment: VI buffer指针
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: 句柄错误
\retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: 空指针
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_PutFrame(HI_HANDLE hVi, const HI_UNF_VI_BUF_S * pViBuf);


/** 
\brief Obtains the address of a YUV picture. CNcomment: 获取一帧YUV 图像地址
\attention \n
You do not need to call this API generally. It is recommended that you bind the VIU to the video encoder (VENC) or video output unit (VOU) to implement the encoding function or VIVO loopback function.
CNcomment: 一般情况下，用户不需要调用此接口，推荐直接将VI与VENC或者VO进行绑定以便实现编码或者VIVO环回功能。
\param[in] hVi VI handle CNcomment: VI句柄
\param[out] pViBuf Pointer to the VI buffer CNcomment: VI buffer指针
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: 句柄错误
\retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: 空指针
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_AcquireFrame(HI_HANDLE hVi, HI_UNF_VI_BUF_S * pViBuf);


/** 
\brief Releases the frame buffer for the VIU after the VENC or VOU obtains a YUV picture.
CNcomment: 用户归还一帧YUV 图像地址
\attention \n
You do not need to call this API generally. It is recommended that you bind the VIU to the VENC or VOU to implement the encoding function or VIVO loopback function.
CNcomment: 一般情况下，用户不需要调用此接口，推荐直接将VI与VENC或者VO进行绑定以便实现编码或者VIVO环回功能。
\param[in] hVi VI handle CNcomment: VI句柄
\param[in] pViBuf Pointer to the VI buffer CNcomment: VI buffer指针
\retval ::HI_SUCCESS Success CNcomment: 成功
\retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: 句柄错误
\retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: 空指针
\see \n
N/A CNcomment: 无
*/
HI_S32 HI_UNF_VI_ReleaseFrame(HI_HANDLE hVi, const HI_UNF_VI_BUF_S * pViBuf);
/** @} */  /** <!-- ====API Declaration End ==== */


#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif
#endif
