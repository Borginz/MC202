//Problema: Escreva uma função para imprimir as chaves de uma árvore de busca em ordem inversa.

#include <stdio.h>
#include <stdlib.h>

typedef struct No *p_no;

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

void pos_ordem(p_no raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->dir);
        pos_ordem(raiz->esq);
        printf("%d ", raiz->chave); /* visita raiz */
    }

// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira