#pragma once
#include "Building.h"
#include <vector>
using namespace std;

class Service
{
private:
	vector<Building*> buildings;
public:
	Service();
	~Service();

	void add(Building* b);

	vector<Building*> getAll() const;
	vector<Building*> getDemolished(int year) const;
	vector<Building*> getRestored() const;
};

