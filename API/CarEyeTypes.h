/*
 * Car eye ��������ƽ̨: www.car-eye.cn
 * Car eye ��Դ��ַ: https://github.com/Car-eye-team
 * CarEyeTypes.h
 *
 * Author: Wgj
 * Date: 2018-04-11 20:56
 * Copyright 2018
 *
 * CarEye ���������Ͷ�������ͷ�ļ�
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

 // ���ӿڿ�����붨��
typedef enum __CarEye_Error__
{
	// �޴���, �ɹ���
	CAREYE_NOERROR = 0,
	// ��֧�ֵĹ���, δʵ�ֵ�
	CAREYE_UNSUPPORTED = -1,
	// ϵͳ��ʼ��ʧ��
	CAREYE_INITFAIL = -2,
	// ������ͨ����������
	CAREYE_NOCHANNEL = -3,
	// ��������������������ʧ��
	CAREYE_CREATE_FAIL = -4,
	// ��Ч���������
	CAREYE_INVALID_PARAM = -5,
	// ��Ȩ����
	CAREYE_AUTH = -6,
	// ����ʧ��
	CAREYE_SEND_FAILE = -7,
}CarEyeError;

// ���������Ͷ���
typedef enum __PUSHER_TYPE__
{
	// ֱ������RTSP��������������
	PUSHER_RTSP = 0,
	// ���ͱ����ļ�RTSP����������
	PUSHER_NATIVEFILE_RTSP,
	// ����RTMP��������������
	PUSHER_RTMP,
	// ���ͱ����ļ�RTMP����������
	PUSHER_NATIVEFILE_RTMP,
}CarEyePusherType;

//����JT1078 Э�����¶�������Ƶ����

// ��Ƶ�������Ͷ���
typedef enum __VIDEO_CODE_TYPE__
{
	// H264����
	CAREYE_VCODE_H264 = 98,
	// H265����
	CAREYE_VCODE_H265 = 99,
}CarEye_VCodeType;

// ��Ƶ�������Ͷ���
typedef enum __AUDIO_CODE_TYPE__
{
	// AAC����
	CAREYE_ACODE_AAC = 0x13,
	// G711 Ulaw����
	CAREYE_ACODE_G711U = 7,
	// G711 Alaw����
	CAREYE_ACODE_G711A = 6,
	// G726����
	CAREYE_ACODE_G726 = 8,
}CarEye_ACodeType;

typedef enum __NET_WORK_TYPE__
{
	// AAC����
	CAREYE_SELET=0,
	// G711 Ulaw����
	CAREYE_EPOOL = 1,	
}CarEye_NetWork;



// Ҫ������ý����Ϣ�ṹ��
typedef struct __MEDIA_INFO_T
{
	// ��Ƶ��������
	CarEye_VCodeType VideoCodec;
	// ��Ƶ֡��, һ��Ϊ25
	unsigned int VideoFps;	
	char SIM[14];
	unsigned int channel; //����ͷ�߼�ͨ��
	// ��Ƶ��������
	CarEye_ACodeType AudioCodec;
	// ��Ƶ������, ¼������һ��Ϊ8000
	unsigned int Samplerate;
	// ��Ƶͨ����, һ��ѡ��Ϊ1
	unsigned int Channels;
	// ��Ƶ������, ��������
	unsigned int AudioBitsPerSample;


}CarEye_MediaInfo;

// ��Ƶ֡���Ͷ���
typedef enum __VIDEO_FRAME_TYPE__
{
	// I֡
	VIDEO_FRAME_I = 0x01,
	// P֡
	VIDEO_FRAME_P = 0x02,
	// B֡
	VIDEO_FRAME_B = 0x03,
	// JPEG
	VIDEO_FRAME_J = 0x04,
}CarEyeVideoFrameType;

// ��Ƶ֡��ʶ
#define CAREYE_VFRAME_FLAG	0x00000001
// ��Ƶ֡��ʶ
#define CAREYE_AFRAME_FLAG	0x00000002

// ý��֡��Ϣ�ṹ����
typedef struct __CAREYE_AV_Frame_T
{
	// ֡���ͱ�ʶ CAREYE_VFRAME_FLAG����CAREYE_AFRAME_FLAG
	unsigned int	FrameFlag;
	// ֡�����ݳ���
	unsigned int	FrameLen;
	// ��Ƶ֡����, �ο�CarEyeVideoFrameType����
	unsigned int	VFrameType;
	// ���ݻ�����
	unsigned char	*Buffer;
	// ʱ���������
	unsigned int	Second;
	// ʱ��������޷���ȷ��΢����, ����΢����, ��Second����γɾ�ȷʱ��
	unsigned int	USecond;
	unsigned short  LastIFrameInterval;
	unsigned short  LastFrameInterval;

}CarEye_AV_Frame;

// ������״̬����
typedef enum __CAREYE_STATE_TYPE__
{
	// �������ӷ�������
	CAREYE_STATE_CONNECTING = 1,
	// �ѳɹ����ӵ�������
	CAREYE_STATE_CONNECTED = 2,
	// ����������ʧ��
	CAREYE_STATE_CONNECT_FAILED = 3,
	// �����쳣�ж�, ��ʱӦ��ֹͣ������������������������...
	CAREYE_STATE_CONNECT_ABORT = 4,
	// ����������
	CAREYE_STATE_PUSHING = 5,
	// ��������Ͽ�����
	CAREYE_STATE_DISCONNECTED = 6,
	// �����ļ����������
	CAREYE_STATE_FILE_FINISHED = 7,
	// δ֪����
	CAREYE_STATE_ERROR = 0xFF,
}CarEyeStateType;

/*
* Comments: ������״̬�仯֪ͨ�ص���������
* Param channel: ��������ͨ����
* Param state: ʵʱ״̬
* Param FrameType: ����������
* @Return int
*/
typedef int(*CarEyePusher_Callback_interface)(int channel, CarEyeStateType state, CarEye_AV_Frame* pFrame, CarEyePusherType FrameType);


#endif
