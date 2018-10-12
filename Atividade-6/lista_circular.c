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
	struct no* ant;
} No;

typedef struct 
{
	No* inicio;	
} LstC;

LstC* lc_criar()
{
	LstC* lista = (LstC*) malloc(sizeof(LstC));
	lista->inicio = NULL;
	return lista;
}

No* lc_buscar_pont(LstC* l, int mat)
{
	No* atual = l->inicio;

	do
	{
		if (atual->info.mat == mat)
			return atual;
		atual = atual->prox;
	}while (atual != l->inicio);

	return NULL;
}

Aluno lc_buscar(LstC* l, int mat)
{
	No* aluno = lc_buscar_pont(l, mat);
	if (aluno != NULL) return aluno->info;

	Aluno erno;
	strcpy(erno.nome, "ERROR");
	erno.mat = -1;
	return erno;
}

void lc_inserir(LstC* l, Aluno a)
{
	No* item = (No*) malloc(sizeof(No));
	item->info = a;
	if (l->inicio == NULL)
	{
		item->prox = item;
		item->ant = item;
	}
	else
	{
		item->prox = l->inicio;
		item->ant = l->inicio->ant;
		l->inicio->ant->prox = item;
		l->inicio->ant = item;
	}
	l->inicio = item;
}

int lc_remover(LstC* l, int mat)
{
	No* item = lc_buscar_pont(l, mat);
	if (item != NULL)
	{
		if (item->prox == item->ant) l->inicio = NULL;
		else 
		{
			item->prox->ant = item->ant;
			item->ant->prox = item->prox;
		}
			free(item);
			return 1;
	}

	return 0;
}

void lc_liberar(LstC* l)
{
	No* atual = l->inicio;
	No* aux = NULL;

	do
	{
		aux = atual;
		atual = atual->prox;
		free(aux);
	}while (atual != l->inicio);

	free(l);
}