#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
    int chegada;
}Paciente;

typedef struct Node
{
    Paciente *paciente;
    Node *prox;
    Node *ant;
}Node;


typedef struct Deques{
 Node*ini;
 Node*fim;
}Deques;


void inicializar_deque(Deques *deque){
    deque->fim = NULL;
    deque->ini = NULL;
}
void inserir_inicio_deque(Deques *deque, Paciente*pont_paciente){
    Node *novo_no = malloc(sizeof(Node));
    novo_no->paciente = pont_paciente;
    novo_no->prox = deque->ini;
    novo_no->ant = deque->ini->ant;
    deque->ini->ant = novo_no;
    deque->ini = novo_no;    

}

void inserir_final_deque(Deques *deque, Paciente *pont_paciente){
    Node *novo_no = malloc(sizeof(Node));
    novo_no->paciente = pont_paciente;
    novo_no->ant = deque->fim;
    deque->fim->prox = novo_no;
    deque->fim = novo_no;
    novo_no->prox = NULL;
}

void inicializar(Especialidade cecom[]){
    int qtd[9] = {10,2,5,3,4,7,2,1,4};
    for(int i = 0; i < 9; i++){
        inicializar_deque(&cecom[i].lista_de_espera);
        cecom[i].qtd_profissionais = qtd[i]; 
    }


}


int main(){
    char nome[51], prioridade;
    Especialidade cecom[9];
    int id;
    inicializar(cecom);
    Deques lista_paciente;
    lista_paciente.fim = NULL;
    lista_paciente.ini = NULL;

    

    


    



    while(scanf("\"%[^\"]\" %c%*s", &nome, &prioridade) != EOF){
        Paciente *paciente = (Paciente*)malloc(sizeof(Paciente));
        strcpy(paciente->Nome,nome);
        paciente->prioridade = prioridade;
        while(scanf("%d",&id) > 0){
            adicionar_atendimento_pac(id,paciente);
        }
        adicionar_paciente(paciente,&lista_paciente);
    }
    while()
    
    adicionar_cecom(&cecom[0].lista_de_espera,paciente); 
}