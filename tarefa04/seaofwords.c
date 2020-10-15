#include <stdio.h>
#define MAX 101
/*
n = O numero de linhas
m = o numero de colunas do texto
q = numero de palavras a serem buscadas
*/

// Função para checar se a posição passada é valida
int valido(int i, int j, int n, int m){
    
    if ((i > n-1) || ( i < 0) || (j > m-1) || (j < 0) ){
        return 0;
    } else
    {
        return 1;
    }
    
}

// Função para verificar a posição recursivamente a respeita da palavra
int verificar_pos(char matriz[][MAX], int i, int j, char palavra[], int k,int n, int m){
    if (!valido(i,j,n,m)){
        return 0;
    }
    if (palavra[k] == '\0'){ // Verificar se chegou ao final da comparação
        return 1;
    }
    if (palavra[k] != matriz[i][j]){ // Verificar se o indice k na palavra corresponde a letra da matriz
        return 0;
    }
    char aux = matriz[i][j];
    matriz[i][j] = '#'; // Trocando letra ja conferida
    // Verificar os vizinhos recursivamente por backtracking
    
    int a = verificar_pos(matriz, i, j+1, palavra, k+1,n, m);
    int b = verificar_pos(matriz, i, j-1, palavra, k+1,n, m);
    int c = verificar_pos(matriz, i-1, j, palavra, k+1,n, m);
    int d = verificar_pos(matriz, i+1, j, palavra, k+1,n, m);
    
    
    matriz[i][j] = aux; // devolvendo letra conferida
    if (a||b||c||d){ // verificando se algum backtracking deu certo
        return 1;
    }
    return 0;

}

// Função para chamar a palavra para a primeira comparção e depois começar a verificar com recursao
int comparar_nome(char matriz[][MAX], char palavra[], int n, int m){
    int id = 0;
    for ( int i = 0; i < n; i++){
        for ( int j = 0; j < m; j++){
            if ( matriz[i][j] == palavra[0]){
                id = verificar_pos(matriz,i,j,palavra,0,n,m);
                if ( id == 1){
                    return id;
                }
            }
        }
    }
    return id;
}
    
// Função para ler a matriz de entrada por linha
void ler_matriz( char matriz[][MAX], int n, int m){
    for ( int i = 0; i < n; i++){
        scanf("%s", matriz[i]);
    }
        
        
}

int main(){
    int n,m,q, id = 0;
    char matriz[MAX][MAX], palavras[10][21];


    scanf("%d %d %d", &n, &m, &q);
    ler_matriz(matriz,n,m);
    for( int i = 0; i < q; i++){
        scanf(" %s", palavras[i]);
        id = comparar_nome(matriz,palavras[i],n,m);
        if ( id == 1){ // verificando se houve algum caso positivo para imprimir
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }
    





}