#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int velocidade;
    int tempo;
    struct node *proximo;
} No;

void enfileirar(No **cabeca, No **cauda, int v, int t) {
    No *novo_no = (No*)malloc(sizeof(No));
    
    if (novo_no != NULL) {
        novo_no->velocidade = v;
        novo_no->tempo = t;
        novo_no->proximo = NULL;

        if (*cabeca == NULL) {
            *cabeca = novo_no;
            *cauda = novo_no;
        } else {
            (*cauda)->proximo = novo_no;
            *cauda = novo_no;
        }
    }
}

void processar_e_limpar(No **cabeca) {
    No *atual = *cabeca;
    No *temp;
    int resultado;

    while (atual != NULL) {
        resultado = 2 * atual->velocidade * atual->tempo;
        printf("%d\n", resultado);

        temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    *cabeca = NULL;
}

int main() {
    int v, t;
    No *inicio = NULL;
    No *fim = NULL;

    while (scanf("%d %d", &v, &t) != EOF) {
        enfileirar(&inicio, &fim, v, t);
    }

    processar_e_limpar(&inicio);

    return 0;
}
