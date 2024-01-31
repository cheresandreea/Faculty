#include "Service.h"

Service::Service()
{
}

Service::Service(Repository& repo)
{
	repo = repo;
}

Service::~Service()
{
}

vector<Bill> Service::getAll()
{
	return repo.getAll();
}
