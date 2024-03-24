#ifndef SQLWIDGET_H
#define SQLWIDGET_H

#include <QWidget>
#include <QDrag>
#include <QDropEvent>
#include <QResizeEvent>

namespace Ui {
class Sqlwidget;
}

class Sqlwidget : public QWidget
{
    Q_OBJECT

public:
    Sqlwidget(int type,QWidget *parent = nullptr);
    ~Sqlwidget();

    QString pixPath;
    QStringList otherInformation;
    int type;//type==1代表输入个人信息，type==2代表创建群聊

private:
    Ui::Sqlwidget *ui;
protected:
    void dragEnterEvent(QDragEnterEvent* e) override;
    void resizeEvent(QResizeEvent *e) override;
    void dropEvent(QDropEvent *e) override;//加了override就必须要实现，否则编译不通过

signals:
    void informationChanged(QString pixPath,QStringList otherInformation);
private slots:
    void on_changeedit_textChanged();
    void on_acceptbutton_clicked();
    void on_pushButton_2_clicked();
};

#endif // SQLWIDGET_H
