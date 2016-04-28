#ifndef __SHARE_MODULE_API_H
#define __SHARE_MODULE_API_H

#include "dllexport.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

#include "TypeDef.h"

extern "C"
{
	/*����������¼
	  @szRemoteName  ����������������ip��("\\\\LM002-PC"  OR  "\\\\192.168.1.5")
	  @szUserName  ���������û���
	  @szPsw  ���������û���¼����
	*/
	DLLEXPORT_API bool share_Login(char *szRemoteName, char *szUserName, char *szPsw);
	/*�ѵ����ļ�������ָ��Ŀ¼
	  @szFileName Ҫ�ƶ����ļ���F:\tools\ultraedit.exe��
	  @szPathMoveTo Ҫ�ƶ�����Ŀ¼(E:\tools)

	  @return �����������������ֹͣ�������Լ���ȡ���ȡ�
	*/
	DLLEXPORT_API unsigned int share_MoveFile(char *szFileName, char *szPathMoveTo, pFuncMovePercentCallback callback, unsigned int iUserData);
	/*�Ѷ���ļ�������ָ��Ŀ¼(���ܿ���Ŀ¼)
	  @vecFileName Ҫ�ƶ����ļ�
	    vecFileName.push_back("F:\tools\ultraedit.exe");
		vecFileName.push_back("F:\tools\bcompare.exe")
		@szPathMoveTo Ҫ�ƶ�����Ŀ¼(E:\tools)

		@return �����������������ֹͣ�������Լ���ȡ���ȡ�
	*/
	DLLEXPORT_API unsigned int share_MoveFiles(vector<string> &vecFileName, char *szPathMoveTo, pFuncMovePercentCallback callback, unsigned int iUserData);
	/*��ĳ��Ŀ¼�µĶ���ļ����ļ��п�����ָ��Ŀ¼���ļ���Ҳ���Կ������������ļ�����Ҫ������������ļ����µ������ļ�·����@vecFileName��
	  @vecFileName Ҫ�ƶ����ļ�
	    vecFileName.push_back("E:\...\rootdir\VideoDown\ultraedit.exe");
		vecFileName.push_back("E:\...\rootdir\VideoDown\...\bcompare.exe")
		vecFileName.push_back("E:\...\rootdir\xxx.exe")
		@szPathMoveFrom ԴĿ¼������Ҫ�ƶ����ļ��ĵ�һ����ͬ�Ķ���Ŀ¼ �� E:\...\rootdir��
		@szPathMoveTo Ҫ�ƶ�����Ŀ¼(F:\...\somedir)

		@return �����������������ֹͣ�������Լ���ȡ���ȡ�
	*/
	DLLEXPORT_API unsigned int share_MoveFiles_2(vector<string> &vecFileName, char *szPathMoveFrom, char *szPathMoveTo, pFuncMovePercentCallback callback, unsigned int iUserData);
	/*��һ���ļ���(�������ļ��С��ļ�)������ָ��Ŀ¼
	  @szDir Ҫ�ƶ����ļ��У�F:\tools��
	  @szPathMoveTo Ҫ�ƶ�����Ŀ¼(E:)

	  @return �����������������ֹͣ�������Լ���ȡ���ȡ�
	*/
	DLLEXPORT_API unsigned int share_MoveDirAndSub(char *szDir, char *szPathMoveTo, pFuncMovePercentCallback callback, unsigned int iUserData);
	/* ֹͣ��ǰ����
	   @iHandle  ���������ÿ��������������ֵ(unsigned int)
	*/
	DLLEXPORT_API void share_Stop(unsigned int &iHandle);
	//�����ļ����ã�����ļ�ʱ��Ӧ��ǰ���ڿ������ļ�
	DLLEXPORT_API int  share_GetCurrentFilePercent(unsigned int iHandle);
	//����ļ�����
	DLLEXPORT_API int  share_GetTotalPercent(unsigned int iHandle);
};

#endif