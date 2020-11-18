#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Cor
{
    VERMELHO,
    PRETO
};

typedef struct No_arvore
{
    long int chave;
    enum Cor cor;
    struct no_arvore *esq, *dir;
    long int contador;
} no_arvore;

int ehVermelho(no_arvore *x)
{
    if (x == NULL)
        return 0;
    return x->cor == VERMELHO;
}
int ehPreto(no_arvore *x)
{
    if (x == NULL)
        return 1;
    return x->cor == PRETO;
}

no_arvore *rotaciona_para_direita(no_arvore *raiz)
{
    no_arvore x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

void sobe_vermelho(no_arvore *raiz)
{
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

no_arvore *rotaciona_para_esquerda(no_arvore *raiz)
{
    no_arvore *x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

no_arvore *inserir_rec(no_arvore *raiz, int chave)
{
    no_arvore *novo;
    if (raiz == NULL)
    {
        novo = malloc(sizeof(no_arvore));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        novo->cor = VERMELHO;
        return novo;
    }
    if (chave < raiz->chave)
        raiz->esq = inserir_rec(raiz->esq, chave);
    else
        raiz->dir = inserir_rec(raiz->dir, chave);
    /* corrige a árvore */
    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq))
        raiz = rotaciona_para_esquerda(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        raiz = rotaciona_para_direita(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        sobe_vermelho(raiz);
    return raiz;
}

no_arvore *inserir(no_arvore *raiz, int chave)
{
    raiz = inserir_rec(raiz, chave);
    raiz->cor = PRETO;
    return raiz;
}

int main()
{
    int qtd_inicial, qtd_opera;
    No_arvore *raiz = NULL;

    scanf("%d %d", qtd_inicial, qtd_opera);
    for (int i = 0; i < qtd_inicial; i++)
    {
        no_arvore *novo_no = malloc(sizeof(no_arvore));
        scanf("%ld", novo_no->chave);
        novo_no->contador = 0
    }
}