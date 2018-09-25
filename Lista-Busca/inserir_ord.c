#include <stdio.h>
#include <stdlib.h>

int inserir_ord(int* vet, int n, int item)
{
	int i;
	for (i = n/2-1; vet[i] > item; i--)
		vet[i] = vet[i-1];
	vet[i] = item;
	return i;
}

int main()
{
	int n = 100;
	int* vet = (int*) malloc(n*sizeof(int));

	for (int i = 0; i < n/2; i++)
		vet[i] = i+1;

	inserir_ord(vet, n, 5);

	for (int i = 0; i < n; i++)
		printf("%d ", vet[i]);	

	return 0;
}