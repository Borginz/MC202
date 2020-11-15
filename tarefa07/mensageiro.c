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
    //fprintf(stderr,"z atual :%ld\n", raiz->valor);
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
    //fprintf(stderr,"to olhando y = %ld\n", raiz_atual->valor);
    triade->z = buscar_triade_z(raiz_ori, (id - triade->y->valor));
    if (triade->z != NULL)
    {
        //fprintf(stderr,"achei o z que completa : %ld\n", triade->z->valor);
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
    //fprintf(stderr,"XXXXXXto olhando x = %ld\n", raiz_atual->valor);
    buscar_triade_y(raiz_ori, raiz_ori, (id - triade->x->valor), triade);
    if (triade->y != NULL)
    {
        //fprintf(stderr,"SAI\n");
        return;
    }
    if (raiz_atual->dir != NULL)
    {
        buscar_triade_x(raiz_ori, raiz_atual->dir, id, triade);
    }
}

void remover_sucessor(No_arvore *raiz)
{

    if (raiz->dir == NULL){
        return;
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
    //free(min);
}

No_arvore *remover_triade(No_arvore *raiz, long int chave)
{
    No_arvore *aux;

    if (raiz == NULL)
        return NULL;
    if (chave < raiz->valor)
        raiz->esq = remover_triade(raiz->esq, chave);
    else if (chave > raiz->valor)
        raiz->dir = remover_triade(raiz->dir, chave);

    else if (raiz->esq == NULL)
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

    else
        remover_sucessor(raiz);
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
            //fprintf(stderr,"TO PROCURANDO ID:%ld\n",id);
            buscar_triade_x(raiz, raiz, id, triade);
            //fprintf(stderr,"%d %d %d\n", triade->x == NULL,triade->y == NULL,triade->z == NULL);
            //fprintf(stderr,"%ld %ld %ld\n", triade->x->valor, triade->y->valor,triade->z->valor);
            //fprintf(stderr, "%s %s %s\n", triade->x->palavra, triade->y->palavra,triade->z->palavra);
            strcpy(palavra_copia, triade->x->palavra);
            valor_x = triade->x->valor;
            //fprintf(stderr,"Print antes\n");
            raiz = remover_triade(raiz, triade->x->valor);
            strcat(palavra_copia, triade->y->palavra);
            valor_y = triade->y->valor;
            raiz = remover_triade(raiz, triade->y->valor);
            strcat(palavra_copia, triade->z->palavra);
            //fprintf(stderr,"%s\n", palavra_copia);
            valor_z = triade->z->valor;
            raiz = remover_triade(raiz, triade->z->valor);
            //fprintf(stderr,"removi todos\n");
            valor_id = valor_x + valor_y + valor_z;
            No_arvore *no_adc = calloc(sizeof(No_arvore), 1);
            no_adc->dir = NULL;
            no_adc->esq = NULL;
            strcpy(no_adc->palavra, palavra_copia);
            no_adc->valor = valor_id;
            //fprintf(stderr,"valor do no: %ld\n", no_adc->valor);
            //fprintf(stderr,"palavra:%s\n", no_adc->palavra);
            raiz = inserir_arvore(raiz, no_adc);
            //fprintf(stderr,"terminei de inserir\n");
            //fprintf(stderr,"Chamei\n");
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
}
