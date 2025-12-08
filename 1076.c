#include <stdio.h>
#include <string.h>

int main() {
    int testes, inicio, V, A, u, v, movimentos;
    int grafo[50][50];

    scanf("%d", &testes);

    while (testes--) {
        scanf("%d", &inicio);
        scanf("%d %d", &V, &A);

        memset(grafo, 0, sizeof(grafo));
        movimentos = 0;

        while (A--) {
            scanf("%d %d", &u, &v);
            
            if (grafo[u][v] == 0) {
                grafo[u][v] = 1;
                grafo[v][u] = 1;
                movimentos += 2;
            }
        }

        printf("%d\n", movimentos);
    }

    return 0;
}
