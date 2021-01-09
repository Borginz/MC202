#include <stdio.h>
#include <stdlib.h>


void koch(int n, int passo){
    
    if (n == 0){
        printf("FD %d\n", passo);
    } if(n > 0) {

        koch(n - 1, passo);
        printf("LT 60\n");
        koch(n - 1, passo);
        printf("RT 120\n");
        koch(n - 1, passo);
        printf("LT 60\n");
        koch(n - 1, passo);
    }
}    
int main(){
    int n, passo;
    scanf("%d %d", &n, &passo);
    printf("RT 90\n");
    koch(n, passo);
}

// Feito por: Lucas Oliveira e Leonardo Borges
