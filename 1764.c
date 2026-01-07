#include <stdio.h>
#define MAX_M 40005
#define MAX_N 50005
typedef struct {
    int u, v, peso;
} Aresta;
Aresta arestas[MAX_N];
Aresta auxiliar[MAX_N]; 
int pai[MAX_M];
void intercalar(Aresta arr[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = inicio;
    while (i <= meio && j <= fim) {
        if (arr[i].peso <= arr[j].peso) {
            auxiliar[k++] = arr[i++];
        } else {
            auxiliar[k++] = arr[j++];
        }
    }
    while (i <= meio) auxiliar[k++] = arr[i++];
    while (j <= fim)   auxiliar[k++] = arr[j++];
    for (i = inicio; i <= fim; i++) {
        arr[i] = auxiliar[i];
    }
}
void mergeSort(Aresta arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        intercalar(arr, inicio, meio, fim);
    }
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
    while (scanf("%d %d", &m, &n) == 2 && (m != 0 || n != 0)) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }     
        mergeSort(arestas, 0, n - 1);

        for (int i = 0; i < m; i++) {
            pai[i] = i;
        }

        int soma_total_mst = 0;
        for (int i = 0; i < n; i++) {
            if (encontrar(arestas[i].u) != encontrar(arestas[i].v)) {
                unir(arestas[i].u, arestas[i].v);
                soma_total_mst += arestas[i].peso;
            }
        }
        printf("%d\n", soma_total_mst);
    }
    return 0;
}
