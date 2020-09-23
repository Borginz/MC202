/* ENTRADA:


Numero de apostadores int (m) e valor da premiação double (n)
Restrições:
5<= m <= 1000
1e6 <=n<=3e9

SAÍDA:
 
 Valor da premiação correspondente a cada apostador, sendo 1 por linha



*/

//ALGORTIMO EM PORTUGUES:

/* Main:
PRIMEIRA LINHA:
recebe duas variaveis sendo a por int m e a double n

SEGINDA LINHA:
percorre o numero de vezes m as matrizes por scanf

ULTIMA LINHA:
recebe separado por espaço os 6 numeros da mega 

Função para ler a matriz:

Função para verificar cada matriz com os numeros:





*/
i = 0
j = 19
k = 2
int contador = 0;
for ( i = 0; i < n; i++){
    
    for (j = 0; j < 60; j++){
        for (k = 0; k < 6; k++){
            if (Matrizona[i][j] == 1 && j+1 == numeros[k]){
                contador += 1
            }
        }
    }
    
    Vetor_jogadores[i] = contador
    contador = 0
}
