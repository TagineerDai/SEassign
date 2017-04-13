#pragma once
#include<vector>
#include "ClientAC.h"

class ClientArray {
public:
	int Cnow, Cmax;
	std::vector<ClientAC> * member;
	ClientArray() {
		Cmax = 4;
		Cnow = 0;
		member = new std::vector<ClientAC>();
	}
	~ClientArray() {
		delete member;
	}
	void clear();
	bool addClient(int roomID, QHostAddress addr, quint16 port);
	ClientAC* getClient(int roomID);
	ClientAC* getClient(ClientAC ac);

};