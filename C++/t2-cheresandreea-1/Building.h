#pragma once
#include <string>

class Building
{
protected:
	int year;
public:
	virtual bool mustBeRestored() const = 0;
	virtual bool canBeDemolished() const = 0;
	std::string toString() const;

	//constructors
	Building(int year) : year{ year } {};
	const int getYear() const { return year; };
	//friend ostream& operator<<(std::ostream& os, const Building& b);


};

