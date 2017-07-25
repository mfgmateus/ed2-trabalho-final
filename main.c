#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "TabelaHashColaborator.h"
#include "Grafo.h"

void imprime_colabs(Grafo* g, HashColab* colabs, Hash* works, char* colab) {

	int idPesquisador, i;
	buscaHashColab(colabs, colab, &idPesquisador);

	printf("Colaboradores de %s:\n", colab);
	for (i = 0; i < g->grau[idPesquisador]; i++) {
		int idColab = g->arestas[idPesquisador][i];
		printf("- %s\n", colabs->itens[idColab]);
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

	Hash* trabPesq = criaHash(359311);
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

		insereHash(trabPesq, work, pId);

		count++;

		if(count == 1000){
			printf("1000 works loaded!\n");
			count = 1;
		}

	}

	int i;

	printf("Works Loaded!\n");

	Grafo* g = cria_Grafo(22721, 200);

	for (i = 0; i < trabPesq->TABLE_SIZE; i++) {
		if (trabPesq->itens[i] == NULL) {
			continue;
		}
		if(i == 109274){
			printf("%d\n",i);
		}
		monta_grafo(g, i, trabPesq->itens[i]->itens);
	}

	printf("Graph Created!\n");

	return 0;

	imprime_colabs(g, colabs, trabPesq, "rodrigo franco goncalves");
	//imprime_authors(trabPesq, colabs, "towards a hybrid federated cloud platform to efficiently execute bioinformatics workflows");
	//imprime_colabs(g, colabs, trabPesq, "andre ricardo backes");

	printf("Grau Máximo: %d\n", max_grau(g));
	printf("Grau Médio: %.2f\n", med_grau(g));

	return 0;
}



