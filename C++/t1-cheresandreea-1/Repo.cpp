#include "Repo.h"

Repo::Repo(){}

Repo::~Repo(){}

vector<Bill> Repo::getAll()
{
	return this->v;
}

void Repo::add(Bill b)
//adds a bill in the vector;
{
	this->v.push_back(b);
}