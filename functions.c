#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

JELOVNIK* zauzimanje(int n, JELOVNIK* x)
{
	x = (JELOVNIK*)calloc(n, sizeof(JELOVNIK));
	if (x == NULL)
	{
		return 1;
	}
	return x;
}

void menu()
{
	printf("______________________________MENU______________________________\n");
	printf("Id:\t\tNaziv:\t\tCijena (kn)\n");
	printf("[1]----------Juha od brokule----------12.99\n");
	printf("[2]----------Juha od gljiva----------13.99\n");
	printf("[3]----------Juha od brokule----------12.99\n");
	printf("[4]----------Zagrebacki odrezak----------21.99\n");
	printf("[5]----------Becki odrezak----------18.99\n");
	printf("[6]----------Tjestenina bolognese----------15.99\n");
	printf("[7]----------Punjeni pileci file----------14.99\n");
	printf("[8]----------Kava s mlijekom----------6.99\n");
	printf("[9]----------Kava sa slagom----------7.99\n");
}

void opcije()
{
	printf("Odaberite opciju:\n");
	printf("1: Dodaj jelo na racun\n");
	printf("2: Dodaj narudzbu\n");
	printf("3: Dodaj rezervaciju\n");
	printf("4: Ispisi racun\n");
	printf("5: Zatvori program\n");
}

int izbornik(const char* const tf, int x)
{
	int uvjet = 0;
	int order = 0;
	int delivery = 0;
	int reservation = 0;
	int m, i;
	int orderCount = 0, deliveryCount = 0;
	menu();
	printf("Order: Odaberite koliko stavki dodati:\n");
	scanf("%d", &m);
	getchar();
	while (m--)
	{
		printf("Unesite id stavke:\n");
		scanf("%d", &order);
		getchar();
	}
	/*
	while
	{
		switch(uvjet/artikl)
		{
		dodaj + izracunaj
		u datoteku ubaci rez
		}
	}

	*/
	opcije();
	scanf("%d", &uvjet);
	getchar();
	switch (uvjet)
	{
	case 1:
	{
		
		break;
	}
	case 2:
	{
		printf("Delivery: Odaberite koliko stavki dodati:\n");
		scanf("%d", &m);
		getchar();
		while (m--)
		{
			printf("Unesite id stavke:\n");
			scanf("%d", &delivery);
			getchar();

		}
		break;
	}
	case 3:
	{
		printf("Imate li rezervaciju?\n");
		printf("Odaberite:\n");
		printf("1: Zelim napraviti rezervaciju.\n");
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
			printf("Ime rezervacije?\n");
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
