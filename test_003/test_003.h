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

	//�������
	void creattable();
	//��ʽ���ʼ��
	void init();
	//tcp��������
	//void receive_signals();

signals:

	void run_signal(QString str);
	//����server���ý���ͼƬ��Ϣ
	void Config_Img(QPixmap img);

public slots:
	void verticalScrollBarHideOrShow(int min, int max);
	//����ʱ��
	void timeUpdate();
	//�����ر�
	void running();
	//tcp�������ݺ�ͼƬ
	void configuration_send();
	//�򿪹ر�����ҳ��
	void Config_Open();
	void Config_Closed();
	//������ҳ��
	void Running_open();
	//�ر�����ҳ��
	void Running_Closed();
	//������Ϣ���洫���ź�
	void running_send(QString str);
	//����f�����ý����ͼƬ��Ϣ
	void Cong_Send(QPixmap img);

	void Show_About();


	void button_send();

	//����������Ϣ
	void send_Config(QString str);
	



	//���ܲ�ͬ��������
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
	QString fileName; //�ļ�����

	qint32 sizePackLast;

	config* Config_Page;
	running_show* Running_Page;

	QString Product_Message;



};
