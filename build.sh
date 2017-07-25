gcc -c ListaSequencial.c
gcc -c TabelaHash.c
gcc -c TabelaHashColaborator.c
gcc -c Grafo.c
gcc -c HashCommon.c
gcc main.c Grafo.o TabelaHash.o TabelaHashColaborator.o ListaSequencial.o HashCommon.o
