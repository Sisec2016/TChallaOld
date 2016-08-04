#include "haik_videoserver.h"
#include <iostream>

#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"
#include <thread>
#include <QFile>
#include <qdebug.h>
Log hk_log("haik_videoserver");

extern "C" VIDEOSERVER_EXPORT IVideoServerFactory* VideoServerFactory()
{

    return new CFactory();
}

std::string GetLastErrorString()
{
    LONG error;
    std::string sError = NET_DVR_GetErrorMsg(&error);

    switch (error)
    {
        case NET_DVR_NOERROR: return "NOERROR";
        case NET_DVR_PASSWORD_ERROR: return "�û����������";
        case NET_DVR_NOENOUGHPRI: return "Ȩ�޲���";
        case NET_DVR_NOINIT: return "û�г�ʼ��";
        case NET_DVR_CHANNEL_ERROR: return "ͨ���Ŵ���";
        case NET_DVR_OVER_MAXLINK: return "���ӵ�DVR�Ŀͻ��˸����������";
        case NET_DVR_VERSIONNOMATCH: return "�汾��ƥ��";
        case NET_DVR_NETWORK_FAIL_CONNECT: return "���ӷ�����ʧ��";
        case NET_DVR_NETWORK_SEND_ERROR: return "�����������ʧ��";
        case NET_DVR_NETWORK_RECV_ERROR: return "�ӷ�������������ʧ��";
        case NET_DVR_NETWORK_RECV_TIMEOUT: return "�ӷ������������ݳ�ʱ";
        case NET_DVR_NETWORK_ERRORDATA: return "���͵���������";
        case NET_DVR_ORDER_ERROR: return "���ô������";
        case NET_DVR_OPERNOPERMIT: return "�޴�Ȩ��";
        case NET_DVR_COMMANDTIMEOUT: return "DVR����ִ�г�ʱ";
        case NET_DVR_ERRORSERIALPORT: return "���ںŴ���";
        case NET_DVR_ERRORALARMPORT: return "�����˿ڴ���";
        case NET_DVR_PARAMETER_ERROR: return "��������";
        case NET_DVR_CHAN_EXCEPTION: return "������ͨ�����ڴ���״̬";
        case NET_DVR_NODISK: return "û��Ӳ��";
        case NET_DVR_ERRORDISKNUM: return "Ӳ�̺Ŵ���";
        case NET_DVR_DISK_FULL: return "������Ӳ����";
        case NET_DVR_DISK_ERROR: return "������Ӳ�̳���";
        case NET_DVR_NOSUPPORT: return "��������֧��";
        case NET_DVR_BUSY: return "������æ";
        case NET_DVR_MODIFY_FAIL: return "�������޸Ĳ��ɹ�";
        case NET_DVR_PASSWORD_FORMAT_ERROR: return "���������ʽ����ȷ";
        case NET_DVR_DISK_FORMATING: return "Ӳ�����ڸ�ʽ����������������";
        case NET_DVR_DVRNORESOURCE: return "DVR��Դ����";
        case NET_DVR_DVROPRATEFAILED: return "DVR����ʧ��";
        case NET_DVR_OPENHOSTSOUND_FAIL: return "��PC����ʧ��";
        case NET_DVR_DVRVOICEOPENED: return "�����������Խ���ռ��";
        case NET_DVR_TIMEINPUTERROR: return "ʱ�����벻��ȷ";
        case NET_DVR_NOSPECFILE: return "�ط�ʱ������û��ָ�����ļ�";
        case NET_DVR_CREATEFILE_ERROR: return "�����ļ�����";
        case NET_DVR_FILEOPENFAIL: return "���ļ�����";
        case NET_DVR_OPERNOTFINISH: return "�ϴεĲ�����û�����";
        case NET_DVR_GETPLAYTIMEFAIL: return "��ȡ��ǰ���ŵ�ʱ�����";
        case NET_DVR_PLAYFAIL: return "���ų���";
        case NET_DVR_FILEFORMAT_ERROR: return "�ļ���ʽ����ȷ";
        case NET_DVR_DIR_ERROR: return "·������";
        case NET_DVR_ALLOC_RESOURCE_ERROR: return "��Դ�������";
        case NET_DVR_AUDIO_MODE_ERROR: return "����ģʽ����";
        case NET_DVR_NOENOUGH_BUF: return "������̫С";
        case NET_DVR_CREATESOCKET_ERROR: return "����SOCKET����";
        case NET_DVR_SETSOCKET_ERROR: return "����SOCKET����";
        case NET_DVR_MAX_NUM: return "�����ﵽ���";
        case NET_DVR_USERNOTEXIST: return "�û�������";
        case NET_DVR_WRITEFLASHERROR: return "дFLASH����";
        case NET_DVR_UPGRADEFAIL: return "DVR����ʧ��";
        case NET_DVR_CARDHAVEINIT: return "���뿨�Ѿ���ʼ����";
        case NET_DVR_PLAYERFAILED: return "���ò��ſ���ĳ������ʧ��";
        case NET_DVR_MAX_USERNUM: return "�豸���û����ﵽ���";
        case NET_DVR_GETLOCALIPANDMACFAIL: return "��ÿͻ��˵�IP��ַ�������ַʧ��";
        case NET_DVR_NOENCODEING: return "��ͨ��û�б���";
        case NET_DVR_IPMISMATCH: return "IP��ַ��ƥ��";
        case NET_DVR_MACMISMATCH: return "MAC��ַ��ƥ��";
        case NET_DVR_UPGRADELANGMISMATCH: return "�����ļ����Բ�ƥ��";
        case NET_DVR_MAX_PLAYERPORT: return "������·���ﵽ���";
        case NET_DVR_NOSPACEBACKUP: return "�����豸��û���㹻�ռ���б���";
        case NET_DVR_NODEVICEBACKUP: return "û���ҵ�ָ���ı����豸";
        case NET_DVR_PICTURE_BITS_ERROR: return "ͼ����λ����������24ɫ";
        case NET_DVR_PICTURE_DIMENSION_ERROR: return "ͼƬ��*���ޣ� ��128*256";
        case NET_DVR_PICTURE_SIZ_ERROR: return "ͼƬ��С���ޣ���100K";
        case NET_DVR_LOADPLAYERSDKFAILED: return "���뵱ǰĿ¼��Player Sdk����";
        case NET_DVR_LOADPLAYERSDKPROC_ERROR: return "�Ҳ���Player Sdk��ĳ���������";
        case NET_DVR_LOADDSSDKFAILED: return "���뵱ǰĿ¼��DSsdk����";
        case NET_DVR_LOADDSSDKPROC_ERROR: return "�Ҳ���DsSdk��ĳ���������";
        case NET_DVR_DSSDK_ERROR: return "����Ӳ�����DsSdk��ĳ������ʧ��";
        case NET_DVR_VOICEMONOPOLIZE: return "��������ռ";
        case NET_DVR_JOINMULTICASTFAILED: return "����ಥ��ʧ��";
        case NET_DVR_CREATEDIR_ERROR: return "������־�ļ�Ŀ¼ʧ��";
        case NET_DVR_BINDSOCKET_ERROR: return "���׽���ʧ��";
        case NET_DVR_SOCKETCLOSE_ERROR: return "socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ�";
        case NET_DVR_USERID_ISUSING: return "ע��ʱ�û�ID���ڽ���ĳ����";
        case NET_DVR_SOCKETLISTEN_ERROR: return "����ʧ��";
        case NET_DVR_PROGRAM_EXCEPTION: return "�����쳣";
        case NET_DVR_WRITEFILE_FAILED: return "д�ļ�ʧ��";
        case NET_DVR_FORMAT_READONLY: return "��ֹ��ʽ��ֻ��Ӳ��";
        case NET_DVR_WITHSAMEUSERNAME: return "�û����ýṹ�д�����ͬ���û���";
        case NET_DVR_DEVICETYPE_ERROR : return "�������ʱ�豸�ͺŲ�ƥ��";
        case NET_DVR_LANGUAGE_ERROR: return "�������ʱ���Բ�ƥ��";
        case NET_DVR_PARAVERSION_ERROR : return "�������ʱ����汾��ƥ��";
        case NET_DVR_IPCHAN_NOTALIVE: return "Ԥ��ʱ���IPͨ��������";
        case NET_DVR_RTSP_SDK_ERROR: return "���ظ���IPCͨѶ��StreamTransClient.dllʧ��";
        case NET_DVR_CONVERT_SDK_ERROR: return "����ת���ʧ��";
        case NET_DVR_IPC_COUNT_OVERFLOW: return "��������ip����ͨ����";
        case NET_DVR_MAX_ADD_NUM: return "��ӱ�ǩ(һ���ļ�Ƭ��64)�ȸ����ﵽ���";
        case NET_DVR_PARAMMODE_ERROR: return "ͼ����ǿ�ǣ�����ģʽ��������Ӳ������ʱ���ͻ��˽����������ʱ����ֵ��";
        case NET_DVR_CODESPITTER_OFFLINE: return "��Ƶ�ۺ�ƽ̨�������������";
        case NET_DVR_BACKUP_COPYING: return "�豸���ڱ���";
        case NET_DVR_CHAN_NOTSUPPORT: return "ͨ����֧�ָò���";
        case NET_DVR_CALLINEINVALID : return "�߶���λ��̫���л򳤶��߲�����б";
        case NET_DVR_CALCANCELCONFLICT: return "ȡ���궨��ͻ����������˹���ȫ�ֵ�ʵ�ʴ�С�ߴ����";
        case NET_DVR_CALPOINTOUTRANGE: return "�궨�㳬����Χ";
        case NET_DVR_FILTERRECTINVALID: return "�ߴ������������Ҫ��";
        case NET_DVR_DDNS_DEVOFFLINE: return "�豸û��ע�ᵽddns��";
        case NET_DVR_DDNS_INTER_ERROR : return "DDNS �������ڲ�����";
        case NET_DVR_FUNCTION_NOT_SUPPORT_OS : return "�˹��ܲ�֧�ָò���ϵͳ";
        case NET_DVR_DEC_CHAN_REBIND : return "����ͨ������ʾ�����������";
        case NET_DVR_INTERCOM_SDK_ERROR: return "���ص�ǰĿ¼�µ������Խ���ʧ��";
        case NET_DVR_NO_CURRENT_UPDATEFILE: return "û����ȷ��������";
        case NET_DVR_USER_NOT_SUCC_LOGIN: return "�û���û��½�ɹ�";
        case NET_DVR_USE_LOG_SWITCH_FILE: return "����ʹ����־�����ļ�";
        case NET_DVR_POOL_PORT_EXHAUST: return "�˿ڳ������ڰ󶨵Ķ˿��Ѻľ�";
        case NET_DVR_PACKET_TYPE_NOT_SUPPORT: return "������װ��ʽ����";
        case NET_DVR_ALIAS_DUPLICATE: return "�����ظ�";
    }

     return sError;
}



CFactory::CFactory()
{
    init();
}

CFactory::~CFactory()
{
    clean();
}






bool CFactory::init()
{
#ifdef LNM_TEST
    return true;
#endif

    if (!m_init)
    {

        m_init = NET_DVR_Init();
        NET_DVR_SetConnectTime(1000, 30);
        NET_DVR_SetReconnect(3000);
        //NET_DVR_SetDVRMessage()
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
    NET_DVR_Cleanup();
}




IVideoServer* CFactory::create()
{
    if (!init())
    {
        return nullptr;
    }

    return new haik_videoserver();
}


std::vector<haik_videoserver*> haik_videoserver::sServers;
std::recursive_mutex haik_videoserver::sMtServers;

/*
 * ��������
 */
haik_videoserver::haik_videoserver()
{
    std::lock_guard<std::recursive_mutex> lock(haik_videoserver::sMtServers);
    sServers.push_back(this);
}

haik_videoserver::~haik_videoserver()
{

    //logout();
    hk_log.AddLog(std::string("haik_videoserver::~haik_videoserver()"));
    std::lock_guard<std::recursive_mutex> lock(haik_videoserver::sMtServers);
    for (int i = 0; i < sServers.size(); i++)
    {
        if (sServers[i] == this)
        {
            sServers.erase(sServers.begin() + i);
            break;
        }
    }
}

IVideoServer* haik_videoserver::clone()
{
    haik_videoserver *svr = new haik_videoserver();
    return svr;
}

bool haik_videoserver::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string>& channels)
{
    logout();
	channels.clear();
    memset(&m_deviceInfo, 0, sizeof(m_deviceInfo));
    m_lLoginHandle = NET_DVR_Login_V30((char*)IP, port,
                                   (char*)user,(char*)password,
                                   &m_deviceInfo);
    if (m_lLoginHandle == -1)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NET_DVR_Login_V30 failed:") + m_sLastError);
        return false;
    }

    NET_DVR_PICCFG_V40 channelInfo;
    DWORD returnBytes = 0;
    hk_log.AddLog(QString("m_deviceInfo.byChanNum:%1, m_deviceInfo.byIPChanNum:%2 ")
                           .arg(m_deviceInfo.byChanNum).arg(m_deviceInfo.byIPChanNum));
    for (int i = 0; i < m_deviceInfo.byChanNum; i++)
    {
        if (NET_DVR_GetDVRConfig(m_lLoginHandle, NET_DVR_GET_PICCFG_V40,
                             m_deviceInfo.byStartChan + i, &channelInfo,
                             sizeof(NET_DVR_PICCFG_V40), &returnBytes) != FALSE)
        {
            channels[m_deviceInfo.byStartChan + i] = std::string ((char *)channelInfo.sChanName);
        }
        else
        {
            channels[m_deviceInfo.byStartChan + i];
        }
    }

    for (int i = 0; i < m_deviceInfo.byIPChanNum + 255*m_deviceInfo.byHighDChanNum; i++)
    {
        if (NET_DVR_GetDVRConfig(m_lLoginHandle, NET_DVR_GET_PICCFG_V40,
                             m_deviceInfo.byStartDChan + i, &channelInfo,
                             sizeof(NET_DVR_PICCFG_V40), &returnBytes) != FALSE)
        {
            channels[m_deviceInfo.byStartDChan + i] = std::string ((char *)channelInfo.sChanName);
        }
        else
        {
            channels[m_deviceInfo.byStartDChan + i];
        }
    }


    return true;
}

bool haik_videoserver::logout()
{
    #ifdef LNM_TEST
    return true;
    #endif

    if (m_lLoginHandle != -1 && !NET_DVR_Logout(m_lLoginHandle))
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("logout failed:") + m_sLastError);
        m_lLoginHandle = -1;
        return false;
    }
    else {
        m_lLoginHandle = -1;
        hk_log.AddLog(std::string("haik_videoserverlogout ok!"));
    }

    return true;
}

void NetTimeToTM(const NET_DVR_TIME& nt, tm& t)
{
    t.tm_year = nt.dwYear - 1900;
    t.tm_mon = nt.dwMonth - 1;
    t.tm_mday = nt.dwDay;
    t.tm_hour = nt.dwHour;
    t.tm_min = nt.dwMinute;
    t.tm_sec = nt.dwSecond;
}
void TMToNetTime(const tm& t, NET_DVR_TIME& nt)
{
    nt.dwYear = t.tm_year + 1900;
    nt.dwMonth = t.tm_mon + 1;
    nt.dwDay = t.tm_mday;
    nt.dwHour = t.tm_hour;
    nt.dwMinute = t.tm_min;
    nt.dwSecond = t.tm_sec;
}
void addLog(const char* sLog, int nLine)
{

    hk_log.AddLog(QString("%1 %2").arg(nLine).arg(sLog));
}

void sheNET_DVR_FindClose_V30(LONG lFind){
    SHE_BEGING
    //NET_DVR_FindClose(lFind);
    SHE_END
}
bool haik_videoserver::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart,
                                                       __time64_t timeEnd)
{
    struct tm Tm;
    NET_DVR_FILECOND_V40 f;
    memset(&f, 0, sizeof(NET_DVR_FILECOND_V40));

    _localtime64_s(&Tm, (const time_t*)&timeStart);
    TMToNetTime(Tm, f.struStartTime);

    _localtime64_s(&Tm, (const time_t*)&timeEnd);
    TMToNetTime(Tm, f.struStopTime);

    if (m_lLoginHandle < 0)
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


	auto itr = channelVec.begin();
	for (; itr != channelVec.end(); itr++)
	{
        hk_log.AddLog(QString("channelVec beg:%1").arg(files.size()));
		int nChannelId = *itr;
        hk_log.AddLog(QString("nChannelId:%1").arg(nChannelId));
		f.dwFileType = 0xff;
		f.dwIsLocked = 0xff;
		f.dwUseCardNo = 0;
		f.lChannel = nChannelId;
		f.sCardNumber[0] = 0;


		LONG lfind = NET_DVR_FindFile_V40(m_lLoginHandle, &f);

		if (lfind == -1)
		{
			m_sLastError = GetLastErrorString();
			hk_log.AddLog(std::string("NET_DVR_FindFile_V40 failed:") + m_sLastError);
			continue;
		}
		std::shared_ptr<NET_DVR_FINDDATA_V40> nriFileinfo(new NET_DVR_FINDDATA_V40());
		LONG re = NET_DVR_FindNextFile_V40(lfind, nriFileinfo.get());
		RecordFile rf;
		hk_log.AddLog(QString("NET_DVR_FindNextFile_V40 re:%1").arg(re));
		while (re == NET_DVR_ISFINDING || re == NET_DVR_FILE_SUCCESS)
		{
			if (re == NET_DVR_FILE_SUCCESS && nriFileinfo->dwFileSize > 0)
			{
                hk_log.AddLog(QString("NET_DVR_FindNextFile_V40:%1").arg(re));
				struct tm Tm;
				NetTimeToTM(nriFileinfo->struStartTime, Tm);
				rf.beginTime = _mktime64(&Tm);

				NetTimeToTM(nriFileinfo->struStopTime, Tm);
				rf.endTime = _mktime64(&Tm);

				rf.channel = nChannelId;
				rf.name = nriFileinfo->sFileName;
				rf.size = nriFileinfo->dwFileSize;

				rf.setPrivateData(nriFileinfo.get(), sizeof(NET_DVR_FINDDATA_V40));
				files.push_back(rf);
			}
			else
			{
				::Sleep(5);
			}

			re = NET_DVR_FindNextFile_V40(lfind, nriFileinfo.get());
		}

		hk_log.AddLog(QString("NET_DVR_FindNextFile_V40 end re:%1").arg(re));

        sheNET_DVR_FindClose_V30(lfind);
        hk_log.AddLog(QString("sheNET_DVR_FindClose_V30 end:%1").arg(files.size()));
	}

    hk_log.AddLog(QString("files:%1").arg(files.size()));
    return true;
}

void addLog(const NET_DVR_TIME& nt)
{
    hk_log.AddLog(QString("%1/%2/%3 %4:%5:%6").arg(nt.dwYear).arg(nt.dwMonth)
                           .arg(nt.dwDay).arg(nt.dwHour).arg(nt.dwMinute).arg(nt.dwSecond));
}

bool haik_videoserver::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
#ifdef LNM_TEST

    std::string fn(saveFileName);
    long long size = file.size;
    qDebug()<<QString::fromLocal8Bit(saveFileName);
    new std::thread([=]{
        QFile f(fn.c_str());
        if (f.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QDataStream out(&f);
            std::string s(200 * 11 * 1024, 's');
            qDebug()<<f.size()<<" "<<size;
            while (f.size() < size)
            {
                ::Sleep(1000);
                int num = rand() % 200;
                if (num < 0)
                {
                    num = -num;
                }
                out.writeBytes(s.c_str(), num * 10 * 1024);
                qDebug()<<fn.c_str()<<" size:"<<f.size();
            }

            f.close();
        }
        else
        {
            qDebug()<<"file open failed";
        }

    });
    hdl = GetTickCount64();
    return true;
#endif



    if (0 > m_lLoginHandle)
    {

        m_sLastError = "���ȵ�¼!";

        return false;
    }

    NET_DVR_PLAYCOND struDownloadCond={0};
    memset(&struDownloadCond, 0, sizeof(NET_DVR_PLAYCOND));
    struDownloadCond.dwChannel = file.channel;
    struDownloadCond.byDrawFrame = 1;

    struct tm Tm;

    _localtime64_s(&Tm, (const time_t*)&file.beginTime);
    TMToNetTime(Tm, struDownloadCond.struStartTime);
    addLog(struDownloadCond.struStartTime);

    time_t tEnd = file.endTime + 100;
    _localtime64_s(&Tm, (const time_t*)&tEnd);
    TMToNetTime(Tm, struDownloadCond.struStopTime);
    addLog(struDownloadCond.struStopTime);

    hk_log.AddLog(QString("m_deviceInfo.wDevType:%1")
                           .arg(m_deviceInfo.wDevType));
    NET_DVR_FINDDATA_V40& info = *((NET_DVR_FINDDATA_V40*)file.getPrivateData());
    hdl = NET_DVR_GetFileByName(m_lLoginHandle, (char*)info.sFileName, (char*)saveFileName);
    hk_log.AddLog(QString::fromLocal8Bit("NET_DVR_GetFileByName"));
    if (hdl < 0)
    {
        hdl = NET_DVR_GetFileByTime_V40(m_lLoginHandle, (char*)info.sFileName, &struDownloadCond);
        hk_log.AddLog(QString::fromLocal8Bit("NET_DVR_GetFileByTime_V40"));
    }
	//����OEM���������������� NET_DVR_GetFileByTime_V40 �޷�����
//    if (this->m_deviceInfo.wDevType == 2015 || this->m_deviceInfo.wDevType == 2215)

    if (hdl < 0)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NET_DVR_GetFileBy failed:") + m_sLastError + " �ļ���" + saveFileName);
        return false;
    }

    if (!NET_DVR_PlayBackControl_V40(hdl, NET_DVR_PLAYSTART, NULL, 0, NULL,NULL))
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NET_DVR_PlayBackControl failed:") + m_sLastError + " �ļ���" + saveFileName);
        return false;
    }

    return true;
}


bool  haik_videoserver::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (0 > m_lLoginHandle)
    {
        m_sLastError = "���ȵ�¼!";
        return false;
    }

    NET_DVR_VOD_PARA struVodPara={0};
    memset(&struVodPara, 0, sizeof(NET_DVR_VOD_PARA));
    struVodPara.dwSize=sizeof(struVodPara);
    struVodPara.struIDInfo.dwChannel = file.channel; //ͨ����
    struVodPara.hWnd = hwnd;

    struct tm Tm;

    _localtime64_s(&Tm, (const time_t*)&file.beginTime);
    TMToNetTime(Tm, struVodPara.struBeginTime);

    _localtime64_s(&Tm, (const time_t*)&file.endTime);
    TMToNetTime(Tm, struVodPara.struEndTime);

    playbackHandle = NET_DVR_PlayBackByTime_V40(m_lLoginHandle, &struVodPara);
    if (playbackHandle < 0)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NET_DVR_PlayBackByTime_V40 failed:") + m_sLastError);
        return false;
    }

    if (!NET_DVR_PlayBackControl(playbackHandle, NET_DVR_PLAYSTART, NULL, 0))
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NET_DVR_PlayBackControl failed:") + m_sLastError);
        return false;
    }

    return true;
}

bool haik_videoserver::SetPlayBack(download_handle_t playbackHandle, __int32 pos)
{
    return FALSE != NET_DVR_PlayBackControl_V40(playbackHandle, NET_DVR_PLAYSETPOS,
                                                &pos);
}

bool haik_videoserver::StopPlayBack(download_handle_t playbackHandle, __int32 mPause)
{
    if (0 > m_lLoginHandle)
    {
        m_sLastError = "���ȵ�¼!";
        return false;
    }

    if (!NET_DVR_StopPlayBack(playbackHandle))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }

    return true;
}



bool haik_videoserver::stopDownload(download_handle_t h)
{
    #ifdef LNM_TEST
    return true;
    #endif

    if (FALSE == NET_DVR_StopGetFile(h))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }

    return true;
}
