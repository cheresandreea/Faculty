#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <exception>

SortedSet::SortedSet(Relation r) {
	//TODO - c
    int cap = 10;
    this->capacity = cap;
    this->array = new TElem[cap];
    length = 0;
    this->relation = r;
}


bool SortedSet::add(TComp elem) {
	//TODO - Implementation THETA(1)-Best Case, THETA(length)-Average, Worst Case
    //TODO TOTAL COMPLEXITY O(N)
    if (search(elem))
        return false;

    if(capacity == length)
        resize();

    int i = 0;
    while(i < length && relation(elem, array[i]) == false)
        i++;

    int j;

    for(j = length - 1; j >= i; j--)
        array[j+1] = array[j];

    array[i] = elem;
    length++;

    return true;
}


bool SortedSet::remove(TComp elem) {
	//TODO - Implementation THETA(1)-Best Case, THETA(length)-Average, Worst Case
    //TODO TOTAL COMPLEXITY O(N)
    int i = 0;
    while(i<length && array[i] != elem)
        i++;

    if(i == length)
        return false;
    int j;
    for(j = i; j < length - 1; j++)
        array[j] = array[j+1];

    length--;
	return true;
}


bool SortedSet::search(TComp elem) const {
	//TODO - Implementation THETA(1)-Best Case, THETA(length)-Average, Worst Case
                    ///TODO TOTAL COMPLEXITY O(N)
    int i = 0;
    while(i < this->length && array[i] != elem)
        i++;

    if(i == this->length)
        return false;

	return true;
}


int SortedSet::size() const {
	//TODO - Implementation THETA(1)
    return length;
}



bool SortedSet::isEmpty() const {
	//TODO - Implementation THETA(1)
    if(length == 0)
	    return true;
    return false;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	//TODO - Implementation THETA(1)
    delete[] this->array;
}

void SortedSet::resize() {
    ///TODO - THETA(length)
    capacity = capacity*2;
    TElem* ar = new TElem[capacity];
    int i;
    for(i = 0 ; i < length; i++)
        ar[i] = array[i];
    delete[] array;
    array = new TElem [capacity];
    for(i = 0 ; i < length; i++)
        array[i] = ar[i];
    delete[]ar;

}

