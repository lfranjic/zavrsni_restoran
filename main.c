#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(void)
{
	int i, n;
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
	JELOVNIK* x;
	x = zauzimanje(n, &x);
	izbornik(tf, x);

	return 0;
}
