#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf(" %d", raiz->dado);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf(" %d", raiz->dado);
        emOrdem(raiz->direita);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf(" %d", raiz->dado);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    int C, N, valor, i, caso = 1;

    if (scanf("%d", &C) != 1) return 0;

    while (C--) {
        if (scanf("%d", &N) != 1) break;
        No* raiz = NULL;
        for (i = 0; i < N; i++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso++);
        printf("Pre.:");
        preOrdem(raiz);
        printf("\n");
        printf("In..:");
        emOrdem(raiz);
        printf("\n");
        printf("Post:");
        posOrdem(raiz);
        printf("\n\n");

        liberarArvore(raiz);
    }

    return 0;
}
