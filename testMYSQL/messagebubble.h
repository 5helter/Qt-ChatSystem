#ifndef MESSAGEBUBBLE_H
#define MESSAGEBUBBLE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QVariant>

namespace Ui {
class Messagebubble;
}

//此类需要先设定倾向大小，设置内容，然后再计算宽高度,头像大小取决于倾向大小
class Messagebubble : public QWidget
{
    Q_OBJECT

public:
    explicit Messagebubble(QWidget *parent = nullptr);
    ~Messagebubble();
    QVariant va;
    int type;//type==1时别人的消息
    QString text;
    QString ano;
    QString name;

    int tw;
    int th;//倾向高度和宽度
    int calculatedW;
    int calculatedH;//最终高度和宽度

    void setbubble(QVariant va,int type,QString text,QString ano,QString name);
    void settendsize(int w,int h);
    void calculatedtext();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Messagebubble *ui;
};

#endif // MESSAGEBUBBLE_H
