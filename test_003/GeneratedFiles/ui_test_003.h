/********************************************************************************
** Form generated from reading UI file 'test_003.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_003_H
#define UI_TEST_003_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_003Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_7;
    QWidget *widget_2;
    QGridLayout *gridLayout_6;
    QLabel *label_T;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *imagelabel;
    QGridLayout *gridLayout;
    QTableWidget *table_header;
    QTableWidget *table_content;
    QWidget *widget_3;
    QTextEdit *textEdit;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QPushButton *running_pushButton;
    QPushButton *config_pushButton;
    QPushButton *pushButton;
    QPushButton *about_pushButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test_003Class)
    {
        if (test_003Class->objectName().isEmpty())
            test_003Class->setObjectName(QString::fromUtf8("test_003Class"));
        test_003Class->resize(1050, 1580);
        centralWidget = new QWidget(test_003Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_7 = new QGridLayout(centralWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout_6 = new QGridLayout(widget_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_T = new QLabel(widget_2);
        label_T->setObjectName(QString::fromUtf8("label_T"));

        gridLayout_6->addWidget(label_T, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_4->addWidget(lineEdit, 0, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 0, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_5->addWidget(lineEdit_2, 0, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 2, 1, 1);

        radioButton = new QRadioButton(widget_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_6->addWidget(radioButton, 0, 3, 1, 1);

        radioButton_2 = new QRadioButton(widget_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_6->addWidget(radioButton_2, 0, 4, 1, 1);

        radioButton_3 = new QRadioButton(widget_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_6->addWidget(radioButton_3, 0, 5, 1, 1);

        radioButton_4 = new QRadioButton(widget_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_6->addWidget(radioButton_4, 0, 6, 1, 1);


        gridLayout_7->addWidget(widget_2, 0, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        imagelabel = new QLabel(centralWidget);
        imagelabel->setObjectName(QString::fromUtf8("imagelabel"));
        imagelabel->setMinimumSize(QSize(512, 640));
        imagelabel->setMaximumSize(QSize(512, 640));
        imagelabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        imagelabel->setScaledContents(false);

        gridLayout_2->addWidget(imagelabel, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        table_header = new QTableWidget(centralWidget);
        table_header->setObjectName(QString::fromUtf8("table_header"));
        table_header->setMinimumSize(QSize(1024, 150));

        gridLayout->addWidget(table_header, 0, 0, 1, 1);

        table_content = new QTableWidget(centralWidget);
        table_content->setObjectName(QString::fromUtf8("table_content"));
        table_content->setMinimumSize(QSize(1024, 350));

        gridLayout->addWidget(table_content, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_7->addLayout(verticalLayout, 1, 0, 1, 3);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        textEdit = new QTextEdit(widget_3);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(11, 11, 400, 192));
        textEdit->setMinimumSize(QSize(400, 50));

        gridLayout_7->addWidget(widget_3, 2, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        running_pushButton = new QPushButton(widget);
        running_pushButton->setObjectName(QString::fromUtf8("running_pushButton"));
        running_pushButton->setMinimumSize(QSize(70, 50));

        gridLayout_3->addWidget(running_pushButton, 2, 2, 1, 1);

        config_pushButton = new QPushButton(widget);
        config_pushButton->setObjectName(QString::fromUtf8("config_pushButton"));
        config_pushButton->setMinimumSize(QSize(70, 50));

        gridLayout_3->addWidget(config_pushButton, 2, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        about_pushButton = new QPushButton(widget);
        about_pushButton->setObjectName(QString::fromUtf8("about_pushButton"));
        about_pushButton->setMinimumSize(QSize(70, 50));

        gridLayout_3->addWidget(about_pushButton, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 1, 1, 1);


        gridLayout_7->addWidget(widget, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        test_003Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(test_003Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1050, 26));
        test_003Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test_003Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        test_003Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(test_003Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        test_003Class->setStatusBar(statusBar);

        retranslateUi(test_003Class);

        QMetaObject::connectSlotsByName(test_003Class);
    } // setupUi

    void retranslateUi(QMainWindow *test_003Class)
    {
        test_003Class->setWindowTitle(QApplication::translate("test_003Class", "test_003", nullptr));
        label_T->setText(QApplication::translate("test_003Class", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("test_003Class", "\345\220\215\344\271\211\347\233\264\345\276\204\357\274\232", nullptr));
        label_4->setText(QApplication::translate("test_003Class", "\346\265\213\351\207\217\345\200\274\357\274\232", nullptr));
        radioButton->setText(QApplication::translate("test_003Class", "\351\230\262\346\212\244", nullptr));
        radioButton_2->setText(QApplication::translate("test_003Class", "\347\224\265\346\272\220", nullptr));
        radioButton_3->setText(QApplication::translate("test_003Class", "\345\277\253\351\227\250", nullptr));
        radioButton_4->setText(QApplication::translate("test_003Class", "\350\277\220\350\241\214", nullptr));
        imagelabel->setText(QString());
        running_pushButton->setText(QApplication::translate("test_003Class", "\350\277\220\350\241\214\344\277\241\346\201\257", nullptr));
        config_pushButton->setText(QApplication::translate("test_003Class", "\351\205\215\347\275\256", nullptr));
        pushButton->setText(QApplication::translate("test_003Class", "\345\274\200\345\247\213", nullptr));
        about_pushButton->setText(QApplication::translate("test_003Class", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test_003Class: public Ui_test_003Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_003_H
