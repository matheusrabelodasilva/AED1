#include <stdio.h>
#include <stdlib.h>
#define MAX_N 30100
typedef struct no {
    int destino;
    struct no *prox;
} No;
typedef struct {
    No **adj;
} Grafo;
int visitado[MAX_N];
int tem_ciclo;
Grafo* criarGrafo(int n) {
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->adj = (No **)malloc((n + 1) * sizeof(No *));
    for (int i = 0; i <= n; i++) {
        g->adj[i] = NULL;
    }
    return g;
}
void inserirAresta(Grafo *g, int u, int v) {
    No *novo = (No *)malloc(sizeof(No));
    novo->destino = v;
    novo->prox = g->adj[u];
    g->adj[u] = novo;
}
void liberarGrafo(Grafo *g, int n) {
    for (int i = 0; i <= n; i++) {
        No *atual = g->adj[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
}
void dfs(Grafo *g, int u) {
    visitado[u] = 1;
    No *ptr = g->adj[u];
    while (ptr != NULL) {
        int v = ptr->destino;
        if (visitado[v] == 1) {
            tem_ciclo = 1;
            return;
        }
        if (visitado[v] == 0) {
            dfs(g, v);
            if (tem_ciclo) return;
        }
        ptr = ptr->prox;
    }
    visitado[u] = 2;
}
int main() {
    int K, N, M, u, v;
    if (scanf("%d", &K) != 1) return 0;
    while (K--) {
        if (scanf("%d %d", &N, &M) != 2) break;
        Grafo *grafo = criarGrafo(N);
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &u, &v);
            inserirAresta(grafo, u, v);
        }
        for (int i = 0; i <= N; i++) {
            visitado[i] = 0;
        }
        tem_ciclo = 0;

        for (int i = 1; i <= N; i++) {
            if (visitado[i] == 0) {
                dfs(grafo, i);
                if (tem_ciclo) break;
            }
        }
        printf("%s\n", tem_ciclo ? "SIM" : "NAO");
        liberarGrafo(grafo, N);
    }
    return 0;
}
