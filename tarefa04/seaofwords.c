#include <stdio.h>
#define MAX 100
/*
n = O numero de linhas
m = o numero de colunas do texto
q = numero de palavras a serem buscadas
*/
int valido(char matriz[][100], int i, int j, int n, int m){
    // Função para checar as bordas
    if ((i > n-1) || ( i < 0) || (j > m-1) || (j < 0) ){
        return 0;
    } else
    {
        return 1;
    }
    
}

int verificar_pos(char matriz[][MAX], int i, int j, char palavra[], int k,int n, int m){
    if (!valido(matriz,i,j,n,m)){
        return 0;
    }
    if (palavra[k] == '\0'){
        return 1;
    }
    if (palavra[k] != matriz[i][j]){
        return 0;
    }
    char aux = matriz[i][j];
    matriz[i][j] = '#';
    
    int a = verificar_pos(matriz, i+1, j, palavra, k+1,n, m);
    int b = verificar_pos(matriz, i-1, j, palavra, k+1,n, m);
    int c = verificar_pos(matriz, i, j+1, palavra, k+1,n, m);
    int d = verificar_pos(matriz, i, j-1, palavra, k+1,n, m);
    matriz[i][j] = aux;
    if (a||b||c||d){
        return 1;
    }
}


void comparar_nome(char matriz[][MAX], char palavra[], int n, int m){
    for ( int i = 0; i < n; i++)
        for ( int j = 0; j < m; j++)
       if ( matriz[i][j] == palavra[0]){
           int id = verificar_pos(matriz,i,j,palavra,1,n,m);
           if ( id == 1)
           printf("sim\n");
           else
           printf("não\n");

       } 
}

void ler_matriz( int matriz[][MAX], int n, int m){
    for ( int i = 0; i < n; i++)
        for ( int j = 0; j < m; j++)
        scanf("%s", &matriz[i][j]);
}

int main(){
    int n,m,q;
    char matriz[MAX][MAX], palavras[10][21];


    scanf("%d %d %d", &n, &m, &q);
    ler_matriz(matriz,n,m);
    for( int i = 0; i < q; i++){
        scanf("%s", &palavras[i]);
        comparar_nome(matriz,palavras[i],n,m);
    }
    





}