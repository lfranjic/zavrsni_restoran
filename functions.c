#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "header.h"

static int orderNum = 0;
static int sumCijena = 0;

FILE* openFile()
{
	FILE* bf = NULL;
	bf = fopen("order.txt", "w+");
	if (bf == NULL)
	{
		printf("Datoteka se ne moze otvoriti.");
		exit(EXIT_FAILURE);
	}
	else
	{
		return bf;
	}
}

void memory()
{
	JELOVNIK* jeloArray = (JELOVNIK*)calloc(orderNum, sizeof(JELOVNIK));
}

int izbornik()
{
	memory();
	printf("____________________\n");
	printf("Odaberite opciju:\n");
	printf("____________________\n");
	printf("1: Dodavanje narudzbe.\n");
	printf("2: Ucitavanje narudzbe.\n");
	printf("3: Ispis narudzbe.\n");
	printf("4: Pretraga narudzbe.\n");
	printf("5: Sortiraj narudzbe po id-u.\n");
	printf("6: Ispis racuna.\n");
	printf("7: Izlaz iz programa.\n");
	printf("____________________\n");
	printf("____________________\n");
	int m = 0;
	if (jeloArray == NULL)
	{
		perror("Zauzimanje memorije narudzbe");
		return NULL;
	}
	int uvjet = 0;
	do
	{
		scanf("%d", &uvjet);
	}
	while (uvjet < 0 || uvjet >= 8);

	switch (uvjet)
	{
	case 1:
	{
		printf("Unesite broj narudzbi:\n");
		scanf("%d", &m);
		addOrder(m);
		break;
	}
	case 2:
	{
		loadOrder();
		if (jeloArray == NULL)
		{
			exit(EXIT_FAILURE);
		}
		break;
	}
	case 3:
	{
		writeOrder(orderNum);
		break;
	}
	case 4:
	{
		searchOrder(orderNum);
		break;
	}
	case 5:
	{
		printArray(jeloArray, orderNum);
		break;
	}
	case 6:
	{
		ispisRacuna(sumCijena);
		break;
	}
	case 7:
	{
		uvjet = 0;
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

int addOrder(int m)
{
	FILE* bf = openFile();
	for (int i = 0; i < m; i++)
	{
		printf("Unesite id:\n");
		scanf("%d", &(jeloArray + i)->id);
		printf("Unesite naziv:\n");
		scanf("%s", &(jeloArray + i)->naziv);
		getchar();
		printf("Unesite cijenu:\n");
		scanf("%d", &(jeloArray + i)->cijena);
		sumCijena += (jeloArray + i)->cijena;
		fprintf(bf, "%d %s %d\n", (jeloArray + i)->id, (jeloArray + i)->naziv, (jeloArray + i)->cijena);
		//fprintf(bf, "%d", sumCijena);
		orderNum++;
	}
	return orderNum;
}

void* loadOrder()
{
	FILE* bf = openFile();
	printf("Broj narudzbi: %d\n", orderNum);
	fread(jeloArray, sizeof(JELOVNIK), orderNum, bf);

	return jeloArray;
}

void writeOrder(int n)
{
	FILE* bf = openFile();
	if (jeloArray == NULL)
	{
		printf("Polje je prazno.\n");
		return -1;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		fscanf(bf, "%d %s %d", (jeloArray + i)->id, (jeloArray + i)->naziv, (jeloArray + i)->cijena);
		printf("Narudzba broj %d\nID: %d\nnaziv: %s\ncijena: %d\n",
			i + 1,
			(jeloArray + i)->id,
			(jeloArray + i)->naziv,
			(jeloArray + i)->cijena);
	}
}

void* searchOrder(int n)
{
	if (jeloArray == NULL)
	{
		printf("Polje je prazno 2.\n");
		return NULL;
	}
	int i;
	int trazenId = 0;
	printf("Unesite kriterij (ID) za pronalazak narudzbe.\n");
	scanf("%d", &trazenId);
	for (i = 0; i < n; i++)
	{
		if (trazenId == (jeloArray + i)->id)
		{
			printf("Narudzba je pronadena.\n");
			printf("ID: %d\nNaziv: %s\nCijena: %d\n",
				(jeloArray + i)->id,
				(jeloArray + i)->naziv,
				(jeloArray + i)->cijena);
		}
	}

	return NULL;
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(JELOVNIK* jeloArray, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if ((jeloArray + j)->id > (jeloArray + j + 1)->id)
			{
				swap(&(jeloArray + j)->id, &(jeloArray + j + 1)->id);
				swap(&(jeloArray + j)->naziv, &(jeloArray + j + 1)->naziv);
				swap(&(jeloArray + j)->cijena, &(jeloArray + j + 1)->cijena);
			}
		}
	}
}
/*
void bubbleSort2(JELOVNIK* jeloArray, int n)
{
	int c, d;
	int changeID;
	int changePrice;
	for (c = 0; c < n - 1; c++)
	{
		for (d = 0; d < n - c - 1; d++)
		{
			if ((jeloArray + d)->id < (jeloArray + d + 1)->id)
			{
				changeID = (jeloArray->id + d);
				(jeloArray + d)->id = (jeloArray + d + 1)->id;
				(jeloArray + d + 1)->id = changeID;
				swap(&(jeloArray + d)->naziv, &(jeloArray + d + 1)->naziv);
				changePrice = (jeloArray->cijena + d);
				(jeloArray + d)->cijena = (jeloArray + d + 1)->cijena;
				(jeloArray + d + 1)->cijena = changePrice;
			}
		}
	}
}*/

void printArray(JELOVNIK* jeloArray, int m)
{
	int i;
	bubbleSort(jeloArray, m);
	for (i = 0; i < m; i++)
	{
		printf("Narudzba broj %d\nID: %d\nnaziv: %s\ncijena: %d\n",
			i + 1, (jeloArray + i)->id, (jeloArray + i)->naziv, (jeloArray + i)->cijena);
	}
}

void ispisRacuna(int obracun)
{
	printf("Cijena racuna je: %d kn\n", obracun);
}