#include <stdio.h>
#include "professor_carlos.h"

int pegar_tamanho(char palavra[]){
    for(int i = 0; palavra[i] != '\0';i++)    
     return i;
}


int comparar_nome( char nome[], char nome_comp[]){
    int tam_1 = pegar_tamanho(nome);
    int tam_2 = pegar_tamanho(nome_comp);
    int max;
    if ( tam_1 < tam_2){
        max = tam_1;
    } else if ( tam_1 > tam_2){
        max = tam_2;
    } else{
        max = tam_2;
    }
    
    for (int i = 0; i < max; i++){
        if (nome[i] < nome_comp[i]){
            return -1;
        } else if ( nome[i] > nome_comp[i]){
            return 1;
        } else if (nome[i] == nome_comp[i] && i == max-1){
            return 0;     
        }

        
    }
}
    
int comparar(char padrao[], char nome[] ){
// vou comparar o nome de todos os alunos com o padrao
    for (int j = 0; padrao[j] != '\0'; j++){
        if ( nome[j] == '\0' || ( nome[j] && padrao[j] != padrao[0])){
            return 0;
        }      
    } 
    return 1;


}


// Retorno 1 se o primeiro parametro for mais velho que o segundo
// -1 se mais novo 
// 0 se igual
int comparar_idade(Aluno novo, Aluno aluno_comp){
    int id = 0;

    if ( novo.nascimento.ano < aluno_comp.nascimento.ano){
        return 1;
    } else if ( novo.nascimento.ano > aluno_comp.nascimento.ano ){
        return -1;
    } else {
        if ( novo.nascimento.mes < aluno_comp.nascimento.mes){
            return 1;
        } else if ( novo.nascimento.mes > aluno_comp.nascimento.mes){
            return -1;
        } else {
            if ( novo.nascimento.dia < aluno_comp.nascimento.dia){
                return 1;                
            } else if ( novo.nascimento.dia > aluno_comp.nascimento.dia ){
                return -1;
            } else {
                if ( comparar_nome(novo.nome, aluno_comp.nome) == 1){
                    return 1;


                } else if (comparar_nome(novo.nome, aluno_comp.nome) == -1){
                    return -1;
                } else{
                    if ( comparar_nome(novo.sobrenome, aluno_comp.sobrenome) == 1){
                        return 1;
                    } else if ( comparar_nome(novo.sobrenome, aluno_comp.sobrenome) == -1){
                        return -1;
                    }
                }
            }
        }
    
    } 
    return 0;
    
}


Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j){

    Aluno novo, aluno_comp;
    int i, id;
    novo = t[j].alunos[0];
    for ( i = 1; i < t[j].qtd; i++){
        aluno_comp = t[j].alunos[i];
        id = comparar_idade( novo, aluno_comp);
        if ( id == 1){
            novo = aluno_comp;
        } 
    }
    return novo;
}


Aluno procura_velho_na_turma(Turma t[], int qtd_turmas, int j){
    Aluno velho, aluno_comp;
    int i, id;
    velho = t[j].alunos[0];
    for ( i = 1; i < t[j].qtd; i++){
        aluno_comp = t[j].alunos[i];
        id = comparar_idade( velho, aluno_comp);
        if ( id == -1){
            velho = aluno_comp;
        }

    } 
}

Aluno procura_novo_todas_turmas(Turma t[], int qtd_turmas){
    Aluno novo, aluno_comp;
    novo = procura_novo_na_turma(t, qtd_turmas, 0);
    for ( int j = 1; j < qtd_turmas; j++){
        aluno_comp = procura_novo_na_turma(t, qtd_turmas, j);
        if ( comparar_idade(novo, aluno_comp) == 1){
            novo = aluno_comp;
        } 

    }
    return novo;
}

  


Aluno procura_velho_todas_turmas(Turma t[], int qtd_turmas){
    Aluno velho, aluno_comp;
    velho = procura_velho_na_turma(t, qtd_turmas, 0);
    for ( int j = 1; j < qtd_turmas; j++){
        aluno_comp = procura_velho_na_turma(t, qtd_turmas, j);
        if ( comparar_idade(velho, aluno_comp) == -1){
            velho = aluno_comp;
        } 

    }
    return velho;
}


int add_aluno(Turma t[], Aluno A, int j){
    t[j].alunos[t[j].qtd] = A;
    t[j].qtd += 1;
    return t[j].qtd;

}

int remove_aluno(Turma t[], int j){
    t[j].qtd-=1;
    return t[j].qtd;

}

int conta_substrings(Turma t[], int qtd_turmas, char *padrao){
    int contador = 0;
    for ( int i = 0; i < qtd_turmas; i++){
        for ( int j = 0; j < t[i].qtd; j++){
            contador+= comparar(padrao, t[j].alunos[i].nome);
        }
    } return contador;
}