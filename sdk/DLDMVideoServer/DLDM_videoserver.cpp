#include "DLDM_videoserver.h"
#include <iostream>

#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"
Log g_log("DLDM_videoserver");

// #pragma comment(lib, "HCNetSDK.lib")

IVideoServerFactory* VideoServerFactory()
{
    return new CFactoryDaLi_DM();
}

std::string GetLastErrorString()
{
    DWORD dwErr;
    dwErr = Api_DaLi_DM::Api().m_pGetLastError();

    switch (dwErr)
    {
        case NET_DLDVR_NOERROR: return "û�д���";
        case NET_DLDVR_PASSWORD_ERROR: return "�û����������";
        case NET_DLDVR_NOENOUGHPRI: return "Ȩ�޲���";
        case NET_DLDVR_NOINIT: return "û�г�ʼ��";
        case NET_DLDVR_CHANNEL_ERROR: return "ͨ���Ŵ���";
        case NET_DLDVR_OVER_MAXLINK: return "���ӵ�DVR�Ŀͻ��˸����������";
        case NET_DLDVR_VERSIONNOMATCH: return "�汾��ƥ��";
        case NET_DLDVR_NETWORK_FAIL_CONNECT: return "���ӷ�����ʧ��";
        case NET_DLDVR_NETWORK_SEND_ERROR: return "�����������ʧ��";
        case NET_DLDVR_NETWORK_RECV_ERROR: return "�ӷ�������������ʧ��";
        case NET_DLDVR_NETWORK_RECV_TIMEOUT: return "�ӷ������������ݳ�ʱ";
        case NET_DLDVR_NETWORK_ERRORDATA: return "���͵���������";
        case NET_DLDVR_ORDER_ERROR: return "���ô������";
        case NET_DLDVR_OPERNOPERMIT: return "�޴�Ȩ��";
        case NET_DLDVR_COMMANDTIMEOUT: return "DVR����ִ�г�ʱ";
        case NET_DLDVR_ERRORSERIALPORT: return "���ںŴ���";
        case NET_DLDVR_ERRORALARMPORT: return "�����˿ڴ���";
        case NET_DLDVR_PARAMETER_ERROR: return "��������";
        case NET_DLDVR_CHAN_EXCEPTION: return "������ͨ�����ڴ���״̬";
        case NET_DLDVR_NODISK: return "û��Ӳ��";
        case NET_DLDVR_ERRORDISKNUM: return "Ӳ�̺Ŵ���";
        case NET_DLDVR_DISK_FULL: return "������Ӳ����";
        case NET_DLDVR_DISK_ERROR: return "������Ӳ�̳���";
        case NET_DLDVR_NOSUPPORT: return "��������֧��";
        case NET_DLDVR_BUSY: return "������æ";
        case NET_DLDVR_MODIFY_FAIL: return "�������޸Ĳ��ɹ�";
        case NET_DLDVR_PASSWORD_FORMAT_ERROR: return "���������ʽ����ȷ";
        case NET_DLDVR_DISK_FORMATING: return "Ӳ�����ڸ�ʽ����������������";
        case NET_DLDVR_DVRNORESOURCE: return "DVR��Դ����";
        case NET_DLDVR_DVROPRATEFAILED: return "DVR����ʧ��";
        case NET_DLDVR_OPENHOSTSOUND_FAIL: return "��PC����ʧ��";
        case NET_DLDVR_DVRVOICEOPENED: return "�����������Խ���ռ��";
        case NET_DLDVR_TIMEINPUTERROR: return "ʱ�����벻��ȷ";
        case NET_DLDVR_NOSPECFILE: return "�ط�ʱ������û��ָ�����ļ�";
        case NET_DLDVR_CREATEFILE_ERROR: return "�����ļ�����";
        case NET_DLDVR_FILEOPENFAIL: return "���ļ�����";
        case NET_DLDVR_OPERNOTFINISH: return "�ϴεĲ�����û�����";
        case NET_DLDVR_GETPLAYTIMEFAIL: return "��ȡ��ǰ���ŵ�ʱ�����";
        case NET_DLDVR_PLAYFAIL: return "���ų���";
        case NET_DLDVR_FILEFORMAT_ERROR: return "�ļ���ʽ����ȷ";
        case NET_DLDVR_DIR_ERROR: return "·������";
        case NET_DLDVR_ALLOC_RESOUCE_ERROR: return "��Դ�������";
        case NET_DLDVR_AUDIO_MODE_ERROR: return "����ģʽ����";
        case NET_DLDVR_NOENOUGH_BUF: return "������̫С";
        case NET_DLDVR_CREATESOCKET_ERROR: return "����SOCKET����";
        case NET_DLDVR_SETSOCKET_ERROR: return "����SOCKET����";
        case NET_DLDVR_MAX_NUM: return "�����ﵽ���";
        case NET_DLDVR_USERNOTEXIST: return "�û�������";
        case NET_DLDVR_WRITEFLASHERROR: return "дFLASH����";
        case NET_DLDVR_UPGRADEFAIL: return "DVR����ʧ��";
        case NET_DLDVR_CARDHAVEINIT: return "���뿨�Ѿ���ʼ����";
        case NET_DLDVR_PLAYERFAILED: return "�������д���";
        case NET_DLDVR_MAX_USERNUM: return "�豸���û����ﵽ���";
        case NET_DLDVR_GETLOCALIPANDMACFAIL: return "��ÿͻ��˵�IP��ַ�������ַʧ��";
        case NET_DLDVR_NOENCODEING: return "��ͨ��û�б���";
        case NET_DLDVR_IPMISMATCH: return "IP��ַ��ƥ��";
        case NET_DLDVR_MACMISMATCH: return "MAC��ַ��ƥ��";
        case NET_DLDVR_UPGRADELANGMISMATCH: return "�����ļ����Բ�ƥ��";
		default: return "δ֪����";
    }
}



CFactoryDaLi_DM::CFactoryDaLi_DM()
{
    init();
}

CFactoryDaLi_DM::~CFactoryDaLi_DM()
{
    clean();
}






bool CFactoryDaLi_DM::init()
{
    if (!m_init)
    {

        m_init = Api_DaLi_DM::Api().m_pInit();
        //NET_DLDVR_SetConnectTime(1000, 30);
        //NET_DLDVR_SetReconnect(3000);
        //NET_DLDVR_SetDVRMessage()
        if (!m_init)
        {
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("��ʼ��SDKʧ�ܣ�����ԭ��") + m_sLastError);
        }

		g_log.AddLog(string("��ʼ��SDK�ɹ�"));
    }

    return m_init;
}


void CFactoryDaLi_DM::clean()
{
    Api_DaLi_DM::Api().m_pUninit();
}




IVideoServer* CFactoryDaLi_DM::create()
{
    if (!init())
    {
        return nullptr;
    }

    return new DaLi_DM_videoserver();
}


// std::vector<DaLi_DM_videoserver*> DaLi_DM_videoserver::sServers;
// std::recursive_mutex DaLi_DM_videoserver::sMtServers;

/*
 * ��������
 */
DaLi_DM_videoserver::DaLi_DM_videoserver()
{
	m_lLoginHandle = -1;
//     std::lock_guard<std::recursive_mutex> lock(DaLi_DM_videoserver::sMtServers);
//     sServers.push_back(this);
}

DaLi_DM_videoserver::~DaLi_DM_videoserver()
{
    logout();
//     std::lock_guard<std::recursive_mutex> lock(DaLi_DM_videoserver::sMtServers);
//     for (int i = 0; i < sServers.size(); i++)
//     {
//         if (sServers[i] == this)
//         {
//             sServers.erase(sServers.begin() + i);
//             break;
//         }
//     }
}

IVideoServer* DaLi_DM_videoserver::clone()
{
//     DaLi_DM_videoserver *svr = new DaLi_DM_videoserver();
// 	memcpy(svr, this, sizeof(DaLi_DM_videoserver));
//     return svr;
	return NULL;
}

DWORD WINAPI ThreadProcTimer(
	LPVOID lpParameter   // thread data
	)
{
	Sleep(2000);
	DaLi_DM_videoserver *pThis = (DaLi_DM_videoserver *)lpParameter;
	if (pThis == NULL)
	{
		return FALSE;
	}
	if (Api_DaLi_DM::Api().m_pHeartBeat)
	{
		Api_DaLi_DM::Api().m_pHeartBeat((char *)pThis->m_strIp.c_str(), pThis->m_iPort, pThis->m_lLoginHandle);
		g_log.AddLog(string("ThreadProcTimer"));
	}
	else
	{
		g_log.AddLog(string("ThreadProcTimer NULL"));
	}
}

bool DaLi_DM_videoserver::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string >& channels)
{
//     if (0 > m_lLoginHandle && !logout())
//     {
//         return false;
//     }
	channels.clear();
    memset(&m_deviceInfo, 0, sizeof(m_deviceInfo));

    m_lLoginHandle = Api_DaLi_DM::Api().m_pLogin((char*)IP, port,
                                   (char*)user,(char*)password,
                                   &m_deviceInfo);
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "��¼ID:%d ip:%s port:%d user:%s psw:%s", m_lLoginHandle, IP, port, user, password);
	g_log.AddLog(string(szLog));
    if (m_lLoginHandle == -1)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("login ��¼ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

//     NET_DLDVR_DEVICECFG channelInfo;
// 	ZeroMemory(&channelInfo, sizeof(channelInfo));
//     DWORD returnBytes = 0;
    for (int i = 0; i < m_deviceInfo.byChanNum; i++)
    {
//         if (Api_DaLi_DM::Api().m_pGetConfig(m_lLoginHandle, NET_DLDVR_GET_DEVICECFG,
//                              m_deviceInfo.byStartChan + i, &channelInfo,
//                              sizeof(NET_DLDVR_PICCFG_EX), &returnBytes) != FALSE)
//         {
//             channels[m_deviceInfo.byStartChan + i] = std::string ((char *)channelInfo.sChanName);
//         }
//         else
//         {
//             channels[m_deviceInfo.byStartChan + i];
//         }
		char szChName[32];
		ZeroMemory(szChName, 32);
		sprintf(szChName, "ͨ��%d", 1 + i);
		channels[1 + i] = std::string (szChName);
    }

	m_strIp = IP;
	m_iPort = port;
// 	CreateThread(NULL, 0, ThreadProcTimer, this, 0, NULL);

    return true;
}

bool DaLi_DM_videoserver::logout()
{
    if (m_lLoginHandle >= 0 && !Api_DaLi_DM::Api().m_pLogout(m_lLoginHandle))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }

    return true;
}




bool DaLi_DM_videoserver::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart,
                                                       __time64_t timeEnd)
{
    if (m_lLoginHandle < 0)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("GetRecordFileList ���ȵ�¼"));
        return false;
    }

    if (timeStart >= timeEnd)
    {
		m_sLastError = "ʱ�䷶Χ����!";
		g_log.AddLog(string("GetRecordFileList ʱ�䷶Χ����"));
        return false;
    }

	files.clear();
	//m_mapArcItem.clear();

	if (channelVec.size() == 0)
	{
		return false;
	}
	int nChannelId = 0;
	auto itr = channelVec.begin();
	for (; itr != channelVec.end(); itr++)
	{
		int nChannelIdTmp = *itr;

		int iTmp = 1 << (nChannelIdTmp - 1);
		nChannelId |= iTmp;
	}

	struct tm Tm;

	NET_DLDVR_TIME struStartTime;
	_localtime64_s(&Tm, (const time_t*)&timeStart);
	struStartTime.dwYear = Tm.tm_year + 1900;
	struStartTime.dwMonth = Tm.tm_mon + 1;
	struStartTime.dwDay = Tm.tm_mday;
	struStartTime.dwHour = Tm.tm_hour;
	struStartTime.dwMinute = Tm.tm_min;
	struStartTime.dwSecond = Tm.tm_sec;

	NET_DLDVR_TIME struStopTime;
	_localtime64_s(&Tm, (const time_t*)&timeEnd);
	struStopTime.dwYear = Tm.tm_year + 1900;
	struStopTime.dwMonth = Tm.tm_mon + 1;
	struStopTime.dwDay = Tm.tm_mday;
	struStopTime.dwHour = Tm.tm_hour;
	struStopTime.dwMinute = Tm.tm_min;
	struStopTime.dwSecond = Tm.tm_sec;

	NET_DLDVR_TIME stime = struStartTime;
	NET_DLDVR_TIME etime = struStopTime;
// 	char szTime[512];
// 	ZeroMemory(szTime, 512);
// 	sprintf(szTime, " s_time:%d-%02d-%02d %02d:%02d:%02d e_time:%d-%02d-%02d %02d:%02d:%02d channel:%d linkID:%d", stime.dwYear, stime.dwMonth, stime.dwDay,
// 		stime.dwHour, stime.dwMinute, stime.dwSecond,
// 		etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond, nChannelId, m_lLoginHandle);
// 	g_log.AddLog(string("GetRecordFileList ") + string(szTime));

	LONG lfind = Api_DaLi_DM::Api().m_pFindFile(m_lLoginHandle, nChannelId, 0xff, &struStartTime, &struStopTime);
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "GetRecordFileList ��¼���:%d ͨ��:%d �ļ�����:%d ���Ҿ��:%d", m_lLoginHandle, nChannelId, 0xff, lfind);
	g_log.AddLog(string(szLog));
	if (lfind == -1)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("GetRecordFileList ��ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}
	NET_DLDVR_FIND_DATA findInfo;
	ZeroMemory(&findInfo, sizeof(findInfo));
	int iFinds = 0;

	LONG re = Api_DaLi_DM::Api().m_pFindNext(lfind, &findInfo);
	RecordFile rf;
	while (re == NET_DLDVR_ERROR_ISFINDING || re == NET_DLDVR_ERROR_FINDFILE_SUCCESS)
	{
		if (re == NET_DLDVR_ERROR_FINDFILE_SUCCESS && findInfo.dwFileSize > 0)//�����Ƶ�ļ��������0(�������з����ļ���СΪ0���,���Ա�����˵��Ĳ���)
		{
			struct tm Tm;
			Tm.tm_year = findInfo.struStartTime.dwYear - 1900;
			Tm.tm_mon = findInfo.struStartTime.dwMonth - 1;
			Tm.tm_mday = findInfo.struStartTime.dwDay;
			Tm.tm_hour = findInfo.struStartTime.dwHour;
			Tm.tm_min = findInfo.struStartTime.dwMinute;
			Tm.tm_sec = findInfo.struStartTime.dwSecond;
			rf.beginTime = _mktime64(&Tm);

			Tm.tm_year = findInfo.struStopTime.dwYear - 1900;
			Tm.tm_mon = findInfo.struStopTime.dwMonth - 1;
			Tm.tm_mday = findInfo.struStopTime.dwDay;
			Tm.tm_hour = findInfo.struStopTime.dwHour;
			Tm.tm_min = findInfo.struStopTime.dwMinute;
			Tm.tm_sec = findInfo.struStopTime.dwSecond;
			rf.endTime = _mktime64(&Tm);

			stime = findInfo.struStartTime;
			etime = findInfo.struStopTime;
// 			ZeroMemory(szTime, 512);
// 			sprintf(szTime, "channel%d %d-%02d-%02d %02d-%02d-%02d %d-%02d-%02d %02d-%02d-%02d", nChannelId,
// 				stime.dwYear, stime.dwMonth, stime.dwDay,
// 				stime.dwHour, stime.dwMinute, stime.dwSecond,
// 				etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond);
// 			{
// 				Mutex::ScopedLock lock(m_mtx);
// 				m_mapArcItem.insert(std::make_pair(string(szTime), findInfo));
// 			}

			rf.channel = findInfo.dwChannel;
			rf.name = string(findInfo.sFileName);
			rf.size = findInfo.dwFileSize;
			rf.setPrivateData(&findInfo, sizeof(NET_DLDVR_FIND_DATA));
			files.push_back(rf);
			iFinds++;

// 			char szLog[1024];
// 			ZeroMemory(szLog, 1024);
// 			sprintf(szLog, "GetRecordFileList �ļ���:%s �ļ���С:%d �ļ�ʱ��:%s ͨ��:%d", findInfo.sFileName, findInfo.dwFileSize, szTime, findInfo.dwChannel);
// 			g_log.AddLog(string(szLog));
		}
		else
		{
			::Sleep(20);
		}
		ZeroMemory(&findInfo, sizeof(findInfo));
		re = Api_DaLi_DM::Api().m_pFindNext(lfind, &findInfo);
	}

	if (FALSE == Api_DaLi_DM::Api().m_pFindClose(lfind))
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("GetRecordFileList �رղ�ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return true;
	}

    return true;
}



bool DaLi_DM_videoserver::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
    if (0 > m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("downLoadByRecordFile ���ȵ�¼"));
        return false;
    }

// 	NET_DLDVR_FIND_DATA info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, NET_DLDVR_FIND_DATA>::iterator itr = m_mapArcItem.find(file.name);
// 		if (itr == m_mapArcItem.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			g_log.AddLog(string("downLoadByRecordFile ���ļ�������"));
// 			return false;
// 		}
// 
// 		info = itr->second;
// 	}
	
	//g_log.AddLog(string("downLoadByRecordFile �ļ���:") + string(info.sFileName) + string(" �����ļ���:") + saveFileName);pData->sFileName
	//hdl = Api_DaLi_DM::Api().m_pDownloadByFile(m_lLoginHandle, (char*)info.sFileName, (char*)saveFileName);
	NET_DLDVR_FIND_DATA* pData = (NET_DLDVR_FIND_DATA *)file.getPrivateData();
	hdl = Api_DaLi_DM::Api().m_pDownloadByFile(m_lLoginHandle, pData->sFileName, (char*)saveFileName);
    if (hdl < 0)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("downLoadByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

//     if (!Api_DaLi_DM::Api().m_pPlayBackControl(hdl, NET_DLDVR_PLAYSTART, 0, NULL))
//     {
// 		Api_DaLi_DM::Api().m_pStopDownload(hdl);
//         m_sLastError = GetLastErrorString();
//         return false;
//     }

	{
		Mutex::ScopedLock lock(m_mtxDownload);
		m_mapDownload.insert(std::make_pair(hdl, file));
	}

    return true;
}


bool  DaLi_DM_videoserver::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (0 > m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("PlayBackByRecordFile ���ȵ�¼"));
        return false;
	}
	
// 	NET_DLDVR_FIND_DATA info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, NET_DLDVR_FIND_DATA>::iterator itr = m_mapArcItem.find(file.name);
// 		if (itr == m_mapArcItem.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			g_log.AddLog(string("PlayBackByRecordFile ���ļ�������"));
// 			return false;
// 		}
// 
// 		info = itr->second;
// 	}

    struct tm Tm;
	NET_DLDVR_TIME struBeginTime;
	_localtime64_s(&Tm, (const time_t*)&file.beginTime);
    struBeginTime.dwYear = Tm.tm_year + 1900;
    struBeginTime.dwMonth = Tm.tm_mon + 1;
    struBeginTime.dwDay = Tm.tm_mday;
    struBeginTime.dwHour = Tm.tm_hour;
    struBeginTime.dwMinute = Tm.tm_min;
    struBeginTime.dwSecond = Tm.tm_sec;

	NET_DLDVR_TIME struEndTime;
	_localtime64_s(&Tm, (const time_t*)&file.endTime);
    struEndTime.dwYear = Tm.tm_year + 1900;
    struEndTime.dwMonth = Tm.tm_mon + 1;
    struEndTime.dwDay = Tm.tm_mday;
    struEndTime.dwHour = Tm.tm_hour;
    struEndTime.dwMinute = Tm.tm_min;
    struEndTime.dwSecond = Tm.tm_sec;

	NET_DLDVR_TIME stime = struBeginTime;
	NET_DLDVR_TIME etime = struEndTime;
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "��¼ID:%d ͨ��:%d ʱ��:%d-%02d-%02d %02d:%02d:%02d %d-%02d-%02d %02d:%02d:%02d", m_lLoginHandle, file.channel,
		stime.dwYear, stime.dwMonth, stime.dwDay, stime.dwHour, stime.dwMinute, stime.dwSecond,
		etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond);
	g_log.AddLog(string(szLog));
	//playbackHandle = Api_DaLi_DM::Api().m_pPlayBackByTime(m_lLoginHandle, file.channel, &struBeginTime, &struEndTime, hwnd);
	
	//playbackHandle = Api_DaLi_DM::Api().m_pPlayBackByName(m_lLoginHandle, info.sFileName, hwnd);
	NET_DLDVR_FIND_DATA* pData = (NET_DLDVR_FIND_DATA *)file.getPrivateData();
	playbackHandle = Api_DaLi_DM::Api().m_pPlayBackByName(m_lLoginHandle, pData->sFileName, hwnd);
    if (playbackHandle < 0)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("PlayBackByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

    if (!Api_DaLi_DM::Api().m_pPlayBackControl(playbackHandle, NET_DLDVR_PLAYSTART, 0, NULL))
    {
		Api_DaLi_DM::Api().m_pStopPlayBack(playbackHandle);
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("PlayBackByRecordFile ��ʼ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

    return true;
}

bool DaLi_DM_videoserver::SetPlayBack(download_handle_t playbackHandle, __int32 pos)
{
	g_log.AddLog(string("SetPlayBack"));
	if (FALSE == Api_DaLi_DM::Api().m_pPlayBackControl(playbackHandle, NET_DLDVR_PLAYSETPOS, pos, NULL))
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("SetPlayBack �϶�����ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
    }
	return true;
}

bool DaLi_DM_videoserver::StopPlayBack(download_handle_t playbackHandle, __int32 mPause)
{
    if (0 > m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("StopPlayBack ���ȵ�¼"));
        return false;
    }

	if (mPause == 1)
	{
		g_log.AddLog(string("StopPlayBack ��ʼ��ͣ����"));
		if (!Api_DaLi_DM::Api().m_pPlayBackControl(playbackHandle, NET_DLDVR_PLAYPAUSE, 0, NULL))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("StopPlayBack ��ͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
		}
	}
	else
	{
		char szLog[1024];
		ZeroMemory(szLog, 1024);
		sprintf(szLog, "StopPlayBack ��ʼֹͣ���� playbackHandle:%d", playbackHandle);
		g_log.AddLog(string(szLog));
		if (!Api_DaLi_DM::Api().m_pStopPlayBack(playbackHandle))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("StopPlayBack ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
		}
	}

    return true;
}

bool DaLi_DM_videoserver::stopDownload(download_handle_t h)
{
	if (0 > m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("stopDownload ���ȵ�¼"));
		return false;
	}
	g_log.AddLog(string("stopDownload ��ʼֹͣ����"));

	{
		Mutex::ScopedLock lock(m_mtxDownload);
		m_mapDownload.erase(h);
	}
    if (FALSE == Api_DaLi_DM::Api().m_pStopDownload(h))
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("stopDownload ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

    return true;
}

bool DaLi_DM_videoserver::getPlayBackPos(__int64 playbackHandle, __int32* pos)
{
	g_log.AddLog(string("getPlayBackPos"));
// 	return false;
	if (0 > m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("getPlayBackPos ���ȵ�¼"));
		return false;
	}
	if (!Api_DaLi_DM::Api().m_pPlayBackControl(playbackHandle, NET_DLDVR_PLAYGETPOS, 0, (DWORD *)pos))
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("getPlayBackPos ��ȡ���Ž���ʧ��"));
		return false;
	}
	return true;
}

bool DaLi_DM_videoserver::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
{
	if (0 > m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("getDownloadPos ���ȵ�¼"));
		return false;
	}

	RecordFile file;
	{
		Mutex::ScopedLock lock(m_mtxDownload);
		map<long, RecordFile>::iterator itr = m_mapDownload.find(h);
		if (itr == m_mapDownload.end())
		{
			m_sLastError = "�Ҳ������ļ�";
			g_log.AddLog(string("getDownloadPos �Ҳ������ļ�"));
			*failed = true;
			return false;
		}
		file = itr->second;
	}
	*totalSize = file.size;

	int iPos = Api_DaLi_DM::Api().m_pGetDownloadPos(h);
	if (FALSE == iPos)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("getDownloadPos ��ȡ���ؽ���ʧ��"));
		*failed = true;
		return false;
	}
	*currentSize = ((float)iPos / (float)100) * (*totalSize);
	*failed = false;
	return true;
}
