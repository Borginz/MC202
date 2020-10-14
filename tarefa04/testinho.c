#include <stdio.h>

int incognita(int n){
    if ( n ==0)
    return 1;
    if(n == 1)
    return 1;
    else
    return incognita(n-1) + 2 * incognita(n-2);
    
}


int main(){
    int n,f;
    scanf("%d", &n);
    f = incognita(n);
    printf("o numero é:%d", f);



}