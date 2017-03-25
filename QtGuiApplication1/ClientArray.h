#pragma once
#include<vector>
#include "ClientAC.h"

class ClientArray {
public:
	std::vector<ClientAC> member;
	void clear();
	ClientAC* getClient(int roomID);
};