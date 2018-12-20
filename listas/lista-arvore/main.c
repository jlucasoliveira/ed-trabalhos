#include <stdio.h>
#include <stdlib.h>


int ab_folhas(No* raiz)
{
	if (raiz == NULL) return 0;
	else if (raiz->esq == raiz->dir) return 1;
	return ab_folhas(raiz->esq) + ab_folhas(raiz->dir);
}

int ab_compara_arvore(No* raiz1, No* raiz2)
{
	if (raiz1 == NULL && raiz1 == NULL) return 1;
	else if (raiz1 == NULL || raiz2 == NULL) return 0;
	return ab_compara_arvore(raiz1->esq, raiz2->esq) &&
		ab_compara_arvore(raiz1->dir, raiz2->dir) &&
		raiz1->info == raiz2->info;
}

int ab_altura(No* raiz)
{
	if (raiz == NULL) return 0;
	else if (raiz->esq == raiz->dir) return 1;
	else 
	{
		int esq = ab_altura(raiz->esq);
		int dir = ab_altura(raiz->dir);
		if (esq > dir) return esq+1;
		else return dir+1;
	}
}

int ab_nos(No* raiz)
{
	if (raiz == NULL) return 0;
	else if (raiz->dir == raiz->esq) return 1;
	return ab_nos(raiz->dir) + ab_nos(raiz->esq) + 1;
}

int ab_soma_nos(No* raiz)
{
	if (raiz == NULL) return 0;
	else if (raiz->esq == raiz->dir) return raiz->info;
	return ab_soma_nos(raiz->esq) + ab_soma_nos(raiz->dir) + raiz->info;
}

int abb_max(No* raiz)
{
	if (raiz->dir == NULL) raiz->info;
	else return abb_max(raiz->dir);
}

int abb_min(No* raiz)
{
	if (raiz->esq == NULL) return raiz->info;
	else return abb_min(raiz->esq);
}