#include <stdio.h>
#include <string.h>//necessário para strcmp
int main (void)
{
  char str1[20] = "Amanda";
  char str2[20] = "Ana Paula silva";
  int retorno;
  double a = 300;
  
  retorno = strcmp(str1, str2);
  printf("retorno = %d\n", retorno);
  //mostra o retorno da função strcmp
  printf("%f ", a);  
  
  return 0;
}