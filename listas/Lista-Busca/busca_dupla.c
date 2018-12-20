#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busca_dupla(int* vet, int n, int chave)
{
	for (int i = 0, j = n-1; i < j; i++, j--)
		if (vet[i] == chave)
			return i;
		else if (vet[j] == chave)
			return j;
	return -1;
}

int main()
{
	int n = 1000, chave;
	int* vet = (int*) malloc(n*sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		vet[i] = 1 + rand()%(2*n);

	chave = 1 + rand()%(2*n);
	printf("%d\n", chave);

	int res = busca_dupla(vet, n, chave);
	if (res > -1)
		printf("%d\n", vet[res]);
	else printf("nao tem:(\n");

	return 0;
}