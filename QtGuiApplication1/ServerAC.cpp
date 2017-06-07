# pragma execution_character_set("utf-8")
#include "ServerAC.h"
#include "qdebug.h"
ServerAC::ServerAC() {
	Tcell = TCELL;
	Tfloor = TFLOOR;
	Tdefault = TDEFAULT;
	Wdefault = MEDIUM;
	mode = COOL;
	work = false;
	Ecost = ELECOST;	
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
	work = false;
	Ecost = cfg.Ecost;
	if (Ecost < 0) {
		Ecost = ELECOST;
	}
	int i;
	for (i = 0; i < 4; i++) {
		filled[i] = false;
		Espeed[i] = cfg.Espeed.at(i);
	}
}

QString ServerAC::toString() {
	return (POWER2Qstr(work) + MODE2Qstr(mode) + QString(", ÎÂ¶È·¶Î§") + QString::number(Tcell) +
		QString("¡ãCµ½") + QString::number(Tfloor) + QString("¡ãC, Ä¬ÈÏ") + QString::number(Tdefault) + QString("¡ãC¡£"));
}