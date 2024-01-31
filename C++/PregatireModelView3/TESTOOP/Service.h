#pragma once
#include "Repository.h"
#include "Bill.h"

class Service
{
private:
	Repository repo;

public:
	Service();
	Service(Repository& repo);
	~Service();
	vector<Bill> getAll();
};

