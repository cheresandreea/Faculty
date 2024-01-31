#include "Service.h"



Service::Service(Repository& repo):repo(repo)
{
	
}

Service::~Service()
{
}

void Service::addIssue(Issue& i)
{
	this->repo.addIssue(i);
}

bool Service::getIssueByDescription(string description)
{
	for (const Issue& i : repo.getIssues())
		if (i.getDescription() == description)
			return true;
	return false;
}

int Service::getIssueByDes(string i)
{
	return repo.getIssueByDes(i);
}