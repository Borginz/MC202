#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Paciente Paciente;
typedef struct Node Node;
typedef struct Lista_atendimento Lista_atendimento;


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

typedef struct Lista_atendimento{
    no_Lista_atendimento *ini;
    no_Lista_atendimento *fim;
} Lista_atendimento;

typedef struct no_Lista_atendimento{
int Valor;
Lista_atendimento *prox;
}no_Lista_atendimento;

typedef struct Paciente{
    char Nome[51];
    char prioridade;
    Lista_atendimento atendimento;
    int qtd_atendimentos;
    int esta_fila;
}Paciente;

typedef struct Especialidade{
    int qtd_profissionais;
    Deques lista_de_espera;
}Especialidade;










void inicializar_deque(Deques *deque){
    deque->fim = NULL;
    deque->ini = NULL;
}
void inserir_inicio_deque(Deques *deque, Paciente*pont_paciente){
    Node *novo_no = malloc(sizeof(Node));
    novo_no->paciente = pont_paciente;
    
    if (deque->ini){
        novo_no->prox = deque->ini;
        novo_no->ant = deque->ini->ant;
        deque->ini->ant = novo_no;
        deque->ini = novo_no;
    } else{
        deque->ini = novo_no;
        deque->fim = novo_no;   
    }
    
        

}

void inserir_final_deque(Deques *deque, Paciente *pont_paciente){
    Node *novo_no = malloc(sizeof(Node));
    novo_no->paciente = pont_paciente;
    if (deque->fim){
        novo_no->ant = deque->fim;
        deque->fim->prox = novo_no;
        deque->fim = novo_no;
        novo_no->prox = NULL;
    } else{
        deque->ini = novo_no;
        deque->fim = novo_no;
    } 
}

void retirar_inicio_deque(Deques *deque, Paciente *p){
    Node *aux = malloc(sizeof(Node));
    aux = deque->ini;
    deque->ini = aux->prox;
    free(aux);
    
}
void remover_atendimento(Lista_atendimento *lista, Paciente *p){
    no_Lista_atendimento *aux = malloc(sizeof(no_Lista_atendimento));
    aux = lista->ini;
    lista->ini = aux->prox;
    free(aux);
}
void inicializar(Especialidade cecom[]){
    int qtd[9] = {10,2,5,3,4,7,2,1,4};
    for(int i = 0; i < 9; i++){
        inicializar_deque(&cecom[i].lista_de_espera);
        cecom[i].qtd_profissionais = qtd[i]; 
    }


}

void adicionar_atendimento_pac(int id, Paciente* paciente){
    no_Lista_atendimento *novo_no = malloc(sizeof(no_Lista_atendimento));
    novo_no->Valor = id;
    novo_no->prox = NULL;
    if ( paciente->atendimento.ini){
        paciente->atendimento.fim->prox = novo_no;
        paciente->atendimento.fim = novo_no;
    } else{
        paciente->atendimento.ini = novo_no;
        paciente->atendimento.fim = novo_no;
    }
}


void atender_pacientes(Deques *lista_paciente, Especialidade cecom[]){
    int hora = 8;
    int minutos = 0;
    Node *aux = malloc(sizeof(Node));
    while(lista_paciente->ini){
        aux = lista_paciente->ini;
        while(aux){
            if (aux->paciente->esta_fila == 0 && aux->paciente->qtd_atendimentos > 0){
                int id = aux->paciente->atendimento.ini->Valor;
                Deques lista_add = cecom[id-1].lista_de_espera;
                Lista_atendimento lista_remover = aux->paciente->atendimento;
                if (aux->paciente->prioridade == 'P'){
                    inserir_inicio_deque(&lista_add, aux->paciente);
                    remover_atendimento(&lista_remover, aux->paciente);
                } else{
                    inserir_final_deque(&lista_add, aux->paciente);
                    remover_atendimento(&lista_remover, aux->paciente);

                }

            } else if (aux->paciente->esta_fila == 1 && aux->paciente->qtd_atendimentos == 0){
                continue;
            } else if (aux->paciente->esta_fila == 0 && aux->paciente->qtd_atendimentos == 0){
                //imprimir_paciente()
                retirar_inicio_deque(&lista_paciente, aux->paciente);
            }
            aux = aux->prox;
        }

        for( int j = 0; j < 9; j++){
            Especialidade profi_atual = cecom[j];
            for( int i = 0; i < profi_atual.qtd_profissionais || profi_atual.lista_de_espera.ini == NULL; i++){
                profi_atual.lista_de_espera.ini->paciente->qtd_atendimentos--;
                profi_atual.lista_de_espera.ini->paciente->esta_fila = 0;
                retirar_inicio_deque(&profi_atual.lista_de_espera,profi_atual.lista_de_espera.ini->paciente);
            }
        }
        minutos += 10;
        if ( minutos >= 60){
            hora += 1;
            minutos = 0;
        }
        

    }
}




int main(){
    char nome[51], prioridade;
    Especialidade cecom[9];
    int id;
    inicializar(cecom);
    Deques lista_paciente;
    Deques Lista_atendidos;
    lista_paciente.fim = NULL;
    lista_paciente.ini = NULL;



    while(scanf("\"%[^\"]\" %c%*s", nome, &prioridade) != EOF){
        
        Paciente *paciente = (Paciente*)malloc(sizeof(Paciente));
        strcpy(paciente->Nome,nome);
        paciente->prioridade = prioridade;
        paciente->qtd_atendimentos = 0;
        
        while(scanf("%d",&id) > 0){
            adicionar_atendimento_pac(id,paciente);
            paciente->qtd_atendimentos += 1;
        }
        inserir_final_deque(paciente,&lista_paciente);
    }
    atender_pacientes(&lista_paciente, cecom); 
}