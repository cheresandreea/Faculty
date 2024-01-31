#pragma once
#include "Building.h"

class Block : public Building
{
private:
	int totalApartments;
	int occupiedAppartments;
public:
	bool mustBeRestored() const override;
	bool canBeDemolished() const override;
	std::string toString() const;

	Block(int year, int totalApartments, int occupiedAppartments) : Building{ year }, totalApartments{ totalApartments }, occupiedAppartments{ occupiedAppartments }{};
	const int getTotal() const { return totalApartments; };
	const int getOccupied() const { return occupiedAppartments; };
};

