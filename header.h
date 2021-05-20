#ifndef HEADER_H
#define HEADER_H	

typedef struct jelovnik
{
	int id;
	char naziv[50];
	float cijena;
	int kolicina;
	int brRacuna;
}JELOVNIK;

typedef struct glavno
{
	JELOVNIK glavno;
}GLAVNO;

typedef struct juha
{
	JELOVNIK juha;
}JUHA;

typedef struct salata
{
	JELOVNIK salata;
}SALATA;

typedef struct desert
{
	JELOVNIK desert;
}DESERT;

typedef struct napitak
{
	JELOVNIK napitak;
}NAPITAK;

JELOVNIK* zauzimanje(int , JELOVNIK *);
int izbornik(const char* const, int);

#endif //HEADER_H