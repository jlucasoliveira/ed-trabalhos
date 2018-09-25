#include <stdio.h>

void ls_troca(ListaSeq* l, int i, int j)
{
	Aluno a = l->itens[i];
	ls_remover(l, a.matricula);
	ls_inserir_index(l, a, j);
}