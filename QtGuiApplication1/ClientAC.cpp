#include "ClientAC.h"

ClientAC::ClientAC() {
	roomID = 0;
	work = OFF;
	state = OFFC;
	waiting = false;
	mode = COOL;
	wind = MEDIUM;
	consume = 0;
	cost = 0;
	Tcurrent = -1;
	Tcell = 32;
	Tfloor = 14;
	Tdefault = 25;
	Ttarget = Tdefault;
}
//When receiving the I<<false
ClientAC::~ClientAC() {};
//When receiving the I << true
ClientAC::ClientAC(int cid, double _Tinit) {
	roomID = cid;
	Tenv = Tcurrent = _Tinit;
	work = OFF;
}

//ClientAC(int, QHostAddress, quint16);
QString ClientAC::toString() {
	char* str, *Tf1, *Tf2;
	sprintf(str, "Room %d ", roomID);
	sprintf(Tf1, " Tnow %.2f¡ãC", Tcurrent);
	sprintf(Tf2, " Target %.2f¡ãC", Ttarget);
	return (QString::fromStdString(str) + AC2Qstr(work) + QString(" ") + MODE2Qstr(mode)
		+ QString(" ") + WIND2Qstr(wind) + QString::fromStdString(Tf1) + QString::fromStdString(Tf2));
}

//When receive the new mode P
void ClientAC::updateMode(bool _iscool, double _Tfloor, double _Tcell, double _Tdefault, int _Wdefault) {
	if (_iscool)
		mode = COOL;
	else
		mode = WARM;
	Tdefault = _Tdefault;
	Tcell = _Tcell;
	Tfloor = _Tfloor;
	Dwind = (WIND)_Wdefault;
}

//When receive the control message O
//once return true ,send the << G << roomID
bool ClientAC::updateON(double _cost, double _temp) {
	if (work == ON && waiting == false) {
		cost = _cost;
		Tcurrent = _temp;
		if (abs(Tcurrent - Ttarget)>1 && waiting == false) {
			waiting = true;
			return true;
		}
	}
	return false;
}
//When receive hang
void ClientAC::updateDispatch(bool hang) {
	if (hang) {//¹ÒÆð
		if (waiting = false && work == ON) {
			sec += QDateTime::currentDateTime().secsTo(time);
		}
	}
	else {//µ÷¶È
		Ttarget = req.Ttarget;
		wind = req.wind;
		req.handle = true;
		waiting = false;
		time = QDateTime::currentDateTime();
	}
}
//When receive A
void ClientAC::updateOFF() {
	if (work == ON) {
		req.handle = false;
		waiting = true;
	}
	else {
		waiting = false;
		req.handle = false;
	}
};