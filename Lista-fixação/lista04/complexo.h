typedef struct {
    double real;
    double imag;
} complexo;

complexo complexo_le();
complexo complexo_novo(double real, double imag);
void complexo_imprime(complexo complex);
complexo complexo_soma(complexo complex1, complexo complex2);
complexo complexo_subtracao(complexo complex1, complexo complex2);
complexo complexo_potencia(complexo complex1, int a);
complexo complexo_multiplicacao(complexo complex1, complexo complex2);
complexo complexo_divisao(complexo complex1, complexo complex2);
int complexo_igualdade(complexo complex1, complexo complex2);
complexo complexo_conjugado(complexo complex1);

