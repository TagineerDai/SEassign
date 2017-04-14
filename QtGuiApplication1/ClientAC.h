#pragma once
#include "ConfigAC.h"
#include <qhostaddress.h>
#include <qdatetime.h>
class ClientAC {
public:
	int roomID;
	AC work;
	CONNECT state;
	MODE mode, Dmode;
	WIND wind;
	double consume;
	double cost;
	double Tenv; // environment temperature
	double Ttarget; // User set temper
	double Tcurrent;
	QHostAddress addr;
	quint16 port;
	long sec;
	QDateTime time;
	ClientAC();
	ClientAC(int);
	ClientAC(int, QHostAddress, quint16);
};