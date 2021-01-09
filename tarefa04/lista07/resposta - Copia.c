// Questão 1:
// potencia recursiva
#include<stdio.h>
/*int pot(int a, int b){
    if ( b == 0 )
        return 1;
    else{
        return a*pot(a,b-1);
    }    
}*/

int main(){
    int a,b, resp;
    scanf("%d %d", &a, &b);
    resp = pot(a,b);
    printf("Resposta: %d", resp);

}
// iterativa 
int pot (int base, int exp){
    int i, resultado = 1;

    for (i = 0; i < exp; i++)
    resultado *= base;
    return resultado;
}

// Questão 3:
/* 
A forma recursiva e mais efienciente e faz menos multiplicações
do que a iterativa por causa do for 
*/