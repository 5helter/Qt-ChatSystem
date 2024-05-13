/********************************************************************************
** Form generated from reading UI file 'splashdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHDIALOG_H
#define UI_SPLASHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SplashDialog
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *SplashDialog)
    {
        if (SplashDialog->objectName().isEmpty())
            SplashDialog->setObjectName("SplashDialog");
        SplashDialog->resize(1011, 682);
        SplashDialog->setStyleSheet(QString::fromUtf8("QDialog{background-color:rgb(85,168,203)}"));
        label = new QLabel(SplashDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1011, 632));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/chatslapsh.jpg")));
        groupBox = new QGroupBox(SplashDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 630, 1029, 50));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{border:none}"));
        groupBox->setFlat(false);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(11, -1, 30, -1);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout->addWidget(lineEdit_3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(lineEdit_2);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");

        horizontalLayout->addWidget(checkBox);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(SplashDialog);

        QMetaObject::connectSlotsByName(SplashDialog);
    } // setupUi

    void retranslateUi(QDialog *SplashDialog)
    {
        SplashDialog->setWindowTitle(QCoreApplication::translate("SplashDialog", "Dialog", nullptr));
        label->setText(QString());
        groupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("SplashDialog", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("SplashDialog", "localhost", nullptr));
        label_2->setText(QCoreApplication::translate("SplashDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("SplashDialog", "\345\257\206\347\240\201", nullptr));
        checkBox->setText(QCoreApplication::translate("SplashDialog", "\344\277\235\345\255\230\347\224\250\346\210\267\345\220\215", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SplashDialog", "\351\200\200\345\207\272", nullptr));
        pushButton->setText(QCoreApplication::translate("SplashDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SplashDialog: public Ui_SplashDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHDIALOG_H
