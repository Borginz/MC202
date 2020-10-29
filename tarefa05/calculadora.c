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
    int tamanho;

} Natural;

void inserir_dir( Natural *x, int digito){
    no* novo_no = malloc(sizeof(no));
    novo_no->valor = digito;
    novo_no->dir = NULL;
    
    if (x->mais_dir == NULL){
        novo_no->esq = NULL;
        x->mais_dir = novo_no;
        x->mais_esq = novo_no;
        x->tamanho = 1;
            
    } else{
        novo_no->esq = x->mais_dir;
        x->mais_dir->dir = novo_no; 
        x->mais_dir = novo_no;
        x->tamanho++;
        
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
int verificar_digito(Natural a, Natural b){
    no* aux1 = a.mais_esq;
    no* aux2 = b.mais_esq;
    while (aux1){
        if (aux1->valor < aux2->valor){
            return 0;
        } else if ( aux1->valor > aux2->valor){
            return 1;
        } else{
            aux1 = aux1->dir;
            aux2 = aux2->dir; 
        }
    }
    return 1;
}

int comparar_tamanho( Natural a, Natural b){
    if ( a.tamanho < b.tamanho){
        return 0;  
    }else if ( a.tamanho == b.tamanho ){
        if(!verificar_digito(a,b)){
            return 0;
        }            
    }
    return 1;
}

void tirar_zeros(Natural *x){
    no* aux = x->mais_esq;
    no* aux_aux = NULL;
    while (aux->dir != NULL && aux->valor == 0){
        aux->dir->esq = NULL;
        aux_aux = aux;
        aux = aux->dir;
        x->mais_esq = aux;
        free(aux_aux);      
    }
}

Natural subtrair_natural( Natural a, Natural b){
    Natural c = {NULL,NULL};
    no* aux1 = a.mais_dir;
    no* aux2 = b.mais_dir;
    int subtracao = 0;
    if(!comparar_tamanho(a,b)){
        aux1 = b.mais_dir;
        aux2 = a.mais_dir;
    }

    while(aux1){
        subtracao = aux1->valor;
        if ( aux2 ){
            if (subtracao < aux2->valor){
                aux1->esq->valor-= 1;
                subtracao += 10;
            }
            subtracao -= aux2->valor;
            aux2 = aux2->esq;
        }
        aux1 = aux1->esq;
        inserir_esq(&c, subtracao);
    }
    tirar_zeros(&c);
    return c;
    
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
            liberar(a);
            liberar(b);
            liberar(c);
            
        } else if ( op == '-'){
            Natural c = subtrair_natural(a,b);
            imprimir_natural(c);
        }


    }
    
    







    







}