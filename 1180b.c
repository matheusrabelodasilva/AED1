#include <stdio.h>
#include <stdlib.h>
typedef struct No {
    int dado;
    struct No* proximo;
} No;

int main() {
    int N;
    scanf("%d", &N);

    No* cabeca = NULL;
    No* cauda = NULL;

    for (int i = 0; i < N; i++) {
        int valor;
        scanf("%d", &valor);
        
        No* novo_no = (No*) malloc(sizeof(No));
        novo_no->dado = valor;
        novo_no->proximo = NULL;

        if (cabeca == NULL) {
            cabeca = novo_no;
            cauda = novo_no;
        } else {
            cauda->proximo = novo_no;
            cauda = novo_no;
        }
    }

    int menor_valor = cabeca->dado;
    int posicao = 0;
    
    No* atual = cabeca->proximo;
    int indice_atual = 1;

    while (atual != NULL) {
        if (atual->dado < menor_valor) {
            menor_valor = atual->dado;
            posicao = indice_atual;
        }
        atual = atual->proximo;
        indice_atual++;
    }

    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    atual = cabeca;
    while (atual != NULL) {
        No* proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }

    return 0;
}
