//--------------------------------------------------------------------------------------
// JCSDK.h
// SDK�ӿڶ���
//--------------------------------------------------------------------------------------

#pragma once

#ifdef __cplusplus
#  define JCSDK_API extern "C" __declspec(dllexport)
#else
#  define JCSDK_API __declspec(dllexport)
#endif

#define JCSDK_CALLTYPE __stdcall

#define JCSDK_INVALID_LINKVALUE -1
typedef int JCLink_t;

#define JCMAX_LINKNUM 512

//�¼�����
enum JCEventType
{
	//���Ӳ���
	JCET_Connected, //δʹ��
	JCET_ConnectOK,	//���ӳɹ�
	JCET_UserAccessError, //�û���֤ʧ��
	JCET_NoChannel,		//����ͨ��δ����
	JCET_ConTypeError,	//�������ʹ���
	JCET_ConCountLimit,	//�����������������
	JCET_ConTimeout,	//���ӳ�ʱ
	JCET_DisconOK, //�Ͽ����ӳɹ�
	JCET_ConAbout, //�����쳣�Ͽ�
	JCET_ServiceStop,	//���ضϿ�����

	//Զ��¼�����
	JCET_GetFileListOK,		//��ȡԶ��¼��ɹ�
	JCET_GetFileListError,	//��ȡԶ��¼��ʧ��

	JCET_RemotePlayBegin,	//Զ�̻طſ�ʼ
	JCET_RemotePlayEnd,		//Զ�̻طŽ���
	JCET_RemoteError,		//Զ�̻ط�ʧ��
	JCET_RemotePlayTimeout,	//Զ�̻طó�ʱ

	JCET_DownloadData,		//¼����������
	JCET_DownloadEnd,		//¼���������
	JCET_DownloadStop,		//¼������ֹͣ
	JCET_DownloadError,		//Զ������ʧ��
	JCET_DownloadTimeout,	//Զ�����س�ʱ

	//����
	JCET_StreamReset,	//���������ź�(�������øı�,��رղ����¿������롢¼���)
	JCET_Alarm,	//�����ź�
};

//����״̬
enum JCLinkStatus
{
	JCLS_UnConnect,	//δ����
	JCLS_Connecting,//������
	JCLS_WaitData,	//���ӳɹ��ȴ�����
	JCLS_Connected,	//������
};

//����֡����
enum JCFrameType
{
	JCFT_I,			//��ƵI֡
	JCFT_P,			//��ƵP֡
	JCFT_B,			//��ƵB֡
	JCFT_Audio,		//��Ƶ֡
};

//¼������
enum JCRecFileType
{
	JCRT_Unknown = 0,//δ֪
	JCRT_SV4,		//sv4�ļ�
	JCRT_SV5,		//sv5�ļ�
	JCRT_SV6,		//sv6�ļ�
	JCRT_MP4,		//MP4�ļ�
};

//�豸����
enum JCDeviceType
{
	JCDT_All = 0,		//δ֪�豸
	JCDT_Card,			//��Ƶ�ɼ���
	JCDT_DVR,			//DVR
	JCDT_IPC,			//IPC
	JCDT_NVR,			//NVR
};

//��������
enum JCCodecID
{
	JCCID_Unknown,		//δ֪����

	//��Ƶ����
	JCCID_JENC04,		//��ά04�����
	JCCID_H264,			//H264����

	//��Ƶ����
	JCCID_PCM,			//PCM����
	JCCID_AMR,			//AMR����
	JCCID_G711A,		//G711����A
	JCCID_G711U,		//G711����U
};

//Զ�̻طÿ�������
enum JCRemotePlayCommand
{
	JCRPC_Play,			//����
	JCRPC_Pause,		//��ͣ
	JCRPC_SPEEDUP,		//����
	JCRPC_SPEEDDOWN,	//����
	JCRPC_SPEEDNORMAL,	//�����ٶ�
};

//����֡
typedef struct _JCStreamFrame
{
	JCFrameType sType;
	PUCHAR pFrameData;
	int nFrameSize;
}
JCStreamFrame, *PJCStreamFrame;

//�����豸��Ϣ
typedef struct _JCLanDeviceInfo
{
	char szCloudSEE[16];
	char szIP[16];
	int nPort;
	char szDeviceName[128];
	int nDeviceType;
	int nChannelNum;
}
JCLanDeviceInfo, *PJCLanDeviceInfo;

//�豸��Ϣ
typedef struct _JCDeviceInfo
{
	JCDeviceType eDevType;
}
JCDeviceInfo, *PJCDeviceInfo;

//������Ϣ
typedef struct _JCStreamInfo
{
	JCCodecID eVideoCodec;		//��Ƶ����
	int nFrameWidth;			//��Ƶ֡���
	int nFrameHeight;			//��Ƶ֡�߶�
	int nVideoFrameRateNum;		//��Ƶ֡�ʷ���
	int nVideoFrameRateDen;		//��Ƶ֡�ʷ�ĸ

	JCCodecID eAudioCodec;		//��Ƶ����
	int nAudioSamples;			//��Ƶ������
	int nAudioSampleBits;		//��Ƶ����λ��
	int nAudioChannels;			//��Ƶͨ����

	JCRecFileType eRecFileType;	//¼���ļ�����
}
JCStreamInfo, *PJCStreamInfo;

//���ڶ�
typedef struct _JCDateBlock
{
	int nBeginYear;		//��ʼ���
	int nBeginMonth;	//��ʼ�·�
	int nBeginDay;		//��ʼ����
	int nEndYear;		//�������
	int nEndMonth;		//�����·�
	int nEndDay;		//��������
}
JCDateBlock, *PJCDateBlock;

//¼����Ϣ
typedef struct _JCRecFileInfo
{
	int nRecFileID;
	JCRecFileType eType;
	char szBeginTime[8];
	char szFilename[16];
	char szPathName[64];
}
JCRecFileInfo, *PJCRecFileInfo;

//yv12����֡
typedef struct _JCRawFrame
{
	DWORD dwWidth;
	DWORD dwHeight;
	PUCHAR pY;
	PUCHAR pU;
	PUCHAR pV;
	DWORD dwYPitch;
	DWORD dwUPitch;
	DWORD dwVPitch;
}
JCRawFrame, *PJCRawFrame;

//�ص�����
typedef void (__cdecl *JCEventCallback_t)(JCLink_t nLinkID, JCEventType etType, DWORD_PTR pData1, DWORD_PTR pData2, LPVOID pUserData);
typedef void (__cdecl *JCDataCallback_t)(JCLink_t nLinkID, PJCStreamFrame pFrame, LPVOID pUserData);
typedef void (__cdecl *JCRawDataCallback_t)(JCLink_t nLinkID, PJCRawFrame pFrame, LPVOID pUserData);
typedef void (__cdecl *JCLanSearchDeviceCallback_t)(PJCLanDeviceInfo pDevice);
typedef void (__cdecl *JCUserDataCallback_t)(JCLink_t nLinkID, PUCHAR pData, int nSize);

//ȫ�ֺ���------------------------------------------------------------------------------
//��ʼ��SDK
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_InitSDK(int nLocStartPort);

//�ͷ�SDK
JCSDK_API void JCSDK_CALLTYPE JCSDK_ReleaseSDK();

//���ûص�����
JCSDK_API void JCSDK_CALLTYPE JCSDK_RegisterCallback(
	JCEventCallback_t funEventCallback,
	JCDataCallback_t funDataCallback,
	JCRawDataCallback_t funRawDataCallback,
	JCLanSearchDeviceCallback_t funLanSearchDeviceCallback);

//����-----------------------------------------------------------------------------------
//����
JCSDK_API JCLink_t JCSDK_CALLTYPE JCSDK_Connect(char *szServer, int nPort, int nChannel,
	char *szNetUser, char *szPwd, BOOL bNumOrIP, LPVOID pUserData);

//�Ͽ�����
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_Disconnect(JCLink_t nLinkID);

//��ȡ�豸��Ϣ
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_GetDeviceInfo(JCLink_t nLinkID, PJCDeviceInfo pDevInfo);

//����Ԥ��-------------------------------------------------------------------------------
//��������Ƶ����(Ĭ��״̬����������Ƶ)
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_EnableVideoData(JCLink_t nLinkID, BOOL bEnable);

//����������
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_EnableDecoder(JCLink_t nLinkID, BOOL bEnable);

//������ƵԤ��
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_SetVideoPreview(JCLink_t nLinkID, HWND hWnd, LPRECT pRect);

//������ƵԤ��
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_SetAudioPreview(JCLink_t nLinkID, HWND hWnd);

//��ȡ������Ϣ
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_GetStreamInfo(JCLink_t nLinkID, PJCStreamInfo pInfo);

//¼����-------------------------------------------------------------------------------
//����¼��
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_StartRec(JCLink_t nLinkID, char *szFilename);

//�ر�¼��
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_StopRec(JCLink_t nLinkID);

//Զ�̲���-------------------------------------------------------------------------------
//Զ��¼�����
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_GetRemoteRecFileList(JCLink_t nLinkID, PJCDateBlock pDate);

//Զ�̻ط�
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_RemotePlay(JCLink_t nLinkID, int nFileID);

//Զ�̻طò��ſ���
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_RemotePlayControl(JCLink_t nLinkID, JCRemotePlayCommand nCmd);

//ˢ�»���(������ͣ״̬��ˢ�´�������øýӿ��ػ�ͼ��)
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_Refresh(JCLink_t nLinkID);

//Զ��¼������
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_DownloadRemoteFile(JCLink_t nLinkID, int nFileID);

//Զ��¼�����
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_RemoteRecording(JCLink_t nLinkID, BOOL bEnable);

//����-----------------------------------------------------------------------------------
//�������豸����
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_LanSeartchDevice(int nDeviceType, DWORD dwTimeout);

//��ͼ
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_SaveBitmap(JCLink_t nLinkID, char *szFilename);

//Զ������(��ֻ֧��IPC),nLanguage:0����,1Ӣ��
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_RemoteConfig(JCLink_t nLinkID, int nLanguage);

JCSDK_API void JCSDK_CALLTYPE JCSDK_yv12_to_rgb32(PUCHAR pDest, DWORD dwDestPitch, PUCHAR pSrcY, PUCHAR pSrcU, PUCHAR pSrcV, 
	DWORD dwSrcYPitch, DWORD dwSrcUPitch, DWORD dwSrcVPitch, DWORD dwWidth, DWORD dwHeight);

//ע���û����ݻص�����
JCSDK_API void JCSDK_CALLTYPE JCSDK_RegisterUserDataCallback(JCUserDataCallback_t funUserDataCallback);

//�����û�����
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_SendUserData(JCLink_t nLinkID, PUCHAR pData, int nSize);

//��ʼԶ������
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_GRPC_Begin(JCLink_t nLinkID);

//����Զ������
JCSDK_API BOOL JCSDK_CALLTYPE JCSDK_GRPC_End(JCLink_t nLinkID);

#include "JGRPC.h"
