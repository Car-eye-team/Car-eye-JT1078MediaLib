/*
* Car eye 车辆管理平台: www.car-eye.cn
* Car eye 开源网址: https://github.com/Car-eye-team
* CarEyeRtspAPI.h
*
* Author: Wgj
* Date: 2018-03-19 19:11
* Copyright 2018
*
* CarEye RTSP推流库接口头文件
* 实时推送数据时候支持最大8个通道的流
*/

#ifndef __CAREYE_PUSHER_H__
#define __CAREYE_PUSHER_H__

#include "CarEyeTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/*
	* Comments: 使用有效的Key进行CarEye 1078 推流器的注册以便使用, 使用本系统前必须进行注册才能正常使用
	* Param key: 有效的密钥
	* Param packName: 针对Android系统的应用程序包名
	* @Return int CAREYE_NOERROR: 成功, 返回结果参考CarEyeError
	*/
#ifdef ANDROID
	CE_API int CE_APICALL CarEye1078RTP_Register(char* key, char* packName);
#else
	CE_API int CE_APICALL CarEye1078RTP_Register(char* key);
#endif

	/*
	* Comments: 注册推流状态事件
	* Param event: 获取推流状态的回调函数
	* @Return None
	*/
	CE_API void CE_APICALL CarEye1078RTP_RegisterStateChangedEvent(CarEyePusher_StateChanged event);

	/*
	* Comments: 启动RTSP推流通道 推流地址以三个参数进行组合: rtsp://svrip:Port/Name
	* Param svrip: 流媒体服务器IP地址或域名
	* Param Port: 流媒体服务器端口号
	* Param Name: 推流的sdp名
	* Param MediaInfo: 要推流的媒体信息
	* @Return int 大于等于0: 启动的推流通道号 小于0错误编号参考CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_StartPusher(char* svrip, unsigned short Port, char* Name, CarEye_MediaInfo MediaInfo);

	/*
	* Comments: 关闭指定的RTSP推流通道
	* Param channel: 已启动的RTSP推流通道号
	* @Return int 是否成功关闭, 状态码参考CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_StopPusher(int channel);

	/*
	* Comments: 获取当前通道的推流器是否已经连接到服务器并做好推流准备
	* Param channel: 通道号
	* @Return int 0未做好准备, 非0做好准备
	*/
	CE_API int CE_APICALL CarEye1078RTP_PusherIsReady(int channel);

	/*
	* Comments: 启动RTSP推流本地文件通道 推流地址以三个参数进行组合: rtsp://svrip:Port/Name
	* Param svrip: 流媒体服务器IP地址或域名
	* Param Port: 流媒体服务器端口号
	* Param Name: 推流的sdp名
	* Param fileName: 要推流的本地文件路径 目前暂时支持MP4文件
	* Param startMs: 推流起始的毫秒数
	* Param endMs: 推流结束的毫秒数 endMs必须大于startMs, 否则推流失败, 当两个参数都为0时推送全文件
	* @Return int 大于等于0: 启动的推流通道号 小于0错误编号参考CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_StartNativeFile(char* svrip, unsigned short Port, const char* SIM, int channel, char* fileName, int startMs, int endMs);

	/*
	* Comments: 关闭指定的本地文件RTSP推流通道
	* Param channel: 已启动的RTSP推流通道号
	* @Return int 是否成功关闭, 状态码参考CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_StopNativeFile(int channel);

	/*
	* Comments: 推送流媒体数据到指定通道中
	* Param channel: 要推送的通道号
	* Param frame: 要推送的帧数据
	* @Return int 是否推送成功, 状态码参考CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_PushData(int channel, CarEye_AV_Frame* frame);

	//以下是接受RTP包的接口//	


#ifdef __cplusplus
}
#endif

#endif