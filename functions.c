#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

JELOVNIK* zauzimanje(int n, JELOVNIK *x)
{
	x = (JELOVNIK*)calloc(n, sizeof(JELOVNIK));
	if (x == NULL)
	{
		return 1;
	}
	return x;
}

int izbornik(const char* const tf, int n)
{
	printf("Odaberite opciju:\n");
	printf("1: Dodaj jelo na racun\n");
	printf("2: Dodaj narudzbu\n");
	printf("3: Dodaj rezervaciju\n");
	printf("4: Ispisi racun\n");
	printf("5: Zatvori program\n");
	printf("______________________________\n");
	int uvjet = 0;
	int order = 0;
	int delivery = 0;
	int reservation = 0;
	scanf("%d", &uvjet);
	switch (uvjet)
	{
	case 1:
	{
		scanf("%d", &order);
		switch (order)
		{
		case 1:
		{
			for (int i = 0; i < n; i++)
			{
				printf("Odaberite sto dodati na racun:\n");
				printf("1: Glavno jelo\n");
				printf("2: Juha\n");
				printf("3: Salata\n");
				printf("4: Desert\n");
				printf("5: Napitak\n");
				printf("______________________________\n");
				break;
			}
		}
		default:
		{
			order = 0;
			break;
		}
		}
		break;
	}
	case 2:
	{
		scanf("%d", &delivery);
		switch (delivery)
		{
		case 1:
		{
			/*
			broj unosa
			*/
			printf("Odaberite sto dodati na narudzbu:\n");
			printf("1: Glavno jelo\n");
			printf("2: Juha\n");
			printf("3: Salata\n");
			printf("4: Desert\n");
			printf("5: Napitak\n");
			printf("______________________________\n");
			break;
		}
		default:
		{
			delivery = 0;
			break;
		}
		}
		break;
	}
	case 3:
	{
		printf("Imate li rezervaciju?\n");
		printf("Odaberite:\n");
		printf("1: Zelim napraviti rezervaciju");
		printf("2: Da\n");
		printf("3: Ne\n");
		scanf("%d", &reservation);
		switch (reservation)
		{
		case 1:
		{
			printf("Mozemo li dobiti podatke o rezervaciji?\n");
			/*
			id/ime, broj osoba, stol, kada
			*/
			break;
		}
		case 2:
		{
			printf("Mozete li samo reci ime?\n");
			/*
			id/ime
			*/
			break;
		}
		case 3:
		{
			/*
			razmisli
			*/
		}
		default:
		{
			break;
		}
		}
	}
	case 4:
	{
		printf("Zelite li racun?\n");
		/*
		ispis racuna
		*/
	}
	case 5:
	{
		/*
		end
		*/
	}
	default:
	{
		break;
	}
	}
	return uvjet;
}