#include "DataAC.h"
#include "ConfigAC.h"
#include "qdebug.h"
#include <sstream>
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

User::User(QString _usr, QString _pwd) {
	MYSQL db;
	QString qstr;
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
	qstr = QString("select `password` from `room` where roomID = ") + QString::number(roomID, 10);
	qDebug() << qstr;
	int Qdone = mysql_query(&db, qstr.toStdString().c_str());
	if (Qdone == 0) {
		res_ptr = mysql_store_result(&db);
		if (mysql_num_rows(res_ptr) == 1) {
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