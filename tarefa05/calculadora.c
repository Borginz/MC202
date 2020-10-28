#include <stdio.h>
#include <stdlib.h>



typedef struct no{
    int valor;
    struct no *dir;
    struct no *esq;
} no;


typedef struct Natural{
    struct no *mais_esq;
    struct no *mais_dir;

} Natural;

void inserir_dir( Natural *x, int digito){
    no* novo_no = malloc(sizeof(no));
    novo_no->valor = digito;
    novo_no->dir = NULL;
    
    if (x->mais_dir == NULL){
        novo_no->esq = NULL;
        x->mais_dir = novo_no;
        x->mais_esq = novo_no;    
    } else{
        novo_no->esq = x->mais_dir;
        x->mais_dir->dir = novo_no; 
        x->mais_dir = novo_no;
        
    }
}


Natural ler_natural(){
    char digito;
    Natural rv = {NULL,NULL};
    digito = getchar();
    while( digito < '0' || digito > '9')
    {
        digito = getchar();
    }
    while (digito >= '0' && digito <= '9')
    {
        inserir_dir(&rv, digito - '0');
        digito = getchar();
    }
    return rv;

    
}



int main(){
    int n;
    char op;
    
    scanf("%d", &n);
    for ( int i = 0; i < n;i++){
        scanf("%c", &op);
         Natural a = ler_natural();
         Natural b = ler_natural();
         if ( op == '+'){
            Natural c = somar_natural(a,b);
            imprimir_natural(c);


    }
    
    







    







}
