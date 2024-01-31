#include "Pharmacy.h"
#include "Repo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int growth_factor = 2;

MedicineRepo *initMedicineRepo(int capacity)
{
	MedicineRepo* repo = (MedicineRepo*)malloc(sizeof(MedicineRepo));

	repo->length = 0;
	repo->capacity = capacity;
	repo->med = (Medicine*)malloc(capacity * sizeof(Medicine));

	return repo;
}

//int addMedicine(MedicineRepo* repo, Medicine* m)
//{
//	Medicine* existingMed = findMedicine(repo, m->name, m->concentration);
//	if (existingMed != 0)
//	{
//		existingMed->quantity += m->quantity;
//		return;
//	}
//
//	if (repo->length >= repo->capacity)
//	{
//		repo->capacity *= growth_factor;
//		repo->med = (Medicine*)realloc(repo->med, repo->capacity * sizeof(Medicine));
//	}
//
//	repo->med[repo->length] = *m;
//	repo->length++;
//}
//
//Medicine* findMedicine(MedicineRepo* repo, char* name, float concentration)
//{
//	for (int i = 0; i < repo->length; i++)
//	{
//		if (strcmp(repo->med[i].name, name) == 0 && repo->med[i].concentration == concentration)
//			return &repo->med[i];
//	}
//	return NULL;
//}