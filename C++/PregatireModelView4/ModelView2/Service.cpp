#include "Service.h"
#include <vector>
using namespace std;

int Service::verifDescription(string t)
{
	vector<Idea> ideas = repo.getIdeas();
	for (auto i : ideas)
		if (i.getDescription() == t)
			return false;
	return true;

}