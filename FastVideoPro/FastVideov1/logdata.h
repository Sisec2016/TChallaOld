#ifndef LOGDATA_H
#define LOGDATA_H
#include <QString>
#include "SqlUtils.h"
#include "SqlTableMembers.h"

#define  LOG_DATA_TIME_FORMAT "yyyy-MM-dd hh:mm:ss"

#define  LOG_Download_STR  QStringLiteral("�ļ�����")
#define  LOG_FtpUpload_STR QStringLiteral("FTP�ϴ�")
#define  LOG_ShareExpt_STR QStringLiteral("������")
#define  LOG_DiskExpt_STR  QStringLiteral("Ӳ�̵���")
#define  LOG_ScreenRec_STR QStringLiteral("��Ļ¼��")
#define  LOG_NetConfig_STR QStringLiteral("��������")
#define  LOG_FileDel_STR   QStringLiteral("�ļ�ɾ��")
#define  LOG_NoDefine_STR   QStringLiteral("δ֪����")

class Logdata : public SqlTable<Logdata>
{
    SERIAL_MEMMBER_HEAD()
public:
    static bool WriteLog(const QString& operation, const QString& describe,
        const QString& mSrcDir = "", const QString& mDstDir = "");
public:
    Logdata();
    QString mUser;
    QString mTime;
    QString mOperation;
    QString mSrcDir;
    QString mDstDir;
    QString mDescribe;
};

#endif // EMPLOYEE_H
