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

void inserir_esq( Natural *x, int digito){
    no* novo_no = malloc(sizeof(no));
    novo_no->valor = digito;
    novo_no->esq = NULL;
    
    if (x->mais_esq == NULL){
        novo_no->dir = NULL;
        x->mais_esq = novo_no;
        x->mais_dir = novo_no;    
    } else{
        novo_no->dir = x->mais_esq;
        x->mais_esq->esq = novo_no; 
        x->mais_esq = novo_no;
        
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
void imprimir_natural(Natural digitos){
    no* aux1 = digitos.mais_esq;

    while(aux1){
        printf("%d",aux1->valor);
        aux1 = aux1->dir;
    }
    printf("\n");
    
    

} 
Natural subtrair_natural( Natural a, Natural b){
    
}
Natural somar_natural(Natural a, Natural b){
    Natural c = {NULL,NULL};
    int carry = 0;
    no* aux1 = a.mais_dir;
    no* aux2 = b.mais_dir;
    
    while (aux1 || aux2)
    {
        int soma = carry;
        if ( aux1 ){
            soma+=aux1->valor;
            aux1 = aux1->esq;
            
        }
        if ( aux2 ){
            soma+=aux2->valor;
            aux2 = aux2->esq;
        }
        inserir_esq(&c,soma%10);
        carry = soma/10;
    }
    if (carry){
        inserir_esq(&c,carry);
    }
    return c;
    
}



int main(){
    int n;
    char op;
    
    scanf("%d", &n);
    for ( int i = 0; i < n;i++){
        scanf(" %c", &op);
         Natural a = ler_natural();
         Natural b = ler_natural();
         if ( op == '+'){ 
            Natural c = somar_natural(a,b);
            imprimir_natural(c);
            
        } else if ( op == '-'){
            Natural c = subtrair_natural(a,b);
        }


    }
    
    







    







}
