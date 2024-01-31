#include "Service.h"
#include "House.h"
#include "Block.h"

Service::Service()
{
}

Service::~Service()
{
}

void Service::add(Building* b)
{
	this->buildings.push_back(b);
}

vector<Building*> Service::getAll() const
{
	return this->buildings;
}

vector<Building*> Service::getDemolished(int year) const
{
	vector<Building*> b;
	for (auto* x : buildings)
	{
		if (x->getYear() < year && x->canBeDemolished())
		{
			if (dynamic_cast<House*>(x) != nullptr)
				b.push_back(x);
			else
				if (dynamic_cast<Block*>(x) != nullptr)
					b.push_back(x);
		}
	}
	return b;
}

vector<Building*> Service::getRestored() const
{
	vector<Building*> buildings;
	for (auto* x : buildings)
	{
		if (x->mustBeRestored() == true)
		{
			if (dynamic_cast<House*>(x) != nullptr)
				buildings.push_back(x);
			else
				if (dynamic_cast<Block*>(x) != nullptr)
					buildings.push_back(x);
		}
	}
	return buildings;
}