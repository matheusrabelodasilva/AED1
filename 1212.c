#include <stdio.h>
int main() {
    int a, b;
    // Lemos os dois números. O loop para se ambos forem zero.
    while (scanf("%d %d", &a, &b) == 2 && (a != 0 || b != 0)) {
        int carries = 0;  // Contador de quantos "vai um" aconteceram
        int vai_um = 0;   // Guarda o 1 que sobe para a próxima coluna
        // Enquanto um dos números ainda tiver dígitos para somar
        while (a > 0 || b > 0) {
            // Pega o último dígito de cada número
            int digito_a = a % 10;
            int digito_b = b % 10;
            // Soma os dígitos mais o que "veio" da coluna anterior
            int soma = digito_a + digito_b + vai_um;
            if (soma >= 10) {
                carries = carries + 1; // Deu "vai um"!
                vai_um = 1;            // Passa 1 para a próxima soma
            } else {
                vai_um = 0;            // Não passa nada
            }
            // Joga fora o último dígito para pegar o próximo na próxima volta
            a = a / 10;
            b = b / 10;
        }
        // Parte das mensagens (Gramática do Beecrowd)
        if (carries == 0) {
            printf("Nenhuma operação.\n");
        } else if (carries == 1) {
            printf("1 operação .\n");
        } else {
            printf("%d operações.\n", carries);
        }
    }
    return 0;
}
