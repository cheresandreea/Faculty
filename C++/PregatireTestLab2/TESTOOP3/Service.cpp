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

vector<Task> Service::getTasks()
{
	return repo.getTasks();
}

void Service::readFile()
{
	repo.readFile();
}
