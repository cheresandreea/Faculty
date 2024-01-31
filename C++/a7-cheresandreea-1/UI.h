#pragma once
#include "Service.h"

class UI
{
private:
	Service service;
public:
	//constructor
	UI();
	UI(Service& service);

	//destructor
	~UI();

	//functions for UI
	void start();
	void menu();
	void openAdmin();
	void openUser();

	//functions for dogs

	void printDog(Dog d);
	void printAllDogs(Service service);
	void addDogUI();
	void deleteDogUI();
	void updateDogUI();
	void seeOnebyOneUI();
	vector<Dog> seeAdoptionList();
	void printAllAdoptedDogs(Service service);
	void printBreedAge();

	/*void UI::testWrite();
	void UI::testRead();*/



};