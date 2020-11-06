#include<stdio.h>


typedef struct Lista_atendimento{
int Valor;
Lista_atendimento *prox;
}Lista_atendimento;


typedef struct Especialidade{
    int qtd_profissionais;
    Deques lista_de_espera;
}Especialidade;


typedef struct Paciente{
 char Nome[51];
char prioridade;
Lista_atendimento atendimento;
}Paciente;

typedef struct Node
{
    Paciente *paciente;
    Node *prox;
    Node *ant;
}Node;


typedef struct Deques{
 *ini;
 *fim;
  int qtd;
}Deques;

typedef struct Lista_paciente{
Paciente paciente;
struct Lista_paciente* prox;
}Lista_paciente;


typedef struct Dummy_Lista_paciente{
Lista_paciente *ini;
Lista_paciente *fim;
}Dummy_Lista_paciente;

int main(){
    char nome[51], prioridade;
    Especialidade cecom[9];
    



    while(scanf("\"%[^\"]\" %c%*s", &nome, &prioridade) != EOF){
        
        adicionar_paciente(&cecom[0].lista_de_espera,paciente);

    } 
}