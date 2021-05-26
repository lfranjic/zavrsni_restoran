#ifndef HEADER_H
#define HEADER_H	

typedef struct jelovnik
{
	int id;
	char naziv[100];
	float cijena;
	int kolicina;
	int brRacuna;
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

JELOVNIK* zauzimanje(int, JELOVNIK*);
void menu();
void opcije();
int izbornik(const char* const, int);

#endif //HEADER_H
