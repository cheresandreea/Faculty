#pragma once
#include "Car.h"
#include <vector>
using namespace std;

class Repo
{
private:
	vector<Car> cars;
public:
	Repo();
	~Repo();
	vector<Car> getAll();
	void add(Car c);
	int rem(Car c);
};