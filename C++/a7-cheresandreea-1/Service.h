#pragma once
#include "Repo.h"

class Service
{
private:
	RepoFile* repo;
	Repo* repoAdopted;
	
public:
	//constructor
	Service();
	Service(RepoFile* repo, Repo* repoAdopted);

	//destructor
	~Service();

	

	//function such as add, remove, update
	void addDogService(Dog& d);
	int findDogService(Dog d);
	void deleteDogService(Dog& d);
	void updateDogService(Dog& d, int x);
	void adoptDogService(Dog& d);
	vector<Dog>filterBreedAgeService(const string & breed, int age);

	//others
	int Service::isEmptyService();

	//getters
	vector<Dog> getAllDogsService();

	//void saveAdoptedDogsCSVFile();
	//void saveAdoptedDogsHTMLFile();

	void saveAdoptedDogsFile(Repo* repo);

	vector<Dog> getAdoptedDogsService();
	void saveAdoptedDogsToSpecificFile();
	
};