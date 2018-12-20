typedef struct
{
	Fila f1, f2;	
} Pilha_Lista;

Pilha_Lista* p_criar(int tam);
int tamanho_pilha(Pilha_Lista* p);
void empilhar(Pilha_Lista* p, int item);
int desempilhar(Pilha_Lista* p);
int topo(Pilha_Lista* p);