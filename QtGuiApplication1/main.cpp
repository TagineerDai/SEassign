#include "mainwindow.h"
#include "ServerAC.h"
#include "ClientArray.h"
#include "ConfigAC.h"
#include <QtWidgets/QApplication>

ServerAC server;
ClientArray clients;
ConfigAC cfg;

bool validConfig();
bool validDatabase();
void newConfig();

int main(int argc, char *argv[])
{	
	// show startwind loading for 1 sec or so
	bool configvalid = validConfig();
	// if (configvalid) ask show The last right setting / new custom setting?
	// 1 skip the newConfig window and rewrite.
	
	// newConfig window
	newConfig();
	// match | unmatch
	// unmatch msg -- "Wrong pwd -- Please contact with the developer.\n"
	// match --> main window
	server = ServerAC(cfg);
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}

bool validConfig() {
	cfg = ConfigAC();
	return true;
}

void newConfig() {
	return ;
}

bool validDatabase() {
	//TODO
	return true;
}