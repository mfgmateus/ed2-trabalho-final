#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"
#include "TabelaHashColaborator.h"
#include "Grafo.h"


int main()
{

    Hash* trabPesq = criaHash(359311);
    HashColab* colabs = criaHash(22721);

    char work[100] = "microstructure and wear of a cu-si-b alloy and diamond composites obtained in high pressure and high temperature conditions";

    insereHash(trabPesq, work,200);
    insereHash(trabPesq, work,201);
    insereHash(trabPesq, work,202);
    insereHash(trabPesq, work,203);

    int i;

    Grafo* g = cria_Grafo(22721, 10);

    for(i = 0; i < trabPesq->TABLE_SIZE; i++){
        if(trabPesq->itens[i] == NULL){
            continue;
        }
        monta_grafo(g, i, trabPesq->itens[i]->itens);
    }

    imprime_Grafo(g);


    printf("Grau Máximo: %d\n",max_grau(g));
    printf("Grau Médio: %.2f\n",med_grau(g));

    return 0;
}


