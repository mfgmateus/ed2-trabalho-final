#include "ListaSequencial.h"

typedef struct hash{
    int qtd;
    int TABLE_SIZE;
    Lista **itens;
    char** trabalhos;
} Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int valorString(char *str);
int chaveDivisao(int chave, int TABLE_SIZE);
int insereHash(Hash* ha, char trabalho[], int idPesquisador);
int sondagemLinear(int pos, int i, int TABLE_SIZE);
int buscaHash(Hash* ha, char trabalho[], int *retorno8, int *qtdadePesq);
int buscaHashList(Hash* ha, char trabalho[], Lista* li);

