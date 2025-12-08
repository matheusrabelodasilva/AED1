#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char letra;
    struct no *esq;
    struct no *dir;
} No;

int primeiro;

No* criarNo(char letra) {
    No* novo = (No*)malloc(sizeof(No));
    novo->letra = letra;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, char letra) {
    if (raiz == NULL) {
        return criarNo(letra);
    }
    if (letra < raiz->letra) {
        raiz->esq = inserir(raiz->esq, letra);
    } else {
        raiz->dir = inserir(raiz->dir, letra);
    }
    return raiz;
}

int buscar(No* raiz, char letra) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->letra == letra) {
        return 1;
    }
    if (letra < raiz->letra) {
        return buscar(raiz->esq, letra);
    } else {
        return buscar(raiz->dir, letra);
    }
}

void prefixa(No* raiz) {
    if (raiz != NULL) {
        if (!primeiro) printf(" ");
        printf("%c", raiz->letra);
        primeiro = 0;
        prefixa(raiz->esq);
        prefixa(raiz->dir);
    }
}

void infixa(No* raiz) {
    if (raiz != NULL) {
        infixa(raiz->esq);
        if (!primeiro) printf(" ");
        printf("%c", raiz->letra);
        primeiro = 0;
        infixa(raiz->dir);
    }
}

void posfixa(No* raiz) {
    if (raiz != NULL) {
        posfixa(raiz->esq);
        posfixa(raiz->dir);
        if (!primeiro) printf(" ");
        printf("%c", raiz->letra);
        primeiro = 0;
    }
}

int main() {
    char comando[20];
    char letra;
    No* raiz = NULL;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &letra);
            raiz = inserir(raiz, letra);
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &letra);
            if (buscar(raiz, letra)) {
                printf("%c existe\n", letra);
            } else {
                printf("%c nao existe\n", letra);
            }
        } else if (strcmp(comando, "PREFIXA") == 0) {
            primeiro = 1;
            prefixa(raiz);
            printf("\n");
        } else if (strcmp(comando, "INFIXA") == 0) {
            primeiro = 1;
            infixa(raiz);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            primeiro = 1;
            posfixa(raiz);
            printf("\n");
        }
    }

    return 0;
}
