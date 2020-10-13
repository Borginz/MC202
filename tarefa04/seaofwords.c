#include <stdio.h>
#define MAX 100
/*
n = O numero de linhas
m = o numero de colunas do texto
q = numero de palavras a serem buscadas
*/

void ler_matriz( int matriz[][MAX], int n, int m){
    for ( int i = 0; i < n; i++)
        for ( int j = 0; j < m; j++)
        scanf("%s", &matriz[i][j]);
}

int main(){
    int n,m,q;
    int matriz[MAX][MAX], palavras[10];


    scanf("%d %d %d", &n, &m, &q);
    ler_matriz(matriz,n,m);
    for( int i = 0; i < q; i++){
        scanf("%d", &palavras[i]);
    }





}