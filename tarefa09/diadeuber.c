#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAI(i) ((i - 1) / 2)
#define F_ESQ(i) (2 * i + 1) /*Filho esquerdo de i*/
#define F_DIR(i) (2 * i + 2) /*Filho direito de i*/
typedef struct Cliente_uber
{
    char Nome[16];
    double avaliacao;
    int pos_ini_x, pos_ini_y;
    int pos_fim_x, pos_fim_y;

} cliente;

typedef struct Fila_prioridade
{
    cliente *v;
    int n, tamanho;
} FP;


void troca(cliente *a, cliente *b)
{
    cliente t = *a;
    *a = *b;
    *b = t;
}



FP *criar_filaprio(int tam)
{
    FP *fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(cliente));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

void sobe_no_heap(FP *fprio, int k)
{
    if (k > 0 && fprio->v[PAI(k)].avaliacao < fprio->v[k].avaliacao)
    {
        troca(&fprio->v[k], &fprio->v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

void insere(FP *fprio, cliente item)
{
    fprio->v[fprio->n] = item;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n - 1);
}

void desce_no_heap(FP *fprio, int k)
{
    int maior_filho;
    if (F_ESQ(k) < fprio->n)
    {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n &&
            fprio->v[F_ESQ(k)].avaliacao < fprio->v[F_DIR(k)].avaliacao)
            maior_filho = F_DIR(k);
        if (fprio->v[k].avaliacao < fprio->v[maior_filho].avaliacao)
        {
            troca(&fprio->v[k], &fprio->v[maior_filho]);
            desce_no_heap(fprio, maior_filho);
        }
    }
}

cliente extrai_maximo(FP *fprio)
{
    cliente item = fprio->v[0];
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return item;
}

 FP* remover_procurado(FP * fprio,char procurado[]);

int main()
{
    int distancia_total = 0, distancia_cliente = 0, bruto = 0, despesas = 0, liquido = 0;
    char x;
    FP* fprio;
    fprio = criar_filaprio(250);
    cliente cliente_heap;
    cliente cliente_atual;
    char procurado[16];

    while (scanf("%c ", &x) != EOF){
        switch(x){
            case 'A':
                scanf("%s %lf %d %d %d %d", cliente_heap.Nome,&cliente_heap.avaliacao,&cliente_heap.pos_ini_x,&cliente_heap.pos_ini_y,&cliente_heap.pos_fim_x,&cliente_heap.pos_fim_y );
                if (cliente_atual.avaliacao != 0){
                    insere(fprio,cliente_heap);
                } else{
                    cliente_atual = cliente_heap;
                }
                printf("Cliente %s foi adicionado(a)\n", cliente_heap.Nome);
            case 'C':
                scanf("%s", procurado);
                fprio = remover_procurado(fprio,procurado);
                bruto += 7;
                printf("%s cancelou a corrida\n",procurado);
            case 'F':
                if (fprio->n > 0){
                    cliente_atual = extrai_maximo(fprio);
                } else{

                }

        }
    }
}