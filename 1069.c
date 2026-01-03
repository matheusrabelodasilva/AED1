#include <stdio.h>
#include <string.h>

int main() {
    int qtdCasos;
    char caso[1001];

    scanf("%d", &qtdCasos);

    while (qtdCasos--) {
        scanf("%s", caso); // Lê a string (mina de diamantes)

        int top = -1;      // Minha "Pilha": controla quantos '<' estão abertos
        int diamantes = 0;
        int tamanho = strlen(caso);

        for (int i = 0; i < tamanho; i++) {
            // Se encontrar a abertura de um diamante
            if (caso[i] == '<') {
                top++; // "Empilha": apenas aumento o contador de aberturas
            } 
            // Se encontrar o fechamento E houver algo para fechar na pilha
            else if (caso[i] == '>' && top >= 0) {
                top--;      // "Desempilha": encontrei um par, removo uma abertura
                diamantes++; // Conto um diamante completo
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
