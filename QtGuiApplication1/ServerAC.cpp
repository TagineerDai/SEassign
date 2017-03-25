#include "ServerAC.h"

ServerAC::ServerAC() {
	Tcell = TCELL;
	Tfloor = TFLOOR;
	Tdefault = TDEFAULT;
	mode = AC::COOL;
	work = AC::OFF;
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
	if (cfg.mode == AC::COOL || cfg.mode == AC::WARM)
		mode = cfg.mode;
	else
		mode = AC::COOL;

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