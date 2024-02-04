#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {

    //TODO - Implementation
    //TODO Tetha(capacity)

    this->lines = nrLines;
    this->cols = nrCols;
    capacity = lines * cols;

    this->elems = new Node[this->capacity];
    this->next = new int[this->capacity];

    this->size = 0;
    this->head = -1;
    this->firstFree = 0;

    for(int i = 0; i < capacity - 1; i++)
        next[i] = i + 1;

    next[capacity - 1] = -1;
}

int Matrix::nrLines() const {
	//TODO - Implementation
    //TODO - THETA(1)
	return lines ;
}


int Matrix::nrColumns() const {
	//TODO - Implementation
    //TODO - THETA(1)
	return cols;
}


TElem Matrix::element(int i, int j) const {
	//TODO - Implementation
    //TODO - Thetha(1) best base,
    if(i < 0 || i >= lines || j < 0 || j >= cols)
        throw std::exception();

    int current = head;
    while (current != -1)
    {
        if (this->elems[current].line == i && this->elems[current].col == j) {
            return this->elems[current].val;
        }
        current = this->next[current];
    }

    return NULL_TELEM;

}

TElem Matrix::modify(int i, int j, TElem e) {
    //TODO - Implementation
    //TODO Tetha(1) best case, Tetha(capacity) - average case, worst case
    //TODO O(n) total

    if (i < 0 || i >= lines || j < 0 || j >= cols)
        throw std::exception();

    int current = head;
    int prev = -1;

    while(current != -1 && (elems[current].line != i || elems[current].col !=j) ) {
        prev = current;
        current = next[current];
    }

    if(current != -1)
    {
        TElem old = elems[current].val;
        elems[current].val = e;
        return old;
    }

    int newElemIndex = allocateP();
    elems[newElemIndex].line = i;
    elems[newElemIndex].col = j;
    elems[newElemIndex].val = e;

    if(prev == -1)
    {
        next[newElemIndex] = head;
        head = newElemIndex;
    }
    else{
        next[newElemIndex] = next[prev];
        next[prev] = newElemIndex;
    }

    this->size++;
    return NULL_TELEM;

}

void Matrix::resizeArrays(int newCapacity) {
    //TODO Tetha (capacity)
    Node* newElems = new Node[newCapacity];
    int* newNext = new int[newCapacity];

    for (int i = 0; i < capacity; i++) {
        newElems[i] = elems[i];
        newNext[i] = next[i];
    }

    for (int i = capacity; i < newCapacity - 1; i++) {
        newNext[i] = i + 1;
    }

    newNext[newCapacity - 1] = -1;
    firstFree = capacity;

    delete[] elems;
    delete[] next;

    elems = newElems;
    next = newNext;
    capacity = newCapacity;
}

int Matrix::allocateP() {
    //TODO Tetha(1) best case, Tetha(capacity) - average, worst
    int newFreePos = firstFree;

    if (newFreePos == -1) {
        int newCapacity = capacity * 2;
        resizeArrays(newCapacity);
    }

    firstFree = next[newFreePos];
    return newFreePos;
}


Matrix::~Matrix() {
    //TODO Tetha(capacity)
    delete[] elems;
    delete[] next;

}