#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No_arvore
{
    struct No_arvore *dir;
    struct No_arvore *esq;
    long int valor;
    char palavra[2000];
} No_arvore;

typedef struct Triade
{
    No_arvore *x;
    No_arvore *y;
    No_arvore *z;
} Triade;


// Função para inserir na arvore recursivamente analisando a arvore binaria
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

//Função para busca normalmente de um elemento na arvore binaria
No_arvore *buscar_triade_z(No_arvore *raiz, long int k)
{
    if (k < 0)
        return NULL;
    if (raiz == NULL || raiz->valor == k)
        return raiz;
    if (raiz->valor > k)
        return buscar_triade_z(raiz->esq, k);
    else
        return buscar_triade_z(raiz->dir, k);
}
// Função para buscar y recursivamente pegando o menor para analisar
// marcando o y caso for o mais a esquerda e buscando z normalmente e analisando se foi null
void buscar_triade_y(No_arvore *raiz_ori, No_arvore *raiz_atual, long int id, Triade *triade)
{
    if (triade->z != NULL)
    {
        return;
    }
    if (raiz_atual->esq != NULL /*&& raiz_atual->esq->valor > triade->x->valor*/)
    {
        buscar_triade_y(raiz_ori, raiz_atual->esq, id, triade);
        if (triade->z != NULL)// se achei o z
        {
            return;
        }
    }

    triade->y = raiz_atual;
    triade->z = buscar_triade_z(raiz_ori, (id - triade->y->valor));
    if (triade->z != NULL)// se achei o z
    {
        return;
    }
    if (raiz_atual->dir != NULL /*&& raiz_atual->valor < id*/)
    {
        buscar_triade_y(raiz_ori, raiz_atual->dir, id, triade);//caso o outro teste de errado
        if (triade->z != NULL)// se achei o z
        {
            return;
        }
    }
    triade->y = NULL;
}
// Função para buscar x recursivamente pegando o mais a esq da arvore (minimo)
// marcando o x caso for o mais a esquerda e buscando y, analisando na volta
void buscar_triade_x(No_arvore *raiz_ori, No_arvore *raiz_atual, long int id, Triade *triade)
{
    if (triade->y != NULL)// se achar o y certo
    {
        return;
    }
    if (raiz_atual->esq != NULL)
    {
        buscar_triade_x(raiz_ori, raiz_atual->esq, id, triade);
        if (triade->y != NULL)// se achar o y certo
        {
            return;
        }
    }
    triade->x = raiz_atual;
    buscar_triade_y(raiz_ori, raiz_ori, (id - triade->x->valor), triade);
    if (triade->y != NULL)// se achar o y certo
    {
        return;
    }
    if (raiz_atual->dir != NULL)// caso o outro teste de errado
    {
        buscar_triade_x(raiz_ori, raiz_atual->dir, id, triade);
    }
}


// Função que remove o sucessor, na verdade removendo o minimo e copiando os valores dele para raiz
// Analisando se algum ponteiro da triade aponta para min e tratando o caso
No_arvore *remover_sucessor(No_arvore *raiz, Triade *triade)
{

    if (raiz->dir == NULL)
    {
        return NULL;
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
    if ( triade->x == min){
        triade->x = raiz;
    }
    if ( triade->y == min){
        triade->y = raiz;
    }
    if ( triade->z == min){
        triade->z = raiz;
    }
    free(min);
    return raiz;
}
// Função para remover o devido triade requerido da arvore, para poder somar depois 
No_arvore *remover_triade(No_arvore *raiz, long int chave, Triade* triade)
{
    No_arvore *aux;
    if (raiz == NULL)
    {
        return NULL;
    }
    if (chave == raiz->valor)
    {
        if (raiz->esq == NULL)
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
        else if (raiz->dir == NULL && raiz->esq == NULL)
        {
            free(raiz);
            return NULL;
        }
        return remover_sucessor(raiz, triade);
    }
    if (chave < raiz->valor)
        raiz->esq = remover_triade(raiz->esq, chave, triade);
    else if (chave > raiz->valor)
        raiz->dir = remover_triade(raiz->dir, chave, triade);
    return raiz;
}
// Função para liberar cada nó dar arvore printada
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
// Função imprimindo a arvore na ordem requisitada recursivamente
void imprimir_arvore(No_arvore *raiz)
{
    if (raiz != NULL)
    {
        imprimir_arvore(raiz->esq);
        printf("%s", raiz->palavra);
        imprimir_arvore(raiz->dir);
    }
}
// Função para liberar a arvore 
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
    char palavra[2000], palavra_copia[2000];
    Triade *triade;
    triade = malloc(sizeof(Triade));
    triade->x = NULL;
    triade->y = NULL;
    triade->z = NULL;

    while (scanf("%d %d", &m, &n) != EOF)// leio até o fim do arquivo
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%ld \"%[^\"]\"", &valor, palavra);// leio cada valor e palavra criando novo no
            No_arvore *novo_no = malloc(sizeof(No_arvore));
            strcpy(novo_no->palavra, palavra);
            novo_no->valor = valor;
            novo_no->dir = NULL;
            novo_no->esq = NULL;
            raiz = inserir_arvore(raiz, novo_no);// insiro esse novo no na arvore
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%ld", &id);
            buscar_triade_x(raiz, raiz, id, triade);// busco meu x y z na arvore
            strcpy(palavra_copia, triade->x->palavra);// copio a string de x para palavra copia
            valor_x = triade->x->valor;// copio o valor
            strcat(palavra_copia, triade->y->palavra);// concateno as strings
            valor_y = triade->y->valor;// copio o valor
            strcat(palavra_copia, triade->z->palavra);// concateno as strings
            valor_z = triade->z->valor;// copio o valor
            valor_id = valor_x + valor_y + valor_z;// somo os valores
            No_arvore *no_adc = malloc(sizeof(No_arvore));// crio o nono no para adicionar
            no_adc->dir = NULL;
            no_adc->esq = NULL;
            strcpy(no_adc->palavra, palavra_copia);// copio a palavra formada para ele
            no_adc->valor = valor_id;// copio o valor para novo no
            raiz = inserir_arvore(raiz, no_adc);// insiro o novo no na raiz
            raiz = remover_triade(raiz, triade->x->valor,triade);// removo os triades
            raiz = remover_triade(raiz, triade->y->valor,triade);
            raiz = remover_triade(raiz, triade->z->valor,triade);
            strcpy(palavra_copia, "");// seto a palavra com nada
            triade->x = NULL;// seto null os triades
            triade->y = NULL;
            triade->z = NULL;
        }
        imprimir_arvore(raiz);//imprimo a arvore
        puts("");
        liberar_arvore(raiz);//libero a arvore
        raiz = NULL;
    }
    free(triade);
}
