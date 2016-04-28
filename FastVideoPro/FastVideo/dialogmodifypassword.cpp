#include "dialogmodifypassword.h"
#include "ui_dialogmodifypassword.h"
#include "safedisk.h"
#include <QMessageBox>

DialogModifyPassword::DialogModifyPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifyPassword)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint|Qt::WindowSystemMenuHint| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);

    setMouseTracking( true );
}

DialogModifyPassword::~DialogModifyPassword()
{
    delete ui;
}

void DialogModifyPassword::on_pushButtonOK_clicked()
{
    QString oldPasswd(ui->lineEditOldPasswords->text());
    QString newPasswd(ui->lineEdit_newPasswords->text());
    if (newPasswd.isEmpty() || oldPasswd.isEmpty()){
        QMessageBox::information(nullptr, QStringLiteral("��ʾ"), QStringLiteral("��������벻��Ϊ�գ�"));
        return;
    }

    if (newPasswd != ui->lineEdit_newPassword2->text()){
        QMessageBox::information(nullptr, QStringLiteral("��ʾ"), QStringLiteral("������������벻һ�£�"));
        return;
    }

    if (!SafeDisk::instance().verifyPasswd(oldPasswd)){
        QMessageBox::information(nullptr, QStringLiteral("��ʾ"), QStringLiteral("���벻�ԣ�"));
        return;
    }

    if (!SafeDisk::instance().modifyPasswd(newPasswd)){
        QMessageBox::information(nullptr, QStringLiteral("��ʾ"), QStringLiteral("�޸�����ʧ�ܣ�"));
        return;
    }

    QMessageBox::information(nullptr, QStringLiteral("��ʾ"), QStringLiteral("�޸�����ɹ���"));
    this->accept();
}

void DialogModifyPassword::on_pushButton_cancel_clicked()
{
    this->close();
}
