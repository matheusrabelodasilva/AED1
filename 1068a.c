#include <stdio.h>
#include <string.h>

int main() {
    char expressao[1001];

    while (scanf("%s", expressao) != EOF) {
        int saldo = 0;
        int tamanho = strlen(expressao);

        for (int i = 0; i < tamanho; i++) {
            if (expressao[i] == '(') {
                saldo++;
            } else if (expressao[i] == ')') {
                saldo--;
            }

            if (saldo < 0) {
                break;
            }
        }

        if (saldo == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
