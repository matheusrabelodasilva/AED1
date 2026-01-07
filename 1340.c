#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *dados;
    int topo;
} Pilha;
void iniciar_pilha(Pilha *p, int cap) {
    p->dados = (int *)malloc(sizeof(int) * cap);
    p->topo = -1;
}
void empilhar(Pilha *p, int val) {
    p->dados[++p->topo] = val;
}
int espiar_pilha(Pilha *p) {
    return p->dados[p->topo];
}
void desempilhar(Pilha *p) {
    p->topo--;
}
typedef struct {
    int *dados;
    int frente;
    int tras;
    int tamanho;
    int capacidade;
} Fila;
void iniciar_fila(Fila *f, int cap) {
    f->dados = (int *)malloc(sizeof(int) * cap);
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
    f->capacidade = cap;
}
void enfileirar(Fila *f, int val) {
    f->tras = (f->tras + 1) % f->capacidade; // Fila circular
    f->dados[f->tras] = val;
    f->tamanho++;
}
int espiar_fila(Fila *f) {
    return f->dados[f->frente];
}
void desenfileirar(Fila *f) {
    f->frente = (f->frente + 1) % f->capacidade; 
    f->tamanho--;
}
typedef struct {
    int *dados;
    int tamanho;
} FilaPrioridade;
int comparar(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}
void iniciar_fp(FilaPrioridade *fp, int cap) {
    fp->dados = (int *)malloc(sizeof(int) * cap);
    fp->tamanho = 0;
}
void inserir_fp(FilaPrioridade *fp, int val) {
    fp->dados[fp->tamanho++] = val;
}
int espiar_fp(FilaPrioridade *fp) {
    qsort(fp->dados, fp->tamanho, sizeof(int), comparar);
    return fp->dados[0];
}
void remover_fp(FilaPrioridade *fp) {
    qsort(fp->dados, fp->tamanho, sizeof(int), comparar);
    for (int i = 0; i < fp->tamanho - 1; i++) {
        fp->dados[i] = fp->dados[i + 1];
    }
    fp->tamanho--;
}
int main() {
    int n, tipo_op, valor;
    while (scanf("%d", &n) != EOF) {
        Pilha p;
        Fila f;
        FilaPrioridade fp;
        iniciar_pilha(&p, n);
        iniciar_fila(&f, n);
        iniciar_fp(&fp, n);
        bool eh_pilha = true, eh_fila = true, eh_fp = true;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &tipo_op, &valor);
            if (tipo_op == 1) { 
                if (eh_pilha) empilhar(&p, valor);
                if (eh_fila) enfileirar(&f, valor);
                if (eh_fp) inserir_fp(&fp, valor);
            } else { 
                if (eh_pilha) {
                    if (p.topo == -1 || espiar_pilha(&p) != valor) eh_pilha = false;
                    else desempilhar(&p);
                }
                if (eh_fila) {
                    if (f.tamanho == 0 || espiar_fila(&f) != valor) eh_fila = false;
                    else desenfileirar(&f);
                }
                if (eh_fp) {
                    if (fp.tamanho == 0 || espiar_fp(&fp) != valor) eh_fp = false;
                    else remover_fp(&fp);
                }
            }
        }
        int possiveis = eh_pilha + eh_fila + eh_fp;
        if (possiveis == 0) printf("impossivel\n");
        else if (possiveis > 1) printf("sem certeza\n");
        else {
            if (eh_pilha) printf("pilha\n");
            else if (eh_fila) printf("fila\n");
            else printf("fila de prioridade\n");
        }
        free(p.dados);
        free(f.dados);
        free(fp.dados);
    }
    return 0;
}
