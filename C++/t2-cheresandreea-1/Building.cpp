#include "Building.h"
#include <sstream>
#include <iostream>
using namespace std;

std::string Building::toString() const
{
    stringstream buffer;
    buffer << "Building year: " << this->year << endl;
    return buffer.str();
}

ostream& operator<<(std::ostream& os, const Building* b)
{
    std::cout << b->toString();
    return os;
}