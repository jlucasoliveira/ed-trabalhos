#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char nome[200];
	int mat;
} Aluno;

typedef struct no
{
	int info;
	struct no* prox;
	struct no* ant;
} No;

typedef struct
{
	No* inicio;
} LstEd;

LstEd* ld_criar()
{
	LstEd* l = (LstEd*) malloc(sizeof(LstEd));
	l->inicio = NULL;
	return l;
}

No* ld_buscar_pont(LstEd* l, int mat)
{
	No* atual = l->inicio;

	while (atual != NULL)
	{
		if (atual->info == mat)
			return atual;
		atual = atual->prox;
	}
	return NULL;
}

int ld_buscar(LstEd* l, int mat)
{
	No* aluno = ld_buscar_pont(l, mat);
	if (aluno != NULL)
		return aluno->info;
	return -1;
}

void ld_inserir(LstEd* l, int a)
{
	No* item = (No*) malloc(sizeof(No));
	item->info = a;
	item->ant = NULL;
	item->prox = l->inicio;
	if (l->inicio != NULL) l->inicio->ant = item;
	l->inicio = item;
}

int ld_remover(LstEd* l, int mat)
{
	No* atual = ld_buscar_pont(l, mat);

	if (atual != NULL)
	{
		if (atual->prox != NULL) atual->prox->ant = atual->ant;
		if (atual->ant != NULL) atual->ant->prox = atual->prox;
		else l->inicio = atual->prox;
		free(atual);
		return 1;
	}

	return 0;
}

void ld_liberar(LstEd* l)
{
	No* atual = l->inicio;
	No* aux = NULL;

	while (atual != NULL)
	{
		aux = atual;
		atual = atual->prox;
		free(aux);
	}

	free(l);
}