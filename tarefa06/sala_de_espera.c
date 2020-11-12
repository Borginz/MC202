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
void inserir_inicio_deque(Deques *deque, Paciente*pont_paciente){// inserir no inicio do deque
    Node *novo_no = malloc(sizeof(Node));
    novo_no->paciente = pont_paciente;
    
    if (deque->ini){ // se o deque nao for vazio
        novo_no->prox = deque->ini;
        novo_no->ant = deque->ini->ant;
        deque->ini->ant = novo_no;
        deque->ini = novo_no;
    } else{// se o deque for vazio
        deque->ini = novo_no;
        deque->fim = novo_no;
        novo_no->ant = NULL;
        novo_no->prox = NULL;   
    }
    
        
 
}
 
void inserir_final_deque(Deques *deque, Paciente *pont_paciente){// colocar no final do deque
    Node *novo_no = malloc(sizeof(Node));
    novo_no->paciente = pont_paciente;
    if (deque->fim){// se nao tiver alguem
        novo_no->ant = deque->fim;
        deque->fim->prox = novo_no;
        deque->fim = novo_no;
        novo_no->prox = NULL;
    } else{// se tiver alguem 
        deque->ini = novo_no;
        deque->fim = novo_no;
        novo_no->ant = NULL;
        novo_no->prox = NULL;
    } 
}
 
void retirar_inicio_deque(Deques *deque){// remover o primeiro do deque
    Node *aux = deque->ini;
    deque->ini = aux->prox;
    if(aux->prox == NULL)// quando for null
        deque->fim = NULL;
    free(aux);
    
}
void remover_atendimento(Lista_atendimento *lista, Paciente *p){// remover o primeiro atendimento
    no_Lista_atendimento *aux = lista->ini;
    if(lista->ini->prox == NULL)// enquanto nao for null
        lista->fim = NULL;
    lista->ini = aux->prox;
    free(aux);
}
void inicializar(Especialidade cecom[]){// inicializando com as quantidades 
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
    if ( paciente->atendimento.ini){// enquanto inicio nao for 0
        paciente->atendimento.fim->prox = novo_no;
        paciente->atendimento.fim = novo_no;
    } else{// quando for
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
    int terminou = 0; // variavel para verificar se todos os atendinentos terminara
    while(terminou == 0){//mudei a condição porque estava complicado tirar a pessoa da lista
        terminou = 1;// atribuo como se ja tivesse terminado    
        aux = lista_paciente->ini;//pego o primeiro paciente
        while(aux){// enquanto nao tiver apontado pra null ( ja feito o ultimo)
            if (aux->paciente->esta_fila == 0 && aux->paciente->qtd_atendimentos > 0){
                int id = aux->paciente->atendimento.ini->Valor;
                if (aux->paciente->prioridade == 'p'){//se o paciente for prioritario
                    inserir_inicio_deque(&cecom[id-1].lista_de_espera, aux->paciente);//insiro no inicio
                    remover_atendimento(&aux->paciente->atendimento, aux->paciente);//removo da lista_atendimento um id
                } else{
                    inserir_final_deque(&cecom[id-1].lista_de_espera, aux->paciente);//insiro no inicio
                    remover_atendimento(&aux->paciente->atendimento, aux->paciente);//removo da lista_atendimento um id
 
                }
                aux->paciente->esta_fila = 1;//vejo que no momento esta na fila

                
 
            } else if (aux->paciente->esta_fila == 0 && aux->paciente->qtd_atendimentos == 0){//se nao estiver na fila e ja todos os atendimentos
                imprimir_paciente(hora, minutos, aux->paciente);//  imprimo o paciente com a hora atual
                aux->paciente->qtd_atendimentos = -1;//atualizo a qntd
                
                
                          
                
            }
            aux = aux->prox; // atualizo meu aux pro proximo
            
            
        }
 
        
 
        for( int j = 0; j < 9; j++){
            for( int i = 0; i < cecom[j].qtd_profissionais && cecom[j].lista_de_espera.ini != NULL; i++){//rodo a quantidade ou até a fila tiver vazia
                cecom[j].lista_de_espera.ini->paciente->qtd_atendimentos--;//diminuo 1 quantidade de atendimento
                cecom[j].lista_de_espera.ini->paciente->esta_fila = 0;//retiro ele da fila no identificador
                retirar_inicio_deque(&cecom[j].lista_de_espera);//retiro do inicio pois ja atendi
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

void liberar_lista_paciente(Deques *lista_paciente){// Libero os pacientes e depois os nós
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
 
 
 
    // Função para ler os pacientes até o fim do arquivo dividindo por quebra de linha atribuindo valores aos parametro
    // Fazendo uma lista de nós com ponteiro para os pacientes, inserindo os pacientes completos ja com sua lista de atendimento
    //no fim da lista_paciente
    while(scanf("\"%[^\"]\" %c%*s", nome, &prioridade) != EOF){
        Paciente *paciente = (Paciente*)malloc(sizeof(Paciente));
        strcpy(paciente->Nome,nome);
        paciente->prioridade = prioridade;
        paciente->qtd_atendimentos = 0;
        paciente->esta_fila = 0;
        inicializar_atendimento_pac(paciente);
        while(scanf("%d",&id) > 0){// adiciono por lista ligadas os atendimento necessarios
            adicionar_atendimento_pac(id,paciente);
            paciente->qtd_atendimentos += 1;
        }
        inserir_final_deque(&lista_paciente, paciente);
    }
 
    atender_pacientes(&lista_paciente, cecom);// Função para rodar por todos os pacientes e ir atendendo
    liberar_lista_paciente(&lista_paciente);// Função para liberar os pacientes e os nós
}