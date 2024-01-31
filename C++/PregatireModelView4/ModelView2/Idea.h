#pragma once
#include <string>
using namespace std;

class Idea
{
private:
	string description;
	string status;
	string creator;
	int act;

public:
	Idea() {}
	Idea(string description, string status, string creator, int act) : description(description), status(status), creator(creator), act(act) {}
	~Idea() {}
	string getDescription() { return description; }
	string getStatus() { return status; }
	string getCreator() { return creator; }
	int getAct() { return act; }
	void setDescription(string description) { description = description; }
	void setStatus(string status) { status = status; }
	void setCreator(string creator) { creator = creator; }
	void setAct(int act) { act = act; }

};

