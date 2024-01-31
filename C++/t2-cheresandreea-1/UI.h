#pragma once
#include "Service.h"

class UI
{
private:
	Service service;
public:
	UI();
	UI(Service& service);
	~UI();

	void start();
	void menu();
	void add();

	void showAll();
	void showAllByGivenYear();
	void saveFile();
};

