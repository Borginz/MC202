#include <stdio.h>
#include <math.h>
#include "tinta.h"

tinta misturar(tinta t1, tinta t2){
    tinta tfinal;
    tfinal.azul = (t1.azul + t2.azul) / 2;
    tfinal.vermelho = (t1.vermelho + t2.vermelho) / 2;
    tfinal.amarelo = (t1.amarelo + t2.amarelo) / 2;
    return tfinal;
}