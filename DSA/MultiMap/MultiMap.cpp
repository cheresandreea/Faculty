#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
	//TODO - Implementation  theta(7)
    m = 7;
    table = new Node*[m]();
    for(int i = 0; i < m; i++)
        table[i] = nullptr;

    count = 0;
    alpha = 0.75;
}

void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation theta(1)

    double loadFactor = count/m;
    if(loadFactor > alpha)
        resizeandRehash();

    int index = hash(c, m);
    Node* newNode = new Node(c, v, nullptr);

    if(table[index] != nullptr)
    {
        newNode->next = table[index];
    }

    table[index] = newNode;
    count++;

}

void MultiMap::resizeandRehash()
//TODO theta(n)
{
    int newcap = m * 2 ;
    Node** newTable = new Node*[newcap];

    for(int i = 0; i < newcap; i++)
        newTable[i] = nullptr;

    for(int i = 0; i < m; i++)
    {
        while(table[i] != nullptr)
        {
            Node* newNode = new Node(table[i]->key, table[i]->value, nullptr);

            int newIndex;
            newIndex = hash(newNode->key, newcap);

            if(newTable[newIndex] != nullptr)
                newNode->next = newTable[newIndex];

            newTable[newIndex] = newNode;
            table[i] = table[i]->next;
        }
    }

    for (int i = 0; i < this->m; i++)
        delete table[i];
    delete[] table;

    this->table = newTable;
    this->m = newcap;
}


bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation  Best case: theta(1),  Worst, average case: theta(n), Total complexity: O(n)

    int index = hash(c, m);

    Node* current = table[index];
    Node* previous = nullptr;

    while(current != nullptr) {
        if (current->key == c && current->value == v) {
            if (previous == nullptr)
                table[index] = current->next;
            else
                previous->next = current->next;

            delete current;
            count--;
            return true;
        }
        previous = current;
        current = current->next;
    }
	return  false;
}


vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation  Best case: theta(1),  Worst, average case: theta(n), Total complexity: O(n)
    vector<TValue > values;

    int index = hash(c, this->m);
    Node* current = table[index];

    while(current != nullptr)
    {
        if(current->key == c)
            values.push_back(current->value);;
        current = current->next;
    }


	return values;
}


int MultiMap::size() const {
	//TODO - Implementation tetha(1)
	return count;
}


bool MultiMap::isEmpty() const {
	//TODO - Implementation theta(1)
    if(count == 0)
        return true;
	return false;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	//TODO - Implementation theta(n)
    for(int i = 0; i < m; i++)
    {
        Node* current = table[i];
        while(current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] table;
}

vector<TKey> MultiMap::keySet() const {
    //returns a vector with all the keys fromthe MultiMap
    vector<TKey > values;
    //TODO tetha(n)

    for(int i = 0; i < m; i++)
    {
        Node* current = table[i];
        if(current != nullptr)
        {
            values.push_back(current->key);
            current = current->next;
        }
    }
    return values;
}