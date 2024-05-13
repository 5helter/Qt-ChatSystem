/********************************************************************************
** Form generated from reading UI file 'friendwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDWIDGET_H
#define UI_FRIENDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendWidget
{
public:
    QAction *informationaction;
    QAction *action;
    QAction *quitgroupaction;
    QAction *invitaction;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *FriendWidget)
    {
        if (FriendWidget->objectName().isEmpty())
            FriendWidget->setObjectName("FriendWidget");
        FriendWidget->resize(213, 102);
        FriendWidget->setMinimumSize(QSize(0, 102));
        informationaction = new QAction(FriendWidget);
        informationaction->setObjectName("informationaction");
        action = new QAction(FriendWidget);
        action->setObjectName("action");
        quitgroupaction = new QAction(FriendWidget);
        quitgroupaction->setObjectName("quitgroupaction");
        invitaction = new QAction(FriendWidget);
        invitaction->setObjectName("invitaction");
        horizontalLayout = new QHBoxLayout(FriendWidget);
        horizontalLayout->setObjectName("horizontalLayout");

        retranslateUi(FriendWidget);

        QMetaObject::connectSlotsByName(FriendWidget);
    } // setupUi

    void retranslateUi(QWidget *FriendWidget)
    {
        FriendWidget->setWindowTitle(QCoreApplication::translate("FriendWidget", "Form", nullptr));
        informationaction->setText(QCoreApplication::translate("FriendWidget", "\346\237\245\347\234\213\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        action->setText(QCoreApplication::translate("FriendWidget", "\345\210\240\351\231\244\345\245\275\345\217\213", nullptr));
        quitgroupaction->setText(QCoreApplication::translate("FriendWidget", "\351\200\200\345\207\272\346\210\226\350\200\205\345\210\240\351\231\244\347\276\244\350\201\212", nullptr));
        invitaction->setText(QCoreApplication::translate("FriendWidget", "\351\202\200\350\257\267\345\205\245\347\276\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendWidget: public Ui_FriendWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDWIDGET_H
