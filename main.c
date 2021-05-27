#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "header.h"

int main(void)
{
	int i = 0, n = 0;
	FILE* tf = NULL;
	tf = fopen("obracun.txt", "w");
	if (tf == NULL)
	{
		printf("Nah");
		return -1;
	}
	printf("Unesite n:\n");
	scanf("%d", &n);
	getchar();
	//zauzimanje(n);
	JELOVNIK* fullOrder = { 0 };
	izbornik(tf, n);
	/*JELOVNIK x;
	JELOVNIK* pokX = &x;
	pokX = zauzimanje(n, &x);*/
	//izbornik(tf);

	return 0;
}
