//Arquivo Grafo.h

typedef struct grafo Grafo;

Grafo* cria_Grafo(int nro_vertices, int grau_max);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, int val);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
void imprime_Grafo(Grafo *gr);
int max_grau(Grafo* gr);
float med_grau(Grafo* gr);
