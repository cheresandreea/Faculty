#include "UI.h"
#include <iostream>
#include <algorithm> 

UI::UI()
{
}

UI::UI(Service& service)
{
	this->service = service;
}

UI::~UI()
{
}

void UI::add()
{
	std::cout << "Give the name of the car: ";
	char name[30];
	std::cin >> name;

	std::cout << "Give the model of the car: ";
	char model[30];
	std::cin >> model;

	std::cout << "Give the year of the car: ";
	int year;
	std::cin >> year;

	std::cout << "Give the color of the car: ";
	char color[30];
	std::cin >> color;

	Car car1 = Car(name, model, year, color);
	vector<Car> v = service.getAll();
	int ok = 1;

	for (Car c : v)
	{
		if (c.getModel() == car1.getModel() && c.getYear() == car1.getYear())
			ok = 0;
		
	}
	if (ok == 1)
	{
		service.add(car1);
		std::cout << "Succesfully added!";
		return;
	}
	else
		std::cout << "Invalid car!";

	
}
void UI::showCar(Car c)
{
	std::cout << c.getName() << " | ";
	std::cout << c.getModel() << " | ";
	std::cout << c.getYear() << " | ";
	std::cout << c.getColor() << endl;
}
void UI::showAll()
{
	vector<Car> v = service.getAll();

	sort(v.begin(), v.end(), [](const Car& a, const Car& b) 
		{
			return a.getName() < b.getName();
		});

	sort(v.begin(), v.end(), [](const Car& a, const Car& b)
		{
			if (a.getName() == b.getName())
				return a.getModel()< b.getModel();

		});

	/*sort(v.begin(), v.end(), [](const Car& a,const Car& b)
	{
			if (a.getName() == b.getName())
				if (a.getModel() < b.getModel())
					return true;
				else 
					return false;

	});*/
	for (Car c : v)
		showCar(c);
	
}

void UI::showCar2()
{
	vector<Car> v = service.getAll();
	vector<Car> nou;
	for (const Car& c : v)
	{
		if (c.getYear() + 45 < 2023)
			nou.push_back(c);
	}
	sort(nou.begin(), nou.end(), [](const Car& a, const Car& b)
	{
		return a.getColor() < b.getColor();
	});

	for (const Car& c : nou)
	{
		showCar(c);
	}
}

void UI::rem()
{
	std::cout << "Give the model of the car: ";
	char model[30];
	std::cin >> model;

	std::cout << "Give the year of the car: ";
	int year;
	std::cin >> year;

	Car c = Car("", model, year, "");

	if (service.rem(c) == true)
	{
		std::cout << "Succesfully removed!";
	}
	else
		std::cout << "Invalid car!";


}
void UI::menu()
{
	std::cout << "1. Add a new car" << endl;
	std::cout << "2. Remove a car " << endl;
	std::cout << "3. Show all cars, with all their information sorted by manufacturer and model" << endl;
	std::cout << "4. Show all vintage cars: those having a fabrication year older than 45 years, sorted by colour" << endl;
}

void UI::addCars()
{
	Car c1 = Car("Fiat", "Idea", 2007, "red");
	Car c2 = Car("Fiat", "Bravo", 2003, "black");
	Car c3 = Car("Audi", "A5", 2007, "blue");
	Car c4 = Car("BMW", "I3", 2001, "grey");
	Car c5 = Car("Skoda", "Fabia", 2022, "white");

	service.add(c1);
	service.add(c2);
	service.add(c3);
	service.add(c4);
	service.add(c5);
}

void UI::start()
{
	int cmd;
	addCars();
	while (true)
	{
		menu();
		std::cin >> cmd;
		switch (cmd)
		{
		case 1:
			add();
			break;
		case 2:
			rem();
			break;
		case 3:
			showAll();
			break;
		case 4:
			showCar2();

		default:
			break;
		}
	}
}