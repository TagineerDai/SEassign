#include "ClientAC.h"
#include "ConfigAC.h"

ClientAC::ClientAC(int ID) {
	roomID = ID;
	state = AC::OFF;
	mode = AC::NON;
	wind = AC::NON;
	cost = 0.0;
}