#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matriz[30][30];
int visitado[30];
int lista_vertices[30];
int tam_lista;
int total_vertices;

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void busca_profundidade(int u) {
    int v;
    visitado[u] = 1;
    lista_vertices[tam_lista++] = u;
    
    for (v = 0; v < total_vertices; v++) {
        if (matriz[u][v] == 1 && visitado[v] == 0) {
            busca_profundidade(v);
        }
    }
}

int main() {
    int casos, caso_atual = 1;
    int arestas, i, j;
    char origem_c, destino_c;
    int origem, destino;
    int componentes;

    scanf("%d", &casos);

    while (casos > 0) {
        scanf("%d %d", &total_vertices, &arestas);

        for (i = 0; i < total_vertices; i++) {
            visitado[i] = 0;
            for (j = 0; j < total_vertices; j++) {
                matriz[i][j] = 0;
            }
        }

        for (i = 0; i < arestas; i++) {
            scanf(" %c %c", &origem_c, &destino_c);
            origem = origem_c - 'a';
            destino = destino_c - 'a';
            matriz[origem][destino] = 1;
            matriz[destino][origem] = 1;
        }

        printf("Case #%d:\n", caso_atual);
        componentes = 0;

        for (i = 0; i < total_vertices; i++) {
            if (visitado[i] == 0) {
                componentes++;
                tam_lista = 0;
                busca_profundidade(i);
                
                qsort(lista_vertices, tam_lista, sizeof(int), comparar);

                for (j = 0; j < tam_lista; j++) {
                    printf("%c,", lista_vertices[j] + 'a');
                }
                printf("\n");
            }
        }

        printf("%d connected components\n\n", componentes);
        
        caso_atual++;
        casos--;
    }

    return 0;
}
