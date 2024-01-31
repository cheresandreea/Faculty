#include "Bill.h"

Bill::Bill(){}

Bill::Bill(const std::string& name, const std::string& number, const float sum, const bool& isPaid)
{
	this->name = name;
	this->number = number;
	this->sum = sum;
	this->isPaid = isPaid;
}

Bill::~Bill(){}