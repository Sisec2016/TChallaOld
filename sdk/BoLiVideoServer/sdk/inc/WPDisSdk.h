#ifndef _WP_DISPLAY_SDK_H_
#define _WP_DISPLAY_SDK_H_

#define DLL_EXPORT extern "C" _declspec(dllexport)

#define MAX_DEVICE			128

#define WP_DISPLAY_NOERROR		0x00c8		//û�д���
#define WP_DISPLAY_INITD3D_FAILED	0x00c9		//����d3d�豸ʧ��
#define WP_DISPLAY_INITDIRECTDRAW_FAILED 0x00ca //����directdraw�豸ʧ��
#define WP_DISPLAY_DEVICE_MAX	0x00cb//������ʾ�豸�ĸ����Ѵﵽ���
#define WP_DISPLAY_D3DDEVICE_NOT_EXIST	0x00cc//�������ŵ�D3d��ʾ���󲻴���          204
#define WP_DISPLAY_DIRECTDRAW_NOT_EXIST	0x00cd//�������ŵ�directdraw��ʾ���󲻴���
#define WP_DISPLAY_DEVICE_INVALID_INDEX 0x00ce//��ʾ�豸�������ŷǷ�
#define WP_DISPLAY_DATA_NULL	0x00cf//��ʾ������Ϊ��
#define WP_DISPLAY_D3DDEVICE_HAS_EXIST 0x00d0 //�������ŵ�D3D�豸�Ѿ�������
#define WP_DISPLAY_PARAM_INVALID	0x00d1	//��ʾ�Ĳ����Ƿ�
#define WP_DISPLAY_CREATESURFACE_FAIL	0x00d2	//������ʾ��ʧ��

#define WP_CAPTURE_NOERROR				600		//û�д���
#define WP_CAPTURE_BUF_NULL				601		//���ݻ���Ϊ��	
#define WP_CAPTURE_PATH_NULL			602		//�ļ���·��Ϊ��
#define WP_CAPTURE_CREAT_FILE_FAILED	603		//�����ļ�ʧ��



//���ݵĸ�ʽ
#define DATA_FORMAT_YUYV				1		//YUYV��ʽ������
#define DATA_FORMAT_RGB24				2		//RGB24��ʽ������

//ץͼ�Ƿ����ʱ���ǩ
typedef enum{
	PIC_ADD_TIME = 1001,
	PIC_NO_TIME = 1002,
}PicTimeLabel;

//for display
DLL_EXPORT int WP_DISPLAY_InitSdk();
DLL_EXPORT int WP_DISPLAY_CleanupSdk();
DLL_EXPORT int WP_DISPLAY_InitDevice(HWND hWnd);	
DLL_EXPORT int WP_DISPLAY_ReleaseDevice(int hWndId);																
DLL_EXPORT int WP_DISPLAY_CreateOneSurface(int hWndId, int width, int height);	//							
DLL_EXPORT int WP_DISPLAY_FreeOneSurface(int hWndId);														
DLL_EXPORT int WP_DISPLAY_DisplayFrame(int hWndId, BYTE *pVData);											
DLL_EXPORT int WP_DISPLAY_SetShowText(int hWndId, char *text);

//DLL_EXPORT int WP_DISPLAY_SetShowMode(int hWndId, int showMode);											//Set the show mode, the max channels count is showMode*showMode.

//for listen play audio
DLL_EXPORT int WP_DISPLAY_PlayAudio(unsigned char *ostream);														//Play the audio data.

//for capture picture
DLL_EXPORT int WP_DISPLAY_CaptureJPG(unsigned char *pImageBuf, int width, int height, int dataFormat, char *fileName, char *pImagePath);     //Save the decoded data to jpg image.
                                                                                                                          //pImageBuf: the decoded data
                                                                                                                          //width:     the width of the image
                                                                                                                          //height:    the height of the image
                                                                                                                          //dataFormat:the format of the decoded data( DATA_FORMAT_YUYV / DATA_FORMAT_RGB24 )
                                                                                                                          //fileName:  the path and filename of the file
DLL_EXPORT int  WP_DISPLAY_CaptureBMP(unsigned char *pImageBuf, int width, int height, int dataFormat, char *fileName, char *pImagePath, PicTimeLabel label);    //Save the decoded data to bmp image
                                                                                                                          //label:     whether add the time to the picture.

#endif