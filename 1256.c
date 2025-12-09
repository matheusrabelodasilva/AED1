#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void inserir(No **tabela, int chave, int tamanho) {
    int indice = chave % tamanho;
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = chave;
    novo->prox = NULL;

    if (tabela[indice] == NULL) {
        tabela[indice] = novo;
    } else {
        No *temp = tabela[indice];
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

int main() {
    int N, M, C, i, j, valor;
    
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &M, &C);

        No **tabela = (No **)malloc(M * sizeof(No *));
        
        for (j = 0; j < M; j++) {
            tabela[j] = NULL;
        }

        for (j = 0; j < C; j++) {
            scanf("%d", &valor);
            inserir(tabela, valor, M);
        }

        for (j = 0; j < M; j++) {
            printf("%d -> ", j);
            No *temp = tabela[j];
            while (temp != NULL) {
                printf("%d -> ", temp->valor);
                temp = temp->prox;
            }
            printf("\\\n");
        }

        if (i < N - 1) {
            printf("\n");
        }

        for (j = 0; j < M; j++) {
            No *atual = tabela[j];
            while (atual != NULL) {
                No *prox = atual->prox;
                free(atual);
                atual = prox;
            }
        }
        free(tabela);
    }

    return 0;
}
