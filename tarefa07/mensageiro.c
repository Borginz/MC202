#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct No_arvore{
    No_arvore *dir;
    No_arvore *esq;
    long int valor;
    char palavra[6];

}No_arvore;

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
   




int main(){
    int m,n,valor;
    long int id;
    No_arvore *raiz = NULL;
    char palavra[6];

    while (scanf("%d %d", &m, &n) != EOF){
        for ( int i = 0; i < m; i++){
            scanf("%d \"%[^\"]\"", &valor, palavra);
            No_arvore *novo_no = malloc(sizeof(No_arvore));
            strcpy(novo_no->palavra,palavra);
            novo_no->valor = valor;
            novo_no->dir,novo_no->esq = NULL;
            raiz = inserir_arvore(raiz,novo_no);
        }
        scanf("%d", id);
        buscar_triade(raiz,id);
        


    }
}