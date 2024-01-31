#include "UI.h"
#include <cassert>
#include <iostream>

void testAddDogsS()
{
	
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");
	Dog d2 = Dog("c", "d", 1, "e");

	service.addDogService(d1);
	Dog dog = service.getAllDogsService()[0];

	assert(dog == d1);

}

void testDeleteDogS()
{
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");
	Dog d2 = Dog("c", "d", 1, "e");

	service.addDogService(d1);
	service.addDogService(d2);

	service.deleteDogService(d1);
	assert(service.getAllDogsService().size() == 1);
}

void testUpdateDogS()
{
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");
	Dog d2 = Dog("c", "d", 1, "e");

	service.addDogService(d1);
	service.updateDogService(d2, 0);

	assert(service.getAllDogsService()[0] == d2);
}

void testAdoptedS()
{
	vector<Dog> adoptedDogs;
	Repo repo = Repo();
	Service service = Service(repo, adoptedDogs);

	Dog d1 = Dog("a", "b", 1, "c");
	Dog d2 = Dog("c", "d", 1, "e");

	service.adoptDogService(d1);
	service.adoptDogService(d2);

	assert(service.getAdoptedDogsService().size() == 2);

}

void testPhotography()
{
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");

	assert(strcmp(d1.getPhotography(), "c") == 0);

	Dog d2 = Dog("c", "d", 1, "e");

	assert(d1.operator==(d2) == 0);
}

void testisEmptyTrue()
{
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");
	Dog d2 = Dog("c", "d", 1, "e");

	service.addDogService(d1);
	service.addDogService(d2);

	assert(service.isEmptyService() == 0);
}

void testisEmptyFalse()
{
	Service service = Service();
	assert(service.isEmptyService() == 1);
}

void testFindDogTrue()
{
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");

	service.addDogService(d1);

	assert(service.findDogService(d1) == 0);
}

void testFindDogFalse()
{
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");
	Dog d2 = Dog("c", "d", 1, "e");

	service.addDogService(d2);

	assert(service.findDogService(d1) == -1);
}

void testResize()
{
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");
	Dog d2 = Dog("c", "d", 1, "e");
	Dog d3 = Dog("e", "f", 1, "g");
	Dog d4 = Dog("g", "h", 1, "i");

	service.addDogService(d1);
	service.addDogService(d2);
	service.addDogService(d3);
	service.addDogService(d4);

	assert(service.getAllDogsService().size() == 4);
}

void testFilterDogs()
{
	Service service = Service();

	Dog d1 = Dog("a", "b", 1, "c");
	Dog d2 = Dog("c", "d", 1, "e");
	Dog d3 = Dog("e", "f", 1, "g");

	service.addDogService(d1);
	service.addDogService(d2);
	service.addDogService(d3);

	vector<Dog> filteredDogs1 = service.filterBreedAgeService("b", 3);
	assert(filteredDogs1.size() == 3);

	vector<Dog> filteredDogs = service.filterBreedAgeService("a", 2);
	std::cout<<filteredDogs.size();
	assert(filteredDogs.size() == 1);
}

void runTests()
{
	testAddDogsS();
	testDeleteDogS();
	testUpdateDogS();
	testAdoptedS();
	testisEmptyTrue();
	testisEmptyFalse();
	testFindDogTrue();
	testFindDogFalse();
	testPhotography();
	testResize();
	testFilterDogs();
}