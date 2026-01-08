#include <stdio.h>
#include <stdlib.h>
int tamanho_str(char *s) {
    int i = 0;
    while (s[i] != '\0' && s[i] != '\n' && s[i] != '\r') i++;
    return i;
}
int compara_str(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}
void copia_str(char *dest, char *orig) {
    int i = 0;
    while (orig[i] != '\0' && orig[i] != '\n' && orig[i] != '\r') {
        dest[i] = orig[i];
        i++;
    }
    dest[i] = '\0';
}
int main() {
    char linha1[1000], linha2[1000], indicado[50];
    char *amigos[500];
    int totalAmigos = 0;
    scanf(" %[^\n]", linha1);
    scanf(" %[^\n]", linha2);
    scanf("%s", indicado);
    int i = 0;
    while (linha1[i] != '\0') {
        if (linha1[i] != ' ') {
            char temp[50];
            int j = 0;
            while (linha1[i] != ' ' && linha1[i] != '\0') {
                temp[j++] = linha1[i++];
            }
            temp[j] = '\0';       
            amigos[totalAmigos] = (char*)malloc((j + 1) * sizeof(char));
            copia_str(amigos[totalAmigos], temp);
            totalAmigos++;
        } else {
            i++;
        }
    }
    int posInsercao = totalAmigos;
    if (compara_str(indicado, "nao") != 0) {
        for (int k = 0; k < totalAmigos; k++) {
            if (compara_str(amigos[k], indicado) == 0) {
                posInsercao = k;
                break;
            }
        }
    }
    i = 0;
    while (linha2[i] != '\0') {
        if (linha2[i] != ' ') {
            char temp[50];
            int j = 0;
            while (linha2[i] != ' ' && linha2[i] != '\0') {
                temp[j++] = linha2[i++];
            }
            temp[j] = '\0';
            for (int k = totalAmigos; k > posInsercao; k--) {
                amigos[k] = amigos[k - 1];
            }
            amigos[posInsercao] = (char*)malloc((j + 1) * sizeof(char));
            copia_str(amigos[posInsercao], temp);
            posInsercao++;
            totalAmigos++;
        } else {
            i++;
        }
    }
    for (int k = 0; k < totalAmigos; k++) {
        printf("%s%c", amigos[k], (k == totalAmigos - 1 ? '\n' : ' '));
        free(amigos[k]);
    }
    return 0;
}
