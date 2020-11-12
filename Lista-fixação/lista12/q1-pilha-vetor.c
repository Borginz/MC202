#include <stdio.h>
#include <math.h>

typedef struct {
    int *v;
    int topo;
} Pilha;

typedef Pilha * p_pilha;

int eh_vazia(p_pilha f){
    return f->topo == 0;
}

int eh_cheia(p_pilha f, int N){
    return f->topo == N;
}

p_pilha criar_pilha(int N) {
    p_pilha f;
    f = malloc(sizeof(Pilha));
    f->v = malloc(N * sizeof(int));
    f->topo = 0;
    return f;
}

void empilhar(p_pilha p, int i) {
    p->v[p->topo] = i;
    p->topo++;
}

int desempilhar(p_pilha p) {
    p->topo--;
    return p->v[p->topo];
}

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.