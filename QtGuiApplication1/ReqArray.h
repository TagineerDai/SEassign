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
	int newReq(Request req);
	void answerReq(int roomID);
	void respondReq(int roomID);//?
};