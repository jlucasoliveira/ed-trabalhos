typedef struct 
{
	int* itens;
	int n;
	int ultimo;	
} Fila;

Fila* criar_fila(int tam);
int tamanho_fila(Fila* f);
void enfilerar(Fila* f, int chave);
int desenfilerar(Fila* f);
void liberar_fila(Fila* f);