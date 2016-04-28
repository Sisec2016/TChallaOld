#ifndef _LOGHEADER_H_
#define _LOGHEADER_H_

#include "Poco/Types.h"

using namespace Poco;


//������־����
typedef enum 
{
	LOG_NoneDef   = -1,
	LOG_Download  = 0,
	LOG_FtpUpload = 1,
	LOG_ShareExpt = 2,
	LOG_DiskExpt  = 3,
	LOG_ScreenRec = 4,
	LOG_NetConfig = 5,
	LOG_FileDel   = 6,

	LOG_NoDefine  = 10,
}LogOperate;

typedef enum 
{
	LOG_NONE			= 0,
	LOG_ALARM			= 1,
	LOG_ABNORMAL		= 2,      
	LOG_OPERATION		= 3,     
	LOG_TYPENUM,    	
	ALL_LOG_TYPE	    = 255,   
}LOG_TYPE;


typedef struct
{
	UInt32 flag;
	UInt32 uiEndNum;
}T_FirIndex_Flag;

//64λ��8���ֽ�
typedef struct
{
	UInt32 uiStartNum;
	T_FirIndex_Flag tFirFlag;
}T_FirIndex;
	
//��־�������ڶ�����SecIndex
typedef struct
{
	time_t uiLogTime;
	UInt32 uiLogPos; //Log���ݵ�pos
	short ucLogType; 
	char Reserved[6];//����λδ�� 
} T_SecIndex; //sizeof=16


typedef struct
{
	char        User[32];
	time_t       uiTime;
	LogOperate  uiOperate;
	char        srcDir[128];
	char        dstDir[128];
	char		describe[200];
}LogInfo;

#define LOG_HEAD            "" 
#define LOG_HEAD_SIZE       sizeof(LOG_HEAD)
#define LOGFILENAME         "Log.log"
#define LOG_FILESIZE_64M 	(64*1024*1024)
#define FIRNUM    			(1000)        //����һ�ζ�ȡFirIndex�������Ŀ
#define SECBUFNUM_LOG   	(32*1024/sizeof(T_SecIndex))  
#define MAX_LOADNUM_LOG	 	(5000) //һ�������û������������Ŀ

#endif

