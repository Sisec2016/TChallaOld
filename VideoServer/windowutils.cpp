//#pragma comment(lib,"iphlpapi.lib")
//#pragma comment(lib,"wsock32.lib")
#include "windowutils.h"
//#include <winsock2.h>
#include <iphlpapi.h>
#include <QNetworkInterface>
#include "windows.h"
#include <tlhelp32.h>
#include <QString>

WindowUtils::WindowUtils()
{
}


bool WindowUtils::isValidNetMacaddress(const QString& macaddress)
{
    return !macaddress.isEmpty() && macaddress != "00:00:00:00:00:00:00:E0"
            && !macaddress.startsWith("00:50:56:C0");
}


void WindowUtils::getLocalIPs(std::vector<QString> &IPs)
{
    IPs.clear();
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface i, list) {
        if (i.isValid() && isValidNetMacaddress(i.hardwareAddress()))
        {
            foreach(QHostAddress address,i.allAddresses())
            {
                if (address.protocol() == QAbstractSocket::IPv4Protocol
                        && !address.isLoopback())
                {
                    if (IPs.end() == std::find(IPs.begin(), IPs.end(), address.toString()))
                    {
                        IPs.push_back(address.toString());
                    }
                }
            }
        }

    }
}

BOOL FindProcessByName(const char* szFileName, PROCESSENTRY32& pe)
{
    // ���ý��̿���ö�ٽ��̵ķ�������ָ�����ƽ���
    HANDLE hProcesses;
    PROCESSENTRY32 lpe =
    {
        sizeof(PROCESSENTRY32)
    };

    QString sFileName(QString::fromLocal8Bit(szFileName).toLower());

    // �������̿���
    hProcesses = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcesses == INVALID_HANDLE_VALUE)
        return FALSE;
    // ��ȡ��һ������ʵ��
    BOOL isExist = ::Process32First(hProcesses, &lpe);
    BOOL isRunning = FALSE;
    QString strName;
    while (isExist)
    {
        strName = QString::fromWCharArray(lpe.szExeFile).toLower();
        if (sFileName.indexOf(strName) >= 0)
        {
            isRunning = TRUE;
            break;
        }
        // ������һ������ʵ��
        isExist = ::Process32Next(hProcesses, &lpe);
    }

    if (isRunning)
    {
        memcpy(&pe, &lpe, sizeof(PROCESSENTRY32));
    }

    CloseHandle(hProcesses);

    return isRunning;
}

bool WindowUtils::findProcessByName(const char* szFileName){
    PROCESSENTRY32 pe;
    return FindProcessByName(szFileName, pe);
}

void WindowUtils::terminateProcess(const char* szFileName){
    HANDLE hProcesses;
    PROCESSENTRY32 lpe =
    {
        sizeof(PROCESSENTRY32)
    };

    QString sFileName(QString::fromLocal8Bit(szFileName).toLower());

    // �������̿���
    hProcesses = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcesses == INVALID_HANDLE_VALUE)
        return ;
    // ��ȡ��һ������ʵ��
    BOOL isExist = ::Process32First(hProcesses, &lpe);
    BOOL isRunning = FALSE;
    QString strName;
    while (isExist)
    {
        strName = QString::fromWCharArray(lpe.szExeFile).toLower();
        if (sFileName.indexOf(strName) >= 0)
        {
            HANDLE h = OpenProcess(1, TRUE, lpe.th32ProcessID);   //ȡ����ʵ�� PROCESS_TERMINATE
            TerminateProcess(h, 0);
        }
        // ������һ������ʵ��
        isExist = ::Process32Next(hProcesses, &lpe);
    }

    CloseHandle(hProcesses);
}