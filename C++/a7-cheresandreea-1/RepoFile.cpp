#include "Repo.h"
#include <fstream>
#include <iostream>
#include <sstream>


void RepoFile::loadAdoptedDogsFile()
{
    std::ifstream file("Dogs.txt");

    if (!file) {
        std::cout << "Error opening file for reading." << std::endl;
        return;
    }
    Dog d;
    string line;

    //while (getline(file, line)) {
    //    std::stringstream ss(line);
    //    std::string breed, name, link;
    //    string years;

    //    if (getline(ss, breed, ',') &&
    //        getline(ss, name, ',') &&
    //        getline(ss, years, ',') &&
    //        getline(ss, link)) {

    //        Dog d = Dog(breed, name, stoi(years), link);
    //        this->dogs.push_back(d);
    //    }
    //    else {
    //        std::cout << "Error reading line: " << line << std::endl;
    //    }
    //}

    while (file >> d)
    {
        this->dogs.push_back(d);
    }

    file.close();

}

RepoFile::RepoFile()
{
    loadAdoptedDogsFile();
}

