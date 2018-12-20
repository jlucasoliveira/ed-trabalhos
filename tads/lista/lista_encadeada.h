typedef struct 
{
	char nome[200];
	int mat;
} Aluno;

typedef struct no
{
	int info;
	struct no* prox;
} No;

typedef struct
{
	No* inicio;
} LstEc;

LstEc* le_criar();
void le_inserir(LstEc* l, int a);
int le_remover(LstEc* l, int mat);
int le_buscar(LstEc* l, int mat);
No* le_buscar_pont(LstEc* l, int mat);
void le_liberar(LstEc* l);
