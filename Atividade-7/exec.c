#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* itens;
	int tam;
	int topo;
} Pilha;

Pilha* p_criar(int tam)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->tam = tam;
	p->topo = -1;
	p->itens = (char*) malloc(sizeof(char)*tam);
	return p;
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

int checar_formula(Pilha* p, char* formula)
{
	int i = 0;
	for(; i < strlen(formula); i++)
	{
		if (formula[i] == '(' || formula[i] == '[' || formula[i] == '{')
			empilhar(p, formula[i]);

		if (formula[i] == ')' || formula[i] == ']' || formula[i] == '}')
			if ((formula[i] == ')' && topo(p) == '(') || (formula[i] == ']' && topo(p) == '[') || (formula[i] == '}' && topo(p) == '{'))
				desempilhar(p);
			else return 0; 
	}

	if (p->topo >= 0) return 0;

	return 1;
}

int main()
{
	int tam = 100;
	char formula[200];

	Pilha* p = p_criar(tam);
	printf("Formula: ");
	fgets(formula, sizeof(formula), stdin);

	printf("%d\n", checar_formula(p, formula));
	return 0;
}