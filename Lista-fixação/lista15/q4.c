/*
Problema: Escreva uma função que receba duas árvores de busca e imprima todos os elementos das duas
árvores em ordem. Escreva a função mais eficiente que você conseguir.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No_arvore *p_no_arvore;

typedef struct No_lista *p_no_lista;

typedef struct No_arvore {
    int dado;
    struct No_arvore *esq, *dir;
} No_arvore;

typedef struct No_lista {
    int dado;
    struct No_lista *prox;
} No_lista;

p_no_lista inserir_lista(p_no_lista lista, int x) {
    p_no_lista novo;
    novo = malloc(sizeof(No_lista));
    novo->dado = x;
    novo->prox = lista;
    return novo;
}

p_no_lista criar_lista_percorrendo_inordem(p_no_arvore raiz, p_no_lista lista) {
    if (raiz != NULL) {
        criar_lista_percorrendo_inordem(raiz->esq, lista);
        lista = inserir_lista(lista, raiz->dado);
        criar_lista_percorrendo_inordem(raiz->dir, lista);
    }

    return lista;
}

void imprimir_listas_ordem(p_no_lista lista1, p_no_lista lista2) {
    while (lista1 != NULL || lista2 != NULL) 
    {
        if (lista1 == NULL) 
        {
            printf("%d ", lista2->dado);
            lista2 = lista2->prox;
        } 
        else if (lista2 == NULL) 
        {
            printf("%d ", lista1->dado);
            lista1 = lista1->prox;
        } 
        else 
        {
            if (lista1->dado < lista2->dado) 
            {
                printf("%d ", lista1->dado);
                lista1 = lista1->prox;
            } 
            else if (lista2->dado < lista1->dado) 
            {
                printf("%d ", lista2->dado);
                lista2 = lista2->prox;
            } 
            else if (lista1->dado == lista2->dado) 
            {
                printf("%d ", lista1->dado);
                lista1 = lista1->prox;
            }
        }
    }
}


int main() {
    p_no_arvore abb1 = NULL; //imagine uma árvore binária de busca aqui
    p_no_arvore abb2 = NULL; //imagine outra árvore binária de busca aqui
    p_no_lista lista1 = NULL;  //lista para armazenar os números na ordem crescente da abb1
    p_no_lista lista2 = NULL;  //lista para armazenar os números na ordem crescente da abb2

    lista1 = criar_lista_percorrendo_inordem(abb1, lista1);
    lista2 = criar_lista_percorrendo_inordem(abb2, lista2);
    imprimir_listas_ordem(lista1, lista2);
}

// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira