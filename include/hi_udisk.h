/**
 \file
 \brief udisk业务模块对外的头文件
 \copyright Hisilicon Tech. Co., Ltd.
 \date 2009-2050
 \version main\2
 \author r00112701/z42136
 \date 2009-11-9
 */


#ifndef __HI_UDISK_H__
#define __HI_UDISK_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */


        /*--------------------------------------------------------------
        Error Code
        ----------------------------------------------------------------*/
        enum
        {
                HI_UDISK_ERR_NULL           = HI_FAILURE,
                HI_UDISK_ERR_INVALIDPARA    = -2,
                HI_UDISK_ERR_NOMEM          = -3,
                HI_UDISK_ERR_EXIST          = -4,
                HI_UDISK_ERR_FULL           = -5,
                HI_UDISK_ERR_UNKNOWN_TYPE   = -6,
                HI_UDISK_ERR_NOTEXIST       = -7,
                HI_UDISK_ERR_BUTT
        };


        /*--------------------------------------------------------------
        数据结构定义
        ----------------------------------------------------------------*/

#define MAX_UDISK_NAME_LEN  256

        /** 磁盘信息 */
        typedef struct
        {
                //HI_U32  u32Port;        /**< 磁盘所在的USB端口, 目前没有实现 */
                HI_U64  u64TotalSize;        /**< 磁盘容量*/
                HI_U64  u64AvailSize;    /* 磁盘可用容量 */
                HI_CHAR szVendor[MAX_UDISK_NAME_LEN];     /**< 厂商，只读 */
                HI_CHAR szModel[MAX_UDISK_NAME_LEN];      /**< 型号，只读 */

                HI_CHAR szDevPath[MAX_UDISK_NAME_LEN];     /**< 磁盘设备节点所在目录，只读 */
                HI_CHAR szMntPath[MAX_UDISK_NAME_LEN];     /**< 磁盘映射主目录，所有的分区都在该目录下；不同磁盘目录可能不一致，只读 */
        } HI_UDISK_DISKINFO_S;

        /** 磁盘分区格式 */
        typedef enum
        {
                HI_UDISK_FSTYPE_FAT = 0x0,
                HI_UDISK_FSTYPE_FAT32,
                HI_UDISK_FSTYPE_NTFS,
                HI_UDISK_FSTYPE_EXT2,
                HI_UDISK_FSTYPE_EXT3,

                HI_UDISK_FSTYPE_BUT,
        } HI_UDISK_FSTYPE_E;


        /** 磁盘分区信息 */
        typedef struct
        {
                HI_BOOL bMounted;           /**< 是否正确挂载。如果没有挂载，下面的属性都无效 */
                HI_UDISK_FSTYPE_E enFSType; /**< 分区文件格式 */
                HI_U64  u64TotalSize;       /**< 分区容量 */
                HI_U64  u64AvailSize;       /**< 分区可用容量 */

                HI_CHAR szDevPath[MAX_UDISK_NAME_LEN];  /**< 分区设备节点目录，只读 */
                HI_CHAR szMntPath[MAX_UDISK_NAME_LEN];  /**< 分区挂载目录，只读 */
        } HI_UDISK_PARTITIONINFO_S;


        /** 文件列表 */
        typedef struct
        {
                HI_U32  u32Index;        /**< 文件在文件列表中的索引号，从0开始编号 */
                HI_U32  u32Type;         /**< 0:DIR, 1:FILE */
                HI_U64  u32Size;         /**< 文件大小, Byte */
                HI_U32  u32CTime;        /**< 文件创建时间 */
                HI_CHAR* pszShortName;   /**< 文件名，不带路径，只读 */
                HI_CHAR* pszFullName;    /**< 带路径的文件名, 只读 */
        } HI_UDISK_FILEINFO_S;

        /** 目录浏览排序方式 */
        typedef enum
        {
                HI_UDISK_SORT_DEFAULT       = 0x00000011, /**< 默认排序 */

                HI_UDISK_SORT_ASC           = 0x00000001, /**< 按升序排序。未指定ASC/DESC情况下，默认为ASC。ASC/DESC可与NAME/TIME/SIZE/TYPE组合适用 */
                HI_UDISK_SORT_DESC          = 0x00000002, /**< 按降序排序 */

                HI_UDISK_SORT_NAME          = 0x00000010,    /**< 按名字排序，未指定NAME/TIME/SIZE/TYPE的情况下，默认为NAME */
                HI_UDISK_SORT_TIME          = 0x00000020,    /**< 按时间排序 */
                HI_UDISK_SORT_SIZE          = 0x00000040,    /**< 按大小排序 */
                HI_UDISK_SORT_EXT           = 0x00000080,    /**< 按类型排序，即按文件扩展名排序 */

                HI_UDISK_SORT_BUTT
        } HI_UDISK_SORT_MODE_E;

        /** 目录浏览过滤条件 */
        typedef enum
        {
                HI_UDISK_FLT_DEFAULT    = 0x00000005,    /**< 默认方式: UP+SUB, 大小写不关心 */
                HI_UDISK_FLT_NODIR      = 0x00000000,    /**< 不包含任何目录 */

                HI_UDISK_FLT_UPDIR      = 0x00000001,    /**< 搜索结果包含上级目录，即".." */
                HI_UDISK_FLT_CURDIR     = 0x00000002,    /**< 搜索结果包含当前目录，即"." */
                HI_UDISK_FLT_SUBDIR     = 0x00000004,    /**< 搜索结果包含目录 */

                HI_UDISK_FLT_CASECARE   = 0x00000008,    /**< 搜索时关心大小写，对文件和目录都有效 */

                HI_UDISK_FLT_BUTT
        } HI_UDISK_FILTER_E;

        /** 目录搜索 */
        typedef struct
        {
                HI_BOOL bRecursive;                 /**< 是否递归搜索子目录中的文件/目录 */
                HI_UDISK_SORT_MODE_E enSortMode;    /**< 目录浏览排序方式 */
                HI_UDISK_FILTER_E enFilterType;     /**< 目录浏览过滤条件 */
                HI_CHAR * pFileFilter;              /**< 用法: ".*":(所有文件)；"": 不包含任何文件；".mp3": 只取mp3文件；".jpg,.png": 取jpg和png文件 */
        } HI_UDISK_SCAN_S;

        typedef struct
        {
                HI_UDISK_FILEINFO_S ** ppFileList;
                HI_U32 u32FileNum;
        } HI_UDISK_FILELIST_S;

        /** 事件类型 */
        typedef enum
        {
                HI_UDISK_EVENT_PLUGIN = 0x0, /**< 磁盘插入 */
                HI_UDISK_EVENT_PLUGOUT,      /**< 磁盘拔出 */
                HI_UDISK_EVENT_MOUNTED,      /**< 分区加载 */
                HI_UDISK_EVENT_UMOUNTED,    /**< 分区卸载 */
                HI_UDISK_EVENT_FULL,         /**< 分区满 */
                HI_UDISK_EVENT_ALLPARTMOUNTED, /* 该磁盘下所有分区已加载*/
                HI_UDISK_EVENT_BUTT
        } HI_UDISK_EVENT_E;

        /**
        \brief  事件回调函数
        \attention \n
        无
        \param[in] HI_UDISK_EVENT_E : 事件类型
        \param[in] pParam : 事件参数，不同的事件类型，对应不同的参数结构，参见HI_UDISK_EVENT_PARAM_xxxx_S

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_EVENT_PARAM_PLUG_S \n
        ::HI_UDISK_EVENT_PARAM_MOUNT_S \n
        ::HI_UDISK_EVENT_PARAM_FULL_S
        */
        typedef void (*HI_UDISK_EVENT_CALLBACK)(HI_UDISK_EVENT_E enEvent, HI_VOID * pParam, HI_VOID * pPrivate);

        /** 事件参数: for PLUGIN/PLUGOUT */
        typedef struct
        {
                HI_U32 u32DiskIndex;
        } HI_UDISK_EVENT_PARAM_PLUG_S;

        /** 事件参数: for MOUNTED/UNMOUNTED */
        typedef struct
        {
                HI_U32 u32DiskIndex;
                HI_U32 u32PartitionIndex;
        } HI_UDISK_EVENT_PARAM_MOUNT_S;

        /** 事件参数: for FULL */
        typedef struct
        {
                HI_U32 u32DiskIndex;
                HI_U32 u32PartitionIndex;
        } HI_UDISK_EVENT_PARAM_FULL_S;


        /******************************* API declaration *****************************/
        /** @defgroup  UDISK组件对外接口模块
         *  @ingroup H1
         *  @brief 详细描述UDISK组件对外接口的API函数
         *  @{  */


        /**
        \brief  UDISK初始化
        \attention \n
        无
        \param[in] pUdiskRoot : UDISK工作目录，必须保证是空目录，如"/tmp"
        \param[in] u32MaxDisk : 系统支持的最大磁盘个数，为0则使用系统默认值(32个)
        \param[in] u32MaxPartition : 系统支持的每个磁盘下最大分区个数，为0则使用系统默认值(32个)

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_Deinit
        */
        HI_S32 HI_UDISK_Init(const HI_CHAR * pUdiskRoot);

        /**
        \brief  UDISK去初始化
        \attention \n
        无
        \param[in] 无

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_Init
        */
        HI_S32 HI_UDISK_Deinit(HI_VOID);

        /**
        \brief  获取Udisk的主目录
        \attention \n
        无
        \param[in] 无

        \retval  ::Udisk的主目录，如果为HI_NULL，则说明UDISK未初始化
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_Init
        */
        HI_CHAR * HI_UDISK_GetRoot(HI_VOID);


        /**
        \brief  获取磁盘个数
        \attention \n
        无
        \param[out] pu32DiskNum  : 磁盘个数

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_GetDiskInfo
        */
        HI_S32 HI_UDISK_GetDiskNum(HI_U32 * pu32DiskNum);

        /**
        \brief  获取磁盘信息
        \attention \n
        无
        \param[in] u32DiskIndex : 磁盘Index，即第几个磁盘，值为0到[DiskNum-1]
        \param[out] pDiskInfo   : 磁盘信息

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_GetDiskNum
        */
        HI_S32 HI_UDISK_GetDiskInfo(HI_U32 u32DiskIndex, HI_UDISK_DISKINFO_S * pDiskInfo);

        /**
        \brief  获取指定磁盘下的分区个数
        \attention \n
        无
        \param[in] u32DiskIndex  : 磁盘Index
        \param[out] pu32PartitionNum  : 磁盘下分区个数

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_GetPartitionInfo
        */
        HI_S32 HI_UDISK_GetPartitionNum(HI_U32 u32DiskIndex, HI_U32 * pu32PartitionNum);

        /**
        \brief  获取指定磁盘下的指定分区的信息
        \attention \n
        无
        \param[in] u32DiskIndex  : 磁盘Index
        \param[in] u32PartitionIndex  : 分区Index
        \param[out] pPartitionInfo  : 分区信息

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_GetPartitionNum
        */
        HI_S32 HI_UDISK_GetPartitionInfo(HI_U32 u32DiskIndex, HI_U32 u32PartitionIndex, HI_UDISK_PARTITIONINFO_S * pPartitionInfo);


        /**
        \brief  分区格式化
        \attention \n
        无
        \param[in] u32DiskIndex  : 磁盘Index
        \param[in] u32PartitionIndex  : 分区Index
        \param[in] enFSType  : 分区欲格式化成哪种格式

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_GetDiskNum \n
        ::HI_UDISK_GetPartitionNum
        */
        HI_S32 HI_UDISK_FormatPartition(HI_U32 u32DiskIndex, HI_U32 u32PartitionIndex, HI_UDISK_FSTYPE_E enFSType);

        /**
        \brief  获取文件列表
        \attention \n
        无
        \param[in] pszDir  : 文件所在主目录
        \param[in] pScanOpt  : 获取方式
        \param[out] pFileList  : 文件/目录列表，内存由UDISK分区，使用完需调用HI_UDISK_FreeFileList释放该内存
        \param[out] pFileNum  : 文件/目录个数

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_FreeFileList
        */
        HI_S32 HI_UDISK_GetFileList(
                HI_CHAR *pszDir,
                HI_UDISK_SCAN_S * pScanOpt,
                HI_UDISK_FILELIST_S * pFileList);

        /**
        \brief  释放文件列表所占内存空间
        \attention \n
        无
        \param[in] pFileList  : 文件列表指针

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_GetFileList
        */
        HI_S32 HI_UDISK_FreeFileList(HI_UDISK_FILELIST_S * pFileList);


        /**
        \brief  注册事件回调
        \attention \n
        无
        \param[in] enEvent  : 事件类型
        \param[in] pCallbackFunc  : 事件类型对应的回调函数
        \param[in] pPrivate  : 用户私有数据，事件到达时，会通过回调函数透传给用户。内存由用户分配/释放，由用户保证内存的有效性

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_UnRegisterEventCallback
        */
        HI_S32 HI_UDISK_RegisterEventCallback(
                HI_UDISK_EVENT_E enEvent,
                HI_UDISK_EVENT_CALLBACK pCallbackFunc,
                HI_VOID * pPrivate);


        /**
        \brief  注销事件回调
        \attention \n
        无
        \param[in] enEvent  : 事件类型

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        ::HI_UDISK_RegisterEventCallback
        */
        HI_S32 HI_UDISK_UnRegisterEventCallback(HI_UDISK_EVENT_E enEvent);

        /**
        \brief  设置分区是否上报FULL事件，默认情况下，所有的分区都不上报
        \attention \n
        无
        \param[in] u32DiskIndex  : 磁盘Index
        \param[in] u32PartitionIndex  : 分区Index
        \param[in] bReport  : 是否上报
        \param[in] u64WaterLine  : 磁盘剩余空间少于该水线就上报FULL事件, 单位Byte

        \retval  ::HI_SUCCESS
        \retval  ::HI_FAILURE

        \see \n
        无
        */
        HI_S32 HI_UDISK_SetFullReport(HI_U32 u32DiskIndex, HI_U32 u32PartitionIndex, HI_BOOL bReport, HI_U64 u64WaterLine);

        HI_VOID HI_UDISK_VfatParaSet(HI_BOOL bLinuxVfatType);


        /** @} */  /*! <!-- API declaration end */


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UDISK_H__ */


