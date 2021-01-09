//Problema: Escreva uma função para imprimir todos os elementos em um determinado intervalo.

#include <stdio.h>
#include <stdlib.h>

typedef struct No *p_no;

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;


/**
 * Recebe os extremos de um intervalo e uma chave, e retorna 1
 * se essa chave está contida nesse intervalo. Caso contrário,
 * retorna 0.
 **/
int pertence_ao_intervalo(int min, int max, int chave) {
    if (chave >= min && chave <= max)
        return 1;

    return 0;
}


/**
 * Recebe um ponteiro para a raiz de uma árvore binária de busca,
 * os extremos de um intervalo e imprime todos os elementos contidos
 * na árvore pertencentes a esse intervalo.
 **/
void imprimir_ordem_crescente_no_intervalo(p_no raiz, int min, int max) {
    
    if (raiz != NULL) {
        imprimir_ordem_crescente_no_intervalo(raiz->esq, min, max);
        if (pertence_ao_intervalo(min, max, raiz->chave))
            printf("%d\n", raiz->chave);
        imprimir_ordem_crescente_no_intervalo(raiz->dir, min, max);
    }
}

// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira