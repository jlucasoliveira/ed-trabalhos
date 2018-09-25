#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../Atividade-2/ordenacao.c"

int copia(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int merge3(int* vet, int ini, int p1, int p2, int fim)
{
	merge(vet, ini, p1, p2);
	merge(vet, ini, p2, fim);
}

void merge_sort3(int* vet, int ini, int fim)
{
	if (ini < fim || fim - ini > 1)
	{
		int p1 = (fim-ini)/3;
		int p2 = fim-p1;

		merge_sort3(vet, ini, p1);
		merge_sort3(vet, p1+1, p2);
		merge_sort3(vet, p2+1, fim);

		merge3(vet, ini, p1, p2, fim);
	}
}


int main()
{
	int n = 10, k = 10;
	int* vet = (int*) malloc(n*sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		vet[i] = 1 + rand()%(2*n);
		printf("%d ", vet[i]);
	}

	printf("\n");
	merge_sort(vet, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d ", vet[i]);

	return 0;
}