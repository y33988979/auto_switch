/*******************************************************************************
 *             Copyright 2004 - 2050, Hisilicon Tech. Co., Ltd.
 *                           ALL RIGHTS RESERVED
 * FileName: hi_loader_info.h
 * Description:
 *
 * History:
 * Version   Date         Author     DefectNum    Description
 * main1     2008-11-26   c47559
 ******************************************************************************/
#ifndef __UPGRD_INFO_H__
#define __UPGRD_INFO_H__


#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

        /*************************** Structure Definition ****************************/
        /** \addtogroup      H_2_2*/
        /** @{ */  /** <!-- 【loader升级参数区数据结构】 */

        /**LOADER DB与OTA参数魔数,用作校验数据的标识*/
#define LOADER_MAGIC_NUMBER 0x4C4F4144
        /**升级文件名称最大长度*/
#define LOADER_FILE_NAME_LEN       128

        /**用户名的最大长度 */
#define LOADER_USER_NAME_LEN        32

        /**密码的最大长度 */
#define LOADER_PASSWORD_LEN         32


        /**内置序列号是否开启的开关*/
#define LOADER_INNER_STB_SN
        /**IP地址定义*/
        typedef HI_U32 HI_IPAddr;
        /**IP端口号定义*/
        typedef HI_U16 HI_IPPort;

#if 0
        typedef enum UPG_UpgradeType
        {
                UPGRADE_TYPE_NONE,
                UPGRADE_TYPE_APP_FORCE,/*0x51DB*/
                UPGRADE_TYPE_IP_FORCE,
                UPGRADE_TYPE_USB,
                UPGRADE_TYPE_SERIAL,
                UPGRADE_TYPE_BIOS_FORCE,
                UPGRADE_TYPE_PIC_FORCE,
                UPGRADE_TYPE_APP_AUTO,/*0xA00A*/
                UPGRADE_TYPE_APP_FORCE2,    /* TEST CODE 0x40CA,该情况下升级失败不会重复升级*/
                UPGRADE_TYPE_IP_AUTO/*0xa622 or 0xB05A(No App)*/
        } UPG_UpgradeType;
        要与下一一对应
#endif
#if 1/* zqyuan jyshan */
        /**升级类型定义*/
        typedef enum tagUPDATE_TYPE_E {
                HI_UPDATE_NULL,    /**< 不升级 对应UPGRADE_TYPE_NONE*/
                HI_UPDATE_OTA     ,/**< CABLE 升级 对应UPGRADE_TYPE_APP_FORCE*/
                HI_UPDATE_IP_FORCE,
                HI_UPDATE_USB,
                HI_UPDATE_SERIAL,
                HI_UPDATE_BIOS_FORCE,
                HI_UPDATE_PIC_FORCE,
                HI_UPDATE_APP_AUTO,/*0xA00A*/
                HI_UPDATE_FORCE2,    /* TEST CODE 0x40CA,该情况下升级失败不会重复升级*/
                HI_UPDATE_IP      /**< IP升级 对应UPGRADE_TYPE_IP_AUTO*/
        } HI_UPDATE_TYPE_E;
#else
        /**升级类型定义*/
        typedef enum tagUPDATE_TYPE_E {
                HI_UPDATE_OTA  = 0,/**< CABLE 升级 */
                HI_UPDATE_IP,      /**< IP升级 */
                HI_UPDATE_NULL,    /**< 不升级 */
        } HI_UPDATE_TYPE_E;
#endif

        /**升级时使用下载协议定义*/
        typedef enum tagProto_TYPE_E {
                HI_PROTO_TFTP = 0, /**< TFTP协议下载 */
                HI_PROTO_FTP,      /**< FTP协议下载 */
                HI_PROTO_HTTP,     /**< HTTP协议下载*/

                HI_PROTO_BUTT
        } HI_PROTO_TYPE_E;

        /**IP升级时使用IP地址类型定义*/
        typedef enum tagIP_TYPE_E {
                HI_IP_STATIC = 0,/**< 使用静态IP */
                HI_IP_DHCP,      /**< 使用动态IP */
                HI_IP_BUTT,
        } HI_IP_TYPE_E;

        /** ota升级类型定义,供上层扩展使用.应用按照规范写入(比如1代表强制、2代表可选) */
        typedef enum tagOTA_TYPE_E
        {
                HI_OTA_BUTT,
        } HI_OTA_TYPE_E;


        /**定义升级参数数接口结构体*/
        typedef struct tagLoaderOtaInfo
        {
                /* 应用和loader 间交互 的变量 */
                HI_U32      u32MagicNumber;     /**< Loader DB Magic Number 名称 */
                HI_UPDATE_TYPE_E eUpdateType;   /**< 公用, 升级类型 , 0 :OTA, 1:IP,2:不升级*/
                HI_PROTO_TYPE_E  eProtoType;    /**< 数据下载协议 0:TFTP, 1:FTP, 2 HTTP >*/
                HI_S8       as8UserName[LOADER_USER_NAME_LEN]; /**<FTP下载使用，用户名 >*/
                HI_S8       as8Password[LOADER_USER_NAME_LEN]; /**<FTP下载使用，密码 >*/
                HI_U32      u32NewSoftware;     /**< 新软件版本，NIT表中描述的需要升级的版本号 */
                HI_U32      u32CurSoftware;     /**< 当前软件版本，应用程序自己在APP中定义了宏，升级时需要写入到DB区 */
                HI_U32      u32Hardware;        /**< 公用, 硬件版本号 */
                HI_U32      u32Loaderversion;

                HI_OTA_TYPE_E eOTAType;         /**< 升级标志，应用按照规范写入(比如1代表强制、2代表可选)*/
                HI_U32      u32OtaPid;          /**< 升级数据流的TS PID  这个参数据非常重要,一定要正确.*/
                HI_U32      u32OtaFreq;         /**< 升级数据流的频点,单位为KHz,例如403000 */
                HI_U32      u32OtaSymbRate;     /**< 升级数据流的符号率, 单位为Kbps, 例如6875 */
                HI_U32      u32OtaModulation;   /**< ota loader使用, 升级数据流的星座数 0:16QM 1:32QAM 2:64QAM 3:128QAM 4:256QAM */

                HI_IP_TYPE_E eIpType;           /**< ip  loader使用, ip获取类型*/
                HI_U8       u8EthAddr[6];       /**< ip  loader使用, mac地址*/
                HI_U8       Reserved1[2];

                /*以下ip地址只有使用静态ip时需要配置*/
                HI_IPAddr   ipOurIp;            /**< ip  loader使用, 本机ip*/
                HI_IPAddr   ipGateway;          /**< ip  loader使用, 网关*/
                HI_IPAddr   ipSubnetMask;       /**< ip  loader使用, 子网掩码*/
                HI_IPAddr   ipServer;           /**< ip  loader使用, 服务器ip*/
                HI_IPPort   ipServerPort;       /**< ip  loader使用, 服务器port*/
                HI_U8       Reserved2[2];
                HI_S8       as8FileName[LOADER_FILE_NAME_LEN]; /**<IP ip  loader使用, 升级文件名*/
                HI_S32      u32FileSize;                       /**<IP ip  loader使用, 升级文件大小 */

                HI_U8       au8AppUse[20];      /**< 上层应用私有 */

                HI_UPDATE_TYPE_E eLastUpdType;  /**< 私有 */
                HI_U32      u32FailedCnt;       /**< 升级失败次数,用户无需关心.*/
                HI_U32      u32DestroyFlag;     /**< 用户无需关心.*/
                HI_U8       au8LoaderReserved[8];  /**<  私有 */
                HI_U32      u32Crc;                  /**< crc 校验值 */
        } HI_LOADER_OTA_INFO_S;

#ifdef HI_SD_LOADER   /** 只有标清版本时才启用HI_LOADER_DB_S,在高清平台上不支持,相关的接口已移到FastPlay模块.*/

        /**视频设置宽高比定义*/
        typedef enum hiUNF_ASPECT_RATIO_E
        {
                HI_UNF_ASPECT_RATIO_UNKNOWN,
                HI_UNF_ASPECT_RATIO_4TO3,
                HI_UNF_ASPECT_RATIO_16TO9,
                HI_UNF_ASPECT_RATIO_SQUARE,
                HI_UNF_ASPECT_RATIO_14TO9,
                HI_UNF_ASPECT_RATIO_221TO1,

                HI_UNF_ASPECT_RATIO_BUTT
        } HI_UNF_ASPECT_RATIO_E;

        /** Video aspect mode */
        typedef enum hiUNF_ASPECT_CVRS_E
        {
                HI_UNF_ASPECT_CVRS_IGNORE = 0x0,
                HI_UNF_ASPECT_CVRS_LETTERBOX,
                HI_UNF_ASPECT_CVRS_PANANDSCAN,
                HI_UNF_ASPECT_CVRS_COMBINED,
                HI_UNF_ASPECT_CONVERSION_MODE_BUTT
        } HI_UNF_ASPECT_CVRS_E;

        /**视频制式设置*/
        typedef enum hiUNF_ENC_FMT_E
        {
                HI_UNF_ENC_FMT_UNKNOWN = 0,
                HI_UNF_ENC_FMT_PAL,         /**< B D G H I PAL */
                HI_UNF_ENC_FMT_PAL_N,       /**< (N)PAL        */
                HI_UNF_ENC_FMT_PAL_Nc,      /**< (Nc)PAL       */
                HI_UNF_ENC_FMT_SECAM_SIN,
                HI_UNF_ENC_FMT_SECAM_COS,
                HI_UNF_ENC_FMT_NTSC,        /**< (M)NTSC       */
                HI_UNF_ENC_FMT_NTSC_J,      /**< NTSC-J        */
                HI_UNF_ENC_FMT_NTSC_PAL_M,  /**< (M)PAL        */
                HI_UNF_ENC_FMT_AUTO,        /**< 仅用于输入端自适应，对输出端无效 */
                HI_UNF_ENC_FMT_BUTT
        } HI_UNF_ENC_FMT_E;


        /********************************DISPLAY STRUCT********************************/
#define MAX_DAC_NUM (4)

        /**DAC输出设置*/
        typedef enum hiUNF_OUTPUT_DAC_MODE_E
        {
                HI_UNF_DAC_MODE_SILENCE = 0,
                HI_UNF_DAC_MODE_CVBS,
                HI_UNF_DAC_MODE_Y,
                HI_UNF_DAC_MODE_PB,
                HI_UNF_DAC_MODE_PR,
                HI_UNF_DAC_MODE_R,
                HI_UNF_DAC_MODE_G,
                HI_UNF_DAC_MODE_B,
                HI_UNF_DAC_MODE_SVIDEO_Y,
                HI_UNF_DAC_MODE_SVIDEO_C,
                HI_UNF_DAC_MODE_BUTT
        } HI_UNF_OUTPUT_DAC_MODE_E;

        /**输出设置*/
        typedef struct  hiUNF_OUTPUT_INTERFACE_S
        {
                HI_BOOL                          bScartEnable;
                HI_UNF_OUTPUT_DAC_MODE_E         enDacMode[MAX_DAC_NUM];
        } HI_UNF_OUTPUT_INTERFACE_S ;


        /** 视频属性 */
        typedef struct hiSYSCFG_VIDEO_ATTR_S
        {
                HI_S8                     s8VideoTrans;      /**< 视频层透明度 */
                HI_UNF_ASPECT_RATIO_E     enAspectRatio ;    /**< 屏幕宽高比 */
                HI_UNF_ASPECT_CVRS_E      enScreenMode ;     /**< 屏幕模式 */
                HI_UNF_ENC_FMT_E          enTV_Mode ;        /**< 电视制式 */
                HI_UNF_OUTPUT_INTERFACE_S stVO_Mode ;        /**< 视频信号输出方式 */
        } HI_SYSCFG_VIDEO_ATTR_S, *HI_SYSCFG_VIDEO_ATTR_S_PTR;

        /** MCE参数 */
        typedef struct hiSYSCFG_MCE_S
        {
                HI_U32 u32MceFreq;         /**< MCE节目流的频点 */
                HI_U32 u32MceSymbRate;   /**< MCE节目流的符号率 */
                HI_U32 u32MceModulation; /**< MCE节目流的调制参数 */
                HI_U16 u16MceVideoPid;   /**< MCE节目流的视频PID */
                HI_U16 u16MceAudioPid;   /**< MCE节目流的音频PID */
                HI_U32 u32Volume;        /**< 保留-MCE节目流的音频 */
        } HI_SYSCFG_MCE_INFO_S;

        /** ca类型 */
        typedef enum hiSYSCFG_CA_TYPE_E
        {
                HI_CA_TYPE_NONE = 0,
                HI_CA_TYPE_TF,       /**< 同方 */
                HI_CA_TYPE_DVT,      /**< 数码视讯 */
                HI_CA_TYPE_IRDETO,  /**< 爱迪德 */
                HI_CA_TYPE_BUTT
        } HI_SYSCFG_CA_TYPE_E;

        /** Loader DB区的数据结构 */
        typedef struct hiLoader_DB_S
        {
                HI_U32 u32MagicNumber;                      /**< Loader DB区的魔数 */
                HI_SYSCFG_MCE_INFO_S   stSysMceInfo;        /**< MCE节目流参数区 */
                HI_SYSCFG_VIDEO_ATTR_S stSysVideoInfo;     /**< 视频属性*/
                HI_SYSCFG_CA_TYPE_E eSysCaType;             /**< ca smart card type */
                HI_U32 u32Crc;                              /**< Loader DB区的CRC32值    */
        } HI_LOADER_DB_S;
#else
        typedef struct hiLoader_DB_S
        {
                HI_U32 u32MagicNumber;                      /**< Loader DB区的魔数 */
                HI_U8   aresove[16];
                HI_U32 u32Crc;                              /**< Loader DB区的CRC32值    */
        } HI_LOADER_DB_S;
#endif

#define HI_SYSCFG_STBID_LEN 26   /**< 机顶盒外部序列号 */
#define HI_SYSCFG_STBSN_LEN 15   /**< 机顶盒内部序列号 */

        /** 机顶盒信息 */
        typedef struct hiLOADER_STBINFO_S
        {
                HI_U32 u32OUI;       /**< 厂商id */
                HI_U32 u32AreaCode;  /**< 区域码 */
                HI_U32 u32HWVersion; /**< 硬件版本号 */
                HI_U32 u32HWBatch;   /**< 硬件批次 */
                HI_U8  au8OutSn[HI_SYSCFG_STBID_LEN];   /**< 机顶盒外部序列号 */
#ifdef LOADER_INNER_STB_SN
                HI_U8  au8Sn[HI_SYSCFG_STBSN_LEN];   /**< 机顶盒内部序列号 */
#endif
        } HI_LOADER_STB_INFO_S;

        /**全局LOADER升级参数变量*/
        extern HI_LOADER_OTA_INFO_S g_struLoaderOTAInfo;
        /**全局LOADER DB参数变量*/
        extern HI_LOADER_DB_S       g_stLoaderDbinfo;
        /**全局序列号参数变量*/
        extern HI_LOADER_STB_INFO_S g_stLoaderStbInfo ;

        /** @} */  /** <!-- ==== Structure Definition end ==== */

        /******************************* API declaration *****************************/
        /** \addtogroup      H_1_2 */
        /** @{ */  /** <!-- 【loader升级参数相关接口】 */

        /**
        \brief 从FLASH或E2ROM中获取升级参数数据.
        \attention \n
        升级参数区的地址由顶层编译宏CFG_LOADER_INFOBASIC_ADDR来决定\n
        \param[out] info  loader升级参数,外部分配内存.
        \retval ::HI_SUCCESS 成功
        \retval ::HI_FAILURE  API系统调用失败
        \see ::HI_LOADER_OTA_INFO_S \n
        详细信息,请参考HI_LOADER_OTA_INFO_S定义.
        */
        HI_U32 HI_LOADER_ReadOTAInfo(HI_LOADER_OTA_INFO_S* info) ;

        /**
        \brief 更新升级参数数据到FLASH或E2ROM.
        \attention \n
        升级参数区的地址由顶层编译宏CCFG_LOADER_INFOBASIC_ADDR来决定.\n
        \param[in]  info 要更新的升级参数.
        \retval ::HI_SUCCESS 成功
        \retval ::HI_FAILURE  API系统调用失败
        \see ::HI_LOADER_OTA_INFO_S \n
        详细信息,请参考HI_LOADER_OTA_INFO_S定义.
        */
        HI_U32 HI_LOADER_WriteOTAInfo(HI_LOADER_OTA_INFO_S* info) ;

        /**
        \brief 从FLASH或E2ROM中获取LOADER DB 参数数据.
        \attention \n
        升级参数区的地址由顶层编译宏CCFG_LOADER_INFOBASIC_ADDR来决定.它与OTA升级参数在同一区,从LOADER_OFFESET(0x100)开始\n
        LOADER DB参数主要用于与上层的应用程序进行通讯,目前主要存存放MCE快速开机参数据,视频设置参数等.
        \param[out] pstLoaderDb  loader DB 参数.外部分配内存.
        \retval ::HI_SUCCESS 成功
        \retval ::HI_FAILURE  API系统调用失败
        \see ::HI_LOADER_DB_S \n
        详细信息,请参考HI_LOADER_DB_S定义.
        */
        HI_S32 HI_LOADER_ReadDBInfo(HI_LOADER_DB_S* pstLoaderDb) ;

        /**
        \brief 更新LOADER DB 参数数据到FLASH或E2ROM中.
        \attention \n
        升级参数区的地址由顶层编译宏CFG_LOADER_INFOBASIC_ADDR来决定.它与OTA升级参数在同一区,从LOADER_OFFESET(0x100)开始\n
        LOADER DB参数主要用于与上层的应用程序进行通讯,目前主要存存放MCE快速开机参数据,视频设置参数等.
        \param[in] pstLoaderDb  要更新的loader DB 参数.
        \retval ::HI_SUCCESS 成功
        \retval ::HI_FAILURE  API系统调用失败
        \see ::HI_LOADER_DB_S \n
        详细信息,请参考HI_LOADER_DB_S定义.
        */
        HI_S32 HI_LOADER_WriteDBInfo(HI_LOADER_DB_S* pstLoaderDb) ;

        /**
        \brief 从FLASH或E2ROM中获取机顶盒序列号信息.
        \attention \n
        机顶盒序列号信息区的地址由顶层编译宏CCFG_LOADER_INFOBASIC_ADDR来决定.
        序列号含有升级时需要比较的硬件版本号,厂商编号。不同的运营商和厂家有不同的规格机顶盒的序列号.\n
        序列号的格式组成如下:\n
                      外置序列号如:  15010300101010001c1d000021 \n
                      注意:内置序列号可选. \n
                      序列号格式如下:\n
                格式：AAAA BB CCC DD EE X FFFF FFFF FFFF\n
                  AAAA  四位地区指示码 \n
                      BB        终端产品生产厂商认证编号\n
                      CCC       终端产品机顶盒生产批次\n
                      DD        终端类型\n
                      EE        硬件版本号\n
                      X         识别码\n
                      FFFFFFFFFFFF      根据前一位的定义的具体数值。    MAC 地址 .\n
        \param[out] pstStbinfo  机顶盒序列号信息.外部分配内存.
        \retval ::HI_SUCCESS 成功
        \retval ::HI_FAILURE  API系统调用失败
        \see ::HI_LOADER_STB_INFO_S \n
        详细信息,请参考HI_LOADER_STB_INFO_S定义.
        */
        HI_S32 HI_LOADER_ReadSTBInfo(HI_LOADER_STB_INFO_S* pstStbinfo);

        /**
        \brief 更新FLASH或E2ROM机顶盒序列号信息.
        \attention \n
        机顶盒序列号信息区的地址由顶层编译宏CFG_LOADER_STBINFO_ADDR来决定.\n
        序列号含有升级时需要比较的硬件版本号,厂商编号。\n
        不同的运营商和厂家有不同的规格机顶盒的序列号，\n
        调用此接口后会自动将序列号的最后12位设置成mac地址,\n
        用户可根据实际需要在修改序列号规则.\n
        该接口只理会au8OutSn(机顶盒外部序列号)参数和\n
        au8Sn参数(如果机顶盒内部序列号LOADER_INNER_STB_SN宏定义的话).\n
        序列号的格式组成如下:\n
                      外置序列号如:  15010300101010001c1d000021      \n
                      注意:内置序列号可选.            \n
                      序列号格式如下:\n
                格式：AAAA BB CCC DD EE X FFFF FFFF FFFF\n
                  AAAA  四位地区指示码  \n
                      BB        终端产品生产厂商认证编号 \n
                      CCC       终端产品机顶盒生产批次\n
                      DD        终端类型\n
                      EE        硬件版本号\n
                      X         识别码\n
                      FFFFFFFFFFFF      根据前一位的定义的具体数值。    MAC 地址 .\n
        \param[out] pstStbinfo  机顶盒序列号信息.外部分配内存.\n
        \retval ::HI_SUCCESS 成功
        \retval ::HI_FAILURE  API系统调用失败
        \see ::HI_LOADER_STB_INFO_S \n
        详细信息,请参考HI_LOADER_STB_INFO_S定义.
        */
        HI_S32 HI_LOADER_WriteSTBInfo(HI_LOADER_STB_INFO_S* pstStbinfo);

        /**
        \brief 清除FLASH或E2ROM中的升级标识.
        \attention \n
        升级参数区的地址由顶层编译宏CFG_LOADER_STBINFO_ADDR来决定.\n
        \retval ::HI_SUCCESS 成功
        \retval ::HI_FAILURE  API系统调用失败
        \see ::HI_LOADER_OTA_INFO_S \n
        详细信息,请参考HI_LOADER_OTA_INFO_S定义.
        */
        HI_S32  HI_LOADER_ClearRequest() ;

        /** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}

#endif
#endif

#endif /*__UPGRD_INFO_H__*/
