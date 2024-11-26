#include <stdio.h>
#include <stdlib.h>

//Declaracao da estrutura do no
struct no {
    int numero;
    int altura;
    struct no *esquerda;
    struct no *direita;
};

//Funcao que retorna a altura do no
int getAlturaNo(struct no *raiz){
    if (raiz == NULL){
        return 0;
    }
    else{
        return raiz -> altura;
    }

}

//Funcao que descobre qual o maior entre dois números
int getMaximoDoisNumeros(int a, int b){
    return (a>b) ? a : b;
}

//Funcao que analisa o balanço da arvore
int getBalanco(struct no *raiz){
    if(raiz == NULL){
        return 0;
    }

    return (getAlturaNo(raiz -> esquerda)) - (getAlturaNo(raiz -> direita));
}


//Funcao que rotaciona a arvore a esquerda
struct no *rotacionarEsquerda(struct no *pai){
    //Correcao dos ponteiros
    struct no *filho = pai -> direita;
    pai -> direita = filho -> esquerda;
    filho -> esquerda = pai;

    //Correcao Alturas
    pai -> altura = (getMaximoDoisNumeros(getAlturaNo(pai -> esquerda), getAlturaNo(pai -> direita)) + 1);
    filho -> altura = (getMaximoDoisNumeros(getAlturaNo(filho -> esquerda), getAlturaNo(filho -> direita)) + 1);

    return filho;
};

//Funcao que rotaciona a arvore a direita
struct no *rotacionarDireita(struct no *pai){
    //Correcao dos ponteiros
    struct no *filho = pai -> esquerda;
    pai -> esquerda = filho -> direita;
    filho -> direita = pai;

    //Correcao Alturas
    pai -> altura = (getMaximoDoisNumeros(getAlturaNo(pai -> esquerda), getAlturaNo(pai -> direita)) + 1);
    filho -> altura = (getMaximoDoisNumeros(getAlturaNo(filho -> esquerda), getAlturaNo(filho -> direita)) + 1);

    return filho;
};


//Funcao que insere um no na arvore
struct no *inserir(struct no *raiz, int numero){
    //Caso facil: arvore vazia
    if (raiz == NULL){
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> altura = 1;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    }

    //Caso dificil: arvore nao vazia
    if (raiz -> numero > numero){
        raiz -> esquerda = inserir(raiz -> esquerda, numero);
    }
    else{
        raiz -> direita = inserir(raiz -> direita, numero);
    }


    //Balanceamento da árvore
    raiz -> altura = (1 + getMaximoDoisNumeros(getAlturaNo(raiz -> esquerda), getAlturaNo(raiz -> direita)));

    int balanco = getBalanco(raiz);

    //Vendo para onde a árvore inclina:

    //Árvore inclinada para a esquerda e número menor foi inserido (Entrar na esquerda)
    if ((balanco > 1) && (numero < raiz -> esquerda -> numero)){
        raiz = rotacionarDireita(raiz);
    }

    //Arvore inclinada para a direita e número maior foi inserido (Entrar na direita)
    if ((balanco < -1) && (numero > raiz -> direita -> numero)){
        raiz = rotacionarEsquerda(raiz);
    }

    //Arvore inclinada para a esquerda e número maior foi inserido (Entrar na direita)
    if ((balanco > 1) && (numero > raiz -> esquerda -> numero)){
        raiz -> esquerda = rotacionarEsquerda(raiz -> esquerda);
        raiz = rotacionarDireita(raiz);
    }

    //Arvore inclinada para a direita e número maior foi inserido (Entrar na esquerda)
    if ((balanco < -1) && (numero < raiz -> direita -> numero)){
        raiz -> direita = rotacionarDireita(raiz -> direita);
        raiz = rotacionarEsquerda(raiz);
    }

    return raiz;
}

//Funcao que imprime a arvore
void imprimir(struct no *raiz, int identacao){
    if (raiz == NULL){
        return;
    }

    int i;
    for (i = 0; i < identacao; i++){
        printf("-");
    }
    printf("%d\n", raiz -> numero);

    identacao += 3;
    imprimir(raiz -> esquerda, identacao);
    imprimir(raiz -> direita, identacao);
}

int main(){
    struct no *arvore = NULL;
    for (int i = 1; i < 100; i++){
        arvore = inserir(arvore, i);
    };
    imprimir(arvore, 0);
}