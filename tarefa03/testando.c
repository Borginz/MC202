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

char **aloca_matriz_char( char **matriz ,int n, int m){
    char **matriz; 
    matriz = malloc(n * sizeof (char *));
    for ( int i = 0; i < n; i++)
        matriz[i] = malloc( m * sizeof(char));
     return matriz;    
}

double **aloca_matriz_int( double **matriz ,int n, int m){
    double **matriz; 
    matriz = malloc(n * sizeof (double *));
    for ( int i = 0; i < n; i++)
        matriz[i] = malloc( m * sizeof(double));
     return matriz;    
}


int main (){
    int n, m, *identificador;
    double **dados, **estatisticas;
    char **nomes;

    scanf(" %d%d", &n, &m);
    
    
    dados = aloca_matriz_int(dados,n, m);
    nomes = aloca_matriz_char(nomes,n,25);
    estatisticas = aloca_matriz(estatisticas,n,4);
    identificador = malloc( n * sizeof(int) );
    for ( int i = 0; i < n; i ++){
        scanf("%s", &nomes[i]);
        for ( int j = 0; j < m; j ++){
            scanf("%lf", &dados[n][m]);
        }
    }
    
    for ( int i = 0; i < n; i++){
        printf("%s", nomes[i]);
        for ( int j = 0; j < m; j++){
            printf("%lf", dados[n][m]);
        }
    }

}