#include "XingWang_videoserver.h"
#include <iostream>

#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"
Log g_log("XingWang_videoserver");

// #pragma comment(lib, "HCNetSDK.lib")

IVideoServerFactory* VideoServerFactory()
{
    return new CFactoryXingWang();
}

std::string GetLastErrorString()
{
    DWORD dwErr;
    dwErr = Api_XingWang::Api().m_pGetLastError();

    switch (dwErr)
    {
		case SN_DVR_ERROR_SUCESS: return "û�д���";
        case SN_DVR_PASSWORD_ERROR: return "�������";
		case SN_DVR_USERNAME_ERROR: return "�û�������";
		case SN_DVR_ACCESS_DENIED: return "���ʾܾ�";
		case SN_DVR_MAX_DEVICE_CONNECTION: return "�豸�ﵽ���������";
		case SN_DVR_OUT_OF_MEMORY: return "�ڴ治��";
		case SN_DVR_REQUEST_TIMEOUT: return "����ʱ";
		case SN_DVR_INVALID_PARAMETER: return "��Ч����";
		case SN_DVR_CONNECT_SERVER_FAILED: return "���ӷ�����ʧ��";
		case SN_DVR_SEND_FAILED: return "����ʧ��";
		case SN_DVR_CREATE_SOCKET_ERROR: return "����socketʧ��";
		case SN_DVR_ALREADY_LOGIN: return "�Ѿ���¼";
		case SN_DVR_MAC_OR_IP_NOT_MATCH: return "MAC��ַ����IP��ַ��ƥ��";
		case SN_DVR_VIDEO_PREVIEW_ERROR: return "��Ƶ��Ԥ������";
		case SN_DVR_LOCAL_PORT_INUSE: return "���ض˿��Ѿ���ʹ��";
		case SN_DVR_FILE_NO_FOUND: return "�ļ�(����Ŀ��)δ�ҵ�";
		case SN_DVR_DEVICE_CONNECTION_LIMIT: return "�豸��������";
		case SN_DVR_SET_PARAMETER_ERROR: return "���ò���ʧ��";
		case SN_DVR_PARAMETER_DATA_ERROR: return "�������ݴ���";
		case SN_DVR_NOT_SUPPORT: return "��֧��";
		case SN_DVR_INNER_DATA_ERROR: return "�ڲ����ݴ���";
		case SN_DVR_RESPONSE_ERROR_MSG: return "�豸��������ʧ����Ϣ";
		case SN_DVR_CRUISE_POINT_EXISTING: return "�ؼ����Ѿ�����";
		case SN_DVR_GSMERROR_OPER: return "�����쳣";
		case SN_DVR_GSMERROR_PARAM: return "�����쳣";
		case SN_DVR_GSMERROR_EXP: return "�豸�쳣";
		case SN_DVR_GSMERROR_NOSIM: return "��SIM��";
		case SN_DVR_GSMERROR_NONET: return "δ����";
		case SN_DVR_GSMERROR_NONE: return "���óɹ�";
		case SN_DVR_GSMRESTARTING_IND: return "�豸����";
		case SN_DVR_CRUISE_POINT_INVALID: return "Ԥ�õ���Ч";
		case SN_DVR_MOD_VOA_TK_ERR_PB: return "�Խ����������,���ڻط�";
		case SN_DVR_SQL_ERROR: return "���ݿ����ʧ��";
		case SN_DVR_CONDITION_ERROR: return "��������";
		case SN_DVR_NO_MATCH_RECORD: return "û�п�ƥ��ļ�¼";
		case SN_DVR_MAX_RECORD: return "�ﵽ��¼���ޣ�һ���������Ӽ�¼����";
		case SN_DVR_PTZ_POINT_INVALID_ERR: return "�ؼ��㲻����";
		case SN_DVR_PTZ_PRESET_USE_ERR: return "Ԥ�õ���ʹ��";
		case SN_DVR_PTZ_PRESET_INVALID_ERR: return "Ԥ�õ���Ч";
		case SN_DVR_PTZ_CRUISE_USE_ERR: return "����Ѳ��";
		case SN_DVR_INNER_COMPONENT_CLOSED: return "�ڲ�������ڹر�״̬";
		case SN_DVR_CREATE_AUDIO_OUTPUT_DEVICE_ERROR: return "������Ƶ����豸ʧ��";
		case SN_DVR_CREATE_AUDIO_INPUT_DEVICE_ERROR: return "������Ƶ�����豸ʧ��";
		case SN_DVR_CRUISE_OPERATION_ERROR: return "Ѳ������ʧ��";
		case SN_DVR_DEVICE_BUSY: return "�豸æ";
		case SN_DVR_NO_HARDDISK: return "�豸��Ӳ��";
		case SN_DVR_HARDDISK_FULL: return "Ӳ��������";
		case SN_DVR_ALL_HARDDISK_NOT_FORMATED: return "����Ӳ�̾�δ��ʽ��";
		case SN_DVR_ANY_HARDDISK_NOT_FORMATED: return "����Ӳ��δ��ʽ��";
		case SN_DVR_HARDDISK_ERROR: return "Ӳ��״̬�쳣";
		case SN_DVR_NO_3G_MODULAR: return "��3Gģ��";
		case SN_DVR_IS_TALKING: return "�豸�Խ���";
		case SN_NVR_DIGITALCHAN_UNCONFIG: return "NVR��ǰͨ��δ����";
		case SN_DVR_AUTHORITY_LOCK: return "Ȩ�޵���";
		case SN_DVR_UNAUTHORITY: return "��Ȩ��";
		case SN_DVR_DATASIZE_TOOLAEAGE: return "�ļ�̫��";
		case SN_DVR_SERIALCOM_UNOPEN: return "����δ��";
		case SN_DVR_SERIALCOM_OPEN_FAIL: return "���ڴ�ʧ��";
		case SN_DVR_DEVICE_EXP: return "�豸���쳣";
		case SN_NVR_REMOTE_CONF_DEVICE_EXP: return "NVRԶ�������豸���쳣";
		case SN_DVR_PASS_OR_USER_ERROR: return "�û������������";
		case SN_DVR_TEST_CONNECT_ERROR: return "��������ʧ��";
		case SN_DVR_TEST_LOGON_ERROR: return "��½����ʧ��";
		case SN_DVR_ERR_RESET_PASSWORD: return "��������";
		case SN_NVR_NOT_SUPPORT: return "NVR�豸��֧��";
		//case SN_NVS_NOT_SUPPORT: return "NVS�豸��֧��";
		case SN_NVR_PTZ_OPT_FAILED: return "��̨�������ɹ�";
		case SN_DVR_3G_CONNECT_FAILED: return "3G����ʧ��";
		case SN_DVR_STARTED_RECORD_ERROR: return "�Ѿ���ʼ¼��";
		case SN_DVR_NO_STARTED_RECORD_ERROR: return "δ��ʼ¼��";
		case SN_DVR_UNKNOWN_ERROR: return "δ֪����";
		//case SN_NVR_PTZ_OPT_FAILED: return "��̨�������ɹ�";
		case SN_ERR_PTZ_PASDECODE_LOCALPTZ: return "���������£�����������̨����";
		case SN_ERR_PTZ_PASDECODE_REMOTEPTZ: return "���������£�����Զ����̨����";
		case SN_ERR_PTZ_SWITCHSTATE_LOCALPTZ: return "��ѯ״̬�£�����������̨����";
		case SN_ERR_PTZ_SWITCHSTATE_REMOTEPTZ: return "��ѯ״̬�£�����Զ����̨����";
		default: return "δ֪����";
    }
}



CFactoryXingWang::CFactoryXingWang()
{
    init();
}

CFactoryXingWang::~CFactoryXingWang()
{
    clean();
}






bool CFactoryXingWang::init()
{
    if (!m_init)
    {

        int iRet = Api_XingWang::Api().m_pInit();
        //SN_DVR_SetConnectTime(1000, 30);
        //SN_DVR_SetReconnect(3000);
        //SN_DVR_SetDVRMessage()
		if (iRet < -1)
        {
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("��ʼ��SDKʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
        }

		bool bRet = Api_XingWang::Api().m_pPlayInit();
		if (!bRet)
		{
			g_log.AddLog(string("��ʼ�����ſ�ʧ�ܣ�"));
			return false;
		}

		m_init = true;
		g_log.AddLog(string("��ʼ��SDK�ɹ�"));
    }

    return m_init;
}


void CFactoryXingWang::clean()
{
    Api_XingWang::Api().m_pUninit();
}




IVideoServer* CFactoryXingWang::create()
{
    if (!init())
    {
        return NULL;
    }

    return new XingWang_videoserver();
}


// std::vector<XingWang_videoserver*> XingWang_videoserver::sServers;
// std::recursive_mutex XingWang_videoserver::sMtServers;

/*
 * ��������
 */
XingWang_videoserver::XingWang_videoserver()
{
//     std::lock_guard<std::recursive_mutex> lock(XingWang_videoserver::sMtServers);
//     sServers.push_back(this);
}

XingWang_videoserver::~XingWang_videoserver()
{
    logout();
//     std::lock_guard<std::recursive_mutex> lock(XingWang_videoserver::sMtServers);
//     for (int i = 0; i < sServers.size(); i++)
//     {
//         if (sServers[i] == this)
//         {
//             sServers.erase(sServers.begin() + i);
//             break;
//         }
//     }
}

IVideoServer* XingWang_videoserver::clone()
{
//     XingWang_videoserver *svr = new XingWang_videoserver();
// 	memcpy(svr, this, sizeof(XingWang_videoserver));
//     return svr;
	return NULL;
}

void CALLBACK PosCallBack(LONG lFilePlay, BYTE *pData, int size, void *pContext)
{
	XingWang_videoserver *pThis = (XingWang_videoserver *)pContext;
	if (!pThis)
	{
		return;
	}
	{
		Mutex::ScopedLock lock(pThis->m_mtxPos);
		map<long long, stPos_DownPlay>::iterator itr = pThis->m_mapPosDownPlay.find(lFilePlay);
		if (itr != pThis->m_mapPosDownPlay.end())
		{
			itr->second.iCurSize += size;
			itr->second.iPercent = ((float)itr->second.iCurSize / (float)itr->second.iTotalSize) * 100;
		}
	}

	while (1){
		BOOL flag = Api_XingWang::Api().m_pPlayInputV(pThis->m_iPort, pData, size);
		if (flag == FALSE)
		{
			Sleep(5);
		}
		else{
			break;
		}
	}
}

bool XingWang_videoserver::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string >& channels)
{
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "��¼ID:%d ip:%s port:%d user:%s psw:%s", m_lLoginHandle, IP, port, user, password);
	g_log.AddLog(string(szLog));
    memset(&m_deviceInfo, 0, sizeof(m_deviceInfo));

    m_lLoginHandle = Api_XingWang::Api().m_pLogin((char*)IP, port,
                                   (char*)user,(char*)password,
                                   &m_deviceInfo);

    if (m_lLoginHandle < 0)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("login ��¼ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

	if (m_deviceInfo.byChannelCount > 0)
	{
		for (int i = 0; i < m_deviceInfo.byChannelCount; i++)
		{
			char szName[16];
			ZeroMemory(szName, sizeof(szName));
			sprintf(szName, "ͨ��%d", i + 1);
			channels[1 + i] = std::string(szName);
		}
	}
	else if(m_deviceInfo.byIPChannelCount > 0)
	{
		for (int i = 0; i < m_deviceInfo.byIPChannelCount; i++)
		{
			char szName[16];
			ZeroMemory(szName, sizeof(szName));
			sprintf(szName, "ͨ��%d", i + 1);
			channels[1 + i] = std::string(szName);
		}
	}

    return true;
}

bool XingWang_videoserver::logout()
{
    if (m_lLoginHandle >= 0 && !Api_XingWang::Api().m_pLogout(m_lLoginHandle))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }

    return true;
}




bool XingWang_videoserver::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart,
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

		XingWang::SN_DVR_FILECONDITION f;
		memset(&f, 0, sizeof(XingWang::SN_DVR_FILECONDITION));
		struct tm Tm;

		XingWang::SN_DVR_TIME struStartTime;
		_localtime64_s(&Tm, (const time_t*)&timeStart);
		struStartTime.dwYear = Tm.tm_year + 1900;
		struStartTime.dwMonth = Tm.tm_mon + 1;
		struStartTime.dwDay = Tm.tm_mday;
		struStartTime.dwHour = Tm.tm_hour;
		struStartTime.dwMinute = Tm.tm_min;
		struStartTime.dwSecond = Tm.tm_sec;

		XingWang::SN_DVR_TIME struStopTime;
		_localtime64_s(&Tm, (const time_t*)&timeEnd);
		struStopTime.dwYear = Tm.tm_year + 1900;
		struStopTime.dwMonth = Tm.tm_mon + 1;
		struStopTime.dwDay = Tm.tm_mday;
		struStopTime.dwHour = Tm.tm_hour;
		struStopTime.dwMinute = Tm.tm_min;
		struStopTime.dwSecond = Tm.tm_sec;

		XingWang::SN_DVR_TIME stime = struStartTime;
		XingWang::SN_DVR_TIME etime = struStopTime;

		char szTime[512];
		ZeroMemory(szTime, 512);
		sprintf(szTime, " s_time:%d-%02d-%02d %02d:%02d:%02d e_time:%d-%02d-%02d %02d:%02d:%02d channel:%d linkID:%d", stime.dwYear, stime.dwMonth, stime.dwDay,
			stime.dwHour, stime.dwMinute, stime.dwSecond,
			etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond, nChannelId, m_lLoginHandle);
		g_log.AddLog(string("GetRecordFileList ") + string(szTime));

		f.lSessionID = m_lLoginHandle;
		f.lChannel = nChannelId;
		f.dwFileType = 0;
		f.dwIsLocked = 0xff;
		f.tmStartTime = struStartTime;
		f.tmEndTime = struStopTime;

		XingWang::SN_DVR_FILEDATA findInfo;
		ZeroMemory(&findInfo, sizeof(findInfo));
		LONG lfind = Api_XingWang::Api().m_pFindFile(&f, &findInfo);

		if (lfind == FALSE)
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("GetRecordFileList ��ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
			continue;
		}

		int iFinds = 0;
		RecordFile rf;
		while (lfind > 0)
		{
			if (findInfo.dwFileSizeHigh > 0 || findInfo.dwFileSizeLow > 0)//�����Ƶ�ļ��������0(�������з����ļ���СΪ0���,���Ա�����˵��Ĳ���)
			{
				struct tm Tm;
				Tm.tm_year = findInfo.tmFileStartTime.dwYear - 1900;
				Tm.tm_mon = findInfo.tmFileStartTime.dwMonth - 1;
				Tm.tm_mday = findInfo.tmFileStartTime.dwDay;
				Tm.tm_hour = findInfo.tmFileStartTime.dwHour;
				Tm.tm_min = findInfo.tmFileStartTime.dwMinute;
				Tm.tm_sec = findInfo.tmFileStartTime.dwSecond;
				rf.beginTime = _mktime64(&Tm);

				Tm.tm_year = findInfo.tmFileEndTime.dwYear - 1900;
				Tm.tm_mon = findInfo.tmFileEndTime.dwMonth - 1;
				Tm.tm_mday = findInfo.tmFileEndTime.dwDay;
				Tm.tm_hour = findInfo.tmFileEndTime.dwHour;
				Tm.tm_min = findInfo.tmFileEndTime.dwMinute;
				Tm.tm_sec = findInfo.tmFileEndTime.dwSecond;
				rf.endTime = _mktime64(&Tm);

				stime = findInfo.tmFileStartTime;
				etime = findInfo.tmFileEndTime;
				ZeroMemory(szTime, 512);
				sprintf(szTime, "channel%d %d-%02d-%02d %02d-%02d-%02d %d-%02d-%02d %02d-%02d-%02d", nChannelId,
					stime.dwYear, stime.dwMonth, stime.dwDay,
					stime.dwHour, stime.dwMinute, stime.dwSecond,
					etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond);

				rf.channel = nChannelId;
				rf.name = szTime;
				rf.size = findInfo.dwFileSizeLow;
				rf.setPrivateData(&findInfo, sizeof(XingWang::SN_DVR_FILEDATA));

// 				{
// 					Mutex::ScopedLock lock(m_mtx);
// 					m_mapArcItem.insert(std::make_pair(string(szTime), findInfo));
// 				}

				files.push_back(rf);
				iFinds++;

				char szSize[64];
				ZeroMemory(szSize, sizeof(szSize));
				_i64toa(rf.size, szSize, 10);

				char szLog[1024];
				ZeroMemory(szLog, 1024);
				sprintf(szLog, "GetRecordFileList �ļ���:%s �ļ���С:%s �ļ�ʱ��:%s ͨ��:%d", findInfo.strFileName, szSize, szTime, nChannelId);
				g_log.AddLog(string(szLog));
			}
			else
			{
				::Sleep(20);
			}
			ZeroMemory(&findInfo, sizeof(findInfo));
			bool bRet = Api_XingWang::Api().m_pFindNext(lfind, &findInfo);
			if (!bRet)
			{
				break;
			}
		}

		if (FALSE == Api_XingWang::Api().m_pFindClose(lfind))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("GetRecordFileList �رղ�ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
			continue;
		}
	}

    return true;
}



bool XingWang_videoserver::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
    if (0 >= m_lLoginHandle)
    {
        m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("downLoadByRecordFile ���ȵ�¼"));
        return false;
    }

// 	XingWang::SN_DVR_FILEDATA info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, XingWang::SN_DVR_FILEDATA>::iterator itr = m_mapArcItem.find(file.name);
// 		if (itr == m_mapArcItem.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			char szLog[1024];
// 			ZeroMemory(szLog, 1024);
// 			sprintf(szLog, "downLoadByRecordFile ���ļ������� mapSize:%d this:%d filename:%s", m_mapArcItem.size(), (int)this, file.name.c_str());
// 			g_log.AddLog(string(szLog));
// 			return false;
// 		}
// 
// 		info = itr->second;
// 	}
//	g_log.AddLog(string("downLoadByRecordFile �ļ���:") + info.strFileName + string(" �����ļ���:") + saveFileName);

	DeleteFileA(saveFileName);
	XingWang::SN_DVR_FILEDATA* pData = (XingWang::SN_DVR_FILEDATA *)file.getPrivateData();
	hdl = Api_XingWang::Api().m_pDownloadByFile(m_lLoginHandle, pData->strFileName, (char*)saveFileName);
	if (hdl <= 0)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("downLoadByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "downLoadByRecordFile hdl:%d", hdl);
	g_log.AddLog(string(szLog));

	m_strDownFile = saveFileName;
	{
		stPos_DownPlay pos;
		pos.iTotalSize = file.size;
		pos.iCurSize = 0;
		pos.iPercent = 0;
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.insert(make_pair(hdl, pos));
	}

    return true;
}


bool  XingWang_videoserver::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("PlayBackByRecordFile ���ȵ�¼"));
        return false;
    }

// 	XingWang::SN_DVR_FILEDATA info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, XingWang::SN_DVR_FILEDATA>::iterator itr = m_mapArcItem.find(file.name);
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
	XingWang::SN_DVR_TIME struBeginTime;
	_localtime64_s(&Tm, (const time_t*)&file.beginTime);
    struBeginTime.dwYear = Tm.tm_year + 1900;
    struBeginTime.dwMonth = Tm.tm_mon + 1;
    struBeginTime.dwDay = Tm.tm_mday;
    struBeginTime.dwHour = Tm.tm_hour;
    struBeginTime.dwMinute = Tm.tm_min;
    struBeginTime.dwSecond = Tm.tm_sec;

	XingWang::SN_DVR_TIME struEndTime;
	_localtime64_s(&Tm, (const time_t*)&file.endTime);
    struEndTime.dwYear = Tm.tm_year + 1900;
    struEndTime.dwMonth = Tm.tm_mon + 1;
    struEndTime.dwDay = Tm.tm_mday;
    struEndTime.dwHour = Tm.tm_hour;
    struEndTime.dwMinute = Tm.tm_min;
    struEndTime.dwSecond = Tm.tm_sec;

	XingWang::SN_DVR_TIME stime = struBeginTime;
	XingWang::SN_DVR_TIME etime = struEndTime;

	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "��¼ID:%d ͨ��:%d ʱ��:%d-%02d-%02d %02d:%02d:%02d %d-%02d-%02d %02d:%02d:%02d", m_lLoginHandle, file.channel,
		stime.dwYear, stime.dwMonth, stime.dwDay, stime.dwHour, stime.dwMinute, stime.dwSecond,
		etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond);
	g_log.AddLog(string(szLog));

	Api_XingWang::Api().ReloadPlayLib();
	m_iPort = 0;
	bool bRet = false;
	bRet = Api_XingWang::Api().m_pPlayGetPort((LONG *)&m_iPort);
	if (!bRet)
	{
		g_log.AddLog(string("PlayBackByRecordFile ���ſ��ȡͨ��ʧ��"));
		return false;
	}
	bRet = Api_XingWang::Api().m_pPlaySetMode(m_iPort, XingWang::EX_FILE_STREAM);
	if (!bRet)
	{
		g_log.AddLog(string("PlayBackByRecordFile ���ſ����ò���ģʽʧ��"));
		return false;
	}
	bRet = Api_XingWang::Api().m_pPlayPlay(m_iPort, hwnd);
	if (!bRet)
	{
		g_log.AddLog(string("PlayBackByRecordFile ���ſ⿪ʼ����ʧ��"));
		return false;
	}
	XingWang::SN_DVR_FILEDATA* pData = (XingWang::SN_DVR_FILEDATA *)file.getPrivateData();
	playbackHandle = Api_XingWang::Api().m_pPlayBackByName(m_lLoginHandle, pData->strFileName, NULL, PosCallBack, this);
	//Api_XingWang::Api().m_pPlayBackByTime(m_lLoginHandle, file.channel, &struBeginTime, &struEndTime, hwnd);
	//playbackHandle = Api_XingWang::Api().m_pPlayBackByTime(m_lLoginHandle, info.nCh, &struBeginTime, &struEndTime, hwnd);
	if (playbackHandle <= 0)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("PlayBackByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
	}
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "PlayBackByRecordFile playbackHandle:%d", playbackHandle);
	g_log.AddLog(string(szLog));

	{
		stPos_DownPlay pos;
		pos.iTotalSize = file.size;
		pos.iCurSize = 0;
		pos.iPercent = 0;
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.insert(make_pair(playbackHandle, pos));
	}

    return true;
}

bool XingWang_videoserver::SetPlayBack(download_handle_t playbackHandle, __int32 pos)
{
	g_log.AddLog(string("SetPlayBack ��֧��"));
	return FALSE;// != Api_XingWang::Api().m_pPlayBackControl(playbackHandle, SN_DVR_PLAYBYSLIDER, pos, NULL);
}

bool XingWang_videoserver::StopPlayBack(download_handle_t playbackHandle, __int32 mPause)
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
		if (!Api_XingWang::Api().m_pPlayBackControl(playbackHandle, SN_DVR_PLAYPAUSE, 0, NULL))
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

		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.erase(playbackHandle);

		if (!Api_XingWang::Api().m_pStopPlayBack(playbackHandle))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("StopPlayBack ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
		}

		bool bRet = Api_XingWang::Api().m_pPlayStop(m_iPort);
		if (!bRet)
		{
			g_log.AddLog(string("PlayBackByRecordFile ���ſ�ֹͣ����ʧ��"));
			return false;
		}
		bRet = Api_XingWang::Api().m_pPlayFreePort(m_iPort);
		if (!bRet)
		{
			g_log.AddLog(string("PlayBackByRecordFile ���ſ��ͷ�ͨ��ʧ��"));
			return false;
		}
	}

    return true;
}

bool XingWang_videoserver::stopDownload(download_handle_t h)
{
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("stopDownload ���ȵ�¼"));
		return false;
	}
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "stopDownload ��ʼֹͣ���� hdl:%d", h);
	g_log.AddLog(string(szLog));

	{
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.erase(h);
	}
    if (FALSE == Api_XingWang::Api().m_pStopDownload(h))
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("stopDownload ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

    return true;
}

bool XingWang_videoserver::getPlayBackPos(__int64 playbackHandle, __int32* pos)
{
	g_log.AddLog(string("getPlayBackPos"));
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("getPlayBackPos ���ȵ�¼"));
		return false;
	}
	{
		Mutex::ScopedLock lock(m_mtxPos);
		map<long long, stPos_DownPlay>::iterator itr = m_mapPosDownPlay.find(playbackHandle);
		if (itr != m_mapPosDownPlay.end())
		{
			*pos = itr->second.iPercent;
			return true;
		}
		else
		{
			g_log.AddLog(string("getPlayBackPos �Ҳ����ò���"));
			return false;
		}
	}

	return false;
}

bool XingWang_videoserver::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
{
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("getDownloadPos ���ȵ�¼"));
		return false;
	}
	int iPos = Api_XingWang::Api().m_pGetDownloadPos(h);
	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "getDownloadPos hdl:%d ��ǰ����:%d", h, iPos);
	g_log.AddLog(string(szLog));

	if (0 > iPos)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("getDownloadPos ��ȡ����ʧ�ܣ� ����ԭ��:") + m_sLastError);
		*failed = true;
		return false;
	}
	
	{
		Mutex::ScopedLock lock(m_mtxPos);
		map<long long, stPos_DownPlay>::iterator itr = m_mapPosDownPlay.find(h);
		if (itr != m_mapPosDownPlay.end())
		{
			itr->second.iCurSize = ((float)iPos / (float)1000) * (itr->second.iTotalSize);
			itr->second.iPercent = iPos/10;

			*totalSize = itr->second.iTotalSize;
			*currentSize = itr->second.iCurSize;
		}
		else
		{
			g_log.AddLog(string("getDownloadPos �Ҳ���������"));
			*failed = true;
			return false;
		}
	}
	*failed = false;
	return true;
}