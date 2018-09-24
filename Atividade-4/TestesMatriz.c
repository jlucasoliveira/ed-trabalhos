#include <stdio.h>
#include <time.h>

#include "MTriangularInferior.h"
#include "MTriangularInferior.c"

int teste_matriz_ti(int n){
        srand(time(NULL));
        float a, magic1 = rand() % 7, magic2 = rand() % 11;
        MTriangularInferior mat = mti_criar(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mti_set(mat, i, j, i*magic1 + j*magic2 + 1);
            }
        }
        int ok = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j > i){
                    if(mti_get(mat, i, j) != 0.0) return 0;
                }else if(mti_get(mat, i, j) != i*magic1 + j*magic2 + 1) return 0;
            }
        }
        mti_liberar(mat);
        return 1;
}

int main(){
    int qtd_ok = 0, qtd_falha = 0;
    for(int i = 1; i <= 100; i++){
        if(teste_matriz_ti(i*10)) qtd_ok++;
        else qtd_falha++;
    }
    printf("Do total de 100 testes, %d funcionou corretamente e %d nao funcionou.", qtd_ok, qtd_falha);
}


