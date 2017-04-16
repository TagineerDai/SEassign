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
	User::User(QString _usr, QString _pwd);
};

bool varifyRoom(QString usr, QString pwd);

class REC {
public:
	QString ID, Tin, Toff, minute, wind, consume, money;
	REC() {};
	REC(int _ID, string _Tin, string _Toff, double _min, WIND w, double _consume, double _money);
};

REC getdetail(int roomID);
