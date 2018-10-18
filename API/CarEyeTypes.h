/*
 * Car eye 车辆管理平台: www.car-eye.cn
 * Car eye 开源网址: https://github.com/Car-eye-team
 * CarEyeTypes.h
 *
 * Author: Wgj
 * Date: 2018-04-11 20:56
 * Copyright 2018
 *
 * CarEye 推流器类型定义声明头文件
 */

#ifndef __CAREYE_TYPES_H__
#define __CAREYE_TYPES_H__

#ifdef _WIN32
#define CE_API  __declspec(dllexport)
#define CE_APICALL  __stdcall
#else
#define CE_API
#define CE_APICALL 
#endif

typedef unsigned char BYTE;
typedef unsigned short WORD;

 // 本接口库错误码定义
typedef enum __CarEye_Error__
{
	// 无错误, 成功的
	CAREYE_NOERROR = 0,
	// 不支持的功能, 未实现的
	CAREYE_UNSUPPORTED = -1,
	// 系统初始化失败
	CAREYE_INITFAIL = -2,
	// 无推流通道可申请了
	CAREYE_NOCHANNEL = -3,
	// 创建推流器或其他对象失败
	CAREYE_CREATE_FAIL = -4,
	// 无效的输入参数
	CAREYE_INVALID_PARAM = -5,
	// 鉴权错误
	CAREYE_AUTH = -6,
	// 发送失败
	CAREYE_SEND_FAILE = -7,
}CarEyeError;

// 推流器类型定义
typedef enum __PUSHER_TYPE__
{
	// 直接推送RTSP数据流的推送器
	PUSHER_RTSP = 0,
	// 推送本地文件RTSP流的推送器
	PUSHER_NATIVEFILE_RTSP,
	// 推送RTMP数据流的推送器
	PUSHER_RTMP,
	// 推送本地文件RTMP流的推送器
	PUSHER_NATIVEFILE_RTMP,
}CarEyePusherType;

//按照JT1078 协议重新定义音视频编码

// 视频编码类型定义
typedef enum __VIDEO_CODE_TYPE__
{
	// H264编码
	CAREYE_VCODE_H264 = 98,
	// H265编码
	CAREYE_VCODE_H265 = 99,
}CarEye_VCodeType;

// 音频编码类型定义
typedef enum __AUDIO_CODE_TYPE__
{
	// AAC编码
	CAREYE_ACODE_AAC = 0x13,
	// G711 Ulaw编码
	CAREYE_ACODE_G711U = 0x6,
	// G711 Alaw编码
	CAREYE_ACODE_G711A = 0x7,
	// G726编码
	CAREYE_ACODE_G726 = 0x9,
}CarEye_ACodeType;

// 要推流的媒体信息结构体
typedef struct __MEDIA_INFO_T
{
	// 视频编码类型
	CarEye_VCodeType VideoCodec;
	// 视频帧率, 一般为25
	unsigned int VideoFps;	
	char SIM[14];
	unsigned int channel; //摄像头逻辑通道
	// 音频编码类型
	CarEye_ACodeType AudioCodec;
	// 音频采样率, 录制人声一般为8000
	unsigned int Samplerate;
	// 音频通道数, 一般选择为1
	unsigned int Channels;
	// 音频采样率, 采样精度
	unsigned int AudioBitsPerSample;


}CarEye_MediaInfo;

// 视频帧类型定义
typedef enum __VIDEO_FRAME_TYPE__
{
	// I帧
	VIDEO_FRAME_I = 0x01,
	// P帧
	VIDEO_FRAME_P = 0x02,
	// B帧
	VIDEO_FRAME_B = 0x03,
	// JPEG
	VIDEO_FRAME_J = 0x04,
}CarEyeVideoFrameType;

// 视频帧标识
#define CAREYE_VFRAME_FLAG	0x00000001
// 音频帧标识
#define CAREYE_AFRAME_FLAG	0x00000002

// 媒体帧信息结构定义
typedef struct __CAREYE_AV_Frame_T
{
	// 帧类型标识 CAREYE_VFRAME_FLAG或者CAREYE_AFRAME_FLAG
	unsigned int	FrameFlag;
	// 帧的数据长度
	unsigned int	FrameLen;
	// 视频帧类型, 参考CarEyeVideoFrameType定义
	unsigned int	VFrameType;
	// 数据缓冲区
	unsigned char	*Buffer;
	// 时间戳总秒数
	unsigned int	Second;
	// 时间戳秒数无法精确的微秒数, 非总微秒数, 与Second结合形成精确时间
	unsigned int	USecond;
	unsigned short  LastIFrameInterval;
	unsigned short  LastFrameInterval;

}CarEye_AV_Frame;

// 推流器状态定义
typedef enum __CAREYE_STATE_TYPE__
{
	// 正在连接服务器中
	CAREYE_STATE_CONNECTING = 1,
	// 已成功连接到服务器
	CAREYE_STATE_CONNECTED = 2,
	// 服务器连接失败
	CAREYE_STATE_CONNECT_FAILED = 3,
	// 推流异常中断, 此时应该停止推流或者重新启动推流器了...
	CAREYE_STATE_CONNECT_ABORT = 4,
	// 正在推流中
	CAREYE_STATE_PUSHING = 5,
	// 与服务器断开链接
	CAREYE_STATE_DISCONNECTED = 6,
	// 本地文件推流已完成
	CAREYE_STATE_FILE_FINISHED = 7,
	// 未知错误
	CAREYE_STATE_ERROR = 0xFF,
}CarEyeStateType;

/*
* Comments: 推流器状态变化通知回调函数声明
* Param channel: 推流器的通道号
* Param state: 实时状态
* Param FrameType: 推流器类型
* @Return int
*/
typedef int(*CarEyePusher_StateChanged)(int channel, CarEyeStateType state, CarEyePusherType FrameType);


#endif
