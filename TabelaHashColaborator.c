#include <stdlib.h>
#include <string.h>
#include "TabelaHashColaborator.h"

HashColab* criaHashColab(int TABLE_SIZE){
    HashColab* ha = (HashColab*) malloc(sizeof(HashColab));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (char**) malloc(TABLE_SIZE * sizeof(char*));
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

void liberaHashColab(HashColab* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

int insereHashColab(HashColab* ha, char* nome){

    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = valorString(nome);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);

    if(ha->itens[pos] == NULL){
        ha->itens[pos] = (char*) malloc(100 * sizeof(char));
        ha->qtd++;
        strcpy(ha->itens[pos], nome);
        return pos;
    }else if(strcmp(ha->itens[pos], nome) != 0){
        int i, newPos;
        for(i = 0; i < ha->TABLE_SIZE; i++){
            newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
            if(ha->itens[newPos] == NULL){
                ha->itens[pos] = (char*) malloc(100 * sizeof(char));
                ha->qtd++;
                strcpy(ha->itens[pos], nome);
                return newPos;
            }
        }
    }else{
        return pos;
    }
}

int buscaHashColab(HashColab* ha, char* nome, int *retorno){
    if(ha == NULL)
        return 0;

    int chave = valorString(nome);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);

    if(ha->itens[pos] == NULL){
        return 0;
    }
    if(strcmp(ha->itens[pos], nome) == 0){
        *retorno = pos;
        return 1;
    }else{
        int i, newPos;
        for(i = 0; i < ha->TABLE_SIZE; i++){
            newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
            if(strcmp(ha->itens[newPos], nome) == 0){
                *retorno = newPos;
                return 1;
            }
        }
    }

    return 0;
}
