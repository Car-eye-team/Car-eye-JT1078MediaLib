/*
* Car eye ��������ƽ̨: www.car-eye.cn
* Car eye ��Դ��ַ: https://github.com/Car-eye-team
* CarEyeRtspAPI.h
*
* Author: Wgj
* Date: 2018-03-19 19:11
* Copyright 2018
*
* CarEye RTSP������ӿ�ͷ�ļ�
* ʵʱ��������ʱ��֧�����8��ͨ������
*/

#ifndef __CAREYE_PUSHER_H__
#define __CAREYE_PUSHER_H__

#include "../API/CarEyeTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/*
	* Comments: ʹ����Ч��Key����CarEye 1078 ��������ע���Ա�ʹ��, ʹ�ñ�ϵͳǰ�������ע���������ʹ��
	* Param key: ��Ч����Կ
	* Param packName: ���Androidϵͳ��Ӧ�ó������
	* @Return int CAREYE_NOERROR: �ɹ�, ���ؽ���ο�CarEyeError
	*/
#ifdef ANDROID
	CE_API int CE_APICALL CarEye1078RTP_Register(char* key, char* packName);
#else
	CE_API int CE_APICALL CarEye1078RTP_Register(char* key);
#endif


	/*
	* Comments: ע������״̬�¼�
	* Param event: ��ȡ����״̬�Ļص�����
	* @Return None
	*/
	CE_API void CE_APICALL CarEye1078RTP_RegisterCallback(CarEyePusher_Callback_interface callback);

	/*
	* Comments: ����RTSP����ͨ�� ������ַ�����������������: rtsp://svrip:Port/Name
	* Param svrip: ��ý�������IP��ַ������
	* Param Port: ��ý��������˿ں�
	* Param Name: ������sdp��
	* Param MediaInfo: Ҫ������ý����Ϣ
	* @Return int ���ڵ���0: ����������ͨ���� С��0�����Ųο�CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_StartPusher(char* svrip, unsigned short Port, char* Name, CarEye_MediaInfo MediaInfo, int epool);

	/*
	* Comments: �ر�ָ����RTSP����ͨ��
	* Param channel: ��������RTSP����ͨ����
	* @Return int �Ƿ�ɹ��ر�, ״̬��ο�CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_StopPusher(int channel);

	/*
	* Comments: ��ȡ��ǰͨ�����������Ƿ��Ѿ����ӵ�����������������׼��
	* Param channel: ͨ����
	* @Return int 0δ����׼��, ��0����׼��
	*/
	CE_API int CE_APICALL CarEye1078RTP_PusherIsReady(int channel);

	/*
	* Comments: ����RTSP���������ļ�ͨ�� ������ַ�����������������: rtsp://svrip:Port/Name
	* Param svrip: ��ý�������IP��ַ������
	* Param Port: ��ý��������˿ں�
	* Param Name: ������sdp��
	* Param fileName: Ҫ�����ı����ļ�·�� Ŀǰ��ʱ֧��MP4�ļ�
	* Param startMs: ������ʼ�ĺ�����
	* Param endMs: ���������ĺ����� endMs�������startMs, ��������ʧ��, ������������Ϊ0ʱ����ȫ�ļ�
	* @Return int ���ڵ���0: ����������ͨ���� С��0�����Ųο�CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_StartNativeFile(char* svrip, unsigned short Port, const char* SIM, int channel, char* fileName, int startMs, int endMs, int epool);

	/*
	* Comments: �ر�ָ���ı����ļ�RTSP����ͨ��
	* Param channel: ��������RTSP����ͨ����
	* @Return int �Ƿ�ɹ��ر�, ״̬��ο�CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_StopNativeFile(int channel);

	/*
	* Comments: ������ý�����ݵ�ָ��ͨ����
	* Param channel: Ҫ���͵�ͨ����
	* Param frame: Ҫ���͵�֡����
	* @Return int �Ƿ����ͳɹ�, ״̬��ο�CarEyeError
	*/
	CE_API int CE_APICALL CarEye1078RTP_PushData(int channel, CarEye_AV_Frame* frame);

	//�����ǽ���RTP���Ľӿ�//	


#ifdef __cplusplus
}
#endif

#endif