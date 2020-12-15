#include <stdio.h>
#include <stdlib.h>

enum Cor
{ VERMELHO, PRETO };

typedef no_arvore *p_no;

typedef struct no_arvore
{
    int chave;
    enum Cor cor;
    struct no_arvore *esq, *dir;
} no_arvore;


int ehVermelho(p_no x)
{
    if (x == NULL)
        return 0;
    return x->cor == VERMELHO;
}

int ehPreto(p_no x)
{
    if (x == NULL)
        return 1;
    return x->cor == PRETO;
}

p_no rotaciona_para_esquerda(p_no raiz)
{
    p_no x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

p_no rotaciona_para_direita(p_no raiz)
{
    p_no x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

void sobe_vermelho(p_no raiz)
{
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

no_arvore *inserir_rec(no_arvore *raiz, long int chave) //função para inserir recursivamente e contando +1 quando ja existir
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
    if (chave < raiz->chave) //se a chave for menor
        raiz->esq = inserir_rec(raiz->esq, chave);
    else if (chave > raiz->chave) //se a chave for maior
        raiz->dir = inserir_rec(raiz->dir, chave);
    else
        return raiz;
    /* corrige a árvore */
    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq))
        raiz = rotaciona_para_esquerda(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        raiz = rotaciona_para_direita(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        sobe_vermelho(raiz);
    return raiz;
}



// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira
