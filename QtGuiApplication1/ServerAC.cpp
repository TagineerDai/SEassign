# pragma execution_character_set("utf-8")
#include "ServerAC.h"
#include "qdebug.h"
ServerAC::ServerAC() {
	Tcell = TCELL;
	Tfloor = TFLOOR;
	Tdefault = TDEFAULT;
	Wdefault = MEDIUM;
	mode = COOL;
	work = OFF;
	Ecost = ELECOST;
	Epower[0] = POWERNON;
	Epower[1] = POWERLOW;
	Epower[2] = POWERMEDIUM;
	Epower[3] = POWERHIGH;
	
}

ServerAC::ServerAC(ConfigAC cfg) {
	Tcell = cfg.Tcell;
	Tfloor = cfg.Tfloor;
	Tdefault = cfg.Tdefault;
	Wdefault = cfg.Wdefault;
	if (cfg.mode == COOL || cfg.mode == WARM)
		mode = cfg.mode;
	else
		mode = COOL;

	work = AC::OFF;
	Ecost = cfg.Ecost;
	if (Ecost < 0) {
		Ecost = ELECOST;
	}

	if (cfg.Epower.size() == 4) {
		int i = 0;
		for (std::vector<double>::iterator ip = cfg.Epower.begin();
			ip != cfg.Epower.end(); ip++) {
			Epower[i] = (*ip);
		}
	}
	else {
		Epower[0] = POWERNON;
		Epower[1] = POWERLOW;
		Epower[2] = POWERMEDIUM;
		Epower[3] = POWERHIGH;
	}
}

void ServerAC::power_off() {
	work = OFF;
	qDebug() << "TODO: serverAC -- power_off()";
}


void ServerAC::power_on() {
	work = ON;
	qDebug() << "TODO: serverAC -- power_on()";
}

QString ServerAC::toString() {
	return (AC2Qstr(work) + MODE2Qstr(mode) + QString(", ÎÂ¶È·¶Î§") + QString::number(Tcell) +
		QString("¡ãCµ½") + QString::number(Tfloor) + QString("¡ãC, Ä¬ÈÏ") + QString::number(Tdefault) + QString("¡ãC¡£"));
}