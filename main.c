#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "TabelaHashColaborator.h"
#include "Grafo.h"

void imprime_colabs(Grafo* g, HashColab* colabs, Hash* works, char* colab) {

	int idPesquisador, i;
	if(!buscaHashColab(colabs, colab, &idPesquisador)){
		printf("Colaborador não encontrado!\n");
		return;
	}

	printf("Colaboradores de %s:\n", colab);
	for (i = 0; i < g->grau[idPesquisador]; i++) {
		int idColab = g->arestas[idPesquisador][i];
		printf("- #%d  %s\n", idColab, colabs->itens[idColab]);
	}
	printf("-------------------------\n");
}

void imprime_authors(Hash* works, HashColab* colabs, char* work){
	int currentColabs[50];
	int colabsLen, i;
	buscaHash(works, work, currentColabs, &colabsLen);
	printf("Autores de %s:\n", work);
	for(i = 0; i < colabsLen; i++){
		printf("- %s\n",colabs->itens[currentColabs[i]]);
	}
	printf("-------------------------\n");
}

int main() {

	Hash* trabPesq = criaHash(718633);
	HashColab* colabs = criaHashColab(22721);

	FILE* f = fopen("dadosPesquisadores.txt", "r");

	int count = 1;

	while (1) {

		char line[500];
		char worker[50];
		char work[100];

		fscanf(f, "%[^\n]%*c", line);

		if (feof(f)) {
			break;
		}

		char* end = strchr(line, '\t');

		sprintf(worker, "%.*s", (int)(end - line), line);
		sprintf(work, "%s", end + 1);

		if(worker == NULL || work == NULL){
			continue;
		}

		int pId = insereHashColab(colabs, worker);

		if(pId == -1){
			printf("Failed to create hash for %s", worker);
			return 1;
		}

		insereHash(trabPesq, work, pId);

		count++;

		if(count == 50000){
	//		printf("50000 works loaded!\n");
			count = 1;
		}

	}

	int i;

	printf("Works Loaded!\n");

	Grafo* g = cria_Grafo(22721, 178);

	for (i = 0; i < trabPesq->TABLE_SIZE; i++) {
		if (trabPesq->itens[i] == NULL) {
			continue;
		}

		if(trabPesq->itens[i]->itens->qtd == 1){
			continue;
		}

		monta_grafo(g, i, trabPesq->itens[i]->itens, colabs);
	}

	printf("Graph Created!\n");

	imprime_colabs(g, colabs, trabPesq, "jean marcelo simao");
	imprime_colabs(g, colabs, trabPesq, "andre ricardo backes");
	imprime_authors(trabPesq, colabs, "towards a hybrid federated cloud platform to efficiently execute bioinformatics workflows");

	printf("Grau Máximo: %d\n", max_grau(g));
	printf("Grau Médio: %.2f\n", med_grau(g));

	return 0;
}



