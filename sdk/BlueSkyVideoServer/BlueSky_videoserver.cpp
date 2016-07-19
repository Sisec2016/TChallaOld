#include "bluesky_videoserver.h"
#include <iostream>
#include <time.h>
#include <io.h>
#include "../../VideoServer/log.h"
#include "dvxSdk.h"
#include "dvxSdkType.h"

IVideoServerFactory* VideoServerFactory()
{
    Log::instance().initFileName("BlueSky_videoserver");
    return new CFactoryBlueSky();
}

static std::string GetLastErrorString(int error)
{
    switch (error)
    {
        case DVX_OK:         return "û�д���";
        case DVX_ERR_ASSERT: return "����SDK�ĳ���";
        case DVX_ERR_MALLOCMEMORY: return "�����ڴ����ϵͳ����";
        case DVX_ERR_CREATE_EVENT: return "����Event�������ϵͳ����";
        case DVX_ERR_CREATE_THREAD: return "�����̳߳���ϵͳ����";
        case DVX_ERR_PARA: return "��������";
        case DVX_ERR_SDK_NO_INIT: return "SDKû�г�ʼ��";
        case DVX_ERR_DVX_NO_LOGIN: return "��û�е�¼";
        case DVX_ERR_DVX_INVALID_HANDLE: return "��Ч��DvxHandle���";
        case DVX_ERR_COMMON: return "ͨ�ô���";
        case DVX_ERR_ERR_TRANS_OPEN: return "�򿪴���������";
        case DVX_ERR_NET_DISCONNECT: return "����Ͽ�";
        case DVX_ERR_HELLO: return "����Ͽ�";
        case DVX_ERR_LOCALPLAY_INVALID_HANDLE: return "��Ч�ı��ػطž��";
        case DVX_ERR_LOCALPLAY_NO_OPEN: return "���ػطţ���û�д�";
        case DVX_ERR_CREATE_FILE: return "�����ļ�ʧ��";
        case DVX_ERR_NET: return "�������";
        case DVX_BSCP_BUSY: return "����ͨ��æ";
        case DVX_BSCP_TIMEOUT: return "bscp����ִ�г�ʱ";
        case DVX_BSCP_NETERR: return "bscp�������";
        case DVX_ERR_INIT: return "��ʼ������";
        case DVX_ERR_NET_INIT: return "�����ʼ������";
        case PLAYER_ERR_PARA: return "��������";
        case PLAYER_ERR_SYSTEM: return "ϵͳ����";
        case PLAYER_ERR_INVALID_HANDLE: return "��Ч���";
        case PLAYER_ERR_FAILED: return "����ʧ��";
        case PLAYER_ERR_FRAMEHDR: return "����֡����";
        case PLAYER_ERR_NO_SPACE: return "û�пռ�";
        case PLAYER_ERR_NOTPLAY: return "û�в���";

    }

    return std::string("δ֪����:") + QString::number(error).toStdString();
}



CFactoryBlueSky::CFactoryBlueSky()
{
    init();
}

CFactoryBlueSky::~CFactoryBlueSky()
{
    clean();
}






bool CFactoryBlueSky::init()
{
    if (!m_init)
    {
        int iRet = dvxSdkInit();
		m_init = (iRet == 0);
        //NET_DVR_SetConnectTime(1000, 30);
        //NET_DVR_SetReconnect(3000);
        //NET_DVR_SetDVRMessage()
        if (!m_init)
        {
            m_sLastError = GetLastErrorString(iRet);
			Log::instance().AddLog(string("��ʼ��SDKʧ�ܣ�����ԭ��") + m_sLastError);
		}

		Log::instance().AddLog(string("��ʼ��SDK�ɹ�"));
    }

    return m_init;
}


void CFactoryBlueSky::clean()
{
    dvxSdkDeInit();
}




IVideoServer* CFactoryBlueSky::create()
{
    if (!init())
    {
        return nullptr;
    }

    return new bluesky_videoserver();
}

// std::vector<bluesky_videoserver*> bluesky_videoserver::sServers;
// std::recursive_mutex bluesky_videoserver::sMtServers;

/*
 * ��������
 */
bluesky_videoserver::bluesky_videoserver()
{
//     std::lock_guard<std::recursive_mutex> lock(bluesky_videoserver::sMtServers);
//     sServers.push_back(this);
}

bluesky_videoserver::~bluesky_videoserver()
{
    logout();
//     std::lock_guard<std::recursive_mutex> lock(bluesky_videoserver::sMtServers);
//     for (int i = 0; i < sServers.size(); i++)
//     {
//         if (sServers[i] == this)
//         {
//             sServers.erase(sServers.begin() + i);
//             break;
//         }
//     }
}

// static void CALL_METHOD PosCallBack(long lPlayHandle, long lTotalSize, long lDownLoadSize, long dwUser)
// {
// 	bluesky_videoserver * pThis = (bluesky_videoserver *)dwUser;
// 	{
// 		std::lock_guard<std::recursive_mutex> lock(pThis->m_mtxPos);
// 		map<long long, stPos_DownPlay>::iterator itr = pThis->m_mapPosDownPlay.find(lPlayHandle);
// 		if (itr != pThis->m_mapPosDownPlay.end())
// 		{
// 			itr->second.iTotalSize = lTotalSize;
// 			itr->second.iCurSize = lDownLoadSize;
// 			itr->second.iPercent = ((float)lDownLoadSize/(float)lTotalSize)*100;
// 		}
// 	}
// }

IVideoServer* bluesky_videoserver::clone()
{
//     bluesky_videoserver *svr = new bluesky_videoserver();
// 	memcpy(svr, this, sizeof(bluesky_videoserver));
//     return svr;
	return NULL;
}

bool bluesky_videoserver::login(const char* IP, __int32 port, const char* user, const char* password, std::map<__int32, std::string>& channels)
{
//    if (0 < m_lLoginHandle && !logout())
//    {
//        return false;
//    }

	DvxHandle hHandle = 0;
    int iRet = dvxCreate(IP, port, 3720,
                                   user, password,
                                   &hHandle);
    if (iRet != 0 || hHandle == 0)
    {
        m_sLastError = GetLastErrorString(iRet);
		Log::instance().AddLog(std::string("login ��¼ʧ�ܣ�����ԭ��") + m_sLastError);
        return false;
    }
	m_lLoginHandle = (long)hHandle;

	channels.clear();
	char szName[16];
	NvrGetExistChannels stChannels;
	ZeroMemory(&stChannels, sizeof(stChannels));
    iRet = dvxAVExistChannelsGet((DvxHandle)m_lLoginHandle, &stChannels);
    Log::instance().AddLog(QString("stChannels.counts:%1").arg(stChannels.counts));
    if (stChannels.counts > 0)
	{
        char szLog[1024];
        ZeroMemory(szLog, 1024);
        sprintf(szLog, "login ͨ������:%d", stChannels.counts);
        Log::instance().AddLog(string(szLog));

        for (int i = 1; i <= stChannels.counts; i++)
        {
            // 			char szLog[1024];
            // 			ZeroMemory(szLog, 1024);
            // 			sprintf(szLog, "login ͨ�����ñ�ʶ:%d", stChannels.channels[i - 1]);
            // 			Log::instance().AddLog(string(szLog));

            if (i <= 64 && stChannels.channels[i - 1] == 1)
            {
                ZeroMemory(szName, sizeof(szName));
                sprintf(szName, "ͨ��%d", i);
                string strName = szName;
                channels.insert(std::make_pair(i, strName));
            }
        }
        return true;
	}
	else
	{
        m_sLastError = GetLastErrorString(iRet);
        Log::instance().AddLog(string("login ��ȡͨ��ʧ�ܣ�Ĭ��4ͨ��������ԭ��") + m_sLastError);
        return false;
	}


    return true;
}

bool bluesky_videoserver::logout()
{
    int iRet = 0;
    if (m_lLoginHandle != 0 && (iRet = dvxLogout((DvxHandle)m_lLoginHandle)) != DVX_OK)
    {
        m_sLastError = GetLastErrorString(iRet);
        return false;
    }

    return true;
}

#define MAX_SEARCH_COUNT 1000
#define PAGE_SIZE (50)
bool bluesky_videoserver::GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int>& channelVec, __time64_t timeStart,
                                                       __time64_t timeEnd)
{
    if (m_lLoginHandle == DVX_OK)
    {
        m_sLastError = "���ȵ�¼!";
		Log::instance().AddLog(string("GetRecordFileList ���ȵ�¼"));
        return false;
    }

    if (timeStart >= timeEnd)
    {
        m_sLastError = "ʱ�䷶Χ����!";
		Log::instance().AddLog(string("GetRecordFileList ʱ�䷶Χ����"));
        return false;
    }

	files.clear();
	//m_mapArcItem.clear();
	std::vector<int>::const_iterator itr = channelVec.begin();
	for (; itr != channelVec.end(); itr++)
	{
		int nChannelId = *itr;

		char szLog[1024];
		ZeroMemory(szLog, 1024);
		sprintf(szLog, "GetRecordFileList ͨ��:%d", nChannelId);
		Log::instance().AddLog(string(szLog));

		int iCount = 0;
		ArchEventOpts opts;
		ZeroMemory(&opts, sizeof(opts));
		//ͨ����
		{
			opts.condList[iCount].key = DVX_SEARCH_KEY_CHANNEL;
			opts.condList[iCount].value.channel = 0;
			if (nChannelId != 0)
			{
				opts.condList[iCount].value.channel = (1 << (nChannelId - 1));
			}
			opts.condList[iCount++].op = 0;
		}
		//ʱ���ѡ��
		{
			opts.condList[iCount].key = DVX_SEARCH_KEY_TIME;
			opts.condList[iCount].value.timeRange.beginTime = (unsigned int)timeStart;
			opts.condList[iCount].value.timeRange.endTime = (unsigned int)timeEnd;
			opts.condList[iCount++].op = 0;
		}
		//����ѡ��
		{
			opts.condList[iCount].key = DVX_SEARCH_KEY_TYPE;
			opts.condList[iCount].value.type = 0;
			opts.condList[iCount++].op = 0;
		}
		//����λ������
		{
			opts.condList[iCount].key = DVX_SEARCH_KEY_DISK;
			opts.condList[iCount].value.disk = 0;
			opts.condList[iCount++].op = 0;
		}
		opts.count = iCount;
		unsigned int m_iTotal = 0;
        int iRet = dvxEventOpen((DvxHandle)m_lLoginHandle, &opts, &m_iTotal, 5 * 1000);
		if (iRet != 0)
		{
            m_sLastError = GetLastErrorString(iRet);
			Log::instance().AddLog(string("GetRecordFileList ��ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
			//continue;
		}

		if (m_iTotal <= 0)
		{
			Log::instance().AddLog(string("GetRecordFileList ��ѯ¼��ɹ���¼�����Ϊ0"));
            dvxEventClose((DvxHandle)m_lLoginHandle);
			continue;
		}
		FetchResult fr;
		ZeroMemory(&fr, sizeof(fr));
        iRet = dvxEventFetch((DvxHandle)m_lLoginHandle, 0, PAGE_SIZE, &fr);
		if (iRet != DVX_OK)
		{
            m_sLastError = GetLastErrorString(iRet);
			Log::instance().AddLog(string("GetRecordFileList 01 ��ѯ¼��ʧ�ܣ�����ԭ��") + m_sLastError);
            dvxEventClose((DvxHandle)m_lLoginHandle);
			continue;
		}
		if (fr.total <= 0)
		{
			Log::instance().AddLog(string("GetRecordFileList 01 ��ѯ¼��ɹ���¼�����Ϊ0"));
            dvxEventClose((DvxHandle)m_lLoginHandle);
			continue;
		}
		{
//			std::lock_guard<std::recursive_mutex> lock(m_mtx);
			RecordFile info;
			char szId[64];
			char szName[128];
			for (int i = 0; i < (int)fr.rowcount; i++)
			{
				if (MAX_SEARCH_COUNT < (i + fr.rowId + 1))
				{
					break;
				}
                ArcItem item = fr.rowList[i];

				//m_vecArcItem.push_back(fr.rowList[i]);
// 				ZeroMemory(szId, sizeof(szId));
// 				_i64toa((__int64)item.id, szId, 10);
				ZeroMemory(szName, sizeof(szName));
				sprintf(szName, "%u-%u_%d", item.beginTime, item.beginTime + item.period, nChannelId);
				info.channel = item.channel;
				info.size = item.size;
                info.name = szName;
				info.beginTime = item.beginTime;
				info.endTime = item.beginTime + item.period;
                info.setPrivateData(&item, sizeof(ArcItem));
				files.push_back(info);

				char szLog[1024];
				ZeroMemory(szLog, 1024);
				sprintf(szLog, "GetRecordFileList �ļ���:%s �ļ���С:%d ʱ��ƫ��:%c", szId, item.size, item.timeShift);
				Log::instance().AddLog(string(szLog));
			}
		}
        dvxEventClose((DvxHandle)m_lLoginHandle);
	}
	return true;
}



bool bluesky_videoserver::downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
{
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼";
		Log::instance().AddLog(string("downLoadByRecordFile ���ȵ�¼"));
        return false;
    }

    ArcItem &info = *((ArcItem*)file.getPrivateData());

	Log::instance().AddLog(string("downLoadByRecordFile �ļ���:") + saveFileName);
	RecordDumpOpenPara downParam;
	downParam.channel = info.channel;
	downParam.idxType = DVX_INDEXTYPE_DVX7_EVENT;
	memcpy( &downParam.index.item, &info, sizeof(ArcItem) );
	downParam.offset = 0;
	downParam.length = info.size;
	downParam.byteRate = 10 * 1024 * 1024;
    downParam.format = 1;

    downParam.type = info.type;
	downParam.bSaveAI = FALSE;

	DumpHandle hDump = 0;
    int iRet = dvxRecordDumpOpen((DvxHandle)m_lLoginHandle, &downParam, saveFileName, NULL, 0, &hDump, false);
    if (iRet != DVX_OK)
	{
        m_sLastError = GetLastErrorString(iRet);
		//Log::instance().AddLog(string("downLoadByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}
    iRet = dvxRecordDumpStart((DumpHandle)hDump);
    if (iRet != DVX_OK)
	{
        dvxRecordDumpClose((DumpHandle)hDump);
        m_sLastError = GetLastErrorString(iRet);
		//Log::instance().AddLog(string("downLoadByRecordFile 01 ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}
	hdl = (download_handle_t)hDump;
    std::lock_guard<std::recursive_mutex> lock(m_mtxPos);
    mDownloadFiles[hdl] = file;
	return true;
}


bool  bluesky_videoserver::PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
{
    if (0 >= m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼";
		Log::instance().AddLog(string("PlayBackByRecordFile ���ȵ�¼"));
        return false;
	}

    ArcItem &info = *((ArcItem*)file.getPrivateData());
	
	
	RecordPlayOpenPara Param;
	Param.channel = info.channel;
	Param.protocol= DVX_PROTOCAL_TCP;
	Param.ip = 0;
	Param.idxType = DVX_INDEXTYPE_DVX7_EVENT;
	memcpy( &Param.index.item, &info, sizeof(ArcItem) );
	Param.beginTime = info.beginTime;
	Param.peroid = info.period;
	Param.byteRate = 10 * 1024 * 1024; // 10MB

	PlayHandle hDump = 0;
    int iRet = dvxRecordOpen((DvxHandle)m_lLoginHandle, &Param, hwnd, NULL, 0, &hDump);
	if (iRet != 0 || hDump == 0)
	{
        m_sLastError = GetLastErrorString(iRet);
		Log::instance().AddLog(string("PlayBackByRecordFile ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}
    iRet = dvxRecordPlay((PlayHandle)hDump);
    if (iRet != DVX_OK)
	{
        dvxRecordClose((PlayHandle)hDump);
        m_sLastError = GetLastErrorString(iRet);
		Log::instance().AddLog(string("PlayBackByRecordFile 01 ����¼��ʧ�ܣ�����ԭ��") + m_sLastError);
		return false;
	}
	playbackHandle = (play_handle_t)hDump;

	char szLog[1024];
	ZeroMemory(szLog, 1024);
	sprintf(szLog, "PlayBackByRecordFile start playbackHandle:%d", playbackHandle);
	//Log::instance().AddLog(string("StopPlayBack ??????"));
	Log::instance().AddLog(string(szLog));
	return true;
}

bool bluesky_videoserver::SetPlayBack(__int64 playbackHandle, __int32 pos)
{

    __int64 msBegin = 0;
    __int64 msEnd = 0;
    int nRet = dvxRecordGetTime((PlayHandle)playbackHandle, &msBegin, &msEnd);
    if (DVX_OK != nRet || msBegin >= msEnd)
    {
        m_sLastError = GetLastErrorString(nRet);
        return false;
    }

    nRet = dvxRecordSeek((PlayHandle)playbackHandle, msBegin + (msEnd - msBegin) * pos / 100);
    if (DVX_OK != nRet)
    {
        m_sLastError = GetLastErrorString(nRet);
        return false;
    }

    return true;
}

bool bluesky_videoserver::StopPlayBack(__int64 playbackHandle, __int32 mPause)
{
    if (0 != m_lLoginHandle)
    {
		m_sLastError = "���ȵ�¼";
		Log::instance().AddLog(string("StopPlayBack ���ȵ�¼"));
        return false;
    }
	if (mPause == 1)
	{
		Log::instance().AddLog(string("StopPlayBack ��ʼ��ͣ����"));
        if (int iRet = dvxRecordPause((PlayHandle)playbackHandle))
		{
            m_sLastError = GetLastErrorString(iRet);
			Log::instance().AddLog(string("StopPlayBack ��ͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
			return false;
		}
	}
	else
	{
        if (int iRet = dvxRecordStop((PlayHandle)playbackHandle))
		{
            m_sLastError = GetLastErrorString(iRet);
			Log::instance().AddLog(string("StopPlayBack ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
		}
        PlayHandle h = (PlayHandle)playbackHandle;
        dvxRecordClose(h);
		playbackHandle = 0;
	}

    return true;
}

bool bluesky_videoserver::stopDownload(download_handle_t h)
{
	Log::instance().AddLog(string("stopDownload ��ʼֹͣ����"));
    if (int iRet = dvxRecordDumpStop((DumpHandle)h))
    {
        m_sLastError = GetLastErrorString(iRet);
		Log::instance().AddLog(string("stopDownload ֹͣ����ʧ�ܣ�����ԭ��") + m_sLastError);
    }
	DumpHandle hTmp = (DumpHandle)h;
    dvxRecordDumpClose(hTmp);
    std::lock_guard<std::recursive_mutex> lock(m_mtxPos);
    mDownloadFiles.erase(h);
    return true;
}

// bool bluesky_videoserver::getPlayBackPos(__int64 playbackHandle, __int32* pos)
// {
// 	if (0 >= m_lLoginHandle)
// 	{
// 		m_sLastError = "���ȵ�¼!";
// 		Log::instance().AddLog(string("getPlayBackPos ���ȵ�¼"));
// 		return false;
// 	}
// 
// 	RecordFile file;
// 	{
// 		std::lock_guard<std::recursive_mutex> lock(m_mtx);
// 		map<long long, RecordFile>::iterator itr = m_mapDownloadOrPlay.find(playbackHandle);
// 		if (itr == m_mapDownloadOrPlay.end())
// 		{
// 			m_sLastError = "���ļ�������";
// 			Log::instance().AddLog(string("getPlayBackPos ���ļ�������"));
// 			return false;
// 		}
// 		file = itr->second;
// 	}
// 
// 	std::lock_guard<std::recursive_mutex> lock(m_mtxPos);
// 	map<long long, stPos_DownPlay>::iterator itr = m_mapPosDownPlay.find(playbackHandle);
// 	if (itr != m_mapPosDownPlay.end())
// 	{
// 		__int64 iCurPos = 0;
// 		int iRet = Api_BlueSky::Api().PlayBackGetPos((PlayHandle)playbackHandle, &iCurPos);
// 		if (iRet != 0)
// 		{
// 			m_sLastError = GetLastErrorString();
// 			return false;
// 		}
// 
// 		int iPosTmp = ((float)iCurPos/(float)(file.endTime-file.beginTime))*100;
// 		itr->second.iPercent = iPosTmp;
// 		*pos = itr->second.iPercent;
// 		return true;
// 	}
// 	m_sLastError = "�Ҳ����ûط�";
// 	Log::instance().AddLog(string("getPlayBackPos �Ҳ����ûط�"));
// 	return false;
// }
// 
bool bluesky_videoserver::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
{
	if (0 >= m_lLoginHandle)
	{
		m_sLastError = "���ȵ�¼";
		Log::instance().AddLog(string("getDownloadPos ���ȵ�¼"));
		return false;
	}

	std::lock_guard<std::recursive_mutex> lock(m_mtxPos);
    std::map<long long, RecordFile>::iterator itr = mDownloadFiles.find(h);
    if (itr != mDownloadFiles.end())
	{
        int iRet = dvxRecordDumpPos((DumpHandle)h, currentSize);
		if (iRet != 0)
		{
            m_sLastError = GetLastErrorString(iRet);
			Log::instance().AddLog(string("��ȡ����ʧ�ܣ�")+m_sLastError);
			return false;
		}
        else{
           // Log::instance().AddLog(QString("download:%1, size:%2, total:%3").arg(h).arg(*currentSize).arg(itr->second.size));
        }
        *totalSize = itr->second.size;
        *failed = false;
		return true;
	}

	m_sLastError = "�Ҳ���������";
	Log::instance().AddLog(string("getDownloadPos �Ҳ���������"));
	*failed = true;
	return false;
}