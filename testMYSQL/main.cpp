#include <QApplication>
#include <QFile>
#include <QString>
#include <QDir>
#include <QDebug>
#include "splashdialog.h"
#include "ordinarywidget.h"
#include "QPluginLoader"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString path=QDir::currentPath();
    QApplication::addLibraryPath(path+QString("/plugins"));
    QPluginLoader loader(path+QString("/plugins/sqldrivers/qsqlmysql.dll"));


    QFile file(":/res/theme.qss");
    file.open(QFile::ReadOnly);
    QString str=file.readAll();
    a.setStyleSheet(str);


    QString acount;
    SplashDialog* dig=new SplashDialog;
    if(dig->exec()==QDialog::Accepted)
    {
        acount=dig->account;
        qDebug()<<acount;
        ordinaryWidget orw(acount);
        orw.show();
        orw.refreshfriendlist();//不要在构造函数里调用获取界面大小的函数
        return a.exec();
    }
    else
    {
        return 0;
    }

}
