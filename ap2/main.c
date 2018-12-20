#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tads/lista/lista_dupla_encadeada.h"


void imprime_listasE(LstEd* l)
{
	No* atual = l->inicio;

	while (atual != NULL)
	{
		printf("[%d], ", atual->info);
		atual = atual->prox;
	}
}
/* FUNCIONA
void questao1(LstEc* l)
{
	No* ant_menor = NULL;
	No* menor = l->inicio;
	No* atual = l->inicio;

	while (atual != NULL)
	{
		if(atual->prox != NULL && atual->prox->info < menor->info)
		{
			menor = atual->prox;
			ant_menor = atual;
		}
		atual = atual->prox;
	}
	ant_menor->prox = menor->prox;
	menor->prox = l->inicio;
	l->inicio = menor;
}
*/


void questao2(LstEd* l)
{
	No aux;
	No* atual = l->inicio;

	while (atual != NULL)
	{
		aux = *atual;
		atual->prox = aux.ant;
		atual->ant = aux.prox;
		if (aux.prox == NULL) l->inicio = atual;
		atual = aux.prox;
	}
}


/*
int palindromo(char* text)
{
	//char text[strlen(texto)];
	int i = 0, j, tam;
	//strcpy(texto, text);
	
	for (i = 0; i < strlen(text); i++)
		if (text[i] == ' ' || text[i] == '-')
		{
			j = i;
			printf("%ld\n", strlen(text));
			while (j < strlen(text)-1)
			{
				text[j] = text[j+1];
				j++;
			}
			//text[j] = '\0';
		}
	
	Pilha* p = p_criar(strlen(text));
	tam = strlen(text)/2;
	for (i = 0; i < strlen(text); i++)
	{
		if ((strlen(text)%2==0 && i <= tam) || (strlen(text)%2!=0 && i < tam))
			empilhar(p, text[i]);
		if (i > tam && desempilhar(p) != text[i]) return 0;
	}

	if (tamanho_pilha(p) > 0) return 0;
	return 1;
}

void imprime_sequencia(int n, int m)
{
	Fila* f = criar_fila(n);

	for (int i = 1; i <= n; i++)
		enfilerar(f, i);

	printf("%d, ", desenfilerar(f));
	while (tamanho_fila(f) > 0)
	{
		for (int i = 1; i < m; i++)
			enfilerar(f, desenfilerar(f));
		printf("%d, ", desenfilerar(f));
	}
}

*/

int main()
{
	int tam = 10;
	LstEd *l = ld_criar(tam);	
	for (int i = 1; i <= tam; i++)
		ld_inserir(l, i);
	imprime_listasE(l);
	questao2(l);
	imprime_listasE(l);
	return 0;
}