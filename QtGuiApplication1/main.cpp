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
ROLE role; //Modified by login window
bool allowin;
double Tinit;

//for user login
QHostAddress r_addr;
quint16 r_port;

int main(int argc, char *argv[])
{
	//QT init
	QApplication a(argc, argv);
	serverWindow *ws;
	clientWindow *wc;

	//DB init
	if (!initDB()) {
		QMessageBox::warning(NULL, "提示", "无法启动数据库服务，程序即将关闭。", QMessageBox::Yes | QMessageBox::Cancel);
		return 101;
	}

	//Config init
	cfg = ConfigAC();//Load in the config file "config.txt"
	if (cfg.unfilled == true) {
		int answer = QMessageBox::question(NULL, "系统设置", "设置文件无法正常打开，是否使用默认设置？",QMessageBox::Yes | QMessageBox::No);
		if (answer == QMessageBox::Yes) {
			cfg.defaultCFG();//Use the default config
		}
		else {
			QMessageBox::warning(NULL, "提示", "程序配置未正常进行，程序即将关闭。", QMessageBox::Yes | QMessageBox::Cancel);
			return 100;
		}
	}

	//Login windows
	loginDialog *login = new loginDialog();
	int loginResult = login->exec();
	if (loginResult == QDialog::Rejected) {
		return 102;
	}

	//Have the GUI on
	if (role == ADMIN) {
		ws = new serverWindow();
		ws->show();
	}
	else {//role = ROOM
		bool ok = FALSE;
		Tinit = QInputDialog::getDouble(NULL, "输入","请输入房间初始温度", 31, 0, 100, 2, &ok);
		if (ok) //OK was pressed
			qDebug() << "初始温度" << Tinit;
		else
			return 105;
		wc = new clientWindow();
		wc->show();
	}

	return a.exec();
}
