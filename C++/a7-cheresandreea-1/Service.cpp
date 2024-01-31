#include "Service.h"
#include <string.h>
#include <fstream>
#include <iostream>


using namespace std;

Service::Service():repo(nullptr) {}

Service::Service(RepoFile* repo, Repo* repoAdopted)
{
	this->repo = repo;
	this->repoAdopted = repoAdopted;
}

Service::~Service(){}

void Service::saveAdoptedDogsFile(Repo* repo)
{
	//repo->saveAdoptedDogsFile();
}

using namespace std;


vector<Dog> Service::getAdoptedDogsService()
{
	return repoAdopted->getAdoptedDogsRepo();
}

void Service::addDogService(Dog& d)
{
	//adds a dog to the repository
	this->repo->addDogRepo(d);
}

int Service::findDogService(Dog d)
{
	//finds a dog in the repository
	return repo->findDogRepo(d);
}

void Service::deleteDogService(Dog& d)
{
	//delete a dog from the repository
	repo->deleteDogRepo(d);
}

vector<Dog> Service::getAllDogsService()
{
	//get all dogs from the repo
	return repo->getDogsRepo();
}

void Service::updateDogService(Dog& d, int x)
{
	//updates the dogs
	repo->updateDogRepo(d, x);
}

void Service::adoptDogService(Dog& d)
{
	//adds an adopted dog in the service
	repoAdopted->adoptDogRepo(d);
}


int Service:: isEmptyService()
{
	//returns 1 if the array is empty, 0 if it s not empty
	return repo->isEmpty();
}

vector<Dog> Service::filterBreedAgeService(const string &breed, int age)
{
	//filters dogs by breed and age, if there exists no breed of 
	vector<Dog> filteredDogs;

	for(int i = 0; i < this->repo->getDogsRepo().size(); i++)
		if (breed == this->repo->getDogsRepo()[i].getBreed()  && this->repo->getDogsRepo()[i].getAge() < age)
			filteredDogs.push_back(this->repo->getDogsRepo()[i]);

	if(filteredDogs.size() == 0)
		return this->repo->getDogsRepo();
	return filteredDogs;
}


void Service::saveAdoptedDogsToSpecificFile()
{
	repoAdopted->saveAdoptedDogsToSpecificFile();
}
