#include <stdio.h>
#include <stdlib.h>


void triangulo(int n, int passo){
    if (n == 1){
        printf("FD %d\n", passo);
        printf("LT 120\n");
        printf("FD %d\n", passo);
        printf("LT 120\n");
        printf("FD %d\n", passo);
        printf("LT 120\n");
        printf("FD %d\n", passo);
     } if (n > 1) {
        for(int i = 0; i < n; i++){
            triangulo(1, passo);
        }
        printf("LT 120\n");
        printf("FD %d\n", passo);
        printf("LT 60\n");
        printf("FD %d\n", passo * (n-1));
        printf("LT 180\n");

        triangulo(n-1, passo);
        
     }
}    
int main(){
    int n, passo;
    scanf("%d %d", &n, &passo);
    printf("RD 90\n");
    triangulo(n, passo);
}

// Feito por: Lucas Oliveira e Leonardo Borges
