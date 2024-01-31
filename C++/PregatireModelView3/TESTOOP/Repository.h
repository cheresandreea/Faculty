#pragma once
#include "Bill.h"
#include <vector>
using namespace std;

class Repository
{
private:
	vector<Bill> bills;

public:
	Repository();
	~Repository();
	vector<Bill> getAll();
};

