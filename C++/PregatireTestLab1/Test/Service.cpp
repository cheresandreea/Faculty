#include "Service.h"

Service::Service()
{
}

Service::Service(Repo& repo)
{
	this->repo = repo;
}

Service::~Service()
{
}

vector<Car> Service::getAll()
{
	return repo.getAll();
}

void Service::add(Car c)
{
	repo.add(c);
}

int Service::rem(Car c)
{
	return repo.rem(c);
}