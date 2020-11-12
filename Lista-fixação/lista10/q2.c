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

/*
 *  b) A diferença dessa estrutura para as vistas em sala é que essa tem ponteiros para apontar para
 *     um elemento acima, o que na lista ligada não acontecia, pois a lista ligada funciona como se 
 *     fosse uma sequência contínua. O nó dummie dessa função aponta para a primeira posição válida
 *     nessa, no caso, sendo o primeiro elemento que aparece na primeira linha válida. Na lista ligada,
 *     o nó dummie aponta para NULL que é o elemento anterior ao primeiro da lista.
 *
 */


float acessar_elemento(No_esparsa *m, int lin, int col)
{
    if (lin < 0 || lin >= m->linha || col < 0 ||
        col >= m->coluna)
        return 0;
    No_esparsa * atual = m->linha;
    while (atual != NULL && atual->coluna < col)
        atual = atual->cima;
    if (atual != NULL && atual->coluna == col)
        return atual->valor;
    return 0;
}

// A complexidade desse algoritmo é O(m*n), pois pode ser que a matriz seja toda completa, ou seja,
// tenha todos os elementos diferentes de 0 e queira-se buscar o elemento da última linha e última
// coluna.

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.