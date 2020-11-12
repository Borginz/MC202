#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *v;
    int ini, fim, N, tamanho;
} Fila;

typedef Fila * p_fila;

p_fila criar_fila(int N) {
    p_fila f;
    f = malloc(sizeof(Fila));
    f->v = malloc(N * sizeof(int));
    f->ini = 0;
    f->fim = 0;
    f->N = N;
    f->tamanho = 0;
    return f;
}
void enfileira(p_fila f, int x) {
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    f->tamanho++;
}

int desenfileira(p_fila f) {
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->N;
    f->tamanho --;
    return x;
}

int eh_vazia(p_fila f){
    return f->tamanho == 0;
}

int eh_cheia(p_fila f, int N){
    return f->tamanho == N;
}

int main() {
    int n, x, i;
    p_fila f;
    f = criar_fila(100);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enfileira(f, x);
    }
    while(!fila_vazia(f)) {
        x = desenfileira(f);
        printf("%d ", x);
    }
    printf("\n");
    // destroi_fila(f);
    return 0;
}

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.