#pragma once
#include <string>
class Car
{
private:
	std::string name;
	std::string model;
	int year;
	std::string color;
public:
	Car();

	// constructor with parameters
	Car(const std::string& name, const std::string& model, const int year, const std::string& color);
	~Car();
	const std::string& getName() const { return name; }
	const std::string& getColor() const { return color; }
	const std::string& getModel() const { return model; }
	int getYear() const { return year; }
};