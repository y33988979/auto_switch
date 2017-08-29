/******************************************************************************
  Copyright (C), 2004-2050, Hisilicon Tech. Co., Ltd.
******************************************************************************
  File Name     : hi_unf_vo.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/1/22
  Last Modified :
  Description   : header file for audio and video output control
  Function List :
  History       :
  1.Date        :
  Author        : z67193
  Modification  : Created file
******************************************************************************/
/** 
 * \file
 * \brief Describes the information about the SOUND (SND) module. CNcomment:提供SOUND的相关信息
 */
 
#ifndef  __HI_UNF_SND_H__
#define  __HI_UNF_SND_H__

#include "hi_unf_common.h"
//#include "hi_debug.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */


/*************************** Structure Definition ****************************/
/** \addtogroup      SOUND */
/** @{ */  /** <!--  [SOUND] */

/**Defines the ID of the audio output (AO) device.*/
/**CNcomment:定义音频输出设备号*/
typedef enum hiUNF_SND_E
{
    HI_UNF_SND_0,           /**<AO device 0*/ /**<CNcomment:音频输出设备0 */
    HI_UNF_SND_BUTT    
} HI_UNF_SND_E;

/**Defines the type of the AO interface.*/
/**CNcomment:定义音频输出接口类型*/
typedef enum hiUNF_SND_INTERFACE_E
{
    HI_UNF_SND_INTERFACE_I2S,      /**<Inter-IC sound (I2S) mode*/ /**<CNcomment:I2S 模式 */
    HI_UNF_SND_INTERFACE_SPDIF,    /**<Sony/Philips digital interface (SPDIF) mode*/ /**<CNcomment:SPDIF 模式 */
    HI_UNF_SND_INTERFACE_HBR,      /**<SPDIF mode*/ /**<CNcomment:SPDIF 模式 */
    HI_UNF_SND_INTERFACE_BUTT
}HI_UNF_SND_INTERFACE_E;


/**Audio mixing type*/
/**CNcomment:音频混音类型 */
typedef enum hiHI_UNF_SND_MIX_TYPE_E
{
    HI_UNF_SND_MIX_TYPE_MASTER,     /**<Primary audio*/ /**<CNcomment:作为主音 */
    HI_UNF_SND_MIX_TYPE_SLAVE,      /**<Mixing audio*/ /**<CNcomment:作为混音 */
    HI_UNF_SND_MIX_TYPE_BUTT 
} HI_UNF_SND_MIX_TYPE_E;


/**Defines the AO mode.*/
/**CNcomment:定义音频输出模式结构体*/
typedef struct hiUNF_SND_INTERFACE_S
{
    HI_UNF_SND_INTERFACE_E  enInterface;     /**<Output type of the audio interface*/ /**<CNcomment:音频接口输出类型 */
    HI_BOOL                 bEnable;         /**<AO enable*/ /**<CNcomment:是否使能音频输出 */
}HI_UNF_SND_INTERFACE_S;

/**Defines the AO attributes.*/
/**CNcomment:定义音频输出属性结构体*/
typedef struct hiHI_UNF_SND_ATTR_S
{

    HI_U32              u32MasterOutputBufSize; /**<Size (in byte) of the buffer for playing the master audio. Note: The size must be 64 times of word8.*/
                                                /**<CNcomment:主音回放缓冲区空间大小. unit:byte */
    HI_U32              u32SlaveOutputBufSize;  /**<Size (in byte) of the buffer for playing the slave audio. Note: The size must be 64 times of word8 */
                                                /**<CNcomment:辅音回放缓冲区空间大小. unit:byte */
    HI_BOOL            bMixerEngineSupport;   /**< if bMixerEngineSupport == HI_TRUE,  UNF_SND support MixerEngine,slave pcm is repalced by one mixer of the MixerEngine,
    									  if bMixerEngineSupport == HI_FALSE, UNF_SND dont support MixerEngine default: HI_FALSE
    									  */  
} HI_UNF_SND_ATTR_S;

/**Audio Mixer attribute                                               			*/
typedef struct hiHI_UNF_MIXER_ATTR_S
{
    HI_U32              u32MixerWeight;    /**<Mixer weight, ranging from 0 to 100*/ /**<CNcomment:混音权重: 0~100 */
    HI_U32              u32MixerBufSize;   /**<Size (in byte) of the mixer buffer, ranging from (1024 x 16) to (1024 x 1024)*/ /**<CNcomment:混音器缓冲区大小 unit:byte */
} HI_UNF_MIXER_ATTR_S;

typedef struct hiHI_UNF_MIXER_STATUSINFO_S
{
    HI_S32 u32MixerID;   /**<Mixer ID, ranging from 0 to 7*/ /**<CNcomment:混音器硬件ID : 范围0~7 */
    HI_S32 u32Working;   /**<Working status of the mixer. 0 : stop; 1: pause; 2: running*/ /**<CNcomment:混音器工作状态: 0 : stop, 1: pause, 2:running */

    HI_U32 u32BufferSize;      /**<Size (in byte) of the mixer buffer*/ /**<CNcomment:混音器缓冲区大小unit: byte.*/
    HI_U32 u32BufferByteLeft;  /**<Remaining audio data (in byte) in the mixer buffer*/ /**<CNcomment:混音器缓冲区音频数据剩余 unit : byte.*/
    HI_BOOL bDataNotEnough;    /**<HI_FALSE : data is enough, HI_TRUE: data is not enough,need more data */
    HI_U32  u32BufDurationMs;  /**<Duration (in ms) for playing the remaining audio data in the mixer buffer*/ /**<CNcomment:混音器缓冲区剩余音频数据可播放时长  unit : MS.*/

} HI_UNF_MIXER_STATUSINFO_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */


/******************************* API declaration *****************************/
/** \addtogroup      SOUND */
/** @{ */  /** <!--  [SOUND] */

/** 
\brief Initializes an AO device. CNcomment:初始化音频输出设备
\attention \n
Before calling the SND module, you must call this application programming interface (API). CNcomment:调用SND模块要求首先调用该接口
\param N/A
\retval HI_SUCCESS Success CNcomment:成功
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Init(HI_VOID);

/** 
\brief Deinitializes an AO device. CNcomment:去初始化音频输出设备
\attention \n
N/A
\param N/A
\retval HI_SUCCESS Success CNcomment:成功 
\see \n
N/A
*/
HI_S32 HI_UNF_SND_DeInit(HI_VOID);

/** 
\brief Sets an AO device. CNcomment:设置音频输出设备
\attention \n
You must call this API before calling HI_UNF_SND_Open. Otherwise, the VO device is started in the default mode. 
CNcomment:必须在HI_UNF_SND_Open 前调用，否则按照默认方式打开音频设备
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] pstAttr     Configured audio attributes CNcomment:音频设置属性
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetOpenAttr(HI_UNF_SND_E enSound,HI_UNF_SND_ATTR_S *pstAttr);

/** 
\brief Obtains the configured parameters of an AO device. CNcomment:获取音频输出设备设置参数
\attention \n
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[out] pstAttr     Audio attributes CNcomment:音频属性
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetOpenAttr(HI_UNF_SND_E enSound, HI_UNF_SND_ATTR_S *pstAttr);

/** 
\brief Starts an AO device. CNcomment:打开音频输出设备
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\retval ::HI_SUCCESS Success CNcomment:
\retval ::HI_ERR_HIAO_CREATE_FAIL	    The device fails to be started. CNcomment:打开设备失败
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Open(HI_UNF_SND_E enSound);

/** 
\brief Destroys a VO SND instance. CNcomment:销毁音频输出Sound实例
\attention \n
An instance cannot be destroyed repeatedly. CNcomment:不支持重复销毁
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_INVALID_PARA	The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Close(HI_UNF_SND_E enSound);

/** 
\brief Enables an AO port. CNcomment:设置音频输出端口使能控制
\attention \n
The analog I2S output port and SPDIF output port can be controlled separately. CNcomment:可以分别控制模拟I2S输出和SPDIF输出
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] pInterface    Pointer to the AO mode. For details, see the description of ::HI_UNF_SND_INTERFACE_S.
CNcomment:指针类型，音频输出模式结构体，请参见::HI_UNF_SND_INTERFACE_S
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN       No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetInterface(HI_UNF_SND_E enSound, const HI_UNF_SND_INTERFACE_S *pInterface);

/** 
\brief Obtains the enable flag of an AO port. CNcomment:获取音频输出端口使能状态
\attention \n
The enInterface parameter of pInterface is an input parameter, and the bEnable parameter is an output parameter.
CNcomment:第二个参数中结构体的第一个参数（enInterface）为输入参数，第二个参数（bEnable）为输出参数
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in/out] pInterface   Pointer to the AO mode. For details, see the description of ::HI_UNF_SND_INTERFACE_S. 
CNcomment:指针类型。音频输出模式结构体，请参见::HI_UNF_SND_INTERFACE_S
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is disabled. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetInterface(HI_UNF_SND_E enSound, HI_UNF_SND_INTERFACE_S *pInterface);


/** 
\brief Sets the mute status of an analog AO port. CNcomment:音频模拟输出的静音开关设置
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] bMute    AO mute enable. HI_TRUE: mute; HI_FALSE: unmute CNcomment:模拟输出静音开关。HI_TRUE：静音；HI_FALSE：非静音
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN       No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetAnalogMute(HI_UNF_SND_E enSound, HI_BOOL bMute);

/** 
\brief Obtains the mute status of an analog AO port. CNcomment:获取音频模拟输出的静音开关状态
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[out] pbMute    Pointer to the mute status. HI_TRUE: mute; HI_FALSE: unmute CNcomment:指针类型。HI_TRUE：静音；HI_FALSE：非静音
\retval ::HI_SUCCESS Success CNcomment:
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetAnalogMute(HI_UNF_SND_E enSound, HI_BOOL *pbMute);

/** 
\brief Sets the mute status of a digital AO port. CNcomment:音频数字输出的静音开关设置
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] bMute    Digital AO mute enable. HI_TRUE: mute; HI_FALSE: unmute CNcomment:数字输出静音开关。HI_TRUE：静音；HI_FALSE：非静音
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetDigitalMute(HI_UNF_SND_E enSound, HI_BOOL bMute);

/** 
\brief Obtains the mute status of a digital AO port. CNcomment:获取音频数字输出的静音开关状态
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[out] pbMute    Pointer to the mute status. HI_TRUE: mute; HI_FALSE: unmute CNcomment:指针类型。HI_TRUE：静音；HI_FALSE：非静音
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN       No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetDigitalMute(HI_UNF_SND_E enSound, HI_BOOL *pbMute);

/** 
\brief Sets the mute status of the digital and analog AO ports. CNcomment:
\attention \n
N/A
\param[in] enSound CNcomment:音频数字和模拟输出的静音开关设置
\param[in] bMute
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetMute(HI_UNF_SND_E enSound, HI_BOOL bMute);

/** 
\brief Obtains the mute status of the digital and analog AO ports. CNcomment:获取音频数字和模拟输出的静音开关状态
\attention \n
N/A
\param[in] enSound CNcomment:
\param[in] pbMute CNcomment: 
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetMute(HI_UNF_SND_E enSound, HI_BOOL *pbMute);

/** 
\brief Sets the mute status of the DAC for analog audio output. CNcomment:音频模拟输出的DAC静音开关设置
\attention \n
This API is applicable to the scenario where the analog output audio needs to be muted, but the HDMI audio needs to be retained.
CNcomment:用于模拟输出静音而保留HDMI声音输出的场景，一般情况下不需要使用
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] bMute    DAC muteHI_TRUE: mute; HI_FALSE: unmute CNcomment:DAC静音开关。HI_TRUE：静音；HI_FALSE：非静音
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetADACMute(HI_UNF_SND_E enSound, HI_BOOL bMute);

/** 
\brief Obtains the mute status of the DAC for analog audio output. CNcomment:获取音频模拟输出的DAC的静音开关状态
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[out] pbMute  Pointer typeHI_TRUE: mute; HI_FALSE: unmute CNcomment:指针类型。HI_TRUE：静音；HI_FALSE：非静音
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN       No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetADACMute(HI_UNF_SND_E enSound, HI_BOOL *pbMute);

/** 
\brief Sets the output audio data of the SPDIF interface. CNcomment:设置SPDIF 音频数据输出
\attention \n
Before calling this API, ensure that the audio decoding mode is set to :HD_DEC_MODE_SIMUL (PCM+transparent decoding mode).\n
For the SPDIF interface, INTERFACE_SPDIF must be enabled no matter what data is output. 
CNcomment:使用该接口时，音频解码模式必须设定为:HD_DEC_MODE_SIMUL(PCM + 透传解码模式)\n
同时，对于SPDIF接口，不管输出什么数据，必须使能INTERFACE_SPDIF
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] bEnable   Transparent data output enable. HI_TRUE: The transparent data is output; HI_FALSE: The PCM data is output.
 CNcomment:透传数据输出开关。HI_TRUE：输出透传数据；HI_FALSE：输出PCM数据
\retval ::HI_SUCCESS Success CNcomment:成功
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetSpdifPassThrough(HI_UNF_SND_E enSound, HI_BOOL bEnable);

/** 
\brief Sets the pass-through function of the HDMI.
\attention \n
Ensure that the audio decoder works in HD_DEC_MODE_SIMUL mode. CNcomment:使用该接口时，音频解码模式必须设定为:HD_DEC_MODE_SIMUL(PCM + 透传解码模式)
\param[in] enSound CNcomment:音频输出设备号 
\param[in] bEnable , HI_TRUE: pass-through enabled; HI_FALSE: pass-through disabled CNcomment:透传数据输出开关。HI_TRUE：使能HDMI透传输出；HI_FALSE：关闭HDMI透传输出
\retval ::HI_SUCCESS Success CNcomment:成功
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetHdmiPassThrough(HI_UNF_SND_E enSound, HI_BOOL bEnable);

/** 
\brief Sets the output volume value. CNcomment:设置输出音量
\attention \n
If u32Volume is set to a value greater than 100, the value 100 is used by default. CNcomment:如果u32Volume设置大于100，默认设置的值为100
\param[in] enSound        ID of an AO device CNcomment:音频输出设备号
\param[in] u32Volume     Volume value, ranging from 0 to 100. 0: mute; 100: maximum volume CNcomment:设置的音量值，范围0～100。0：静音；100：最大音量
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetVolume(HI_UNF_SND_E enSound, HI_U32 u32Volume);

/** 
\brief Sets the output volume value. CNcomment:设置输出绝对音量
\attention \n
If s32AbsVolume is set to a value greater than 0 dB, the value 0 dB is used by default. CNcomment:如果s32AbsVolume设置大于 0 dB，默认设置的值为0 dB
\param[in] enSound        ID of an AO device CNcomment:音频输出设备号
\param[in] s32AbsVolume     Volume value, ranging from -70dB to 0 dB -70dB: mute; 0 dB: maximum volume CNcomment:设置的音量值，范围-70dB~0dB。-70dB：静音；0dB：最大音量
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetAbsoluteVolume(HI_UNF_SND_E enSound, HI_S32 s32AbsVolume);

/** 
\brief Obtains the output volume value. CNcomment:获取输出绝对音量
\attention \n
The default volume value is 100. CNcomment:查询的默认音量值为0dB
\param[in] enSound         ID of an AO device CNcomment:音频输出设备号
\param[out] ps32AbsVolume    Pointer to the obtained volume value CNcomment:指针类型，获取到的音量值
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetAbsoluteVolume(HI_UNF_SND_E enSound, HI_S32 *ps32AbsVolume);

/** 
\brief Obtains the output volume value. CNcomment:获取输出音量
\attention \n
The default volume value is 100. CNcomment:查询的默认音量值为100
\param[in] enSound         ID of an AO device CNcomment:音频输出设备号
\param[out] pu32Volume    Pointer to the obtained volume value CNcomment:指针类型，获取到的音量值
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetVolume(HI_UNF_SND_E enSound, HI_U32 *pu32Volume);

/** 
\brief Sets the sampling rate during audio output. CNcomment:设置音频输出时的采样率
\attention \n
At present, the sampling rate cannot be set, and it is fixed at 48 kHz. The streams that are not sampled at 48 kHz are resampled at 48 kHz.
CNcomment:目前输出采样率默认为48k(实际输出采样率为48K~192K)，支持从8K到192K码流输入，因最大支持6倍重采样，\n
因此当设定输出采样率为192K时(实际输出采样率为192K)，播小于32K的码流会出错(此时不影响其它采样率的码流切换)\n
然而当设定输出采样率为8K时(实际输出采样率为8K~192K)，此时不能通过HDMI输出小于32K的码流(HDMI不支持)
\param[in] enSound          ID of an AO device CNcomment:音频输出设备号
\param[in] enSampleRate    Audio sampling rate. For details, see the description of ::HI_UNF_SAMPLE_RATE_E. CNcomment:音频采样率。请参见::HI_UNF_SAMPLE_RATE_E
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetSampleRate(HI_UNF_SND_E enSound, HI_UNF_SAMPLE_RATE_E enSampleRate);

/** 
\brief Obtains the sampling rate during audio output. CNcomment:获取音频输出时的采样率
\attention \n
The 48 kHz sampling rate is returned by default. CNcomment:此接口默认返回48kHz采样率
\param[in] enSound           ID of an AO device CNcomment:音频输出设备号
\param[out] penSampleRate   Pointer to the type of the audio sampling rate CNcomment:指针类型，音频采样率的类型
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetSampleRate(HI_UNF_SND_E enSound, HI_UNF_SAMPLE_RATE_E *penSampleRate);

/** 
\brief Enables the AO auto-resampling function. CNcomment:音频输出自动进行重采样开关设置
\attention \n
By default, auto-resampling is enabled and cannot be disabled.\n CNcomment:默认已经打开重采样，不允许关闭
At present, the source sampling rates 8 kHz, 16 kHz, 22.05 kHz, 24 kHz, 32 kHz, 44.1 kHz, and 48 kHz are supported. The default value is 48 kHz.\n
If you call this API to set bAutoResample to HI_TRUE, HI_SUCCESS is returned.\n
If you call this API to set bAutoResample to HI_FALSE, the error code HI_UNF_ERR_SND_NOTSUPPORT is returned.
CNcomment:目前仅支持源采样率为8kHz、16kHz、22.05kHz、24kHz、32kHz、44.1kHz和48kHz，默认以48kHz输出\n
如果通过本接口设置bAutoResample为HI_TRUE，则此接口将直接返回成功\n
如果通过本接口设置bAutoResample为HI_FALSE，则此接口将直接返回HI_UNF_ERR_SND_NOTSUPPORT错误码
\param[in] enSound            ID of an AO device CNcomment:音频输出设备号
\param[in] bAutoResample     Auto-resampling enable. HI_TRUE: enabled; HI_FALSE: disabled CNcomment:是否自动重采样。HI_TRUE：设置自动重采样；HI_FALSE：不设置自动重采样
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetAutoResample(HI_UNF_SND_E enSound, HI_BOOL bAutoResample);

/** 
\brief Obtains the enable status of AO auto-sampling. CNcomment:获取音频输出自动重采样开关状态
\attention \n
N/A
\param[in] enSound              ID of an AO device CNcomment:音频输出设备号
\param[out] pbAutoResample     Pointer to the enable status of auto-sampling CNcomment:指针类型，是否自动重采样
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetAutoResample(HI_UNF_SND_E enSound, HI_BOOL *pbAutoResample);

/** 
\brief Sets the smart volume for audio output. CNcomment:音频输出进行智能音量处理处理开关设置
\attention \n
1. The smart volume is disabled by default.\n 
2. The smart volume is valid only for the master audio.\n 
3. The smart volume is enabled only when the program is switched. 
CNcomment:1. 默认关闭该智能音量\n
2. 智能音量仅对主音有效\n
3. 智能音量仅在切换节目时触发
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] bSmartVolume     Smart volume enableHI_TRUE: enabled; HI_FALSE: disabled CNcomment:是否打开智能音量。HI_TRUE：打开；HI_FALSE：关闭
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetSmartVolume(HI_UNF_SND_E enSound, HI_BOOL bSmartVolume);

/** 
\brief Obtains the status of the smart volume for audio output. CNcomment:获取音频输出智能音量开关状态\attention \n
\attention \n
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[out] pbSmartVolume     Pointer to the enable status of the smart volume CNcomment:指针类型，是否打开智能音量
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetSmartVolume(HI_UNF_SND_E enSound, HI_BOOL *pbSmartVolume);

/** 
\brief Set the AO track mode. CNcomment:设置音频输出声道模式
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] enMode     Audio track mode. For details, see the description of ::HI_UNF_TRACK_MODE_E. CNcomment:音频声道模式，请参见::HI_UNF_TRACK_MODE_E
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetTrackMode(HI_UNF_SND_E enSound, HI_UNF_TRACK_MODE_E enMode);

/** 
\brief Obtains the AO track mode. CNcomment:获取音频输出声道模式
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[out] penMode   Pointer to the AO track mode. For details, see the description of ::HI_UNF_TRACK_MODE_E.
CNcomment:指针类型，音频声道模式。请参见::HI_UNF_TRACK_MODE_E
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	    No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR           The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	    The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetTrackMode(HI_UNF_SND_E enSound, HI_UNF_TRACK_MODE_E *penMode);

/** 
\brief Attaches the SND module to an audio/video player (AVPLAY). CNcomment:绑定音频输出Sound和AV（Audio Video）播放器
\attention \n
Before calling this API, you must create a player and ensure that the player has no output. CNcomment:调用此接口前必须先创建播放器，对应这路播放器没有输出
\param[in] enSound          ID of an AO device CNcomment:音频输出设备号
\param[in] hSource         
\param[in] enMixType       Instance handle of an AVPLAY CNcomment:AV播放器播放实例句柄
\param[in] u32MixWeight    Mixing weight, ranging from 0 to 100. 0: minimum value; 100: maximum value CNcomment:权重，范围为0～100。0：最小值；100：最大值
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	        No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PORT	        The attach type is invalid. CNcomment:无效绑定类型
\retval ::HI_ERR_HIAO_INVALID_PARA	        The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Attach(HI_UNF_SND_E enSound, HI_HANDLE hSource, HI_UNF_SND_MIX_TYPE_E enMixType, HI_U32 u32MixWeight);

/** 
\brief Detaches the SND module from an AVPLAY. CNcomment:解除Sound和AV播放器绑定
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[in] hSource    Instance handle of an AVPLAY CNcomment:AV播放器播放实例句柄
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	        No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	        The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Detach(HI_UNF_SND_E enSound, HI_HANDLE hSource);

/** 
\brief Sets the mixing weight of an audio player. CNcomment:设置音频播放器混音权重
\attention \n
The output volumes of two players are calculated as follows: (volume x weight 1 + volume x weight 2)/100. The formula of calculating the output volumes of multiple players is similar.
CNcomment:两个播放器输出音量的计算方法为：（设置的音量%权重1+设置的音量%权重2）/100，多个播放器的计算方法与此类似
\param[in] enSound              ID of an AO device CNcomment:音频输出设备号
\param[in] hSource    Instance handle of an AVPLAY CNcomment:AV播放器播放实例句柄
\param[in] u32MixWeight    Mixing weight, ranging from 0 to 100. 0: minimum value; 100: maximum value CNcomment:权重，范围为0～100。0：最小值；100：最大值
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	        No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	        The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetMixWeight(HI_UNF_SND_E enSound, HI_HANDLE hSource, HI_U32 u32MixWeight);

/** 
\brief Obtains the mixing weight of an audio player. CNcomment:获取音频播放器混音权重
\attention \n

\param[in] enSound            ID of an AO device CNcomment:音频输出设备号
\param[in] hSource    Instance handle of an AVPLAY CNcomment:AV播放器播放实例句柄
\param[in] pu32MixWeight     Pointer to the mixing weight CNcomment:指针类型，权重值
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	        No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR               The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	        The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetMixWeight(HI_UNF_SND_E enSound, HI_HANDLE hSource, HI_U32 *pu32MixWeight);

/** 
\brief Sets the fade in time and fade out time of an audio player. CNcomment:设置音频播放器淡入淡出时间
\attention \n
\param[in] enSound             ID of an AO device CNcomment:音频输出设备号
\param[in] hSource    Instance handle of an AVPLAY CNcomment:AV播放器播放实例句柄
\param[in] u32FadeinMs         Fade in time (in ms). The maximum value is 2000 ms. CNcomment:淡入时间，单位为毫秒，最大取值2000
\param[in] u32FadeoutMs        Fade out time (in ms). The maximum value is 500 ms. CNcomment:淡出时间，单位为毫秒，最大取值500
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	        No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_INVALID_PARA	        The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetFadeTime(HI_UNF_SND_E enSound, HI_HANDLE hSource, HI_U32 u32FadeinMs, HI_U32 u32FadeoutMs);

/** 
\brief Obtains the fade in time and fade out time of an audio player. CNcomment:获取音频播放器淡入淡出时间
\attention \n

\param[in] enSound           ID of an AO device CNcomment:音频输出设备号
\param[in] hSource    Instance handle of an AVPLAY CNcomment:AV播放器播放实例句柄
\param[in] pu32FadeinMs      Pointer to the fade in time CNcomment:指针类型，淡入时间
\param[in] pu32FadeoutMs     Pointer to the fade out time CNcomment:指针类型，淡出时间
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_HIAO_DEV_NOT_OPEN	        No audio device is started. CNcomment:Audio设备未打开
\retval ::HI_ERR_HIAO_NULL_PTR               The pointer is null. CNcomment:指针参数为空
\retval ::HI_ERR_HIAO_INVALID_PARA	        The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetFadeTime(HI_UNF_SND_E enSound, HI_HANDLE hSource, HI_U32 *pu32FadeinMs, HI_U32 *pu32FadeoutMs);

/** 
\brief Enables a mixer. CNcomment:打开一个混音器
\attention \n
A mixer is available only after HI_UNF_SND_Open is called successfully. CNcomment:只有HI_UNF_SND_Open 成功后，才能操作混音设备
\param[in] enSound     ID of an AO device CNcomment:音频输出设备号
\param[out] phMixer   Pointer to the handle of the created mixer CNcomment:指针类型，创建的混音器 句柄
\param[in] pstMixerAttr    Pointer to mixer attributes CNcomment:指针类型，混音器属性
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_SND_INVALID_ID	The parameter is invalid. CNcomment:无效的参数
\retval ::HI_ERR_SND_INVALID_PARA	The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32   HI_UNF_SND_Mixer_Open(HI_UNF_SND_E enSound,HI_HANDLE *phMixer, HI_UNF_MIXER_ATTR_S *pstMixerAttr);

/** 
\brief Disables a mixer. CNcomment:关闭 一个混音器
\attention \n
N/A
\param[in] hMixer   Mixer handle CNcomment:混音器句柄
\retval ::HI_SUCCESS Success CNcomment:成功
\see \n
N/A
*/
HI_S32   HI_UNF_SND_Mixer_Close(HI_HANDLE hMixer);

/** 
\brief Starts a mixer. CNcomment:启动混音器
\attention \n
N/A
\param[in] hMixer   Mixer handle CNcomment:混音器句柄
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_SND_INVALID_PARA	The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32   HI_UNF_SND_Mixer_Start(HI_HANDLE hMixer);

/** 
\brief Stops a mixer. CNcomment:停止混音器
\attention \n
The data in the buffer will be discarded. CNcomment:缓冲区数据将会丢弃
\param[in] hMixer   Mixer handle CNcomment:混音器句柄
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_SND_INVALID_PARA	The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32   HI_UNF_SND_Mixer_Stop(HI_HANDLE hMixer);

/** 
\brief Pauses a mixer. CNcomment:暂停混音器
\attention \n
The data in the buffer is retained. CNcomment:缓冲区数据仍然保留
\param[in] hMixer   Mixer handle CNcomment:混音器句柄
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_SND_INVALID_PARA	The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32   HI_UNF_SND_Mixer_Pause(HI_HANDLE hMixer);

/** 
\brief  Resets the status of a mixer. CNcomment:混音器状态复位
\attention \n
N/A
\param[in] hMixer   Mixer handle CNcomment:混音器句柄
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_SND_INVALID_PARA	The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32   HI_UNF_SND_Mixer_Flush(HI_HANDLE hMixer);

/** 
\brief Obtains the status of a mixer. CNcomment:获取混音器状态信息
\attention \n
N/A
\param[in] hMixer   Mixer handle CNcomment:混音器句柄
\param[out] pstStatus  Mixer handle CNcomment:混音器句柄
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_SND_NULL_PTR	The parameter is invalid. CNcomment:无效的参数
\retval ::HI_ERR_SND_INVALID_PARA	The parameter is invalid. CNcomment:无效的参数
\see \n
N/A
*/
HI_S32   HI_UNF_SND_Mixer_GetStatus(HI_HANDLE hMixer, HI_UNF_MIXER_STATUSINFO_S *pstStatus);

/** 
\brief  Transmits data to a mixer. CNcomment:送数据到混音器
\attention \n
1. If HI_ERR_HIAO_OUT_BUF_FULL is returned, you need to transmit the data that fails to be transmitted last time to ensure the audio continuity.
2. For the PCM data, the restrictions are as follows:
    s32BitPerSample must be set to 16.
    bInterleaved must be set to HI_TRUE. Only interlaced mode is supported.
    u32Channels can be set to 1 or 2.
    u32PtsMs can be ignored.
    ps32PcmBuffer indicates the PCM data pointer.
    ps32BitsBuffer can be ignored.
    u32PcmSamplesPerFrame indicates the number of audio sampling. The data length (in byte) is calculated as follows: u32PcmSamplesPerFrame x u32Channels x sizeof(HI_u16)
    u32BitsBytesPerFrame can be ignored.
    u32FrameIndex can be ignored.
CNcomment:1 如果返回HI_ERR_HIAO_OUT_BUF_FULL，需要调度者继续送上次失败数据，才能保证声音的连续
2 PCM 数据格式在混音器的限制如下
    s32BitPerSample: 必须为16
    bInterleaved: 必须为HI_TRUE, 仅支持交织模式
    u32Channels: 1 或2
    u32PtsMs: 忽略该参数
    ps32PcmBuffer: PCM 数据指针
    ps32BitsBuffer: 忽略该参数
    u32PcmSamplesPerFrame: 音频样点数, 数据长度(unit:Bytes): u32PcmSamplesPerFrame*u32Channels*sizeof(HI_u16)
    u32BitsBytesPerFrame: 忽略该参数
    u32FrameIndex: 忽略该参数
\param[in] hMixer   Mixer handle CNcomment:混音器句柄
\param[out] pstAOFrame   Information about the audio data CNcomment:音频数据信息
\retval ::HI_SUCCESS Success CNcomment:成功
\retval ::HI_ERR_SND_NULL_PTR	The parameter is invalid. CNcomment:无效的参数
\retval ::HI_ERR_SND_INVALID_PARA	The parameter is invalid. CNcomment:无效的参数
\retval ::HI_ERR_HIAO_OUT_BUF_FULL  Data fails to be transmitted because the mixer buffer is full. CNcomment:混音缓冲区数据满，送数据失败
\see \n
N/A
*/
HI_S32	 HI_UNF_SND_Mixer_SendData(HI_HANDLE hMixer, const HI_UNF_AO_FRAMEINFO_S *pstAOFrame);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif  /*__HI_UNF_SND_H__*/

