#pragma once

#include <stack>
#include "SortedIndexedList.h"


//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIndexedList;
private:
	const SortedIndexedList& list;
	ListIterator(const SortedIndexedList& list);

	//TODO - Representation
    std::stack<SortedIndexedList::Node*> nodeStack;
    SortedIndexedList::Node* currentNode;



public:
	void first();
	void next();
	bool valid() const;
    TComp getCurrent() const;
};


