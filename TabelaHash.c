#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"


Hash* criaHash(int TABLE_SIZE){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (Trabalho**) malloc(TABLE_SIZE * sizeof(Trabalho*));
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
        ha->itens[pos] = (Trabalho*) malloc(sizeof(Trabalho));
        ha->qtd++;
        ha->itens[pos]->nome = malloc(100*sizeof(char));
        ha->itens[pos]->itens = cria_lista();
        strcpy(ha->itens[pos]->nome, trabalho);
        return insere_lista_final(ha->itens[pos]->itens, idPesquisador);
    }else{
        if(strcmp(ha->itens[pos]->nome,trabalho) == 0){
            ha->qtd++;
            return insere_lista_final(ha->itens[pos]->itens, idPesquisador);
        }
        else{
            int i, newPos;
            for(i = 0; i < ha->TABLE_SIZE; i++){
                newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
                if(ha->itens[newPos] == NULL){
                    ha->itens[newPos] = cria_lista();
                    ha->qtd++;
                    return insere_lista_final(ha->itens[newPos]->itens, idPesquisador);
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
        if(strcmp(ha->itens[pos]->nome,trabalho) == 0){
            lista_retorno(ha->itens[pos]->itens, retorno, qtdadePesq);
            return 1;
        }
        else{
            int i, newPos;
            for(i = 0; i < ha->TABLE_SIZE; i++){
                newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
                if(ha->itens[newPos] == NULL)
                    return 0;

                if(strcmp(ha->itens[newPos]->nome,trabalho) == 0){
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
