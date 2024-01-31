#pragma once
#include "Repository.h"
#include "Task.h"

class Service
{
private:
	Repository repo;
public:
	Service();
	Service(Repository& repo);
	~Service();
	vector<Task> getTasks();
	void readFile();

};

