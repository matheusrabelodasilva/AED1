#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no {
    char *palavra;
    struct no *esq;
    struct no *dir;
} No;
unsigned int total_palavras = 0;
void copiar_string(char *destino, char *origem) {
    int i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0'; 
}
No* inserir(No *raiz, char *texto) {
    if (raiz == NULL) {
        raiz = (No*)malloc(sizeof(No));
        raiz->palavra = (char*)malloc(strlen(texto) + 1);
        copiar_string(raiz->palavra, texto);       
        raiz->esq = NULL;
        raiz->dir = NULL;
        total_palavras++;
    } else {
        int comparacao = strcmp(texto, raiz->palavra);
        if (comparacao < 0) {
            raiz->esq = inserir(raiz->esq, texto);
        } else if (comparacao > 0) {
            raiz->dir = inserir(raiz->dir, texto);
        }
    }
    return raiz;
}
void liberar(No *raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz->palavra);
        free(raiz);
    }
}
int main() {
    char buffer[100010]; 
    No *arvore = NULL;
    while (scanf("%s", buffer) != EOF) {
        arvore = inserir(arvore, buffer);
    }
    printf("%u\n", total_palavras);
    liberar(arvore);
    return 0;
}
