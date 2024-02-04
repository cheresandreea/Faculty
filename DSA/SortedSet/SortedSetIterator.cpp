#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//TODO - Implementation THETA(1)
    this->index = 0;
}


void SortedSetIterator::first() {
	//TODO - Implementation THETA(1)
    this->index = 0;
}


void SortedSetIterator::next() {
	//TODO - Implementation THETA(1)
    if(valid())
        index++;
    else
        throw std::exception();
}

TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation THETA(1)
    if(valid())
	    return multime.array[index];
    else
        throw std::exception();
}

bool SortedSetIterator::valid() const {
	//TODO - Implementation THETA(1)
    if(index >= 0 && index < this->multime.size())
        return true;
	return false;
}

void SortedSetIterator::previous()
{
    //TODO - THETA(1)
    if(valid() && index > 0)
        index--;
    else
        throw std::exception();
    //O(1)
}