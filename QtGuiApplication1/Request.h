#pragma once
#include <time.h>
#include <qstring.h>
#include "ConfigAC.h"

extern ConfigAC cfg;

class Request {
public:
	time_t timestamp;
	int roomID;
	int mode, wind;
	float Ttarget;
	Request();
	Request(int roomID);
	Request(int id, int mode, int wind, float Ttarget, time_t timestamp) :
		roomID(id), mode(mode), wind(wind), Ttarget(Ttarget), timestamp(timestamp) {}
	Request(Request& req);
	void setReq(Request req);
	QString toString();
};