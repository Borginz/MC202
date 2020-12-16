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
// Função para copiar todos os parametros e criar um novo no adicionando no inicio da lista ligada
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
// Função que inicia com null cada posição do vetor
p_no *iniciar_vetor(int n)
{
    p_no *vetor;
    vetor = malloc(n * sizeof(No));
    for (int i = 0; i < n; i++)
    {
        vetor[i] = NULL;
    }
    return vetor;
}
// Função que copia todos os nos da lista ligada para o vetor grafo
p_no *montar_grafo(p_no *grafo, p_no lista, int n)
{
    p_no novo;

    int idx = n - 1;

    while (lista)
    {
        novo = malloc(sizeof(No));
        novo->x = lista->x;
        novo->y = lista->y;
        novo->identificador = lista->identificador;
        novo->prox = NULL;
        grafo[idx] = novo;
        idx--;
        lista = lista->prox;
    }
    return grafo;
}
// Função que calcula a maior arresta dois a dois do grafo, criando uma matriz de distancia
int criar_matriz_dist(p_no *vetor, int n, int **matriz)
{
    int limitante = 0;
    double distancia = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            distancia = sqrt(pow(vetor[i]->x - vetor[j]->x, 2) + pow(vetor[i]->y - vetor[j]->y, 2));
            int dist_int = ceil(distancia);
            matriz[i][j] = dist_int;
            matriz[j][i] = dist_int;
            if (dist_int > limitante)
            {
                limitante = dist_int;
            }
        }
    }
    return limitante;
}

// Função que cria matriz de distancia e inica com tudo 0 
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
// Função que vai percorrendo até achar um lugia e com condição de ser menor que o limitante
int busca_rec(p_no *vetor, int *visitado, int v, int limitante, int n, int **matriz)
{
    int w;
    if (vetor[v]->identificador == 'L')
        return 1;
    visitado[v] = 1;
    for (w = 0; w < n; w++)
        if (matriz[v][w] <= limitante && !visitado[w])
            if (busca_rec(vetor, visitado, w, limitante, n, matriz))
                return 1;
    return 0;
}
// Função que devolve se encontrou um caminhho a partir da origem para um limitante.
int existe_caminho(p_no *vetor, int idx_origem, int limitante, int contador_total, int **matriz)
{
    int encontrou, i, *visitado = malloc(contador_total * sizeof(int));
    for (i = 0; i < contador_total; i++)
        visitado[i] = 0;
    encontrou = busca_rec(vetor, visitado, idx_origem, limitante, contador_total, matriz);
    free(visitado);
    return encontrou;
}
// Função que calcula o limitante por busca binaria para otimizar o codigo, sendo a resposta o ultimo elemento
int calcular_limitante(int inf, int limitante, int idx_origem, p_no *vetor, int contador_total, int **matriz)
{
    int resposta = 0;

    while (inf < limitante)//verificação dos limites
    {
        int media = ((inf + limitante) / 2);
        if (existe_caminho(vetor, idx_origem, media, contador_total, matriz))// se existir caminho sei que é menor que o atual
        {
            resposta = media;
            limitante = media;
        }
        else// se nao existir sei que esta para cima
        {
            inf = media + 1;
        }
    }

    return resposta;
}
// libero lista
void liberar_lista(p_no lista)
{
    p_no aux;
    
        while (lista){
            aux = lista;
            lista = lista->prox;
            free(aux);
        }    

}
//libero vetor
void liberar_vetor(p_no *vetor, int m){
    for( int i = 0; i < m; i++){
        free(vetor[i]);
    }
    free(vetor);

}
//libero matriz
void liberar_matriz(int **M, int m)
{
    int i;
    for (i = 0; i < m; i++)
        free(M[i]);
    free(M);
}

int main()
{
    double origem_x = 0, origem_y = 0, coord_x_atual = 0, coord_y_atual = 0;
    char identificador;
    int contador_total = 0, idx_origem = 0, **matriz_dist, resposta = 0, limitante = 0;
    p_no lista = NULL, *vetor_grafo;

    scanf("%lf %lf", &origem_x, &origem_y);
    while (scanf("%lf %lf %c%*s", &coord_x_atual, &coord_y_atual, &identificador) != EOF)
    {
        if (coord_x_atual == origem_x && coord_y_atual == origem_y)
        {
            idx_origem = contador_total;
        }
        lista = insere_lista(lista, contador_total, coord_x_atual, coord_y_atual, identificador);
        contador_total++;
    }
    vetor_grafo = iniciar_vetor(contador_total);
    vetor_grafo = montar_grafo(vetor_grafo, lista, contador_total);//monto o grafo a partir da lista_ligada
    matriz_dist = iniciar_matriz(contador_total);
    limitante = criar_matriz_dist(vetor_grafo, contador_total, matriz_dist);// a maior aresta que existe
    resposta = calcular_limitante(0, limitante, idx_origem, vetor_grafo, contador_total, matriz_dist);
    printf("%d\n", resposta);
    liberar_matriz(matriz_dist,contador_total);
    liberar_vetor(vetor_grafo, contador_total);
    liberar_lista(lista);
}