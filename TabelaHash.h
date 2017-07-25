#include "ListaSequencial.h"
#include "HashCommon.h"

typedef struct trabalho{
    char* nome;
    Lista* itens;
} Trabalho;

typedef struct hash{
    int qtd;
    int TABLE_SIZE;
    Trabalho** itens;
} Hash;


Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int insereHash(Hash* ha, char trabalho[], int idPesquisador);
int buscaHash(Hash* ha, char trabalho[], int *retorno8, int *qtdadePesq);
int buscaHashList(Hash* ha, char trabalho[], Lista* li);

