#include "Request.h"
Request::Request()
{
	roomID = 0;
	mode = AC::COOL;
	wind = AC::NON;
	Ttarget = cfg.Tdefault;
	timestamp = time((time_t*)NULL);
}
Request::Request(int id)
{
	roomID = id;
	mode = AC::COOL;
	wind = AC::NON;
	Ttarget = cfg.Tdefault;
	timestamp = time((time_t*)NULL);
}

Request::Request(Request& req)
{
	roomID = req.roomID;
	mode = req.mode;
	wind = req.wind;
	Ttarget = req.Ttarget;
	timestamp = req.timestamp;
}

void Request::setReq(Request req)
{
	roomID = req.roomID;
	mode = req.mode;
	wind = req.wind;
	Ttarget = req.Ttarget;
	timestamp = req.timestamp;
}

QString Request::toString()
{
	QString str = "Room " + QString::number(roomID, 10)
		+ " request: " + Enum2QStr(mode) 
		+ " " + Enum2QStr(wind)
		+ " to " + QString::number(Ttarget);
	return str;
}


