

void infeccao(p_grafo g, int *horario_infeccao, int minutos, int v) {
    p_no t;
    horario_infeccao[v] = minutos;
    for (t = g->adj[v]; t != NULL; t = t->prox)
        infeccao(g, horario_infeccao, minutos+60, t->v);
}

void imunizacao(p_grafo g, int *horario_imunizacao, int minutos, int v) {
    p_no t;
    horario_imunizacao[v] = minutos;
    for (t = g->adj[v]; t != NULL; t = t->prox)
        imunizacao(g, horario_imunizacao, minutos+10, t->v);
}

int main(){
    p_grafo g = recebe_grafo();
    int * horario_infeccao = malloc(g->n * sizeof(int)), * horario_imunizacao = malloc(g->n * sizeof(int)), infectados = 0;
    infeccao(g, horario_infeccao, 0, 0);
    imunizacao(g, horario_imunizacao, 120, 0);
    for(int i = 0; i < g->n; i++){
        if(horario_infeccao < horario_imunizacao){
            infectados++;
        }
    }
    printf("São %d infectados.\n", infectados);

}


//Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira