#include <stdlib.h>
#include <stdio.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct No * p_no;

typedef struct{
    p_no ini, fim;
} Fila;
typedef Fila * p_fila;

int eh_vazia(p_fila f){
    return f->ini == NULL && f->fim == NULL;
}

p_fila criar_fila() {
    p_fila f;
    f = malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void destruir_lista(p_no lista) {
    if(lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}

void destruir_fila(p_fila f) {
    destruir_lista(f->ini);
    free(f);
}

void enfileira(p_fila f, int x) {
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = NULL;
    if (f->ini == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    
}

int desenfileira(p_fila f) {
    p_no primeiro = f->ini;
    int x = primeiro->dado;
    f->ini - f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(primeiro);
    return x;
}

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.