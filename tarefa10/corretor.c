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

int hash(char *palavra)
{
    int i, n = 0;
    for (i = 0; i < strlen(palavra); i++)
        n = (256 * n + palavra[i]) % MAX;
    return n;
}

void inserir(p_hash t, char *palavra)
{
    int n = hash(palavra);
    t->vetor[n] = adicionar_elemento(t->vetor[n], palavra);
}

int buscar_hash(p_no lista, char* palavra){
    while(strcmp(lista->palavra,palavra) != 0 && lista != NULL){
        lista = lista->prox;
    }
    if (lista){
        return 1;
    }
    return 0;
}




int main()
{
    p_hash hash;
    hash->vetor[1513];
    int a,b;
    char palavra_ini[26];
    scanf("%d %d", &a, &b);
    for(int i = 0; i < a; i++){
        scanf("%s", palavra_ini);
        inserir(&hash,palavra_ini);
    }
    for(int i = 0; i < b;i++){
        scanf("%s", palavra_ini);
        if(buscar_hash(&hash, palavra_ini)){
            printf("verde\n");
        }
        else if(verificar_amarelo(&hash,palavra_ini)){
            printf("amareloz\n");
        }
        else{
            printf("vermlho\n");
        }

    }
    //liberar_hash

}