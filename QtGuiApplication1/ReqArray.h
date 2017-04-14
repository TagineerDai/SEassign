#pragma once
#include "Request.h"
#include <vector>
class ReqArray {
public:
	std::vector<Request> *member;
	ReqArray();
	~ReqArray();
	void pushReq(int roomID);
	Request* getReq(int roomID);
	int updateReq(Request req);
	void answerReq(int roomID);
	void respondReq(int roomID);//?
};


class RequestList
{
public:
	void updateRequest(Request newRequest);
	void setRequestDealt(int roomNum);
	void dealRequests();
	Request* findNextAvailableRequest();
	void setAllRequestDealt();
};