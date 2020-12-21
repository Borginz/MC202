#include <string.h>
#include <stdio.h>

int main2()
{
    char *linha;
    char *token;
    char aux[5];

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            scanf(" %m[^,\n]%*[,\n]", &linha);
            token = strtok(linha, " ");
            while (token != NULL)
            {
                printf("%s\n", token);
                token = strtok(NULL, " ");
            }
        }
    }
}
