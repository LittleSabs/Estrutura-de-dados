//programa que implementa deque
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//delclaracao da estrutura do no
struct no {
	int numero;
	struct no *proximo;
};

struct deque {
	struct no *filaNormal;
	struct no *filaPreferencial;
};

//funcao que insere um no no deque

struct deque *entrar(struct deque *cabeca, bool tipo, int numero) {
	//alocacao de memoria do novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero; //cria novo no
	novoNo -> proximo = NULL; //aponta o proximo para nulo
	
	//insercao na fila propriamente dito
	if (tipo) { //fila normal
		novoNo -> proximo = cabeca -> filaNormal; //entra na cabeca pela fila normal
		cabeca -> filaNormal = novoNo;	
	} else{ //filapreferencial
		novoNo -> proximo = cabeca -> filaPreferencial;
		cabeca -> filaPreferencial = novoNo;	
	}
	return cabeca;
}

//funcao que remove no de qualquer fila
struct no *sair (struct no *fila) {
	//caso mt facil: fila vazia
	if (fila==NULL) {
		return NULL;
	}
	//caso medio facil: fila so tem um unico no
	if(fila -> proximo ==NULL) {
		printf("%d\n", fila -> numero);
		free(fila);
		return NULL;
	}
	//caso dificil: fila tem mais de um no, percorrer ate o penultimo
	struct no *penultimo = fila;
	while (penultimo -> proximo -> proximo != NULL) {
		penultimo = penultimo -> proximo;
	}
	printf("%d\n", penultimo -> proximo -> numero);
	free(penultimo -> proximo);
	penultimo -> proximo = NULL;
	return fila;
}

//funcao que gera o atendimento do deque

void atender (struct deque *cabeca, int *contador) {
//caso mt facil: deque vazio
if((cabeca -> filaNormal == NULL) && (cabeca -> filaPreferencial == NULL)) {
	return; 
}

//caso facil: so tem normal
if (cabeca -> filaPreferencial == NULL) {
	cabeca -> filaNormal = sair(cabeca -> filaNormal);
	return;
}

//caso facil: so tem preferencial
if (cabeca -> filaNormal == NULL) {
	cabeca -> filaPreferencial = sair(cabeca -> filaPreferencial);
	return;
}
//caso dificil: tem atendimento nas duas filas
	if (*contador >4) {
	cabeca -> filaNormal = sair(cabeca -> filaNormal);
	*contador=0;
	} else { 
	cabeca -> filaPreferencial = sair(cabeca -> filaPreferencial);
	(*contador)++;
	}
}

int main() {
	struct deque *cabeca = (struct deque *) malloc(sizeof(struct deque));
	cabeca -> filaNormal = NULL;
	cabeca ->filaPreferencial = NULL; 
	int i=0;
	int contador =0;
	
	for (i=0; i<10; i++) {
		cabeca = entrar(cabeca, true, i);
	}
		for (i=100; i<110; i++) {
		cabeca = entrar(cabeca, false, i);
	}
	for (i=0; i<100; i++) {
		atender(cabeca, &contador);
	}
	
}