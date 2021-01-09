#include <stdio.h>
#include <stdlib.h>

typedef struct No
{   
    int valor;
    struct No *anterior;
    struct No *proximo;
} No;

typedef struct Lista
{
    No *inicio;
    No *fim;
} Lista;

// Dado o ponteiro para a lista (já inicializada)
// e o valor inteiro x, pode-se inserir no início.
void inserir_elemento_inicio(Lista *lista_dupla, int x)
{
    No *novo;

    novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        exit(1);
    }

    novo->valor = x;
    novo->proximo = lista_dupla->inicio;
    novo->anterior = NULL;

    if (lista_dupla->inicio == NULL)
    {
        lista_dupla->fim = novo;
    }
    else
    {
        lista_dupla->inicio->anterior = novo;
    }
    lista_dupla->inicio = novo;
}

void inserir_elemento_final(Lista *lista_dupla, int x)
{
    No *novo;

    novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        exit(1);
    }

    novo->valor = x;
    novo->anterior = lista_dupla->fim;
    novo->proximo = NULL;

    if (lista_dupla->fim == NULL)
    {
        lista_dupla->inicio = novo;
    }
    else
    {
        lista_dupla->fim->proximo = novo;
    }
    lista_dupla->fim = novo;
}

void remover_elemento(Lista *lista_dupla, int x)
{
    No *aux;

    aux = lista_dupla->inicio;

    while (aux->valor != NULL)
    {
        aux = aux->proximo;
    }

    if (aux != lista_dupla->inicio && aux != lista_dupla->fim)
    {
        aux->proximo->anterior = aux->anterior;
        aux->anterior->proximo = aux->proximo;
        free(aux);
    }
    else if (aux == lista_dupla->inicio){
        aux->proximo->anterior = NULL;
        free(aux);
    }
    else{
        aux->anterior->proximo = NULL;
        free(aux);
    }
}

/*
 * c) O tempo de inserção no fim de uma lista encadeada com ponteiro somente para o início,
 *    é da ordem de O(n). Para que a inserção no fim dessa lista tenha tempo constante, ou seja,
 *    sua complexidade seja O(1), deve-se criar um ponteiro para o fim da lista quando inicializa-se
 *    ela. Esse ponteiro aponta para o último elemento dessa lista encadeada.
 */ 

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.