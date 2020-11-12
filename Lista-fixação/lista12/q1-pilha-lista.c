#include <stdio.h>
#include <math.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct No * p_no;

typedef struct Pilha {
    p_no topo;
} Pilha;

typedef Pilha * p_pilha;

int eh_vazia(p_pilha f){
    return f->topo == NULL;
}

p_pilha criar_pilha(){
    p_pilha f;
    f = malloc(sizeof(Pilha));
    f->topo = NULL;
    return f;
}

void empilhar(p_pilha pilha, int x) {
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(p_pilha pilha) {
    p_no topo = pilha->topo;
    int x = topo->dado;
    pilha->topo = pilha->topo->prox;
    free(topo);
    return x;
}

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.