#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "header.h"

int izbornik();
void createFile();
void addOrder();
void* loadOrder();
void writeOrder();
void* searchOrder(JELOVNIK* const);
int exitProgram(JELOVNIK*);

#endif //FUNCTIONS_H