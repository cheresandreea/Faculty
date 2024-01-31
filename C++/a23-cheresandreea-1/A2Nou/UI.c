#include "Repo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

void menu()
{
	printf("Welcome to Smiles Pharmacy!\n");
	printf("1. Add a medicine to the stock\n");
	printf("2. Delete a medicine from the stock\n");
	printf("3. Update a medicine in the stock\n");
	printf("4. Display the list of medicines in the stock\n");
	printf("5. Exit\n");
}

void addMedicineMenu()
{
	printf("Enter the details of the medicine:\n");
	char name[50];
	float concentration;
	int quantity;
	float price;
	printf("Name: ");
	scanf("%s", name);
	printf("Concentration: ");
	scanf("%f", &concentration);
	printf("Quantity: ");
	scanf("%d", &quantity);
	printf("Price: ");
	scanf("%f", &price);
	addMedicineToStock(name, concentration, quantity, price);
}


int start()
{
	menu();
}