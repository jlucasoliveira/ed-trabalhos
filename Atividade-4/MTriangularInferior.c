#include <stdlib.h>

struct mti
{
	float** dados;
	int n;
};

typedef struct mti MTriangularInferior;

MTriangularInferior mti_criar(int tam)
{
	MTriangularInferior mat;
	mat.dados = (float**) malloc(tam*sizeof(float*));
	for (int i = 1; i <= tam; i++)
		mat.dados[i-1] = (float*) malloc(i*sizeof(float));
	mat.n = tam; 
	return mat;
}

void mti_set(MTriangularInferior mat, int i, int j, float a)
{
	if (i >= j)
	{
		mat.dados[i][j] = a;
	}
}

float mti_get(MTriangularInferior mat, int i, int j)
{
	if (i >= j)
	{
		return mat.dados[i][j];
	}
	else return 0.0;
}

void mti_liberar(MTriangularInferior mat)
{
	free(mat.dados);
}