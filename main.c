#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Selection Sort: Um algoritmo simples que repetidamente seleciona o menor elemento restante.
void selectionSort(int array[], int n) {
  //se array tiver somente 1 já é ordenado
  if(n <= 1) {
    return;
  }

  //seleciona o menor elemento e coloca na primeira posicao
  for(int i = 0; i < n - 1; i++){
    int min = i;

    //procura menor no array
    for(int j = i + 1; j < n; j++){
      //se j for menor que min
      if(array[j] < array[min]){
        min = j; //atualiza menor
      }
    }
    //troca o menor com o primeiro nao ordenado
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

//Insertion Sort: Constrói a lista final um item de cada vez, como organizar cartas de baralho na mão.
void insertionSort(int array[], int n) {
  //se array tiver somente 1 já é ordenado
  if(n <= 1) {
    return;
  }

  //coloca o primeiro elemento na posicao certa
  for(int i = 1; i < n; i++){
    int temp = array[i];
    int j = i - 1;

    //move maiores que temp para frente
    while(j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }
    //insere temp na posicao certa
    array[j + 1] = temp;
  }
}

//Bubble Sort: Compara pares adjacentes e os troca se estiverem fora de ordem.
void bubbleSort(int array[], int n) {
  //se array tiver somente 1 já é ordenado
  if(n <= 1) {
    return;
  }

  //seleciona o menor elemento e coloca na primeira posicao
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      //se j maior que proximo, troca
      if(array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

//Merge Sort: Um algoritmo eficiente que divide a lista, ordena as partes e depois as mescla.
void merge(int esquerdo[], int tamEsq, int direito[], int tamDir, int array[]) {
  int i = 0; //indice do array original
  int e = 0; //indice do array esquerdo
  int d = 0; //indice do array direito

  //coloca esquerda e direita de volta no array original
  while(e < tamEsq && d < tamDir) {
    if(esquerdo[e] <= direito[d]) {
      array[i++] = esquerdo[e++];
    } else {
      array[i++] = direito[d++];
    }
  }
  //coloca restantes esquerda
  while(e < tamEsq) {
    array[i++] = esquerdo[e++];
  }
  //coloca restantes direita
  while(d < tamDir) {
    array[i++] = direito[d++];
  }
}

// Função principal do Merge Sort
void mergeSort(int array[], int n) {
  //se array tiver somente 1 já é ordenado
  if(n <= 1) {
    return;
  }

  int meio = n / 2;
  int esquerdo[meio];
  int direito[n - meio];

  //divide array em esquerdo
  for(int i = 0; i < meio; i++) {
    esquerdo[i] = array[i];
  }
  //divide array em direito
  for(int i = meio; i < n; i++) {
    direito[i - meio] = array[i];
  }

  //ordena o array esquerdo
  mergeSort(esquerdo, meio);
  //ordena o array direito
  mergeSort(direito, n - meio);
  //junta os arrays ordenados e coloca de volta no original
  merge(esquerdo, meio, direito, n - meio, array);
}

//Quick Sort: Um algoritmo rápido que usa a estratégia de dividir e conquistar.
int partition(int array[], int comeco, int final){
  int pivo = array[final];
  int i = comeco - 1;

  //reorganiza para menor que pivo fique na esquerda
  for(int j = comeco; j < final; j++){
    if(array[j] < pivo){
      i++;
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  i++;
  int temp = array[i];
  array[i] = array[final];
  array[final] = temp;

  return i; //retorna pivo
}

void quickSort(int array[], int comeco, int final) {
  //se array tiver somente 1 já é ordenado
  if(final <= comeco) {
      return;
  }

  //separa array e pega posicao do pivo
  int pivo = partition(array, comeco, final);

  //ordena as duas metades do array
  quickSort(array, comeco, pivo - 1);
  quickSort(array, pivo + 1, final);
}


//Heap Sort: Utiliza uma estrutura de dados chamada heap para ordenar os elementos.
void heapify(int array[], int n, int i){
  if(n < 1){
    return;
  }
  int maior = i; //maior é raiz
  int esquerda = 2 * i + 1; //filho esquerda
  int direita = 2 * i + 2; //filho direita

  //se filho esquerda for maior q raiz
  if(esquerda < n && array[esquerda] > array[maior]) {
    maior = esquerda;
  }
  //se filho direita maior que o maior
  if(direita < n && array[direita] > array[maior]) {
    maior = direita;
  }
  //se maior não é raiz
  if(maior!= i) {
    int temp = array[i];
    array[i] = array[maior];
    array[maior] = temp;

    heapify(array, n, maior);
  }
}

void heapSort(int array[], int n) {
  //se array tiver somente 1 já é ordenado
  if(n <= 1) {
    return;
  }

  //constroi heap inicial
  for(int i = n / 2 -1; i >= 0; i--){
    heapify(array, n, i);
  }

  //tira de um em um
  for(int i = n - 1; i > 0; i--){
    //move raiz atual para final
    int temp = array[0];
    array[0] = array[i];
    array[i] = temp;

    //chama dnv para raiz reduzida
    heapify(array, i, 0);
  }
}

//funcao para copiar o array principal para ser usado novamente
void copiarArray(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

//main para testes
int main() {
  int array[1000]; //trocar por 100, 1000, 10000, 50000, 100000.
  int arrayCopia[1000]; //trocar por 100, 1000, 10000, 50000, 100000.
  int n = sizeof(array) / sizeof(array[0]); //pega o tamanho do array
  int comeco = 0; //declara inicio do array
  int final = n - 1; //declara final do array

  srand(time(NULL));

  //enche o array com numeros inteiros
  for(int i = 0; i < n; i++){
    array[i] = rand();
  }

  //imprime o array desordenado
  printf("Array antes da ordenação: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  clock_t inicio, fim; //declara variaveis de tempo inicio e tempo fim
  double tempo_cpu; //declara variavel tempo da cpu
  
  //selection
  copiarArray(array, arrayCopia, n); //copia o array principal para auxiliar
  inicio = clock(); //inicia o temporizador
  selectionSort(arrayCopia, n); //ordena o array aux
  printf("Array após ordenação SELECTION: ");
  //imprime o array ordenado
  for(int i = 0; i < 100; i++) {
    printf("%d ", arrayCopia[i]);
  }
  printf("\n");
  fim = clock(); //finaliza o temporizador
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; //guarda o tempo total da execucao
  printf("Tempo de execução SELECTION: %f segundos\n", tempo_cpu); //imprime o tempo de execucao

  //insertion
  copiarArray(array, arrayCopia, n); //copia o array principal para auxiliar
  inicio = clock(); //inicia o temporizador
  insertionSort(arrayCopia, n); //ordena o array aux
  printf("Array após ordenação INSERTION: ");
  //imprime o array ordenado
  for(int i = 0; i < 100; i++) {
    printf("%d ", arrayCopia[i]);
  }
  printf("\n");
  fim = clock(); //finaliza o temporizador
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; //guarda o tempo total da execucao
  printf("Tempo de execução INSERTION: %f segundos\n", tempo_cpu); //imprime o tempo de execucao

  //bubble
  copiarArray(array, arrayCopia, n); //copia o array principal para auxiliar
  inicio = clock(); //inicia o temporizador
  bubbleSort(arrayCopia, n); //ordena o array aux
  printf("Array após ordenação BUBBLE: ");
  //imprime o array ordenado
  for(int i = 0; i < 100; i++) {
    printf("%d ", arrayCopia[i]);
  }
  printf("\n");
  fim = clock(); //finaliza o temporizador
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; //guarda o tempo total da execucao
  printf("Tempo de execução BUBBLE: %f segundos\n", tempo_cpu); //imprime o tempo de execucao

  //merge
  copiarArray(array, arrayCopia, n); //copia o array principal para auxiliar
  inicio = clock(); //inicia o temporizador
  mergeSort(arrayCopia, n); //ordena o array aux
  printf("Array após ordenação MERGE: ");
  //imprime o array ordenado
  for(int i = 0; i < 100; i++) {
    printf("%d ", arrayCopia[i]);
  }
  printf("\n");
  fim = clock(); //finaliza o temporizador
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; //guarda o tempo total da execucao
  printf("Tempo de execução MERGE: %f segundos\n", tempo_cpu); //imprime o tempo de execucao

  //quick
  copiarArray(array, arrayCopia, n); //copia o array principal para auxiliar
  inicio = clock(); //inicia o temporizador
  quickSort(arrayCopia, comeco, final); //ordena o array aux
  printf("Array após ordenação QUICK: ");
  //imprime o array ordenado
  for(int i = 0; i < 100; i++) {
    printf("%d ", arrayCopia[i]);
  }
  printf("\n");
  fim = clock(); //finaliza o temporizador
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; //guarda o tempo total da execucao
  printf("Tempo de execução QUICK: %f segundos\n", tempo_cpu); //imprime o tempo de execucao

  //heap
  copiarArray(array, arrayCopia, n); //copia o array principal para auxiliar
  inicio = clock(); //inicia o temporizador
  heapSort(arrayCopia, n); //ordena o array aux
  printf("Array após ordenação HEAP: ");
  //imprime o array ordenado
  for(int i = 0; i < 100; i++) {
    printf("%d ", arrayCopia[i]);
  }
  printf("\n");
  fim = clock(); //finaliza o temporizador
  tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; //guarda o tempo total da execucao
  printf("Tempo de execução HEAP: %f segundos\n", tempo_cpu); //imprime o tempo de execucao

  return 0;
}