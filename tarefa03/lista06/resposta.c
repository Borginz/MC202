#include<stdio.h>
#include<stdlib.h>

void f(int a, int b){
    int c = a;
    a = b;
    b = c;
}

void g(int *c, int n){
    c = malloc(sizeof(int)*n);
}

void h(int*h){
    *h = 100;
}


int main(){
    int a = 1, b = 2, c = 3;
    int **d;
    d = malloc(sizeof(int*));
    f(a,b);
    g(d[1],1);
    h(*d);
    free(d);
    printf("%d, %d, %d", a, c, d[1][1]);
    return 0;
}

