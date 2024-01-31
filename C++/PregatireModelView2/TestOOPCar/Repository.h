#pragma once
#include "Car.h"
#include <vector>
using namespace std;

class Repository
{
private:
	vector <Car> cars;
public:
	Repository();
	~Repository();

	vector<Car> getAll();

};

