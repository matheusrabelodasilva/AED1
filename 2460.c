#include <stdio.h>
#include <stdbool.h>
#define MAX_ID 100001
int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    int fila_inicial[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &fila_inicial[i]);
    }
    bool deixou_a_fila[MAX_ID];
    for (int i = 0; i < MAX_ID; i++) {
        deixou_a_fila[i] = false;
    }
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        int id_desistente;
        scanf("%d", &id_desistente);
        deixou_a_fila[id_desistente] = true;
    }
    bool primeiro_a_imprimir = true;
    for (int i = 0; i < n; i++) {
        int id_pessoa_atual = fila_inicial[i];
        if (!deixou_a_fila[id_pessoa_atual]) {
            if (primeiro_a_imprimir) {
                printf("%d", id_pessoa_atual);
                primeiro_a_imprimir = false;
            } else {
                printf(" %d", id_pessoa_atual);
            }
        }
    }
    printf("\n");
    return 0;
}
