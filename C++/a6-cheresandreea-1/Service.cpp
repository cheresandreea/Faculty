#include "Service.h"
#include <string.h>

Service::Service(){}

Service::Service(Repo& repo, vector<Dog>& adoptedDogs)
{
	/*this->repo = repo;
	this->adoptedDogs = adoptedDogs;*/
}

Service::~Service(){}

void Service::addDogService(Dog& d)
{
	//adds a dog to the repository
	this->repo.addDogRepo(d);
}

int Service::findDogService(Dog d)
{
	//finds a dog in the repository
	return repo.findDogRepo(d);
}

void Service::deleteDogService(Dog& d)
{
	//delete a dog from the repository
	repo.deleteDogRepo(d);
}

vector<Dog> Service::getAllDogsService()
{
	//get all dogs from the repo
	return repo.getDogsRepo();
}

void Service::updateDogService(Dog& d, int x)
{
	//updates the dogs
	repo.updateDogRepo(d, x);
}

void Service::adoptDogService(Dog& d)
{
	//adds an adopted dog in the service
	this->adoptedDogs.push_back(d);
}


vector<Dog> Service::getAdoptedDogsService()
{
	//returns the array of adopted dogs
	return this->adoptedDogs;
}

int Service:: isEmptyService()
{
	//returns 1 if the array is empty, 0 if it s not empty
	return repo.isEmpty();
}

vector<Dog> Service::filterBreedAgeService(char breed[30], int age)
{
	//filters dogs by breed and age, if there exists no breed of 
	vector<Dog> filteredDogs;

	for(int i = 0; i < this->repo.getDogsRepo().size(); i++)
		if (strcmp(breed, this->repo.getDogsRepo()[i].getBreed()) == 0 && this->repo.getDogsRepo()[i].getAge() < age)
			filteredDogs.push_back(this->repo.getDogsRepo()[i]);

	if(filteredDogs.size() == 0)
		return this->repo.getDogsRepo();
	return filteredDogs;
}