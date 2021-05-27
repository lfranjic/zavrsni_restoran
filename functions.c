#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "header.h"
/*
JELOVNIK* zauzimanje(int n)
{
	JELOVNIK* x;
	x = (JELOVNIK*)calloc(n, sizeof(JELOVNIK));
	if (x == NULL)
	{
		return 1;
	}
	return x;
}*/

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
	printf("Options:\n");
	printf("1: Dodaj jelo na racun\n");
	printf("2: Dodaj narudzbu\n");
	printf("3: Dodaj rezervaciju\n");
	printf("4: Ispisi racun\n");
	printf("5: Zatvori program\n");
}

int izbornik(FILE* tf, int n)
{
	int uvjet = 0;
	int itemId = 0;
	int delivery = 0;
	int reservation = 0;
	int m = 0, i = 0;
	int qu = 0;
	int ordQu = 0, delQu = 0, rezBill = 0;
	static JELOVNIK* orderFound = NULL;
	JELOVNIK* orderArray = (JELOVNIK*)calloc(n, sizeof(JELOVNIK));
	menu();
	opcije();
	
	FILE* bill = fopen("order.bin", "rb");
	if (bill == NULL)
	{
		perror("Nah v2");
		exit(EXIT_FAILURE);
	}
	/*
	p[orderCount].kolicina = n;
	p[orderCount].kolicina = 0;
	*/
	JELOVNIK tempOrder = { 0 };
	JELOVNIK fullOrder = { 0 };
	printf("Odaberite koliko stavki zelite naruciti:\n");
	scanf("%d", &m);
	getchar();
	while (m--)
	{
		printf("Odaberite opciju:\n");
		scanf("%d", &uvjet);
		getchar();
		printf("Unesite id stavke:\n");
		scanf("%d", &itemId);
		getchar();
		tempOrder.id = itemId;
		switch (uvjet)
		{
		case 1:
		{
			printf("Order: Koliko stavki zelite naruciti?\n");
			scanf("%d", &qu);
			getchar();
			/*
			cijena preko id koji ide na varijablu iz datoteke
			*/
			tempOrder.cijena = 12;
			ordQu = tempOrder.cijena * qu;
			printf("Stavke order: %d\n", ordQu);
			break;
		}
		case 2:
		{
			printf("Delivery: Odaberite koliko stavki dodati:\n");
			scanf("%d", &m);
			getchar();
			/*
			cijena preko id koji ide na varijablu iz datoteke
			*/
			tempOrder.cijena = 12;
			delQu = tempOrder.cijena * qu;
			printf("Stavke delivery: %d\n", delQu);
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
			fullOrder.cijena = ordQu + delQu;
			printf("%d\n", fullOrder.cijena);
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
	}
	return uvjet;
}
