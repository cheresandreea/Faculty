#include <iostream>
#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	//TODO - Implementation Best case: theta(1), Worst, average case: theta(n), Total complexity: O(n)
    currentPos = 0;
    currentNode = c.table[currentPos];

    while (col.table[currentPos] == nullptr && valid()) {
        currentPos++;
        currentNode = c.table[currentPos];
    }

}

TElem MultiMapIterator::getCurrent() const{
	//TODO - Implementation theta(1)
    if(!valid())
        throw std::exception();

    return TElem(currentNode->key, currentNode->value);
}

bool MultiMapIterator::valid() const {
	//TODO - Implementation theta(1)
    if(currentPos < 0 || currentPos >= col.m)
        return false;
    return true;
}


void MultiMapIterator::next() {
	//TODO - Implementation  Best case: theta(1), Worst, average case: theta(n), Total complexity: O(n)
    if (!valid())
        throw std::exception();

    if(currentNode->next != nullptr)
        currentNode = currentNode->next;

    else {
        currentPos++;
        currentNode = col.table[currentPos];
        while (currentNode == nullptr && valid()) {
            currentPos++;
            currentNode = col.table[currentPos];
        }
    }


}

void MultiMapIterator::first() {
	//TODO - Implementation Best case: theta(1), Worst, average case: theta(n), Total complexity: O(n)
    currentPos = 0;
    currentNode = col.table[currentPos];

    while(col.table[currentPos] == nullptr && valid())
    {
        currentPos++;
        currentNode = col.table[currentPos];
    }
}


