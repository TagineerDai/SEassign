#pragma once
#include <vector>
#include "ConfigAC.h"
#include <qhostaddress.h>
#include <qdatetime.h>
#include <sstream>
#include "ServerAC.h"
#include "Request.h"
#include "qdatetime.h"

extern QHostAddress r_addr;
extern quint16 r_port;
extern ConfigAC cfg;
using namespace std;

class rec {
public:
	int wind;
	QTime start;
	QTime end;
	double cost;
	double elec;
	rec(int wind, QTime start, QTime end) {
		this->wind = wind;
		this->start = start;
		this->end = end;
		int elapsed = start.msecsTo(end)/1000;
		this->elec = (double)elapsed * cfg.Espeed.at(wind);
		this->cost = this->elec * 1.0;
	}
};

class ClientAC {
public:
	int roomID;
	double Tdefault, Tcell, Tfloor;
	double Tenv, Ttarget, Tcurrent;
	MODE mode;
	WIND wind;
	double elec;
	double cost;
	bool power; // on/off
	bool run; //working, not working;
	bool req; //there is a req

	// only for server
	long secs; //total serve_time
	QTime last_on; //The last run/dispatch time
	QTime time_in; //the registed time
	vector<rec> reclist;

	/*
	AC work;
	bool autoUpdate = true;
	bool waiting = false;
	Request req;
	QHostAddress addr;
	quint16 port;
	qint64 sec;
	QDateTime time;// 上次调度时间
	*/

	ClientAC();
	//When receiving the I<<false
	~ClientAC();
	//When receiving the I << true
	ClientAC(int cid, double _Tinit);

	void room_in_accepted();
	bool work_mode_received(MODE mode, int Tfloor, int Tcell, int Tdefault, WIND windtemp);
	void set_temp_target(int Ttarget);
	void set_wind(WIND wind);
	void power_on();
	void power_off();
	//only for server count
	void add_a_rec();
	void start_a_rec();
	double get_serv_time();

	/*
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
	*/
};