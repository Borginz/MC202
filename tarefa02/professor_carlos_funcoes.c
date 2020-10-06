#include <stdio.h>
#include "professor_carlos.h"

int pegar_tamanho(char palavra[]){
    int len = 0;
    for(int i = 0; palavra[i] != '\0';i++){
        len++;
    }   
    return len; 
    
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
        }

    // se passar dos criterios do for, vai checar o tamanho   
    }
    if ( tam_1 > tam_2){
        return 1;
    } else if ( tam_1 < tam_2){
        return -1;
    } else{
        return 0;
    }
}

    
int comparar(char padrao[], char texto[] ){
    int tamanho_padrao = pegar_tamanho(padrao), tamanho_texto = pegar_tamanho(texto);
    for ( int j = 0; j <= tamanho_texto - tamanho_padrao ; j++){
        int aparece = 1;
        for ( int i = 0; i < tamanho_padrao; i++){
            if (padrao[i] != texto[j+i]){
                aparece = 0;
            }
        }

        if ( aparece == 1 )
            return 1;
    }

    return 0;



}





// Se o primeiro < segundo ( primeiro mais velho = 1)
// se o primeiro > segundo ( primeiro mais novo = -1)
int comparar_idade(Aluno novo, Aluno aluno_comp){
    

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
                    return 0;


                } else if (comparar_nome(novo.nome, aluno_comp.nome) == -1){
                    return 2;
                } else{
                    if ( comparar_nome(novo.sobrenome, aluno_comp.sobrenome) == 1){
                        return 0;
                    } else if ( comparar_nome(novo.sobrenome, aluno_comp.sobrenome) == -1){
                        return 2;
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
        id = comparar_idade(novo, aluno_comp);
        if ( id == 1 || id == 0){
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
        if ( id == -1 || id == 0){
            velho = aluno_comp;
        }

    }
    return velho; 
}

Aluno procura_novo_todas_turmas(Turma t[], int qtd_turmas){
    Aluno novo, aluno_comp;
    novo = procura_novo_na_turma(t, qtd_turmas, 0);
    for ( int j = 1; j < qtd_turmas; j++){
        aluno_comp = procura_novo_na_turma(t, qtd_turmas, j);
        if ( comparar_idade(novo, aluno_comp) == 1 || comparar_idade(novo, aluno_comp) == 0){
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
        if ( comparar_idade(velho, aluno_comp) == -1 || comparar_idade(velho, aluno_comp) == 0){
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
    t[j].qtd -= 1;
    return t[j].qtd;

}

int conta_substrings(Turma t[], int qtd_turmas, char *padrao){
    int contador = 0;
    for ( int i = 0; i < qtd_turmas; i++){
        for ( int j = 0; j < t[i].qtd; j++){
            contador+= comparar(padrao, t[i].alunos[j].nome);
        }
    } return contador;
}