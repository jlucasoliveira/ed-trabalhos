/**
*
*	RAM: 8GB
*	CPU: Intel i5-4210U CPU @ 1.70GHz × 2
*	n = 1000000;
*	k = 10000
*	Tempo Algoritmo 1: 25078204 (somatorio)
*	Tempo Algoritmo 2: 14224075 (somatorio)
*
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int* vet, int n, int chave){
	int i;
	for (i = 0; i < n; i++)
		if (chave == vet[i])
			return i;
	return -1;
}

int busca_sequencial2(int* vet, int n, int chave){
	int i, j;
	for (i = 0, j = n-1; i <= j; i++, j--){
		if (chave == vet[i])
			return i;
		if (chave == vet[j])
			return j;
	}
	return -1;
}

int main(){
	clock_t temp1 = 0, temp2 = 0, start, end;
	int i, chave, n = 1000000000, k = 10000;
	int *vet = (int*) malloc(n*sizeof(int));
	srand((unsigned) time(NULL));

	// preenchendo o vetor com numeros aleatorios, com limite de 2 * tam_vetor
	for (i = 0; i < n; i++)
		vet[i] = 1 + rand()%(2*n);

	for (i = 0; i < k; i++){
		chave = 1 + rand()%(2*n);
		start = clock();
		busca_sequencial(vet, n, chave);
		end = clock();
		temp1+= (end-start);
		start = clock();
		busca_sequencial2(vet, n, chave);
		end = clock();
		temp2+= (end-start);
	}

	printf("Alg 1: %ld\n", temp1);
	printf("Alg 2: %ld\n", temp2);

	return 0;
}