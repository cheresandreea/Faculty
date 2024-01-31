#include "Car.h"
#include <cstring>
#include <string>

Car::Car() {}

Car::Car(const std::string& name, const std::string& model, const int year, const std::string& color)
{
	//constructor
	this->name = name;
	this->model = model;
	this->year = year;
	this->color = color;
}

Car::~Car()
{
}
