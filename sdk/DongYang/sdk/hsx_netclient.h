#ifndef HSX_NETWORK_CLIENT_H
#define HSX_NETWORK_CLIENT_H

#ifdef WIN32
#include <windows.h>

#if defined(NETCLIENT_EXPORT)
#define DVR_NET_API extern "C" __declspec(dllexport) 
#else
#define DVR_NET_API extern "C" __declspec(dllimport) 
#endif

#else // ifndef win32
#define DVR_NET_API extern "C"

#ifndef DWORD
#define DWORD unsigned int
#endif

#ifndef WORD
#define WORD unsigned short
#endif

#ifndef BYTE
#define BYTE unsigned char
#endif

#ifndef HWND
#define HWND unsigned
#endif

#ifndef HDC
#define HDC unsigned
#endif

#ifndef HANDLE
#define HANDLE unsigned
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef __stdcall
#define __stdcall 
#endif

#ifndef CALLBACK 
#define CALLBACK
#endif

#endif // end of (ifdef win32)

////////////////////////////////////////////////////////////////////////////////
// �궨��
////////////////////////////////////////////////////////////////////////////////

// �������
#define IN
// �������
#define OUT
// �����������
#define INOUT


// �豸���
#define HDEVICE         HANDLE
// ��ѯ���
#define HQUERY          HANDLE
// ������� 
#define HUPGRADE        HANDLE
// ���ؾ��
#define HDOWNLOAD		HANDLE
// ʵʱ�����
#define HLIVE           HANDLE
// ��ʷ�ļ����
#define HPLAYBACK       HANDLE
// �����Խ����
#define HVOICE			HANDLE
// �豸���־��
#define HDISCOVERY		HANDLE


// �豸���Ƴ���
#define MAX_DEVICE_NAME_LEN     (32)
// �豸��ַ��󳤶�
#define	MAX_DEV_ADDR_LEN		(256)
// ����û�������
#define MAX_USERNAME_LEN		(32)
// ������볤��
#define MAX_PASSWORD_LEN		(32)
// ip��ַ����
#define IP_ADDR_LEN             (16)
// mac��ַ����
#define MAC_ADDR_LEN            (18)
// ���������Ϣ����
#define MAX_CFG_INFO_LEN        (20 * 1024)
// ����ļ������ȣ����ļ�·�����ȣ�
#define MAX_FILE_NAME_LEN       (256)	
// �汾��Ϣ����
#define MAX_VERSION_INFO_LEN	(32)

// ÿ̨�豸�����ͨ����
#define MAX_CHANNLE_PER_DEVICE	(32)  

////////////////////////////////////////////////////////////////////////////////
// ö�ٶ���
////////////////////////////////////////////////////////////////////////////////

// �ӿڷ����붨��
typedef enum eNetClientRetCode
{
	eRetSuccess = 0,						// �ɹ�
	eRetFailed,								// ʧ��
	eRetFailVersion,						// �汾��ƥ��
	eRetFailBoardType,						// ���Ͳ�ƥ�䣬�޷�����

	eRetFailSdkNotInit,						// �ͻ���sdkδ��ʼ��
	eRetFailUnsupported,                    // ��֧�ֵĲ���
	eRetFailHasStarted,						// �Ѿ�����
	eRetFailNotStart,						// δ����

	eRetFailInvalidParameter,				// ������Ч
	eRetFailInvalidHandle,					// ���ֵ��Ч
	eRetFailInvalidFile,					// �ļ���Ч
	eRetFailNoResource,						// ��Դ����

	eRetFailUserName,						// �û�������
	eRetFailUserPwd,						// �û��������
	eRetFailIpNotAllowed,					// �������ip��ַ
	eRetFailTooManyLoginedUser,				// ��¼�û�����

	eRetFailNetworkError,					// �������
	eRetFailCmdTimeout,						// ���ʱ
	eRetFailReplyError,						// �豸�˻ظ�����
	eRetFailDisconnect,						// ���ӶϿ�
	
	eRetFailDecodeShow,						// ������ʾʧ��
	eRetFailAudioCapture,					// ��Ƶ����ʧ��
	eRetFailVoicePlay,						// ��������ʧ��
	eRetFailNotFind,						// δ�ҵ�

	eRetFailNoRight = 1000,					// û��Ȩ��
	eRetFailChannelDisabled,				// ͨ��������
	eRetFailSameIPLoginLimit,				// ͬһip��ַ��½��������

}eNetClientRetCode;


// �豸��־��ѯ��ʽ 
typedef enum eLogQueryMode
{
	eLogQueryModeBegin,
	eLogQueryModeByTime			= 0x01,
	eLogQueryModeByType			= 0x02,
	eLogQueryModeByTimeAndType	= 0x04,
	eLogQueryModeAll			= 0xFFFFFFFF,
}eLogQueryMode;

// ��־��ѯ������
typedef enum eLogQueryMainType
{
	eLogMainBegin, 
	eLogMainOperation	= 0x01,
	eLogMainException	= 0x02,
	eLogMainAlarm		= 0x04,
	eLogMainAll			= 0xFFFFFFFF
}eLogQueryMainType;

// ��־��ѯ������
typedef enum eLogQuerySubType
{
	eLogOptBegin				= 100,
	eLogOptPowerOn,						// ����
	eLogOptLogout,						// ע��
	eLogOptLogin,						// ��¼
	eLogOptFormatDisk,					// ��ʽ��Ӳ��
	eLogOptClearAlarm,					// �������
	eLogOptBackup,						// �����ļ�
	eLogOptUpdate,						// ����
	eLogOptCommandConfig,				// һ������
	eLogOptResolutionConfig,			// �ֱ��ʵ���
	eLogOptStandardConfig,				// ��Ƶ��ʽ����
	eLogOptPollingConfig,				// ������Ѳ
	eLogOptScreenConfig,				// ��Ļ����
	eLogOptAudioMute,					// ���þ���
	eLogOptAudioVolumn,					// ��������
	eLogOptFactoryConfig,				// �ָ�Ĭ������
	eLogOptUserInfoConfig,				// �û���Ϣ����
	eLogOptSystemTimeConfig,			// ϵͳʱ������
	eLogOptAudioOutConfig,				// ������
	eLogOptStartRecord,					// ����¼��
	eLogOptStopRecord,					// ֹͣ¼��
	eLogOptCameraNameConfig,			// �޸����������
	eLogOptRecordConfig,				// �޸�¼�����
	eLogOptColorConfig,					// ��ɫ����
	eLogOptMotionConfig,				// �����ƶ����
	eLogOptMosaicConfig,				// ����������
	eLogOptVideoLostConfig,				// ��Ƶ��ʧ����
	eLogOptPTZConfig,					// ��̨����
	eLogOptAlarmConfig,					// ��������
	eLogOptNetworkConfig,				// ��������
	eLogOptDiskConfig,					// Ӳ������
	eLogOptMacConfig,                   // �����ַ(MAC)����
	eLogOptNtpConfig,					// NTP����
	eLogOptPwdReset,					// ���븴λ
	eLogOptCoverConfig,					// �ڵ��������
	eLogOptEnd,

	eLogAlarmBegin				= 200,
	eLogAlarmMotionStart,				// �ƶ���ⱨ����ʼ
	eLogAlarmMotionStop,				// �ƶ���ⱨ������
	eLogAlarmVideoLost,					// ��Ƶ��ʧ
	eLogAlarmVideoOk,					// ��Ƶ�ָ�	
	eLogAlarmAlarmInTriggered,			// ������������
	eLogAlarmAlarmOutTriggered,			// �����������
	eLogAlarmCoverStart,				// �ڵ��¼���ʼ
	eLogAlarmCoverStop,					// �ڵ��¼�����
	eLogAlarmEnd,

	eLogExceptionBegin			= 300,
	eLogExceptionHDFull,				// Ӳ����
	eLogExceptionHDError,				// Ӳ�̴���
	eLogExceptionNetBroken,				// �����쳣
	eLogExceptionNoHDD,					// ��Ӳ��
	eLogExceptionHDFS,					// Ӳ�̵��ļ�ϵͳ�쳣
	eLogExceptionHDWritting,			// дӲ���쳣
	eLogExceptionHDAllError,			// ����Ӳ�̶�����
	eLogExceptionHDFSOverflow,			// Ӳ����Դй©
	eLogExceptionEnd,

	eLogSubAll					= 0xFFFFFFFF

}eLogQuerySubType;


// �طſ����� 
typedef enum ePlaybackCtrlCode
{
	ePlaybackPause		= 1,			// ��ͣ����
	ePlaybackResume,					// �ָ����� 
	ePlaybackFast,						// ���
	ePlaybackSlow,						// ���� 
	ePlaybackNormalSpeed,				// �����ٶ�
	ePlaybackSingle,					// ��֡��
	ePlaybackOpenSound,					// ������
	ePlaybackCloseSound,				// �ر�����
	ePlaybackSetVolumn,					// ��������
	ePlaybackSeek,						// �ط���ת	
	ePlaybackGetCurPlayTime,			// ��ȡ��ǰ����ʱ��
	ePlaybackKeepImgAspectRatio,		// �����Ƿ�ͼ��������ţ������洰�ڽ�������
	ePlaybackCaptureBmp,				// ץͼ
	ePlaybackSetVSync,					// �����Ƿ�����ֱͬ��
}ePlaybackCtrlCode;

// ʵʱ��������
typedef enum eLiveStreamCtrlCode
{
	eLiveForceIFrame = 1,			// ǿ��I֡
	eLiveSetVolumn,					// ��������
	eLiveOpenSound,					// ����������Ӱ��ص�����
	eLiveCloseSound,				// ֹͣ��������Ӱ��ص�����
	eLiveNotShowImage,				// ��������ʾͼ��
	eLiveResumeShowImage,			// �ָ�������ʾ����ͨ������ָ����ʾ����
	eLiveKeepImgAspectRatio,		// �����Ƿ�ͼ��������ţ������洰�ڽ�������
	eLiveCaptureBmp,				// ץͼ
	eLiveSetVSync,					// �����Ƿ�����ֱͬ��
	eLiveSetConnectMode,			// ����Ԥ�����ӷ�ʽ��������/������/�Զ�ѡ��
}eLiveCtrlCode;

// �¼�������
typedef enum eEventMainType
{
	eEventTypeAlarm			= 0x101,	// �����¼�
	eEventTypeVLost			= 0x201,	// ��Ƶ��ʧ�¼�
	eEventTypeMotion		= 0x301,	// �ƶ�����¼�
	eEventTypeHDD			= 0x701,	// Ӳ���¼�
	eEventTypeSystem		= 0x1001,	// ϵͳ�¼�
	eEventNetDisconnect		= 0x10001,	// ���ӶϿ�
	eEventNetReconnect		= 0x11001,	// �����ɹ�
}eEventMainType;

// �����¼�������
typedef enum eEventSubTypeAlarm
{
	eEventSubAlarmInvalid = -1,
	eEventSubAlarmDisappear = 0,
	eEventSubAlarmArise,	
}eEventSubTypeAlarm;

// �ƶ�����¼�������
typedef enum eEventSubTypeMotion
{
	eEventSubMotionInvalid = -1,
	eEventSubMotionDisappear = 0,
	eEventSubMotionArise,
}eEventSubTypeMotion;

// ��Ƶ��ʧ�¼�������
typedef enum eEventSubTypeVLost
{
	eEventSubVLostInvalid = -1,
	eEventSubVLostDisappear = 0,
	eEventSubVLostArise,
}eEventSubTypeVLost;

// Ӳ���¼�������
typedef enum eEventSubTypeHDD
{
	eEventSubHDDInvalid = -1,
	eEventSubHDDNormal = 0,	
	eEventSubHDDFormatting,
	eEventSubHDDNeedFormat,
	eEventSubHDDFS_RO,
	eEventSubHDDEnd,
};

// ϵͳ�¼�������
typedef enum eEventSubTypeSystem
{
	eEventSubSystemInvalid = -1,
	eEventSubSystemStandardChange = 0,		// ��Ƶ��ʽ�ı� ��Ԥ����
	eEventSubSystemChannelModeChange,		// ͨ��ģʽ�ı�
};


// �豸������
typedef enum eDeviceCtrlCode
{
	eDevReboot = 1,           // ����
	eDevResumeDefaultCfg,     // �ָ�Ĭ������
	eDevDiskFormat,           // Ӳ�̸�ʽ��
	eDevReserved = 100,		  // Ԥ��
	
}eDeviceCtrlCode;

// ¼������
typedef enum
{
	RECORD_TYPE_NONE	 = 0,						// �Ƿ�¼������,����¼��
	RECORD_TYPE_TIME	 = 0x01 << 0,				// ʱ��¼��
	RECORD_TYPE_MOTION	 = 0x01 << 1,				// �ƶ����¼��
	RECORD_TYPE_ALARM	 = 0x01 << 2,				// ��������¼��
	RECORD_TYPE_MANUAL	 = 0x01 << 3,				// �ֶ�¼��
	RECORD_TYPE_COVER	 = 0x01 << 4,				// �ڵ�¼��
	RECORD_TYPE_EVENT	 = 6,						// �¼�¼�񣨰����ƶ����¼�񡢱���¼����ڵ�¼��
	RECORD_TYPE_ALL		 = 0xFFFFFFFF,
}record_type_e;


// ptz������
typedef enum
{
	PTZ_ACTION_BEGIN,
	PTZ_DIRECTION,				// �������
	PTZ_ZOOM,					// ����
	PTZ_FOCUS,					// ����
	PTZ_IRIS,					// ����
	PTZ_PRESET,					// Ԥ�õ�
	PTZ_TRACK,					// �켣
	PTZ_CRUISE,					// Ѳ��
	PTZ_ACTION_END,
}ptz_action_e;

// �������
typedef enum
{
	PTZ_DIRCTION_UP,
	PTZ_DIRCTION_DOWN,
	PTZ_DIRCTION_LEFT,
	PTZ_DIRCTION_RIGHT,
	PTZ_DIRCTION_LEFT_UP,
	PTZ_DIRCTION_LEFT_DOWN,
	PTZ_DIRCTION_RIGHT_UP,
	PTZ_DIRCTION_RIGHT_DOWN,
	PTZ_DIRCTION_STOP,
}ptz_dirction_ctl_e;

// zoom
typedef enum
{
	PTZ_ZOOM_WIDE,
	PTZ_ZOOM_TELE,
	PTZ_ZOOM_STOP,
}ptz_zoom_ctl_e;

// focus
typedef enum
{
	PTZ_FOCUS_NEAR,
	PTZ_FOCUS_FAR,
	PTZ_FOCUS_STOP,
}ptz_focus_ctl_e;

// iris
typedef enum
{
	PTZ_IRIS_OPEN,
	PTZ_IRIS_CLOSE,
	PTZ_IRIS_STOP,
}ptz_iris_ctl_e;

// preset
typedef enum
{
	PTZ_PRESET_SET,
	PTZ_PRESET_CLR,
	PTZ_PRESET_GOTO,
}ptz_preset_ctl_e;

// track
typedef enum
{
	PTZ_TRACK_START_SET,
	PTZ_TRACK_STOP_SET,
	PTZ_TRACK_RUN,
}ptz_track_ctl_e;

// cruise
typedef enum
{
	PTZ_CRUISE_STOP,			// ֹͣѲ��
	PTZ_CRUISE_START,			// ��ʼѲ��
}ptz_cruise_ctl_e;

// �豸����Э������
typedef enum eDiscoveryType
{
	eDiscoveryProtoPrivate	= 0x01,		// ˽��Э���豸����
	eDiscoveryProtoOnivf	= 0x02,		// onvif�豸����
	eDiscoveryProtoAll		= eDiscoveryProtoPrivate | eDiscoveryProtoOnivf,
}eDiscoveryType;

// ���ֵ����豸����
typedef enum egk_device_type
{
	eDevTypeUnknown,			// δ֪���豸����
	eDevTypeDVR,				// DVR�豸
	eDevTypeIPC,				// IPC�豸
	eDevTypeHVR,				// HVR�豸
	eDevTypeNVR,				// NVR�豸
}gk_device_type;

////////////////////////////////////////////////////////////////////////////////
// �ṹ�嶨��
////////////////////////////////////////////////////////////////////////////////

// ʱ��ṹ
typedef struct tagTimeInfo
{
	WORD wYear;									// ��
	WORD wMonth;								// ��
	WORD wDay;									// ��
	WORD wHour;									// ʱ
	WORD wMinute;								// �� 
	WORD wSecond;								// ��
}TimeInfo, *LPTimeInfo;

// ʵʱ��������Ϣ
typedef struct tagLiveConnect
{
	DWORD dwChannel;							// ��Ӧ�豸ͨ��
	HWND hPlayWnd;								// ��Ƶ��ʾ����, NULL��ʾ�����ղ��ص�Ԥ�����ݣ�����Ҫ������ʾͼ��
	DWORD dwConnectMode;						// ���ӷ�ʽ�� 0--������ 1--������ 2-�Զ�ѡ��
}LiveConnect, *LPLiveConnect;

// ��־�ķ��ؽ�� 
typedef struct tagLogQueryResult
{
    TimeInfo cLogTime;							// ʱ��
    eLogQueryMainType eMainType;				// ������
    eLogQuerySubType eSubType;					// ������
    char acUser[MAX_USERNAME_LEN];				// ����Ա
    DWORD dwRemoteHostAddr;						// Զ��������ַ��Ϊ0ʱ��ʾ���ز�������־�������ʾԶ�̲�������־
    int nChannel;								// ͨ����
}LogQueryResult, *LPLogQueryResult;

// ¼���ļ����� 
typedef struct tagRecFileQueryResult
{
	char acFileName[MAX_FILE_NAME_LEN];			// ¼���ļ���
    record_type_e dwFileType;					// ¼���ļ������ͣ��Ͳ���ʱ����һ�� 
	DWORD dwFileSize;							// ¼���ļ��Ĵ�С
	TimeInfo cBeginTime;						// �ļ��Ŀ�ʼʱ��
	TimeInfo cEndTime;							// �ļ��Ľ���ʱ��
}RecFileQueryResult, *LPRecFileQueryResult;

// ptz������Ϣ
typedef struct tagPtzControlInfo
{
	ptz_action_e action;
	long 	control_data1;
	long 	control_data2;
}PtzControlInfo;

// �豸�¼�
typedef struct server_event_s
{
	int channel;								// �����¼���ͨ����
	int event_main;								// �¼������ͣ��μ�eEventMainType�Ķ���
	int event_sub;								// �¼������ͣ��μ��������͵Ķ��壬��eEventSubTypeAlarm
	int data1;					
	int data2;
}server_event_t;


// �豸������Ϣ
typedef struct tagDiscoveryInfo
{
	char uuid[128];
	char ip_address[128];
	int port;
	char device_type;				// �豸����(�ο�����gk_device_type)
	char ipc_type;					// IPC����(�ο�hsx_cfgdefine.h�еĶ���eIPCType)
	char wifi_ipaddr[32];			// wifi����ip��ַ
}DiscoveryInfo;


// ͨ��������Դ��Ϣ
typedef struct tagChannelAttrResInfo
{
	int video_standard;				// ��Ƶ��ʽ���ο�hsx_cfgdefine.h�й���video_stand_eö�����͵Ķ��壩
	DWORD ch_enable_mask;			// ͨ����������
	int resolution[32];				// ��ͨ���ķֱ��ʣ��ο�hsx_cfgdefine.h�й���enc_size_eö�����͵Ķ��壩
}ChannelAttrResInfo;

// ¼������Դ��Ϣ
typedef struct tagRecQualityResInfo
{
	int video_standard;				// ��Ƶ��ʽ���ο�hsx_cfgdefine.h�й���video_stand_eö�����͵Ķ��壩
	DWORD ch_enable_mask;			// ͨ����������
	int resolution[32];				// ��ͨ���ķֱ��ʣ��ο�hsx_cfgdefine.h�й���enc_size_eö�����͵Ķ��壩
	int framerate[32];				// ��ͨ����֡�ʣ�1-30��
	int event_resolution[32];		// ��ͨ���¼�¼��ķֱ���
	int event_framerate[32];		// ��ͨ���¼�¼���֡��
}RecQualityResInfo;

// λ�ñ�����Ϣ
typedef struct tagPosRatioInfo
{
	DWORD numerator;				// ����
	DWORD denominator;				// ��ĸ
}PosRatioInfo;

// ͨ��λ����Ϣ
typedef struct tagChPosInfo
{
	int ch;							// ͨ����, ��0��ʼ
	PosRatioInfo x;					
	PosRatioInfo y;
	PosRatioInfo w;
	PosRatioInfo h;
}ChPosInfo;

// �豸��������
typedef struct tagDeviceScreenDisplay
{
	int nScreenChCnt;							
	ChPosInfo ChPos[MAX_CHANNLE_PER_DEVICE];
}DeviceScreenDisplay;

////////////////////////////////////////////////////////////////////////////////
// �ص���������
////////////////////////////////////////////////////////////////////////////////


// �豸�¼��ص�
typedef int (CALLBACK *CB_DeviceEvent)(IN HDEVICE hDev, server_event_t *pEvent, DWORD dwUserData);

// ʵʱ�����ݻص�
typedef int (CALLBACK *CB_StreamData)(HLIVE hStream, BYTE *pDataBuf, DWORD dwDataLen, DWORD dwUserData);

// ʵʱͼ����ƻص�
typedef void (CALLBACK* CB_DrawFun)(HLIVE hStream, HDC hDC, DWORD dwUserData);

// �豸���ֻص�
typedef int(CALLBACK* CB_Discovery)(HDISCOVERY hDiscovery, DiscoveryInfo *pDiscoveryInfo, int nIsNewDevice, DWORD dwUserData);

#ifndef WIN32
// rgb֡���ݻص�
typedef void (CALLBACK *CB_RGBVideoFrame)(BYTE *pFrame, int nWidth, int nHeight, int nLineBytes, DWORD dwUserData);
#endif

////////////////////////////////////////////////////////////////////////////////
// �ӿڶ���
////////////////////////////////////////////////////////////////////////////////

#ifndef WIN32
#pragma GCC visibility push(default)
#endif

// ��ʼ��
DVR_NET_API int __stdcall Network_ClientInit();

// ����ʼ��
DVR_NET_API int __stdcall Network_ClientUnInit();

// ��ȡ��ǰSDK�İ汾��Ϣ
DVR_NET_API int __stdcall Network_ClientGetVersion(BYTE *pVersionInfo, int nInfoLen);



// ��¼�豸
DVR_NET_API int __stdcall Network_ClientLogin(OUT HDEVICE *pDev, char *pSeverAddr, DWORD dwCmdPort, char *pUserName, char *pPassword);

// �ǳ��豸
DVR_NET_API int __stdcall Network_ClientLogout(HDEVICE hDev);

// �豸����
DVR_NET_API int __stdcall Network_ClientDeviceControl(IN HDEVICE hDev, eDeviceCtrlCode eCtrlCode, DWORD dwParam);

// �����¼��ص�
DVR_NET_API int __stdcall Network_ClientSetEventCB(HDEVICE hDev, CB_DeviceEvent cbfEvent, DWORD dwUserData);

// �ֱ��ʸı�ʱ����Ҫ������Ƶ������ͼ���޷���ʾ
DVR_NET_API int __stdcall Network_ClientRefreshVideo(IN HDEVICE hDev);


// ����ʵʱ��
DVR_NET_API int __stdcall Network_ClientStartLive(HLIVE *pStream, IN HDEVICE hDev, LiveConnect *pClientInfo, CB_StreamData cDatacbf = NULL, DWORD dwUserData = 0);

// ֹͣʵʱ��
DVR_NET_API int __stdcall Network_ClientStopLive(HLIVE hStream);

// ʵʱ������
DVR_NET_API int __stdcall Network_ClientLiveControl(HLIVE hStream, eLiveCtrlCode eCode, void *pParam);

// ����ʵʱ��ͼ����ӻ��ƻص�
DVR_NET_API int __stdcall Network_ClientSetLiveDrawCB(HLIVE hStream, IN HWND hWnd, IN CB_DrawFun cbfDraw, DWORD dwUserData);

// ����ʵʱ�����ݻص�, bMustCBMainStream���ò���ֻ���豸֧�ֶ��������������Ч: true--����ص���������false--ֱ�ӻص�Ԥ������
// bNeedSound, �ص��Ƿ���Ҫ����
DVR_NET_API int __stdcall Network_ClientSetLiveDataCB(HLIVE hStream, CB_StreamData cDatacbf, DWORD dwUserData, bool bMustCBMainStream = false, bool bNeedSound = true);

// Ԥ�����ӷ�ʽΪ������/�Զ�ѡ��ʱ����������ʾ���ڵĴ�С����Ӧѡ��������Ԥ�����ӷ�ʽΪ������ʱ�����øýӿ���Ч
DVR_NET_API int __stdcall Network_ClientSubcodeAdapt(HLIVE hStream, int nWndWidth, int nWndHeight);



// ��ȡһ��������¼�������Щ��
DVR_NET_API int __stdcall Network_ClientGetMonthRecDate(HDEVICE hDev, DWORD dwYear, DWORD dwMonth, DWORD &dwRecDateMask);

// ��ȡĳһ����¼���ʱ��
// �Է���Ϊ��λ����¼��ʱ�䣬����dwBufLen����>=(24 * 60)
DVR_NET_API int __stdcall Network_ClientGetDayRecTime(HDEVICE hDev, TimeInfo *pRecDate, BYTE *pRecTimeBuf, DWORD dwBufLen, DWORD dwChannel);

// �����ط�
DVR_NET_API int __stdcall Network_ClientStartPlayback(OUT HPLAYBACK *pPlayback, HANDLE hDev, DWORD dwChannel, DWORD dwFileType, TimeInfo *pBeginTime, TimeInfo *pEndTime, HWND hWnd);

//  ֹͣ�ط�
DVR_NET_API int __stdcall Network_ClientStopPlayback(IN HPLAYBACK hPlayback);

// �طſ���
DVR_NET_API int __stdcall Network_ClientPlaybackControl(IN HPLAYBACK hPlayback, ePlaybackCtrlCode dwControlCode, void *pParam);



// ��������
DVR_NET_API int __stdcall Network_ClientStartDownload(OUT HDOWNLOAD *pDownload, HANDLE hDev, char *pDevFileName, char *pSavedFileName, TimeInfo *pBeginTime = NULL, TimeInfo *pEndTime = NULL);

// ֹͣ����
DVR_NET_API int __stdcall Network_ClientStopDownload(HDOWNLOAD hDownload);

// ��ȡ����״̬
DVR_NET_API int __stdcall Network_ClientGetDownloadStatus(IN HDOWNLOAD hDownload, DWORD &dwProgress);


// PTZ����
DVR_NET_API int __stdcall Network_ClientPTZControl(HDEVICE hDev, DWORD dwChannle, PtzControlInfo *pControlInfo);

// ͸��ͨ����������, nDataLen <= 2048(�ֽ�)
DVR_NET_API int __stdcall Network_ClientTransparentSend(HDEVICE hDev, DWORD dwBuadRate, BYTE *pDataBuf, int nDataLen);

// ��ȡ�豸����
// ע�⣺�ڻ�������������ķ�Χ��(�μ�MAX_CFG_INFO_LEN)����ͬʱ���û��ȡ�����ͬ������
// ����Ҫ��ȡdvr_channel_cfg�����ͨ������Ϊ�����Ƶ�0101,��m_acCfg�е�����Ϊdvr_channel_cfg1, dvr_channel_cfg3
DVR_NET_API int __stdcall Network_ClientGetDeviceConfig(HDEVICE hDev, DWORD dwCommand, DWORD dwChannelMask, BYTE *pCfgBuf, DWORD dwBufLen);

// �����豸����
DVR_NET_API int __stdcall Network_ClientSetDeviceConfig(HDEVICE hDev, DWORD dwCommand, DWORD dwChannelMask, BYTE *pCfgBuf, DWORD dwCfgLen);



// ��������
DVR_NET_API int __stdcall Network_ClientStartUpgrade(OUT HUPGRADE *pUpgrade, IN HANDLE hDev, const char *pFileName);

// ֹͣ����
DVR_NET_API int __stdcall Network_ClientStopUpgrade(HUPGRADE hUpgrade);

// ��ȡ����״̬
DVR_NET_API int __stdcall Network_ClientGetUpgradeStatus(IN HUPGRADE hUpgrade, OUT DWORD &dwProgress);



// ������־��ѯ
DVR_NET_API int __stdcall Network_ClientStartLogQuery(OUT HQUERY *pLog, HANDLE hDev, eLogQueryMode eQueryMode, DWORD dwChannel, eLogQueryMainType eMainType, eLogQuerySubType eSubType, TimeInfo *pQueryTime);

// ��ȡ��־��ѯ��� dwLogCnt >= 0 && dwLogCnt <= 100
DVR_NET_API int __stdcall Network_ClientGetLogQueryResult(IN HQUERY hLog, INOUT DWORD &dwLogCnt, OUT BYTE *pLogBuf, IN DWORD dwBufLen);

// ֹͣ��־��ѯ
DVR_NET_API int __stdcall Network_ClientStopLogQuery(HQUERY hLog);



// �����ļ���ѯ
DVR_NET_API int __stdcall Network_ClientStartFileQuery(OUT HQUERY *pFileQuery, HANDLE hDev, DWORD dwChannel, DWORD dwFileType, TimeInfo *pBeginTime, TimeInfo *pEndTime);

// ��ȡ�ļ���ѯ��� dwFileCnt >= 0 && dwFileCnt <= 50
DVR_NET_API int __stdcall Network_ClientGetFileQueryResult(IN HQUERY hFileQuery, INOUT DWORD &dwFileCnt, OUT BYTE *pFileBuf, IN DWORD dwBufLen);

// ֹͣ�ļ���ѯ
DVR_NET_API int __stdcall Network_ClientStopFileQuery(HQUERY hFileQuery);



// ���������Խ�
DVR_NET_API int __stdcall Network_ClientStartVoice(OUT HVOICE *pVoice, IN HANDLE hDev, IN HWND hWnd = NULL);

// ֹͣ�����Խ�
DVR_NET_API int __stdcall Network_ClientStopVoice(IN HVOICE hVoice);

// ���������Խ����� bHighOrLow: true--������� false--��������
DVR_NET_API int __stdcall Network_ClientSetVoiceVolumn(IN HVOICE hVoice, bool bHighOrLow);



// �����豸����, nInterval--����̽��������ڣ���λ��ms (nInterval >= 1000)
DVR_NET_API int __stdcall Network_ClientStartDiscovery(OUT HDISCOVERY *pDiscovery, int nInterval, CB_Discovery cbfDiscovery, DWORD dwUserData, eDiscoveryType eType = eDiscoveryProtoAll);

// ֹͣ�豸����
DVR_NET_API int __stdcall Network_ClientStopDiscovery(IN HDISCOVERY hDiscovery);

// ˢ���豸����
DVR_NET_API int __stdcall Network_ClientRefreshDiscovery(IN HDISCOVERY hDiscovery);



// �������ͨ�������������������Ƿ񳬹�ϵͳ���������
// *pExceedCIFCntΪ0��ʾ��ǰ���ÿ������㣬�������0��ʾ��ǰ�������������޷����㣬��������Ϊ*pExceedCIFCnt����λ��CIF, ֡ÿ�룩
DVR_NET_API int __stdcall Network_ClientCheckChAttrResLimit(OUT int *pExceedCIFCnt, HANDLE hDev, IN ChannelAttrResInfo *pResInfo);

// �������¼�����������������Ƿ񳬹�ϵͳ���������
// *pExceedCIFCntΪ0��ʾ��ǰ���ÿ������㣬�������0��ʾ��ǰ�������������޷����㣬��������Ϊ*pExceedCIFCnt����λ��CIF, ֡ÿ�룩
DVR_NET_API int __stdcall Network_ClientCheckRecQualityResLimit(OUT int *pExceedCIFCnt, HANDLE hDev, IN RecQualityResInfo *pResInfo);



#ifndef WIN32
// set live rgb callback
DVR_NET_API int __stdcall Network_ClientSetLiveRgbCB(HLIVE hStream, CB_RGBVideoFrame cbf, DWORD dwUserData);

// set playback rgb callback
DVR_NET_API int __stdcall Network_ClientSetPlaybackRgbCB(HPLAYBACK hPlayback, CB_RGBVideoFrame cbf, DWORD dwUserData);
#endif


// �����豸�˷���ģʽ
DVR_NET_API int __stdcall Network_ClientSetDeviceScreenDisplay(IN HDEVICE hDevice, DeviceScreenDisplay *pScreenDisplay);


#ifndef WIN32
#pragma GCC visibility pop
#endif

#endif // end of HSX_NETWORK_CLIENT_H
