#pragma once
#include "Repository.h"
class Service
{
private:
	Repository& repo;
	string currentUserName;

public:
	//Service();
	Service(Repository& repo);
	~Service();
	void addIssue(Issue& i);
	vector<User> getUsers() { return this->repo.getUsers(); }
	vector<Issue> getIssues() { return this->repo.getIssues(); }
	void readUsers() { this->repo.readUsers(); }
	void readIssues() { this->repo.readIssues(); }
	string getCurrentUserName() const {return this->currentUserName;}
	void setCurrentUserName(string name) { this->currentUserName = name; }
	bool getIssueByDescription(string description);
	int getIssueByDes(string i);
};

