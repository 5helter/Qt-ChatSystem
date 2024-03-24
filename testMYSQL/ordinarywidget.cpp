#include "ordinarywidget.h"
#include "ui_ordinarywidget.h"
#include <QTabWidget>
#include <QTabBar>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDebug>
#include <QSqlQuery>
#include <QLabel>
#include <QToolBar>
#include <QDateTime>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QTime>
#include "sqlwidget.h"
ordinaryWidget::ordinaryWidget(QString account,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ordinaryWidget)
{
    ui->setupUi(this);
    ui->widget->setMaximumHeight(this->height()/5);//个人页面上面的框
    //隐藏页头
    QTabBar* bar=ui->tabWidget->tabBar();
    bar->hide();
    ui->uncertaintylabel->setPixmap(QPixmap(":/res/remain.png"));


    friendlistwidget=ui->friendlistarea->widget();

    //清空并禁用messageedit
    ui->dialoglabel->clear();
    ui->messageedit->setDisabled(1);
    //安装事件过滤器
    ui->addfriendlabel->installEventFilter(this);
    ui->creategruop->installEventFilter(this);

    //系统消息布局
    systemtasklayout=new QVBoxLayout;


    this->account=account;
    setWindowTitle(QString("当前登录账号为")+account+QString("\n"));

    //初始时置空
    targetNo="";
    targetName="";

    //刷新个人信息页面，系统消息列表
    loadInPersonalInformation();
    loadinsystemmessage();

    //扫描线程启用
    Thethread=new ScanThread(this);
    connect(Thethread,&ScanThread::updateTable,this,&ordinaryWidget::scanTaskTable);
    Thethread->start();

    connect(ui->sendbutton,&QPushButton::clicked,this,&ordinaryWidget::sendmessage);//发送消息
}

ordinaryWidget::~ordinaryWidget()
{
    delete ui;
}

void ordinaryWidget::scanTaskTable()//直接包含了对于普通消息的处理//查询了my_task表
{
    Thethread->stop=true;
    {
        QSqlQuery task;
        task.prepare("select * from `my_task`;");
        //查询时一并将任务删除，for update会上写锁
        task.exec();
        task.first();
        while(task.isValid())
        {
            if(task.value("type").toInt()==1)
            {
                if(task.value("sender").toString()!=targetNo)//不是当前页面不追加
                {
                    task.next();
                    continue;
                }
                else
                    appendmessage(targetva,targetName,targetNo,1,task.value("content").toString());
            }
            if(task.value("type").toInt()==4)
            {
                if(task.value("sender").toString()!=targetNo)//不是当前页面不追加
                {
                    task.next();
                    continue;
                }
                else
                    haddlegroupmessage(task);
            }
            if(task.value("type").toInt()==3||task.value("type").toInt()==4)
                loadinsystemmessage();

            task.next();
        }

        QSqlQuery deletetask;
        deletetask.prepare("delete from `my_task` where `type`=1 or `type`=4;");
        deletetask.bindValue(":account",account);
        deletetask.exec();
    }
    Thethread->stop=false;
    Thethread->start();
}

void ordinaryWidget::loadchatrecord()//查询了my_cmessage表，my_gmessage表,client表（使用client是为了查询发送者）
{

    //清空现有聊天记录
    while(messagecontainer.isEmpty()!=1)
    {
        delete messagecontainer.last();
        messagecontainer.pop_back();
    }
    ui->messagelistarea->widget()->setMinimumHeight(ui->messagelistarea->height());
    ui->messagelistarea->widget()->resize(ui->messagelistarea->width(),ui->messagelistarea->height());//放大要用setminimumHeight()缩小不仅要设置这个，还要resize();
    //清空数据记录
    if(targetNo=="")
    {
        qDebug()<<"清除了聊天内容";
        return;
    }


    QSqlQuery load;
    if(targetNo[targetNo.length()-1]!="#")
    {
        load.prepare("select * from `my_cmessage` where `csender`=:targetNo or (`csender`=:account and `creceiver`=:targetNo) order by `send_time`;");
        load.bindValue(":account",account);
        load.bindValue(":targetNo",targetNo);
        load.setForwardOnly(1);//可以提高性能
        load.exec();
        load.first();//要讲游标移动到正确的位置
        while(load.isValid())//当前游标记录有效
        {
            if(load.value("csender").toString()==account)
                appendmessage(my_va,my_name,account,2,load.value("content").toString());
            else
                appendmessage(targetva,targetName,targetNo,1,load.value("content").toString());

            load.next();
        }
    }
    else
    {
        load.prepare("select * from `my_gmessage` where `Greceiver`=:targetNo order by `send_time`;");//my_gmessage这个表是包含自己消息的
        load.bindValue(":targetNo",targetNo);
        load.setForwardOnly(1);//可以提高性能
        load.exec();
        load.first();//要讲游标移动到正确的位置
        while(load.isValid())//当前游标记录有效
        {
            if(load.value("Gsender").toString()==account)
                appendmessage(my_va,my_name,account,2,load.value("content").toString());
            else
            {
                QSqlQuery a;
                a.prepare("select * from `client` where `ano`=:ano");
                a.bindValue(":ano",load.value("Gsender"));
                a.exec();
                a.first();
                if(a.isValid())
                {
                    appendmessage(a.value("Pimage"),a.value("Cname").toString(),a.value("ano").toString(),1,load.value("content").toString());
                }
            }

            load.next();
        }

    }
}

void ordinaryWidget::sendmessage()//sendmessage需要发布任务//my_cmessage，my_cmessage
{

    QString message=ui->messageedit->toPlainText();
    if(message.isEmpty())
    {
       return;
    }

    if(targetNo[targetNo.length()-1]=="#")
    {
        sendgmessage();
        return;
    }


    QString sendtime=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");



    QSqlQuery insertmessage;
    QSqlQuery postTask;

    insertmessage.prepare("insert into `my_cmessage`(`csender`,`creceiver`,`send_time`,`content`) values(?,?,?,?);");
    insertmessage.bindValue(0,account);
    insertmessage.bindValue(1,targetNo);
    insertmessage.bindValue(2,sendtime);
    insertmessage.bindValue(3,message);
    insertmessage.exec();


    postTask.prepare("insert into `my_task`(`sender`,`receiver`,`type`,`content`,`send_time`) values(?,?,?,?,?);");
    postTask.bindValue(0,account);
    postTask.bindValue(1,targetNo);
    postTask.bindValue(2,1);//type==1代表普通Cmessage类型
    postTask.bindValue(3,message);
    postTask.bindValue(4,sendtime);
    postTask.exec();

    if(insertmessage.isActive())
    {

        appendmessage(my_va,my_name,account,2,message);
    }


}

void ordinaryWidget::sendgmessage()//my_gmessage，gmemeber，my_task
{

    QString message=ui->messageedit->toPlainText();
    //需要通知群里所有人
    QString sendtime=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");



    QSqlQuery insertmessage;

    insertmessage.prepare("INSERT INTO `my_gmessage` (`Gsender`, `Greceiver`, `send_time`, `content`) VALUES(?,?,?,?);");
    insertmessage.bindValue(0,account);
    insertmessage.bindValue(1,targetNo);
    insertmessage.bindValue(2,sendtime);
    insertmessage.bindValue(3,message);
    insertmessage.exec();


    QSqlQuery membersin;
    membersin.prepare("select `ano` from `gmemeber` where `gno` =:theNo and `ano`!=:account");
    membersin.bindValue(":theNo",targetNo);
    membersin.bindValue(":account",account);
    membersin.exec();
    membersin.first();
    while(membersin.isValid())//任务表中的接收者只能个人，消息发送者是群号，发送者账号作为附加信息
    {
        QSqlQuery postTask;
        postTask.prepare("insert into `my_task`(`sender`,`receiver`,`type`,`content`,`send_time`) values(?,?,?,?,?);");
        postTask.bindValue(0,targetNo);
        postTask.bindValue(1,membersin.value("ano").toString());
        postTask.bindValue(2,4);//type==4代表普通群发消息类型
        postTask.bindValue(3,message+"###"+account);
        postTask.bindValue(4,sendtime);
        postTask.exec();



        membersin.next();
    }


    if(insertmessage.isActive())
    {

        appendmessage(my_va,my_name,account,2,message);
    }
}

void ordinaryWidget::refreshfriendlist()//这里面包含了处理删除好友的函数//`my_friends`,`client`,my_cmessage,friends
{
    int sw=ui->friendlistarea->width();
    int sh=ui->friendlistarea->height();

    //清空好友群列表,并且恢复长度
    while(friendscontainer.isEmpty()!=1)
    {
        delete friendscontainer.last();
        friendscontainer.pop_back();
    }
    while(grouplistcontainer.isEmpty()!=1)
    {
        delete grouplistcontainer.last();
        grouplistcontainer.pop_back();
    }

    friendlistwidget->setMinimumHeight(sh);
    friendlistwidget->resize(sw,sh);


    QSqlQuery friends;
    friends.prepare("SELECT `ano2`,`Cname`,`Pimage` FROM `my_friends`,`client` where `client`.`ano`=`my_friends`.`ano2` and `my_friends`.ano1=:account;");
    friends.bindValue(":account",account);
    friends.exec();
    friends.first();
    int i=0;
    int th=sh/8;
    int tw=sw;
    while(friends.isValid())
    {
        //获取信息
        QString ano=friends.value("ano2").toString();
        QString name=friends.value("Cname").toString();
        QVariant va=friends.value("Pimage");
        //设置窗口

        FriendWidget* afriend=new FriendWidget;
        afriend->setfriendano(ano);
        afriend->setPimage(va);
        afriend->setName(name);




        //必须使用这个
        friendlistwidget->setMinimumHeight(friendlistwidget->height()+th);


        afriend->setParent(friendlistwidget);
        afriend->resize(tw,th);
        afriend->setSize(tw,th);//qt貌似有个bug,在类内部resize和外部效果不一样？
        afriend->setGeometry(0,i*th+i*5,tw,th);
        afriend->show();

        ui->friendlistarea->viewport()->update();
        friendlistwidget->update();


        //链接信号和槽并加入管理
        friendscontainer.push_back(afriend);
        connect(afriend,&FriendWidget::friendselected,this,[=](QString name,QString ano,QVariant va){
            ui->dialoglabel->setText(name);
            this->targetNo=ano;
            this->targetName=name;
            this->targetva=va;
            ui->messageedit->setDisabled(0);
            loadchatrecord();
        });
        connect(afriend,&FriendWidget::deleteFriend,this,[=](QString ano){
            QMessageBox::StandardButton result;
            result=QMessageBox::information(this,"删除好友","是否要删除好友",QMessageBox::Ok|QMessageBox::No);
            if(result==QMessageBox::Ok)
            {
                QSqlQuery query;
                QString str="delete from `my_cmessage` where `csender`=:ano or (`csender`=:account and `creceiver`=:ano);"
                            "delete from `friends` where (`ano1`=:account and `ano2`=:ano) or(`ano1`=:ano and `ano2`=:account);";
                query.prepare(str);
                query.bindValue(":ano",ano);
                query.bindValue(":account",account);
                query.exec();
                if(query.isActive())
                {
                    QMessageBox::information(this,"完成","好友已删除");
                    refreshfriendlist();
                    qDebug()<<"刷新好友列表";
                    if(targetNo==ano)
                    {
                        targetNo="";
                        loadchatrecord();
                        qDebug()<<"刷新聊天框";
                        ui->messageedit->setEnabled(0);
                    }
                }
            }
        });
        connect(afriend,&FriendWidget::checkchanged,this,&ordinaryWidget::changeSelected);
        ++i;
        friends.next();
    }

    QSqlQuery groupquery;
    groupquery.prepare("select * from `my_groups`");
    groupquery.exec();
    groupquery.first();

    while(groupquery.isValid())
    {
        FriendWidget* agroup=new FriendWidget;


        int theheight=i*th+th+i*5;
        int thewidth=tw;

        //必须使用这两个
        friendlistwidget->setMinimumHeight(theheight);
        friendlistwidget->setMinimumWidth(thewidth);



        //获取群信息
        QString gno=groupquery.value("gno").toString();
        QString gname=groupquery.value("gname").toString();
        QVariant gpimage=groupquery.value("gpimage");

        //设置控件
        agroup->setfriendano(gno);
        agroup->setPimage(gpimage);
        agroup->setName(gname);


        agroup->setParent(friendlistwidget);
        agroup->resize(tw,th);
        agroup->setSize(tw,th);
        agroup->setGeometry(0,i*th+i*5,tw,th);


        friendscontainer.push_back(agroup);
        connect(agroup,&FriendWidget::friendselected,this,[=](QString name,QString ano,QVariant va){
            ui->dialoglabel->setText(name);
            this->targetNo=ano;
            this->targetName=name;
            this->targetva=va;
            ui->messageedit->setDisabled(0);
            loadchatrecord();
        });
        connect(agroup,&FriendWidget::deleteFriend,this,&ordinaryWidget::haddlequitordeletegroup);
        connect(agroup,&FriendWidget::invitetogroup,this,&ordinaryWidget::invitetogroup);
        connect(agroup,&FriendWidget::checkchanged,this,&ordinaryWidget::changeSelected);


        i++;
        groupquery.next();
    }
}

void ordinaryWidget::loadInPersonalInformation()//client
{
    QSqlQuery personal;
    personal.prepare("SELECT * FROM `client` where `ano`=?;");
    personal.bindValue(0,account);
    personal.exec();
    personal.first();
    if(personal.isValid())
    {
        QString name=personal.value("Cname").toString();
        QString ap=personal.value("ap").toString();
        QString sign=personal.value("sign").toString();
        ui->nameLabel->setText(name);
        ui->aplabel->setText("账号:"+account);
        ui->signlabel->setText(sign);

        QVariant va=personal.value("Pimage");
        setPixlabel(va);

        personal.next();

        my_va=va;
        my_name=name;

        QPixmap pix;
        pix.loadFromData(va.toByteArray());
        setWindowIcon(pix);

        QTime currentTime = QTime::currentTime();

        // 判断当前时间是上午还是下午还是晚上
        QString str;
        if (currentTime.hour() >= 0 && currentTime.hour() < 12) {
            // 上午
           str="上午好,";
        } else if (currentTime.hour() >= 12 && currentTime.hour() < 18) {
            // 下午
             str="下午好,";
        } else {
            // 晚上
             str="晚上好,";
        }

        setWindowTitle(str+my_name);

    }
}

void ordinaryWidget::loadinsystemmessage()//my_task
{

    while(!systemtaskcontainer.isEmpty())
    {
        delete systemtaskcontainer.last();
        systemtaskcontainer.pop_back();
    }


    QSqlQuery task;
    task.prepare("select * from `my_task`order by `send_time`;");
    //查询时一并将任务删除，for update会上写锁
    task.exec();
    task.first();


    while(task.isValid())
    {
        if(task.value("type").toInt()==2)
        {
            QPushButton* atask=new QPushButton;
            atask->setText(task.value("sender").toString()+"的好友申请");
            systemtaskcontainer.push_back(atask);
            systemtasklayout->addWidget(atask);
            connect(atask,&QPushButton::clicked,this,&ordinaryWidget::haddlefriendapply);
        }
        if(task.value("type").toInt()==3)
        {
            QPushButton* atask=new QPushButton;
            atask->setProperty("gno",QVariant(task.value("content").toString()));//设置属性保存信息
            QString btntext=task.value("sender").toString()+QString("邀请你加入")+task.value("content").toString();
            btntext.chop(1);//没有返回值
            atask->setText(btntext);//chop(1)去掉最后一个字符
            systemtaskcontainer.push_back(atask);
            systemtasklayout->addWidget(atask);
            connect(atask,&QPushButton::clicked,this,&ordinaryWidget::haddleinvitetogroupapply);
        }

        task.next();
    }
    ui->sysscrollArea->widget()->setLayout(systemtasklayout);

}

void ordinaryWidget::setPixlabel(QVariant& va)
{

    QByteArray data;
    if(va.isValid())
        data=va.toByteArray();
    else
        return;


    QPixmap originalPixmap; // 加载原始图片
    originalPixmap.loadFromData(data);
    originalPixmap=originalPixmap.scaled(100,100);
    QSize size(100, 100); // 需要裁剪的大小

    // 创建一个QImage对象，并使用QPainter将原始QPixmap绘制到QImage中
    QImage image(size, QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBackground(Qt::transparent); // 设置背景为透明
    painter.eraseRect(QRect(0, 0, size.width(), size.height())); // 清空画布
    painter.drawPixmap(0, 0, size.width(), size.height(), originalPixmap); // 绘制QPixmap


    // 使用QPainter将圆形区域裁剪出来，并将结果绘制到新的QPixmap中
    QPixmap croppedPixmap(size);
    croppedPixmap.fill(Qt::transparent); // 设置背景为透明
    QPainter pixmapPainter(&croppedPixmap);

    pixmapPainter.setBrush(QBrush(Qt::white));
    pixmapPainter.drawEllipse(0, 0, size.width(), size.height()); // 绘制圆形路径
    pixmapPainter.setCompositionMode(QPainter::CompositionMode_SourceIn); //使用相交的方式绘制,和透明度为0的区域相交透明度保持0，与白色相交保持不变
    pixmapPainter.drawImage(0, 0, image); // 将裁剪结果绘制到新的QPixmap中
    // 创建一个QLabel，并使用裁剪后的QPixmap设置其显示内容
    ui->Pixlabel->setPixmap(croppedPixmap);
}

void ordinaryWidget::appendmessage(QVariant va, QString name, QString no, int type,QString message)
{
    int w=ui->messagelistarea->width();
    int h=ui->messagelistarea->height();

    Messagebubble* amessage=new Messagebubble;
    amessage->setParent(ui->messagelistarea->widget());
    amessage->setbubble(va,type,message,no,name);
    amessage->settendsize(w-30,h/5);//-10是留空白防止message遮挡
    amessage->calculatedtext();//计算
    amessage->calculatedW;

    int i=0;
    int jh=0;//已有高度
    while(i<messagecontainer.size())
    {
        jh+=messagecontainer[i]->calculatedH;
        jh+=10;
        ++i;
    }

    ui->messagelistarea->widget()->setMinimumHeight((ui->messagelistarea->widget()->height())+amessage->calculatedH);

    amessage->show();
    amessage->setGeometry(15,jh,amessage->tw,amessage->calculatedH);//窗口的宽度就是倾向宽度


    ui->messagelistarea->viewport()->update();
    ui->messagelistarea->widget()->update();

    messagecontainer.push_back(amessage);
    ui->messageedit->clear();
}

void ordinaryWidget::haddlegroupmessage(QSqlQuery &task)//client
{
    QStringList list=task.value("content").toString().split("###");
    QString message=list[0];
    QString ano=list[1];//发送者账号
    qDebug()<<ano;

    QSqlQuery a;
    a.prepare("select * from `client` where `ano`=:ano");
    a.bindValue(":ano",ano);
    a.exec();
    a.first();
    if(a.isValid())
    {
        appendmessage(a.value("Pimage"),a.value("Cname").toString(),a.value("ano").toString(),1,message);
    }
}

void ordinaryWidget::haddlefriendapply()//my_friends,my_task
{
    QPushButton* btn=qobject_cast<QPushButton*>(sender());//获取信号发射者
    int pos = btn->text().indexOf("的好友申请");
    QString ano=btn->text().left(pos); //获取左边的部分



    QMessageBox::StandardButton result;
    result=QMessageBox::information(this,"好友申请","是否接受成为好友",QMessageBox::Ok|QMessageBox::No);
    if(result==QMessageBox::Ok)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO `my_friends` (`ano1`, `ano2`) VALUES (?, ?), (?,?);");
        query.bindValue(0,account);
        query.bindValue(1,ano);
        query.bindValue(2,ano);
        query.bindValue(3,account);
        query.exec();
        if(query.isActive())
        {
            QMessageBox::information(this,"成功","好友添加成功");
        }
        else
        {
            QMessageBox::critical(this,"错误","操作失败，请检查你们是否已经是好友");
        }
        refreshfriendlist();
    }

    QSqlQuery query;
    query.prepare("delete from `my_task` where `type`=2 and `sender`=:ano;");
    query.bindValue(":ano",ano);
    query.exec();

    loadinsystemmessage();

}

void ordinaryWidget::haddleinvitetogroupapply()//gmemeber,my_task
{
    QPushButton* btn=qobject_cast<QPushButton*>(sender());//获取信号发射者
    QString gno =btn->property("gno").toString();
    qDebug()<<gno;

    QMessageBox::StandardButton result;
    result=QMessageBox::information(this,"入群邀请","是否加入群聊",QMessageBox::Ok|QMessageBox::No);
    if(result==QMessageBox::Ok)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO `gmemeber` (`ano`, `gno`) VALUES (?,?)");
        query.bindValue(0,account);
        query.bindValue(1,gno);
        query.exec();
        if(query.isActive())
        {
            QMessageBox::information(this,"成功","加入群聊成功");
        }
        else
        {
            QMessageBox::critical(this,"","已拒绝");
        }
        refreshfriendlist();
    }

    QSqlQuery query;
    query.prepare("delete from `my_task` where `type`=3 and `content`=:gno;");
    query.bindValue(":gno",gno);
    query.exec();

    loadinsystemmessage();

}

void ordinaryWidget::haddlequitordeletegroup(QString theNo)//my_groups,gmessage,gmemeber,groups
{
    QSqlQuery query1;
    query1.prepare("select * from `my_groups` where `gno`=:theNo");
    query1.bindValue(":theNo",theNo);
    query1.exec();
    query1.first();
    if(query1.value("ano")==account)
    {
        QMessageBox::StandardButton result;
        result=QMessageBox::information(this,"删除群聊","是否要删除群聊",QMessageBox::Ok|QMessageBox::No);
        if(result==QMessageBox::Ok)
        {
            QSqlQuery query;
            QString str="delete from `gmessage` where `Greceiver`=:theNo;"
                        "delete from `gmemeber` where `gno`=:theNo;"
                        "delete from `groups` where `gno`=:theNo;";
            query.prepare(str);
            query.bindValue(":theNo",theNo);
            query.exec();
            if(query.isActive())
            {
                QMessageBox::information(this,"成功","该群已被解散");
                if(targetNo==theNo)
                {
                    targetNo=="";
                    ui->messageedit->clear();
                    ui->messageedit->setEnabled(0);
                }
                refreshfriendlist();
                loadchatrecord();//如果theNo为空，只有清空聊天框的作用
                qDebug()<<"奇怪";
            }
        }
        else
        {
        }
    }
    else
    {
        QMessageBox::StandardButton result;
        result=QMessageBox::information(this,"退出","是否要退出群聊",QMessageBox::Ok|QMessageBox::No);
        if(result==QMessageBox::Ok)
        {
            QSqlQuery query;
            QString str="delete from `gmemeber` where `ano`=:account and `gno`=:theNo;";
            query.prepare(str);
            query.bindValue(":account",account);
            query.bindValue(":theNo",theNo);
            query.exec();
            if(query.isActive())
            {
                if(targetNo==theNo)
                {
                    targetNo=="";
                    ui->messageedit->clear();
                    ui->messageedit->setEnabled(0);
                }
                QMessageBox::information(this,"成功","已退出该群");
                refreshfriendlist();
            }
            loadchatrecord();
        }
        else
        {

        }

    }
}

void ordinaryWidget::changeSelected(QString ano)
{
    int i=0;
    while(i<friendscontainer.size())
    {
        if(friendscontainer[i]->ano==ano)
        {
            friendscontainer[i]->selected=1;
            friendscontainer[i]->update();
        }
        else
        {
            friendscontainer[i]->selected=0;
            friendscontainer[i]->update();
        }
        ++i;
    }
    i=0;
    while(i<grouplistcontainer.size())
    {
        if(grouplistcontainer[i]->ano==ano)
        {
            grouplistcontainer[i]->selected=1;
            grouplistcontainer[i]->update();
        }
        else
        {
            grouplistcontainer[i]->selected=0;
            grouplistcontainer[i]->update();
        }
        ++i;

    }
}

void ordinaryWidget::on_radioButton_clicked()
{
    tabChanged();
}

void ordinaryWidget::tabChanged()
{
    int i=0;//i==0代表新页面画在右边

     QWidget* widgetformer;
     QWidget* widgetnow;

    if(ui->radioButton->isChecked())
    {
        if(ui->tabWidget->currentIndex()==0)
        {
            return;
        }
        else
        {
            //换图标
            ui->radioButton_3->setIcon(QIcon(":/res/person.png"));
            ui->radioButton->setIcon(QIcon(":/res/messagechecked.png"));
            ui->radioButton_2->setIcon(QIcon(":/res/add2.png"));

            refreshfriendlist();
            loadchatrecord();
            qDebug()<<"?";



            i=1;
            widgetformer=ui->tabWidget->widget(ui->tabWidget->currentIndex());
            widgetnow=ui->tabWidget->widget(0);

            ui->tabWidget->setCurrentIndex(0);





        }
    }
    else if(ui->radioButton_2->isChecked())
    {
        if(ui->tabWidget->currentIndex()==1)
        {
            return;
        }
        else
        {
            //换图标
            ui->radioButton_3->setIcon(QIcon(":/res/person.png"));
            ui->radioButton->setIcon(QIcon(":/res/message.png"));
            ui->radioButton_2->setIcon(QIcon(":/res/addchecked.png"));


            loadinsystemmessage();


            if(ui->tabWidget->currentIndex()<1)
                i=0;
            else
                i=1;
            widgetformer=ui->tabWidget->widget(ui->tabWidget->currentIndex());
            widgetnow=ui->tabWidget->widget(1);

            ui->tabWidget->setCurrentIndex(1);
        }
    }
    else if(ui->radioButton_3->isChecked())
    {
        loadInPersonalInformation();

        if(ui->tabWidget->currentIndex()==2)
        {
            return;
        }

        else
        {

            //换图标
            ui->radioButton_3->setIcon(QIcon(":/res/personchecked.png"));
            ui->radioButton->setIcon(QIcon(":/res/message.png"));
            ui->radioButton_2->setIcon(QIcon(":/res/add2.png"));





            if(ui->tabWidget->currentIndex()<2)
                i=0;
            else
                i=1;
            widgetformer=ui->tabWidget->widget(ui->tabWidget->currentIndex());
            widgetnow=ui->tabWidget->widget(2);

            ui->tabWidget->setCurrentIndex(2);
        }

    }
    else
    {
        return;
    }

    //将页面转换成pixmap
    QPixmap pixf=QWidget::grab(widgetformer->rect());
    QPixmap pixn=QWidget::grab(widgetnow->rect());

//     QPixmap* pix=new QPixmap(pixf.width()+pixn.width(),pixf.height());
     QImage* image=new QImage(pixf.width()+pixn.width(),pixf.height(),QImage::Format_ARGB32);


     //画一幅含有两张pixmap的image
     image->fill(QColor(Qt::black));
    QPainter p(image);
    QBrush brush(QColor(255,255,0),Qt::Dense4Pattern);
    p.setBrush(brush);
    QPen pen;
    pen.setColor(Qt::white);
    p.setPen(pen);

    if(i==0)
    {
        p.drawPixmap(0,0,pixf);
        p.drawPixmap(pixf.width(),0,pixn);
    }
    else
    {
        p.drawPixmap(0,0,pixn);
        p.drawPixmap(pixf.width(),0,pixf);
    }


    p.end();



    //将pix设置给label
    QLabel* animationLabel=new QLabel(ui->tabWidget);
    animationLabel->resize(image->size());
    animationLabel->setPixmap(QPixmap::fromImage(*image));

    animationLabel->show();
    animationLabel->raise();//放到最顶层


    //播放动画
    if(i==0)
    {
        QPropertyAnimation* anim=new QPropertyAnimation(animationLabel,"geometry");
        anim->setDuration(200);
        anim->setStartValue(QRect(0,0,image->width(),image->height()));
        anim->setEndValue(QRect(-pixf.height(),0,image->width(),image->height()));
        anim->start();
        connect(anim,&QPropertyAnimation::finished,this,[=](){
            delete image;
            delete anim;
            delete animationLabel;
        });

    }
    else
    {
        QPropertyAnimation* anim=new QPropertyAnimation(animationLabel,"geometry");
        anim->setDuration(200);
        anim->setStartValue(QRect(-pixf.height(),0,image->width(),image->height()));
        anim->setEndValue(QRect(0,0,image->width(),image->height()));
        anim->start();
        connect(anim,&QPropertyAnimation::finished,this,[=](){
            delete image;
            delete anim;
            delete animationLabel;
        });

    }



}

void ordinaryWidget::on_radioButton_2_clicked()
{
    tabChanged();
}

void ordinaryWidget::on_radioButton_3_clicked()
{
    tabChanged();
}

void ordinaryWidget::closeEvent(QCloseEvent *e)
{
    Thethread->terminate();
    Thethread->wait();
}

bool ordinaryWidget::eventFilter(QObject *watched, QEvent *event)//my_task
{
    if(event->type()==QEvent::MouseButtonPress)
    {
        if(watched==ui->addfriendlabel)
        {
            QString  title="添加好友";
            QString textlabel="输入账号";
            bool ok=false;
            QString theNo=QInputDialog::getText(this,title,textlabel,QLineEdit::Normal,"",&ok);

            if(ok)
            {
                if(theNo==account)
                {
                    QMessageBox::critical(this,"失败","不能添加自己为好友");
                    return QWidget::eventFilter(watched,event);
                }
                QSqlQuery postTask;
                QString sendtime=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
                postTask.prepare("insert into `my_task`(`sender`,`receiver`,`type`,`content`,`send_time`) values(?,?,?,?,?);");
                postTask.bindValue(0,account);
                postTask.bindValue(1,theNo);
                postTask.bindValue(2,2);//type==1代表普通Cmessage类型
                postTask.bindValue(3,"");
                postTask.bindValue(4,sendtime);
                postTask.exec();
                if(postTask.isActive())
                {
                    QMessageBox::information(this,"成功","已发出好友申请");
                }
                else
                {
                    QMessageBox::critical(this,"失败","发送失败请检查是否存在该用户");
                }

            }
        }
        if(watched==ui->creategruop)
        {
            Sqlwidget* wid=new Sqlwidget(2);
            wid->show();
            wid->setAttribute(Qt::WA_DeleteOnClose);
            connect(wid,&Sqlwidget::informationChanged,this,&ordinaryWidget::createagroup);
        }
    }
    return QWidget::eventFilter(watched,event);
}

void ordinaryWidget::resizeEvent(QResizeEvent *e)
{
   //QWidget::resizeEvent(e);
}

void ordinaryWidget::on_pushButton_clicked()
{

    Sqlwidget* wid=new Sqlwidget(1);//创建窗口
    wid->show();
    wid->setAttribute(Qt::WA_DeleteOnClose);
    connect(wid,&Sqlwidget::informationChanged,this,&ordinaryWidget::savenew);

}

void ordinaryWidget::savenew(QString path,QStringList others)//client
{
    qDebug()<<path;
    if(!others[1].isEmpty())
    {
       QSqlQuery a;
       a.prepare("update `client` set `sign`=:others where `ano`=:account");
       a.bindValue(":account",account);
       a.bindValue(":others",others[1]);
       a.exec();
       qDebug()<<others;
       if(a.isActive())
           qDebug()<<"执行完毕";
    }
    if(!others[0].isEmpty())
    {
       QSqlQuery a;
       a.prepare("update `client` set `Cname`=:others where `ano`=:account");
       a.bindValue(":account",account);
       a.bindValue(":others",others[0]);
       a.exec();
       qDebug()<<others;
       if(a.isActive())
           qDebug()<<"执行完毕";
    }
    if(!path.isEmpty())
    {
        QFile* file=new QFile(path);
        file->open(QIODevice::ReadOnly);
        QByteArray by=file->readAll();
        file->close();
        delete file;

        QSqlQuery b;
        b.prepare("update `client` set `Pimage`=:photo where `ano`=:account;");
        b.bindValue(":account",account);
        b.bindValue(":photo",by);
        b.exec();
        qDebug()<<"图片更新";
    }

    loadInPersonalInformation();

}

void ordinaryWidget::createagroup(QString path, QStringList other)//my_groups,gmemeber
{
    if(other[0]=="")
    {
        QMessageBox::critical(this,"创建失败","群号不能为空");
    }
    else
    {
        other[0]=other[0]+"#";// 在数据库中群号用#号结尾
        QSqlQuery a;
        a.prepare("INSERT INTO `my_groups` (`gno`, `gname`, `ano`, `gpimage`) VALUES (?,?,?,?)");

        a.bindValue(0,other[0]);
        a.bindValue(1,other[1]);
        a.bindValue(2,account);

        QFile* file=new QFile(path);
        file->open(QIODevice::ReadOnly);
        QByteArray by=file->readAll();
        file->close();
        delete file;

        a.bindValue(3,by);
        a.exec();

        QSqlQuery b;
        b.prepare("INSERT INTO `gmemeber` (`ano`, `gno`) VALUES (?, ?)");
        b.bindValue(0,account);
        b.bindValue(1,other[0]);
        b.exec();


        if(a.isActive())
        {
            QMessageBox::information(this,"成功","已创建群聊");
            refreshfriendlist();
        }
        else
        {
            QMessageBox::critical(this,"错误","创建失败请检查是否已经创建了该群聊");
        }
    }

}

void ordinaryWidget::invitetogroup(QString gno)//my_task
{
    QString  title="邀请入群";
    QString textlabel="请输入账号";
    bool ok=false;
    QString theNo=QInputDialog::getText(this,title,textlabel,QLineEdit::Normal,"",&ok);
    if(ok)
    {
        QSqlQuery postTask;
        QString sendtime=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        postTask.prepare("insert into `my_task`(`sender`,`receiver`,`type`,`content`,`send_time`) values(?,?,?,?,?);");
        postTask.bindValue(0,account);
        postTask.bindValue(1,theNo);
        postTask.bindValue(2,3);//type==3代表普通邀请入群类型，群号位于content中
        postTask.bindValue(3,gno);
        postTask.bindValue(4,sendtime);
        postTask.exec();
        if(postTask.isActive())
        {
            QMessageBox::information(this,"成功","已发出群邀请");
        }
        else
        {
            QMessageBox::critical(this,"失败","发送失败");
        }
    }

}
