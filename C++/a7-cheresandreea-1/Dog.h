#pragma once
#include <string>
class Dog
{
private:
	std::string breed;
	std::string name;
	int age;
	std::string photography;

public:
	//constructor
	Dog();
	Dog(const std::string& breed, const std::string& name, int age, const std::string& photograph);
	
	//destructor
	~Dog();

	//getters
	const std::string getName() const { return name; }
	const std::string getBreed() const { return breed; }
	const std::string getPhotography() const { return photography; }
	int getAge() const { return age; }

	//overload operator ==
	bool operator==(const Dog& other) const;
	friend std::istream& operator>>(std::istream& is, Dog& d);
	friend std::ostream& operator<<(std::ostream& os, const Dog& d);
};