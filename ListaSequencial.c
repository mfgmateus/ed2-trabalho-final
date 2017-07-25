#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h" //inclui os Prot�tipos

//Defini��o do tipo lista


Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int insere_lista_final(Lista* li, int val){
    if(li == NULL)
        return 0;

    if(li->qtd >= MAX)//lista cheia
        return 0;

    if(li->dados == NULL)
        return 0;

    li->dados[li->qtd] = val;
    li->qtd++;
    return 1;
}

int insere_lista_final_uniq(Lista* li, int val){
    if(li == NULL)
        return 0;

    if(li->qtd >= MAX)//lista cheia
        return 0;

    if(li->dados == NULL)
        return 0;

    int i;

    for(i = 0; i < li->qtd; i++){
        if(li->dados[i] == val){
            return 0;
        }
    }

    li->dados[li->qtd] = val;
    li->qtd++;
    return 1;
}


int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li){
    int i;
    printf("[");

    if(li != NULL){
        for(i = 0; i < li->qtd; i++){
            printf("%d", li->dados[i]);
            if(i != li->qtd-1){
                printf(",");
            }
        }
    }
    printf("]");
}
