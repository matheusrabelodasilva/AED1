#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int X[N];
    int menor_valor;
    int posicao;

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    menor_valor = X[0];
    posicao = 0;

    for (int i = 1; i < N; i++) {
        if (X[i] < menor_valor) {
            menor_valor = X[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
