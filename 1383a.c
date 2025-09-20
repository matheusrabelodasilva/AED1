#include <stdio.h>

int verifica_bloco(int bloco[9]) {
    int vistos[10] = {0};
    int i;
    int num;

    for (i = 0; i < 9; i++) {
        num = bloco[i];
        if (num < 1 || num > 9 || vistos[num]) {
            return 0; 
        }
        vistos[num] = 1; 
    }
    return 1; 
}

int eh_solucao_valida(int matriz[9][9]) {
    int i, j, k;
    int i_bloco, j_bloco;
    
    for (i = 0; i < 9; i++) {
        if (!verifica_bloco(matriz[i])) {
            return 0;
        }
    }

    for (j = 0; j < 9; j++) {
        int coluna[9];
        for (i = 0; i < 9; i++) {
            coluna[i] = matriz[i][j];
        }
        if (!verifica_bloco(coluna)) {
            return 0;
        }
    }

    for (i_bloco = 0; i_bloco < 9; i_bloco += 3) {
        for (j_bloco = 0; j_bloco < 9; j_bloco += 3) {
            int sub_matriz[9];
            k = 0;
            for (i = i_bloco; i < i_bloco + 3; i++) {
                for (j = j_bloco; j < j_bloco + 3; j++) {
                    sub_matriz[k++] = matriz[i][j];
                }
            }
            if (!verifica_bloco(sub_matriz)) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n;
    int k;
    int i, j;
    int matriz[9][9];

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", k);
        if (eh_solucao_valida(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
