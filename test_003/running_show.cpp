#include "running_show.h"



running_show::running_show(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	this->resize(400, 300);

	connect(ui.exit_pushButton, &QPushButton::clicked, this, &running_show::Exit_interface);

}


void running_show::Exit_interface() {
	emit running_Exit();
}


void running_show::Show_Message(QString str) {
	ui.textEdit->append(str);
	ui.textEdit->setFocus();

}

running_show::~running_show()
{


}


