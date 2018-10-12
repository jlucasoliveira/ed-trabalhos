#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char nome[200];
	int mat;
} Aluno;

typedef struct no
{
	Aluno info;
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

void le_inserir(LstEc* l, Aluno a)
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
		if (atual->info.mat == mat)
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

Aluno le_buscar(LstEc* l, int mat)
{
	No* atual = l->inicio;

	while (atual != NULL)
	{
		if (atual->info.mat == mat)
			return atual->info;
		atual = atual->prox;
	}

	Aluno erno;
	strcpy(erno.nome, "ERROR");
	erno.mat = -1;

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