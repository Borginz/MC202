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

void troca(cliente *a, cliente *b)//Troca de posiçoes dos clientes
{
    cliente t = *a;
    *a = *b;
    *b = t;
}

FP *criar_filaprio(int tam)// Função para criar a FP
{
    FP *fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(cliente));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

void sobe_no_heap(FP *fprio, int k)//Ir subind na heap
{
    if (k > 0 && fprio->v[PAI(k)].avaliacao < fprio->v[k].avaliacao)
    {
        troca(&fprio->v[k], &fprio->v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

void insere(FP *fprio, cliente item)// inserir subindo no heap
{
    fprio->v[fprio->n] = item;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n - 1);
}

void desce_no_heap(FP *fprio, int k)// ir descendo na heap
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

cliente extrai_maximo(FP *fprio)//tirar o maximo da heap descendo na heap
{
    cliente item = fprio->v[0];
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return item;
}

FP *remover_procurado(FP *fprio, char procurado[])//Achar o que eu quero e seto 6 para subir pro maximo e retirar ele subindo
{
    for (int i = 0; i < fprio->n; i++)
    {
        if (strcmp(fprio->v[i].Nome, procurado) == 0)
        {
            fprio->v[i].avaliacao = 6;
            sobe_no_heap(fprio, i);
            extrai_maximo(fprio);
        }
    }
    return fprio;
}

void liberar_heap(FP* fprio){// libero o vetor e depois a FP
    free(fprio->v);
    free(fprio);
    return;
}

int main()
{
    int distancia_total = 0, distancia_cliente = 0, pos_mot_x = 0, pos_mot_y = 0,distancia_parcial = 0, distancia_viagem = 0;
    char x;
    double liquido = 0, bruto = 0, despesas = 0;
    FP *fprio;
    fprio = criar_filaprio(250);
    cliente cliente_heap;
    cliente cliente_atual;
    strcpy(cliente_atual.Nome, "Leonardo");// inicio o primeiro me homenageando
    cliente_atual.avaliacao = 0;
    cliente_atual.pos_fim_x = 0;
    cliente_atual.pos_fim_y = 0;
    cliente_atual.pos_ini_x = 0;
    cliente_atual.pos_ini_y = 0;
    char procurado[20];

    while (scanf("%c ", &x) != EOF)//ler até o fim do arquivo
    {
        switch (x)
        {
        case 'A':
            scanf("%s %lf %d %d %d %d", cliente_heap.Nome, &(cliente_heap.avaliacao), &(cliente_heap.pos_ini_x), &(cliente_heap.pos_ini_y), &(cliente_heap.pos_fim_x), &(cliente_heap.pos_fim_y));
            if (cliente_atual.avaliacao != 0)// vejo se a avaliação é zero pq foi meu set de atual vazio
            {
                insere(fprio, cliente_heap);// insiro na heap
            }
            else
            {
                cliente_atual = cliente_heap;// se nao tiver como avaliação 0 eu copio
            }
            printf("Cliente %s foi adicionado(a)\n", cliente_heap.Nome);
            break;
        case 'C':
            scanf("%s", procurado);
            fprio = remover_procurado(fprio, procurado);// tiro o procurado
            bruto += 7;
            printf("%s cancelou a corrida\n", procurado);
            break;
        case 'F':
            printf("A corrida de %s foi finalizada\n", cliente_atual.Nome);
            distancia_parcial = abs(pos_mot_x - cliente_atual.pos_ini_x) + abs(pos_mot_y - cliente_atual.pos_ini_y);//pego a distancia parcial até o cliente
            distancia_viagem = abs(cliente_atual.pos_ini_x - cliente_atual.pos_fim_x) + abs(cliente_atual.pos_ini_y - cliente_atual.pos_fim_y);//pego a distancia da viagem
            distancia_total += distancia_parcial + distancia_viagem;// somo as parcias até o cliente e a viagem dele e somo no total 
            distancia_cliente += distancia_viagem;//somo a distancia de viagem com o cliente total
            pos_mot_x = cliente_atual.pos_fim_x;//seto a distancia do motorista pro final da corrida 
            pos_mot_y = cliente_atual.pos_fim_y;

            if (fprio->n > 0)
            {
                cliente_atual = extrai_maximo(fprio);// se tiver gente no vetor, eu tiro o maixmo pro cliente
            }
            else
            {
                cliente_atual.avaliacao = 0;// se nao eu seto o atual como avaliação 0
            }
            break;

        case 'T':
            despesas += (((distancia_total / 10.00) * 4.104) + 57);
            bruto += distancia_cliente * 1.4;
            liquido += bruto - ((bruto * 0.25) + despesas);

            printf("\n");
            printf("Jornada finalizada. Aqui esta o seu rendimento de hoje\n");
            printf("Km total: %d\n", distancia_total);
            printf("Rendimento bruto: %.2lf\n", bruto);
            printf("Despesas: %.2lf\n", despesas);
            printf("Rendimento liquido: %.2lf\n", liquido);
            break;
        }
    }
    liberar_heap(fprio);
}