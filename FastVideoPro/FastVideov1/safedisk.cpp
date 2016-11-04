#include "safedisk.h"
#include <QMessageBox>
#include <QDebug>
#include <QApplication>
#include <QDir>
#include <QTime>
#include <vector>
#include <string>
#include <memory>

#include "SAGESSDDll.h"
#include "cwaitdlg.h"

#define DISK_LETTER_DATA   "D:"
#define PROCESS_NONE   -1
#define RETURN_FAILED  -1

SafeDisk* SafeDisk::s_pInstance = nullptr;

SafeDisk::SafeDisk()
{
    m_bInit = false;
    m_bLogin = false;
    memset(&m_safeDiskInfo, 0, sizeof(SafeDiskInfo));
    memset(&m_secDiskInfo, 0, sizeof(SecurityDiskInfo));
    memset(m_szPSN, 0, sizeof(m_szPSN));
    memset(m_szDeviceName, 0, sizeof(m_szDeviceName));
    m_hEventCreate = NULL;
    m_hEventMount = NULL;
    m_nProcessState = PROCESS_NONE;
    m_nProcessStateMount = PROCESS_NONE;
    m_cMountedDevice = MOUNT_NONE;

}

SafeDisk::~SafeDisk(){
    FreeSAGESSD_dll();
}

bool SafeDisk::init(){
    if (!m_bInit){
        if (0 != LoadSAGESSD_dll())
        {
            qDebug() << "0 != LoadSAGESSD_dll()";
            return false;
        }

        if (!MyDriverAttach()){
            return false;
        }

        char szSSDDeviceName[MAX_SAGE_SSD_COUNT][32];		//SSD�豸����������
        UINT32 nSSDDeviceNum;//SSD �豸����
        UINT32 retValue = EnumSageSSDDev(szSSDDeviceName, nSSDDeviceNum); //��ȡ���е�����SSD
        if (0 != retValue)
        {
            qDebug() << QStringLiteral("δ�ҵ����ܼ���SSD��");
            QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("δ�ҵ����ܼ���SSD��"));
            return false;
        }
        else if (1 < nSSDDeviceNum)
        {
            QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("��⵽������ܼ���SSD����γ�����SSD"));
            return false;
        }

        memcpy_s(m_szDeviceName, sizeof(m_szDeviceName), szSSDDeviceName[0], sizeof(szSSDDeviceName[0]));
        m_bInit = true;
    }

    return m_bInit;
}

#define MYWM_CREATE_VOLUME_FINISH						(WM_APP + 1)
#define MYWM_MOUNT_VOLUME_FINISH						(WM_APP + 2)
bool SafeDisk::nativeEvent(void *message){
    MSG* msg = reinterpret_cast<MSG*>(message);
    qDebug() << __FUNCTION__ << __LINE__;
    if (msg != nullptr){
        qDebug() << __FUNCTION__ << __LINE__ << msg->message;
        switch (msg->message) {
        case MYWM_CREATE_VOLUME_FINISH:
            qDebug() << __FUNCTION__ << " " << __LINE__ << " " << msg->wParam;
            m_nProcessState = msg->wParam;
            SetEvent(m_hEventCreate);
            break;
        case MYWM_MOUNT_VOLUME_FINISH:
            qDebug() << __FUNCTION__ << " " << __LINE__ << " " << msg->wParam;
            m_nProcessStateMount = msg->wParam;
            SetEvent(m_hEventMount);
            break;
        default:

            break;
        }
    }

    return true;
}
bool SafeDisk::verifyPasswd(const QString& sPassword){
    if (!init()){
        return false;
    }

    auto pw = sPassword.toStdString();
    BOOL isSuc = VerifyLoginPasswordA_SageAPI(m_szDeviceName, (char *)pw.c_str());
    if (!isSuc)
    {
        QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("�������"));
        return false;
    }

    return true;
}
bool SafeDisk::modifyPasswd(const QString& sNewPassword){

    UINT32 retValue = ModifyLoginPasswordA_SageAPI(m_szDeviceName, (CHAR*)sNewPassword.toStdString().c_str());

    return 0 == retValue;
}

bool SafeDisk::login(const QString& sPassword){
    if (!verifyPasswd(sPassword)){
        return false;
    }
    //��ȡ��ǰSSD��Ϣ
    ZeroMemory((void*)&m_safeDiskInfo, sizeof(SafeDiskInfo));
    int retValue = GetSafeDiskInfoFromDeviceA_SageAPI(m_szDeviceName, &m_safeDiskInfo);
    if (0 != retValue)
    {
        QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("��ȡSSD��Ϣʧ�ܣ�"));
        return false;
    }



    memset(m_szPSN, 0x00, 32);
    retValue = GetSageSSDPsn(m_szDeviceName, m_szPSN);
    if (0 != retValue)
    {
        QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("��ȡPSNʧ�ܣ�"));
        return false;
    }

    m_bLogin = true;
    return true;
}

bool SafeDisk::Mount(const QWidget& wd){
    if (!m_bLogin){
        qDebug() << "please login first";
        return false;
    }
    ZeroMemory((void*)&m_secDiskInfo, sizeof(SecurityDiskInfo));
    int retValue = GetSecurityDiskInfoFromDeviceA_SageAPI(m_szDeviceName, m_safeDiskInfo.m_nPCNumber, SECURITY_DISK_INFO_LEN_SECTOR, &m_secDiskInfo);
    if (0 == retValue)
    {
        qDebug() << (QString(QStringLiteral("��ǰPC�ϴ�����%1����ȫ����")).arg(m_secDiskInfo.m_nVirDiskCnt));
    }
    qDebug() << QStringLiteral("Mount");
    if (0 != retValue || m_secDiskInfo.m_nVirDiskCnt == 0)//
    {
        ZeroMemory((void*)&m_secDiskInfo, sizeof(SecurityDiskInfo));
        if (!CreateSafeDisk(wd))
        {
            return false;
        }
    }
    qDebug() << __FUNCTION__ << "  " << __LINE__;
    QString mountExe = QApplication::applicationDirPath() + "/MountVolume_Client.exe";
    mountExe.replace("/", "\\");
    std::shared_ptr<bool> bCanGoOn = std::make_shared<bool>(false);
    std::shared_ptr<bool> bFailed = std::make_shared<bool>(true);
    HWND h = (HWND)wd.winId();
    CWaitDlg::waitForDoing((QWidget*)&wd, QString::fromLocal8Bit("���ڹ��ذ�ȫ����..."), [=, this]()
    {
        for (UINT i = 0, j = 1; i < MAX_VIRDISK_NUM; i++)
        {
            qDebug() << __FUNCTION__ << __LINE__;
            if (EXIST_MARK != m_secDiskInfo.m_VirDiskInfo[i].m_IsExist)//�����־λ����������������ѭ��
            {
                qDebug() << __FUNCTION__ << __LINE__;
                continue;
            }

            MountSecurityDiskParam aMountParam;
            aMountParam.hwnd = h;
            int n = strlen((char*)m_secDiskInfo.m_VirDiskInfo[i].m_chFilePath); //��ȡstr���ַ���
            int len = MultiByteToWideChar(CP_ACP, 0, (char*)m_secDiskInfo.m_VirDiskInfo[i].m_chFilePath, n, NULL, 0);
            WCHAR *pWChar = new WCHAR[len + 1]; //���ֽ�Ϊ��λ
            MultiByteToWideChar(CP_ACP, 0, (char*)m_secDiskInfo.m_VirDiskInfo[i].m_chFilePath, n, pWChar, len);
            pWChar[len] = '\0'; //���ֽ��ַ���'\0'����
            memcpy(aMountParam.wDiskImageFilePath, (void*)pWChar, VDISK_NAME_LEN * 2);
            delete[] pWChar;
            qDebug() << __FUNCTION__ << __LINE__;
            memcpy(aMountParam.szKey, (BYTE*)m_safeDiskInfo.m_szKey, 32);
            aMountParam.nKeyLength = sizeof(m_safeDiskInfo.m_szKey);
            qDebug() << __FUNCTION__ << __LINE__;
            m_hEventMount = CreateEvent(NULL, FALSE, FALSE, NULL);
            qDebug() << __FUNCTION__ << __LINE__;
            UINT32 retValue = MountSecurityDiskW_SageAPI(mountExe.toStdWString().c_str(), aMountParam, L'M');
            if (0 != retValue)
            {
                *bFailed = false;
                qDebug() << __FUNCTION__ << __LINE__;
                CloseHandle(m_hEventMount);
                *bCanGoOn = true;
                return;
            }
            qDebug() << __FUNCTION__ << __LINE__;
            retValue = WaitForSingleObject(m_hEventMount, 80000);
            qDebug() << __FUNCTION__ << __LINE__;

            CloseHandle(m_hEventMount);
            switch (retValue)
            {
            case WAIT_OBJECT_0:
                if (2 == m_nProcessStateMount)
                {
                    m_cMountedDevice = 'M';
                    m_secDiskInfo.m_VirDiskInfo[i].m_nIsMount = 1;
                    m_secDiskInfo.m_VirDiskInfo[i].m_chDiskLetter = 'M';
                }
                else{
                    m_secDiskInfo.m_nVirDiskCnt--;
                    if (m_secDiskInfo.m_nVirDiskCnt < 0)
                    {
                        m_secDiskInfo.m_nVirDiskCnt = 0;
                    }
                }
                m_nProcessStateMount = MESSAGE_NO_COME;
                *bFailed = false;
                qDebug() << __FUNCTION__ << "  " << __LINE__ ;
                *bCanGoOn = true;
                return; //break the loop
            case SAGE_API_ERR_LETTER_NO_EXIST:
                qDebug() << __FUNCTION__ << "  " << __LINE__ ;
                *bCanGoOn = true;
                return;
            default:
                DWORD nErr = GetLastError();
                m_secDiskInfo.m_VirDiskInfo[i].m_nIsMount = 0;
                m_secDiskInfo.m_VirDiskInfo[i].m_chDiskLetter = 0;
                qDebug() << __FUNCTION__ << "  " << __LINE__ << "error:" << nErr;
                *bCanGoOn = true; 
                *bFailed = nErr != 0;
                return; // unexpected failure
            }

            j++;
        }
        *bCanGoOn = true;
    }, [=,this](bool){
        if (*bFailed){
            QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("�޷���ȡϵͳ�����̷������ְ�ȫ���޷����أ�\r\n�����Գ����������Բ�����"));
        }
        *bCanGoOn = true;
    });
    

    while (!(*bCanGoOn)){
        qDebug() << __FUNCTION__ << __LINE__;
        ::Sleep(500);
    }
    if (*bFailed){
        return false;
    }
    SetSecurityDiskInfoA_SageAPI(m_szDeviceName, m_safeDiskInfo.m_nPCNumber, SECURITY_DISK_INFO_LEN_SECTOR, &m_secDiskInfo);//�޸ı�PC�ϵİ�ȫ����Ϣ
    return true;

}


bool SafeDisk::CreateSafeDisk(const QWidget& wd)
{
    std::shared_ptr<UINT32> pRetValue = std::make_shared<UINT32>(0);
    std::shared_ptr<bool> bCanGoOn = std::make_shared<bool>(false);
    ++m_safeDiskInfo.m_nPCNumber;
    QString createExe = QApplication::applicationDirPath() + "/CreateVolume_Client.exe";
    createExe.replace("/", "\\");
    VirDiskInfo& vdi = m_secDiskInfo.m_VirDiskInfo[0];
    vdi.m_nIsMount = 0x01;
    //������ȫ������洢�ļ���
    QDir d(DISK_LETTER_DATA"/VultureSafeArea");
    if (!d.exists())
    {
        d.mkpath(DISK_LETTER_DATA"/VultureSafeArea");
        SetFileAttributesA(DISK_LETTER_DATA"\\VultureSafeArea", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM); //����
    }


    UINT32 nRandomNum = QTime::currentTime().msec();
    sprintf_s((char*)vdi.m_chFilePath, VDISK_NAME_LEN, "%s\\VultureSafeArea\\%s_%dfdisk.img",
        DISK_LETTER_DATA, m_szPSN, nRandomNum);

    CHAR chLetter = 'L';
    *pRetValue = GetVailLunA_SageAPI(&chLetter, 'M');//��ȡһ�������̷�
    if (0 != *pRetValue)
    {
        QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("�޷���ȡϵͳ�����̷������������Ժ������"));
        *pRetValue = RETURN_FAILED;
        goto EXIT2;
    }
    vdi.m_chDiskLetter = chLetter;

    CreateSecurityDiskParam securityDiskParam;
    securityDiskParam.hwnd = (HWND)wd.winId();
    securityDiskParam.iDriverNo = chLetter - 65;

    ULARGE_INTEGER FreeAv, TotalBytes, FreeBytes;
    if (!GetDiskFreeSpaceExA(DISK_LETTER_DATA, &FreeAv, &TotalBytes, &FreeBytes))
    {
        QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("��Ҫ��D�̷�����������ȫ����"));
        *pRetValue = RETURN_FAILED;
        goto EXIT2;
    }

    securityDiskParam.nDiskCapacity = ((double)FreeBytes.QuadPart) / 1024 / 1024;
    int n = strlen((char*)vdi.m_chFilePath); //��ȡstr���ַ���
    int len = MultiByteToWideChar(CP_ACP, 0, (char*)vdi.m_chFilePath, n, NULL, 0);
    WCHAR *pWChar = new WCHAR[len + 1]; //���ֽ�Ϊ��λ
    MultiByteToWideChar(CP_ACP, 0, (char*)vdi.m_chFilePath, n, pWChar, len);
    pWChar[len] = '\0'; //���ֽ��ַ���'\0'����
    memcpy(securityDiskParam.wDiskImageFilePath, (void*)pWChar, VDISK_NAME_LEN * 2);
    delete[] pWChar;

    securityDiskParam.nDiskSysType = FILESYS_FAT;
    securityDiskParam.bQuickFormate = TRUE;
    memcpy(securityDiskParam.szKey, m_safeDiskInfo.m_szKey, 32);
    securityDiskParam.nKeyLength = sizeof(m_safeDiskInfo.m_szKey);

    m_hEventCreate = CreateEvent(NULL, FALSE, FALSE, NULL);
    qDebug() << __FUNCTION__ << " " << __LINE__ << " " << createExe << " " << QString::fromWCharArray(securityDiskParam.wDiskImageFilePath) << " " << securityDiskParam.iDriverNo
        << " " << securityDiskParam.nDiskCapacity;
    *pRetValue = CreateSecurityDiskW_SageAPI(createExe.toStdWString().c_str(), securityDiskParam);
    if (*pRetValue == 0)
    {
        QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("������ȫ�����̳���"));
        *pRetValue = RETURN_FAILED;
        goto EXIT2;
    }

    CWaitDlg::waitForDoing(nullptr, QString::fromLocal8Bit("���ڴ�����ȫ����..."), [=]()
    {
        *pRetValue = WaitForSingleObject(m_hEventCreate, 80000);
        UnMountAllVolume();
        *bCanGoOn = true;
    }, [](bool){});

    while (!(*bCanGoOn)){
        ::Sleep(500);
    }

    switch (*pRetValue)
    {
    case WAIT_OBJECT_0:
        // hProcess������Ľ�����80���ڽ���
        if (m_nProcessState != 0)
        {
            m_nProcessState = MESSAGE_NO_COME;
            GetSafeDiskInfoFromDeviceA_SageAPI(m_szDeviceName, &m_safeDiskInfo);//��ȡUSB�豸��Ϣ
            *pRetValue = RETURN_FAILED;
            QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("����ʧ�ܣ�"));
            goto EXIT2;
        }
        break;
    case WAIT_TIMEOUT:
        // �ȴ�ʱ�䳬��80��
        m_nProcessState = MESSAGE_NO_COME;
        GetSafeDiskInfoFromDeviceA_SageAPI(m_szDeviceName, &m_safeDiskInfo);//��ȡUSB�豸��Ϣ
        QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("����������ʱ���أ�"));
        *pRetValue = RETURN_FAILED;
        goto EXIT2;
        break;
    case WAIT_FAILED:
        // ��������ʧ�ܣ����紫����һ����Ч�ľ��
        m_nProcessState = MESSAGE_NO_COME;
        GetSafeDiskInfoFromDeviceA_SageAPI(m_szDeviceName, &m_safeDiskInfo);//��ȡUSB�豸��Ϣ

        QMessageBox::information(nullptr, QStringLiteral("��Ϣ"), QStringLiteral("����ʧ�ܣ������أ�"));
        *pRetValue = RETURN_FAILED;
        goto EXIT2;
        break;
    }

    qDebug() << __FUNCTION__ << " " << __LINE__;
    m_safeDiskInfo.m_nCurIndex = m_safeDiskInfo.m_nPCNumber;
    m_safeDiskInfo.m_nBlockIndex[m_safeDiskInfo.m_nPCNumber] = EXIST_MARK;
    SetSafeDiskInfoA_SageAPI(m_szDeviceName, &m_safeDiskInfo);//�޸�U����Ϣ


    //�޸ľ�������
    //    USES_CONVERSION ;
    char strTemp[32];
    sprintf(strTemp, "%c:\\", chLetter);
    SetVolumeLabelA(strTemp, (char*)vdi.m_chDiskName);

    ++m_secDiskInfo.m_nVirDiskCnt;
    vdi.m_IsExist = EXIST_MARK;
    memcpy(m_secDiskInfo.m_szPSN, m_szPSN, 32);
    SetSecurityDiskInfoA_SageAPI(m_szDeviceName, m_safeDiskInfo.m_nPCNumber,
        SECURITY_DISK_INFO_LEN_SECTOR, &m_secDiskInfo);//�޸ı�PC�ϵİ�ȫ����Ϣ
    *pRetValue = securityDiskParam.iDriverNo;
    qDebug() << __FUNCTION__ << " " << __LINE__;
EXIT2:
    CloseHandle(m_hEventCreate);
    m_hEventCreate = NULL;
    if (m_secDiskInfo.m_nVirDiskCnt > 0) //��ȫ��������ʱ����Ҫ������������
    {
        GetSecurityDiskInfoFromDeviceA_SageAPI(m_szDeviceName, m_safeDiskInfo.m_nPCNumber,
            SECURITY_DISK_INFO_LEN_SECTOR, &m_secDiskInfo);
    }

EXIT1:
    return *pRetValue != RETURN_FAILED;;
}
void SafeDisk::unMountAll(){
    UnMountAllVolume();
}
bool SafeDisk::MyDriverAttach()
{
    //�жϲ���ϵͳ32 ��64
    BOOL bWow64 = TRUE;
    typedef BOOL(__stdcall *LPFN_ISWOW64PROCESS) (HANDLE hProcess, PBOOL Wow64Process);
    LPFN_ISWOW64PROCESS fnIsWow64Process;
    fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandleA("kernel32"), "IsWow64Process");

    if (fnIsWow64Process != NULL)
    {
        if (!fnIsWow64Process(GetCurrentProcess(), &bWow64)){
            bWow64 = FALSE;
        }
    }

    QString createDriver = QApplication::applicationDirPath();
    createDriver.replace("/", "\\");
    if (bWow64)
    {
        createDriver += "\\sagedisks-x64.sys";
    }
    else
    {
        createDriver += "\\sagedisks.sys";
    }

    UINT32 retValue = MyDriverAttachW_SageAPI((WCHAR*)createDriver.toStdWString().c_str());
    if (0 != retValue)
    {
        qDebug() << QStringLiteral("����������װ�����ʧ�ܣ�·����") << createDriver;
        return false;
    }
    else
    {
        qDebug() << QStringLiteral("����������װ����سɹ���·����") << createDriver;
        return true;
    }
}
