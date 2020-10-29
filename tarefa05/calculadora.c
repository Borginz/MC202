#include <stdio.h>
#include <stdlib.h>



typedef struct no{
    int valor;
    struct no *dir;
    struct no *esq;
} no;


typedef struct Natural{
    struct no *mais_esq;
    struct no *mais_dir;
    int tamanho;

} Natural;

void inserir_dir( Natural *x, int digito){
    no* novo_no = malloc(sizeof(no));
    novo_no->valor = digito;
    novo_no->dir = NULL;
    
    if (x->mais_dir == NULL){// verificando se a lista for vazia
        novo_no->esq = NULL;
        x->mais_dir = novo_no;
        x->mais_esq = novo_no;
        x->tamanho = 1;
            
    } else{// caso a lista nao for vazia
        novo_no->esq = x->mais_dir;
        x->mais_dir->dir = novo_no; 
        x->mais_dir = novo_no;
        x->tamanho++;
        
    }
    
}

void inserir_esq( Natural *x, int digito){
    no* novo_no = malloc(sizeof(no));
    novo_no->valor = digito;
    novo_no->esq = NULL;
    
    if (x->mais_esq == NULL){// verificando se a lista for vazia
        novo_no->dir = NULL;
        x->mais_esq = novo_no;
        x->mais_dir = novo_no;    
    } else{// caso a lista nao for vazia
        novo_no->dir = x->mais_esq;
        x->mais_esq->esq = novo_no; 
        x->mais_esq = novo_no;
        
    }
}
// Função que le digito a digito a string 
Natural ler_natural(){
    char digito;
    Natural rv = {NULL,NULL};
    digito = getchar();
    while( digito < '0' || digito > '9')// verifica os invalidos e pula
    {
        digito = getchar();
    }
    while (digito >= '0' && digito <= '9')// verifica os validos e add a direita
    {
        inserir_dir(&rv, digito - '0');
        digito = getchar();
    }
    return rv;

    
}
void imprimir_natural(Natural digitos){
    no* aux1 = digitos.mais_esq;

    while(aux1){// enquanto nao acabar, imprime o digito
        printf("%d",aux1->valor);
        aux1 = aux1->dir;
    }
    printf("\n");
    
    

}
//Função para verificar digito a digito qual é maior
int verificar_digito(Natural a, Natural b){
    no* aux1 = a.mais_esq;
    no* aux2 = b.mais_esq;
    while (aux1){
        if (aux1->valor < aux2->valor){
            return 0;
        } else if ( aux1->valor > aux2->valor){
            return 1;
        } else{
            aux1 = aux1->dir;
            aux2 = aux2->dir; 
        }
    }
    return 1;
}
// Função que compara o tamanho de duas listas de nós, retorno 0 se o segundo for maior
int comparar_tamanho( Natural a, Natural b){
    if ( a.tamanho < b.tamanho){
        return 0;  
    }else if ( a.tamanho == b.tamanho ){
        if(!verificar_digito(a,b)){
            return 0;
        }            
    }
    return 1;
}
// Função para tirar os zeros a esquerda das listas
void tirar_zeros(Natural *x){
    no* aux = x->mais_esq;
    no* aux_aux = NULL;
    while (aux->dir != NULL && aux->valor == 0){//verificar se é valido ( zero a esquerda)
        aux->dir->esq = NULL;
        aux_aux = aux;
        aux = aux->dir;
        x->mais_esq = aux;
        free(aux_aux);      
    }
}
// Função para subtrair uma lista da outra
Natural subtrair_natural( Natural a, Natural b){
    Natural c = {NULL,NULL};
    no* aux1 = a.mais_dir;
    no* aux2 = b.mais_dir;
    int subtracao = 0;
    if(!comparar_tamanho(a,b)){// comparar o tamanho para subtrair
        aux1 = b.mais_dir;
        aux2 = a.mais_dir;
    }

    while(aux1){//enquanto o maior nao acabar
        subtracao = aux1->valor;
        if ( aux2 ){
            if (subtracao < aux2->valor){// verificar subtração digito a digito
                aux1->esq->valor-= 1;
                subtracao += 10;
            }
            subtracao -= aux2->valor;
            aux2 = aux2->esq;
        }
        aux1 = aux1->esq;
        inserir_esq(&c, subtracao);//insere a esquerda a subtração
    }
    tirar_zeros(&c);// tirar os zeros a esquerda em caso de numeros iguais 
    return c;
    
}
//Função para somar duas listas
Natural somar_natural(Natural a, Natural b){
    Natural c = {NULL,NULL};
    int carry = 0;
    no* aux1 = a.mais_dir;
    no* aux2 = b.mais_dir;
    
    while (aux1 || aux2)// verificar se ainda precisa somar
    {
        int soma = carry;
        if ( aux1 ){
            soma+=aux1->valor;
            aux1 = aux1->esq;
            
        }
        if ( aux2 ){
            soma+=aux2->valor;
            aux2 = aux2->esq;
        }
        inserir_esq(&c,soma%10);//insere a esquerda o resto
        carry = soma/10;
    }
    if (carry){
        inserir_esq(&c,carry);//insere a esq se ainda tiver carry
    }
    return c;
    
}
void liberar(no *x){
    no* aux = x;
    while(x){
        aux = x;
        x = x->dir;
        free(aux);
    }
}
// Função para multiplicar os digitos
Natural multiplicar_natural(Natural a, Natural b){
    Natural c = {NULL,NULL};
    Natural soma_aux = {NULL,NULL};
    no* aux_liberar_multi;
    int carry = 0, contador = 0;
    no* aux1 = a.mais_dir;
    no* aux2 = b.mais_dir;
    while(aux2){
        carry = 0;
            while(aux1){//enquanto nao acabar a linha de cima da multiplicação
                inserir_esq(&soma_aux, ((aux1->valor*aux2->valor+carry)%10));//inserir na soma aux a esquerda
                carry = ((aux1->valor*aux2->valor+carry)/10);// atualiza o carry
                aux1 = aux1->esq;
            }
            if(carry){
                inserir_esq(&soma_aux,carry);// se ainda estiver carry adiciona a esquerda
            }
            for ( int i = 0; i < contador; i++){// inserir zeros a direita para somar
                inserir_dir(&soma_aux,0);
            }
            contador++;
            aux_liberar_multi = c.mais_esq;
            c = somar_natural(soma_aux,c);//somar os produtos
            liberar(aux_liberar_multi);
            liberar(soma_aux.mais_esq);
            soma_aux.mais_dir = NULL;
            soma_aux.mais_esq = NULL;
            aux1 = a.mais_dir;
            aux2 = aux2->esq;
    }
    tirar_zeros(&c);
    return c;
    



}

int main(){
    int n;
    char op;
    
    scanf("%d", &n);
    for ( int i = 0; i < n;i++){
        scanf(" %c", &op);
         Natural a = ler_natural();
         Natural b = ler_natural();
         if ( op == '+'){ 
            Natural c = somar_natural(a,b);
            imprimir_natural(c);
            liberar(a.mais_esq);
            liberar(b.mais_esq);
            liberar(c.mais_esq);
        } else if ( op == '-'){
            Natural c = subtrair_natural(a,b);
            imprimir_natural(c);
            liberar(a.mais_esq);
            liberar(b.mais_esq);
            liberar(c.mais_esq);
        } else if (op == '*'){
            Natural c = multiplicar_natural(a,b);
            imprimir_natural(c);
            liberar(a.mais_esq);
            liberar(b.mais_esq);
            liberar(c.mais_esq);
        } 


    }
}
