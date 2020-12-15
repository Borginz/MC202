//Problema: Implemente a operação antecessor.

#include <stdio.h>
#include <stdlib.h>

typedef struct No *p_no;

typedef struct No {
    int chave;
    struct No *esq, *dir, *pai;
} No;

p_no antecessor(p_no x) {
    if (x->dir != NULL)
        return minimo(x->esq);
    else
        return ancestral_a_esquerda(x);
}

p_no ancestral_a_esquerda(p_no x) {
    if (x == NULL)
        return NULL;
    if (x->pai == NULL || x->pai->dir == x)
        return x->pai;
    else
        return ancestral_a_esquerda(x->pai);
}

// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira