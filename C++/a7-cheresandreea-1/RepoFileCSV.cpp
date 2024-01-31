#include "Repo.h"
#include "fstream"
#include "iostream"
#include <windows.h>

RepoFileCSV::RepoFileCSV() : Repo() {}

RepoFileCSV::~RepoFileCSV() {}


void RepoFileCSV::saveAdoptedDogsToSpecificFile()
{
	std::ofstream file("Dogs.csv");
	if (file.is_open()) {
		file << "Breed,Name,Age,PhotoLink\n";
		for (const auto& dog : adoptedDogs) {
			file << dog.getBreed() << "," << dog.getName() << "," << dog.getAge() << "," << dog.getPhotography() << "\n";
		}

		std::string path = "Dogs.csv";
		open(path);

		file.close();
		std::cout << "File saved successfully.\n";
	}
	else {
		std::cout << "Unable to open the file.\n";
	}
}

void RepoFileCSV::open(std::string& path)
{
	ShellExecute(nullptr, "open", path.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

}
void RepoFileCSV::adoptDogRepo(Dog& d)
{
	this->adoptedDogs.push_back(d);
}

vector<Dog> RepoFileCSV::getAdoptedDogsRepo()
{
	return adoptedDogs;
}

void RepoFile::saveToFile()
{
	ofstream file("Dogs.txt");

	for (Dog d : dogs)
	{
		file << d;
	}
	file.close();
}
