- f(n) = O(g(n)) se f(n) <= c.g(n), para todo n>=n0.
f(n) = 2^n
g(n) = 2^(n-0,01)
Como:
2^(n-0,001) =
2^(n).(1/(2^0,001))
Portanto c = (1/(2^0,001))
Então, como f(n) <= c.g(n) para todo n>=n0, a afirmação é verdadeira.

- f(n) = 2^n
g(n) = O(2^(n.(1-0,001)))
Como:
2^(n.(1-0,001)) =
2^n.(1/(2^0,001n))
Como c é uma constante, c não pode ser igual a 2^n.(1/(2^0,001n)).
Então, como f(n) > c.g(n) para todo n>=n0, a afirmação é falsa.


-f(n) = n^2
g(n) = O(n^1.999)
Como:
n^2 > n^1.999, não existe n >= n0 que faça com que f(n) <= c.g(n),
portanto, a afirmação é falsa.

Feito por: Cícero Libardi, Lucas Oliveira e Leonardo Borges