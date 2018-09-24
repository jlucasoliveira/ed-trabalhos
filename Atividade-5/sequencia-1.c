#include <stdio.h>

void copia(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}