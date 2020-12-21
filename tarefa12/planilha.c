#include <string.h>
#include <stdio.h>
typedef struct No
{
    char token[5];
    struct No *prox;
} No;

typedef struct No *p_no;

typedef struct No_dummy
{
    No *ini;
    No *fim;
} dummy;
No **iniciar_matriz(int n, int m)
{
    No **matriz = (No **)malloc(n * sizeof(No *));

    for (char i = 0; i < n; i++)
    {
        matriz[i] = (No *)malloc(m * sizeof(No));
    }
    return matriz;
}

No **ler_csv(No**matriz, int n, int m, FILE *arquivo)
{
    No novo;
    char linha[15];
    char *token;
    char aux[5];

    for (int i = 0; i < n-1; i++)
    {
        fscanf(arquivo, " %[^,],", linha);
        token = strtok(linha, " ");
        while (token != NULL)
        {
            inserir_lista(token);
            token = strtok(NULL, " ");
        }
    }
    fscanf(arquivo," %[^\n]\n", linha);
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

int ler_celula(char *coordenada, char ***matriz)
{
    char x_letra[2];
    int x, y, constante;
    sscanf(coordenada, " %[A-Z]%d", x_letra, &y);
    x = x_letra[0] - 'A';
    y -= 1;
    char *celula = matriz[y][x];

    if (sscanf(celula, " %d", &constante) != 0)
    {
        return constante;
    }
    else if (sscanf(celula, " %[A-Z]") != 0)
    {
        return ler_celula(celula, matriz);
    }
    else
    {
        return ler_parenteses(celula, matriz);
    }
}

int main()
{
    char *nome_arquivo;
    int m, n, valor_celula;
    scanf("%ms", &nome_arquivo);
    scanf("%d %d", &m, &n);
    FILE *arquivo = fopen(nome_arquivo, "r");
    char r, celula[5], *valor_alterar, ***matriz;
    matriz = iniciar_matriz(n, m);
    matriz = ler_csv(matriz, n, m, arquivo);

    while (fscanf(arquivo, "%c", &r) != EOF)
    {
        if (r == 'G')
        {
            scanf("%s", celula);
            valor_celula = ler_celula(celula, matriz);
            printf("%s: %d\n", celula, valor_celula);
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