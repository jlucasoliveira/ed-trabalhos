#include <stdio.h>
#include <stdlib.h>
#include "../Lista-Sequencial/lista_sequencial.c"

int busca_sequencial_par_impar(int* vet, int n, int chave)
{
	for(int i = chave%2; i < n; i+=2)
		if (vet[i] == chave)
			return i;
	return -1;
}

void ordenacaoABC(int* vet, int n, int a, int b, int c)
{
	int count[c-a+1], valores[3] = {a, b, c}, j = 0;
	for (int i = 0; i < c-a+1; i++) count[i] = 0;
	for (int i = 0; i < n; i++) count[vet[i]-a]++;
	for (int i = 0; i < 3; i++)
		while(count[valores[i]-a] > 0){
			vet[j] = valores[i];
			j++;
			count[valores[i]-a]--;
		}
}

void imprima_ordenado(int* vet, int n)
{
	int i, k = 0, j = 1;
	for (i = 0; i < n; i++)
		if (vet[k] < vet[j]){
			printf("%d ", vet[k]);
			k+=2;
		}
		else{
			printf("%d ", vet[j]);
			j+=2;
		}
}

ListaSeq* ls_intercecao(ListaSeq* l1, ListaSeq* l2)
{
	int menor;
	if (l1->n > l2->n) menor = l2->n;
	else menor = l1->n;

	ListaSeq* intercecao = ls_criar(menor);
	for (int i = 0; i < l1->n; i++)
		for (int j = 0; j < l2->n; j++)
			if (l1->itens[i].matricula == l2->itens[j].matricula)
				ls_inserir(intercecao, l1->itens[i]);

	return intercecao;
}

int main()
{

	return 0;
}