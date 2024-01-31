#pragma once
#include <string>
using namespace std;

class Bill
{
private:
	string name;
	string code;
	double sum;
	bool isPaid;
public:
	Bill();
	Bill(string name, string code, double sum, bool isPaid): name(name), code(code), sum(sum), isPaid(isPaid) {};
	~Bill();
	string getName() { return name; }
	string getCode(){return code;}
	double getSum() { return sum; }
	bool getIsPaid(){return isPaid;}

};

