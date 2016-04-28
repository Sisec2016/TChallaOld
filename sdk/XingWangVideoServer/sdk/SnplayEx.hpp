#ifndef _SNPLAYEX_HPP
#define _SNPLAYEX_HPP

#include <Windows.h>
#include <climits>
#include <cfloat>

#include "SnplayExDef.hpp"


//************************************
// Method:    ��ȡ���ſ�SDK�汾�ź�build��SnPlay_GetSdkVersion
// FullName:  SnPlay_GetSdkVersion
// Returns:   DWORD PLAY_DLL_EXPORT
//************************************
DWORD PLAY_DLL_EXPORT SnPlay_GetSdkVersion();


//************************************
// Method:    ��ʼ��������,�ڵ��ò�����sdk���к���֮ǰ����,��������һ��
// FullName:  SnPlay_Init
// Returns:   BOOL PLAY_DLL_EXPORT  �ɹ�����TURE��ʧ�ܷ���FALSE
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_Init();

//************************************
// Method:    ����ʼ�����������ڵ����겥����sdk���к�������ã���������һ��
// FullName:  SnPlay_Destory
// Returns:   void PLAY_DLL_EXPORT
//************************************
void PLAY_DLL_EXPORT SnPlay_Destory();







//************************************
// Method:    ��ȡδʹ�õ�ͨ����SnPlay_GetPort
// FullName:  SnPlay_GetPort
// Returns:   BOOL PLAY_DLL_EXPORT���ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG * nPort	[out],����ͨ���ţ�ָ�����ڻ�ȡ�˿ںŵ�LONG�ͱ���ָ�� ����200
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_GetPort(LONG* nPort);


//************************************
// Method:    �ͷ���ʹ�õ�ͨ����
// FullName:  SnPlay_FreePort
// Returns:   BOOL PLAY_DLL_EXPORT���ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG nPort	�ͷ���ʹ�õ�ͨ���ţ��ͷųɹ����ⲿ�����轫nPort��Ϊ-1
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_FreePort(LONG nPort);



//------------------------------------------------------
//���ſ�����أ����ţ��������������ͣ
//------------------------------------------------------

//************************************
// Method:    ��ȡָ��ͨ���Ĳ���״̬,�ڵ��ÿ��������������ʱ״̬�Ļ�ȡ
// FullName:  SnPlay_GetPlayStatus
// Returns:   PLAY_EX_STATUS  PLAY_DLL_EXPORT
// Parameter: LONG nPort ����ͨ����
//************************************
PLAY_EX_STATUS  PLAY_DLL_EXPORT SnPlay_GetPlayStatus(LONG nPort);



//************************************
// Method:    ���ò����������ļ�ʱ�򲥷�״̬
//			  ��������ʼ�����Ժ�������������ͣ����������״̬�ĸı�
//			  ������ֹͣ, ֹͣʱ�����SnPlay_Stop
//			  ��������ͣ����ͣʱ����SnPlay_Pause
// FullName:  SnPlay_SetPlayStatus
// Returns:   BOOL PLAY_DLL_EXPORT
// Parameter: LONG nPort				����ͨ����
// Parameter: PLAY_EX_STATUS pstatus	����״̬
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetPlayStatus(LONG nPort,PLAY_EX_STATUS pstatus);


//************************************
// Method:    ��������,EX_PLAY,�����ļ���ʵʱ�������ô˽ӿ�
// FullName:  SnPlay_Play
// Returns:   BOOL PLAY_DLL_EXPORT
// Parameter: LONG nPort	����ͨ����
// Parameter: HWND hWnd		������Ƶ�Ĵ��ھ��
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_Play(LONG nPort, HWND hWnd);


//************************************
// Method:    �رղ���SnPlay_Stop
// FullName:  SnPlay_Stop
// Returns:   BOOL PLAY_DLL_EXPORT	�ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG nPort	 ����ͨ����
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_Stop(LONG nPort);


//************************************
// Method:    ��ͣ/�ָ�����,��������
// FullName:  SnPlay_Pause
// Returns:   BOOL PLAY_DLL_EXPORT	�ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG nPort			����ͨ����
// Parameter: DWORD nPause			TURE��ͣ��FALSE�ָ�
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_Pause(LONG nPort,DWORD nPause);


//************************************
// Method:  ��֡ǰ��
//			�ָ�����������Ҫ����SnPlay_SetPlayStatus(EX_PLAY)
// FullName:  SnPlay_OneByOne
// Returns:   BOOL PLAY_DLL_EXPORT	�ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG nPort	����ͨ����
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_OneByOne(LONG nPort);






//************************************
// Method:  ���ÿ���ٶ�
//			����ʹ��SnPlay_SetPlayStatus�����滻
// FullName:  SnPlay_FastEx
// Returns:   BOOL PLAY_DLL_EXPORT,�ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG nPort	����ͨ����
// Parameter: PLAY_EX_STATUS pstatus	�����ٶ�,EX_PLAY2X,EX_PLAY4X,EX_PLAY8X,EX_PLAY16X
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_FastEx(LONG nPort,PLAY_EX_STATUS pstatus);


//************************************
// Method:    ���ٲ���
//			  ����ʹ��SnPlay_SetPlayStatus�����滻
//			  ÿ�ε��ý�ʹ��ǰ�����ٶȼӿ�һ��(2,4,8,16)��������4�Σ�//			  
// FullName:  SnPlay_Fast
// Returns:   BOOL PLAY_DLL_EXPORT	�ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG nPort	����ͨ����
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_Fast(LONG nPort);


//************************************
// Method:    ���ٲ���
//			  ����ʹ��SnPlay_SetPlayStatus�����滻
//			  ÿ�ε��ý�ʹ��ǰ�����ٶ���һ��(2,4,8,16)��������4�Σ�
// FullName:  SnPlay_Slow
// Returns:   BOOL PLAY_DLL_EXPORT	�ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG nPort		����ͨ����
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_Slow(LONG nPort);

//************************************
// Method:    ���˲���
//			  ����ʹ��SnPlay_SetPlayStatus�����滻
//			  ÿ�ε��ý�ʹ��ǰ�����ٶȼӿ�һ��(2,4,8,16)��������4�Σ�//			  
// FullName:  SnPlay_Fast
// Returns:   BOOL PLAY_DLL_EXPORT	�ɹ�����TURE��ʧ�ܷ���FALSE
// Parameter: LONG nPort	����ͨ����
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_Back(LONG nPort);


//************************************
// Method:    ��ȡ��ǰ֡��
// FullName:  SnPlay_GetCurrentFrameRate
// Returns:   DWORD PLAY_DLL_EXPORT
// Parameter: LONG nPort	����ͨ����
//************************************
DWORD PLAY_DLL_EXPORT SnPlay_GetCurrentFrameRate(LONG nPort);


//-----------------------------------------------------------------------------
//�ļ��������
//-----------------------------------------------------------------------------

//************************************
// Method:    ���ý�����Ϣ�ص�,��Ҫ֪ͨ�����ļ�����
// FullName:  SnPlay_SetDecMsgCallBack

// Returns:   BOOL PLAY_DLL_EXPORT
// Parameter: long lPort	 =player session
// Parameter: CALLBACK * DecMsgFun
// Parameter: long lPort	 =player session
// Parameter: int nFlag		 =��Ϣ���ͣ�0��ʾ��������
// Parameter: void * pUserData  =����������
// Parameter: void * pUserData	=����������
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetDecMsgCallBack(long lPort, 
	void (CALLBACK* DecMsgFun)(long lPort, int nFlag , void *pUserData), void *pUserData);


//************************************
// Method:    �����ļ���ͼ��֡��
// FullName:  SnPlay_SetFileFrameCnt
// Returns:   BOOL PLAY_DLL_EXPORT
// Parameter: LONG nport		����ͨ����
// Parameter: int fileFrameCnt	�ļ���֡��
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetFileFrameCnt(LONG nPort,int fileFrameCnt);

//************************************
// Method:    �����ļ���ǰ����λ��(�ٷֱ�)
// FullName:  SnPlay_SetPlayPos
// Returns:   BOOL PLAY_DLL_EXPORT
// Parameter: LONG nPort			����ͨ����
// Parameter: float fRelativePos	����λ��,��Χ0-100%
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetPlayPos(LONG nPort,float fRelativePos);


//************************************
// Method:    ��ȡ�ļ���ǰ����λ�ã��ٷֱȣ�
// FullName:  SnPlay_GetPlayPos
// Returns:   float PLAY_DLL_EXPORT		�ļ�����λ�÷�Χ0-100%
// Parameter: LONG nPort				����ͨ����
//************************************
float PLAY_DLL_EXPORT SnPlay_GetPlayPos(LONG nPort);

//************************************
// Method:    ���õ�ǰ���Ų���λ�õ�ָ��֡��
// FullName:  SnPlay_SetCurrentFrameNum
// Returns:   BOOL PLAY_DLL_EXPORT		�ɹ�����TURE,ʧ�ܷ���FALSE
// Parameter: LONG nPort		����ͨ����
// Parameter: DWORD nFrameNum	ָ��֡��
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);

//************************************
// Method:    ��ȡ�ļ���ǰ����֡��
// FullName:  SnPlay_GetCurrentFrameNum
// Returns:   DWORD PLAY_DLL_EXPORT
// Parameter: LONG nPort	����ͨ����
//************************************
DWORD PLAY_DLL_EXPORT SnPlay_GetCurrentFrameNum(LONG nPort);




//************************************
// Method:    ץͼ(BMP��ʽ)
// FullName:  SnPlay_CaptureBmpPicture
// Returns:   BOOL PLAY_DLL_EXPORT
// Parameter: long lPort		 ����ͨ����
// Parameter: char * filename	 ץͼ�ļ��� 
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_CaptureBmpPicture(long lPort,char * filename);


/*����˵����CaptureBmpPicture
/*����: long lPort  = player session
/*            char * filename= the file's name of saved Jpeg file*/

//************************************
// Method:    ץͼ(jpeg��ʽ)
// FullName:  SnPlay_CaptureJpegPicture
// Returns:   BOOL PLAY_DLL_EXPORT
// Parameter: long lPort		����ͨ����
// Parameter: char * filename	ץͼ�ļ���
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_CaptureJpegPicture(long lPort,char * filename);


//-----------------------------------------------------------------------------
//�������ӿ�
//-----------------------------------------------------------------------------

//************************************
// Method:    ����������,�ⲿ�����߱��뱣֤ʧ��ʱ���ٴγ����������ݣ��������ݻᶪʧ
// FullName:  SnPlay_InputData
// Returns:   BOOL PLAY_DLL_EXPORT	TURE=���뵽��������FALSE ��ʾʧ�ܣ�����û�����벥����
// Parameter: LONG nPort		����ͨ����
// Parameter: PBYTE pBuf		�����ݻ�������ַ
// Parameter: DWORD nSize		�����ݻ�������С
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);



















/*����˵�������ļ�SnPlay_OpenFile
/*�� ����LONG nPort ����ͨ����
/*�� ����LPSTR sFileName �ļ���
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*ע �⣺�ļ����ܳ���4G��С��4K*/
BOOL PLAY_DLL_EXPORT SnPlay_OpenFile(LONG nPort,LPSTR sFileName);

/*����˵�����ر��ļ�
/*�� ������
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_CloseFile(LONG nPort);


/*����˵��������������ģʽSnPlay_SetStreamOpenMode
/*������LONG nPort ����ͨ����
/*������DWORD nMode ������ģʽ��EX_STREAM,EX_FILE_STREAM EX_STREAMģʽ��Ĭ�ϣ���, �ᾡ������ʵʱ��, ��ֹ��������; �������ݼ���ϸ�;
/*      EX_FILE_STREAMģʽ����Ȼ.
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_SetStreamOpenMode(LONG nPort,DWORD nMode);

/*����˵������ȡ������ģʽSnPlay_GetStreamOpenMode
/*�� ����LONG nPort ����ͨ����
/*����ֵ��STREAME_REALTIME��STREAME_FILE*/
LONG PLAY_DLL_EXPORT SnPlay_GetStreamOpenMode(LONG nPort);

/*����˵��������SnPlay_OpenStream
/*�� ����LONG nPort ����ͨ����
/*�� ����PBYTE pFileHeadBuf �ļ�ͷ����
/*�� ����DWORD nSize �ļ�ͷ����
/*�� ����DWORD nBufPoolSize ���ò������д���������Ļ�������С�� ��Χ��SOURCE_BUF_MIN~ SOURCE_BUF_MAX����ֵ��С�ᵼ���޷����룬��������豸��ֵ���ڵ���200*1024�������豸���ڵ���600*1024��
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize, DWORD nBufPoolSize);

/*����˵�����ر���SnPlay_CloseStream
/*�� ����LONG nPort ����ͨ����
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_CloseStream(LONG nPort);



/*����˵����������������Ƶ�ֿ����뷽ʽ��SnPlay_OpenStreamEx
/*�� ����LONG nPort ����ͨ����
/*�� ����PBYTE pFileHeadBuf �ļ�ͷ����
/*�� ����DWORD nSize DWORD �ļ�ͷ����
/*�� ����nBufPoolSize ���ò������д���������Ļ�������С����Χ��SOURCE_BUF_MIN~ SOURCE_BUF_MAX
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*˵ ����������Ƶ�ֿ�����ķ�ʽ����*/
BOOL PLAY_DLL_EXPORT SnPlay_OpenStreamEx(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize, DWORD nBufPoolSize);

/*����˵�����ر�����������Ƶ�ֿ����뷽ʽ��SnPlay_CloseStreamEx
/*�� ����LONG nPort ����ͨ����
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_CloseStreamEx(LONG nPort);

/*����˵����������Ƶ��SnPlay_InputVideoData
/*�� ����LONG nPort ����ͨ����
/*���� PBYTE pBuf ��������ַ 
/*����DWORD nSize ��������С
/*����ֵ��TURE,��ʾ�Ѿ��������ݡ�FALSE ��ʾʧ�ܣ�����û������
/*˵ ����������Ƶ�� (�����Ǹ�����������Ƶ���ݻᱻ����);������֮�������������*/
BOOL PLAY_DLL_EXPORT SnPlay_InputVideoData(LONG nPort,PBYTE pBuf,DWORD nSize);

/*����˵����������Ƶ��SnPlay_InputAudioData
/*�� ����LONG nPort ����ͨ����
/*�� ����PBYTE pBuf ��������ַ 
/*�� ����DWORD nSize ��������С
/*����ֵ��TURE,��ʾ�Ѿ��������ݡ�FALSE ��ʾʧ�ܣ�����û������
/*˵ ����������Ƶ����������֮������������ݡ�����False�������ڲ���������������ͻ���ͣ���������̣߳��ٴ��������ݣ�ȷ�����ſⲻ��ʧ����*/
BOOL PLAY_DLL_EXPORT SnPlay_InputAudioData(LONG nPort,PBYTE pBuf,DWORD nSize);







/*����˵�����Զ�ռ��ʽ������SnPlay_PlaySound
/*�� ����LONG nPort ����ͨ����
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*˵ ����ͬһʱ��ֻ����һ·��������������Ѿ��������򿪣����Զ��ر�ԭ���Ѿ��򿪵�����*/
BOOL PLAY_DLL_EXPORT SnPlay_PlaySound(LONG nPort);

/*����˵�����ر���������ռ��ʽ��SnPlay_StopSound
/*�� ������
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*ע �⣺SnPlay_PlaySound��SnPlay_StopSound��Ҫ��Ե���*/
BOOL PLAY_DLL_EXPORT SnPlay_StopSound(LONG nPort);

/*����˵�����Թ���ʽ������SnPlay_PlaySoundShare
/*�� ����LONG nPort ����ͨ����
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*˵ �����Թ���ʽ����������ֻ�ܲ��ű�·��������ȥ�ر�����·������*/
BOOL PLAY_DLL_EXPORT SnPlay_PlaySoundShare(LONG nPort);

/*����˵�����ر�����������ʽ��SnPlay_StopSoundShare
/*�� ����LONG nPort ����ͨ����
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*˵ �����Թ���ʽ�ر�������SnPlay_PlaySound��SnPlay_StopSound���Զ�ռ��ʽ����������*/
BOOL PLAY_DLL_EXPORT SnPlay_StopSoundShare(LONG nPort);

/*����˵������������SnPlay_SetVolume
/*�� ����LONG nPort ����ͨ����
/*�� ����WORD nVolume ����ֵ����Χ0-0XFFFF
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ���������ڲ���֮ǰ���ã�����ֵ��FALSE�������õ�ֵ�����棬����Ϊ��������ʱ�ĳ�ʼ�����������������ֻ�������������������Ӱ�쵽����������Ӧ��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetVolume(LONG nPort,WORD nVolume);

/*����˵������ȡ����SnPlay_GetVolume
/*�� ����LONG nPort ����ͨ����
/*����ֵ������ֵ�������������ֻ�������������������Ӱ�쵽����������Ӧ��*/
WORD PLAY_DLL_EXPORT SnPlay_GetVolume(LONG nPort);

/*����˵��������WAVE����SnPlay_AdjustWaveAudio
/*�� ����LONG nPort ����ͨ����
/*�� ����LONG nCoefficient ����������0�ǲ������� ��Χ��MIN_WAVE_COEF �� MAX_WAVE_COEF��
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ��������WAVE���Σ����Ըı������Ĵ�С����SnPlay_SetVolume�Ĳ�ͬ���ڣ����ǵ����������ݣ�ֻ�Ը�·�����ã���SnPlay_SetVolume�ǵ�������������������ϵͳ������*/
BOOL PLAY_DLL_EXPORT SnPlay_AdjustWaveAudio(LONG nPort,LONG nCoefficient);

/*����˵��������ͼ������SnPlay_SetPicQuality
/*�� ����LONG nPort ����ͨ����
/*BOOL bHighQuality ����1ʱͼ�������������0ʱ��������Ĭ��ֵ����
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*˵ ���������óɸ�����ʱ����Ч���ã���CPU�����ʸߡ���֧�ֶ�·����ʱ��������Ϊ���������Խ���CPU�����ʣ���ĳ·�Ŵ󲥷�ʱ����·���óɸ��������Դﵽ�õĻ���Ч��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetPicQuality(LONG nPort,BOOL bHighQuality);

/*����˵������ȡͼ������SnPlay_GetPictureQuality
/*�� ����LONG nPort ����ͨ����
/*�� ����[out]BOOL *bHighQuality 1��ʾ��������0��ʾ������
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_GetPictureQuality(LONG nPort,BOOL *bHighQuality);

/*����˵����������Ƶ����SnPlay_SetColor
/*�� ����LONG nPort ����ͨ���� 
/*�� ����DWORD nRegionNum ��ʾ���򣬲ο�SnPlay_SetDisplayRegion ���ֻ��һ����ʾ����(ͨ�����);��Ϊ0
/*�� ����int nBrightness  ���ȣ�Ĭ��64 ��Χ0-128
/*�� ����int nContrast  �Աȶȣ�Ĭ��64 ��Χ0-128
/*�� ����int nSaturation  ���Ͷȣ�Ĭ��64 ��Χ0-128
/*�� ����int nHue ɫ����Ĭ��64 ��Χ0-128
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);

/*����˵������ȡ��Ƶ����SnPlay_GetColor
/*�� ����LONG nPort ����ͨ����
/*�� ����DWORD nRegionNum ��ʾ����
/*�� ����[out]int *pBrightness ���ȣ�Ĭ��64�� ��Χ0-128
/*�� ����[out]int *pContrast �Աȶȣ�Ĭ��64�� ��Χ0-128
/*�� ����[out]int *pSaturation ���Ͷȣ�Ĭ��64�� ��Χ0-128
/*�� ����[out]int *pHue ɫ����Ĭ��64�� ��Χ0-128
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast,int *pSaturation, int *pHue);

/*�� ���������ļ���ǰ����ʱ�䣨���룩SnPlay_SetPlayedTimeEx
�� ����LONG nPort DWORD nTime����ͨ���� �����ļ����ŵ�ָ��ʱ�䣬��λ����
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵��������ʱ�������ļ�����λ��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetPlayedTimeEx(LONG nPort,DWORD nTime);

/*�� ������ȡ�ļ���ǰ����ʱ�䣨���룩SnPlay_GetPlayedTimeEx
�� ����LONG nPort����ͨ����
����ֵ���ļ���ǰ���ŵ�ʱ�䣬��λ����*/
DWORD PLAY_DLL_EXPORT SnPlay_GetPlayedTimeEx(LONG nPort);


/*�� ������ȡ�ļ���ʱ��SnPlay_GetFileTime
�� ����LONG nPort����ͨ����
����ֵ���ļ���ʱ�䳤�ȣ���λ��*/
DWORD PLAY_DLL_EXPORT SnPlay_GetFileTime(LONG nPort);

/*�� ������ȡ�ļ���֡��SnPlay_GetFileTotalFrames
�� ����LONG nPort����ͨ����
����ֵ���ļ���֡��*/
DWORD PLAY_DLL_EXPORT SnPlay_GetFileTotalFrames(LONG nPort);


/*�� ������ȡ�Ѳ���ʱ��SnPlay_GetPlayedTime
�� ����LONG nPort����ͨ����
����ֵ���ļ���ǰ����ʱ�䣬��λ��*/
DWORD PLAY_DLL_EXPORT SnPlay_GetPlayedTime(LONG nPort);

/*�� ������ȡ�ѽ������Ƶ֡��SnPlay_GetPlayedFrames
�� ����LONG nPort����ͨ����
����ֵ���Ѿ��������Ƶ֡��*/
DWORD PLAY_DLL_EXPORT SnPlay_GetPlayedFrames(LONG nPort);

/*�� ������ȡԭʼͼ���СSnPlay_GetPictureSize
�� ����
LONG nPort, [out]LONG *pWidth, [out]LONG *pHeight
����ͨ���� ԭʼͼ��Ŀ�� ԭʼͼ��ĸ߶�
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������������ԭʼͼ��Ĵ�С�����ݴ˴�С��������ʾ���ڵ����򣬿��Բ�ʹ���Կ������Ź�����������Щ��֧��Ӳ�����ŵ��Կ���˵�ǳ�����*/
BOOL PLAY_DLL_EXPORT SnPlay_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);

/*�� ������ȡ�ļ�ͷ����SnPlay_GetFileHeadLength
�� ������
����ֵ���������ڽ����ĺ���ý���ļ�ͷ�򺣿�ý����Ϣͷ�Ĵ�С*/
DWORD PLAY_DLL_EXPORT SnPlay_GetFileHeadLength();;

/*�� �������ý���ص�������SnPlay_SetDecCBStream
�� ����
LONG nPort DWORD nStream
����ͨ���� 1��Ƶ����2��Ƶ����3������
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ���������ڽ���ص�����ǰʹ��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetDecCBStream(LONG nPort,DWORD nStream);

/*�� ��������ص�SnPlay_SetDecCallBack
�� ����
LONG nPort void (CALLBACK* DecCBFun); DecCBFun�ص���������˵�� nPort pBuf nSize pFrameInfo nReserved1��nReserved2 SNEX_FRAME_INFO�ṹ˵��typedef struct{ long nWidth; long nHeight; long nStamp; long nType long nFrameRate; DWORD dwFrameNum; }SNEX_FRAME_INFO; �궨��˵��T_AUDIO16 T_RGB32 T_UYVY
����ͨ���� ����ص�����ָ�룬����ΪNULL ������ͨ���� ����������Ƶ���� ����������Ƶ����pBuf�ĳ��� ͼ���������Ϣ �������� �������λ���ء��������Ƶ������Ϊ0�� ����ߡ��������Ƶ������Ϊ0�� ʱ����Ϣ����λ�����������ͣ�T_AUDIO16��T_RGB32�� T_YV12�� ����ʱ������ͼ��֡��֡�� ��Ƶ����;������16khz����������ÿ��������16λ��ʾ����Ƶ���ݡ�ÿ������4���ֽڣ����з�ʽ��λͼ���ƣ���B-G-R-0 ��������һ������λ��ͼ�����½ǡ���Ƶ���ݣ�uyvy��ʽ����U0-Y0-V0-Y1-U2-Y2-V2-Y3��.������һ������λ��ͼ�����Ͻ�
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ûص��������滻�������е���ʾ���֣����û��Լ�������ʾ���ú�����SnPlay_Play֮ǰ���ã���SnPlay_Stopʱ�Զ�ʧЧ���´ε���SnPlay_Play֮ǰ��Ҫ�������á�*/	
BOOL PLAY_DLL_EXPORT SnPlay_SetDecCallBack(LONG nPort,void (CALLBACK* DecCBFun)(long nPort,char * pBuf,long nSize,SNEX_FRAME_INFO * pFrameInfo, long nReserved1,long nReserved2));


/*�� ��������ص��������û����ݲ�����SnPlay_SetDecCallBackMend
�� ����
LONG nPort void (CALLBACK* DecCBFun); long nUser DecCBFun�ص��������� long nPort char * pBuf long nSize SNEX_FRAME_INFO * pFrameInfo long nUser long nReserved2 SNEX_FRAME_INFO����˵�� typedef struct{ long nWidth long nHeight long nStamp long nType long nFrameRate }SNEX_FRAME_INFO;
����ͨ���� ����ص�����������ΪNULL �û����� ����ͨ���� ����������Ƶ���� ����������Ƶ���ݳ��� ͼ����������Ϣ �û����� �������� �������λ���ء��������Ƶ������Ϊ0 ����ߡ��������Ƶ������Ϊ0 ʱ����Ϣ����λ���� �������ͣ�T_AUDIO16��T_RGB32�� T_YV12 ����ʱ������ͼ��֡��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ûص��������滻�������е���ʾ���֣����û��Լ�������ʾ���ú�����SnPlay_Play֮ǰ���ã���SnPlay_Stopʱ�Զ�ʧЧ���´ε���SnPlay_Play֮ǰ��Ҫ�������á�ע����벿�ֲ������ٶȣ�ֻҪ�û��ӻص������з��أ��������ͻ������һ�������ݡ�������ܵ�ʹ����Ҫ�û�����Ƶ��ʾ�������������㹻���˽⣬����������ʹ�ã��й�֪ʶ�����directx���������ͽ���ص�*/
BOOL PLAY_DLL_EXPORT SnPlay_SetDecCallBackMend(LONG nPort,void (CALLBACK* DecCBFun)(long nPort,char * pBuf,long nSize,SNEX_FRAME_INFO * pFrameInfo, long nUser, long nReserved2), long nUser);

/*�� ������Ƶ����ص�SnPlay_SetAudioCallBack *
�� ����
LONG nPort void (__stdcall * funAudio); long nUser funAudio�ص��������� long nPort char * pAudioBuf long nSize long nStamp long nType long nUser
����ͨ���� ��Ƶ����ص����� �û����� ����ͨ���� wave��ʽ��Ƶ���� ��Ƶ���ݳ��� ʱ��(ms); ��Ƶ����T_AUDIO16, ������16khz����������ÿ��������16λ �û�����
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE		*/
BOOL PLAY_DLL_EXPORT SnPlay_SetAudioCallBack(LONG nPort, void (__stdcall * funAudio)(long nPort, char * pAudioBuf, long nSize, long nStamp, long nType, long nUser), long nUser);;

/*�� �����ļ�������ϢSnPlay_SetFileEndMsg
�� ����
LONG nPort HWND hWnd UINT nMsg
����ͨ������Ϣ���͵Ĵ����û��Զ�����������Ϣ�������ŵ��ļ�����ʱ�û���hWnd���ڹ������յ������Ϣ������Ϣ�����е�wParam��������nPort��ֵ
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ���������ļ�����ʱҪ���͵���Ϣ����2.4�汾SDK�𣬵��ļ�������ʱ�������߳̽������Զ���������Ҫ�û���ֹͣ������Ӧ�ó������յ������Ϣ��Ҫ���ò��Ž�������SnPlay_Stop(nPort);*/
BOOL PLAY_DLL_EXPORT SnPlay_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);

/*�� �����ļ������ص�SnPlay_SetFileEndCallback
�� ����
LONG nPort void(CALLBACK*FileEndCallback); void *pUser FileEndCallback�ص��������� long nPort void *pUser
����ͨ���� �ļ������ص����� �û����� ����ͨ���� �û�����
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ���������ļ����Ž����ص���������SnPlay_OpenSteam/SnPlay_OpenFile֮ǰ���ò���Ч	*/	
BOOL PLAY_DLL_EXPORT __stdcall SnPlay_SetFileEndCallback(LONG nPort, void(CALLBACK*FileEndCallback)(long nPort, void *pUser), void *pUser);;

/*�� �����ֱ�ı�֪ͨ��ϢSnPlay_SetEncChangeMsg
�� ����
LONG nPort HWND hWnd UINT nMsg
����ͨ���� hWnd ��Ϣ���͵Ĵ��� �û��������Ϣ�������ý���ʱ�����ʽ�����ı�ʱҪ���ʹ˶������Ϣ����Ϣ�����е�wParam����ֵ�Ƿ���nPort��ֵ��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ý���ʱ����ֱ��ʷ����ı�ʱҪ���͵���Ϣ*/		
BOOL PLAY_DLL_EXPORT SnPlay_SetEncChangeMsg(LONG nPort,HWND hWnd,UINT nMsg);

/*�� �����ֱ��ʸı�֪ͨ�ص�SnPlay_SetEncTypeChangeCallBack
�� ����
LONG nPort void(CALLBACK *funEncChange); long nUser funEncChange�ص��������� long nPort long nUser
����ͨ���� �ֱ��ʷ����ı�ʱ֪ͨ�û��Ļص����� �û����� ����ͨ���� �û�����
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ������Ҫ�ڴ��ļ�֮ǰʹ��*/		
BOOL PLAY_DLL_EXPORT SnPlay_SetEncTypeChangeCallBack (LONG nPort,void(CALLBACK *funEncChange)(long nPort,long nUser),long nUser);

/*�� �������ö�B֡����SnPlay_ThrowBFrameNum
�� ����
LONG nPort DWORD nNum
����ͨ���� ������B֡��֡������Χ0~2
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ò�����B֡֡����������B֡�����Լ�СCPU�����ʣ����������û��B֡����ô�������ֵ�����������á����ڿ��ٲ��ţ���֧�ֶ�·��CPU������̫�ߵ�����¿��Կ���ʹ�á�*/
BOOL PLAY_DLL_EXPORT SnPlay_ThrowBFrameNum(LONG nPort,DWORD nNum);

/*�� �������֡���Ƿ�����SnPlay_CheckDiscontinuousFrameNum
�� ����LONG nPort BOOL bCheck����ͨ���� ֡�Ų�����ʱ�Ƿ�����һ��I֡
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������֡���Ƿ������� 4.8build0813��6.1.1.17�汾֧�֡�	*/	
BOOL PLAY_DLL_EXPORT SnPlay_CheckDiscontinuousFrameNum(LONG nPort, BOOL bCheck);

/*�� ����������ԿSnPlay_SetSecretKey
�� ����
LONG nPort LONG lKeyType char *pSecretKey LONG lKeyLen
����ͨ���� ��Կ���� ��Կ�� ��Կ���ȣ���λΪbit��1�ֽ�Ϊ8 bit��
����ֵ��
�ɹ�����TURE��ʧ�ܷ���FALSE
˵ ����
����ڱ���ʱ��������Կ����ô�ڽ���֮ǰ��Ҫ���øýӿ�������Կ�����������롣�ýӿ���SnPlay_OpenSteam/SnPlay_OpenFile֮ǰ���ò���Ч��	*/	
BOOL PLAY_DLL_EXPORT __stdcall SnPlay_SetSecretKey(LONG nPort, LONG lKeyType, char *pSecretKey, LONG lKeyLen);

/*�� ��������OVERLAY��ʾģʽ���ؼ�ɫSnPlay_SetOverlayMode	
�� ����
LONG nPort BOOL bOverlay
����ͨ����
TRUE��ʾ�����ȳ���ʹ��OVERLAYģʽ�����������ʹ��		
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ��������OVERLAYģʽ��ʾ���档��һ���Կ���ͬһʱ��ֻ����һ��OVERLAY���洦�ڻ״̬�������ʱϵͳ���Ѿ��г���ʹ����OVERLAY����ô�������Ͳ����ٴ���OVERLAY���棬�����Զ�����Off_Screen���棬��������FALSE��һЩ���õĲ��������Լ����ǿ���Ԥ��������ʹ����overlay���档ͬ�������������ʹ����OVERLAY���棬��ô�������ĳ��򽫲���ʹ��OVERLAY���棬�ر�ע�⣬���ǵĿ���Ԥ��ʱ����ҲҪʹ��OVERLAY(�û�������);������ȴ򿪲�����������ʹ����OVERLAY����������Ԥ������ôԤ��������Ϊ�ò���OVERLAY��ʧ�ܡ�ʹ��OVERLAYģʽ���ŵ��ǣ��󲿷ݵ��Կ���֧��OVERLAY����һЩ��֧��BLTӲ�����ź���ɫת�����Կ���(��SISϵ���Կ�);ʹ��OVERLAYģʽ��OVERLAYģʽ�µ����ź���ɫת�����Կ�֧�֣������Դ���Сcpu�����ʲ���߻��������������������ź���ɫת������ȱ���ǣ�ֻ����һ·������ʹ�á������ñ�����PLAY֮ǰʹ�ã�������Ҫ����͸��ɫ��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetOverlayMode(LONG nPort,BOOL bOverlay,COLORREF colorKey);

/*�� ������ȡOVERLAY�ؼ�ɫSnPlay_GetColorKey
�� ����LONG nPort ����ͨ����
����ֵ����ɫֵ	*/	
COLORREF PLAY_DLL_EXPORT SnPlay_GetColorKey(LONG nPort);

/*�� �������û�������ʾ����SnPlay_SetDisplayRegion
�� ����LONG nPort DWORD
����ͨ���� ��ʾ������ţ�0~(MAX_DISPLAY_WND-1);��nRegionNum RECT *pSrcRect HWND hDestWnd BOOL bEnable
���nRegionNumΪ0����ʾ����Ҫ��ʾ����(SnPlay_Play�����õĴ���);�������ã�������hDestWnd��bEnable�����á� ������Ҫ��ʾ��ԭʼͼ���ϵ������磺���ԭʼͼ����352*288����ôpSrcRect�����õķ�Χֻ���ڣ�0��0��352��288��֮�С����pSrcRect=NULL,����ʾ����ͼ�� ������ʾ���ڡ����������Ĵ����Ѿ����ù����򿪹�������ô�ò��������ԡ� �򿪣����ã���ر���ʾ����	
����ֵ��
�ɹ�����TURE��ʧ�ܷ���FALSE
˵ ����
���û�������ʾ���򡣿������ֲ��Ŵ���ʾ��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetDisplayRegion(LONG nPort,DWORD nRegionNum, RECT *pSrcRect, HWND hDestWnd, BOOL bEnable);

/*�� ����ˢ����ʾSnPlay_RefreshPlay
�� ����LONG nPort����ͨ����
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ����ˢ����ʾ�����û���ͣʱ���ˢ���˴��ڣ��򴰿��е�ͼ����Ϊˢ�¶���ʧ����ʱ��������ӿڿ������°�ͼ����ʾ������ֻ������ͣ�͵�֡����ʱ�Ż�ִ�У����������ֱ�ӷ��ء�*/
BOOL PLAY_DLL_EXPORT SnPlay_RefreshPlay(LONG nPort);

/*�� ����ˢ����ʾ������ʾ����SnPlay_RefreshPlayEx
�� ����LONG nPort DWORD nRegionNum����ͨ���� ��ʾ�������
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ����ˢ����ʾ��ͬSnPlay_RefreshPlay��Ϊ֧��SnPlay_SetDisplayRegion������һ��������	*/	
BOOL PLAY_DLL_EXPORT SnPlay_RefreshPlayEx(LONG nPort,DWORD nRegionNum);

/*�� ����������ʾģʽSnPlay_SetDisplayType
�� ����LONG nPort LONG nType����ͨ���� ����ģʽ�� ISPLAY_NORMAL �����ֱ����������Կ���ʾ�� DISPLAY_QUARTER 1/4�ֱ����������Կ���ʾ��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ����������ʾ��ģʽ����С������ʾʱ������DISPLAY_QUARTER ���Լ�С�Կ����������Ӷ�֧�ָ���·��ʾ����������ʾ�������½����������ʹ�����ʾʱӦ��ʹ��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetDisplayType(LONG nPort,LONG nType);

/*�� ������ȡ��ʾģʽSnPlay_GetDisplayType
�� ����LONG nPort����ͨ����
����ֵ��DISPLAY_NORMAL �� DISPLAY_QUARTER*/		
LONG PLAY_DLL_EXPORT SnPlay_GetDisplayType(LONG nPort);

/*�� ������ȡԴ������ʣ�����ݴ�СSnPlay_GetSourceBufferRemain
�� ����LONG nPort ����ͨ����
����ֵ����ǰԴ����Ĵ�С��BYTE��	*/	
DWORD PLAY_DLL_EXPORT SnPlay_GetSourceBufferRemain(LONG nPort);

/*�� ��������Դ��������ֵ���ص�ָ��SnPlay_SetSourceBufCallBack
�� ����nThreShold SourceBufCallBack dwUser pReserved SourceBufCallBack�ص���������˵�� nPort nBufSize dwUser pResvered
��ֵ �ص�����ָ�� �û����� �������� ������ͨ���� ��������ʣ������ �û����� ��������
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ��������Դ��������ֵ��ʣ������С�ڵ��ڷ�ֵʱ�Ļص�����ָ�롣ֻ�����������Ӵ�С"Խ��"ָ����ֵ��ʱ��, �Żᴥ���ص�; һ�δ�������Ҫ����		*/
BOOL PLAY_DLL_EXPORT SnPlay_SetSourceBufCallBack(LONG nPort,DWORD nThreShold, void (CALLBACK * SourceBufCallBack)(long nPort,DWORD nBufSize,DWORD dwUser,void*pResvered),DWORD dwUser,void *pReserved);

/*�� �������ûص���־Ϊ��Ч״̬SnPlay_ResetSourceBufFlag
�� ����LONG nPor ����ͨ����
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ûص���־λΪ��Ч״̬��*/		
BOOL PLAY_DLL_EXPORT SnPlay_ResetSourceBufFlag(LONG nPort);

/*�� �������ò��Ż�������󻺳�֡��SnPlay_SetDisplayBuf
�� ����
LONG nPort DWORD nNum
����ͨ���� ���Ż�������󻺳�֡������Χ��MIN_DIS_FRAMES ~MAX_DIS_FRAMES��һ֡352*288ͼ��������ڴ���Сֵ�� 352*288*3/2��Լ150K �����ֵ��352*288*4��Լ405K��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ò��Ż���������������ͼ�񻺳�������С������������Ƚ���Ҫ����ֱ��Ӱ�첥�ŵ������Ժ���ʱ�ԡ���һ����Χ�ڻ���Խ��Խ������ͬʱ��ʱԽ���ڲ����ļ�ʱ�û���ÿ��Կ��ǿ��󻺳壨����ڴ��㹻�󣩣����ǵ�Ĭ��ֵ��15��֡������25֡/�������¼�0.6������ݡ��ڲ�����ʱ���ǵ�Ĭ��ֵ��10(֡);������û�׷�������ʱ��С�����Կ����ʵ���С���ֵ��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetDisplayBuf(LONG nPort,DWORD nNum);

/*�� ������ȡ���Ż�������󻺳�֡��SnPlay_GetDisplayBuf
�� ����LONG nPort����ͨ����
����ֵ�����Ż�������󻺳�֡��	*/	
DWORD PLAY_DLL_EXPORT SnPlay_GetDisplayBuf(LONG nPort);

/*�� ����������л�������ʣ������SnPlay_ResetSourceBuffer
�� ����LONG nPort ����ͨ����
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE	*/	
BOOL PLAY_DLL_EXPORT SnPlay_ResetSourceBuffer(LONG nPort);

/*�� �������ָ����������ʣ������SnPlay_ResetBuffer
�� ����LONG nPort DWORD nBufType �������궨�� BUF_VIDEO_SRC BUF_AUDIO_SRC BUF_VIDEO_RENDER BUF_AUDIO_RENDER
����ͨ���� ���������� ��Ƶ����Դ���������������֮ǰ��Ƶ���ݣ�ֻ����ģʽ��Ч����λbyte�� ��Ƶ����Դ���������������֮ǰ��Ƶ���ݣ�ֻ����ģʽ��Ч����λbyte��������Ƶ���ݷֿ��͵�����²���Ч ��Ƶ���Ż�����ʣ�����ݣ���λ֡���� ��Ƶ���Ż�����ʣ�����ݣ���λ֡������Ƶ40ms���ݶ�Ϊһ֡��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE		*/
BOOL PLAY_DLL_EXPORT SnPlay_ResetBuffer(LONG nPort,DWORD nBufType);

/*�� ������ȡָ���������Ĵ�СSnPlay_GetBufferValue
�� ����LONG nPort DWORD nBufType �������궨�� BUF_VIDEO_SRC BUF_AUDIO_SRC BUF_VIDEO_RENDER BUF_AUDIO_RENDER
����ͨ���� ���������� ��Ƶ����Դ���������������֮ǰ��Ƶ���ݣ�ֻ����ģʽ��Ч����λbyte�� ��Ƶ����Դ���������������֮ǰ��Ƶ���ݣ�ֻ����ģʽ��Ч����λbyte��������Ƶ���ݷֿ��͵�����²���Ч ��Ƶ���Ż�����ʣ�����ݣ���λ֡���� ��Ƶ���Ż�����ʣ�����ݣ���λ֡������Ƶ40ms���ݶ�Ϊһ֡��
����ֵ�����ݲ�����ͬ�����ػ�����ֵ��Դ����������byte,����󻺳�������֡����
˵ ������ȡ�������еĻ�������С��֡������byte��������ӿڿ��԰����û��˽⻺�����е����ݣ��Ӷ���������ʱ�����������ơ�*/
DWORD PLAY_DLL_EXPORT SnPlay_GetBufferValue(LONG nPort,DWORD nBufType);

/*�� �������ý��������ص�SnPlay_SetFileRefCallBack
�� ����
LONG nPort void (__stdcall *pFileRefDone); DWORD nUser pFileRefDone�ص���������˵�� nPort nUser
����ͨ���� �����ص����� �û����� ������ͨ���� �û�����
����ֵ��
�ɹ�����TURE��ʧ�ܷ���FALSE
˵ ����
�ļ�����������ص��� Ϊ�������ļ���׼ȷ���ٵĶ�λ���������ļ��򿪵�ʱ�������ļ�������������̺�ʱ�Ƚϳ�����Լÿ�봦��40M���ҵ����ݣ���Ҫ����Ϊ��Ӳ�̶����ݱȽ��������������Ĺ������ں�̨��ɣ���Ҫʹ�������ĺ���Ҫ�ȴ�������̽������������ӿڲ����ܵ�Ӱ�졣 ���ļ�ʱ�Ƿ����ļ��Ĺؼ�֡����, ��������ص�δ����, ����¼���ļ��쳣��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetFileRefCallBack(LONG nPort, void (__stdcall *pFileRefDone)(DWORD nPort,DWORD nUser),DWORD nUser);

/*�� ��������ָ��λ��֮ǰ�Ĺؼ�֡λ��SnPlay_GetKeyFramePos
/*�� ����LONG nPort DWORD nValue DWORD nType PSNEX_FRAME_POS pFramePos PSNEX_FRAME_POS����˵�� typedef struct{ long nFilePos long nFrameNum long nFrameTime }SNEX_FRAME_POS,*PSNEX_FRAME_POS;
����ͨ���� ��ǰλ�ã�������ʱ���֡�ţ�������nTypeָ�� nValue���͡����nType ��BY_FRAMENUM��nValue��ʾ֡�ţ����nType ��BY_FRAMTIME����nValue��ʾʱ�䣬��λ���� ���ҵ��Ĺؼ�֡���ļ�λ�á�֡��š�ʱ����Ϣ �ļ�λ�� ֡��� ֡ʱ�꣨���룩
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE	
˵ ��������ָ��λ��֮ǰ�Ĺؼ�֡λ�á�ͼ��������ӹؼ�֡��ʼ������û�������ļ����Ǵӹؼ�֡��ʼ�ģ���ô����һ���ؼ�֮֡ǰ�����ݻᱻ���ԡ�����û�Ҫ��ȡ�ļ��е�һ�����ݣ���Ӧ�ÿ��Ǵӹؼ�֡��ʼ��ȡ������λ�����ϵ������ඪʧ3֡���ݡ� ���ļ�����������ɵ�ǰ����, �������ӿڣ�81��82����������ʵ�ּ���¼���ļ�, ����������ؼ�֡����й�.*/	
BOOL PLAY_DLL_EXPORT SnPlay_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PSNEX_FRAME_POS pFramePos);

/*�� ��������ָ��λ��֮��Ĺؼ�֡λ��SnPlay_GetNextKeyFramePos
�� ����
LONG nPort DWORD nValue DWORD nType PSNEX_FRAME_POS pFramePos
����ͨ���� ��ǰλ�ã�������ʱ���֡�ţ�������nTypeָ�� nValue���͡����nType ��BY_FRAMENUM��nValue��ʾ֡�ţ����nType ��BY_FRAMTIME����nValue��ʾʱ�䣬��λ���� ���ҵ��Ĺؼ�֡���ļ�λ�á�֡��š�ʱ����Ϣ
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ��������ָ��λ��֮��Ĺؼ�֡λ�� ���ļ�����������ɵ�ǰ����, �������ӿڣ�81��82����������ʵ�ּ���¼���ļ�, ����������ؼ�֡����й�.*/
BOOL PLAY_DLL_EXPORT SnPlay_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PSNEX_FRAME_POS pFramePos);

/*�� ������ȡ�ļ�����SnPlay_GetRefValue
�� ����
LONG nPort [out]BYTE *pBuffer DWORD *pSize
����ͨ���� ������Ϣ ����pBuffer�Ĵ�С�����������Ϣ��С��ע�⣺�����ڵ�һ��ָ��pSize=0,pBuffer=NULL,��pSize�ķ���ֵ�����Ҫ�Ļ�������С��Ȼ������㹻�Ļ��壬�ٵ���һ��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ������ȡ�ļ�������Ϣ���Ա��´δ�ͬһ���ļ�ʱֱ��ʹ�������Ϣ���������������ɺ���ܻ����Ϣ��*/
BOOL PLAY_DLL_EXPORT SnPlay_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);

/*�� ���������ļ�����SnPlay_SetRefValue
�� ����
LONG nPort BYTE *pBuffer
����ͨ���� ������Ϣ		
DWORD nSize
������Ϣ�ĳ���
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ���������ļ�����������Ѿ������ļ�������Ϣ�����Բ��ٵ������������Ļص����� SnPlay_SetFileRefCallBack��ֱ������������Ϣ��	*/
BOOL PLAY_DLL_EXPORT SnPlay_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);

/*�� ����ö��ϵͳ�е���ʾ�豸SnPlay_InitDDrawDevice ע�⣺V6.1.1.0�����ϵİ汾���ڶ�����ʾ����Ӧ��������Ҫ�ٵ��������ⲿ�ֺ�����
�� ������
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE		*/
BOOL PLAY_DLL_EXPORT SnPlay_InitDDrawDevice();

/*�� �����ͷ�ö����ʾ�豸���̷������ԴSnPlay_ReleaseDDrawDevice
�� ������
����ֵ��Void	*/	
void PLAY_DLL_EXPORT SnPlay_ReleaseDDrawDevice();


/*�� ������ȡ��ʾ�豸���Կ�������SnPlay_GetDDrawDeviceTotalNums
�� �����������0�����ʾϵͳ��ֻ������ʾ�豸���������1�����ʾϵͳ�а�װ�˶���Կ�����ֻ��һ���Կ���Windows����󶨡���������ֵ�����ʾϵͳ��������󶨵��Կ���Ŀ���ڶ��Կ���ϵͳ�п���ͨ��������ʾ���ԣ���ָ������һ���Կ���Ϊ����ʾ�豸��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ϵͳ����windows����󶨵��ܵ���ʾ�豸��Ŀ��������Ҫ��ָ�Կ���	*/	
DWORD PLAY_DLL_EXPORT SnPlay_GetDDrawDeviceTotalNums();

/*�� �������ò��Ŵ���ʹ�õ���ʾ�豸SnPlay_SetDDrawDevice
�� ����LONG nPort DWORD nDeviceNum
����ͨ���� ��ʾ�豸���豸�ţ������0�����ʾʹ������ʾ�豸
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ò��Ŵ���ʹ�õ��Կ���ע��ô��ڱ����ڸ��Կ�����Ӧ�ļ������ϲ�����ʾ���Ż��档*/		
BOOL PLAY_DLL_EXPORT SnPlay_SetDDrawDevice(LONG nPort,DWORD nDeviceNum);

/*�� �������ò��Ŵ���ʹ�õ���ʾ�豸������ʾ����SnPlay_SetDDrawDeviceEx *
�� ����LONG nPort, DWORD nRegionNum DWORD nDeviceNum
����ͨ���� ��ʾ���� ��ʾ�豸���豸��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ �������ò��Ŵ���ʹ�õ��Կ�������ͬSnPlay_SetDDrawDevice�� Ϊ֧��SnPlay_SetDisplayRegion������һ��������*/		
BOOL PLAY_DLL_EXPORT SnPlay_SetDDrawDeviceEx(LONG nPort,DWORD nRegionNum, DWORD nDeviceNum);;

/*�� ������ȡָ���Կ��ͼ�������ϢSnPlay_GetDDrawDeviceInfo
�� ����
DWORD nDeviceNum LPSTR lpDriverDescription DWORD nDespLen [out]LPSTR lpDriverName [out]DWORD nNameLen [out]HMONITOR *hhMonitor
��ʾ�豸���豸�ţ������0�����ʾ����ʾ�豸�� ��ʾlpDriverDescription�ѷ���ռ�Ĵ�С����λbyte�� ��ʾlpDriverName�ѷ���ռ�Ĵ�С����λbyte ��ʾ�豸��������Ϣ ��ʾ�豸���豸��
��ʾ�豸ʹ�õļ����������ͨ��Windows API ����GetMonitorInfo�����Եõ���ϸ��Ϣ�����û���λ����λ�á�
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_GetDDrawDeviceInfo(DWORD nDeviceNum, LPSTR lpDriverDescription,DWORD nDespLen,LPSTR lpDriverName , DWORD nNameLen,HMONITOR *hhMonitor);

/*�� ������ȡָ����ʾ�豸��ϵͳ��ϢSnPlay_GetCapsEx
�� ����DWORD nDDrawDeviceNum
ָ����ʾ�豸���豸�ţ������0�����ʾ����ʾ�豸��
����ֵ��ָ����ʾ�豸��ϵͳ��Ϣ	*/	
int PLAY_DLL_EXPORT SnPlay_GetCapsEx(DWORD nDDrawDeviceNum);

/*�� ����ץͼ�ص�SnPlay_SetDisplayCallBack
�� ����LONG nPort void (CALLBACK* DisplayCBFun); DisplayCBFunץͼ�ص���������˵�� nPort pBuf nSize nWidth nHeigh nStamp nType nReceaved
����ͨ���� ץͼ�ص�����������ΪNULL ͨ���� ����ͼ������ ����ͼ�����ݴ�С �������λ���� ����� ʱ����Ϣ����λ���� �������ͣ� T_YV12��T_RGB32��T_UYVY�� ���SnPlay_SetDecCallBack�궨�� ����
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE	
˵ ��������ץͼ�ص�������ע��Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ��DisplayCBFun��ΪNULL��һ�����ûص���������һֱ��Ч��ֱ�������˳����ú����������κ�ʱ����� �ص���ʱ���߳��д���, ���ܳ��ֺ�ʱ����, ��������ʱ������, Ӱ����ʾ*/
BOOL PLAY_DLL_EXPORT SnPlay_SetDisplayCallBack(LONG nPort,void (CALLBACK* DisplayCBFun) (long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp, long nType,long nReceaved));

/*�� ����ͼ������תΪBMP��ʽ SnPlay_ConvertToBmpFile
�� ����char * pBuf long nSize long nWidth long nHeight long nType char *sFileName
ץͼ�ص�������ͼ�񻺳��� ץͼ�ص�������ͼ��Ĵ�С ץͼ�ص�������ͼ���� ץͼ�ص�������ͼ��߶� ץͼ�ص�������ͼ������ Ҫ������ļ����������BMP��Ϊ�ļ���չ��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ������ץͼ�õ���ͼ�����ݱ����BMP�ļ���ת������ռ�õ�cpu��Դ���������Ҫ����ͼƬ����Ҫ����*/		
BOOL PLAY_DLL_EXPORT SnPlay_ConvertToBmpFile (char * pBuf,long nSize,long nWidth,long nHeight,long nType,char *sFileName);

/*�� ����ͼ������תΪJPEG ��ʽSnPlay_ConvertToJpegFile
�� ����char *pBuf long nSize long nWidth long nHeight long nType char *sFileName
ͼ�����ݻ��� ͼ���С ͼ���� ͼ��߶� ͼ�����ͣ�yv12�� ����·��
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ����ץͼ��ΪJPEG�ļ�, �ú���������ʾ�ص�������ʹ��, �÷��μ�SnPlay_ConvertToBmpFile	*/	
BOOL PLAY_DLL_EXPORT SnPlay_ConvertToJpegFile(char *pBuf, long nSize, long nWidth, long nHeight, long nType, char *sFileName);

/*�� ����ֱ��ץȡBMPͼ��SnPlay_GetBMP
�� ����LONG nPort PBYTE pBitmap ����ͨ����
DWORD nBufSize DWORD* pBmpSize
��С�� ��sizeof(BITMAPFILEHEADER); + sizeof(BITMAPINFOHEADER); + w * h * 4�� ����w��h�ֱ�Ϊͼ���ߡ� ����Ļ�������С ��ȡ����ʵ��bmpͼ���С
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_GetBMP(LONG nPort,PBYTE pBitmap,DWORD nBufSize, DWORD* pBmpSize);

/*�� ����ֱ��ץȡJPEGͼ��SnPlay_GetJPEG
�� ����LONG nPort PBYTE pJpeg DWORD nBufSize DWORD* pJpegSize
����ͨ���� ���JEPGͼ�����ݵ�ַ�����û����䣬����С��JPEGͼ���С�������Сw * h * 3/2�� ����w��h�ֱ�Ϊͼ���ߡ� ����Ļ�������С ��ȡ����ʵ��JPEGͼ�����ݴ�С
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE	*/	
BOOL PLAY_DLL_EXPORT SnPlay_GetJPEG(LONG nPort,PBYTE pJpeg,DWORD nBufSize, DWORD* pJpegSize);

/*�� ��������JPEGͼ������SnPlay_SetJpegQuality
�� ����long nQuality
ͼ��������������Χ0~100 0: ͼ���������, ��ץȡ��ͼ���С��С 100: ͼ���������, ��ץȡ��ͼ���С���
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ��������ץȡ��jpegͼ������, ���÷�Χ0~100, ����ʹ��75~90, �������øú���, �����Ĭ��ͼ������, ĿǰĬ��Ϊ80����Ҫ��ץͼ����ǰ���ã�������openfile֮ǰʹ��*/
BOOL PLAY_DLL_EXPORT SnPlay_SetJpegQuality(long nQuality);

/*�� ������ͼ�ص�SnPlay_RegisterDrawFun
�� ����LONG nPort void (CALLBACK* DrawFun);����ͨ���� ��ͼ�ص�����	
LONG nUser DrawFun �ص���������˵�� long nPort HDC hDc LONG nUser
�û����� ����ͨ���� �����豸�����ģ������������ʾ���ڿͻ���DC������������ �û����ݣ���������������û����ݣ�
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ����ע��һ���ص���������õ�ǰ�����device context, ����������DC�ϻ�ͼ����д�֣����ͺ����ڴ��ڵĿͻ���DC�ϻ�ͼ�������DC���Ǵ��ڿͻ�����DC������DirectDraw���Off-Screen�����DC��ע�⣬�����ʹ��overlay���棬����ӿ���Ч�������ֱ���ڴ����ϻ�ͼ��ֻҪ����͸��ɫ�Ͳ��ᱻ���ǡ� �ص���ʱ���߳��д���, ���ܳ��ֺ�ʱ����, ��������ʱ������, Ӱ����ʾ*/
BOOL PLAY_DLL_EXPORT SnPlay_RegisterDrawFun(LONG nPort, void (CALLBACK* DrawFun)(long nPort,HDC hDc,LONG nUser),LONG nUser);

/* ����˵��: ��������У��SnPlay_SetVerifyCallBack *
/* �� ����LONG nPort ����ͨ����
/* DWORD nBeginTime  У�鿪ʼʱ�䣬��λms
/* DWORD nEndTime  У�����ʱ�䣬��λms
/* void (__stdcall* funVerify); ���������ݱ��޸�ʱ�ص��ĺ���
/* DWORD nUser �û����� 
/* funVerify �ص���������˵��: 
/* long nPort  ����ͨ����
/* SNEX_FRAME_POS * pFilePos  ������Ϣ
/* DWORD bIsVideo �Ƿ���Ƶ���ݣ�1��Ƶ��0��Ƶ
/* DWORD nUser �û�����
/* SNEX_FRAME_POS���Ͷ���: 
/* long nFilePos  ������ļ�λ��
/* long nFrameNum  �����������֡��
/* long nFrameTime  �����������ʱ�䣨��Դ��ļ���ʼʱ�䣩
/* long nErrorFrameNum  ����ʱ��֡��
/* SYSTEMTIME *pErrorTime  ����ľ���ʱ�䣨�豸¼���ļ����ã�
/* long nErrorLostFrameNum ����ʱ��ʧ��֡��
/* long nErrorFrameSize ����ʱ��������ݴ�С               
/* ����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/* ˵ ����ע��һ���ص�������У�������Ƿ��޸ģ�ʵ��ˮӡ���ܡ����ڿ��Է������ݶ�ʧ�����ע�⣬��У���ڽ����ļ�������ʱ����У����Ա��뽨�ļ���������У�顣��openfile֮ǰʹ�á�*/
BOOL PLAY_DLL_EXPORT SnPlay_SetVerifyCallBack(LONG nPort, DWORD nBeginTime, DWORD nEndTime, void (__stdcall* funVerify)(long nPort, SNEX_FRAME_POS * pFilePos, DWORD bIsVideo, DWORD nUser), DWORD nUser);
		
			
/* ����˵��: ��ȡԭʼ֡���ݻص�����SnPlay_GetOriginalFrameCallBack *
/* �� ����LONG nPort ����ͨ����
/* BOOL bIsChange  �Ƿ�Ҫ�ı�ÿ֡�Ĳ���
/* BOOL bNormalSpeed  �Ƿ�Ҫ�������ٶȵõ�ԭʼ֡
/* long nStartFrameNum  ���Ҫ�ı�ԭʼ֡֡�ţ����Ǵ��ļ��Ŀ�ʼ֡�� 
/* long nStartStamp  ���Ҫ�ı�ԭʼ֡ʱ�꣬���Ǵ��ļ��Ŀ�ʼʱ��
/* [out]long nFileHeader �ļ�ͷ�汾��Ϣ������汾��ƥ�䣬���ز��ɹ�
/* void(CALLBACK *funGetOrignalFrame); ԭʼ֡�ص�����
/* long nUser �û�����
/* funGetOrignalFrame �ص���������: 
/* long nPort ����ͨ����
/* SNEX_FRAME_TYPE *frameType ����֡��Ϣ
/* long nUser  �û�����
/* SNEX_FRAME_TYPE����˵�� 
/* typedef struct{ char *pDataBuf  ����֡�׵�ַ
/* long nSize  ����֡�Ĵ�С
/* long nFrameNum  ����֡�ĸ���
/* BOOL bIsAudio  �Ƿ���Ƶ֡
/* long nReserved ���� } SNEX_FRAME_TYPE;        
/* ����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/* ˵ ���������õ�ԭʼ���ݵĻص����������Ըı�ÿ֡��ʱ���֡�ţ����ļ���֮����ã����ڽ������ļ�ƴ����һ��*/	
BOOL PLAY_DLL_EXPORT SnPlay_GetOriginalFrameCallBack(LONG nPort, BOOL bIsChange, BOOL bNormalSpeed, long nStartFrameNum, long nStartStamp, long nFileHeader, void(CALLBACK *funGetOrignalFrame) (long nPort,SNEX_FRAME_TYPE *frameType, long nUser), long nUser);
		 
/* ����˵��: ��ȡ�ļ�����ʱ���֡��SnPlay_GetFileSpecialAttr *
/* �� ����LONG nPort ����ͨ���� 
/* [out]DWORD *pTimeStamp �ļ�����ʱ��
/* [out]DWORD *pFileNum �ļ�����֡��
/* [out]DWORD *nFileHeader �ļ�ͷ��Ϣ	 
/* ����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/* ˵ �����õ��ļ�����ʱ���֡�ţ����ļ���֮����á����ϸ��ļ�һ��ʹ�ã������ļ�ƴ��*/
BOOL PLAY_DLL_EXPORT SnPlay_GetFileSpecialAttr(LONG nPort, DWORD *pTimeStamp,DWORD *pFileNum ,DWORD *nFileHeader);;
 
/* ����˵������������ֱ��������һ�ؼ�֡SnPlay_PlaySkipErrorData
/* �� ����LONG nport ����ͨ����, BOOL bSkip TRUE ��������ʱ��ֱ������һ���ؼ�֡���룻 FALSE Ѱ����һ֡���ݽ���	 
/* ����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/* ˵ ��������������д��������£���������ֻ���������������ó�TRUE*/
BOOL PLAY_DLL_EXPORT SnPlay_PlaySkipErrorData(LONG nport, BOOL bSkip);

/* ����˵�������֡��������SnPlay_CheckDiscontinueFrameNum
/* �� ����LONG nport ����ͨ����, BOOL bCheck TRUE �������֡�������ԣ�FALSE ���������֡��������	 
/* ����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/* ˵ ����������������������£����ü��󣬻�����һ���ؼ�֡����*/
BOOL PLAY_DLL_EXPORT SnPlay_CheckDiscontinueFrameNum(LONG nport, BOOL bCheck);

/*����˵������ȡ¼���ļ�����
/*����: long lPort  = player session
/*����ֵ������¼���ļ���С*/
unsigned long PLAY_DLL_EXPORT SnPlay_GetRecordSize(long lPort);

/*����˵������ʼ¼��
/*����: long lPort  = player session
/*            char * filename= name of record file*/
BOOL PLAY_DLL_EXPORT SnPlay_StartRecord(long lPort,char * filename);

/*����˵����ֹͣ¼��
/*����: long lPort  = player session*/
BOOL PLAY_DLL_EXPORT SnPlay_StopRecord(long lPort);


//*****************************************************************************
//��ʱû��ʵ�ֺ���
//*****************************************************************************

/*����˵���� ���Բ�������ϵͳ����SnPlay_GetCaps
/*�� ������
/*����ֵ��1~8λ�ֱ��ʾ������Ϣ��λ����TRUE��ʾ֧�֣���
/*SUPPORT_DDRAW SUPPORT_BLT SUPPORT_BLTFOURCC SUPPORT_BLTSHRINKX SUPPORT_BLTSHRINKY SUPPORT_BLTSTRETCHX SUPPORT_BLTSTRETCHY SUPPORT_SSE SUPPORT_MMX
/*֧��DIRECTDRAW�������֧�֣��򲥷������ܹ����Կ�֧��BLT�����������֧�֣��򲥷������ܹ����Կ�BLT֧����ɫת���������֧�֣���������ʹ�������ʽ��RGBת���Կ�BLT֧��X����С�������֧�֣�ϵͳʹ�������ʽת���Կ�BLT֧��Y����С�������֧�֣�ϵͳʹ�������ʽת���Կ�BLT֧��X��Ŵ������֧�֣�ϵͳʹ�������ʽת���Կ�BLT֧��Y��Ŵ������֧�֣�ϵͳʹ�������ʽת��CPU֧��SSEָ��,Intel Pentium3����֧��SSEָ��CPU֧��MMXָ�
/*˵ �������Բ�������Ҫ��һЩϵͳ����*/
int PLAY_DLL_EXPORT SnPlay_GetCaps();


/*����˵���� ��ȡ�����SnPlay_GetLastError
/*�� ����LONG nPort ����ͨ����
/*����ֵ�������룬���������궨��
/*˵ ������õ�ǰ����Ĵ����롣�û��ڵ���ĳ����������ʧ��ʱ�����ô˺�����ô������ϸ��Ϣ*/
DWORD PLAY_DLL_EXPORT SnPlay_GetLastError(LONG nPort);


/*����˵������ʼ��Direct����SnPlay_InitDDraw
/*�� ����HWND hWnd Ӧ�ó��������ڵľ��
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*˵ ������ʹ��vb,delphi����ʱ��ע�⣬�������ɵĶԻ������WS_CLIPCHILDREN���ڷ�񣬱���ȥ�����ַ�񣬷�����ʾ����ᱻ�Ի����ϵĿؼ�����*/
BOOL PLAY_DLL_EXPORT SnPlay_InitDDraw(HWND hWnd);


/*����˵�����ͷ�Direct����SnPlay_RealeseDDraw
/*�� ������
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_RealeseDDraw();

/*����˵���� ���ò���ʹ�õĶ�ʱ������SnPlay_SetTimerType
/*�� ����LONG nPort  ����ͨ����
/*�� ����DWORD nTimerType TIMER_1 �Ƕ�ý��ʱ�� һ��������ֻ��ʹ��16����ʱ�侫�ȸߣ�TIMER_2 �ǵȴ���ʱ����ʹ����Ŀû�����ƣ���ʱ�侫�Ƚϵͣ����Ƽ��ڸ߱��ٲ���ʱʹ�á�Ĭ�������0~15·ʹ��TIMER_1������ʹ��TIMER_2�� 
/*�� ����DWORD nReserved ��������
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_SetTimerType(LONG nPort,DWORD nTimerType,DWORD nReserved);

/*����˵������ȡ����ʹ�õĶ�ʱ������SnPlay_GetTimerType
/*�� ����LONG nPort ����ͨ����
/*������[out]DWORD *pTimerType TIMER_1��TIMER_2
/*������DWORD *pReserved ��������
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE*/
BOOL PLAY_DLL_EXPORT SnPlay_GetTimerType(LONG nPort,DWORD *pTimerType, DWORD *pReserved);


/*����˵������֡����SnPlay_OneByOneBack
/*�� ����LONG nPort ����ͨ����
/*����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
/*˵ ����ÿ����һ�ε���һ֡*/
BOOL PLAY_DLL_EXPORT SnPlay_OneByOneBack(LONG nPort);



/*�� ����ȥ��˸SnPlay_SetDeflash
�� ����
LONG nPort BOOL bDeflash
����ͨ���� TRUE��ʾ����ȥ��˸��FALSE��ʾ�����ã�Ĭ��Ϊ������
����ֵ���ɹ�����TURE��ʧ�ܷ���FALSE
˵ ���������Ƿ�ȥ��˸����, ԭ���ھ�ֹͼ�����������������, ͼ��������˸���󣨻��ˢ�»�������������ȥ��˸���ܺ���˸Ч������������ᣬͬʱҲ�ܽ�������*/
BOOL PLAY_DLL_EXPORT SnPlay_SetDeflash(LONG nPort,BOOL bDeflash);


/*�� ������ȡ��ǰ�Ƿ����OVERLAY��ʾģʽSnPlay_GetOverlayMode
�� ����LONG nPort ����ͨ����
����ֵ��0��ʾû��ʹ��OVERLAY��1��ʾʹ����OVERLAY���棻-1��ʾ����ʧ��
˵ ������鵱ǰ�������Ƿ�ʹ����OVERLAYģʽ	*/	
LONG PLAY_DLL_EXPORT SnPlay_GetOverlayMode(LONG nPort);


//************************************
// Method:    �����쳣��Ϣ�ص�,��Ҫ֪ͨ����ʱ���쳣��Ϣ
// FullName:  SnPlay_SetDecMsgCallBack

// Returns:   BOOL PLAY_DLL_EXPORT
// Parameter: long lPort	 =player session
// Parameter: CALLBACK * ExceptionMsgFun
// Parameter: long lPort	 =player session
// Parameter: int nFlag		 =�쳣���ͣ�1��ʾ¼���쳣
// Parameter: void * pUserData  =����������
// Parameter: void * pUserData	=����������
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetExceptionFilter(void (CALLBACK* ExceptionMsgFun)(long lPort, int nFlag , void *pUserData),long lPort,void *pUserData);


/*�� ������ͼ���ϻ��ƾ���
�� ����LONG nPort ����ͨ����
�� ����int ix,int iy, ���Ͻ�����
�� ����LONG lWidth,LONG lHeight�� ���ο��
�� ����unsigned char RColor,unsigned char GColor,unsigned char BColor��������ɫ
����ֵ��TRUE��ʾ�ɹ���FALSE��ʾʧ��*/
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetRectangle(LONG nPort,int ix,int iy,LONG lWidth,LONG lHeight,unsigned char RColor,unsigned char GColor,unsigned char BColor,int index);

/*�� ����ȥ���ѻ����
�� ����LONG nPort ����ͨ����
�� ����int index, ���ο�����
����ֵ��TRUE��ʾ�ɹ���FALSE��ʾʧ��*/
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_RemoveRectangle(LONG nPort,int index);

/*�� ������ȡ��ǰ�Ѳ��Ŵ�С
�� ����LONG nPort ����ͨ����
����ֵ��>0��ʾ��ǰ�Ѳ��Ŵ�С��-1��ʾʧ��*/
//************************************
LONG PLAY_DLL_EXPORT SnPlay_GetPlaySize(LONG nPort);

/*�� ������ȡ��ǰˮӡ��Ϣ
�� ����LONG nPort ����ͨ����
	   char *cWaterMask �ѽ�����ˮӡ
����ֵ��>0��ʾ��ǰ�Ѳ��Ŵ�С��-1��ʾʧ��*/
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_GetWaterMask(LONG nPort,char *cWaterMask);

/*�� ��������ˮӡ��Ϣ�ص�
�� ����LONG nPort ����ͨ����
����ֵ��>0��ʾ��ǰ�Ѳ��Ŵ�С��-1��ʾʧ��*/
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetWaterMaskCB(LONG nPort,void (CALLBACK* WaterMaskMsgFun)(char *WaterMask,void *pUserData),void *pUserData);

/*�� ��������ͼ��ֱ��ʸı�֪ͨ
�� ����LONG nPort ����ͨ����
����ֵ��>0��ʾ��ǰ�Ѳ��Ŵ�С��-1��ʾʧ��*/
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_SetResNotifyCB(LONG nPort,void (CALLBACK* ResNotifyMsgFun)(int iWidth,int iHeight,void *pUserData),void *pUserData);

/*�� ������ȡYUV����
�� ����LONG nPort ����ͨ����
�� ����unsigned char *pYUV(out) ͼ��yuv����
�� ����int nWidth(in) ͼ��ֱ��ʿ�
�� ����int nHeight(in) ͼ��ֱ��ʸ�
����ֵ��>0��ʾ��ǰ�Ѳ��Ŵ�С��-1��ʾʧ��
˵����yuv�����ڴ��С=��*��*3/2,yuv��ʽΪyuv420*/
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_GetYUVData(LONG nPort,unsigned char *pYUV,int nWidth,int nHeight);

/*�� ��������yuv
�� ����LONG nPort ����ͨ����
�� ����unsigned char *pYUV(in) ͼ��yuv����
�� ����int nWidth(in) ͼ��ֱ��ʿ�
�� ����int nHeight(in) ͼ��ֱ��ʸ�
����ֵ��>0��ʾ��ǰ�Ѳ��Ŵ�С��-1��ʾʧ��*/
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_DrawYUV(LONG nPort,unsigned char *pYUV,int nWidth,int nHeight);

/*�� ����ֹͣ����yuv
�� ����LONG nPort ����ͨ����
�� ����unsigned char *pYUV(in) ͼ��yuv����
�� ����int nWidth(in) ͼ��ֱ��ʿ�
�� ����int nHeight(in) ͼ��ֱ��ʸ�
����ֵ��>0��ʾ��ǰ�Ѳ��Ŵ�С��-1��ʾʧ��*/
//************************************
BOOL PLAY_DLL_EXPORT SnPlay_StopDrawYUV(LONG nPort);


#endif