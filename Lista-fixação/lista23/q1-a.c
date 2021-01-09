void ordenacao_topologica(p_grafo g) {
    int s, *visitado = malloc(g->n * sizeof(int)), *visitado_anteriormente = malloc(g->n * sizeof(int)), ha_ciclos = 0;
    for (s = 0; s < g->n; s++)
        visitado[s] = 0;
        visitado_anteriormente[s] = 0;
    for (s = 0; s < g->n; s++)
        if (!visitado[s])
            if(visita_rec(g, visitado, visitado_anteriormente, s))
                ha_ciclos = 1;
    free(visitado);
    free(visitado_anteriormente);
    printf("\n");
    if(ha_ciclos)
        printf("Há ciclos\n");
    else
        printf("Não há ciclos\n");
}
int visita_rec(p_grafo g, int *visitado, int *visitado_anteriormente, int v) {
    p_no t;
    int resultado = 0;
    visitado[v] = 1;
    for (t = g->adj[v]; t != NULL; t = t->prox)
        if (!visitado[t->v])
            visitado_anteriormente[v] = 1;
            if(visita_rec(g, visitado, visitado_anteriormente t->v))
                resultado = 1;
        if(visitado_anteriormente[t->v])
            resultado = 1;
            resultado = 1;
    printf("%d ", v);
    return resultado;
}

//Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira