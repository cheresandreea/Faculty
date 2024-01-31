#include <stdio.h>
#include "Repo.h"
#include "Ui.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	//Medicine m = { 0 };
	/*char name[100];
	float concentration, price;
	int quantity;
	int choice;*/

	MedicineRepo *repo = initMedicineRepo(10);
	addMedicine(repo, "Aspirin", 100, 50, 1);

	//repo.
	//Service serv = createService(&repo);
	//UI ui = createUI(&repo);
	
	return 0;
}

