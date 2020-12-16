#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct No
{
    double x, y;
    char identificador;
    struct No *prox;
} No;

typedef struct No *p_no;



p_no insere_lista(p_no lista, int contador_total, double coord_x_atual, double coord_y_atual, char identificador){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->x = coord_x_atual;
    novo->y = coord_y_atual;
    novo->identificador = identificador;
    novo->prox = lista;
    return novo;
}


int *iniciar_vetor(int n)
{
    p_no *vetor;
    vetor = malloc(n * sizeof(p_no));
    for (int i = 0; i < n; i++){
        vetor[i] = NULL;
    }
    return vetor;
}
int *montar_grafo(p_no *grafo, p_no lista,int n){
    p_no novo;
    novo = malloc(sizeof(p_no));
    int idx = 0;

    while(lista){
        novo->x = lista->x;
        novo->y = lista->y;
        novo->identificador = lista->y;
        novo->prox = NULL;
        grafo[idx] = novo;
        lista = lista->prox;
        idx++;
    }
}


int criar_matriz_dist(p_no *vetor, int n, int **matriz){

}
int ** iniciar_matriz(int n);
int main()
{
    double origem_x = 0, origem_y = 0, coord_x_atual = 0, coord_y_atual = 0;
    char identificador;
    int contador_total = 0, idx_origem = 0, **matriz_dist, resposta = 0, limitante = 0;
    p_no lista = NULL, *vetor_grafo;

    scanf("%d %d", origem_x, origem_y);
    while (scanf("%d %d %c%*s"), coord_x_atual, coord_y_atual, identificador)
    {
        if (coord_x_atual == origem_x && coord_y_atual == origem_y)
        {
            idx_origem = contador_total;
        }
        lista = insere_lista(lista, contador_total, coord_x_atual, coord_y_atual, identificador);
        contador_total++;
    }
    vetor_grafo = iniciar_vetor(contador_total);
    vetor_grafo = montar_grafo(vetor_grafo,lista,contador_total);
    matriz_dist = iniciar_matriz(contador_total);
    limitante = criar_matriz_dist(vetor_grafo, contador_total, matriz_dist);
    resposta = calcular_limitante(0, limitante);
    printf("%d\n", resposta);
}