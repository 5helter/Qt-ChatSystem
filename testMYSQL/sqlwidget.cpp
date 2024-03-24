#include "sqlwidget.h"
#include "ui_sqlwidget.h"
#include <QMimeData>
#include <QFileInfo>
#include <QDebug>
Sqlwidget::Sqlwidget(int type ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sqlwidget)
{
    ui->setupUi(this);

    ui->changepimagelabel->setAcceptDrops(0);
    ui->changeedit->setAcceptDrops(0);
    this->setAcceptDrops(1);//窗口来处理拖放事件
    ui->changepimagelabel->setScaledContents(true);//内容适应图片大小

    ui->changepimagelabel->setText("从系统中拖动放置新头像吧");
    pixPath="";
    otherInformation<<""<<"";
    this->type=type;
    if(type==1)
    {
        ui->label->setText("设置昵称:");
        ui->label_2->setText("设置个性签名");
    }
}

Sqlwidget::~Sqlwidget()
{
    delete ui;
}

void Sqlwidget::dragEnterEvent(QDragEnterEvent *e)
{

    if(e->mimeData()->hasUrls())
    {
        QString filename=e->mimeData()->urls().at(0).fileName();

       QFileInfo fileInfo(filename);
       QString ext=fileInfo.suffix().toUpper();
       if(ext=="JPG"||ext=="PNG")
           e->acceptProposedAction();//接受拖放操作
       else
           e->ignore();
    }
}

void Sqlwidget::resizeEvent(QResizeEvent *e)
{
}

void Sqlwidget::dropEvent(QDropEvent *e)
{
    QString filename=e->mimeData()->urls().at(0).path();
    filename=filename.right(filename.length()-1);//去除最前面的\

    pixPath=filename;
    QPixmap pix(filename);

    ui->changepimagelabel->setPixmap(pix);
    e->accept();
}

void Sqlwidget::on_changeedit_textChanged()
{
}


void Sqlwidget::on_acceptbutton_clicked()
{
    otherInformation.clear();
    otherInformation<<ui->changeedit->toPlainText()<<ui->plainTextEdit->toPlainText();
    qDebug()<<otherInformation[0]<<otherInformation[1];
    emit informationChanged(pixPath,otherInformation);
    this->close();
}


void Sqlwidget::on_pushButton_2_clicked()
{
    this->close();
}

