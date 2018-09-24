#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int copia(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int merge(int* vet, int ini, int p1, int fim)
{
	int n1 = p1 - ini + 1;
	int n2 = fim - p1;
	int l[n1+1], r[n2+1];

	for (int i = 0; i < n1; i++) l[i] = vet[ini+i];
	for (int i = 0; i < n2; i++) r[i] = vet[p1+i];

	int i = 0, j = 0;
	l[n1] = INT_MAX, r[n2] = INT_MAX;

	for (int k = ini; k <= fim; k++)
	{
		if (l[i] < r[j])
		{
			vet[k] = l[i];
			i++;
		}
		else if (r[j] < l[i])
		{
			vet[k] = r[j];
			j++;
		}
	}
}

void merge_sort(int* vet, int ini, int fim)
{
	if (ini < fim || fim - ini > 1)
	{
		int p1 = ini + ((fim-ini)/3);
		int p2 = ini + 2*((fim-ini)/3) + 1;

		merge_sort(vet, ini, p1);
		merge_sort(vet, p1, p2);
		merge_sort(vet, p2, fim);

		merge(vet, ini, p1, p2, fim);
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