#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int dado;
    struct No * esq;
    struct No * dir;
}No;
typedef No * p_no;

p_no criar_arvore ( int x, p_no esq, p_no dir{
    p_no raiz = malloc(sizeof(No));
    raiz->dado = x;
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
}
int numeros_nos(p_no raiz, int l, int nivel){
    if (raiz == NULL)
        return 0;
    if (nivel == l)
        return 1;

    return numeros_nos(raiz->esq, l, nivel+1) + numeros_nos(raiz->dir, l, nivel+1);    
}
