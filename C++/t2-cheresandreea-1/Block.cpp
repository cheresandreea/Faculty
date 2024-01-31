#include "Block.h"
#include <sstream>
using namespace std;

bool Block::mustBeRestored() const
{
	if(2023 - this->year > 40 && this->occupiedAppartments > 80/100*totalApartments)
		return true;
	return false;
}

bool Block::canBeDemolished() const
{
	if (this->occupiedAppartments < 5/100*this->totalApartments)
		return true;
	return false;
}


std::string Block::toString() const
{
	stringstream buffer;
	buffer << "Building year: " << this->year << endl << "Total apps: "<< this->getTotal() << endl<< "Occupied apps:"<< this->getOccupied() << endl;

	return buffer.str();
}