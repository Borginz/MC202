#include <stdio.h>
#include <stdlib.h>
#include "tinta.h"

int main(){
    tinta t1;
    tinta t2;
    tinta tfinal;
    scanf("%lf %lf %lf", &t1.azul, &t1.vermelho, &t1.amarelo);
    scanf("%lf %lf %lf", &t2.azul, &t2.vermelho, &t2.amarelo);
    tfinal = misturar(t1, t2);
    printf("%.02lf %.02lf %.02lf\n", tfinal.azul, tfinal.vermelho, tfinal.amarelo);
    
}