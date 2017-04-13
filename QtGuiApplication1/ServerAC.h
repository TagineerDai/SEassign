#pragma once
#include "ClientArray.h"
#include "ConfigAC.h"

class ServerAC {
public:
	ServerAC();
	ServerAC(ConfigAC cfg);
	AC work; // ON | OFF
	MODE mode; 
	double Tcell, Tfloor, Tdefault;
	double Ecost;
	double Epower[4];
	//ClientArray clients;
};