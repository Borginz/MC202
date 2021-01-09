
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int vazia(p_fp fprio);

int cheia(p_fp fprio);

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

#define PAI(i) ((i - 1) / 2)

void sobe_no_heap(p_fp fprio, int k) {
    if (k > 0 && fprio->v[PAI(k)].chave < fprio->v[k].chave)
    {
        troca(&fprio->v[k], &fprio->v[PAI(k)]); 
        sobe_no_heap(fprio, PAI(k));
    }
}

// O(lg(n))
void remove_maximo(p_fp fprio) {
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
}

void remove_minimo(p_fp fprio) {
    int minimo = fprio->v[0].chave;
    int id_minimo = 0;
    int i;
    for(i = 0; i < fprio->n; i++){
        if(fprio->v[i].chave < minimo){
            minimo = fprio->v[i].chave;
            id_minimo = i;
        }
    }
    troca(&fprio->v[i], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, i);
}


#define F_ESQ(i) (2 * i + 1) /*Filho esquerdo de i*/
#define F_DIR(i) (2 * i + 2) /*Filho direito de i*/

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


void muda_prioridade(p_fp fprio, int k, int valor) {
    if (fprio->v[k].chave < valor) {
        fprio->v[k].chave = valor;
        sobe_no_heap(fprio, k);
    } else {
        fprio->v[k].chave = valor;
        desce_no_heap(fprio, k);
    }
}

// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira