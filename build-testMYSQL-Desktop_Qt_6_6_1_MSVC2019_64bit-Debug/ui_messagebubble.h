/********************************************************************************
** Form generated from reading UI file 'messagebubble.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEBUBBLE_H
#define UI_MESSAGEBUBBLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Messagebubble
{
public:

    void setupUi(QWidget *Messagebubble)
    {
        if (Messagebubble->objectName().isEmpty())
            Messagebubble->setObjectName("Messagebubble");
        Messagebubble->resize(351, 241);

        retranslateUi(Messagebubble);

        QMetaObject::connectSlotsByName(Messagebubble);
    } // setupUi

    void retranslateUi(QWidget *Messagebubble)
    {
        Messagebubble->setWindowTitle(QCoreApplication::translate("Messagebubble", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Messagebubble: public Ui_Messagebubble {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEBUBBLE_H
