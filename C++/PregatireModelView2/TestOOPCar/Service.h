#pragma once
#include "Repository.h"
class Service
{
private:
	Repository repo;
public:
	Service();
	Service(Repository& repo);
	~Service();

	vector<Car> getAll();

};

