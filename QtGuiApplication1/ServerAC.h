# pragma execution_character_set("utf-8")
#pragma once
#include "ConfigAC.h"
#include "ClientAC.h"
class ServerAC {
public:
	ServerAC();
	~ServerAC() {};
	ServerAC(ConfigAC cfg);
	bool work;
	MODE mode; 
	double Tcell, Tfloor, Tdefault;
	
	WIND Wdefault;
	double Ecost;
	double Espeed[4];

	QString toString();
	bool filled[4] = { false };
};