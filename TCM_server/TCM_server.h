#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_TCM_server.h"
#include<iostream>
#include<opencv2/opencv.hpp>
#include"qimage.h"

#include<qtcpsocket.h>
#include<qtcpserver.h>
#include<qlist.h>
#include<qtimer.h>
#include<qbuffer.h>

#include<qdebug.h>
#include<qhostaddress.h>
#include<qfiledialog.h>
#include<qfile.h>
#include<qdatastream.h>
#include<qdatetime.h>
#include<string>
#include<set>
#include<qmessagebox.h>

using namespace cv;

using namespace std;


class TCM_server : public QMainWindow
{
	Q_OBJECT

public:
	TCM_server(QWidget *parent = Q_NULLPTR);

	//��mat����תΪqimage����
	QImage  cvMatToQImage(const cv::Mat &inMat);

	//���͵��ߵĳߴ���Ϣ    ���ͳɹ�����1  ʧ�ܷ���-1
	int Size_Mess(QString str);

	//�����洫�䵶��ͼƬ    ���ͳɹ�����1  ʧ�ܷ���-1
	int Image_Mess(Mat image);

	//���ý��洫�䵶��ͼƬ    ���ͳɹ�����1  ʧ�ܷ���-1
	int Image_Cong(Mat image);

	//����������Ϣ          ���ͳɹ�����1  ʧ�ܷ���-1
	int Running_Mess(QString str);


public slots:
	void onNewConnection();

	void onReadyRead();
	void onConnected();
	void onDisconnectd();
	void onError(QAbstractSocket::SocketError socketError);
	void Config_Message();

	



private slots:
	//push_button����
	void btnSend();
	void btnImage();

	void run_send();
	void btncong();

private:
	Ui::TCM_serverClass ui;

	QTcpServer sever;
	QList<QTcpSocket*>clients;

	int imageIndex;
	//QString fileName;
	quint32 sizePackLast;

};
