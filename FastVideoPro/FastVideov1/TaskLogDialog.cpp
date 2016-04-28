#include "TaskLogDialog.h"
#include "ui_TaskLogDialog.h"
#include "CommonFunc.h"
#include "log.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QSettings>
#include <QApplication>

#include <vector>
#include <string>

#include "settings.h"
#include "Verify.h"
#include "SqlUtils.h"


TaskLogDialog::TaskLogDialog(QWidget *parent) :
    MyBaseDialog(parent),
    ui(new Ui::TaskLogDialog)
{
    ui->setupUi(this);

    setTitleName(QStringLiteral("������ѯ"));
    ui->tableView->horizontalHeader()->setSectionsClickable(false);
    ui->tableView->setAlternatingRowColors(true);
    QDateTime t = QDateTime::currentDateTime();
    ui->beginDateEdit->setDate(t.addDays(-1).date());
    ui->endDateEdit->setDate(t.date());

    mbHeadSetted = false;

    connect(ui->pushButtonFind, SIGNAL(clicked()), this, SLOT(onFindBtn()));
}

TaskLogDialog::~TaskLogDialog()
{
    delete ui;
}


void TaskLogDialog::refreshTime()
{
    
}


void TaskLogDialog::setModelHeadData()
{
    if (mbHeadSetted)
    {
        return;
    }

    mbHeadSetted = true;
    m_queryModel.setHeaderData(0, Qt::Horizontal, QStringLiteral("ʱ��"));
    m_queryModel.setHeaderData(1, Qt::Horizontal, QStringLiteral("�ص�"));
    m_queryModel.setHeaderData(2, Qt::Horizontal, QStringLiteral("�ɼ���"));
    m_queryModel.setHeaderData(3, Qt::Horizontal, QStringLiteral("��������"));
    m_queryModel.setHeaderData(4, Qt::Horizontal, QStringLiteral("��������"));
    m_queryModel.setHeaderData(5, Qt::Horizontal, QStringLiteral("�豸IP"));
    m_queryModel.setHeaderData(6, Qt::Horizontal, QStringLiteral("��ע"));
}


void TaskLogDialog::onFindBtn()
{
    std::stringstream sqlStream;

    sqlStream << "SELECT substr(mTime, 1, 16), mAddress, mMen, mName, mDesc, mDeviceIP, mText "
        << " FROM TaskLog WHERE ";
    QDateTime t;

    t.setDate(ui->beginDateEdit->date());
    t.setTime(ui->beginTimeEdit->getTime());
    QString timeBeg = t.toString(SQL_UTIL_TIME_FORMAT);

    t.setDate(ui->endDateEdit->date());
    t.setTime(ui->endTimeEdit->getTime());
    QString timeEnd = t.toString(SQL_UTIL_TIME_FORMAT);

    printWhereCondtionSql(sqlStream, std::make_tuple("mTime", ">=", timeBeg)
        , std::make_tuple("mTime", "<=", timeEnd));


    qDebug() << sqlStream.str().c_str();
    m_queryModel.setQuery(sqlStream.str().c_str());
    setModelHeadData();
    ui->tableView->setModel(&m_queryModel);
}

