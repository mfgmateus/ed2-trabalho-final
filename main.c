#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"
#include "Grafo.h"

int main()
{

    Hash* trabPesq = criaHash(500009);

    int idPesquisadores[20];
    int qtdadePesquisadores;

    char work[100] = "microstructure and wear of a cu-si-b alloy and diamond composites obtained in high pressure and high temperature conditions";

    insereHash(trabPesq, work,200);
    insereHash(trabPesq, work,201);
    insereHash(trabPesq, work,202);
    insereHash(trabPesq, work,203);

    buscaHash(trabPesq, work, idPesquisadores, &qtdadePesquisadores);

    int i;
    for(i = 0; i < qtdadePesquisadores; i++){
        printf("%d\n", idPesquisadores[i]);
    }

    printf("---------\n");

    Grafo* g = cria_Grafo(10, 10);
    insereAresta(g, 1, 2, 0, 1);
    insereAresta(g, 1, 3, 0, 2);
    insereAresta(g, 1, 3, 0, 3);
    imprime_Grafo(g);
    printf("Grau Máximo: %d\n",max_grau(g));
    printf("Grau Médio: %.2f\n",med_grau(g));

    return 0;
}
