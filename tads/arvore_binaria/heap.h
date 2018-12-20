typedef struct 
{
	int* itens;
	int TAM_MAX, n;
} Heap;

Heap* hp_criar(int tam);
int hp_maior_filho(Heap* hp, int pai);
void hp_subir(Heap* hp, int posicao);
void hp_descer(Heap* hp, int posicao);
void hp_add(Heap* hp, int chave);
int hp_remover(Heap* hp);
void hp_atualizar(Heap* hp, int posicao, int chave);
int verificar_heap_maximo(int* vetor, int n);
void hp_liberar(Heap* hp);
