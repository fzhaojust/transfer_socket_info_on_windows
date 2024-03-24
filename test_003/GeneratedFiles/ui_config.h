/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_config
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_Img;
    QPushButton *pushopen;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushclose;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *config)
    {
        if (config->objectName().isEmpty())
            config->setObjectName(QString::fromUtf8("config"));
        config->resize(1031, 719);
        gridLayout_3 = new QGridLayout(config);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_2 = new QWidget(config);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_Img = new QLabel(widget_2);
        label_Img->setObjectName(QString::fromUtf8("label_Img"));
        label_Img->setMinimumSize(QSize(512, 640));
        label_Img->setMaximumSize(QSize(512, 640));
        label_Img->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_Img, 0, 0, 1, 3);

        pushopen = new QPushButton(widget_2);
        pushopen->setObjectName(QString::fromUtf8("pushopen"));

        gridLayout_2->addWidget(pushopen, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(287, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        pushclose = new QPushButton(widget_2);
        pushclose->setObjectName(QString::fromUtf8("pushclose"));
        pushclose->setMinimumSize(QSize(90, 0));

        gridLayout_2->addWidget(pushclose, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(286, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 3, 1, 1);


        gridLayout_3->addWidget(widget_2, 0, 0, 2, 1);

        widget = new QWidget(config);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(80, 50));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);


        gridLayout_3->addWidget(widget, 0, 1, 1, 1);

        exit_pushButton = new QPushButton(config);
        exit_pushButton->setObjectName(QString::fromUtf8("exit_pushButton"));
        exit_pushButton->setMinimumSize(QSize(100, 50));

        gridLayout_3->addWidget(exit_pushButton, 1, 1, 1, 1);


        retranslateUi(config);

        QMetaObject::connectSlotsByName(config);
    } // setupUi

    void retranslateUi(QWidget *config)
    {
        config->setWindowTitle(QApplication::translate("config", "config", nullptr));
        label_Img->setText(QApplication::translate("config", "TextLabel", nullptr));
        pushopen->setText(QApplication::translate("config", "\346\211\223\345\274\200", nullptr));
        pushclose->setText(QApplication::translate("config", "\345\205\263\351\227\255", nullptr));
        pushButton->setText(QApplication::translate("config", "\350\203\214\345\205\211", nullptr));
        label->setText(QApplication::translate("config", "TextLabel", nullptr));
        pushButton_2->setText(QApplication::translate("config", "\345\277\253\351\227\250", nullptr));
        label_2->setText(QApplication::translate("config", "TextLabel", nullptr));
        pushButton_3->setText(QApplication::translate("config", "\346\255\243\345\216\213\351\230\262\346\212\244", nullptr));
        label_3->setText(QApplication::translate("config", "TextLabel", nullptr));
        pushButton_4->setText(QApplication::translate("config", "\345\210\200\345\205\267\346\270\205\346\264\201", nullptr));
        label_4->setText(QApplication::translate("config", "TextLabel", nullptr));
        exit_pushButton->setText(QApplication::translate("config", "\345\205\263\351\227\255\345\271\266\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class config: public Ui_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
