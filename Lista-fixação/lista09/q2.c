int potenciaR(int x, int n)
{
    int aux;
    if (n == 0){
        return 1;

    }else if (n % 2 == 0){
        aux = potenciaR(x, n / 2);
        return aux * aux;
    }else{
        aux = potenciaR(x, (n - 1) / 2);
        return x * aux * aux;
    }
}
int potencia(int x, int n){
    double pot = 1.0;
    while (n > 0){
        if(n % 2 == 0)
        pot *= x;
        n -= 1; 
    }
    return pot;

}
  

// Feito por: Cícero Libardi, Lucas Oliveira e Leonardo Borges
