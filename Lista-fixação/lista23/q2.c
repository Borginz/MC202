/*
Tempo: O(|E| lg |V |)
n = vertices
m = arestas

a) O(n), sendo n o numero de elementos
b) 1
c) O(log n + m )
d)
*/

typedef No *p_no;
typedef Grafo *p_grafo;
typedef FP *p_fp;

typedef struct No {
    int v;
    int peso;
    struct No *prox;
} No;

typedef struct Grafo {
    int n;
    p_no *adj;
} Grafo;

typedef struct Heap binário {
    int prioridade;
    int vertice;
} Item;

typedef struct {
    Item *v;
    int *indice;
    int n, tamanho;

} FP;

Dijkstra int *dijkstra(p_grafo g, int s) {
    int v, *pai = malloc(g->n * sizeof(int));
    p_no t;
    p_fp h = criar_fprio(g->n);
    for (v = 0; v < g->n; v++) {
        pai[v] = -1;
        insere(h, v, INT_MAX);
    }
    pai[s] = s;
    diminuiprioridade(h, s, 0);
    while (!vazia(h)) {
        v = extrai_minimo(h);
        if (prioridade(h, v) != INT_MAX)
            for (t = g->adj[v]; t != NULL; t = t->prox)
                if (prioridade(h, v) + t->peso < prioridade(h, t->v)) {
                    diminuiprioridade(h, t->v, prioridade(h, v) + t->peso);
                    pai[t->v] = v;
                }
    }
    return pai;
}

//Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira