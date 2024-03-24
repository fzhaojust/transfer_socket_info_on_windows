#include "test_003.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test_003 w;
	//w.resize(960, 640);
	//w.setFixedSize(1100, 800);
	//w.setFixedSize(2000, 2000);

	w.setWindowTitle(QString::fromUtf8("TCM"));


	w.showMaximized();

	//w.show();
	return a.exec();
}
