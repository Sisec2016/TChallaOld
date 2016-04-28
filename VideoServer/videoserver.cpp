#include "videoserver.h"
#include <QCoreApplication>
#include <QList>
#include <QLibrary>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QProcess>
#include <qdebug.h>
#include "windowutils.h"
#include <QThread>
#include <eh.h>
#include <algorithm>
#include "xmlsettings.h"
#include <QTcpSocket>
#include "time.h"
#include "PublicsherServer.h"
#include "VideoserverSvrImp.h"

QDataStream & operator << (QDataStream &dataStream, RecordFile &d)
{
    dataStream<<d.beginTime;
    dataStream<<d.channel;
    dataStream<<d.endTime;
    dataStream<<QString::fromLocal8Bit(d.name.c_str());
    dataStream<<d.size;
    dataStream<<d.getPrivateDataSize();
    if (d.getPrivateDataSize() > 0)
    {
        dataStream.writeBytes((char*)d.getPrivateData(), d.getPrivateDataSize());
    }

    return dataStream;
}

QDataStream & operator >> (QDataStream &dataStream, RecordFile &d)
{
    dataStream>>d.beginTime;
    dataStream>>d.channel;
    dataStream>>d.endTime;
    QString qName;
    dataStream>>qName;
    d.name = qName.toStdString();
    dataStream>>d.size;
    dataStream>>d.PrivateDataDataSize;
    if (d.PrivateDataDataSize > 0)
    {
        uint bufLen = d.PrivateDataDataSize;
        dataStream.readBytes(d.pPrivateData, bufLen);
        d.PrivateDataDataSize = bufLen;
    }

    return dataStream;
}

QDataStream & operator << (QDataStream &dataStream, LoginServerInfo &d)
{
    dataStream << (qint32)d.factory << d.ip << d.macAddress << d.name << d.password
                  << d.port << d.user <<d.id;

    return dataStream;
}

QDataStream & operator >> (QDataStream &dataStream, LoginServerInfo &d)
{
    qint32 f = 0;
    dataStream >> f;
    d.factory = (DeviceFactory)f;
    dataStream >> d.ip >> d.macAddress >> d.name >> d.password
                                    >> d.port >> d.user >> d.id;

    return dataStream;
}


std::deque<videoserverFactory *> videoserverFactory::s_Factorys;
std::recursive_mutex videoserverFactory::s_mutexFactorys;
std::vector<std::string> videoserverFactory::s_vcExternFunStrings;

OEMFacMap videoserverFactory::m_OEMXMFacMap;   //����OEMϵ��
OEMFacMap videoserverFactory::m_OEMHIKFacMap;  //����OEMϵ��
OEMFacMap videoserverFactory::m_OEMDHFacMap;   //��OEMϵ��
OEMFacMap videoserverFactory::m_OEMWSDFacMap;  //���˴�OEMϵ��
OEMFacMap videoserverFactory::m_OEMJiuAnFacMap;  //�Ű�OEMϵ��
OEMFacMap videoserverFactory::m_OEMDongYangFacMap; //����OEMϵͳ
OEMFacMap videoserverFactory::m_OEMZhongWeiFacMap; //��άOEMϵ��




const std::deque<videoserverFactory*>& videoserverFactory::getFactorys()
{
    std::lock_guard<std::recursive_mutex> lock(s_mutexFactorys);
    if (s_vcExternFunStrings.size() == 0)
    {
        s_vcExternFunStrings.push_back(EXTERN_FUN_CAN_PLAY_BACK);
    }

    if (s_Factorys.size() == 0)
    {
        QDir dir(QApplication::applicationDirPath() + "/factorys");
        dir.setFilter(QDir::Dirs | QDir::NoSymLinks);
        QFileInfoList list = dir.entryInfoList();
        QStringList filters;
        filters << "*.dll";
        pfGetVideoServerFactory GetVideoServerFactory = nullptr;
         QString env(QString::fromLocal8Bit(::getenv("path")));
        for (int i = 0; i < list.size(); ++i) {
            const QFileInfo& fileInfo = list.at(i);
            if (fileInfo.isDir() && !fileInfo.fileName().startsWith("."))
            {
               
                QString envFile(fileInfo.filePath().replace("/", "\\"));
                if (env.indexOf(envFile) < 0)
                {
                    ::putenv(QString("path=%1;%2").arg(envFile).arg(env).toLocal8Bit());
                }

                QDir dirServer(fileInfo.filePath());
                dirServer.setFilter(QDir::Files | QDir::NoSymLinks);
                dirServer.setNameFilters(filters);
                QFileInfoList l = dirServer.entryInfoList();
                for (int j = 0; j < l.size(); j++)
                {
                    const QFileInfo& f = l.at(j);
                    GetVideoServerFactory = (pfGetVideoServerFactory)QLibrary::resolve(f.filePath(), "VideoServerFactory");
                    if (GetVideoServerFactory != nullptr)
                    {
                        IVideoServerFactory* pFactory = GetVideoServerFactory();
                        if (nullptr != pFactory)
                        {
                            videoserverFactory* pvsf = new videoserverFactory(pFactory);
                            s_Factorys.push_back(pvsf);
                            for (int k = 0; k < s_vcExternFunStrings.size(); k++)
                            {
                                pfExternFun ef = (pfExternFun)QLibrary::resolve(f.filePath(), s_vcExternFunStrings[k].c_str());
                                pvsf->addServerExterFun(s_vcExternFunStrings[k], ef);
                            }
							addFakeFactory(pFactory);
                        }
                        break;
                    }
                    else{
                        //Log::instance().AddLog(f.filePath() + "GetVideoServerFactory == nullptr");
                    }
                }

            }
        }

        s_Factorys.push_front(new videoserverFactory(nullptr));
    }

    return s_Factorys;
}

void videoserverFactory::initOEMFacList()
{
	// ������OEM
	{
		m_OEMXMFacMap["�޷�Ƽ�"] = SISC_IPC_JF;
		m_OEMXMFacMap["ʩ�Ͱ�"] = SISC_IPC_SNA;
		m_OEMXMFacMap["����"] = SISC_IPC_XM;
		m_OEMXMFacMap["����̩"] = SISC_IPC_HAISHITAI;
		m_OEMXMFacMap["�´ﹲ��"] = SISC_IPC_XINDAGONGCHUANG;
		m_OEMXMFacMap["���Ӵ�"] = SISC_IPC_TIANSHIDA;
		m_OEMXMFacMap["������"] = SISC_IPC_SHOUWEIZHE;
		m_OEMXMFacMap["����˼��"] = SISC_IPC_SILANG;
		m_OEMXMFacMap["����Τ��"] = SISC_IPC_HUONIWEIER;
		m_OEMXMFacMap["�Ƶ���"] = SISC_IPC_YUNDIANSHI;
		m_OEMXMFacMap["���ǰ���"] = SISC_IPC_SHIXINGANFANG;
		m_OEMXMFacMap["������"] = SISC_IPC_LIANDA;
		m_OEMXMFacMap["������̩"] = SISC_IPC_NANNINGGUANGTAI;
		m_OEMXMFacMap["�Ƶ���"] = SISC_IPC_YUNDIANSHI;
		m_OEMXMFacMap["�¼���"] = SISC_IPC_DEJIALA;


 		m_OEMXMFacMap["����ΰҵ"] = SISC_IPC_MEIFANGWEIYE;
 		m_OEMXMFacMap["��������"] = SISC_IPC_GUANGZHOUBANGSHI;
 		m_OEMXMFacMap["�Ӱ�����"] = SISC_IPC_GUANGZHOUSHIAN;
 		m_OEMXMFacMap["�ǰ��Ƽ�"] = SISC_IPC_QIAOAN;
// 		m_OEMXMFacMap["������"] = SISC_IPC_LANGSHIXIN;
// 		m_OEMXMFacMap["�ǰ�"] = SISC_IPC_YAAN;
 		m_OEMXMFacMap["̩���߿�"] = SISC_IPC_TAIWEIGAOKE;
// 		m_OEMXMFacMap["��������"] = SISC_IPC_GUANGZHOUYISHI;
// 		m_OEMXMFacMap["���ں꿵����OEM����"] = SISC_IPC_HONGKANGWEISHIOEMXM;
	}
	
	// ����OEM
	{
		m_OEMHIKFacMap["�㶫����"] = SISC_IPC_GUANGDONGLINYU;

// 		m_OEMHIKFacMap["���Ӱ�"] = SISC_IPC_KUANGSHIAN;
// 		m_OEMHIKFacMap["���ݺ���"] = SISC_IPC_GZHX;
// 
// 		m_OEMHIKFacMap["����ʢ"] = SISC_IPC_BAOXINGSHENG;
// 		m_OEMHIKFacMap["������OEM"] = SISC_IPC_LANDAOEMHK;
// 		m_OEMHIKFacMap["��������"] = SISC_IPC_XIANHAIFANG;
// 		m_OEMHIKFacMap["��������ʱ��"] = SISC_IPC_BEIJINGZHENGFANG;
// 		m_OEMHIKFacMap["̩��ΰҵOEM����"] = SISC_IPC_TAIKANGWEIYEOEMHK;
// 		m_OEMHIKFacMap["����"] = SISC_IPC_TIANMIN;
// 		m_OEMHIKFacMap["�ƶ�"] = SISC_IPC_KEEN;
// 		m_OEMHIKFacMap["������"] = SISC_IPC_ANJULIAO;
// 		m_OEMHIKFacMap["�������ڹ���"] = SISC_IPC_YIRONGGUANSHI;
// 		m_OEMHIKFacMap["�������ƽ̨"] = SISC_IPC_DONGDAJIZHI;
// 		m_OEMHIKFacMap["GEӲ��¼���"] = SISC_IPC_GERECORDER;
// 		m_OEMHIKFacMap["�����׿�61ϵ��"] = SISC_IPC_MIKA61;
// 		m_OEMHIKFacMap["�����׿�8081ϵ��NVR"] = SISC_IPC_MIKA8081;
// 		m_OEMHIKFacMap["����"] = SISC_IPC_HENGYI;
// 		m_OEMHIKFacMap["���ڰ˰�"] = SISC_IPC_BAAN;
// 		m_OEMHIKFacMap["���ڰٻ�"] = SISC_IPC_BAIHUI;
// 		m_OEMHIKFacMap["���ں��Ӱ�"] = SISC_IPC_HAISHIAN;
// 		m_OEMHIKFacMap["���ھ��J"] = SISC_IPC_JUFU;
// 		m_OEMHIKFacMap["��������"] = SISC_IPC_SAIQING;
// 		m_OEMHIKFacMap["�����˿ư�"] = SISC_IPC_XINGKEAN;
// 		m_OEMHIKFacMap["������"] = SISC_IPC_TIANTIANYOU;
	}
	
	// ���˴�OEM
	{
		m_OEMWSDFacMap["��������"] = SISC_IPC_XP;
	}
	
	// �Ű����OEM
	{
		m_OEMJiuAnFacMap["̩��ΰҵ"] = SISC_IPC_TAIKANGWEIYE;
	}
	
	// ��������OEM
	{
		m_OEMDongYangFacMap["�꿵����"] = SISC_IPC_HONGKANGWEISHI;
	}
	
	// ��άOEM
	{
		m_OEMZhongWeiFacMap["ʨ����Ѷ"] = SISC_IPC_SALX;
		m_OEMZhongWeiFacMap["��������"] = SISC_IPC_GZLL;
		m_OEMZhongWeiFacMap["���ﰲ��"] = SISC_IPC_ZHONGTIANANBAO;
		m_OEMZhongWeiFacMap["����"] = SISC_IPC_JIRUI;
		m_OEMZhongWeiFacMap["�����"] = SISC_IPC_HUABANGHAISHI;
	}
}

void videoserverFactory::addFakeFactory(IVideoServerFactory *pFactory)
{
	switch(pFactory->factory())
	{
		case SISC_IPC_DIZHIPU:
		{
			OEMFacMap::iterator itr = m_OEMXMFacMap.begin();
			for(itr; itr !=m_OEMXMFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}
		case SISC_IPC_HIKVISION:
		{
			OEMFacMap::iterator itr = m_OEMHIKFacMap.begin();
			for(itr; itr !=m_OEMHIKFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}
		case SISC_IPC_WSD:
		{
			OEMFacMap::iterator itr = m_OEMWSDFacMap.begin();
			for(itr; itr !=m_OEMWSDFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}
		case SISC_IPC_JIUAN:
		{
			OEMFacMap::iterator itr = m_OEMJiuAnFacMap.begin();
			for(itr; itr !=m_OEMJiuAnFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}
		case SISC_IPC_DOANGYANG:
		{
			 OEMFacMap::iterator itr = m_OEMDongYangFacMap.begin();
			for(itr; itr !=m_OEMDongYangFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}	
		case SISC_IPC_ZHONGWEI:
		{
			OEMFacMap::iterator itr = m_OEMZhongWeiFacMap.begin();
			for(itr; itr !=m_OEMZhongWeiFacMap.end(); itr++)
			{
				IVideoServerFactory* pOEMFactory = new OEMFactory((DeviceFactory)itr->second, true, (char *)itr->first.c_str(), pFactory);
				if (nullptr != pFactory)
				{
					videoserverFactory* pvsf = new videoserverFactory(pOEMFactory);
					s_Factorys.push_back(pvsf);
				}
			}
			
			break;
		}	
		default:
			break;
	}
}

videoserverFactory* videoserverFactory::getFactory(DeviceFactory f)
{
    //getFactorys();
    std::lock_guard<std::recursive_mutex> lock(s_mutexFactorys);
    for (int index = 0; index < s_Factorys.size(); index++)
    {
        if (s_Factorys[index]->factory() == f)
        {
            return s_Factorys[index];
        }
    }
    return nullptr;
}



void videoserverFactory::releaseVideoServerFactory()
{
    std::lock_guard<std::recursive_mutex> lock(s_mutexFactorys);
    for (int i = 0; i < s_Factorys.size(); i++)
    {
        delete s_Factorys[i];
    }
    s_Factorys.clear();
}

videoserverFactory::videoserverFactory(IVideoServerFactory *p)
    :  mpFactory(p), mInit(false)
{
	//initOEMFacList();
    sheInit();
}

videoserverFactory::~videoserverFactory()
{
    mpFactory->destroy();
}

videoserver* videoserverFactory::create()
{
    if (!mInit)
    {
        mInit = sheInit();
        mInit = true;
    }

    if (mInit)
    {
        if (nullptr == mpFactory)
        {
            return new videoserver(nullptr, this);
        }

        IVideoServer* pvr = mpFactory->create();
        if (pvr != nullptr)
        {
            return new videoserver(pvr, this);
        }

    }
    return nullptr;
}

IVideoServer* videoserverFactory::createDerect()
{
    if (!mInit)
    {
        mInit = sheInit();
        mInit = true;
    }

    if (mInit)
    {
        if (nullptr == mpFactory)
        {
            return nullptr;
        }

        return mpFactory->create();
    }

    return nullptr;
}

PlayBackPosCaculator::PlayBackPosCaculator()
{
    _time64(&mStartPlayTime);
}

int PlayBackPosCaculator::getPos()
{
    if (mPlaySeconds <= 0)
    {
        return 100;
    }

    __time64_t nowPlayTime;
    _time64(&nowPlayTime);

    __time64_t pos =  (nowPlayTime - mStartPlayTime) * 100 / mPlaySeconds;
    if (pos > 100)
    {
        return 100;
    }

    return pos;
}

void PlayBackPosCaculator::setPos(unsigned int pos)
{
    if (mPlaySeconds <= 0)
    {
        return;
    }

    __time64_t nowPlayTime;
    _time64(&nowPlayTime);

    mStartPlayTime = nowPlayTime - (pos * mPlaySeconds) / 100;
}

DownloadPosCaculator::DownloadPosCaculator()
{
    mTotalSize = 0;
}

int DownloadPosCaculator::getPos(__int64& totalSize, __int64& currentSize)
{
    QFile f(QString::fromLocal8Bit(mSaveFile.c_str()));
    if (f.exists())
    {
        currentSize = f.size();
    }
    else
    {
        currentSize = 0;
    }

    totalSize = mTotalSize;
    if (totalSize > 0 && totalSize >= currentSize)
    {
        return currentSize * 100 / totalSize;
    }

    return 100;
}

videoserver::videoserver(IVideoServer *p, videoserverFactory *f) :
    mpServer(p), mpFactory(f), mStop(false), mpThrDowload(nullptr)
{
}

videoserver::~videoserver()
{
    std::lock_guard<std::recursive_mutex> lockeThread(mMutexThread);
    if (mpThrDowload != nullptr)
    {
        mStop = true;
        mpThrDowload->join();
        delete mpThrDowload;
    }

}

//����ɾ������ʱ��¼������
void videoserver::remove()
{
	delete this;
}

videoserver* videoserver::clone()
{
    if (nullptr == mpServer)
    {
        return new videoserver(nullptr, mpFactory);
    }

    IVideoServer* p = mpServer->clone();
    if (p != nullptr)
    {
        videoserver* s = new videoserver(p, mpFactory);
		bool bStop = false;
		if (s->login(mpLoginInfo, &bStop))
        {
            return s;
        }
        else
        {
            s->destroy();
            return nullptr;
        }
    }

    return nullptr;
}
videoserver* videoserver::cloneDerect()
{
    if (nullptr == mpServer)
    {
        return new videoserver(nullptr, mpFactory);
    }

    IVideoServer* p = mpServer->clone();
    if (p != nullptr)
    {
        return new videoserver(p, mpFactory);
    }

    return nullptr;
}

bool videoserver::PlayBackByRecordFile(RecordFile& file, QWidget &w, play_handle_t& playbackHandle)
{
	return PlayBackByRecordFile(file, (HWND)w.winId(), playbackHandle);
}

bool videoserver::PlayBackByRecordFile(RecordFile& file, HWND hWnd, play_handle_t& playbackHandle){
	if (nullptr != mpServer)
	{
		if (!mpServer->PlayBackByRecordFile(file, hWnd, playbackHandle))
		{
			Log::instance().AddLog(QString("!PlayBackByRecordFile:") + QString::fromLocal8Bit(mpServer->getLastError()) + QString::fromLocal8Bit(file.name.c_str()));
			return false;
		}

		mMpPlayBackPosCaculators[playbackHandle].setPlaySeconds(file.endTime - file.beginTime);
		return true;
	}

	return false;
}

bool videoserver::SetPlayBack(play_handle_t playbackHandle, qint32 pos)
{

    if (nullptr != mpServer)
    {
        bool r = mpServer->SetPlayBack(playbackHandle, pos);
        if (!r)
        {
            addLog("SetPlayBack", __LINE__);
        }
        else
        {
            mMpPlayBackPosCaculators[playbackHandle].setPos(pos);
        }

        return r;
    }

    return false;

}

bool videoserver::getPlayBackPos(play_handle_t playbackHandle, qint32& pos)
{
    if (nullptr != mpServer)
    {
        bool r = mpServer->getPlayBackPos(playbackHandle, &pos);
        if (!r)
        {
            pos = mMpPlayBackPosCaculators[playbackHandle].getPos();
            return true;
        }
        return r;
    }

    return false;

}

bool videoserver::StopPlayBack(play_handle_t playbackHandle, int mPause)
{

    if (nullptr != mpServer)
    {
        bool r = mpServer->StopPlayBack(playbackHandle, mPause);
        if (!r)
        {
            addLog("StopPlayBack", __LINE__);
        }
        else
        {
            mMpPlayBackPosCaculators.erase(playbackHandle);
        }

        return r;
    }

    return false;

}


void getCommonFactorys(std::vector<videoserverFactory *>& factorys)
{
    factorys.clear();
    XmlSettings setings("cf");
    auto fs = videoserverFactory::getFactorys();
    std::vector< std::pair<int, int> > vcSorts;
    for (auto it = fs.begin(); it != fs.end(); it++)
    {
        videoserverFactory* pF = (*it);
		factorys.push_back(pF);
//         vcSorts.push_back(std::make_pair(pF->factory(),
//                                          setings.value(QString::number(pF->factory()), 0).toInt()));
    }
//     std::stable_sort(vcSorts.begin(), vcSorts.end(),
//               [](const std::pair<int, int>& f, const std::pair<int, int>& s)
//     {
//         return f.second > s.second;df
//     });

//     for (int i = 0; i < vcSorts.size(); i++)
//     {
//         factorys.push_back((DeviceFactory)vcSorts[i].first);
//     }
}

void plusCommonFactorySort(const std::vector<DeviceFactory>& factories, int index)
{
    if (index >= factories.size())
    {
        return;
    }

    XmlSettings setings("cf");
    int nSort = setings.value(QString::number(factories[index]), 0).toInt() + 1;
    setings.setValue(QString::number(factories[index]), nSort);
}
bool videoserver::login(const char* IP, __int32 port, const char* user,
    const char* password){
    Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, msg:%4, IP:%5, port:%6, user:%7, password:%8").arg(__FILE__)
        .arg(__FUNCTION__).arg(__LINE__).arg("login").arg(IP).arg(port).arg(user).arg(password));
    bool b = sheLogin(mpServer, IP, port, user, password);
    Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, msg:%4").arg(__FILE__)
        .arg(__FUNCTION__).arg(__LINE__).arg(b));
    return b;
}
bool videoserver::login(std::shared_ptr<LoginServerInfo> p, bool *pbStop)
{
	if (!p || *pbStop)
    {
        return false;
    }

    mpLoginInfo = p;

// 	if (LoginedServerProtect::set(this))
// 	{
// 		return true;
// 	}


    if (nullptr == mpServer)
    {
		std::vector<videoserverFactory *> factorys;
        getCommonFactorys(factorys);
        int nPort = 0;
        QString sUser;
        QString sPasswords;
		std::shared_ptr<LoginServerInfo> tmpLoginfo = std::make_shared<LoginServerInfo>();
        for (int i = 0; i < factorys.size(); i++)
        {
			if (*pbStop)
			{
				return false;
			}
			
			videoserverFactory *f = factorys[i];
            if (f != nullptr)
            {
				if ((mpFactory->name() == QString::fromLocal8Bit("����ʶ��")) && f->IsOEMFac())
				{
					continue;
				}

                IVideoServer* pServer = f->createDerect();
                if (pServer != nullptr)
                {
                    if (p->port == 0)
                    {
                        nPort = f->port();
                    }
                    else
                    {
                        nPort = p->port;
                    }

                    if (p->user == UNDEFIN_DEVICE_DEFAULT_USER)
                    {
                        sUser = f->defaultUser();
                    }
                    else
                    {
                        sUser = p->user;
                    }

                    if (p->password == UNDEFIN_DEVICE_DEFAULT_PASSWORD)
                    {
                        sPasswords = f->defaultPasswords();
                    }
                    else
                    {
                        sPasswords = p->password;
                    }
					
					if (sheLogin(pServer, p->ip.toStdString(), nPort, sUser.toStdString(), sPasswords.toStdString()))
                    {
						Log::instance().AddLog(QString("OK!") + mpFactory->name() + "," + f->name() + " " + p->ip);
                        mpServer = pServer;
                        this->mpFactory = f;
                        p->factory = f->factory();
						p->name = f->name() + "(" + p->ip + ")";
                        p->user = sUser;
                        p->password = sPasswords;
                        p->port = nPort;
                        //plusCommonFactorySort(factorys, i);
						mpLoginInfo = p;
						mpLoginInfo->ip = p->ip;
                        return true;
                    }
                    else
                    {
						Log::instance().AddLog(QString("Failed!") + mpFactory->name() + "," + f->name() + " " + p->ip);
                        pServer->destroy();
                    }
                }
            }

        }

        mLastError = "�޷�ʶ����豸!";
        return false;
    }

	if (p->user == UNDEFIN_DEVICE_DEFAULT_USER)
	{
		p->user = mpFactory->defaultUser();
	}

	if (p->password == UNDEFIN_DEVICE_DEFAULT_PASSWORD)
	{
		p->password = mpFactory->defaultPasswords();
	}

    if (sheLogin(mpServer, p->ip.toStdString(), p->port, p->user.toStdString(), p->password.toStdString()))
    {
        return true;
    }

    return false;
}


void videoserver::DealDownLoadCallback(download_handle_t h, quint64 totalSize, quint64 size, bool failed)
{
    if (nullptr == mpServer)
    {
        return;
    }

    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
    if (failed)
    {
        size = 0;
    }
    if (mEventReceivers.find(h) != mEventReceivers.end() && NULL != mEventReceivers[h])
    {
		PublicsherServer::instance().get()->publish().onDownloadPos((int64_t)mEventReceivers[h], VideoserverSvrImp::getPortByVideoServer(this),
			totalSize, size, failed);
    //    QCoreApplication::postEvent(mEventReceivers[h], new downloadEvent(this, totalSize, size, failed));
    }

    if (failed || totalSize <= size)
    {
        if (mEventReceivers.find(h) != mEventReceivers.end() && NULL != mEventReceivers[h])
        {
            stopDownload(mEventReceivers[h]);
        }
        else
        {
            mpServer->stopDownload(h);
        }
    }
}

void videoserver::SendDownLoadHeartbeat(download_handle_t h)
{
    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);

    if (mEventReceivers.find(h) != mEventReceivers.end() && NULL != mEventReceivers[h])
    {
		PublicsherServer::instance().get()->publish().onHeartbeat((int64_t)mEventReceivers[h], VideoserverSvrImp::getPortByVideoServer(this));
    }
}

void videoserver::DealDisconnectCallback()
{
    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
    for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin(); it != mEventReceivers.end();
         it++)
    {
        if (NULL != it->second)
        {
            this->logout();
			PublicsherServer::instance().get()->publish().onDisconnet((int64_t)it->second, VideoserverSvrImp::getPortByVideoServer(this));
           // QCoreApplication::postEvent(it->second, new disconnectEvent(this));
        }
    }
}

void videoserver::DealReconnectCallback()
{
    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
    for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin();
         it != mEventReceivers.end();
         it++)
    {
        if (NULL != it->second)
		{
			PublicsherServer::instance().get()->publish().onReconnet((int64_t)it->second, VideoserverSvrImp::getPortByVideoServer(this));
        }
    }
}
bool videoserver::reLogin(){
    //this->logout();
    return sheLogin(mpServer, mpLoginInfo->ip.toStdString(), mpLoginInfo->port, mpLoginInfo->user.toStdString(), mpLoginInfo->password.toStdString());
}

bool videoserver::logout()
{
    if (!stopDownloadAll())
    {
        return false;
    }

    if (nullptr != mpServer)
    {
		return mpServer->logout();
    }

    return true;

}

bool videoserver::GetRecordFileList(std::vector<RecordFile>& files, /*int nChannelId */ std::vector<int>& channelVec, const QDateTime& timeStart, const QDateTime& timeEnd)
{

    if (nullptr != mpServer)
    {
		bool r = mpServer->GetRecordFileList(files, channelVec, timeStart.toTime_t(), timeEnd.toTime_t());
        return r;
    }

    return false;

}

bool videoserver::GetRecordFileListZone(std::vector<RecordFile>& files, /*int nChannelId*/std::vector<int>& channelVec,
                           const QDateTime& timeStart, const QDateTime& timeEnd)
{
    for (QDate start(timeStart.date()); start <= timeEnd.date(); start = start.addDays(1))
    {
        std::vector<RecordFile> oneDayFiles;
		if (GetRecordFileList(oneDayFiles, channelVec, QDateTime(start, timeStart.time()),
                              QDateTime(start, timeEnd.time())))
        {
            for (int i = 0; i < oneDayFiles.size(); i++)
            {
                files.push_back(oneDayFiles[i]);
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool videoserver::downLoadByRecordFile(std::string filePath, const RecordFile& file, int64_t& hdl){
    return shedownLoadByRecordFile(filePath, file, hdl);
}
#define SLEEP_MILLISECONDE                      500
#define DISCONNECT_TIME                         1
#define CONNECTD_TIME                           20
bool videoserver::downLoad(const QString& saveFileName, const RecordFile& file, QObject* eventReceiver)
{
    if (nullptr == mpServer)
    {
        return false;
    }

    download_handle_t hdl;
    try
    {
        if (shedownLoadByRecordFile(saveFileName.toLocal8Bit().data(), file, hdl))
		{
            std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
            std::lock_guard<std::recursive_mutex> lockeThread(mMutexThread);
            mMpDownloadPosCaculators[hdl].init(file.size, saveFileName.toLocal8Bit().data());
            mEventReceivers[hdl] = eventReceiver;
            if (nullptr == mpThrDowload)
            {
                mpThrDowload = new std::thread([&](videoserver* pThis)
                {
                    int mTimes = 0;
                    int totalTime = 20;
                    bool isconnect = false;
                    qint64  totalSize = 0;
                    qint64 currentSize = 0;
                    bool failed = false;

                    while (!mStop)
                    {
						mTimes = mTimes + 2;
                        QThread::msleep(2000);
						if (mTimes >= totalTime)
						{
							isconnect = WindowUtils::isConnecteTo(pThis->ip());
							if (!isconnect)
							{
								//Log::instance().AddLog(QString("################### 05"));
								DealDisconnectCallback();
								//Log::instance().AddLog(QString("################### 06"));
								totalTime = DISCONNECT_TIME;
							}
                            else if (totalTime == DISCONNECT_TIME)
							{
                                isconnect = pThis->reLogin();
							}
                            else
							{
								totalTime = CONNECTD_TIME;
							}
							mTimes = 0;
						}

						if (!isconnect)
						{
							continue;
						}

                         std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
                         for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin();
                               it != mEventReceivers.end(); /*it++*/)
                         {
							 std::map<download_handle_t, QObject*>::iterator itTmp = it;
							 it++;
							 if (pThis->mpServer->getDownloadPos(itTmp->first, &totalSize, &currentSize, &failed))
                             {
								 DealDownLoadCallback(itTmp->first, totalSize, currentSize, failed);
                             }
                             else
                             {
							     pThis->mMpDownloadPosCaculators[itTmp->first].getPos(totalSize, currentSize);
								 DealDownLoadCallback(itTmp->first, totalSize, currentSize, failed);
                             }
                         }

                    }
                }, this);
            }

            return true;
        }
        else
        {
            return false;
        }
    }
    catch(...)
    {
		Log::instance().AddLog(QString("################### exception"));
        return false;
    }
}

bool videoserver::stopDownload(QObject* eventReceiver)
{
    if (nullptr != mpServer)
    {
        std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
        for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin();
             it != mEventReceivers.end(); it++)
        {
            if (it->second == eventReceiver)
            {
				mpServer->stopDownload(it->first);
				mMpDownloadPosCaculators.erase(it->first);
				it = mEventReceivers.erase(it);
				return true;
//                 if (mpServer->stopDownload(it->first))
// 				{
// 					mMpDownloadPosCaculators.erase(it->first);
// 					it = mEventReceivers.erase(it);
//                     return true;
//                 }
// 
//                 return false;
            }
        }
    }

    return true;
}
bool videoserver::stopDownload(__int64 downloadHandle){
    if (nullptr != mpServer)
    {
        return mpServer->stopDownload(downloadHandle);
    }

    return true;
}
bool videoserver::stopDownloadAll()
{
    if (nullptr == mpServer)
    {
        return true;
    }
    std::lock_guard<std::recursive_mutex> locker(mMutexEventRecievers);
    for (std::map<download_handle_t, QObject*>::iterator it = mEventReceivers.begin();
         it != mEventReceivers.end(); /*it++*/)
    {
        if (!mpServer->stopDownload(it->first))
        {
            return false;
        }
        else
        {
            it = mEventReceivers.erase(it);
        }
    }
    mStop = true;
    if (mpThrDowload)
    {
        mpThrDowload->join();
        delete mpThrDowload;
        mpThrDowload = nullptr;
    }
    
    return true;
}
bool videoserver::getPlayBackPos(__int64 playbackHandle, __int32* pos)
{
    if (nullptr == mpServer)
    {
        return false;
    }
    return mpServer->getPlayBackPos(playbackHandle, pos);
}

bool videoserver::getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
{
    return mpServer->getDownloadPos(h, totalSize, currentSize, failed);
}
QString videoserver::getChannelName(int channel)
{
    if (m_channels.find(channel) != m_channels.end())
    {
         QString s = QString::fromLocal8Bit(m_channels.at(channel).c_str());
         if (s.isEmpty())
         {
             s = QString::fromLocal8Bit("ͨ��%1").arg(channel);
         }
         s.replace(" ", "");
         return s;
    }

    return "";
}
QString videoserver::getFileName(const RecordFile &f)
{
    std::vector<QString> externs;
    mpFactory->videoFileExterns(externs);
    QString ext("mp4");
    if (externs.size() > 0)
    {
        ext = externs[0];
    }
    QString sBegin(QDateTime::fromTime_t(f.beginTime).toString(TIME_FORMAT));
    QString sEnd(QDateTime::fromTime_t(f.endTime).toString(TIME_FORMAT));
    return (QString("channel") + QString::number(f.channel) + QString("-") + sBegin.remove(QRegExp("[^0-9]")) +
        QString("-") + sEnd.remove(QRegExp("[^0-9]")) + "." + ext).trimmed();
}


OEMFactory::OEMFactory()
{
	m_name[32] = {0};
	m_FacID = SISC_IPC_UNDEFINE;
	m_OemFlag = false;
	m_pFactory = NULL;
}

OEMFactory::OEMFactory(DeviceFactory FacID, bool bOEMFlag, char *FacName, IVideoServerFactory *pFactory)
{
	m_FacID = FacID;
	m_OemFlag = bOEMFlag;
	strcpy_s(m_name, FacName);
	m_pFactory = pFactory;

 	m_port = 0;
	memset(m_usr, 0, strlen(m_usr));
	memset(m_pass, 0, strlen(m_pass));

	switch (m_FacID)
	{
	case SISC_IPC_GZLL:
	case SISC_IPC_JIRUI:
	case SISC_IPC_HUABANGHAISHI:
		strcpy_s(m_usr, "admin");
		strcpy_s(m_pass, "");
		m_port = 9101;
		break;
	case SISC_IPC_SALX:
		strcpy_s(m_usr, "admin");
		strcpy_s(m_pass, "123456");
		m_port = 34567;
		break;
	default:
		break;
	}
}

const char* OEMFactory::name()
{
	return m_name;
}

DeviceFactory OEMFactory::factory()
{
	return m_FacID;
}
