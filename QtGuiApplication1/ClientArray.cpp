#include "ClientArray.h"

void ClientArray::clear() {
	member.clear();
}

ClientAC* ClientArray::getClient(int roomID) {
	std::vector<ClientAC>::iterator ip;
	for (ip = member.begin(); ip != member.end(); ip++) {
		if (roomID == ip->roomID)
			return &(*ip);
	}
}