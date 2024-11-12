///////////////////////////////////////////
///programa que implementa um Grafo //////
///////////////////////////////////////////

#include <stdio.h>

///////////////////////////////////////////
///////// declaracao de constante ////////////
/////////////////////////////////////////////


#define TAMANHO 5 

/////////////////////////////////////////
// constroi o grafo ///////////////////////
/////////////////////////////////////////

void construir(int grafo[TAMANHO][TAMANHO]){
int i , j, adjacencia;

//inicializaÃ§Ã£o da memoria

for(i=0; i<TAMANHO; i++){
    for (j=0;j<TAMANHO; j++){
        grafo[i][j]=0;
    }
}

// construcao propriamente dita 

for (i =0; i< (TAMANHO-1) ; i++){
    for(j=(i+1); j<TAMANHO; j ++){
        printf("Digite <1> se %d for adjacente a %d", i, j);
        scanf("%d", &adjacencia);
        grafo[i][j]= adjacencia;
        grafo[i][j]=adjacencia;
    }
}

}


////////////////////////////////////////////////////
/// funcao que imprime o grafo /////////
/////////////////////////////////////////////

void imprimir (int grafo[TAMANHO][TAMANHO]){
    int i , j;

    printf("=====================");
    printf("Vertice\tVizinhanca");
    for(i=0; i< TAMANHO; i++){
        printf("%d\t\t", i);
        for(j=0; j<TAMANHO; j++){
            if(grafo[i][j]){
                printf("%d,", j);
            }
        }

        printf("\n");
    }
    printf("======================");
}

//////////////////////////////////////////////////
// funcao que descobre o vertice mais popular /////////////
///////////////////////////////////////////////////

void descobrirMaiorGrau(int grafo[TAMANHO][TAMANHO]){
    int i, j, vertice, maiorgrau, contador;

    maiorgrau=0;

    for(i=0; i<TAMANHO; i ++){
        contador = 0;
        for(j=0; j<TAMANHO; j++){
            if(grafo[i][j]){
                contador++;
            }
        }

        if(contador>maiorgrau){
            vertice=i;
            maiorgrau=contador;
        }
    }

    printf("O vertice mais popular e: %d\n", vertice);
}

//////////////////////////////////////////////////////////
///// funcao principal que executa o programa ////////////
///////////////////////////////////////////////////////////

int main(){
    int grafo[TAMANHO][TAMANHO];
    construir(grafo);
    imprimir(grafo);
    descobrirMaiorGrau(grafo);
}