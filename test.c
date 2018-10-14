#include <stdio.h>
#include <math.h>
/*
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

}*/

int primo(int n)
{
	for (int i = n-1; i >= 2; i--)
		if (n%i == 0) return i;
	return 0;
}

int mdc(int a, int b)
{
	int t = a%b;
	printf("%d - %d\n", a, b);
	if (t == 0) return a/b;
	else return mdc(b, t);
}

void exibir_fatoracao(int n)
{
	int i = 2;
	while(n > 1)
	{
		if (!primo(i))
			while (n%i == 0)
			{
				printf("%d ", i);
				n/=i;
			}
		i++;
	}
}

void numero_perfeito(int n)
{
	int soma = 0;
	for (int i = 1; i < n-1; i++)
		if (n%i == 0) soma+=i;

	if (soma == n) printf("Perfeito\n");
	else printf("Normal\n");
}

int main()
{
	int a, b;
	scanf("%d\n%d", &a, &b);
	/*int z = primo(tmp);
	if (z == 0) printf("Primo\n");
	else printf("nao-primo - %d\n", z);*/
	printf("%d\n", mdc(a, b));
	//exibir_fatoracao(a);
	//numero_pereito(a);
	return 0;
}