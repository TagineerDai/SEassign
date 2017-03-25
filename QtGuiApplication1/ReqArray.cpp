#include "ReqArray.h"
#include "ServerAC.h"
#include "ClientArray.h"

ReqArray::ReqArray()
{
	member->clear();
}

ReqArray::~ReqArray()
{
	delete member;
}

void ReqArray::pushReq(int roomID)
{
	if (getReq(roomID) == nullptr) {
		
	}
}

Request * ReqArray::getReq(int roomID)
{
	return nullptr;
}

int ReqArray::newReq(Request req)
{
	return 0;
}

void ReqArray::answerReq(int roomID)
{
}

void ReqArray::respondReq(int roomID)
{
}


