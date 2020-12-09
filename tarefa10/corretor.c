#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1783

typedef struct
{
    char palavra[26];
    No *prox;
} No;

typedef No *p_no;

typedef struct
{
    p_no vetor[MAX];
} Hash;

typedef Hash *p_hash;

p_no adicionar_elemento(p_no lista, char palavra[])
{
    p_no novo;
    novo = malloc(sizeof(No));
    strcpy(novo->palavra, palavra);
    novo->prox = lista;
    return novo;
}

int hashing(char *palavra)
{
    int i, n = 0;
    for (i = 0; i < strlen(palavra); i++)
        n = (256 * n + palavra[i]) % MAX;
    return n;
}

void inserir(p_hash t, char *palavra)
{
    int n = hashing(palavra);
    t->vetor[n] = adicionar_elemento(t->vetor[n], palavra);
}

int buscar_lista(p_no lista, char *palavra)
{

    while (strcmp(lista->palavra, palavra) != 0 && lista != NULL)
    {
        lista = lista->prox;
    }
    if (lista)
    {
        return 1;
    }
    return 0;
}

int buscar_hash(p_hash hash, char *palavra)
{
    int n = hashing(palavra);
    int a = buscar_lista(hash->vetor[n], palavra);
    return a;
}


int verificar_amarelo(p_hash hash, char *palavra)
{
    int p;
    int w;
    char palavra_aux[26];
    char palavra_cop1[26];
    strcpy(palavra_aux, palavra);
    strcpy(palavra_cop1,palavra);

    for (int i = 0; i < strlen(palavra_aux); i++)
    {
        char atual = palavra_aux[i];
        for (int k = 0; k < 26; k++)
        {
            palavra_aux[i] = k + 'a';
            if (buscar_hash(hash, palavra_aux))
            {
                return 1;
            }
        }
        palavra_aux[i] = atual;
    }
    // verifiquei se trocando as letras funciona;
    // devo agora tirar um caracter e procurar
    for (int i = 0; i <= strlen(palavra); i++)
    {
        palavra_aux[i] = '\0';
        for ( int j = 0; palavra_aux[j] != '\0'; j++){
            palavra_cop1[j] = palavra_aux[j];
        }
        for (p = i; palavra[p]!= '\0'; p++){
            palavra_cop1[p+1] = palavra[p];
        }
        palavra_cop1[p+1] = '\0';
        for ( int k = 0; k < 26; k++){
            palavra_cop1[i] = 'a' + k;
            if ( buscar_hash(hash,palavra)){
                return 1;
            }
        }
        strcpy(palavra_aux,palavra);
        strcpy(palavra_cop1,"");
    }







        

    for (int m = 0; m < strlen(palavra); m++)
    {
        palavra_aux[m] = '\0';
        for (int i = 0; palavra_aux[i] != '\0'; i++)
        {
            palavra_cop1[i] = palavra[i];
        }
        for (w = m; palavra[w] != '\0'; w++)
        {
            palavra_cop1[w] = palavra[w+1];
        }
        palavra_cop1[w+1] = '\0';
        printf("%s\n", palavra_cop1);
        if ( buscar_hash(hash, palavra)){
            return 1;
        }
        strcpy(palavra_cop1, "");
        strcpy(palavra_aux,palavra);
    }
    return 0;

    /*for ( int m = 0; m < strlen(palavra); m++){
        if ( m == strlen(palavra)-1){
            if(buscar_hash(hash,palavra[]))
        }
        for ( int n = m+1; n < strlen(palavra); n++){
            palavra_aux[n-1] = palavra_aux[n];
        }
        if(buscar_hash(hash,palavra_aux)){
            return 1;
        }
        strcpy(palavra_aux, palavra);
    }*/
    //agora eu tenho que adicionar
}

int main()
{
    p_hash hash;
    hash->vetor[1513];
    int a, b;
    char palavra_ini[26];
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++)
    {
        scanf("%s", palavra_ini);
        inserir(&hash, palavra_ini);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%s", palavra_ini);
        if (buscar_hash(&hash, palavra_ini))
        {
            printf("verde\n");
        }
        else if (verificar_amarelo(&hash, palavra_ini))
        {
            printf("amarelo\n");
        }
        else
        {
            printf("vermlho\n");
        }
    }
    //liberar_hash
}