#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct No
{
    double x,y;
    char identificador;
    struct No *prox;
} No;

typedef struct No *p_no;






int main(){
    double origem_x = 0,origem_y = 0, coord_x_atual = 0, coord_y_atual = 0;
    char identificador;
    int contador_total = 0, idx_origem = 0, **matriz_dist,resposta = 0,limitante = 0;
    p_no lista = NULL, *vetor_grafo;


    scanf("%d %d", origem_x, origem_y);
    while(scanf("%d %d %c%*s"), coord_x_atual,coord_y_atual,identificador){
        if ( coord_x_atual == origem_x && coord_y_atual == origem_y){
            idx_origem = contador_total;
        }
        lista = insere_lista(lista,contador_total,coord_x_atual,coord_y_atual,identificador);
        contador_total++;
    }
    vetor_grafo = iniciar_vetor(contador_total,lista);
    limitante = criar_matriz_dist(vetor_grafo,contador_total,matriz_dist);
    resposta = calcular_limitante(0,limitante);
    printf("%d\n", resposta);




    






}