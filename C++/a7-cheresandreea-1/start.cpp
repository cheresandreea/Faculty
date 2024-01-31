#include "UI.h"
#include "Test.h"
#include <iostream>
#include <crtdbg.h>


int main()
{
	vector<Dog> adoptedDogs;

	std::cout << "What type of file do you want to use? (CSV or HTML)\n";
	std::string op;
	std::cin >> op;

	//Repo* repo = nullptr;
	RepoFile* repof = nullptr;
	Repo* repoAdopted = nullptr;
	repof = new RepoFile();

	if (op == "CSV")
	{
		repoAdopted = new RepoFileCSV();
	}
	else if (op == "HTML")
	{
		repoAdopted = new RepoFileHTML();
		
	}
	else
	{
		std::cout << "Invalid input!\n";
		return 1;

	}

	Service service(repof, repoAdopted);
	UI ui(service);

	ui.start();
	delete repoAdopted;
	delete repof;
	_CrtDumpMemoryLeaks();
	//runTests();

	return 0;
}