#pragma once
#include <string>
using namespace std;

class User
{
private:
	string name;
	string type;
public:
	User();
	User(string name, string type):name{name}, type{type}{}
	~User();
	string getName() const{return this->name;}
	string getType() const{return this->type;}

};

