#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<assert.h>
/*
- Recebe o N e o M na primeira linha
- Faz um for que le linhas referentes aos nomes e colunas sobre os dados
- Criar um vetor de nomes e de dados 
- For nos nomes e imprimo o nome
- For calculando cada um dos termos, armanezar
- Vetor de inteiros analisando a condição
*/

 void liberar_matriz_int(int **m_categoria, int n){
     for ( int i = 0; i < n; i++){
         free(m_categoria[i]);
     }
     free(m_categoria);

 }
void liberar_matriz_char(char **m_categoria, int n){
     for ( int i = 0; i < n; i++){
         free(m_categoria[i]);
     }
     free(m_categoria);

 }
 void liberar_matriz_double(double **m_categoria, int n){
     for ( int i = 0; i < n; i++){
         free(m_categoria[i]);
     }
     free(m_categoria);

 }

 void imprimir_nomes(int *m_categoria, int tamanho, char **nomes){
     for ( int i = 0; i < tamanho; i++){
         if ( strcmp(nomes[m_categoria[i]], "AlexandriaOcasioCortez") == 0){
             printf("achamos\n");
        }
        printf(" %s", nomes[m_categoria[i]]);

         
     }
     printf("\n");

}
 int contar_nomes(int *m_categoria, int m){
     int contadora = 0;
     for ( int i = 0; i < m; i++){
         if (m_categoria[i] == -1){
             break;
         }
         contadora += 1;
     }
     return contadora;

 }




int procurar_idx(int **m_categoria,int categoria, int m){
    for ( int i = 0; i < m; i++){
        if ( m_categoria[categoria][i] == -1){
            return i;
        }
    }
    return 0;



}



int ** aloca_matriz_int(int n, int m){
    int **matriz;
    matriz = malloc((n+10) * sizeof (int *));
    for ( int i = 0; i < n; i++){
        matriz[i] = malloc( (m+10) * sizeof(int));
    }
    return matriz;
}

double calcular_desvpad(double *dados, int m, double media){
    double soma = 0, desvpad;
    for ( int i = 0; i < m; i++){
        soma += (dados[i]-media)*(dados[i]-media);
    } 
    desvpad = sqrt((soma/m));
    return desvpad;

}

double calcular_med( double *dados, int m){
    double media = 0;
    for ( int i = 0; i < m; i++){
        media += dados[i]/m;
    }
    return media;

}

double calcular_min( double *dados, int m){
    double minimo;
    minimo = dados[0];
    for ( int i = 1; i < m; i++){
        if ( minimo > dados[i]){
            minimo = dados[i];
        }
    }
    return minimo;
}


double calcular_maximo( double *dados, int m){
    double maximo;
    maximo = dados[0];
    for ( int i = 1; i < m; i++){
        if (maximo < dados[i]){
            maximo = dados[i];
        }

    }
    return maximo;
}

int calcular_stats(double *dados, int m){
    // calculo as coisas 
    // 0 = Bot -- 1 = surpreendente -- 2 = normal 
    // 3 = local -- 4 = irrelevante 
    double max, min, media, desvpad;
    int identificador;
    max = calcular_maximo(dados, m);
    printf("%.2lf ", max);
    min = calcular_min(dados, m);
    printf("%.2lf ", min);
    media = calcular_med(dados, m);
    printf("%.2lf ", media);
    desvpad = calcular_desvpad(dados,m,media);
    printf("%.2lf\n", desvpad);
    
    if ((media >= 60) && ( desvpad > 15)){
        identificador = 0;
    } else if ((media >= 60) && (desvpad <= 15)){
        identificador = 1;
    } else if ((media < 60) && (max >= 80) && (min > 20)){
        identificador = 2;     
    } else if ((media < 60) && (max >= 80) && (min <= 20)){
        identificador = 3;
    } else /*if ((media < 60) && (max < 80))*/{
        identificador = 4;
    } 
        
    

    return identificador;
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
    int idx ,n, m, categoria, **m_categoria, *vetor_tamanhos;
    double **dados;
    char **nomes;

    scanf("%d%d", &n, &m);
    
    vetor_tamanhos = malloc(5*sizeof(int));
    for ( int i = 0; i < 5; i++){
        vetor_tamanhos[i] = 0;
    }
    dados = aloca_matriz_double(n, m);
    nomes = aloca_matriz_char(n,30);
    m_categoria = aloca_matriz_int(5,n);
    
    for ( int i = 0; i < n; i ++){
        scanf("%s", nomes[i]);
        for ( int j = 0; j < m; j ++){
            scanf("%lf", &dados[i][j]);
        }
    }


    for ( int i = 0; i < n; i++){
        printf("%s ", nomes[i]);
        categoria = calcular_stats(dados[i], m);
        assert (vetor_tamanhos[categoria] < n);
        idx = vetor_tamanhos[categoria];
        m_categoria[categoria][idx] = i; 
        vetor_tamanhos[categoria]++;
    }


    printf("\nRESULTADO:\n");
    for ( int i = 0; i < 5; i++){
        int size = vetor_tamanhos[i];
        if ( i == 0){
            printf("Bot (%d):", size);
        } else if ( i == 1){
            printf("Surpreendente (%d):", size);
        } else if ( i == 2){
            printf("Normal (%d):", size);
        } else if ( i == 3){
            printf("Local (%d):", size);
        } else if ( i == 4){
            printf("Irrelevante (%d):", size);
        }
        
        imprimir_nomes(m_categoria[i], size, nomes);
    }

    liberar_matriz_int(m_categoria,5);
    liberar_matriz_char(nomes,n);
    liberar_matriz_double(dados,n);
    free(vetor_tamanhos);
    
    

    


    
    
    
    
    


}
