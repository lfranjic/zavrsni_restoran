#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "header.h"

//void memory();
int izbornik();
FILE* openFile();
int addOrder(int);
void* loadOrder();
void writeOrder(int);
void* searchOrder(int);
void swap(int*, int*);
void bubbleSort(JELOVNIK*, int);
void printArray(JELOVNIK*, int);
void ispisRacuna(int);

#endif //FUNCTIONS_H