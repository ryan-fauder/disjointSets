# Resolução do problema da plataforma URI

## URI Online Judge

<a href="https://www.urionlinejudge.com.br/judge/pt/problems/view/1527"> Guildas | 1527 </a>

Por Cristhian Bonilha, UTFPR

## Solução

Consiste na utilização da estrutura de conjuntos disjuntos. Todo relação entre players é realizada pela união. Como a prioridade é calcular o número de vitorias do Player 0, deve-se, na união, sempre deixá-lo como a raiz. Além disso, para o cálculo da pontuação total, basta armazenar sempre na raiz a soma dos ranks dos filhos.
