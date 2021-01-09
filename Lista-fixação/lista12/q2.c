#include <stdlib.h>
#include <stdio.h>

typedef struct No {
    char dado;
    struct No *prox;
} No;

typedef struct No * p_no;

typedef struct{
    p_no ini, fim;
} String;
typedef String * p_string;

int eh_vazia(p_string f){
    return f->ini == NULL && f->fim == NULL;
}

p_string criar_string() {
    p_string f;
    f = malloc(sizeof(String));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void enfileira(p_string f, char x) {
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = NULL;
    if (f->ini == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    
}

int desenfileira(p_string f) {
    p_no primeiro = f->ini;
    int x = primeiro->dado;
    f->ini - f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(primeiro);
    return x;
}

int desempilhar(p_string f) {
    p_no fim = f->fim;
    int x = fim->dado;
    f->fim = f->fim->prox;
    free(fim);
    return x;
}

int main(){
    char c;
    int tanenbaum;
    p_string string;
    string = criar_string();
    scanf("%c", &c);
    while(c != '\n'){
        enfileira(string, c);
        scanf("%c", &c);
    }
    tanenbaum = 1;
    while (!eh_vazia){
        if(desenfileira(string) != desimpilhar(string)){
            printf("Não");
            tanenbaum = 0;
            break;
        }
    }
    if(tanenbaum){
        printf("Sim");
    }
    
}

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.