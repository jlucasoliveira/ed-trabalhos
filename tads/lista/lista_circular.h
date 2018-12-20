typedef struct
{
	char nome[200];
	int mat;
} Aluno;

typedef struct no
{
	Aluno info;
	struct no* prox;
	struct no* ant;
} No;

typedef struct 
{
	No* inicio;	
} LstC;

LstC* lc_criar();
void lc_inserir(LstC* l, Aluno a);
int lc_remover(LstC* l, int mat);
Aluno lc_buscar(LstC* l, int mat);
No* lc_buscar_pont(LstC* l, int mat);
void lc_liberar(LstC* l);