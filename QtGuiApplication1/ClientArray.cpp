#include "ClientArray.h"

void ClientArray::clear() {
	member->clear();
}

ClientAC* ClientArray::getClient(int roomID) {
	std::vector<ClientAC>::iterator ip;
	for (ip = member->begin(); ip != member->end(); ip++) {
		if (roomID == ip->roomID)
			return &(*ip);
	}
	return nullptr;
}

ClientAC* ClientArray::getClient(ClientAC ac) {
	std::vector<ClientAC>::iterator ip;
	for (ip = member->begin(); ip != member->end(); ip++) {
		if (ac.roomID == ip->roomID)
			return &(*ip);
	}
	return nullptr;
}

bool ClientArray::addClient(int roomID, QHostAddress addr, quint16 port) {
	ClientAC* now = getClient(roomID);
	if (now != nullptr) {
		now->state = ONC;
		now->
	}
	return true;
}

