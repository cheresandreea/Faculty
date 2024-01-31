/**
### Pharmacy
John is the administrator of the* “Smiles”* Pharmacy.He needs a software application to help him manage his pharmacy's medicine stocks. Each **Medicine**
has the following attributes: `name`, `concentration`, `quantity` and `price`. John wants the application to help him in the following ways:\
* *(a) * *Add, delete or update a medicine.A medicine is uniquely identified by its name and concentration.If a product that already exists is added, its
quantity will be updated(the new quantity is added to the existing one).\
** (b)** See all available medicines containing a given string(if the string is empty, all the available medicines will be considered), sorted ascending by medicine name.\
** (c)** See only those medicines that are in short supply(quantity less than `X` items, where the value of `X` is user - provided).\
** (d)** Provide multiple undo and redo functionality.Each step will undo / redo the previous operation performed by the user.
* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pharmacy.h"

Medicine create(char name[], float concentration, int quantity, float price)
{
	Medicine m;
	strcpy(m.name, name);
	m.concentration = concentration;
	m.quantity = quantity;
	m.price = price;

	return m;
}

//
//char* getName(Medicine* m)
//{
//	return m->name;
//}
//
//float getConcentration(Medicine* m)
//{
//	return m->concentration;
//}
//
//int getQuantity(Medicine* m)
//{
//	return m->quantity;
//}
//
//float getPrice(Medicine* m)
//{
//	return m->price;
//}
//
//
//void toString(Medicine m, char str[])
//{
//	sprintf(str, "Medicine %s has concentration %f and quantity %d and the price is %f.", m.name, m.quantity, m.concentration);
//}
