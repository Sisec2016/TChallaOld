#include "YyShiKejiVideoServer.h"
#include <iostream>

#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"
#include <thread>
#include <QFile>
#include <qdebug.h>
Log hk_log("YyShiKejiVideoServer");

extern "C" VIDEOSERVER_EXPORT IVideoServerFactory* VideoServerFactory()
{

    return new CFactory();
}


std::string GetLastErrorString()
{
    LONG error = NETDEV_GetLastError();
    switch (error)
    {
        case NETDEV_E_COMMON_FAILED: return "ͨ�ô���  Common error";
        case NETDEV_E_DEV_COMMON_FAILED: return "���豸���ص�ͨ�ô���  Common error returned by device";
        case NETDEV_E_SYSCALL_FALIED: return "ϵͳ��������ʧ�ܣ���鿴errno  Failed to call system function. See errno";
        case NETDEV_E_NULL_POINT: return "��ָ��  Null pointer";
        case NETDEV_E_INVALID_PARAM: return "��Ч����  Invalid parameter";
        case NETDEV_E_INVALID_MODULEID: return "��Чģ��ID  Invalid module ID";
        case NETDEV_E_NO_MEMORY: return "�ڴ����ʧ��  Failed to allocate memory";
        case NETDEV_E_NOT_SUPPORT: return "�豸��֧��  Not supported by device";
        case NETDEV_E_SDK_SOCKET_LSN_FAIL: return "����socket listenʧ��  Failed to create socket listen";
        case NETDEV_E_INIT_MUTEX_FAIL: return "��ʼ����ʧ��  Failed to initialize lock";
        case NETDEV_E_INIT_SEMA_FAIL: return "��ʼ���ź���ʧ��  Failed to initialize semaphore";
        case NETDEV_E_ALLOC_RESOURCE_ERROR: return "SDK��Դ�������  Error occurred during SDK resource allocation";
        case NETDEV_E_SDK_NOINTE_ERROR: return "SDKδ��ʼ��  SDK not initialized";
        case NETDEV_E_ALREDY_INIT_ERROR: return "SDK�Ѿ���ʼ����  SDK already initialized";
        case NETDEV_E_HAVEDATA: return "��������   Data not all sent";
        case NETDEV_E_NEEDMOREDATA: return "��Ҫ��������  More data required ";
        case NETDEV_E_CONNECT_ERROR: return "��������ʧ��  Failed to create connection";
        case NETDEV_E_SEND_MSG_ERROR: return "����������Ϣʧ��  Failed to send request message";
        case NETDEV_E_TIMEOUT: return "��Ϣ��ʱ  Message timeout";
        case NETDEV_E_DECODE_RSP_ERROR: return "������Ӧ��Ϣʧ��  Failed to decode response message";
        case NETDEV_E_SOCKET_RECV_ERROR: return "Socket������Ϣʧ��  Socket failed to receive message";
        case NETDEV_E_NUM_MAX_ERROR: return "�����ﵽ��󡣷����ע����������Ԥ������������SDK֧�ֵ������  Maximum number reached. The assigned numbers of registration connections and preview connections reached the maximum supported by SDK";
        case NETDEV_E_GET_PORT_ERROR: return "��ȡ���ض˿ں�ʧ��  Failed to obtain local port number";
        case NETDEV_E_CREATE_THREAD_FAIL: return "�����߳�ʧ��  Failed to create thread";
        case NETDEV_E_NOENOUGH_BUF: return "������̫С: �����豸���ݵĻ�����  Buffer is too small for receiving device data";
        case NETDEV_E_GETLOCALIPANDMACFAIL: return "��ñ���PC��IP��ַ�������ַʧ��  Failed to obtain the IP or MAC address of the local PC";
        case NETDEV_E_RESCODE_NO_EXIST: return "��Դ���벻����  Resource code not exist";
        case NETDEV_E_MSG_DATA_INVALID: return "��Ϣ���ݴ���  Incorrect message content";
        case NETDEV_E_GET_CAPABILITY_ERROR: return "��ȡ������ʧ��  Failed to obtain capabilities";
        case NETDEV_E_USER_NOT_BIND: return "���û�û�ж��ĸ澯   User not subscribed to alarms";
        case NETDEV_E_AUTHORIZATIONFAIL: return "�û���Ȩʧ��  User authentication failed";
        case NETDEV_E_BINDNOTIFY_FAIL: return "�󶨸澯ʧ��  Failed to bind alarms";
//        case NDEDEV_E_NOTADMIN: return "����Ȩ�޲��㣬windows��һ��Ϊ�ǹ���Ա�ʺŲ������� Not enough permission. In Windows, it is normally because the operator is not an administrator.";
//        case NDEDEV_E_DEVICE_FACTURER_ERR: return "��֧�ֵ��豸���� Manufacturers that are not supported";
        case NETDEV_E_NONSUPPORT: return "�ù��ܲ�֧��  Function not supported";
        case NETDEV_E_TRANSFILE_FAIL: return "�ļ�����ʧ��  File transmission failed";
        case NETDEV_E_JSON_ERROR: return "Json ͨ�ô���  Json common error";


        case NETDEV_E_USER_WRONG_PASSWD: return "�û��������  Incorrect password";
        case NETDEV_E_USER_LOGIN_MAX_NUM: return "�û���¼���Ѵ�����  Number of login users reached the upper limit";
        case NETDEV_E_USER_NOT_ONLINE: return "�û�������  User not online";
        case NETDEV_E_USER_NO_SUCH_USER: return "û�и��û�  User not online";
        case NETDEV_E_USER_NO_AUTH: return "�û���Ȩ��  User has no rights";
        case NETDEV_E_USER_MAX_NUM: return "�û�����-�����ٱ����  Reached the upper limit�Cno more users can be added";
        case NETDEV_E_USER_EXIST: return "�û��Ѵ���  User already exists";
        case NETDEV_E_USER_PASSWORD_CHANGE: return "�û������޸�  Password changed";

        case NETDEV_E_LIVE_EXISTED: return "ʵ��ҵ���Ѿ�����  Live video service already established";
        case NETDEV_E_LIVE_INPUT_NOT_READY: return "ý����δ׼������  Media stream not ready";
        case NETDEV_E_LIVE_OUTPUT_BUSY: return "ʵ��ҵ����ʾ��Դæ  Display resource is busy for live video service";
        case NETDEV_E_LIVE_CB_NOTEXIST: return "ʵ�����ƿ鲻����  Control module for live video not exist";
        case NETDEV_E_LIVE_STREAM_FULL: return "ʵ������Դ����  Live stream resource full";

        case NETDEV_E_CAPTURE_NO_SUPPORT_FORMAT: return "ץ�ĸ�ʽ��֧��  Format of captured image not supported";
        case NETDEV_E_CAPTURE_NO_ENOUGH_CAPACITY: return "Ӳ�̿ռ䲻��  Insufficient disk space";
        case NETDEV_E_CAPTURE_NO_DECODED_PICTURE: return "û�н������ͼƬ�ɹ�ץ��  No decoded image for capture";
        case NETDEV_E_CAPTURE_SINGLE_FAILED: return "����ץ�Ĳ���ʧ��  Single capture failed";

        case NETDEV_E_VOD_PLAY_END: return "�طŽ���  Playback ended";
        case NETDEV_E_VOD_NO_CM: return "�طſ��ƿ鲻����  Playback controlling module not exist";
        case NETDEV_E_VOD_OVER_ABILITY: return "�ط�������������  Beyond playback capability";
        case NETDEV_E_VOD_NO_RECORDING_CM: return "¼���ļ����ƿ鲻����  Recording file controlling module not exist ";
        case NETDEV_E_VOD_NO_RECORDING: return "��¼������   No recording";
        case NETDEV_E_VOD_NO_REPLAYURL: return "�޷���ȡ�طŵ�url   Cannot get the URL for playback";
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






bool CFactory::init()
{

    if (!m_init)
    {

        m_init = NETDEV_Init();
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
    NETDEV_Cleanup();
}




IVideoServer* CFactory::create()
{
    if (!init())
    {
        return nullptr;
    }

    return new YyShiKejiVideoServer();
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

std::vector<YyShiKejiVideoServer*> YyShiKejiVideoServer::sServers;
std::recursive_mutex YyShiKejiVideoServer::sMtServers;

/*
 * ��������
 */
YyShiKejiVideoServer::YyShiKejiVideoServer()
{
    std::lock_guard<std::recursive_mutex> lock(YyShiKejiVideoServer::sMtServers);
    sServers.push_back(this);
    m_pPlayFile = nullptr;
    m_lLoginHandle = NULL;
}

YyShiKejiVideoServer::~YyShiKejiVideoServer()
{

    //logout();
    hk_log.AddLog(std::string("YyShiKejiVideoServer::~YyShiKejiVideoServer()"));
    std::lock_guard<std::recursive_mutex> lock(YyShiKejiVideoServer::sMtServers);
    for (int i = 0; i < sServers.size(); i++)
    {
        if (sServers[i] == this)
        {
            sServers.erase(sServers.begin() + i);
            break;
        }
    }
}

IVideoServer* YyShiKejiVideoServer::clone()
{
    YyShiKejiVideoServer *svr = new YyShiKejiVideoServer();
    return svr;
}

bool YyShiKejiVideoServer::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string>& channels)
{

	channels.clear();
    memset(&m_deviceInfo, 0, sizeof(m_deviceInfo));
    m_lLoginHandle = (long)NETDEV_Login((char*)IP, port,
                                   (char*)user,(char*)password,
                                   &m_deviceInfo);
    if (m_lLoginHandle == NULL)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NETDEV_Login failed:") + m_sLastError);
        return false;
    }

    for (int i = 0; i < m_deviceInfo.dwChannelNum; i++)
    {
        channels[i + 1] = QString("channel%1").arg(i + 1).toStdString();
    }
    return true;
}

bool YyShiKejiVideoServer::logout()
{

    if (m_lLoginHandle >= 0 && !NETDEV_Logout((LPVOID)m_lLoginHandle))
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("logout failed:") + m_sLastError);
        return false;
    }
    else {
        hk_log.AddLog(std::string("YyShiKejiVideoServerlogout ok!"));
    }

    return true;
}

bool YyShiKejiVideoServer::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart,
                                                       __time64_t timeEnd)
{
    const int BYTE_ONE_SECONDS = 234947;
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

    struct tm Tm;
    NETDEV_FILECOND_S f;
    memset(&f, 0, sizeof(NETDEV_FILECOND_S));
    //stFileCond.dwChannelID = m_lChannelID;
    LPVOID dwFileHandle = 0;

    /* UTC time. The found period of time is 24 hours from current system time. */
    f.tBeginTime = timeStart;
    f.tEndTime = timeEnd;

    auto itr = channelVec.begin();
    RecordFile rf;
    for (; itr != channelVec.end(); itr++)
    {
        int nChannelId = *itr;
        f.dwChannelID = nChannelId;

        dwFileHandle = NETDEV_FindFile((LPVOID)m_lLoginHandle, &f);
        if (NULL != dwFileHandle)
        {
            NETDEV_FINDDATA_S stVodFile = { 0 };
            hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
            while (NETDEV_FindNextFile(dwFileHandle, &stVodFile))
            {
                if (stVodFile.tBeginTime == stVodFile.tEndTime)
                {
                    continue;
                }
                hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
                rf.beginTime = stVodFile.tBeginTime;
                rf.endTime = stVodFile.tEndTime;

                rf.channel = nChannelId;
                rf.name = stVodFile.szFileName;
                rf.size = (rf.endTime - rf.beginTime) * BYTE_ONE_SECONDS;

                rf.setPrivateData(&stVodFile, sizeof(NETDEV_FINDDATA_S));
                files.push_back(rf);

            }
            hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
            NETDEV_FindClose(dwFileHandle);
            hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
        }

        hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
    }

    hk_log.AddLog(QString("%1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
   return true;
}


bool YyShiKejiVideoServer::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
    if (m_lLoginHandle == NULL)
    {
        m_sLastError = "���ȵ�¼!";
        hk_log.AddLog("downLoadByRecordFile ���ȵ�¼!");
        return false;
    }

    NETDEV_PLAYBACKCOND_S stPlayBackInfo = { 0 };
    stPlayBackInfo.hPlayWnd = NULL;
    stPlayBackInfo.dwDownloadSpeed = NETDEV_DOWNLOAD_SPEED_FOUR;

    stPlayBackInfo.tBeginTime = file.beginTime;
    stPlayBackInfo.tEndTime = file.endTime + file.endTime - file.beginTime;
    stPlayBackInfo.dwChannelID = file.channel;

    hdl = (download_handle_t)NETDEV_GetFileByTime((LPVOID)m_lLoginHandle, &stPlayBackInfo, (char *)saveFileName, NETDEV_MEDIA_FILE_MP4);
    if (NULL == hdl)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NETDEV_GetFileByTime failed:") + m_sLastError + " �ļ���" + saveFileName);
        return false;
    }
//     int enSpeed = NETDEV_DOWNLOAD_SPEED_EIGHT;
//     int bRet = NETDEV_PlayBackControl((LPVOID)hdl, NETDEV_PLAY_CTRL_SETPLAYSPEED, &enSpeed);

    QString qsFile(QString::fromLocal8Bit(saveFileName));
    QFile::remove(qsFile);

    mMpDownloadPosCaculators[hdl].init(file.size, qsFile.left(QString(saveFileName).lastIndexOf(".")).toLocal8Bit().data());
    QFile::remove(QString::fromLocal8Bit(mMpDownloadPosCaculators[hdl].getSaveFile()));
    mMpDownloadRecords[hdl] = file;
    return true;
}

HWND playWwnd = NULL;
LPVOID playHandle = NULL;
bool YyShiKejiVideoServer::playVideo(INT64 beginTime, INT64 tEndTime, int channel){
    NETDEV_PLAYBACKCOND_S stPlayBackByTimeInfo = { 0 };

    /* Assume to play the first recording found */
    stPlayBackByTimeInfo.tBeginTime = beginTime;
    stPlayBackByTimeInfo.tEndTime = tEndTime;
    stPlayBackByTimeInfo.dwChannelID = channel;

    stPlayBackByTimeInfo.hPlayWnd = playWwnd;
    stPlayBackByTimeInfo.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;

    playHandle =  NETDEV_PlayBackByTime((LPVOID)m_lLoginHandle, &stPlayBackByTimeInfo);
    if (NULL == playHandle)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NET_DVR_PlayBackControl failed:") + m_sLastError);
        return false;
    }
    
    return true;
}

bool  YyShiKejiVideoServer::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (0 == m_lLoginHandle)
    {
        m_sLastError = "���ȵ�¼!";
        return false;
    }
    StopPlayBack(playbackHandle, 0);
    playWwnd = hwnd;
    if (!this->playVideo(file.beginTime, file.endTime, file.channel)){
        return false;
    }

    m_pPlayFile = &file;
    playbackHandle = (play_handle_t)m_pPlayFile;
    return true;
}

bool YyShiKejiVideoServer::SetPlayBack(play_handle_t playbackHandle, __int32 pos)
{
    if (m_lLoginHandle == NULL)
    {
        m_sLastError = "���ȵ�¼!";
        return false;
    }
    
//    StopPlayBack(playbackHandle, 0);
    INT64 iTime = m_pPlayFile->beginTime + (m_pPlayFile->endTime - m_pPlayFile->beginTime) * pos / 100;
//     RecordFile* pFile = (RecordFile*)playbackHandle;
//     return this->playVideo(iTime, pFile->endTime, pFile->channel);
// 

//     BOOL bRet = NETDEV_PlayBackControl((LPVOID)playbackHandle, NETDEV_PLAY_CTRL_GETPLAYTIME, &(iTime));
//     if (TRUE != bRet)
//     {
//         hk_log.AddLog(std::string("Get playtime failed. failed:") + m_sLastError);
//         return false;
//     }

    BOOL bRet = NETDEV_PlayBackControl((LPVOID)playbackHandle, NETDEV_PLAY_CTRL_SETPLAYTIME, &iTime);
    if (TRUE != bRet)
    {
        m_sLastError = GetLastErrorString();
        hk_log.AddLog(std::string("NET_DVR_PlayBackControl failed:") + m_sLastError);
        return false;
    }

    return true;
}

bool YyShiKejiVideoServer::StopPlayBack(download_handle_t playbackHandle, __int32 mPause)
{
    if (m_lLoginHandle == NULL)
    {
        m_sLastError = "���ȵ�¼!";
        return false;
    }
    if (NULL == playHandle)
    {
        return true;
    }
    int bRet = NETDEV_StopPlayBack(playHandle);
    if (TRUE != bRet)
    {
        m_sLastError = GetLastErrorString();
        return false;
        
    }
    playHandle = NULL;
    return true;
}



bool YyShiKejiVideoServer::stopDownload(download_handle_t h)
{

    if (TRUE != NETDEV_StopGetFile((LPVOID)h))
    {
        m_sLastError = GetLastErrorString();
        return false;
    }
    if (mMpDownloadPosCaculators.find(h) == mMpDownloadPosCaculators.end())
    {
        return false;
    }

    QFile::remove(QString::fromLocal8Bit(mMpDownloadPosCaculators[h].getSaveFile()));
    mMpDownloadRecords.erase(h);
    mMpDownloadPosCaculators.erase(h);
    return true;
}


bool YyShiKejiVideoServer::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed){
    
    mMpDownloadPosCaculators[h].getPos(*totalSize, *currentSize);
    *failed = false;
    if (mMpDownloadPosCaculators[h].isMaybeFishish())
    {
        INT64 iTime = 0;
        BOOL bRet = NETDEV_PlayBackControl((LPVOID)h, NETDEV_PLAY_CTRL_GETPLAYTIME, &(iTime));
        if (bRet)
        {
            RecordFile& file = mMpDownloadRecords[h];
            *currentSize = file.size * (iTime - file.beginTime) / (file.endTime - file.beginTime);
            *totalSize = file.size;
        }
        else{
            return true;
        }
    }
    
    
    
    if (*currentSize >= *totalSize)
    {
        *totalSize = *currentSize;
        this->stopDownload(h);
    }
    return true;
}