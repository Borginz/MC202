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
