#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Cor
{
    VERMELHO,PRETO
};

typedef struct No_arvore
{
    long int chave;
    enum Cor cor;
    struct No_arvore *esq, *dir;
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
    no_arvore* x = raiz->esq;
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

no_arvore *inserir_rec(no_arvore *raiz, long int chave)
{
    no_arvore *novo;
    if (raiz == NULL)
    {
        novo = malloc(sizeof(no_arvore));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        novo->cor = VERMELHO;
        novo->contador = 1;
        return novo;
    }
    if (chave < raiz->chave)
        raiz->esq = inserir_rec(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = inserir_rec(raiz->dir, chave);
    else
    {
        raiz->contador++;
        return raiz;
    }
    /* corrige a árvore */
    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq))
        raiz = rotaciona_para_esquerda(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        raiz = rotaciona_para_direita(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        sobe_vermelho(raiz);
    return raiz;
}
void verificar_cada(no_arvore *raiz, long int *contador)
{
    if (raiz != NULL)
    {
        if (raiz->chave < raiz->contador){
            contador += raiz->chave - raiz->contador; 
        } else if(raiz->chave < raiz->contador){
            contador += raiz->contador;
        }
        verificar_cada(raiz->esq,contador);
        verificar_cada(raiz->dir,contador);
    }
}

no_arvore *inserir(no_arvore *raiz, long int chave)
{
    raiz = inserir_rec(raiz, chave);
    raiz->cor = PRETO;
    return raiz;
}

no_arvore *buscar(no_arvore *raiz, long int k)
{
    if (k < 0)
        return NULL;
    if (raiz == NULL || raiz->chave == k)
        return raiz;
    if (raiz->chave > k)
        return buscar(raiz->esq, k);
    else
        return buscar(raiz->dir, k);
}

int main()
{
    int qtd_inicial, qtd_opera,x;
    no_arvore *raiz = NULL;
    long int *contador = 0,valor;

    scanf("%d %d", &qtd_inicial, &qtd_opera);
    for (int i = 0; i < qtd_inicial; i++)
    {
        scanf("%ld", &valor);
        raiz = inserir(raiz, valor);
    }
    for (int i = 0; i < qtd_opera; i++)
    {
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            scanf("%ld", &valor);
            inserir(raiz, valor);
            break;
        case 2:
            scanf("%ld", &valor);
            no_arvore *esperado;
            esperado = buscar(raiz, valor);
            printf("%ld\n", esperado->contador);
            break;
        case 3:
            scanf("%ld", &valor);
            verificar_cada(raiz, &contador);
            printf("%ld\n", contador);
            break;
        }
    }
}