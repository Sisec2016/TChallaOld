#include "UserManagerDialog.h"
#include "ui_UserManagerDialog.h"
#include <QMessageBox>
#include "User.h"

UserManagerDialog::UserManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManagerDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint|Qt::WindowSystemMenuHint| Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);

    setMouseTracking( true );
    ui->radioButtonCollector->setChecked(true);
}

UserManagerDialog::~UserManagerDialog()
{
    delete ui;
}

void UserManagerDialog::on_pushButtonOK_clicked()
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

    if (!User::current().isCollectPasswords(oldPasswd)){
        QMessageBox::information(nullptr, QStringLiteral("��ʾ"), QStringLiteral("���벻�ԣ�"));
        return;
    }

    int type = getSelectUserType();
    if (type != USER_TYPE_ADMIN)
    {
        User::setUserType(type);
        User::current().setPassword(newPasswd);
        User::login(USER_TYPE_ADMIN, oldPasswd);
    }
    else
    {
        User::current().setPassword(newPasswd);
    }

    
    QMessageBox::information(nullptr, QStringLiteral("��ʾ"), QStringLiteral("�޸�����ɹ���"));
    this->accept();
}

void UserManagerDialog::on_pushButton_cancel_clicked()
{
    this->close();
}

int UserManagerDialog::getSelectUserType(){
    if (ui->radioButtonCollector->isChecked())
    {
        return USER_TYPE_COLLECT;
    }
    else if (ui->radioButtonExport->isChecked())
    {
        return USER_TYPE_EXPORT;
    }
    else if (ui->radioButtonAdmin->isChecked()){
        return USER_TYPE_ADMIN;
    }

    return USER_TYPE_NULL;
}