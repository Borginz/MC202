#include <stdio.h>
#include <stdlib.h>

typedef struct No_esparsa
{
    int linha;
    int coluna;
    float valor;
    struct No_esparsa *cima;
    struct No_esparsa *anterior;

} No_esparsa;

void alterar_valor_elemento(No_esparsa *m, int lin, int col, int x)
{
    No_esparsa *atual = m->linha;

    while (atual != NULL && atual->coluna < col)
        atual = atual->cima;
    if (atual != NULL && atual->coluna == col)
        atual->valor = x;
    
}

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.