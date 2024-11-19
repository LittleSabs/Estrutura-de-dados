//Dijkstra
//programa que implementa a ordenacao topologica num grafo
#include <stdio.h>

//declaracao de constantes
#define TAMANHO 4

//funcao que constroi o grafo

void construir(int grafo[TAMANHO][TAMANHO]) {
	//declaracao de variaveis
	int i,j, adjacencia;
	
	//incializacao do grafo
	for (i=0; i< TAMANHO; i++) {
		for (j=0; j< TAMANHO; j++) {
			grafo[i][j]=0;
		}
	}
	//construcao propriamente dita
	for (i=0; i< TAMANHO; i++) {
		for (j=0; j< TAMANHO; j++) {
			if (i==j) {
				continue;
			}
			
			printf("Digite <1> se %d for adjacente a %d:", i,j);
			scanf("%d", &adjacencia);
			grafo[i][j] = adjacencia;
		}
	}
}

//funcao recursiva que descobre a ordenacao topologica do grafo
void ordenarTopologicoRecursivo(int grafo[TAMANHO][TAMANHO], int visitado[TAMANHO], int vertice){
	int i;
	visitado[vertice]= 1;
	
	for(i=0; i<TAMANHO; i++) {
		if ((grafo[vertice][i]) && (! visitado[i])) {
			ordenarTopologicoRecursivo(grafo,visitado,i);
		}
	}
	printf("%d\t", vertice);
}

//funcao que descobre a ordenacao topologica do grafo
void ordenarTopologico(int grafo[TAMANHO][TAMANHO]) {
	int vertice;
	int visitado[TAMANHO];
	
	for(vertice=0; vertice< TAMANHO; vertice++) {
		visitado[vertice] =0;
	}
	
	for (vertice =0; vertice < TAMANHO; vertice++) {
		if (! visitado[vertice]) {
			ordenarTopologicoRecursivo(grafo,visitado,vertice);
		}
	}
	printf("\n");
}

//funcao principal de execucao do programa

int main() {
	int grafo[TAMANHO][TAMANHO];
	
	construir(grafo);
	ordenarTopologico(grafo);
}