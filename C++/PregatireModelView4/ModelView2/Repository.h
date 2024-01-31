#pragma once
#include "Writer.h"
#include "Idea.h"
#include <vector>
using namespace std;

class Repository
{
private:
	vector<Writer> writers ;
	vector<Idea> ideas;

public:
	Repository() { readFromFileIdeas(), readFromFileWriters(); }
	void readFromFileWriters();
	void readFromFileIdeas();
	void add(Idea& i);
	vector<Writer>& getWriters() { return writers; }
	vector<Idea>& getIdeas() { return ideas; }

	~Repository() {};
};

