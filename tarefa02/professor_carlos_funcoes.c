#include <stdio.h>
#include "professor_carlos.h"

int comparar_nome(char novo_nome, char nome_comp){
    int id = 0;
    // Segue as regras da comparar_idade


}

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
                return 0;
            }
        }
    
    }
    
}


Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j){

    Aluno novo, aluno_comp;
    int i, id;
    novo = t[j].alunos[0];
    for ( i = 1; i < t[j].qtd; i++){
        aluno_comp = t[j].alunos[i];
        id = comparar_idade( novo, aluno_comp);
        if ( id == -1){
            novo = t[j].alunos[i];

        } else if ( id == 0){
            id = comparar_nome(novo.nome, aluno_comp.nome);
            if ( id == -1){
                novo = t[j].alunos[i];
            } else if ( id == 0){
                id = comparar_nome(novo.sobrenome, aluno_comp.sobrenome);
                if ( id == -1){
                    novo = t[j].alunos[i];

                }
            }




        }
    }
}


Aluno procura_velho_na_turma(Turma t[], int qtd_turmas, int j){
    
}