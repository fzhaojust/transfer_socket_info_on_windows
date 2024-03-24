#include "test_003.h"


test_003::test_003(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	init();
	
	creattable();



	connect(ui.pushButton, &QPushButton::clicked, this, &test_003::running);

	//connect(ui.pushButton_2, &QPushButton::clicked, this, &test_003::show_picture);
	//connect(&tcpSocket, SIGNAL(readyRead()),
	//	this, SLOT(onReadyRead()));
	//connect(&tcpSocket, SIGNAL(connected()),
	//	this, SLOT(onConnectd()));
	//connect(&tcpSocket, SIGNAL(disconnected()),
	//	this, SLOT(onDisconnected()));
	//connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
	//	this, SLOT(onError(QAbstractSocket::SocketError)));
	// tcpSocket.connectToHost("192.168.8.105",8888);

	Running_Page = new running_show();
	Config_Page = new config();


	//TCP通信链接
	connect(&tcpSocket, &QTcpSocket::readyRead, this, &test_003::onReadyRead);
	connect(&tcpSocket, &QTcpSocket::connected, this, &test_003::onConnected);
	connect(&tcpSocket, &QTcpSocket::disconnected, this, &test_003::onDisconnectd);
	connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
		this, SLOT(onError(QAbstractSocket::SocketError)));
	imageIndex = 0;
	sizePackLast = 0;
	//发送刀具尺寸信息
	connect(ui.config_pushButton, &QPushButton::clicked, this, &test_003::configuration_send);

	
	//打开配置页面
	connect(ui.config_pushButton, &QPushButton::clicked, this, &test_003::Config_Open);
	//关闭配置页面
	connect(Config_Page, &config::Config_Exit, this, &test_003::Config_Closed);
	//打开运行页面
	connect(ui.running_pushButton, &QPushButton::clicked, this, &test_003::Running_open);
	//关闭运行页面
	connect(Running_Page, &running_show::running_Exit, this, &test_003::Running_Closed);
	//接收配置页面信号
	connect(Config_Page, SIGNAL(Config_Mess(QString)), this, SLOT(send_Config(QString)));
	//向运行信息界面传输log
	connect(this, SIGNAL(run_signal(QString)), this, SLOT(running_send(QString)));
	//向配置界面传输图片信息  
	connect(this, SIGNAL(Config_Img(QPixmap)), this, SLOT(Cong_Send(QPixmap)));

	//关于界面显示信息
	connect(ui.about_pushButton, &QPushButton::clicked, this, &test_003::Show_About);



}

//样式表修改
void test_003::init() {
	//true 表示
	flag = true;
	QFont ft;

	ft.setPointSize(20);
	int grid_width=512;
	int grid_height=640;
	ui.imagelabel->setFixedSize(QSize(768, 960));
	ui.textEdit->setReadOnly(true);
	//ui.gridLayout_2->SetFixedSize(grid_width, grid_height + 300);
	ui.textEdit->setFixedWidth(grid_width);
	//ui.gridLayout_2->SetFixedSize(QSize(grid_width,grid_height + 300));
	//ui.imagelabel->resize(512, 514);
	ui.label_T->setStyleSheet("QLabel{color:blue;"
		"}");
	ui.label_T->setFont(ft);
	ui.label_T->setText("T1");
	ui.label_3->setStyleSheet("QLabel{color:blue;"
		"}");
	ui.label_3->setFont(ft);
	ui.label_4->setStyleSheet("QLabel{color:blue;"
		"}");
	ui.label_4->setFont(ft);
	// ui->label->setStyleSheet("QLabel{border-image:url(:/new/prefix1/OIP.jpg)}");

	 //ui->label->show();
	ui.lineEdit->setText("0.00mm");
	ui.lineEdit_2->setText("0.00mm");
	ui.lineEdit->setStyleSheet("color:blue");
	ui.lineEdit_2->setStyleSheet("color:blue");
	ui.lineEdit->setFont(ft);
	ui.lineEdit_2->setFont(ft);

	//时间设置
	QTimer *timer = new QTimer(this);
	timer->start(1000); // 每次触发timeout信号时间间隔为1秒
	connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));

	ShowTimeLabel = new QLabel(this);

}

//表格创建
void test_003::creattable() {
	//    table_header = new QTableWidget(this);
    //    table_content = new QTableWidget(this);
    //    table_header->setObjectName("table_header");
    //    table_content->setObjectName("table_content");
	ui.table_header->horizontalHeader()->setVisible(false);
	ui.table_header->verticalHeader()->setVisible(false);
	//    table_header->horizontalHeader()->setVisible(false);
	//    table_header->verticalHeader()->setVisible(false);
	ui.table_header->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.table_header->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.table_header->setFrameShape(QFrame::NoFrame);
	ui.table_header->setFocusPolicy(Qt::NoFocus);
	ui.table_header->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.table_header->setSelectionMode(QAbstractItemView::NoSelection);

	ui.table_header->setRowCount(3);
	ui.table_header->setColumnCount(6);
	ui.table_header->setFixedHeight(ui.table_header->rowHeight(0) + ui.table_header->rowHeight(1) + ui.table_header->rowHeight(2));

	ui.table_header->setSpan(0, 1, 1, 2);
	ui.table_header->setItem(0, 1, new QTableWidgetItem("对刀定位"));
	ui.table_header->item(0, 1)->setTextAlignment(Qt::AlignCenter);

	ui.table_header->setSpan(0, 3, 1, 2);
	ui.table_header->setItem(0, 3, new QTableWidgetItem("磨损监测"));
	ui.table_header->item(0, 3)->setTextAlignment(Qt::AlignCenter);
	ui.table_header->setSpan(0, 5, 1, 1);
	ui.table_header->setItem(0, 5, new QTableWidgetItem("状态监测"));
	ui.table_header->item(0, 5)->setTextAlignment(Qt::AlignCenter);



	ui.table_header->setSpan(1, 1, 1, 2);
	ui.table_header->setItem(1, 1, new QTableWidgetItem("【长度】"));
	ui.table_header->item(1, 1)->setTextAlignment(Qt::AlignCenter);
	ui.table_header->setSpan(1, 3, 1, 2);
	ui.table_header->setItem(1, 3, new QTableWidgetItem("【半径】"));
	ui.table_header->item(1, 3)->setTextAlignment(Qt::AlignCenter);

	//    ui->table_header->setSpan(0, 3, 1, 2);
	//    ui->table_header->setItem(0, 3, new QTableWidgetItem("header3"));
	//    ui->table_header->item(0, 3)->setTextAlignment(Qt::AlignCenter);
	//    ui->table_header->setItem(1, 3, new QTableWidgetItem("header31"));
	//    ui->table_header->item(1, 3)->setTextAlignment(Qt::AlignCenter);
	//    ui->table_header->setItem(1, 4, new QTableWidgetItem("header32"));
	//    ui->table_header->item(1, 4)->setTextAlignment(Qt::AlignCenter);

	ui.table_header->setItem(2, 0, new QTableWidgetItem("刀具"));
	ui.table_header->item(2, 0)->setTextAlignment(Qt::AlignCenter);
	ui.table_header->setItem(2, 1, new QTableWidgetItem("形状"));
	ui.table_header->item(2, 1)->setTextAlignment(Qt::AlignCenter);
	ui.table_header->setItem(2, 2, new QTableWidgetItem("磨损"));
	ui.table_header->item(2, 2)->setTextAlignment(Qt::AlignCenter);
	ui.table_header->setItem(2, 3, new QTableWidgetItem("形状"));
	ui.table_header->item(2, 3)->setTextAlignment(Qt::AlignCenter);
	ui.table_header->setItem(2, 4, new QTableWidgetItem("磨损"));
	ui.table_header->item(2, 4)->setTextAlignment(Qt::AlignCenter);
	ui.table_header->setItem(2, 5, new QTableWidgetItem("状态监测"));
	ui.table_header->item(2, 5)->setTextAlignment(Qt::AlignCenter);




	ui.table_content->horizontalHeader()->setVisible(false);
	ui.table_content->verticalHeader()->setVisible(false);
	ui.table_content->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.table_content->setFrameShape(QFrame::NoFrame);
	ui.table_content->setFocusPolicy(Qt::NoFocus);
	ui.table_content->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.table_content->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.table_content->setAlternatingRowColors(true);
	ui.table_content->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui.table_content->setColumnCount(6);
	ui.table_content->setRowCount(100);
	//    for(int i=0; i<15; i++)
	//    {
	//        ui->table_content->setItem(i/5, i%5, new QTableWidgetItem("item"+QString::number(i/5)+QString::number(i%5)));
	//    }

	for (int i = 0; i < 90; ++i) {
		QString str = QString::fromStdString("T") + QString::number(i);
		ui.table_content->setItem(i, 0, new QTableWidgetItem("T" + QString::number(i)));
		ui.table_content->item(i, 0)->setTextAlignment(Qt::AlignCenter);

	}


	verticalScrollBar = new QScrollBar(Qt::Vertical, this);
	ui.table_content->setVerticalScrollBar(verticalScrollBar);

	connect(ui.table_content->horizontalScrollBar(), &QScrollBar::valueChanged, ui.table_header->horizontalScrollBar(), &QScrollBar::setSliderPosition);
	connect(ui.table_header->horizontalScrollBar(), &QScrollBar::valueChanged, ui.table_content->horizontalScrollBar(), &QScrollBar::setSliderPosition);
	connect(verticalScrollBar, &QScrollBar::rangeChanged, this, &test_003::verticalScrollBarHideOrShow);

	//    QVBoxLayout *vb_no_vertical_scrollbar = new QVBoxLayout();
	//    vb_no_vertical_scrollbar->addWidget(ui->table_header);
	//    vb_no_vertical_scrollbar->addWidget(ui->table_content);
	//    vb_no_vertical_scrollbar->setSpacing(0);

	//    QHBoxLayout *hb_tables = new QHBoxLayout(this);
	//    hb_tables->addLayout(vb_no_vertical_scrollbar);
	//    hb_tables->addWidget(verticalScrollBar);


		//所有对setColumnWidth()的调用都要放在setModel()之后
	int tableheader_width = 100;
	ui.table_header->setColumnWidth(0, tableheader_width);
	ui.table_content->setColumnWidth(0, tableheader_width);
	int table_width = 190;
	ui.table_header->setColumnWidth(1, table_width);
	ui.table_content->setColumnWidth(1, table_width);
	ui.table_header->setColumnWidth(2, table_width);
	ui.table_content->setColumnWidth(2, table_width);
	ui.table_header->setColumnWidth(3, table_width);
	ui.table_content->setColumnWidth(3, table_width);
	ui.table_header->setColumnWidth(4, table_width);
	ui.table_content->setColumnWidth(4, table_width);
	ui.table_header->setColumnWidth(5, table_width);
	ui.table_content->setColumnWidth(5, table_width);
	
	this->setStyleSheet("QTableWidget#table_header::item{background-color:lightgray;} QTableWidget#table_header{gridline-color:gray;} QTableWidget#table_content::item::selected{background-color:lightgreen;color:white;}");
}






//表格头与biogenic体同大小
void test_003::verticalScrollBarHideOrShow(int min, int max) {
	if (min == max)
	{
		verticalScrollBar->setHidden(true);
	}
	else
	{
		verticalScrollBar->setHidden(false);
	}

}

//时间戳
void test_003::timeUpdate() {
	QDateTime CurrentTime = QDateTime::currentDateTime();
	QString strTime = CurrentTime.toString(" yyyy年MM月dd日 hh:mm:ss "); //设置显示的格式
	ShowTimeLabel->setText(strTime);
	ui.statusBar->addWidget(ShowTimeLabel,1);

	//ui.statusBar->addWidget(ShowTimeLabel);
	//statusBar()->addPermanentWidget(ShowTimeLabel);
	//statusBar()->setSizeGripEnabled(true); //设置是否显示右边的大小控制点
}

//启动与关闭程序
void test_003::running() {
	//开启
	if (flag == true) {

		QString ip = "127.0.0.1";
		//本地测试
		//QString ip = "127.0.0.1";
		qint16 port = 8000;
		string file_name = "config.txt";

		fstream configuration_file;
		configuration_file.open(file_name);
		if (!configuration_file)
			return ;

		string s;
		for (int i = 0; i < 2; ++i) {
			getline(configuration_file, s);
			switch (i)
			{
			case 0:
				ip= QString::fromStdString(s);
			case 1:
				port= stoi(s);
			default:
				break;
			}
		}
		configuration_file.close();
		cout << ip.toStdString() << "  " << port << endl;
		
		//主动和服务器建立链接
		tcpSocket.connectToHost(QHostAddress(ip), port);
		flag = false;

		ui.pushButton->setText("关闭");
	}
	//关闭
	else
	{
		//if (tcpsocket == nullptr)return;
		flag = true;
		//主动和对方断开链接
		tcpSocket.disconnectFromHost();
		ui.pushButton->setText("开始");
		cout << "disconnected" << endl;
		QObject *obj = this->sender();
		QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
		if (socket == 0)
		{
			return;
		}
		socket->close();
		
	} 
}


test_003::~test_003() {
	delete verticalScrollBar;
	delete Config_Page;

	delete ShowTimeLabel;
	delete Running_Page;

}

//读取数据
void test_003::onReadyRead() {
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
		//cout << "full pack" << endl;
		QByteArray dataFull;
		stream >> dataFull;
		//设置为0
		sizePackLast = 0;
		//cout << dataFull.toStdString() << endl;
		//判断剩下的字节数,是否会有粘包的情况
		sizeNow = socket->bytesAvailable();
		//取出消息头
		QString prefix = dataFull.mid(0, 4);
		//记录系统时间
		QString dataTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
		if (prefix == "TXT:") {
			
			//QString textContent=dataFull.mid(4);
			QByteArray byteArray = dataFull.mid(4);//从第四个位置一直取到最后
			QString str = QString::fromLocal8Bit(byteArray.constData());//显示中文
			//文本数据显示
			


			//表格中显示数据
			ui.table_content->setItem(2, 2, new QTableWidgetItem(str));
			ui.table_content->item(2, 2)->setTextAlignment(Qt::AlignCenter);
		}
		//主界面传输图片
		else if (prefix == "IMG1")
		{
			QByteArray byteArray = dataFull.mid(4);//从第四个位置一直取到最后
			QPixmap img;
			img.loadFromData(byteArray);

			ui.imagelabel->setScaledContents(true);
			int with = ui.imagelabel->width();
			int height = ui.imagelabel->height();
			ui.imagelabel->resize(img.width(), img.height());

			//QPixmap fitpixmap = img.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
			ui.imagelabel->setPixmap(img);
			ui.imagelabel->show();

		}
		else if (prefix == "IMG2") {
			QByteArray byteArray = dataFull.mid(4);//从第四个位置一直取到最后
			QPixmap img;
			img.loadFromData(byteArray);
			emit Config_Img(img);


		}
		else if (prefix == "RUN:") {
			QByteArray byteArray = dataFull.mid(4);//从第四个位置一直取到最后
			QString str = QString::fromLocal8Bit(byteArray.constData());//显示中文
			//发送信息
			emit run_signal(str);
			//connect(this, SIGNAL(run_signal(str)), &Config_Page, SLOT(running_show::Show_Message(QString)));

		}
		else {
			ui.textEdit->append("消息传输错误");
		}
	} while (sizeNow > 0);
	

}


void test_003::button_send() {
	
}


void test_003::onConnected() {
	ui.textEdit->append("成功与服务器链接");
}
void test_003::onDisconnectd()//断开
{
	ui.textEdit->append("与服务器断开链接");
	flag = true;
	//主动和对方断开链接
	tcpSocket.disconnectFromHost();
	ui.pushButton->setText("开始");
	cout << "disconnected" << endl;
	QObject *obj = this->sender();
	QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
	if (socket == 0)
	{
		return;
	}
	socket->close();

}


void test_003::onError(QAbstractSocket::SocketError socketError) {
	ui.textEdit->append("error" + QString(socketError));
	//cout << "error:" << socketError << endl;
	flag = true;
	//主动和对方断开链接
	tcpSocket.disconnectFromHost();
	ui.pushButton->setText("开始");
	cout << "error disconnected" << endl;
	QObject *obj = this->sender();
	QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
	if (socket == 0)
	{
		return;
	}
	socket->close();
}


//发送配置消息
void test_003::send_Config(QString str) {
	
	if (str.isEmpty())return;
	QString msgInput = str;

	//封装包头
	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	stream << (quint32)0 << msgInput.toLocal8Bit();
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket.write(dataSend);
	ui.textEdit->setFocus();//定位光标
}



//发送文本消息
void test_003::configuration_send(){
	QString strSend = ui.textEdit->toPlainText();
	send_Config(strSend);

	//QString strSend = ui.textEdit->toPlainText();
	//if (strSend.isEmpty())return;
	//QString msgInput = "TXT:" + strSend;
	////封装包头
	//QByteArray dataSend;
	//QDataStream stream(&dataSend, QIODevice::WriteOnly);
	//stream << (quint32)0 << msgInput.toLocal8Bit();
	//stream.device()->seek(0);
	//stream << dataSend.size();
	//tcpSocket.write(dataSend);
	//ui.textEdit->setFocus();//定位光标
}




void test_003::Config_Open() {
	Config_Page->show();

}

void test_003::Config_Closed() {
	Config_Page->hide();

}


void test_003::Running_open() {
	Running_Page->show();
}
void test_003::Running_Closed() {
	Running_Page->hide();


}

void test_003::running_send(QString str) {
	Running_Page->Show_Message(str);

}



//发送配置界面的图片信息
void test_003::Cong_Send(QPixmap img) {
	Config_Page->Show_img(img);

}

void test_003::Show_About() {

	//QString t1 = "Product ID: 1034012872";
	//QString t2 = "Version  VTM5.0V9.0.0.4";

	//QMessageBox::about(this, "About", t1+"<br>"+t2);
	//默认版本
	QString t1 = "Product ID: 1034012872_Version  VTM5.0V9.0.0.4";


	QStringList list = t1.split("_");
	QMessageBox::about(this, "About", list[0] + "<br>" + list[1]);
	

}