#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200005

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[MAX_N];
int pai[MAX_N];

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int encontrar(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = encontrar(pai[i]);
}

void unir(int i, int j) {
    int raiz_i = encontrar(i);
    int raiz_j = encontrar(j);
    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
    }
}

int main() {
    int m, n;
    int i;
    
    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        int custo_total = 0;
        
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            custo_total += arestas[i].peso;
        }

        qsort(arestas, n, sizeof(Aresta), comparar);

        for (i = 0; i < m; i++) {
            pai[i] = i;
        }

        int custo_mst = 0;
        
        for (i = 0; i < n; i++) {
            if (encontrar(arestas[i].u) != encontrar(arestas[i].v)) {
                unir(arestas[i].u, arestas[i].v);
                custo_mst += arestas[i].peso;
            }
        }

        printf("%d\n", custo_total - custo_mst);
    }

    return 0;
}
