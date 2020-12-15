int hashing(char *palavra)//função pelo metodo da divisao do hash
{
    int i, n = 0;
    int len = strlen(palavra);
    n = len % 10;
    return n;
}

*Feito por: Cícero Libardi, César Devens, Leonardo Borges e Lucas Oliveira*