#include <stdio.h>
int matriz[30][30];
int visitado[30];
int total_vertices;
void busca_marcar(int u) {
    visitado[u] = 1; 
    for (int v = 0; v < total_vertices; v++) {
        if (matriz[u][v] == 1 && visitado[v] == 0) {
            busca_marcar(v);
        }
    }
}
int main() {
    int casos, caso_atual = 1;
    int arestas, i, j;
    char origem_c, destino_c;
    if (scanf("%d", &casos) != 1) return 0;
    while (caso_atual <= casos) {
        if (scanf("%d %d", &total_vertices, &arestas) != 2) break;
        for (i = 0; i < total_vertices; i++) {
            visitado[i] = 0;
            for (j = 0; j < total_vertices; j++) {
                matriz[i][j] = 0;
            }
        }
        for (i = 0; i < arestas; i++) {
            scanf(" %c %c", &origem_c, &destino_c);
            int u = origem_c - 'a';
            int v = destino_c - 'a';
            matriz[u][v] = 1;
            matriz[v][u] = 1;
        }
        printf("Case #%d:\n", caso_atual);
        int componentes = 0;
        for (i = 0; i < total_vertices; i++) {
            if (visitado[i] == 0) {
                componentes++;
                int jah_visitado_antes[30];
                for(int k=0; k<total_vertices; k++) jah_visitado_antes[k] = visitado[k];
                busca_marcar(i);
                for (int k = 0; k < total_vertices; k++) {
                    if (jah_visitado_antes[k] == 0 && visitado[k] == 1) {
                        printf("%c,", k + 'a');
                    }
                }
                printf("\n");
            }
        }
        printf("%d connected components\n\n", componentes);
        caso_atual++;
    }
    return 0;
}
