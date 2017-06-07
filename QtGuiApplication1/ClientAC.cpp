#include "ClientAC.h"
#include "ConfigAC.h"
extern ConfigAC cfg;
//for nothing
ClientAC::ClientAC() {
	roomID = 0;
	Tcell = cfg.Tcell;
	Tfloor = cfg.Tfloor;
	Tdefault = cfg.Tdefault;
	Tenv = -1; //To show that it wasn't init;
	Ttarget = Tdefault;
	Tcurrent = -1; // To show that it wasn't accepted by S_I;
	mode = COOL;
	wind = NON;
	cost = 0;
	elec = 0;

	power = false;
	run = false;
	req = false;
	secs = 0;
	reclist.clear();

	/*	
	waiting = false;
	consume = 0;
	addr = r_addr;
	port= r_port;
	*/
}

//for nothing
ClientAC::~ClientAC() {};

//Init in the clientWindow
ClientAC::ClientAC(int _cid, double _Tinit) {
	roomID = _cid;
	Tenv = _Tinit;
	Tcurrent = -1;
	mode = COOL;

	wind = NON;
	Tcell = cfg.Tcell;
	Tfloor = cfg.Tfloor;
	Tdefault = cfg.Tdefault;

	run = false;
	power = false;
	req = false;
	cost = 0;
	elec = 0;
	secs = 0;
	reclist.clear();

	/*
	work = OFF;
	*/
}


//When received S_I true
void ClientAC::room_in_accepted() {
	this->time_in = QTime::currentTime();
	this->Tcurrent = Tenv;
}

//When sending C_B
void ClientAC::power_on() {
	this->power = true;
	this->run = false;
	this->req = false;
	this->Ttarget = -1;
	this->time_in = QTime::currentTime();
}

//When sending C_B
void ClientAC::power_off() {
	this->power = false;
	this->run = false;
	this->req = false;
	this->Ttarget = -1;
}

void ClientAC::add_a_rec() {
	//int sec =(int)( QTime::currentTime().msecsTo(this->last_on) / 1000);
	//if (sec == 0) return;

	int elapsed = this->last_on.msecsTo(QTime::currentTime()) / 1000;
	if (elapsed == 0) return;
	this->reclist.push_back(rec(int(this->wind), this->last_on, QTime::currentTime()));
	this->secs += elapsed;

}

void ClientAC::start_a_rec() {
	this->last_on = QTime::currentTime();
}

//When received S_P true, return if should send a new target temperature
//TODO in Client: if return true send a new target message
//TODO in Server: ignore the received message
//the Wind init have been down without any other message
bool ClientAC::work_mode_received(MODE mode, int Tfloor, int Tcell, int Tdefault, WIND windtemp) {
	//S_P()
	bool newmessage = false;
	this->mode = mode;
	this->Tfloor = Tfloor;
	this->Tcell = Tcell;
	if (this->Ttarget == -1)
		newmessage = true;
	this->Tdefault = Tdefault;
	this->wind = windtemp;
	return newmessage;
}

//send message no matter what the value is
void ClientAC::set_temp_target(int Ttarget) {
	this->Ttarget = Ttarget;
	if (this->power) {
		if (this->mode == COOL && this->Ttarget < this->Tcurrent ||
			this->mode == WARM && this->Ttarget > this->Tcurrent)//有效请求
			this->req = true;  //req +
		else
			this->req = false; //req -
	}
}

//send message no matter what the value is
void ClientAC::set_wind(WIND wind) {
	this->wind = wind;
	if (this->power) 
		this->req = true; // req +
}

double ClientAC::get_serv_time() {
	double serv_time = this->secs;
	double lastone = QTime::currentTime().msecsTo(this->last_on) / 1000;
	serv_time += lastone;
	return serv_time;
}

/*
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
	if (hang) {//挂起
		if (waiting = false && work == ON) {
			sec += QDateTime::currentDateTime().secsTo(time);
		}
	}
	else {//调度
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

QString ClientAC::toString() {
	char* str, *Tf1, *Tf2;
	sprintf(str, "Room %d ", roomID);
	sprintf(Tf1, " Tnow %.2f°C", Tcurrent);
	sprintf(Tf2, " Target %.2f°C", Ttarget);
	return (QString::fromStdString(str) + AC2Qstr(work) + QString(" ") + MODE2Qstr(mode)
		+ QString(" ") + WIND2Qstr(wind) + QString::fromStdString(Tf1) + QString::fromStdString(Tf2));
}
*/