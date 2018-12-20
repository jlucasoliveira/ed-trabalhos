typedef struct
{
	char* itens;
	int tam;
	int topo;
} Pilha;

Pilha* p_criar(int tam);
int tamanho_pilha(Pilha* p);
void empilhar(Pilha* p, char item);
char desempilhar(Pilha* p);
char topo(Pilha* p);