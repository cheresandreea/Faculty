#pragma once
#include <string>
using namespace std;

class Issue
{
private:
	string description;
	string status;
	string reporter;
	string solver;
public:
	Issue();
	Issue(string description, string status, string reporter, string solver) :description{ description }, status{ status }, reporter{ reporter }, solver{ solver }{}
	~Issue();
	string getDescription() const{ return this->description; }
	string getStatus() const{ return this->status; }
	string getReporter() const{ return this->reporter; }
	string getSolver() const{ return this->solver; }
	void setSolver(string s) { this->solver = s; }
	void setStatus(string s) { this->status = s; }

};

