#include <stdio.h>

int main() {
    int maxima = 0,i, n, duracao, limite;
    int velocidades[100];
    

    scanf("%d", &n);

    /* guardamos as velocidades */
    for (i = 0; i < n; i++) {
        scanf("%d", &velocidades[i]);
    }

    scanf("%d", &duracao);
    if ( duracao == 1){
        limite = 100;
    } else if ( duracao == 2){
        limite = 20;
    } else{
        limite = 10;
    }
    for (i = 0; i < n; i++) {
        if (velocidades[i] > maxima && velocidades[i] <= limite){
            maxima = velocidades[i];

        }
    }
    printf("%d", maxima);
    /* complete com seu código aqui  */
}
