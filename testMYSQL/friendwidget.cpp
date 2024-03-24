#include "friendwidget.h"
#include "ui_friendwidget.h"
#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QMenu>
FriendWidget::FriendWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendWidget)
{
    ui->setupUi(this);
    ano="";
    selected=0;
    setContextMenuPolicy(Qt::CustomContextMenu);//启用右键菜单功能
    connect(this,&FriendWidget::customContextMenuRequested,this,&FriendWidget::on_friendwidget_customContextMenuRequested);
}

FriendWidget::~FriendWidget()
{
    delete ui;
}

void FriendWidget::setSize(int w, int h)
{
    resize(w,h);
    update();
}

void FriendWidget::setfriendano(QString ano)
{
    this->ano=ano;
}

void FriendWidget::setPimage(QVariant& va)
{
    this->va=va; 
}

void FriendWidget::setName(QString name)
{
    this->name=name;
}

void FriendWidget::on_pushButton_clicked()
{

}

void FriendWidget::mousePressEvent(QMouseEvent *e)
{

    if(e->buttons()==Qt::LeftButton)
    {
        emit friendselected(name,ano,va);
         emit checkchanged(ano);
    }
//    if(e->buttons()==Qt::RightButton)
//    {
//        emit deleteFriend(ano);
//    }
    QWidget::mousePressEvent(e);
}

void FriendWidget::paintEvent(QPaintEvent *e)
{

    double side=qMin(this->height(),this->width())/1.5;

    // 圆形图片
    QRectF circleRect = QRectF(0, 0, side, side);
    QSize size(side,side);
    // 加载图片
    QImage image(size, QImage::Format_ARGB32_Premultiplied);
    QPixmap originalPixmap;
    if(va.toByteArray().isEmpty())
        originalPixmap.load(":/res/nopix.png");
    else
        originalPixmap.loadFromData(va.toByteArray());
    // 创建一个QImage对象，并使用QPainter将原始QPixmap绘制到QImage中
    QPainter imagepainter(&image);
    imagepainter.setRenderHint(QPainter::Antialiasing);
    imagepainter.setBackground(Qt::transparent); // 设置背景为透明
    imagepainter.eraseRect(QRect(0, 0, size.width(), size.height())); // 清空画布
    imagepainter.drawPixmap(0, 0, size.width(), size.height(), originalPixmap); // 绘制QPixmap

    // 使用QPainter将圆形区域裁剪出来，并将结果绘制到新的QPixmap中
    QPixmap croppedPixmap(size);
    croppedPixmap.fill(Qt::transparent); // 设置背景为透明
    QPainter pixmapPainter(&croppedPixmap);

    pixmapPainter.setBrush(QBrush(Qt::white));
    pixmapPainter.drawEllipse(0, 0, size.width(), size.height()); // 绘制圆形路径
    pixmapPainter.setCompositionMode(QPainter::CompositionMode_SourceIn); //使用相交的方式绘制,和透明度为0的区域相交透明度保持0，与白色相交保持不变
    pixmapPainter.drawImage(0, 0, image); // 将裁剪结果绘制到新的QPixmap中

    //在窗口上画出圆形
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawPixmap(20,0,side,side,croppedPixmap);

    if(selected)
    {
        painter.setBrush(QColor(85,168,203));
        painter.setPen(QColor(85,168,203));
        painter.drawRect(0,0,10,this->height()/1.5);
    }

}

void FriendWidget::on_informationaction_triggered()
{
    emit showdetail(ano);
}

void FriendWidget::on_action_triggered()
{
    emit deleteFriend(ano);
}


void FriendWidget::on_quitgroupaction_triggered()
{
    emit deleteFriend(ano);
}

void FriendWidget::on_friendwidget_customContextMenuRequested(const QPoint &pos)
{
    if(ano=="")
        return;
    QMenu* Menulist=new QMenu;
    Menulist->addAction(ui->informationaction);
    if(ano[ano.length()-1]=="#")
    {
        Menulist->addAction(ui->quitgroupaction);
        Menulist->addAction(ui->invitaction);
    }
    else
    {
        Menulist->addAction(ui->action);
    }

    Menulist->exec(QCursor::pos());//模态运行
    delete Menulist;//运行完释放内存
}


void FriendWidget::on_invitaction_triggered()
{
    emit invitetogroup(ano);
}

