//progrma que implementa arvore de busca

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaracao estrutura do no
struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

//funcao que insere um no na arvore

struct no *inserir(struct no *raiz, int numero){
	//caso facil: arvore vazia
	if (raiz== NULL) {
		raiz = (struct no *)malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz-> esquerda = NULL;
		raiz->direita = NULL;
		return raiz;
	}
	
	//caso dificil: arvore nao vazia
	if ((raiz -> numero)> numero){
		raiz -> esquerda = inserir(raiz -> esquerda, numero);
	} else{
		raiz -> direita = inserir(raiz->direita, numero);
	}
	return raiz;
	}

//funcao que busca no na arovre
void procurar (struct no *raiz, int numero) {
	//caso mnt facil arvore vazia
	if (raiz == NULL) {
		printf("Nao encontrei o numero \n");
		return;
	}
	
	//caso facilo: numero procurado na raiz
	if (raiz -> numero ==numero){
		printf("Numero encontrado \n");
		return;
	}
	//caso dificil: numero n esta na raiz
	if (raiz -> numero > numero) {
		procurar(raiz -> esquerda, numero);
	} else{ 
		procurar(raiz->direita , numero);
	}
}

//funcao que navega a arvore em ordem

void navegarEmOrdem(struct no *raiz) {
	if (raiz == NULL) {
		return;
	}
	navegarEmOrdem(raiz -> esquerda);
	printf("%d, ", raiz -> numero);
	navegarEmOrdem(raiz->direita);
}

//funcao principal de execucao do programa 
int main() {
	//declaracao de variaveis
	struct no *arvore = NULL;
	int i =0;
	int numero= 0;
	
	//iniciacao da aleatoriedade
	time_t t; 
	srand(time(&t));
	
	//construcao0 da arvore
	for (i=0; i<100;i++) {
		arvore= inserir(arvore,rand());
	}
	
	//navegacao em arvore
	navegarEmOrdem(arvore);
	printf("\n");
	
	//procura de nos
	while(true){
	printf("Digite um numero:");
	scanf("%d", &numero);
	procurar(arvore, numero);	
	}
}
