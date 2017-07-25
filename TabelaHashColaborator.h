#include "ListaSequencial.h"
#include "HashCommon.h"

typedef struct hashColab{
    int qtd;
    int TABLE_SIZE;
    char** itens;
} HashColab;

HashColab* criaHashColab(int TABLE_SIZE);
void liberaHashColab(HashColab* ha);
int insereHashColab(HashColab* ha, char* nome);
int buscaHashColab(HashColab* ha, char* nome, int *retorno);
