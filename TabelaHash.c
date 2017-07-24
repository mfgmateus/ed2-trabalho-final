#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"

Hash* criaHash(int TABLE_SIZE){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (Lista**) malloc(TABLE_SIZE * sizeof(Lista*));
        ha->trabalhos = (char**) malloc(TABLE_SIZE * sizeof(char*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void liberaHash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL)
                libera_lista(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

int valorString(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return (valor & 0x7FFFFFFF);
}

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash(Hash* ha, char trabalho[], int idPesquisador){

    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = valorString(trabalho);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);

    if(ha->itens[pos] == NULL){
        ha->itens[pos] = cria_lista();
        ha->qtd++;
        ha->trabalhos[pos] = malloc(100*sizeof(char));
        strcpy(ha->trabalhos[pos], trabalho);
        return insere_lista_final(ha->itens[pos], idPesquisador);
    }else{
        if(strcmp(ha->trabalhos[pos],trabalho) == 0){
            ha->qtd++;
            return insere_lista_final(ha->itens[pos], idPesquisador);
        }
        else{
            int i, newPos;
            for(i = 0; i < ha->TABLE_SIZE; i++){
                newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
                if(ha->itens[newPos] == NULL){
                    ha->itens[newPos] = cria_lista();
                    ha->qtd++;
                    return insere_lista_final(ha->itens[newPos], idPesquisador);
                }
            }
        }
    }
}

int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int buscaHash(Hash* ha, char trabalho[], int *retorno, int *qtdadePesq){
    if(ha == NULL)
        return 0;

    int chave = valorString(trabalho);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);

    if(ha->itens[pos] == NULL){
        return 0;
    }
    else{
        if(strcmp(ha->trabalhos[pos],trabalho) == 0){
            //imprime_lista(ha->itens[pos]);
            lista_retorno(ha->itens[pos], retorno, qtdadePesq);
            return 1;
        }
        else{
            int i, newPos;
            for(i = 0; i < ha->TABLE_SIZE; i++){
                newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
                if(ha->itens[newPos] == NULL)
                    return 0;

                if(strcmp(ha->trabalhos[newPos],trabalho) == 0){
                    //imprime_lista(ha->itens[newPos]);
                    lista_retorno(ha->itens[newPos], retorno, qtdadePesq);
                    return 1;
                }
            }
        }
    }
}

int lista_retorno(Lista* li, int *retorno, int *qtdadePesq){
    if(li == NULL)
        return 0;

    int i;

    for(i = 0; i < li->qtd; i++){
        retorno[i] = li->dados[i];
    }

    *qtdadePesq = li->qtd;

    return 1;
}
