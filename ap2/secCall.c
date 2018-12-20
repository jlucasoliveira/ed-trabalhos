#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../tads/fila/fila.h"
//#include "../tads/lista/lista_dupla_encadeada.h"
//#include "../tads/lista/lista_encadeada.h"

/*
void imprime_listasE(LstEd* l)
{
	No* atual = l->inicio;
	while (atual != NULL)
	{
		printf("[%d], ", atual->info);
		atual = atual->prox;
	}
	printf("\n");
}

FUNFOU
void le_soma(LstEc* l)
{
	No* atual = l->inicio;
	No aux;

	while(atual != NULL)
	{
		atual->info+=atual->prox->info;
		aux = *atual->prox;
		free(atual->prox);
		atual->prox = aux.prox;
		atual = atual->prox;
	}
}

PEGO NAO
void ld_remove_par(LstEd* l)
{
	No* atual = l->inicio;
	No* aux;

	while(atual != NULL)
		if (atual->info%2==0)
		{
			if (atual->prox != NULL) atual->prox->ant = atual->ant;
			if (atual->ant != NULL) atual->ant->prox = atual->prox;
			aux = atual;
			atual = atual->prox;
			//free(aux);
		}
}

FUNFOU
void editor_texto(char frase[])
{
	Pilha* p  = p_criar(strlen(frase));
	int i = 0;

	while (frase[i] != '\0')
	{
		if (frase[i] != '#') empilhar(p, frase[i]);
		else desempilhar(p);
		i++;
	}
	frase[3] = '\0';
	while(tamanho_pilha(p) > 0)
		frase[tamanho_pilha(p)-1] = desempilhar(p);
}
*/

void furaFila(Fila* f, int chave)
{
	int tam = tamanho_fila(f);
	int i = 0;

	while (i < tam)
	{
		int tmp = desenfilerar(f);
		if (tmp != chave) enfilerar(f, tmp);
		i++;
	}
}

int main()
{
	/*
	LstEd* l = ld_criar(10);
	for (int i = 1; i <= 10; i++)
		ld_inserir(l, i);
	imprime_listasE(l);
	//le_soma(l);
	ld_remove_par(l);
	imprime_listasE(l);
	
	char frase[20] = "UMG##FK#C";
	editor_texto(frase);
	printf("%s\n", frase);
	*/
	Fila* f = criar_fila(10);
	enfilerar(f, 7);
	enfilerar(f, 4);
	enfilerar(f, 12);
	enfilerar(f, 1);
	enfilerar(f, 9);
	enfilerar(f, 5);

	for (int i = 0; i < tamanho_fila(f); i++)
		printf("[%d] ", f->itens[i]);

	furaFila(f, 1);
	printf("\n");
	for (int i = 0; i < tamanho_fila(f); i++)
		printf("[%d] ", f->itens[i]);
	return 0;
}
