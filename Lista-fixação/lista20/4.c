int hash(int chave1, int chave2) {
    int i, n = 0;
    n = (chave1 * chave2) / 256;
    return n;
}