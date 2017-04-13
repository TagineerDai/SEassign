#include "ClientAC.h"

ClientAC::ClientAC() {
	roomID = 0;
	work = OFF;
	state = OFFC;
	mode = COOL;
	wind = NON;
	consume = 0;
	cost = 0;
	Ttarget = 25;
	Tcurrent = 25;
	addr = QHostAddress::LocalHost;
	port = 0;
	time = QDateTime::currentDateTime();
}

ClientAC::ClientAC(int _roomID) {
	roomID = _roomID;
	work = OFF;
	state = OFFC;
	mode = COOL;
	wind = NON;
	consume = 0;
	cost = 0;
	Ttarget = 25;
	Tcurrent = 25;
	addr = QHostAddress::LocalHost;
	port = 0;
	time = QDateTime::currentDateTime();
}

ClientAC::ClientAC(int _roomID, QHostAddress _addr, quint16 _port) {
	roomID = _roomID;
	work = OFF;
	state = OFFC;
	mode = COOL;
	wind = NON;
	consume = 0;
	cost = 0;
	Ttarget = 25;
	Tcurrent = 25;
	addr = _addr;
	port = _port;
	time = QDateTime::currentDateTime();
}