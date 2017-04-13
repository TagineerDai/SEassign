#pragma once
#include "ConfigAC.h"
#include <qhostaddress.h>
#include <qdatetime.h>
class ClientAC {
public:
	int roomID;
	AC work;
	CONNECT state;
	MODE mode;
	WIND wind;
	double consume;
	double cost;
	double Ttarget;
	double Tcurrent;
	QHostAddress addr;
	quint16 port;
	QDateTime time;
	ClientAC();
	ClientAC(int);
	ClientAC(int, QHostAddress, quint16);
};