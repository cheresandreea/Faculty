#include "Repository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

Repository::Repository()
{
	users = new vector<User>;
	issues = new vector<Issue>;
	readIssues();
	readUsers();
}

Repository::~Repository()
{
}

void Repository::saveToFileIssues()
{
	ofstream f("users.txt");
	
	for (int i = 0; i < issues->size(); i++)
	{
		f << issues->at(i).getDescription() << "," << issues->at(i).getStatus()<<"," << issues->at(i).getReporter()<<","<< issues->at(i).getSolver()<<"\n";
	}
}

void Repository::readUsers()
{
	ifstream f("users.txt");
	string line;
	while (getline(f, line))
	{
		stringstream ss(line);

		string username;
		string password;

		getline(ss, username, ',');
		getline(ss, password, ',');

		User u{ username, password };
		this->users->push_back(u);
	}
	f.close();
}

void Repository :: readIssues()
{
	ifstream f("issues.txt");
	string line;
	while (getline(f, line))
	{
		stringstream ss(line);
		string description;
		string status;
		string reporter;
		string solver;
		getline(ss, description, ',');
		getline(ss, status, ',');
		getline(ss, reporter, ',');
		getline(ss, solver, ',');
		Issue i{ description, status, reporter, solver };
		this->issues->push_back(i);
	}
	std::sort((*issues).begin(), (*issues).end(), [&](Issue& i1, Issue& i2)
		{
			if (i1.getStatus() == i2.getStatus())
				return i1.getDescription() < i2.getDescription();
			else return i1.getStatus() > i2.getStatus();
		});
}

void Repository::addIssue(Issue& i)
{
	this->issues->push_back(i);

	std::sort((*issues).begin(), (*issues).end(), [&](Issue& i1, Issue& i2)
		{
			if (i1.getStatus() == i2.getStatus())
				return i1.getDescription() < i2.getDescription();
			else return i1.getStatus() > i2.getStatus();
		});

}

int Repository::sizeIssues()
{
	return issues->size();
}

int Repository::sizeUsers()
{
	return users->size();
}

int Repository::getIssueByDes(string t)
{
	for (int i = 0; i < issues->size(); i++)
	{
		if (issues->at(i).getDescription() == t)
			return i;
	}
	return -1;
}

void Repository::removeIssue(int pos)
{
	issues->erase(issues->begin() + pos);
}
