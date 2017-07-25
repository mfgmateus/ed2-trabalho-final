#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"
#include "TabelaHashColaborator.h"
#include "Grafo.h"


int main()
{

    Hash* trabPesq = criaHash(359311);
    HashColab* colabs = criaHash(22721);

    FILE* f = fopen("dadosPesquisadores10000.txt", "r");

    while(1){

        char line[500];
        char worker[50];
        char work[100];


        if(feof(f)){
            break;
        }

        fscanf(f, "%[^\n]%*c", line);

        char* end = strchr( line, '\t' );

        sprintf(worker, "%.*s", end - line, line);
        sprintf(work, "%s", end+1);

        int pId = insereHashColab(colabs, worker);
        printf("%d\n",pId);

        if(pId == 17026){
            printf("%d\n",pId);
        }

        insereHash(trabPesq, work, pId);

    }

    return 0;

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


