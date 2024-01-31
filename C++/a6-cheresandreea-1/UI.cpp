#include "UI.h"
#include <iostream>
#include <exception>
#include <string>

UI::UI(){}//constructor

UI::UI(Service& service)
{
	//constructor
	this->service = service;
}

UI::~UI(){}

void UI::startDogs()
{
	//put dogs in the start
	Dog a = Dog("ShihTzu", "Cris", 2, "link1");
	Dog b = Dog("Poodle", "Mera", 1, "link2");
	Dog c = Dog("Bulldog", "Rex", 3, "link3");
	Dog d = Dog("Pitbull", "Nero", 5, "link4");
	Dog e = Dog("Chiuaua", "Miki", 4, "link5");
	Dog f = Dog("Pug", "Limo", 2, "link6");
	Dog g = Dog("Poodle", "Terra", 1, "link7");
	Dog h = Dog("Bulldog", "Caro", 3, "link8");
	Dog i = Dog("Chowchow", "Momo", 5, "link9");
	Dog j = Dog("Pitbull", "Luna", 4, "link10");

	service.addDogService(a);
	service.addDogService(b);
	service.addDogService(c);
	service.addDogService(d);
	service.addDogService(e);
	service.addDogService(f);
	service.addDogService(g);
	service.addDogService(h);
	service.addDogService(i);
	service.addDogService(j);

}

int UI::validator(const char* breed, const char* name, const char age, const char* link)
{
	//validator for dogs
	if (strlen(breed) == 0)
		return false;
	if(strlen(name) == 0)
		return false;
	if (age < '1' || age > '9')
		return false;
	
	if(strlen(link) == 0)
		return false;
	return true;
}

void UI::printDog(Dog d)
{
	//prints a dog
	std::cout << d.getBreed() << " ";
	std::cout << d.getName() << " ";
	std::cout << d.getAge() << " ";
	std::cout << d.getPhotography() << std::endl;
}

void UI::printAllDogs(Service service)
{
	//prints all dogs
	
	vector<Dog> d = service.getAllDogsService();
	for (vector <Dog>::iterator it = d.begin(); it != d.end(); it++)
	{
		printDog(*it);
	}
	
}

void UI::addDogUI()
{
	//add a dog to array
	std::cout << "Give the breed of the dog: ";
	char breed[30];
	std::cin >> breed;

	std::cout << "Give the name of the dog: ";
	char name[30];
	std::cin >> name;

	std::cout << "Give the age of the dog: ";
	char age;
	std::cin >> age;

	std::cout << "Give the link of the photo: ";
	char link[30];
	std::cin >> link;
	

	try {
		if (this->validator(breed, name, age, link) == false)
			throw std::exception("Invalid data");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return;
	}

	
	try {
		Dog d = Dog(breed, name, age-'0', link);
		if (service.findDogService(d) != -1)
			throw std::exception("Dog already exists");
		else
			service.addDogService(d);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
}

void UI::deleteDogUI()
{
	//deletes a dog from the array
	std::cout << "Give the breed of the dog: ";
	char breed[30];
	std::cin >> breed;

	std::cout << "Give the name of the dog: ";
	char name[30];
	std::cin >> name;

	std::cout << "Give the age of the dog: ";
	int age;
	std::cin >> age;

	char photograph[30] = "link";

	try {
		Dog d = Dog(breed, name, age, photograph);
		if (service.findDogService(d) == -1)
			throw std::exception("Dog does not exist");
		else
		{
			service.deleteDogService(d);
			std::cout << "Dog deleted" << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void UI::updateDogUI()
{
	//updates a dog
	std::cout << "Give the breed of the dog: ";
	char breed[30];
	std::cin >> breed;

	std::cout << "Give the name of the dog: ";
	char name[30];
	std::cin >> name;

	std::cout << "Give the age of the dog: ";
	int age;
	std::cin >> age;

	char photograph[30] = "link";
	


	try {
		Dog a = Dog(breed, name, age, photograph);
		int x = service.findDogService(a);
		if (x == -1)
			throw std::exception("Dog does not exist");
		else
		{
			std::cout << "Give the new breed: ";
			char newBreed[30];
			std::cin >> newBreed;

			std::cout << "Give the new name: ";
			char newName[30];
			std::cin >> newName;

			std::cout << "Give the new age: ";
			char newAge;
			std::cin >> newAge;

			std::cout << "Give the new link: ";
			char newLink[30];
			std::cin >> newLink;

			try {
				if (this->validator(newBreed, newName, newAge, newLink) == false)
					throw std::exception("Invalid data");
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
				return;
			}
			Dog d = Dog(newBreed, newName, newAge, newLink);
			service.updateDogService(d, x);
			std::cout << "Dog updated!" << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void UI::openAdmin()
{
	//menu
	int op;
	
	while (true)
	{
		std::cout << "1. Add a dog: " << std::endl;
		std::cout << "2. Delete a dog: " << std::endl;
		std::cout << "3. Update a dog: " << std::endl;
		std::cout << "4. See all dogs: " << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cin >> op;
		switch (op)
		{
		case 1:
			addDogUI();
			break;
		case 2:
			deleteDogUI();
			break;
		case 3:
			updateDogUI();
			break;
		case 4:
			printAllDogs(service);
			break;
		case 5:
			return;
		}
	}

}

void UI::seeOnebyOneUI()
{
	//prints dogs dog by dog
	vector<Dog> d = service.getAllDogsService();

	for (int i = 0; i < d.size(); i++)
	{
	
		printDog(d[i]);
		std::cout << "Write A for adopt and S for skip to the next dog" << std::endl;
		char op;
		std::cin >> op;
		if (op == 'A')
		{
			service.adoptDogService(d[i]);
			service.deleteDogService(d[i]);
			std::cout << "Dog adopted" << std::endl;
		}
		if (i == d.size() - 1)
		{
			std::cout << "If you want to see the dogs again press S, if you want to exit press E" << std::endl;
			char op;
			std::cin >> op;
			if (op == 'S')
				i = 0;
			else
				return;

		}
	}
}

vector<Dog> UI::seeAdoptionList()
{
	//returns the adoption list
	return service.getAdoptedDogsService();
}

void UI::printAllAdoptedDogs(Service service)
{
	//prints all adopted list
	vector<Dog> d = seeAdoptionList();
	for (int i = 0; i < d.size(); i++)
		printDog(d[i]);
}

void UI::printBreedAge()
{
	//filters by breed and age
	std::cout<<"Give the breed: ";
	char breed[30];
	std::cin>>breed;
	std::cout<<"Give the age: ";
	int age;
	std::cin>>age;

	vector<Dog> d = service.filterBreedAgeService(breed, age);
	for (int i = 0; i < d.size(); i++)
		printDog(d[i]);
}

void UI::openUser()
{
	//user menu
	int op;
	while (true)
	{
		std::cout << "1. See all dogs one by one: " << std::endl;
		std::cout << "2. See all dogs in the adoption list: " << std::endl;
		std::cout << "3. See all dogs of a given breed having an age less than a given number: " << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cin>>op;
		switch (op)
		{
		case 1:
			//see all dogs one by one
			if (service.isEmptyService())
			{
				std::cout << "No more dogs to see" << std::endl;
				break;
			}
			seeOnebyOneUI();
			break;
		case 2:
			//see all dogs in the adoption list
			printAllAdoptedDogs(service);
			break;
		case 3:
			//see all dogs of a given breed having an age less than a given number
			printBreedAge();
			break;
		case 4:
			return;
		}


	}
}

void UI::menu()
{
	//start menu
	std::cout << "1. Administrator mode" << std::endl;
	std::cout << "2. User mode" << std::endl;
	std::cout << "3. Exit" << std::endl;

}

void UI::start()
{
	//starts UI
	int op;
	
	startDogs();
	
	while (true)
	{
		menu();
		std::cin >> op;
		switch (op)
		{
		case 1:
			//administrator mode
			openAdmin();
			
			break;
		case 2:
			//user mode
			openUser();
			
			break;
		case 3:
			exit(0);
			break;
		}
		
	}

}