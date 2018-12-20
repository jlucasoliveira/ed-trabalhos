#include <stdio.h>
#include <string.h>
#include "../../tads/fila/fila.h"
#include "../../tads/pilha/pilha.h"

void inverte_fila_com_pilha(Fila* f)
{
	Pilha* p = p_criar(tamanho_fila(f));

	while (tamanho_fila(f) > 0)
		empilhar(p, desenfilerar(f));

	while (tamanho_pilha(p) >= 0)
		enfilerar(f, desempilhar(p));
}

void ordena_vetor(int* vet, int tam)
{
	Fila* f = criar_fila(tam);
	Pilha* p = p_criar(tam);
	int i = 0;

	while (i < tam)
	{
		if (vet[i] >= 0) empilhar(p, vet[i]);
		else enfilerar(f, vet[i]);
		i++;
	}

	i = -1;
	while (tamanho_fila(f) > 0)
	{
		i++;
		vet[i] = desenfilerar(f);
	}

	while (tamanho_pilha(p) > 0)
	{
		i++;
		vet[i] = desempilhar(p);
	}

}

int xCy(char* cadeia)
{
	Pilha* p = p_criar(strlen(cadeia));
	int i = 0;

	for (; cadeia[i] != 'C'; i++)
		empilhar(p, cadeia[i]);

	if (tamanho_pilha(p) != strlen(cadeia) - 1 - i) return 0;
	for (i+=1; i < strlen(cadeia); i++)
		if (desempilhar(p) != cadeia[i]) return 0;

	return 1;
}

int main()
{

	char* cadeia = "ABABKACAZBABA";
	printf("%d\n", xCy(cadeia));
	return 0;
}