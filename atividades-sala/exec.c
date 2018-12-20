#include "fila.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Atividade-7/pilha.h"

int josephus(Fila* f, int m)
{
	int i = 1;
	while (f->ultimo > 0)
	{
		int aux = desenfilerar(f);
		if (i != m) enfilerar(f, aux);
		else
		{
			//printf("Pessoa %d saiu.\n", aux);
			i = 0;
		}
		i++;
	}
	int lider =  desenfilerar(f);
	//liberar_fila(f);
}

void inverte_frase(char* frase)
{
	Pilha* p = p_criar(strlen(frase));
	for (int i = 0; i < strlen(frase); i++)
		if (frase[i] == ' ' || frase[i] == '\n' || frase[i] == '\0')
		{
			while (p->topo > -1)
				printf("%c", desempilhar(p));
			printf("%c", frase[i]);
		}
		else empilhar(p, frase[i]);
}

int josephus_fabio(Fila* f, int m)
{
	while (f->ultimo > 0)
	{
		for (int j = 1; j < m; j++)
		{
			int aux = desenfilerar(f);
			enfilerar(f, aux);
		}
		//printf("Pessoa %d saiu\n", desenfilerar(f));
	}
	int lider = desenfilerar(f);
	//printf("Pessoa %d é lider\n", lider);
	//return lider;
	//liberar_fila(f);
}

int main()
{
	/*
	char frase[300];
	int qtde_pessoas, modulo;

	printf("Digite a frase a ser invertida:\n");
	fgets(frase, sizeof(frase), stdin);
	printf("Quatidade de pessoas: ");
	scanf("%d", &qtde_pessoas);
	printf("Módulo de escolha: ");
	scanf("%d", &modulo);

	inverte_frase(frase);
	
	printf("Fabio %d.\n", josephus_fabio(7, 10));
	printf("\n");
	printf("meu %d.\n", josephus(7, 10));
	
	*/
	clock_t ini, fim, meu = 0, fabio = 0;
	int n, m;
	for (int k = 0; k < 100; k++)
	{
		Fila* f = criar_fila(5000);
		n = (1 + rand())%490;
		m = (1 + rand())%40;

		for (int j = 1; j <= n; j++)
			enfilerar(f, j);

		ini = clock();
		josephus(f, m);
		fim = clock();
		meu+=(fim - ini);

		ini = clock();
		josephus_fabio(f, m);
		fim = clock();
		fabio+=(fim - ini);
	}

	printf("Meu: %ld\nFabio: %ld\n", meu/CLOCKS_PER_SEC, fabio/CLOCKS_PER_SEC);
	
	return 0;
}