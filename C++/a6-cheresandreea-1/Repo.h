#pragma once
#include "Vector.h"
#include "Dog.h"
#include <vector>

using namespace std;
class Repo
{
private:
	vector<Dog> dogs;

public:
	//constructor
	Repo();

	//destructor
	~Repo();


	//function such as add, remove, update
	void addDogRepo(Dog& d);
	int findDogRepo(Dog d);
	vector<Dog> getDogsRepo();
	void deleteDogRepo(Dog& d);
	void updateDogRepo(Dog& d, int x);

	//others
	int isEmpty();
	vector<Dog> operator[](int i);
};	
