#include "DataAC.h"
#include "ConfigAC.h"
#include "qdebug.h"

bool getDB(MYSQL *db) {
	mysql_init(db);
	MySQLSetting dbc = MySQLSetting();
	if (mysql_real_connect(db, dbc.host, dbc.user, dbc.pswd, dbc.table, dbc.port, NULL, 0))
		return true;
	else return false;
}

void closeDB(MYSQL *db) {
	mysql_close(db);
	return;
}

bool initDB() {
	MYSQL db;
	MySQLSetting dbc = MySQLSetting();
	mysql_init(&db);
	if (mysql_real_connect(&db, dbc.host, dbc.user, dbc.pswd, dbc.table, dbc.port, NULL, 0))
	{
		mysql_query(&db, "CREATE DATABASE  IF NOT EXISTS `dac`");
		mysql_query(&db, "USE `DAC`");
		mysql_query(&db, "DROP TABLE IF EXISTS `room`");
		mysql_query(&db, "DROP TABLE IF EXISTS `record`");
		mysql_query(&db, "create table room("
			"`roomID` int primary key,"
			"`password` varchar(20) default 'SE2017')");
		mysql_query(&db, "insert into `room`(`roomID`,`password`)"
			"values('1', ''), ('2', ''), ('3', ''), ('4', '')");
		mysql_query(&db, "create table account("
			"`account` varchar(20) PRIMARY KEY NOT NULL,"
			"`roomID` int,"
			"`password` varchar(20) DEFAULT 'SE2017')");

		mysql_query(&db, "create table record("
			"`ID` int primary key , "
			"`roomID` int, "
			"`Tstart` datetime, "
			"`Tend` datetime, "
			"`minute` double default 0,"
			"`wind` int default 2, "
			"`consume` double default 0, "
			"`cost` double default 0)");
		mysql_close(&db);
		return true;
	}
	return false;
}

bool varifyAdmin(QString usr, QString pwd) {
	Admin admin = Admin(usr, pwd);
	return admin.varified;
}

bool varifyRoom(QString usr, QString pwd) {
	User room = User(usr, pwd);
	return room.varified;
};

Admin::Admin(QString usr, QString pwd) {
	qDebug() << usr;
	qDebug() << pwd;
	int v1 = QString::compare(QString("admin"), usr);
	int v2 = QString::compare(QString("SE2017"), pwd);
	if (v1 == 0 && v2 == 0)
		varified = true;
	else return;
	return;
}


REC getdetail(int roomID) {
	//MYSQL db = getDB();
	//mysql_query(&db, "");
	REC b = REC();
	return b;
}

REC::REC(int _ID, string _Tin, string _Toff, double _min, WIND w, double _consume, double _money) {
	ID = QString(_ID);
	Tin = QString::fromStdString(_Tin);
	Toff = QString::fromStdString(_Toff);
	wind = WIND2Qstr(w);
	minute = QString::number(_min, 'f', 2);
	consume = QString::number(_consume, 'f', 4);
	money = QString::number(_money, 'f', 2);
	return;
}