#include "Tests.h"
#include <vector>
#include <cassert>
#include "Service.h"
#include <iostream>

using namespace std;

void addCar()
{
	Repo repo;
	Service service = Service(repo);

	Car car1 = Car("Fiat", "Bravo", 2007, "red");
	service.add(car1);
	std::cout << service.getAll().size();
	assert(service.getAll().size() == 1);
}

void runAll()
{
	addCar();
}