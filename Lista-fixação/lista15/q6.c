
#include <stdio.h>
#include <stdlib.h>

typedef struct No_arvore *p_no;

typedef struct No_arvore {
    int chave;
    struct No_arvore *esq, *dir, *pai;
} No_arvore;

p_no remover_rec(p_no raiz, int chave) {
    if (raiz == NULL)
        return NULL;
    if (chave < raiz->chave)
        raiz->esq = remover_rec(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = remover_rec(raiz->dir, chave);
    else if (raiz->esq == NULL)
        return raiz->dir;
    else if (raiz->dir == NULL)
        return raiz->esq;
    else
        remover_sucessor(raiz);
    return raiz;
}

void remover_sucessor(p_no raiz) {
    p_no min = raiz->dir; /*será o mínimo da subárvore direita*/
    p_no pai = raiz;      /*será o pai de min*/
    while (min->esq != NULL) {
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;
    raiz->chave = min->chave;
}


p_no inserir_arvore(p_no raiz, int dado) {
    if (raiz == NULL) {
        p_no novo;
        novo = malloc(sizeof(No_arvore));
        novo->chave = dado;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    else if (raiz->chave > dado) {
        raiz->esq = inserir_arvore(raiz->esq, dado);
    } 
    else {
        raiz->dir = inserir_arvore(raiz->dir, dado);
    }
    return raiz;
}
// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira