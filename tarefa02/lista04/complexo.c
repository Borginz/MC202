#include <stdio.h>
#include <math.h>
#include "complexo.h"

complexo complexo_novo(double real, double imag) {
    complexo novo;
    novo.real = real;
    novo.imag = imag;
    return novo;
}


complexo complexo_soma(complexo complex1, complexo complex2) {
    complexo auxiliar;
    double  soma_real, soma_img;
    soma_real = complex1.real + complex2.real;
    soma_img = complex1.imag + complex2.imag;
    auxiliar = complexo_novo(soma_real, soma_img);
    return auxiliar;
}


complexo complexo_le() {
    complexo complex;
    scanf("%lf %lf", &complex.real, &complex.imag);
    return complex;
}

void complexo_imprime(complexo complex) {
    printf("%.02lf %.02lf\n", complex.real, complex.imag);
}



complexo complexo_subtracao(complexo complex1, complexo complex2) {
    complexo auxiliar;
    double subt_real, subt_img;
    subt_real = complex1.real - complex2.real;
    subt_img =  complex1.imag - complex2.imag;
    auxiliar = complexo_novo(subt_real, subt_img);
    return auxiliar;
}



complexo complexo_multiplicacao(complexo complex1, complexo complex2) {
    complexo auxiliar;
    double mult_real, mult_img;
    mult_real = (complex1.real * complex2.real) - (complex1.imag * complex2.imag);
    mult_img = (complex1.real * complex2.imag) + (complex2.real * complex1.imag);
    auxiliar = complexo_novo(mult_real, mult_real );
    return auxiliar;
}

complexo complexo_divisao(complexo complex1, complexo complex2) {
    complexo conjugado = complexo_conjugado(complex2);
    complexo numerador = complexo_multiplicacao(complex1, conjugado);
    complexo auxiliar;
    float denominador = ((complex2.real * complex2.real) + (complex2.imag * complex2.imag));
    if (denominador == 0.00) {
        printf("A operação não está bem definida.");
        return complexo_novo(0, 0);
    } 
    auxiliar = complexo_novo(numerador.real / denominador, numerador.imag / denominador);
    return auxiliar;
}

complexo complexo_potencia(complexo complex1, int pot) {
    complexo novo = complex1;
    for (int i = 1; i < pot; i++) {
        novo.real = (novo.real * novo.real) - (novo.imag * novo.imag);
        novo.imag = (novo.real * novo.imag) + (novo.imag * novo.real);
    }
    return novo;
}

int complexo_igualdade(complexo complex1, complexo complex2) {
    if (complex1.real == complex2.real && complex1.imag == complex2.imag) {
        return 1;
    } else return 0;
}

complexo complexo_conjugado(complexo complex) {
    complexo auxiliar;
    auxiliar = complexo_novo(complex.real, -(complex.imag));
    return auxiliar;
}
