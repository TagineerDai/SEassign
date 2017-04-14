# pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "loginDialog.h"
#include "ServerAC.h"
#include "ClientAC.h"
#include "ClientArray.h"
#include "ConfigAC.h"
#include "DataAC.h"
#include <QtWidgets/QApplication>
#include <QtCore\qfileinfo.h>
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qdialog.h>
#include <iostream>
#include <qmessagebox.h>
using namespace std;

ClientAC client;
ServerAC server;
ClientArray clients;
ConfigAC cfg;
ROLE role;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

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
	server = ServerAC(cfg);
	w.initWidget();
	w.show();
	return a.exec();
}
