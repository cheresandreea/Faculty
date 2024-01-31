#pragma once
#include <string>
using namespace std;

class Car
{
private:
	string name, model, color;
	int year;
public:
	Car(string& name, string& model, int year, string& color):name(name), model(model), year(year), color(color){}
	~Car();
	string getName() { return name; }
	string getModel() { return model; }
	string getColor() { return color; }
	int getYear() { return year; }

};

