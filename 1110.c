//fila dinamica, exercicio das cartas
#include <stdio.h>
#include <stdlib.h>
typedef struct No {
    int dado;
    struct No* prox;
} No;
typedef struct Fila {
    No *frente, *traseira;
} Fila;
No* CriarNo(int data) {
    No* NovoNo = (No*)malloc(sizeof(No));
    NovoNo->dado = data;
    NovoNo->prox = NULL;
    return NovoNo;
}
Fila* CriarFila() {
    Fila* q = (Fila*)malloc(sizeof(Fila));
    q->frente = q->traseira = NULL;
    return q;
}
void Enfileirar(Fila* q, int num) {
    No* NovoNo = CriarNo(num);
    if (q->traseira == NULL) {
        q->frente = q->traseira = NovoNo;
        return;
    }
    q->traseira->prox = NovoNo;
    q->traseira = NovoNo;
}

int Desenfileirar(Fila* q) {
    if (q->frente == NULL) {
        return -1;
    }
    No* temp = q->frente;
    int data = temp->dado;
    q->frente = q->frente->prox;
    if (q->frente == NULL) {
        q->traseira = NULL;
    }
    free(temp);
    return data;
}
int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Fila* baralho = CriarFila();
        int Cartas_descartadas[50];
        int contador = 0;
        for (int i = 1; i <= n; i++) {
            Enfileirar(baralho, i);
        }
        while (baralho->frente->prox != NULL) {
            Cartas_descartadas[contador++] = Desenfileirar(baralho);
            int carta_a_mover = Desenfileirar(baralho);
            Enfileirar(baralho, carta_a_mover);
        }
        printf("Cartas Descartadas:");
        for (int i = 0; i < contador; i++) {
            if (i == 0) {
                printf(" %d", Cartas_descartadas[i]);
            } else {
                printf(", %d", Cartas_descartadas[i]);
            }
        }
        printf("\n");
        printf("Cartas Remanescentes: %d\n", baralho->frente->dado);
        free(baralho->frente);
        free(baralho);
    }
    return 0;
}
