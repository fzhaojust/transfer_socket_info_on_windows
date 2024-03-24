/********************************************************************************
** Form generated from reading UI file 'TCM_server.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCM_SERVER_H
#define UI_TCM_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCM_serverClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QTextEdit *textMsg;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btnSend;
    QPushButton *btnImage;
    QPushButton *run_push;
    QPushButton *btnclose;
    QPushButton *btncong;
    QTextEdit *textInput;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TCM_serverClass)
    {
        if (TCM_serverClass->objectName().isEmpty())
            TCM_serverClass->setObjectName(QString::fromUtf8("TCM_serverClass"));
        TCM_serverClass->resize(968, 557);
        centralWidget = new QWidget(TCM_serverClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textMsg = new QTextEdit(centralWidget);
        textMsg->setObjectName(QString::fromUtf8("textMsg"));

        gridLayout_3->addWidget(textMsg, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnSend = new QPushButton(widget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));

        gridLayout->addWidget(btnSend, 0, 0, 1, 1);

        btnImage = new QPushButton(widget);
        btnImage->setObjectName(QString::fromUtf8("btnImage"));

        gridLayout->addWidget(btnImage, 1, 0, 1, 1);

        run_push = new QPushButton(widget);
        run_push->setObjectName(QString::fromUtf8("run_push"));

        gridLayout->addWidget(run_push, 2, 0, 1, 1);

        btnclose = new QPushButton(widget);
        btnclose->setObjectName(QString::fromUtf8("btnclose"));

        gridLayout->addWidget(btnclose, 4, 0, 1, 1);

        btncong = new QPushButton(widget);
        btncong->setObjectName(QString::fromUtf8("btncong"));

        gridLayout->addWidget(btncong, 3, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 2, 1, 1);

        textInput = new QTextEdit(centralWidget);
        textInput->setObjectName(QString::fromUtf8("textInput"));

        gridLayout_2->addWidget(textInput, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 100));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        TCM_serverClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TCM_serverClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 968, 26));
        TCM_serverClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TCM_serverClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TCM_serverClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TCM_serverClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TCM_serverClass->setStatusBar(statusBar);

        retranslateUi(TCM_serverClass);

        QMetaObject::connectSlotsByName(TCM_serverClass);
    } // setupUi

    void retranslateUi(QMainWindow *TCM_serverClass)
    {
        TCM_serverClass->setWindowTitle(QApplication::translate("TCM_serverClass", "TCM_server", nullptr));
        btnSend->setText(QApplication::translate("TCM_serverClass", "send", nullptr));
        btnImage->setText(QApplication::translate("TCM_serverClass", "image", nullptr));
        run_push->setText(QApplication::translate("TCM_serverClass", "running", nullptr));
        btnclose->setText(QApplication::translate("TCM_serverClass", "close", nullptr));
        btncong->setText(QApplication::translate("TCM_serverClass", "Cong", nullptr));
        label->setText(QApplication::translate("TCM_serverClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCM_serverClass: public Ui_TCM_serverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCM_SERVER_H
