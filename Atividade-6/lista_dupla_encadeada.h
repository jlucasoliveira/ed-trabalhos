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
} LstEd;

LstEd* ld_criar();
void ld_inserir(LstEd* l, Aluno a);
int ld_remover(LstEd* l, int mat);
Aluno ld_buscar(LstEd* l, int mat);
No* ld_buscar_pont(LstEd* l, int mat);
void ld_liberar(LstEd* l);
