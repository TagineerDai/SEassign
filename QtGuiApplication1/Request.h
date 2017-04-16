#pragma once
#include <qdatetime.h>
#include <time.h>
#include <qstring.h>
#include "ConfigAC.h"

extern ConfigAC cfg;

class Request {
public:
	QDateTime time;//The newest time
	int roomID;
	WIND wind;
	float Ttarget;
	bool handle;
	Request();
	Request(int roomID);
	QString toString();
};