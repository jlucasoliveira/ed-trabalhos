typedef struct no
{
	struct no* pai;
	struct no* esq;
	struct no* dir;
	int info;
} No;

void visitar(No* raiz);
int abb_qtde_filhos(No* raiz);
No* abb_sucessor(No* raiz);
No* abb_busca(No* raiz, int chave);
No* abb_add(No* raiz, int chave);
void abb_remover(No* raiz, int chave);

/* MODOS DE VISITA AOS NÓS */
void pre_ordem(No* raiz);