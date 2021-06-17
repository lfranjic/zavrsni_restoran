#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
	int uvjet = 1;
	openFile();
	while (uvjet)
	{
		uvjet = izbornik();
	}
	printf("Kraj programa.\n");

	return 0;
}