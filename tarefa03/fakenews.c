#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
- Recebe o N e o M na primeira linha
- Faz um for que le linhas referentes aos nomes e colunas sobre os dados
- Criar um vetor de nomes e de dados 
- For nos nomes e imprimo o nome
- For calculando cada um dos termos, armanezar
- Vetor de inteiros analisando a condição
*/
double calcular_maximo( double *dados, int m){
    double maximo;
    maximo = dados[0];
    for 
}

int calcular_stats(double *dados, int m){
    // calculo as coisas 
    // retorno de 0 a 5 identificando 
    double max, min, media, desvpad;
    max = calcular_maximo(dados, m);

}

char ** aloca_matriz_char(int n, int m){ 
    char **matriz;
    matriz = malloc(n * sizeof (char *));
    for ( int i = 0; i < n; i++)
        matriz[i] = malloc( m * sizeof(char));  
    return matriz;
} 

double ** aloca_matriz_double(int n, int m){
    double **matriz;
    matriz = malloc(n * sizeof (double *));
    for ( int i = 0; i < n; i++)
        matriz[i] = malloc( m * sizeof(double));
    return matriz;
}


int main (){
    int n, m, categoria, m_categoria;
    double **dados;
    char **nomes;

    scanf(" %d%d", &n, &m);
    
    
    dados = aloca_matriz_double(n, m);
    nomes = aloca_matriz_char(n,25);
    
    for ( int i = 0; i < n; i ++){
        scanf("%s", nomes[i]);
        for ( int j = 0; j < m; j ++){
            scanf("%lf", &dados[n][m]);
        }
    }

    for ( int i = 0; i < n; i++){
        printf("%s", nomes[i]);
        categoria = calcular_stats(dados[i], m);
        m_categoria[categoria] = i;

    }
    
    




    

    
    
    
    
    


}
