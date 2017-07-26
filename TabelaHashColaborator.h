#include "ListaSequencial.h"
#include "HashCommon.h"

#ifndef _HASH_COLAB_
#define _HASH_COLAB_
typedef struct hashColab {
	int qtd;
	int TABLE_SIZE;
	char** itens;
} HashColab;
#endif

HashColab* criaHashColab(int TABLE_SIZE);
void liberaHashColab(HashColab* ha);
int insereHashColab(HashColab* ha, char* nome);
int buscaHashColab(HashColab* ha, char* nome, int *retorno);
