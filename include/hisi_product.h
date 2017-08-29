
#include "hisi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif

        /**升级文件名称最大长度*/
#define LOADER_FILE_NAME_LEN       128
#define HI_SYSCFG_STBID_LEN        26   /**< 机顶盒外部序列号 */
#define HI_SYSCFG_STBSN_LEN        15   /**< 机顶盒内部序列号 */

        /**IP地址定义*/
        typedef HI_U32 HI_IPAddr;
        /**IP端口号定义*/
        typedef HI_U16 HI_IPPort;

        /**升级类型定义*/
        typedef enum tagUPDATE_TYPE_E {
                HI_UPDATE_OTA  = 0,/**< CABLE 升级 */
                HI_UPDATE_IP,      /**< IP升级 */
                HI_UPDATE_NULL,    /**< 不升级 */
        } HI_UPDATE_TYPE_E;

        /** ota升级类型定义,供上层扩展使用.应用按照规范写入(比如1代表强制、2代表可选) */
        typedef enum tagOTA_TYPE_E
        {
                HI_OTA_BUTT,
        } HI_OTA_TYPE_E;

        /**IP升级时使用IP地址类型定义*/
        typedef enum tagIP_TYPE_E {
                HI_IP_STATIC = 0,/**< 使用静态IP */
                HI_IP_DHCP,      /**< 使用动态IP */
                HI_IP_BUTT,
        } HI_IP_TYPE_E;

#if 0
        /**定义升级参数数接口结构体*/
        typedef struct tagLoaderOtaInfo
        {
                /* 应用和loader 间交互 的变量 */
                HI_U32      u32MagicNumber;     /**< Loader DB Magic Number 名称 */
                HI_UPDATE_TYPE_E eUpdateType;   /**< 公用, 升级类型 , 0 :OTA, 1:IP,2:不升级*/
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

                HI_U8       au8AppUse[20];      /**< 上层应用私有 */

                HI_UPDATE_TYPE_E eLastUpdType;  /**< 私有 */
                HI_U32      u32FailedCnt;       /**< 升级失败次数,用户无需关心.*/
                HI_U32      u32DestroyFlag;     /**< 用户无需关心.*/
                HI_U8       au8LoaderReserved[8];  /**<  私有 */
                HI_U32      u32Crc;                  /**< crc 校验值 */
        } HI_LOADER_OTA_INFO_S;
#else
        typedef enum
        {
                OUTPUT_INTERFACE_NONE=0x0,
                OUTPUT_INTERFACE_CVBS2_SVIDEO,           //0x1
                OUTPUT_INTERFACE_CVBS2,                  //0x2
                OUTPUT_INTERFACE_CVBS3,                  //0x3
                OUTPUT_INTERFACE_CVBS4,                  //0x4
                OUTPUT_INTERFACE_CVBS_SVIDEO,            //0x5
                OUTPUT_INTERFACE_CVBS_YUV,               //0x6
                OUTPUT_INTERFACE_CVBS_RGB,               //0x7
                OUTPUT_INTERFACE_SVIDEO_SVIDEO,          //0x8
        } OUTPUT_INTERFACE_E;
        typedef enum
        {
                TV_MODE_AUTO = 0,
                TV_MODE_PAL,
                TV_MODE_PAL_M,//  PAL3.58
                TV_MODE_PAL_N,
                TV_MODE_NTSC358,//NTSC3.58
                TV_MODE_NTSC443,
                TV_MODE_SECAM,
                TV_MODE_480I,//高清输出端
                TV_MODE_480P,
                TV_MODE_576I,//高清输出端
                TV_MODE_576P,
                TV_MODE_720P_50,
                TV_MODE_720P_60,
                TV_MODE_1080I_50,
                TV_MODE_1080I_60,
                TV_MODE_1080P_24,
                TV_MODE_1080P_25,
                TV_MODE_1080P_30,
                TV_MODE_1080P_50,
                TV_MODE_1080P_60,
        } TV_MODE_TYPE;
        typedef enum otaloader_type
        {
                Single_Loader = 0,
                Double_Loader   = 1,
                Sounth_Loader  = 2,
                Irdeto_Loader = 3,
        } Loader_Type;
        /** 软件版本类型定义 */
        typedef struct LDR_SoftwareVersion
        {
                HI_U16  SolutionId;            /**< 软件解决方案标识 */
                HI_U16  MajorVersion;          /**< 主版本号 */
                HI_U16  MinorVersion;          /**< 次版本号 */
        } LDR_SoftwareVersion ;
        typedef struct _mce_db
        {
                HI_U64 u8AdvMinTime;
                HI_U64 u8AdvMaxTime;
                HI_U64 resolve2;
                HI_U64 u16ServiceId;
                HI_U64 u16TsId;
                HI_U64 u32Freq;
                HI_U64 u16SymboRate;
                HI_U64 u16VideoPid;
                HI_U64 u16AudioPid;
                HI_U64 u8ChannelNum;
                HI_U64 u8Qam;
                HI_U64 u8Volume;
        } MCE_DB_S, *PTR_MCE_DB_S;
        /**定义升级参数数接口结构体*/
        typedef struct tagLoaderOtaInfo
        {
                /* 应用和loader 间交互 的变量 */
                HI_U32 u32MagicNumber; /* Loader DB Magic Number 名称 */
                HI_U32 db_len; /* Loader DB 的总长度，从magic_number算起，到u32Crc截止 */
                HI_U32 ota_type; /* 升级类型*/
                OUTPUT_INTERFACE_E enOutputInterface;    /* 视频输出模式*/
                TV_MODE_TYPE enTvModetype;          /* 视频输出制式*/
                TV_MODE_TYPE enHdTvModetype;          /* 视频输出制式*/
                HI_U32 u32LoaderDestroyFlag;         /*LOADER破坏标志*/
                HI_U32 u32FailedCnt; /* 升级失败次数 */
                HI_U32 u32DestroyFlag;  /* 主程损坏标志 */

                HI_U32 enAspectRatio;
                HI_U32 enAspectConversionMode;
                HI_U32 enEncodeFormat;

                Loader_Type loader_type;
                HI_U32 u32OtaPid; /* 升级的pid */
                HI_U32 u32OtaFreq; /* 升级的频点, 单位为10KHz */
                HI_U32 u32OtaSymbRate; /* 符号率 */
                HI_U32 u32OtaModulation; /* 调制模式 */
                HI_U32 u32NewSoftware; /* 被升级的软件版本号 */
                HI_U32 u32CurSoftware; /* 当前软件版本号 */
                HI_U32 u32HardwareVersion; /* 硬件版本号 */

                HI_U32 u32NewMajorSwVersion; /* 新软件主版本 */
                HI_U32 u32NewMinorSwVersion; /* 新软件次版本 */
                HI_U32 u32MajorSwVersion; /* 软件主版本 */
                HI_U32 u32MinorSwVersion; /* 软件次版本 */
                HI_U32 u32MajorHardwareVersion; /* 硬件主版本号 */
                HI_U32 u32MinorHardwareVersion; /* 硬件次版本号 */
                HI_U32 u32Regioncode; /* 区域码 */
                HI_U32 u32HwBatchNo; /*批次 */
                HI_U32 stb_type; /* 运营商公钥 */
                HI_U32 time; /* 升级预估时间 */

#if 1 //TF_LOADER
                HI_U32 u32HardwareSubVersion; /*硬件子版本号*/
                LDR_SoftwareVersion appVersion;  /*同方这边需要的软件版本*/
                LDR_SoftwareVersion ldVersion;  /*同方这边需要的loader版本*/
                LDR_SoftwareVersion lgVersion;
                LDR_SoftwareVersion MCEVersion;
                LDR_SoftwareVersion KerVersion;
                LDR_SoftwareVersion RBVersion;
#endif

                HI_U32 download_data; /* 下载日期 */

                /* AMLOGIC平台Loader要用到的描述 */
                HI_U32 oui_code; /*  厂商ID */
                HI_U32 stb_sn; /* 机顶盒序列号*/
                HI_U32 upgrade_type;  /*  升级类型*/
                HI_U32 manual_upgrade_flag; /* 手动升级标识*/
                HI_U32 table_id; /* 升级的table id */
                HI_U32 u32Reserved6;
                HI_U32 u32Reserved7;
                HI_U32 u32Reserved8;
                MCE_DB_S stMCEDb;
                HI_U8 au8AppUse[24];      /**< 上层应用私有 */
                HI_U32 RESERVED;
                HI_U32 u32Crc;                  /**< crc 校验值 */
        } HI_LOADER_OTA_INFO_S;

#endif

        /** 机顶盒信息 */
        typedef struct hiLOADER_STBINFO_S
        {
                HI_U32 u32OUI;       /**< 厂商id */
                HI_U32 u32AreaCode;  /**< 区域码 */
                HI_U32 u32HWVersion; /**< 硬件版本号 */
                HI_U32 u32HWBatch;   /**< 硬件批次 */
                HI_U8  au8OutSn[HI_SYSCFG_STBID_LEN];   /**< 机顶盒外部序列号 */
                HI_U8  au8Sn[HI_SYSCFG_STBSN_LEN];   /**< 机顶盒内部序列号 */
        } HI_LOADER_STB_INFO_S;

        HI_U32 HI_APP_LOADER_ReadLoaderInfo(HI_LOADER_OTA_INFO_S* info);
        HI_S32 HI_APP_LOADER_WriteLoaderInfo(HI_LOADER_OTA_INFO_S* info);
        HI_S32 HI_APP_LOADER_ReadSTBInfo(HI_LOADER_STB_INFO_S* pstStbinfo);
        HI_S32 HI_APP_LOADER_WriteSTBInfo(HI_LOADER_STB_INFO_S* pstStbinfo);

#ifdef __cplusplus
}
#endif

