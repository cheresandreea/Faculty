//
// Created by Andreea on 5/17/2023.
//

#ifndef MATRIX_MATRIXITERATOR_H
#define MATRIX_MATRIXITERATOR_H

#endif //MATRIX_MATRIXITERATOR_H

#include "Matrix.h"

class Matrix;

class MatrixIterator
{
    friend class Matrix;

private:
    Matrix& matrix;
    int line;
    int current;

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
    void previous();

    MatrixIterator(Matrix &matrix, int line);
};