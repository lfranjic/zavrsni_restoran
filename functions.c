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
	JELOVNIK* orderArray = NULL;
	JELOVNIK* foundOrder = NULL;
	int uvjet = 0;
	do
	{
		scanf("%d", &uvjet);
	}
	while (uvjet < 1 || uvjet > 5);

	switch (uvjet)
	{
	case 1:
	{
		addOrder();
		break;
	}
	case 2:
	{
		if (orderArray != NULL)
		{
			free(orderArray);
			orderArray = NULL;
		}
		orderArray = (JELOVNIK*)loadOrder();
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

void* loadOrder()
{
	FILE* bf = fopen("order.bin", "rb");
	if (bf == NULL)
	{
		perror("Ucitavanje narudzbe iz datoteke.");
		return NULL;
	}
	fread(&orderNum, sizeof(int), 1, bf);
	printf("Broj narudzbi: %d\n", orderNum);
	JELOVNIK* orderArray = (JELOVNIK*)calloc(orderNum, sizeof(JELOVNIK));
	if (orderArray == NULL)
	{
		perror("Zauzimanje memorije narudzbe");
		return NULL;
	}
	fread(orderArray, sizeof(JELOVNIK), orderNum, bf);

	return orderArray;
}

void addOrder()
{
	FILE* bf = fopen("order.bin", "rb+");
	if (bf == NULL)
	{
		perror("Dodavanje narudzbe u datoteku");
		exit(EXIT_FAILURE);
	}

	fread(&orderNum, sizeof(int), 1, bf);
	printf("Broj narudzbi: %d\n", orderNum);
	JELOVNIK temp = { 0 };
	temp.id = orderNum;
	getchar();
	printf("Unesite id:\n");
	scanf("%d[^\n]", &temp.id);
	printf("Unesite naziv:\n");
	getchar();
	scanf("%29s[^\n]", &temp.naziv);
	getchar();
	printf("Unesite cijenu:\n");
	scanf("%9s[^\n]", &temp.cijena);
	getchar();
	fseek(bf, sizeof(JELOVNIK) * orderNum, SEEK_CUR);
	fwrite(&temp, sizeof(JELOVNIK), 1, bf);
	rewind(bf);
	orderNum++;
	fwrite(&orderNum, sizeof(int), 1, bf);
	fclose(bf);
}

void writeOrder(const JELOVNIK* const orderArray)
{
	if (orderArray == NULL)
	{
		printf("Polje je prazno.\n");
		return -1;
	}
	int i;
	for (i = 0; i < orderNum; i++)
	{
		printf("Narudzba broj %d\tID:\tnaziv: %29s\tcijena: %9s\n",
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
	char trazenId[30] = { '\0' };
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