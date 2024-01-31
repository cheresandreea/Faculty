#include "Service.h"

Service::Service()
{
}

Service::Service(Repository& repo)
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
