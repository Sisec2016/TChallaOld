#ifndef NETCLIENTTYPES_H
#define NETCLIENTTYPES_H

#include "GlobalTypes.h"

#ifdef WIN32
#else
#define __stdcall
#endif

#define LEN_8   8
#define LEN_16  16
#define LEN_32  32
#define LEN_64  64
#define LEN_128 128
#define LEN_256 256
#define LEN_1300 1300 //����һ��Э�鲻����ȫ���͵�Э�飬�����ַ������ֶθ���������65�ֽ�����MAX��1300/65 = 20.ʣ��140�ֽڱ�������int�ͱ���

#define TD_FALSE 0
#define TD_TRUE  1


#define TD_NULL                 0L
#define TD_NULL_PTR             TD_NULL

#define TD_SUCCESS              0
#define TD_FAILURE              (-1)

#define  TD_LITTLE_ENDIAN       1234      
#define  TD_BIG_ENDIAN          4321      


#ifdef _MSC_VER
typedef __int64                 TD_S64;
typedef unsigned __int64        TD_U64;
#endif

#if defined __INTEL_COMPILER || defined __GNUC__
typedef long long               TD_S64;
typedef unsigned long long      TD_U64;
#endif

#define MAX_LOCAL_CHANNEL_NUM	32	
#define MAX_DIGIT_CHANNEL_NUM	32
#define	MAX_CHANNEL_NUM		(MAX_LOCAL_CHANNEL_NUM + MAX_DIGIT_CHANNEL_NUM)	   //֧��3511
#define MAX_TOTAL_CHANNEL_NUM	MAX_CHANNEL_NUM

#define MAX_CONNECTION		32
#define MAX_PORT_NUM        64
#define MAX_DOWNLOAD_NUM    5
#define MAX_COM_NUM			16	   //��󴮿���
#define MAX_INTERTALK_NUM	1      //���˫��Խ���
#define MAX_PICTURECHANNEL_NUM  	1      //���ͼƬͨ����
#define MAX_CAPTURECHANNEL_NUM  	1      //���ץ��ͨ����
#define MAX_TRACECHANNEL_NUM        1


#define MAX_RECV_CHANNEL    1024
#define MAX_ENCODER         1024
#define LENGTH_RECV_ORDER   1024

#define LENGTH_USER_NAME_BASE64		50
#define LENGTH_PASSWORD_BASE64		50

#define LENGTH_USER_NAME	16
#define LENGTH_PASSWORD		16
#define LENGTH_CHN_TITLE    32
#define LENGTH_CHANNEL_TITLE  64
#define LENGTH_DEVICE_NAME  32
#define LENGTH_IPV4			16	
#define LENGTH_IPV6			32
#define LENGTH_SUB_MASK		16


//connect mode
#define NETMODE_TCP     1   //Tcp connect
#define NETMODE_UDP     2   //Udp connect
#define NETMODE_MC      3   //Multicast connect
#define NVS_ACTIVE      4   //Positive Mode
#define NETMODE_P2P		5   //P2P connect

//Video resolution
#define QCIF			0   //QCif 			176*144
#define HCIF			1   //HCif			352*144	
#define FCIF			2	//Cif			352*288	
#define HD1				3	//HD1			720*288
#define FD1				4	//D1			720*576
#define MD1				5	//MD1			720*288
#define QVGA			6   //QVGA			320x240
#define VGA				7   //VGA			640*480
#define HVGA			8	//HVGA			640*240
#define HD_720P			9   //720p			1280*720
#define HD_960P			10	//960P			1280*960
#define HD_200W			11  //200W			1600*1200
#define HD_1080P		12	//1080P			1920*1080
#define HD_QXGA			13	//QXGA			2048*1536
#define QHD				0x100	//QHD		960*540
#define VZ_960H			0x200	//960H		960*576
#define VZ_5MA			0x300	//500W(1)	2448*2048
#define VZ_5M			0x400	//500W(2)	2560*1920
#define VZ_QSXGA		0x500	//500W(3)	2560*2048

//��Ƶ��ת
#define VZ_QCIF_REVERSE			(0x100000+QCIF)
#define VZ_HCIF_REVERSE			(0x100000+HCIF)
#define VZ_FCIF_REVERSE			(0x100000+FCIF)
#define VZ_HD1_REVERSE			(0x100000+HD1)
#define VZ_FD1_REVERSE			(0x100000+FD1)
#define VZ_MD1_REVERSE			(0x100000+MD1)
#define VZ_QVGA_REVERSE			(0x100000+QVGA)
#define VZ_VGA_REVERSE			(0x100000+VGA)
#define VZ_HVGA_REVERSE			(0x100000+HVGA)
#define VZ_HD_720P_REVERSE		(0x100000+HD_720P)
#define VZ_HD_960P_REVERSE		(0x100000+HD_960P)
#define VZ_HD_200W_REVERSE		(0x100000+HD_200W)
#define VZ_HD_1080P_REVERSE		(0x100000+HD_1080P)
#define VZ_HD_QXGA_REVERSE		(0x100000+HD_QXGA)
#define VZ_QHD_REVERSE			(0x100000+QHD)
#define VZ_VZ_960H_REVERSE		(0x100000+VZ_960H)
#define VZ_VZ_5MA_REVERSE		(0x100000+VZ_5MA)
#define VZ_VZ_5M_REVERSE		(0x100000+VZ_5M)
#define VZ_VZ_QSXGA_REVERSE		(0x100000+VZ_QSXGA)

//Stream type
#define MAIN_STREAM   0           //Basic stream(hight quality)
#define SUB_STREAM    1           //Extended stream(low bitrate)
#define FLAG_THREE_STREAM  256		 //������
#define FLAG_CONID_THREE_STREAM		8 //��λ��ʶ������

#define LAN_VIDEO MAIN_STREAM     //for old compatible
#define WAN_VIDEO SUB_STREAM    

//Device type
#define NVS_T       0           //T serials NVS
#define NVS_S       1           //S serials NVS
#define NVS_TPLUS   2           //T+ serials NVS

//Product Model
#define TC_NVSS					0x0000
#define TC_NS621S				0x0010			
#define TC_NS621S_USB			0x0011			
#define TC_NS224S				0x0020			
#define TC_NC621S				0x0030			
#define TC_NC8000S				0x0040			
#define TC_NC8001S				0x0041			
#define TC_NC8100S				0x0042			
#define TC_NC8101S				0x0043			
#define TC_NC8200S				0x0044			
#define TC_NC8700S2				0x0045
#define	TC_NC9100S1_MP_IR       0x0046	
#define TC_NC8250				0x0050			
#define TC_NC9010S2_MP			0x0051			
#define TC_NC9000S2_2MP			0x0052			
#define TC_NC9010N1_2MP			0x0053			
#define TC_NC9000S3_3MP			0x0054			
#define TC_NH9106N1_2MPIR		0x0055			
#define	TC_NS921_N1_2MP			0x0056	
#define	TC_NS921S3_HD_V1        0x0056			
#define TC_CC9118_MP_E			0x0057			
#define TC_NH9206N1_MPIR_IVS	0x0058			
#define TC_NC9100S3_3MP_IR30    0x0059          
#define TC_NT9054S2_MPIR		0x005A	
#define	TC_NC9000S3_2MP_E       0x005B			
#define	TC_NC9200S3_MP_E_IR15   0x005C
#define TC_NH9206S3_2MP_IVS		0x005D	
#define	TC_NC9000S3_MP_E        0x005E
#define TC_NS621S2				0x0060			
#define TC_NS622S2				0x0061			
#define TC_NS324S2				0x0062			
#define TC_NS628S2 				0x0064	
#define	TC_FS0013ERS_HD         0x0070
#define TC_NC9100S3E_MP_IR30	0x0080
#define TC_NC9000S3E_MP			0x0081
#define TC_NC9200S3E_MP_IR		0x0082
#define TC_NC9100S3E_2MP_IR30	0x0083
#define TC_NC9000S3E_2MP		0x0084
#define TC_NC9200S3E_2MP_IR		0x0085
#define TC_NC921S3E_MP_HD_C		0x0086
#define TC_NH9406S3E_MPIR       0x0087
#define TC_NH9406S3E_2MPIR		0x0088
#define TC_NC9320S3E_2MP_E		0x0090

#define TC_NC9010I_2MP			0x00A1			
#define TC_NC9000I_5MP			0x00A2			
#define TC_21X_R2				0x00A3			
#define TC_21X_R3				0x00A4			
#define TC_21X_R5				0x00A5
#define TC_218_T5	            0x00A8
#define	TC_218_T3H				0x00A9	
#define	TC_217_T5				0x00AA	
#define	TC_217_T3H				0x00AB	
//end

#define TC_2816AN_SH			0x0100			
#define TC_2808AN_S_3511		0x0110			
#define TC_2816AN_SD			0x0120			
#define TC_2816AN_SD_E          0x0121			
#define TC_2808AN_S_3515		0x0130			
#define TC_2804AN_MX			0x0131			
#define TC_2816AN_S				0x0140			
#define TC_H802BHX_T			0x0141			
#define TC_2832AN_SS            0x0142			
#define TC_H804BE_HD            0x0143			
#define TC_1002S2_3C			0x0150			
#define TC_H804N_HD				0x0151			
#define	TC_2802AN_SDI			0x0160			
#define TC_H908NC_H_V50			0x0161			
#define TC_2800AN_SF_L_H		0x0170			
#define TC_2800AN_SF_H			0x0171			
#define TC_2804AN_SA			0x0172			
#define TC_2800AN_SF_L			0x0173			
#define TC_2800AN_SF			0x0174			
#define TC_H804BE_P				0x0175	
#define TC_2808AN_SF_L			0x0176
#define	TC_2804AN_SQ        	0x0177

#define TC_2800AN_R16_S2		0x017C
#define	TC_2804AN_M				0x017D
#define TC_2800AN_R4_S1			0x017E
#define TC_2800AN_R4_S2			0x017F
#define TC_2800AN_R8_S2			0x017F

#define TC_H804N_HD_P			0x0180
#define TC_2800AN_R16_S2_V2_0   0x0181
#define TC_2800AN_R16_S4	    0x0181
#define TC_2800AN_R32_S4        0x0181

#define TC_2816AN_SR_V2_0		0x0182
#define TC_2832AN_SR_V2_0		0x0182

#define TC_ND921S2_MP			0x0400			
#define	TC_ND921S2_2MP			0x0410			
#define	TC_ND921S2_SDI			0x0411			
#define	TC_2804AN_SDI			0x0500	


//Encode type
#define H263		11
#define H264		21
#define MP4			31
#define MJPEG		41

//	SendStringToServer
#define SEND_STRING_CMD		0
#define SEND_STRING_DATA	1
#define SEND_UTF8_STRING	2

//H264 Decod mode
#define H264DEC_DECTWO	0		//decode 2 field
#define H264DEC_DECTOP	1		//decode top field ��low CPU cost��

//Message define
#define WCM_RECVMESSAGE         1   //Received string
#define WCM_ERR_ORDER           2   //Occur error in command socket
#define WCM_ERR_DATANET         3   //Occur error in data socket
#define WCM_TIMEOUT_DATANET     4   //Process stream timeout
#define WCM_ERR_PLAYER          5   //Occur error in player
#define WCM_ERR_USER            6   //User define error
#define WCM_LOGON_NOTIFY        7   //Logon notify
#define WCM_VIDEO_HEAD          8   //Received video head
#define WCM_VIDEO_DISCONNECT    9   //the connection were disconnect by mediacenter

//Message of Mediacenter
#define WCM_CLIENT_CONNECT      10  //There a client connected to Mediacenter
#define WCM_CLIENT_DISCONNECT   11  //A client disconnected from Mediacenter
#define WCM_CLIENT_LOGON        12  //A client logon/logogg the Mediacenter

#define WCM_RECORD_ERR          13  //Occur when recording file

//Directory Service Mode
#define WCM_DSM_REGERR          14  //Error on proxy regist to Directory server
#define WCM_DSM_ENCODERADD      15  //A NVS regist on the proxy
#define WCM_DSM_ENCODERDEL      16  //A NVS's regist connection disconnected.
//#define	WCM_DSM_ENCODERCHANGE	28	// A NVS'S IP changed.

//Message of Download logfile
#define WCM_LOGFILE_FINISHED    17  //When logfile download finished

//Message of query file
#define WCM_QUERYFILE_FINISHED  18  //Query finished record files

#define WCM_DWONLOAD_FINISHED   19  //Download finished
#define WCM_DWONLOAD_FAULT		20  //Download fault
#define WCM_REBUILDINDEX        22  //Finished of rebuild index file

//Message of talk
#define WCM_TALK				23  //Begin to talk

//Message of DiskManager
#define WCM_DISK_FORMAT_PROGRESS	24
#define WCM_DISK_FORMAT_ERROR		25
#define WCM_DISK_PART_ERROR			26

//Message of Backup Kernel
#define	WCM_BUCKUP_KERNEL			27

//Message of LocalstoreClearDisk
#define	WCM_LOCALSTORE_PROGRESS		28
#define WCM_DOWNLOAD_INTERRUPT		29	//  Download interrupt    
#define WCM_QUERYLOG_FINISHED		30  //	Query finished log

#define WCM_INTERTALK_READY			31	//	Intertalk is ready for now ...
#define WCM_CONTROL_DEVICE_RECORD	32	//	Control device record (start, stop, package)

#define WCM_RECORD_OVER_MAX_LIMIT	33	//	The size of record file is too big, and we should start to capture a new file.
#define WCM_ERR_DATANET_MAX_COUNT	34	//	Max DataNet

#define WCM_CDBURN_STATUS			35
#define WCM_NEED_DECRYPT_KEY		36	//	Need decrypt key for video
#define WCM_DECRYPT_KEY_FAILED		37	//	decrypt key is not matched
#define WCM_DECRYPT_SUCCESS			38	//	decrypt success

#define WCM_ERR_DIGITCHANNEL_NOT_ENABLED	39	//	The digital channel is not enabled
#define WCM_ERR_DIGITCHANNEL_NOT_CONNECTED	40	//	The digital channel is not connected

#define WCM_ENCRYPT_CLEARED			41   //	clear encrypt
#define WCM_FTP_UPDATE_STATUS       42   //FTP_UPDATE_STATUS
#define	WCM_BUCKUP_IMAGE			43
#define WCM_REBUILDINDEX_PROGRESS   44   //rebuild index file progress

#define	WCM_ILLEGAL_RECORD			45   //record notify when there is illegal patking

#define WCM_QUERY_ATMFILE_FINISHED  46  //Query ATM record files finished

#define WCM_AUTOTEST_INFO			47  //�Զ�������@130109

#define WCM_LASTERROR_INFO			48	//�豸���صĴ�����

#define	WCM_LOCALSTORE_LOCK_FILE	49  //�ļ��ӽ���

#define WCM_DISK_QUOTA				50	//�������

#define WCM_CONNECT_INFO			51	//������Ϣ

#define WCM_USER_CHANGE             100          //�û���Ϣ�ı�
#define WCM_UNSUPPORT_STREAM        101          //�豸��֧�ָ�·����
#define WCM_BROADCAST_MSG			102          //ͨ�ù㲥��Ϣ



//IPC 3MP
#define PARA_CHECKBADPIXEL_STATUS           196     //������״̬
#define PARA_DEVICE_STATE                   197     //�豸ʵʱ״̬
#define PARA_CHECKIRIS_STATUS               198     //��Ȧ���״̬

//Number of Show Video
#define MAX_DRAW_NUM	2
#define MAX_OSDTYPE_NUM         10

//User 
#define AUT_BROWSE            1     //Only can preview video
#define AUT_BROWSE_CTRL       2     //Can preview and control device
#define AUT_BROWSE_CTRL_SET   3     //Preview, control device, modify settings
#define AUT_ADMIN             4      //Super user, No.0 user is super user,
                             //User name is Admin, which can not be modified,
                             //Can add, delete, modify user's authority



typedef int						ALARMTYPE;
#define ALARM_VDO_MOTION		0
#define ALARM_VDO_REC			1
#define ALARM_VDO_LOST			2
#define ALARM_VDO_INPORT		3
#define ALARM_VDO_OUTPORT		4
#define ALARM_VDO_COVER 		5
#define ALARM_VCA_INFO			6			//	VCA������Ϣ
#define ALARM_AUDIO_LOST		7
#define ALARM_EXCEPTION		    8

//Logon state

#define LOGON_DSMING       3    //DSM��Directory Sevices Mode��connecting
#define LOGON_RETRY        2    //Retry
#define LOGON_SUCCESS      0    //Logon successfully
#define LOGON_ING          1    //Being logon
#define LOGON_FAILED       4   //Fail to logon
#define LOGON_TIMEOUT      5   //Logon timeout
#define NOT_LOGON          6   //Not logon
#define LOGON_DSMFAILED    7   //DSM connection failure
#define LOGON_DSMTIMEOUT   8   //DSM connection 

//Player state

#define    PLAYER_STOP          0    //Not require to play
#define    PLAYER_WAITTING      0x01 //Require to play but not play, waiting for data
#define    PLAYER_PLAYING       0x02 //Playing
#define    PLAYER_CARDWAITTING  0x04 //Require to hardware decode
#define    PLAYER_CARDPLAYING   0x08  //Being hardware decode output



//PAL/NTSC
// enum VIDEO_NORM
// {
//     VIDEO_MODE_PAL    = 0x00,
//     VIDEO_MODE_NTSC   = 0x01,
//     VIDEO_MODE_AUTO   = 0x02
// };
typedef int VIDEO_NORM;
#define VIDEO_MODE_PAL 0x00
#define VIDEO_MODE_NTSC 0x01
#define VIDEO_MODE_AUTO 0x02

//Character overlay type
// enum
// {
//     OSDTYPE_TIME      = 0x01,   //Overlay time
//     OSDTYPE_TITLE     = 0x02,   //Overlay character string
//     OSDTYPE_LOGO      = 0x04    //Overlay mark
// };

#define OSDTYPE_TIME	0x01
#define OSDTYPE_TITLE	0x02
#define OSDTYPE_LOGO	0x04
#define OSDTYPE_ITS		0x05

//Image property
// enum
// {
//     BRIGHTNESS = 0,         //Brightness
//     CONTRAST   = 1,         //Contrast
//     SATURATION = 2,         //Saturation
//     HUE        = 3          //Hue
// };
#define BRIGHTNESS 0
#define CONTRAST   1
#define SATURATION 2
#define HUE        3

//Prefer mode
// enum
// {
//     PRE_VDOQUALITY = 0,     //Video quality prefer
//     PRE_FRAMERATE  = 2      //Framerate prefer
// };
#define PRE_VDOQUALITY 0
#define PRE_FRAMERATE  2

//Stream encode type
// enum
// {
//     NO_STREAM   = 0,    //Null
//     ONLY_VIDEO  = 1,    //Video stream
//     ONLY_AUDIO  = 2,    //Audio stream
//     VIDEO_AUDIO = 3     //Video and audio stream
// };
#define NO_STREAM  0
#define ONLY_VIDEO 1
#define ONLY_AUDIO 2
#define VIDEO_AUDIO 3

// enum
// {
//     DISABLE     = 0,
//     ENABLE      = 1
// };

#define  DISABLE 0
#define  ENABLE  1
// enum
// {
//     LOW         = 0,
//     HIGH        = 1
// };
#define LOW 0
#define HIGH 1

//Talk
//enum
//{
//    TALK_BEGIN_OK       = 0,    //Start talk successfully
//    TALK_BEGIN_ERROR    = 1,   //Fail to start talk
//    TALK_ERROR          = 2,    //Talk error
//    TALK_END_OK         = 3
//};

#define TALK_BEGIN_OK			0
#define TALK_BEGIN_ERROR		1
#define TALK_ERROR				2
#define TALK_END_OK				3

//enum
//{
//    TALK_STATE_NO_TALK      = 0,
//    TALK_STATE_ASK_BEGIN    = 1,
//    TALK_STATE_TALKING      = 2,
//    TALK_STATE_ASK_STOP     = 3,
//    TALK_STATE_RESUME       = 4         //  2010-4-26-16:21 @yys@,  �����Զ��ָ��Խ�������
//
//};

#define TALK_STATE_NO_TALK			0			//	û�жԽ�
#define TALK_STATE_ASK_BEGIN		1			//	�Ѿ�����ʼ�Խ�
#define TALK_STATE_TALKING			2			//	���ڶԽ�
#define TALK_STATE_ASK_STOP			3			//	�Ѿ�����ֹͣ�Խ�
#define TALK_STATE_RESUME			4			//  2010-4-26-16:21 @yys@,	�����Զ��ָ��Խ�������

//Core remote upgrade
// enum
// {
//     PRO_UPGRADE_OK      = 0,    // Remote upgrade success
//     PRO_UPGRADE_ERROR   = -1    // Remote upgrade failure
// };
#define  PRO_UPGRADE_OK 0
#define  PRO_UPGRADE_ERROR -1
#define  PRO_UPGRADE_READY -2

// enum
// {
//     WEB_UPGRADE_OK      = 0,    // Remote upgrade success
//     WEB_UPGRADE_ERROR   = -1    // Remote upgrade failure
// };
#define WEB_UPGRADE_OK 0
#define WEB_UPGRADE_ERROR -1
#define WEB_UPGRADE_READY -2
//����IE
#define WEB_UPGRADE_REDAY	WEB_UPGRADE_READY

//��Ƶ�������豸����
typedef int							PARATYPE;
#define PARA_VIDOEPARA				0
#define PARA_VIDEOPARA				0 
#define PARA_VIDEOPARA				0 
#define PARA_VIDEOQUALITY			1     
#define PARA_FRAMERATE				2     
#define PARA_IFRAMERATE				3     
#define PARA_STREAMTYPE				4     
#define PARA_MOTIONDETECTAREA		5
#define PARA_THRESHOLD          	6    
#define PARA_MOTIONDETECT			7     
#define PARA_OSDTEXT				8    
#define PARA_OSDTYPE				9     
#define PARA_ALMINMODE				10    
#define PARA_ALMOUTMODE				11    
#define PARA_ALARMINPUT				12    
#define PARA_ALARMOUTPUT			13    
#define PARA_AlMVDOCOVTHRESHOLD		14    
#define PARA_ALMVIDEOCOV			15    
#define PARA_RECORDCOVERAREA		16    
#define PARA_RECORDCOVER			17    
#define PARA_ALMVDOLOST				18    
#define PARA_DEVICETYPE				19    
#define PARA_NEWIP					20
#define PARA_AUDIOCHN				21    
#define PARA_IPFILTER				22    
#define PARA_COVERAREA				23    
#define PARA_VIDEOHEADER			24
#define PARA_VIDEOSIZE				25    
#define PARA_BITRATE				26    
#define PARA_DATACHANGED			27
#define PARA_PARSECHANGED			28   

#define PARA_APPIFRAMERATE			29    
#define PARA_APPFRAMERATE			30    
#define PARA_APPVIDEOQUALITY		31    
#define PARA_APPVIDEOSIZE			32    
#define PARA_APPSTREAMTYPE			33    
#define PARA_APPBITRATE				34    
#define PARA_APPCOVERAREA			35    
#define PARA_APPVIDEOHEADER			36    

#define PARA_REDUCENOISE			37    
#define PARA_BOTHSTREAMSAME			38    
#define PARA_PPPOE					39    

#define PARA_ENCODETYPE				40    
#define PARA_PREFERMODE				41    

#define PARA_LOGFILE				42    
#define PARA_SETLOGOOK				43    

#define PARA_STORAGE_SCHEDULE   	44   
#define PARA_STORAGE_TASKSTATE		45    
#define PARA_STORAGE_ALARMSTATE		46    
#define PARA_STORAGE_PRERECORD		47    
#define PARA_STORAGE_RECORDRULE		49    
#define PARA_STORAGE_EXTNAME		50    
#define PARA_STORAGE_MAPDEVICE		51    
#define PARA_STORAGE_MOUNTUSB		52    
#define PARA_STORAGE_DISKSTATE		53    
#define PARA_AUDIOCODER				54    
#define PARA_NPMODE					55    
#define PARA_STORAGE_RECORDSTATE	56    

#define PARA_PU_MANAGERSVR			57    
#define PARA_PU_DEVICEID			58    
#define PARA_STREAMCLIENT			59    
#define PARA_DATEFORMAT				60    
#define PARA_HTTPPORT				61    

#define PARA_CMOS_SCENE				62    
#define PARA_SMTP_INTO				63    
#define PARA_SMTP_ENABLE			64    
#define PARA_SENSORFLIP				65    

#define PRAM_WIFI_PARAM				66
#define PARA_WIFI_SEARCH_RESULT		67   

#define PARA_PRIVACYPROTECT			68
#define PARA_NTP					69
#define PARA_ALARTHRESHOLD			70
#define PARA_OSDALPHA				71
#define PARA_WORDOVERLAY			72

#define PARA_ALARMSERVER			73
#define PARA_DHCP_BACK				74
#define PARA_WIFIDHCP				75
#define PARA_DIAPHANEITY			76
#define PARA_PTZ_PROTOCOL			77
#define PARA_3D						78
#define PARA_DISK_USAGE				79
#define PARA_VIDEOPARA_SCHEDULE		80
#define PARA_ALARM_INPORT			81
#define PARA_ALARM_OUT				82
#define PARA_INPORT_SCHEDULE		83
#define PARA_OUTPORT_SCHEDULE		84
#define PARA_MOTION_SCHEDULE		85
#define PARA_VDOLOST_SCHEDULE		86
#define PARA_VDOLOST_LINKREC		87
#define PARA_MOTIONDEC_LINKREC		88
#define PARA_ALMINPORT_LINKREC		89
#define PARA_VDOLOST_LINKSNAP		90
#define PARA_MOTIONDEC_LINKSNAP		91
#define PARA_ALMINPORT_LINKSNAP		92
#define PARA_VDOLOST_LINKPTZ		93
#define PARA_ALMINPORT_LINKPTZ		94
#define PARA_VDOLOST_LINKSNDDIS		95
#define PARA_MOTIONDEC_LNKSNDDIS	96
#define PARA_ALMINPORT_LNKSNDDIS	97
#define PARA_ALMINPORT_LNKOUT		98
#define PARA_VDOLOST_LNKOUT			99
#define PARA_MOTIONDEC_LNKOUT		100
#define PARA_OUTPORT_DELAY			101
#define PARA_UPNP_ENABLE			102
#define PARA_SYSINFO_RESULT			103
#define PARA_DDNSCHANGED 			104	   
#define PARA_FUNCLIST				105	
#define PARA_OUTPORT_STATE			106
#define PARA_ZTEINFO				107
#define PARA_ONLINESTATE			108
#define PARA_DZINFO					109
#define PARA_COMSERVER				110
#define PARA_VENCTYPE				111  //��Ƶ����ı� ������
#define PARA_PTZAUTOPBACK			112
#define PARA_3GDEVICESTATUS			113
#define PARA_3GDIALOG				114
#define PARA_3GMESSAGE				115
#define PARA_HDCAMER				116
#define PARA_HXLISTENPORTINFO		117
#define PARA_3GTASKSCHEDULE			118
#define PARA_3GNOTIFY				119
#define PARA_COLORPARA				120
#define PARA_EXCEPTION				121
#define PARA_CAHNNELNAME			122
#define PARA_CUSTOMRECTYPE			123
#define PARA_FTP_UPDATE				124
#define PARA_FTP_UPDATE_STATUS		125
#define PARA_CHNPTZFORMAT			126
#define PARA_3GVPDN					127
#define PARA_VIDEOCOVER_SCHEDULE	128
#define PARA_CHNPTZCRUISE			129
#define PARA_VDOCOVER_LINKPTZ		130

#define PARA_VCA_CHANNEL			131
#define PARA_VCA_VIDEOSIZE			132
#define PARA_VCA_ADVANCED			133
#define PARA_VCA_TARGET				134
#define PARA_VCA_ALARMSTAT			135
#define PARA_VCA_RULESET			136
#define PARA_VCA_RULEEVENT0			137
#define PARA_VCA_RULEEVENT1			138
#define PARA_VCA_RULEEVENT2			139
#define PARA_VCA_ALARMSCHEDULE		140
#define PARA_VCA_SCHEDULEENABLE		141
#define PARA_VCA_ALARMLINK			142

#define PARA_FTP_SNAPSHOT			143
#define PARA_FTP_LINKSEND			144
#define PARA_FTP_TIMEDSEND			145

#define PARA_DVR3G_POWERDELAY		146
#define PARA_DVR3G_SIMNUM			147
#define PARA_DVR3G_GPSINFO			148
#define PARA_DVR3G_GPSFILTER		149

#define PARA_CDBURN_MODE			150					//	��¼��ʽ����
#define PARA_VIDEOENCRYPT			151
#define PARA_PREIVEWREOCRD			152

#define PARA_DIGITALCHANNEL			153
#define PARA_NPMODE_EX				154

#define	PARA_SIP_VIDEOCHANNEL		155			//	SIP��Ƶͨ������
#define PARA_SIP_ALARMCHANNEL		156			//	SIP����ͨ������

#define PARA_VIDEOCOMBINE			157        //	�໭��ϳ�
#define PARA_PLATFORM_RUN			158			//	PlatForm Run

#define PARA_ITS_CHNLENABLE         159       //
#define PARA_ITS_CHNLLOOP           160       //
#define PARA_ITS_CHNLTIME           161       //
#define PARA_ITS_CHNLSPEED          162       //
#define PARA_ITS_CHNLRECO           163       //
#define PARA_ITS_CHNLVLOOP          164       //

#define PARA_ITS_LPOPTIM_FIRSTHZ    165       //
#define PARA_ITS_LPOPTIM_NPENABLE   166       //
#define PARA_ITS_LPOPTIM_OTHER      167       //

#define PARA_ITS_TIMERANGE			168         //���ʱ������� 
#define PARA_ITS_TIMERANGEPARAM     169			//ʱ��β�������
#define PARA_ITS_TIMERANGE_AGCBLOCK			170     //ʱ��β������ʹ��
#define PARA_ITS_TIMERANGE_FLASHLAMP		171     //ʱ��������ʹ��
#define PARA_ITS_DETECTMODE					172     //������ģʽ����
#define PARA_ITS_BLOCK						173		//��������������
#define PARA_ITS_LOOPMODE					174		//��Ȧ����ģʽ	
#define PARA_ITS_DEVICETYPE					175		//�����������
#define PARA_ITS_SWITCHTIME					176     //������Ƶ���ⴥ��ģʽ�л�ʱ�������������ʱץ��ʱ�䣨��Ҫ�����״
#define PARA_JPEGQUALITY					177     //����JPEGͼƬ����	

#define PARA_VCA_RULEEVENT9					178		//���ܷ�������ʶ�����
#define PARA_VCA_RULEEVENT10				179		//���ܷ�����Ƶ��ϲ���

#define PARA_ITS_TEMPLATENAME				180		//�������ģ����������

#define PARA_ITS_RECOPARAM					181		//��ͨ-����ʶ���㷨����

#define PARA_ITS_DAYNIGHT					182		//��ͨ-����ҹ��ʼʱ������
#define PARA_ITS_CAMLOCATION				183		//��ͨ-���λ��
#define PARA_ITS_WORKMODE					184		//��ͨ-�������ģʽ
#define PARA_TIMEZONE_SET                   185     //����ʱ��
#define PARA_LANGUAGE_SET                   186     //��������

#define PARA_CHANNELENCODEPROFILE_SET       187     //ͨ������

#define PARA_EXCEPTION_HANDLE               188    //�쳣����

#define PARA_ITS_CHNLIGHT					189		//������Ӧ���źŵ�
#define PARA_ITS_CAPTURE					190		//������Ӧ��ץ��λ��
#define PARA_ITS_RECOGNIZE					191		//�Ƿ�����ʶ����								
#define PARA_IMG_DISPOSAL					192		//ͼƬЧ��������
#define PARA_WATERMARK						193		//�Ƿ�����ˮӡ����
#define PARA_SYSTEM_TYPE					194		//ϵͳ����
#define PARA_ITS_LIGHT_INFO					195		//�źŵƶ�Ӧ�Ĳ���

#define PARA_CHECKBADPIXEL_STATUS           196     //������״̬
#define PARA_DEVICE_STATE                   197     //�豸ʵʱ״̬
#define PARA_CHECKIRIS_STATUS               198     //��Ȧ���״̬

#define PARA_ITS_ILLEGALPARK				199     //����Υ��ͣ������
#define PARA_ITS_ILLEGALPARKPARAM           200    //����Υ��ͣ���궨�������

#define PARA_LAN_IPV4						201     //����IPv4��ַ
#define PARA_LAN_IPV6						202     //����IPv6��ַ
#define PARA_LAN_WORKMODE					203     //���繤��ģʽ
#define PARA_PWM_STATUS                     204     //�����PWM����ֵ

#define PARA_AUDIOMIX	                    205     //�����ϳɲ���
#define PARA_AUDIOLOST_ALARMSCHEDULE		206		//��Ƶ��ʧ��������ģ��
#define PARA_AUDIOLOST_ALARMLINK			207		//��Ƶ��ʧ��������ģ��
#define PARA_AUDIOLOST_ALARMSCHENABLE		208		//��Ƶ��ʧ��������ģ��

#define PARA_ITS_SWITCH_INTERVAL			209		//����ⴥ������Ƶ�Զ��л�ʱ����
#define PARA_ITS_VIDEODETECT				210		//�������ͼ����
#define PARA_ITS_REFERENCLINES				211		//���������������
#define PARA_ITS_DETECTAREA					212		//������������������
#define PARA_ITS_RECOTYPE					213		//��������㷨��������
#define PARA_METHODMODE				        214     //������ƵԴ��ʽ�Ļ�ȡ��ʽ

#define PARA_LOCALSTORE_CHANNELPARA	        215     //ͨ����ش洢����


#define PARA_WIFIWORKMODE				    216      //����WIFI����ģʽ
#define PARA_WIFIAPDHCPPARA					217      //����DHCP�������ò��� Ip��Χ ����ʱ���
#define PARA_WIFIAPPARA						218      //����WIFI_AP���������Ϣ

#define PARA_ITS_ENABLEPARAM				219		 //���ý�ͨ��ع���ʹ��
#define PARA_ITS_REDLIGHTDETECTAREA			220		 //���ú�Ƽ���������
#define PARA_ATM_INFO						221		 //����ATM��Ϣ
#define PARA_AUDIO_SAMPLE					222		 //������Ƶ������
#define PARA_IPCPnP							223		 //��������ͨ�����弴��
#define PARA_WIFIDHCPAP						224		 //����APģʽDHCP����
#define PARA_MIXAUDIO   			        225		 //����
#define PARA_DOME_TITLE   			        226		 //	�������
#define PARA_HARDWARE_VOLTAGE               227      //����8127�����ѹ

#define PARA_ALARMTRIGGER_AUDIOLOSE	        228      //������Ƶ��ʧ��������ֵ

#define PARA_VIDEOCOVER_ALARMSCHEDULE		229		 //��Ƶ�ڵ���������ģ��
#define PARA_VIDEOCOVER_ALARMLINK			230		 //��Ƶ�ڵ�������������
#define PARA_VIDEOCOVER_ALARMSCHENABLE		231		 //��Ƶ�ڵ�����ģ��ʹ��
#define PARA_HOLIDAY_PLAN_SCHEDULE			232		 //����ģ��
#define PARA_VCA_RULEEVENT12				233
#define PARA_VCA_RULEEVENT13				234
#define PARA_VDOLOST_LNKSINGLEPIC			235
#define PARA_ALMINPORT_LNKSINGLEPIC			236
#define PARA_MOTIONDEC_LNKSINGLEPIC			237
#define PARA_VDOCOVER_LNKSINGLEPIC			238
#define PARA_CHANNEL_TYPE				    239  //ͨ������
#define PARA_OTHER_ALARMSCHEDULE			240 	//������������ģ��
#define PARA_OTHER_ALARMLINK				241		//������������ģ��
#define PARA_OTHER_ALARMSCHENABLE			242		//������������ģ��
#define PARA_PORTSET						243		//�˿����ò����ı�
#define PARA_DISKGROUP						244		
#define PARA_DISKQUOTA						245			
#define PARA_NEW_IP							246

//add by wd @20130603
#define  PARA_ITS_CROSSINFO					247     //·����Ϣ
#define  PARA_ITS_AREAINFO					248     //��������
#define  PARA_JPEGSIZEINFO					249    //���ץ�ķֱ���	
#define  PARA_DEVSTATUS						250
//add end 

#define  PARA_HD_TEMPLATE_INDEX				251		//����ģ����
#define	 PARA_STREAM_DATA					252		//�û��Զ������ݲ���
#define  PARA_VCA_RULEEVENT14_LEAVE_DETECT	253		//��ڼ����Ϣ
#define  PARA_DOME_PTZ						254		//���PTZ�����ı���Ϣ
#define  PARA_ITS_TEMPLATEMAP				255     //ʱ�������������ģ��ӳ���ϵ
#define  PARA_GPS_CALIBRATION				256     //�Ƿ�����GPSУʱ
#define  PARA_ALARM_THRESHOLD				257     //��ѹ������ֵ
#define  PARA_SHUTDOWN_THRESHOLD			258     //��ѹ�ػ���ֵ
#define  PARA_SMART_SCHEDULE				259		//����¼��ģ��
#define  PARA_VIDEO_SCHEDULE				260
#define  PARA_ITS_CHNCARSPEED				261		//�����ڳ����ٶȲ���

#define  PARA_DOME_SYETEM				    262		//���ϵͳ����
#define  PARA_DOME_MENU						263		//����˵�����
#define  PARA_DOME_WORK_SCHEDULE			264		//�������ģ�����
#define  PARA_INTERESTED_AREA 				265		//����Ȥ�������
#define  PARA_APPEND_OSD				    266		//�����ַ����Ӳ���
#define  PARA_AUTO_REBOOT					267		//NVR�Զ���������ʱ��
#define	 PARA_IP_FILTER						268		//IP��ַ����
#define	 PARA_DATE_FORMAT					269		//����ʱ���ʽ
#define  PARA_NETCONNECT_INFO_MTU			270     //MTU�������ײ�socket���ͷְ������Ԫ��
#define  PARA_LANSET_INFO					271     //�������ò���
#define  PARA_DAYLIGHT_SAVING_TIME			272		//����ʱ
#define  PARA_NET_OFF_LINE					273
#define	 PARA_PICTURE_MERGE					274		//ͼ��ϳ�
#define  PARA_SNAP_SHOT_INFO			    275		//ǰ��ץ�Ĳ���
#define	 PARA_IO_LINK_INFO					276
#define  PARA_COMMAND_ITS_FOCUS				278		//�۽��������
#define  PARA_VCA_RULEEVENT7				279		//��Ʒ������ʧ
#define	 PARA_VCA_RULEEVENT11				280		//�����¼�
#define	 PARA_DEV_COMMONNAME  				281		//�Զ����豸ͨ�ýӿڵı�����64�ֽڣ�

#define  PARA_APPVENCTYPE				    282  //��Ƶ����ı� ������
#define  PARA_THIRD_VENCTYPE				283  //��Ƶ����ı� ������
#define	 PARA_ITS_DEV_COMMONINFO  			284		//ITS�豸ͨ����Ϣ��Ϣ


typedef int							IDENTIFY;
#define CLIENT						0
#define PROXY						1
#define CLIENT_PROXY				2

// enum DECDATATYPE
// {
//     T_AUDIO8,T_YUV420,T_YUV422
// };
typedef int DECDATATYPE;
#define T_AUDIO8 0
#define T_YUV420 1
#define T_YUV422 2

typedef struct
{
    int     m_iPara[10];
    char    m_cPara[33];
}STR_Para;

//add by wd 20130621
#define MAX_DEVSTATUS_NUM 4
typedef struct 
{
	int     iType;
	int     iStatus[MAX_DEVSTATUS_NUM];
}STR_DevStatus;
//add end

//Templet time
/*typedef struct
{
    UINT8		m_u8StartHour;
    UINT8		m_u8StartMin;
    UINT8		m_u8StopHour;
    UINT8		m_u8StopMin;
}NVS_TEMPLETTIME,*PNVS_TEMPLETTIME;*/

//Schedle time
typedef struct
{
    unsigned short      iStartHour;
    unsigned short      iStartMin;
    unsigned short      iStopHour;
    unsigned short      iStopMin;
    unsigned short      iRecordMode; //iEnable;
}NVS_SCHEDTIME,*PNVS_SCHEDTIME;

typedef struct
{
	int		 iSize;
	int      iStartHour;
	int      iStartMin;
	int      iStopHour;
	int      iStopMin;
	int      iRecordMode; 
}NVS_SCHEDTIME_Ex,*PNVS_SCHEDTIME_Ex;

typedef struct
{
    unsigned short      m_u16Brightness;
    unsigned short      m_u16Hue;
    unsigned short      m_u16Contrast;
    unsigned short      m_u16Saturation;
    /*
    UINT8		m_u8StartHour;
    UINT8		m_u8StartMin;
    UINT8		m_u8StopHour;
    UINT8		m_u8StopMin;
    */
    NVS_SCHEDTIME strctTempletTime;
}STR_VideoParam;

typedef struct
{
    char    cEncoder[16];       //NVS IP��
    char    cClientIP[16];      //Client IP��
    int     iChannel;           //Channel Number��
    int     iStreamNO;          //Stream type
    int     iMode;              //Network mode��1��TCP���� 2��UDP����3��multicast��
}LINKINFO, *PLINKINFO;

typedef struct
{
    int             iCount;                     //Connect Count��
    unsigned int    uiID[MAX_ENCODER];          //ID
}UIDLIST, *PUIDLIST;

typedef struct
{
    char        m_cHostName[32];    //NVS host name
    char        m_cEncoder[16];     //NVS (IP)
    int         m_iRecvMode;        //Network mode
    char        m_cProxy[16];       //Proxy (IP)
    char        m_cFactoryID[32];   //ProductID
    int         m_iPort;            //NVS port
    int         m_nvsType;          //NVS type(NVS_T or NVS_S or DVR ...eg)

	int         m_iChanNum;         //encoder channel num
    int         m_iLogonState;      //encoder logon state 090414 zyp add
    int         m_iServerType;      //������ģʽ�豸SERVER_ACTIVE�����Ǳ���ģʽ�豸SERVER_NORMAL
}ENCODERINFO,*PENCODERINFO;

typedef struct
{
    int             m_iServerID;        //NVS ID,NetClient_Logon ����ֵ
    int             m_iChannelNo;       //Remote host to be connected video channel number (Begin from 0)
    char            m_cNetFile[255];    //Play the file on net, not used temporarily
    char            m_cRemoteIP[16];    //IP address of remote host
    int             m_iNetMode;         //Select net mode 1--TCP  2--UDP  3--Multicast
    int             m_iTimeout;         //Timeout length for data receipt
    int             m_iTTL;             //TTL value when Multicast
    int             m_iBufferCount;     //Buffer number
    int             m_iDelayNum;        //Start to call play progress after which buffer is filled
    int             m_iDelayTime;       //Delay time(second), reserve
    int             m_iStreamNO;        //Stream type
    int             m_iFlag;            //0���״������¼���ļ���1������¼���ļ�
    int             m_iPosition;        //0��100����λ�ļ�����λ�ã�-1�������ж�λ
    int             m_iSpeed;           //1��2��4��8�������ļ������ٶ�
}CLIENTINFO;

//Version message structure, with which to transmit SDK version message
typedef struct
{
    unsigned short  m_ulMajorVersion;
    unsigned short  m_ulMinorVersion;
    unsigned short  m_ulBuilder;
    char*           m_cVerInfo;
}SDK_VERSION;

//OSD param
typedef struct
{
    unsigned char   ucCovTime;
    unsigned char   ucCovWord;
    int             iCovYear;
    int             iCovMonth;
    int             iCovDay;
    int             iCovHour;
    int             iCovMinute;
    int             iCovSecond;
    unsigned char   ucPosition;
    char            cCovWord[32];
}OSD_PROPERTY;

//Hardware decode to show external data parameter
typedef struct
{
    int     m_iChannelNum;      //Decode card hardware channel number
    int     m_iVideoWidth;      //Video width
    int     m_iVideoHeight;     //Video height
    int     m_iFrameRate;       //Frame rate
    int     m_iDisPos;          //Video display position
    int     m_iAudioOut;        //whether to output audio
}DecoderParam;

typedef struct
{
    unsigned long nWidth;    //Video width, audio data is 0��
    unsigned long nHeight;   //Video height, audio data is 0��
    unsigned long nStamp;    //Time stamp(ms)��
    unsigned long nType;     //Audio type��T_AUDIO8,T_YUV420����
    unsigned long nFrameRate;//Frame rate��
    unsigned long nReserved; //reserve
}FRAME_INFO;

// enum RAWFRAMETYPE
// {
//     VI_FRAME = 0,   //��ƵI֡
//     VP_FRAME = 1,   //��ƵP֡
//     AUDIO_FRAME = 5 //��Ƶ֡
// };
typedef int RAWFRAMETYPE;
#define VI_FRAME 0
#define VP_FRAME 1
#define AUDIO_FRAME 5


typedef struct
{
    unsigned int nWidth;    //Video width, audio data is 0
    unsigned int nHeight;   //Video height, audio data is 0
    unsigned int nStamp;    //Time stamp(ms)
    unsigned int nType;     //RAWFRAMETYPE, I Frame:0,P Frame:1,B Frame:2,Audio:5
    unsigned int nEnCoder;  //Audio or Video encoder(Video,0:H263,1:H264, 2:MP4. Audio,��ѹ��:0,G711_A:0x01,G711_U:0x02,ADPCM_A:0x03,G726:0x04)
    unsigned int nFrameRate;//Frame rate
    unsigned int nReserved; //reserve
}RAWFRAME_INFO;
   
//�����ֵĻص�����           
typedef void (*PROXY_NOTIFY)(int _ulLogonID,int _iCmdKey, char* _cData,  int _iLen,int _iUser);

//������յ�ԭʼ����,����������һ֡���ݣ������ڴ���ת��
typedef void (*NVSDATA_NOTIFY)(unsigned int _ulID,unsigned char *_cData,int _iLen,int _iUser);

#define STREAM_INFO_SYSHEAD     1  //ϵͳͷ����
#define STREAM_INFO_STREAMDATA  2  //��Ƶ�����ݣ�����������������Ƶ�ֿ�����Ƶ�����ݣ�
//������һ֡����,������д¼���ļ�,�����Ͳ����������š�Ҫ����_ulStreamType������
typedef void (__stdcall *FULLFRAME_NOTIFY)(unsigned int _ulID,unsigned int _ulStreamType,unsigned char *_cData,int _iLen,int _iUser);
typedef void (__stdcall *FULLFRAME_NOTIFY_V4)(unsigned int _ulID, unsigned int _ulStreamType, unsigned char *_cData, int _iLen, int _iUser, int _iUserData); //_iUser���ļ�ͷ���ݣ�_iUserData���û�����
//δ����ǰ�ı�׼����,��h264����
typedef void (__stdcall *RAWFRAME_NOTIFY)(unsigned int _ulID,unsigned char* _cData,int _iLen, RAWFRAME_INFO *_pRawFrameInfo, int _iUser);

//�������ݣ��������ز���
typedef void (__stdcall *RECV_DOWNLOADDATA_NOTIFY)(unsigned int _ulID, unsigned char* _ucData,int _iLen, int _iFlag, void* _lpUserData);


//===========================================================================
//  storage  add 2007.6.13
//===========================================================================

#define MAX_DAYS            7
#define MAX_TIMESEGMENT     4
#define MAX_PAGE_SIZE       20
#define MAX_PAGE_LOG_SIZE	20
#define MAX_BITSET_COUNT    2

//Record type�� 1-Manual record��2-Schedule record��3-Alarm record
// enum RECORD_TYPE
// {
//     RECORD_ALL=0xFF, RECORD_MANUAL=1, RECORD_TIME=2, RECORD_ALARM=3, RECORD_OTHER
// };
typedef int RECORD_TYPE;
#define RECORD_ALL 0xFF
#define RECORD_MANUAL 1
#define RECORD_TIME	  2
#define RECORD_ALARM  3
#define RECORD_OTHER  4

//Record state��
// enum RECORD_STATE
// {
//     REC_STOP=0, REC_MANUAL=1, REC_TIME=2, REC_ALARM=3
// };
 typedef int RECORD_STATE;
#define REC_STOP 0
#define REC_MANUAL 1
#define REC_TIME 2
#define REC_ALARM 3

//Audio encoder��
// enum AUDIO_ENCODER
// {
//     G711_A              = 0x01,  /* 64kbps G.711 A, see RFC3551.txt  4.5.14 PCMA */
//     G711_U              = 0x02,  /* 64kbps G.711 U, see RFC3551.txt  4.5.14 PCMU */
//     ADPCM_DVI4          = 0x03,  /* 32kbps ADPCM(DVI4) */
// 	G726_16KBPS         = 0x04,  /* 16kbps G.726, see RFC3551.txt  4.5.4 G726-16 */
//     G726_24KBPS         = 0x05,  /* 24kbps G.726, see RFC3551.txt  4.5.4 G726-24 */
//     G726_32KBPS         = 0x06,  /* 32kbps G.726, see RFC3551.txt  4.5.4 G726-32 */
//     G726_40KBPS         = 0x07,  /* 40kbps G.726, see RFC3551.txt  4.5.4 G726-40 */
//     MPEG_LAYER2         = 0x0E,  /* Mpeg layer 2*/
// 	AMR_NB				= 0x15,
//     ADPCM_IMA           = 0x23,  /* 32kbps ADPCM(IMA) */
//     MEDIA_G726_16KBPS   = 0x24,  /* G726 16kbps for ASF ... */
//     MEDIA_G726_24KBPS   = 0x25,  /* G726 24kbps for ASF ... */
//     MEDIA_G726_32KBPS   = 0x26,  /* G726 32kbps for ASF ... */
//     MEDIA_G726_40KBPS   = 0x27   /* G726 40kbps for ASF ... */
// };
typedef int AUDIO_ENCODER;
#define   G711_A              0x01  /* 64kbps G.711 A, see RFC3551.txt  4.5.14 PCMA */
#define   G711_U              0x02  /* 64kbps G.711 U, see RFC3551.txt  4.5.14 PCMU */
#define   ADPCM_DVI4          0x03  /* 32kbps ADPCM(DVI4) */
#define   G726_16KBPS         0x04  /* 16kbps G.726, see RFC3551.txt  4.5.4 G726-16 */
#define   G726_24KBPS         0x05  /* 24kbps G.726, see RFC3551.txt  4.5.4 G726-24 */
#define   G726_32KBPS         0x06  /* 32kbps G.726, see RFC3551.txt  4.5.4 G726-32 */
#define   G726_40KBPS         0x07  /* 40kbps G.726, see RFC3551.txt  4.5.4 G726-40 */
#define   MPEG_LAYER2         0x0E  /* Mpeg layer 2*/
#define   AMR_NB			  0x15
#define	  MPEG4_AAC			  0x16	/* MPEG-4 aac HEv2 ADTS*/
#define   ADPCM_IMA           0x23  /* 32kbps ADPCM(IMA) */
#define   MEDIA_G726_16KBPS   0x24  /* G726 16kbps for ASF ... */
#define   MEDIA_G726_24KBPS   0x25  /* G726 24kbps for ASF ... */
#define   MEDIA_G726_32KBPS   0x26  /* G726 32kbps for ASF ... */
#define   MEDIA_G726_40KBPS   0x27   /* G726 40kbps for ASF ... */

//Record mode param
typedef struct
{
    int  iPreRecord[MAX_CHANNEL_NUM];           /* Prerecord enabled: 0-Enable 1-Disable*/
    int  iPreRecordTime[MAX_CHANNEL_NUM];       /* Prerecord time 5-30s��default 10s */
    int  iDelayTime[MAX_CHANNEL_NUM];           /* Delay time*/
    int  iDelayEnable[MAX_CHANNEL_NUM];         /* Delay enabled: 0-Enable 1-Disable*/
    char cExternName[10];   /* Record file extended name */
    int  iRecordTime;       /* Record time length */
    int  iRecPolicy;        /* Storage strategy */
    int  iFreeDisk;         /* Minimum free disk space */
    int  iFileSize;         /* File maximum space*/
}NVS_RECORD,*PNVS_RECORD;

//Record time parameter
typedef struct
{
    unsigned short iYear;   /* Year */
    unsigned short iMonth;  /* Month */
    unsigned short iDay;    /* Day */
    unsigned short iHour;   /* Hour */
    unsigned short iMinute; /* Minute */
    unsigned short iSecond; /* Second */
} NVS_FILE_TIME,*PNVS_FILE_TIME;

//Record File Property
typedef struct
{
    int             iType;          /* Record type 1-Manual record, 2-Schedule record, 3-Alarm record*/
    int             iChannel;       /* Record channel 0~channel defined channel number*/
    char            cFileName[250]; /* File name */
    NVS_FILE_TIME   struStartTime;  /* File start time */
    NVS_FILE_TIME   struStoptime;   /* File end time */
    int             iFileSize;      /* File size */
}NVS_FILE_DATA,*PNVS_FILE_DATA;

typedef struct
{
	int				iSize;
	NVS_FILE_DATA	tFileData;		//�ļ�������Ϣ
	int			    iLocked;		//�ӽ���״̬
}NVS_FILE_DATA_EX,*PNVS_FILE_DATA_EX;

//Reserch parameter
typedef struct
{
    int             iType;          /* Record type 0xFF-All, 1-Manual record, 2-Schedule record, 3-Alarm record*/
    int             iChannel;       /* Record channel 0xFF-All, 0~channel-defined channel number*/
    NVS_FILE_TIME   struStartTime;  /* Start time of file */
    NVS_FILE_TIME   struStopTime;   /* End time of file */
    int             iPageSize;      /* Record number returned by each research*/
    int             iPageNo;        /* From which page to research */
    int             iFiletype;      /* File type, 0-All, 1-AVstream, 2-picture*/
    int             iDevType;       /* �豸���ͣ�0-���� 1-������Ƶ������ 2-��������� 0xff-ȫ��*/
}NVS_FILE_QUERY, *PNVS_FILE_QUERY;

typedef struct  
{
	NVS_FILE_QUERY	fileQuery;
	char			cOtherQuery[65];
	int				iTriggerType;		//�������� 3:�˿ڱ���,4:�ƶ�����,5:��Ƶ��ʧ����,0x7FFFFFFF:��Ч
	int				iTrigger;			//�˿ڣ�ͨ������
}NVS_FILE_QUERY_EX, *PNVS_FILE_QUERY_EX;

//Net storage device
typedef struct
{
    char cDeviceIP[16];
    char cStorePath[250];
    char cUsername[16];
    char cPassword[16];
    int  iState;
}NVS_NFS_DEV,*PNVS_NFS_DEV;

//Diskinfo
//disk manager
#define DISK_SATA_NUM	8
#define DISK_USB_NUM	4
#define	DISK_NFS_NUM	1
#define	DISK_ESATA_NUM	1
#define	DISK_SD_NUM		1

#define DNO_ESATA	32	// esata disk first no
#define DNO_SD		50	// SD disk first no

// enum DISK_STATUSTYPE
// {
//     DISK_ZERO = 0,DISK_NOTFORMAT,DISK_FORMATED,DISK_CANUSE,DISK_READING
// };
typedef int DISK_STATUSTYPE;
#define DISK_ZERO 0
#define DISK_NOTFORMAT 1
#define DISK_FORMATED  2
#define DISK_CANUSE    3
#define DISK_READING   4

/*typedef struct
{
    int  iTotal;        //total size
    int  iFree;         //free size
    int  iReserved;     //reserved
}NVS_DISKINFO, *PNVS_DISKINFO;*/

typedef struct
{
    unsigned int  m_u32TotalSpace; // �ܴ�С
    unsigned int  m_u32FreeSpace;  // ʣ��ռ�
    unsigned short  m_u16PartNum;    // ������  1��4
    unsigned short  m_u16Status;     // ״̬ 0���޴��̣�1��δ��ʽ����2���Ѹ�ʽ����3���ѹ��أ�4����д��
    unsigned short  m_u16Usage;      // ��; 0��¼��1������
    unsigned short  m_u16Reserve;    //	����
}NVS_DISKINFO, *PNVS_DISKINFO;

//���ṹ��
#define  CMD_DISK_QUOTA_MAX_USED  			1
#define  CMD_DISK_QUOTA_TOTAL				2
#define  CMD_DISK_QUOTA_CURRENT_USED		3
typedef struct
{
	int  iSize;												//�ṹ���С
	int  iRecordQuota; 										//¼������λ��GB��
	int  iPictureQuota;										//ͼƬ����λ��GB��
}DISK_QUOTA;

typedef struct
{
	int  iSize;												//�ṹ���С
	char cRecordQuota[65]; 										//����¼������λ��GB��
	char cPictureQuota[65];										//����ͼƬ����λ��GB��
}DISK_QUOTA_USED;
//����ṹ��
#define MAX_DISK_GROUP_NUM			8
typedef struct
{
	int  iSize;												//�ṹ���С 
	int  iGroupNO;											//�����ţ�0-7
	unsigned  int	 uiDiskNO[2];							//���̱�ţ���λ��ʾ��ֻ��ѡ��0-7
	//����32����С���󣬶�Ӧbitλ�ӵ͵���
	unsigned  int  uiChannelNO[4];							//ͨ�����,��λ��ʾ��ͨ���Ŵ�С���󣬶�Ӧ
	//bitλ�ӵ͵���������256ͨ��
}DISK_GROUP;

//����Ȩ����Ϣ�ṹ��
#define MAX_MODIFY_AUTHORITY_NUM    26				//���Ȩ�޸���
typedef struct 
{
	int iLevel;										// Ȩ�޺�
	unsigned int uiList[4];							//ͨ���б�����
}AUTHORITY_INFO;
//�û�Ȩ�޽ṹ��
typedef struct
{
	int iNeedSize;				//�û�ʹ��ʱ��iNeedSize����һ��������Ҫ�޸ĵ�Ȩ����,��󲻳���10
	AUTHORITY_INFO  strAutInfo[MAX_MODIFY_AUTHORITY_NUM];
}USER_AUTHORITY;

//�û�Ȩ�����ṹ��
#define MAX_AUTHORITY_GROUP_NUM		4	//Ȩ�����������
typedef struct
{
	int iSize;												//�ṹ���С 
	int iGroupNO;											//Ȩ�����ţ�1��ͨ�û���2��Ȩ�û���
	//3�����û���4����Ա
	unsigned int uiList[2];									//��Ȩ��������Ӧ��Ȩ�޺ţ���λ��ʾ��
	//Ȩ�ޱ�Ŵ�С���󣬶�Ӧbitλ�ӵ͵���
	char  cReserved[256];									//Ԥ��
}GROUP_AUTHORITY;

//Storage device info
/*typedef struct
{
    NVS_DISKINFO  usbDisk;  //usb disk information
    NVS_DISKINFO  nfsDisk;  //nfs disk information
    NVS_DISKINFO  ideDisk;  //ide disk information
}NVS_STORAGEDEV, *PNVS_STORAGEDEV;*/

typedef struct
{
    NVS_DISKINFO m_strctSATA[DISK_SATA_NUM];
    NVS_DISKINFO m_strctUSB[DISK_USB_NUM];
    NVS_DISKINFO m_strctNFS[DISK_NFS_NUM];
    NVS_DISKINFO m_strctESATA[DISK_ESATA_NUM];
    NVS_DISKINFO m_strctSD[DISK_SD_NUM];
}NVS_STORAGEDEV, *PNVS_STORAGEDEV;

// enum SMTP_AUTHTYPE
// {
//     AUTH_OFF=0,AUTH_PLAIN,AUTH_CRAM_MD5,AUTH_DIGEST_MD5,AUTH_GSSAPI,AUTH_EXTERNAL,AUTH_LOGIN,AUTH_NTLM,SMTP_AUTHTYPE_LAST
// };
typedef int SMTP_AUTHTYPE;
#define AUTH_OFF			0
#define AUTH_PLAIN			1
#define AUTH_CRAM_MD5		2
#define AUTH_DIGEST_MD5 	3
#define AUTH_GSSAPI			4
#define AUTH_EXTERNAL		5
#define AUTH_LOGIN			6
#define AUTH_NTLM			7
#define SMTP_AUTHTYPE_LAST	8
// enum SCENE_TYPE
// {
//     AUTO=0, SCENE1,SCENE2,SCENE3,SCENE4,SCENE5,SCENE6,SCENE7,SCENE8,SCENE9,SCENE10,SCENE11,SCENE_TYPE_LAST
// };
typedef int SCENE_TYPE;
#define AUTO			0
#define SCENE1			1
#define SCENE2			2
#define SCENE3 			3
#define SCENE4			4
#define SCENE5			5
#define SCENE6			6
#define SCENE7			7
#define SCENE8			8
#define SCENE9			9
#define SCENE10			10
#define SCENE11			11
#define SCENE_TYPE_LAST	12

//SMTP alarm info
typedef struct
{
    char            cSmtpServer[32];    //smtp server
    unsigned short  wdSmtpPort;         //smtp server port
    char            cEmailAccount[32];  //mail account
    char            cEmailPassword[32];  //mail password
    int             iAuthtype;           //authtype
    char            cEmailAddress[32];  //mailbox address
    char            cMailSubject[32];   //mail subject
}SMTP_INFO,*PSMTP_INFO;
//add SMTP alarm info by gjf
typedef struct SMTP_INFOEX
{
	SMTP_INFO	smtpInfo;
	char		cMailAddr[3][32];		//	����3����ַ
}*PSMTP_INFOEX;
//add end 
//---------------------------------------------------------------------------

typedef struct
{
    char cESSID[33];            //ESSID
    char cEncryption[16];       //wifi encrypttion flag; 0 no encryption��1 digital encryption
}WIFI_INFO, *PWIFI_INFO;

typedef struct
{
    char    m_cDDNSUserName[32];
    char    m_cDDNSPwd[32];
    char    m_cDDNSNvsName[32];
    char    m_cDDNSDomain[32];
    int     m_iDDNSPort;
    int     m_iDDNSEnable;
}DDNS_INFO, *PDDNS_INFO;

typedef struct
{
    char    cESSID[33];         //ESSID
    char    cWifiSvrIP[16];     //wifiIP
    char    cWifiMask[16];          //wifi mask
    char    cWifiGateway[16];       //wifi gateway
    char    cWifiDNS[16];           //wifi DNS
    char    cWifiKeyType[16];       //wifi KeyType��Hex��ASCII
    char    cWifiPassword[128];     //wifi password, @yys@, 32->128, 2010-07-05
    char    cEncryption[16];        //wifi encrypttion flag; NULL no encryption��"WEP" encryption
    char    cWifiKeyNum[2];         //wifi KeyNum (1,2,3,4)
    int     iPwdFormat;
    int     iHaveCard;
    int     iCardOnline;
}NVS_WIFI_PARAM, *PNVS_WIFI_PARAM;

//����IE
//wifiap
//typedef struct
//{
//	char	cESSID[64];			    //ESSID!
//	char	cWifiSvrIP[16];		    //wifiapIP
//	char	cWifiMask[16];			//wifiap mask
//	char	cWifiGateway[16];		//wifiap gateway
//	char	cWifiDNS[16];			//wifiap DNS
//	char	cWifiKeyType[16];		//wifiap KeyType��Hex��ASCII
//	char	cWifiPassword[128];		//wifiap password,
//	char	cEncryption[16];		//wifiap encrypttion flag; NULL no encryption��"WEP" encryption
//	char	cWifiKeyNum[2];         //wifiap KeyNum (1,2,3,4)
//	int		iPwdFormat;
//	int		iHaveCard;
//	int		iCardOnline;
//}NVS_WIFIAP_PARAM, *PNVS_WIFIAP_PARAM;

//����SDK4.0��3.3
typedef struct NVS_IPAndID
{
    char *m_pIP;
    char *m_pID;
	union
	{
		unsigned int *m_puiLogonID;
		int  *m_piLogonID;
	};
}*pNVS_IPAndID;

typedef struct			//���Ƶ�ͨ����Ϣ
{
	char    m_cParam1[64];
	char    m_cParam2[64];
	char    m_cParam3[64];
	char    m_cParam4[64];
	char    m_cParam5[64];
	char    m_cParam6[64];
	char    m_cParam7[64];
	char    m_cParam8[64];
	char    m_cParam9[64];
	char    m_cParam10[64];
	char    m_cParam11[64];
	char    m_cParam12[64];
	char    m_cParam13[64];
	char    m_cParam14[64];
	char    m_cParam15[64];
	char    m_cParam16[64];
	char    m_cParam17[64];
	char    m_cParam18[64];
	char    m_cParam19[64];
	char    m_cParam20[64];
}DZ_INFO_PARAM, *PDZ_INFO_PARAM;


#define MAX_PARAM_NUM 32

typedef struct STRCT_ParamPackage
{
	char			m_strParam[MAX_PARAM_NUM][256];
	int				m_iParam[MAX_PARAM_NUM];
	void*           m_lpVoid[MAX_PARAM_NUM];
	
}*pSTRCT_ParamPackage;
//--------------------------------------------------------

#ifndef HIWORD
#define HIWORD(l)   ((unsigned short) (((unsigned int) (l) >> 16) & 0xFFFF))
#endif

#ifndef LOWORD
#define LOWORD(l)   ((unsigned short) (l))
#endif

#define CHANNEL_INTERTALK	2		//˫��Խ�
#define CHANNEL_DOWNLOAD    3		//�ļ�����
#define STREAM_DOWNLOAD     CHANNEL_DOWNLOAD
#define CHANNEL_PICTURE     4		//ͼƬץ��    
#define CHANNEL_SIMUCAP  	5		//ģ��ץ����
#define CHANNEL_TRACK  	    6		//�켣��
#define CHANNEL_THREE_STREAM	254	//������

#define DOWNLOAD_CHANNEL_TAG  (250)

#define SERVER_NORMAL  0
#define SERVER_ACTIVE  1

#define DATA_RECEIVE_NOT  0      //û�н���
#define DATA_RECEIVE_WAIT 1      //�ȴ�����
#define DATA_RECEIVE_HEAD 2      //�Ѿ��յ���Ƶͷ�����ǻ�û���յ�����								 
#define DATA_RECEIVE_ING  3      //���ڽ���ing
#define DATA_RECEIVE_DIGITALCHANNEL_FAILED  4      //����ͨ��δ����

#define INFO_USER_PARA     0
#define INFO_CHANNEL_PARA  1
#define INFO_ALARM_PARA    2
#define INFO_VIDEO_HEAD    3

typedef void (*CMDSTRING_NOTIFY)(char *_cBuf,int _iLen,void* _pUserData); 
  
#define PROTOCOL_COUNT			64				//	���֧�ֵ�Э�����
#define PROTOCOL_NAME_LENGTH	32				//	����Э�����Ƶ���󳤶�
typedef struct
{
	int     iType;							   //������ 0�����豸֧�ֵ�Э��, 1��������ʹ�õ�Э��
	int		iCount;					           //������֧�ֵ�Э��������
	char 	cProtocol[PROTOCOL_COUNT][PROTOCOL_NAME_LENGTH];		//��Э�����ƣ����֧�ָ�Э�飬ÿ��Э��������ֽڣ�
} st_NVSProtocol;  

#ifdef WIN32
typedef struct
{
	char m_cIP[32];
	char m_cDeviceID[64];
	int  m_iLogonID;
	int  m_iChannel;
	int  m_iStreamNO;
	int  m_iDrawIndex;
}st_ConnectInfo,*pst_ConnectInfo;
#else
typedef struct
{
	char m_cIP[32];
	char m_cDeviceID[64];
	int  m_iLogonID;
	int  m_iChannel;
	int  m_iStreamNO;
	int  m_iDrawIndex;
	char m_cDownLoadFile[256];
}st_ConnectInfo,*pst_ConnectInfo;
#endif


#define CLIENT_DEFAULT 0       //���Ӵ����Ĭ�Ͽͻ���
#define CLIENT_DECODER 1       //�Խ��������⴦��

#define MAX_DATA_CHAN MAX_CHANNEL_NUM		//����������
#define MAX_FILE_CHAN 5

#define DATA_CMD  1
#define DATA_DATA 2
typedef void (*INNER_DATA_NOTIFY)(unsigned int _ulID,void *_pBlock,int _iType,int _iUser);

#define REC_FILE_TYPE_STOP      (-1)
#define REC_FILE_TYPE_NORMAL	0
#define REC_FILE_TYPE_AVI		1
#define REC_FILE_TYPE_ASF		2
#define REC_FILE_TYPE_AUDIO     3
#define REC_FILE_TYPE_RAWAAC    4
#define REC_FILE_TYPE_VIDEO     5


typedef struct					//  2010-1-26-18:09 @yys@
{
	int			iChannelNo;		//	ͨ����
	int			iLogType;		//	��־����
	int			iLanguage;		//	��������
	NVS_FILE_TIME	struStartTime;		//	��ʼʱ��
	NVS_FILE_TIME	struStopTime;		//	����ʱ��
	int			iPageSize;		//	ҳ��С
	int			iPageNo;		//	ҳ���
}NVS_LOG_QUERY, *PNVS_LOG_QUERY;

typedef struct  
{
	int				iChannel;
	int				iLogType;
	NVS_FILE_TIME	struStartTime; 	/* File start time */
	NVS_FILE_TIME	struStoptime; 	/* File end time */
	char			szLogContent[129];					
}NVS_LOG_DATA,*PNVS_LOG_DATA;

#define DOWNLOAD_TYPE_NOTHING		0
#define DOWNLOAD_TYPE_ERROR			1
#define DOWNLOAD_TYPE_PIC			2
#define DOWNLOAD_TYPE_VIDEO			3
#define DOWNLOAD_TYPE_TIMESPAN		4

typedef struct  
{
	int iPreset[32]	;				//Ԥ��λ�� ȡֵ��Χ��1-255	
	int	iStayTime[32];				//ͣ��ʱ�� ȡֵ��Χ��1-60	
	int	iSpeed[32];					//�ٶ�	   ȡֵ��Χ��0-100	
}st_PTZCruise,*Pst_PTZCruise;

/************************************************************************
*  CD-Burn �������                                                                    
************************************************************************/
#define		CDBURN_CMD_SET_MIN					0
#define		CDBURN_CMD_SET_START				(CDBURN_CMD_SET_MIN+0)				//	��ʼ��¼
#define		CDBURN_CMD_SET_STOP					(CDBURN_CMD_SET_MIN+1)				//	ֹͣ��¼
#define		CDBURN_CMD_SET_MODE					(CDBURN_CMD_SET_MIN+2)				//	���ÿ�¼ģʽ
#define		CDBURN_CMD_SET_RESUME				(CDBURN_CMD_SET_MIN+3)				//	������¼
#define		CDBURN_CMD_SET_MAX					(CDBURN_CMD_SET_MIN+4)

//#define		CDBURN_CMD_GET_MIN					(CDBURN_CMD_SET_MAX)			//	�����������չ������
#define		CDBURN_CMD_GET_MIN					(3)									//	Get��������
#define		CDBURN_CMD_GET_MODE					(CDBURN_CMD_GET_MIN+0)				//	�õ���¼ģʽ
#define		CDBURN_CMD_GET_CDROMLIST			(CDBURN_CMD_GET_MIN+1)				//	�õ���ǰ�����б�
#define		CDBURN_CMD_GET_CDROMCOUNT			(CDBURN_CMD_GET_MIN+2)				//	�õ���ǰ�����ĸ���
#define		CDBURN_CMD_GET_STATUS				(CDBURN_CMD_GET_MIN+3)				//	�õ���ǰ��¼״̬
#define		CDBURN_CMD_GET_MAX					(CDBURN_CMD_GET_MIN+4)

#define		CDBURN_MAX_COUNT				32			//	�������Ĺ�����

#define		CDBURN_STATUS_FREE				0		//	����δʹ��
#define		CDBURN_STATUS_BUSY				1		//	���ڿ�¼
#define		CDBURN_STATUS_BAD				2		//	��������
#define		CDBURN_STATUS_FULL				3		//	�����Ѿ���
#define		CDBURN_STATUS_PACK				4		//	�������ڴ��
#define     CDBURN_STATUS_BEGINFAILED       102     //  ��ʼ��¼ʧ�� 

#define		MAX_DVDNAME_LEN					31

struct TCDBurnStatus
{
	int				iCDRomID;					//	����ID
	int				iState;						//	��ǰ״̬
	unsigned long	ulTotal;					//	�ܴ�С
	unsigned long	ulFree;						//	�����С
	char			cReserved[4];				//	Ԥ��4���ֽ�
};

struct TCDBurnPolicy
{
	int				iCDRomID;								//	����ID��ֻ�ڵ��̿�¼ʱ����

	int				iMode;									//	0-���̿�¼, 1-����ͬ��, 2-ѭ����¼
	int				iChannelBits[CDBURN_MAX_COUNT];			//	ͨ���б���λʵ��
	int				iDeviceBits[CDBURN_MAX_COUNT];			//	�����б���λʵ��
	//��չ20121025
	int				iDiskType;								//	��������
	int				iBurnSpeed;								//	��¼�ٶ�
	int				iBurnHour;								//	��¼ʱ��
	int				iResSpace;								//	Ԥ���ռ�
	char			cDVDName[MAX_DVDNAME_LEN+1];			//	�����ļ���
};

struct TCBurnStopMode
{
	int             iDeviceNum;                            //�������
	int             iFlagByBits;                            //bit0: 1�����̣�0���̣�bit1��1�����̣� 0����
};       

/************************************************************************
*	��Ƶ���� Video Encrypt & Decrypt                                                                      
************************************************************************/
struct TVideoEncrypt
{
	int			iChannel;					//	����ͨ��, -1����ʾ����ͨ��
	int			iType;						//	��������, -- 0�������ܣ�1��AES����������չ
	int			iMode;						//	�����㷨�򷽷���Ŀǰ�ò���
	char		cPassword[17];				//	��������
};

struct TVideoDecrypt
{
	int			iChannel;							//	����ͨ��
	char		cDecryptKey[17];					//	������Կ
};

/************************************************************************
   Digital Channel Param  20110303                                                                   
************************************************************************/
#define DC_CMD_GET_MIN				0
#define DC_CMD_GET_ALL				(DC_CMD_GET_MIN+0)
#define DC_CMD_GET_IPCPnP			(DC_CMD_GET_MIN+2)
#define DC_CMD_GET_MAX				(DC_CMD_GET_MIN+3)

#define DC_CMD_SET_MIN				(0)
#define DC_CMD_SET_ALL				(DC_CMD_SET_MIN+1)
#define DC_CMD_SET_IPCPnP			(DC_CMD_SET_MIN+2)
#define DC_CMD_SET_MAX				(DC_CMD_SET_MIN+3)
/************************************************************************
   ����ͨ�����弴�ù���ģʽ
***********************************************************************/
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN         0
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_OFF        (DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN + 0)//�ر�
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_AUTO_ADD   (DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN + 1)//�Զ����
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_AUTO_FIND  (DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN + 2)//�Զ�����(��ʾ�û��ֶ����)
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MAX        (DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN + 0)

//  [12/15/2012]
#define	MAX_RTSPURL_LEN				(127)

//	Э������
#define SERVERTYPE_PRIVATE			(0)
#define SERVERTYPE_ONVIF			(1)
#define SERVERTYPE_PUSH				(2)
#define SERVERTYPE_RTSP				(3)

struct TDigitalChannelParam
{
	int iChannel;							//	[����ͨ����]--ȡֵ��Χ���豸���Ͷ�������¼ʱ����ͻ��˷�������ͨ����
	int	iEnable;							//	[ʹ��]--0�����ø�����ͨ����1�����ø�����ͨ����Ĭ��Ϊ����
	int iConnectMode;						//	[���ӷ�ʽ]--0��IP��1��������2������ģʽ��Ĭ��ΪIP
	int	iDevChannel;						//	[ǰ���豸ͨ����]--ȡֵ��Χ��ǰ���豸����������Ĭ��Ϊ0
	int iDevPort;							//	[ǰ���豸�˿ں�]--81��65535��Ĭ��Ϊ3000
	int iStreamType;						//	[��������]--0����������1����������Ĭ��Ϊ������
	int iNetMode;							//	[��������]--1��TCP��2��UDP��3���鲥���ݶ�ΪTCP,���ɸ���
	int iPtzAddr;							//	[PTZ��ַ]--0��256��Ϊ����ʹ��Ĭ��ֵ

	char cIP[33];							//	[���Ӳ���]--iConnectMode=0ʱ��IP��ַ��iConnectMode=1ʱ��������iConnectMode=2ʱ���豸ID��Ĭ��Ϊ�գ�����32���ַ�
	char cProxyIP[33];						//	[����IP]--iConnectMode=2ʱ�����ֶ���Ч��Ĭ��Ϊ�գ�����32���ַ�
	char cPtzProtocolName[33];				//	[PTZЭ��]--��¼�豸ʱ����ͻ��˷����豸֧�ֵ�PTZЭ���б�Ϊ����ʹ��Ĭ��ֵ������32���ַ�
	char cUserName[17];						//	[�û���]--��¼ǰ���豸���û���������Ϊ�գ�����16���ַ�
	char cPassword[17];						//	[����]--��¼ǰ���豸�����룬����Ϊ�գ�����16���ַ�
	char cEncryptKey[17];					//	[��Ƶ��������]--ǰ���豸��Ƶ���ܵ����룬Ϊ�����ʾ�����ܣ�����16���ַ�
	int iServerType;						//  ǰ���豸�����õ�����Э��(Miracle�����ֶ�)
											//  0:˽��Э�飨��TiandyЭ�飩
											//  1:OnvifЭ�飻
											//  2:Push��
											//	3:RTSP
	//  ��չRTSP url[12/15/2012]
	char cRTSPUrl[MAX_RTSPURL_LEN+1];		//	RTSP url
};

/************************************************************************
*	�õ��豸ͨ�������Բ���                                                                     
************************************************************************/
#define		CHANNEL_TYPE_LOCAL			0			//	����ģ��ͨ��
#define		CHANNEL_TYPE_DIGITAL		2			//	����ͨ��
#define		CHANNEL_TYPE_COMBINE		3			//	�ϳ�ͨ��

#define		CHANNEL_TYPE_MAINSTREAM		0			//	������
#define     CHANNEL_TYPE_SUBSTREAM      1           //	������
#define		CHANNEL_TYPE_THIRDSTREAM	4			//	������

#define GENERAL_CMD_MIN						0
#define GENERAL_CMD_GET_CHANNEL_TYPE		(GENERAL_CMD_MIN+1)			//	�õ����豸��ĳ��ͨ��������(��)
#define GENERAL_CMD_CHANNEL_TYPE			(GENERAL_CMD_MIN+1)			//	�õ����豸��ĳ��ͨ��������(��)
#define GENERAL_CMD_CHANTYPE_LIST			(GENERAL_CMD_MIN+2)			//	�õ����豸�ĸ�ͨ���ɱ༭������
#define GENERAL_CMD_MAX						(GENERAL_CMD_MIN+3)

/************************************************************************
* VCA ������ݽṹ�����ϲ����ʹ��,�����CMDIDʹ��enum���(sizeof(enum))��
	�����ǵ�CB��VC�ļ��������⣬ͳһʹ��#defineʵ��
************************************************************************/
#define VCA_MAX_RULE_NUM				8				//	ÿ��ͨ�����������������
#define VCA_MAX_EVENT_NUM				14				//	�����¼�����
#define VCA_MAX_TRIPWIRE_NUM			8				//	���ĵ����߸���
#define VCA_MAX_DBTRIPWIRE_NUM			4				//	����˫���߸���
														//
#define VCA_MAX_OSC_REGION_NUM			3				//	�����Ʒ��ʧ�������

#define VCA_MAX_RULE_NAME_LEN			17				//	�������Ƶĳ���

typedef int vca_EEventType;

#define VCA_EVENT_MIN							0						//	�¼�ID������ "[0,9)"
#define VCA_EVENT_TRIPWIRE						(VCA_EVENT_MIN+0)		//	�����¼�
#define VCA_EVENT_DBTRIPWIRE					(VCA_EVENT_MIN+1)		//	˫�����¼�
#define VCA_EVENT_PERIMETER						(VCA_EVENT_MIN+2)		//	�ܽ��¼�
#define VCA_EVENT_LOITER						(VCA_EVENT_MIN+3)		//	�ǻ��¼�
#define VCA_EVENT_PARKING						(VCA_EVENT_MIN+4)		//	ͣ���¼�
#define VCA_EVENT_RUN							(VCA_EVENT_MIN+5)		//	�����¼�
#define VCA_EVENT_HIGH_DENSITY					(VCA_EVENT_MIN+6)		//	��Ա�ܶ��¼�
#define VCA_EVENT_ABANDUM						(VCA_EVENT_MIN+7)		//	�������¼�
#define VCA_EVENT_OBJSTOLEN						(VCA_EVENT_MIN+8)		//	�������¼�
#define VCA_EVENT_FACEREC						(VCA_EVENT_MIN+9)		//	����ʶ���¼�
#define	VCA_EVENT_VIDEODETECT					(VCA_EVENT_MIN+10)		//	��Ƶ����¼�
#define	VCA_EVENT_TRACK							(VCA_EVENT_MIN+11)		//	�����¼�
#define	VCA_EVENT_FLUXSTATISTIC					(VCA_EVENT_MIN+12)		//	����ͳ���¼�
#define	VCA_EVENT_CROWD						    (VCA_EVENT_MIN+13)		//	��Ⱥ�ۼ��¼�
#define	VCA_EVENT_LEAVE_DETECT					(VCA_EVENT_MIN+14)		//	��ڼ���¼�
#define	VCA_EVENT_MAX							(VCA_EVENT_MIN+15)		//	��Ч�¼�ID���������


#define VCA_CMD_SET_MIN							1									//	VCA������������
#define VCA_CMD_SET_CHANNEL						(VCA_CMD_SET_MIN+ 0)				//	����VCAͨ���ż�ʹ��
#define VCA_CMD_SET_VIDEOSIZE					(VCA_CMD_SET_MIN+ 1)				//	����VCAͨ������Ƶ��С
#define VCA_CMD_SET_ADVANCE_PARAM				(VCA_CMD_SET_MIN+ 2)				//	����VCA�߼�����
#define VCA_CMD_SET_TARGET_PARAM				(VCA_CMD_SET_MIN+ 3)				//	����VCA���Ӳ�������ɫ����
#define VCA_CMD_SET_ALARM_STATISTIC				(VCA_CMD_SET_MIN+ 4)				//	����VCA��������Ϊ��
#define VCA_CMD_SET_RULE_COMMON					(VCA_CMD_SET_MIN+ 5)				//	����VCA���򳣹����
#define VCA_CMD_SET_RULE0_TRIPWIRE				(VCA_CMD_SET_MIN+ 6)				//	����VCA���򣨵����ߣ�
#define VCA_CMD_SET_RULE1_DBTRIPWIRE			(VCA_CMD_SET_MIN+ 7)				//	����VCA����˫���ߣ�
#define VCA_CMD_SET_RULE2_PERIMETER				(VCA_CMD_SET_MIN+ 8)				//	����VCA�����ܽ磩
#define VCA_CMD_SET_ALARM_SCHEDULE				(VCA_CMD_SET_MIN+ 9)				//	����VCA����ģ��
#define VCA_CMD_SET_ALARM_LINK					(VCA_CMD_SET_MIN+10)				//	����VCA��������˿�
#define VCA_CMD_SET_SCHEDULE_ENABLE				(VCA_CMD_SET_MIN+11)				//	����VCA����ʹ��
#define VCA_CMD_SET_RULE9_FACEREC				(VCA_CMD_SET_MIN+12)				//	����VCA��������ʶ��
#define VCA_CMD_SET_RULE10_VIDEODETECT			(VCA_CMD_SET_MIN+13)				//	����VCA������Ƶ��ϣ�
#define VCA_CMD_SET_RULE8_ABANDUM		        (VCA_CMD_SET_MIN+14)				//	����VCA���������
#define VCA_CMD_SET_RULE7_OBJSTOLEN             (VCA_CMD_SET_MIN+15)                //  ����VCA���򣨱����
#define VCA_CMD_SET_RULE11_TRACK	            (VCA_CMD_SET_MIN+16)                //  ����VCA���򣨸��٣�
#define	VCA_CMD_CALL_TRACK_NO					(VCA_CMD_SET_MIN+17)				//  ������ʼ����λ
#define VCA_CMD_SET_RULE12_FLUXSTATISTIC	    (VCA_CMD_SET_MIN+18)				//	����VCA��������ͳ��)
#define VCA_CMD_SET_RULE13_CROWD				(VCA_CMD_SET_MIN+19)				//	����VCA������Ⱥ�ۼ�)
#define VCA_CMD_SET_CHANNEL_ENABLE				(VCA_CMD_SET_MIN+20)				//	����VCAͨ��ʹ��(0:���������ܷ��� 1:���ñ���ͨ�����ܷ��� 2:����ǰ��ͨ�����ܷ���)
#define VCA_CMD_SET_RULE14_LEAVE_DETECT			(VCA_CMD_SET_MIN+21)				//	����VCA������ڼ��)
#define VCA_CMD_SET_MAX							(VCA_CMD_SET_MIN+22)				//	VCA������������


#define VCA_CMD_GET_MIN							(16)								//	VCA��ȡ��������,Ϊ�˼���VIDEODETECT֮ǰ�ĺ�
#define VCA_CMD_GET_CHANNEL						(VCA_CMD_GET_MIN+ 0)				//	��ȡVCAͨ���ż�ʹ��
#define VCA_CMD_GET_VIDEOSIZE					(VCA_CMD_GET_MIN+ 1)				//	��ȡVCAͨ������Ƶ��С
#define VCA_CMD_GET_ADVANCE_PARAM				(VCA_CMD_GET_MIN+ 2)				//	��ȡVCA�߼�����
#define VCA_CMD_GET_TARGET_PARAM				(VCA_CMD_GET_MIN+ 3)				//	��ȡVCA���Ӳ�������ɫ����
#define VCA_CMD_GET_ALARM_STATISTIC				(VCA_CMD_GET_MIN+ 4)				//	��ȡVCA��������
#define VCA_CMD_GET_RULE_COMMON					(VCA_CMD_GET_MIN+ 5)				//	��ȡVCA���򳣹����
#define VCA_CMD_GET_RULE0_TRIPWIRE				(VCA_CMD_GET_MIN+ 6)				//	��ȡVCA���򣨵����ߣ�
#define VCA_CMD_GET_RULE1_DBTRIPWIRE			(VCA_CMD_GET_MIN+ 7)				//	��ȡVCA����˫���ߣ�
#define VCA_CMD_GET_RULE2_PERIMETER				(VCA_CMD_GET_MIN+ 8)				//	��ȡVCA�����ܽ磩
#define VCA_CMD_GET_ALARM_LINK					(VCA_CMD_GET_MIN+ 9)				//	��ȡVCA��������˿�
#define VCA_CMD_GET_ALARM_SCHEDULE				(VCA_CMD_GET_MIN+10)				//	��ȡVCA����ģ��
#define VCA_CMD_GET_SCHEDULE_ENABLE				(VCA_CMD_GET_MIN+11)				//	��ȡVCA����ʹ��
#define VCA_CMD_GET_RULE9_FACEREC				(VCA_CMD_GET_MIN+12)				//	��ȡVCA��������ʶ��
#define VCA_CMD_GET_RULE10_VIDEODETECT			(VCA_CMD_GET_MIN+13)				//	��ȡVCA������Ƶ��ϣ�
#define VCA_CMD_GET_RULE8_ABANDUM			    (VCA_CMD_GET_MIN+14)				//	����VCA���������
#define VCA_CMD_GET_RULE7_OBJSTOLEN             (VCA_CMD_GET_MIN+15)				//  ����VCA���򣨱����
#define VCA_CMD_GET_RULE11_TRACK	            (VCA_CMD_GET_MIN+16)                //  ����VCA���򣨸��٣�
#define VCA_CMD_GET_RULE12_FLUXSTATISTIC	    (VCA_CMD_GET_MIN+18)				//	����VCA��������ͳ��)
#define VCA_CMD_GET_RULE13_CROWD				(VCA_CMD_GET_MIN+19)				//	����VCA������Ⱥ�ۼ�)
#define VCA_CMD_GET_CHANNEL_ENABLE				(VCA_CMD_GET_MIN+20)				//	��ȡVCAͨ��ʹ��(0:���������ܷ��� 1:���ñ���ͨ�����ܷ��� 2:����ǰ��ͨ�����ܷ���)
#define VCA_CMD_GET_STATISTIC_INFO				(VCA_CMD_GET_MIN+21)				//  ��ȡVCAͨ��������ͳ������
#define VCA_CMD_GET_RULE14_LEAVE_DETECT			(VCA_CMD_GET_MIN+22)				//  ��ȡVCA������ڼ�⣩
#define VCA_CMD_GET_MAX							(VCA_CMD_GET_MIN+23)				//	VCA��ȡ���������

#define VCA_ALARMLINK_MIN                        0
#define VCA_ALARMLINK_AUDIO	                    (VCA_ALARMLINK_MIN)                 //����������ʾ
#define VCA_ARARMLINK_SCREEMSHOW                (VCA_ALARMLINK_MIN + 1)             //������Ļ��ʾ
#define VCA_ALARMLINK_OUTPORT                   (VCA_ALARMLINK_MIN + 2)             //��������˿�
#define VCA_ALARMLINK_RECODER                   (VCA_ALARMLINK_MIN + 3)             //����¼��
#define VCA_ALARMLINK_PTZ                       (VCA_ALARMLINK_MIN + 4)             //����PTZ
#define VCA_ALARMLINK_CAPTUREPIC                (VCA_ALARMLINK_MIN + 5)             //����ץ��
#define VCA_ALARMLINK_SINGLEPIC					(VCA_ALARMLINK_MIN + 6)				//����������
#define VCA_ALARMLINK_MAX                       (VCA_ALARMLINK_MIN + 7)

#define VCA_ALARMTYPE_MIN                       0         
#define VCA_ALARMTYPE_VIDEOLOST                 (VCA_ALARMTYPE_MIN)                 //��Ƶ��ʧ
#define VCA_ALARMTYPE_PORT                      (VCA_ALARMTYPE_MIN + 1)				//�˿�
#define VCA_ALARMTYPE_MOVE						(VCA_ALARMTYPE_MIN + 2)				//�ƶ����
#define VCA_ALARMTYPE_COVER						(VCA_ALARMTYPE_MIN + 3)				//��Ƶ�ڵ�
#define VCA_ALARMTYPE_VCA						(VCA_ALARMTYPE_MIN + 4)				//���ܷ���
#define VCA_ALARMTYPE_MAX						(VCA_ALARMTYPE_MIN + 5)

#define VCA_LINKPTZ_TYPE_MIN                    0
#define VCA_LINKPTZ_TYPE_NOLINK                 (VCA_LINKPTZ_TYPE_MIN )          //������
#define VCA_LINKPTZ_TYPE_PRESET                 (VCA_LINKPTZ_TYPE_MIN + 1)		 //Ԥ��λ
#define VCA_LINKPTZ_TYPE_TRACK                  (VCA_LINKPTZ_TYPE_MIN + 2)		 //�켣
#define VCA_LINKPTZ_TYPE_PATH                   (VCA_LINKPTZ_TYPE_MIN + 3)		 //·��
#define VCA_LINKPTZ_TYPE_MAX                    (VCA_LINKPTZ_TYPE_MIN + 4)

/************************************************************************/
/* ���ܷ�����Ƶ�������                                                 */
/************************************************************************/
#define	VCA_AVD_NOISE 				(1<<0)   	//	�������
#define VCA_AVD_CLARITY				(1<<1)		//	���������
#define VCA_AVD_BRIGHT_ABMNL		(1<<2)		//	�����쳣���
#define VCA_ADV_COLOR				(1<<3)		//	ƫɫ���
#define VCA_ADV_FREEZE				(1<<4)		//	���涳�����
#define VCA_ADV_NOSIGNAL			(1<<5)		//	�źŶ�ʧ���
#define VCA_ADV_CHANGE				(1<<6)		//	�����任���
#define VCA_ADV_INTERFERE			(1<<7)		//	��Ϊ�������
#define VCA_ADV_PTZ_LOST_CTL		(1<<8)		//	PTZʧ�����


//����
#define	MAX_BITSET_NUM		4
#define	MAX_ALARM_LINKTYPE  6

// typedef enum __tagLinkPTZType
// {
// 	LINKPTZ_TYPE_MIN = 0,
// 	LINKPTZ_TYPE_NOLINK = LINKPTZ_TYPE_MIN,			//������
// 	LINKPTZ_TYPE_PRESET,						//Ԥ��λ
// 	LINKPTZ_TYPE_TRACK,							//�켣
// 	LINKPTZ_TYPE_PATH							//·��
// }ELinkPTZType, *PELinkPTZType;	
typedef int ELinkPTZType;
typedef int __tagLinkPTZType;
typedef int * PELinkPTZType ;
#define LINKPTZ_TYPE_MIN	0
#define LINKPTZ_TYPE_NOLINK LINKPTZ_TYPE_MIN
#define LINKPTZ_TYPE_PRESET 1
#define LINKPTZ_TYPE_TRACK  2
#define LINKPTZ_TYPE_PATH	3

//ʱ���
typedef struct __tagAlarmScheduleParam
{
	int				iBuffSize;

	int				iWeekday;								//	�����յ���������0-6��
	int				iParam1;
	int				iParam2;
	NVS_SCHEDTIME	timeSeg[MAX_DAYS][MAX_TIMESEGMENT];		//	ʱ���

	void*			pvReserved;									
}TAlarmScheduleParam, *PTAlarmScheduleParam;

//����ģ��ʹ��
typedef struct __tagAlarmScheEnableParam
{
	int				iBuffSize;

	int				iEnable;						//	����ģ��ʹ��
	int				iParam1;						//	ȡֵ��iAlarmType����
	int				iParam2;						//	ȡֵ��iAlarmType����
	int				iParam3;						//	����

	void*			pvReserved;									
}TAlarmScheEnableParam, *PTAlarmScheEnableParam;


struct vca_TPoint
{
	int iX;
	int	iY;
} ;					//	sizeof = 2*4 = 8

struct vca_TLine
{
	vca_TPoint 	stStart;
	vca_TPoint 	stEnd;
} ;						//	sizeof = 2*8 = 16

struct vca_TPolygon
{
	int 		iPointNum;
	vca_TPoint 	stPoints[VCA_MAX_POLYGON_POINT_NUM];   
} ;						//	sizeof = 32*8+4 = 260

struct vca_TDisplayParam
{
	int				iDisplayRule;			//	�Ƿ���ʾ���򣬱�����ߣ��ܽ���	
	int				iDisplayStat;			//	�Ƿ���ʾ��������
	int				iColor;					//	����ʱ����ɫ
	int				iAlarmColor;			//	����ʱ����ɫ
};	
				
struct vca_TAlarmTimeSegment
{
	int		iStartHour;					
	int		iStartMinute;
	int		iStopHour;
	int		iStopMinute;
	int		iEnable;
};				//	����ʱ���

struct vca_TAlarmSchedule
{
	int						iWeekday;					//	�����յ���������0-6��
	vca_TAlarmTimeSegment	timeSeg[7][4];				//	ʱ���
};			//	��������ģ��

struct vca_TLinkPTZ
{
	unsigned short	usType;								//	0��������ͨ����1Ԥ��λ��2�켣��3·��
	unsigned short	usPresetNO;							//	Ԥ��λ��
	unsigned short	usTrackNO;							//	�켣��
	unsigned short	usPathNO;							//	·����
};

//	��������
struct vca_TAlarmLink
{
	int						iLinkType;					//	0������������ʾ��1��������Ļ��ʾ��2����������˿ڣ�3������¼��4������PTZ��5������ץ��
	int						iLinkChannel;
	
	int						iLinkSet[6];				//	0,1,2,3,5
	vca_TLinkPTZ			ptz[MAX_CHANNEL_NUM];		//	4
};					

struct vca_TScheduleEnable
{
	int						iEnable;					//	�Ƿ�ʹ��	
	int						iParam;						//	����������
};

// �����߲���
struct vca_TTripwire
{
	int					iValid;					//	�Ƿ���Ч,�����ɹ����е�iEventID�ж��ĸ��¼���Ч���ɣ�
												//	��������й��򶼲���ЧʱiEventID�ܻ�ָ��һ���¼����ϲ��޷��ж��Ƿ������Ч��ֻ�ܼ�һ���¼���Ч�ֶ�
	int					iTargetTypeCheck;		//	Ŀ����������
	int					iMinDistance;			//	��С����,Ŀ���˶����������ڴ���ֵ
	int					iMinTime;				//	���ʱ��,Ŀ���˶����������ڴ���ֵ	
	int					iType;					//	��ʾ��Խ����
	int					iDirection;				//	�����߽�ֹ����Ƕ�
	vca_TLine			stLine;					//	��������
}; 

struct vca_TPerimeter
{
	int					iValid;					//	�Ƿ���Ч,�����ɹ����е�iEventID�ж��ĸ��¼���Ч���ɣ�
												//	��������й��򶼲���ЧʱiEventID�ܻ�ָ��һ���¼����ϲ��޷��ж��Ƿ������Ч��ֻ�ܼ�һ���¼���Ч�ֶ�
	int					iTargetTypeCheck;		//	�����˳�
	int					iMode;					//	���ģʽ
	int 				iMinDistance;			//	��С����
	int 				iMinTime;				//	���ʱ��		
	int					iType;					//	�Ƿ�����������
	int 				iDirection;				//	��ֹ����Ƕ�(��λ: �Ƕ�)
	vca_TPolygon		stRegion;				//	����Χ	
} ;		// �ܽ����

struct vca_TFaceRec
{
	int					iValid;					//	�Ƿ���Ч,�����ɹ����е�iEventID�ж��ĸ��¼���Ч���ɣ�
												//	��������й��򶼲���ЧʱiEventID�ܻ�ָ��һ���¼����ϲ��޷��ж��Ƿ������Ч��ֻ�ܼ�һ���¼���Ч�ֶ�
	vca_TPolygon		stRegion;				//	����Χ
};		//����ʶ�����

struct vca_TVideoDetection
{
	int					iValid;					//	�Ƿ���Ч,�����ɹ����е�iEventID�ж��ĸ��¼���Ч���ɣ�
												//	��������й��򶼲���ЧʱiEventID�ܻ�ָ��һ���¼����ϲ��޷��ж��Ƿ������Ч��ֻ�ܼ�һ���¼���Ч�ֶ�
	int					m_iCheckTime;
};

struct vca_tOSC
{
	int                 iValid;					//	�Ƿ���Ч,�����ɹ����е�iEventID�ж��ĸ��¼���Ч���ɣ�
	int                 iColor;					//������ɫ
	int					iAlarmColor;			//����ʱ������ɫ
	int					iMinTime;				//��������������ڵ����ʱ��
	int 				iMinSize;				//��С���سߴ�
	int 				iMaxSize;				//������سߴ�
	int 				iSunRegionCount;		//�Ӷ���θ���
	vca_TPolygon 		stMainRegion;			//�����������
	vca_TPolygon 		stSubRegion[VCA_MAX_OSC_REGION_NUM];	//�Ӷ��������
};

typedef	struct vca_tTrack
{
	int					m_iStartPreset;			//��ʼ���ٵ�
	vca_TPolygon		m_TrackRegion;			//��������
	int					m_iScene;				//������/��/С
	int					m_iWeekDay;				//����
	NVS_SCHEDTIME		m_timeSeg[MAX_DAYS][MAX_TIMESEGMENT];		//����ʱ���
}vca_tTrack, *LPvca_tTrack;

typedef	struct vca_tFluxStatistic
{
	int					iValid;					//	�Ƿ���Ч,�����ɹ����е�iEventID�ж��ĸ��¼���Ч���ɣ�
												//	��������й��򶼲���ЧʱiEventID�ܻ�ָ��һ���¼����ϲ��޷��ж��Ƿ������Ч��ֻ�ܼ�һ���¼���Ч�ֶ�
	vca_TPolygon		stRegion;				//	����Χ	
}vca_tFluxStatistic, *LPvca_tFluxStatistic;

typedef	struct vca_tCrowd
{
	int					iValid;					//	�Ƿ���Ч,�����ɹ����е�iEventID�ж��ĸ��¼���Ч���ɣ�
												//	��������й��򶼲���ЧʱiEventID�ܻ�ָ��һ���¼����ϲ��޷��ж��Ƿ������Ч��ֻ�ܼ�һ���¼���Ч�ֶ�
	vca_TPolygon		stRegion;				//	����Χ	
}vca_tCrowd, *LPvca_tCrowd;

#define  MAX_RULE_REGION_NUM	4
typedef struct vca_tLeaveDetect
{
	int					iValid;					//	���¼�����Ƿ���Ч,0����Ч 1����Ч
	int					iLeaveAlarmTime;		//	��ڱ���ʱ��,60~3600,��λ���� ,Ĭ��ֵ��120S
	int					iRuturnClearAlarmTime;	//	�ظ�����ʱ��,10~300,��λ����   Ĭ��ֵ��15S
	int					iAreaNum;				//	������������,1��4
	vca_TPolygon		stRegion[MAX_RULE_REGION_NUM];			//	����Χ	
}vca_tLeaveDetect, *LPvca_tLeaveDetect;

#define	EVENT_BUF_RESERVED		2048			//Ԥ����С
typedef union vca_UEventParam
{	
	char cBuf[EVENT_BUF_RESERVED];							//	������Ԥ���ռ��Ϊ2048
	vca_TTripwire		tripwire;
	vca_TPerimeter		perimeter;
	vca_TFaceRec		m_stFaceRec;
	vca_TVideoDetection	m_stVideoDetection;
	vca_tOSC            m_stOSC;
	vca_tTrack			m_stTrack;
	vca_tFluxStatistic  m_stFluxStatic;
	vca_tCrowd          m_stCrowd;
	vca_tLeaveDetect	m_stLeaveDetect;
}vca_UEventParam, *LPvca_UEventParam;
	
// �������ò���
struct vca_TRuleParam
{
	char 				cRuleName[VCA_MAX_RULE_NAME_LEN];	// ��������
	int					iValid;								// �ù����Ƿ���Ч

	vca_TDisplayParam	stDisplayParam;						//	��ʾʱ�Ĳ����趨

	int					iAlarmCount;						//	��������
	vca_TAlarmSchedule	alarmSchedule;						//	��������ģ�����
	vca_TAlarmLink		alarmLink;							//	�����������ò���
	vca_TScheduleEnable	scheduleEnable;						//	����ʹ��

	vca_EEventType		iEventID;							// ��Ϊ�����¼����� 
	vca_UEventParam		events;								// ��Ϊ�����¼�����
};	

// ���ܷ������ò���
struct vca_TConfig
{
	int		iVideoSize;						// ��Ƶ��С
	int		iDisplayTarget;					// �Ƿ����Ŀ���
	int		iDisplayTrace;					// �Ƿ���ӹ켣
	int		iTargetColor;					// Ŀ�����ɫ
	int		iTargetAlarmColor;				// ����ʱĿ�����ɫ
	int		iTraceLength;					// �켣����
};	  

// ���ܷ����߼�����
struct vca_TAdvParam
{
	int		iEnable; 					//�Ƿ����ø߼�����
	int		iTargetMinSize; 			//Ŀ����С������
	int		iTargetMaxSize; 			//Ŀ�����������
	int   	iTargetMinWidth;  			//�����
	int		iTargetMaxWidth;  			//��С���
	int		iTargetMinHeight;  			//���߶�
	int		iTargetMaxHeight;  			//��С�߶�
	int     iTargetMinSpeed;			//Ŀ����С�����ٶ�(-1Ϊ��������)
	int     iTargetMaxSpeed;			//Ŀ����������ٶ�(-1Ϊ��������)
	int 	iTargetMinWHRatio;			//��С�����
	int 	iTargetMaxWHRatio;			//��󳤿��
	int		iSensitivity;				//�����ȼ���
};	

struct TStatisticInfo
{
	int					iSize;								//�ṹ���С
	int					iFluxIn;							//��������
	int					iFluxOut;							//�뿪����
};

//���ܷ���ͨ������
struct vca_TVCAChannelParam
{
	int					iEnable;					//	�Ƿ�ʹ�ܴ�ͨ�����ܷ���
	vca_TConfig			config;  					//	���ܷ������ò���    	
	vca_TAdvParam		advParam;					//	���ܷ����߼�����

	int					iRuleID;
	vca_TRuleParam	rule[VCA_MAX_RULE_NUM]; 		//	�������ò���	
};

//	VCA���õĲ����ܼ�, 
struct vca_TVCAParam
{
	int						iEnable;								//	�Ƿ�ʹ�����ܷ���
	int						iChannelBit;							//	���ܷ���ͨ����Bit��

	int						iChannelID;								//	VCAͨ��
	vca_TVCAChannelParam	chnParam[MAX_CHANNEL_NUM];				//	ÿ��ͨ���Ĳ�������
};					

struct vca_TAlarmInfo
{
	int				iID;				//	������ϢID�����ڻ�ȡ�������Ϣ
	int				iChannel;			//	ͨ����
	int				iState;				//	����״̬
	int				iEventType;			//	�¼�����
	int				iRuleID;			//	����ID

	unsigned int	uiTargetID;			//	Ŀ��ID
	int				iTargetType;		//	Ŀ������
	RECT			rctTarget;			//	Ŀ��λ��
	int				iTargetSpeed;		//	Ŀ���ٶ�
	int				iTargetDirection;	//	Ŀ�귽��
};

/************************************************************************
* FTP ��ʱ�������                                                                     
************************************************************************/

//	FTP���Э��
#define FTP_CMD_SET_MIN				0
#define FTP_CMD_SET_SNAPSHOT		(FTP_CMD_SET_MIN+0)
#define FTP_CMD_SET_LINKSEND		(FTP_CMD_SET_MIN+1)
#define FTP_CMD_SET_TIMEDSEND		(FTP_CMD_SET_MIN+2)
#define FTP_CMD_SET_UPDATE			(FTP_CMD_SET_MIN+3)
#define FTP_CMD_SET_MAX				(FTP_CMD_SET_MIN+4)

//#define FTP_CMD_GET_MIN				(FTP_CMD_SET_MAX)		//	�����������չ������
#define FTP_CMD_GET_MIN				(4)
#define FTP_CMD_GET_SNAPSHOT		(FTP_CMD_GET_MIN+0)
#define FTP_CMD_GET_LINKSEND		(FTP_CMD_GET_MIN+1)
#define FTP_CMD_GET_TIMEDSEND		(FTP_CMD_GET_MIN+2)
#define FTP_CMD_GET_UPDATE			(FTP_CMD_GET_MIN+3)
#define FTP_CMD_GET_MAX				(FTP_CMD_GET_MIN+4)

struct FTP_SNAPSHOT
{
	int		iChannel;			//	ͨ�� 
	int		iEnable;			//	ʹ��
	int		iQValue;			//	����
	int		iInterval;			//	ʱ����
	int		iPictureSize;       //  ץ��ͼƬ��С	0x7fff�������Զ��������Ӧ�ֱ��ʴ�С
	int		iPicCount;			//  ץ��ͼƬ����
};

struct FTP_LINKSEND
{
	int		iChannel;			//	ͨ��
	int		iEnable;			//	ʹ��
	int		iMethod;			//	��ʽ
};

struct FTP_TIMEDSEND	
{
	int		iChannel;			//	ͨ��
	int		iEnable;			//	ʹ��
	int		iFileType;			//	�ļ�����
	int		iHour;				//	ʱ��(hour)
	int		iMinute;			//	ʱ��(Minute)
	int		iSecond;			//	����(Second)
};

struct FTP_UPDATE
{
	char	cFtpAddr[32];		//	����ʹ�õ�Ftp��ַ
	char	cFileName[32];		//	����ʹ�õ��ļ���
	char	cUserName[16];		//	����ʹ�õ��û���
	char	cPassword[16];		//	����ʹ�õ�����
	int		iPort;				//	�˿�
	int		iUsage;				//	��־λ��;
};

/************************************************************************
* 3G DVR �������
************************************************************************/
#define		DVR3G_CMD_SET_MIN					0
#define		DVR3G_CMD_SET_POWERDELAY			(DVR3G_CMD_SET_MIN+0)				//	��ʱ���ػ�
#define		DVR3G_CMD_SET_SIMNUM				(DVR3G_CMD_SET_MIN+1)				//	SIM����
#define		DVR3G_CMD_SET_GPSOVERLAY			(DVR3G_CMD_SET_MIN+2)				//	GPS��Ϣ
#define		DVR3G_CMD_SET_GPSFILTER				(DVR3G_CMD_SET_MIN+3)				//	GPS����
#define		DVR3G_CMD_SET_FTPUPLOAD_MODE		(DVR3G_CMD_SET_MIN+4)				//	Ftp�Զ��ϴ��ķ�ʽ
#define		DVR3G_CMD_SET_VPDN					(DVR3G_CMD_GET_MIN+5)				//	VPDN
#define		DVR3G_CMD_SET_MAX					(DVR3G_CMD_SET_MIN+6)

//#define		DVR3G_CMD_GET_MIN					(DVR3G_CMD_SET_MAX)					//	�����������չ������
#define		DVR3G_CMD_GET_MIN					(5)									//  Get��������
#define		DVR3G_CMD_GET_POWERDELAY			(DVR3G_CMD_GET_MIN+0)				//	��ʱ���ػ�
#define		DVR3G_CMD_GET_SIMNUM				(DVR3G_CMD_GET_MIN+1)				//	SIM����
#define		DVR3G_CMD_GET_GPSOVERLAY			(DVR3G_CMD_GET_MIN+2)				//	GPS��Ϣ
#define		DVR3G_CMD_GET_GPSFILTER				(DVR3G_CMD_GET_MIN+3)				//	GPS����
#define		DVR3G_CMD_GET_FTPUPLOAD_MODE		(DVR3G_CMD_GET_MIN+4)				//	Ftp�Զ��ϴ��ķ�ʽ
#define		DVR3G_CMD_GET_VPDN					(DVR3G_CMD_GET_MIN+5)				//	VPDN
#define		DVR3G_CMD_GET_MAX					(DVR3G_CMD_GET_MIN+6)

struct TDVR3GInfo
{
	int		iPowerDelayOnTime;						//	��ʱ������ʱ�䣬��������Χ0~999�룬 0��ʾ��ʱ������ʹ�ܡ�
	int		iPowerDelayOffTime;						//	��ʱ�ػ���ʱ�䣬������ ��Χ0~999�룬0��ʾ��ʱ�ػ���ʹ�ܡ�	
	int		iGpsOverlay[MAX_CHANNEL_NUM];			//	ʹ�ܵ���GPS��Ϣ����ͨ�����
	int		iGpsFilter;								//	bitset, 0-��ת��, 65535-����. GPGGA-bit 1��GPRMC-bit 2��GPVTG-bit 3��GPGLL-bit 4��GPGSA- bit 5, GPGSV-bit 6������λ��ʱ������
	char	cSimNum[33];							//	SIM���ţ������Ϊ32λ��
};

struct TDVR3GInfoEx
{
	TDVR3GInfo	dvr3GInfo;
	int			iFtpUploadMode;					//	�ϴ���ʽ
	char		cReserved[64];					//	Ԥ���ֶ�
};

#define DVR3G_VPDN_MAX_LEN 32

struct TDVR3GVPDN
{
	int iSize;
	char cDialNumber[DVR3G_VPDN_MAX_LEN];	//�������
	char cAccount[DVR3G_VPDN_MAX_LEN];		//�˺�
	char cPassword[DVR3G_VPDN_MAX_LEN];		//����
};

/************************************************************************
* �໭��ϳ�                                                                     
************************************************************************/
struct TVideoCombine 
{
	int     iPicNum;     		// �ϳɻ�����
	int		iRec;  				// �ϳ�λ��
	char	cChannelID[300];   	// �ϳ�ͨ����Ϣ
};

/************************************************************************
* ����                                                                     
************************************************************************/
#define MAX_MIX_NUM 300
typedef struct __tagAudioMix
{	
	int		iEnable;					//����ʹ��
	int		iChannel;					//��Ƶ�ϳ�ͨ����ͨ����
	char	cMixChannels[MAX_MIX_NUM];	//��Դ���
	void*	pvReserved;					//��������,ͬʱҲ��Ϊ����TVideoCombine�Ĵ�С����
}TAudioMix,	*PTAudioMix;


/************************************************************************
* SIPЭ�����                                                                     
************************************************************************/
#define SIP_CMD_GET_MIN						0
#define SIP_CMD_GET_ALARMCHANNEL			(SIP_CMD_GET_MIN+0)
#define SIP_CMD_GET_VIDEOCHANNEL			(SIP_CMD_GET_MIN+1)
#define SIP_CMD_GET_MAX						(SIP_CMD_GET_MIN+2)

//#define SIP_CMD_SET_MIN						(SIP_CMD_GET_MAX)		//	�����������չ������
#define SIP_CMD_SET_MIN						(2)
#define SIP_CMD_SET_ALARMCHANNEL			(SIP_CMD_SET_MIN+0)
#define SIP_CMD_SET_VIDEOCHANNEL			(SIP_CMD_SET_MIN+1)
#define SIP_CMD_SET_MAX						(SIP_CMD_SET_MIN+2)

struct TSipVideoChannel
{
	int		iChannelNo;
	char	cChannelID[33];
	int		iLevel;
	int		iPtzTime;
};

struct TSipAlarmChannel
{
	int		iChannelNo;
	char	cChannelID[33];
	int		iLevel;
};

#define CHARSET_LENGTH          32              //  ��ʾ�ַ����ַ�������
#define LANGUAGE_COUNT			255				//	���֧�ֵ����Ը���
#define LANGUAGE_NAME_LENGTH	32				//	�����������Ƶ���󳤶�
typedef struct
{
	int    iCount;
	char   cLanguage[LANGUAGE_COUNT][LANGUAGE_NAME_LENGTH];
} st_NVSLanguageList;

typedef struct
{
	unsigned long nWidth;
	unsigned long nHeight;
	unsigned long nStamp;
	unsigned long nType;
	unsigned long nFrameRate;
	unsigned long nReserved;
}PSPACK_INFO;

//2012-04-22
/************************************************************************
* �������ݻص��ṹ�����                                                                     
************************************************************************/
#define 	DTYPE_MIN			0
#define 	DTYPE_H264_MP		(DTYPE_MIN + 0)
#define     DTYPE_RAW_AUDIO		(DTYPE_MIN + 1)
#define 	DTYPE_PS			(DTYPE_MIN + 2)
#define 	DTYPE_MAX			(DTYPE_MIN + 2)

typedef void (*RAWH264_MP_NOTIFY)(unsigned int _ulID, unsigned char* _cData, 
								  int _iLen, RAWFRAME_INFO *_pRawFrameInfo, int _iUser);

typedef void (*RAW_AUDIO_NOTIFY)(unsigned int _ulID, unsigned char* _cData, int _iLen, int Type, void* _pvUserData);
//PS���ص��봿��Ƶ�ص�һ��
typedef RAW_AUDIO_NOTIFY	PS_STREAM_NOTIFY;

//PS����װ�Ļص����� 
typedef void (*PSPACK_NOTIFY)(unsigned long _ulID, unsigned char* _ucData, int _iSize, PSPACK_INFO* _pPsPackInfo, void* _pContext);

/************************************************************************/
/*                   �����ݻص�                                         */
/************************************************************************/

//������Ϣ�ص�
typedef void (*ALARM_NOTIFY_V4)(int _ulLogonID, int _iChan, int _iAlarmState,ALARMTYPE _iAlarmType,int _iUser);

//�豸�����ı�ص�   
typedef void (*PARACHANGE_NOTIFY_V4)(int _ulLogonID, int _iChan, PARATYPE _iParaType,STR_Para* _strPara,int _iUser);

//���ص�����,����֪ͨ�豸�����ߡ���Ƶ���ݵ������Ϣ��_iWparam����WCM_LOGON_NOTIFY����Ϣ����
typedef void (*MAIN_NOTIFY_V4)(int _ulLogonID,int _iWparam, int _iLParam,int _iUser); 

//���������ص�
typedef void (*COMRECV_NOTIFY_V4)(int _ulLogonID, char *_cData, int _iLen,int _iComNo,int _iUser); 

//����������Ƶ����
typedef void (*DECYUV_NOTIFY_V4)(unsigned int _ulID,unsigned char *_cData, int _iLen, const FRAME_INFO *_pFrameInfo, int _iUser);


#define UPGRADE_PROGRAM			1		//	��������
#define UPGRADE_WEB				2		//	��ҳ����

typedef void (*UPGRADE_NOTIFY_V4)(int _iLogonID, int _iServerState, int _iUserData);


typedef void (__stdcall *RECVDATA_NOTIFY)(unsigned long _ulID,unsigned char* _ucData,int _iLen);		//	������ʹ�ô˻ص�����
typedef void (__stdcall *RECVDATA_NOTIFY_EX)(unsigned long _ulID, unsigned char* _ucData,int _iLen, int _iFlag, void* _lpUserData);

#ifdef WIN32
typedef void (__stdcall *LOGON_NOTIFY)(int _iLogonID, int _iLogonState);
typedef void (__stdcall *ALARM_NOTIFY)(int _iLogonID, int _iCh, void* _vContext,ALARMTYPE _iAlarmType);
typedef void (__stdcall *PARACHANGE_NOTIFY)(int _iLogonID, int _iCh, PARATYPE _iParaType,LPVOID _strPara);
typedef void (__stdcall *MAIN_NOTIFY)(int _iLogonID,int _iWParam,int _iLParam, void* _lpNoitfyUserData);
typedef void (__stdcall *ALARM_NOTIFY_EX)(int _iLogonID, int _iChannel, void* _vContext,ALARMTYPE _iAlarmType, void* _lpNoitfyUserData);
typedef void (__stdcall *PARACHANGE_NOTIFY_EX)(int _iLogonID, int _iChannel, PARATYPE _iParaType,LPVOID _strPara, void* _lpNoitfyUserData);
typedef void (__stdcall *COMRECV_NOTIFY)(int _iLogonID, char *_buf, int _length,int _iComNo);
typedef void (__stdcall *DECYUV_NOTIFY)(unsigned long _ulID, unsigned char* _ucData, int _iSize, FRAME_INFO *_pFrameInfo, void* _pContext);
//�����ں˳���
typedef void (__stdcall *PROUPGRADE_NOTIFY)(int _iLogonID,int _iServerState);
//������ҳ
typedef void (__stdcall *WEBUPGRADE_NOTIFY)(int _iLogonID,int _iServerState);    
#else
typedef void (*ALARM_NOTIFY)(int _ulLogonID, int _iChan, int _iAlarmState,ALARMTYPE _iAlarmType,int _iUser);
typedef void (*PARACHANGE_NOTIFY)(int _ulLogonID, int _iChan, PARATYPE _iParaType,STR_Para* _strPara,int _iUser);
typedef void (*MAIN_NOTIFY)(int _ulLogonID,int _iWparam, int _iLParam,int _iUser); 
typedef void (*COMRECV_NOTIFY)(int _ulLogonID, char *_cData, int _iLen,int _iComNo,int _iUser);
typedef void (*DECYUV_NOTIFY)(unsigned int _ulID,unsigned char *_cData, int _iLen, const FRAME_INFO *_pFrameInfo, int _iUser);
//�����ں˳���
typedef void (*PROUPGRADE_NOTIFY)(int _iLogonID,int _iServerState,int _iUser);
//������ҳ
typedef void (*WEBUPGRADE_NOTIFY)(int _iLogonID,int _iServerState,int _iUser);    
#endif

//ͨ����ش洢����
#define STORAGE_CMD_MIN 0
#define STORAGE_CMD_STORAGE_RULE STORAGE_CMD_MIN+0
#define STORAGE_CMD_MAX STORAGE_CMD_MIN+1

#define STORAGE_RULE_MIN 0
#define STORAGE_RULE_RECORD_AUDIO STORAGE_RULE_MIN+0
#define STORAGE_RULE_STORAGE_TIME STORAGE_RULE_MIN+1
#define STORAGE_RULE_EXTRACT_FRAME STORAGE_RULE_MIN+2
#define STORAGE_RULE_REDUNDANCE_RECORD STORAGE_RULE_MIN+3
#define STORAGE_RULE_SUB_RECORD STORAGE_RULE_MIN+4
#define STORAGE_RULE_SUB_STORAGE_TIME STORAGE_RULE_MIN+5
#define STORAGE_RULE_MAX STORAGE_RULE_MIN+6
typedef struct STORAGE_RULE
{
	int			iSize;		//Size of the structure,must be initialized before used
	int			iType;		//�������� 0:�Ƿ��¼��Ƶ 1:����ʱ��(��λ:��) 2:�Ƿ�����֡���� 3���Ƿ�������¼��
	int			iValue;		//����ֵ iType = 0��2��3ʱ��0:����¼�򲻿��� 1:��¼����;
							//iType = 1ʱ����ΧΪ[0,60]��0��ʾ��ǿ��ִ�й��ڲ������������󸲸ǡ�
}*PSTORAGE_RULE;


//************************************************************************/
//*							��������
//************************************************************************/
#define MAX_LAN_NUM						2
#define MAX_WIFICARD_NUM				2

#define LAN_CMD_SET_MIN					0
#define LAN_CMD_SET_IPV4				(LAN_CMD_SET_MIN+0)
#define LAN_CMD_SET_IPV6				(LAN_CMD_SET_MIN+1)
#define LAN_CMD_SET_WORKMODE			(LAN_CMD_SET_MIN+2)
//#define LAN_CMD_SET_LANNUM			(LAN_CMD_SET_MIN+3)
#define LAN_CMD_SET_DHCP				(LAN_CMD_SET_MIN+4)
#define LAN_CMD_SET_WIFIDHCPMODE		(LAN_CMD_SET_MIN+5)
#define LAN_CMD_SET_WIFIWORKMODE		(LAN_CMD_SET_MIN+6)
#define LAN_CMD_SET_WIFIAPDHCPPARA		(LAN_CMD_SET_MIN+7)
#define LAN_CMD_SET_WIFIAPPARA			(LAN_CMD_SET_MIN+8)
#define LAN_CMD_SET_WIFIPARA			(LAN_CMD_SET_MIN+9)
#define LAN_CMD_SET_MAX					(LAN_CMD_SET_MIN+10)

#define LAN_CMD_GET_MIN					0
#define LAN_CMD_GET_IPV4				(LAN_CMD_GET_MIN+0)
#define LAN_CMD_GET_IPV6				(LAN_CMD_GET_MIN+1)
#define LAN_CMD_GET_WORKMODE			(LAN_CMD_GET_MIN+2)
#define LAN_CMD_GET_LANNUM				(LAN_CMD_GET_MIN+3)
#define LAN_CMD_GET_DHCP				(LAN_CMD_GET_MIN+4)
#define LAN_CMD_GET_WIFIDHCPMODE		(LAN_CMD_GET_MIN+5)
#define LAN_CMD_GET_WIFIWORKMODE		(LAN_CMD_GET_MIN+6)
#define LAN_CMD_GET_WIFIAPDHCPPARA		(LAN_CMD_GET_MIN+7)
#define LAN_CMD_GET_WIFIAPPARA			(LAN_CMD_GET_MIN+8)
#define LAN_CMD_GET_WIFIPARA			(LAN_CMD_GET_MIN+9)
#define LAN_CMD_GET_MAX					(LAN_CMD_GET_MIN+10)

typedef struct LANPARAM_IPV4 
{
	int iSize;						//sizeof(LANPARAM_IPV4)
	int iLanNo;						//������� 0:Lan1 1:Lan2	
	int iLanType;					//�������� Ԥ������0���ɡ�
	//Ĭ��10M/100M/1000M����Ӧ�����ɸ��ġ�
	char cIP[LENGTH_IPV4];			//IPV4 IP��ַ			
	char cMask[LENGTH_IPV4];		//IPV4 ��������
	char cGateway[LENGTH_IPV4];		//IPV4 Ĭ������
	char cDNS[LENGTH_IPV4];			//IPV4 ��ѡDNS������
	char cBackDNS[LENGTH_IPV4];		//IPV4 ����DNS������
	char cReserved[64];				//Ԥ������0���ɡ�
	//�����Ժ������������Ե���չ������MTU					
} *PLANPARAM_IPV4;

typedef struct LANPARAM_IPV6 
{
	int iSize;						//sizeof(LANPARAM_IPV6)
	int iLanNo;						//������� 0:Lan1 1:Lan2	
	int iPrefixLen;					//IPV6 ����ǰ׺����
	char cIP[LENGTH_IPV6];			//IPV6 IP��ַ	
	char cGateway[LENGTH_IPV6];		//IPV6 Ĭ������
	char cDNS[LENGTH_IPV6];			//IPV6 ��ѡDNS������
	char cBackDNS[LENGTH_IPV6];		//IPV6 ����DNS������
	char cReserved[64];				//Ԥ������0���ɡ�
	//����IPV6��صĻ������Կ���ͨ�����ֶ�ʵ�֡�					
} *PLANPARAM_IPV6;

typedef struct LANPARAM_WORKMODE 
{
	int iSize;						//sizeof(LANPARAM_WORKMODE)
	int iWorkMode;					//����ģʽ	0:���ؾ��� 1:�����ݴ� 2:��ַ�趨					
	int iMainLanNo;					//��������� 0:Lan1 1:Lan2					
} *PLANPARAM_WORKMODE;

typedef struct LANPARAM_DHCP 
{
	int iSize;						//sizeof(LANPARAM_WORKMODE)
	int iLanNo;						//������� 0:Lan1 1:Lan2	
	int iEnable;					//DHCPʹ�� 0:ͣ�� 1:���� 
} *PLANPARAM_DHCP;
//add wifi&wifiap
typedef struct WIFIPARAM_DHCP       //cb@120711
{
	int iSize;						//sizeof(WIFIPARAM_DHCP)
	int iWifiDHCPMode;				//��������ģʽ 0:��������0 DHCP�� 1:��������0 apģʽDHCP	
	int iEnable;					//DHCPʹ�� 0:ͣ�� 1:���� 
	int iReserved;                  //����չ���� PS��Ŀǰֻ��һ����������������DHCP����
} *PWIFIPARAM_DHCP;

typedef struct WIFIAPDHCPPARA_DHCP       
{
	int iSize;						//sizeof(WIFIAPDHCPPARA_DHCP)
	int iDHCPStart;					//DHCP���䷶Χ��ʼ	
	int iDHCPEnd;					//DHCP���䷶Χ���� 
	int iDHCPLease;                //DHCP����
} *PWIFIAPDHCPPARA_DHCP;

typedef struct ITS_OSD
{
	int iX;
	int iY;
	int iEnable;
} *PITS_OSD;

// typedef	enum __tagAlarmLinkType
// {
// 	ALARM_LINKTYPE_AUDIO = 0,
// 	ALARM_LINKTYPE_VIDEO,
// 	ALARM_LINKTYPE_OUTPORT,
// 	ALARM_LINKTYPE_RECORD,
// 	ALARM_LINKTYPE_PTZ,
// 	ALARM_LINKTYPE_SNAPSHOT
// }EAlarmLinkType, *PEAlarmLinkType;
typedef int __tagAlarmLinkType;
typedef int EAlarmLinkType;
typedef int *PEAlarmLinkType;

//modify by zhy 2013.03.06
//////////////////////////////////////General AlarmLinkType////////////////////////////////////
#define ALARMLINKTYPE_MIN                               0  
#define ALARMLINKTYPE_LINKSOUND			(ALARMLINKTYPE_MIN + 0)		//����������ʾ
#define ALARMLINKTYPE_LINKDISPLAY		(ALARMLINKTYPE_MIN + 1)		//������Ļ��ʾ
#define ALARMLINKTYPE_LINKOUTPORT		(ALARMLINKTYPE_MIN + 2)     //��������˿� 
#define ALARMLINKTYPE_LINKRECORD     	(ALARMLINKTYPE_MIN + 3)     //����¼��  
#define ALARMLINKTYPE_LINKPTZ	     	(ALARMLINKTYPE_MIN + 4)     //����PTZ  
#define ALARMLINKTYPE_LINKSNAP   	    (ALARMLINKTYPE_MIN + 5)     //����ץ�� 
#define ALARMLINKTYPE_LINKSINGLEPIC		(ALARMLINKTYPE_MIN + 6)		//����������

//����IE
#define ALARM_LINKTYPE_AUDIO		ALARMLINKTYPE_LINKSOUND			//����������ʾ
#define ALARM_LINKTYPE_VIDEO		ALARMLINKTYPE_LINKDISPLAY		//������Ļ��ʾ
#define ALARM_LINKTYPE_OUTPORT		ALARMLINKTYPE_LINKOUTPORT		//��������˿� 
#define ALARM_LINKTYPE_RECORD		ALARMLINKTYPE_LINKRECORD		//����¼��  
#define ALARM_LINKTYPE_PTZ			ALARMLINKTYPE_LINKPTZ			//����PTZ  
#define ALARM_LINKTYPE_SNAPSHOT		ALARMLINKTYPE_LINKSNAP   		//����ץ��
#define ALARM_LINKTYPE_SINGLEPIC	ALARMLINKTYPE_LINKSINGLEPIC		//����������

typedef struct __tagAlarmLink
{
	int				iLinkSetSize;
	int				iLinkSet[MAX_ALARM_LINKTYPE*MAX_BITSET_NUM];	
	//ȡֵ��iLinkType����,MAX_BITSET_NUM������չ����0 Type��0+MAX_ALARM_LINKTYPEΪͬһ���������͵Ĳ���������Ϊ��չ
	//iLinkType=0,1ʱ��iLinkSet�ж�Ӧλ�����ݱ�ʾʹ��iEnable��0����ʹ�ܣ�1��ʹ�ܡ�
	//iLinkType=2,3,5ʱ��iLinkSet�ж�Ӧλ�����ݱ�ʾ��λʹ��iEnableByBits��
	//�����λ�����λÿһλ��ʾһ������Ƶͨ��/����˿ڵ�ʹ�ܡ�
	//iLinkType=4ʱ��iLinkSe��Ӧλ������t��ʾ������ͨ����

	int				iPtzSize;
	struct			vca_TLinkPTZ		ptz[MAX_CHANNEL_NUM];		//iLinkType=4ʱ�洢����PTZ�Ĳ���
}TAlarmLink, *PTAlarmLink;							//	������������

typedef struct __tagAlarmLinkParam
{
	int				iBuffSize;

	int				iAlarmTypeParam;				//	�������Ͳ���
	//	ȡֵ��iAlarmType����������iAlarmTypeΪ���ܷ�������iAlarmTypeParam��ʾiRuleID
	int				iReserved;						//	ȡֵ��iAlarmType����������iAlarmTypeΪ���ܷ�������iAlarmTypeParam��ʾiEventID
	int				iLinkType;
	union
	{
		int iChannelSet[4];
		int iEnable;								//�����������ô˽ṹ
		struct
		{
			TAlarmLink		stLinkContent;				//	��������
			void*			pvReserved;		
		};										
	};
}TAlarmLinkParam, *PTAlarmLinkParam;

/************************************************************************/
/* ͨ�ñ�������															*/
/************************************************************************/
//����
// typedef enum __tagAlarmSetCmd
// {
// 	CMD_SET_ALARMSCHEDULE = 0,
// 	CMD_SET_ALARMLINK,
// 	CMD_SET_ALARMSCH_ENABLE
// }EAlarmSetCmd, *PEAlarmSetCmd;
typedef int __tagAlarmSetCmd;
typedef int EAlarmSetCmd;
typedef int * PEAlarmSetCmd;
#define CMD_SET_ALARMSCHEDULE	0
#define CMD_SET_ALARMLINK		1
#define CMD_SET_ALARMSCH_ENABLE 2
#define CMD_SET_ALARMTRIGGER	3

// typedef enum __tagAlarmGetCmd
// {
// 	CMD_GET_ALARMSCHEDULE = 0,
// 	CMD_GET_ALARMLINK,
// 	CMD_GET_ALARMSCH_ENABLE
// }EAlarmGetCmd, *PEAlarmGetCmd;
typedef int __tagAlarmGetCmd;
typedef int EAlarmGetCmd;
typedef int * PEAlarmGetCmd;
#define CMD_GET_ALARMSCHEDULE	0
#define CMD_GET_ALARMLINK		1
#define CMD_GET_ALARMSCH_ENABLE 2
#define CMD_GET_ALARMTRIGGER	3

//����������ʶ
#define ATPI_AUDIO_LOST			0		//��Ƶ��ʧ������������
#define AUDIO_LOST_PARAM_COUNT	1		

//������ֵ����
typedef struct __tagAlarmTriggerParam
{
	int				iBuffSize;
	int				iType;				//	��������
	int				iID;				//	����������ʶ
	int				iValue;				//	����ֵ
}TAlarmTriggerParam, *PTAlarmTriggerParam;


//////////////////////////////////////ALARM CLEAR TYPE////////////////////////////////////CMD_GET_ALARMSCHEDULE

#define  ALARM_TYPE_MIN                          0
#define  ALARM_TYPE_VIDEO_LOST					 (ALARM_TYPE_MIN)       //��Ƶ��ʧ
#define  ALARM_TYPE_PORT_ALARM                   (ALARM_TYPE_MIN + 1)   //�˿ڱ���            
#define  ALARM_TYPE_MOTION_DETECTION			 (ALARM_TYPE_MIN + 2)   //�ƶ����
#define  ALARM_TYPE_VIDEO_COVER					 (ALARM_TYPE_MIN + 3)   //��Ƶ�ڵ�
#define	 ALARM_TYPE_VCA							 (ALARM_TYPE_MIN + 4)	//���ܷ���
#define  ALARM_TYPE_AUDIOLOST					 (ALARM_TYPE_MIN + 5)	//��Ƶ��ʧ
#define  ALARM_TYPE_TEMPERATURE                  (ALARM_TYPE_MIN + 6)	//��ʪ��
#define  ALARM_TYPE_EXCPETION				     (ALARM_TYPE_MIN + 100) //�쳣����
#define  ALARM_TYPE_ALL							 (ALARM_TYPE_MIN + 255) //ȫ��
#define  ALARM_TYPE_MAX                          (ALARM_TYPE_ALL + 1)

///////////////////////////////////////ExceptionType///////////////////////////////////

#define  EXCEPTION_TYPE_MIN						0
#define  EXCEPTION_TYPE_DISK_FULL				(EXCEPTION_TYPE_MIN + 0)  //������			
#define  EXCEPTION_TYPE_NO_DISK					(EXCEPTION_TYPE_MIN + 1)  //�޴���
#define  EXCEPTION_TYPE_DISK_IO_ERROR			(EXCEPTION_TYPE_MIN + 2)  //���̶�д����
#define  EXCEPTION_TYPE_NOALLOW_ACCESS			(EXCEPTION_TYPE_MIN + 3)  //�Ƿ�����
#define  EXCEPTION_TYPE_IP_COLLISION			(EXCEPTION_TYPE_MIN + 4)  //IP��ͻ
#define  EXCEPTION_TYPE_NETWORK_INTERRUPT		(EXCEPTION_TYPE_MIN + 5)  //�����ж�
#define  EXCEPTION_TYPE_SYSTEM_BUSY				(EXCEPTION_TYPE_MIN + 6)  //ϵͳæ	
#define  EXCEPTION_TYPE_NO_REDUNDANCY_DISK		(EXCEPTION_TYPE_MIN + 7)  //��������
#define  EXCEPTION_TYPE_ABNORMAL_VOLTAGE		(EXCEPTION_TYPE_MIN + 8)  //��ѹ�쳣
#define  EXCEPTION_TYPE_MAC_COLLISION			(EXCEPTION_TYPE_MIN + 9)  //MAC��ͻ
#define  EXCEPTION_TYPE_MAX						(EXCEPTION_TYPE_MIN + 10)	

//////////////////////////////////////Exception Handle////////////////////////////////////
#define  EXCEPTION_HANDLE_ENABLE                 0x01         //ʹ���쳣���� 
#define  EXCEPTION_HANDLE_DIALOG				 0x02         //�Ƿ񵯳���ʾ�Ի���
#define  EXCEPTION_HANDLE_LINK_BELL              0x04         //�Ƿ�����������
#define  EXCEPTION_HANDLE_LINK_NETCLIENT         0x08         //�Ƿ�֪ͨ����ͻ���

//////////////////////////////////////AlarmLinkType////////////////////////////////////
#define ALARMLINKTYPE_MIN                               0  
#define ALARMLINKTYPE_VIDEOLOST_LINKRECORD     	(ALARMLINKTYPE_MIN + 0)   //��Ƶ��ʧ��������¼��    
#define ALARMLINKTYPE_VIDEOLOST_LINKSNAP   	    (ALARMLINKTYPE_MIN + 1)   //��Ƶ��ʧ��������ץ�� 
#define ALARMLINKTYPE_VIDEOLOST_LINKOUTPORT     (ALARMLINKTYPE_MIN + 3)   //��Ƶ��ʧ��������˿� 
#define ALARMLINKTYPE_MOTIONDETECT_LINKRECORD   (ALARMLINKTYPE_MIN + 4)   //�ƶ���ⱨ������¼�� 
#define ALARMLINKTYPE_MOTIONDETECT_LINKSNAP     (ALARMLINKTYPE_MIN + 5)   //�ƶ���ⱨ������ץ��
#define ALARMLINKTYPE_MOTIONDETECT_LINKOUTPORT 	(ALARMLINKTYPE_MIN + 6)   //�ƶ������������˿� 
#define ALARMLINKTYPE_PORTALARM_LINKRECORD     	(ALARMLINKTYPE_MIN + 7)   //�˿ڱ�������¼��
#define ALARMLINKTYPE_PORTALARM_LINKSNAP       	(ALARMLINKTYPE_MIN + 8)   //�˿ڱ�������ץ��
#define ALARMLINKTYPE_PORTALARM_LINKOUTPORT    	(ALARMLINKTYPE_MIN + 9)   //�˿ڱ�����������˿�
#define ALARMLINKTYPE_MAX					   	(ALARMLINKTYPE_PORTALARM_LINKOUTPORT + 1)

/************************************************************************/
/*  ���ܽ�ͨ ���Ӿ���*/
/************************************************************************/

#define SN_ENCRYPT_TYPE_MASK					0x01
#define SN_ENCRYPT_TYPE_RECOGNIZE_ARITHMETIC	0x00			//ʶ���㷨��������
#define SN_ENCRYPT_TYPE_PROGRAM					0x01			//�����������

#define SYSTEM_TYPE_MASK					0x04					
#define SYSTEM_TYPE_DEBUG					0x00				//����
#define SYSTEM_TYPE_GATE					0x03				//����
#define SYSTEM_TYPE_ECOP					0x04				//�羯

#define SN_REG_MASK							0x02				
#define SN_REG_RECOGNIZE_DOG				0x01				//ʶ��
#define SN_REG_ENCRYPT_DOG					0x02				//���ܽ�ͨ���ܹ�



//IPC 3MP
#define MAX_CHANNEL_TYPE		2
#define MAX_REALTYPE_NUM        2  //ʵʱ�����������࣬0���������ʵʱ����ֵ��1�����ʵʱ�����Ϣ

struct STRCT_REAL_STATE 
{
	int        m_iTypes[MAX_REALTYPE_NUM];  //ÿ��type��typeֵ
	int        m_iValues[MAX_REALTYPE_NUM]; //ÿ��type��Ӧ��ʵʱ����
};

//ITScb@121010
//���������չ
////CMD����
///************************************************************************
//*	�������ʱ���                                                                     
//************************************************************************/
//#define ITS_CMD_SET_MIN                         0
//#define ITS_CMD_SET_TIMERANGE_ENABLE			0                           //����ʱ���ʹ��
//#define ITS_CMD_SET_TIMERANGE_AGCBLOCK			1							//����ʱ��β������ʹ��
//#define ITS_CMD_SET_TIMERANGE_FLASHLAMP			2							//����ʱ��������ʹ��
//
//#define ITS_CMD_GET_TIMERANGE_ENABLE			3							//��ȡʱ���ʹ��
//#define ITS_CMD_GET_TIMERANGE_AGCBLOCK			4							//��ȡʱ��β������ʹ��
//#define ITS_CMD_GET_TIMERANGE_FLASHLAMP			5							//��ȡʱ��������ʹ��
///************************************************************************/
///*   ���ܽ�ͨ��������                                                                 
///************************************************************************/
//#define ITS_ROADWAY_CMD_SET_MIN     0
//#define ITS_ROADWAY_CMD_SET_ENABLE  (ITS_ROADWAY_CMD_SET_MIN + 0)	    //���ó���ʹ��
//#define ITS_ROADWAY_CMD_SET_LOOP    (ITS_ROADWAY_CMD_SET_MIN + 1)		//���ó�����Ȧ
//#define ITS_ROADWAY_CMD_SET_TIME    (ITS_ROADWAY_CMD_SET_MIN + 2)		//���ó���ʱ��
//#define ITS_ROADWAY_CMD_SET_SPEED   (ITS_ROADWAY_CMD_SET_MIN + 3)		//���ó����ٶ�
//#define ITS_ROADWAY_CMD_SET_RECO    (ITS_ROADWAY_CMD_SET_MIN + 4)		//���ò⵽ʶ������
//#define ITS_ROADWAY_CMD_SET_VLOOP   (ITS_ROADWAY_CMD_SET_MIN + 5)		//����������Ȧ
//#define ITS_ROADWAY_CMD_SET_LIGHT   (ITS_ROADWAY_CMD_SET_MIN + 6)		//���ó����źŵ�
//#define ITS_ROADWAY_CMD_SET_CAPTURE (ITS_ROADWAY_CMD_SET_MIN + 7)		//���ó���ץ��
//#define ITS_ROADWAY_CMD_SET_REFERENCELINE	(ITS_ROADWAY_CMD_SET_MIN + 8)		//���ó�������
//#define ITS_ROADWAY_CMD_SET_MAX     (ITS_ROADWAY_CMD_SET_MIN + 9)		//
//
//#define ITS_ROADWAY_CMD_GET_MIN     0
//#define ITS_ROADWAY_CMD_GET_ENABLE  (ITS_ROADWAY_CMD_GET_MIN + 0)	    //��ó���ʹ��
//#define ITS_ROADWAY_CMD_GET_LOOP    (ITS_ROADWAY_CMD_GET_MIN + 1)		//��ó�����Ȧ
//#define ITS_ROADWAY_CMD_GET_TIME    (ITS_ROADWAY_CMD_GET_MIN + 2)		//��ó���ʱ��
//#define ITS_ROADWAY_CMD_GET_SPEED   (ITS_ROADWAY_CMD_GET_MIN + 3)		//��ó����ٶ�
//#define ITS_ROADWAY_CMD_GET_RECO    (ITS_ROADWAY_CMD_GET_MIN + 4)		//��ò⵽ʶ������
//#define ITS_ROADWAY_CMD_GET_VLOOP   (ITS_ROADWAY_CMD_GET_MIN + 5)		//���������Ȧ
//#define ITS_ROADWAY_CMD_GET_LIGHT   (ITS_ROADWAY_CMD_GET_MIN + 6)		//��ó����źŵ�
//#define ITS_ROADWAY_CMD_GET_CAPTURE (ITS_ROADWAY_CMD_GET_MIN + 7)		//��ó���ץ��
//#define ITS_ROADWAY_CMD_GET_REFERENCELINE	(ITS_ROADWAY_CMD_GET_MIN + 8)	//���ó�������
//#define ITS_ROADWAY_CMD_GET_MAX     (ITS_ROADWAY_CMD_GET_MIN + 9)		//
///************************************************************************/
///*	���ܽ�ͨ�����Ż�
///************************************************************************/
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN                   0
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_FIRST_HZ				(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 0)	    //���ó����Ż��׺���
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_NOPLATE_ENABLE		(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 1)		//�����Ƿ��������Ƴ�
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_OTHER					(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 2)		//���ô��������ƺͲ����ų���
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MAX					(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 3)		//
//
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN                   0										   		
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_FIRST_CHARACTER       (ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 0)		//��ó����Ż��׺���
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_NOPLATE_ENABLE		(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 1)		//����Ƿ��������Ƴ�
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_OTHER					(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 2)		//��ô��������ƺͲ����ų���
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MAX					(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 3)		//
///************************************************************************/
///*  ��ͨΥ�¼����  
///************************************************************************/
//#define ITS_EXTRAINFO_CMD_SET_MIN								 0
////Υͣ��Ŀ
//#define ITS_ILLEGALPARK_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 0)	    //����Υ��ͣ������
//#define ITS_ILLEGALPARKPARM_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 1)		//����Υ��ͣ���궨�������
//#define ITS_LICENSEOPTIMIZEOTHER_CMD_SET						(ITS_EXTRAINFO_CMD_SET_MIN + 2)		//���ô��������ƺͲ����ų���
//#define ITS_OPTIM_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 3)		//���ó����Ż��׺���
//#define ITS_RECOPARAM_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 4)		//����ʶ���㷨����
//#define ITS_ROADWAYENABLE_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 5)		//���ó���
//#define ITS_CAMLOCATION_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 6)		//�����豸��Ϣ
//#define ITS_EXACTCONFIRM_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 7)		//���þ�ȷ��λ��Ϣ
////�������
//#define ITS_VIDEODECTECT_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 8)		//ͼ�������
//#define ITS_DETECTAREA_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 10)	//�켣��������������
//#define ITS_RECOTYPE_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 11)	//�㷨���Ͳ���
////��ͨһ���
//#define ITS_REDLIGHTDETECTAREA_CMD_SET							(ITS_EXTRAINFO_CMD_SET_MIN + 12)	//���ú�Ƽ���������
//#define ITS_ENABLE_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 13)	//���ý�ͨ��ع���ʹ��Э��
//
//#define ITS_EXTRAINFO_CMD_SET_MAX								(ITS_EXTRAINFO_CMD_SET_MIN + 15)	//
//
//#define ITS_EXTRAINFO_CMD_GET_MIN								 0
////Υͣ��Ŀ
//#define ITS_ILLEGALPARK_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 0)	    //���Υ��ͣ������
//#define ITS_ILLEGALPARKPARM_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 1)		//���Υ��ͣ���궨�������
//#define ITS_LICENSEOPTIMIZEOTHER_CMD_GET						(ITS_EXTRAINFO_CMD_GET_MIN + 2)		//��ô��������ƺͲ����ų���
//#define ITS_OPTIM_CMD_GET										(ITS_EXTRAINFO_CMD_GET_MIN + 3)		//��ó����Ż��׺���
//#define ITS_RECOPARAM_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 4)		//���ʶ���㷨����
//#define ITS_ROADWAYENABLE_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 5)		//��ó���
//#define ITS_CAMLOCATION_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 6)		//����豸��Ϣ
////�������
//#define ITS_VIDEODECTECT_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 7)		//ͼ�������
//#define ITS_DETECTAREA_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 9)		//�켣��������������
//#define ITS_RECOTYPE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 10)	//�㷨���Ͳ���
//#define ITS_CAMRATYPE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 11)	//�������
////��ͨһ���
//#define ITS_REDLIGHTDETECTAREA_CMD_GET							(ITS_EXTRAINFO_CMD_SET_MIN + 12)	//��ú�Ƽ���������
//#define ITS_ENABLE_CMD_GET										(ITS_EXTRAINFO_CMD_SET_MIN + 13)	//��ý�ͨ��ع���ʹ��Э��
//#define ITS_VERSIONPRO_CMD_GET									(ITS_EXTRAINFO_CMD_SET_MIN + 14)	//�������汾��Ϣ
//
//#define ITS_EXTRAINFO_CMD_GET_MAX								(ITS_EXTRAINFO_CMD_GET_MIN + 15)	//
////CMD����END ���鱣��ԭλ��ע�ͣ��Ա���ز�����ͬһ��λ�ã���߿ɶ���

/************************************************************************
*	��������������                                                                   
************************************************************************/
#define MAX_ITS_BLOCK        5  


struct ITS_TBlock  
{
	int iX;					
	int iY;
};

struct ITS_TOTAL_TBlock
{
	ITS_TBlock block[MAX_ITS_BLOCK];
};
/************************************************************************
*	�������ʱ���                                                                     
************************************************************************/
#define ITS_CMD_SET_TIMERANGE_ENABLE			0                           //����ʱ���ʹ��
#define ITS_CMD_SET_TIMERANGE_AGCBLOCK			1							//����ʱ��β������ʹ��
#define ITS_CMD_SET_TIMERANGE_FLASHLAMP			2							//����ʱ��������ʹ��

#define ITS_CMD_GET_TIMERANGE_ENABLE			3							//��ȡʱ���ʹ��
#define ITS_CMD_GET_TIMERANGE_AGCBLOCK			4							//��ȡʱ��β������ʹ��
#define ITS_CMD_GET_TIMERANGE_FLASHLAMP			5							//��ȡʱ��������ʹ��

#define MAX_ITS_TIMERANGE                8

struct ITS_TTimeRange 
{
	int iEnable;								//�Ƿ����ø�ʱ��Σ�1-���ã�0-������
	int iTimeRange;								//ʱ�䷶Χ�� bit24-bit31:��ʼСʱ
	//					bit16-bit23:��ʼ����
	//					bit8-bit15:����Сʱ
	//					bit0-bit7:��������	
};

struct ITS_TOTAL_TTimeRange 
{
	ITS_TTimeRange timerange[MAX_ITS_TIMERANGE];
};
/************************************************************************
*	�������ʱ���ͨ�ò���                                                                     
************************************************************************/
#define MAX_ITS_TEMPLATE                8
#define MAX_TIME_RANGE_PARAM  			25
struct ITS_TTimeRangeParam 
{
	int iType;							// 0-�������� 1-�����ع� 2-���ð�ƽ�� 3-��������
	int iAutoEnable[MAX_TIME_RANGE_PARAM];	//  1��1-�Զ���0-�ֶ���
	//	2������˵����iTypeΪ12ʱ��0-�չ�ģʽ��1-ӫ���ģʽ��2-�����а�ƽ�⣩��
	//	3��iTypeΪ255ʱ������1-�Զ���0-�ֶ���
	//  4��iTypeΪ8ʱ1-�Զ�����ͨģʽ����0-�ֶ� 2-�Զ���ר��ģʽ��3-ITS���3D���뼶��   //add by wd @20130619
	int iParam1[MAX_TIME_RANGE_PARAM];		//0--��Ȧ���ڣ��ֶ��£��������ֵ���Զ��£�1������Ȧ��0�رչ�Ȧ��
	//1--����̬��1��������0����ر�
	//2--���ⲹ����1��������0����ر�
	//3--�ع�ʱ�䣺�ֶ��£��������ֵ���Զ��£���������ֵ
	//4--���ŵ��ڣ��ֶ��£��������ֵ���Զ��£���������ֵ
	//5--������ڣ��ֶ��£��������ֵ���Զ��£���������ֵ
	//6--gamma���ڣ��ֶ��£��������ֵ���Զ��£���������ֵ
	//7--��ȵ��ڣ��ֶ��£��������ֵ���Զ��£���������ֵ
	//8--������ڣ��ֶ��£��������ֵ���Զ�(��ģʽ)�£���������ֵ���Զ�(ר��ģʽ)�£�����2D��������ֵ   ITS���3D���뼶��3-�ߣ�2-�У�1-�ͣ�0-��� //add by wd @20130619
	//9--�ع����򣺴������Ͻ�X����
	//10--���ⲹ�����򣺴������Ͻ�X����
	//11--AF�������ã��������Ͻ�X����
	//12--Ŀ�����ȵ��ڣ��ֶ��£��������ֵ���Զ��£���������ֵ
	//13--��ƽ����ڣ��ֶ��£������ƽ���R������0-255���Զ��£������ƽ���R����У��ϵ������Χ100-200������Ϊ5
	//14--jpegͼ������
	//15--lutʹ��
	//16--�Զ����ȵ���ʹ��
	int iParam2[MAX_TIME_RANGE_PARAM];		//0--��Ȧ���ڣ�δʹ��
	//1--����̬��δʹ��
	//2--���ⲹ����δʹ��
	//3--�ع�ʱ�䣺�ֶ��£�δʹ�ã��Զ��£���������ֵ
	//4--���ŵ��ڣ��ֶ��£�δʹ�ã��Զ��£���������ֵ
	//5--������ڣ��ֶ��£�δʹ�ã��Զ��£���������ֵ
	//6--gamma���ڣ��ֶ��£�δʹ�ã��Զ��£���������ֵ
	//7--��ȵ��ڣ��ֶ��£�δʹ�ã��Զ��£���������ֵ
	//8--������ڣ��ֶ��£�δʹ�ã��Զ�(��ģʽ)�£�δʹ�ã��Զ�(ר��ģʽ)�£�����3D��������ֵ
	//9--�ع����򣺴������Ͻ�Y����
	//10--���ⲹ�����򣺴������Ͻ�Y����
	//	11--AF�������ã��������Ͻ�Y����
	//12--Ŀ�����ȵ��ڣ��ֶ��£��������ֵ���Զ��£���������ֵ
	//13--��ƽ����ڣ��ֶ��£������ƽ���G������0-255���Զ��£������ƽ���G����У��ϵ������Χ100-200������Ϊ5
	//14--jpegͼ������
	//15--lutʹ��
	//16--�Զ����ȵ���ʹ��
	int iParam3[MAX_TIME_RANGE_PARAM];		//0--��Ȧ���ڣ�δʹ��
	//1--����̬��δʹ��
	//	2--���ⲹ����δʹ��
	//3--�ع�ʱ�䣺�ֶ��£�δʹ�ã��Զ��£���������ֵ
	//4--���ŵ��ڣ��ֶ��£�δʹ�ã��Զ��£���������ֵ
	//5--������ڣ��ֶ��£�δʹ�ã��Զ��£���������ֵ
	//6--gamma���ڣ��ֶ��£�δʹ�ã��Զ��£���������ֵ
	//7--��ȵ��ڣ��ֶ��£�δʹ�ã��Զ��£���������ֵ
	//8--������ڣ��ֶ��£�δʹ�ã��Զ��£�δʹ��
	//9--�ع����򣺴������½�X����
	//10--���ⲹ�����򣺴������½�X����
	//11--AF�������ã��������½�X����
	//12--Ŀ�����ȵ��ڣ��ֶ��£��������ֵ���Զ��£���������ֵ
	//13--��ƽ����ڣ��ֶ��£������ƽ���B������0-255���Զ��£������ƽ���B����У��ϵ������Χ100-200������Ϊ5
	//14--jpegͼ������
	//15--lutʹ��
	//16--�Զ����ȵ���ʹ��
	int iParam4[MAX_TIME_RANGE_PARAM];		//0--��Ȧ���ڣ�δʹ��
	//1--����̬��δʹ��
	//2--���ⲹ����δʹ��
	//3--�ع�ʱ�䣺δʹ��
	//4--���ŵ��ڣ�δʹ��
	//5--������ڣ�δʹ��
	//6--gamma���ڣ�δʹ��
	//7--��ȵ��ڣ�δʹ��
	//8--������ڣ�δʹ��
	//9--�ع����򣺴������½�Y����
	//10--���ⲹ�����򣺴������½�Y����
	//11--AF�������ã��������½�Y����
	//12--Ŀ�����ȵ��ڣ�δʹ��
	//13--��ƽ����ڣ�δʹ��
	//14--jpegͼ������
	//15--lutʹ��
	//16--�Զ����ȵ���ʹ��
};

struct ITS_TOTAL_TTimeRangeParam 
{
	ITS_TTimeRangeParam timerangeparam[MAX_ITS_TEMPLATE +1];
};

struct ITS_TTemplateMap 
{
	int iTemplateID;					//ģ����
	char cTemplateName[64];				//ģ������
};

struct ITS_TOTAL_TTemplateMap 
{
	ITS_TTemplateMap templatemap[MAX_ITS_TIMERANGE];
};

typedef struct ITS_ILLEGALRECORD
{
	long m_lCarID;
	int  m_iRecordFlag;
	int  m_iIllegalType;
	int  m_iPreset;
}*pITS_ILLEGALRECORD;

/************************************************************************
*	�����������ģʽ                                                                    
************************************************************************/
struct ITS_CamWorkMode 
{
	int iWorkMode;							//����ģʽ  0-����ģʽ   1-����ģʽ
	int iInterval;								//ʱ����	
};

/************************************************************************/
//*   ���ܽ�ͨ��������                                                                 
/************************************************************************/

//��9��ʼGET/SETʹ��ͳһ�ĺ궨�壬����ʱע���޸�ITS_ROADWAY_CMD_GET_MAX/ITS_ROADWAY_CMD_SET_MAX��ֵ
#define ITS_ROADWAY_CMD_SET_MIN				0
#define ITS_ROADWAY_CMD_SET_ENABLE			(ITS_ROADWAY_CMD_SET_MIN + 0)	    //���ó���ʹ��
#define ITS_ROADWAY_CMD_SET_LOOP			(ITS_ROADWAY_CMD_SET_MIN + 1)		//���ó�����Ȧ
#define ITS_ROADWAY_CMD_SET_TIME			(ITS_ROADWAY_CMD_SET_MIN + 2)		//���ó���ʱ��
#define ITS_ROADWAY_CMD_SET_SPEED			(ITS_ROADWAY_CMD_SET_MIN + 3)		//���ó����ٶ�
#define ITS_ROADWAY_CMD_SET_RECO			(ITS_ROADWAY_CMD_SET_MIN + 4)		//���ò⵽ʶ������
#define ITS_ROADWAY_CMD_SET_VLOOP			(ITS_ROADWAY_CMD_SET_MIN + 5)		//����������Ȧ
#define ITS_ROADWAY_CMD_SET_LIGHT			(ITS_ROADWAY_CMD_SET_MIN + 6)		//���ó����źŵ�
#define ITS_ROADWAY_CMD_SET_CAPTURE			(ITS_ROADWAY_CMD_SET_MIN + 7)		//���ó���ץ��
#define ITS_ROADWAY_CMD_SET_REFERENCELINE	(ITS_ROADWAY_CMD_SET_MIN + 8)		//���ó�������
#define ITS_ROADWAY_CMD_CHNLCARSPEED        (ITS_ROADWAY_CMD_SET_MIN + 9)		//����/��ȡ ������ͬ�������͵��ٶȼ�����
#define ITS_ROADWAY_CMD_SET_MAX				(ITS_ROADWAY_CMD_SET_MIN + 10)		

#define ITS_ROADWAY_CMD_GET_MIN				0
#define ITS_ROADWAY_CMD_GET_ENABLE			(ITS_ROADWAY_CMD_GET_MIN + 0)	    //��ó���ʹ��
#define ITS_ROADWAY_CMD_GET_LOOP			(ITS_ROADWAY_CMD_GET_MIN + 1)		//��ó�����Ȧ
#define ITS_ROADWAY_CMD_GET_TIME			(ITS_ROADWAY_CMD_GET_MIN + 2)		//��ó���ʱ��
#define ITS_ROADWAY_CMD_GET_SPEED			(ITS_ROADWAY_CMD_GET_MIN + 3)		//��ó����ٶ�
#define ITS_ROADWAY_CMD_GET_RECO			(ITS_ROADWAY_CMD_GET_MIN + 4)		//��ò⵽ʶ������
#define ITS_ROADWAY_CMD_GET_VLOOP			(ITS_ROADWAY_CMD_GET_MIN + 5)		//���������Ȧ
#define ITS_ROADWAY_CMD_GET_LIGHT			(ITS_ROADWAY_CMD_GET_MIN + 6)		//��ó����źŵ�
#define ITS_ROADWAY_CMD_GET_CAPTURE			(ITS_ROADWAY_CMD_GET_MIN + 7)		//��ó���ץ��
#define ITS_ROADWAY_CMD_GET_REFERENCELINE	(ITS_ROADWAY_CMD_GET_MIN + 8)		//��ó�������
#define ITS_ROADWAY_CMD_GET_MAX				(ITS_ROADWAY_CMD_GET_MIN + 10)		

#define MAX_ROADWAY_COUNT					4          //��󳵵���
#define MAX_LOOP_COUNT						4          //�����������Ȧ��
#define DAY_OR_NIGHT						2          //0---���죬1---����

#define LIGHT_COUNT_EX                      8                   //�źŵ��� 
#define LIGHT_COUNT							4					//�źŵ���
#define LIGHT_COM_COUNT						4					//�źŵƴ�����
#define CAPTURE_PLACE_COUNT					3					//������Ӧ��ץ��λ����Ŀ

#define CAPTURE_TYPE_MASK					0x01FF				// ��������8λ [4/19/2012 hanyongqiang]
#define CAPTURE_TYPE_GATE					0x01				//����
#define CAPTURE_TYPE_RED_LIGHT				0x02				//����� 
#define CAPTURE_TYPE_REVERSE				0x04				//����
#define CAPTURE_TYPE_OVERSPEED				0x08				//����

//���������չ
#define	MAX_ITS_REFLINE_NUM		25
#define MAX_ITS_DETECTMODE		5

struct TITSRoadwayInfo 
{
	int iRoadwayID;
	int  iEnable;
	char cChannelName[32];
	char cChannelDir[32];
};

struct TITSRoadwayInfoEx
{
	int iRoadwayID;
	int  iEnable;
	char cChannelName[51];
	char cChannelDir[32];
};

//add by wd @20130531 ���ó�����Ϣ ��չ
typedef struct __tagTITSRoadwayInfo_V1
{
	int  iBufSize;                //��������ṹ��ĳ���(���Զ���)
	int  iRoadwayID;              //������� ���֧��4��������0-3
	int  iEnable;                 //����ʹ�ܱ�־  1-ʹ�ܣ�0-��ʹ��
	char cChannelName[51];        //��������  ���Ȳ�����50�ַ�
	char cChannelDir[32];         //��������  ���Ȳ�����31�ַ�
	int	 iChannelDownUp;          //����������  0-���У�1-����
	//add by wd 20130619 ��չ�ֶ� ����
	int  iUses;                   //������; 0-��ͨ������1-�ǻ���������2-��������,3-С����������
} TITSRoadwayInfo_V1, *PTITSRoadwayInfo_V1;
//add ended

struct TITSRoadWayLoop
{
	int iRoadwayID;
	int iComportNo;
	int iSpeedLoopNo;
	int iCaptureLoopNo;
};

struct TITSRoadwayTime
{
	int iRoadwayID;
	int iLoopMaxTime;
	int iLoopMinTime;
	int iLoopDelayTime;
};

struct TITSRoadwaySpeed
{
	int iRoadwayID;
	int iLoopDistance;
	int iSpeedLimit;
	int iSpeedModify;
};

struct TITSRoadwayReco
{
	int iRoadwayID;
	int iRoadwayRange;
};

struct TITSRoadwayVLoop
{
	int iRoadwayID;
	int iLoopID;
	int iDayNight;
	int iPoint1[DAY_OR_NIGHT][MAX_LOOP_COUNT];
	int iPoint2[DAY_OR_NIGHT][MAX_LOOP_COUNT];
	int iPoint3[DAY_OR_NIGHT][MAX_LOOP_COUNT];
	int iPoint4[DAY_OR_NIGHT][MAX_LOOP_COUNT];
};

struct TITSRoadwayLight			//�źŵ�
{
	int iRoadwayID;
	int iComNo;				//�źŵƶ�Ӧ�Ĵ��ںţ���Χ0-2������0��1ΪRS232���ڣ�2ΪRS485���ڣ�
	int iFloodID;			//����Ʊ��,��λ					
	char cLightID[32];	//�����źŵ�,��ʽ4,0,1,2,3����(��һλ��ʾһ�������ƣ��������4·��Ƽ��������Χ0-3��)					
};
//���������չ
typedef struct __tagTITSRoadwayLight_V1
{
	TITSRoadwayLight m_stLight;
	int				 m_iCompelRedlight;		//ǿ�ƺ��
}TITSRoadwayLight_V1, *PTITSRoadwayLight_V1;

struct TITSRoadwayCapture			//ץ��λ��
{
	int iRoadwayID;                         //�������   ���֧��4��������0-3
	int iType;							//����ץ������
	//bit0--����
	//bit1--����� 
	//bit2--���� 
	//bit3--����
	//bit4--��ֹ����ʻץ�� 
	//bit5--��ֹ����ʻץ�� 
	//bit6--ѹ����ץ��
	//bit7--�ǻ�����ץ��
	//bit8--�����涨������ʻ (����������ʻ)
	//bit9--��ֱֹ��    //add by wd @20130619 ��չ
	//bit10--��������
	//bit11--ѹ������
	//bit12--��ת���򴳺��
	//bit13--Υ��ͣ��  //add end
	char cPlace[CAPTURE_PLACE_COUNT][64];	//����������Ȧʱ��ץ��λ��
	//0������ץ��
	//1�������������Ȧʱץ��
	//2�����뿪������Ȧʱץ��
	//3��������ץ����Ȧʱץ��
	//4�����뿪ץ����Ȧʱץ��
	//5������ʱץ��
	//�����ͽ��У�����1,2,3,4
	int iChannelTpye;                       //���
	//0--��ת����
	//1--��ת����
	//2--ֱ�г���
	//3--��תֱ�г���
	//4--��תֱ�г���
	//5--�ǻ������� ---Ԥ��                 //modify by wd @20130619 
	//6--��ת��ת����
	//7--��ת�����Ӵ�ת��
	int iRecognizePlace;                   //ʶ�����
	//0--ʶ���һ��
	//1--ʶ��ڶ���
	//2--��ʶ���һ����ʶ��ڶ���,ȡ���ŶȸߵĽ��
	//3--ʶ��ڶ���,���δʶ������,��ʶ���һ��
	//4--ʶ���һ��,���δʶ������,��ʶ��ڶ���
	//5��ʶ�������                        //add by wd @20130619 
};

struct ITS_RecoParamEx					//�������ʶ���㷨��չ����   
{
	int iMaxPlateNO;					//�������
	int iMaxPlateWidth;					//����ƿ��
	int iMinPlateWidth;					//��С���ƿ��
	int iRoadwayID;						//�������
	int iEnable;						//ʹ�ܱ�־	0������ʶ��1������ʶ��					
	int iEngineNum;						//ʶ���������	�ݲ�֧�֣���0����	
	int iAreaType;						//ʶ����������
	int iPlateType;						//ʶ��������
	int iSpeed;							//�����ٶȡ�ע�������ٶ�ָ���ǳ�������Ƶ�����е��ƶ��ٶȣ����ǳ�����ʵ����ʹ�ٶȡ�	��Χ1-10					
	int iMaxSkip;						//����ڵ�֡��
	int iMinValid;						//��С�������Ŷ�
	int iFramePercent;					//ʶ�����
	int iMinCapDiff;					//ץͼ������ֵ
	char cCaliInfo[76];					//���Ʊ궨  20120229��չ
	//20121030��չ
	int	iPlateCharType;					//����ÿһλ��ʶ���ַ�����,
	//��ǰ����Ϊ7λ��ʹ�ú�14λ��ʾÿλ���Ƶ��ַ����ͣ�ÿ��λ��ʾһλ�ַ�����
	//00-���� 01-��ĸ 10-���� 11-��ĸ������
	int iConfid;						//�������Ŷ���ֵ
};

//ITS���߲���---�������v3.2
typedef struct __tagTITS_RefLine
{
	int			m_iLineID;
	int			m_iEnable;
	int			m_iLineType;
	vca_TLine	m_stLine1;
	vca_TLine	m_stLine2;				//Ԥ��
	int			m_iDistance;
}TITS_RefLine, *PTITS_RefLine;

typedef struct __tagTITS_ReflineAarry
{
	int			m_iRoadwayID;
	int			m_iLineNum;
	TITS_RefLine m_stLines[MAX_ITS_REFLINE_NUM];
}TITS_RefLineAarry, *PTITS_ReflineArray;


#define MAX_VEHICLE_TYPE 3//�����������
typedef struct __tagTITS_ChnCarSpeedPara
{
	int iCarWayNo;						//������ţ����֧��4��������0-3
	int iCarType;						//�������ͣ�0-����⣬1-С����2-��
	int iSpeedHighLimit;				//�����������ޣ�m/s������ʱ����1000��ת���ɱ���3ΪС����
	int iSpeedLowLimit;					//�����������ޣ�m/s������ʱ����1000��ת���ɱ���3ΪС����
	int iHighExceedPercent;				//����ִ���ٷֱȣ�0-100
	int iLowExceedPercent;				//����ִ���ٷֱȣ�0-100
}TITS_ChnCarSpeedPara, *PTITS_ChnCarSpeedPara;


struct TITSRoadwayParam
{
	int iRoadWayID;

	//modified by wd @20130531 
	//TITSRoadwayInfoEx info;
	TITSRoadwayInfo_V1 RoadWayInfo;
	//modified end

	TITSRoadWayLoop loop;
	TITSRoadwayTime time;
	TITSRoadwaySpeed speed;
	TITSRoadwayReco reco;
	TITSRoadwayVLoop vloop;
	TITSRoadwayCapture capture;
	TITSRoadwayCapture captureNew;
	ITS_RecoParamEx recopara;
	TITSRoadwayLight_V1	light;
	TITS_RefLineAarry   m_stLineArray;	
};

/************************************************************************/
//*	���ܽ�ͨ�����Ż�
/************************************************************************/

#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN                   0
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_FIRST_HZ				(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 0)	    //���ó����Ż��׺���
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_NOPLATE_ENABLE		(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 1)		//�����Ƿ��������Ƴ�
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_OTHER					(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 2)		//���ô��������ƺͲ����ų���
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MAX					(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 3)		//

#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN                   0										   		
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_FIRST_CHARACTER       (ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 0)		//��ó����Ż��׺���
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_NOPLATE_ENABLE		(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 1)		//����Ƿ��������Ƴ�
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_OTHER					(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 2)		//��ô��������ƺͲ����ų���
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MAX					(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 3)		//

struct TITSLicensePlateOptimizeFirstHZInfo
{
	char cModifyChar[9];
	int iMinCharConfid;
	char cModifyAlpha[10];
	int iMinAlphaConfig;
};

struct TITSLicesePlateOptimizeOther    //�������ƺͲ����ų���
{
	int iType;                         //���� 0�����������֣�1�������ź���
	int iCount;                        //�׺�����Ŀ ���֧��8��
	char cModifyChar[8][3];            //�׺���    Ӧ���ó���ʡ�����׺��ֻ򲻿��ܳ��ֵĳ����׺��֡�������4���ֽ�
};

#define MAX_OPTIMIZEOTHERTYPE_NUM 2    //0�����������֣�1�������ź���
struct TITSLicensePlateOptimizeParam
{
	int iEnableNoPlate;
	TITSLicensePlateOptimizeFirstHZInfo  firstHZinfo;
	//modify by wd @20130626
	TITSLicesePlateOptimizeOther other[MAX_OPTIMIZEOTHERTYPE_NUM];
};

/************************************************************************/
///*  ���ô��������ƺͲ����ų���//�Ǳ��س��� 
/************************************************************************/
#define  MAX_MODIFYCHAR_COUNT    8
struct ITS_LicenseOptimizeOther
{
	int			iType;      							//0�����������֣�1�������ź���
	int			iCount;									//�׺�����Ŀ ���֧��8��
	char		cModifyChar[MAX_MODIFYCHAR_COUNT][5];	//Ӧ���ó���ʡ�����׺��ֻ򲻿��ܳ��ֵĳ����׺��֡�������4���ֽ�
	int			iOtherCharWeight[MAX_MODIFYCHAR_COUNT];	//�׺����Ż�������Ŷ�
} ;

/************************************************************************/
///*  ��ͨΥ�¼����  
/************************************************************************/
#define ITS_EXTRAINFO_CMD_SET_MIN								 0
//Υͣ��Ŀ
#define ITS_ILLEGALPARK_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 0)	    //����Υ��ͣ������
#define ITS_ILLEGALPARKPARM_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 1)		//����Υ��ͣ���궨�������
#define ITS_LICENSEOPTIMIZEOTHER_CMD_SET						(ITS_EXTRAINFO_CMD_SET_MIN + 2)		//���ô��������ƺͲ����ų���
#define ITS_OPTIM_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 3)		//���ó����Ż��׺���
#define ITS_RECOPARAM_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 4)		//����ʶ���㷨����
#define ITS_ROADWAYENABLE_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 5)		//���ó���
#define ITS_CAMLOCATION_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 6)		//�����豸��Ϣ
#define ITS_EXACTCONFIRM_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 7)		//���þ�ȷ��λ��Ϣ
//�������
#define ITS_VIDEODECTECT_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 8)		//ͼ�������
#define ITS_DETECTAREA_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 10)	//�켣��������������
#define ITS_RECOTYPE_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 11)	//�㷨���Ͳ���
//��ͨһ���
#define ITS_REDLIGHTDETECTAREA_CMD_SET							(ITS_EXTRAINFO_CMD_SET_MIN + 12)	//���ú�Ƽ���������
#define ITS_ENABLE_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 13)	//���ý�ͨ��ع���ʹ��Э��
#define ITS_DAYNIGHT_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 14)	//���ý�ͨ��ع���ʹ��Э��
#define ITS_WORKMODE_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 15)	//���ù���ģʽ
#define  ITS_LIGHTINFO_CMD_SET                                  (ITS_EXTRAINFO_CMD_SET_MIN + 16)   //�����źŵƶ�Ӧ�Ĳ���
//add by wd @20130603
#define ITS_CROSSINFO_CMD_SET                                   (ITS_EXTRAINFO_CMD_SET_MIN + 17)	//����·����Ϣ����
//add by wd @20130619
#define ITS_AREAINFO_CMD_SET                                    (ITS_EXTRAINFO_CMD_SET_MIN + 18)    //���������������
#define ITS_EXTRAINFO_CMD_SET_MAX								(ITS_EXTRAINFO_CMD_SET_MIN + 19)	//���
//end

#define ITS_EXTRAINFO_CMD_GET_MIN								 0
//Υͣ��Ŀ
#define ITS_ILLEGALPARK_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 0)	    //���Υ��ͣ������
#define ITS_ILLEGALPARKPARM_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 1)		//���Υ��ͣ���궨�������
#define ITS_LICENSEOPTIMIZEOTHER_CMD_GET						(ITS_EXTRAINFO_CMD_GET_MIN + 2)		//��ô��������ƺͲ����ų���
#define ITS_OPTIM_CMD_GET										(ITS_EXTRAINFO_CMD_GET_MIN + 3)		//��ó����Ż��׺���
#define ITS_RECOPARAM_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 4)		//���ʶ���㷨����
#define ITS_ROADWAYENABLE_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 5)		//��ó���
#define ITS_CAMLOCATION_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 6)		//����豸��Ϣ
//�������
#define ITS_VIDEODECTECT_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 7)		//ͼ�������
#define ITS_DETECTAREA_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 9)		//�켣��������������
#define ITS_RECOTYPE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 10)	//�㷨���Ͳ���
#define ITS_CAMRATYPE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 11)	//�������
//��ͨһ���
#define ITS_REDLIGHTDETECTAREA_CMD_GET							(ITS_EXTRAINFO_CMD_SET_MIN + 12)	//��ú�Ƽ���������
#define ITS_ENABLE_CMD_GET										(ITS_EXTRAINFO_CMD_SET_MIN + 13)	//��ý�ͨ��ع���ʹ��Э��
#define ITS_VERSIONPRO_CMD_GET									(ITS_EXTRAINFO_CMD_SET_MIN + 14)	//�������汾��Ϣ
#define ITS_DAYNIGHT_CMD_GET									(ITS_EXTRAINFO_CMD_SET_MIN + 15)	//���ý�ͨ��ع���ʹ��Э��
#define ITS_WORKMODE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 16)    //��ȡ����ģʽ
#define ITS_LIGHTINFO_CMD_GET                                   (ITS_EXTRAINFO_CMD_GET_MIN + 17)    //��ȡ�źŵƶ�Ӧ�Ĳ���
//add by wd @20130603
#define ITS_CROSSINFO_CMD_GET	                                (ITS_EXTRAINFO_CMD_GET_MIN + 18)	//��ȡ·����Ϣ����
//add by wd @20130619
#define ITS_AREAINFO_CMD_GET	                                (ITS_EXTRAINFO_CMD_GET_MIN + 19)    //��ȡ�����������
#define ITS_EXTRAINFO_CMD_GET_MAX								(ITS_EXTRAINFO_CMD_GET_MIN + 21)	//���
//add end

#define MAX_PRESET_COUNT			8					//Υ��ͣ�����Ԥ��λ��
#define MAX_AREA_COUNT				4					//Υ��ͣ�����������
#define MAX_PARAM_COUNT				4					//Υ��ͣ���ı������������궨λ����
/************************************************************************/
///*  ����Υ��ͣ������  
/************************************************************************/
//struct ITS_IllegalPark
//{
//	int			iPresetNo;      						//Ԥ��λ���
//	int			iAreaNo;								//������
//	int		  	iIllegalParkTime;						//Υ��ͣ�����ʱ��
//	int			iTimeRange[MAX_TIMESEGMENT];								//ʹ��ʱ�䷶Χ
//	POINT		arrPTArea[MAX_AREA_COUNT];				//�����ĸ�������  iX1,iY1:iX2,iY2:iX3,iY3:iX4,iY4
//} ;

struct ITS_IllegalPark                                  //��չΥͣ������iCheckParkTime&iSensitivity��@120905
{
	int			iPresetNo;      						//Ԥ��λ���   ���8����0-7
	int			iAreaNo;								//������     ���4����0-3
	int		  	iIllegalParkTime;						//Υ��ͣ�����ʱ��  ��Ϊ��λ
	int			iTimeRange[MAX_TIMESEGMENT];								//ʹ��ʱ�䷶Χ
	POINT		arrPTArea[MAX_AREA_COUNT];				//�����ĸ�������  iX1,iY1:iX2,iY2:iX3,iY3:iX4,iY4
	int         iCheckParkTime;                         //ͣ���ж�ʱ��
	int         iSensitivity;                           //�����ȵȼ�
} ;

/************************************************************************/
//  ����Υ��ͣ���궨������� 
/************************************************************************/
struct ITS_IllegalParkParm
{
	int			iPresetNo;      					    //Ԥ��λ���
	int			iAreaNo;								//������
	POINT       arrPTParam[MAX_PARAM_COUNT][2];         //�궨λ������������ iAX1,iAY1:iAX2,iAY2;iBX1,iBY1:iBX2,BiY2;iCX1,iCY1:iCX2,iCY2;iDX1,iDY1:iDX2,iDY2
} ;

/************************************************************************/
//  ���ô��������ƺͲ����ų���//�Ǳ��س��� 
/************************************************************************/
//#define  MAX_MODIFYCHAR_COUNT    8
//struct ITS_LicenseOptimizeOther
//{
//	int			iType;      							//0�����������֣�1�������ź���
//	int			iCount;									//�׺�����Ŀ ���֧��8��
//	char		cModifyChar[MAX_MODIFYCHAR_COUNT][5];	//Ӧ���ó���ʡ�����׺��ֻ򲻿��ܳ��ֵĳ����׺��֡�������4���ֽ�
//	int			iOtherCharWeight[MAX_MODIFYCHAR_COUNT];	//�׺����Ż�������Ŷ�
//} ;


/************************************************************************/
//*  ���þ�ȷ��λ���� 
/************************************************************************/
struct ITS_ExactConfirm
{
	int			iPresetNo;      						//Ԥ��λ���
	int			iAreaNo;								//������
	int         iLocalPos1;								//�궨����
} ;

/************************************************************************/
//*							�����������				
/************************************************************************/

#define		MAX_ITS_DETECTAREA_NUM		16
#define		MAX_ITS_AREA_POINTNUM		16
//130T�㷨˽�в���
typedef struct __tagTITS_Params130T
{
	int			m_iZoomRate;
	int			m_iVehicleWidth;
	int			m_iConfidenceValve;
	int			m_iProportion;
}TITS_Params130T, *PTITS_Params130T;

//ITSͼ�������
typedef	struct __tagTITS_VDetect
{
	int			m_iEngineType;
	int			m_iEnable;
	int			m_iVedioType;
	int			m_iVedioWidth;
	int			m_iVedioHeight;
	int			m_iVehicleMinSize;
	int			m_iVehicleMaxSize;
	int			m_iModelType;
	int			m_iFrameRateCount;
	TITS_Params130T	m_stParmas130T;
}TITS_VDetect, *PTITS_VDetect;

typedef	struct __tagTITS_VDetect_Ex
{
	int				m_iSize;
	TITS_VDetect	m_tVDetect;
	int				m_iVDetectMotor;	//�ǻ��������ʹ��
}TITS_VDetect_Ex, *PTITS_VDetect_Ex;

//ITSͼ�����������
#define  MAX_ITS_DETECTAREAPOINT_NUM  15
typedef struct __tagTITS_DetectArea
{ 
	int			m_iRegionID;                      //������  0~11
	int			m_iEnabled;                       //ʹ�ܱ��  0�������ã�1������ 
	int			m_iPointCount;                    //������� 4~15
	vca_TPoint	m_arrPoint[MAX_ITS_AREA_POINTNUM];//�궨λ�����������꣨���15���㣩 iAX1:iAY1,iAX2:iAY2,iAX3:iAY3,iAX4:iAY4,��
}TITS_DetectArea, *LTITS_PDetectArea;

/************************************************************************/
//*  ��ͨ��ع���ʹ�ܲ���
/************************************************************************/

#define MAX_ITS_ENABLE_NUM	8
#define MAX_ITS_POWERINPHASEENABLE_NUM	0
#define MAX_ITS_ITSMANUALENABLE_NUM	1
struct ITS_EnalbeParam
{
	int iType;	    // �������� 0--��Դͬ������  1--�����ֶ�ģʽ  2--CRCУ�鹦��  3--��Ƶ���ٹ��� 4���������ʹ�� 5��ftpʹ��
					// 6--ͼ��ϳɹ���   7--����ʶ����
	int iEnable;	// 0-��ʹ�ܣ�1-ʹ��
};

//#define	MAX_ITS_REDLIGHT_DETECTAREA_NUM		4
#define	MAX_ITS_REDLIGHT_DETECTAREA_NUM		8

struct ITS_RedLightDetectArea
{
	int iRegionID;	//��������� 0-3
	int iEnabled;	//ʹ�ܱ��	0�������ã�1������					
	RECT rcStandardArea;	//�궨����λ��
	RECT rcReviseArea;		
};

//add by wd @20130603
typedef struct __tagITS_RedLightDetectAreaV1
{
	int  iBufSize;                  //��������ṹ��ĳ���(���Զ���)
	int  iRegionID;	                //��Ʊ�� 8��
	int  iEnabled;	                //ʹ�ܱ��	0�������ã�������	
	RECT rcStandardArea;	        //�궨����λ��
	RECT rcReviseArea;		
	int  iLightType;                //�������� 0-���Ƶ��̣�1-���Ƶ��̣�2-��Ƶ��̺죬3-��Ƶ�����
	int  iChannelType;              //��������Ӧ�ĳ������� �������Ͱ�λ����,0-�����ã�1-���ã� bit0-ֱ�� bit1-��ת bit2-��ת bit3-��ͷ
} ITS_RedLightDetectAreaV1, *PITS_RedLightDetectAreaV1;
//ended

//add by wd @20130603 ·����Ϣ�ṹ��
struct ITS_CrossInfo
{
	int iBufSize;                //��������ṹ��ĳ���(���Զ���)
	char pcCrossingID[64];       //·�ڱ��  ���Ȳ�����63�ַ�
	char pcCrossingName[64];     //·������  ���Ȳ�����63�ַ�
};
//add end

//add by wd @20130620�����������
#define  MAX_AREAINFOPOINT_NUM 6
#define	 MAX_ITS_AREAINFOREGIONID_NUM		8     //������ 
#define  MAX_ITS_AREAINFO_TYPE				2		//��������
struct ITS_AreaInfo
{
	int iBufSize;                 //��������ṹ��ĳ���
	int iType;                    //��������  0���������
	int iRegionID;               //����������ID��0~7
	int iEnabled;                //ʹ�ܱ�� 0�������ã�1������
	int iCount;                  //������� 4~6
	vca_TPoint  stTPoint[MAX_AREAINFOPOINT_NUM];	         //�궨λ�����������꣨���6���㣩
};
//add end

/************************************************************************
*	�������ʶ���㷨����                                                                     
************************************************************************/
struct ITS_RecoParam 
{
	int iMaxPlateNO;					//�������
	int iMaxPlateWidth;					//����ƿ��
	int iMinPlateWidth;					//��С���ƿ��
};

/************************************************************************
*	�������λ��                                                                     
************************************************************************/
struct ITS_CamLocation
{
	char cDeviceVode[64];								//�豸���
	char cRoadName[64];									//·������
};

//	ITS(���ܽ�ͨ)���õı����ܼ�
struct ITS_VariableParam
{
	int m_iAgcBlock[MAX_ITS_TIMERANGE];              //ʱ��β������ʹ��
	int m_iFlashLamp[MAX_ITS_TIMERANGE];             //ʱ��������ʹ��
	int m_iDetectMode;								 //������ģʽ
	int m_iLoopMode;			  				     //��Ȧ����ģʽ
	int m_iITSDeviceType;							 //�����������

	//�������
	int	m_iITSCamraType;
	//����汾��Ϣ
	char m_strITSVersionPro[1024];	
};


#define CAMERA_PARAM_JPEG_QUALITY			0
#define CAMERA_PARAM_LUT					1

struct TCameraParam
{
	int iParamType;		//�������� 0:ͼƬ���� 1:LUT  ����Ԥ��					
	int iParamValue;	//����ֵ iParamType=0ʱ��0-100����ֵԽ������Խ��; iParamType=1ʱ��0:������;1:����		
};

/************************************************************************
* �õ��豸��������Ϣ                                                                     
************************************************************************/
#define MAX_CONNECT_COUNT		128

struct TChannelConnectInfo
{
	int iChannelID;					//	ȡֵ��Χ���豸��ͨ����������������NVSSDK����ͬ��������ͨ����0��ʼ������ͨ������
	char cClientIP[16];				//	�ͻ���IP��ַ
	int iChannelType;				//ͨ�����ͣ�0��������ͨ����1��������ͨ��
	int iNetMode;					//1��TCP�� 2��UDP�� 3���ಥ�� 4������ģʽ
	int iConnectState;				//����״̬��0�����������ӣ�  1����Ͽ�����
	char cUserName[17];				//�û��������16���ַ�
};

struct TTotalConnectInfo
{
	TChannelConnectInfo	connInfo[MAX_CONNECT_COUNT];
};

/************************************************************************
*	ƽ̨��������б�����                                                                     
************************************************************************/
#define MAX_PLATFORM_COUNT			10
#define MAX_PALTFORM_NAME_LENGTH	33

#define PLATFORM_CMD_SET_MIN		0
#define PLATFORM_CMD_SET_RUN		(PLATFORM_CMD_SET_MIN+0)
#define PLATFORM_CMD_SET_MAX		(PLATFORM_CMD_SET_MIN+1)

//#define PLATFORM_CMD_GET_MIN		(PLATFORM_CMD_SET_MAX)			//	�����������չ������			
#define PLATFORM_CMD_GET_MIN		(1)
#define PLATFORM_CMD_GET_LIST		(PLATFORM_CMD_GET_MIN+0)
#define PLATFORM_CMD_GET_MAX		(PLATFORM_CMD_GET_MIN+1)


struct TPlatformVersion
{
	char cData[33];
};

struct TPlatformApp
{
	char cName[MAX_PLATFORM_COUNT][MAX_PALTFORM_NAME_LENGTH];			//	ƽ̨�����������ƣ����10�������������32�ֽ�
	int iState[MAX_PLATFORM_COUNT];										//	����ƽ̨��������״̬, 0-ֹͣ��1-����
};

//ATM��ز���
#define ATM_CONFIG_CMD_MIN							0
#define ATM_CONFIG_CMD_ATM_INFO				(ATM_CONFIG_CMD_MIN+0)
#define ATM_CONFIG_CMD_OSD_INFO				(ATM_CONFIG_CMD_MIN+1)
#define ATM_CONFIG_CMD_PROTOCOL_COUNT		(ATM_CONFIG_CMD_MIN+2)
#define ATM_CONFIG_CMD_PROTOCOL_NAME		(ATM_CONFIG_CMD_MIN+3)
#define ATM_CONFIG_CMD_MAX					(ATM_CONFIG_CMD_MIN+4)

#define ATM_PROTOCOL_NAME_LEN 31
#define ATM_PROTOCOL_NAME_COUNT 40
#define ATM_FIELD_COUNT	5
#define ATM_FIELD_LEN	64
#define ATM_CARD_ID_LEN 32

//ATM�ļ���ѯ��ز���
#define ATM_QUERY_CMD_MIN						0
#define ATM_QUERY_CMD_FIELD				(ATM_QUERY_CMD_MIN+0)
#define ATM_QUERY_CMD_CARD				(ATM_QUERY_CMD_MIN+1)
#define ATM_QUERY_CMD_MAX				(ATM_QUERY_CMD_MIN+2)

typedef struct ATM_INFO
{
	int		iSize;									//Size of the structure,must be initialized before used
	int		iInformWay;								//ͨ�ŷ�ʽ 0:����,1:UDP
	char	cProtocolName[ATM_PROTOCOL_NAME_LEN+1];	//Э������ Э�鳧��
	char	cSrcIP[LENGTH_IPV4];					//ATM IP��ַ
	int		iSrcPort;								//ATM �˿ں�
	char	cDestIP[LENGTH_IPV4];					//�豸IP��ַ Ĭ��0
	int		iDestPort;								//�豸�˿ں�
}*PATM_INFO;

typedef struct ATM_OSD_INFO
{
	int				iSize;					//Size of the structure,must be initialized before used
	int 	        iX; 	    			//������
	int             iY; 	    			//������
	unsigned int	uEnable;				//ʹ�� ͨ����λȡ
}*PATM_OSD_INFO;

typedef struct ATM_PROTOCOL_NAME
{
	int		iSize;							//Size of the structure,must be initialized before used
	int		iIndex;							//Э������
	char	cName[ATM_PROTOCOL_NAME_LEN+1];	//Э������
}*PATM_PROTOCOL_NAME;

typedef struct ATM_FIELD_QUERY
{
	int				iSize;										//Size of the structure,must be initialized before used
	int          	iType; 										//¼������ 33:ATM
	int     	    iChannel; 									//ͨ���� ��0��ʼ,0xff��������
	NVS_FILE_TIME	struStartTime; 								//��ʼʱ��
	NVS_FILE_TIME	struStopTime; 								//����ʱ��
	int     	    iPageSize;									//ҳ��С
	int         	iPageNo;									//ҳ���
	int             iFiletype;									//�ļ����� 0:ȫ��,1:��Ƶ,2:ͼƬ
	int				iDevType;									//�豸���� 0:�����,1:������Ƶ������,2:���������,0xff:ȫ��
	char			cOtherQuery[65];							//�ַ�����
	int				iTriggerType;								//�������� 3:�˿ڱ���,4:�ƶ�����,5:��Ƶ��ʧ����,0x7FFFFFFF:��Ч
	int				iTrigger;									//�˿ڣ�ͨ������
	char			cField[ATM_FIELD_COUNT][ATM_FIELD_LEN+1];	//���ѯ
}*PATM_FIELD_QUERY;

typedef struct ATM_CARD_QUERY
{
	int				iSize;					//Size of the structure,must be initialized before used
	int          	iType; 					//¼������ 33:ATM
	int     	    iChannel; 				//ͨ���� ��0��ʼ,0xff��������
	NVS_FILE_TIME	struStartTime; 			//��ʼʱ��
	NVS_FILE_TIME	struStopTime; 			//����ʱ��
	int     	    iPageSize;				//ҳ��С
	int         	iPageNo;				//ҳ���
	int             iFiletype;				//�ļ����� 0:ȫ��,1:��Ƶ,2:ͼƬ
	int				iDevType;				//�豸���� 0:�����,1:������Ƶ������,2:���������,0xff:ȫ��
	char			cOtherQuery[65];		//�ַ�����
	int				iTriggerType;			//�������� 3:�˿ڱ���,4:�ƶ�����,5:��Ƶ��ʧ����,0x7FFFFFFF:��Ч
	int				iTrigger;				//�˿ڣ�ͨ������
	char			cID[ATM_CARD_ID_LEN+1];	//����
	int				iOperate;				//ҵ������ 0:�����ѯ,1:ȡ��,2:����,3:ת��,4:���,5:�޿���ѯ,6:�޿����,20:����
	int				iQuantity;				//���:��������Ŀ���֣�
	int				iAbnormity;				//�쳣��� 0:�̳�,1:�̿�
}*PATM_CARD_QUERY;

typedef struct ATM_FILE_DATA
{
	int				iSize;					//Size of the structure,must be initialized before used
	int             iType; 	        		//¼������ 33:ATM
	int 	        iChannel; 	    		//ͨ���� ��0��ʼ,0xff��������
	char 		    cFileName[250]; 		//�ļ���
	NVS_FILE_TIME	struStartTime; 			//��ʼʱ��
	NVS_FILE_TIME	struStoptime; 			//����ʱ��
	int             iFileSize; 	    		//�ļ���С
	int				iOperate;				//�������� 1:ȡ��,2:����,3:ת��,4:���,5:�޿���ѯ,6:�޿����,20:����,21:�̳�,22:�̿�
	NVS_FILE_TIME	struOperateTime;		//����ʱ��
}*PATM_FILE_DATA;

//��Ƶ��������ز���
#define AUDIO_SAMPLE_CMD_MIN						0			
#define AUDIO_SAMPLE_CMD_SAMPLE				(AUDIO_SAMPLE_CMD_MIN+0)	//���û��ȡĳͨ���Ĳ�����
#define AUDIO_SAMPLE_CMD_SAMPLE_COUNT		(AUDIO_SAMPLE_CMD_MIN+1)	//���ĳͨ��֧�ֵĲ����ʸ���
#define AUDIO_SAMPLE_CMD_SAMPLE_LIST		(AUDIO_SAMPLE_CMD_MIN+2)	//���ĳͨ��֧�ֵĵڼ��������ʣ���Ӧ�ṹ��ΪAUDIO_SAMPLE
#define AUDIO_SAMPLE_CMD_MAX				(AUDIO_SAMPLE_CMD_MIN+3)

#define MAX_AUDIO_SAMPLE_NUM 16

typedef struct AUDIO_SAMPLE
{
	int				iSize;					//Size of the structure,must be initialized before used
	int				iIndex;					//����������
	int				iSample;				//��Ƶ������
}*PAUDIO_SAMPLE;

/*-------------------------------------------------------*/
//ϵͳ���Ͳ���
#define	SYSTEMTYPE_WORKMODE		0		//	����ģʽ	
#define SYSTEMTYPE_DEVPROD		1		//	�豸������
typedef struct __tagSYSTEMTYPE
{
	int m_iSize;
	int m_iWorkMode;					//	���޸Ĵ˲���ʱ��0x7FFFFFFF
	int m_iDevProducter;
}SYSTEMTYPE, *LPSYSTEMTYPE;


//��ͨ���
#define MAX_ROADWAY_COUNT           4          //��󳵵���
#define MAX_LOOP_COUNT              4           //�����������Ȧ��
#define DAY_OR_NIGHT                2          //0---���죬1---����

#define LIGHT_COUNT							4					//�źŵ���
#define LIGHT_COM_COUNT						4					//�źŵƴ�����
#define CAPTURE_PLACE_COUNT					3					//������Ӧ��ץ��λ����Ŀ

struct TImgDisposal	//ͼƬЧ��
{
	int iChannelID;
	int iStartUp;		//ͼƬЧ�������Ƿ����ñ�ʶ, 0�������� 1������
	int iQuality;		//����,	��Χ��0��100
	int iSaturation;	//���Ͷ�,��Χ��0��255
	int iBrighten;		//����,��Χ��0��255
	int iContrast;		//�Աȶ�,��Χ��0��255
	int iGamma;			//٤��ֵ,��Χ��0��50	
	int iAcutance;		//���,��Χ��0��255
	int iImgEnhanceLevel;//ͼ����ǿ����,��Χ��0��3					
};

struct TECOPChannelParam	//������ز���
{
	TImgDisposal tImgDisposal;
	int iRecognizeEnable;
	int iWaterMarkEnable;
};

//�źŵƶ�Ӧ�Ĳ���
struct TITSLightInfo
{
	int iLightID;						//�źŵƱ�� 0-3	
	int iTimeInterval;					//�źŵ�ʱ���� ��λ��	
	int iTimeAcceptDiff;				//�źŵ�ʱ������ֵ ��λ��					
};
//��չ�źŵƲ���
//��չ�źŵƲ���
typedef	struct __tagTITSLightInfoEx
{
	int				iBufSize;
	TITSLightInfo	m_stLightInfo;			//���� �źŵƱ�� 0-7	
	int				iChannelType;			//�źŵƶ�Ӧ�ĳ�������  �������Ͱ�λ����,0-�����ã�1-���ã�bit0-ֱ�� bit1-��ת bit2-��ת bit3-��ͷ
	int				iPhase;					//�����λֵ   ��λֵ 0~360
	int				iDetectType;			//����ƻ����̵� 0����ơ�1���̵�
	int				m_iYellowLightTime;		//�ƵƳ���ʱ��, ��λms��0-100000ms----->add new
	int				m_iLightEnhanceLevel;	//�������ȼ�;���淶Χ��1~255��0-������
}TITSLightInfoEx,LPTITSLightInfoEx;

struct TECOPParam
{
	TECOPChannelParam tChannel[MAX_ROADWAY_COUNT];
	int iSystemType;	//ϵͳ����
	//0������
	//3������
	//4���羯	
	int iLockRet;		//��ȡע����
	//bit0��ʶ��
	//bit1�����ܽ�ͨ���ܹ�
	//0��δע�ᣬ1��ע��
	TITSLightInfo tLightInfo[LIGHT_COUNT];
};

typedef int				VIDEO_METHOD;
#define VIDEO_MODE_HAND			0x00
#define VIDEO_MODE_AUT			0x01

#define MAX_MONITOR_DESCLEN     512
typedef struct MONITOR_INFO
{
	char        cDriverDesc[MAX_MONITOR_DESCLEN];
	char        cDriverName[MAX_MONITOR_DESCLEN];	
	RECT		rect;
}*PMONITOR_INFO;

typedef struct
{
	int         m_iStructSize;        //�ṹ���С
	char        m_cVersion[32];       //�������汾��
	char		m_cUIVersion[32];	  //UI�������汾��
	char		m_cSlaveVersion[32];  //��Ƭ�汾��
	char        m_cPlugInVersion[32]; //��Ұ汾�� 
	char		m_cSCMVersion[32];	  //��Ƭ���汾��
}SERVER_VERSION;

/************************************************************************/
/*							���ڸ�ʽ����                                */
/************************************************************************/
typedef struct COMFORMAT
{
	int				iSize;				//Size of the structure,must be initialized before used
	int				iComNo;				//���ڱ��
	char			cDeviceName[32];	//Э������
	char			cComFormat[32];		//��ʽ�� 9600,n,8,1
	int				iWorkMode;			//����ģʽ 1:Э�����,2:͸��ͨ��,3:��ҵԤ��,4:7601B���б�������,5:485����
	int				iComType;			//�������� 0:485,1:232,2:422
} *PCOMFORMAT;

/*-------------------------------------------------------*/
//����߼�����
#define	MAX_DOME_PRESET_NUM			255	//	���Ԥ��λ��Ÿ���
#define	MAX_DOME_SCAN_NUM			255	//	���ɨ���Ÿ���
#define	MAX_DOME_CURISE_NUM			255	//	���Ѳ����Ÿ���
#define	MAX_DOME_PATTERN_NUM		255	//	���ģʽ·����Ÿ���
#define	MAX_DOME_ZONES_NUM			255	//	���������ʾ��Ÿ���

#define TITLETYPE_RESERVED			0	//	Ԥ��
#define TITLETYPE_PRESET			1	//	Ԥ��λ
#define TITLETYPE_SCAN				2	//	ɨ��
#define TITLETYPE_CRUISE			3	//	Ѳ��
#define TITLETYPE_PATTERN			4	//	ģʽ·��
#define TITLETYPE_ZONES				5	//	������ʾ

#define	MAX_TITLE_LEN				31

#define	CMD_DOME_ADV_SETTITLE		0	//	�����������
typedef struct __tagDOME_TITLE
{
	int		m_iStructSize;				//	�ṹ��size
	int		m_iType;					//	��������
	int		m_iNum;						//	������
	char	m_cTitle[MAX_TITLE_LEN+1];	//	������
}DOME_TITLE, *LPDOME_TITLE;

/*-------------------------------------------------------*/
//cb@1212068124: SET GET��CMDʹ��ͬһ�����֣�ʹ����ɶ��Ժ������Ը��ã�
#define IPC_CMD_MIN 0
#define IPC_CMD_SENSOR_VOLTAGE       (IPC_CMD_MIN + 0)
#define IPC_CMD_MAX                  (IPC_CMD_MIN + 1)

typedef struct  
{
	int		iType; 
	int		iMold;
	float   iValue;
	int     iReserved;
}HardWare_Param;

typedef struct
{
	unsigned int uiTextColor;
	unsigned char ucOSDText[LENGTH_CHANNEL_TITLE+1];
}OSD_TEXT;

//���ռƻ���ز���
#define HOLIDAY_PLAN_CMD_MIN						0			
#define HOLIDAY_PLAN_CMD_SCHEDULE			(HOLIDAY_PLAN_CMD_MIN+0)	//���û��ȡ���ռƻ�¼��ģ��
#define HOLIDAY_PLAN_CMD_MAX				(HOLIDAY_PLAN_CMD_MIN+1)
#define MAX_HOLIDAY_PLAN_SCHEDULE					10

typedef struct
{
	unsigned short iYear;
	unsigned short iMonth;
	unsigned short iDay;
	unsigned short iWeekOfMonth;
	unsigned short iDayOfWeek;
}HOLIDAY_TIME;

typedef struct
{
	int iPlanID;		//�ƻ�ģ��ID,[0,9]
	int iEnable;		//�Ƿ�ʹ��,1:ʹ�� 0:��ʹ��
	char cPlanName[33]; //�ƻ�ģ������
	int iMode;			//ʱ���ʽ,0:������(������) 1:������(���� ����) 2:���·�(����)
	HOLIDAY_TIME tStartTime;	//��ʼʱ��
	HOLIDAY_TIME tEndTime;		//����ʱ��
}HOLIDAYPLAN_SCHEDULE;

//M7.6֮���豸���صĴ���ID		EC:ERROR CODE
//����Ƶ
#define EC_AV_SWITCHOVER_CHANNEL			0x1000	//������ͨ�����л�ͨ������ʧ��
#define EC_AV_QUERY_FILE					0x1010	//���ϵ���������ѯ���������ļ�
//�ַ�����
#define EC_OSD_LOGO_FORMAT					0x2001	//���ַ����ӣ������logoͼƬ��ʽ����
#define EC_OSD_LOGO_DATA					0x2002	//���ַ����ӣ������logoͼƬ���ݴ���
//����PTZ
#define EC_SERIAL_PORT_PTZ					0x3000
//�쳣
#define EC_EXCEPTION						0x4000
//����
#define EC_ALARM							0x5000
//�洢
#define EC_STORAGE_LOCK_FILE				0x6000	//���ӽ����������ļ�ʧ��
#define EC_STORAGE_UNLOCK_FILE				0x6001	//���ӽ����������ļ�ʧ��
#define EC_STORAGE_REDUNDANCY				0x6010	//���洢���ԣ�û������������ԣ��޷���������¼��
#define EC_STORAGE_HOLIDAY_TIME				0x6020	//�����ռƻ�������ģ�����ʱ���ͻ
//�������
#define EC_NET_SERVICE						0x7000	
//�û�
#define EC_LOGON_USERNAME					0x8000	//����¼���û���������
#define EC_LOGON_PASSWORD					0x8001	//����¼���������
#define EC_LOGON_DECRYPT_PWD				0x8002	//����¼���������벻��
#define EC_LOGON_AUTHORITY					0x8010	//���������û�Ȩ�޲���
#define EC_LOGON_AUTHORITY_GROUP			0x8020	//���޸��û�Ȩ�ޣ��û������鲻�����������ø�Ȩ��
//PU����
#define EC_PU								0x9000
//���̹���
#define EC_DISK_RECORDING					0xA000	//(��;)����¼���޷��޸Ĵ���
#define EC_DISK_MEMORY						0xA001	//(��;)������¼����̲���
#define EC_DISK_TYPE						0xA002	//(��;)�������Ͳ�֧�ִ���;
#define EC_DISK_NO_DISK						0xA010	//(���飩������û��¼����
#define EC_DISK_NO_SETTING					0xA011	//�����飩������δ�����κδ���
#define EC_DISK_REPEAT_ADD					0xA012	//�����飩�ظ����ͬһ���̵���ͬ����
#define EC_DISK_NO_RECORD_CHANNEL			0xA013	//�����飩��������δ����κ�¼��ͨ��
#define EC_DISK_RECORD_QUOTA_BIG			0xA020	//����¼��������
#define EC_DISK_IMAGE_QUOTA_BIG				0xA021	//����ͼƬ������
#define EC_DISK_DEL_LOCK_FILE				0xA022	//�����޸�������ʱ���޷�ɾ�������ļ�
//ϵͳ����
#define EC_SYSTEM							0xB000	
//ͨ��
#define EC_COM								0xC000
//��������
#define EC_NET_CONNECTION					0xD000	
//���ܷ���
#define EC_VCA								0xE000	
//ATM
#define EC_ATM								0xF000	
//��ͨ���
#define EC_ITS								0x10000	
//DZ���
#define EC_DZ								0x11000	
//ͨ��ʹ��
#define EC_COMMON_ENABLE					0x12000


//M7.6֮���豸����ͨ��ʹ��ID		CI:COMMON ID
#define CI_ALARM_MOTION_DETECT					0x5000
#define CI_ALARM_VIDEO_COVER					0x5001
#define CI_NET_SERVICE_SNMP			0x7000
#define CI_NET_SERVICE_SMTP			0x7001

#define CI_STORAGE_DISK_GROUP		0xA000
#define CI_STORAGE_DISK_QUOTA		0xA001

#define CI_VEHICLE_GPS_CALIBRATION				0x12001
#define CI_VEHICLE_ALARM_THRESHOLD				0x12002
#define CI_VEHICLE_SHUTDOWN_THRESHOLD			0x12003

#define CI_NET_CONNECT_INFO			0xD001      //�ײ�socket���ͷְ������Ԫ
#define CI_COMMON_ID_EIS			0x1001		//���ӷ���
 

typedef struct  
{
	int iSNMPEnable;
	int iSMTPEnable[MAX_CHANNEL_NUM];
	int iDiskGroup;
	int iDiskQuota;
	int iMDAlarm[MAX_CHANNEL_NUM];
	int iODAlarm[MAX_CHANNEL_NUM];
	int iGPSCalibration;			//GPSУʱ 0:����,1:����
	int iAlarmThreshold;			//��ʾ�豸��ѹ������ֵ
	int iShutdownThreshold;			//��ʾ�豸��ѹ�ػ���ֵ
}COMMON_ENABLE;

typedef struct
{ 
	int m_iSize;             //�ṹ���С
	COMMON_ENABLE tEnable;   //���COMMON_ENABLE
	int iMTUValue;           //MTU���ã��ײ�socket���ͷְ������Ԫ��       
		
}COMMON_ENABLE_EX;


//add by wd @20130621
//���ץ�ķֱ��ʽṹ�� 
struct JPEGSizeInfo
{
	int iBufSize;                 //��������ṹ��ĳ���
	int iChannelNo;              //ͨ���� 0~n-1
	int iWidth;                   //ץ��ͼƬ��  ������ֵ
	int iHeight;                 //ץ��ͼƬ��  �ߣ�����ֵ
};
//add end

//������ز���
#define DOWNLOAD_FLAG_MIN							0
#define DOWNLOAD_FLAG_FIRST_REQUEST		(DOWNLOAD_FLAG_MIN+0)
#define DOWNLOAD_FLAG_OPERATE_RECORD	(DOWNLOAD_FLAG_MIN+1)
#define DOWNLOAD_FLAG_BREAK_CONTINUE	(DOWNLOAD_FLAG_MIN+2)
#define DOWNLOAD_FLAG_MAX				(DOWNLOAD_FLAG_MIN+3)

#define DOWNLOAD_CMD_MIN							0
#define DOWNLOAD_CMD_FILE				(DOWNLOAD_CMD_MIN+0)
#define DOWNLOAD_CMD_TIMESPAN			(DOWNLOAD_CMD_MIN+1)
#define DOWNLOAD_CMD_CONTROL			(DOWNLOAD_CMD_MIN+2)
#define DOWNLOAD_CMD_FILE_CONTINUE		(DOWNLOAD_CMD_MIN+3)
#define DOWNLOAD_CMD_MAX				(DOWNLOAD_CMD_MIN+4)

typedef struct
{
	int				m_iSize;			//�ṹ���С
	char            m_cRemoteFilename[255];   //ǰ��¼���ļ���
	char			m_cLocalFilename[255];	  //����¼���ļ���
	int				m_iPosition;		//�ļ���λʱ,���ٷֱ�0��100;�ϵ�����ʱ��������ļ�ָ��ƫ����
	int				m_iSpeed;			//1��2��4��8�������ļ������ٶ�, 0-��ͣ
	int				m_iIFrame;			//ֻ��I֡ 1,ֻ����I֡;0,ȫ������					
	int				m_iReqMode;			//�������ݵ�ģʽ 1,֡ģʽ;0,��ģʽ					
}DOWNLOAD_FILE;

typedef struct
{
	int				m_iSize;			//�ṹ���С
	char			m_cLocalFilename[255]; //����¼���ļ���
	int				m_iChannelNO;		//ͨ����
	NVS_FILE_TIME	m_tTimeBegin;		//��ʼʱ��
	NVS_FILE_TIME	m_tTimeEnd;			//����ʱ��
	int				m_iPosition;		//��ʱ��㶨λ��>100
	int				m_iSpeed;			//1��2��4��8�������ļ������ٶ�, 0-��ͣ
	int				m_iIFrame;			//ֻ��I֡ 1,ֻ����I֡;0,ȫ������
	int				m_iReqMode;			//�������ݵ�ģʽ 1,֡ģʽ;0,��ģʽ
}DOWNLOAD_TIMESPAN;

typedef struct
{
	int				m_iSize;			//�ṹ���С
	int				m_iPosition;		//0��100����λ�ļ�����λ�ã�-1�������ж�λ
	int				m_iSpeed;			//1��2��4��8�������ļ������ٶ�, 0-��ͣ
	int				m_iIFrame;			//ֻ��I֡ 1,ֻ����I֡;0,ȫ������
	int				m_iReqMode;			//�������ݵ�ģʽ 1,֡ģʽ;0,��ģʽ
}DOWNLOAD_CONTROL;

//�Զ����������Э��
#define CMD_AUTOTEST_MIN                    0
#define	CMD_AUTOTEST_RESERVED 				(CMD_AUTOTEST_MIN+0)      //Ԥ��
#define	CMD_AUTOTEST_SETMACADDR				(CMD_AUTOTEST_MIN+1)	  //����MAC��ַ�� 
#define	CMD_AUTOTEST_LAN					(CMD_AUTOTEST_MIN+2)	  //��������
#define	CMD_AUTOTEST_AUDIOIN				(CMD_AUTOTEST_MIN+3)      //������Ƶ���룻
#define	CMD_AUTOTEST_VIDEOIN				(CMD_AUTOTEST_MIN+4)	  //������Ƶ���룻
#define	CMD_AUTOTEST_AUDIOOUT				(CMD_AUTOTEST_MIN+5)	  //������Ƶ�����
#define	CMD_AUTOTEST_VIDEOOUT				(CMD_AUTOTEST_MIN+6)	  //������Ƶ�����
#define	CMD_AUTOTEST_MICIN					(CMD_AUTOTEST_MIN+7)	  //����MIC���룻
#define	CMD_AUTOTEST_SPEAKER				(CMD_AUTOTEST_MIN+8)	  //����SPEAKER�����
#define	CMD_AUTOTEST_VIDEOADJUST			(CMD_AUTOTEST_MIN+9)	  //������Ƶ���ڣ�Э��Ϊ��AUTOTEST_ADADJUST
#define	CMD_AUTOTEST_USB					(CMD_AUTOTEST_MIN+10)     //����USB�ڣ�
#define	CMD_AUTOTEST_SATA					(CMD_AUTOTEST_MIN+11)	  //����SATA�ڣ�
#define	CMD_AUTOTEST_ALARMIN				(CMD_AUTOTEST_MIN+12)	  //���Ա�������˿ڣ�
#define	CMD_AUTOTEST_ALARMOUT				(CMD_AUTOTEST_MIN+13)	  //���Ա�������˿ڣ�
#define	CMD_AUTOTEST_SERIAL					(CMD_AUTOTEST_MIN+14)	  //���Դ��ڣ�
#define	CMD_AUTOTEST_RTC			   		(CMD_AUTOTEST_MIN+15)	  //����ʱ��оƬ��
#define	CMD_AUTOTEST_VGADETECTIVE   		(CMD_AUTOTEST_MIN+16)	  //����VGA�ź���⣻�豸��
#define	CMD_AUTOTEST_HDMIDETECTIVE			(CMD_AUTOTEST_MIN+17)	  //����HDMI�ź���⣻�豸��
#define	CMD_AUTOTEST_RESETDETECTIVE			(CMD_AUTOTEST_MIN+18)	  //���Ը�λ�ź���⣻�豸��
#define	CMD_AUTOTEST_FORMATDISK				(CMD_AUTOTEST_MIN+19)	  //��ʽ�����̣�
#define	CMD_AUTOTEST_BACKUPSYSTEM			(CMD_AUTOTEST_MIN+20)	  //����ϵͳ��
#define	CMD_AUTOTEST_ENABLEGUIDE			(CMD_AUTOTEST_MIN+21)	  //���ÿ����򵼣�

#define CMD_AUTOTEST_IRIS					(CMD_AUTOTEST_MIN+22)	  //��ȦУ����
#define CMD_AUTOTEST_BADPOINTS				(CMD_AUTOTEST_MIN+23)	  //����У����
#define CMD_AUTOTEST_IRCUT					(CMD_AUTOTEST_MIN+24)	  //IRCUTУ����
#define CMD_AUTOTEST_SDCARD					(CMD_AUTOTEST_MIN+25)	  //SD��У����
#define CMD_AUTOTEST_VERIFYTIME				(CMD_AUTOTEST_MIN+26)	  //ʱ��У����
#define CMD_AUTOTEST_CALIBRATEVIDEOBRIGHTNESS	(CMD_AUTOTEST_MIN+27) //���Ȳ���У����
#define CMD_AUTOTEST_POWER_SYNC				(CMD_AUTOTEST_MIN+28)	  //��Դͬ�����
#define	CMD_AUTOTEST_END					(CMD_AUTOTEST_MIN+100)	  //���Խ�����
#define	CMD_AUTOTEST_MAX					(CMD_AUTOTEST_MIN+101)

#define MAX_AUTOTEST_ID     CMD_AUTOTEST_MAX

typedef struct
{
	int     iTestParam[5];
	char    cTestParam[65];
}strAutoTest_Para;

#define MAX_HD_TEMPLATE_NUMBER	8

//�û��Զ����������
#define STREAMDATA_CMD_MIN		                0
#define	STREAMDATA_CMD_USER_DEFINE				STREAMDATA_CMD_MIN + 1
#define STREAMDATA_CMD_MAX						STREAMDATA_CMD_MIN + 1
#define MAX_INSERT_STREAM_LEN					64

#define INSERTDATA_FLAG_MIN						0
#define INSERTDATA_MAIN_STRAM					INSERTDATA_FLAG_MIN + 1
#define INSERTDATA_SUB_STRAM					INSERTDATA_FLAG_MIN + 2
#define INSERTDATA_MAIN_SUB						INSERTDATA_FLAG_MIN + 3
#define INSERTDATA_FLAG_MAX						INSERTDATA_FLAG_MIN + 4
typedef struct __tagTStreamData
{
	int  iSize;				//�ṹ���С
	char cStreamData[MAX_INSERT_STREAM_LEN];
	int  iStreamLen;
} TStreamData, *PTStreamData;

#define DOME_PTZ_TYPE_MIN  1
#define DOME_PTZ_TYPE_PRESET_FREEZE_UP  		(DOME_PTZ_TYPE_MIN +0)
#define DOME_PTZ_TYPE_AUTO_FLIP 	 			(DOME_PTZ_TYPE_MIN +1)
#define DOME_PTZ_TYPE_PRESET_SPEED_LEVE			(DOME_PTZ_TYPE_MIN +2)
#define DOME_PTZ_TYPE_MANUL_SEPPD_LEVEL			(DOME_PTZ_TYPE_MIN +3)
#define DOME_PTZ_TYPE_WAIT_ACT             		(DOME_PTZ_TYPE_MIN +4)
#define DOME_PTZ_TYPE_INFRARED_MODE 			(DOME_PTZ_TYPE_MIN +5)
#define DOME_PTZ_TYPE_MAX			 			(DOME_PTZ_TYPE_MIN +6)
typedef struct
{
	int iSize;
	int iType;       		//����
	int iAutoEnable; 		//0--��ʹ�ܣ�1--ʹ��
	int iParam1;			//����
							//1--����Ԥ��λ���᣺δʹ��
							//2--�����Զ���ת��δʹ��
							//3--Ԥ��λ�ٶȵȼ���0--�ͣ�1--�У�2--��
							//4--�ֿ��ٶȵȼ���0--�ͣ�1--�У�2--��
							//5--���ô���������������ֵ��30��60��300��600��1800����λ���룩
							//6--�����ģʽ��0--�ֶ���1--�Զ�
	int iParam2;    		//����
							//1--����Ԥ��λ���᣺δʹ��
							//2--�����Զ���ת��δʹ��
							//3--Ԥ��λ�ٶȵȼ���δʹ��
							//4--�ֿ��ٶȵȼ���δʹ��
							//5--���ô���������0--Ԥ��λ��1--ɨ�裬2--Ѳ����3--ģʽ·��
							//6--�����ģʽ��"0--�ֶ�ʱ�������������ȣ�������ֵ��[0,10]��
								//1--�Զ�ʱ�����������\���ȣ�������ֵ��0-��ͣ�1-�ϵͣ�2-��׼��
								//3-�ϸߣ�4-��ߣ�"
	int iParam3;	//Ԥ��
	int iParam4;	//Ԥ��	
}DOMEPTZ;

/*****************************************************************************/
#define GET_USERDATA_INFO_MIN                            (0)                           
#define GET_USERDATA_INFO_TIME							 (GET_USERDATA_INFO_MIN )		//����û������е�ʱ����Ϣ
#define GET_USERDATA_INFO_OSD							 (GET_USERDATA_INFO_MIN +1)		//����û������е�OSD��Ϣ
#define GET_USERDATA_INFO_GPS                            (GET_USERDATA_INFO_MIN +2)		//����û������е�GPS��Ϣ
#define GET_USERDATA_INFO_VCA                            (GET_USERDATA_INFO_MIN +3)		//����û������е�VCA��Ϣ
#define GET_USERDATA_INFO_USER_DEFINE                    (GET_USERDATA_INFO_MIN +4)		//����û������е�VCA��Ϣ
#define GET_USERDATA_INFO_MAX                            (GET_USERDATA_INFO_MIN +4)	
/*****************************************************************************/

//�㲥��ϢID
#define MSG_VEHICLE_GPS_CALIBRATION				0x12001		//GPSУʱ iMsgValue(0:����,1:����)
#define MSG_VEHICLE_VOLTAGE						0x12002		//iMsgValue(��ʾ��ѹֵ)
#define MSG_VEHICLE_TEMPERATURE					0x12003		//iMsgValue(��ʾ�¶�ֵ)
#define MSG_VEHICLE_SATELLITE_NUM				0x12004		//iMsgValue(��ʾ���Ǹ���)
#define MSG_VEHICLE_SIGNAL_INTENSITY			0x12005		//iMsgValue(��ʾGPS�ź�ǿ��)
#define MSG_VEHICLE_GPS_MODULE_TYPE				0x12006		//GPSģ������ iMsgValue(0:��ģ��,1:GPS,2:����)
#define MSG_VEHICLE_ALARM_THRESHOLD				0x12007		//��ѹ������ֵ
#define MSG_VEHICLE_SHUTDOWN_THRESHOLD			0x12008		//��ѹ�ػ���ֵ

#define MSG_VALUE_MAX_LEN 64
typedef struct  
{
	int iMsgID;								//��ϢID
	int iChannelNo;							//ͨ����
	int iMsgValue;							//��Ϣ��������
	char cMsgValue[MSG_VALUE_MAX_LEN];		//��Ϣ��������
}BROADCAST_MSG,*PBROADCAST_MSG;

//ģ������ID
#define MODULE_CAP_MIN				(0) 
#define MODULE_CAP_VEHICLE	(MODULE_CAP_MIN+0)
#define MODULE_CAP_MAX		(MODULE_CAP_MIN+1)

//����ģ������
#define MODULE_CAP_VEHICLE_GPS_OVERLAY			0x1
#define MODULE_CAP_VEHICLE_POWER_DELAY			0x2
#define MODULE_CAP_VEHICLE_ALARM_THRESHOLD		0x4
#define MODULE_CAP_VEHICLE_SHUTDOWN_THRESHOLD	0x8

//ģ��485���̿���ָ��
#define KEYBOARD_CTRL_MIN			0
#define KEYBOARD_CURRENT_SCREEN		KEYBOARD_CTRL_MIN + 0 	//����UIѡ�д��ڣ�ValueΪUI���ں�
#define KEYBOARD_SINGLE_SCREEN 		KEYBOARD_CTRL_MIN + 1 	//������ʾUI���ڣ�ValueԤ��
#define KEYBOARD_PRESET_CALL		KEYBOARD_CTRL_MIN + 2 	//�ӵ�����ʾ�ָ���Valueδʹ��
#define KEYBOARD_SCREEN_RRSTORE 	KEYBOARD_CTRL_MIN + 3 	//����Ԥ��λ,ValueΪԤ��λ��
#define KEYBOARD_CTRL_MAX			KEYBOARD_CTRL_MIN + 4

#define TTEMPLATE_CMD_MIN				0
#define TTEMPLATE_CMD_SMART	(TTEMPLATE_CMD_MIN+0)
#define TTEMPLATE_CMD_VIDEO	(TTEMPLATE_CMD_MIN+1)
#define TTEMPLATE_CMD_MAX	(TTEMPLATE_CMD_MIN+2)

#define SMART_TTEMPLATE_MAX_NUM	4
typedef struct  
{
	int iWeek;								//�����յ�������Ϊ����iWeekday=7��������ռƻ�
	int iIndex[SMART_TTEMPLATE_MAX_NUM];		//ģ����1-8��-�����ã�-8����ģ��-ģ��
}SMART_TEMPLATE,*PSMART_TEMPLATE;

typedef struct  
{
	int iIndex;			//ģ����
	int iType;			//��������
	int iValue;			//����ֵ
}VIDEO_TEMPLATE,*PVIDEO_TEMPLATE;

//*****VIDEO_TEMPLATE��Ӧ��type��value******/
// 1--���뷽ʽ	0��H.264����M-JPEG����MPEG4
// 2--����Profile 0:baseline,1:main,2:high
// 3--�ֱ���	����ֱ���ҳ
// 4--֡��	1��
// 5--ѹ��ģʽ	0��CBR����VBR
// 6--����	��λΪKBytes/s����kbps�����ʣ��˴�Ӧ��(����)
// 7--��������	4����ԽС����Խ��
// 8--I֡֡��	0-100
// 9--��������	3������Ƶ������������Ƶ��������Ƶ��
// 10--��Ƶ�����㷨	AUDIO_CODEC_FORMAT_G711A   = 1,   /*G.711 A��*/
//					AUDIO_CODEC_FORMAT_G711Mu  = 2,   /*G.711 Mu��*/
//					AUDIO_CODEC_FORMAT_ADPCM   = 3,   /*ADPCM */
//					AUDIO_CODEC_FORMAT_G726    = 4,   /*G.726 */
//					AUDIO_CODEC_FORMAT_AAC_LC  = 22---31,   /*AAC */Ԥ��һ�������AAC������չ
//					AUDIO_CODEC_FORMAT_BUTT

//add by 20131022
#define DEVICE_STATE_MIN            0
#define DEVICE_STATE_BRIGHT			(DEVICE_STATE_MIN)    //����
#define DEVICE_STATE_ACUTANCE		(DEVICE_STATE_MIN+1)  //���
#define DEVICE_STATE_SYSTEM			(DEVICE_STATE_MIN+2)  //ϵͳ
#define DEVICE_STATE_MAX			(DEVICE_STATE_MIN+2)  

#define NVS_TIME NVS_FILE_TIME
typedef struct __tagSystemState
{
	int iSize;
	int iCamera;				//�����״̬
	int iHLimit;				//ˮƽ��λ
	int iVLimit;				//��ֱ��λ
	int iInterface;				//�ӿ�ģ��
	int iTSensor;				//�¶ȴ�����
	int temperature;			//����¶�
	int itemperatureScale;		//�¶ȵ�λ
	NVS_TIME strPublishData;		//��������
}TSystemState, *pTSystemState;

#define NET_CLIENT_MIN					0	
#define NET_CLIENT_DOME_MENU			(NET_CLIENT_MIN + 0)	//����˵�����
#define NET_CLIENT_DOME_WORK_SCHEDULE	(NET_CLIENT_MIN + 1)	//�������ģ�����
#define NET_CLIENT_INTERESTED_AREA		(NET_CLIENT_MIN + 2)	//����Ȥ����
#define NET_CLIENT_APPEND_OSD			(NET_CLIENT_MIN + 3)	//�����ַ�����
#define NET_CLIENT_LOGONFAILED_REASON	(NET_CLIENT_MIN + 4)	//��½ʧ��
#define NET_CLIENT_AUTOREBOOT			(NET_CLIENT_MIN + 5)	//NVR�Զ���������ʱ��
#define NET_CLIENT_IP_FILTER			(NET_CLIENT_MIN + 6)	//IP��ַ���ˣ��ڰ�������
#define NET_CLIENT_DATE_FORMATE			(NET_CLIENT_MIN + 7)	//�����ַ�������ʾ��ʽ
#define NET_CLINET_COLOR2GRAY			(NET_CLIENT_MIN + 8)	//��Ƶ��ת�Ҽ�ʱ��Ч
#define NET_CLINET_LANPARAM			    (NET_CLIENT_MIN + 9)	//�������ù���
#define NET_CLINET_DAYLIGHT_SAVING_TIME	(NET_CLIENT_MIN + 10)	//�����豸����ʱ
#define NET_CLINET_NETOFFLINE			(NET_CLIENT_MIN + 11)	//ǿ�ƶϿ��û�����
#define NET_CLINET_HTTPPORT				(NET_CLIENT_MIN + 12)	//HTTP�˿�
#define NET_CLINET_PICTURE_MERGE		(NET_CLIENT_MIN + 13)	//ͼ��ϳ�
#define NET_CLIENT_SNAP_SHOT_INFO		(NET_CLIENT_MIN + 14)	//ǰ��ץ�Ĳ���
#define NET_CLIENT_IO_LINK_INFO			(NET_CLIENT_MIN + 15)	//IO�����豸����
#define NET_CLIENT_DEV_COMMONNAME		(NET_CLIENT_MIN + 16)	//�Զ����豸ͨ�ýӿڵı���
#define NET_CLIENT_ITS_DEV_COMMONINFO	(NET_CLIENT_MIN + 17)	//ITS�豸ͨ����Ϣ
#define NET_CLIENT_MAX					(NET_CLIENT_MIN + 18)			

#define MAX_DOME_TYPE	25
#define MAX_DOME_PARA_GROUP_NUM		8
typedef struct __tagDomeParam
{
	int iType;
	int iParam1;
	int iParam2;
	int iParam3;
	int iParam4;
}TDomeParam, *pTDomeParam;

#define MAX_SCHEDULE 8
typedef struct __tagDomeWork
{
	int iBeginHour;
	int iBeginMinute;
	int iEndHour;
	int iEndMinute;
	int iWorkType;  //0���޶���1��Ԥ��λ2��ɨ�� 3��Ѳ�� 4��ģʽ
	int iWorkValue; //Ԥ��λ��ȡֵ��Χ1��8��ɨ���ȡֵ��Χ��1��4��Ѳ����ȡֵ��Χ��1��4��ģʽ·����ȡֵ��Χ��1��4 
	int iEnable;
}TDomeWork, *pTDomeWork;

//��ת��
typedef struct __tagColor2GrayParam
{
	int  m_isize;         //�ṹ���С
	int  m_iColor2Gray;   //��ת������
	int  m_iDayRange;     //��������ֵ
	int  m_iNightRange;   //ҹ������ֵ
	int  m_iTimeRange;    //��ʱ��Χ�����쿪ʼʱ�䣬���Ͽ�ʼʱ�䡣
	int  m_iColorDelay;   //��ת����ʱ
	int  m_iGrayDelay;    //��ת����ʱ
}TColor2GrayParam,*pTColor2GrayParam;

//��������
typedef struct __tagLanParam
{
	int m_iSize;		  //�ṹ���С
	int m_iNo;			  //������ţ�lan1��0�� lan2:1
	int m_iMode;		  //����ģʽ��0��������1����˫����2��������3��˫����
	int m_iSpeed;		  //����
}TLanParam,*pTLanParam;

#define MAX_DEVCOMNAME_NO   3		//ͨ��������Ŀ
#define DEVCOMNAME_VIDEO    0		//��Ƶ
#define DEVCOMNAME_ALARMIN	1       //��������
#define DEVCOMNAME_ALARMOUT 2       //�������
//�Զ����豸ͨ�ýӿڵı���
typedef struct __tagDevCommonName
{
	int  m_iSize;				//�ṹ���С
	int	 m_iChannelType;		//ͨ������
	char m_cChanneleName[LEN_64+1];   //ͨ������
}TDevCommonName,*pTDevCommonName;

typedef struct __tagDomeWorkSchedule
{	
	int iWeekDay;
	TDomeWork tWork[MAX_SCHEDULE];
}TDomeWorkSchedule, *pTDomeWorkSchedule;

#define  MAX_APPEND_DSD_LAY_BUM	7
#define MAX_OSD_LENGTH 256
typedef struct __tagAppendOSD
{
	int iSize;
	int iLayNo;
	int iColor;
	int iDiaphaneity;
	int iFontSize;
	int iPosX;
	int iPosY;
	char pcText[MAX_OSD_LENGTH];
}TAppendOSD, *pTAppendOSD;

#define MAX_INTERESTED_AREA_NUM	8
typedef struct __tagInterestedArea
{
	int iSize;
	int iIndex;
	int iEnable;
	int iAbsQp;
	int iQp;
	int iLeft;
	int iTop;
	int iRight;
	int iBottom;
}TInterestedArea, *pTInterestedArea;

#define MAX_NVR_AUTOREBOOT_SCHEDULE 9
typedef struct __tagAutoRebootSchedule
{
	int iSize;
	int iWeekDay;			//�����յ�������Ϊ0��6��7-ÿ�죬8-�Ӳ�
	int iHour;
	int iMinute;
}TAutoRebootSchedule, *pTAutoRebootSchedule;

#define MAX_IP_FILTER_NUM	16
typedef struct __tagIpFilter
{
	int iSize;
	char cIp[LENGTH_IPV4];
	char cSubMask[LENGTH_SUB_MASK];
	int iFilterType;								//��������:0,����IPȨ���趨;1,��ֹIP����;2,����IP����
	int iIpNum;										//����ip����,���֧��16����ͬ��IP��ַ
	char cFilterIp[MAX_IP_FILTER_NUM][LENGTH_IPV4];	//�����ַ�ַ������磺pcFilterIp[0]=��192.168.1.10��
}TIpFilter, *pTIpFilter;

typedef struct __tagDateFormat
{
	int iSize;
	int iFormatType;	//��ʽ����:case 0:/*yyyy/mm/dd*/; 1:/*mm/dd/yyyy*/; 2:/*dd/mm/yyyy*/; 3:/*M day yyyy*/; 4:/*day M yyyy*/
	char cSeparate;		//�ָ���,������Ϊ��/������-��
	char cReserved[3];	//�ֽڶ���
	int iFlagWeek;		//��ʾ�����Ƿ���ʾ: 0-����ʾ��1-��ʾ					
	int iTimeMode;		//��ʾʱ����ʽ: 0-24Сʱ�ƣ�1-12Сʱ��							
}TDateFormat, *pDateFormat;

//����ʱ
typedef struct __tagDaylightSavingTime
{
	int m_iSize;
	int m_iMonth;				//�·�
	int m_iWeekOfMonth;			//���ڱ��(0��ĩ����1���׸���2���ڶ�����3����������4�����ĸ�)
	int m_iDayOfWeek;			//���ڣ������յ�������Ϊ0��6��
	int m_iHourOfDay;			//Сʱ��0��23��
}TDaylightSavingTime, *pTDaylightSavingTime;

typedef struct __tagDaylightSavingTimeSchedule
{
	int m_iSize;
	int m_iDSTEnable;					//����ʱʹ��,0-���ã�1-����
	int m_iOffsetTime;					//ƫ��ʱ��,0��120����λ���֣�
	TDaylightSavingTime m_tBeginDST;	//��ʼʱ��
	TDaylightSavingTime m_tEndDST;		//����ʱ��
}TDaylightSavingTimeSchedule, *pTDaylightSavingTimeSchedule;

//Զ��ǿ�ƶϿ��û�����
typedef struct __tagNetOffLine
{
	int iSize;
	char cIPAddr[LENGTH_IPV4];		//IP��ַ������
	int iOffTime;					//�Ͽ�ʱ��,�룻��С10��
}TNetOffLine, *pTNetOffLine;

//HTTP�˿�
typedef struct __tagHttpPort
{
	int iSize;
	int iPort;			//http�˿ں�
	int iHttpsport;		//https�˿ں�,Ĭ��443
}THttpPort, *pTHttpPort;

//��¼ʧ�ܴ�����
#define UNKNOW_ERROR			0
#define CIPHER_USERNAME_ERROR	1
#define CIPHER_USERPASS_ERROR	2
#define NO_SUPPORT_ALGORITHM	3
#define LOGON_NET_ERROR			0xFF01
#define LOGON_PORT_ERROR		0xFF02

//�������������ģ������
#define CAMERA_PARA_MIN								0
#define CAMERA_PARA_IRIS_ADJUSTMENT 				CAMERA_PARA_MIN + 0		//0--��Ȧ����
#define CAMERA_PARA_WDR								CAMERA_PARA_MIN + 1		//1--����̬
#define CAMERA_PARA_BLC								CAMERA_PARA_MIN + 2		//2--���ⲹ��
#define CAMERA_PARA_EXPOSURE_TIME					CAMERA_PARA_MIN + 3		//3--�ع�ʱ��
#define CAMERA_PARA_SHUTTER_ADJUSTMENT				CAMERA_PARA_MIN + 4		//4--���ŵ���
#define CAMERA_PARA_GAIN_ADJUSTMENT					CAMERA_PARA_MIN + 5		//5--�������
#define CAMERA_PARA_GAMMA_ADJUSTMENT				CAMERA_PARA_MIN + 6		//6--gamma����
#define CAMERA_PARA_SHARPNESS_ADJUSTMENT			CAMERA_PARA_MIN + 7		//7--��ȵ���
#define CAMERA_PARA_NOISE_REDUCTION_ADJUSTMENT		CAMERA_PARA_MIN + 8		//8--�������
#define CAMERA_PARA_EXPOSURE_REGION					CAMERA_PARA_MIN + 9		//9--�ع�����
#define CAMERA_PARA_BLC_REGION						CAMERA_PARA_MIN + 10	//10--���ⲹ������
#define CAMERA_PARA_AF_REGION_SET					CAMERA_PARA_MIN + 11	//11--AF��������
#define CAMERA_PARA_TARGET_BRIGHTNESS_ADJUSTMENT	CAMERA_PARA_MIN + 12	//12--Ŀ�����ȵ���
#define CAMERA_PARA_WHITE_BALANCE_ADJUSTMENT		CAMERA_PARA_MIN + 13	//13--��ƽ�����
#define CAMERA_PARA_JPEG_IMAGE_QUALITY				CAMERA_PARA_MIN + 14	//14--JPEGͼ������
#define CAMERA_PARA_LUT_ENABLE						CAMERA_PARA_MIN + 15	//15--LUTʹ��
#define CAMERA_PARA_AUTOMATIC_BRIGHTNESS_ADJUST		CAMERA_PARA_MIN + 16	//16--�Զ����ȵ���ʹ��
#define CAMERA_PARA_HSBLC							CAMERA_PARA_MIN + 17	//17--ǿ�����ƹ���
#define CAMERA_PARA_AUTO_EXPOSURE_MODE				CAMERA_PARA_MIN + 18	//18--�Զ��ع�ģʽ
#define CAMERA_PARA_SCENE_MODE						CAMERA_PARA_MIN + 19	//19--����ģʽ
#define CAMERA_PARA_FOCUS_MODE						CAMERA_PARA_MIN + 20	//20--�۽�ģʽ
#define CAMERA_PARA_MIN_FOCUSING_DISTANCE			CAMERA_PARA_MIN + 21	//21--��С�۽�����
#define CAMERA_PARA_DAY_AND_NIGHT					CAMERA_PARA_MIN + 22	//22--��ҹ�л�
#define CAMERA_PARA_RESTORE_DEFAULT					CAMERA_PARA_MIN + 23	//23--�ָ�Ĭ��
#define CAMERA_PARA_THROUGH_FOG						CAMERA_PARA_MIN + 24	//24--ȥ��
#define CAMERA_PARA_MAX								CAMERA_PARA_MIN + 25

//����˵�����ģ������
#define DOME_PARA_MIN										0
#define DOME_PARA_PRESET_TITLE_DISPLAY_TIME					DOME_PARA_MIN + 1		//1--Ԥ��λ������ʾʱ��
#define DOME_PARA_AUTOMATIC_FUNCTION_TITLE_DISPLAY_TIME		DOME_PARA_MIN + 2		//2--�Զ����ܱ�����ʾʱ��
#define DOME_PARA_REGION_TITLE_DISPLAY_TIME					DOME_PARA_MIN + 3		//3--���������ʾʱ��
#define DOME_PARA_COORDINATE_DIRECTION_DISPLAY_TIME			DOME_PARA_MIN + 4		//4--���귽����ʾʱ��
#define DOME_PARA_TRACEPOINTS_DISPLAY_TIME					DOME_PARA_MIN + 5		//5--���ٵ������ʾʱ��
#define DOME_PARA_TITLE_BACKGROUND							DOME_PARA_MIN + 6		//6--���ⱳ��
#define DOME_PARA_AUTOMATIC_STOP_TIME						DOME_PARA_MIN + 7		//7--�Զ�ֹͣʱ��
#define DOME_PARA_MENU_OFF_TIME								DOME_PARA_MIN + 8		//8--�˵��ر�ʱ��
#define DOME_PARA_VERTICAL_ANGLE_ADJUSTMENT					DOME_PARA_MIN + 9		//9--��ֱ�Ƕȵ���
#define DOME_PARA_MANIPULATION_SPEED_RATING					DOME_PARA_MIN + 10		//10--�ٿ��ٶȵȼ�
#define DOME_PARA_PRESET_SPEED_RATING						DOME_PARA_MIN + 11		//11--Ԥ��λ�ٶȵȼ�
#define DOME_PARA_TEMPERATURE_CONTROL_MODE					DOME_PARA_MIN + 12		//12--�¶ȿ���ģʽ
#define DOME_PARA_485_ADDRESS_SETTING						DOME_PARA_MIN + 13		//13--485��ַ����
#define DOME_PARA_ZERO_SETTING								DOME_PARA_MIN + 14		//14--�������
#define DOME_PARA_NORTH_SETTING								DOME_PARA_MIN + 15		//15--ָ������
#define DOME_PARA_CONTROL_MODE								DOME_PARA_MIN + 16		//16--���Ʒ�ʽ
#define DOME_PARA_SENSITIVE_THRESHOLD						DOME_PARA_MIN + 17		//17--�й���ֵ
#define DOME_PARA_DELAY_TIME								DOME_PARA_MIN + 18		//18--��ʱʱ��
#define DOME_PARA_ZOOM_MATCH								DOME_PARA_MIN + 19		//19--�䱶ƥ��
#define DOME_PARA_PRESET									DOME_PARA_MIN + 20		//20--Ԥ��λ
#define DOME_PARA_SCANNING									DOME_PARA_MIN + 21		//21--ɨ��
#define DOME_PARA_SCHEMA_PATH								DOME_PARA_MIN + 22		//22--ģʽ·��
#define DOME_PARA_SCHEMA_PATH_CURRENT_STATE					DOME_PARA_MIN + 23		//23--ģʽ·����ǰ״̬
#define DOME_PARA_REGIONAL_INDICATIVE						DOME_PARA_MIN + 24		//24--����ָʾ
#define DOME_PARA_CRUISE									DOME_PARA_MIN + 25		//25-Ѳ��
#define DOME_PARA_MAX										DOME_PARA_MIN + 26

#define COMMAND_ID_MIN					0
#define COMMAND_ID_ITS_FOCUS			COMMAND_ID_MIN + 1		//���۽��������Э��
#define COMMAND_ID_MAX					COMMAND_ID_MIN + 2

//ͼ��ϳɷ�ʽ����
#define MAX_ITS_MERGE_TYPE	4
typedef struct __tagTITS_MergeInfo
{
	int		m_iSize;
	int		m_iMergeType;		//�ϳ�ͼƬ��������:2-���źϳɷ�ʽ����,3-���źϳɷ�ʽ����
	int		m_iMergeMode;		//�ϳɷ�ʽ:���źϳɷ�ʽ���ͣ�0-��ֱ�ϳ�ģʽ,1-ˮƽ�ϳ�ģʽ
	//���źϳɷ�ʽ����:0-Ʒ����,��һ�¶�;1-Ʒ����,�϶���һ;2-�����һ;3-��һ�Ҷ�;
	//4-��ֱ����;5-ˮƽ����;6-������
	int		m_iResizePercent;	//ͼ�����ű���
}TITS_MergeInfo, *PTITS_MergeInfo;

//ǰ��ץ�Ĳ���
#define MAX_LINK_CAMERA_ID		4
typedef struct __tagTITS_SnapShotInfo
{
	int		m_iSize;
	int		m_iRoadNo;				//�������
	int		m_iEnable;				//ʹ��
	char	m_cLinkIP[LENGTH_IPV4];	//�������IP
	int		m_iLinkRoadNo;			//�����������ID
}TITS_SnapShotInfo, *pTITS_SnapShotInfo;

//IO�����豸��������
#define MAX_IO_DEVICE_NUM	10
typedef struct __tagTITS_IOLinkInfo
{
	int   m_iSize;
	int   m_iIONo;			//IO�ڱ��,0-10
	int   m_iLinkDevice;	//�豸��������,0-�����,1-Ƶ����
}TITS_IOLinkInfo, *pTITS_IOLinkInfo;

//ʱ��������ʹ��
typedef struct __tagTITS_FlashEnable
{
	int   m_iSize;
	int   m_iIndex;				//ʱ��α��,0-7��֧�����8��ʱ���
	int   m_iFlashLampEnable;	//�Ƿ����������
	int   m_iVideoLinkEnbale;	//��Ƶ����ʹ��,��λbit0:0-��ʹ�ܣ�1-ʹ��
}TITS_FlashEnable, *pTITS_FlashEnable;

#define REBUILDINDEX_SUCCESS			0
#define REBUILDINDEX_NO_DISK			1
#define REBUILDINDEX_EXCEPTION			2

#define MAX_ITS_DEV_COMMOMINFO_TYPE		3
typedef struct tagITS_DevCommonInfo
{
	int		iSize;
	int		iType;					//��Ϣ����,0-������1-���ش��룬2-��������
	char	cCommonInfo[LEN_64];	//��Ϣ����,���Ȳ�����63�ַ�
}ITS_DevCommonInfo, *pITS_DevCommonInfo;

typedef struct tagITS_CamLocationEx
{
	int				iSize;
	ITS_CamLocation tITS_CamLocation;	//�������λ���豸��Ϣ�ṹ��
	int				iDeviceType;		//�豸����,��λ��bit0��������豸,bit1������֤�豸,bit2�����¼��,
										//bit3����������,bit4�����ڼ��,bit5���������֤�豸��
}ITS_CamLocationEx, *pITS_CamLocationEx;

#endif
