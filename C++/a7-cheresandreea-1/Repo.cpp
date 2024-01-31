#include "Repo.h"
#include <iostream>

Repo::Repo(){}

Repo::~Repo(){}

int RepoFile::findDogRepo(Dog d)
{
	//finds a dog in repo
	for (int i = 0; i < dogs.size(); i++)
	{
		if (dogs[i] == d)
			return i;
	}
	return -1;
}

void RepoFile::addDogRepo(Dog& d)
{
	//adds a dog in repo
	this->dogs.push_back(d);
	saveToFile();
}

vector<Dog> RepoFile::getDogsRepo()
{
	//returns all the dogs
	return this->dogs;
}

void RepoFile::deleteDogRepo(Dog& d)
{
	//deletes a dog from repo
	int i = this->findDogRepo(d);
	this->dogs.erase(this->dogs.begin() + i);
	saveToFile();
}

void RepoFile::updateDogRepo(Dog& d, int x)
{
	//updates a dog from the repo
	this->dogs[x] = d;
	saveToFile();
}

int Repo::isEmpty()
{
	//if its empty it returns 1 and if not it returns 0
	if (this->dogs.size() == 0)
		return 1;
	return 0;
}


void RepoFile::saveAdoptedDogsToSpecificFile()
{

}

