#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Selection Sort: Um algoritmo simples que repetidamente seleciona o menor elemento restante.
void selectionSort(int array[], int n) {
  for(int i = 0; i < n - 1; i++){
    int min = i;

    for(int j = i + 1; j < n; j++){
      if(array[j] < array[min]){
        min = j;
      }
    }
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

//Insertion Sort: Constrói a lista final um item de cada vez, como organizar cartas de baralho na mão.
void insertionSort(int array[], int n) {
  for(int i = 1; i < n; i++){
    int temp = array[i];
    int j = i - 1;
    while(j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp;
  }
}

//Bubble Sort: Compara pares adjacentes e os troca se estiverem fora de ordem.
void bubbleSort(int array[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
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

    while(e < tamEsq && d < tamDir) {
        if(esquerdo[e] <= direito[d]) {
            array[i++] = esquerdo[e++];
        } else {
            array[i++] = direito[d++];
        }
    }
    while(e < tamEsq) {
        array[i++] = esquerdo[e++];
    }
    while(d < tamDir) {
        array[i++] = direito[d++];
    }
}

// Função principal do Merge Sort
void mergeSort(int array[], int n) {
    if(n <= 1) {
        return;
    }

    int meio = n / 2;
    int esquerdo[meio];
    int direito[n - meio];

    for(int i = 0; i < meio; i++) {
        esquerdo[i] = array[i];
    }
    for(int i = meio; i < n; i++) {
        direito[i - meio] = array[i];
    }

    mergeSort(esquerdo, meio);
    mergeSort(direito, n - meio);
    merge(esquerdo, meio, direito, n - meio, array);
}

//Quick Sort: Um algoritmo rápido que usa a estratégia de dividir e conquistar.
int partition(int array[], int comeco, int final){
  int pivo = array[final];
  int i = comeco - 1;

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

  return i;
}

void quickSort(int array[], int comeco, int final) {
    if(final <= comeco) {
        return;
    }

    int pivo = partition(array, comeco, final);

    quickSort(array, comeco, pivo - 1);
    quickSort(array, pivo + 1, final);
}


//Heap Sort: Utiliza uma estrutura de dados chamada heap para ordenar os elementos.
void heapify(int array[], int n, int i){
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


//main para testes
int main() {

}