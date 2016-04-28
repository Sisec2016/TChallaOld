#ifndef LOGINEDSERVERPROTECT_H
#define LOGINEDSERVERPROTECT_H
#include <QString>
#include <map>
#include <mutex>
#include <memory>

class IVideoServer;
class videoserver;
class videoserverFactory;
class LoginServerInfo;

class LoginedServerProtect
{
    static std::recursive_mutex sMutexEvent;
    static std::map<QString, std::shared_ptr<LoginedServerProtect> > sLoginedServers;
public:
    LoginedServerProtect();
    static bool isLogined(videoserver* p);
    static bool set(videoserver* p);
    static bool add(videoserver* p);
	static void release(videoserver* p);
	//����ɾ������ʱ,�����¼��¼
	static void remove(videoserver* p);
    IVideoServer* getServer()
    {
        return mpIServer;
    }
    videoserverFactory* getFactory()
    {
        return mpFactory;
    }
protected:
    static  QString getServerTag(std::shared_ptr<LoginServerInfo> p);
    videoserver* mpvsServer;
    videoserverFactory* mpFactory;
    IVideoServer* mpIServer;
    std::map<qint32, std::string> m_channels;
};

#endif // LOGINEDSERVERPROTECT_H
