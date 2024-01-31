#include "Repository.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void Repository::readFromFileWriters()
{
	ifstream f("writers.txt");

	string line;
	while (getline(f, line))
	{
		stringstream ss(line);
		string name;
		string expertise;

		getline(ss, name, ',');
		getline(ss, expertise, ',');
		Writer w(name, expertise);
		writers.push_back(w);
	}
	f.close();
}

void Repository::readFromFileIdeas()
{
	ifstream f("ideas.txt");
	string line;
	while (getline(f, line))
	{
		stringstream ss(line);
		string description;
		string status;
		string creator;
		string act;

		getline(ss, description, ',');
		getline(ss, status, ',');
		getline(ss, creator, ',');
		getline(ss, act, ',');

		Idea i(description, status, creator, stoi(act));
		ideas.push_back(i);
	} 
	f.close();
}

void Repository::add(Idea& i)
{
	ideas.push_back(i);
}