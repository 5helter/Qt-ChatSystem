#ifndef SPLASHDIALOG_H
#define SPLASHDIALOG_H

#include <QDialog>

namespace Ui {
class SplashDialog;
}

class SplashDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SplashDialog(QWidget *parent = nullptr);
    ~SplashDialog();
    QString account;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void writeSettings();

    void readSeettings();
private:
    Ui::SplashDialog *ui;
};

#endif // SPLASHDIALOG_H
