#include"Request.h"

Request::Request()
{
	roomID = 0;
	wind = cfg.Wdefault;
	Ttarget = cfg.Tdefault;
	time = QDateTime::currentDateTime();
}
Request::Request(int id)
{
	roomID = id;
	wind = cfg.Wdefault;
	Ttarget = cfg.Tdefault;
	time = QDateTime::currentDateTime();
	handle = false;
}

QString Request::toString()
{
	QString str = QString("Room ") + QString::number(roomID, 10)
		+ QString(" request: ") + QString(" ") + WIND2Qstr(wind)
		+ QString(" to ") + time.toString("yyyy-MM-dd hh:mm:ss");
	return str;
}