#pragma once
#include "DynamicVector.h"

class Repo
{
private:
	DynamicVector<Dog> dogs;

public:
	//constructor
	Repo();

	//destructor
	~Repo();


	//function such as add, remove, update
	void addDogRepo(Dog& d);
	int findDogRepo(Dog d);
	DynamicVector<Dog> getDogsRepo();
	void deleteDogRepo(Dog& d);
	void updateDogRepo(Dog& d, int x);

	//others
	int isEmpty();
};	
