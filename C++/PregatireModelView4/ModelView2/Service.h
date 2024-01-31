#pragma once
#include "Repository.h"

class Service
{
private:
	Repository& repo;
public:
	//Service() {}
	Service(Repository& r) :repo{ r } {}
	vector<Writer> getWriters() { return repo.getWriters(); }
	vector<Idea> getIdeas() { return repo.getIdeas(); }
	~Service() {}
	int verifDescription(string t);
};

