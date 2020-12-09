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
        strcpy(palavra_cop1, "");
        strcpy(palavra_cop2, "");
        strcpy(palavra_aux,palavra);
    }
}