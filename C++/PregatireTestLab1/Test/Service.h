#pragma once
#include "Repo.h"

class Service
{
private:
	Repo repo;
public:
	Service();
	Service(Repo& repo);
	~Service();
	vector<Car> getAll();
	void add(Car c);
	int rem(Car c);

};
