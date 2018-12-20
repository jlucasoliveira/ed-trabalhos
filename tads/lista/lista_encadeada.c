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
} No;

typedef struct
{
	No* inicio;
} LstEc;

LstEc* le_criar()
{
	LstEc* lista = (LstEc*) malloc(sizeof(LstEc));
	lista->inicio = NULL;
	return lista;
}

void le_inserir(LstEc* l, int a)
{
	No* item = (No*) malloc(sizeof(No));
	item->info = a;
	item->prox = l->inicio;
	l->inicio = item;
}

int le_remover(LstEc* l, int mat)
{
	No* atual = l->inicio;
	No* ant = NULL;

	while(atual != NULL)
	{
		if (atual->info == mat)
		{
			if (ant != NULL)
				ant->prox = atual->prox;
			else
				l->inicio = atual->prox;
			
			free(atual);
			return 1;
		}

		ant = atual;
		atual = atual->prox;
	}
	return 0;
}

No* le_buscar_pont(LstEc* l, int mat)
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

int le_buscar(LstEc* l, int mat)
{	
	No* atual = le_buscar_pont(l, mat);
	if (atual != NULL) return atual->info;

	int erno = 1;
	return erno;
}

void le_liberar(LstEc* l)
{
	No* atual = l->inicio;

	while (atual != NULL)
	{
		No* aux = atual;
		atual = atual->prox;
		free(aux);
	}

	free(l);
}