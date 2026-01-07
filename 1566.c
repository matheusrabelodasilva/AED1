#include <stdio.h>
int main() {
    int num_casos_teste;
    if (scanf("%d", &num_casos_teste) != 1) return 0;
    while (num_casos_teste--) {
        int num_cidadaos;
        if (scanf("%d", &num_cidadaos) != 1) break;
        int frequencia_alturas[231];
        for (int i = 0; i < 231; i++) {
            frequencia_alturas[i] = 0;
        }
        for (int i = 0; i < num_cidadaos; i++) {
            int altura_atual;
            scanf("%d", &altura_atual);
            frequencia_alturas[altura_atual]++;
        }
        int primeiro_numero_impresso = 1;
        for (int altura = 20; altura <= 230; altura++) {
            int quantidade = frequencia_alturas[altura];
            for (int i = 0; i < quantidade; i++) {
                if (primeiro_numero_impresso) {
                    printf("%d", altura);
                    primeiro_numero_impresso = 0; 
                } else {
                    printf(" %d", altura);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
