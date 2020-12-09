#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int p;
    char palavra[] = "CICERO";
    char palavra_aux[26];
    char palavra_cop1[26];
    char palavra_cop2[26];
    strcpy(palavra_aux, palavra);


                // palavra = CICERO'\0'
                // palavra_aux = '\0'ICERO'\0'
                // palavra_cop1 = CICERO'\0'
                // palavra_cop2 = CICERO'\0'
    int idx = 0;
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
            printf("%s\n", palavra_cop1);
        }
        strcpy(palavra_aux,palavra);
    }
    strcpy(palavra_cop1,"");
    printf("%s\n", palavra_cop1);
}