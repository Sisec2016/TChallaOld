#ifndef _TL_PLAY_H_
#define _TL_PLAY_H_

#include <windows.h>

//������
#define TLPLAY_NO_ERROR				0		//�޴���
#define TLPLAY_PARAM_INVALID		1		//����Ĳ���
#define TLPLAY_MODE_ERR				2		//ģʽ���ô���
#define TLPLAY_FILE_OPENERR			3		//�ļ���ʧ��
#define TLPLAY_FILE_NOVIDEO			4		//�ļ�û����Ƶ
#define TLPLAY_NOT_OPENED			5		//δ��
#define TLPLAY_NOT_PLAYING			6		//δ��ʼplay
#define TLPLAY_DDRAW_INITERR		7		//DDRAW�����ʼ��ʧ��
#define TLPLAY_VIDEODEC_INITERR		8		//��Ƶ��������ʼ��ʧ��
#define TLPLAY_OPENSOUND_ERR		9		//����Ƶʧ��
#define TLPLAY_DECVIDEO_ERR			10		//������Ƶʧ��
#define TLPLAY_DECAUDIO_ERR			11		//������Ƶʧ��
#define TLPLAY_FILE_PLAYOVER		12		//�ļ��ѽ���
#define TLPLAY_CREATEDIR_ERR		13		//����·��ʧ��
#define TLPLAY_CREATEFILE_ERR		14		//�����ļ�ʧ��
#define TLPLAY_NO_ENOUGH_POOL		15		//����ʣ��ռ䲻��
#define TLPLAY_OUTOFMEMORY			16		//ϵͳ�ռ䲻��
#pragma pack( push, 4 )
typedef struct
{
    BYTE     m_byMediaType; //ý������
    BYTE	 reserved[8];		//�����ֶ�
    DWORD    m_dwDataSize;  //ʵ�ʱ������ݴ�С
    BYTE     m_byFrameRate; //����֡��,���ڽ��ն�
	DWORD    m_dwFrameID;   //֡��ʶ�����ڽ��ն�
	DWORD    m_dwTimeStamp; //ʱ���, ���ڽ��ն�
    union
    {
        struct{
			BOOL		m_bKeyFrame;    //Ƶ֡����(I or P)
			WORD		m_wVideoWidth;  //��Ƶ֡��
			WORD		m_wVideoHeight; //��Ƶ֡��
			DWORD       m_wBitRate;
		}m_tVideoParam;
        BYTE    m_byAudioMode;//��Ƶģʽ
    };
}PLAYFRAMEHDR,*LPPLAYFRAMEHDR;

#define  T_AUDIO_8_8K	1 //8K8bit ��Ƶ		
#define  T_AUDIO_16_8K	2 //8K16bit ��Ƶ	
#define  T_VIDEO_YV12	11 //YV12 ͼ��	

typedef struct{ 
    long nWidth;  //�������λ���ء��������Ƶ������Ϊ0�� 
    long nHeight;   //����ߡ��������Ƶ������Ϊ0�� 
    long nStamp;  //ʱ����Ϣ����λ���롣 
    long nType;  //�������ͣ�T_AUDIO_8_8K��T_AUDIO_16_8K��T_VIDEO_YV12������궨��˵���� 
    long nFrameRate;//����ʱ������ͼ��֡�ʡ� 
}DECFRAME_INFO; 
#pragma pack( pop )

#ifdef __cplusplus
extern "C"{
#endif

BOOL __stdcall TLPlay_GetPort(LONG* pnPort);
//����µĲ��ž��

BOOL __stdcall TLPlay_FreePort(LONG nPort);
//�ͷŲ��ž��

DWORD __stdcall TLPlay_GetLastError(LONG nPort);
//��ô�����


DWORD __stdcall TLPlay_GetSdkVersion(); 
// ˵�����õ���ǰ������sdk �İ汾�ź�build �š����ֻ���޸�bug������ֻ����build �š� 
// ����ֵ���� 16 λ��ʾ��ǰ��build �š�9~16 λ��ʾ���汾�ţ�1~8 λ��ʾ�ΰ汾�š��磺����ֵ0x08310001 
// ��ʾ��build ����0831���汾�� 0.1�� 

DWORD __stdcall TLPlay_GetDDrawDeviceTotalNums(); 
// ˵�������ϵͳ����windows ����󶨵��ܵ���ʾ�豸��Ŀ��������Ҫ��ָ�Կ����� 
// ����ֵ��������� 0�����ʾϵͳ��ֻ������ʾ�豸��������� 1�����ʾϵͳ�а�װ�˶���Կ��� 
// ��ֻ��һ���Կ���Windows ����󶨡���������ֵ�����ʾϵͳ��������󶨵��Կ���Ŀ���ڶ��Կ� 
//     ��ϵͳ�п���ͨ��������ʾ���ԣ���ָ������һ���Կ���Ϊ����ʾ�豸�� 

BOOL __stdcall TLPlay_SetDDrawDevice(LONG nPort, DWORD nDeviceNum); 
// ˵�������ò��Ŵ���ʹ�õ��Կ��� 
// ע�⣺�ô��ڱ����ڸ��Կ�����Ӧ�ļ������ϲ�����ʾ���Ż��档 
// ���������nDeviceNum ��ʾ�豸���豸�ţ������0�����ʾʹ������ʾ�豸�� 


enum TLPLAYMODE{TL_PLAY_REALTIME_STREAM, TL_PLAY_POOL_STREAM, TL_PLAY_FILE};
BOOL __stdcall TLPlay_SetPlayMode(LONG nPort, enum TLPLAYMODE mode);
//���ò���ģʽ����Open֮ǰ����
//TL_PLAY_REALTIME_STREAM ʵʱ������ʽ��һ������һ֡���ݡ� ��������
//TL_PLAY_POOL_STREAM ��������ʽ�����������룬ͨ������������
//TL_PLAY_FILE �ļ���ʽ��һ�β���һ���ļ�

BOOL __stdcall TLPlay_OpenFile(LONG nPort, const char* sFileName);
//���ļ� ��������TL_PLAY_FILE��ʽ


#define POOL_BUF_MAX	1024*100000
#define POOL_BUF_MIN	1024*65

BOOL __stdcall TLPlay_OpenStream(LONG nPort, DWORD dwPoolsize);
//������ ��������TL_PLAY_REALTIME_STREAM ���� TL_PLAY_POOL_STREAM��ʽ
// dwPoolsize ȡֵ��Χ POOL_BUF_MIN �� POOL_BUF_MAX
//����TL_PLAY_REALTIME_STREAM ģʽ��dwPoolsize��������

BOOL __stdcall TLPlay_Close(LONG nPort);
//�ر�

typedef void (CALLBACK*  pDecCBFun)(long nPort,unsigned char* pBuf,long nSize,DECFRAME_INFO* pFrameInfo,unsigned int dwContext);

BOOL __stdcall TLPlay_SetDecCallBack(LONG nPort, pDecCBFun DecCBFun, LONG nUser); 
// ˵�������ûص���������ý�������, ��TLPlay_Play֮ǰ���ã� TLPlay_Stopʱ�Ὣ�ص����
// ���������DecCBFun �ص�����ָ�룬����ΪNULL; 
// �ص������еĲ���˵���� 
// nPort ������ͨ���š� 
// pBuf ����������Ƶ���ݡ� 
// nSize ����������Ƶ����pBuf �ĳ��ȣ� 
// pFrameInfo ͼ���������Ϣ��
// nUser �û������� 



BOOL __stdcall TLPlay_Play(LONG nPort, HWND hWnd); 
//���ſ�ʼ��������Ƶ�����С������hWnd ���ڵ�����Ҫȫ����ʾ��ֻҪ��hWnd ���ڷŴ�ȫ���� 
//����Ѿ����ţ�ֻ�Ǹı䵱ǰ�����ٶ�Ϊ�����ٶȡ� 
//���������hWnd    ������Ƶ�Ĵ��ھ����

BOOL __stdcall TLPlay_Stop(LONG nPort);
//ֹͣ����


BOOL __stdcall TLPlay_PlaySound(LONG nPort);
//����Ƶ����
//˵������������ͬһʱ��ֻ����һ·��������������Ѿ��������򿪣����Զ��ر�ԭ���Ѿ��򿪵������� 
//ע�⣺Ĭ������������ǹرյģ�

BOOL __stdcall TLPlay_StopSound();
//ֹͣ��Ƶ����

BOOL __stdcall TLPlay_SetVolume(LONG nPort, WORD nVolume);
//��������  ȡֵ0-0xffff

WORD __stdcall TLPlay_GetVolume(LONG nPort);
//�������  ȡֵ0-0xffff


BOOL __stdcall TLPlay_GetBMP(LONG nPort, char* sBMPFileName); 
// ˵��:  ץȡbmp  ͼ�� 
// ����:  nPort:  ͨ���ţ�sBMPFileName ��ŵ�BMP�ļ���,��·�����������·����ȱʡ��c:\\SnapShotFile��

BOOL __stdcall TLPlay_GetJPG(LONG nPort, char* sJPGFileName, BYTE quality); 
// ˵��:  ץȡjpeg  ͼ�� 
// ����:  nPort: ͨ���ţ�sJPGFileName ��ŵ�JPG�ļ���,��·�����������·����ȱʡ��c:\\SnapShotFile��
// qualityͼ������ 0-100 
typedef void(CALLBACK *pCBDrawFun)(long  nPort, HDC hDc, LONG nUser);
BOOL __stdcall TLPlay_RigisterDrawFun(LONG  nPort, pCBDrawFun drawfun, LONG nUser); 
// ˵����ע��һ���ص���������õ�ǰ�����device context, ����������DC �ϻ�ͼ����д�֣�
//���������DrawFun    �ص���������� 
//          nUser �û����ݣ� 
// �ص�����˵����void CALLBACK DrawFun(long nPort,HDC hDc,LONG nUser)�� 
// 		 nPort ͨ���ţ� 
// 		 hDc �豸DC�� 
//       nUser  �û����ݣ���������������û����ݣ� 


BOOL __stdcall TLPlay_SetColor(LONG nPort, int nBrightness, int nContrast, int nSaturation, int nHue); 
// ˵��������ͼ�����Ƶ��������ʱ�����ã� 
// ��������� 
// nBrightness: ���ȣ�Ĭ�� 64�� ��Χ0-128�� 
// nContrast: �Աȶȣ�Ĭ�� 64�� ��Χ0-128�� 
// nSaturation: ���Ͷȣ�Ĭ�� 64�� ��Χ0-128�� 
// nHue:      ɫ����Ĭ�� 64�� ��Χ0-128�� 
// ע�⣺ ���ȫ��ΪĬ��ֵ����������ɫ���ڣ� 
		   
BOOL __stdcall TLPlay_GetColor(LONG nPort, int *pBrightness, int *pContrast, int *pSaturation, int *pHue); 
// ˵������Ӧ�Ļ����ɫֵ������ͬ�� 

//////////////////////////////////////////////////////////////////////////
//ֻ������TL_PLAY_POOL_STREAMģʽ�ӿ�
//////////////////////////////////////////////////////////////////////////
DWORD __stdcall TLPlay_GetSourceBufferRemain(LONG nPort);
//˵�������������ģʽ��Դ����ʣ�����ݣ� 
//����ֵ����ǰԴ����Ĵ�С��BYTE ����

BOOL __stdcall TLPlay_ResetSourceBuffer(LONG nPort);
//˵�������������ģʽ��Դ������ʣ������ 

DWORD __stdcall TLPlay_GetPlayedTime(LONG nPort); 
//˵�����õ�����ڵ�һ֡�ĵ�ǰ���ŵ�ʱ�������λ����

BOOL __stdcall TLPlay_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight); 
//˵�������������ԭʼͼ��Ĵ�С

//////////////////////////////////////////////////////////////////////////
// ����TL_PLAY_FILE ���� TL_PLAY_POOL_STREAM��ʽ �ӿ�
//////////////////////////////////////////////////////////////////////////

BOOL __stdcall TLPlay_Pause(LONG nPort, BOOL bPause);
//˵����������ͣ/�ָ��� 
//���������bPause=TRUE ��ͣ������ָ��� 

BOOL __stdcall TLPlay_Fast(LONG nPort);
// ˵�������ٲ��ţ�ÿ�ε��ý�ʹ��ǰ�����ٶȼӿ�һ����16�����ޣ�Ҫ�ָ��������ŵ��� 
// TLPlay_Play(),�ӵ�ǰλ�ÿ�ʼ�������ţ� 

BOOL __stdcall TLPlay_Slow(LONG nPort);
// ˵�������ٲ��ţ�ÿ�ε��ý�ʹ��ǰ�����ٶ���һ����1/16�����ޣ�Ҫ�ָ��������ŵ��� TLPlay_Play() 

BOOL __stdcall TLPlay_OneByOne(LONG nPort);
// ˵������֡���š�Ҫ�ָ��������ŵ���TLPlay_Pause(nPort, FALSE); 


//////////////////////////////////////////////////////////////////////////
// ֻ�����ļ�ģʽ (TL_PLAY_FILE) �ӿ�
//////////////////////////////////////////////////////////////////////////

DWORD __stdcall TLPlay_GetFileTime(LONG nPort); 
//˵�����õ��ļ��ܵ�ʱ�䳤�ȣ���λ���룬��֧�ֶ��ļ�������׷�ӣ� 

DWORD __stdcall TLPlay_GetFileTotalFrames(LONG nPort); 
// ˵�����õ��ļ��е���֡���� 
// ����ֵ���ļ��е���֡����  

DWORD  __stdcall TLPlay_GetPlayedFrames(LONG nPort); 
//˵�����õ��Ѿ��������Ƶ֡���� 

BOOL __stdcall TLPlay_SetPlayPos(LONG nPort,float fRelativePos);
// ���ò���λ�ðٷֱ�
// ���������fRelativePos  ��Χ0-100%��

float __stdcall TLPlay_GetPlayPos(LONG nPort);
// ��ȡ����λ�ðٷֱ�
// ����ֵ����Χ0-100% 

BOOL __stdcall TLPlay_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg); 
// ˵���������ļ�����ʱҪ���͵���Ϣ�� 
// ���������hWnd    ��Ϣ���͵Ĵ��ڡ� 
// nMsg �û��Զ�����������Ϣ�������ŵ��ļ�����ʱ�û���hWnd ���ڹ������յ������Ϣ�� 
// ����Ϣ�����е�wParam ��������nPort ��ֵ�� 

//////////////////////////////////////////////////////////////////////////
// ��������ģʽ (TL_PLAY_REALTIME_STREAM ���� TL_PLAY_POOL_STREAM��ʽ) �ӿ�
//////////////////////////////////////////////////////////////////////////

BOOL __stdcall TLPlay_InputVideoData(LONG nPort, PBYTE/*PPLAYFRAMEHDR*/ pBuf,DWORD nSize);
//������Ƶ�������ݣ�һ��һ֡�� pBufΪ��PLAYFRAMEHDRͷ�ı������ݣ�nSize =(sizeof(PLAYFRAMEHDR)+((LPPLAYFRAMEHDR)pBuf)->m_dwDataSize)

BOOL __stdcall TLPlay_InputAudioData(LONG nPort, PBYTE/*PPLAYFRAMEHDR*/ pBuf,DWORD nSize);
//������Ƶ�������ݣ�һ��һ֡�� pBufΪ��PLAYFRAMEHDRͷ�ı������ݣ�nSize =(sizeof(PLAYFRAMEHDR)+((LPPLAYFRAMEHDR)pBuf)->m_dwDataSize)
enum AUDIOTYPE{AT_ERR, AT_ADPB_8k16, AT_GRAW_8K8, AT_GRAW_8K16, AT_G711_8K8};

BOOL __stdcall EncAudioFrame(AUDIOTYPE type, unsigned char *pInputBuf, unsigned char *pOutputBuf, int souraudioframelen);//maxframelenΪ��ƵԴ����

#ifdef __cplusplus
}
#endif

#endif


