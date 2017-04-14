#include "Request.h"
#include "ConfigAC.h"
Request::Request()
{
	roomID = 0;
	mode = COOL;
	wind = NON;
	Ttarget = cfg.Tdefault;
	time = QDateTime::currentDateTime();
}
Request::Request(int id)
{
	roomID = id;
	mode = COOL;
	wind = NON;
	Ttarget = cfg.Tdefault;
	time = QDateTime::currentDateTime();
}

Request::Request(Request& req)
{
	roomID = req.roomID;
	mode = req.mode;
	wind = req.wind;
	Ttarget = req.Ttarget;
	time = req.time;
}

void Request::setReq(Request req)
{
	roomID = req.roomID;
	mode = req.mode;
	wind = req.wind;
	Ttarget = req.Ttarget;
	time = req.time;
}

QString Request::toString()
{
	QString str = QString("Room ") + QString::number(roomID, 10)
		+ QString(" request: ") + MODE2Qstr(mode) 
		+ QString(" ") + WIND2Qstr(wind)
		+ QString(" to ") + time.toString("yyyy-MM-dd hh:mm:ss");
	return str;
}


