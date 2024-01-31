#include "Repository.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Repository::Repository()
{
}

Repository::~Repository()
{
}

void Repository::readFile()
{
	ifstream file("file.txt");
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string description;
		string duration;
		string priority;
		getline(ss, description, '|');
		getline(ss, duration, '|');
		getline(ss, priority, '|');
		
		Task t{ description, stoi(duration), stoi(priority) };
		tasks.push_back(t);

	}
	file.close();

}

vector<Task> Repository::getTasks()
{
	return tasks;
}