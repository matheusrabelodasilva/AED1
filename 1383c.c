#include <stdio.h>
#include <stdlib.h>
int verifica_grupo(int grupo[9]) {
    int visto[10] = {0};
    for (int i = 0; i < 9; i++) {
        int num = grupo[i];
        if (num < 1 || num > 9 || visto[num] == 1) {
            return 0;
        }
        visto[num] = 1;
    }
    return 1;
}
int main() {
    int n, instancia;
    scanf("%d", &n);
    for (instancia = 1; instancia <= n; instancia++) {
        int **matriz = (int **)malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++) {
            matriz[i] = (int *)malloc(9 * sizeof(int));
        }
        int solucao_valida = 1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        for (int i = 0; i < 9; i++) {
            int linha[9];
            int coluna[9];
            for (int j = 0; j < 9; j++) {
                linha[j] = matriz[i][j];
                coluna[j] = matriz[j][i];
            }
            if (!verifica_grupo(linha) || !verifica_grupo(coluna)) {
                solucao_valida = 0;
                break;
            }
        }
        if (solucao_valida) {
            for (int i = 0; i < 9; i += 3) {
                for (int j = 0; j < 9; j += 3) {
                    int submatriz[9];
                    int k = 0;
                    for (int sub_i = 0; sub_i < 3; sub_i++) {
                        for (int sub_j = 0; sub_j < 3; sub_j++) {
                            submatriz[k++] = matriz[i + sub_i][j + sub_j];
                        }
                    }
                    if (!verifica_grupo(submatriz)) {
                        solucao_valida = 0;
                        break;
                    }
                }
                if (!solucao_valida) break;
            }
        }
        printf("Instancia %d\n", instancia);
        if (solucao_valida) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
        for (int i = 0; i < 9; i++) {
            free(matriz[i]);
        }
        free(matriz);
    }
    return 0;
}
