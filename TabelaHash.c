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

int insereHash(Hash* ha, char trabalho[], int idPesquisador){

    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = valorString(trabalho);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);

    if(pos == 34256){
        printf("Trab %s\n",trabalho);
    }

    if(ha->itens[pos] == NULL){
        ha->itens[pos] = (Trabalho*) malloc(sizeof(Trabalho));
        int i;
        ha->qtd++;
        ha->itens[pos]->nome = malloc(400*sizeof(char));
        ha->itens[pos]->itens = cria_lista();
        ha->itens[pos]->itens->qtd = 0;
        strcpy(ha->itens[pos]->nome, trabalho);
        return insere_lista_final(ha->itens[pos]->itens, idPesquisador);
    }else{
        if(ha->itens[pos]->nome == NULL && ha->itens[pos] == NULL){
            printf("Lista[%d]: ",pos);
            imprime_lista(ha->itens[pos]->itens);
            return 0;
        }
        if(strcmp(ha->itens[pos]->nome,trabalho) == 0){
            ha->qtd++;
            return insere_lista_final_uniq(ha->itens[pos]->itens, idPesquisador);
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
