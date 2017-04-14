#pragma once
#include <qdatetime.h>
#include <time.h>
#include <qstring.h>
#include "ConfigAC.h"

extern ConfigAC cfg;

class Request {
public:
	QDateTime time;
	int roomID;
	MODE mode;
	WIND wind;
	float Ttarget;
	bool handle;
	Request();
	Request(int roomID);

	Request(int id, MODE mode, WIND wind, float Ttarget, QDateTime timestamp) :
		roomID(id), mode(mode), wind(wind), Ttarget(Ttarget), time(timestamp) {}
	
	Request(Request& req);
	void setReq(Request req);
	QString toString();
};