#ifndef ORDINARYWIDGET_H
#define ORDINARYWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSqlQuery>
#include "scanthread.h"
#include "friendwidget.h"
#include "messagebubble.h"
namespace Ui {
class ordinaryWidget;
}

class ordinaryWidget : public QWidget
{
    Q_OBJECT

public:
    ordinaryWidget(QString account,QWidget *parent = nullptr);
    ~ordinaryWidget();


    ScanThread* Thethread;//扫描线程
    QWidget* friendlistwidget;//好友列表内置容器
    QVector<FriendWidget*> friendscontainer;//好友窗口容器
    QVector<FriendWidget*> grouplistcontainer;//群窗口容器
    QVector<Messagebubble*> messagecontainer;//消息窗口容器
    QVector<QPushButton*> systemtaskcontainer;//系统申请消息容器
    QVBoxLayout* systemtasklayout;//系统窗口布局


    void refreshfriendlist();//加载好友列表(包括群）
    void loadInPersonalInformation();//加载个人信息
    void loadinsystemmessage();//加载申请信息
    void loadchatrecord();//加载消息


    //部分任务函数
    void scanTaskTable();//扫描任务表
    void sendmessage();//发送普通消息，对应Cmessgae表
    void sendgmessage();//发送群消息，该函数只是被sendmessage()调用

    void setPixlabel(QVariant& va);//设置圆形图片
    void appendmessage(QVariant va,QString name,QString no,int type,QString message);//直接在消息窗口追加消息
    void haddlegroupmessage(QSqlQuery& task);//处理必要时追加群消息
    void haddlefriendapply();//处理好友申请
    void haddleinvitetogroupapply();//处理入群申请
    void haddlequitordeletegroup(QString theNo);//处理退群或者删除群
    void changeSelected(QString ano);//选择变化



    //当前登录账号，姓名，头像
    QString account;
    QString my_name;
    QVariant my_va;

    //正在聊天的账号，姓名，头像
    QString targetNo;
    QString targetName;
    QVariant targetva;
private slots:
    //页面切换
    void on_radioButton_clicked();
    void tabChanged();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();

    //修改个人信息按钮
    void on_pushButton_clicked();
    //保存个人信息
    void savenew(QString path,QStringList other);
    //创建群聊，这个函数被eventFilter调用
    void createagroup(QString path,QStringList other);
    //邀请入群
    void invitetogroup(QString gno);

private:
    Ui::ordinaryWidget *ui;
protected:
    void closeEvent(QCloseEvent* e) override;
    //两个label添加好友，创建群聊的处理,添加好友操作直接在这里完成
    bool eventFilter(QObject *watched, QEvent *event) override;

    void resizeEvent(QResizeEvent* e) override;
};

/*普通群发消息发送者是个人账号，接收者是群号，任务表中的群发类型接收者只能个人，发送者是群号，发送者账号作为附加信息*/


#endif // ORDINARYWIDGET_H
