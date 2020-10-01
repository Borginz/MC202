#include <stdio.h>
#include "professor_carlos.h"



int main(){
    int n, k, m, j, x;
    char s[5];
    Turma t[50];
    Aluno aluno_adc;
    scanf(" %d %d", &n, &k);
    for ( int i = 0; i < n; i++){
        scanf(" %d", &m);
        t[i].qtd = m;
        for ( int p = 0; p < m; p++){
            scanf(" %s %s %d %d %d", t[i].alunos[p].nome,t[i].alunos[p].sobrenome, &t[i].alunos[p].nascimento.dia, &t[i].alunos[p].nascimento.mes, &t[i].alunos[p].nascimento.ano );
        }

    
    }
    for ( int l = 0; l < k ; l++){
        scanf(" %d", &x);
        switch (x)
        {
        case 1:
            scanf(" %d", &j);
            printf("%s\n", procura_novo_na_turma(t, n, j).nome);
            break;
        case 2:
            scanf(" %d", &j);
            printf("%s\n", procura_velho_na_turma(t, n, j).sobrenome);
            break;
        case 3:
            printf("%s\n", procura_velho_todas_turmas(t, n).nome);
            break;
        case 4:
            printf("%s\n", procura_novo_todas_turmas(t, n).sobrenome);
            break;
        case 5:
            
            scanf(" %s", s);
            printf("%d\n", conta_substrings(t, n, s));
            break;
        case 6:
            scanf(" %d %s %s %d %d %d", &j , aluno_adc.nome, aluno_adc.sobrenome, &aluno_adc.nascimento.dia, &aluno_adc.nascimento.mes, &aluno_adc.nascimento.ano);
            printf("%d\n", add_aluno(t, aluno_adc, j));
            break;
        case 7:
            scanf(" %d", &j);
            printf("%d\n", remove_aluno(t, j));
            break;

        default:
            printf("Chegou aqui, fez caquinha\n");
            break;
        }
    }

    
}