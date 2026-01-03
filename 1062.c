//Exercicio sobre trens, Pilha
#include <stdio.h>
#define max_vagoes 1001
int main() {
    int n;
    int ordem[max_vagoes];
    int pilha_estacao[max_vagoes];
    int primeiro_vagao;
    while (scanf("%d", &n) == 1 && n != 0) {
        while (1) {
            scanf("%d", &primeiro_vagao);
            if (primeiro_vagao == 0) {
                printf("\n");
                break;
            }
            ordem[0] = primeiro_vagao;
            for (int i = 1; i < n; i++) {
                scanf("%d", &ordem[i]);
            }
            int ponteiro = -1;
            int alvo = 0;
            for (int j = 1; j <= n; j++) {
                pilha_estacao[++ponteiro] = j;
                while (top != -1 && pilha_estacao[ponteiro] == ordem[alvo]) {
                    ponteiro--;
                    alvo++;
                }
            }
            if (ponteiro == -1) {
                printf("Sim\n");
            } else {
                printf("Nao\n");
            }
        }
    }
    return 0;
}
