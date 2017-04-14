#pragma once
#include <winsock2.h>//For mysql error
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqldriver.h>
#include <qdatetime.h>
#include <cstring>
#include <qstring.h>
#include<sstream>
#include "ConfigAC.h"
#include <qdebug.h>
using namespace std;

bool initDB();
bool getDB(MYSQL *db);
void closeDB(MYSQL *db);

class Admin{
public:
	bool varified = false;
	Admin(QString usr, QString pwd);
};

bool varifyAdmin(QString usr, QString pwd);

class User {
public:
	bool varified = false;
	int roomID;
	std::string pwd;
	User(QString _usr, QString _pwd) {
		MYSQL db;
		char* qstr;
		MYSQL_RES *res_ptr;
		MYSQL_ROW record;
		roomID = _usr.toInt();

		qDebug() << roomID;
		MySQLSetting dbc = MySQLSetting();
		mysql_init(&db);
		if (mysql_real_connect(&db, dbc.host, dbc.user, dbc.pswd, dbc.table, dbc.port, NULL, 0))
			qDebug() << "Connected!"; 
		else return;
		mysql_query(&db, "USE `DAC`");
		sprintf(qstr, "select `password` from `room` where roomID = %d;", roomID);
		int Qdone = mysql_query(&db, qstr);
		if (Qdone == 0) {
			res_ptr = mysql_store_result(&db);
			if(mysql_num_rows(res_ptr)==1) {
				record = mysql_fetch_row(res_ptr);
				qDebug() << "query answer!!!" << record[0] << endl;
				int issame = QString::compare(QString(record[0]), _pwd);
				if (issame == 0) varified = true;
			}
			else {
				qDebug() << "rownumber error :" << mysql_num_rows(res_ptr);
			}			
			mysql_free_result(res_ptr);
		}
		else {
			qDebug() << "query string should be char* = = false";
		}
		mysql_close(&db);
	}
};

bool varifyRoom(QString usr, QString pwd);

class REC {
public:
	QString ID, Tin, Toff, minute, wind, consume, money;
	REC() {};
	REC(int _ID, string _Tin, string _Toff, double _min, WIND w, double _consume, double _money);
};

REC getdetail(int roomID);
