/*
Você recebe k listas de números já ordenadas, com um total de m elementos. Escreva um programa 
para criar uma lista ordenada com todos os m elementos. A complexidade do algoritmo deve ser O(mlogk).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAI(i) ((i - 1) / 2)
#define F_ESQ(i) (2 * i + 1) /*Filho esquerdo de i*/
#define F_DIR(i) (2 * i + 2) /*Filho direito de i*/

typedef struct
{
    char nome[20];
    int chave;
} Item;

typedef struct
{
    Item *v;
    int n, tamanho;  // n = numero de elementos, tamanho é a capacidade
} FP;

typedef FP *p_fp;

p_fp criar_filaprio(int tam) {
    p_fp fprio = malloc(sizeof(FP));        // aloca o tamanho da fila
    fprio->v = malloc(tam * sizeof(Item));  // aloca o v do tamanho da capacidade
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}


// troca(&v[i], &v[j] troca os valores de v[i] e v[j])
void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//O(lg(n))
void insere(p_fp fprio, Item item) {
    fprio->v[fprio->n] = item;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n - 1);
}

void sobe_no_heap(p_fp fprio, int k) {
    if (k > 0 && fprio->v[PAI(k)].chave < fprio->v[k].chave)  // se não é a raiz e a raiz do pai é menor que a raiz do cara:
    {
        troca(&fprio->v[k], &fprio->v[PAI(k)]);  // troco o pai pelo cara e subo o pai no heap de novo
        sobe_no_heap(fprio, PAI(k));
    }
}

// O(lg(n))
Item extrai_maximo(p_fp fprio) {
    Item item = fprio->v[0];
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return item;
}


void desce_no_heap(p_fp fprio, int k) {
    int maior_filho;
    if (F_ESQ(k) < fprio->n) {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n &&
            fprio->v[F_ESQ(k)].chave < fprio->v[F_DIR(k)].chave)
            maior_filho = F_DIR(k);
        if (fprio->v[k].chave < fprio->v[maior_filho].chave) {
            troca(&fprio->v[k], &fprio->v[maior_filho]);
            desce_no_heap(fprio, maior_filho);
        }
    }
}


int main() {

    p_fp fila;
    int m, k, num;
    scanf("%d %d", &m, &k);
    Item v[m*k];
    fila = criar_filaprio(m*k);

    //para cada elemento das listas (vetor) adiciono o elemento no heap
    for (int i = 0; i <= k; i++) {
        for (int j = 0; i <= m; j++) {
            scanf("%d", &num);
            insere(fila, num);
        }
    }

    int c = 0;

    //extraio o maximo do vetor e adiciono 
    for (int i = 0; i <= k; i++) {
        for (int j = 0; i <= m; j++) {
            v[c] = extrai_maximo(fila);
            c++;
        }
    }

    for (int i = c - 1; i != 0; i--) {
        printf(v[i]);
    }
}

// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira