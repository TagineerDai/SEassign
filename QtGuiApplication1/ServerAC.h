#pragma once
#include "ClientArray.h"
#include "ConfigAC.h"

class ServerAC {
public:
	ServerAC();
	ServerAC(ConfigAC cfg);
	int work; // AC::ON | OFF
	int mode; // AC::WARM | COOL
	double Tcell, Tfloor, Tdefault;
	double Ecost;
	double Epower[4];
	//ClientArray clients;
};