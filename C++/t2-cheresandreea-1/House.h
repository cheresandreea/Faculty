#pragma once
#include <string>
#include "Building.h"

class House : public Building
{
private:
	bool isHistorical;
public:
	bool mustBeRestored() const override;
	bool canBeDemolished() const override;
	std::string toString() const;

	House(int year, bool isHistorical) : Building{ year }, isHistorical{ isHistorical }{};
	const int getYear() const { return year; };
};

