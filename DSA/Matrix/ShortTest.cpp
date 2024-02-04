#include <assert.h>
#include <iostream>
#include "Matrix.h"
#include "MatrixIterator.h"

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);

 /*   Matrix matrix(3, 3);
    matrix.modify(1,1,0);
    matrix.modify(2,2,5);
    matrix.modify(2,1,1);

    MatrixIterator it(matrix);
    it.first();
    assert(it.getCurrent() == 0);

    it.next();
    assert(it.getCurrent() == 5);*/

}
