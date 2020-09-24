#include <stdio.h>
#define MAX 1000


void ler_matriz(int matriz[][60], int m){
    int i,j;

    for ( i = 0; i < m; i++)
        for ( j = 0; j < 60; j++)
        scanf(" %d", &matriz[i][j]);
}



void imprime_matriz_quadrada(int matriz[][60], int m) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < 60; j++)
            printf("%.2lf ", matriz[i][j]);
            printf("\n");
    }
    }


int main(){
    int m, matriz[MAX][60],jogadores[MAX],numeros[6], i;
    double n;
    scanf(" %d %lf", &m,&n);
    ler_matriz(matriz, m);
    for( i = 0; i < 6; i++){
        scanf(" %d", &numeros[i]);
    }
    imprime_matriz_quadrada(matriz, m);
    
    return 0;
}






imprimir_dinheiro(int jogadores[MAX], double n, int m){
    int i, quadra, quina, sena;
    for ( i = 0; i < m; i++){
        if jogadores[i] == 4{
            quadra++;
        } else if jogadores[i] == 5{
            quina++;
        } else if jogadores[i] == 6{
            sena++;
        }
    }
}
    for ( j = 0; j < m; j++){
        if jogadores[j] = 4 {
            printf(" %.2lf", m*0.19/quadra );
        }
    }

    
