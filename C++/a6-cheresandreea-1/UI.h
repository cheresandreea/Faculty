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
	int UI::validator(const char* breed, const char* name, const char age, const char* link);

	//functions for dogs
	void startDogs();
	void printDog(Dog d);
	void printAllDogs(Service service);
	void addDogUI();
	void deleteDogUI();
	void updateDogUI();
	void seeOnebyOneUI();
	vector<Dog> seeAdoptionList();
	void printAllAdoptedDogs(Service service);
	void printBreedAge();

};