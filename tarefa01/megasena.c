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
        scanf(" %d", &matriz[i][j]);
}

void contar_acertos(int matriz[][60], int m, int jogadores[MAX], int numeros[6]){
    int contador = 0, i, j, k;
    for ( i = 0; i < m; i++){
        for( j = 0; j < 60; j++)
        for (k = 0; k < 6; k++){
            if ( matriz[i][j] == 1 && j+1 == numeros[k]){
                contador += 1;
            }
        }
        jogadores[i] = contador;
        contador = 0;

    }
    

}

void imprimir_dinheiro(int jogadores[MAX], double n, int m){
    int i, j, quadra = 0, quina = 0, sena = 0;
    for ( i = 0; i < m; i++){
        if (jogadores[i] == 4){
            quadra++;
        } else if (jogadores[i] == 5){
            quina++;
        } else if (jogadores[i] == 6){
            sena++;
        }
    } 
    for ( j = 0; j < m; j++){
        if (jogadores[j] == 4){
            printf("%.2lf\n", 0.19*n/quadra);
        } else if ( jogadores[j] == 5){
            printf("%.2lf\n", 0.19*n/quina);
        } else if ( jogadores[j] == 6){
            printf("%.2lf\n", 0.62*n/sena);
        } else{
            printf("%.2lf\n", 0.00);
        }
    }        
}
    
int main(){
    int m, matriz[MAX][60],jogadores[MAX],numeros[6],i;
    double n;
    scanf(" %d%lf", &m,&n);
    ler_matriz(matriz, m);
    for( i = 0; i < 6; i++){
        scanf(" %d", &numeros[i]);
    }
    contar_acertos(matriz,m,jogadores,numeros);
    imprimir_dinheiro(jogadores,n,m);
    return 0;
}