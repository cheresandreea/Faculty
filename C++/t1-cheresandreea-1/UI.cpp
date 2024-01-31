#include "UI.h"
#include <iostream>
#include<algorithm>

using namespace std;

UI::UI(){}

UI::UI(Service& service)
{
	this->service = service;
}

UI::~UI(){}

void UI::menu()
{
	std::cout << "1. Add a new bill" <<endl;
	std::cout << "2. See all bills"<<endl;
	std::cout << "3. Show all the bills and calculate their sum: ";

}

void UI::addB()
{
	Bill b1 = Bill("Digi Sport", "0A33455X", 75.00, false);
	Bill b2 = Bill("E-On", "EED36677", 122.00, true);
	Bill b3 = Bill("Orange", "X990TTRR", 46.00, true);
	Bill b4 = Bill("Vodafone", "1234RR", 23.00, false);
	Bill b5 = Bill("Tcommn", "TREee", 10.00, false);

	service.add(b1);
	service.add(b2);
	service.add(b3);
	service.add(b4);
	service.add(b5);


}

void UI::add()
//adds a bill in service
{
	std::cout << "Enter the company name: ";
	std::string name;
	std::cin >> name;
	std::cout << "Enter the serial number: ";
	std::string number;
	std::cin >> number;
	std::cout << "Enter the sum: ";
	float sum;
	std::cin >> sum;
	std::cout << "Enter the status: ";
	bool isPaid;
	std::cin >> isPaid;

	vector<Bill> vec = service.getAll();

	Bill bill = Bill(name, number, sum, isPaid);

	int ok = 1;

	for (const auto& b : vec)
	{
		if (b.getNumber() == bill.getNumber())
		{
			std::cout << "The bill already exists!";
			ok = 0;
			return;
		}
	}
	if (ok == 1)
	{
		service.add(bill);
		std::cout << "Bill was successfully added!";
		return;
	}
	return;
}

void UI::seePaid()
{
	//break;
}

void UI::seeAll()
{
	vector<Bill> vec = service.getAll();
	//sorted by comany name
	std::sort(vec.begin(), vec.end(), [](Bill b1, Bill b2) 
		{
			return b1.getName() < b2.getName(); 
		});
	for (const auto& b : vec)
	{

		std::cout << b.getName() << " " << b.getNumber() << " " << b.getSum() << " " << b.getIsPaid() << std::endl;
	}
}

void UI::start()
{
	int cmd;
	addB();

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
			seeAll();
			break;

		case 3:
			seePaid();
			break;
		
		default:
			std::cout << "Invalid input. Please try again." << std::endl;
			break;
		}
	}
}