#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int main()
{
    int p;
    int w;
    char palavra[] = "LEONARDO";
    char palavra_aux[26];
    char palavra_cop1[26];
    char palavra_cop2[26];
    strcpy(palavra_aux, palavra);
    //strcpy(palavra_cop1,palavra);

            // palavra = CICERO
            // palavra_aux = '\0'ICERO
            // palavra_cop1 = ICERO'\0'

    for (int i = 0; i < strlen(palavra_aux); i++)
    {
        char atual = palavra_aux[i];
        for (int k = 0; k < 26; k++)
        {
            palavra_aux[i] = k + 'a';
            printf("%s\n", palavra_aux);
        }
        palavra_aux[i] = atual;
    }
}