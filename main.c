#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h";
//#include "ListaSequencial.h"

int main()
{
    Grafo* g = cria_Grafo(10, 10);
    insereAresta(g, 1, 2, 0, 1);
    insereAresta(g, 1, 3, 0, 2);
    insereAresta(g, 1, 3, 0, 3);
    imprime_Grafo(g);
    printf("Grau Máximo: %d\n",max_grau(g));
    printf("Grau Médio: %.2f\n",med_grau(g));
    return 0;
}
