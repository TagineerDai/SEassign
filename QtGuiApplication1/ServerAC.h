# pragma execution_character_set("utf-8")
#pragma once
#include "ConfigAC.h"

class ServerAC {
public:
	ServerAC();
	ServerAC(ConfigAC cfg);
	AC work; // ON | OFF
	MODE mode; 
	WIND Wdefault;
	double Tcell, Tfloor, Tdefault;
	double Ecost;
	double Epower[4];
	void power_off();
	void power_on();
	QString toString();
	bool filled[5] = { false };
};