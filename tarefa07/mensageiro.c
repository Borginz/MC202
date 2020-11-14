#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct No_arvore{
    struct No_arvore *dir;
    struct No_arvore *esq;
    long int valor;
    char palavra[6];
}No_arvore;



typedef struct Triade{
    No_arvore *x;
    No_arvore *y;
    No_arvore *z;
}Triade;





No_arvore* inserir_arvore( No_arvore* raiz, No_arvore *novo){
    if (raiz == NULL){
        return novo;
    } else if ( raiz->valor > novo->valor){
        raiz->esq = inserir_arvore(raiz->esq, novo);
    } else{
        raiz->dir = inserir_arvore(raiz->dir, novo);
    }
    return raiz;
}



void buscar_triade_x(No_arvore* raiz_ori, No_arvore* raiz_atual, int id, Triade* triade ){
    if (raiz_atual->esq != NULL){
        buscar_triade_x(raiz_ori,raiz_atual->esq,id,triade);
        if(triade->x != NULL){
            return;
        }
    }
    triade->x = raiz_atual;
    buscar_triade_y(raiz_ori,raiz_ori,(id-triade->x->valor),triade);
    if ( triade->y != NULL){
        return;
    }
    if ( raiz_atual->dir != NULL){
        buscar_triade_x(raiz_ori,raiz_atual->dir,id,triade);
    }
}

void buscar_triade_y(No_arvore *raiz_ori,No_arvore *raiz_atual,int id,Triade *triade){
    if (raiz_atual->esq != NULL && raiz_atual->esq->valor > triade->x->valor){
        buscar_triade_y(raiz_ori,raiz_atual->esq,id,triade);
        if ( triade->y != NULL){
            return;
        }
    }
    triade->y = raiz_atual;
    triade->z = buscar_triade_z(raiz_ori,(id-triade->y->valor));
    if (triade->z != NULL){
        return;
    }
    if (raiz_atual->dir != NULL && raiz_atual->valor < id){
        buscar_triade_y(raiz_ori,raiz_atual->dir,id,triade);
    }

}

No_arvore* busca_traide_z (No_arvore* raiz, int k) {
    if (raiz == NULL || raiz->valor == k)
       return raiz;
    if (raiz->valor > k)
       return buscar_triade_z(raiz->esq, k);
    else
       return buscar_triade_z(raiz->dir, k);
}

int main(){
    int m,n,valor;
    long int id = 0,valor_x,valor_y,valor_z,valor_id;
    No_arvore *raiz = NULL;
    char palavra[6], palavra_copia[100];
    Triade triade;
    triade.x = NULL;
    triade.y = NULL;
    triade.z = NULL;
    

    while (scanf("%d %d", &m, &n) != EOF){
        for ( int i = 0; i < m; i++){
            scanf("%d \"%[^\"]\"", &valor, palavra);
            No_arvore *novo_no = malloc(sizeof(No_arvore));
            strcpy(novo_no->palavra,palavra);
            novo_no->valor = valor;
            novo_no->dir = NULL;
            novo_no->esq = NULL;
            raiz = inserir_arvore(raiz,novo_no);
        }
        for ( int i = 0; i < n;i++){
            scanf("%ld",&id);
            buscar_triade_x(raiz,raiz,id,&triade);
            strcpy(palavra_copia,triade.x->palavra);
            valor_x = triade.x->valor;
            remover_triade(x);
            strcat(palavra_copia,triade.y->palavra);
            valor_y = triade.y->valor;
            remover_triade(y);
            strcat(palavra_copia,triade.z->palavra);
            valor_y = triade.z->valor;
            remover_triade(z);
            valor_id = valor_x+valor_y+valor_z;
            criar_novo_no(palavra_copia,valor_id);
            inserir_arvore(novo_no);


        }
        //imprimir_arvore(raiz);
        //liberar_arvore(raiz);
        
    }
}