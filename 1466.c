#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void bfs(No* raiz) {
    if (raiz == NULL) return;

    No* fila[505];
    int frente = 0, tras = 0;
    int primeiro = 1;

    fila[tras++] = raiz;

    while (frente < tras) {
        No* atual = fila[frente++];
        
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esq != NULL) fila[tras++] = atual->esq;
        if (atual->dir != NULL) fila[tras++] = atual->dir;
    }
}

void liberar(No* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int C, N, i, val, caso = 1;
    
    scanf("%d", &C);

    while (C--) {
        scanf("%d", &N);
        No* raiz = NULL;

        for (i = 0; i < N; i++) {
            scanf("%d", &val);
            raiz = inserir(raiz, val);
        }

        printf("Case %d:\n", caso++);
        bfs(raiz);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
