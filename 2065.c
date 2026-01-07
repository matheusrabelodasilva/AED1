#include <stdio.h>
int main() {
    int N, M, i, j;
    if (scanf("%d %d", &N, &M) != 2) return 0;
    int V[N];
    int tempo_termino_caixa[N]; 
    for (i = 0; i < N; i++) {
        scanf("%d", &V[i]);
        tempo_termino_caixa[i] = 0;
    }
    for (i = 0; i < M; i++) {
        int itens_cliente;
        scanf("%d", &itens_cliente);
        int caixa_escolhido = 0;
        for (j = 1; j < N; j++) {
            if (tempo_termino_caixa[j] < tempo_termino_caixa[caixa_escolhido]) {
                caixa_escolhido = j;
            } 
        }
        tempo_termino_caixa[caixa_escolhido] += itens_cliente * V[caixa_escolhido];
    }
    int tempo_total_final = 0;
    for (i = 0; i < N; i++) {
        if (tempo_termino_caixa[i] > tempo_total_final) {
            tempo_total_final = tempo_termino_caixa[i];
        }
    }
    printf("%d\n", tempo_total_final);
    return 0;
}
