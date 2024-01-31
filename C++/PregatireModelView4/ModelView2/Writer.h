#pragma once
#include <string>
using namespace std;

class Writer
{
private:
	string name;
	string expertise;
public:
	Writer() {}
	Writer(string name, string expertise) : name(name), expertise(expertise) {}
	~Writer() {}
	string getName() { return name; }
	string getExpertise() { return expertise; }
	void setName(string name) { name = name; }
	void setExpertise(string expertise) { expertise = expertise; }

};

