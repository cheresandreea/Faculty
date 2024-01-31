#include "Service.h"

Service::Service(){}

Service::Service(Repo& repo)
{
	this->repo = repo;
}

Service::~Service(){}

vector<Bill> Service::getAll()
{
	return this->repo.getAll();
}

void Service::add(Bill b)
//adds a bill in repo
{
	this->repo.add(b);
}