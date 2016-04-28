#ifndef _FILEDISK_H_
#define _FILEDISK_H_

#include <map>
#include <string>
#include "dllexport.h"
#include "Poco/Types.h"
#include "Poco/Mutex.h"
#include "Poco/Thread.h"


namespace Poco 
{

enum ENDIAN_TYPE
{
	DATA_LITTLE_ENDIAN= 0,
	DATA_BIG_ENDIAN 
};

class CIFileDisk
{
public:
	CIFileDisk();
	virtual ~CIFileDisk();

public:
	//static Int32 GetCurOsEndian();
	void InvertEndian(char *chData, UInt32 unLen);
	
	virtual Int32 CreatSpecFile(char *pFileName, UInt32 iSize, char* dir)=0;
	virtual Int32 OpenSpecFile(char *pFileName, char* dir)=0;
	virtual Int32 ReadSpecFile(void *pBuf, UInt32 uiSize)=0;
	virtual Int32 WriteSpecFile(void *pBuf,  UInt32 uiSize, Int32 iSyncFlag=0)=0;//0==��ֱ��д��Ӳ�̣�1==ֱ��д��Ӳ��
	virtual Int32 SeekSpecFile(long lOffset, Int32 iBeginPos);
	virtual Int32 CloseSpecFile();
	virtual Int32 CheckSpecFile(char *pFileName, char* dir);	
	
	static Int32 AddFiletoList(Int32 iFd, std::string &cFileName);
	static Int32 DelFiletoList(Int32 iFd);
	static void ShowFile();

protected:	
	static Int32 m_iCurOsEndian;	//��ǰ����ϵͳ��С��˳��  0=С�ˣ�1=���
	static std::map<Int32, std::string> m_OpenedFile;
	static FastMutex m_Listmutex;

protected:
	//void ClearInfo();
	Int32 lastError();
	char *ErrorString(int iError);
	
	Int32 m_iDiskStEndian;//Ӳ�̴洢���ݴ�С��˳��, Ĭ��Ϊ0 

protected:
	Int32 m_iFd;	
	//char m_FileName[128]; 
	std::string m_FileName;

	//Int32 m_iStorageType;
	//Int32 m_iDiskNum;
	//Int32 m_iPartitionNum;
	Int32 m_iFileIndex;
};

class CFileDisk : public CIFileDisk
{
public:	
	virtual Int32 CreatSpecFile(char *pFileName, UInt32 iSize, char* dir);
	virtual Int32 OpenSpecFile(char *pFileName, char* dir);//iDiskNum=1,2,3... iPartitionNum=1,2,3...
	virtual Int32 ReadSpecFile(void *pBuf, UInt32 uiSize);
	virtual Int32 WriteSpecFile(void *pBuf,  UInt32 uiSize, Int32 iSyncFlag=0);//0==��ֱ��д��Ӳ�̣�1==ֱ��д��Ӳ��

#if 0
	Int32 ReadOsEndianFile(T_DiskHead *pDiskHead);//��ȡ����ϵͳ��˳������ݽṹ
	Int32 WriteDiskEndianFile(const T_DiskHead *pDiskHead);//д��Ӳ�̶�˳������ݽṹ

	Int32 ReadOsEndianFile(T_DiskIndex *pDiskIndex,  UInt32 uiSize);
	Int32 WriteDiskEndianFile(const T_DiskIndex *pDiskIndex,  UInt32 uiSize);

	Int32 ReadOsEndianFile(T_RecIndex *pRecIndex, UInt32 uiSize);	
	Int32 WriteDiskEndianFile(const T_RecIndex *pRecIndex, UInt32 uiSize);
#endif
	
};


}

#endif

