#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int busca_binaria(int vetor[], int inicio, int fim, int valor_desejado) {
    int meio;
    if (inicio > fim)
        return -1;
    else {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor_desejado)
            return meio;
        else if (valor_desejado < vetor[meio])
            return busca_binaria(vetor, inicio, meio - 1, valor_desejado);
        else
            return busca_binaria(vetor, meio + 1, fim, valor_desejado);
    }
}

// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira