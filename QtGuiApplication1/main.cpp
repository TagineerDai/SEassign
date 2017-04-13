#include "mainwindow.h"
#include "ServerAC.h"
#include "ClientArray.h"
#include "ConfigAC.h"
#include <QtWidgets/QApplication>
#include <winsock2.h>//For mysql error
#include <mysql.h>
#include <QtCore\qfileinfo.h>
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qdialog.h>
#include <iostream>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqldriver.h>
#include <qmessagebox.h>
using namespace std;

ServerAC server;
ClientArray clients;
ConfigAC cfg;
MYSQL myCont;

bool initDatabase() {
	MySQLSetting dbc = MySQLSetting();
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, dbc.host, dbc.user, dbc.pswd, dbc.table, dbc.port, NULL, 0))
	{
		mysql_query(&myCont, "CREATE DATABASE  IF NOT EXISTS `DAC`");
		mysql_query(&myCont, "USE `DAC`");
		mysql_query(&myCont, "DROP TABLE IF EXISTS `accountInfo`");
		mysql_query(&myCont, "DROP TABLE IF EXISTS `slave`");
		mysql_query(&myCont, "DROP TABLE IF EXISTS `request`");
		mysql_query(&myCont, "DROP TABLE IF EXISTS `event`");
		mysql_query(&myCont, "create table accountInfo("
			"`account` varchar(20) PRIMARY KEY NOT NULL,"
			"`password` varchar(20) DEFAULT 'SE2017')");
		mysql_query(&myCont, "create table slave("
			"`rnum` int,"
			"`consume` real default '0',"
			"`cost` real default '0')");
		mysql_query(&myCont, "create table request("
			"`id` int primary key auto_increment,"
			"`rnum` int,"
			"`timestart` varchar(32),"
			"`timeend` varchar(32),"
			"`tempstart` varchar(32),"
			"`tempend` varchar(32),"
			"`wind` int,"
			"`consume` real default 0,"
			"`cost` real default 0)");
		mysql_query(&myCont, "create table event("
			"`id` int primary key auto_increment,"
			"`rnum` int,"
			"`event` varchar(20),"
			"`time` varchar(20))");
		mysql_close(&myCont);//close the connect
		return true;
	}
	return false;
}


int main(int argc, char *argv[])
{
	//LoginWindow lw;

	cfg = ConfigAC();
	if (cfg.unfilled) {
		//MessageBox 1

		return 100;
	}

	if (!initDatabase()) {
		//MessageBox 2
		return 101;
	}

	server = ServerAC(cfg);
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
