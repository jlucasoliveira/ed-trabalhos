#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "lista_encadeada.h"
#include "lista_circular.h"

LstC* get_from_file(LstC* l)
{
	FILE* f = fopen("alunos.txt", "r");
	Aluno a;
	if (f == NULL) return l;

	while (fscanf(f, "%d\n", &a.mat) > 0)
	{
		fgets(a.nome, sizeof(a.nome), f);
		a.nome[strlen(a.nome)-1] = 0;
		lc_inserir(l, a);
	}

	fclose(f);
	return l;
}

void print_list (LstC* l)
{
	No* atual = l->inicio;

	printf("\n");
	do
	{
		printf("%s - %d\n", atual->info.nome, atual->info.mat);
		atual = atual->prox;
	}while (atual != l->inicio);
	printf("\n");
}


int main()
{
	Aluno a; 
	strcpy(a.nome, "ZEZITO");
	a.mat = 32542351;

	/* LISTA SIMPLISMENTE ENCADEADA
	LstEc* l = le_criar();
	l = get_from_file(l);
	print_list(l);
	Aluno a;
	a = le_buscar(l, 352);
	printf("%s - %d\n", a.nome, a.mat);
	a.nome = "ZEZITO";
	a.mat = 141242;
	le_inserir(l, a);
	le_remover(l, 63463426);
	print_list(l);
	le_liberar(l);

	-- LISTA DUPLAMENTE ENCADEADA
	LstEd* l = ld_criar();
	//l = get_from_file(l);
	for (int i = 0; i < 15; i++)
	{
		a.mat+=1;
		ld_inserir(l, a);
	}
	print_list(l);
	a = ld_buscar(l, a.mat-14);
	printf("\n%s - %d\n", a.nome, a.mat);
	ld_remover(l, 32542356);
	print_list(l);
	ld_liberar(l);
	*/

	LstC* l = lc_criar();
	l = get_from_file(l);
	print_list(l);

	lc_inserir(l, a);
	print_list(l);

	a = lc_buscar(l, 5235235);
	printf("\n%s - %d\n", a.nome, a.mat);

	lc_remover(l, 5235235);
	print_list(l);

	lc_liberar(l);

	return 0;
}