#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "header.h"

static int orderNum = 0;

int izbornik()
{
	printf("____________________\n");
	printf("Odaberite opciju:\n");
	printf("____________________\n");
	printf("1: Dodavanje narudzbe.\n");
	printf("2: Ucitavanje narudzbe.\n");
	printf("3: Ispis narudzbe.\n");
	printf("4: Pretraga narudzbe.\n");
	printf("5: Izlaz iz programa.\n");
	printf("____________________\n");
	printf("____________________\n");
	JELOVNIK* foundOrder = NULL;
	JELOVNIK* orderArray = (JELOVNIK*)calloc(orderNum, sizeof(JELOVNIK));
	if (orderArray == NULL)
	{
		perror("Zauzimanje memorije narudzbe");
		return NULL;
	}
	int uvjet = 0;
	do
	{
		scanf("%d", &uvjet);
	}
	while (uvjet < 0 || uvjet >= 6);

	switch (uvjet)
	{
	case 1:
	{
		addOrder(orderArray);
		break;
	}
	case 2:
	{
		orderArray = (JELOVNIK*)loadOrder(orderArray);
		if (orderArray == NULL)
		{
			exit(EXIT_FAILURE);
		}
		break;
	}
	case 3:
	{
		writeOrder(orderArray);
		break;
	}
	case 4:
	{
		foundOrder = (JELOVNIK*)searchOrder(orderArray);
		break;
	}
	case 5:
	{
		uvjet = exitProgram(orderArray);
		break;
	}
	default:
	{
		uvjet = 0;
		break;
	}
	}
	return uvjet;
}

void createFile()
{
	FILE* bf = fopen("order.bin", "wb");
	if (bf == NULL)
	{
		perror("Kreiranje narudzba.bin");
		exit(EXIT_FAILURE);
	}
	else
	{
		fwrite(&orderNum, sizeof(int), 1, bf);
		fclose(bf);
	}
}

void* loadOrder(JELOVNIK* const orderArray)
{
	FILE* bf = fopen("order.bin", "rb");
	if (bf == NULL)
	{
		perror("Ucitavanje narudzbe iz datoteke.");
		return NULL;
	}
	printf("Broj narudzbi: %d\n", orderNum);
	fread(orderArray, sizeof(JELOVNIK), orderNum, bf);

	return orderArray;
}

void addOrder(JELOVNIK* temp)
{
	FILE* bf = fopen("order.bin", "rb+");
	if (bf == NULL)
	{
		perror("Dodavanje narudzbe u datoteku");
		exit(EXIT_FAILURE);
	}
	printf("Broj narudzbi: %d\n", orderNum);
	//JELOVNIK temp = { 0 };
	temp->id = orderNum;
	printf("Unesite id:\n");
	scanf("%d[^\n]", &temp->id);
	printf("Unesite naziv:\n");
	scanf("%99s[^\n]", &temp->naziv);
	getchar();
	printf("Unesite cijenu:\n");
	scanf("%d[^\n]", &temp->cijena);
	fseek(bf, sizeof(JELOVNIK) * orderNum, SEEK_CUR);
	fwrite(&temp, sizeof(JELOVNIK), 1, bf);
	rewind(bf);
	int helpCijena = 0;
	temp->cijena = helpCijena;
	int sumCijena = 0;
	sumCijena += temp->cijena;
	fprintf(bf, "%d", sumCijena);
	orderNum++;
	fwrite(&orderNum, sizeof(int), 1, bf);
	fclose(bf);
}

void writeOrder(JELOVNIK* const orderArray)
{
	if (orderArray == NULL)
	{
		printf("Polje je prazno.\n");
		return -1;
	}
	int i;
	for (i = 0; i < orderNum; i++)
	{
		printf("Narudzba broj %d\nID: %d\nnaziv: %99s\ncijena: %d\n",
			i + 1, (orderArray + i)->id, (orderArray + i)->naziv, (orderArray + i)->cijena);
	}
}

void* searchOrder(JELOVNIK* const orderArray)
{
	if (orderArray == NULL)
	{
		printf("Polje je prazno 2.\n");
		return NULL;
	}
	int i;
	//id ili naziv, pokusat oboje
	char trazenId[100] = { '\0' };
	printf("Unesite kriterij za pronalazak narudzbe.\n");
	getchar();
	scanf("%d", &trazenId);
	for (i = 0; i < orderNum; i++)
	{
		if (!strcmp(trazenId, (orderArray + i)->id))
		{
			printf("Narudzba je pronadena.\n");
			return (orderArray + i);
		}
	}

	return NULL;
}

int exitProgram(JELOVNIK* orderArray)
{
	free(orderArray);

	return 0;
}