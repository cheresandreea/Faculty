//#include "DynamicVector.h"
//#include <iostream>
//
//template <typename TElem>
//DynamicVector<TElem>::DynamicVector(int capacity)
//{
//	//constructor
//	this->size = 0;
//	this->capacity = capacity;
//	this->elems = new TElem[capacity];
//}
//
//template <typename TElem>
//DynamicVector<TElem>::DynamicVector(const DynamicVector& v)
//{
//	//copy constructor
//	this->size = v.size;
//	this->capacity = v.capacity;
//	this->elems = new TElem[this->capacity];
//	for (int i = 0; i < this->size; i++)
//		this->elems[i] = v.elems[i];
//}
//
//template <typename TElem>
//DynamicVector<TElem>::~DynamicVector()
//{
//	//deletes an element from the dynamic array
//	delete[]this->elems;
//}
//
//template <typename TElem>
//void DynamicVector<TElem>::resize()
//{
//	//resizes the dynamic array
//	this->capacity *= 2;
//
//	TElem* els = new TElem[this->capacity];
//	for (int i = 0; i < this->size; i++)
//		els[i] = this->elems[i];
//
//	delete[]this->elems;
//	this->elems = els;
//}
//
//
//
//template <typename TElem>
//int DynamicVector<TElem>::getSize()
//{
//	//returns the size of the array
//	return this->size;
//}
//
//template <typename TElem>
//void DynamicVector<TElem>::add(TElem e)
//{
//	//adds an alement in the array
//	if (this->size == this->capacity)
//		this->resize();
//	this->elems[this->size] = e;
//	this->size++;
//}
//
//template <typename TElem>
//void DynamicVector<TElem>::deleteElem(TElem e, int i)
//{
//	//deletes an element in the array
//	this->elems[i] = this->elems[this->size - 1];
//	this->size--;
//}
//
//template <typename TElem>
//TElem& DynamicVector<TElem>::operator[](int index)
//{
//	//overloads the operator []
//	return this->elems[index];
//}
