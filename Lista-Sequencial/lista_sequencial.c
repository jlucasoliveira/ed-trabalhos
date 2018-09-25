#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* nome;
	int matricula;
}Aluno;

typedef struct {
	Aluno* itens;
	int n;
	int TAM_MAX;
}ListaSeq;


ListaSeq* ls_criar(int tam){
	ListaSeq* l = (ListaSeq*) malloc(sizeof(ListaSeq));
	
	l->itens = (Aluno*) malloc(tam*sizeof(Aluno));
	l->n = 0;
	l->TAM_MAX = tam;

	if (l == 0) return NULL;
	return l;
}

int ls_inserir(ListaSeq* l, Aluno a)
{
	if (l->n >= l->TAM_MAX)
	{
		Aluno* temp = (Aluno*) malloc(2*l->n*sizeof(Aluno));
		for (int i = 0; i < l->n; i++)
			temp[i] = l->itens[i];
		free(l->itens);
		l->itens = temp;
	}

	l->itens[l->n] = a;
	l->n++;
	return l->n-1;
}

int ls_inserir_index(ListaSeq* l, Aluno a, int index)
{
	if (l->n >= l->TAM_MAX)
	{
		Aluno* temp = (Aluno*) malloc(2*l->n*sizeof(Aluno));
		for (int i = 0; i < l->n; i++)
			temp[i] = l->itens[i];
		free(l->itens);
		l->itens = temp;
	}

	for (int i = l->n-1; i > index; i--)
		l->itens[i] = l->itens[i-1];
	l->itens[index] = a;
	l->n++;
	return l->n;
}
