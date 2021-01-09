enum Cor
{
    VERMELHO,
    PRETO
};

typedef struct No
{
    int chave;
    enum Cor cor;
    struct No *esq, *dir;
} No;

typedef No *p_no;

int inserir_rec(p_no raiz, int chave)
{
   /* 
   Percorro recursivamente todos os elemementos da arvore
   Se entrar em alguma das tres condicoes eu ja retorno falso
   Caso contrario eu retorno 1
   
   */
    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq))
        return 0;
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        return 0;
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        return 0;
    return 1;
}

p_no inserir(p_no raiz, int chave)
{
    raiz = inserir_rec(raiz, chave);
    raiz->cor = PRETO;
    return raiz;
}

// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira






































// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira











// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira











// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira











// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira











// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira











// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira











// Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira
