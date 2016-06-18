#include "HanBang_videoserver.h"
#include <iostream>

#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"
Log g_log("HanBang_videoserver");

// #pragma comment(lib, "HCNetSDK.lib")

IVideoServerFactory* VideoServerFactory()
{
    return new CFactoryHanBang();
}

std::string GetLastErrorString()
{
    DWORD dwErr;
    dwErr = Api_HanBang::Api().m_pGetLastError();

    switch (dwErr)
    {
        case HB_SDVR_NOERROR: return "û�д���";
        case HB_SDVR_PASSWORD_ERROR: return "�û����������";
        case HB_SDVR_NOENOUGHPRI: return "Ȩ�޲���";
        case HB_SDVR_NOINIT: return "û�г�ʼ��";
        case HB_SDVR_CHANNEL_ERROR: return "ͨ���Ŵ���";
        case HB_SDVR_OVER_MAXLINK: return "���ӵ�DVR�Ŀͻ��˸����������";
        case HB_SDVR_VERSIONNOMATCH: return "�汾��ƥ��";
        case HB_SDVR_NETWORK_FAIL_CONNECT: return "���ӷ�����ʧ��";
        case HB_SDVR_NETWORK_SEND_ERROR: return "�����������ʧ��";
        case HB_SDVR_NETWORK_RECV_ERROR: return "�ӷ�������������ʧ��";
        case HB_SDVR_NETWORK_RECV_TIMEOUT: return "�ӷ������������ݳ�ʱ";
        case HB_SDVR_NETWORK_ERRORDATA: return "���͵���������";
        case HB_SDVR_ORDER_ERROR: return "���ô������";
        case HB_SDVR_OPERNOPERMIT: return "�޴�Ȩ��";
        case HB_SDVR_COMMANDTIMEOUT: return "DVR����ִ�г�ʱ";
        case HB_SDVR_ERRORSERIALPORT: return "���ںŴ���";
        case HB_SDVR_ERRORALARMPORT: return "�����˿ڴ���";
        case HB_SDVR_PARAMETER_ERROR: return "��������";
        case HB_SDVR_CHAN_EXCEPTION: return "������ͨ�����ڴ���״̬";
        case HB_SDVR_NODISK: return "û��Ӳ��";
        case HB_SDVR_ERRORDISKNUM: return "Ӳ�̺Ŵ���";
        case HB_SDVR_DISK_FULL: return "������Ӳ����";
        case HB_SDVR_DISK_ERROR: return "������Ӳ�̳���";
        case HB_SDVR_NOSUPPORT: return "��������֧��";
        case HB_SDVR_BUSY: return "������æ";
        case HB_SDVR_MODIFY_FAIL: return "�������޸Ĳ��ɹ�";
        case HB_SDVR_PASSWORD_FORMAT_ERROR: return "���������ʽ����ȷ";
        case HB_SDVR_DISK_FORMATING: return "Ӳ�����ڸ�ʽ����������������";
        case HB_SDVR_DVRNORESOURCE: return "DVR��Դ����";
        case HB_SDVR_DVROPRATEFAILED: return "DVR����ʧ��";
        case HB_SDVR_OPENHOSTSOUND_FAIL: return "��PC����ʧ��";
        case HB_SDVR_DVRVOICEOPENED: return "�����������Խ���ռ��";
        case HB_SDVR_TIMEINPUTERROR: return "ʱ�����벻��ȷ";
        case HB_SDVR_NOSPECFILE: return "�ط�ʱ������û��ָ�����ļ�";
        case HB_SDVR_CREATEFILE_ERROR: return "�����ļ�����";
        case HB_SDVR_FILEOPENFAIL: return "���ļ�����";
        case HB_SDVR_OPERNOTFINISH: return "�ϴεĲ�����û�����";
        case HB_SDVR_GETPLAYTIMEFAIL: return "��ȡ��ǰ���ŵ�ʱ�����";
        case HB_SDVR_PLAYFAIL: return "���ų���";
        case HB_SDVR_FILEFORMAT_ERROR: return "�ļ���ʽ����ȷ";
        case HB_SDVR_DIR_ERROR: return "·������";
        case HB_SDVR_ALLOC_RESOUCE_ERROR: return "��Դ�������";
        case HB_SDVR_AUDIO_MODE_ERROR: return "����ģʽ����";
        case HB_SDVR_NOENOUGH_BUF: return "������̫С";
        case HB_SDVR_CREATESOCKET_ERROR: return "����SOCKET����";
        case HB_SDVR_SETSOCKET_ERROR: return "����SOCKET����";
        case HB_SDVR_MAX_NUM: return "�����ﵽ���";
        case HB_SDVR_USERNOTEXIST: return "�û�������";
        case HB_SDVR_WRITEFLASHERROR: return "дFLASH����";
        case HB_SDVR_UPGRADEFAIL: return "DVR����ʧ��";
        case HB_SDVR_CARDHAVEINIT: return "���뿨�Ѿ���ʼ����";
        case HB_SDVR_PLAYERFAILED: return "�������д���";
        case HB_SDVR_MAX_USERNUM: return "�豸���û����ﵽ���";
        case HB_SDVR_GETLOCALIPANDMACFAIL: return "��ÿͻ��˵�IP��ַ�������ַʧ��";
        case HB_SDVR_NOENCODEING: return "��ͨ��û�б���";
        case HB_SDVR_IPMISMATCH: return "IP��ַ��ƥ��";
        case HB_SDVR_MACMISMATCH: return "MAC��ַ��ƥ��";
        case HB_SDVR_UPGRADELANGMISMATCH: return "�����ļ����Բ�ƥ��";
        case HB_SDVR_USERISALIVE: return "�û��ѵ�½";
        case HB_SDVR_UNKNOWNERROR: return "δ֪����";
        case HB_SDVR_KEYVERIFYFAIL: return "��Կ��֤ʧ��";
        case HB_SDVR_IPERR: return "IP��ַ��ƥ��";
        case HB_SDVR_MACERR: return "MAC��ַ��ƥ��";
        case HB_SDVR_PSWERR: return "�û����������";
        case HB_SDVR_USERERR: return "�û����������";
        case HB_SDVR_USERISFULL: return "��¼�û�������������";
        case NO_PERMISSION: return "�û�û��Ȩ��";
		default: return "δ֪����";
    }
}



CFactoryHanBang::CFactoryHanBang()
{
    init();
}

CFactoryHanBang::~CFactoryHanBang()
{
    clean();
}






bool CFactoryHanBang::init()
{
    if (!m_init)
    {

        m_init = Api_HanBang::Api().m_pInit();
        //HB_SDVR_SetConnectTime(1000, 30);
        //HB_SDVR_SetReconnect(3000);
        //HB_SDVR_SetDVRMessage()
        if (!m_init)
        {
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("��ʼ��SDKʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
        }

		g_log.AddLog(string("��ʼ��SDK�ɹ�"));
    }

    return m_init;
}


void CFactoryHanBang::clean()
{
    Api_HanBang::Api().m_pUninit();
}




IVideoServer* CFactoryHanBang::create()
{
    if (!init())
    {
        return nullptr;
    }

    return new HanBang_videoserver();
}


// std::vector<HanBang_videoserver*> HanBang_videoserver::sServers;
// std::recursive_mutex HanBang_videoserver::sMtServers;

/*
 * ��������
 */
HanBang_videoserver::HanBang_videoserver()
{
    m_lLoginHandle = 0;
//     std::lock_guard<std::recursive_mutex> lock(HanBang_videoserver::sMtServers);
//     sServers.push_back(this);
}

HanBang_videoserver::~HanBang_videoserver()
{
    logout();
//     std::lock_guard<std::recursive_mutex> lock(HanBang_videoserver::sMtServers);
//     for (int i = 0; i < sServers.size(); i++)
//     {
//         if (sServers[i] == this)
//         {
//             sServers.erase(sServers.begin() + i);
//             break;
//         }
//     }
}

IVideoServer* HanBang_videoserver::clone()
{
//     HanBang_videoserver *svr = new HanBang_videoserver();
// 	memcpy(svr, this, sizeof(HanBang_videoserver));
//     return svr;
	return NULL;
}

bool HanBang_videoserver::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string >& channels)
{
    if (m_lLoginHandle > 0 && !logout())
    {
        g_log.AddLog("login out failed");
        return false;
    }
    else{

    }
	channels.clear();
    memset(&m_deviceInfo, 0, sizeof(m_deviceInfo));

    m_lLoginHandle = Api_HanBang::Api().m_pLogin((char*)IP, port,
                                   (char*)user,(char*)password,
                                   &m_deviceInfo);
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "��¼ID:%d ip:%s port:%d user:%s psw:%s", m_lLoginHandle, IP, port, user, password);
	g_log.AddLog(string(szLog));

    if (m_lLoginHandle <= 0)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("login ��¼ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

    for (int i = 0; i < m_deviceInfo.byChanNum; i++)
    {
        channels[/*m_deviceInfo.byStartChan*/1 + i] = std::string ((char *)m_deviceInfo.sChanName[i]);
    }

	ZeroMemory(szLog, 1024);
	sprintf(szLog, "login ͨ������:%d", m_deviceInfo.byChanNum);
	g_log.AddLog(string(szLog));
    return true;
}

bool HanBang_videoserver::logout()
{
    g_log.AddLog("videoserver::logout");
    if (m_lLoginHandle > 0 && !Api_HanBang::Api().m_pLogout(m_lLoginHandle))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }
    m_lLoginHandle = 0;
    return true;
}

void changeToHBTime(__time64_t from, HanBang::HB_SDVR_TIME& to){
    struct tm Tm;
    _localtime64_s(&Tm, (const time_t*)&from);
    to.dwYear = Tm.tm_year + 1900;
    to.dwMonth = Tm.tm_mon + 1;
    to.dwDay = Tm.tm_mday;
    to.dwHour = Tm.tm_hour;
    to.dwMinute = Tm.tm_min;
    to.dwSecond = Tm.tm_sec;
}


bool HanBang_videoserver::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart,
                                                       __time64_t timeEnd)
{
	g_log.AddLog(string("GetRecordFileList"));
    if (m_lLoginHandle <= 0)
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

	auto itr = channelVec.begin();
	for (; itr != channelVec.end(); itr++)
	{
		int nChannelId = *itr;

		HanBang::HB_SDVR_FILEGETCOND f;
		memset(&f, 0, sizeof(HanBang::HB_SDVR_FILEGETCOND));

		HanBang::HB_SDVR_TIME struStartTime;
        changeToHBTime(timeStart, struStartTime);

		HanBang::HB_SDVR_TIME struStopTime;
        changeToHBTime(timeEnd, struStopTime);

		LONG lfind = Api_HanBang::Api().m_pFindFile(m_lLoginHandle, nChannelId, MFS_REC_TYPE_ALL, &struStartTime, &struStopTime);

		if (lfind == FALSE)
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("GetRecordFileList ��ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
			continue;
		}
		HanBang::HB_SDVR_FIND_DATA findInfo;
		ZeroMemory(&findInfo, sizeof(findInfo));
		int iFinds = 0;

		LONG re = Api_HanBang::Api().m_pFindNext(lfind, &findInfo);
		RecordFile rf;
		while (re == HB_SDVR_ISFINDING || re == HB_SDVR_FILE_SUCCESS)
		{
			if (re == HB_SDVR_FILE_SUCCESS && findInfo.dwFileSize > 0)//�����Ƶ�ļ��������0(�������з����ļ���СΪ0���,���Ա�����˵��Ĳ���)
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

				rf.channel = nChannelId;
				rf.name = findInfo.sFileName;
				rf.size = findInfo.dwFileSize;
				rf.setPrivateData(&findInfo, sizeof(HanBang::HB_SDVR_FIND_DATA));

				files.push_back(rf);
				iFinds++;
			}
			else
			{
				::Sleep(20);
			}

			ZeroMemory(&findInfo, sizeof(findInfo));
			re = Api_HanBang::Api().m_pFindNext(lfind, &findInfo);
		}


		if (-1 == re)
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("GetRecordFileList 01 ��ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
			continue;
		}

		if (FALSE == Api_HanBang::Api().m_pFindClose(lfind))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("GetRecordFileList �رղ�ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
			continue;
		}
	}

    return true;
}



bool HanBang_videoserver::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
    if (m_lLoginHandle <= 0)
    {
        m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("downLoadByRecordFile ���ȵ�¼"));
        return false;
    }
    
    if (m_mapDownInfo.size() > 0)
    {
        g_log.AddLog(string("m_mapDownInfo.size()"));
        return false;
    }

    HanBang::HB_SDVR_TIME struStartTime;
    changeToHBTime(file.beginTime, struStartTime);

    HanBang::HB_SDVR_TIME struStopTime;
    changeToHBTime(file.endTime, struStopTime);

    g_log.AddLog(QString("m_lLoginHandle:%1, file.channel:%2, struStartTime:%3,%4,%5,%6,%7,%8")
        .arg(m_lLoginHandle).arg(file.channel).arg(struStartTime.dwYear).arg(struStartTime.dwMonth).arg(struStartTime.dwDay)
        .arg(struStartTime.dwHour).arg(struStartTime.dwMinute).arg(struStartTime.dwSecond));
	hdl = Api_HanBang::Api().m_pDownloadByFile(m_lLoginHandle, (char *)file.name.c_str(), (char *)saveFileName);
	//<<<<<<<<<add by zhangyaofa 2016/6/8
	if (!hdl)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("NET_DVR_GetFileBy failed : ") + m_sLastError + " �ļ���" + saveFileName);
		hdl = Api_HanBang::Api().m_pDownloadByTime(m_lLoginHandle, file.channel, &struStartTime, &struStopTime, (char *)saveFileName);		
	}
	//>>>>>>>>>>add ebd
    if (!hdl)
    {
        m_sLastError = GetLastErrorString();
        g_log.AddLog(string("m_pDownloadByFile ����ԭ��") + m_sLastError);
    }
    else
    {
        m_mapDownInfo[hdl] = file;
    }
    return hdl;
}


bool  HanBang_videoserver::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("PlayBackByRecordFile ���ȵ�¼"));
        return false;
    }

//     HB_SDVR_VOD_PARA struVodPara={0};
//     memset(&struVodPara, 0, sizeof(HB_SDVR_VOD_PARA));
//     dwSize=sizeof(struVodPara);
//     struIDInfo.dwChannel = file.channel; //ͨ����
//     hWnd = hwnd;
// 	HanBang::HB_SDVR_FIND_DATA info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, HanBang::HB_SDVR_FIND_DATA>::iterator itr = m_mapArcItem.find(file.name);
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
	HanBang::HB_SDVR_TIME struBeginTime;
	_localtime64_s(&Tm, (const time_t*)&file.beginTime);
    struBeginTime.dwYear = Tm.tm_year + 1900;
    struBeginTime.dwMonth = Tm.tm_mon + 1;
    struBeginTime.dwDay = Tm.tm_mday;
    struBeginTime.dwHour = Tm.tm_hour;
    struBeginTime.dwMinute = Tm.tm_min;
    struBeginTime.dwSecond = Tm.tm_sec;
// 	char szTime[512];
// 	ZeroMemory(szTime, 512);
// 	sprintf(szTime, "%d-%02d-%02d %02d-%02d-%02d", 
// 		Tm.tm_year, Tm.tm_mon, Tm.tm_mday, Tm.tm_hour, Tm.tm_min, Tm.tm_sec);
// 	g_log.AddLog(string(szTime));

	HanBang::HB_SDVR_TIME struEndTime;
	_localtime64_s(&Tm, (const time_t*)&file.endTime);
    struEndTime.dwYear = Tm.tm_year + 1900;
    struEndTime.dwMonth = Tm.tm_mon + 1;
    struEndTime.dwDay = Tm.tm_mday;
    struEndTime.dwHour = Tm.tm_hour;
    struEndTime.dwMinute = Tm.tm_min;
    struEndTime.dwSecond = Tm.tm_sec;

// 	ZeroMemory(szTime, 512);
// 	sprintf(szTime, "%d-%02d-%02d %02d-%02d-%02d", 
// 		Tm.tm_year, Tm.tm_mon, Tm.tm_mday, Tm.tm_hour, Tm.tm_min, Tm.tm_sec);
// 	g_log.AddLog(string(szTime));

	HanBang::HB_SDVR_TIME stime = struBeginTime;
	HanBang::HB_SDVR_TIME etime = struEndTime;

// 	ZeroMemory(szTime, 512);
// 	sprintf(szTime, "%d-%02d-%02d %02d-%02d-%02d %d-%02d-%02d %02d-%02d-%02d", stime.dwYear, stime.dwMonth, stime.dwDay,
// 		stime.dwHour, stime.dwMinute, stime.dwSecond,
// 		etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond);
// 	g_log.AddLog(string(szTime));
// 	char szTmp[64];
// 	ZeroMemory(szTmp, 64);
// 	sprintf(szTmp, "~%02d", info.nCh);
// 	string strFileName = info.sFileName;
// 	strFileName.insert(19, szTmp);
// 	g_log.AddLog(string("PlayBackByRecordFile �ļ���:") + strFileName);
// 	char szLog[1024];
// 	ZeroMemory(szLog, 1024);
// 	sprintf(szLog, "��¼ID:%d ͨ��:%d ʱ��:%d-%02d-%02d %02d:%02d:%02d %d-%02d-%02d %02d:%02d:%02d", m_lLoginHandle, info.nCh,
// 		stime.dwYear, stime.dwMonth, stime.dwDay, stime.dwHour, stime.dwMinute, stime.dwSecond,
// 		etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond);
// 	g_log.AddLog(string(szLog));

	//playbackHandle = Api_HanBang::Api().m_pPlayBackByName(m_lLoginHandle, (char *)strFileName.c_str(), hwnd);
	//Api_HanBang::Api().m_pPlayBackByTime(m_lLoginHandle, file.channel, &struBeginTime, &struEndTime, hwnd);
	//playbackHandle = Api_HanBang::Api().m_pPlayBackByTime(m_lLoginHandle, info.nCh, &struBeginTime, &struEndTime, hwnd);
	playbackHandle = Api_HanBang::Api().m_pPlayBackByTime(m_lLoginHandle, file.channel, &struBeginTime, &struEndTime, hwnd);
	if (playbackHandle == FALSE)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("PlayBackByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

//     if (!Api_HanBang::Api().m_pPlayBackControl(playbackHandle, HB_SDVR_PLAYSTART, 0, NULL))
//     {
// 		m_sLastError = GetLastErrorString();
// 		g_log.AddLog(string("PlayBackByRecordFile 01 ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
//         return false;
//     }

    return true;
}

bool HanBang_videoserver::SetPlayBack(download_handle_t playbackHandle, __int32 pos)
{
	g_log.AddLog(string("SetPlayBack"));
    return FALSE != Api_HanBang::Api().m_pPlayBackControl(playbackHandle, HB_SDVR_PLAYBYSLIDER, pos, NULL);
}

bool HanBang_videoserver::StopPlayBack(download_handle_t playbackHandle, __int32 mPause)
{
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("StopPlayBack ���ȵ�¼"));
        return false;
    }

	if (mPause == 1)
	{
		g_log.AddLog(string("StopPlayBack ��ʼ��ͣ����"));
		if (!Api_HanBang::Api().m_pPlayBackControl(playbackHandle, HB_SDVR_PLAYPAUSE, 0, NULL))
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
		if (!Api_HanBang::Api().m_pStopPlayBack(playbackHandle))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("StopPlayBack ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
		}
	}

    return true;
}

bool HanBang_videoserver::stopDownload(download_handle_t h)
{
    m_mapDownInfo.clear();
    return true;
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("stopDownload ���ȵ�¼"));
		return false;
	}
	g_log.AddLog(string("stopDownload ��ʼֹͣ����"));

	{
		Mutex::ScopedLock lock(m_mtxdown);
		auto itr = m_mapDownInfo.find(h);
		if (itr == m_mapDownInfo.end())
		{
			m_sLastError = "���ļ�������";
			g_log.AddLog(string("getDownloadPos ���ļ�������"));
			return false;
		}
		m_mapDownInfo.erase(itr);
	}
    if (FALSE == Api_HanBang::Api().m_pStopDownload(h))
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("stopDownload ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

    return true;
}

bool HanBang_videoserver::getPlayBackPos(__int64 playbackHandle, __int32* pos)
{
	g_log.AddLog(string("getPlayBackPos"));
    return false;
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("getDownloadPos ���ȵ�¼"));
		return false;
	}
	BOOL bRet = Api_HanBang::Api().m_pPlayBackControl(playbackHandle, HB_SDVR_PLAYGETPOS, NULL, (DWORD *)pos);
	if (bRet < 0)
	{
		g_log.AddLog(string("getDownloadPos ��ȡ���Ž���ʧ��"));
		return false;
	}
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "getPlayBackPos pos:%d", *pos);
	g_log.AddLog(string(szLog));
	return true;
}

bool HanBang_videoserver::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
{
    
    if (m_mapDownInfo.find(h) != m_mapDownInfo.end())
    {
        *totalSize = m_mapDownInfo[h].size;
        *currentSize = Api_HanBang::Api().m_pGetDownloadBytesSize(h);
        *failed = (*currentSize < 0);
    }
    else
    {
        return false;
    }

    if (*totalSize <= *currentSize)
    {
        m_mapDownInfo.clear();
    }

    return true;
}