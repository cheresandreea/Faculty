#pragma once
#include <string>
#include <stdexcept>
#include "Dog.h"
#include <exception>


class ValidationException : public std::exception {
private:
    const char* m;
public:
    ValidationException(const char* msg) : m(msg) {}
    const char* what()
    {
        return this->m;
    }

};


class FileReadException : public std::exception {
private:
    const char* m;
public:
    FileReadException(const char* msg) : m(msg) {}
    const char* what()
    {
        return this->m;

    }
    
};

class FileWriteException : public std::exception {
private:
    const char* m;
public:
    FileWriteException(const char* msg) : m(msg) {}
    const char* what()
    {
        return this->m;

    }

};

class PetValidator {
public:
    static void validate(const Dog& dog);
      
};

