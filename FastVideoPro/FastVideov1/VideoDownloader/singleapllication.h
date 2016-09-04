#ifndef SINGLEAPLLICATION_H
#define SINGLEAPLLICATION_H

#ifndef SINGLEAPPLICATION_H
#define SINGLEAPPLICATION_H

#include <QObject>
#include <QApplication>
#include <QtNetwork/QLocalServer>
#include <QWidget>
#include <QSharedMemory>

class SingleApplication : public QApplication {

        Q_OBJECT
        static SingleApplication* sInstance;
    public:
        SingleApplication(int &argc, char **argv, const QString& uniqueKey = "");

        bool isRunning();
        void setMainWidget(QWidget* mainW)
        {
            w = mainW;
        }
        static SingleApplication* instance()
        {
            return sInstance;
        }
        QWidget *mainWidget()
        {
           return w;
        }

protected:
        QWidget *w;
        QSharedMemory sharedMemory;
    private slots:
        void _newLocalConnection();

    private:
        void _initLocalConnection();
        void _newLocalServer();
        void _activateWindow();

        bool _isRunning;                // �Ƿ��ѽ���ʵ��������
        QLocalServer *_localServer;     // ����socket Server
        QString _serverName;            // ��������
};

#endif // SINGLEAPPLICATION_H

#endif // SINGLEAPLLICATION_H
