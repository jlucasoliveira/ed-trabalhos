/**
*
*	RAM: 8GB
*	CPU: Intel i5-4210U CPU @ 1.70GHz × 2
*	n = 2000;
*	k = 10000
*	Tempo Bubble Sort: 98660018 (somatorio)
*	Tempo Select Sort: 58423896 (somatorio)
*	Tempo Insert Sort: 91518 (somatorio)
*	Tempo Insert Sort v2: 109318 (somatorio)
*	Tempo Merge Sort: 2548866 (somatorio)
*
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void bubble_sort(int* vet, int n)
{
	int i, j;

	for (j = n; j > 1; j--)
		for (i = 0; i < j-1; i++)
			if (vet[i] > vet[i+1])
			{
				int aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
			}
}

void select_sort(int* vet, int n)
{
	int i, j, k;

	for (j = 0; j < n; j++)
	{
		k = j;
		for (i = j + 1; i < n; i++)
			if (vet[k] > vet[i])
				k = i;
		int aux = vet[k];
		vet[k] = vet[j];
		vet[j] = aux;
	}
}

void insert_sort(int* vet, int n){
	int i, j;

	for (j = 1; j < n; j++)
		for (i = j - 1; i >= 0 && vet[i] > vet[i+1]; i--)
		{
			int aux = vet[i];
			vet[i] = vet[i+1];
			vet[i+1] = aux;
		}
}

void insert_sort_v2(int* vet, int n)
{
	int i, j;
	
	for (j = 1; j < n; j++)
	{
		int aux = vet[j];
		for (i = j - 1; i >= 0 && vet[i] > aux; i--)
			vet[i+1] = vet[i];
		vet[i+1] = aux;
	}
}

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
/*
int main()
{
	clock_t temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, start, end;
	int i, j, n = 2000, k = 10000;
	int *vet = (int*) malloc(n*sizeof(int));
	int *aux = (int*) malloc(n*sizeof(int));

	for (i = 0; i < k; i++)
	{
		// alterando valores do rand e preenchendo o vetor
		srand(clock());
		for (j = 0; j < n; j++)
			vet[j] = 1 + rand()%(2*n);

		// Bubble sort
		aux = vet;
		start = clock();
		bubble_sort(aux, n);
		end = clock();
		temp1+=(end-start);

		// Select sort
		aux = vet;
		start = clock();
		select_sort(aux, n);
		end = clock();
		temp2+=(end-start);

		// Insert sort
		aux = vet;
		start = clock();
		insert_sort(aux, n);
		end = clock();
		temp3+=(end-start);

		// Insert sort v2
		aux = vet;
		start = clock();
		insert_sort_v2(aux, n);
		end = clock();
		temp4+=(end-start);

		// Merge sort
		aux = vet;
		start = clock();
		merge_sort(aux, 0, n-1);
		end = clock();
		temp5+=(end-start);

	}

	printf("Bubble sort: %ld\n", temp1);
	printf("Select sort: %ld\n", temp2);
	printf("Insert sort: %ld\n", temp3);
	printf("Insert sort v2: %ld\n", temp4);
	printf("Merge sort: %ld\n", temp5);
}*/