#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No* proximo;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

void empilhar(Pilha* p) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->proximo = p->topo;
    p->topo = novoNo;
}

void desempilhar(Pilha* p) {
    if (p->topo != NULL) {
        No* temp = p->topo;
        p->topo = temp->proximo;
        free(temp);
    }
}

int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

int main() {
    char expressao[1001];

    while (scanf("%s", expressao) != EOF) {
        Pilha pilha = { NULL }; 
        int eh_correta = 1;
        int tamanho = strlen(expressao);

        for (int i = 0; i < tamanho; i++) {
            if (expressao[i] == '(') {
                empilhar(&pilha);
            } else if (expressao[i] == ')') {
                if (estaVazia(&pilha)) {
                    eh_correta = 0;
                    break;
                } else {
                    desempilhar(&pilha);
                }
            }
        }

        if (!estaVazia(&pilha)) {
            eh_correta = 0;
        }

        if (eh_correta) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        while (!estaVazia(&pilha)) {
            desempilhar(&pilha);
        }
    }

    return 0;
}
