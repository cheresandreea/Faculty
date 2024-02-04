#include <assert.h>
#include <iostream>

#include "ListIterator.h"
#include "SortedIndexedList.h"

using namespace std;

bool relation1(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll() {
    SortedIndexedList list = SortedIndexedList(relation1);
    assert(list.size() == 0);
    assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator iterator = list.iterator();
    assert(iterator.valid());
    iterator.first();
    assert(iterator.getCurrent() == 1);
    iterator.next();
    assert(!iterator.valid());
    iterator.first();
    assert(iterator.valid());
    assert(list.search(1) == 0);
    assert(list.remove(0) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());



    SortedIndexedList list1 = SortedIndexedList(relation1);
    list1.add(5);
    list1.add(3);
    list1.add(7);
    list1.add(6);
    list1.add(2);
    list1.add(1);
    list1.add(4);
    list1.add(9);
    list1.add(8);
    list1.add(10);
    for(int i = 1; i<=10; i++)
    {
        int p = list1.search(i);
        assert(p == i - 1);
        int el=list1.getElement(p);
        assert(el == i);
    }

/*    SortedIndexedList list5 = SortedIndexedList(relation1);
    list5.add(5);
    list5.add(3);
    list5.add(7);
    list5.add(3);
    list5.add(3);

    std::cout<<list5.lastIndexOf(7);*/




}

