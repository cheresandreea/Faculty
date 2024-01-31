#pragma once
#include "User.h"
#include "Issue.h"
#include <vector>
using namespace std;

class Repository
{
private:
	vector<User>* users;
	vector<Issue>* issues ;
public:
	Repository();
	~Repository();
	void readUsers();
	void readIssues();
	void addIssue(Issue& i);
	int sizeIssues();
	int sizeUsers();

	vector<User>& getUsers() { return *this->users; }
	vector<Issue>& getIssues() { return *this->issues; }
	int getIssueByDes(string t);
	void removeIssue(int pos);
	void saveToFileIssues();
};

