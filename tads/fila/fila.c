#include "fila.h"
#include <stdlib.h>

Fila* criar_fila(int tam)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->n = tam;
	f->ultimo = -1;
	f->itens = (int*) malloc(sizeof(int) * tam);
	return f;
}

int tamanho_fila(Fila* f)
{
	return f->ultimo+1;
}

void enfilerar(Fila* f, int chave)
{
	if (f->ultimo < f->n-1) f->itens[++f->ultimo] = chave;
}

int desenfilerar(Fila* f)
{
	if (f->ultimo >= 0)
	{
		int aux = f->itens[0];
		for (int i = 0; i < f->ultimo; i++)
			f->itens[i] = f->itens[i+1];
		f->ultimo--;
		return aux;
	}
}

void liberar_fila(Fila* f)
{
	free(f->itens);
	free(f);
}
