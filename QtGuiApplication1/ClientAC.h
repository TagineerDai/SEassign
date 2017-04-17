#pragma once
#include "ConfigAC.h"
#include <qhostaddress.h>
#include <qdatetime.h>
#include <sstream>
#include "ServerAC.h"
#include "Request.h"

class ClientAC {
public:
	int roomID;
	AC work;
	CONNECT state;
	MODE mode, Dmode;
	WIND wind, Dwind;
	double consume;
	double cost;
	double Tenv; // environment temperature
	double Ttarget; // User set temper
	double Tcurrent;
	double Tdefault, Tcell, Tfloor; 
	bool autoUpdate = true;
	bool waiting = false;
	Request req;
	QHostAddress addr;
	quint16 port;
	qint64 sec;
	QDateTime time;// 上次调度时间
	ClientAC();
	//When receiving the I<<false
	~ClientAC();
	//When receiving the I << true
	ClientAC(int cid, double _Tinit);

	//ClientAC(int, QHostAddress, quint16);
	QString toString();
	
	//When receive the new mode P
	void updateMode(bool _iscool, double _Tfloor, double _Tcell, double _Tdefault, int _Wdefault);
	
	//When receive the control message O
	//once return true ,send the << G << roomID
	bool updateON(double _cost, double _temp);
	//When receive hang
	void updateDispatch(bool hang);
	//When receive A
	void updateOFF();
};