#ifndef HEADER_H
#define HEADER_H	

typedef struct jelovnik
{
	int id;
	char naziv[100];
	int cijena;
	int kolicina;
	int orderNum;
}JELOVNIK;
/*
typedef struct jelo
{
	JELOVNIK* glavno;
	JELOVNIK* juha;
	JELOVNIK* salata;
	JELOVNIK* desert;
	JELOVNIK* napitak;
}JELO;
*/

JELOVNIK* zauzimanje(int);
void menu();
void opcije();
int izbornik(FILE*, int n);

#endif //HEADER_H
