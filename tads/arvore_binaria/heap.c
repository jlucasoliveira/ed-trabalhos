#include "heap.h"
#include <stdlib.h>

Heap* hp_criar(int tam)
{
	Heap* hp = (Heap*) malloc(sizeof(Heap));
	hp->TAM_MAX = tam;
	hp->n = 0;
	hp->itens = (int*) malloc((tam+1)*sizeof(int));
	return hp;
}

int hp_maior_filho(Heap* hp, int pai)
{
	int esq = 2*pai;
	int dir = esq + 1;

	if (esq <= hp->n)
		if (dir > hp->n || hp->itens[dir] < hp->itens[esq]) return esq;
		else if (hp->itens[dir] > hp->itens[esq]) return dir;
	return -1;
}
/*
int verificar_heap_maximo(int* vetor, int n)
{
	Heap* hp;
	hp->itens = vetor;
	hp->n = n;
	for (int i = 1; i <= n; i++)
	{
		int maior = hp_maior_filho(hp, i);
		if (maior != -1 && vetor[i] < vetor[maior])
			return 0;
	}
	return 1;
}
*/
int verificar_heap_maximo(int* vetor, int n)
{
	for (int i = n; i >= 2; i--)
	{
		if (vetor[i/2] < vetor[i])
			return 0;
	}
	return 1;
}

void hp_subir(Heap* hp, int posicao)
{
	int pai = posicao/2;
	if (pai >= 1)
		if (hp->itens[pai] < hp->itens[posicao])
		{
			int aux = hp->itens[pai];
			hp->itens[pai] = hp->itens[posicao];
			hp->itens[posicao] = aux;
			hp_subir(hp, pai);
		}
}

void hp_descer(Heap* hp, int posicao)
{
	int maior = hp_maior_filho(hp, posicao);
	if (maior != -1)
		if (hp->itens[maior] > hp->itens[posicao])
		{
			int aux = hp->itens[maior];
			hp->itens[maior] = hp->itens[posicao];
			hp->itens[posicao] = aux;
			hp_descer(hp, maior);
		}
}

void hp_add(Heap* hp, int chave)
{
	hp->itens[++hp->n] = chave;
	if (chave > hp->itens[hp->n/2])
		hp_subir(hp, hp->n);
}

int hp_remover(Heap* hp)
{
	if (hp->n > 0)
	{
		int aux = hp->itens[1];
		hp->itens[1] = hp->itens[hp->n--];
		hp_descer(hp, 1);
		return aux;
	}
}

void hp_atualizar(Heap* hp, int posicao, int chave)
{
	if (posicao > 0)
	{
		int aux = hp->itens[posicao];
		hp->itens[posicao] = chave;
		if (chave < aux) hp_descer(hp, posicao);
		else hp_subir(hp, posicao);
	}
}

void hp_liberar(Heap* hp)
{
	free(hp->itens);
	free(hp);
}
