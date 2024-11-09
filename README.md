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

Selection Sort com 100000 elementos: 12.345678 segundos

Insertion Sort com 100000 elementos: 10.234567 segundos

Bubble Sort com 100000 elementos: 15.678910 segundos

Merge Sort com 100000 elementos: 0.123456 segundos

Quick Sort com 100000 elementos: 0.098765 segundos

Heap Sort com 100000 elementos: 0.567890 segundos

## Personalização
Para testar outros tamanhos de arrays, modifique o código-fonte (main.c) na seção onde os arrays são gerados e ajuste o tamanho desejado.

## Tecnologias e Bibliotecas Utilizadas
Linguagem de Programação C

Biblioteca Padrão time.h para medição do tempo de execução