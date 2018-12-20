#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int* itens;
	int TAM_MAX, n;
}Heap;


void mostrar_em_vetor(Heap* hp)
{
	for (int i = 1; i <= hp->n; i++)
		printf("[%d] ", hp->itens[i]);
	printf("\n");
}

Heap* hp_criar(int tam)
{
	Heap* hp = (Heap*) malloc(sizeof(Heap));
	hp->TAM_MAX = tam;
	hp->n = 0;
	hp->itens = (int*) malloc((tam+1)*sizeof(int));
	return hp;
}

int hp_filho_menor(Heap* hp, int pai)
{
	int esq = pai*2;
	int dir = esq + 1;

	if (dir <= hp->n)
		if (dir > hp->n || hp->itens[dir] > hp->itens[esq]) return esq;
		else return dir;
	return -1;
}

void hp_subir(Heap* hp, int posicao)
{
	int pai = posicao/2;
	if (pai >= 1)
		if (hp->itens[pai] > hp->itens[posicao])
		{
			int aux = hp->itens[pai];
			hp->itens[pai] = hp->itens[posicao];
			hp->itens[posicao] = aux;
			hp_subir(hp, pai);
		}
}

void hp_descer(Heap* hp, int posicao)
{
	int menor = hp_filho_menor(hp, posicao);
	if (menor != -1)
		if (hp->itens[menor] < hp->itens[posicao])
		{
			int aux = hp->itens[menor];
			hp->itens[menor] = hp->itens[posicao];
			hp->itens[posicao] = aux;
			hp_descer(hp, menor);
		}
}

void hp_add(Heap* hp, int valor)
{
	hp->itens[++hp->n] = valor;
	int pai = hp->n/2;
	if (pai >= 1 && valor < hp->itens[pai])
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
		if (chave < aux) hp_subir(hp, posicao);
		else hp_descer(hp, posicao);
	}
}

int verificar_heap_minimo(int* vetor, int n)
{
	for (int i = n; i >= 2; i--)
	{
		if (vetor[i] < vetor[i/2])
			return 0;
	}
	return 1;
}

int main()
{
	Heap* hp = hp_criar(200);
	hp_add(hp, 10);
	hp_add(hp, 30);
	hp_add(hp, 5);
	hp_add(hp, 2);
	hp_add(hp, 50);
	hp_add(hp, 1);
	mostrar_em_vetor(hp);
	return 0;
}