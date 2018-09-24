/**
*
*	RAM: 8GB
*	CPU: Intel i5-4210U CPU @ 1.70GHz × 2
*	n = 10000;
*	k = 10000
*	Merge Sort: 20.724668s
*	Quick Sort: 14.818927s
*
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int* vet, int ini, int meio, int fim)
{
	int n1 = meio - ini + 1;
	int n2 = fim - meio;
	int part_l[n1+1], part_r[n2+1];
	part_l[n1] = part_r[n2] = INT_MAX;

	for (int i = 0; i < n1; i++) part_l[i] = vet[ini+i];
	for (int i = 0; i < n2; i++) part_r[i] = vet[meio+1+i];
	int i = 0, j = 0, k;

	for (k = ini; k <= fim; k++)
	{
		if (part_l[i] < part_r[j])
		{
			vet[k] = part_l[i];
			i++;
		}
		else
		{
			vet[k] = part_r[j];
			j++;
		}
	}
}

void merge_sort(int* vet, int ini, int fim)
{
	if (ini < fim)
	{
		int meio = (ini + fim)/2;
		merge_sort(vet, ini, meio);
		merge_sort(vet, meio+1, fim);
		merge(vet, ini, meio, fim);
	}
}

void troca(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

/*

int particiona(int* vet, int ini, int fim)
{
	int pivo = vet[ini], i = ini, j, aux;
	for (j = ini + 1; j < fim; j++)
		if (vet[j] <= pivo)
		{
			i++;
			troca(&vet[i], &vet[j]);
		}
	troca(&vet[ini], &vet[i+1]);
	return i+1;
}

void quick_sort(int* vet, int ini, int fim)
{
	if (ini < fim)
	{
		int q = particiona(vet, ini, fim);
		printf("\npivo: %d\n", q);
		quick_sort(vet, ini, q-1);
		quick_sort(vet, q+1, fim);
	}
}

*/


void quick_sort(int* vet, int ini, int fim)
{
	int pivo, aux, i, j, meio;
	i = ini, j = fim;
	meio = (i+j)/2;
	pivo = vet[meio];

	do
	{
		while (vet[i] < pivo) i++;
		while (vet[j] > pivo) j--;

		if (i <= j)
		{
			troca(&vet[i], &vet[j]);
			i++;
			j--;
		}

	}while (j > i);

	if (ini < j) quick_sort(vet, ini, j);
	if (i < fim) quick_sort(vet, i, fim);
}

void copia(int* vet, int* aux, int n)
{
	for (int i = 0; i < n; i++)
		aux[i] = vet[i];
}

int main(){
	clock_t tempo_merge = 0, tempo_quick = 0, start, end;
	int i, j, k = 10000, n = 10000;
	int *vet = (int*) malloc(n*sizeof(int));
	int *aux = (int*) malloc(n*sizeof(int));

	for (i = 0; i < k; i++)
	{
		srand(clock());
		for (j = 0; j < n; j++)
			vet[j] = 1 + rand()%(2*n);

		copia(vet, aux, n);
		start = clock();
		merge_sort(aux, 0, n-1);
		end = clock();
		tempo_merge+=(end-start);

		copia(vet, aux, n);
		start = clock();
		quick_sort(aux, 0, n-1);
		end = clock();
		tempo_quick+=(end-start);

	}

	printf("Merge Sort: %fs\n", tempo_merge/(double) CLOCKS_PER_SEC);
	printf("Quick Sort: %fs\n", tempo_quick/(double) CLOCKS_PER_SEC);

	return 0;
}