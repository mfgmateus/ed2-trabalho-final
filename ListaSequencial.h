//Arquivo ListaSequencial.h
#define MAX 20

#ifndef _LIST_
#define _LIST_
typedef struct lista{
    int qtd;
    int dados[MAX];
} Lista;
#endif // _LIST_
Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int id);
int insere_lista_final(Lista* li, int id);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
