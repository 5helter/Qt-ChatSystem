/********************************************************************************
** Form generated from reading UI file 'sqlwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLWIDGET_H
#define UI_SQLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sqlwidget
{
public:
    QGridLayout *gridLayout;
    QLabel *changepimagelabel;
    QTextEdit *changeedit;
    QPushButton *acceptbutton;
    QLabel *label;
    QPushButton *pushButton_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;

    void setupUi(QWidget *Sqlwidget)
    {
        if (Sqlwidget->objectName().isEmpty())
            Sqlwidget->setObjectName("Sqlwidget");
        Sqlwidget->resize(424, 704);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Sqlwidget->sizePolicy().hasHeightForWidth());
        Sqlwidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Sqlwidget);
        gridLayout->setObjectName("gridLayout");
        changepimagelabel = new QLabel(Sqlwidget);
        changepimagelabel->setObjectName("changepimagelabel");
        changepimagelabel->setMinimumSize(QSize(0, 402));
        changepimagelabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(changepimagelabel, 0, 0, 1, 1);

        changeedit = new QTextEdit(Sqlwidget);
        changeedit->setObjectName("changeedit");

        gridLayout->addWidget(changeedit, 2, 0, 1, 1);

        acceptbutton = new QPushButton(Sqlwidget);
        acceptbutton->setObjectName("acceptbutton");

        gridLayout->addWidget(acceptbutton, 5, 0, 1, 1);

        label = new QLabel(Sqlwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(Sqlwidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 6, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(Sqlwidget);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout->addWidget(plainTextEdit, 4, 0, 1, 1);

        label_2 = new QLabel(Sqlwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);


        retranslateUi(Sqlwidget);
        QObject::connect(pushButton_2, &QPushButton::clicked, Sqlwidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Sqlwidget);
    } // setupUi

    void retranslateUi(QWidget *Sqlwidget)
    {
        Sqlwidget->setWindowTitle(QCoreApplication::translate("Sqlwidget", "Form", nullptr));
        changepimagelabel->setText(QCoreApplication::translate("Sqlwidget", "TextLabel", nullptr));
        acceptbutton->setText(QCoreApplication::translate("Sqlwidget", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("Sqlwidget", "\350\256\276\347\275\256\347\276\244\345\217\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Sqlwidget", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("Sqlwidget", "\350\256\276\347\275\256\347\276\244\350\201\212\345\220\215\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sqlwidget: public Ui_Sqlwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLWIDGET_H
