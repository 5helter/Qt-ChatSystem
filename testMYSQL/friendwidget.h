#ifndef FRIENDWIDGET_H
#define FRIENDWIDGET_H

#include <QWidget>
#include <QByteArray>
#include <QString>
#include <QVariant>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
namespace Ui {
class FriendWidget;
}

class FriendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FriendWidget(QWidget *parent = nullptr);
    ~FriendWidget();
    void setSize(int w,int h);
    void setfriendano(QString ano);
    void setPimage(QVariant&  va);
    void setName(QString name);
    QString ano;
    QVariant va;
    QString name;

    bool selected;
signals:
    void friendselected(QString name,QString ano,QVariant va);
    void deleteFriend(QString ano);
    void invitetogroup(QString gno);
    void showdetail(QString ano);
    void checkchanged(QString ano);

private slots:
    void on_pushButton_clicked();
    void on_informationaction_triggered();

    void on_action_triggered();

    void on_quitgroupaction_triggered();

    void on_friendwidget_customContextMenuRequested(const QPoint &pos);//右键菜单事件

    void on_invitaction_triggered();

protected:
    void mousePressEvent(QMouseEvent* e) override;
    void paintEvent(QPaintEvent* e) override;

private:
    Ui::FriendWidget *ui;
};

#endif // FRIENDWIDGET_H
