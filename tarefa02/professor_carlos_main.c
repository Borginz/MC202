#include <stdio.h>
#include "professor_carlos.h"


int main(){
    int n, k, m, j;
    char x;
    Turma t[50];
    scanf("%d %d", &n, &k);
    for ( int i = 0; i < n; i++){
        scanf("%d", &m);
        t[i].qtd = m;
        for ( int p = 0; p < m; p++){
            scanf("%s %s %d %d %d %d", t[i].alunos[p].nome,t[i].alunos[p].sobrenome, t[i].alunos[p].nascimento.dia, t[i].alunos[p].nascimento.mes, t[i].alunos[p].nascimento.dia );
        }

    
    }
    for ( int t = 0; t < k ; t++){
        scanf("%c", &x);
        switch (x)
        {
        case '1':
            scanf("%d", &j);
            printf("%", procura_novo_na_turma(t, n, j).nome);
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;

        default:
            break;
        }
    }

    
}