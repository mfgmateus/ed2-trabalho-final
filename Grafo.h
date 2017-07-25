//Arquivo Grafo.h
#include "ListaSequencial.h"

//Defini��o do tipo Grafo
typedef struct grafo{
    int nro_vertices;
    int grau_max;
    int** arestas;
    Lista*** trabalhos;
    int* grau;
} Grafo;

Grafo* cria_Grafo(int nro_vertices, int grau_max);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, int val);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
void imprime_Grafo(Grafo *gr);
int max_grau(Grafo* gr);
float med_grau(Grafo* gr);
int monta_grafo(Grafo* g, int work, void* workers);
