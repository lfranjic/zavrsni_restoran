#ifndef HEADER_H
#define HEADER_H	

struct jelovnik
{
	int id;
	char naziv[100];
	int cijena;
	int kolicina;
	int orderNum;
}p[10000];
int orderCount = 0, foodNum = 0;
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

/*JELOVNIK* zauzimanje(int, JELOVNIK*);*/
void menu();
void opcije();
int izbornik(const char* const, int);

#endif //HEADER_H
