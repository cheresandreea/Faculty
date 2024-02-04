/*
//
// Created by Andreea on 5/17/2023.
//
#include "MatrixIterator.h"
#include <iostream>

using namespace std;

MatrixIterator::MatrixIterator(Matrix matrix, int line){
    this->matrix = matrix;
    current = matrix.head;
    this->line = line;
}

void MatrixIterator::next()
{
    if(current == -1 || line < 0 || line > matrix.lines)
        throw exception();

    while(matrix.elems[current].line != line)
        current = matrix.next[current];

    if(matrix.elems[current].line == line)
        current = matrix.elems[matrix.next[current]];
    else throw exception();

}

void MatrixIterator::previous()
{
}

bool MatrixIterator::valid() const
{
    if(current == -1)
        return false;
    return true;
}

TElem MatrixIterator::getCurrent() {
    if(current == -1)
        throw exception();

    while(matrix.elems[current].line != line)
        current = matrix.next[current];

    return matrix.elems[current].val;
}



*/
