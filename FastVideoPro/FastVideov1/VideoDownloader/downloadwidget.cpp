#include "downloadwidget.h"
#include "ui_downloadwidget.h"
#include "windowutils.h"
#include <QMessageBox>
#include "customEvent.h"
#include "messageboxdlg.h"
#include "screenadaption.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "IPHLPAPI.lib")

#include <iphlpapi.h>

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

DownloadWidget::DownloadWidget(std::shared_ptr<videoserver> pServer, const QString& filePath, const QString& name, const QString& startTime,
                               const QString& endTime, const int& channel, QWidget *parent) :
    mDownloading(true),
    iChannel(channel),
    QWidget(parent),
    ui(new Ui::DownloadWidget),
    beg(QDateTime::currentDateTime()),
    mLastDownloadSize(0),
    mLastFailedDownloadSize(0),
    mTotalSize(0),
    mDownloadSize(0),
    strfilePath(filePath),
    mpSvr(pServer),
    mTask(nullptr),
    mBeatTime(0)
{
    last = beg;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    int index = name.indexOf("\\");
    if (index >= 0)
    {
         ui->nameLabel->setText(name.right(name.length() - index - 1));
    }
    else
    {
        ui->nameLabel->setText(name);
        ui->nameLabel->setToolTip(name);
    }

    ScreenAdaption::instance().adpte(this);
}

DownloadWidget::DownloadWidget():
mDownloading(true),
ui(new Ui::DownloadWidget),
beg(QDateTime::currentDateTime()),
mLastDownloadSize(0),
mLastFailedDownloadSize(0),
mTotalSize(0),
mDownloadSize(0),
mTask(nullptr),
mBeatTime(0)
{
	last = beg;
	ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground);

	ScreenAdaption::instance().adpte(this);
}

DownloadWidget::~DownloadWidget()
{
    delete ui;
}
#define MAX_MISS_BYTES (1024 * 1024 * 2)
#define MAX_HEARTBEAT_TIME 20000
void DownloadWidget::heartBeat()
{
    std::lock_guard<std::recursive_mutex> lock(this->mMutexHeartBeat);
    if (0 == mBeatTime)
    {
        mBeatTime = GetTickCount();
    }
    if ((GetTickCount() - mBeatTime >= MAX_HEARTBEAT_TIME) && this->mDownloading)
    {
        Log::instance().AddLog(QString("File:%1, Function:%2, Line:%3, download_timeout:%4").arg(__FILE__)
            .arg(__FUNCTION__).arg(__LINE__).arg(QString("progress:") + QString::number(ui->progressBar->value()) + " letf_time: " + ui->timeLabel->text()));

        if (nullptr != mpSvr)
        {
            this->mpSvr->stopDownload(this);

        }

       
        bool bComplete = false;
        auto progress = ui->progressBar->value();
        if (progress >= 97)
        {
            auto leftSize = mTotalSize - mDownloadSize;
            bComplete = (leftSize <= MAX_MISS_BYTES);
        }
        if (!bComplete && mLastFailedDownloadSize > 0 && progress > 80)
        {
            bComplete = (mLastFailedDownloadSize == mDownloadSize);
        }
        if (bComplete)
        {
             QCoreApplication::postEvent(this, new downloadEvent(mpSvr.get(), mDownloadSize, mDownloadSize, false));
        }
        else
        {
            mLastFailedDownloadSize = mDownloadSize;
            this->mDownloading = false;
            this->mpSvr->reLogin();
            this->mDownloading = true;
            QCoreApplication::postEvent(this, new downloadEvent(mpSvr.get(), 0, 0, true));
            
        }
        
        mBeatTime = GetTickCount();
    }

}

bool DownloadWidget::dealHeartbeat(QEvent* event)
{
    downloadEvent* edownload = dynamic_cast<downloadEvent *> (event);
    if (edownload != nullptr && !edownload->m_failed )
    {
        if (edownload->m_size != mDownloadSize)
        {
            std::lock_guard<std::recursive_mutex> lock(this->mMutexHeartBeat);
            mBeatTime = GetTickCount();
        }
    }


    return false;
}


void DownloadWidget::customEvent(QEvent* event)
{
    if (!this->mDownloading || dealHeartbeat(event))
    {
        return;
    }

    downloadEvent* edownload = dynamic_cast<downloadEvent *> (event);


    disconnectEvent* edisconnect = NULL;
    reconnectEvent* ereconnect = NULL;

    if (edownload != NULL)
    {
        if (!edownload->m_failed && edownload->m_size > edownload->m_totalSize)
        {
            edownload->m_size = edownload->m_totalSize;
        }

        if (mTask != nullptr && !edownload->m_failed &&  edownload->m_size <= edownload->m_totalSize)
        {
            QCoreApplication::postEvent(mTask, new taskEvent(this, edownload->m_size - mDownloadSize, edownload->m_failed));
        }
        mDownloadSize = edownload->m_size;
        mTotalSize = edownload->m_totalSize;
        if (!edownload->m_failed)
        {

            int totalM = edownload->m_totalSize / KBS_ONE_M / BYTES_ONE_KB;
            if (totalM > 0)
            {
                ui->sizeLabel->setText(QString("%1M").arg(totalM));
            }
            else
            {
                ui->sizeLabel->setText(QString("%1KB").arg(edownload->m_totalSize / BYTES_ONE_KB));
            }

            if (edownload->m_size >= edownload->m_totalSize)
            {
                edownload->m_size = edownload->m_totalSize;
            }

            QDateTime end(QDateTime::currentDateTime());
            qint64 msecs = last.msecsTo(end);
            if (msecs > 500)
            {

                qint64 v = (edownload->m_size - this->mLastDownloadSize) * 1000 / (msecs * 1.0) / BYTES_ONE_KB;
                int vM = v / KBS_ONE_M;

                this->last = end;
                mLastDownloadSize = edownload->m_size;
                ui->progressBar->setValue(edownload->m_size);				

                if (vM > 0)
                {
					DWORD dwPerSpeed = 0;
					//获取当前网卡的网速
					dwPerSpeed = this->getMaxDownloadSpeed() / 1000 / 1000 / BIT_ONE_BYTE;

					//增加限速	
					if (vM > dwPerSpeed)
					{
						vM = static_cast<int>(dwPerSpeed);
					}

                    ui->speedLabel->setText(QString("%1M/S").arg(vM));
                }
                else
                {
                    ui->speedLabel->setText(QString("%1KB/S").arg(v));
                }

                if (v > 0)
                {
                    int leftsecs = (edownload->m_totalSize - edownload->m_size) / v / BYTES_ONE_KB;
                    ui->timeLabel->setText(QString::fromLocal8Bit("%1分%2秒").arg(leftsecs / 60).arg(leftsecs % 60));
                    if (leftsecs == 0 && v < 2000 &&  (edownload->m_size * 100 / edownload->m_totalSize) >= 99)
                    {
                        edownload->m_size = edownload->m_totalSize;
                    }
                }
               
            }

            if (edownload->m_size < edownload->m_totalSize)
            {
                this->mDownloading = true;
                ui->statusLabel->setText(QString::fromLocal8Bit("下载中"));
            }

			//增加控制,防止进度条回滚
			int nProgress = edownload->m_size * 100 / edownload->m_totalSize;

			if (nProgress > ui->progressBar->value())
			{
				ui->progressBar->setValue(nProgress);
			}
            
            if(ui->progressBar->value() == 100)
            {
                if((ui->speedLabel->text().toUpper()=="0M/S") || (ui->speedLabel->text().toUpper()=="0KB/S"))
                {
                    ui->speedLabel->setText(QString("%1/S").arg(ui->sizeLabel->text()));
                }
            }

            if (edownload->m_size >= edownload->m_totalSize)
            {
                ui->statusLabel->setText(QString::fromLocal8Bit("完成"));
                QPalette pe;
                pe.setColor(QPalette::WindowText, Qt::green);
                ui->statusLabel->setPalette(pe);

                mLastDownloadSize = edownload->m_totalSize;
                this->mDownloading = false;
                ui->progressBar->setValue(100);
                ui->timeLabel->setText(QString::fromLocal8Bit("0分0秒"));
                if (nullptr != mpSvr)
                {
                    this->mpSvr->stopDownload(this);

                }
                emit finished(this,iChannel, true);
            }
        }
        else if (edownload->m_failed)
        {
            if (mTask != nullptr)
            {
                QCoreApplication::postEvent(mTask, new taskEvent(this, 0, true));
            }
            ui->statusLabel->setText(QString::fromLocal8Bit("等待中"));
            if (nullptr != mpSvr)
            {
                this->mpSvr->stopDownload(this);

            }
            emit finished(this, iChannel, false);
        }
    }
    else if ((edisconnect = dynamic_cast<disconnectEvent *> (event)) != NULL)
    {
        if (this->mDownloading)
        {
            ui->statusLabel->setText(QString::fromLocal8Bit("掉线"));
        }
    }
    else if ((ereconnect = dynamic_cast<reconnectEvent *> (event)) != NULL)
    {
        if (this->mDownloading)
        {
            ui->statusLabel->setText(QString::fromLocal8Bit("下载中"));
        }
    }

    if(ui->progressBar->value() == 100)
    {
        ui->statusLabel->setText(QString::fromLocal8Bit("完成"));
		ui->speedLabel->setText(QString("0M/S"));		
    }

}
/*
 * 构造函数取消下载
 *  @return void
 */
void DownloadWidget::on_cancelButton_clicked()
{
    MessageBoxDlg msgDlg(QString::fromLocal8Bit("下载任务还没完成,是否确要取消？") , MsgButton::Yes, MsgButton::No);
    msgDlg.exec();
    if (mDownloading && msgDlg.isConfirm() != MsgButton::Yes)
    {
        return;
    }


    if (mDownloading && !mpSvr->stopDownload(this))
    {
        //QMessageBox::about(this,  tr("prompt"), mpSvr->getLastError());
        MessageBoxDlg msgDlg(mpSvr->getLastError());
        msgDlg.exec();
        return;
    }
    this->mDownloading = false;
    if (nullptr != mpSvr)
    {
        this->mpSvr->stopDownload(this);

    }
    emit finished(this, iChannel, false, true);
    this->close();
    this->deleteLater();
}

void DownloadWidget::cancel()
{
    if (mDownloading && mpSvr)
    {
        mpSvr->stopDownload(this);
        mDownloading = false;
    }
}

void DownloadWidget::setStatus(const QString& s)
{
    ui->statusLabel->setText(s);
}

void DownloadWidget::setSource(const QString& s)
{

}

QDataStream & operator << (QDataStream &dataStream, DownloadWidget &d)
{
    dataStream << d.mLastDownloadSize;
    dataStream << d.mDownloadSize;
    dataStream << d.mLastFailedDownloadSize;
    dataStream << d.mTotalSize;
    dataStream << d.strfilePath;
    dataStream << d.iChannel;
    dataStream << d.ui->nameLabel->text();
    dataStream << d.ui->progressBar->value();
    dataStream << d.ui->sizeLabel->text();
    dataStream << d.ui->statusLabel->text();

    return dataStream;
}

QDataStream & operator >> (QDataStream &dataStream, DownloadWidget &d)
{
    dataStream >> d.mLastDownloadSize;
    dataStream >> d.mDownloadSize;
    dataStream >> d.mLastFailedDownloadSize;
    dataStream >> d.mTotalSize;
    dataStream >> d.strfilePath;
    dataStream >> d.iChannel;
    QString text;
    dataStream >> text;
    d.ui->nameLabel->setText(text);
    int value = 0;
    dataStream >> value;
    d.ui->progressBar->setValue(value);
    dataStream >> text;
    d.ui->sizeLabel->setText(text);
    dataStream >> text;
    d.ui->statusLabel->setText(text);
    d.mpSvr = nullptr;
    return dataStream;
}

void DownloadWidget::initSpeed()
{
	ui->speedLabel->setText(QString("0M/S"));
}

DWORD DownloadWidget::getMaxDownloadSpeed()
{
	DWORD dwSize = 0;
	DWORD dwRetValDes = 0;
	DWORD dwSpeed = 0;

	PIP_ADAPTER_INFO pAdapterInfo;
	PIP_ADAPTER_INFO pAdapter = NULL;
	DWORD dwRetValSrc = 0;

	MIB_IFTABLE *pIfTable = NULL;
	MIB_IFROW *pIfRow = NULL;

	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
	pAdapterInfo = (IP_ADAPTER_INFO *)MALLOC(sizeof(IP_ADAPTER_INFO));

	if (NULL == pAdapterInfo)
	{
		return 1;
	}

	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		FREE(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO *)MALLOC(ulOutBufLen);
		if (NULL == pAdapterInfo)
		{
			return 1;
		}
	}

	pIfTable = (MIB_IFTABLE *)MALLOC(sizeof(MIB_IFTABLE));
	if (pIfTable == NULL)
	{
		return 1;
	}

	dwSize = sizeof(MIB_IFTABLE);

	if (GetIfTable(pIfTable, &dwSize, FALSE) == ERROR_INSUFFICIENT_BUFFER)
	{
		FREE(pIfTable);
		pIfTable = (MIB_IFTABLE *)MALLOC(dwSize);
		if (NULL == pIfTable)
		{
			return 1;
		}
	}

	dwRetValDes = GetIfTable(pIfTable, &dwSize, FALSE);
	dwRetValSrc = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen);
	if ((NO_ERROR == dwRetValDes) && (NO_ERROR == dwRetValSrc))
	{
		pAdapter = pAdapterInfo;
		int nNumWntries = 0;
		//找到本地物理网卡信息
		while (pAdapter)
		{
			// 遍历所有网卡信息
			while (nNumWntries < pIfTable->dwNumEntries)
			{
				pIfRow = (MIB_IFROW *)& pIfTable->table[nNumWntries];

				int i = 0;
				int j = 0;

				while (i < pIfRow->dwPhysAddrLen && j < pAdapter->AddressLength)
				{
					if ((int)pIfRow->bPhysAddr[i] == (int)pAdapter->Address[j])
					{
						if (j == (pAdapter->AddressLength - 1))
						{
							dwSpeed = pIfRow->dwSpeed;
							break;
						}
						i++;
						j++;
					}
					else
					{
						break;
					}

				}

				if (0 != dwSpeed)
				{
					break;
				}

				nNumWntries++;
			}

			pAdapter = pAdapter->Next;
		}

	} //

	if (NULL != pIfTable)
	{
		FREE(pIfTable);
		pIfTable = NULL;
	}

	if (NULL != pAdapterInfo)
	{
		FREE(pAdapterInfo);
		pAdapterInfo = NULL;
	}

	return dwSpeed;
}

