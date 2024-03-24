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

	//将mat类型转为qimage类型
	QImage  cvMatToQImage(const cv::Mat &inMat);

	//发送刀具的尺寸信息    发送成功返回1  失败返回-1
	int Size_Mess(QString str);

	//主界面传输刀具图片    发送成功返回1  失败返回-1
	int Image_Mess(Mat image);

	//配置界面传输刀具图片    发送成功返回1  失败返回-1
	int Image_Cong(Mat image);

	//发送运行信息          发送成功返回1  失败返回-1
	int Running_Mess(QString str);


public slots:
	void onNewConnection();

	void onReadyRead();
	void onConnected();
	void onDisconnectd();
	void onError(QAbstractSocket::SocketError socketError);
	void Config_Message();

	



private slots:
	//push_button函数
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
