/********************************************************************************
** Form generated from reading UI file 'running_show.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNNING_SHOW_H
#define UI_RUNNING_SHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_running_show
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *running_show)
    {
        if (running_show->objectName().isEmpty())
            running_show->setObjectName(QString::fromUtf8("running_show"));
        running_show->resize(832, 628);
        gridLayout = new QGridLayout(running_show);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(running_show);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(200, 100));

        gridLayout->addWidget(textEdit, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(399, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        widget = new QWidget(running_show);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exit_pushButton = new QPushButton(widget);
        exit_pushButton->setObjectName(QString::fromUtf8("exit_pushButton"));
        exit_pushButton->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(exit_pushButton);


        gridLayout->addWidget(widget, 1, 1, 1, 1);


        retranslateUi(running_show);

        QMetaObject::connectSlotsByName(running_show);
    } // setupUi

    void retranslateUi(QWidget *running_show)
    {
        running_show->setWindowTitle(QApplication::translate("running_show", "running_show", nullptr));
        exit_pushButton->setText(QApplication::translate("running_show", "\345\205\263\351\227\255\344\270\224\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class running_show: public Ui_running_show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNNING_SHOW_H
