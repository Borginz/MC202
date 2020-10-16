#include <stdio.h>
#include <stdlib.h>

void criar_presente(int presentes[], int n){
    int k=1;
    for(int i = 1; i <= n; i++){
        presentes[k] = i;
        presentes[k+1] = i;
        k += 2;
    }
}

void funcao_zerar(int pessoas[][2], int n){
    for(int i = 0; i < n; i++){
        pessoas[i][0] = 0;
        pessoas[i][1] = 0;
    }
}

int dar_presente(int presentes[], int pessoas[][2], int i, int p){
    if(i == 0){
        return 1;
    }
    for(int k = 0; k < 2; k++){
        if (pessoas[p][k] == 0){
            if (presentes[i] != p){
                pessoas[p][k] = presentes[i];
                if(dar_presente(presentes, pessoas, i-1, p) == 1){
                    return 1;
                }
                pessoas[p][k] = 0;
                return 0;
            }
            return -1
        }
    }
    return dar_presente(presentes, pessoas, i, p+1);
}

int main() {
    int presentes[11], pessoas[6][2], n = 5, p, k;
    
    funcao_zerar(pessoas, n);

    criar_presente(presentes, n);

    k = dar_presente(presentes, pessoas, n*2, 1);


    for(int i = 0; i < n; i++){
        printf("Qual pessoa é voce?\n");
        scanf("%d", &p);
        printf("Voce precisa dar presente para as pessoas %d e %d.\n", pessoas[p][0], pessoas[p][1]);
        system("clear");

    }
}

// Feito por: Cícero Libardi, Lucas Oliveira e Leonardo Borges
