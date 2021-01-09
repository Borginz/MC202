#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_deque{
    int valor;
    struct no_deque *prox;
    struct no_deque *ant;
} no_deque;

typedef struct no_deque * p_no_deque;


typedef struct deque{
    p_no_deque ini, fim;
} deque;

typedef struct deque * p_deque;

void insere_inicio(p_deque deque1, int valor){
    p_no_deque novo = malloc(sizeof(no_deque)); 
    novo->valor = valor;
    novo->ant = deque1->fim; 
    novo->prox = NULL;
    if(deque1->ini == NULL){
        deque1->ini = novo;
    } else{
        deque1->fim->prox = novo; 
    deque1->fim = novo;
}

void insere_fim(p_deque deque1, int valor){
    p_no_deque novo = malloc(sizeof(no_deque)); 
    novo->valor = valor; 
    novo->prox = deque1->ini; 
    novo->ant = NULL;
    if(deque1->fim == NULL){
        deque1->fim = novo;
    } else{
        deque1->ini->ant = novo;
    deque1->ini = novo;
}

int remove_fim(p_deque deque1){ 
    int valor = ultimo->valor;
    deque1->fim = deque1->fim->ant;
    if (deque1->fim == NULL)
        deque1->ini = NULL;
    free(ultimo);
    return valor;
}

int remove_inicio(p_deque deque1){ 
    p_no_deque primeiro = deque1->ini;
    int valor = primeiro->valor;
    deque1->ini = deque1->ini->prox;
    if (deque1->ini == NULL)
        deque1->fim = NULL;
    free(primeiro);
    return valor;    
}

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.