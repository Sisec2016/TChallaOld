#ifndef _SNPLAYEXDEF_HPP
#define _SNPLAYEXDEF_HPP

#include "windows.h"

typedef signed char  int8_t;
typedef signed short int16_t;
typedef signed int   int32_t;
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;

#ifdef _WIN32
typedef signed __int64   int64_t;
typedef unsigned __int64 uint64_t;
#else 
/* other OS */
typedef signed long long   int64_t;
typedef unsigned long long uint64_t;
#endif 


#define PLAY_DLL_EXPORT	__declspec(dllexport)			//����dll export
//#define PLAY_DLL_EXPORT	 


enum PLAY_EX_STATUS {EX_PLAYBACK=-20,EX_STOP = -19, EX_PAUSE = -18, EX_PLAY_ONEBYONE = -17, EX_SLOW16X = -16, EX_SLOW8X = -8, 
                     EX_SLOW4X = -4, EX_SLOW2X = -2,EX_PLAY = 1, EX_PLAY2X = 2, EX_PLAY4X = 4, EX_PLAY8X = 8, 
					 EX_PLAY16X = 16};

enum PLAY_EX_STREAM {EX_STREAM,EX_FILE_STREAM, EX_FILENAME_PLAY,EX_REAL_STREAM};//EX_STREAM:ʵʱ��,�л���;EX_FILE_STREAM���ļ���;EX_REAL_STREAM:�޻���

enum PLAY_EX_DATATYPE {EX_YV12,EX_RGB24};

//-----------------------------------------------------------------------------
//�ļ�������Ϣ
//-----------------------------------------------------------------------------
struct H264_PES_FILE_PARAM
{
	int videoTotalFrame;
	int curPlayPos;
	int fbs;
};

struct H264_PARAM
{
	uint8_t head[8];	//��ͷ8���ַ�A       8 
	int  version;		//�汾				 4	 ����Ϊ1��Ϊ��֡�ʲ��ţ��汾��Ϊ2��Ϊ��ʱ�������	
	int64_t idx;		//����				 8
	int  knd;			//0=H264��Ƶ��1=G711.A(1ch,8k,16bit)	 2=unsigned pcm(1ch,8k,8bit)  3=G711 ulaw(1ch,8k,16bit)				
	int  fbs;			//֡�ʻ������		 4			
	time_t curtime;		//������ʱ��		 8
	int ptsSetup;		//pts����ֵ			 4	
	int dtsSetup;		//dtsSetup			 4
	int64_t pts;        //pts��Ϣ            8
	int64_t dts;        //dts��Ϣ			 8	
	int  nal_len;		//����������		 4	

	H264_PARAM(){
		version=1;
		for(int i=0;i<8;i++) head[i]=0x41;
	}
	
};
const int H264_PARAM_LEN=sizeof(H264_PARAM);	//window =72��0x48

struct H264_VAO
{	
	H264_PARAM param;	
	uint8_t *	data;
};

typedef struct{ 
	long nWidth;     //�������λ���ء��������Ƶ������Ϊ0��
	long nHeight;    //����ߡ��������Ƶ������Ϊ0��
	long nStamp;     //ʱ����Ϣ����λ����
	long nType;      //�������ͣ�T_AUDIO16��T_RGB32�� T_YV12�� 
	long nFrameRate; //����ʱ������ͼ��֡�� 
	DWORD dwFrameNum;//֡�� 
}SNEX_FRAME_INFO;

typedef struct{ 
	char *pDataBuf;
	long nSize;
	long nFrameNum;
	BOOL bIsAudio;
	long nReserved;
}SNEX_FRAME_TYPE;

typedef struct{ 
	long nFilePos;
	long nFrameNum;
	long nFrameTime;
}SNEX_FRAME_POS,*PSNEX_FRAME_POS;



#endif