#pragma once
#include "Service.h"

class UI
{
private:
	Service service;
public:
	UI();
	UI(Service &service);
	~UI();
	void add();
	void menu();
	void addCars();
	void start();
	void showAll();
	void showCar(Car c);
	void rem();
	void showCar2();

};