#pragma once
class ClientAC {
public:
	int roomID;
	int state, mode, wind;
	double cost;
	double Ttarget, Tcurrent;
	ClientAC(int roomID);
};