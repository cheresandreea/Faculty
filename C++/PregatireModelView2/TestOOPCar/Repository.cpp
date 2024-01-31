#include "Repository.h"
#include <fstream>
#include <sstream>
using namespace std;

Repository::Repository()
{
}

Repository::~Repository()
{
}

vector<Car> Repository::getAll()
{
	//read from fille
	ifstream f("file.txt");
	vector<Car> cars;
	string line;

	while (getline(f, line))
	{
		stringstream ss(line);
		string token;
		vector<string> tokens;

		while (getline(ss, token, '|'))
		{
			tokens.push_back(token);
		}
		Car c(tokens[0], tokens[1], stoi(tokens[2]), tokens[3]);
		cars.push_back(c);
	}
	f.close();
	return cars;

}
