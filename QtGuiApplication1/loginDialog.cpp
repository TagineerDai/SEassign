# pragma execution_character_set("utf-8")
#include "loginDialog.h"
#include "qmessagebox.h"
#include "qdebug.h"
#include "DataAC.h"
loginDialog::loginDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

loginDialog::~loginDialog()
{
}

void loginDialog::on_Bhelp_clicked() {
	QMessageBox::warning(NULL, "°ïÖú", "ÇëÁªÏµÏµÍ³¹ÜÀíÔ±¡£", QMessageBox::Yes | QMessageBox::Cancel);
}

void loginDialog::on_Blogin_clicked() {
	int isroom = this->ui.roleTab->currentIndex();
	if (isroom) {
		role = ROOM;
		qDebug() << "ROOM!";
		if (varifyRoom(this->ui.roomuser->text(), this->ui.roompwd->text())) {
			room = this->ui.roomuser->text().toInt();
			role = ROOM;
			this->accept();
			return;
		}
		else {
			QMessageBox::warning(NULL, "´íÎó", "ÃÜÂë´íÎó£¬ÇëÖØÊÔ¡£", QMessageBox::Yes | QMessageBox::Cancel);
			this->ui.roompwd->setText(QString(""));
			return;
		}
	}else{
		role = ADMIN;
		qDebug() << "ADMIN!";
		if (varifyAdmin(this->ui.adminuser->text(), this->ui.adminpwd->text())) {
			role = ADMIN;
			this->accept();
			return;
		}
		else {
			QMessageBox::warning(NULL, "´íÎó", "ÃÜÂë´íÎó£¬ÇëÖØÊÔ¡£", QMessageBox::Yes | QMessageBox::Cancel);
			this->ui.adminpwd->setText(QString(""));
			return;
		}
	}
}

void loginDialog::on_Bcancel_clicked() {
	this->reject();
	return;
}

void loginDialog::on_closeButton_clicked() {
	this->reject();
	return;
}
