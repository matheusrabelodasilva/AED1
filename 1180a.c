#include <stdio.h>
int main() {
    int n;
    int x[1000];
    int menor;
    int posicao = 0;
    printf("DIGITE O NUMERO DE ELEMENTOS (ENTRE 1 E 1000): ");
    scanf("%d", &n);
    while (n < 1 || n > 1000) {
        printf("VALOR INVALIDO. DIGITE UM VALOR ENTRE 1 E 1000: ");
        scanf("%d", &n);
    }
    printf("DIGITE OS %d VALORES PARA O VETOR:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    menor = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] < menor) {
            menor = x[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao + 1);
    return 0;
}
