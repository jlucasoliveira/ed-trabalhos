#include <stdio.h>
#include <stdlib.h>
#include "tads/arvore_binaria/heap.h"

void mostrar_em_vetor(Heap* hp)
{
	for (int i = 1; i <= hp->n; i++)
		printf("[%d] ", hp->itens[i]);
	printf("\n");
}

int main()
{
	Heap* hp = hp_criar(50);
	for (int i = 1; i <= 20; i+=2)
	{
		int a = 1+rand()%100;
		//printf("[%d] ", a);
		hp_add(hp, a);
	}
	printf("\n");
	mostrar_em_vetor(hp);
	hp->itens[++hp->n] = 5000;
	mostrar_em_vetor(hp);
	printf("%d\n", verificar_heap_maximo(hp->itens, hp->n));
	return 0;
}