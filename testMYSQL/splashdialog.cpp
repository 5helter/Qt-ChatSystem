#include "splashdialog.h"
#include "ui_splashdialog.h"
#include <QSettings>
#include <QString>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlError>
SplashDialog::SplashDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashDialog)
{
    ui->setupUi(this);
    setFixedSize(1011,682);
    setWindowFlag(Qt::FramelessWindowHint);
    QApplication::setOrganizationName("WWW-Qt");
    QApplication::setApplicationName("manager");

    setWindowIcon(QIcon(":/res/icon.png"));
    readSeettings();
}
SplashDialog::~SplashDialog()
{
    delete ui;
}

void SplashDialog::on_pushButton_2_clicked()
{
    this->reject();
}


void SplashDialog::on_pushButton_clicked()
{
    QSqlDatabase DB=QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName(ui->lineEdit_3->text());
    DB.setPort(3306);
    if(ui->lineEdit->text().isEmpty())
    {
         QMessageBox::critical(this,"用户名为空","请输入用户名");
         return;
    }
    if(ui->lineEdit_2->text().isEmpty())
    {
         QMessageBox::critical(this,"密码为空","请输入密码");
         return;
    }
    DB.setUserName(ui->lineEdit->text().trimmed());
    DB.setPassword(ui->lineEdit_2->text().trimmed()+"apex#");

    DB.setPort(3306);
    DB.setDatabaseName("chat_system");


    if(DB.open())
    {
        account=ui->lineEdit->text();
        writeSettings();
        this->accept();
    }
    else
    {
        QMessageBox::critical(this,"连接失败",DB.lastError().text());
    }


}

void SplashDialog::writeSettings()//写入用户名
{
        QSettings setting;
        QString username=ui->lineEdit->text();
        QString password=ui->lineEdit_2->text();
        if(username.isEmpty())
        {
           return;
        }
        setting.setValue("USERNAME",username);
        setting.setValue("SAVED",ui->checkBox->isChecked());
}
void SplashDialog::readSeettings()
{
     QSettings setting;
     bool saved=setting.value("SAVED",false).toBool();
     QString username=setting.value("USERNAME","").toString();

     if(saved)
     {
         ui->lineEdit->setText(username);
         ui->checkBox->setChecked(saved);
     }
}

