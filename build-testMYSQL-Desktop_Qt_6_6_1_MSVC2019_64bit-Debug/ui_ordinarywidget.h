/********************************************************************************
** Form generated from reading UI file 'ordinarywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDINARYWIDGET_H
#define UI_ORDINARYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ordinaryWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QSplitter *splitter_4;
    QScrollArea *friendlistarea;
    QWidget *scrollAreaWidgetContents_3;
    QSplitter *splitter_3;
    QLabel *dialoglabel;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QScrollArea *messagelistarea;
    QWidget *scrollAreaWidgetContents_2;
    QPlainTextEdit *messageedit;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *sendbutton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *sysscrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *addfriendlabel;
    QLabel *creategruop;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Pixlabel;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *nameLabel;
    QLabel *aplabel;
    QLabel *signlabel;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *uncertaintylabel;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButton_3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *ordinaryWidget)
    {
        if (ordinaryWidget->objectName().isEmpty())
            ordinaryWidget->setObjectName("ordinaryWidget");
        ordinaryWidget->resize(616, 674);
        verticalLayout = new QVBoxLayout(ordinaryWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(ordinaryWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName("gridLayout");
        splitter_4 = new QSplitter(tab);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Horizontal);
        friendlistarea = new QScrollArea(splitter_4);
        friendlistarea->setObjectName("friendlistarea");
        friendlistarea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 85, 532));
        friendlistarea->setWidget(scrollAreaWidgetContents_3);
        splitter_4->addWidget(friendlistarea);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Vertical);
        dialoglabel = new QLabel(splitter_3);
        dialoglabel->setObjectName("dialoglabel");
        dialoglabel->setAlignment(Qt::AlignCenter);
        splitter_3->addWidget(dialoglabel);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        messagelistarea = new QScrollArea(splitter);
        messagelistarea->setObjectName("messagelistarea");
        messagelistarea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 471, 345));
        messagelistarea->setWidget(scrollAreaWidgetContents_2);
        splitter->addWidget(messagelistarea);
        messageedit = new QPlainTextEdit(splitter);
        messageedit->setObjectName("messageedit");
        messageedit->setMaximumSize(QSize(16777215, 70));
        splitter->addWidget(messageedit);
        splitter_2->addWidget(splitter);
        groupBox = new QGroupBox(splitter_2);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(402, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        sendbutton = new QPushButton(groupBox);
        sendbutton->setObjectName("sendbutton");

        horizontalLayout_5->addWidget(sendbutton);

        splitter_2->addWidget(groupBox);
        splitter_3->addWidget(splitter_2);
        splitter_4->addWidget(splitter_3);

        gridLayout->addWidget(splitter_4, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        sysscrollArea = new QScrollArea(tab_2);
        sysscrollArea->setObjectName("sysscrollArea");
        sysscrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 564, 488));
        sysscrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(sysscrollArea);

        addfriendlabel = new QLabel(tab_2);
        addfriendlabel->setObjectName("addfriendlabel");
        addfriendlabel->setTextFormat(Qt::PlainText);
        addfriendlabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(addfriendlabel);

        creategruop = new QLabel(tab_2);
        creategruop->setObjectName("creategruop");
        creategruop->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(creategruop);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tab_3->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget = new QWidget(tab_3);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
" border: 3px,solid blue;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        Pixlabel = new QLabel(widget);
        Pixlabel->setObjectName("Pixlabel");
        Pixlabel->setMinimumSize(QSize(100, 100));
        Pixlabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-radius:50px;\n"
"	min-width:100px;\n"
"	min-heigth:100px;\n"
"}"));

        horizontalLayout_4->addWidget(Pixlabel);

        horizontalSpacer_10 = new QSpacerItem(30, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer);

        nameLabel = new QLabel(widget);
        nameLabel->setObjectName("nameLabel");
        QFont font;
        font.setPointSize(17);
        nameLabel->setFont(font);

        verticalLayout_4->addWidget(nameLabel);

        aplabel = new QLabel(widget);
        aplabel->setObjectName("aplabel");
        QFont font1;
        font1.setPointSize(12);
        aplabel->setFont(font1);

        verticalLayout_4->addWidget(aplabel);

        signlabel = new QLabel(widget);
        signlabel->setObjectName("signlabel");
        QFont font2;
        font2.setPointSize(13);
        signlabel->setFont(font2);

        verticalLayout_4->addWidget(signlabel);


        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        horizontalLayout_3->addWidget(widget);


        verticalLayout_3->addLayout(horizontalLayout_3);

        widget_2 = new QWidget(tab_3);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 11, 0, 0);
        uncertaintylabel = new QLabel(widget_2);
        uncertaintylabel->setObjectName("uncertaintylabel");
        uncertaintylabel->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"background-color:rgb(41, 144, 160)\n"
"};"));

        gridLayout_2->addWidget(uncertaintylabel, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(tab_3);
        widget_3->setObjectName("widget_3");
        widget_3->setMaximumSize(QSize(16777215, 50));
        widget_3->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName("pushButton");

        horizontalLayout_6->addWidget(pushButton);


        verticalLayout_3->addWidget(widget_3);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioButton = new QRadioButton(ordinaryWidget);
        radioButton->setObjectName("radioButton");
        radioButton->setMinimumSize(QSize(0, 30));
        radioButton->setMaximumSize(QSize(16777215, 30));
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"   width: 0px;\n"
"   height: 0px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/messagechecked.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton->setIcon(icon);
        radioButton->setIconSize(QSize(30, 30));
        radioButton->setChecked(true);

        horizontalLayout->addWidget(radioButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        radioButton_2 = new QRadioButton(ordinaryWidget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setMinimumSize(QSize(0, 30));
        radioButton_2->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"   width: 0px;\n"
"   height: 0px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_2->setIcon(icon1);
        radioButton_2->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(radioButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        radioButton_3 = new QRadioButton(ordinaryWidget);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setMinimumSize(QSize(0, 30));
        radioButton_3->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"   width: 0px;\n"
"   height: 0px;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/person.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_3->setIcon(icon2);
        radioButton_3->setIconSize(QSize(30, 30));
        radioButton_3->setCheckable(true);
        radioButton_3->setChecked(false);

        horizontalLayout->addWidget(radioButton_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_2 = new QLabel(ordinaryWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_3 = new QLabel(ordinaryWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        label_4 = new QLabel(ordinaryWidget);
        label_4->setObjectName("label_4");
        QPalette palette;
        QBrush brush(QColor(0, 85, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 85, 255, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_4->setPalette(palette);

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ordinaryWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ordinaryWidget);
    } // setupUi

    void retranslateUi(QWidget *ordinaryWidget)
    {
        ordinaryWidget->setWindowTitle(QCoreApplication::translate("ordinaryWidget", "Form", nullptr));
        dialoglabel->setText(QCoreApplication::translate("ordinaryWidget", "TextLabel", nullptr));
        groupBox->setTitle(QString());
        sendbutton->setText(QCoreApplication::translate("ordinaryWidget", "\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ordinaryWidget", "Tab 1", nullptr));
        addfriendlabel->setText(QCoreApplication::translate("ordinaryWidget", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        creategruop->setText(QCoreApplication::translate("ordinaryWidget", "\345\210\233\345\273\272\347\276\244\350\201\212", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ordinaryWidget", "Tab 2", nullptr));
        Pixlabel->setText(QString());
        nameLabel->setText(QCoreApplication::translate("ordinaryWidget", "LUMOS!", nullptr));
        aplabel->setText(QCoreApplication::translate("ordinaryWidget", "\345\261\261\350\245\277\345\250\230\345\255\220\347\201\253\347\224\265\345\216\202", nullptr));
        signlabel->setText(QCoreApplication::translate("ordinaryWidget", "\342\235\244\357\270\217\342\230\240\357\270\217\360\237\244\226", nullptr));
        uncertaintylabel->setText(QCoreApplication::translate("ordinaryWidget", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("ordinaryWidget", "\344\277\256\346\224\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("ordinaryWidget", "\351\241\265", nullptr));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        label_2->setText(QCoreApplication::translate("ordinaryWidget", " \346\266\210\346\201\257", nullptr));
        label_3->setText(QCoreApplication::translate("ordinaryWidget", "   \346\267\273\345\212\240", nullptr));
        label_4->setText(QCoreApplication::translate("ordinaryWidget", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ordinaryWidget: public Ui_ordinaryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDINARYWIDGET_H
