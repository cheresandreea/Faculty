#pragma once
#include "Dog.h"
#include <vector>

using namespace std;
class Repo
{
protected:
	vector<Dog> dogs;


public:
	//constructor
	Repo();

	//destructor
	~Repo();


	//function such as add, remove, update
	
	virtual void adoptDogRepo(Dog& d) {}

	//others
	int isEmpty();

	//virtual void loadAdoptedDogsFile() = 0;
	virtual void saveAdoptedDogsToSpecificFile() = 0;

	virtual vector<Dog>getAdoptedDogsRepo() {
		return vector<Dog>
			();
	}
};	

class RepoFile : public Repo
{
public:
	RepoFile();
	void loadAdoptedDogsFile();
	void saveAdoptedDogsToSpecificFile() override;
	void saveToFile();

	vector<Dog> getDogsRepo();

	void addDogRepo(Dog& d);
	int findDogRepo(Dog d);
	
	void deleteDogRepo(Dog& d);
	void updateDogRepo(Dog& d, int x);
};


class RepoFileCSV : public Repo
{
private:
	vector<Dog> adoptedDogs;

public:
	RepoFileCSV();
	~RepoFileCSV();
	void saveAdoptedDogsToSpecificFile() override;
	void open(std::string& path);

	void adoptDogRepo(Dog& d);
	vector<Dog>getAdoptedDogsRepo();
};

class RepoFileHTML : public Repo
{
private:
	vector<Dog> adoptedDogs;

public:
	RepoFileHTML();
	~RepoFileHTML();
	void saveAdoptedDogsToSpecificFile() override;
	void open(std::string& path);

	void adoptDogRepo(Dog& d);
	vector<Dog>getAdoptedDogsRepo();
};
