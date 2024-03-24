#pragma once

#include <QWidget>
#include "ui_config.h"

class config : public QWidget
{
	Q_OBJECT

public:
	config(QWidget *parent = Q_NULLPTR);
	~config();


signals:
	void Config_Exit();
	void Config_Mess(QString str);

public slots:
	void Exit_interface();

	void Backlight();
	void shutter();
	void protect();
	void clean();

	void Show_img(QPixmap img);



private:
	Ui::config ui;
};
