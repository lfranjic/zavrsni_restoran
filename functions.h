#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "header.h"

int izbornik();
void createFile();
void addOrder(JELOVNIK*);
void* loadOrder(JELOVNIK* const);
void writeOrder(JELOVNIK* const);
void* searchOrder(JELOVNIK* const);
int exitProgram(JELOVNIK*);

#endif //FUNCTIONS_H