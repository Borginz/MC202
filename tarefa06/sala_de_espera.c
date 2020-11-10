#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct Paciente Paciente;
typedef struct Node Node;
typedef struct Lista_atendimento Lista_atendimento;
typedef struct no_Lista_atendimento no_Lista_atendimento;
 
 
 
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
 
typedef struct no_Lista_atendimento{
int Valor;
no_Lista_atendimento *prox;
}no_Lista_atendimento;
 
typedef struct Lista_atendimento{
    no_Lista_atendimento *ini;
    no_Lista_atendimento *fim;
} Lista_atendimento;
 
 
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
        novo_no->ant = NULL;
        novo_no->prox = NULL;   
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
        novo_no->ant = NULL;
        novo_no->prox = NULL;
    } 
}
 
void retirar_inicio_deque(Deques *deque){
    Node *aux = deque->ini;
    deque->ini = aux->prox;
    if(aux->prox == NULL)
        deque->fim = NULL;
    free(aux);
    
}
void remover_atendimento(Lista_atendimento *lista, Paciente *p){
    no_Lista_atendimento *aux = lista->ini;
    if(lista->ini->prox == NULL)
        lista->fim = NULL;
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
void imprimir_paciente(int hora, int minutos, Paciente *paciente){
    printf("%02d:%02d %s\n", hora, minutos, paciente->Nome);
 
}
 


void atender_pacientes(Deques *lista_paciente, Especialidade cecom[]){
    int hora = 8;
    int minutos = 0;
    Node *aux;
    int terminou = 0; 
    while(terminou == 0){//mudei a condição porque estava complicado tirar a pessoa da lista
        terminou = 1;    
        aux = lista_paciente->ini;
        while(aux){
            if (aux->paciente->esta_fila == 0 && aux->paciente->qtd_atendimentos > 0){
                int id = aux->paciente->atendimento.ini->Valor;
                if (aux->paciente->prioridade == 'p'){
                    inserir_inicio_deque(&cecom[id-1].lista_de_espera, aux->paciente);
                    remover_atendimento(&aux->paciente->atendimento, aux->paciente);
                } else{
                    inserir_final_deque(&cecom[id-1].lista_de_espera, aux->paciente);
                    remover_atendimento(&aux->paciente->atendimento, aux->paciente);
 
                }
                aux->paciente->esta_fila = 1;
                
 
            } else if (aux->paciente->esta_fila == 0 && aux->paciente->qtd_atendimentos == 0){
                imprimir_paciente(hora, minutos, aux->paciente);
                aux->paciente->qtd_atendimentos = -1;
                
                
                          
                
            }
            aux = aux->prox;
            
            
        }
 
        
 
        for( int j = 0; j < 9; j++){
            for( int i = 0; i < cecom[j].qtd_profissionais && cecom[j].lista_de_espera.ini != NULL; i++){
                cecom[j].lista_de_espera.ini->paciente->qtd_atendimentos--;
                cecom[j].lista_de_espera.ini->paciente->esta_fila = 0;
                retirar_inicio_deque(&cecom[j].lista_de_espera);
                terminou = 0;
            }
        }
        minutos += 10;
        if ( minutos == 60){
            hora += 1;
            minutos = 0;
        }
        
 
    }
}
 
void inicializar_atendimento_pac(Paciente *paciente){
    paciente->atendimento.fim = NULL;
    paciente->atendimento.ini = NULL;
}

void liberar_lista_paciente(Deques *lista_paciente){
    int i = 0;
    while(lista_paciente->ini){
        free(lista_paciente->ini->paciente);
        retirar_inicio_deque(lista_paciente);
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
 
 
 
    while(scanf("\"%[^\"]\" %c%*s", nome, &prioridade) != EOF){
        
        Paciente *paciente = (Paciente*)malloc(sizeof(Paciente));
        strcpy(paciente->Nome,nome);
        paciente->prioridade = prioridade;
        paciente->qtd_atendimentos = 0;
        paciente->esta_fila = 0;
        //paciente->ja_printou = 0;
        inicializar_atendimento_pac(paciente);
        while(scanf("%d",&id) > 0){
            adicionar_atendimento_pac(id,paciente);
            paciente->qtd_atendimentos += 1;
        }
        inserir_final_deque(&lista_paciente, paciente);
    }
 
    atender_pacientes(&lista_paciente, cecom);
    liberar_lista_paciente(&lista_paciente);
    

    
}