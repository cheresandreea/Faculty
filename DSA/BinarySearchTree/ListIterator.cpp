#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;



ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	//TODO - Implementation best case tetha(1), worst, average -tetha(n), total O(n)

    currentNode = list.root;
    while (currentNode != nullptr) {
        nodeStack.push(currentNode);
        currentNode = currentNode->left;
    }

    if (!nodeStack.empty()) {
        currentNode = nodeStack.top();
        nodeStack.pop();
    } else {
        currentNode = nullptr;
    }
}

void ListIterator::first(){
	//TODO - Implementation best case tetha(1), worst, average -tetha(n), total O(n)

    currentNode = list.root;
    while (currentNode != nullptr) {
        nodeStack.push(currentNode);
        currentNode = currentNode->left;
    }

    if (!nodeStack.empty()) {
        currentNode = nodeStack.top();
        nodeStack.pop();
    } else {
        currentNode = nullptr;
    }

}

void ListIterator::next() {
    //TODO - Implementation best case tetha(1), worst, average -tetha(n), total O(n)

    if (!valid())
        throw std::runtime_error("Iterator is not valid.");

    currentNode = currentNode->right;
    while (currentNode != nullptr) {
        nodeStack.push(currentNode);
        currentNode = currentNode->left;
    }

    if (!nodeStack.empty()) {
        currentNode = nodeStack.top();
        nodeStack.pop();
    } else {
        currentNode = nullptr;
    }
}

bool ListIterator::valid() const{
	//TODO - Implementation tetha(1)
    return (currentNode != nullptr);

}

TComp ListIterator::getCurrent() const{
	//TODO - Implementation tetha(1)
    if (currentNode == nullptr)
        throw std::runtime_error("Iterator is not valid.");

    return currentNode->info;
}



