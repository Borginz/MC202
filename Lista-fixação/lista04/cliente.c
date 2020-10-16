#include <stdio.h>
#include "complexo.h"

int main() {
    complexo complex1, complex2, soma, subtração, potencia, divisao, conjungado;
    int igualdade, pot;
    complex1 = complexo_le();
    complex2= complexo_le();
    soma = complexo_soma(complex1, complex2);
    complexo_imprime(soma);
    subtração = complexo_subtracao(complex1, complex2);
    complexo_imprime(subtração);
    potencia = complexo_potencia(complex1, pot);
    complexo_imprime(potencia);
    divisao = complexo_divisao(complex1, complex2);
    complexo_imprime(divisao);
    igualdade = complexo_igualdade(complex1, complex2);
    printf("eles são iguais ?", igualdade);
    conjungado = complexo_conjugado(complex1);
    complexo_imprime(conjungado);
    

    return 0;

}