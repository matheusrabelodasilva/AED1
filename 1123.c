#include <stdio.h>
#include <stdlib.h>

#define INFINITO 99999999
#define MAX 255

int adj[MAX][MAX];
int dist[MAX];
int visitado[MAX];

int main() {
    int N, M, C, K;
    int u, v, p, i, j;
    int menor_dist, atual;

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N != 0 || M != 0 || C != 0 || K != 0)) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                adj[i][j] = INFINITO;
            }
            dist[i] = INFINITO;
            visitado[i] = 0;
            adj[i][i] = 0;
        }

        for (i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &p);
            if (p < adj[u][v]) {
                adj[u][v] = p;
                adj[v][u] = p;
            }
        }

        dist[K] = 0;

        for (i = 0; i < N; i++) {
            atual = -1;
            menor_dist = INFINITO;

            for (j = 0; j < N; j++) {
                if (!visitado[j] && dist[j] < menor_dist) {
                    menor_dist = dist[j];
                    atual = j;
                }
            }

            if (atual == -1) break;

            visitado[atual] = 1;

            if (atual < C - 1) {
                if (adj[atual][atual + 1] != INFINITO) {
                    if (dist[atual] + adj[atual][atual + 1] < dist[atual + 1]) {
                        dist[atual + 1] = dist[atual] + adj[atual][atual + 1];
                    }
                }
            } else {
                for (v = 0; v < N; v++) {
                    if (adj[atual][v] != INFINITO && !visitado[v]) {
                        if (dist[atual] + adj[atual][v] < dist[v]) {
                            dist[v] = dist[atual] + adj[atual][v];
                        }
                    }
                }
            }
        }

        printf("%d\n", dist[C - 1]);
    }

    return 0;
}
