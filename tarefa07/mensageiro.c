#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No_arvore
{
    struct No_arvore *dir;
    struct No_arvore *esq;
    long int valor;
    char palavra[2050];
} No_arvore;

typedef struct Triade
{
    No_arvore *x;
    No_arvore *y;
    No_arvore *z;
} Triade;


// Função para inserir na arvore recursivamente analisando a arvore binaria
No_arvore *inserir_arvore(No_arvore *raiz, No_arvore *novo)
{
    if (raiz == NULL)
    {
        return novo;
    }
    else if (raiz->valor > novo->valor)
    {
        raiz->esq = inserir_arvore(raiz->esq, novo);
    }
    else
    {
        raiz->dir = inserir_arvore(raiz->dir, novo);
    }
    return raiz;
}
No_arvore *buscar_triade_z(No_arvore *raiz, long int k)
{
    if (k < 0)
        return NULL;
    if (raiz == NULL || raiz->valor == k)
        return raiz;
    if (raiz->valor > k)
        return buscar_triade_z(raiz->esq, k);
    else
        return buscar_triade_z(raiz->dir, k);
}

void buscar_triade_y(No_arvore *raiz_ori, No_arvore *raiz_atual, long int id, Triade *triade)
{
    if (triade->z != NULL)
    {
        return;
    }
    if (raiz_atual->esq != NULL /*&& raiz_atual->esq->valor > triade->x->valor*/)
    {
        buscar_triade_y(raiz_ori, raiz_atual->esq, id, triade);
        if (triade->z != NULL)
        {
            return;
        }
    }

    triade->y = raiz_atual;
    triade->z = buscar_triade_z(raiz_ori, (id - triade->y->valor));
    if (triade->z != NULL)
    {
        return;
    }
    if (raiz_atual->dir != NULL /*&& raiz_atual->valor < id*/)
    {
        buscar_triade_y(raiz_ori, raiz_atual->dir, id, triade);
        if (triade->z != NULL)
        {
            return;
        }
    }
    triade->y = NULL;
}
// Função para buscar x recursivamente 
void buscar_triade_x(No_arvore *raiz_ori, No_arvore *raiz_atual, long int id, Triade *triade)
{
    if (triade->y != NULL)
    {
        return;
    }
    if (raiz_atual->esq != NULL)
    {
        buscar_triade_x(raiz_ori, raiz_atual->esq, id, triade);
        if (triade->y != NULL)
        {
            return;
        }
    }
    triade->x = raiz_atual;
    buscar_triade_y(raiz_ori, raiz_ori, (id - triade->x->valor), triade);
    if (triade->y != NULL)
    {
        return;
    }
    if (raiz_atual->dir != NULL)
    {
        buscar_triade_x(raiz_ori, raiz_atual->dir, id, triade);
    }
}

No_arvore *remover_sucessor(No_arvore *raiz, Triade *triade)
{

    if (raiz->dir == NULL)
    {
        return NULL;
    }
    No_arvore *min = raiz->dir;
    No_arvore *pai = raiz;
    while (min->esq != NULL)
    {
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;

    raiz->valor = min->valor;
    strcpy(raiz->palavra, min->palavra);
    if ( triade->x == min){
        triade->x = raiz;
    }
    if ( triade->y == min){
        triade->y = raiz;
    }
    if ( triade->z == min){
        triade->z = raiz;
    }
    free(min);
    return raiz;
}

No_arvore *remover_triade(No_arvore *raiz, long int chave, Triade* triade)
{
    No_arvore *aux;
    if (raiz == NULL)
    {
        return NULL;
    }
    if (chave == raiz->valor)
    {
        if (raiz->esq == NULL)
        {
            aux = raiz->dir;
            free(raiz);
            return aux;
        }
        else if (raiz->dir == NULL)
        {
            aux = raiz->esq;
            free(raiz);
            return aux;
        }
        else if (raiz->dir == NULL && raiz->esq == NULL)
        {
            free(raiz);
            return NULL;
        }
        return remover_sucessor(raiz, triade);
    }
    if (chave < raiz->valor)
        raiz->esq = remover_triade(raiz->esq, chave, triade);
    else if (chave > raiz->valor)
        raiz->dir = remover_triade(raiz->dir, chave, triade);
    return raiz;
}

void liberar_no(No_arvore *no)
{
    if (no == NULL)
    {
        return;
    }
    liberar_no(no->esq);
    liberar_no(no->dir);
    free(no);
    no = NULL;
}

void imprimir_arvore(No_arvore *raiz)
{
    if (raiz != NULL)
    {
        imprimir_arvore(raiz->esq);
        printf("%s", raiz->palavra);
        imprimir_arvore(raiz->dir);
    }
}
void liberar_arvore(No_arvore *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    liberar_no(raiz);
    //free(raiz);
}

int main()
{
    int m, n;
    long int id = 0, valor_x = 0, valor_y = 0, valor_z = 0, valor_id = 0, valor = 0;
    No_arvore *raiz = NULL;
    char palavra[2050], palavra_copia[2050];
    Triade *triade;
    triade = malloc(sizeof(Triade));
    triade->x = NULL;
    triade->y = NULL;
    triade->z = NULL;

    while (scanf("%d %d", &m, &n) != EOF)
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%ld \"%[^\"]\"", &valor, palavra);
            No_arvore *novo_no = malloc(sizeof(No_arvore));
            strcpy(novo_no->palavra, palavra);
            novo_no->valor = valor;
            novo_no->dir = NULL;
            novo_no->esq = NULL;
            raiz = inserir_arvore(raiz, novo_no);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%ld", &id);
            buscar_triade_x(raiz, raiz, id, triade);
            strcpy(palavra_copia, triade->x->palavra);
            valor_x = triade->x->valor;
            strcat(palavra_copia, triade->y->palavra);
            valor_y = triade->y->valor;
            strcat(palavra_copia, triade->z->palavra);
            valor_z = triade->z->valor;
            valor_id = valor_x + valor_y + valor_z;
            No_arvore *no_adc = malloc(sizeof(No_arvore));
            no_adc->dir = NULL;
            no_adc->esq = NULL;
            strcpy(no_adc->palavra, palavra_copia);
            no_adc->valor = valor_id;
            raiz = inserir_arvore(raiz, no_adc);
            raiz = remover_triade(raiz, triade->x->valor,triade);
            raiz = remover_triade(raiz, triade->y->valor,triade);
            raiz = remover_triade(raiz, triade->z->valor,triade);
            strcpy(palavra_copia, "");
            triade->x = NULL;
            triade->y = NULL;
            triade->z = NULL;
        }
        imprimir_arvore(raiz);
        puts("");
        liberar_arvore(raiz);
        raiz = NULL;
    }
    free(triade);
}
