// Questão 1:
// potencia recursiva
#include<stdio.h>
int pot(int a, int b){
    if ( b == 0 )
        return 1;
    else{
        return a*pot(a,b-1);
    }    
}

// iterativa 
int pot (int base, int exp){
    int i, resultado = 1;

    for (i = 0; i < exp; i++)
    resultado *= base;
    return resultado;
}

int main(){
    int a,b, resp;
    scanf("%d %d", &a, &b);
    resp = pot(a,b);
    printf("Resposta: %d", resp);

}


// Questão 3:
/* 
A forma recursiva é menos eficient e faz mais operações
do que a iterativa por causa do for 
*/