#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1783

typedef struct No
{
    char palavra[26];
    struct No *prox;
} No;

typedef struct No *p_no;

typedef struct Hash
{
    p_no vetor[MAX];
} Hash;

typedef struct Hash *p_hash;

p_no adicionar_elemento(p_no lista, char palavra[])//adiciono na lista ligada atualizando o inicio e devolvo o inicio
{
    p_no novo;
    novo = malloc(sizeof(No));
    strcpy(novo->palavra, palavra);
    novo->prox = lista;
    return novo;
}

int hashing(char *palavra)//função pelo metodo da divisao do hash
{
    int i, n = 0;
    for (i = 0; i < strlen(palavra); i++)
        n = (256 * n + palavra[i]) % MAX;
    return n;
}

void inserir(p_hash t, char *palavra)//calculo o hash e adiciono na posição correta
{
    int n = hashing(palavra);
    t->vetor[n] = adicionar_elemento(t->vetor[n], palavra);
}

int buscar_lista(p_no lista, char *palavra)
{

    while (lista != NULL)//procuro até ser null
    {
        if (strcmp(lista->palavra, palavra) == 0)//comparo, se for igual achei
        {
            return 1;
        }
        else// se n for atualizo até chegar no ultimo
        {
            lista = lista->prox;
        }
    }
    return 0;//devolvo falso se n achei
}

int buscar_hash(p_hash hash, char *palavra)//pego o indice e busco na lista ligada
{
    int n = hashing(palavra);
    int a = buscar_lista(hash->vetor[n], palavra);
    return a;
}

int verificar_amarelo(p_hash hash, char *palavra)// Função que olha caso a caso do amarelo
{
    int p;
    int w;
    char palavra_aux[26];
    char palavra_cop1[26];
    strcpy(palavra_aux, palavra);
    strcpy(palavra_cop1, palavra);

    for (int i = 0; i < strlen(palavra_aux); i++)//marco o char que quero alterar
    {
        char atual = palavra_aux[i];//salvo em atual
        for (int k = 0; k < 26; k++)
        {
            palavra_aux[i] = k + 'a';// vou mudando pelas palavras do alfabeto
            if (buscar_hash(hash, palavra_aux))//busco no hash a tentativa
            {
                return 1;
            }
        }
        palavra_aux[i] = atual;//devolvo o char certo
    }

    // verifiquei se trocando as letras funciona;
    // Devo agora adicionar um caracter e verificar 
    for (int i = 0; i <= strlen(palavra); i++)
    {
        palavra_aux[i] = '\0';//troco para '0\' para copiar antes disso
        for (int j = 0; palavra_aux[j] != '\0'; j++)
        {
            palavra_cop1[j] = palavra_aux[j];//copio tudo antes da marcação
        }
        for (p = i; palavra[p] != '\0'; p++)
        {
            palavra_cop1[p + 1] = palavra[p];//copio tudo depois da marcacao
        }
        palavra_cop1[p + 1] = '\0';//adiciono o '0\'
        for (int k = 0; k < 26; k++)
        {
            palavra_cop1[i] = 'a' + k;//testo todas as letras adicionando no meio
            if (buscar_hash(hash, palavra_cop1))
            {
                return 1;
            }
        }
        strcpy(palavra_aux, palavra);
        strcpy(palavra_cop1, "");
    }


    // Agora devo retirar um caracter e verificar 

    for (int m = 0; m < strlen(palavra); m++)//marco onde eu quero retirar
    {
        palavra_aux[m] = '\0';//marco a posição
        for (int i = 0; palavra_aux[i] != '\0'; i++)
        {
            palavra_cop1[i] = palavra[i];//copio tudo antes
        }
        for (w = m; palavra[w] != '\0'; w++)//copio depois 
        {
            palavra_cop1[w] = palavra[w + 1];
        }
        palavra_cop1[w + 1] = '\0';//adiciono a quebra no final
        if (buscar_hash(hash, palavra_cop1))//busco
        {
            return 1;
        }
        strcpy(palavra_cop1, "");
        strcpy(palavra_aux, palavra);
    }
    return 0;

}
void liberar_hash(p_hash hash)//liberar a lista ligada do hash
{
    p_no aux;
    for (int i = 0; i < MAX; i++)
    {
        while (hash->vetor[i]){
            aux = hash->vetor[i];
            hash->vetor[i] = hash->vetor[i]->prox;
            free(aux);

        }
    }
    free(hash);
}

int main()
{
    p_hash hash;
    hash = malloc(sizeof(Hash));//iniciar o hash
    for (int i = 0; i < MAX; i++)// iniciar o vetor com null
    {
        hash->vetor[i] = NULL;
    }
    int a, b;
    char palavra_ini[26];//palavra auxiliar
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++)
    {
        scanf("%s", palavra_ini);
        inserir(hash, palavra_ini);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%s", palavra_ini);
        if (buscar_hash(hash, palavra_ini))//faço busca simples no hash
        {
            printf("verde\n");
        }
        else if (verificar_amarelo(hash, palavra_ini))//procuro cada caso do amarelo
        {
            printf("amarelo\n");
        }
        else// se nao for verde ou amarelo eu sei que é vermelho
        {
            printf("vermelho\n");
        }
    }
    liberar_hash(hash);
}