#pragma once
#include "Task.h"
#include <vector>
using namespace std;

class Repository
{
private:
	vector<Task> tasks;
public:
	Repository();
	~Repository();
	void readFile();
	vector<Task> getTasks();
};

