#include "Repository.h"
#include "Bill.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

Repository::Repository()
{
}

Repository::~Repository()
{
}

vector<Bill> Repository::getAll()
{
	ifstream file("bill.txt");
	
	//read from the file separated by ;
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string name, code;
		double sum;
		bool isPaid;
		getline(ss, name, ';');
		getline(ss, code, ';');
		ss >> sum;

		ss.ignore();
		string isPaidString;
		getline(ss, isPaidString, ';');
		if (isPaidString == "true")
			isPaid = true;
		else
			isPaid = false;

		Bill b(name, code, sum, isPaid);
		bills.push_back(b);
	}
		
	file.close();
	return bills;
	
}