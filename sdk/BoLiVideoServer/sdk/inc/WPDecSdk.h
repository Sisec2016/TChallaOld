#ifndef _WP_DECODE_SDK_H_
#define _WP_DECODE_SDK_H_

#define DLL_EXPORT extern "C" _declspec(dllexport)

#define MAX_DECODE 0x0100

typedef enum{
	MPEG4 = 0,
	H264 = 264,
}ENCODE_TYPE;

#define WP_DECODE_NOERROR			0x012c		//û�д���
#define WP_DECODE_INITVIDEO_FAILED	0x012d		//��ʼ����Ƶ������ʧ��
#define WP_DECODE_VIDEODEC_NOT_EXIST 0x012e		//��Ƶ������������
#define WP_DECODE_VIDEODEC_MAX			  0x012f	//������Ƶ�������ĸ����Ѵﵽ���ֵ
#define WP_DECODE_VIDEODEC_INVALID_INDEX	0x0130	//��Ƶ�������������ŷǷ�
#define WP_DECODE_VIDEOBUF_NULL				0x0131	//δ�������Ƶ����Ϊ��
#define WP_DECODE_AUDIODEC_EXIST			0x0132	//��Ƶ�������Ѿ�������
#define WP_DECODE_AUDIOBUF_NULL				0x0133	//δ�������Ƶ����Ϊ��
#define WP_DECODE_AUDIODEC_NOT_EXIST		0x0134	//��Ƶ������������
#define WP_DECODE_INIT_FAILED				0x0135	//��ʼ����������SDKʧ��
#define WP_DECODE_VIDEO_PARAM_INVALID       0x0136  //��Ƶ�Ĳ����Ƿ�

//****************************************************************
//Function:	int WP_DECODE_InitSdk()
//Description:��ʼ����������SDK
//return: �ɹ���WP_DECODE_NOERROR��ʧ���򷵻ش�����Ϣ
//****************************************************************
DLL_EXPORT int WP_DECODE_InitSdk();

//****************************************************************
//Function:	int WP_DECODE_CleanupSdk()
//Description:�ͷŽ�������SDK
//return: �ɹ���WP_DECODE_NOERROR��ʧ���򷵻ش�����Ϣ
//****************************************************************
DLL_EXPORT int WP_DECODE_CleanupSdk();

//****************************************************************
//Function:	int WP_DECODE_InitVideoDec(int width, int height, int encodeFormat)
//Description:������Ƶ������
//Input: width �������Ŀ�
//Input: height �������ĸ�
//Input: encodeFormat �������ı��뷽ʽ���μ�ENCODE_TYPE
//return: �ɹ��򷵻ؽ������������ţ�ʧ���򷵻ش�����Ϣ
//****************************************************************
DLL_EXPORT int WP_DECODE_InitVideoDec(int width, int height, int encodeFormat);								

//****************************************************************
//Function:	int WP_DECODE_DecVideo(int decodeIndex, unsigned char *istream, int istream_size, unsigned char *ostream)
//Description:������Ƶ����
//Input: decodeIndex ��������������
//Input: istream δ�������Ƶ����
//Input: istream_size δ�������Ƶ���ݵĳ���
//Output: ostream ��������Ƶ����
//return: �ɹ��򷵻�WP_DECODE_NOERROR��ʧ���򷵻ش�����Ϣ
//****************************************************************
DLL_EXPORT int WP_DECODE_DecVideo(int decodeIndex, unsigned char *istream, int istream_size, unsigned char *ostream);								

//****************************************************************
//Function:	int WP_DECODE_DestroyVideoDec(int decodeIndex)
//Description:������Ƶ������
//Input: decodeIndex ��������������
//return: �ɹ��򷵻�WP_DECODE_NOERROR��ʧ���򷵻ش�����Ϣ
//****************************************************************
DLL_EXPORT int WP_DECODE_DestroyVideoDec(int decodeIndex);

//****************************************************************
//Function:	int WP_DECODE_InitAudioDec()
//Description:������Ƶ������
//return: �ɹ��򷵻�WP_DECODE_NOERROR��ʧ���򷵻ش�����Ϣ
//****************************************************************
DLL_EXPORT int WP_DECODE_InitAudioDec();

//****************************************************************
//Function:	int WP_DECODE_DecAudio(unsigned char *istream, int istream_size, unsigned char *ostream)
//Description:������Ƶ����
//Input: istream δ�������Ƶ����
//Input: istream_size δ�������Ƶ���ݵĳ���
//Output: ostream ��������Ƶ����
//return: �ɹ��򷵻�WP_DECODE_NOERROR��ʧ���򷵻ش�����Ϣ
//****************************************************************																		
DLL_EXPORT int WP_DECODE_DecAudio(unsigned char *istream, int istream_size, unsigned char *ostream);	
		
//****************************************************************
//Function:	int WP_DECODE_DestroyAudioDec()
//Description:������Ƶ������
//return: �ɹ��򷵻�WP_DECODE_NOERROR��ʧ���򷵻ش�����Ϣ
//****************************************************************
DLL_EXPORT int WP_DECODE_DestroyAudioDec();																		

#endif