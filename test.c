#include <stdio.h>
#include "Atividade-4/MTriangularInferior.c"

int main()
{
	int n = 5,  magic1 = rand() % 7, magic2 = rand() % 11;
	MTriangularInferior mat = mti_criar(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mti_set(mat, i, j, i*magic1 + j*magic2 + 1);
            printf("%d ", i*magic1 + j*magic2 + 1);
        }
        printf("\n");
    }

	printf("\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.1f\t", mti_get(mat, i, j));
        }
        printf("\n");
    }

    printf("\n%ld\n", sizeof(mat));

}