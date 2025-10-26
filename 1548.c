#include <stdio.h>
#include <stdlib.h>
int comparar_decrescente(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    return int_b - int_a;
}
int main() {
    int n;
    scanf("%d", &n);
    while (n > 0) {
        int m;
        scanf("%d", &m);
        int ordem_chegada[m];
        int ordem_ordenada[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &ordem_chegada[i]);
            ordem_ordenada[i] = ordem_chegada[i];
        }
        qsort(ordem_ordenada, m, sizeof(int), comparar_decrescente);
        int contador_nao_mudou = 0;
        for (int i = 0; i < m; i++) {
            if (ordem_chegada[i] == ordem_ordenada[i]) {
                contador_nao_mudou++;
            }
        }
        printf("%d\n", contador_nao_mudou);
        n--;
    }
    return 0;
}
