#include <stdio.h>
#include <stdlib.h>

typedef struct no_complexo{
    float real;
    float complexo;
    struct no_complexo * prox;

} no_complexo;

typedef struct sequencia_complexos{

    struct no_complexo * ini;
    struct no_complexo * fim;

} sequencia_complexos;

sequencia_complexos * iniciar_sequencia(){
    sequencia_complexos * sequencia = malloc(sizeof(sequencia_complexos*));
    sequencia->ini == NULL;
    sequencia->fim == NULL;
    return sequencia;
}

void adicionar(float real, float complexo, sequencia_complexos * sequencia){
    no_complexo * novo_no = malloc(sizeof(no_complexo *));
    no_complexo->real = real;
    no_complexo->complexo = complexo;
    sequencia->fim->prox = no_complexo;
    no_complexo->prox = NULL;
    sequencia->fim = no_complexo;

}

void destruir_sequencia(sequencia_complexos * sequencia){
    no_complexo * atual = sequencia->ini;
    no_complexo * aux;
    while(atual != sequencia->fim){
        aux = atual;
        atual = atual->prox;
        free(aux);
    }
    free(atual);
    free(sequencia);
}

sequencia_complexos * concatenar_sequencias(sequencia_complexos * sequencia1, sequencia_complexos * sequencia2){
    sequencia_complexos * sequenciares = iniciar_sequencia();
    no_complexo * atual = sequencia1->ini;
    while (atual != sequencia1->fim){
        adicionar(atual->real, atual->complexo, sequenciares);
        atual = atual->prox;
    }
    adicionar(atual->real, atual->complexo, sequenciares);
    atual = sequencia2->ini;
    while (atual != sequencia2->fim){
        adicionar(atual->real, atual->complexo, sequenciares);
        atual = atual->prox;
    }
    adicionar(atual->real, atual->complexo, sequenciares);
    return sequenciares;
}

int comparar_sequencias(sequencia_complexos * sequencia1, sequencia_complexos * sequencia2);

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.