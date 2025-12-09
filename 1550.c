#include <stdio.h>
#include <string.h>

#define MAX 10005

int distancias[MAX];
int fila[20000];

int inverter(int num) {
    int reverso = 0;
    while (num > 0) {
        reverso = reverso * 10 + num % 10;
        num /= 10;
    }
    return reverso;
}

int bfs(int inicio, int fim) {
    int frente = 0, tras = 0;
    int atual, proximo;

    memset(distancias, -1, sizeof(distancias));

    fila[tras++] = inicio;
    distancias[inicio] = 0;

    while (frente < tras) {
        atual = fila[frente++];

        if (atual == fim) {
            return distancias[atual];
        }

        proximo = atual + 1;
        if (proximo < MAX && distancias[proximo] == -1) {
            distancias[proximo] = distancias[atual] + 1;
            fila[tras++] = proximo;
        }

        proximo = inverter(atual);
        if (proximo < MAX && distancias[proximo] == -1) {
            distancias[proximo] = distancias[atual] + 1;
            fila[tras++] = proximo;
        }
    }
    return 0;
}

int main() {
    int T, A, B;

    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }

    return 0;
}
