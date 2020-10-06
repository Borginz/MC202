#include <stdio.h>

/*int main(){
    float operando1, operando2;
    float resultado;
    char operador;
    scanf("%f %c %f", &operando1, &operador, &operando2);
    if ( operador = '/'){
        resultado = operando1 / operando2;
        printf("%f\n", resultado);    
    } else{
        printf("Erro: operador nao reconhecido\n");
    }
} */

int main(){
    int n, i;
    float operando1, operando2, resultado;
    char operador;

    scanf("%d", &n);
    for ( i = 0; i < n; i+=1){
        scanf("%f %c %f", &operando1, &operador, &operando2);
        if ( operador == '/'){
            resultado = operando1 / operando2;
            printf("%f\n", resultado);
        } else if ( operador == '+'){
            resultado = operando1 + operando2;
            printf("%f\n", resultado);
        } else {
            printf("Erro: operador nao existe\n");
        }

    }

} 
