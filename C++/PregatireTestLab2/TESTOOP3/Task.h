#pragma once
#include <string>
using namespace std;

class Task
{
private:
	string description;
	int duration;
	int priority;

public:
	Task();
	Task(string description, int duration, int priority) : description{ description }, duration{ duration }, priority{ priority } {};
	~Task();
	string getDescription() { return description; }
	int getDuration() { return duration; }
	int getPriority() { return priority; }
};