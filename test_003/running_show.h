#pragma once

#include <QWidget>
#include "ui_running_show.h"




class running_show : public QWidget
{
	Q_OBJECT

public:
	running_show(QWidget *parent = Q_NULLPTR);
	~running_show();
	

signals:
	void running_Exit();


public slots:
	void Exit_interface();
	//������Ϣ���洫���ź�
	void Show_Message(QString str);


private:
	Ui::running_show ui;
	

};
