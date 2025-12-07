#include <stdio.h>
#include <stdlib.h>

#define INF 100000000
#define MAX_N 505

int adj[MAX_N][MAX_N];
int conexao[MAX_N][MAX_N];
int grafo_final[MAX_N][MAX_N];
int distancias[MAX_N];
int visitado[MAX_N];

void dijkstra(int N, int origem, int destino) {
    int i, v, count;
    
    for (i = 1; i <= N; i++) {
        distancias[i] = INF;
        visitado[i] = 0;
    }
    distancias[origem] = 0;

    for (count = 1; count <= N; count++) {
        int u = -1;
        int min_val = INF;

        for (i = 1; i <= N; i++) {
            if (!visitado[i] && distancias[i] < min_val) {
                min_val = distancias[i];
                u = i;
            }
        }

        if (u == -1 || distancias[u] == INF) break;
        visitado[u] = 1;
        if (u == destino) break;

        for (v = 1; v <= N; v++) {
            if (grafo_final[u][v] != INF) {
                if (distancias[u] + grafo_final[u][v] < distancias[v]) {
                    distancias[v] = distancias[u] + grafo_final[u][v];
                }
            }
        }
    }
}

int main() {
    int N, E, K;
    int X, Y, H, O, D;
    int i, j, k;

    while (scanf("%d %d", &N, &E) == 2 && (N != 0 || E != 0)) {
        
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                adj[i][j] = INF;
                conexao[i][j] = INF;
                grafo_final[i][j] = INF;
            }
            adj[i][i] = 0;
            conexao[i][i] = 0;
        }

        for (i = 0; i < E; i++) {
            scanf("%d %d %d", &X, &Y, &H);
            if (adj[X][Y] > H) {
                adj[X][Y] = H;
                conexao[X][Y] = H;
            }
        }

        for (k = 1; k <= N; k++) {
            for (i = 1; i <= N; i++) {
                for (j = 1; j <= N; j++) {
                    if (conexao[i][k] != INF && conexao[k][j] != INF) {
                        if (conexao[i][k] + conexao[k][j] < conexao[i][j]) {
                            conexao[i][j] = conexao[i][k] + conexao[k][j];
                        }
                    }
                }
            }
        }

        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                if (conexao[i][j] != INF && conexao[j][i] != INF) {
                    grafo_final[i][j] = 0;
                } else {
                    grafo_final[i][j] = adj[i][j];
                }
            }
        }

        scanf("%d", &K);
        for (i = 0; i < K; i++) {
            scanf("%d %d", &O, &D);
            
            dijkstra(N, O, D);

            if (distancias[D] == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", distancias[D]);
            }
        }
        
        printf("\n");
    }

    return 0;
}
