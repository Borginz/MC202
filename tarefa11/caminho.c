#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct No
{
    double x, y;
    char identificador;
    struct No *prox;
} No;

typedef struct No *p_no;

p_no insere_lista(p_no lista, int contador_total, double coord_x_atual, double coord_y_atual, char identificador)
{
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
    for (int i = 0; i < n; i++)
    {
        vetor[i] = NULL;
    }
    return vetor;
}
int *montar_grafo(p_no *grafo, p_no lista, int n)
{
    p_no novo;
    novo = malloc(sizeof(p_no));
    int idx = n - 1;

    while (lista)
    {
        novo->x = lista->x;
        novo->y = lista->y;
        novo->identificador = lista->y;
        novo->prox = NULL;
        grafo[idx] = novo;
        lista = lista->prox;
        idx--;
    }
}

int criar_matriz_dist(p_no *vetor, int n, int **matriz)
{
    int limitante = vetor[0];
    int distancia;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            distancia = sqrt(pow(vetor[i]->x - vetor[j]->x, 2) + pow(vetor[i]->y - vetor[j]->y, 2));
            ceil(distancia);
            matriz[i][j] = distancia;
            matriz[j][i] = distancia;
            if (distancia > limitante)
            {
                limitante = distancia;
            }
        }
    }
    return limitante;
}
int **iniciar_matriz(int n)
{
    int **matriz = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

int busca_rec(p_no * vetor, int *visitado, int v, int limitante, int n, int **matriz)
{
    int w;
    if (vetor[v]->identificador == 'L')
        return 1; 
    visitado[v] = 1;
    for (w = 0; w < n; w++)
        if (matriz[v][w] < limitante && !visitado[w])
            if (busca_rec(vetor, visitado, w, limitante,n,matriz))
                return 1;
    return 0;
}

int existe_caminho(p_no *vetor, int idx_origem, int limitante, int contador_total, int **matriz)
{
    int encontrou, i, *visitado = malloc(contador_total * sizeof(int));
    for (i = 0; i < contador_total; i++)
        visitado[i] = 0;
    encontrou = busca_rec(vetor, visitado, idx_origem,limitante,contador_total,matriz);
    free(visitado);
    return encontrou;
}

int calcular_limitante(int inf, int limitante, int idx_origem, p_no *vetor,int contador_total,int **matriz)
{
    int resposta = 0;
    while (inf != limitante)
    {
        int media = limitante / 2;
        if (existe_caminho(vetor,idx_origem,media,contador_total,matriz))
        {
            resposta = media;
            limitante = media - 1 ;
        }
        else
            {
                inf = media + 1;
            }
        return resposta;
    }
}    
    int main()
    {
        double origem_x = 0, origem_y = 0, coord_x_atual = 0, coord_y_atual = 0;
        char identificador;
        int contador_total = 0, idx_origem = 0, **matriz_dist, resposta = 0, limitante = 0;
        p_no lista = NULL, *vetor_grafo;

        scanf("%d %d", origem_x, origem_y);
        while (scanf("%d %d %c%*s", coord_x_atual, coord_y_atual, identificador)!=EOF)
        {
            if (coord_x_atual == origem_x && coord_y_atual == origem_y)
            {
                idx_origem = contador_total;
            }
            lista = insere_lista(lista, contador_total, coord_x_atual, coord_y_atual, identificador);
            contador_total++;
        }
        vetor_grafo = iniciar_vetor(contador_total);
        vetor_grafo = montar_grafo(vetor_grafo, lista, contador_total);
        matriz_dist = iniciar_matriz(contador_total);
        limitante = criar_matriz_dist(vetor_grafo, contador_total, matriz_dist);
        resposta = calcular_limitante(0, limitante, idx_origem);
        printf("%d\n", resposta);
    }