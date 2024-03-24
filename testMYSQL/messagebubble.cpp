#include "messagebubble.h"
#include "ui_messagebubble.h"
#include <QDebug>
#include <QPixmap>
#include <QtMath>
Messagebubble::Messagebubble(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Messagebubble)
{
    ui->setupUi(this);
    type=1;
}

Messagebubble::~Messagebubble()
{
    delete ui;
}

void Messagebubble::setbubble(QVariant va, int type, QString text,QString ano,QString name)
{
    this->va=va;
    this->type=type;
    this->text=text;
    this->ano=ano;
    this->name=name;


}

void Messagebubble::settendsize(int w, int h)
{
    tw=w;
    th=h;
}

void Messagebubble::calculatedtext()
{
    int side = qMin(tw, th); // 获取窗口较小的一边作为直径
     QFont font("Arial", side/4);
     // 计算文本宽度和高度
     QFontMetrics fontMetrics(font);

     if(text=="")
     {
         calculatedH=th;
         calculatedW=tw;
     }
     int i=1;
     int maxWidth=0;
     int heightcount=1;
     int theWidth=0;//每一行的长度

     while(i<=text.length())
     {
         theWidth+=fontMetrics.width(text[i-1]);
         if(theWidth>maxWidth)
         {
             maxWidth=theWidth;
         }
         if(theWidth>=tw-side)
         {
             ++heightcount;
             theWidth=0;
         }
         if(text[i-1]=="\n")
         {
             ++heightcount;
             theWidth=0;
         }
         ++i;
     }


     calculatedH=heightcount*(fontMetrics.height());

     qDebug()<<fontMetrics.height()<<"              "<<heightcount;
     if(calculatedH<=th)
     {
         calculatedH=th;//如果小于倾向高度还是以倾向高度为准
     }
     calculatedW=maxWidth;

     //重定窗口大小
     resize(tw,calculatedH);


}

void Messagebubble::paintEvent(QPaintEvent *event)
{

        int side = qMin(tw, th)/2; // 获取窗口较小的一边作为直径，只要一半

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
        if(type==1)
        {
            painter.drawPixmap(0,0,side,side,croppedPixmap);
        }
        else
        {
            painter.drawPixmap(tw-side,0,side,side,croppedPixmap);
        }



        QPen bubblupen;
        bubblupen.setColor(QColor(173, 216, 230));
        QBrush bubbluebruh(QColor(173, 216, 230));//方块笔刷和笔
        QPen textPen;//文字笔
        textPen.setWidth(10);
        textPen.setColor(Qt::white);

        QFont font("Arial", side/2);//这个side是计算side的一半

        // 在绘图设备上绘制文本宽度矩形
        painter.setPen(bubblupen);
        painter.setBrush(bubbluebruh);
        QRect textrect;
        if(calculatedW<=tw)
        {
            if(type==1)
                textrect=QRect(side, 0,calculatedW,calculatedH);
            else
                textrect=QRect(tw-side-calculatedW, 0, calculatedW, calculatedH);
        }
        else
        {
            if(type==1)
                textrect=QRect(side, 0, tw-side, calculatedH);
            else
                textrect=QRect(0, 0, tw-side, calculatedH);
        }

        //画出气泡
        painter.drawRoundedRect(textrect,10,10);
        //绘制文本
        painter.setPen(textPen);//设置笔
        painter.setFont(font); // 设置字体
        if(type==1)
            painter.drawText(textrect,Qt::AlignLeft | Qt::TextWordWrap,text);
        else
            painter.drawText(textrect,Qt::AlignLeft | Qt::TextWordWrap,text);

}
