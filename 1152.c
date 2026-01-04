//dijkstra, exercicio da guerra 
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARESTAS 200005
typedef struct {
    int u, v, peso;
} Estrada;
Estrada lista[MAX_ARESTAS];
int grupos[MAX_ARESTAS];
// Função para ordenar as estradas da mais barata para a mais cara
int comparar(const void *a, const void *b) {
    return ((Estrada*)a)->peso - ((Estrada*)b)->peso;
}
// Função que descobre a qual grupo uma cidade pertence
int buscar_grupo(int i) {
    if (grupos[i] == i)
        return i;
    return grupos[i] = buscar_grupo(grupos[i]); // Otimização: aponta direto para o chefe do grupo
}
int main() {
    int m, n;   
    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        long long custo_total_original = 0; // Usamos long long porque o valor pode ser alto
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &lista[i].u, &lista[i].v, &lista[i].peso);
            custo_total_original += lista[i].peso;
        }
        // 1. Ordenamos para priorizar as estradas mais baratas
        qsort(lista, n, sizeof(Estrada), comparar);
        // 2. Inicialmente, cada cidade é seu próprio grupo
        for (int i = 0; i < m; i++) {
            grupos[i] = i;
        }
        long long custo_minimo_conectar = 0;
        int conexoes_feitas = 0;
        // 3. Percorremos as estradas baratas e vamos unindo as cidades
        for (int i = 0; i < n; i++) {
            int raiz_u = buscar_grupo(lista[i].u);
            int raiz_v = buscar_grupo(lista[i].v);
            // Se as cidades estão em grupos diferentes, precisamos dessa estrada!
            if (raiz_u != raiz_v) {
                grupos[raiz_u] = raiz_v; // Une os grupos
                custo_minimo_conectar += lista[i].peso;
                conexoes_feitas++;
            }
            // Se já estão no mesmo grupo, ignoramos a estrada (economia!)
        }
        // A resposta é a diferença entre o que tínhamos e o que realmente precisamos
        printf("%lld\n", custo_total_original - custo_minimo_conectar);
    }
    return 0;
}
