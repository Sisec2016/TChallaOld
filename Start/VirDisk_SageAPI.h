// VirDisk_SageAPI.h : VirDisk_SageAPI DLL ����ͷ�ļ�
//

#ifndef __VIR_DISK_API_H__
#define __VIR_DISK_API_H__


#ifdef _Sage_USB_API_DLL
#define SAGE_API extern "C" _declspec(dllexport)
#else
#define SAGE_API extern "C" _declspec(dllimport)
#endif

#define MAX_VIRDISK_NUM	11
#define EXIST_MARK	0XF5

#define FILESYS_NONE				0
#define FILESYS_FAT					1
#define FILESYS_NTFS					2

//UnMount����
#define ERR_FILES_OPEN		6
#define TC_IOCTL(CODE) (CTL_CODE (FILE_DEVICE_UNKNOWN, 0x800 + (CODE), METHOD_BUFFERED, FILE_ANY_ACCESS))
#define TC_IOCTL_DISMOUNT_VOLUME						TC_IOCTL (4)
#define TC_IOCTL_DISMOUNT_ALL_VOLUMES					TC_IOCTL (5)
#define TC_IOCTL_GET_MOUNTED_VOLUMES				TC_IOCTL	(6)
#define TC_IOCTL_GET_DRIVER_VERSION											TC_IOCTL(1)
#define TC_IOCTL_LEGACY_GET_DRIVER_VERSION 							466968
#define WIN32_ROOT_PREFIX "\\\\.\\SageDisks"	

#define SSDDEVICE_INFO_LEN					64
typedef struct _SSDDeviceInfo
{
	UINT8 m_szPsn[32] ;							//PSN��
	UINT8 m_szDeviceName[20] ;				//SSD����������
	UINT32 m_nVolumeNum ;				//��������
	UINT8 m_chDiskLetter[8] ;							//�����̷�
}SSDDeviceInfo;

#define MAX_SAGE_SSD_COUNT 10
typedef struct _CurrentSSDDevInfo
{
	SSDDeviceInfo m_ssdDeviceList[ MAX_SAGE_SSD_COUNT ] ;
	UINT8 m_nSSDDevNum ;
	UINT8 m_Rev[3] ;
}CurrentSSDDevInfo;

#define SAFEDISK_INFO_LEN_SECTORS		2
typedef struct _SafeDiskInfo
{
	UINT8 m_szVersion[32] ;					//��ǰ�汾��
	UINT32 m_nPCNumber;					//��ǰ��ʹ��PC����
	UINT8 m_nBlockIndex[400];				//����������
	UINT32 m_nLimitPCNumber;			//������Ŀ
	UINT8 m_szPasswd[32] ;					//����
	UINT8 m_szKey[32] ;							//������Կ
	UINT32 m_nCurIndex;						//��ǰPC������ 
	UINT8 m_szPSN[32] ;						//��ǰ�豸PSN
	UINT32 m_nPromptMark ;					//����û��Լ�������������ʾ�����Ϊ0xf5 ����Ϊ����е��������
	UINT8 m_szLoginQuestion[32] ;		//������ʾ��Ϣ
	UINT8 m_szUserAnswer[32] ;			//�û���
	UINT8 m_isLogin ;							//��½״̬
	UINT8 m_nRvs[415];							//����
}SafeDiskInfo;

#define VIR_DISK_INFO_LEN 160
#define VDISK_NAME_LEN		64		//��ȫ�����Ƴ���
//��ȫ����Ϣ
typedef struct _VirDiskInfo
{
	UINT8 m_IsExist;				//���ڱ��									
	UINT8 m_nIsMount;			//���ر��
	UINT8 m_chDiskLetter;		//�����̷�
	UINT8 m_Rev ;					//����λ
	UINT8 m_chFilePath[VDISK_NAME_LEN];		//����·��
	UINT8 m_chDiskName[VDISK_NAME_LEN];	//���ش���ȯ��
	UINT64 m_nDiskCap;									//��ȫ������
	UINT8 m_nRev[16];										//����λ
}VirDiskInfo;

#define SECURITY_DISK_INFO_LEN_SECTOR			4				
//���ݱ���Ϣ
typedef struct _SecurityDiskInfo
{
	UINT32 m_nVirDiskCnt;										//��ȫ������
	VirDiskInfo m_VirDiskInfo[MAX_VIRDISK_NUM];	//��ȫ����Ϣ
	UINT32 m_nCurIndex ;										//�ڵ�ǰPC�ϵ�����λ�ñ��
	UINT8 m_szPSN[32] ;											//��ǰ�豸PSN��
	UINT8 m_CheckBit ;											//���������Ա��λ
	UINT8 m_Rev[236] ;											//����λ
}SecurityDiskInfo;

//UnMount�ṹ��
typedef struct
{
	int nDosDriveNo;	/* Drive letter to unmount */
	BOOL ignoreOpenFiles;
	BOOL HiddenVolumeProtectionTriggered;
	int nReturnCode;	/* Return code back from driver */
} UNMOUNT_STRUCT;

typedef struct
{
	unsigned __int32 ulMountedDrives;	/* Bitfield of all mounted drive letters */
	wchar_t wszVolume[26][MAX_PATH];	/* Volume names of mounted volumes */
	unsigned __int64 diskLength[26];
	int ea[26];
	int volumeType[26];	/* Volume type (e.g. PROP_VOL_TYPE_OUTER, PROP_VOL_TYPE_OUTER_VOL_WRITE_PREVENTED, etc.) */
} MOUNT_LIST_STRUCT;


//	��ȫ��������
#define DEVICE_BASE_NAME    _T("\\FileDisk")
#define DEVICE_DIR_NAME     _T("\\Device")      DEVICE_BASE_NAME
#define DEVICE_NAME_PREFIX  DEVICE_DIR_NAME     DEVICE_BASE_NAME

#define FILE_DEVICE_FILE_DISK       0x8000
#define IOCTL_FILE_DISK_OPEN_FILE   CTL_CODE(FILE_DEVICE_FILE_DISK, 0x800, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_FILE_DISK_CLOSE_FILE  CTL_CODE(FILE_DEVICE_FILE_DISK, 0x801, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_FILE_DISK_QUERY_FILE  CTL_CODE(FILE_DEVICE_FILE_DISK, 0x802, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_FILE_DISK_GET_DISK_VERSION	CTL_CODE(FILE_DEVICE_FILE_DISK, 0x805, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)


#define SAGE_VERSION	"SageVirDisk"
#define TC_MOUNT_PREFIX "\\Device\\SageDisksVolume"

/************************************************************************/
/* ���������������������Ƿ���������������װ
* �������:
*		szDriverPath: ����·��
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API int __stdcall MyDriverAttachW_SageAPI( WCHAR *szDriverPath );

/************************************************************************/
/* ��aStartLetter֮���ȡ��Ч��δ��ռ�õ��̷�
* �������:
*		aStartLetter: ��ʼ�̷�
*���������
*		aVailLetter: ���صĿ����̷�
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
UINT32 __stdcall GetVailLunA_SageAPI( CHAR* aVailLetter , CHAR  aStartLetter = 'D' );

/************************************************************************/
/*  ж�ذ�ȫ��  
* �������:
*		iDriverNo: ��ȫ����ţ�����A�� ��Ӧ 0 �� C�� ��Ӧ 2��
*		bForceUnmount: ǿ��ж�أ����ܵ�ǰ�����Ƿ����ļ���ռ��
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API BOOL __stdcall UnMountVolume(int iDriverNo,BOOL bForceUnmount = TRUE);

/************************************************************************/
/* ж�����а�ȫ��
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API UINT32 __stdcall UnMountAllVolume();

/************************************************************************/
/* ��ȡ����δж�ذ�ȫ��
*���������
		unMountList����ȫ��������Ϣ�ṹ��
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API BOOL __stdcall GetUnMountAllVolumeList( MOUNT_LIST_STRUCT * unMountList);


/************************************************************************/
/*  ��ȡSAGE SSD��Ϣ
* ����:
*		_In szDeviceName : SSD�����豸���ƣ�
*		_Out ssdDevInfo����ǰSSD�ϵ����������Ϣ
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API UINT32 __stdcall GetSafeDiskInfoFromDeviceA_SageAPI( CHAR *szDeviceName ,SafeDiskInfo *ssdDevInfo) ;

/************************************************************************/
/*  ����SSD�豸����Ϣ��������Ϣд��SSD�豸  
* ����:
*		_In szDeviceName : SSD�����豸���ƣ�
*		_In ssdDevInfo����ǰSSD�ϵ����������Ϣ
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API UINT32 __stdcall SetSafeDiskInfoA_SageAPI( CHAR *szDeviceName ,SafeDiskInfo *ssdDevInfo ) ;

/************************************************************************/
/*  ���豸�л�ȡ��ȫ��������Ϣ  
* ����:
*		_In szDeviceName : SSD�����豸���ƣ�
*		_In aStartIndex��PC�ڵ�ǰSSD�ϵ�������Ϣ����λ��
*		_In aSectsToWrite��������Ϣռ�ÿռ��С
*		_Out secDiskInfo��������Ϣ
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API UINT32 __stdcall GetSecurityDiskInfoFromDeviceA_SageAPI( CHAR *szDeviceName , DWORD aStartIndex, DWORD aSectsToRead, SecurityDiskInfo * secDiskInfo ) ;

/************************************************************************/
/*  ������������������  
* ����:
*		_In szDeviceName : SSD�����豸���ƣ�
*		_In aStartIndex��PC�ڵ�ǰSSD�ϵ�������Ϣ����λ��
*		_In aSectsToWrite��������Ϣռ�ÿռ��С
*		_In secDiskInfo��������Ϣ
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API UINT32 __stdcall SetSecurityDiskInfoA_SageAPI( CHAR *szDeviceName , DWORD aStartIndex, DWORD aSectsToWrite, SecurityDiskInfo * secDiskInfo ) ;


/************************************************************************/
/*  ���Ҿ����ļ����ڷ���  
* ����:
*		_In_Out szFileName : ����·�����ƣ�
*		_In_Out chLetter�����������̷�
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API BOOL __stdcall  isSafeAreaImgFileExistA_SageAPI( char *szFileName ,  CHAR &chLetter ) ;

typedef struct _CREATE_SECURITY_DISK_PARAM
{
	HWND hwnd;												//���մ�������Ĵ��ھ��
	INT iDriverNo;											//��ȫ�������̷����
	UINT64 nDiskCapacity;								//��ȫ������
	WCHAR wDiskImageFilePath[VDISK_NAME_LEN] ;	//��ȫ�������ļ�·��
	INT nDiskSysType;										//��ȫ���ļ�ϵͳ����
	BOOL bQuickFormate ;								//��ȫ���Ƿ�ִ�п��ٸ�ʽ��
	BYTE szKey[32];												//��ȫ��������Կ
	UINT32 nKeyLength;									//��Կ����
}CreateSecurityDiskParam;

/************************************************************************/
/*  ������ȫ�����̵��ýӿ�
* ����:
*		_In wCreateFilePath : ��ȫ����������·��
*		_In aCreateParam����ȫ����������
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API BOOL __stdcall  CreateSecurityDiskW_SageAPI( const WCHAR *wCreateFilePath , const CreateSecurityDiskParam aCreateParam ) ;

typedef struct _MOUNT_SECURITY_DISK_PARAM
{
	HWND hwnd;												//���ܹ��ؽ���Ĵ��ھ��
	WCHAR wDiskImageFilePath[VDISK_NAME_LEN] ;	//��ȫ�������ļ�·��
	BYTE szKey[32];												//��ȫ��������Կ
	UINT32 nKeyLength;									//��Կ����
}MountSecurityDiskParam;

/************************************************************************/
/*  ���ذ�ȫ�����̵��ýӿ�
* ����:
*		_In wCreateFilePath : ��ȫ����������·��
*		_In aMountParam����ȫ����������
*		_Out chMountLetter : ��ȫ�������̷�
*		_In chMaxLetter : ��ǰ��ȫ�������������ʹ�õ��̷�
* ����ֵ��
*	 	0--�ɹ�����0--ʧ�� 
/************************************************************************/
SAGE_API UINT32 __stdcall MountSecurityDiskW_SageAPI( const WCHAR *wMountFilePath , const MountSecurityDiskParam aMountParam , WCHAR &chMountLetter , WCHAR chMaxLetter = L'D' ) ;

/************************************************************************/
/*  ��֤��½����
* ����:
*		_In cDeviceName : SSD�̷�����
*		_In cPassword����½���������
* ����ֵ��
*	 	1--�ɹ���0--ʧ�� 
/************************************************************************/
SAGE_API BOOL __stdcall VerifyLoginPasswordA_SageAPI(CHAR* cDeviceName,CHAR* cPassword);
/************************************************************************/
/*  �޸ĵ�¼����
* ����:
*		_In cDeviceName : SSD�̷�����
*		_In cNewPassword���µĵ�½����
* ����ֵ��
*	 	0--�ɹ�����0--ʧ��  
/************************************************************************/
SAGE_API UINT32 __stdcall ModifyLoginPasswordA_SageAPI(CHAR* cDeviceName,CHAR* cNewPassword);
#endif //__VIR_DISK_API_H__