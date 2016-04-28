#include "WSD_videoserver.h"
#include <iostream>

#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"
Log g_log("WSD_videoserver");

IVideoServerFactory* VideoServerFactory()
{
    return new CFactoryWSD();
}

static std::string GetLastErrorString()
{
    DWORD dwError;
	dwError = Api_WSD::Api().ZLNET_GetLastError();
// 	char erch[128] = { 0 };
// 	sprintf_s(erch, "dwError:%d", dwError);
// 	g_log.AddLog(string(erch));
    switch (dwError)
    {
		case ZLNET_ERROR: return "δ֪����";
		case ZLNET_SYSTEM_ERROR: return "Windowsϵͳ����";
		case ZLNET_NETWORK_ERROR: return "������󣬿�������Ϊ���糬ʱ";
		case ZLNET_DEV_VER_NOMATCH: return "�豸Э�鲻ƥ��";
		case ZLNET_INVALID_HANDLE: return "�����Ч";
		case ZLNET_OPEN_CHANNEL_ERROR: return "��ͨ��ʧ��";
		case ZLNET_CLOSE_CHANNEL_ERROR: return "�ر�ͨ��ʧ��";
		case ZLNET_ILLEGAL_PARAM: return "�û��������Ϸ�";
		case ZLNET_SDK_INIT_ERROR: return "SDK��ʼ������";
		case ZLNET_SDK_UNINIT_ERROR: return "SDK�������";
		case ZLNET_RENDER_OPEN_ERROR: return "����render��Դ����";
		case ZLNET_DEC_OPEN_ERROR: return "�򿪽�������";
		case ZLNET_DEC_CLOSE_ERROR: return "�رս�������";
		case ZLNET_MULTIPLAY_NOCHANNEL: return "�໭��Ԥ���м�⵽ͨ����Ϊ0";
		case ZLNET_TALK_INIT_ERROR: return "¼�����ʼ��ʧ��";
		case ZLNET_TALK_NOT_INIT: return "¼����δ����ʼ��";
		case ZLNET_TALK_SENDDATA_ERROR: return "������Ƶ���ݳ���";
		case ZLNET_REAL_ALREADY_SAVING: return "ʵʱ�����Ѿ����ڱ���״̬";
		case ZLNET_NOT_SAVING: return "δ����ʵʱ����";
		case ZLNET_OPEN_FILE_ERROR: return "���ļ�����";
		case ZLNET_PTZ_SET_TIMER_ERROR: return "������̨���ƶ�ʱ��ʧ��";
		case ZLNET_RETURN_DATA_ERROR: return "�Է������ݵ�У�����";
		case ZLNET_INSUFFICIENT_BUFFER: return "û���㹻�Ļ���";
		case ZLNET_NOT_SUPPORTED: return "��ǰSDKδ֧�ָù���";
		case ZLNET_NO_RECORD_FOUND: return "��ѯ����¼��";
		case ZLNET_NOT_AUTHORIZED: return "�޲���Ȩ��";
		case ZLNET_NOT_NOW: return "��ʱ�޷�ִ��";
		case ZLNET_NO_TALK_CHANNEL: return "δ���ֶԽ�ͨ��";
		case ZLNET_NO_AUDIO: return "δ������Ƶ";
		case ZLNET_NO_INIT: return "����SDKδ����ʼ��";
		case ZLNET_DOWNLOAD_END: return "�����ѽ���";
		case ZLNET_EMPTY_LIST: return "��ѯ���Ϊ��";
		case ZLNET_ERROR_GETCFG_SYSATTR: return "��ȡϵͳ��������ʧ��";
		case ZLNET_ERROR_GETCFG_SERIAL: return "��ȡ���к�ʧ��";
		case ZLNET_ERROR_GETCFG_GENERAL: return "��ȡ��������ʧ��";
		case ZLNET_ERROR_GETCFG_DSPCAP: return "��ȡDSP��������ʧ��";
		case ZLNET_ERROR_GETCFG_NETCFG: return "��ȡ��������ʧ��";
		case ZLNET_ERROR_GETCFG_CHANNAME: return "��ȡͨ������ʧ��";
		case ZLNET_ERROR_GETCFG_VIDEO: return "��ȡ��Ƶ����ʧ��";
		case ZLNET_ERROR_GETCFG_RECORD: return "��ȡ¼������ʧ��";
		case ZLNET_ERROR_GETCFG_PRONAME: return "��ȡ������Э������ʧ��";
		case ZLNET_ERROR_GETCFG_FUNCNAME: return "��ȡ232���ڹ�������ʧ��";
		case ZLNET_ERROR_GETCFG_485DECODER: return "��ȡ����������ʧ��";
		case ZLNET_ERROR_GETCFG_232COM: return "��ȡ232��������ʧ��";
		case ZLNET_ERROR_GETCFG_ALARMIN: return "��ȡ�ⲿ������������ʧ��";
		case ZLNET_ERROR_GETCFG_ALARMDET: return "��ȡ��̬��ⱨ��ʧ��";
		case ZLNET_ERROR_GETCFG_SYSTIME: return "��ȡ�豸ʱ��ʧ��";
		case ZLNET_ERROR_GETCFG_PREVIEW: return "��ȡԤ������ʧ��";
		case ZLNET_ERROR_GETCFG_AUTOMT: return "��ȡ�Զ�ά������ʧ��";
		case ZLNET_ERROR_GETCFG_VIDEOMTRX: return "��ȡ��Ƶ��������ʧ��";
		case ZLNET_ERROR_GETCFG_COVER: return "��ȡ�����ڵ�����ʧ��";
		case ZLNET_ERROR_GETCFG_WATERMAKE: return "��ȡͼ��ˮӡ����ʧ��";
		case ZLNET_ERROR_SETCFG_GENERAL: return "�޸ĳ�������ʧ��";
		case ZLNET_ERROR_SETCFG_NETCFG: return "�޸���������ʧ��";
		case ZLNET_ERROR_SETCFG_CHANNAME: return "�޸�ͨ������ʧ��";
		case ZLNET_ERROR_SETCFG_VIDEO: return "�޸���Ƶ����ʧ��";
		case ZLNET_ERROR_SETCFG_RECORD: return " �޸�¼������ʧ��";
		case ZLNET_ERROR_SETCFG_485DECODER: return "�޸Ľ���������ʧ��";
		case ZLNET_ERROR_SETCFG_232COM: return " �޸�232��������ʧ��";
		case ZLNET_ERROR_SETCFG_ALARMIN: return "�޸��ⲿ���뱨������ʧ��";
		case ZLNET_ERROR_SETCFG_ALARMDET: return " �޸Ķ�̬��ⱨ������ʧ��";
		case ZLNET_ERROR_SETCFG_SYSTIME: return " �޸��豸ʱ��ʧ��";
		case ZLNET_ERROR_SETCFG_PREVIEW: return " �޸�Ԥ������ʧ��";
		case ZLNET_ERROR_SETCFG_AUTOMT: return "�޸��Զ�ά������ʧ��";
		case ZLNET_ERROR_SETCFG_VIDEOMTRX: return "�޸���Ƶ��������ʧ��";
		case ZLNET_ERROR_SETCFG_COVER: return "�޸������ڵ�����ʧ��";
		case ZLNET_ERROR_SETCFG_WATERMAKE: return "�޸�ͼ��ˮӡ����ʧ��";
		case ZLNET_ERROR_SETCFG_WLAN: return "�޸�����������Ϣʧ��";
		case ZLNET_ERROR_SETCFG_WLANDEV: return "ѡ�����������豸ʧ��";
		case ZLNET_ERROR_SETCFG_REGISTER: return "�޸�����ע���������ʧ��";
		case ZLNET_ERROR_SETCFG_CAMERA: return "�޸�����ͷ��������ʧ��";
		case ZLNET_ERROR_SETCFG_INFRARED: return "�޸ĺ��ⱨ������ʧ��";
		case ZLNET_ERROR_SETCFG_SOUNDALARM: return "�޸���Ƶ��������ʧ��";
		case ZLNET_ERROR_SETCFG_STORAGE: return "�޸Ĵ洢λ������ʧ��";
		case ZLNET_AUDIOENCODE_NOTINIT: return "��Ƶ����ӿ�û�гɹ���ʼ��";
		case ZLNET_DATA_TOOLONGH: return "���ݹ���";
		case ZLNET_UNSUPPORTED: return "�豸��֧�ָò���";
		case ZLNET_DEVICE_BUSY: return "�豸��Դ����";
		case ZLNET_SERVER_STARTED: return "�������Ѿ�����";
		case ZLNET_SERVER_STOPPED: return "��������δ�ɹ�����";
		case ZLNET_LISTER_INCORRECT_SERIAL: return "�������к�����";
		case ZLNET_QUERY_DISKINFO_FAILED: return "��ȡӲ����Ϣʧ��";
		case ZLNET_ERROR_GETCFG_SESSION: return "��ȡ����Session��Ϣ";
		case ZLNET_USER_FLASEPWD_TRYTIME: return "����������󳬹����ƴ���";
		case ZLNET_LOGIN_ERROR_PASSWORD: return "���벻��ȷ";
		case ZLNET_LOGIN_ERROR_USER: return "�ʻ�������";
		case ZLNET_LOGIN_ERROR_TIMEOUT: return "�ȴ���¼���س�ʱ";
		case ZLNET_LOGIN_ERROR_RELOGGIN: return "�ʺ��ѵ�¼";
		case ZLNET_LOGIN_ERROR_LOCKED: return "�ʺ��ѱ�����";
		case ZLNET_LOGIN_ERROR_BLACKLIST: return "�ʺ��ѱ���Ϊ������";
		case ZLNET_LOGIN_ERROR_BUSY: return "��Դ���㣬ϵͳæ";
		case ZLNET_LOGIN_ERROR_CONNECT: return "��¼�豸��ʱ���������粢����";
		case ZLNET_LOGIN_ERROR_NETWORK: return "��������ʧ��";
		case ZLNET_LOGIN_ERROR_SUBCONNECT: return "��¼�豸�ɹ������޷�������Ƶͨ������������״��";
		case ZLNET_RENDER_SOUND_ON_ERROR: return "Render�����Ƶ����";
		case ZLNET_RENDER_SOUND_OFF_ERROR: return "Render��ر���Ƶ����";
		case ZLNET_RENDER_SET_VOLUME_ERROR: return "Render�������������";
		case ZLNET_RENDER_ADJUST_ERROR: return "Render�����û����������";
		case ZLNET_RENDER_PAUSE_ERROR: return "Render����ͣ���ų���";
		case ZLNET_RENDER_SNAP_ERROR: return "Render��ץͼ����";
		case ZLNET_RENDER_STEP_ERROR: return "Render�ⲽ������";
		case ZLNET_RENDER_FRAMERATE_ERROR: return "Render������֡�ʳ���";
		case ZLNET_GROUP_EXIST: return "�����Ѵ���";
		case ZLNET_GROUP_NOEXIST: return "����������";
		case ZLNET_GROUP_RIGHTOVER: return "���Ȩ�޳���Ȩ���б�Χ";
		case ZLNET_GROUP_HAVEUSER: return "�������û�������ɾ��";
		case ZLNET_GROUP_RIGHTUSE: return "���ĳ��Ȩ�ޱ��û�ʹ�ã����ܳ���";
		case ZLNET_GROUP_SAMENAME: return "������ͬ���������ظ�";
		case ZLNET_USER_EXIST: return "�û��Ѵ���";
		case ZLNET_USER_NOEXIST: return "�û�������";
		case ZLNET_USER_RIGHTOVER: return "�û�Ȩ�޳�����Ȩ��";
		case ZLNET_USER_PWD: return "�����ʺţ��������޸�����";
		case ZLNET_USER_FLASEPWD: return "���벻��ȷ";
		case ZLNET_USER_NOMATCHING: return "���벻ƥ��";
		case ZLNET_ERROR_GETCFG_ETHERNET: return "��ȡ��������ʧ��";
		case ZLNET_ERROR_GETCFG_WLAN: return "��ȡ����������Ϣʧ��";
		case ZLNET_ERROR_GETCFG_WLANDEV: return "��ȡ���������豸ʧ��";
		case ZLNET_ERROR_GETCFG_REGISTER: return "��ȡ����ע�����ʧ��";
		case ZLNET_ERROR_GETCFG_CAMERA: return "��ȡ����ͷ����ʧ��";
		case ZLNET_ERROR_GETCFG_INFRARED: return "��ȡ���ⱨ������ʧ��";
		case ZLNET_ERROR_GETCFG_SOUNDALARM: return "��ȡ��Ƶ��������ʧ��";
		case ZLNET_ERROR_GETCFG_STORAGE: return "��ȡ�洢λ������ʧ��";
		case ZLNET_ERROR_GETCFG_MAIL: return "��ȡ�ʼ�����ʧ��";
		case ZLNET_CONFIG_DEVBUSY: return "��ʱ�޷�����";
		case ZLNET_CONFIG_DATAILLEGAL: return "�������ݲ��Ϸ�";
		case ZLNET_ERROR_GETCFG_DST: return "��ȡ����ʱ����ʧ��";
		case ZLNET_ERROR_SETCFG_DST: return "��������ʱ����ʧ��";
		case ZLNET_ERROR_GETCFG_VIDEO_OSD: return "��ȡ��ƵOSD��������ʧ��";
		case ZLNET_ERROR_SETCFG_VIDEO_OSD: return "������ƵOSD��������ʧ��";
		case ZLNET_ERROR_GETCFG_GPRSCDMA: return "��ȡCDMA\GPRS��������ʧ��";
		case ZLNET_ERROR_SETCFG_GPRSCDMA: return "����CDMA\GPRS��������ʧ��";
		case ZLNET_ERROR_GETCFG_IPFILTER: return "��ȡIP��������ʧ��";
		case ZLNET_ERROR_SETCFG_IPFILTER: return "����IP��������ʧ��";
		case ZLNET_ERROR_GETCFG_TALKENCODE: return "��ȡ�����Խ���������ʧ��";
		case ZLNET_ERROR_SETCFG_TALKENCODE: return "���������Խ���������ʧ��";
		case ZLNET_ERROR_GETCFG_RECORDLEN: return "��ȡ¼������������ʧ��";
		case ZLNET_ERROR_SETCFG_RECORDLEN: return "����¼������������ʧ��";
		case ZLNET_DONT_SUPPORT_SUBAREA: return "��֧������Ӳ�̷���";
		case ZLNET_ERROR_GET_AUTOREGSERVER: return "��ȡ�豸������ע���������Ϣʧ��";
		case ZLNET_ERROR_CONTROL_AUTOREGISTER: return "����ע���ض���ע�����";
		case ZLNET_ERROR_DISCONNECT_AUTOREGISTER: return " �Ͽ�����ע�����������";
		case ZLNET_ERROR_GETCFG_MMS: return "��ȡmms����ʧ��";
		case ZLNET_ERROR_SETCFG_MMS: return "����mms����ʧ��";
		case ZLNET_ERROR_GETCFG_SMSACTIVATION: return "��ȡ���ż���������������ʧ��";
		case ZLNET_ERROR_SETCFG_SMSACTIVATION: return "���ö��ż���������������ʧ��";
		case ZLNET_ERROR_GETCFG_DIALINACTIVATION: return "��ȡ���ż���������������ʧ��";
		case ZLNET_ERROR_SETCFG_DIALINACTIVATION: return "���ò��ż���������������ʧ��";
		case ZLNET_ERROR_GETCFG_VIDEOOUT: return "��ѯ��Ƶ�����������ʧ��";
		case ZLNET_ERROR_SETCFG_VIDEOOUT: return "������Ƶ�����������ʧ��";
		case ZLNET_ERROR_GETCFG_OSDENABLE: return "��ȡosd����ʹ������ʧ��";
		case ZLNET_ERROR_SETCFG_OSDENABLE: return "����osd����ʹ������ʧ��";
		case ZLNET_ERROR_SETCFG_ENCODERINFO: return "��������ͨ��ǰ�˱����������ʧ��";
		case ZLNET_ERROR_GETCFG_TVADJUST: return "��ȡTV��������ʧ��";
		case ZLNET_ERROR_SETCFG_TVADJUST: return "����TV��������ʧ��";
		case ZLNET_ERROR_CONNECT_FAILED: return "����������ʧ��";
		case ZLNET_ERROR_SETCFG_BURNFILE: return "�����¼�ļ��ϴ�ʧ��";
		case ZLNET_ERROR_SNIFFER_GETCFG: return "��ȡץ��������Ϣʧ��";
		case ZLNET_ERROR_SNIFFER_SETCFG: return "����ץ��������Ϣʧ��";
		case ZLNET_ERROR_DOWNLOADRATE_GETCFG: return "��ѯ����������Ϣʧ��";
		case ZLNET_ERROR_DOWNLOADRATE_SETCFG: return "��������������Ϣʧ��";
		case ZLNET_ERROR_SEARCH_TRANSCOM: return "��ѯ���ڲ���ʧ��";
		case ZLNET_ERROR_GETCFG_POINT: return "��ȡԤ�Ƶ���Ϣ����";
		case ZLNET_ERROR_SETCFG_POINT: return "����Ԥ�Ƶ���Ϣ����";
		case ZLNET_SDK_LOGOUT_ERROR: return "SDKû�������ǳ��豸";
		case ZLNET_ERROR_GET_VEHICLE_CFG: return "��ȡ��������ʧ��";
		case ZLNET_ERROR_SET_VEHICLE_CFG: return "���ó�������ʧ��";
		case ZLNET_ERROR_GET_ATM_OVERLAY_CFG: return "��ȡatm��������ʧ��";
		case ZLNET_ERROR_SET_ATM_OVERLAY_CFG: return "����atm��������ʧ��";
		case ZLNET_ERROR_GET_ATM_OVERLAY_ABILITY: return "��ȡatm��������ʧ��";
		case ZLNET_ERROR_GET_DECODER_TOUR_CFG: return "��ȡ������������Ѳ����ʧ��";
		case ZLNET_ERROR_SET_DECODER_TOUR_CFG: return "���ý�����������Ѳ����ʧ��";
		case ZLNET_ERROR_CTRL_DECODER_TOUR: return "���ƽ�����������Ѳʧ��";
		case ZLNET_GROUP_OVERSUPPORTNUM: return "�����豸֧������û�����Ŀ";
		case ZLNET_USER_OVERSUPPORTNUM: return "�����豸֧������û���Ŀ";
		case ZLNET_ERROR_GET_SIP_CFG: return "��ȡSIP����ʧ��";
		case ZLNET_ERROR_SET_SIP_CFG: return "����SIP����ʧ��";
		case ZLNET_ERROR_GET_SIP_ABILITY: return "��ȡSIP����ʧ��";
		case ZLNET_TALK_REJECT: return "�ܾ��Խ�";
		case ZLNET_TALK_BUSY: return "��Դ��ͻ�����ܶԽ�";
		case ZLNET_TALK_FORMAT_NOT_SUPPORTED: return "�ܾ��Խ��������ʽ��֧��";
		case ZLNET_ERROR_UPSUPPORT_WAV: return "��֧�ֵ�WAV�ļ�";
		case ZLNET_ERROR_CHANGE_FORMAT_WAV: return "ת��WAV������ʧ��";
		case ZLNET_ERROR_PACKFRAME: return "���ʧ��";
		case ZLNET_ERROR_LATTICE_CFG: return "���õ�������ʧ��";
		default: return "δ֪����";
    }
}



CFactoryWSD::CFactoryWSD()
{
    init();
}

CFactoryWSD::~CFactoryWSD()
{
    clean();
}






bool CFactoryWSD::init()
{
    if (!m_init)
    {
		m_init = Api_WSD::Api().ZLNET_Init(NULL, 0);

        if (!m_init)
        {
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("��ʼ��SDKʧ�ܣ�����ԭ��") + m_sLastError);
		}

		g_log.AddLog(string("��ʼ��SDK�ɹ�"));
    }

    return m_init;
}


void CFactoryWSD::clean()
{
	Api_WSD::Api().ZLNET_Cleanup();
}




IVideoServer* CFactoryWSD::create()
{
    if (!init())
    {
        return nullptr;
    }

    return new WSD_videoserver();
}

// std::vector<WSD_videoserver*> WSD_videoserver::sServers;
// std::recursive_mutex WSD_videoserver::sMtServers;

/*
 * ��������
 */
WSD_videoserver::WSD_videoserver()
{
//     std::lock_guard<std::recursive_mutex> lock(WSD_videoserver::sMtServers);
//     sServers.push_back(this);
}

WSD_videoserver::~WSD_videoserver()
{
    logout();
//     std::lock_guard<std::recursive_mutex> lock(WSD_videoserver::sMtServers);
//     for (int i = 0; i < sServers.size(); i++)
//     {
//         if (sServers[i] == this)
//         {
//             sServers.erase(sServers.begin() + i);
//             break;
//         }
//     }
}

void CALLBACK PosCallBack(LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, DWORD dwUser)
{
	WSD_videoserver * pThis = (WSD_videoserver *)dwUser;
	{
		Mutex::ScopedLock lock(pThis->m_mtxPos);
		map<long long, stPos_DownPlay>::iterator itr = pThis->m_mapPosDownPlay.find(lPlayHandle);
		if (itr != pThis->m_mapPosDownPlay.end())
		{
			itr->second.iTotalSize = dwTotalSize*1024;
			itr->second.iCurSize = dwDownLoadSize*1024;
			itr->second.iPercent = ((float)dwTotalSize / (float)dwDownLoadSize) * 100;
		}
	}
}

IVideoServer* WSD_videoserver::clone()
{
	return nullptr;
// 	WSD_videoserver *svr = new WSD_videoserver();
// 	memcpy(svr, this, sizeof(WSD_videoserver));
//     return svr;
}

bool WSD_videoserver::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string>& channels)
{
//     if (0 < m_lLoginHandle && !logout())
// 	{
// 		g_log.AddLog(string("login �豸�ѵ�¼�����Է���½ʧ��"));
//         return false;
//     }
	char addThis[32] = { 0 };
	sprintf(addThis, "this:%d", this);
	g_log.AddLog(string("WSD_videoserver::login ") + addThis);
	channels.clear();
    memset(&m_deviceInfo, 0, sizeof(m_deviceInfo));

	int iError = 0;
	m_lLoginHandle = Api_WSD::Api().ZLNET_Login((char *)IP, port, (char *)user, (char *)password, &m_deviceInfo, &iError);

    if (m_lLoginHandle == 0)
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("login ��¼ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

	char logInfo[128] = { 0 };
	sprintf_s(logInfo, "byChanNum:%d, deviceTye:%d, m_lLoginHandle:%d", m_deviceInfo.byChanNum, m_deviceInfo.byDVRType, m_lLoginHandle);
	g_log.AddLog(string(logInfo));

	for (int i = 0; i < m_deviceInfo.byChanNum; i++)
	{
		char chname[16] = { 0 };
		sprintf_s(chname, "ͨ��%d", i+1);
		channels.insert(std::make_pair(i, chname));
	}

    return true;
}

bool WSD_videoserver::logout()
{
	char addThis[32] = { 0 };
	sprintf(addThis, "this:%d", this);
	g_log.AddLog(string("WSD_videoserver::logout ") + addThis);

    if (m_lLoginHandle > 0 && !Api_WSD::Api().ZLNET_Logout(m_lLoginHandle))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }

    return true;
}

static void timeWSDToStd(WSD::ZLNET_TIME *pTimeDH, tm *pTimeStd)
{
	pTimeStd->tm_year = pTimeDH->dwYear - 1900;
	pTimeStd->tm_mon = pTimeDH->dwMonth - 1;
	pTimeStd->tm_mday = pTimeDH->dwDay;
	pTimeStd->tm_hour = pTimeDH->dwHour;
	pTimeStd->tm_min = pTimeDH->dwMinute;
	pTimeStd->tm_sec = pTimeDH->dwSecond;
}

static void timeStdToWSD(tm *pTimeStd, WSD::ZLNET_TIME *pTimeDH)
{
	pTimeDH->dwDay = pTimeStd->tm_year + 1900;
	pTimeDH->dwMonth = pTimeStd->tm_mon + 1;
	pTimeDH->dwDay = pTimeStd->tm_mday;
	pTimeDH->dwHour = pTimeStd->tm_hour;
	pTimeDH->dwMinute = pTimeStd->tm_min;
	pTimeDH->dwSecond = pTimeStd->tm_sec;
}

static void timeWSDToStd2(WSD::ZLNET_TIME *pTimeDH, tm *pTimeStd)
{
	pTimeStd->tm_year = pTimeDH->dwYear - 1900;
	pTimeStd->tm_mon = pTimeDH->dwMonth - 1;
	pTimeStd->tm_mday = pTimeDH->dwDay;
	pTimeStd->tm_hour = pTimeDH->dwHour;
	pTimeStd->tm_min = pTimeDH->dwMinute;
	pTimeStd->tm_sec = pTimeDH->dwSecond;
}

static void timeStdToWSD2(tm *pTimeStd, WSD::ZLNET_TIME *pTimeDH)
{
	pTimeDH->dwYear = pTimeStd->tm_year + 1900;
	pTimeDH->dwMonth = pTimeStd->tm_mon + 1;
	pTimeDH->dwDay = pTimeStd->tm_mday;
	pTimeDH->dwHour = pTimeStd->tm_hour;
	pTimeDH->dwMinute = pTimeStd->tm_min;
	pTimeDH->dwSecond = pTimeStd->tm_sec;
}

#define MAX_SEARCH_COUNT 1000
bool WSD_videoserver::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart, __time64_t timeEnd)
{
	char addThis[32] = { 0 };
	sprintf(addThis, "this:%d", this);
	g_log.AddLog(string("WSD_videoserver::GetRecordFileList ") + addThis);

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

	WSD::ZLNET_TIME stime;
	WSD::ZLNET_TIME etime;

	tm STime;
	tm ETime;
	_localtime64_s(&STime, (const time_t*)&timeStart);
	_localtime64_s(&ETime, (const time_t*)&timeEnd);

	timeStdToWSD2(&STime, &stime);
	timeStdToWSD2(&ETime, &etime);
	char szTime[512];
	ZeroMemory(szTime, 512);
	sprintf(szTime, " s_time:%d-%02d-%02d %02d:%02d:%02d e_time:%d-%02d-%02d %02d:%02d:%02d linkID:%d", stime.dwYear, stime.dwMonth, stime.dwDay,
		stime.dwHour, stime.dwMinute, stime.dwSecond,
		etime.dwYear, etime.dwMonth, etime.dwDay, etime.dwHour, etime.dwMinute, etime.dwSecond, m_lLoginHandle);
	g_log.AddLog(string("GetRecordFileList ") + string(szTime));

	char szTime64_s[64];
	ZeroMemory(szTime64_s, 64);
	char szTime64_e[64];
	ZeroMemory(szTime64_e, 64);
	_i64toa(timeStart, szTime64_s, 10);
	_i64toa(timeEnd, szTime64_e, 10);
	//m_mapArcItem.clear();
	g_log.AddLog(string("time64 s_time:") + string(szTime64_s) + string(" e_time:") + string(szTime64_e));

	int iMaxNum = 0;
	__int32 nChannelId = 0;
	for (int ch = 0; ch < channelVec.size(); ch++)
	{
		nChannelId = channelVec[ch];
		LONG searchHandle = Api_WSD::Api().ZLNET_FindFile(m_lLoginHandle, nChannelId, 0, NULL, &stime, &etime, FALSE, 2000);
		if (searchHandle == 0)
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("GetRecordFileList ��ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
			/*return false*/;
			continue;
		}
	
		int getRet = -1;
		RecordFile info;
		tm sTm;
		tm eTm;
		char szFileName[MAX_PATH];
		while(1)
		{
			WSD::ZLNET_RECORDFILE_INFO findInfo = { 0 };
			getRet = Api_WSD::Api().ZLNET_FindNextFile(searchHandle, &findInfo);
			if (getRet == 0)
			{
				Api_WSD::Api().ZLNET_FindClose(searchHandle);
				break;
			}

// 			Mutex::ScopedLock lock(m_mtx);
// 
// 			ZeroMemory(szFileName, sizeof(szFileName));
// 			sprintf(szFileName, "ch%d%04d%02d%02d-%02d%02d%02d--%04d%02d%02d-%02d%02d%02d", nChannelId,
// 					findInfo.starttime.dwYear, findInfo.starttime.dwMonth, findInfo.starttime.dwDay,
// 					findInfo.starttime.dwHour, findInfo.starttime.dwMinute, findInfo.starttime.dwSecond,
// 					findInfo.endtime.dwYear, findInfo.endtime.dwMonth, findInfo.endtime.dwDay, 
// 					findInfo.endtime.dwHour, findInfo.endtime.dwMinute, findInfo.endtime.dwSecond);
// 			WSD::ZLNET_RECORDFILE_INFO * pFileInfo = new WSD::ZLNET_RECORDFILE_INFO;
// 			memset(pFileInfo, 0, sizeof(WSD::ZLNET_RECORDFILE_INFO));
// 			memcpy(pFileInfo, &findInfo, sizeof(WSD::ZLNET_RECORDFILE_INFO));
// 			sprintf(pFileInfo->filename, "channel%02d", nChannelId+1);
// 			m_mapArcItem.insert(make_pair(string(szFileName), pFileInfo));

			timeWSDToStd(&findInfo.starttime, &sTm);
			timeWSDToStd(&findInfo.endtime, &eTm);

			info.channel = findInfo.ch;
			info.size = findInfo.size*1024;
			/*info.name = szFileName;*/
			info.name = findInfo.filename;
			info.beginTime = mktime(&sTm);
			info.endTime = mktime(&eTm);
			info.setPrivateData(&findInfo, sizeof(WSD::ZLNET_RECORDFILE_INFO));
			files.push_back(info);
		}
	}
	return true;
}


bool WSD_videoserver::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
	char addThis[32] = { 0 };
	sprintf(addThis, "this:%d", this);
	g_log.AddLog(string("WSD_videoserver::downLoadByRecordFile ") + addThis);

    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("downLoadByRecordFile ���ȵ�¼"));
        return false;
    }

// 	int size = m_mapArcItem.size();
// 	char csize[8] = { 0 };
// 	sprintf_s(csize, "size:%d,", size);
// 	g_log.AddLog(file.name+ csize);

// 	map<string, WSD::ZLNET_RECORDFILE_INFO*>::iterator itr = m_mapArcItem.begin();
// 	for (; itr != m_mapArcItem.end(); itr++)
// 	{
// 		g_log.AddLog(itr->first);
// 	}

// 	WSD::ZLNET_RECORDFILE_INFO info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, WSD::ZLNET_RECORDFILE_INFO*>::iterator itr = m_mapArcItem.find(file.name);
// 		if (itr == m_mapArcItem.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			g_log.AddLog(string("[1]downLoadByRecordFile ���ļ�������"));
// 			return false;
// 		}
// 
// 		memcpy(&info, itr->second, sizeof(WSD::ZLNET_RECORDFILE_INFO));
// 	}

// 	char szFileName[256] = { 0 };
// 	sprintf(szFileName, "%04d%02d%02d-%02d%02d%02d--%04d%02d%02d-%02d%02d%02d",
// 		info.starttime.dwYear, info.starttime.dwMonth, info.starttime.dwDay,
// 		info.starttime.dwHour, info.starttime.dwMinute, info.starttime.dwSecond,
// 		info.endtime.dwYear, info.endtime.dwMonth, info.endtime.dwDay,
// 		info.endtime.dwHour, info.endtime.dwMinute, info.endtime.dwSecond);
// 	g_log.AddLog(string(szFileName));
// 	char tch[256] = { 0 };
// 	sprintf_s(tch, "ch:%d,name:%s,sz:%d,dr:%d,st:%d,nr:%d,bi%d,bh%d,br%d", info.ch,info.filename,info.size,info.driveno,info.startcluster,info.nRecordFileType,info.bImportantRecID,info.bHint,info.bReserved);
// 	g_log.AddLog(string(tch));
// 	g_log.AddLog(string("downLoadByRecordFile �ļ�����") + saveFileName);

	WSD::ZLNET_RECORDFILE_INFO* pData = (WSD::ZLNET_RECORDFILE_INFO*)file.getPrivateData();

	hdl = Api_WSD::Api().ZLNET_DownloadByRecordFile(m_lLoginHandle, pData, (char *)saveFileName, PosCallBack, (DWORD)this);
	if (hdl == 0)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("downLoadByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}

	{
		Mutex::ScopedLock lock(m_mtx);
		m_mapDownloadOrPlay.insert(std::make_pair(hdl, file));
	}
	{
		stPos_DownPlay pos;
		pos.iTotalSize = pData->size * 1024;
		pos.iCurSize = 0;
		pos.iPercent = 0;
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.insert(std::make_pair(hdl, pos));
	}

	return true;
}


bool  WSD_videoserver::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (0 >= m_lLoginHandle)
    {
        m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("PlayBackByRecordFile ���ȵ�¼"));
        return false;
	}

// 	WSD::ZLNET_RECORDFILE_INFO info;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<string, WSD::ZLNET_RECORDFILE_INFO*>::iterator itr = m_mapArcItem.find(file.name);
// 		if (itr == m_mapArcItem.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			g_log.AddLog(string("PlayBackByRecordFile ���ļ�������"));
// 			return false;
// 		}
// 
// 		memcpy(&info, itr->second, sizeof(WSD::ZLNET_RECORDFILE_INFO));
// 	}

	WSD::ZLNET_RECORDFILE_INFO* pData = (WSD::ZLNET_RECORDFILE_INFO*)file.getPrivateData();
	playbackHandle = Api_WSD::Api().ZLNET_PlayBackByRecordFile(m_lLoginHandle, pData, hwnd, PosCallBack, (DWORD)this);
	if (playbackHandle == 0)
	{
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("PlayBackByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}

	{
		Mutex::ScopedLock lock(m_mtx);
		m_mapDownloadOrPlay.insert(std::make_pair(playbackHandle, file));
	}
	{
		stPos_DownPlay pos;
		pos.iTotalSize = 1;
		pos.iCurSize = 0;
		pos.iPercent = 0;
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.insert(std::make_pair(playbackHandle, pos));
	}

	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "PlayBackByRecordFile start playbackHandle:%d", playbackHandle);
	//g_log.AddLog(string("StopPlayBack ��ʼֹͣ����"));
	g_log.AddLog(string(szLog));
	return true;
}

bool WSD_videoserver::SetPlayBack(__int64 playbackHandle, __int32 pos)
{
// 	RecordFile file;
// 	{
// 		Mutex::ScopedLock lock(m_mtx);
// 		map<long long, RecordFile>::iterator itr = m_mapDownloadOrPlay.find(playbackHandle);
// 		if (itr == m_mapDownloadOrPlay.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			g_log.AddLog(string("SetPlayBack ���ļ�������"));
// 			return false;
// 		}
// 		file = itr->second;
// 	}
// 	return FALSE != Api_WSD::Api().m_pPlayBackControl(playbackHandle, WSD::SDK_PLAY_BACK_SEEK_PERCENT, pos);
	return true;
}

bool WSD_videoserver::StopPlayBack(__int64 playbackHandle, __int32 mPause)
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
		if (!Api_WSD::Api().ZLNET_StopPlayBack(playbackHandle))
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
		//g_log.AddLog(string("StopPlayBack ��ʼֹͣ����"));
		g_log.AddLog(string(szLog));

		{
			Mutex::ScopedLock lock(m_mtx);
			m_mapDownloadOrPlay.erase(playbackHandle);
		}
		{
			Mutex::ScopedLock lock(m_mtxPos);
			m_mapPosDownPlay.erase(playbackHandle);
		}
		if (!Api_WSD::Api().ZLNET_StopPlayBack(playbackHandle))
		{
			m_sLastError = GetLastErrorString();
			g_log.AddLog(string("StopPlayBack ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
		}
	}

    return true;
}

bool WSD_videoserver::stopDownload(download_handle_t h)
{
	g_log.AddLog(string("stopDownload ��ʼֹͣ����"));
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("stopDownload ���ȵ�¼"));
        return false;
	}

	{
		Mutex::ScopedLock lock(m_mtx);
		m_mapDownloadOrPlay.erase(h);
	}
	{
		Mutex::ScopedLock lock(m_mtxPos);
		m_mapPosDownPlay.erase(h);
	}

	if (FALSE == Api_WSD::Api().ZLNET_StopDownload(h))
    {
		m_sLastError = GetLastErrorString();
		g_log.AddLog(string("stopDownload ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }

    return true;
}

bool WSD_videoserver::getPlayBackPos(__int64 playbackHandle, __int32* pos)
{
// 	if (0 >= m_lLoginHandle)
// 	{
// 		m_sLastError = "���ȵ�¼!";
// 		g_log.AddLog(string("getPlayBackPos ���ȵ�¼"));
// 		return false;
// 	}
// 
// 	Mutex::ScopedLock lock(m_mtxPos);
// 	map<long long, stPos_DownPlay>::iterator itr = m_mapPosDownPlay.find(playbackHandle);
// 	if (itr != m_mapPosDownPlay.end())
// 	{
// 		*pos = itr->second.iPercent;
// 		return true;
// 	}
// 	m_sLastError = "�Ҳ����ûط�";
// 	g_log.AddLog(string("getPlayBackPos �Ҳ����ûط�"));
	return false;
}

bool WSD_videoserver::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
{
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼!";
		g_log.AddLog(string("getDownloadPos ���ȵ�¼"));
		return false;
	}

	Mutex::ScopedLock lock(m_mtxPos);
	map<long long, stPos_DownPlay>::iterator itr = m_mapPosDownPlay.find(h);
	if (itr != m_mapPosDownPlay.end())
	{
		*totalSize = itr->second.iTotalSize;
		*currentSize = itr->second.iCurSize;

		*failed = false;
		return true;
	}
	m_sLastError = "�Ҳ���������";
	g_log.AddLog(string("getDownloadPos �Ҳ���������"));
	*failed = true;
	return false;
}