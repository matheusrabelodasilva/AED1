//grafo simples nao direcionado com matriz de adjacencia 
#include <stdio.h>
int main() {
    int testes, inicio, V, A, u, v, movimentos;
    int grafo[50][50];
    if (scanf("%d", &testes) != 1) return 0;
    while (testes--) {
        scanf("%d", &inicio);
        scanf("%d %d", &V, &A);
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                grafo[i][j] = 0;
            }
        }
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
