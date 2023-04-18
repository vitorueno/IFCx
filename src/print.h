#ifndef __PRINT_H__
#define __PRINT_H__

#include "types.h"
#include "lib.h"

int numLen(int numero);
int pow(int base, int expoente);
int printString(const char *message);
int printNum(int numero);
int printNumAt(int numero, int linha, int coluna);
int printStringAt(const char *message, int linha, int coluna);

#endif // __PRINT_H__