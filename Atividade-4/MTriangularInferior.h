typedef struct mti MTriangularInferior;

MTriangularInferior mti_criar(int tam);
void mti_set(MTriangularInferior mat, int i, int j, float a);
float mti_get(MTriangularInferior mat, int i, int j);
void mti_liberar(MTriangularInferior mat);
