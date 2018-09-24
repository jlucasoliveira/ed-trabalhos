#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int* itens;
	int n;
	int TAM_MAX; 
} ListaSeq;

ListaSeq* ls_criar(int tam)
{
	ListaSeq* lista = (ListaSeq*) malloc(sizeof(ListaSeq));
	lista->n = 0;
	lista->TAM_MAX = tam;
	lista->itens = (int*) malloc(tam*sizeof(int));
	return lista;
}

void ls_burst_remove(ListaSeq* l, int i, int k)
{
	if (k > l->n || i > l->n || i > k || i < 0 || k < 0) return;
	l->n-=k;
	for (int j = i; j < l->n; j++)
		l->itens[j] = l->itens[j+k];
}

int main()
{
	ListaSeq* t = ls_criar(100);
	t->n = 50;

	for (int k = 0; k < t->n; k++)
		t->itens[k] = 1 + rand()%(2000);

	for (int k = 0; k < t->n; k++)
		printf("%d ", t->itens[k]);

	ls_burst_remove(t, 6, 15);
	
	printf("\n");
	  for (int k = 0; k < t->n; k++)
		printf("%d ", t->itens[k]);


	return 0;
}