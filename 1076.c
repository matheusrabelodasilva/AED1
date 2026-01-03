//grafo simples nao direcionado com matriz de adjacencia 
#include <stdio.h>
#include <string.h>

int main() {
    int testes, inicio, V, A, u, v, movimentos;
    int grafo[50][50];

    scanf("%d", &testes);

    while (testes--) {
        scanf("%d", &inicio);
        scanf("%d %d", &V, &A);

        memset(grafo, 0, sizeof(grafo));// limpa o grafo para analisarmos as proximas arestas
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
