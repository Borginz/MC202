#include <stdio.h>
#include "professor_carlos.h"



int main(){
    int n, k, m, j;
    char x, s[5];
    Turma t[50];
    Aluno aluno_adc;
    scanf("%d %d", &n, &k);
    for ( int i = 0; i < n; i++){
        scanf("%d", &m);
        t[i].qtd = m;
        for ( int p = 0; p < m; p++){
            scanf("%s %s %d %d %d", t[i].alunos[p].nome,t[i].alunos[p].sobrenome, t[i].alunos[p].nascimento.dia, t[i].alunos[p].nascimento.mes, t[i].alunos[p].nascimento.dia );
        }

    
    }
    for ( int t = 0; t < k ; t++){
        scanf("%c", &x);
        switch (x)
        {
        case '1':
            scanf("%d", &j);
            printf("%s", procura_novo_na_turma(t, n, j).nome);
            break;
        case '2':
            scanf("%d", &j);
            printf("%s", procura_velho_na_turma(t, n, j).nome);
            break;
        case '3':
            prinft("%s", procura_velho_todas_turmas(t, n).nome);
            break;
        case '4':
            printf("%s", procura_novo_todas_turmas(t, n).sobrenome);
            break;
        case '5':
            
            scanf("%s", &s);
            printf("%d", conta_substrings(t, n, s));
            break;
        case '6':
            scanf("%d %s %s %d %d %d", &j , aluno_adc.nome, aluno_adc.sobrenome, &aluno_adc.nascimento.dia, &aluno_adc.nascimento.mes, &aluno_adc.nascimento.ano);
            printf("%d", add_aluno(t, aluno_adc, j));
            break;
        case '7':
            scanf("%d", &j);
            print("%d", remove_aluno(t, j));
            break;

        default:
            print("Chegou aqui, fez caquinha");
            break;
        }
    }

    
}