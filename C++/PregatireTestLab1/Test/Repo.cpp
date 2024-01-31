#include "Repo.h"
#include <iostream>

Repo::Repo()
{
}

Repo::~Repo()
{
}

vector<Car> Repo::getAll()
{
	return this->cars;
}

void Repo::add(Car c)
{
	this->cars.push_back(c);
}

int Repo::rem(Car c)
{
	for (auto it = this->cars.begin(); it != this->cars.end(); it++)
	{
		if ( it->getModel() == c.getModel() && it->getYear() == c.getYear())
		{
			cars.erase(it);
			return true;
		}
	}
	return false;
}