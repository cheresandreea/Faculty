#pragma once
#include "Repo.h"

class Service
{
private:
	Repo repo;
	vector<Dog> adoptedDogs;
public:
	//constructor
	Service();
	Service(Repo& repo, vector<Dog>& adoptedDogs);

	//destructor
	~Service();

	//function such as add, remove, update
	void addDogService(Dog& d);
	int findDogService(Dog d);
	void deleteDogService(Dog& d);
	void updateDogService(Dog& d, int x);
	void adoptDogService(Dog& d);
	vector<Dog>getAdoptedDogsService();
	vector<Dog>filterBreedAgeService(char breed[30], int age);

	//others
	int Service::isEmptyService();

	//getters
	vector<Dog> getAllDogsService();
};