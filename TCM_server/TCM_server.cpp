#include "TCM_server.h"

TCM_server::TCM_server(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	bool ok = sever.listen(QHostAddress::Any, 8000);//�����˿�
	if (ok == 0)cout << "listen failed" << endl;
	else cout << "listen success" << endl;
	
	connect(&sever, &QTcpServer::newConnection, this, &TCM_server::onNewConnection);
	//connect(&sever, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
	imageIndex = 0;
	sizePackLast = 0;
	
	ui.textInput->setFocus();
	//����
	connect(ui.btnSend, &QPushButton::clicked, this, &TCM_server::btnSend);
	connect(ui.btnImage, &QPushButton::clicked, this, &TCM_server::btnImage);
	connect(ui.run_push, &QPushButton::clicked, this, &TCM_server::run_send);

	connect(ui.btncong, &QPushButton::clicked, this, &TCM_server::btncong);

}



void TCM_server::onNewConnection() {

	//ʹ�����socket�ͻ��˽���ͨ��
	QTcpSocket *socket = sever.nextPendingConnection();//���socket
	cout << "get tcpsocket " << endl;
	ui.textMsg->append("��ͻ��˽�������");

	//ui.textMsg->append(QString("�ɹ���ͻ�������onNewConnection"));

	clients.append(socket);//�������
	//�����źźͲ�
	
	//��ȡ������Ϣ
		connect(socket, SIGNAL(readyRead()),
			this, SLOT(Config_Message()));

	//connect(socket, SIGNAL(readyRead()),this, SLOT(onReadyRead()));
	connect(socket, SIGNAL(connected()),
		this, SLOT(onConnected()));
	connect(socket, SIGNAL(disconnected()),
		this, SLOT(onDisconnectd()));

	/*connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
		this, SLOT(onError(QAbstractSocket::SocketError)));*/
	connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
		this, SLOT(onError(QAbstractSocket::SocketError)));

}

//������������
void TCM_server::Config_Message() {
	QObject *obj = this->sender();
	QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
	//��ǰ������������ݴ�С,�յ������ݴ�С.
	qint64 sizeNow = 0;
	do
	{

		sizeNow = socket->bytesAvailable();
		QDataStream stream(socket);
		if (sizePackLast == 0)
		{
			if (sizeNow < sizeof(quint32))
			{
				return;
			}
			stream >> sizePackLast;//�Ѿ���ֵ��
		}
		//������������,�ȴ�������;
		if (sizeNow < sizePackLast - 4)
		{
			return;
		}
		//cout << "full pack"<<endl;

		QByteArray dataFull;
		stream >> dataFull;
		//����Ϊ0
		sizePackLast = 0;

		//�ж�ʣ�µ��ֽ���,�Ƿ����ճ�������
		sizeNow = socket->bytesAvailable();

		QString prefix = dataFull.mid(0, 4);
		QString dataTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
		//����
		if (prefix == "cfg1") {
			//�źŴ�����---�Զ�
			ui.textMsg->append("cfg1");
			ui.textInput->setFocus();
		}
		//����
		else if (prefix == "cfg2")
		{
			ui.textMsg->append("cfg2");
			ui.textInput->setFocus();
		}
		//��ѹ����
		else if (prefix == "cfg3") {
			ui.textMsg->append("cfg3");
			ui.textInput->setFocus();
		}
		//�������
		else if (prefix == "cfg4") {
			ui.textMsg->append("cfg3");
			ui.textInput->setFocus();
		}
		

	} while (sizeNow > 0);
}


//��������
void TCM_server::onReadyRead() {

	QObject *obj = this->sender();
	QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
	//��ǰ������������ݴ�С,�յ������ݴ�С.
	qint64 sizeNow = 0;
	do
	{
		sizeNow = socket->bytesAvailable();
		QDataStream stream(socket);
		if (sizePackLast == 0)
		{
			if (sizeNow < sizeof(quint32))
			{
				return;
			}
			stream >> sizePackLast;//�Ѿ���ֵ��
		}
		//������������,�ȴ�������;
		if (sizeNow < sizePackLast - 4)
		{
			return;
		}
		//cout << "full pack"<<endl;

		QByteArray dataFull;
		stream >> dataFull;
		//����Ϊ0
		sizePackLast = 0;

		//�ж�ʣ�µ��ֽ���,�Ƿ����ճ�������
		sizeNow = socket->bytesAvailable();

		QString prefix = dataFull.mid(0, 4);
		QString dataTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

		
		if (prefix == "TXT:") {
			//ui.textMsg->append(dataTime);
			ui.textInput->setFocus();
			//QString textContent=dataFull.mid(4);
			QByteArray byteArray = dataFull.mid(4);
			QString str = QString::fromLocal8Bit(byteArray.constData());
			//ui.textMsg->append("<p>" + str + "</p><br>");
			ui.textMsg->append(str);

			ui.textInput->setFocus();
		}
		/*else if (prefix == "IMG:")
		{
			QString index = QString::number(imageIndex++);
			QFile file(index + ".png");
			file.open(QIODevice::WriteOnly);
			file.write(dataFull.mid(4));
			file.close();

			QString htmlTag = QString("<img src=\"%1\"></img><br>");
			htmlTag = htmlTag.arg(index + ".png");
			cout << ("<p>" + dataTime + "</p><br>").toStdString() << endl;
			ui.textMsg->append("<p>" + dataTime + "</p><br>");
			ui.textInput->setFocus();
			ui.textMsg->append(htmlTag);
			ui.textInput->setFocus();
		}*/
		else {
			ui.textMsg->append("����Ϊ��");
			ui.textInput->setFocus();
		}

	} while (sizeNow > 0);

}

void TCM_server::onConnected() {
	
	ui.textMsg->append(QString("�ɹ����ӿͻ���"));
	//cout << "���ӳɹ�" << endl;

}
void TCM_server::onDisconnectd() {
	QObject *obj = this->sender();
	QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
	clients.removeAll(socket);
	socket->deleteLater();
	ui.textMsg->append(QString("��ͻ��˶Ͽ�����"));
	cout << "disconnected" << endl;

}
void TCM_server::onError(QAbstractSocket::SocketError socketError) {

	cout << "error:" << "   ";
}

//���䵶�߳ߴ���Ϣ
int TCM_server::Size_Mess(QString str) {
	if (str.isEmpty())
	{
		return -1;
	}
	
	for (QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr)
	{
		QTcpSocket *client = *itr;
		QString msgInput = "TXT:" + str;
		//��װ��ͷ
		QByteArray dataSend;
		QDataStream stream(&dataSend, QIODevice::WriteOnly);
		stream << (quint32)0 << msgInput.toLocal8Bit();
		stream.device()->seek(0);
		stream << dataSend.size();
		client->write(dataSend);
	}
	return 0;
}

//��ť��������
void TCM_server::btnSend() {
	QString strSend = ui.textInput->toPlainText();
	Size_Mess(strSend);
	ui.textInput->clear();
	ui.textInput->setFocus();

}



//�����洫�䵶��ͼƬ
int TCM_server::Image_Mess(Mat image) {

	if (image.empty())return -1;
	QPixmap pixmap= QPixmap::fromImage(cvMatToQImage(image));
	QBuffer buffer;
	buffer.open(QIODevice::ReadWrite);
	//pixmap����Ϊ�գ������Ƚ�ͼƬ���ص�pixmap��
	pixmap.save(&buffer, "bmp");
	QByteArray pixArray;
	pixArray.append(buffer.data());
	QByteArray data = "IMG1" + pixArray;
	//��װ��ͷ
	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	stream << (quint32)0 << data;
	stream.device()->seek(0);
	stream << dataSend.size();

	for (QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr)
	{
		QTcpSocket *client = *itr;

		client->write(dataSend);
	}
	return 0;

}




//��ť����������ͼƬ
void TCM_server::btnImage() {
	Mat img = imread("T32020-06-04 22-08-11.bmp",1);
	if (img.empty())return;
	Image_Mess(img);
	
	/////////---------------------------------------------
	//set<string>imagefiles;

	////���ļ���ѡ����棬ѡ��ͼƬ·��
	//QString image_path = QFileDialog::getExistingDirectory(this, QStringLiteral("ѡ��ͼƬ����Ŀ¼"), "", QFileDialog::ShowDirsOnly);
	//if (image_path.isEmpty())
	//{
	//	QMessageBox::information(NULL, "Error", QStringLiteral("δ������Ч�ļ�·��"));
	//	return;
	//}
	////�ж��ļ���·���ܷ�ɹ���
	//QDir *dir = new QDir(image_path);
	//if (!dir->exists())
	//{
	//	
	//	QMessageBox::information(NULL, "Error", QStringLiteral("���ļ���ʧ��"));
	//	return;
	//}
	//imagefiles.clear();
	//QStringList filter;
	//QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
	////qDebug() << fileInfo->count();
	//bool flag = false;
	//for (int i = 0; i < fileInfo->count(); i++)
	//{
	//	if (fileInfo->at(i).fileName()[0] == '.')
	//		continue;

	//	//��������ָ��ͼƬ��ʽ���ļ�
	//	if (fileInfo->at(i).suffix() != "bmp"&&fileInfo->at(i).suffix() != "jpg"&&fileInfo->at(i).suffix() != "BMP"&&fileInfo->at(i).suffix() != "JPG"&&fileInfo->at(i).suffix() != "tif")
	//		continue;
	//	//qDebug() << fileInfo->at(i).filePath();
	//	//qDebug() << fileInfo->at(i).fileName();

	//	flag = true;

	//	//�ж�ͼƬ�������Ƿ����Ҫ����������򱨴�
	//	QRegExp rex("\\d*_\\d*.\\d*m_\\d*_\\d*-\\d*-\\d*-\\d*.(bmp|BMP|tif|jpg|JPG)");
	//	if (!rex.exactMatch(fileInfo->at(i).fileName()))
	//	{
	//		QMessageBox::information(NULL, "Error", QStringLiteral("ͼƬ����������Ҫ��"));
	//		return;
	//	}

	//	//����ͼƬ�����֣���ͼƬ�ı�ź����ִ���map��
	//	QStringList list = fileInfo->at(i).fileName().split("-");

	//	string filename = string(fileInfo->at(i).filePath().toLocal8Bit());

	//	imagefiles.insert(filename);

	//	

	//}
	////����ļ���·����û�з���Ҫ���ͼƬ���򱨴�
	//if (!flag)
	//{
	//	QMessageBox::information(NULL, "Error", QStringLiteral("��·���²�����ͼƬ�ļ�"));
	//	
	//	return;
	//}
	//for (set<string>::iterator iter = imagefiles.begin(); iter != imagefiles.end(); iter++) {
	//	string filename = *iter;
	//	Mat img = imread("filename", 1);
	//	if (img.empty())return;
	//	Image_Mess(img);


	//}
	//QString image = QFileDialog::getOpenFileName(this, "title", ".", "*.png *.jpg *.bmp");
	//if (image.isEmpty())
	//	return;
	//QFile file(image);
	//file.open(QIODevice::ReadOnly);
	//QByteArray data = "IMG:" + file.readAll();
	//file.close();
	////��װ��ͷ
	//QByteArray dataSend;
	//QDataStream stream(&dataSend, QIODevice::WriteOnly);
	//stream << (quint32)0 << data;
	//stream.device()->seek(0);
	//stream << dataSend.size();

	//for (QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr)
	//{
	//	QTcpSocket *client = *itr;

	//	client->write(dataSend);
	//}
	//

}

int TCM_server::Image_Cong(Mat image) {

	if (image.empty())return -1;
	QPixmap pixmap = QPixmap::fromImage(cvMatToQImage(image));
	QBuffer buffer;
	buffer.open(QIODevice::ReadWrite);
	//pixmap����Ϊ�գ������Ƚ�ͼƬ���ص�pixmap��
	pixmap.save(&buffer, "bmp");
	QByteArray pixArray;
	pixArray.append(buffer.data());
	QByteArray data = "IMG2" + pixArray;
	//��װ��ͷ
	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	stream << (quint32)0 << data;
	stream.device()->seek(0);
	stream << dataSend.size();




	for (QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr)
	{
		QTcpSocket *client = *itr;

		client->write(dataSend);
	}
	return 1;
}


void TCM_server::btncong() {

	Mat img = imread("T32020-06-04 22-08-11.bmp", 1);
	if (img.empty())return;

	Image_Cong(img);


}
//����������Ϣ��������
int TCM_server::Running_Mess(QString str) {
	if (str.isEmpty())
	{
		return -1;
	}

	QString dataTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	for (QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr)
	{
		QTcpSocket *client = *itr;
		QString msgInput = "RUN:" + dataTime+"   "+ str;
		//��װ��ͷ
		
		QByteArray dataSend;
		QDataStream stream(&dataSend, QIODevice::WriteOnly);
		stream << (quint32)0 << msgInput.toLocal8Bit();
		stream.device()->seek(0);
		stream << dataSend.size();
		client->write(dataSend);
	}
	return 1;
}
//�������н�����Ϣ
void TCM_server::run_send() {
	QString str = "����������Ϣѽ";
	//��¼ϵͳʱ��
	Running_Mess(str);
	
}



QImage TCM_server::cvMatToQImage(const cv::Mat &inMat)
{
	switch (inMat.type())
	{
		// 8-bit, 4 channel
	case CV_8UC4:
	{
		QImage image(inMat.data,
			inMat.cols, inMat.rows,
			static_cast<int>(inMat.step),
			QImage::Format_ARGB32);

		return image;
	}
	// 8-bit, 3 channel
	case CV_8UC3:
	{
		QImage image(inMat.data,
			inMat.cols, inMat.rows,
			static_cast<int>(inMat.step),
			QImage::Format_RGB888);

		return image.rgbSwapped();
	}

	// 8-bit, 1 channel
	case CV_8UC1:
	{
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
		QImage image(inMat.data,
			inMat.cols, inMat.rows,
			static_cast<int>(inMat.step),
			QImage::Format_Grayscale8);//Format_Alpha8 and Format_Grayscale8 were added in Qt 5.5
#else//���ﻹ��һ��д����������
		static QVector<QRgb>  sColorTable;

		// only create our color table the first time
		if (sColorTable.isEmpty())
		{
			sColorTable.resize(256);

			for (int i = 0; i < 256; ++i)
			{
				sColorTable[i] = qRgb(i, i, i);
			}
		}

		QImage image(inMat.data,
			inMat.cols, inMat.rows,
			static_cast<int>(inMat.step),
			QImage::Format_Indexed8);

		image.setColorTable(sColorTable);
#endif

		return image;
	}

	default:
		qWarning() << "CVS::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
		break;
	}
	return QImage();
}
