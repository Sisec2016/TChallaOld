#include "BaoXinShengVideoServer.h"
#include <iostream>

#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"
#include <thread>
#include <QFile>
#include <qdebug.h>
Log hk_log("BaoXinShengVideoServer");

extern "C" VIDEOSERVER_EXPORT IVideoServerFactory* VideoServerFactory()
{

    return new CFactory();
}


std::string GetLastErrorString()
{
    LONG error = ZLNET_GetLastError();
    switch (error)
    {
    case ZLNET_NOERROR: return "û�д���";
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
    case ZLNET_MULTIPLAY_NOCHANNEL: return "�໭��Ԥ���м�⵽ͨ����Ϊ";
    case ZLNET_TALK_INIT_ERROR: return "¼�����ʼ��ʧ��";
    case ZLNET_TALK_NOT_INIT: return "¼����δ����ʼ��";
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
    case ZLNET_ERROR_SETCFG_RECORD: return "�޸�¼������ʧ��";
    case ZLNET_ERROR_SETCFG_485DECODER: return "�޸Ľ���������ʧ��";
    case ZLNET_ERROR_SETCFG_232COM: return "�޸�232��������ʧ��";
    case ZLNET_ERROR_SETCFG_ALARMIN: return "�޸��ⲿ���뱨������ʧ��";
    case ZLNET_ERROR_SETCFG_ALARMDET: return "�޸Ķ�̬��ⱨ������ʧ��";
    case ZLNET_ERROR_SETCFG_SYSTIME: return "�޸��豸ʱ��ʧ��";
    case ZLNET_ERROR_SETCFG_PREVIEW: return "�޸�Ԥ������ʧ��";
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
    case ZLNET_RENDER_SNAP_ERROR: return " Render��ץͼ����";
    case ZLNET_RENDER_STEP_ERROR: return "Render";
    case ZLNET_RENDER_FRAMERATE_ERROR: return "Render������֡�ʳ���";
    case ZLNET_GROUP_EXIST: return "�����Ѵ���";
    case ZLNET_GROUP_RIGHTOVER: return "���Ȩ�޳���Ȩ���б�Χ";
    case ZLNET_GROUP_HAVEUSER: return "�������û�������ɾ��";
    case ZLNET_GROUP_RIGHTUSE: return "���ĳ��Ȩ�ޱ��û�ʹ�ã����ܳ���";
    case ZLNET_GROUP_SAMENAME: return "������ͬ���������ظ�";
    case ZLNET_USER_EXIST: return "�û��Ѵ���";
    case ZLNET_USER_NOEXIST: return " �û�������";
    case ZLNET_USER_RIGHTOVER: return " �û�Ȩ�޳�����Ȩ��";
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
        case ZLNET_ERROR_GETCFG_GPRSCDMA: return " ��ȡCDMA\GPRS��������ʧ��";
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
        case ZLNET_ERROR_DISCONNECT_AUTOREGISTER: return "�Ͽ�����ע�����������";
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

    }

    return "δ֪����";
}



CFactory::CFactory()
{
    init();
}

CFactory::~CFactory()
{
    clean();
}



void CALLBACK DisConnectFunc(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
    if (dwUser == 0)
    {
        return;
    }
    BaoXinShengVideoServer* psvr = (BaoXinShengVideoServer*)dwUser;
    psvr->reallogout();
    psvr->reLogin();
}


bool CFactory::init()
{

    if (!m_init)
    {

        m_init = ZLNET_Init(DisConnectFunc, (DWORD)this);
        if (!m_init)
        {

           m_sLastError = GetLastErrorString();
           hk_log.AddLog(std::string("init failed:") + m_sLastError);
        }


    }

    return m_init;
}


void CFactory::clean()
{
    ZLNET_Cleanup();
    m_init = false;
}




IVideoServer* CFactory::create()
{
    if (!init())
    {
        return nullptr;
    }

    return new BaoXinShengVideoServer();
}
__int64 DownloadPosCaculator::getFileSize(const std::string& sFile)
{
    QFile f(QString::fromLocal8Bit(sFile.c_str()));
    if (f.exists())
    {
        return f.size();
    }
    else
    {
        return 0;
    }
}
DownloadPosCaculator::DownloadPosCaculator()
{
    mTotalSize = 0;
    mLastSize = 0;
    mLittleTimes = 0;
    mMaybeFinish = false;
}

int DownloadPosCaculator::getPos(__int64& totalSize, __int64& currentSize)
{
    currentSize = getFileSize(mSaveFile);
    mMaybeFinish = true;
    if (!mMaybeFinish)
    {
        mMaybeFinish = (mLastSize == currentSize && mLastSize > 1024 * 1024);
        if (currentSize - mLastSize <= 13 * 1024 * 3 && mLastSize > 1024 * 1024)
        {
            mLittleTimes++;
        }
        if (!mMaybeFinish)
        {
            mMaybeFinish = (mLittleTimes > 100);
        }
    }
    
    mLastSize = currentSize;
    totalSize = mTotalSize;
    if (totalSize > 0 && totalSize >= currentSize)
    {
        return currentSize * 100 / totalSize;
    }

    return 100;
}

std::vector<BaoXinShengVideoServer*> BaoXinShengVideoServer::sServers;
std::recursive_mutex BaoXinShengVideoServer::sMtServers;

/*
 * ��������
 */
BaoXinShengVideoServer::BaoXinShengVideoServer()
{
    std::lock_guard<std::recursive_mutex> lock(BaoXinShengVideoServer::sMtServers);
    sServers.push_back(this);
    m_pPlayFile = nullptr;
    m_lLoginHandle = NULL;
}

BaoXinShengVideoServer::~BaoXinShengVideoServer()
{

    logout();
    hk_log.AddLog(std::string("BaoXinShengVideoServer::~BaoXinShengVideoServer()"));
    std::lock_guard<std::recursive_mutex> lock(BaoXinShengVideoServer::sMtServers);
    for (int i = 0; i < sServers.size(); i++)
    {
        if (sServers[i] == this)
        {
            sServers.erase(sServers.begin() + i);
            break;
        }
    }
    
}

IVideoServer* BaoXinShengVideoServer::clone()
{
    BaoXinShengVideoServer *svr = new BaoXinShengVideoServer();
    return svr;
}

bool BaoXinShengVideoServer::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string>& channels)
{
    if (mIP == IP && port == mPort && m_lLoginHandle > 0)
    {
        return true;
    }
    else{
        this->reallogout();
    }

	channels.clear();
    memset(&m_deviceInfo, 0, sizeof(m_deviceInfo));
    int err;
    m_lLoginHandle = ZLNET_Login((char*)IP, port,
                                   (char*)user,(char*)password,
                                   &m_deviceInfo, &err);
    if (m_lLoginHandle <= 0)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("ZLNET_Login failed:") + m_sLastError);
        return false;
    }
    mUser = user;
    mIP = IP;
    mPasswords = password;
    mPort = port;
    for (int i = 0; i < m_deviceInfo.byChanNum; i++)
    {
        channels[i + 1] = QString("channel%1").arg(i + 1).toStdString();
    }
    return true;
}
bool BaoXinShengVideoServer::reallogout()
{
    if (m_lLoginHandle >= 0 && !ZLNET_Logout(m_lLoginHandle))
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("logout failed:") + m_sLastError);
        return false;
    }
    else {
        hk_log.AddLog(std::string("BaoXinShengVideoServerlogout ok!"));
        m_lLoginHandle = 0;
    }

    return true;
}

bool BaoXinShengVideoServer::reLogin(){
    int err;
    m_lLoginHandle = ZLNET_Login((char*)mIP.c_str(), mPort,
        (char*)mUser.c_str(), (char*)mPasswords.c_str(),
        &m_deviceInfo, &err);
    if (m_lLoginHandle <= 0)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("ZLNET_Login failed:") + m_sLastError);
        return false;
    }
    
    return true;
}

bool BaoXinShengVideoServer::logout()
{
    return true;

}
void NetTimeTo(const ZLNET_TIME& nt, __time64_t& t)
{
    struct tm Tm;
    Tm.tm_year = nt.dwYear - 1900;
    Tm.tm_mon = nt.dwMonth - 1;
    Tm.tm_mday = nt.dwDay;
    Tm.tm_hour = nt.dwHour;
    Tm.tm_min = nt.dwMinute;
    Tm.tm_sec = nt.dwSecond;

    t = _mktime64(&Tm);
}

void ToNetTime(const __time64_t& t, ZLNET_TIME& nt)
{
    struct tm Tm;
    _localtime64_s(&Tm, (const time_t*)&t);
    nt.dwYear = Tm.tm_year + 1900;
    nt.dwMonth = Tm.tm_mon + 1;
    nt.dwDay = Tm.tm_mday;
    nt.dwHour = Tm.tm_hour;
    nt.dwMinute = Tm.tm_min;
    nt.dwSecond = Tm.tm_sec;
}
bool BaoXinShengVideoServer::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart,
                                                       __time64_t timeEnd)
{
    const int BYTE_ONE_SECONDS = 234947;
    if (m_lLoginHandle <= 0)
    {
        m_sLastError = "���ȵ�¼!";
        hk_log.AddLog(std::string("GetRecordFileList failed:") + m_sLastError);
        return false;
    }

    if (timeStart >= timeEnd)
    {
        m_sLastError = "ʱ�䷶Χ����!";
        hk_log.AddLog(std::string("GetRecordFileList failed:") + m_sLastError);
        return false;
    }


    ZLNET_TIME stime, etime;
    ToNetTime(timeStart, stime);
    ToNetTime(timeEnd,etime);
    //stFileCond.dwChannelID = m_lChannelID;
    LPVOID dwFileHandle = 0;


    auto itr = channelVec.begin();
    RecordFile rf;
    for (; itr != channelVec.end(); itr++)
    {
        int nChannelId = *itr;

        BOOL dwFileHandle = ZLNET_FindFile(m_lLoginHandle,
            nChannelId - 1,
            0,
            (char*)"",
            &stime,
            &etime,
            false,
            2000);
        if (NULL != dwFileHandle)
        {
            ZLNET_RECORDFILE_INFO stVodFile = { 0 };
            hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
            while (ZLNET_FindNextFile(dwFileHandle, &stVodFile))
            {

                hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
                NetTimeTo(stVodFile.starttime, rf.beginTime);
                NetTimeTo(stVodFile.endtime, rf.endTime);

                rf.channel = nChannelId;
                rf.name = stVodFile.filename;
                rf.size = stVodFile.size * 1024;

                rf.setPrivateData(&stVodFile, sizeof(ZLNET_RECORDFILE_INFO));
                files.push_back(rf);
            }

            hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
            ZLNET_FindClose(dwFileHandle);
            hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
        }

        hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
    }

    hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
   return true;
}

void CALLBACK BTDownLoadPos(LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, ZLNET_RECORDFILE_INFO recordfileinfo, DWORD dwUser)
{
    BaoXinShengVideoServer* svr = (BaoXinShengVideoServer *)dwUser;

    svr->UpdateDownloadPos(lPlayHandle, dwTotalSize, dwDownLoadSize, index, recordfileinfo);
}
//�������ؽ���
void BaoXinShengVideoServer::UpdateDownloadPos(LONG iHandle, DWORD dwTotal, DWORD dwDownload, int index, ZLNET_RECORDFILE_INFO recordfileinfo)
{
}

bool BaoXinShengVideoServer::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
    if (m_lLoginHandle <= 0)
    {
        m_sLastError = "���ȵ�¼!";
        hk_log.AddLog("downLoadByRecordFile ���ȵ�¼!");
        return false;
    }

    ZLNET_TIME stime, etime;
    ToNetTime(file.beginTime, stime);
    ToNetTime(file.endTime, etime);
    hdl = (download_handle_t)ZLNET_DownloadByTime(m_lLoginHandle, file.channel - 1, 0, &stime, &etime, (char *)saveFileName, BTDownLoadPos,
                (DWORD)this);
    if (NULL == hdl)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("ZLNET_GetFileByTime failed:") + m_sLastError + " �ļ���" + saveFileName);
        return false;
    }
//     int enSpeed = ZLNET_DOWNLOAD_SPEED_EIGHT;
//     int bRet = ZLNET_PlayBackControl(hdl, ZLNET_PLAY_CTRL_SETPLAYSPEED, &enSpeed);

    QString qsFile(QString::fromLocal8Bit(saveFileName));
    QFile::remove(qsFile);

    mMpDownloadRecords[hdl] = file;
    return true;
}

void CALLBACK PlayCallBack(LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, DWORD dwUser)
{
    if (dwUser == 0)
    {
        return;
    }

}

bool  BaoXinShengVideoServer::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (m_lLoginHandle <= 0)
    {
        m_sLastError = "���ȵ�¼!";
        return false;
    }
    ZLNET_TIME stime, etime;
    ToNetTime(file.beginTime, stime);
    ToNetTime(file.endTime, etime);
    playbackHandle = ZLNET_PlayBackByTime(m_lLoginHandle, file.channel - 1, &stime, &etime, hwnd, PlayCallBack, (DWORD)this);
    if (NULL == playbackHandle)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NET_DVR_PlayBackControl failed:") + m_sLastError);
        return false;
    }

    m_pPlayFile = &file;
    return true;
}

bool BaoXinShengVideoServer::SetPlayBack(play_handle_t playbackHandle, __int32 pos)
{
    if (m_lLoginHandle <= 0)
    {
        m_sLastError = "���ȵ�¼!";
        return false;
    }

    BOOL bRet = ZLNET_SeekPlayBack(playbackHandle, (m_pPlayFile->endTime - m_pPlayFile->beginTime) * pos / 100, 0xffffffff);
    if (!bRet)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("ZLNET_SeekPlayBack failed:") + m_sLastError);
        return false;
    }

    return true;
}

bool BaoXinShengVideoServer::StopPlayBack(download_handle_t playbackHandle, __int32 mPause)
{
    if (m_lLoginHandle <= 0)
    {
        m_sLastError = "���ȵ�¼!";
        return false;
    }

    int bRet = ZLNET_StopPlayBack(playbackHandle);
    if (TRUE != bRet)
    {
        m_sLastError = GetLastErrorString();
        return false;
        
    }

    return true;
}



bool BaoXinShengVideoServer::stopDownload(download_handle_t h)
{

    if (TRUE != ZLNET_StopDownload(h))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }
    
    mMpDownloadRecords.erase(h);
    return true;
}


bool BaoXinShengVideoServer::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed){
    
    return false;
}