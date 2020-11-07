#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int a,b,c;
    char n;
    for ( int i = 0; i < 2; i++){
        scanf(" %c", &n);
        while(scanf("%d", &a) > 0){
            printf("%d ", a);
        }
        printf("%d", EOF);
        printf("\n"); 

    }
    
}