#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test_003.h"
#pragma execution_character_set("utf-8")
#include<iostream>
#include<fstream>

#include<qtablewidget.h>
#include<qscrollbar.h>
#include<qtcpsocket.h>

#include<qlabel.h>
#include<qdatetime.h>
#include<qtimer.h>
#include<qstring.h>
#include<qfont.h>
#include<qpixmap.h>
#include<qimage.h>
#include<qhostaddress.h>
#include<qdebug.h>

#include<vector>
#include<qlist.h>
#include<qfile.h>
#include<qdatetime.h>
#include<qbuffer.h>

#include<qimagereader.h>
#include"config.h"
#include"running_show.h"

#include<qmessagebox.h>

using namespace std;





class test_003 : public QMainWindow
{
	Q_OBJECT

public:
	test_003(QWidget *parent = Q_NULLPTR);
	~test_003();

	//创建表格
	void creattable();
	//样式表初始化
	void init();
	//tcp传输文字
	//void receive_signals();

signals:

	void run_signal(QString str);
	//接受server配置界面图片信息
	void Config_Img(QPixmap img);

public slots:
	void verticalScrollBarHideOrShow(int min, int max);
	//更新时间
	void timeUpdate();
	//启动关闭
	void running();
	//tcp传输数据和图片
	void configuration_send();
	//打开关闭配置页面
	void Config_Open();
	void Config_Closed();
	//打开运行页面
	void Running_open();
	//关闭运行页面
	void Running_Closed();
	//运行信息界面传输信号
	void running_send(QString str);
	//发送f给配置界面的图片信息
	void Cong_Send(QPixmap img);

	void Show_About();


	void button_send();

	//发送配置消息
	void send_Config(QString str);
	



	//接受不同类型数据
	void onReadyRead();
	void onConnected();
	void onDisconnectd();
	void onError(QAbstractSocket::SocketError socketError);







private:
	Ui::test_003Class ui;
	QLabel* ShowTimeLabel;
	//QTableWidget* table_header=nullptr ;
	//QTableWidget* table_content=nullptr;
	QScrollBar* verticalScrollBar = nullptr;
	//QTcpSocket *tcpsocket;
	bool flag;

	QTcpSocket tcpSocket;
	int imageIndex;
	QString fileName; //文件名字

	qint32 sizePackLast;

	config* Config_Page;
	running_show* Running_Page;

	QString Product_Message;



};
