#include <stdio.h>
#include <stdlib.h>

/*
- Recebe o N e o M na primeira linha
- Faz um for que le linhas referentes aos nomes e colunas sobre os dados
- Criar um vetor de nomes e de dados 
- For nos nomes e imprimo o nome
- For calculando cada um dos termos, armanezar
- Vetor de inteiros analisando a condição
*/
void ler_dados();

double **aloca_matriz(int n, int m){
    double **dados;  
    dados = malloc(n * sizeof (double *));
    for ( int i = 0; i < n; i++)
        dados[i] = malloc( m * sizeof(double));
     return dados;    
}


int main (){
    int n, m;
    double **dados;
    char *nomes;

    dados = aloca_matriz(n, m);
    nomes = malloc( 25 * sizeof(char));
    



    scanf(" %d%d", &n, &m);

    
    
    for ( int i = 0; i < n; i ++){
        for ( int j = 0; j < m; j ++){
            scanf("%lf", &dados[n][m]);
        }
    }
    
    


}
