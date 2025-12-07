#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado;
    struct no *prox;
} Pilha;

void empilha(Pilha **topo, char valor) {
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
    
    if (novo != NULL) {
        novo->dado = valor;
        novo->prox = *topo; 
        *topo = novo;       
    }
}

void desempilha(Pilha **topo) {
    if (*topo != NULL) {
        Pilha *temp = *topo;
        *topo = (*topo)->prox; 
        free(temp);
    }
}

void limparPilha(Pilha **topo) {
    Pilha *atual = *topo;
    Pilha *proxNode;

    while (atual != NULL) {
        proxNode = atual->prox;
        free(atual);
        atual = proxNode;
    }
    *topo = NULL;
}

int main() {
    char caso[1001]; 
    int qtdCasos, i, diamantes;
    Pilha *meuTopo = NULL;

    scanf("%d", &qtdCasos);

    while (qtdCasos > 0) {
        diamantes = 0;
        scanf(" %[^\n]", caso); 

        for (i = 0; caso[i] != '\0'; i++) {
            
            if (caso[i] == '<') {
                empilha(&meuTopo, '<');
            }
            else if (caso[i] == '>') {
                if (meuTopo != NULL) {
                    desempilha(&meuTopo);
                    diamantes++;
                }
            }
        }

        printf("%d\n", diamantes);
        limparPilha(&meuTopo); 
        
        qtdCasos--;
    }

    return 0;
}
