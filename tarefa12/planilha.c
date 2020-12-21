#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAX_PILHA (25)

typedef struct pilha
{
    int pilha[MAX_PILHA]; 
    int tamanho;
}*Pilha;

Pilha nova_pilha(){
    return NULL;
}

void destruir_pilha(Pilha pilha){
}

void empilha(int valor, Pilha pilha){

}

int pop(Pilha pilha){
    return 0;
}


bool eh_letra(char c){
    return false;
}

typedef struct resultado
{
    int resultado;
    bool erro;
}Resultado;

const Resultado ERRO = {0,true};


typedef struct No
{
    char token[10];
    struct No *prox;
} No;

typedef struct No *p_no;

typedef struct No_dummy
{
    No *ini;
    No *fim;
    bool visitando;
} deque;
deque **iniciar_matriz(int altura, int largura)
{
    deque **matriz = malloc(altura * sizeof(deque *));

    for (char i = 0; i < altura; i++)
    {
        matriz[i] = calloc(largura , sizeof(deque));
    }
    return matriz;
}

void inserir_lista_final(char *token, deque *cabeca){// colocar no final do deque
    No *novo_no = malloc(sizeof(No));
    strcpy(novo_no->token, token);
    novo_no->prox = NULL;
    if (cabeca->fim){
        cabeca->fim->prox = novo_no;
        cabeca->fim = novo_no;
    } else{
        cabeca->ini = novo_no;
        cabeca->fim = novo_no;
    }
}




deque **ler_csv(deque **matriz, int altura, int largura, FILE *arquivo)
{
    char *linha;
    char *token;
    char aux[5];

    for (int num_linha = 0; num_linha < altura; num_linha++)
    {
        for (int num_coluna = 0; num_coluna < largura; num_coluna++)
        {
            fscanf(arquivo, " %m[^,\n]%*[,\n]", &linha);
            token = strtok(linha, " ");
            while (token != NULL)
            {
                inserir_lista_final(token,&(matriz[num_linha][num_coluna]));
                token = strtok(NULL, " ");
            }
        }
    }

    return matriz;
}

/*int ler_parenteses(char *celula, char ***matriz)
{
    char termo_a[10];
    char *celula_parcial = celula;
    int avanco, valor_a, valor_b;
    sscanf(celula_parcial, " ( %s%n", termo_a, &avanco);
    celula_parcial += avanco;
    if (termo_a[0] == '(')
    {
        valor_a = ler_parenteses(celula + 2, matriz);
    }

    sscanf(celula, " ")
}*/
Resultado ler_celula(char *coordenada, deque **matriz);



Resultado resolver_pilha(p_no inicio, deque **matriz){
    Pilha valores = nova_pilha();
    Pilha operadores = nova_pilha();

    while(inicio){
        if (eh_letra(inicio->token[0])){
            Resultado rv = ler_celula(inicio->token, matriz);
            if(rv.erro){
                destruir_pilha(valores);
                destruir_pilha(operadores);
                return ERRO;
            } else{
                empilha(rv.resultado,valores);
            }
        } else if (inicio->token[0] == '+'){
            empilha('+',operadores);
        } else if (inicio->token[0] == '-'){
            empilha('-',operadores);
        } else if ( inicio->token[0] == ')'){
            int b = pop(valores);
            int a = pop(valores);
            if(pop(operadores) == '+'){
                empilha(a+b,valores);
            } else{
                empilha(a-b,valores);
            }
        }     
        inicio = inicio->prox;
    }
    Resultado rv = {pop(valores), false};
    destruir_pilha(valores);
    destruir_pilha(operadores);
    return rv;
}


Resultado ler_celula(char *coordenada, deque **matriz)
{
    char x_letra[2];
    int x, y, constante;


    sscanf(coordenada, " %[A-Z]%d", x_letra, &y);
    x = x_letra[0] - 'A';
    y -= 1;
    
    if ( matriz[y][x].visitando){
        return ERRO; 
    }
    
    p_no inicio = matriz[y][x].ini;
    if (inicio->token[0] == '='){
        
        matriz[y][x].visitando = true;
        Resultado rv = resolver_pilha(inicio,matriz);
        matriz[y][x].visitando = false;
        return rv;

    } else{
        Resultado rv;
        sscanf(inicio->token,"%d", &rv.resultado);
        rv.erro = false;
        return rv;
    }

}

int main()
{
    char *nome_arquivo;
    int altura, largura;
    scanf("%ms", &nome_arquivo);
    scanf("%d %d", &largura, &altura);
    FILE *arquivo = fopen(nome_arquivo, "r");
    char r, celula[5], *valor_alterar;
    deque **matriz;
    
    matriz = iniciar_matriz(altura, largura);
    matriz = ler_csv(matriz, altura, largura, arquivo);

    while (fscanf(arquivo, "%c", &r) != EOF)
    {
        if (r == 'G')
        {
            Resultado valor_celula;
            scanf("%s", celula);
            valor_celula = ler_celula(celula, matriz);
            if ( valor_celula.erro){
                printf("%s: #ERRO#\n", celula);
            } else{
                printf("%s: %d\n", celula, valor_celula.resultado);
            }
            
        }
        else
        {
            scanf("%s", celula);
            scanf("%ms", &valor_alterar);
            printf("%s: %s -> ", celula, valor_alterar);
        }
    }
    fclose(arquivo);
    return 0;
}