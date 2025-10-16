#include <stdio.h>
#include <string.h>
void zera_frequencia(int array[], int tamanho) {
    memset(array, 0, tamanho * sizeof(int));
}
int main() {
    int num_casos_teste;
    scanf("%d", &num_casos_teste);
    while (num_casos_teste--) {
        int num_cidadaos;
        scanf("%d", &num_cidadaos);
        int frequencia_alturas[231];
        zera_frequencia(frequencia_alturas, 231);
        for (int i = 0; i < num_cidadaos; i++) {
            int altura_atual;
            scanf("%d", &altura_atual);
            if (altura_atual >= 20 && altura_atual <= 230) {
                frequencia_alturas[altura_atual]++;
            }
        }
        int primeiro_numero_impresso = 1;
        for (int altura = 20; altura <= 230; altura++) {
            int count = frequencia_alturas[altura];
            for (int i = 0; i < count; i++) {
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
