# Projeto de Comparação de Algoritmos de Ordenação

Este projeto implementa e compara a eficiência de vários algoritmos de ordenação em C, medindo o tempo de execução para conjuntos de dados de tamanhos variados. O projeto utiliza a biblioteca time.h para calcular o tempo necessário para cada algoritmo ordenar um array de números aleatórios.

## Objetivo
O objetivo deste projeto é:

Implementar diferentes algoritmos de ordenação em C.

Comparar o desempenho desses algoritmos com conjuntos de dados de diferentes tamanhos.

Medir o tempo de execução de cada algoritmo usando a biblioteca time.h.

## Algoritmos Implementados

Os seguintes algoritmos de ordenação foram implementados:

- Selection Sort: Um algoritmo simples que repetidamente seleciona o menor elemento restante.
- Insertion Sort: Constrói a lista final um item de cada vez, como organizar cartas de baralho na mão.
- Bubble Sort: Compara pares adjacentes e os troca se estiverem fora de ordem.
- Merge Sort: Um algoritmo eficiente que divide a lista, ordena as partes e depois as mescla.
- Quick Sort: Um algoritmo rápido que usa a estratégia de dividir e conquistar.
- Heap Sort: Utiliza uma estrutura de dados chamada heap para ordenar os elementos.

## Estrutura do Projeto

main.c: Contém o código principal para gerar arrays aleatórios, executar os algoritmos de ordenação e medir o tempo de execução.

Funções de Ordenação: Cada algoritmo de ordenação está implementado no próprio main.c.

README.md: Arquivo de documentação do projeto.

O programa irá gerar um array aleatório de números e medir o tempo de execução para cada algoritmo de ordenação. Os resultados serão exibidos no terminal.

## Exemplo de Saída

Ao executar o programa, a saída será semelhante a:

Array antes da ordenação: 2 9 4 7 1 8 3 6 5

Array após ordenação SELECTION: 1 2 3 4 5 6 7 8 9

Tempo de execução SELECTION: 0.001000 segundos
Array após ordenação INSERTION: 1 2 3 4 5 6 7 8 9

Tempo de execução INSERTION: 0.000000 segundos

Array após ordenação BUBBLE: 1 2 3 4 5 6 7 8 9
Tempo de execução BUBBLE: 0.002000 segundos

Array após ordenação MERGE: 1 2 3 4 5 6 7 8 9
Tempo de execução MERGE: 0.000000 segundos

Array após ordenação QUICK: 1 2 3 4 5 6 7 8 9
Tempo de execução QUICK: 0.000000 segundos

Array após ordenação HEAP: 1 2 3 4 5 6 7 8 9
Tempo de execução HEAP: 0.000000 segundos

## Personalização
Para testar outros tamanhos de arrays, modifique o código-fonte (main.c) no próprio tamanho do array, não esqueça de mudar o arrayCopia também.

## Tecnologias e Bibliotecas Utilizadas
Linguagem de Programação C

Biblioteca Padrão time.h para medição do tempo de execução, stdlib.h para inserir números aleatórios no array usando srand e stdio.h para manipular entrada e saída de dados.
