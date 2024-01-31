#include "Dog.h"
#include <iostream>

Dog::Dog()
{
	//constructor
	breed[0] = '\0';
	name[0] = '\0';
	age = 0;
	photography[0] = '\0';
}

Dog::Dog(const char* breed, const char* name, int age, const char* photograph)
{
	//constructor
	strcpy(this->breed, breed);
	strcpy(this->name, name);
	this->age = age;
	strcpy(this->photography, photograph);
}

Dog::~Dog() {}//destructor



const char* Dog::getName() const
{
	//returns name
	return name;
}

const char* Dog::getBreed() const
{
	//returns breed
	return breed;
}

const char* Dog::getPhotography() const
{
	//returns photography
	return photography;
}

int Dog::getAge() const
{
	//returns age
	return age;
}

bool Dog::operator==(const Dog& other) const {
	//overloads the operator==
	if(strcmp(name, other.getName()) == 0 && strcmp(breed, other.getBreed()) == 0 && age == other.getAge())
		return true;
	return false;
}

