#pragma once
#include "Pharmacy.h"
typedef struct
{
	Medicine *med;
	int length;
	int capacity;
}MedicineRepo;

int addMedicine(MedicineRepo* repo, Medicine* m);
Medicine* findMedicine(MedicineRepo* repo, char* name, float concentration);