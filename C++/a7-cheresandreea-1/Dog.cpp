#include "Dog.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//Dog::Dog(){}

Dog::Dog()
{
}

Dog::Dog(const std::string& breed, const std::string& name, int age, const std::string& photography) : breed{ breed }, name { name }, age{ age }, photography{photography}
{
}

Dog::~Dog() {}//destructor

bool Dog::operator==(const Dog& other) const {
	//overloads the operator==
	if(name == other.getName() && breed == other.getBreed() && age == other.getAge())
		return true;
	return false;
}

using namespace std;

vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::istream& operator>>(std::istream& is, Dog& d)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;

	d.breed = tokens[0];
	d.name = tokens[1];
	d.age = std::stoi(tokens[2]);
	d.photography = tokens[3];

	return is;
}

std::ostream& operator<<(std::ostream& os, const Dog& d)
{
	os << d.breed << "," << d.name << "," << d.age << "," << d.photography << '\n';
	return os;
}