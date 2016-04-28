#ifndef _LOG_H_
#define _LOG_H_

#include "FileDisk.h" 
#include "Poco/Types.h"
#include "LogHeader.h"


#define  LOGCONTINUM				(5000)	//һ�β��ֶ�������Ŀ

namespace Poco 
{

class CLog
{
public:
	CLog();
	virtual ~CLog();

public:	
	Int32 Init(const char * pLogName);
	Int32 WriteData(LogInfo* ptLog);
	void  CloseLogFiles();
    
    bool IsRecycle();
	
private:
    CLog(const CLog&);
	Int32 CheckOpenLogFiles(char *pFileName);
	Int32 ReadFirLogIndex(T_FirIndex *pFirIndex,Int32 iPos,UInt32 iNum=1);
	Int32 ReadSecLogIndex(T_SecIndex *pSecIndex, Int32 iPos, UInt32 iNum=1);
	
	Int32 WriteFirIndex(UInt32 iPos,T_FirIndex *pFirIndex, UInt32 iNum=1);
	Int32 WriteLogContent(LogInfo* ptLog, T_SecIndex &tSecIndex);
	void  ParaInit();
	
private:
	
	//��¼��־��������־�ļ��ĵ�ǰ��Ϣ
	UInt32 m_uiCurFirPos;		//��һ������ǰλ�ã���¼��������д��λ��
	UInt32 m_uiFirNum;			//�� һ �� �� �� Ŀ
	UInt32 m_uiCurSecNum;		//�� ǰ �� Ŀ
	UInt32 m_uiLogMaxNum;		//�� �� �� �� �� �� �� �� Ŀ

	Int32 m_LogStartPos; 		// �� ¼ �� ־ �� �� �� ʼ λ ��
	Int32 m_SecStartPos; 		// �� ¼ �� �� �� �� �� ʼ λ ��

	UInt32 m_iCycle;			//�� �� �� ǰ �� �� ѭ ��

	T_FirIndex m_tFirIndex;		//�� ¼ 1 �� �� ��
	T_FirIndex m_tFirNext;		//�� ¼ 1 �� �� ��	
	T_SecIndex m_tSecIndex;
		
	char m_iLogFileName[30];		//��־��¼�ļ���
	
	Int32 m_iLogContiNum;				//���ֶ���������Ŀ
	
	CFileDisk* m_pLog;				//��־�ļ�FileDisk

	FastMutex m_mutex_write;

protected:
	UInt32 m_LogFileSz;		//�� log �� �� �� С
};


}

#endif

