#include "pilha.h"
#include <stdlib.h>

Pilha* p_criar(int tam)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->tam = tam;
	p->topo = -1;
	p->itens = (char*) malloc(sizeof(char)*tam);
	return p;
}

int tamanho_pilha(Pilha* p)
{
	return p->topo+1;
}

void empilhar(Pilha* p, char item)
{
	if (p->topo < p->tam -1)
		p->itens[++p->topo] = item;
}

char desempilhar(Pilha* p)
{
	if (p->topo >= 0) return p->itens[p->topo--];
}

char topo(Pilha* p)
{
	if (p->topo >= 0) return p->itens[p->topo];
}
