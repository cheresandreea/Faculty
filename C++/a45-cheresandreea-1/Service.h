#pragma once
#include "Repo.h"

class Service
{
private:
	Repo repo;
	DynamicVector<Dog> adoptedDogs;
public:
	//constructor
	Service();
	Service(Repo& repo, DynamicVector<Dog>& adoptedDogs);

	//destructor
	~Service();

	//function such as add, remove, update
	void addDogService(Dog& d);
	int findDogService(Dog d);
	void deleteDogService(Dog& d);
	void updateDogService(Dog& d, int x);
	void adoptDogService(Dog& d);
	DynamicVector<Dog>getAdoptedDogsService();
	DynamicVector<Dog>filterBreedAgeService(char breed[30], int age);

	//others
	int Service::isEmptyService();

	//getters
	DynamicVector<Dog> getAllDogsService();
};