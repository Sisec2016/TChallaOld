
#ifndef HSX_CONFIG_DEFINE_H
#define HSX_CONFIG_DEFINE_H


#include "./hsx_netclient.h"


////////////////////////////////////////////////////////////////////////////////
// �����еĺ궨��
////////////////////////////////////////////////////////////////////////////////

#define max_user_cnt				(10)				// ����û��������а���һ������Ա�û�
#define max_normal_user_cnt			(max_user_cnt -1)	// ������ͨ�û������ǳ�ȥ����Ա������û���
#define max_user_name_len			(32)				// ����û����Ƴ���
#define max_user_pwd_len			(32)				// ����û����볤��

#define max_name_len				(32)				// �������Ƴ���
#define max_address_len				(64)				// ����ַ����
#define max_hdd_cnt					(8)					// ���֧�ֵ�Ӳ�̸���
#define max_alarm_out_cnt			(4)					// ��󱨾��������

#define motion_area_rect_row		(12)				// ������Ƶ���򱻷ָ��12*16�Ŀ飬�Կ�Ϊ��λ�������ƶ��������
#define motion_area_rect_column		(16)
#define max_mosaic_area_cnt			(4)					// ���������õ�����������ĸ���
#define day_per_week				(7)					// ÿ�ܵ�����
#define hour_per_day				(24)				// ÿ���Сʱ��

#define max_ptz_protocol_cnt		(16)				// ���֧�ֵ���̨Э�����
#define max_preset_point_cnt		(255)				// ���Ԥ�õ����
#define max_cruise_preset_cnt		(16)				// Ѳ����·�е����Ԥ�õ����

#define max_ddns_protocol_cnt		(32)				// ���ddnsЭ�����

#define max_email_username_len		(64)				// ���email�û�������
#define max_email_userpass_len		(32)				// ���email�û����볤��
#define max_email_receiver_cnt		(3)					// ���֧�ֵ��ʼ������߸���

#define max_wifi_search_cnt			(16)				// wifi�����������
#define max_spare_domain_cnt		(1)					// �����������
#define max_usb_disk_cnt			(4)					// ���֧�ֵ�u�̸���

////////////////////////////////////////////////////////////////////////////////
// ��������id
////////////////////////////////////////////////////////////////////////////////
enum msg_dvr_ctrl_id
{
	msg_get_wifi_search_info = 908,						// ��ȡwifi������Ϣ
	msg_get_usb_disk_info = 910,						// ��ȡU����Ϣ

	msg_get_device_cfg = 1000,							// ��ȡ�豸����
	msg_set_device_cfg,									// �����豸����

	msg_get_dst_cfg,									// ��ȡDST����
	msg_set_dst_cfg,									// ����DST����

	msg_get_ntp_cfg,									// ��ȡNTP����
	msg_set_ntp_cfg,									// ����NTP����

	msg_get_disk_cfg,									// ��ȡӲ������
	msg_set_disk_cfg,									// ����Ӳ������

	msg_get_user_cfg,									// ��ȡ�û�����
	msg_set_user_cfg,									// �����û�����

	msg_get_channel_basic_cfg,							// ��ȡͨ����������
	msg_set_channel_basic_cfg,							// ����ͨ����������
	msg_get_channel_ptz_cfg,							// ��ȡͨ��PTZ����
	msg_set_channel_ptz_cfg,							// ����ͨ��PTZ����

	msg_get_record_schedule_cfg,						// ��ȡ¼��ƻ�����
	msg_set_record_schedule_cfg,						// ����¼��ƻ�����
	msg_get_record_quality_cfg,							// ��ȡ¼��������
	msg_set_record_quality_cfg,							// ����¼��������

	msg_get_alarm_in_cfg,								// ��ȡ������������
	msg_set_alarm_in_cfg,								// ���ñ�����������
		
	msg_get_network_basic_cfg,							// ��ȡ�����������
	msg_set_network_basic_cfg,							// ���������������
	msg_get_network_advanced_cfg,						// ��ȡ����߼�����
	msg_set_network_advanced_cfg,						// ��������߼�����

	msg_get_channel_attr_cfg,							// ��ȡͨ����������
	msg_set_channel_attr_cfg,							// ����ͨ����������

	msg_get_ipc_cfg,									// ��ȡIPC����									
	msg_set_ipc_cfg,									// ����IPC����

	msg_get_network_wireless_cfg,						// ��ȡ������������
	msg_set_network_wireless_cfg,						// ����������������

	msg_get_device_info = 1100,							// ��ȡ�豸��Ϣ
	msg_get_channel_info,								// ��ȡͨ����Ϣ
	msg_get_alarm_in_info,								// ��ȡ����������Ϣ
	msg_get_network_info,								// ��ȡ������Ϣ
	msg_get_wireless_info,								// ��ȡ������Ϣ
};

////////////////////////////////////////////////////////////////////////////////
// ������Ϣ�ṹ�嶨��
////////////////////////////////////////////////////////////////////////////////

#pragma pack(push)
#pragma pack(1) 


// ��Ƶ��ʽ
typedef enum 
{
	VIDEO_STD_NTSC        = 0x00000001,					// NTSC
	VIDEO_STD_PAL         = 0x00000002,					// PAL
	VIDEO_STD_SECAM       = 0x00000004,					// SECAM
}video_stand_e;  


/*	
	�豸����
	��ȡ�豸���õ�����idΪmsg_get_device_cfg
	�����豸���õ�����idΪmsg_set_device_cfg
*/
typedef struct
{
	char dvr_name[max_name_len];						// dvr�豸����, ע��ʹ�õ���utf-8����
	long dvr_id;										// dvr�豸id������ң�������ã�
	long video_standard;								// ��Ƶ��ʽ����ο�video_stand_eö�����Ͷ���

	float latitude;										// �豸����γ�� [-90, 90] ����Чֵ��360
	float longitude;									// �豸���ھ��� [-180, 180]����Чֵ��360

	// �豸ʱ��
	DWORD year;											//	�꣬��2011
	DWORD month;										//	�£�0-11
	DWORD day;											//	�գ�1-
	DWORD hour;											//	ʱ��0-23
	DWORD minute;										//	�֣�0-59
	DWORD second;										//	�룬0-59
	
}dvr_device_cfg, *lpdvr_device_cfg;

// Ӳ��״̬
typedef enum
{
	DISK_STAT_ERROR	 	= -1,							// ����
	DISK_STAT_NORMAL 	= 0,							// ����
	DISK_STAT_WRITE 	= 1,							// ����д��
	DISK_STAT_FORMAT 	= 2,							// ���ڸ�ʽ��
}disk_state_e;


// ������������
typedef enum
{
	SUPPORT_CH_ATTR			= (1 << 0),					// �Ƿ�֧��ͨ������
	SUPPORT_SYNC_PLAYBACK	= (1 << 1),					// �Ƿ�֧��ͬ���ط�
	SUPPORT_ADVANCED_CFG	= (1 << 2),					/* �Ƿ�֧�ָ߼����ã�������ʹ�õ������汾��һ������¶���֧�ָ߼����õ�;
														�����ڱȽ��ϵ������᲻֧��dst��ntp�����ã��������������������dvr�豸*/
	SUPPORT_MULTI_STREAM    = (1 << 3),					// �Ƿ�֧�ֶ�����
	SUPPORT_WIFI			= (1 << 4),					// �Ƿ�֧��wifi
	SUPPORT_3G				= (1 << 5),					// �Ƿ�֧��3G
	SUPPORT_P2P				= (1 << 6),					// �Ƿ�֧��P2P
	PN_REBOOT				= (1 << 7),					// �޸���ʽ�Ƿ���Ҫ����
}net_capability_e;


// ��Ƶ�ֱ���
typedef enum
{
	ENC_SIZE_NOT_CARE = 0,		//ά��ԭ���ߴ粻��
	ENC_SIZE_CIF 	= 0x02,		//352*288
	ENC_SIZE_HD1	= 0x04,		//704*288
	ENC_SIZE_D1		= 0x08,		//704*576
	ENC_SIZE_720P	= 0x10,		//1280*720
	ENC_SIZE_1080P	= 0x20,		//1920*1080
	ENC_SIZE_SXGA	= 0x40,		//1280*1024
	ENC_SIZE_VGA	= 0x80,		//640*480
	ENC_SIZE_QVGA	= 0x100,	//320*240
	ENC_SIZE_QQVGA	= 0x200,	//176*128
	ENC_SIZE_1280x960 = 0x400,	//1280*960
}enc_size_e;

// �������Դ��������
typedef enum
{
	AD_LIMIT_BY_ENC_PERFOR, // �����ڿ��б�����Դ
	AD_LIMIT_BY_ANALOGO,	// �����ڿ���ģ��ͨ��
	AD_LIMIT_BY_NONE,		// ������
}ad_ch_resource_type;


/*	
	�豸��Ϣ��ֻ����
	��ȡ�豸��Ϣ������idΪmsg_get_device_info
*/
typedef struct
{
	char board_name[max_name_len];						// �������ƣ�������������У�飩
	DWORD board_id;										// ����id
	DWORD serial_number;								// ���к�
	char mac[max_name_len];								// �豸mac��ַ���磺00:0b:74:9f:5f:33

	char software_version_base[max_name_len];			// ��������汾��������������У�飬��ʽ:���汾.�ΰ汾.�޶��汾����1.0.0
	char software_version_main[max_name_len];			// ����汾����1.0.0
	char software_build_date[max_name_len];				// �����������
	char hardware_version[max_name_len];				// Ӳ���汾����1.0.0
	char hardware_build_date[max_name_len];				// Ӳ����������
	
	DWORD video_analog_cnt_max;							// ģ��ͨ��������
	DWORD video_digital_cnt_max;						// ����ͨ��������

	DWORD spot_cnt;										// spot����								
	DWORD audio_enc_cnt;								/* ��Ƶͨ������, ��ʾǰaudio_enc_cnt����Ƶͨ��֧����Ƶ,
														   ע�⣺����hvr/nvr�豸���ò�����Ч*/
	DWORD audio_talk_cnt;								// �����Խ�����

	DWORD alarm_in_cnt;									// �����������	
	DWORD alarm_out_cnt;								// �����������	

	DWORD video_enc_resolution;							/* ��Ƶ�����������ֱ��ʣ���enc_size_e���͵����, 
														   ע�⣺��net_capability֧��ͨ������ʱ���Ը�ͨ�������ڵķֱ�������Ϊ��*/
	DWORD video_analog_performance;						// ģ����Ƶ��������
	DWORD video_analog_digital_performance;				// ģ��������Ƶ���ñ�������
	DWORD video_digital_performance;					// ������Ƶ��������

	DWORD disk_cnt;										// Ӳ�̸���
	DWORD capacity[max_hdd_cnt];						// Ӳ������������λMB		
	DWORD useable[max_hdd_cnt];							// Ӳ�̿�ʹ����������λMB		
	DWORD write_status[max_hdd_cnt];					// Ӳ��״̬���μ�disk_state_e
	char disk_type[max_hdd_cnt][max_name_len];			// Ӳ������

	DWORD is_support_ch_auth;							// �豸�Ƿ�֧��ͨ��Ȩ��
	DWORD net_capability;								// ����������net_capability_e���͵����
	ad_ch_resource_type ad_ch_res_type;					// �������Դ��������

}dvr_device_info, *lpdvr_device_info;


/*	
	U����Ϣ��ֻ����
	��ȡU����Ϣ������idΪmsg_get_usb_disk_info
*/
typedef struct
{
	long disk_cnt;										// u�̸���
	long capacity[max_usb_disk_cnt];					// u������������λMB		
	long useable[max_usb_disk_cnt];						// u�̿�ʹ����������λMB		
	long write_status[max_usb_disk_cnt];				// u��״̬���μ�disk_state_e
	char disk_type[max_usb_disk_cnt][max_name_len];		// u������

}dvr_usb_disk_info;


/*	
	DST����
	��ȡDST���õ�����idΪmsg_get_dst_cfg
	����DST���õ�����idΪmsg_set_dst_cfg
*/
typedef struct
{
	// ����ʱDST
	DWORD dst_enable;									// �Ƿ�������ʱ��0--�ر� 1--����
	DWORD adjust_time_len_s;							// ������ʱ�䳤�� (��)

	// ����ʱ��ʼʱ��
	int begin_month;									// [0,11]
	int begin_week_index;								// [1-5]
	int begin_week_day;									// [0-6]
	int begin_hour;										// [0-23]
	int begin_minute;									// [0-59]
	int begin_second;									// [0-59]

	// ����ʱ����ʱ��
	int end_month;										// [0,11]
	int end_week_index;									// [1-5]
	int end_week_day;									// [0-6]
	int end_hour;										// [0-23]
	int end_minute;										// [0-59]
	int end_second;										// [0-59]	

}dvr_dst_cfg, *lpdvr_dst_cfg;



/*	
	NTP����
	��ȡNTP���õ�����idΪmsg_get_ntp_cfg
	����NTP���õ�����idΪmsg_set_ntp_cfg
*/
typedef struct
{
	int ntp_enable;										// �Ƿ�������ʱ��ͬ����0--�ر� 1--����
	int interval;										// ͬ��ʱ���� (24*3600 - 7*24*3600 ��)
	int timezone_hour;									// ʱ����ʱ(0-11)
	int timezone_min;									// ʱ������(0-59)

	char server[256];									// NTP������

}dvr_ntp_cfg, *lpdvr_ntp_cfg;	



/*	
	Ӳ������
	��ȡӲ�����õ�����idΪmsg_get_disk_cfg
	����Ӳ�����õ�����idΪmsg_set_disk_cfg
*/
typedef struct
{
	int overwrite_enable;								// �Ƿ���Ӳ�̸���

}dvr_disk_cfg, *lpdvr_disk_cfg;



// �û�Ȩ��
typedef enum
{	
	eAuthority_Undefined		= 0x00,
	eAuthority_Configuration	= 0x01,					// ϵͳ����Ȩ��
	eAuthority_PTZControl		= 0x02,					// ��̨����Ȩ��
	eAuthority_Playback			= 0x04,					// �ط�Ȩ��
	eAuthority_Backup			= 0x08,					// ����Ȩ��
	eAuthority_All				= eAuthority_Configuration | eAuthority_PTZControl | eAuthority_Playback | eAuthority_Backup,
}eAuthority;

/*	
	�û�����
	��ȡ�û����õ�����idΪmsg_get_user_cfg
	�����û����õ�����idΪmsg_set_user_cfg
*/
typedef struct
{
	int ch_auth_enable;									// �Ƿ�����ͨ��Ȩ�ޡ�ֻ���豸�д�����ʱ��������ͨ��Ȩ��

	char admin_name[max_user_name_len];					// ����Ա���ƣ�ֻ������ֻ����"Admin"	
	char admin_pass[max_user_pwd_len];					// ����Ա����
	DWORD admin_auth;									// ����ԱȨ�ޣ�ֻ����������Աӵ������Ȩ�ޣ��μ�eAuthority
	DWORD admin_ch_auth_mask;							// ͨ��Ȩ������

	DWORD user_cnt;										// ��ͨ�û��ĸ���
	char user_name[max_normal_user_cnt][max_user_name_len];	// ��ͨ�û����û����ƣ��û����Ʋ�Ϊ�յ��û���Ϊ��Ч�û�
	char user_pass[max_normal_user_cnt][max_user_pwd_len];	// ��ͨ�û����û�����
	DWORD user_auth[max_normal_user_cnt];				// ��ͨ�û���Ȩ��,�μ�eAuthorityö�����͵Ķ���
	DWORD user_ch_auth_mask[max_normal_user_cnt];		// ��ͨ�û���ͨ��Ȩ������
	
}dvr_user_cfg, *lpdvr_user_cfg;





/*	
	ͨ����������
	��ȡͨ���������õ�����idΪmsg_get_channel_basic_cfg
	����ͨ���������õ�����idΪmsg_set_channel_basic_cfg
*/
typedef struct
{	
	int video_channel;									// ͨ���ţ���0��ʼ
	char name[max_name_len];							// ͨ������, ע��ʹ�õ���utf-8����

	// ɫ�ʵ���
	DWORD brightness;									// ���� 0-255
	DWORD contrast;										// �Աȶ� 0-255
	DWORD saturation;									// ���Ͷ� 0-255
	DWORD hue;											// ɫ�� 0-255	
	DWORD sharpness;									// ��ȣ������ȣ� 0-255

	// �źŶ�ʧ���� 
	DWORD vl_trigger_record_mask;						// ����¼���ͨ�����룬�������0101��ʾ������1��3ͨ����¼��
	DWORD vl_trigger_alarm_out_mask;					// �������������ͨ�����룬����ͬ��
	DWORD vl_trigger_live;								// ����Ԥ����ͨ���ţ���0��ʼ��(DWORD)-1��ʾ�ر�����Ԥ��
	DWORD vl_trigger_buzzer;							// ��������������
	DWORD vl_trigger_email;								// �����ʼ�ͨ��

	// �ƶ���� 
	DWORD motion_en;									// �Ƿ���ƶ���⣬0--�ر� 1--����
	BYTE motion_area[motion_area_rect_row][motion_area_rect_column];// �ƶ���������Ժ��Ϊ��λ��0--���� 1--����
	DWORD motion_senstivity;							// �ƶ���������ȣ�0-4����ֵԽ��������Խ��
	DWORD mt_trigger_record_mask;						// ����¼���ͨ�����룬�������0101��ʾ������1��3ͨ����¼��
	DWORD mt_trigger_alarm_out_mask;					// �������������ͨ�����룬����ͬ��
	DWORD mt_trigger_live;								// ����Ԥ����ͨ���ţ���0��ʼ��(DWORD)-1��ʾ�ر�����Ԥ��
	DWORD mt_trigger_buzzer;							// ��������������						
	DWORD mt_trigger_mail;								// �����ʼ�ͨ��

	//������
	DWORD mosaic_cnt;									// �����˵ĸ���
	DWORD mosaic_x[max_mosaic_area_cnt];				// �����������x����, [��������ĸ�̶�Ϊ16�������Ƿ��ӵ�ֵ��0-16����ͬ]
	DWORD mosaic_y[max_mosaic_area_cnt];				// �����������y����
	DWORD mosaic_w[max_mosaic_area_cnt];				// ����������Ŀ��
	DWORD mosaic_h[max_mosaic_area_cnt];				// ����������ĸ߶�

}dvr_channel_basic_cfg, *lpdvr_channel_basic_cfg;

/*	
	ͨ��PTZ����
	��ȡͨ��PTZ���õ�����idΪmsg_get_channel_ptz_cfg
	����ͨ��PTZ���õ�����idΪmsg_set_channel_ptz_cfg
*/
typedef struct
{
	int video_channel;									// ͨ���ţ���0��ʼ
	//	PTZ
	DWORD speed;										// ��̨�ƶ����ٶȣ�1-16
	DWORD baudrate;										// �����ʣ�1200, 2400, 4800, 9600
	DWORD databit;										// ����λ
	DWORD stopbit;										// ֹͣλ
	DWORD parity;										// У��λ
	DWORD address;										// ��̨��ַ
	DWORD flowcontrol;									// ����

	DWORD protocol_index;								// ��ǰͨ������̨Э������	
	DWORD protocol_cnt;									// ��̨Э�����
	char protocol_name[max_ptz_protocol_cnt][max_name_len]; // ֧�ֵ���̨Э������

	DWORD cruise_preset_cnt;							// Ѳ��Ԥ�õ����
	DWORD cruise_preset[max_cruise_preset_cnt];			// Ѳ��Ԥ�õ�id����0��ʼ
	DWORD delay_time[max_cruise_preset_cnt];			// ͣ��ʱ��(��), 1-(24*3600)

}dvr_channel_ptz_cfg, *lpdvr_channel_ptz_cfg;

// ipc����
typedef enum eIPCType
{
	eIpcType_None,				// ����IPC
	eIPCType_AutoAdapt = 1,		// �Զ���ƥIPC������,�û�Ӧ�þ���ʹ��ȷ�е�����,�������Ϊ֧�����͵�����Ӱ��ɹ����ӵ�ʱ�� (Ԥ��)
	eIPCType_AMTK_V5,			// A-MTK V5��,һ��ָMTK 1.3Mega��IPC,��������5.0�� (Ԥ��)
	eIPCType_AMTK_V6,			// A-MTK V6��,һ��ָMTK 2.0Mega��IPC,��������6.0��
	eIPCType_GK,				// GK
	eIPCType_ONVIF,				// onvif
	eIPCType_IPUX,				// IPUX���ҵ�,����豸ֻ֧��һ������.
	eIPCType_ONVIF_TST,			// ����ͨONVIFЭ��,�����ò���.��Ϊ���ò����ᵼ���䲻����.
}eIPCType;


/*	
	ͨ����������
	��ȡͨ���������õ�����idΪmsg_get_channel_attr_cfg
	����ͨ���������õ�����idΪmsg_set_channel_attr_cfg
*/
typedef struct
{
	int video_channel;									// ͨ���ţ���0��ʼ
	int enable;											// ��ǰͨ���Ƿ��Ѿ�����.
	int is_ipcam;										// ��ǰͨ���Ǳ���ͨ������IPCAMͨ��. 0--���� 1--IPͨ����ֻ����
	int ipcam_port;										// IPCAM������˿�.
	int ipcam_channel;									// IPCAM��ͨ����,һ��Ϊ0.
	int ipcam_resolution;								// IPCAM�ı���ֱ���
	DWORD video_enc_resolution;							// ��Ƶ�����������ֱ��ʣ���enc_size_e���͵����

	DWORD ipcam_ipaddr;									// IPCAM��IP��ַ.
	char ipcam_username[max_user_name_len];				// ��½IPCAM���û���
	char ipcam_password[max_user_pwd_len];				// ��½IPCAM���û�����
	eIPCType ipcam_type;								// IPCAM����

}dvr_channel_attr_cfg, *lpdvr_channel_attr_cfg;

// ipc����ģʽ
 typedef enum
 {
 	IPC_AE_INDOOR_MODE = 0, //����ģʽ
 	IPC_AE_OUTDOOR_MODE = 1, //����ģʽ
 }ipc_ae_work_mode;

 typedef enum
 {
	 ICR_WORK_BY_CHECK_LEVEL,	// �Զ������ݵư����ѹ���������������
	 ICR_WORK_FORCE_DAY,		// ǿ�Ʋ�ɫ
	 ICR_WORK_FORCE_NIGHT,		// ǿ�ƺڰ�
 }icr_wrok_mode;

/*	
	IPC����
	��ȡIPC���õ�����idΪmsg_get_ipc_cfg
	����IPC���õ�����idΪmsg_set_ipc_cfg
*/
typedef struct
{
	// �Զ��ع�
	ipc_ae_work_mode work_mode;							// ����ģʽ
	long outdoor_day;									// ���ڰ��� 1-100
	long outdoor_night;									// ���ں�ҹ	1-100
	long indoor_day;									// �������1-100									
	long indoor_night;									// �����ҹ1-100
	long frequence;										// ��ԴƵ�� 50HZ/60HZ

	// ɫ��ģʽ
	char fixed_mode_start_hour;							// ��ʼСʱ��0-23,default 18
	char fixed_mode_start_min;							// ��ʼ���ӣ�0-59,default 0
	char fixed_mode_end_hour;							// ����Сʱ��0-23,default 21
	char fixed_mode_end_min;							// �������ӣ�0-59,default 0
	long fixed_mode;									// ǿ��Ϊ����ģʽ, �μ�icr_wrok_mode

}dvr_ipc_cfg, *lpdvr_ipc_cfg;

/*
	ͨ����Ϣ��ֻ����
	��ȡͨ����Ϣ������idΪmsg_get_channel_info
*/
typedef struct
{
	int video_channel;									// ͨ���ţ���0��ʼ

	DWORD is_recording;									// �Ƿ�����¼��0--δ¼�� 1--����¼��
	DWORD record_type;									// ¼�����ͣ��μ�record_type_eö�����Ͷ���
	DWORD record_resolution;							// ¼��ֱ��ʣ� �μ�enc_size_eö�����͵Ķ���
	DWORD record_fps;									// ʵ��֡�ʣ���λfps
	DWORD record_kpbs;									// ʵ�����ʣ���λkbps

	DWORD is_videolost;									// �ź��Ƿ�ʧ
	DWORD is_motion;									// ��ǰ�Ƿ����ƶ��¼�
	
}dvr_channel_info, *lpdvr_channel_info;





// ¼��������
typedef enum
{
	eRecordSourceType_VideoOnly,						// ��Ƶ��	
	eRecordSourceType_VideoAudio,						// ����Ƶ������
	eRecordSourceType_Undefined							// δ����
}eRecordSourceType;

/*	
	¼��ƻ�����
	��ȡ¼��ƻ����õ�����idΪmsg_get_record_schedule_cfg
	����¼��ƻ����õ�����idΪmsg_set_record_schedule_cfg
*/
typedef struct 
{
	int video_channel;									// ͨ���ţ���0��ʼ

	DWORD stream_type;									// ¼��������ͣ��μ�eRecordSourceTypeö�����Ͷ���
	DWORD prerecord_time;								// Ԥ¼ʱ��	
	DWORD delayrecord_time;								// �ӳ�¼��ʱ��		
	BYTE schedule[day_per_week][hour_per_day];			// һ�ܵ�¼��ƻ�����СʱΪ��λ�������ã�¼�����Ͳμ�record_type_e

}dvr_record_schedule_cfg;

/*	
	¼��������
	��ȡ¼�������õ�����idΪmsg_get_record_quality_cfg
	����¼�������õ�����idΪmsg_set_record_quality_cfg
*/
typedef struct 
{
	int video_channel;									// ͨ���ţ���0��ʼ

	int bitrate;										/* ��ͨ¼������, ��λkbps��
														   ȡֵ��Χ��256, 384, 512, 640, 768, 1024, 1536, 2048, 2560, 3072, 4096, 5120, 6144 */
	int framerate;										// ��ͨ¼��֡�ʣ�1-30 ��FPS��
	int resolution;										// ��ͨ¼��ֱ��ʣ��μ�enc_size_e

	int event_bitrate;									/* �¼�¼������, ��λkbps��
														   ȡֵ��Χ��256, 384, 512, 640, 768, 1024, 1536, 2048, 2560, 3072, 4096, 5120, 6144 */
	int event_framerate;								// �¼�¼��֡�ʣ�1-30 ��FPS��
	int event_resolution;								// �¼�¼��ֱ��ʣ��μ�enc_size_e
						 
}dvr_record_quality_cfg; 





/*	
	������������
	��ȡ�����������õ�����idΪmsg_get_alarm_in_cfg
	���ñ����������õ�����idΪmsg_set_alarm_in_cfg
*/
typedef struct
{
	int alarm_in_channel;								// ��������ͨ���ţ���0��ʼ
	DWORD device_type;									// �����豸���ͣ�0--���� 1--����
	BYTE schedule[day_per_week][hour_per_day];			// һ�ܵı����ƻ�����СʱΪ��λ�������ã�0--���� 1--����

	DWORD trigger_record_mask;							// ����¼���ͨ�����룬�������0101��ʾ������1��3ͨ����¼��
	DWORD trigger_alarm_out_mask;						// �������������ͨ�����룬����ͬ��
	DWORD trigger_live;									// ����Ԥ����ͨ���ţ���0��ʼ��(DWORD)-1��ʾ�ر�����Ԥ��
	DWORD trigger_preset;								// ������Ԥ�õ���������0��ʼ
	DWORD trigger_buzzer;								// ��������������
	DWORD trigger_mail;									// �����ʼ�ͨ��

}dvr_alarm_in_cfg, *lpdvr_alarm_in_cfg;

/*	
	����������Ϣ��ֻ����
	��ȡ����������Ϣ������idΪmsg_get_alarm_in_info
*/
typedef struct
{
	int alarm_in_channel;								// ��������ͨ���ţ���0��ʼ
	DWORD device_type;									// �����豸���ͣ�0--���� 1--����
	DWORD status;										// �豸״̬��0--���� 1--����
}dvr_alarm_in_info, *lpdvr_alarm_in_info;




/*	
	�����������
	��ȡ����������õ�����idΪmsg_get_network_basic_cfg
	��������������õ�����idΪmsg_set_network_basic_cfg
*/
typedef struct 
{
	int ip;												// ip��ַ
	int submask;										// ��������
	int gateway;										// ����
	int dns1;											// DNS1
	int dns2;											// DNS2

	int http_port;										// http�˿ڣ�Ĭ��80
	int cmd_port;										// ����˿ڣ�Ĭ��6001
	int data_port;										// ý��˿ڣ�Ĭ��6002
	int mobile_port;									// �ֻ��˿ڣ�Ĭ��6003
	
	int upnp_enable;									// UPnP���ã�0--�ر� 1--����
	int dhcp_enable;									// IP��ȡ��ʽ��0--��̬���� 1--��̬��ȡ
	int p2p_enable;										// �Ƿ�����P2P, 0--���ã�1--����

}dvr_network_basic_cfg, *lpdvr_network_basic_cfg;

/*	
	����߼�����
	��ȡ����߼����õ�����idΪmsg_get_network_advanced_cfg
	��������߼����õ�����idΪmsg_set_network_advanced_cfg
*/
typedef struct  
{
	DWORD pppoe_enable;									// �Ƿ������ţ�0--�ر� 1--����
	char pppoe_user[max_user_name_len];					// pppoe�û���
	char pppoe_pass[max_user_pwd_len];					// pppoe�û�����

	DWORD ddns_enable;									// �Ƿ�����̬������0--�ر� 1--����
	DWORD server_index;									// ��ǰʹ�õ�ddns��������������
	char domain_name[max_name_len];						// �豸����
	char ddns_user[max_user_name_len];					// ddns�û���
	char ddns_pass[max_user_pwd_len];					// ddns�û�����
	DWORD server_cnt;									// ��������������			
	char server_info[max_ddns_protocol_cnt][max_address_len]; // ������������Ϣ

	// email
	DWORD email_enable;									// �Ƿ������ʼ���0--�ر� 1--����
	char email_server[max_address_len];					// �����ʼ���������SMTP��
	DWORD email_port;									// �������˿�
	DWORD ssl_enable;									// �Ƿ���Ҫ��ȫ���ӣ�0--�ر� 1--����
	char email_sender[max_address_len];					// ����������
	char email_user[max_email_username_len];			// �û�����
	char email_pass[max_email_userpass_len];			// �û�����
	char email_receiver[max_email_receiver_cnt][max_address_len]; // �ռ�������
	int  need_snapshot;									// ����ץͼ��0--�ر� 1--����

	// subcode
	DWORD subcode_enable;								// �Ƿ�����������0--�ر� 1--����
	DWORD framerate_by_fps;								// ������֡�ʣ���λfps����Χ1-30
	DWORD bitrate_by_kbps;								// ���������ʣ���λkbps����Χ10-512

}dvr_network_advanced_cfg;

// 3G �����ṩ������
typedef enum provider_type_s
{
	NET_3G_AUTO,
	NET_3G_TD_SCDMA,
	NET_3G_WCDMA,		// �й���ͨ
	NET_3G_CDMA_1x,		// �й�����
	NET_3G_GPRS,		// �й��ƶ�
	NET_3G_EVDO,
}provider_type_t;

/*	
	������������
	��ȡ�����������õ�����idΪmsg_get_network_wireless_cfg
	���������������õ�����idΪmsg_set_network_wireless_cfg
*/
typedef struct
{
	// wifi
	long wifi_enable;									// �Ƿ�����WIFI��0--�ر� 1--����
	char wifi_pass[32];									// ���ʵ�wifi���������
	char wifi_ssid[32];									// ���ʵ�wifi�����SSID
	long wifi_auto_join;								// �Ƿ��Զ�����
	long wifi_enable_dhcp;								// wifi�˿��Ƿ�ʹ��dhcp
	long wifi_static_ip;								// ���ʹ��dhcp���������
	long wifi_static_submask;							// ���ʹ��dhcp���������
	long wifi_static_gw;								// ���ʹ��dhcp���������
	long wifi_static_dns1;								// ���ʹ��dhcp���������
	long wifi_static_dns2;								// ���ʹ��dhcp���������

	// 3G����
	long net3g_enable;									// �Ƿ���,1,����,0,����.
	provider_type_t net3g_provider_type;				// �����ṩ������
	char net3g_dial_number[32];							// ����
	char net3g_username[32];							// �û���
	char net3g_password[32];							// ����
	char net3g_apn[32];									// APN

}dvr_network_wireless_cfg;


/*	
	������Ϣ��ֻ����
	��ȡ������Ϣ������idΪmsg_get_network_info
*/
typedef struct
{
	int ip;												// ip��ַ
	int submask;										// ��������
	int gateway;										// ����
	int dns1;											// DNS1
	int dns2;											// DNS2
	char mac[max_name_len];								// �豸mac��ַ���磺00:0b:74:9f:5f:33

	// pppoe info
	int pppoe_status;									// ����״̬��0--δ���� 1--����
	int pppoe_ip;										// ����ip
	int pppoe_submask;									// pppoe��������
	int pppoe_gateway;									// pppoe����

	// �Դ�����
	char own_domain_name[64];							// ��������
	time_t last_update_time;							// ���һ���ɹ�ˢ��ip��ʱ�䣬������ʱ��Ϊ0
	char spare_domain_name[max_spare_domain_cnt][64];	// ������������
	time_t spare_last_update_time[max_spare_domain_cnt];// �����������һ������ˢ��ip��ʱ��

}dvr_network_info, *lpdvr_network_info;


/*	
	������Ϣ��ֻ����
	��ȡ������Ϣ������idΪmsg_get_wireless_info
*/
typedef struct
{
	// wifi
	char wifi_ssid[32];									// SSID
	long wifi_connect_status;							// �Ƿ�����
	long wifi_ip;										// wifi ip��ַ								
	long wifi_submask;									// wifi ��������
	long wifi_gw;										// wifi ����
	long wifi_dns1;										// wifi DNS1
	long wifi_dns2;										// wifi DNS2

	// 3G
	long net3g_status;									// �Ƿ�������
	long net3g_ip;										// IP
	long net3g_submask;									// ��������
	long net3g_gateway;									// ����
	int net3g_reserved[128];							// ������

}dvr_network_wireless_info;


/*	
	wifi������Ϣ��ֻ����
	��ȡwifi������Ϣ������idΪmsg_get_wifi_search_info
*/
typedef struct
{
	long count;											// ���ҵ���wifi���������
	char ssid[max_wifi_search_cnt][32];					// ssid
	long quality[max_wifi_search_cnt];					// �ź�ǿ�ȣ�0-100��0-������100-��ǿ
	long encryption[max_wifi_search_cnt];				// �Ƿ���ܣ�0-no��1-yes
	long is_join[max_wifi_search_cnt];					// �Ƿ��Ѽ��룬0-no 1-yes
	long state[max_wifi_search_cnt];					// ����״̬��0-no 1-yes
}wifi_search_info;


#pragma pack(pop)

#endif

