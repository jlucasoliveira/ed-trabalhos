#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "lista_encadeada.h"
//#include "lista_dupla_encadeada.h"
#include "lista_circular.h"

void get_from_file(LstC* l)
{
	FILE* f = fopen("alunos.txt", "r");
	Aluno a;
	if (f == NULL) return;

	while (fscanf(f, "%d\n", &a.mat) > 0)
	{
		fgets(a.nome, sizeof(a.nome), f);
		a.nome[strlen(a.nome)-1] = 0;
		lc_inserir(l, a);
	}

	fclose(f);
}

void print_list(LstC* l)
{
	No* atual = l->inicio;

	printf("\n");
	/*
	while (atual != NULL)
	{
		printf("%s - %d\n", atual->info.nome, atual->info.mat);
		atual = atual->prox;
	}
	*/

	do
	{
		printf("%s - %d\n", atual->info.nome, atual->info.mat);
		atual = atual->prox;
	}while(atual != l->inicio);

	printf("\n");
}


int main()
{	
	LstC* l = lc_criar();
	get_from_file(l);

	Aluno a;
	a = lc_buscar(l, 2346453);
	printf("%s - %d\n", a.nome, a.mat);
	lc_remover(l, 2346453);
	print_list(l);
	lc_liberar(l);

	return 0;
}