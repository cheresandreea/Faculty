#include "House.h"
#include <sstream>

using namespace std;

bool House::mustBeRestored() const
{
	if (2023 - this->year > 100) 
		return true;
	return false;
}

bool House::canBeDemolished() const
{
	if (this->isHistorical == false)
		return true;

	return false;
}

std::string House::toString() const
{
	stringstream buffer;
	buffer << "Building year: " << this->year << endl << "IsHistorical: " << this->isHistorical <<endl;

	return buffer.str();
}
