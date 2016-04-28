#include "ftppathadddlg.h"
#include "ui_ftppathadddlg.h"

#include <QMessageBox>

FTPPathAddDlg::FTPPathAddDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FTPPathAddDlg)
{
    ui->setupUi(this);

    connect(ui->OKBtn, SIGNAL(clicked()), this, SLOT(onOKBtn()));
    connect(ui->CancelBtn, SIGNAL(clicked()), this, SLOT(onCancelBtn()));
}

FTPPathAddDlg::~FTPPathAddDlg()
{
    delete ui;
}

void FTPPathAddDlg::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void FTPPathAddDlg::onOKBtn()
{
	m_FTPPath.strFtpHost = ui->FtpServerHost->text().trimmed();
	m_FTPPath.strFtpPort = ui->FtpServerPort->text().trimmed();
	m_FTPPath.strUser    = ui->UsrName->text().trimmed();
	m_FTPPath.strPwd     = ui->Passwd->text().trimmed();

    if(m_FTPPath.strFtpHost.isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("��ʾ"),
                                 QStringLiteral("�����������IP��"));
        return;
    }

    if(m_FTPPath.strFtpPort.isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("��ʾ"),
                                 QStringLiteral("������������˿ڣ�"));
        return;
    }

	if(m_FTPPath.strUser.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("��ʾ"),
			QStringLiteral("�������û�����"));
		return;
	}

	if(m_FTPPath.strPwd.isEmpty())
	{
		QMessageBox::information(this, QStringLiteral("��ʾ"),
			QStringLiteral("���������룡"));
		return;
	}
/*
   int size = m_plistFTPPath->size();
   for(int i= 0;i<size;i++)
   {
       m_plistFTPPath->at(i).strFTPPath
   }*/

    this->accept();
}

void FTPPathAddDlg::setCurFTPPath(T_FTPPath& tFTPPath )
{
	ui->FtpServerHost->setText(tFTPPath.strFtpHost);
	ui->FtpServerPort->setText(tFTPPath.strFtpPort);
	ui->UsrName->setText(tFTPPath.strUser);
	ui->Passwd->setText(tFTPPath.strPwd);
}

void FTPPathAddDlg::onCancelBtn()
{
    this->reject();
}
