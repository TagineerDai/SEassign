# pragma execution_character_set("utf-8")
#include "serverWindow.h"
#include "clientWindow.h"
#include "loginDialog.h"
#include "ServerAC.h"
#include "Request.h"
#include "ClientAC.h"
#include "ConfigAC.h"
#include "DataAC.h"
#include <qinputdialog.h>
#include <QtWidgets/QApplication>
#include <QtCore\qfileinfo.h>
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qdialog.h>
#include <iostream>
#include <qmessagebox.h>
#include <qhostaddress.h>

using namespace std;
//config

ConfigAC cfg;
int room;
ROLE role;
bool allowin;
double Tinit;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//MainWindow w;
	serverWindow *ws;
	clientWindow *wc;
	if (!initDB()) {
		QMessageBox::warning(NULL, "提示", "无法启动数据库服务，程序即将关闭。", QMessageBox::Yes | QMessageBox::Cancel);
		return 101;
	}

	cfg = ConfigAC();

	if (cfg.unfilled == true) {
		int answer = QMessageBox::question(NULL, "系统设置", "设置文件无法正常打开，是否使用默认设置？",
			QMessageBox::Yes | QMessageBox::No);
		if (answer == QMessageBox::Yes) {
			cfg.defaultCFG();
		}
		else {
			QMessageBox::warning(NULL, "提示", "程序配置未正常进行，程序即将关闭。", QMessageBox::Yes | QMessageBox::Cancel);
			return 100;
		}
	}

	loginDialog *login = new loginDialog();

	int loginResult = login->exec();

	if (loginResult == QDialog::Rejected) {
		return 102;
	}

	if (role == ADMIN) {
		ws = new serverWindow();
		ws->show();
	}
	else {
		bool ok = FALSE;
		Tinit = QInputDialog::getDouble(NULL, "输入","请输入房间初始温度", 31, 10, 40, 2, &ok);
		if (ok)
			qDebug() << "初始温度" << Tinit;// 用户输入一些东西并且按下OK
		else
			return 105;
		wc = new clientWindow();
		wc->show();
	}

	//w.initWidget();
	//network init 
	//1. ROLE=ADMIN build server // listen
	//1. ROLE=ROOM now

	return a.exec();
}
