#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 1000

int hash(int chave1, int chave2) {
    int i, n = 0;
    n = (MAX * ((sqrt(5) - 1)/2 * chave1 * chave2) % 1) / 1;
    return n;
}