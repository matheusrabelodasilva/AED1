#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 2147483647
#define MAX_C 10005
#define MAX_V 100050

typedef struct Aresta {
    int destino;
    int peso;
    struct Aresta *prox;
} Aresta;

typedef struct NoHeap {
    int custo;
    int u;
    int paridade;
} NoHeap;

Aresta *adj[MAX_C];
Aresta pool[MAX_V]; 
int pool_ptr;
int dist[MAX_C][2];
NoHeap heap[MAX_V * 5];
int tamanho_heap;

void adicionar_aresta(int u, int v, int w) {
    Aresta *nova = &pool[pool_ptr++];
    nova->destino = v;
    nova->peso = w;
    nova->prox = adj[u];
    adj[u] = nova;
}

void push(int custo, int u, int paridade) {
    tamanho_heap++;
    int i = tamanho_heap;
    while (i > 1) {
        int pai = i / 2;
        if (heap[pai].custo <= custo) break;
        heap[i] = heap[pai];
        i = pai;
    }
    heap[i].custo = custo;
    heap[i].u = u;
    heap[i].paridade = paridade;
}

NoHeap pop() {
    NoHeap topo = heap[1];
    NoHeap ultimo = heap[tamanho_heap--];
    int i = 1;
    while (i * 2 <= tamanho_heap) {
        int filho = i * 2;
        if (filho < tamanho_heap && heap[filho + 1].custo < heap[filho].custo) {
            filho++;
        }
        if (ultimo.custo <= heap[filho].custo) break;
        heap[i] = heap[filho];
        i = filho;
    }
    heap[i] = ultimo;
    return topo;
}

int main() {
    int C, V, c1, c2, g, i;

    while (scanf("%d %d", &C, &V) != EOF) {
        memset(adj, 0, sizeof(adj));
        pool_ptr = 0;

        for (i = 0; i < V; i++) {
            scanf("%d %d %d", &c1, &c2, &g);
            adicionar_aresta(c1, c2, g);
            adicionar_aresta(c2, c1, g);
        }

        for (i = 1; i <= C; i++) {
            dist[i][0] = INF;
            dist[i][1] = INF;
        }

        tamanho_heap = 0;
        dist[1][0] = 0;
        push(0, 1, 0);

        while (tamanho_heap > 0) {
            NoHeap atual = pop();
            int d = atual.custo;
            int u = atual.u;
            int p = atual.paridade;

            if (d > dist[u][p]) continue;

            Aresta *e = adj[u];
            while (e != NULL) {
                int v = e->destino;
                int w = e->peso;
                int novo_p = 1 - p;

                if (dist[u][p] != INF && dist[u][p] + w < dist[v][novo_p]) {
                    dist[v][novo_p] = dist[u][p] + w;
                    push(dist[v][novo_p], v, novo_p);
                }
                e = e->prox;
            }
        }

        if (dist[C][0] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", dist[C][0]);
        }
    }

    return 0;
}
