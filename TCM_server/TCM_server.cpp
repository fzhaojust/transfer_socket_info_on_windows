#include "TCM_server.h"

TCM_server::TCM_server(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	bool ok = sever.listen(QHostAddress::Any, 8000);//监听端口
	if (ok == 0)cout << "listen failed" << endl;
	else cout << "listen success" << endl;
	
	connect(&sever, &QTcpServer::newConnection, this, &TCM_server::onNewConnection);
	//connect(&sever, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
	imageIndex = 0;
	sizePackLast = 0;
	
	ui.textInput->setFocus();
	//发送
	connect(ui.btnSend, &QPushButton::clicked, this, &TCM_server::btnSend);
	connect(ui.btnImage, &QPushButton::clicked, this, &TCM_server::btnImage);
	connect(ui.run_push, &QPushButton::clicked, this, &TCM_server::run_send);

	connect(ui.btncong, &QPushButton::clicked, this, &TCM_server::btncong);

}



void TCM_server::onNewConnection() {

	//使用这个socket客户端进行通信
	QTcpSocket *socket = sever.nextPendingConnection();//获得socket
	cout << "get tcpsocket " << endl;
	ui.textMsg->append("与客户端建立连接");

	//ui.textMsg->append(QString("成功与客户端连接onNewConnection"));

	clients.append(socket);//进入监听
	//连接信号和槽
	
	//读取配置信息
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

//接收配置数据
void TCM_server::Config_Message() {
	QObject *obj = this->sender();
	QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
	//当前缓冲区里的数据大小,收到的数据大小.
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
			stream >> sizePackLast;//已经有值了
		}
		//包不完整返回,等待包完整;
		if (sizeNow < sizePackLast - 4)
		{
			return;
		}
		//cout << "full pack"<<endl;

		QByteArray dataFull;
		stream >> dataFull;
		//设置为0
		sizePackLast = 0;

		//判断剩下的字节数,是否会有粘包的情况
		sizeNow = socket->bytesAvailable();

		QString prefix = dataFull.mid(0, 4);
		QString dataTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
		//背光
		if (prefix == "cfg1") {
			//信号处理函数---自定
			ui.textMsg->append("cfg1");
			ui.textInput->setFocus();
		}
		//快门
		else if (prefix == "cfg2")
		{
			ui.textMsg->append("cfg2");
			ui.textInput->setFocus();
		}
		//正压防护
		else if (prefix == "cfg3") {
			ui.textMsg->append("cfg3");
			ui.textInput->setFocus();
		}
		//刀具清洁
		else if (prefix == "cfg4") {
			ui.textMsg->append("cfg3");
			ui.textInput->setFocus();
		}
		

	} while (sizeNow > 0);
}


//接受数据
void TCM_server::onReadyRead() {

	QObject *obj = this->sender();
	QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
	//当前缓冲区里的数据大小,收到的数据大小.
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
			stream >> sizePackLast;//已经有值了
		}
		//包不完整返回,等待包完整;
		if (sizeNow < sizePackLast - 4)
		{
			return;
		}
		//cout << "full pack"<<endl;

		QByteArray dataFull;
		stream >> dataFull;
		//设置为0
		sizePackLast = 0;

		//判断剩下的字节数,是否会有粘包的情况
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
			ui.textMsg->append("数据为空");
			ui.textInput->setFocus();
		}

	} while (sizeNow > 0);

}

void TCM_server::onConnected() {
	
	ui.textMsg->append(QString("成功连接客户端"));
	//cout << "连接成功" << endl;

}
void TCM_server::onDisconnectd() {
	QObject *obj = this->sender();
	QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
	clients.removeAll(socket);
	socket->deleteLater();
	ui.textMsg->append(QString("与客户端断开连接"));
	cout << "disconnected" << endl;

}
void TCM_server::onError(QAbstractSocket::SocketError socketError) {

	cout << "error:" << "   ";
}

//传输刀具尺寸信息
int TCM_server::Size_Mess(QString str) {
	if (str.isEmpty())
	{
		return -1;
	}
	
	for (QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr)
	{
		QTcpSocket *client = *itr;
		QString msgInput = "TXT:" + str;
		//封装包头
		QByteArray dataSend;
		QDataStream stream(&dataSend, QIODevice::WriteOnly);
		stream << (quint32)0 << msgInput.toLocal8Bit();
		stream.device()->seek(0);
		stream << dataSend.size();
		client->write(dataSend);
	}
	return 0;
}

//按钮发送数据
void TCM_server::btnSend() {
	QString strSend = ui.textInput->toPlainText();
	Size_Mess(strSend);
	ui.textInput->clear();
	ui.textInput->setFocus();

}



//主界面传输刀具图片
int TCM_server::Image_Mess(Mat image) {

	if (image.empty())return -1;
	QPixmap pixmap= QPixmap::fromImage(cvMatToQImage(image));
	QBuffer buffer;
	buffer.open(QIODevice::ReadWrite);
	//pixmap不能为空，必须先将图片加载到pixmap中
	pixmap.save(&buffer, "bmp");
	QByteArray pixArray;
	pixArray.append(buffer.data());
	QByteArray data = "IMG1" + pixArray;
	//封装包头
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




//按钮发送主界面图片
void TCM_server::btnImage() {
	Mat img = imread("T32020-06-04 22-08-11.bmp",1);
	if (img.empty())return;
	Image_Mess(img);
	
	/////////---------------------------------------------
	//set<string>imagefiles;

	////打开文件夹选择界面，选择图片路径
	//QString image_path = QFileDialog::getExistingDirectory(this, QStringLiteral("选择图片所在目录"), "", QFileDialog::ShowDirsOnly);
	//if (image_path.isEmpty())
	//{
	//	QMessageBox::information(NULL, "Error", QStringLiteral("未输入有效文件路径"));
	//	return;
	//}
	////判断文件夹路径能否成功打开
	//QDir *dir = new QDir(image_path);
	//if (!dir->exists())
	//{
	//	
	//	QMessageBox::information(NULL, "Error", QStringLiteral("打开文件夹失败"));
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

	//	//跳过不是指定图片格式的文件
	//	if (fileInfo->at(i).suffix() != "bmp"&&fileInfo->at(i).suffix() != "jpg"&&fileInfo->at(i).suffix() != "BMP"&&fileInfo->at(i).suffix() != "JPG"&&fileInfo->at(i).suffix() != "tif")
	//		continue;
	//	//qDebug() << fileInfo->at(i).filePath();
	//	//qDebug() << fileInfo->at(i).fileName();

	//	flag = true;

	//	//判断图片的命名是否符合要求，如果不是则报错
	//	QRegExp rex("\\d*_\\d*.\\d*m_\\d*_\\d*-\\d*-\\d*-\\d*.(bmp|BMP|tif|jpg|JPG)");
	//	if (!rex.exactMatch(fileInfo->at(i).fileName()))
	//	{
	//		QMessageBox::information(NULL, "Error", QStringLiteral("图片命名不符合要求"));
	//		return;
	//	}

	//	//处理图片的名字，将图片的编号和名字存入map中
	//	QStringList list = fileInfo->at(i).fileName().split("-");

	//	string filename = string(fileInfo->at(i).filePath().toLocal8Bit());

	//	imagefiles.insert(filename);

	//	

	//}
	////如果文件件路径下没有符合要求的图片，则报错
	//if (!flag)
	//{
	//	QMessageBox::information(NULL, "Error", QStringLiteral("该路径下不含有图片文件"));
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
	////封装包头
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
	//pixmap不能为空，必须先将图片加载到pixmap中
	pixmap.save(&buffer, "bmp");
	QByteArray pixArray;
	pixArray.append(buffer.data());
	QByteArray data = "IMG2" + pixArray;
	//封装包头
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
//传输运行信息界面数据
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
		//封装包头
		
		QByteArray dataSend;
		QDataStream stream(&dataSend, QIODevice::WriteOnly);
		stream << (quint32)0 << msgInput.toLocal8Bit();
		stream.device()->seek(0);
		stream << dataSend.size();
		client->write(dataSend);
	}
	return 1;
}
//发送运行界面消息
void TCM_server::run_send() {
	QString str = "这是运行消息呀";
	//记录系统时间
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
#else//这里还有一种写法，最后给出
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
