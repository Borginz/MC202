#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Clientes Clientes;

typedef struct No
{
    Clientes *cliente;
    struct No *prox;
    struct No *ant;

} No;

typedef struct Deque
{
    No *ini;
    No *fim;

} Deque;

typedef struct Clientes
{
    char Nome[30];
    char prioridade;
    int contador;

} Clientes;

/* 
 *Leio os pacientes adicionando cada cliente da leitura em um nó com o ponteiro do cliente 
 *atualizando deque ini e fim,assim tenho uma lista de pacientes organizada em ordem, crio um 
 *contador em cliente para ver quantas vezes um prioritario passou na frentede um não prioritario, 
 *assim quando ler o prioritario para adicionar, verificara se o cliente tem o contador menor que 2, 
 *caso contrario sera colocado depois dessa pessoa.
 */

// Feito por Cícero Libardi, Leonardo Borges e Lucas Oliveira.