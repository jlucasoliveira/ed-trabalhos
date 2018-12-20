#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.h"

void visitar(No* raiz)
{
	if (raiz != NULL)
		printf(" [%d] ", raiz->info);
}

void pre_ordem(No* raiz)
{
	if (raiz == NULL) return;
	visitar(raiz);
	printf("\n");
	pre_ordem(raiz->esq);
	pre_ordem(raiz->dir);
}

int abb_qtde_filhos(No* raiz)
{
	if (raiz->esq == raiz->dir)
		return 0;
	else if (raiz->dir != NULL && raiz->esq != NULL)
		return 2;
	return 1;
}

No* abb_sucessor(No* raiz)
{
	if (raiz->esq == NULL) return raiz;
	return abb_sucessor(raiz->esq);
}

No* abb_busca(No* raiz, int chave)
{
	if (raiz == NULL) return NULL;
	else if (raiz->info == chave) return raiz;
	else if (raiz->info > chave) return abb_busca(raiz->esq, chave);
	else return abb_busca(raiz->dir, chave);
}

No* abb_add(No* raiz, int chave)
{
	if (raiz == NULL)
	{
		No* no = (No*) malloc(sizeof(No));
		no->dir = no->esq = no->pai = NULL;
		no->info = chave;
		return no;
	}
	else if (raiz->info > chave)
	{
		raiz->esq = abb_add(raiz->esq, chave);
		raiz->esq->pai = raiz;
	}
	else
	{
		raiz->dir = abb_add(raiz->dir, chave);
		raiz->dir->pai = raiz;
	}
	return raiz;
}

void abb_remover(No* raiz, int chave)
{
	No* no = abb_busca(raiz, chave);
	if (raiz != NULL)
	{
		if (abb_qtde_filhos(no) == 0)
		{
			if (no->pai->esq == no) no->pai->esq = NULL;
			else no->pai->dir = NULL;
			free(no);
		}
		else if (abb_qtde_filhos(no) == 1)
		{
			No* filho = no->esq; 
			if (filho == NULL) filho = no->dir;
			if (no->pai->esq == no) no->pai->esq = filho;
			else no->pai->dir = filho;
			free(no);	
		}
		else
		{
			No* sucessor = abb_sucessor(no->dir);
			int bkp_info = sucessor->info;
			abb_remover(no->dir, sucessor->info);
			no->info = bkp_info;
		}
	}
}
