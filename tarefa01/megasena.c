/* ENTRADA:


Numero de apostadores int (m) e valor da premiação double (n)
Restrições:
5<= m <= 1000
1e6 <=n<=3e9

SAÍDA:
 
 Valor da premiação correspondente a cada apostador, sendo 1 por linha





//ALGORTIMO EM PORTUGUES:

 Main:
PRIMEIRA LINHA:
recebe duas variaveis sendo a por int m e a double n

SEGINDA LINHA:
percorre o numero de vezes m as matrizes por scanf

ULTIMA LINHA:
recebe separado por espaço os 6 numeros da mega 

Função para ler a matriz:

Função para verificar cada matriz com os numeros:
*/
#include<stdio.h>
#define MAX 1000

void ler_matriz(int matriz[][60], int m){
    int i,j;

    for ( i = 0; i < m; i++)
        for ( j = 0; j < 60; j++)
        scanf("%d ", &matriz[i][j]);
}

void contar_acertos(int matriz[][60], int m, int jogadores[MAX], int numeros[6]){
    int contador = 0, i, j, k;
    for ( i = 0; i < m; i++){
        
        for (k = 0; k < 6; k++){
            if ( matriz[i][j] == 1 && j+1 == numeros[k]){
                contador += 1;
            }
        }
        jogadores[i] = contador;
        contador = 0;

    }
    

}

int main(){
    int m, matriz[MAX][60],jogadores[m],numeros[6];
    double n;

    ler_matriz(matriz, m);
    contar_acertos(matriz,m,jogadores,numeros);
    imprimir_dinheiro(jogadores,n);
    scanf("%d %lf ", &m,&n);
}