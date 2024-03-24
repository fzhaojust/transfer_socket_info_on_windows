#include "config.h"

config::config(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	connect(ui.exit_pushButton, &QPushButton::clicked, this, &config::Exit_interface);

	connect(ui.pushButton, &QPushButton::clicked, this, &config::Backlight);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &config::shutter);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &config::protect);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &config::clean);
}



void config::Exit_interface() {

	emit Config_Exit();

}



config::~config()
{

}
void config::Backlight() {

	emit Config_Mess("cfg1");


}
void config::shutter() {
	emit Config_Mess("cfg2");

}
void config::protect() {
	emit Config_Mess("cfg3");

}
void config::clean() {
	emit Config_Mess("cfg4");

}


void config::Show_img(QPixmap img) {

	ui.label_Img->setScaledContents(true);
	int width = ui.label_Img->width();
	int height = ui.label_Img->height();
	ui.label_Img->resize(img.width(), img.height());
	ui.label_Img->setPixmap(img);
	ui.label_Img->show();



	//ui.imagelabel->setScaledContents(true);
	//int with = ui.imagelabel->width();
	//int height = ui.imagelabel->height();
	//ui.imagelabel->resize(img.width(), img.height());

	////QPixmap fitpixmap = img.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // °´±ÈÀýËõ·Å
	//ui.imagelabel->setPixmap(img);
	//ui.imagelabel->show();
}

