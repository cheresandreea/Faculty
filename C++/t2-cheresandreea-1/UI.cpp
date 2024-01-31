#include "UI.h"
#include <iostream>
#include "House.h"
#include "Block.h"
using namespace std;

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

void UI::menu()
{
	std::cout<<"1. Add building\n";
	std::cout<<"2. Show all buildings\n";
	std::cout<<"3. Show demolished buildings\n";
}

void UI::add()
{
	int year;

	std::cout << "Year: ";
	std::cin >> year;

	std::cout << "1. House: " << endl;
	std::cout<<"2. Block: "<<endl;

	int op;
	std::cin >> op;

	if (op == 1)
	{
		bool isH;
		std::cout<<"Is historical? 1/0: ";
		std::cin >> isH;

		House* h = new House(year, isH);

		service.add(h);

	}
	else
		if (op == 2)
		{
			int totalA, occA;
			std::cout<<"Number of otal appartments: ";
			std::cout << "Number of occupied appartments: ";

			std::cin >> totalA >> occA;
			Block* b = new Block(year, totalA, occA);

			service.add(b);
		}
	

}

void UI::showAllByGivenYear()
{
	int year;
	std::cout << "Year: ";
	std::cin >> year;

	vector<Building*> buildings = service.getAll();

	vector<Building*> dem = service.getDemolished(year);
	
	for (auto* x : dem)
	{
		if (dynamic_cast<House*>(x) != nullptr)
			std::cout << dynamic_cast<House*>(x)->toString();
		else
			if (dynamic_cast<Block*>(x) != nullptr)
				std::cout << dynamic_cast<Block*>(x)->toString();
	}

}

//void UI::saveFile()
//{
//	vector<Building*> buildings = service.getAll();
//
//	ofstream f("file.txt");
//	if (!f.is_open())
//		return;
//	vector<Building*> b = service.getRestored();
//	for (auto* x : b)
//	{
//		f << b;
//	}
//	
//	f.close();
//}

void UI::showAll()
{
	vector<Building*> buildings = service.getAll();

	for (auto* x : buildings)
	{
		if (dynamic_cast<House*>(x) != nullptr)
			std::cout << dynamic_cast<House*>(x)->toString();
		else
			if (dynamic_cast<Block*>(x) != nullptr)
				std::cout << dynamic_cast<Block*>(x)->toString();
	}
}

void UI::start()
{
	int op;

	//3 buildings 
	House* h1 = new House(2000, true);
	House* h2 = new House(2020, false);
	Block* b1 = new Block(1990, 100, 50);
	Block* b2 = new Block(2023, 100, 100);
	
	service.add(h1);
	service.add(h2);
	service.add(b1);
	service.add(b2);


	while (true)
	{
		menu();
		std::cin >> op;
		switch (op)
		{

		case 1:
			add();
			break;
		case 2:
			showAll();
			break;
		case 3:
			showAllByGivenYear();
			break;
		default:
			break;

		}
	}
}