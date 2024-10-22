//programa que implementa uma arvore rubro-
#include <stdio.h>
#include <stdlib.h>

//declaracao de constantes
#define PRETO 0
#define VERMELHO 1

//declaracao da estrutura do no
struct no {
	int numero;
	int cor; 
	struct no *esquerda;
	struct no *direita;
};

//funcao que recupera a cor do no
int ehVermelho(struct no *raiz) {
	if(raiz==NULL) {
		return PRETO;
	}
	return raiz -> cor;
}

//funcao que rotaciona o no na esquerda
struct no *rotacionarEsquerda(struct no *pai) {
	//corecao dos ponterios
	struct no *filho= pai -> direita;
	pai -> direita = filho-> esquerda;
	filho -> esquerda = pai;
	
	//corecao das cores
	filho->cor = pai-> cor;
	pai->cor = VERMELHO;
	
	//retorno
	return filho;
}
//funcao que rotaciona o no na direita
struct no *rotacionarDireita(struct no *pai) {
	//corecao dos ponterios
	struct no *filho= pai -> esquerda;
	pai -> esquerda = filho-> direita;
	filho -> direita = pai;
	
	//corecao das cores
	filho->cor = pai-> cor;
	pai->cor = VERMELHO;
	
	//retorno
	return filho;
}

//funcao que sobe o vermelho
void subirVermelho(struct no *pai) {
	pai->cor = VERMELHO;
	pai-> esquerda -> cor = PRETO;
	pai -> direita -> cor = PRETO;
}

//funcao que insere um  no na arvore
struct no *inserir(struct no *raiz, int numero) {
	//caso facil arvore vazia
	if (raiz==NULL) {
		raiz= (struct no *) malloc(sizeof(struct no));
		raiz->numero = numero;
		raiz -> cor = VERMELHO;
		raiz-> esquerda = NULL;
		raiz -> direita = NULL;
		return raiz;
	}
	//caso dificil arvore nao vazia 
	if (raiz -> numero > numero) {
		raiz -> esquerda = inserir (raiz -> esquerda, numero);
	} else {
		raiz -> direita = inserir(raiz -> direita, numero);
	}
	//balanceamento da arvore
	if((! ehVermelho(raiz -> esquerda)) && (ehVermelho(raiz->direita))){
		raiz = rotacionarEsquerda(raiz);
	}
	if ((ehVermelho(raiz -> esquerda))&& (ehVermelho(raiz -> direita))) {
		subirVermelho(raiz);
	}
	return raiz;
	}

//funcao que imrpime arvore
void imprimir(struct no *raiz, int indentacao) {
	if (raiz==NULL) {
		return;
	}
	int i;
	for (i=0; i< indentacao; i++) {
		printf("-");
	}
	printf("%d", raiz->numero);
	printf("(%s)\n", (raiz->cor ? "V": "P" ));
	
	indentacao +=3;
	imprimir (raiz -> esquerda, indentacao);
	imprimir (raiz -> direita, indentacao);
}

//funcao principal de excusao dp programa
int main(){
	struct no *arvore = NULL;
	int i=0;
	
	for (i=0; i<10; i++) {
		arvore = inserir(arvore,i);
	}
	imprimir(arvore,0);
}